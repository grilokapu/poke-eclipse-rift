// Add entries here
// These entries are example entries which you can replace, but they exist to get you started.
// Remember to modify include/constants/help_window.h to include identifiers so they can be used in event scripts.
const struct HelpWindow gHelpWindowInfo[] =
{
    [HELP_START_MENU] =
    {
        .header = COMPOUND_STRING("Information: Pokédex"),
        .desc = COMPOUND_STRING("To access the Pokédex, press {START_BUTTON}\n"
                                "while you're in the overworld!"
                            ),
        .headerFont = FONT_NORMAL,
        .descFont = FONT_NORMAL
    },
    [HELP_MEGA_EVOLUTION] =
    {
        .header = COMPOUND_STRING("Information: Mega Evolution"),
        .desc = COMPOUND_STRING("In battle, press {START_BUTTON} to Mega Evolve!\n\n"
                                "The Pokémon must hold their Mega Stone\n"
                                "to be able to Mega Evolve.\n"
                                "You can only Mega Evolve once per battle."
                            ),
    },
    [HELP_MASTER_BALL] =
    {
        .header = COMPOUND_STRING("Information: Master Ball"),
        .desc = COMPOUND_STRING("There is only one Master Ball in Pokémon;\n"
                                "use it wisely!\n"
                                "Professor Oak suggests using it on a Pokémon\n"
                                "you want to add to your team but are hard to\n"
                                "catch, like a Fearow or Tentacruel!"
                            ),
    },
    [HELP_GIMMIGHOUL_COINS] =
    {
        .header = COMPOUND_STRING("Information: Evolving Gimmighoul into Gholdengo"),
        .desc = COMPOUND_STRING("To evolve Gimmighoul into Gholdengo, you\n"
                                "need to gather 999 {COLOR RED}Gimmighoul Coins{COLOR DARK_GRAY}.\n\n"
                                "You can find Gimmighoul Coins scattered\n"
                                "all around Paldea."
                            ),
        .headerFont = FONT_NARROWER,
    },
    [HELP_EASY_MODE] =
    {
        .header = COMPOUND_STRING("Information: Easy Mode Description"),
        .headerPt = COMPOUND_STRING("Informação: Descrição do Modo Fácil"),
        .headerEs = COMPOUND_STRING("Información: Descripción del Modo Fácil"),
        .desc = COMPOUND_STRING("In Easy Mode, you'll enjoy a more\n"
                                "relaxed and accessible adventure.\n\n"
                                "Trainers and wild Pokémon use\n"
                                "lower levels, ideal for beginners\n"
                                "or a lighter journey."
                            ),
        .descPt = COMPOUND_STRING("No Modo Fácil, você terá uma\n"
                                "aventura mais relaxante e acessível.\n\n"
                                "Treinadores e Pokémon usam níveis\n"
                                "mais baixos, ideal para iniciantes\n"
                                "ou uma jornada mais leve."
                            ),
        .descEs = COMPOUND_STRING("En el Modo Fácil, disfrutarás de\n"
                                "una aventura más relajada y accesible.\n\n"
                                "Entrenadores y Pokémon usan niveles\n"
                                "más bajos, ideal para principiantes\n"
                                "o una experiencia más ligera."
                            ),
    },

    [HELP_NORMAL_MODE] =
    {
        .header = COMPOUND_STRING("Information: Normal Mode Description"),
        .headerPt = COMPOUND_STRING("Informação: Descrição do Modo Normal"),
        .headerEs = COMPOUND_STRING("Información: Descripción del Modo Normal"),
        .desc = COMPOUND_STRING("In Normal Mode, enjoy a balanced\n"
                                "and fair adventure.\n\n"
                                "Trainers and wild Pokémon follow\n"
                                "standard levels, offering the\n"
                                "classic experience."
                            ),
        .descPt = COMPOUND_STRING("No Modo Normal, você terá uma\n"
                                "aventura equilibrada e justa.\n\n"
                                "Treinadores e Pokémon seguem níveis\n"
                                "padrão, oferecendo a experiência\n"
                                "clássica."
                            ),
        .descEs = COMPOUND_STRING("En el Modo Normal, tendrás una\n"
                                "aventura equilibrada y justa.\n\n"
                                "Entrenadores y Pokémon siguen\n"
                                "niveles estándar, ofreciendo la\n"
                                "experiencia clásica."
                            ),
    },

    [HELP_HARD_MODE] =
    {
        .header = COMPOUND_STRING("Information: Hard Mode Description"),
        .headerPt = COMPOUND_STRING("Informação: Descrição do Modo Difícil"),
        .headerEs = COMPOUND_STRING("Información: Descripción del Modo Difícil"),
        .desc = COMPOUND_STRING("In Hard Mode, battles are much\n"
                                "more challenging.\n\n"
                                "AI is at max level, and only four\n"
                                "items may be used per battle.\n\n"
                                "Level Cap is enforced, preventing\n"
                                "overleveling."
                            ),
        .descPt = COMPOUND_STRING("No Modo Difícil, as batalhas são\n"
                                "muito mais desafiadoras.\n\n"
                                "IA no nível máximo, e só quatro\n"
                                "itens podem ser usados.\n\n"
                                "Level Cap ativo, evitando overlevel."
                            ),
        .descEs = COMPOUND_STRING("En el Modo Difícil, las batallas\n"
                                "son más desafiantes.\n\n"
                                "IA al máximo, y solo cuatro\n"
                                "objetos por combate.\n\n"
                                "Level Cap activo, evitando exceso."
                            ),
    },

    [HELP_LEVEL_CAP] =
    {
        .header = COMPOUND_STRING("Information: Level Cap Description"),
        .headerPt = COMPOUND_STRING("Informação: Descrição do Level Cap"),
        .headerEs = COMPOUND_STRING("Información: Descripción del Level Cap"),
        .desc = COMPOUND_STRING("Level Cap limits the max level\n"
                                "your Pokémon can reach per stage.\n\n"
                                "This prevents overleveling and\n"
                                "keeps battles balanced and\n"
                                "challenging."
                            ),
        .descPt = COMPOUND_STRING("Level Cap limita o nível máximo\n"
                                "dos Pokémon por etapa.\n\n"
                                "Evita overlevel e mantém batalhas\n"
                                "equilibradas e desafiadoras."
                            ),
        .descEs = COMPOUND_STRING("Level Cap limita el nivel máximo\n"
                                "por etapa del juego.\n\n"
                                "Evita exceso de nivel y mantiene\n"
                                "batallas equilibradas y difíciles."
                            ),
    },

    [HELP_MINIMAL_GRIND_MODE] =
    {
        .header = COMPOUND_STRING("Information: Minimal Grind Mode"),
        .headerPt = COMPOUND_STRING("Informação: Modo Sem Grind"),
        .headerEs = COMPOUND_STRING("Información: Modo Sin Grind"),
        .desc = COMPOUND_STRING("Minimal Grind Mode reduces the\n"
                                "need for repeated battles.\n\n"
                                "Experience is adjusted so your\n"
                                "team grows steadily without grind.\n\n"
                                "All Pokémon have perfect IVs, and\n"
                                "EV training is not required."
                            ),
        .descPt = COMPOUND_STRING("Modo Sem Grind reduz batalhas\n"
                                "repetidas.\n\n"
                                "A experiência é ajustada para\n"
                                "crescimento constante sem grind.\n\n"
                                "Todos têm IVs perfeitos, sem\n"
                                "necessidade de EVs."
                            ),
        .descEs = COMPOUND_STRING("Modo Sin Grind reduce batallas\n"
                                "repetidas.\n\n"
                                "La experiencia permite progreso\n"
                                "constante sin grind.\n\n"
                                "Todos tienen IVs perfectos y no\n"
                                "requieren EVs."
                            ),
    },
    [HELP_POKE_BALL] =
    {
        .header = COMPOUND_STRING("Information: Poké Ball"),
        .headerPt = COMPOUND_STRING("Informação: Poké Ball"),
        .headerEs = COMPOUND_STRING("Información: Poké Ball"),
        .desc = COMPOUND_STRING("Poké Balls are essential tools for\n"
                                "every Trainer!\n\n"
                                "They allow you to catch wild Pokémon\n"
                                "and add them to your team.\n\n"
                                "Even the most experienced Trainers always\n"
                                "carry a few during their journeys!"
                            ),
        .descPt = COMPOUND_STRING("As Poké Bolas são ferramentas essenciais\n"
                                "para qualquer Treinador!\n\n"
                                "Com elas, você pode capturar Pokémon\n"
                                "selvagens e montar sua equipe.\n\n"
                                "Até os Treinadores mais experientes\n"
                                "sempre levam algumas consigo!"
                            ),
        .descEs = COMPOUND_STRING("¡Las Poké Balls son herramientas\n"
                                "esenciales para todo Entrenador!\n\n"
                                "Te permiten capturar Pokémon salvajes\n"
                                "y formar tu propio equipo.\n\n"
                                "¡Hasta los Entrenadores más expertos\n"
                                "siempre llevan algunas encima!"
                            ),
    },

    [HELP_LUNATIC_MODE] =
    {
        .header = COMPOUND_STRING("Information: Lunatic Mode Description"),
        .headerPt = COMPOUND_STRING("Informação: Descrição do Modo Lunático"),
        .headerEs = COMPOUND_STRING("Información: Descripción del Modo Lunático"),
        .desc = COMPOUND_STRING("In Lunatic Mode, you face the\n"
                                "ultimate challenge!\n\n"
                                "Level Cap and Minimal Grind Mode are\n"
                                "forced on, with maximum AI difficulty.\n\n"
                                "Only for the most dedicated Trainers\n"
                                "seeking the true test of mastery!"
                            ),
        .descPt = COMPOUND_STRING("No Modo Lunático, você enfrenta\n"
                                "o desafio supremo!\n\n"
                                "Level Cap e Modo Sem Grind são\n"
                                "forçados, com IA no máximo.\n\n"
                                "Apenas para Treinadores dedicados\n"
                                "que buscam o verdadeiro teste!"
                            ),
        .descEs = COMPOUND_STRING("En el Modo Lunático, ¡enfrenta\n"
                                "el desafío supremo!\n\n"
                                "Level Cap y Modo Sin Grind son\n"
                                "forzados, con IA al máximo.\n\n"
                                "¡Solo para Entrenadores dedicados\n"
                                "que buscan la prueba definitiva!"
                            ),
    },
    // Add more entries
};
