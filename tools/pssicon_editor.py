import os
import re
from pathlib import Path

# Novos paths

ROOT = Path(__file__).resolve().parents[1]
file_path = ROOT / "src" / "pssicons.c"
header_path = ROOT / "include" / "pssicons.h"
const_header_path = ROOT / "include" / "constants" / "pssicons.h"

def get_current_pss_icons():
    """Lê os membros do enum pssicons (formato sem valores explícitos)"""
    try:
        with open(const_header_path, 'r', encoding='utf-8') as file:
            content = file.read()
    except Exception as e:
        print(f"Erro ao ler arquivo de constantes: {e}")
        return [], 1

    # Procura o bloco enum pssicons
    enum_pattern = r'enum\s+pssicons\s*\{([^}]+)\}'
    match = re.search(enum_pattern, content, re.DOTALL)
    if not match:
        # Fallback: tenta defines antigos
        pss_defs = re.findall(r'#define PSS_ICON_(\w+)\s+(\d+)', content)
        if pss_defs:
            icons = [(name, int(num)) for name, num in pss_defs]
            next_id = max(num for _, num in icons) + 1
            return icons, next_id
        print("Nenhum enum ou define encontrado.")
        return [], 1

    enum_body = match.group(1)
    # Extrai todas as linhas que contêm identificadores
    # Padrão: captura palavras entre vírgulas ou no final
    # Ex: "    PSS_NONE," -> PSS_NONE
    #     "    PSS_ICON_BARRY" (sem vírgula)
    members = re.findall(r'\b(PSS_\w+)\b', enum_body)
    if not members:
        return [], 1
    
    # Remove duplicatas (caso haja)
    seen = set()
    unique_members = []
    for m in members:
        if m not in seen:
            seen.add(m)
            unique_members.append(m)
    
    # IDs são implícitos: posição no enum (0,1,2,...)
    icons = [(name, idx) for idx, name in enumerate(unique_members)]
    next_id = len(unique_members)  # próximo ID = tamanho atual
    return icons, next_id

def show_current_icons(icons):
    print("\n=== PSS Icons Definidos (enum pssicons) ===")
    for name, num in sorted(icons, key=lambda x: x[1]):
        print(f"{name} = {num}")
    print(f"Total: {len(icons)} membros")
    print("===========================================")

def update_pss_files():
    # Ler membros atuais do enum
    icons, next_id = get_current_pss_icons()

    while True:
        show_current_icons(icons)
        print(f"\nPróximo ID disponível: {next_id}")
        icon_name = input("Digite o nome do novo PSS Icon (ou 'sair'): ").strip()

        if icon_name.lower() == 'sair':
            break

        if not icon_name.isalpha():
            print("Nome deve conter apenas letras. Tente novamente.")
            continue

        icon_name_upper = f"PSS_ICON_{icon_name.upper()}"
        # Permite também PSS_NONE? Não, mas não impede se for igual
        if any(name == icon_name_upper for name, _ in icons):
            print(f"Erro: '{icon_name_upper}' já existe!")
            continue

        try:
            # 1. ATUALIZAR CONSTANTES HEADER (enum)
            with open(const_header_path, 'r', encoding='utf-8') as file:
                const_lines = file.readlines()

            # Encontrar o bloco enum pssicons
            enum_start = -1
            enum_end = -1
            for i, line in enumerate(const_lines):
                if 'enum pssicons' in line and '{' in line:
                    enum_start = i
                if enum_start != -1 and '};' in line:
                    enum_end = i
                    break

            if enum_end == -1:
                print("Erro: não foi possível localizar o enum pssicons.")
                continue

            # Determinar a indentação usada no enum (ex: 4 espaços)
            indent = '    '  # padrão
            # Tentar detectar a indentação de um membro existente
            for i in range(enum_start+1, enum_end):
                line = const_lines[i]
                if line.strip() and not line.strip().startswith('//'):
                    # Encontrar espaços antes do primeiro caractere não espaço
                    leading_spaces = len(line) - len(line.lstrip())
                    if leading_spaces > 0:
                        indent = ' ' * leading_spaces
                    break

            # Inserir novo membro na linha antes de '};'
            # Verificar se o último membro já tem vírgula
            last_member_line = enum_end - 1
            # Pular linhas vazias ou comentários
            while last_member_line > enum_start and (const_lines[last_member_line].strip() == '' or const_lines[last_member_line].strip().startswith('//')):
                last_member_line -= 1

            if last_member_line > enum_start:
                last_line_content = const_lines[last_member_line]
                # Se não termina com vírgula, adicionar vírgula no final
                if not last_line_content.rstrip().endswith(','):
                    const_lines[last_member_line] = last_line_content.rstrip() + ',\n'

            # Criar a nova linha do membro
            new_member = f"{indent}{icon_name_upper},\n"
            # Inserir antes da linha que contém '};'
            const_lines.insert(enum_end, new_member)

            # Salvar o arquivo modificado
            with open(const_header_path, 'w', encoding='utf-8') as file:
                file.writelines(const_lines)

            # 2. ATUALIZAR HEADER PRINCIPAL (include/pssicons.h)
            icon_name_cap = icon_name.capitalize()
            with open(header_path, 'r', encoding='utf-8') as file:
                header_content = file.readlines()

            insert_pos = -1
            for i, line in enumerate(header_content):
                if 'static const u16 gPssIcon_' in line:
                    insert_pos = i

            if insert_pos != -1:
                while insert_pos + 1 < len(header_content) and 'static const u16 gPssIcon_' in header_content[insert_pos + 1]:
                    insert_pos += 1

                header_content.insert(insert_pos + 1, f"static const u16 gPssIcon_{icon_name_cap}Gfx[] = INCBIN_U16(\"graphics/pss_icons/{icon_name.lower()}.4bpp\");\n")
                header_content.insert(insert_pos + 2, f"static const u16 gPssIcon_{icon_name_cap}Pal[] = INCBIN_U16(\"graphics/pss_icons/{icon_name.lower()}.gbapal\");\n")

            with open(header_path, 'w', encoding='utf-8') as file:
                file.writelines(header_content)

            # 3. ATUALIZAR ARQUIVO C (src/pssicons.c)
            with open(file_path, 'r', encoding='utf-8') as file:
                c_content = file.readlines()

            table_start = -1
            table_end = -1
            for i, line in enumerate(c_content):
                if 'gCustomPicTable[]' in line:
                    table_start = i
                if table_start != -1 and '};' in line and i > table_start:
                    table_end = i
                    break

            if table_end != -1:
                indent_c = ' ' * 4
                new_entry = f"{indent_c}[{icon_name_upper}] = {{gPssIcon_{icon_name_cap}Gfx, gPssIcon_{icon_name_cap}Pal}},"

                last_entry_line = table_end - 1
                while last_entry_line > table_start and not c_content[last_entry_line].strip():
                    last_entry_line -= 1

                if last_entry_line > table_start and not c_content[last_entry_line].rstrip().endswith(','):
                    c_content[last_entry_line] = c_content[last_entry_line].rstrip() + ',\n'

                c_content.insert(table_end, new_entry + '\n')

                with open(file_path, 'w', encoding='utf-8') as file:
                    file.writelines(c_content)

            print(f"\n✅ '{icon_name_upper}' adicionado com sucesso (ID: {next_id})")
            print(f"👉 Arquivos necessários:")
            print(f"- graphics/pss_icons/{icon_name.lower()}.4bpp")
            print(f"- graphics/pss_icons/{icon_name.lower()}.gbapal\n")

            # Atualizar lista para próxima iteração
            icons.append((icon_name_upper, next_id))
            next_id += 1

        except Exception as e:
            print(f"Erro ao atualizar arquivos: {e}")
            import traceback
            traceback.print_exc()

if __name__ == "__main__":
    print("=== ATUALIZADOR DE PSS ICONS (ENUM SEM VALORES) ===")
    print(f"Arquivo fonte: {file_path}")
    print(f"Header: {header_path}")
    print(f"Constantes (enum): {const_header_path}\n")
    update_pss_files()