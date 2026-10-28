# Blocos com três camadas

Esta portabilidade adiciona o tipo de camada `METATILE_LAYER_TYPE_TRIPLE` (valor 3). Um metatile desse tipo desenha simultaneamente nos três backgrounds usados pelo mapa:

| Entradas | Destino | Relação com os sprites |
| --- | --- | --- |
| 0–3 | BG3 | camada inferior |
| 4–7 | BG2 | camada intermediária |
| 8–11 | BG1 | camada superior, na frente dos eventos/objetos |

## Como os dados são organizados

O formato normal do projeto armazena oito entradas de tile por metatile. Para permanecer compatível com o hack original de `triple_layer_blocks.s`, o bloco triplo usa dois metatiles consecutivos no editor:

1. No metatile **N**, coloque a camada inferior nas entradas 0–3 e a intermediária nas entradas 4–7.
2. No metatile **N + 1**, coloque a camada superior nas entradas 0–3.
3. Marque o tipo de camada do metatile **N** como **3** (`TRIPLE`).
4. Use somente o metatile **N** no mapa. O metatile **N + 1** funciona como armazenamento auxiliar da terceira camada.

Em forma compacta:

```text
metatile N      [ BG3: 0 1 2 3 ][ BG2: 4 5 6 7 ]  tipo = 3
metatile N + 1  [ BG1: 0 1 2 3 ][ não utilizado ]
```

As quatro entradas de cada camada seguem a disposição 2×2 habitual:

```text
0 1
2 3
```

## Exemplo de uso

Para criar uma ponte com água embaixo, piso no meio e corrimão sobre o jogador:

1. Escolha dois IDs consecutivos, por exemplo `0x120` e `0x121`.
2. Em `0x120`, desenhe a água na camada inferior e o piso na camada intermediária.
3. Em `0x121`, desenhe o corrimão nas quatro primeiras posições.
4. Defina o layer type de `0x120` como 3.
5. Pinte o mapa com `0x120`; não pinte com `0x121`.

O motor buscará automaticamente os dados de `0x121` ao desenhar `0x120`.

## Cuidados

- Reserve sempre o metatile seguinte; ele faz parte do bloco triplo.
- Não use como triplo o último metatile de um tileset, pois não existe uma entrada seguinte válida no mesmo conjunto de dados.
- A colisão e o comportamento usados no mapa continuam sendo os atributos do metatile **N**.
- Tiles transparentes devem usar a entrada transparente configurada pelo tileset, como em qualquer outra camada.
- Para voltar ao comportamento padrão, altere o layer type para 0 (`NORMAL`), 1 (`COVERED`) ou 2 (`SPLIT`).

## Implementação

A enumeração fica em `include/global.fieldmap.h`. O desenho ocorre em `DrawMetatile`, em `src/field_camera.c`, usando os buffers `gOverworldTilemapBuffer_Bg3`, `gOverworldTilemapBuffer_Bg2` e `gOverworldTilemapBuffer_Bg1`. A implementação em C substitui os endereços fixos e o hook Thumb do patch original por símbolos nativos da decompilação.
