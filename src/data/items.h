#if I_USE_EVO_HELD_ITEMS_FROM_BAG == TRUE
    #define EVO_HELD_ITEM_TYPE ITEM_USE_PARTY_MENU
    #define EVO_HELD_ITEM_FIELD_FUNC ItemUseOutOfBattle_EvolutionStone
#else
    #define EVO_HELD_ITEM_TYPE ITEM_USE_BAG_MENU
    #define EVO_HELD_ITEM_FIELD_FUNC ItemUseOutOfBattle_CannotUse
#endif

#define GEM_BOOST_PARAM ((I_GEM_BOOST_POWER >= GEN_6) ? 30 : 50)
#define TYPE_BOOST_PARAM ((I_TYPE_BOOST_POWER >= GEN_4) ? 20 : 10) // For non Pokémon-specific type-boosting held items.
#define POWER_ITEM_BOOST ((I_POWER_ITEM_BOOST >= GEN_7) ? 8 : 4)

#define X_ITEM_STAGES ((B_X_ITEMS_BUFF >= GEN_7) ? 2 : 1)

#define TREASURE_FACTOR ((I_SELL_VALUE_FRACTION >= GEN_9) ? 2 : 1)

#define ITEM_NAME(str) COMPOUND_STRING_SIZE_LIMIT(str, ITEM_NAME_LENGTH)
#define ITEM_PLURAL_NAME(str) COMPOUND_STRING_SIZE_LIMIT(str, ITEM_NAME_PLURAL_LENGTH)

// Shared Item Description entries

static const u8 sFullHealDesc[]       = _("Heals all the\n"
                                          "status problems of\n"
                                          "one Pokémon.");

static const u8 sPokeDollDesc[]       = _("Use to flee from\n"
                                          "any battle with a\n"
                                          "wild Pokémon.");

static const u8 sMaxReviveDesc[]      = _("Revives a fainted\n"
                                          "Pokémon with all\n"
                                          "its HP.");

static const u8 sHealthFeatherDesc[]  = _("An item that raises\n"
                                          "the base HP of a\n"
                                          "Pokémon.");

static const u8 sMuscleFeatherDesc[]  = _("An item that raises\n"
                                          "the base Atk. of a\n"
                                          "Pokémon.");

static const u8 sResistFeatherDesc[]  = _("An item that raises\n"
                                          "the base Def. of a\n"
                                          "Pokémon.");

static const u8 sGeniusFeatherDesc[]  = _("An item that raises\n"
                                          "the base Sp. Atk.\n"
                                          "of a Pokémon.");

static const u8 sCleverFeatherDesc[]  = _("An item that raises\n"
                                          "the base Sp. Def.\n"
                                          "of a Pokémon.");

static const u8 sSwiftFeatherDesc[]   = _("An item that raises\n"
                                          "the base Speed of a\n"
                                          "Pokémon.");

static const u8 sBigMushroomDesc[]    = _("A rare mushroom\n"
                                          "that would sell at\n"
                                          "a high price.");

static const u8 sShardsDesc[]         = _("A shard from an\n"
                                          "ancient item. Can\n"
                                          "be sold cheaply.");

static const u8 sRootFossilDesc[]     = _("A fossil of an\n"
                                          "ancient, seafloor-\n"
                                          "dwelling Pokémon.");

static const u8 sFossilizedFishDesc[] = _("A fossil of an\n"
                                          "ancient, sea-\n"
                                          "dwelling Pokémon.");

static const u8 sBeadMailDesc[]       = _("Mail featuring a\n"
                                          "sketch of the\n"
                                          "holding Pokémon.");

static const u8 sEvolutionStoneDesc[] = _("Makes certain\n"
                                          "species of Pokémon\n"
                                          "evolve.");

static const u8 sNectarDesc[]         = _("Flower nectar that\n"
                                          "changes the form of\n"
                                          "certain Pokémon.");

static const u8 sCharizarditeDesc[]   = _("This stone enables\n"
                                          "Charizard to Mega\n"
                                          "Evolve in battle.");

static const u8 sMewtwoniteDesc[]     = _("This stone enables\n"
                                          "Mewtwo to Mega\n"
                                          "Evolve in battle.");

static const u8 sRaichuniteDesc[]     = _("This stone enables\n"
                                          "Raichu to Mega\n"
                                          "Evolve in battle.");

static const u8 sAbsoliteDesc[]       = _("This stone enables\n"
                                          "Absol to Mega\n"
                                          "Evolve in battle.");

static const u8 sGarchompiteDesc[]    = _("This stone enables\n"
                                          "Garchomp to Mega\n"
                                          "Evolve in battle.");

static const u8 sLucarioniteDesc[]    = _("This stone enables\n"
                                          "Lucario to Mega\n"
                                          "Evolve in battle.");

static const u8 sSeaIncenseDesc[]     = _("A hold item that\n"
                                          "mildly boosts\n"
                                          "Water-type moves.");

static const u8 sOddIncenseDesc[]     = _("A hold item that\n"
                                          "boosts Psychic-\n"
                                          "type moves.");

static const u8 sRockIncenseDesc[]    = _("A hold item that\n"
                                          "boosts the power of\n"
                                          "Rock-type moves.");

static const u8 sFullIncenseDesc[]    = _("A held item that\n"
                                          "makes the holder\n"
                                          "move slower.");

static const u8 sRoseIncenseDesc[]    = _("A hold item that\n"
                                          "boosts the power of\n"
                                          "Grass-type moves.");

static const u8 sLuckIncenseDesc[]    = _("Doubles money in\n"
                                          "battle if the\n"
                                          "holder takes part.");

static const u8 sPureIncenseDesc[]    = _("A hold item that\n"
                                          "helps repel wild\n"
                                          "Pokémon.");

static const u8 sKingsRockDesc[]      = _("A hold item that\n"
                                          "may cause flinching\n"
                                          "when the foe is\n"
                                          "hit.");

static const u8 sFigyBerryDesc[]      = _("A hold item that\n"
                                          "heals HP but may\n"
                                          "confuse.");

const u8 gQuestionMarksItemName[] = _("????????");

static const u8 sQuestionMarksDesc[]  = _("?????");

static const u8 sKeyToRoomDesc[]      = _("A key that opens a\n"
                                          "door inside the\n"
                                          "Abandoned Ship.");

static const u8 sTeraShardDesc[]      = _("These shards may\n"
                                          "form when a Tera\n"
                                          "Pokémon faints.");

static const u8 sGenericMulchDesc[]   = _("A fertilizer that\n"
                                          "is unsuitable for\n"
                                          "local soil.");

const struct ItemInfo gItemsInfo[] =
{
    [ITEM_NONE] =
    {
        .name = gQuestionMarksItemName,
        .nombre = gQuestionMarksItemName,
        .price = 0,
        .description = sQuestionMarksDesc,
        .descricao = COMPOUND_STRING(
            "?????"),
        .descricion = COMPOUND_STRING(
            "?????"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_UNCATEGORIZED,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_QuestionMark,
        .iconPalette = gItemIconPalette_QuestionMark,
    },

// Poké Balls

    [ITEM_STRANGE_BALL] =
    {
        .name = ITEM_NAME("Strange Ball"),
        .nombre = ITEM_NAME("bola extrana"),
        .price = 0,
        .description = COMPOUND_STRING(
            "An rare Ball warped\n"
            "via space and time."),
        .descricao = COMPOUND_STRING(
            "Uma bola rara se\n"
            "veio no espaco e no\n"
            "tempo."),
        .descricion = COMPOUND_STRING(
            "Una bola inusual\n"
            "viajó través del\n"
            "espacio y el."),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_STRANGE,
        .iconPic = gItemIcon_StrangeBall,
        .iconPalette = gItemIconPalette_StrangeBall,
    },

    [ITEM_POKE_BALL] =
    {
        .name = ITEM_NAME("Poké Ball"),
        .nombre = ITEM_NAME("Pokebola"),
        .price = 200,
        .description = COMPOUND_STRING(
            "A tool used for\n"
            "catch wild Pokémon."),
        .descricao = COMPOUND_STRING(
            "Uma ferramenta\n"
            "usada para pegar\n"
            "Pokémon selv."),
        .descricion = COMPOUND_STRING(
            "Una herramienta\n"
            "utilizada para\n"
            "pegar Pokémon."),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_POKE,
        .iconPic = gItemIcon_PokeBall,
        .iconPalette = gItemIconPalette_PokeBall,
    },

    [ITEM_GREAT_BALL] =
    {
        .name = ITEM_NAME("Great Ball"),
        .nombre = ITEM_NAME("Gran bola"),
        .price = 600,
        .description = COMPOUND_STRING(
            "A good Ball with a\n"
            "higher catch rate\n"
            "than a Poké Ball."),
        .descricao = COMPOUND_STRING(
            "Uma boa bola com\n"
            "uma taxa de pega\n"
            "maior que uma."),
        .descricion = COMPOUND_STRING(
            "Una buena Bola con\n"
            "una tasa de pega\n"
            "mayor que una Poké."),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_GREAT,
        .iconPic = gItemIcon_GreatBall,
        .iconPalette = gItemIconPalette_GreatBall,
    },

    [ITEM_ULTRA_BALL] =
    {
        .name = ITEM_NAME("Ultra Ball"),
        .nombre = ITEM_NAME("ultra bola"),
        .price = (I_PRICE >= GEN_7) ? 800 : 1200,
        .description = COMPOUND_STRING(
            "A better Ball with\n"
            "a higher catch rate\n"
            "than a Great Ball."),
        .descricao = COMPOUND_STRING(
            "Uma bola melhor com\n"
            "taxa pega mais alta"),
        .descricion = COMPOUND_STRING(
            "Una mejor pelota\n"
            "con una tasa pega\n"
            "más alta una."),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_ULTRA,
        .iconPic = gItemIcon_UltraBall,
        .iconPalette = gItemIconPalette_UltraBall,
    },

    [ITEM_MASTER_BALL] =
    {
        .name = ITEM_NAME("Master Ball"),
        .nombre = ITEM_NAME("bola maestra"),
        .price = 0,
        .description = COMPOUND_STRING(
            "The best Ball that\n"
            "catches a Pokémon\n"
            "without fail."),
        .descricao = COMPOUND_STRING(
            "A melhor bola que\n"
            "pega um Pokémon sem\n"
            "falhar."),
        .descricion = COMPOUND_STRING(
            "La mejor Bola que\n"
            "atrapa un Pokémon\n"
            "sin falta."),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_MASTER,
        .iconPic = gItemIcon_MasterBall,
        .iconPalette = gItemIconPalette_MasterBall,
    },

    [ITEM_PREMIER_BALL] =
    {
        .name = ITEM_NAME("Premier Ball"),
        .nombre = ITEM_NAME("Primera bola"),
        .price = (I_PRICE >= GEN_7) ? 20 : 200,
        .description = COMPOUND_STRING(
            "A rare Ball made in\n"
            "commemoration of\n"
            "some event."),
        .descricao = COMPOUND_STRING(
            "Uma rara Bola feita\n"
            "em comemoração a\n"
            "algum evento."),
        .descricion = COMPOUND_STRING(
            "Un baile poco común\n"
            "realizado en\n"
            "conmemoración de."),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_PREMIER,
        .iconPic = gItemIcon_PremierBall,
        .iconPalette = gItemIconPalette_PremierBall,
    },

    [ITEM_HEAL_BALL] =
    {
        .name = ITEM_NAME("Heal Ball"),
        .nombre = ITEM_NAME("Bola de curacion"),
        .price = 300,
        .description = COMPOUND_STRING(
            "A remedial Ball\n"
            "that heals caught\n"
            "Pokémon."),
        .descricao = COMPOUND_STRING(
            "Uma bola corretiva\n"
            "que cura Pokémon\n"
            "capturados."),
        .descricion = COMPOUND_STRING(
            "Una bola de\n"
            "recuperación que\n"
            "cura Pokémon."),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_HEAL,
        .iconPic = gItemIcon_HealBall,
        .iconPalette = gItemIconPalette_HealBall,
    },

    [ITEM_NET_BALL] =
    {
        .name = ITEM_NAME("Net Ball"),
        .nombre = ITEM_NAME("bola neta"),
        .price = 1000,
        .description = COMPOUND_STRING(
            "A Ball that works\n"
            "well on Water- and\n"
            "Bug-type Pokémon."),
        .descricao = COMPOUND_STRING(
            "Uma bola que age\n"
            "bem em Pokémon do\n"
            "tipo Água"),
        .descricion = COMPOUND_STRING(
            "Una bola que age\n"
            "bien con Pokémon de\n"
            "tipo Agua"),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_NET,
        .iconPic = gItemIcon_NetBall,
        .iconPalette = gItemIconPalette_NetBall,
    },

    [ITEM_NEST_BALL] =
    {
        .name = ITEM_NAME("Nest Ball"),
        .nombre = ITEM_NAME("Bola nido"),
        .price = 1000,
        .description = COMPOUND_STRING(
            "A Ball that works\n"
            "better on weaker\n"
            "Pokémon."),
        .descricao = COMPOUND_STRING(
            "Uma bola que age\n"
            "melhor em Pokémon\n"
            "mais fracos."),
        .descricion = COMPOUND_STRING(
            "Una Bola que age\n"
            "mejor con Pokémon\n"
            "más débiles."),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_NEST,
        .iconPic = gItemIcon_NestBall,
        .iconPalette = gItemIconPalette_NestBall,
    },

    [ITEM_DIVE_BALL] =
    {
        .name = ITEM_NAME("Dive Ball"),
        .nombre = ITEM_NAME("Bola de buceo"),
        .price = 1000,
        .description = COMPOUND_STRING(
            "A Ball that works\n"
            "better on Pokémon\n"
            "on the ocean floor."),
        .descricao = COMPOUND_STRING(
            "Uma bola que age\n"
            "melhor em Pokémon\n"
            "no fundo do."),
        .descricion = COMPOUND_STRING(
            "Una Bola que age\n"
            "mejor con Pokémon\n"
            "en el fondo."),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_DIVE,
        .iconPic = gItemIcon_DiveBall,
        .iconPalette = gItemIconPalette_DiveBall,
    },

    [ITEM_DUSK_BALL] =
    {
        .name = ITEM_NAME("Dusk Ball"),
        .nombre = ITEM_NAME("Bola del noche"),
        .price = 1000,
        .description = COMPOUND_STRING(
            "Works well if used\n"
            "in a dark place."),
        .descricao = COMPOUND_STRING(
            "Funciona bem se\n"
            "usado em um local\n"
            "escuro."),
        .descricion = COMPOUND_STRING(
            "Funciona bien si se\n"
            "usa en un lugar\n"
            "oscuro."),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_DUSK,
        .iconPic = gItemIcon_DuskBall,
        .iconPalette = gItemIconPalette_DuskBall,
    },

    [ITEM_TIMER_BALL] =
    {
        .name = ITEM_NAME("Timer Ball"),
        .nombre = ITEM_NAME("Timer Ball"),
        .price = 1000,
        .description = COMPOUND_STRING(
            "A Ball that gains\n"
            "power in battles\n"
            "taking many turns."),
        .descricao = COMPOUND_STRING(
            "Uma bola que ganha\n"
            "poder em batalhas\n"
            "que duram vários."),
        .descricion = COMPOUND_STRING(
            "Una Bola que gana\n"
            "poder en batallas\n"
            "que duran muchos."),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_TIMER,
        .iconPic = gItemIcon_TimerBall,
        .iconPalette = gItemIconPalette_RepeatBall,
    },

    [ITEM_QUICK_BALL] =
    {
        .name = ITEM_NAME("Quick Ball"),
        .nombre = ITEM_NAME("Bola rapida"),
        .price = 1000,
        .description = COMPOUND_STRING(
            "Works well if used\n"
            "on the first turn."),
        .descricao = COMPOUND_STRING(
            "Funciona bem se\n"
            "usado no primeiro\n"
            "turno."),
        .descricion = COMPOUND_STRING(
            "Funciona bien si se\n"
            "usa en el primer\n"
            "turno."),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_QUICK,
        .iconPic = gItemIcon_QuickBall,
        .iconPalette = gItemIconPalette_QuickBall,
    },

    [ITEM_REPEAT_BALL] =
    {
        .name = ITEM_NAME("Repeat Ball"),
        .nombre = ITEM_NAME("Repetir bola"),
        .price = 1000,
        .description = COMPOUND_STRING(
            "A Ball that works\n"
            "better on Pokémon\n"
            "caught before."),
        .descricao = COMPOUND_STRING(
            "Uma bola que age\n"
            "melhor em Pokémon\n"
            "capturados."),
        .descricion = COMPOUND_STRING(
            "Una Bola que age\n"
            "mejor con Pokémon\n"
            "capturados."),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_REPEAT,
        .iconPic = gItemIcon_RepeatBall,
        .iconPalette = gItemIconPalette_RepeatBall,
    },

    [ITEM_LUXURY_BALL] =
    {
        .name = ITEM_NAME("Luxury Ball"),
        .nombre = ITEM_NAME("Bola de lujo"),
        .price = (I_PRICE >= GEN_8) ? 3000 : 1000,
        .description = COMPOUND_STRING(
            "A cozy Ball that\n"
            "makes Pokémon more\n"
            "friendly."),
        .descricao = COMPOUND_STRING(
            "Uma bola\n"
            "aconchegante que\n"
            "torna os Pokémon."),
        .descricion = COMPOUND_STRING(
            "Una bola acogedora\n"
            "que hace que los\n"
            "Pokémon sean más."),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_LUXURY,
        .iconPic = gItemIcon_LuxuryBall,
        .iconPalette = gItemIconPalette_LuxuryBall,
    },

    [ITEM_LEVEL_BALL] =
    {
        .name = ITEM_NAME("Level Ball"),
        .nombre = ITEM_NAME("Bola de nivel"),
        .price = (I_PRICE >= GEN_7) ? 0 : 300,
        .description = COMPOUND_STRING(
            "A Ball that works\n"
            "well on lower level\n"
            "Pokémon."),
        .descricao = COMPOUND_STRING(
            "Uma bola que age\n"
            "bem em Pokémon de\n"
            "nível."),
        .descricion = COMPOUND_STRING(
            "Una Bola que age\n"
            "bien con Pokémon de\n"
            "nivel."),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_LEVEL,
        .iconPic = gItemIcon_LevelBall,
        .iconPalette = gItemIconPalette_LevelBall,
    },

    [ITEM_LURE_BALL] =
    {
        .name = ITEM_NAME("Lure Ball"),
        .nombre = ITEM_NAME("Bola de senuelo"),
        .price = (I_PRICE >= GEN_7) ? 0 : 300,
        .description = COMPOUND_STRING(
            "A Ball that works\n"
            "well on fished up\n"
            "Pokémon."),
        .descricao = COMPOUND_STRING(
            "Uma bola que age\n"
            "bem em Pokémon\n"
            "pescados."),
        .descricion = COMPOUND_STRING(
            "Una bola que age\n"
            "bien con Pokémon\n"
            "pescados."),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_LURE,
        .iconPic = gItemIcon_LureBall,
        .iconPalette = gItemIconPalette_LureBall,
    },

    [ITEM_MOON_BALL] =
    {
        .name = ITEM_NAME("Moon Ball"),
        .nombre = ITEM_NAME("bola lunar"),
        .price = (I_PRICE >= GEN_7) ? 0 : 300,
        .description = COMPOUND_STRING(
            "A Ball that works\n"
            "well on Moon Stone\n"
            "users."),
        .descricao = COMPOUND_STRING(
            "Uma bola que age\n"
            "bem em usuários da\n"
            "Moon."),
        .descricion = COMPOUND_STRING(
            "Una bola que age\n"
            "bien con los\n"
            "usuarios de Moon"),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_MOON,
        .iconPic = gItemIcon_MoonBall,
        .iconPalette = gItemIconPalette_MoonBall,
    },

    [ITEM_FRIEND_BALL] =
    {
        .name = ITEM_NAME("Friend Ball"),
        .nombre = ITEM_NAME("bola amiga"),
        .price = (I_PRICE >= GEN_7) ? 0 : 300,
        .description = COMPOUND_STRING(
            "A Ball that makes a\n"
            "Pokémon friendly\n"
            "when caught."),
        .descricao = COMPOUND_STRING(
            "Uma bola que torna\n"
            "um Pokémon amigável\n"
            "quando capturado."),
        .descricion = COMPOUND_STRING(
            "Una bola que hace\n"
            "que un Pokémon sea\n"
            "amigable cuando lo."),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_FRIEND,
        .iconPic = gItemIcon_FriendBall,
        .iconPalette = gItemIconPalette_FriendBall,
    },

    [ITEM_LOVE_BALL] =
    {
        .name = ITEM_NAME("Love Ball"),
        .nombre = ITEM_NAME("bola de amor"),
        .price = (I_PRICE >= GEN_7) ? 0 : 300,
        .description = COMPOUND_STRING(
            "Works well on\n"
            "Pokémon of the\n"
            "opposite gender."),
        .descricao = COMPOUND_STRING(
            "Funciona bem em\n"
            "Pokémon do sexo\n"
            "oposto."),
        .descricion = COMPOUND_STRING(
            "Funciona bien con\n"
            "Pokémon del sexo\n"
            "opuesto."),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_LOVE,
        .iconPic = gItemIcon_LoveBall,
        .iconPalette = gItemIconPalette_LoveBall,
    },

    [ITEM_FAST_BALL] =
    {
        .name = ITEM_NAME("Fast Ball"),
        .nombre = ITEM_NAME("bola rapida"),
        .price = (I_PRICE >= GEN_7) ? 0 : 300,
        .description = COMPOUND_STRING(
            "Works well on very\n"
            "fast Pokémon."),
        .descricao = COMPOUND_STRING(
            "Funciona bem em\n"
            "Pokémon muito\n"
            "rápidos."),
        .descricion = COMPOUND_STRING(
            "Funciona bien en\n"
            "Pokémon muy\n"
            "rápidos."),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_FAST,
        .iconPic = gItemIcon_FastBall,
        .iconPalette = gItemIconPalette_FastBall,
    },

    [ITEM_HEAVY_BALL] =
    {
        .name = ITEM_NAME("Heavy Ball"),
        .nombre = ITEM_NAME("Bola pesada"),
        .price = (I_PRICE >= GEN_7) ? 0 : 300,
        .description = COMPOUND_STRING(
            "Works well on very\n"
            "heavy Pokémon."),
        .descricao = COMPOUND_STRING(
            "Funciona bem em\n"
            "Pokémon muito\n"
            "pesados."),
        .descricion = COMPOUND_STRING(
            "Funciona bien en\n"
            "Pokémon muy\n"
            "pesados."),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_HEAVY,
        .iconPic = gItemIcon_HeavyBall,
        .iconPalette = gItemIconPalette_HeavyBall,
    },

    [ITEM_DREAM_BALL] =
    {
        .name = ITEM_NAME("Dream Ball"),
        .nombre = ITEM_NAME("Bola de ensueno"),
        .price = 0,
        .description = COMPOUND_STRING(
        #if B_DREAM_BALL_MODIFIER >= GEN_8
            "A Ball that works\n"
            "well on sleeping\n"
            "Pokémon."),
        .descricao = COMPOUND_STRING(
            "Uma bola que age\n"
            "bem em Pokémon\n"
            "adormecidos."),
        .descricion = COMPOUND_STRING(
            "Una bola que age\n"
            "bien con Pokémon\n"
            "dormidos."),
        #else
            "A Poké Ball used in\n"
            "the Entree Forest."),
        #endif
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_DREAM,
        .iconPic = gItemIcon_DreamBall,
        .iconPalette = gItemIconPalette_DreamBall,
    },

    [ITEM_SAFARI_BALL] =
    {
        .name = ITEM_NAME("Safari Ball"),
        .nombre = ITEM_NAME("Bola de safari"),
        .price = 0,
        .description = COMPOUND_STRING(
            "A special Ball that\n"
            "is used only in the\n"
            "Safari Zone."),
        .descricao = COMPOUND_STRING(
            "Uma bola esp. usada\n"
            "apenas na Safari\n"
            "Zone."),
        .descricion = COMPOUND_STRING(
            "Una pelota esp. que\n"
            "se usa únicamente\n"
            "en la."),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_SAFARI,
        .iconPic = gItemIcon_SafariBall,
        .iconPalette = gItemIconPalette_SafariBall,
    },

    [ITEM_SPORT_BALL] =
    {
        .name = ITEM_NAME("Sport Ball"),
        .nombre = ITEM_NAME("Pelota deportiva"),
        .price = (I_PRICE <= GEN_3 || I_PRICE >= GEN_9) ? 0 : 300,
        .description = COMPOUND_STRING(
            "A special Ball used\n"
            "in the Bug-\n"
            "Catching Contest."),
        .descricao = COMPOUND_STRING(
            "Uma bola esp. usada\n"
            "no concurso de pega\n"
            "de insetos."),
        .descricion = COMPOUND_STRING(
            "Una pelota esp.\n"
            "utilizada en el\n"
            "concurso de pega."),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_SPORT,
        .iconPic = gItemIcon_SportBall,
        .iconPalette = gItemIconPalette_SportBall,
    },

    [ITEM_PARK_BALL] =
    {
        .name = ITEM_NAME("Park Ball"),
        .nombre = ITEM_NAME("pelota de parque"),
        .price = 0,
        .description = COMPOUND_STRING(
            "A special Ball for\n"
            "the Pal Park."),
        .descricao = COMPOUND_STRING(
            "Um baile esp. para\n"
            "o Pal Park."),
        .descricion = COMPOUND_STRING(
            "Un Baile esp. para\n"
            "el Parque Pal."),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_PARK,
        .iconPic = gItemIcon_ParkBall,
        .iconPalette = gItemIconPalette_ParkBall,
    },

    [ITEM_BEAST_BALL] =
    {
        .name = ITEM_NAME("Beast Ball"),
        .nombre = ITEM_NAME("Bola Bestia"),
        .price = 0,
        .description = COMPOUND_STRING(
            "A Ball designed to\n"
            "catch Ultra Beasts."),
        .descricao = COMPOUND_STRING(
            "Uma bola projetada\n"
            "para pegar Ultra\n"
            "Beasts."),
        .descricion = COMPOUND_STRING(
            "Una pelota diseñada\n"
            "para atrapar\n"
            "Ultrabestias."),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_BEAST,
        .iconPic = gItemIcon_BeastBall,
        .iconPalette = gItemIconPalette_BeastBall,
    },

    [ITEM_CHERISH_BALL] =
    {
        .name = ITEM_NAME("Cherish Ball"),
        .nombre = ITEM_NAME("Apreciar la bola"),
        .price = 0,
        .description = COMPOUND_STRING(
            "A rare Ball made in\n"
            "commemoration of\n"
            "some event."),
        .descricao = COMPOUND_STRING(
            "Uma rara Bola feita\n"
            "em comemoração a\n"
            "algum evento."),
        .descricion = COMPOUND_STRING(
            "Un baile poco común\n"
            "realizado en\n"
            "conmemoración de."),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_CHERISH,
        .iconPic = gItemIcon_CherishBall,
        .iconPalette = gItemIconPalette_CherishBall,
    },

// Medicine

    [ITEM_POTION] =
    {
        .name = ITEM_NAME("Potion"),
        .nombre = ITEM_NAME("Pocion"),
        .price = (I_PRICE >= GEN_7) ? 200 : 300,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "Restores the HP of\n"
            "a Pokémon by 20\n"
            "points."),
        .descricao = COMPOUND_STRING(
            "Restaura o HP de um\n"
            "Pokémon em 20\n"
            "pontos."),
        .descricion = COMPOUND_STRING(
            "Restaura el HP de\n"
            "un Pokémon en 20\n"
            "puntos."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HEALTH_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_RESTORE_HP,
        .effect = gItemEffect_Potion,
        .flingPower = 30,
        .iconPic = gItemIcon_Potion,
        .iconPalette = gItemIconPalette_Potion,
    },

    [ITEM_SUPER_POTION] =
    {
        .name = ITEM_NAME("Super Potion"),
        .nombre = ITEM_NAME("Super pocion"),
        .price = 700,
        .holdEffectParam = 60,
        .description = COMPOUND_STRING(
            "Restores the HP of\n"
            "a Pokémon by"
        #if I_HEALTH_RECOVERY >= GEN_7
            "60 points."),
        .descricao = COMPOUND_STRING(
            "Restaura o HP de um\n"
            "Pokémon em 60\n"
            "pontos."),
        .descricion = COMPOUND_STRING(
            "Restaura el HP de\n"
            "un Pokémon en 60\n"
            "puntos."),
        #else
            "50 points."),
        #endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HEALTH_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_RESTORE_HP,
        .effect = gItemEffect_SuperPotion,
        .flingPower = 30,
        .iconPic = gItemIcon_Potion,
        .iconPalette = gItemIconPalette_SuperPotion,
    },

    [ITEM_HYPER_POTION] =
    {
        .name = ITEM_NAME("Hyper Potion"),
        .nombre = ITEM_NAME("Hiperpocion"),
        .price = (I_PRICE >= GEN_2 && I_PRICE <= GEN_6) ? 1200 : 1500,
        .holdEffectParam = 120,
        .description = COMPOUND_STRING(
            "Restores the HP of\n"
            "a Pokémon by"
        #if I_HEALTH_RECOVERY >= GEN_7
            "120 points."),
        .descricao = COMPOUND_STRING(
            "Restaura o HP de um\n"
            "Pokémon em 120\n"
            "pontos."),
        .descricion = COMPOUND_STRING(
            "Restaura el HP de\n"
            "un Pokémon en 120\n"
            "puntos."),
        #else
            "200 points."),
        #endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HEALTH_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_RESTORE_HP,
        .effect = gItemEffect_HyperPotion,
        .flingPower = 30,
        .iconPic = gItemIcon_Potion,
        .iconPalette = gItemIconPalette_HyperPotion,
    },

    [ITEM_MAX_POTION] =
    {
        .name = ITEM_NAME("Max Potion"),
        .nombre = ITEM_NAME("Pocion maxima"),
        .price = 2500,
        .holdEffectParam = 255,
        .description = COMPOUND_STRING(
            "Fully heals the HP\n"
            "of a Pokémon."),
        .descricao = COMPOUND_STRING(
            "Restaura totalmente\n"
            "o HP de um Pokémon."),
        .descricion = COMPOUND_STRING(
            "Restaura\n"
            "completamente el HP\n"
            "de un Pokémon."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HEALTH_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_RESTORE_HP,
        .effect = gItemEffect_MaxPotion,
        .flingPower = 30,
        .iconPic = gItemIcon_LargePotion,
        .iconPalette = gItemIconPalette_MaxPotion,
    },

    [ITEM_FULL_RESTORE] =
    {
        .name = ITEM_NAME("Full Restore"),
        .nombre = ITEM_NAME("Full Restore"),
        .price = 3000,
        .holdEffectParam = 255,
        .description = COMPOUND_STRING(
            "Fully heals the HP\n"
            "and status of a\n"
            "Pokémon."),
        .descricao = COMPOUND_STRING(
            "Restaura totalmente\n"
            "o HP e o status de\n"
            "um Pokémon."),
        .descricion = COMPOUND_STRING(
            "Restaura\n"
            "completamente el HP\n"
            "y el estado de un."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HEALTH_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_HEAL_AND_CURE_STATUS,
        .effect = gItemEffect_FullRestore,
        .flingPower = 30,
        .iconPic = gItemIcon_LargePotion,
        .iconPalette = gItemIconPalette_FullRestore,
    },

    [ITEM_REVIVE] =
    {
        .name = ITEM_NAME("Revive"),
        .nombre = ITEM_NAME("revivir"),
        .price = (I_PRICE >= GEN_7) ? 2000 : 1500,
        .description = COMPOUND_STRING(
            "Revives a fainted\n"
            "Pokémon with half\n"
            "its HP."),
        .descricao = COMPOUND_STRING(
            "Revive um Pokémon\n"
            "desmaiado com\n"
            "metade do seu HP."),
        .descricion = COMPOUND_STRING(
            "Revive a un Pokémon\n"
            "desmayado con la\n"
            "mitad de su HP."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HEALTH_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_REVIVE,
        .effect = gItemEffect_Revive,
        .flingPower = 30,
        .iconPic = gItemIcon_Revive,
        .iconPalette = gItemIconPalette_Revive,
    },

    [ITEM_MAX_REVIVE] =
    {
        .name = ITEM_NAME("Max Revive"),
        .nombre = ITEM_NAME("Revivir maximo"),
        .price = 4000,
        .description = sMaxReviveDesc,
        .descricao = COMPOUND_STRING(
            "Revive um Pokémon\n"
            "desmaiado com todo\n"
            "o seu HP."),
        .descricion = COMPOUND_STRING(
            "Revive a un Pokémon\n"
            "desmayado con todos\n"
            "sus HP."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HEALTH_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_REVIVE,
        .effect = gItemEffect_MaxRevive,
        .flingPower = 30,
        .iconPic = gItemIcon_MaxRevive,
        .iconPalette = gItemIconPalette_Revive,
    },

    [ITEM_FRESH_WATER] =
    {
        .name = ITEM_NAME("Fresh Water"),
        .nombre = ITEM_NAME("agua dulce"),
        .price = 200,
        .holdEffectParam = 30,
        .description = COMPOUND_STRING(
            "A mineral water\n"
            "that heals HP"
        #if I_HEALTH_RECOVERY >= GEN_7
            "by 30 points."),
        .descricao = COMPOUND_STRING(
            "Uma água mineral\n"
            "que cura o HP em 30\n"
            "pontos."),
        .descricion = COMPOUND_STRING(
            "Un agua mineral que\n"
            "cura HP en 30\n"
            "puntos."),
        #else
            "by 50 points."),
        #endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HEALTH_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_RESTORE_HP,
        .effect = gItemEffect_FreshWater,
        .flingPower = 30,
        .iconPic = gItemIcon_FreshWater,
        .iconPalette = gItemIconPalette_FreshWater,
    },

    [ITEM_SODA_POP] =
    {
        .name = ITEM_NAME("Soda Pop"),
        .nombre = ITEM_NAME("refresco"),
        .price = 300,
        .holdEffectParam = 50,
        .description = COMPOUND_STRING(
            "A fizzy soda drink\n"
            "that heals HP"
        #if I_HEALTH_RECOVERY >= GEN_7
            "by 50 points."),
        .descricao = COMPOUND_STRING(
            "Um refrigerante com\n"
            "gás que cura o HP\n"
            "em 50 pontos."),
        .descricion = COMPOUND_STRING(
            "Una bebida gaseosa\n"
            "que cura HP en 50\n"
            "puntos."),
        #else
            "by 60 points."),
        #endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HEALTH_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_RESTORE_HP,
        .effect = gItemEffect_SodaPop,
        .flingPower = 30,
        .iconPic = gItemIcon_SodaPop,
        .iconPalette = gItemIconPalette_SodaPop,
    },

    [ITEM_LEMONADE] =
    {
        .name = ITEM_NAME("Lemonade"),
        .nombre = ITEM_NAME("limonada"),
        .price = (I_PRICE >= GEN_7) ? 400 : 350,
        .holdEffectParam = 70,
        .description = COMPOUND_STRING(
            "A very sweet drink\n"
            "that heals HP"
        #if I_HEALTH_RECOVERY >= GEN_7
            "by 70 points."),
        .descricao = COMPOUND_STRING(
            "Uma bebida muito\n"
            "doce que cura o HP\n"
            "em 70 pontos."),
        .descricion = COMPOUND_STRING(
            "Una bebida muy\n"
            "dulce que cura HP\n"
            "en 70 puntos."),
        #else
            "by 80 points."),
        #endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HEALTH_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_RESTORE_HP,
        .effect = gItemEffect_Lemonade,
        .flingPower = 30,
        .iconPic = gItemIcon_Lemonade,
        .iconPalette = gItemIconPalette_Lemonade,
    },

    [ITEM_MOOMOO_MILK] =
    {
        .name = ITEM_NAME("Moomoo Milk"),
        .nombre = ITEM_NAME("Leche Moomoo"),
        .price = (I_PRICE >= GEN_7) ? 600 : 500,
        .holdEffectParam = 100,
        .description = COMPOUND_STRING(
            "A nutritious milk\n"
            "that heals HP by\n"
            "100 points."),
        .descricao = COMPOUND_STRING(
            "Um leite nutritivo\n"
            "que cura o HP em\n"
            "100 pontos."),
        .descricion = COMPOUND_STRING(
            "Una leche nutritiva\n"
            "que cura HP en 100\n"
            "puntos."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HEALTH_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_RESTORE_HP,
        .effect = gItemEffect_MoomooMilk,
        .flingPower = 30,
        .iconPic = gItemIcon_MoomooMilk,
        .iconPalette = gItemIconPalette_MoomooMilk,
    },

    [ITEM_ENERGY_POWDER] =
    {
        .name = ITEM_NAME("Energy Powder"),
        .nombre = ITEM_NAME("Polvo energetico"),
        .price = 500,
        .description = COMPOUND_STRING(
            "A bitter powder\n"
            "that heals HP"
        #if I_HEALTH_RECOVERY >= GEN_7
            "by 60 points."),
        .descricao = COMPOUND_STRING(
            "Um pó amargo que\n"
            "cura o HP em 60\n"
            "pontos."),
        .descricion = COMPOUND_STRING(
            "Un polvo amargo que\n"
            "cura HP en 60\n"
            "puntos."),
        #else
            "by 50 points."),
        #endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HEALTH_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_RESTORE_HP,
        .effect = gItemEffect_EnergyPowder,
        .flingPower = 30,
        .iconPic = gItemIcon_Powder,
        .iconPalette = gItemIconPalette_EnergyPowder,
    },

    [ITEM_ENERGY_ROOT] =
    {
        .name = ITEM_NAME("Energy Root"),
        .nombre = ITEM_NAME("Raiz de energia"),
        .price = (I_PRICE >= GEN_7) ? 1200 : 800,
        .description = COMPOUND_STRING(
            "A bitter root that\n"
            "heals HP"
        #if I_HEALTH_RECOVERY >= GEN_7
            "by 120 points."),
        .descricao = COMPOUND_STRING(
            "Uma raiz amarga que\n"
            "cura o HP em 120\n"
            "pontos."),
        .descricion = COMPOUND_STRING(
            "Una raíz amarga que\n"
            "cura HP en 120\n"
            "puntos."),
        #else
            "by 200 points."),
        #endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HEALTH_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_RESTORE_HP,
        .effect = gItemEffect_EnergyRoot,
        .flingPower = 30,
        .iconPic = gItemIcon_EnergyRoot,
        .iconPalette = gItemIconPalette_EnergyRoot,
    },

    [ITEM_HEAL_POWDER] =
    {
        .name = ITEM_NAME("Heal Powder"),
        .nombre = ITEM_NAME("Polvo curativo"),
        .price = (I_PRICE >= GEN_7) ? 300 : 450,
        .description = COMPOUND_STRING(
            "A bitter powder\n"
            "that heals all\n"
            "status problems."),
        .descricao = COMPOUND_STRING(
            "Um pó amargo cura\n"
            "todos problemas\n"
            "status."),
        .descricion = COMPOUND_STRING(
            "Un polvo amargo que\n"
            "cura todos los\n"
            "problemas de."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STATUS_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_HealPowder,
        .flingPower = 30,
        .iconPic = gItemIcon_Powder,
        .iconPalette = gItemIconPalette_HealPowder,
    },

    [ITEM_REVIVAL_HERB] =
    {
        .name = ITEM_NAME("Revival Herb"),
        .nombre = ITEM_NAME("Revival Herb"),
        .price = 2800,
        .description = COMPOUND_STRING(
            "A very bitter herb\n"
            "that revives a\n"
            "fainted Pokémon."),
        .descricao = COMPOUND_STRING(
            "Uma erva amarga\n"
            "revive Pokémon\n"
            "desmaiado."),
        .descricion = COMPOUND_STRING(
            "Una hierba muy\n"
            "amarga que revive a\n"
            "un Pokémon."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HEALTH_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_REVIVE,
        .effect = gItemEffect_RevivalHerb,
        .flingPower = 30,
        .iconPic = gItemIcon_RevivalHerb,
        .iconPalette = gItemIconPalette_RevivalHerb,
    },

    [ITEM_ANTIDOTE] =
    {
        .name = ITEM_NAME("Antidote"),
        .nombre = ITEM_NAME("antidoto"),
        .price = (I_PRICE >= GEN_7) ? 200 : 100,
        .description = COMPOUND_STRING(
            "Heals a poisoned\n"
            "Pokémon."),
        .descricao = COMPOUND_STRING(
            "Cura um Pokémon\n"
            "envenenado."),
        .descricion = COMPOUND_STRING(
            "Cura a un Pokémon\n"
            "envenenado."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STATUS_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_Antidote,
        .flingPower = 30,
        .iconPic = gItemIcon_StatusHeal,
        .iconPalette = gItemIconPalette_Antidote,
    },

    [ITEM_PARALYZE_HEAL] =
    {
        .name = ITEM_NAME("Paralyze Heal"),
        .nombre = ITEM_NAME("Paralizar sanar"),
        .price = (I_PRICE == GEN_7) ? 300 : 200,
        .description = COMPOUND_STRING(
            "Heals a paralyzed\n"
            "Pokémon."),
        .descricao = COMPOUND_STRING(
            "Cura um Pokémon\n"
            "paralisado."),
        .descricion = COMPOUND_STRING(
            "Cura a un Pokémon\n"
            "paralizado."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STATUS_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_ParalyzeHeal,
        .flingPower = 30,
        .iconPic = gItemIcon_StatusHeal,
        .iconPalette = gItemIconPalette_ParalyzeHeal,
    },

    [ITEM_BURN_HEAL] =
    {
        .name = ITEM_NAME("Burn Heal"),
        .nombre = ITEM_NAME("Quemar sanar"),
    #if I_PRICE >= GEN_8
        .price = 200,
    #elif I_PRICE == GEN_7
        .price = 300,
    #else
        .price = 250,
    #endif
        .description = COMPOUND_STRING(
            "Heals Pokémon of a\n"
            "burn."),
        .descricao = COMPOUND_STRING(
            "Cura Pokémon de\n"
            "queimaduras."),
        .descricion = COMPOUND_STRING(
            "Cura Pokémon de una\n"
            "quemadura."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STATUS_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_BurnHeal,
        .flingPower = 30,
        .iconPic = gItemIcon_StatusHeal,
        .iconPalette = gItemIconPalette_BurnHeal,
    },

    [ITEM_ICE_HEAL] =
    {
        .name = ITEM_NAME("Ice Heal"),
        .nombre = ITEM_NAME("curacion de hielo"),
    #if I_PRICE >= GEN_8
        .price = 200,
    #elif I_PRICE == GEN_7
        .price = 100,
    #else
        .price = 250,
    #endif
        .description = COMPOUND_STRING(
            "Defrosts a frozen\n"
            "Pokémon."),
        .descricao = COMPOUND_STRING(
            "Descongela um\n"
            "Pokémon congelado."),
        .descricion = COMPOUND_STRING(
            "Descongela un\n"
            "Pokémon congelado."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STATUS_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_IceHeal,
        .flingPower = 30,
        .iconPic = gItemIcon_StatusHeal,
        .iconPalette = gItemIconPalette_IceHeal,
    },

    [ITEM_AWAKENING] =
    {
        .name = ITEM_NAME("Awakening"),
        .nombre = ITEM_NAME("Despertar"),
    #if (I_PRICE >= GEN_8 || I_PRICE == GEN_1)
        .price = 200,
    #elif I_PRICE == GEN_7
        .price = 100,
    #else
        .price = 250,
    #endif
        .description = COMPOUND_STRING(
            "Awakens a sleeping\n"
            "Pokémon."),
        .descricao = COMPOUND_STRING(
            "Desperta um Pokémon\n"
            "adormecido."),
        .descricion = COMPOUND_STRING(
            "Despierta a un\n"
            "Pokémon dormido."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STATUS_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_Awakening,
        .flingPower = 30,
        .iconPic = gItemIcon_StatusHeal,
        .iconPalette = gItemIconPalette_Awakening,
    },

    [ITEM_FULL_HEAL] =
    {
        .name = ITEM_NAME("Full Heal"),
        .nombre = ITEM_NAME("Curacion completa"),
        .price = (I_PRICE >= GEN_7) ? 400 : 600,
        .description = sFullHealDesc,
        .descricao = COMPOUND_STRING(
            "Cura todos os\n"
            "problemas de status\n"
            "de um Pokémon."),
        .descricion = COMPOUND_STRING(
            "Cura todos los\n"
            "problemas de estado\n"
            "de un Pokémon."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STATUS_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_FullHeal,
        .flingPower = 30,
        .iconPic = gItemIcon_FullHeal,
        .iconPalette = gItemIconPalette_FullHeal,
    },

    [ITEM_ETHER] =
    {
        .name = ITEM_NAME("Ether"),
        .nombre = ITEM_NAME("Eter"),
        .price = (I_PRICE >= GEN_2) ? 1200 : 1,
        .holdEffectParam = 10,
        .description = COMPOUND_STRING(
            "Restores the PP of\n"
            "a selected move by\n"
            "10."),
        .descricao = COMPOUND_STRING(
            "Restaura o PP de um\n"
            "golpe selecionado\n"
            "em 10."),
        .descricion = COMPOUND_STRING(
            "Restaura el PP de\n"
            "un mov.\n"
            "seleccionado en 10."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_PP_RECOVERY,
        .type = ITEM_USE_PARTY_MENU_MOVES,
        .fieldUseFunc = ItemUseOutOfBattle_PPRecovery,
        .battleUsage = EFFECT_ITEM_RESTORE_PP,
        .effect = gItemEffect_Ether,
        .flingPower = 30,
        .iconPic = gItemIcon_Ether,
        .iconPalette = gItemIconPalette_Ether,
    },

    [ITEM_MAX_ETHER] =
    {
        .name = ITEM_NAME("Max Ether"),
        .nombre = ITEM_NAME("Eter maximo"),
        .price = (I_PRICE >= GEN_2) ? 2000 : 1,
        .holdEffectParam = 255,
        .description = COMPOUND_STRING(
            "Fully heals the PP\n"
            "of a selected move."),
        .descricao = COMPOUND_STRING(
            "Restaura totalmente\n"
            "o PP de um golpe\n"
            "selecionado."),
        .descricion = COMPOUND_STRING(
            "Restaura\n"
            "completamente el PP\n"
            "de un mov."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_PP_RECOVERY,
        .type = ITEM_USE_PARTY_MENU_MOVES,
        .fieldUseFunc = ItemUseOutOfBattle_PPRecovery,
        .battleUsage = EFFECT_ITEM_RESTORE_PP,
        .effect = gItemEffect_MaxEther,
        .flingPower = 30,
        .iconPic = gItemIcon_Ether,
        .iconPalette = gItemIconPalette_MaxEther,
    },

    [ITEM_ELIXIR] =
    {
        .name = ITEM_NAME("Elixir"),
        .nombre = ITEM_NAME("Elixir"),
        .price = (I_PRICE >= GEN_2) ? 3000 : 1,
        .holdEffectParam = 10,
        .description = COMPOUND_STRING(
            "Restores the PP of\n"
            "all moves by 10."),
        .descricao = COMPOUND_STRING(
            "Restaura o PP de\n"
            "todos os golpes em\n"
            "10."),
        .descricion = COMPOUND_STRING(
            "Restaura el PP de\n"
            "todos los movs. en\n"
            "10."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_PP_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PPRecovery,
        .battleUsage = EFFECT_ITEM_RESTORE_PP,
        .effect = gItemEffect_Elixir,
        .flingPower = 30,
        .iconPic = gItemIcon_Ether,
        .iconPalette = gItemIconPalette_Elixir,
    },

    [ITEM_MAX_ELIXIR] =
    {
        .name = ITEM_NAME("Max Elixir"),
        .nombre = ITEM_NAME("Elixir maximo"),
        .price = (I_PRICE >= GEN_2) ? 4500 : 1,
        .holdEffectParam = 255,
        .description = COMPOUND_STRING(
            "Fully heals the PP\n"
            "of a Pokémon's\n"
            "moves."),
        .descricao = COMPOUND_STRING(
            "Restaura totalmente\n"
            "o PP dos golpes de\n"
            "um Pokémon."),
        .descricion = COMPOUND_STRING(
            "Restaura\n"
            "completamente los\n"
            "PP los movs. un."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_PP_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PPRecovery,
        .battleUsage = EFFECT_ITEM_RESTORE_PP,
        .effect = gItemEffect_MaxElixir,
        .flingPower = 30,
        .iconPic = gItemIcon_Ether,
        .iconPalette = gItemIconPalette_MaxElixir,
    },

    [ITEM_BERRY_JUICE] =
    {
        .name = ITEM_NAME("Berry Juice"),
        .nombre = ITEM_NAME("Jugo de bayas"),
        .price = 100,
        .holdEffect = HOLD_EFFECT_RESTORE_HP,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "A 100% pure juice\n"
            "that heals HP by 20\n"
            "points."),
        .descricao = COMPOUND_STRING(
            "Um suco 100% puro\n"
            "que cura o HP em 20\n"
            "pontos."),
        .descricion = COMPOUND_STRING(
            "Un jugo 100% puro\n"
            "que cura HP en 20\n"
            "puntos."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HEALTH_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_RESTORE_HP,
        .effect = gItemEffect_Potion,
        .flingPower = 30,
        .iconPic = gItemIcon_BerryJuice,
        .iconPalette = gItemIconPalette_BerryJuice,
    },

    [ITEM_SACRED_ASH] =
    {
        .name = ITEM_NAME("Sacred Ash"),
        .nombre = ITEM_NAME("Ceniza Sagrada"),
        .pluralName = ITEM_PLURAL_NAME("Sacred Ashes"),
        .price = (I_PRICE >= GEN_7) ? 50000 : 200,
        .description = COMPOUND_STRING(
            "Fully revives and\n"
            "heals all fainted\n"
            "Pokémon."),
        .descricao = COMPOUND_STRING(
            "Revive e cura\n"
            "totalmente todos os\n"
            "Pokémon desmaiados."),
        .descricion = COMPOUND_STRING(
            "Revive y cura\n"
            "completamente a\n"
            "todos los Pokémon."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HEALTH_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_SacredAsh,
        .effect = gItemEffect_SacredAsh,
        .flingPower = 30,
        .iconPic = gItemIcon_DittoPowder,
        .iconPalette = gItemIconPalette_SacredAsh,
    },

    [ITEM_SWEET_HEART] =
    {
        .name = ITEM_NAME("Sweet Heart"),
        .nombre = ITEM_NAME("dulce corazon"),
        .price = (I_PRICE >= GEN_7) ? 3000 : 100,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "A sweet chocolate\n"
            "that heals HP by 20\n"
            "points."),
        .descricao = COMPOUND_STRING(
            "Um chocolate doce\n"
            "que cura o HP em 20\n"
            "pontos."),
        .descricion = COMPOUND_STRING(
            "Un chocolate dulce\n"
            "que cura HP en 20\n"
            "puntos."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HEALTH_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_RESTORE_HP,
        .effect = gItemEffect_Potion,
        .flingPower = 30,
        .iconPic = gItemIcon_SweetHeart,
        .iconPalette = gItemIconPalette_SweetHeart,
    },

    [ITEM_MAX_HONEY] =
    {
        .name = ITEM_NAME("Max Honey"),
        .nombre = ITEM_NAME("Miel maxima"),
        .pluralName = ITEM_PLURAL_NAME("Max Honey"),
        .price = 8000,
        .description = sMaxReviveDesc,
        .descricao = COMPOUND_STRING(
            "Revive um Pokémon\n"
            "desmaiado com todo\n"
            "o seu HP."),
        .descricion = COMPOUND_STRING(
            "Revive a un Pokémon\n"
            "desmayado con todos\n"
            "sus HP."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HEALTH_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_REVIVE,
        .effect = gItemEffect_MaxRevive,
        .flingPower = 30,
        .iconPic = gItemIcon_MaxHoney,
        .iconPalette = gItemIconPalette_MaxHoney,
    },

// Regional Specialties

    [ITEM_PEWTER_CRUNCHIES] =
    {
        .name = ITEM_NAME("Pewter Crunchies"),
        .nombre = ITEM_NAME("Cruj. de peltre"),
        .pluralName = ITEM_PLURAL_NAME("Pewter Crunchies"),
        .price = 250,
        .description = sFullHealDesc,
        .descricao = COMPOUND_STRING(
            "Cura todos os\n"
            "problemas de status\n"
            "de um Pokémon."),
        .descricion = COMPOUND_STRING(
            "Cura todos los\n"
            "problemas de estado\n"
            "de un Pokémon."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STATUS_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_FullHeal,
        .flingPower = 30,
        .iconPic = gItemIcon_PewterCrunchies,
        .iconPalette = gItemIconPalette_PewterCrunchies,
    },

    [ITEM_RAGE_CANDY_BAR] =
    {
        .name = ITEM_NAME("Rage Candy Bar"),
        .nombre = ITEM_NAME("Rage Candy Bar"),
        .price = (I_PRICE >= GEN_7) ? 350 : 300,
        .description = sFullHealDesc,
        .descricao = COMPOUND_STRING(
            "Cura todos os\n"
            "problemas de status\n"
            "de um Pokémon."),
        .descricion = COMPOUND_STRING(
            "Cura todos los\n"
            "problemas de estado\n"
            "de un Pokémon."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STATUS_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_FullHeal,
        .flingPower = 30,
        .iconPic = gItemIcon_RageCandyBar,
        .iconPalette = gItemIconPalette_RageCandyBar,
    },

    [ITEM_LAVA_COOKIE] =
    {
        .name = ITEM_NAME("Lava Cookie"),
        .nombre = ITEM_NAME("galleta de lava"),
        .price = (I_PRICE >= GEN_7) ? 350 : 200,
        .description = COMPOUND_STRING(
            "A local specialty\n"
            "that heals all\n"
            "status problems."),
        .descricao = COMPOUND_STRING(
            "Uma especialidade\n"
            "local cura todos\n"
            "problemas"),
        .descricion = COMPOUND_STRING(
            "Una especialidad\n"
            "local cura todos\n"
            "los problemas"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STATUS_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_FullHeal,
        .flingPower = 30,
        .iconPic = gItemIcon_LavaCookie,
        .iconPalette = gItemIconPalette_LavaCookieAndLetter,
    },

    [ITEM_OLD_GATEAU] =
    {
        .name = ITEM_NAME("Old Gateau"),
        .nombre = ITEM_NAME("pastel viejo"),
        .pluralName = ITEM_PLURAL_NAME("Old Gateaux"),
        .price = (I_PRICE >= GEN_7) ? 350 : 200,
        .description = sFullHealDesc,
        .descricao = COMPOUND_STRING(
            "Cura todos os\n"
            "problemas de status\n"
            "de um Pokémon."),
        .descricion = COMPOUND_STRING(
            "Cura todos los\n"
            "problemas de estado\n"
            "de un Pokémon."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STATUS_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_FullHeal,
        .flingPower = 30,
        .iconPic = gItemIcon_OldGateau,
        .iconPalette = gItemIconPalette_OldGateau,
    },

    [ITEM_CASTELIACONE] =
    {
        .name = ITEM_NAME("Casteliacone"),
        .nombre = ITEM_NAME("castellano"),
        .price = (I_PRICE >= GEN_7) ? 350 : 100,
        .description = sFullHealDesc,
        .descricao = COMPOUND_STRING(
            "Cura todos os\n"
            "problemas de status\n"
            "de um Pokémon."),
        .descricion = COMPOUND_STRING(
            "Cura todos los\n"
            "problemas de estado\n"
            "de un Pokémon."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STATUS_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_FullHeal,
        .flingPower = 30,
        .iconPic = gItemIcon_Casteliacone,
        .iconPalette = gItemIconPalette_Casteliacone,
    },

    [ITEM_LUMIOSE_GALETTE] =
    {
        .name = ITEM_NAME("Lumiose Galette"),
        .nombre = ITEM_NAME("Galette Lumiosa"),
        .price = (I_PRICE >= GEN_7) ? 350 : 200,
        .description = sFullHealDesc,
        .descricao = COMPOUND_STRING(
            "Cura todos os\n"
            "problemas de status\n"
            "de um Pokémon."),
        .descricion = COMPOUND_STRING(
            "Cura todos los\n"
            "problemas de estado\n"
            "de un Pokémon."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STATUS_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_FullHeal,
        .flingPower = 30,
        .iconPic = gItemIcon_LumioseGalette,
        .iconPalette = gItemIconPalette_LumioseGalette,
    },

    [ITEM_SHALOUR_SABLE] =
    {
        .name = ITEM_NAME("Shalour Sable"),
        .nombre = ITEM_NAME("Shalour Sable"),
        .price = (I_PRICE >= GEN_7) ? 350 : 200,
        .description = sFullHealDesc,
        .descricao = COMPOUND_STRING(
            "Cura todos os\n"
            "problemas de status\n"
            "de um Pokémon."),
        .descricion = COMPOUND_STRING(
            "Cura todos los\n"
            "problemas de estado\n"
            "de un Pokémon."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STATUS_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_FullHeal,
        .flingPower = 30,
        .iconPic = gItemIcon_ShalourSable,
        .iconPalette = gItemIconPalette_ShalourSable,
    },

    [ITEM_BIG_MALASADA] =
    {
        .name = ITEM_NAME("Big Malasada"),
        .nombre = ITEM_NAME("Gran Malasada"),
        .price = 350,
        .description = sFullHealDesc,
        .descricao = COMPOUND_STRING(
            "Cura todos os\n"
            "problemas de status\n"
            "de um Pokémon."),
        .descricion = COMPOUND_STRING(
            "Cura todos los\n"
            "problemas de estado\n"
            "de un Pokémon."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STATUS_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_FullHeal,
        .flingPower = 30,
        .iconPic = gItemIcon_BigMalasada,
        .iconPalette = gItemIconPalette_BigMalasada,
    },

// Vitamins

    [ITEM_HP_UP] =
    {
        .name = ITEM_NAME("HP Up"),
        .nombre = ITEM_NAME("HP arriba"),
        .price = (I_PRICE >= GEN_7) ? 10000 : 9800,
        .description = COMPOUND_STRING(
            "Raises the base HP\n"
            "of one Pokémon."),
        .descricao = COMPOUND_STRING(
            "Aumenta o HP base\n"
            "de um Pokémon."),
        .descricion = COMPOUND_STRING(
            "Aumenta el HP base\n"
            "de un Pokémon."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STAT_BOOST_DRINK,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .effect = gItemEffect_HPUp,
        .flingPower = 30,
        .iconPic = gItemIcon_HPUp,
        .iconPalette = gItemIconPalette_HPUp,
    },

    [ITEM_PROTEIN] =
    {
        .name = ITEM_NAME("Protein"),
        .nombre = ITEM_NAME("Proteina"),
        .price = (I_PRICE >= GEN_7) ? 10000 : 9800,
        .description = COMPOUND_STRING(
            "Raises the base\n"
            "Atk. stat of one\n"
            "Pokémon."),
        .descricao = COMPOUND_STRING(
            "Aumenta a\n"
            "estatística de Atq.\n"
            "base de um."),
        .descricion = COMPOUND_STRING(
            "Aumenta la\n"
            "estadística de Atq.\n"
            "base de un."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STAT_BOOST_DRINK,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .effect = gItemEffect_Protein,
        .flingPower = 30,
        .iconPic = gItemIcon_Vitamin,
        .iconPalette = gItemIconPalette_Protein,
    },

    [ITEM_IRON] =
    {
        .name = ITEM_NAME("Iron"),
        .nombre = ITEM_NAME("hierro"),
        .price = (I_PRICE >= GEN_7) ? 10000 : 9800,
        .description = COMPOUND_STRING(
            "Raises the base\n"
            "Def. stat of one\n"
            "Pokémon."),
        .descricao = COMPOUND_STRING(
            "Aumenta a\n"
            "estatística básica\n"
            "de Def. de um."),
        .descricion = COMPOUND_STRING(
            "Aumenta la\n"
            "estadística de Def.\n"
            "base de un Pokémon."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STAT_BOOST_DRINK,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .effect = gItemEffect_Iron,
        .flingPower = 30,
        .iconPic = gItemIcon_Vitamin,
        .iconPalette = gItemIconPalette_Iron,
    },

    [ITEM_CALCIUM] =
    {
        .name = ITEM_NAME("Calcium"),
        .nombre = ITEM_NAME("calcio"),
        .price = (I_PRICE >= GEN_7) ? 10000 : 9800,
        .description = COMPOUND_STRING(
            "Raises the base Sp.\n"
            "Atk stat of one\n"
            "Pokémon."),
        .descricao = COMPOUND_STRING(
            "Eleva a base Sp.\n"
            "Estatística de Atq.\n"
            "de um."),
        .descricion = COMPOUND_STRING(
            "Eleva la base Sp.\n"
            "Estadística de Atq.\n"
            "de un."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STAT_BOOST_DRINK,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .effect = gItemEffect_Calcium,
        .flingPower = 30,
        .iconPic = gItemIcon_Vitamin,
        .iconPalette = gItemIconPalette_Calcium,
    },

    [ITEM_ZINC] =
    {
        .name = ITEM_NAME("Zinc"),
        .nombre = ITEM_NAME("zinc"),
        .price = (I_PRICE >= GEN_7) ? 10000 : 9800,
        .description = COMPOUND_STRING(
            "Raises the base Sp.\n"
            "Def stat of one\n"
            "Pokémon."),
        .descricao = COMPOUND_STRING(
            "Eleva a base Sp.\n"
            "Estatística de\n"
            "definição de um."),
        .descricion = COMPOUND_STRING(
            "Eleva la base Sp.\n"
            "Estadística de\n"
            "definición de un."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STAT_BOOST_DRINK,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .effect = gItemEffect_Zinc,
        .flingPower = 30,
        .iconPic = gItemIcon_Vitamin,
        .iconPalette = gItemIconPalette_Zinc,
    },

    [ITEM_CARBOS] =
    {
        .name = ITEM_NAME("Carbos"),
        .nombre = ITEM_NAME("Carbos"),
        .pluralName = ITEM_PLURAL_NAME("Carbos"),
        .price = (I_PRICE >= GEN_7) ? 10000 : 9800,
        .description = COMPOUND_STRING(
            "Raises the base\n"
            "Speed stat of one\n"
            "Pokémon."),
        .descricao = COMPOUND_STRING(
            "Aumenta a\n"
            "estatística básica\n"
            "de Vel. de um."),
        .descricion = COMPOUND_STRING(
            "Aumenta la\n"
            "estadística de Vel.\n"
            "base de un Pokémon."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STAT_BOOST_DRINK,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .effect = gItemEffect_Carbos,
        .flingPower = 30,
        .iconPic = gItemIcon_Vitamin,
        .iconPalette = gItemIconPalette_Carbos,
    },

    [ITEM_PP_UP] =
    {
        .name = ITEM_NAME("PP Up"),
        .nombre = ITEM_NAME("PP arriba"),
    #if I_PRICE >= GEN_7
        .price = 10000,
    #elif I_PRICE >= GEN_2
        .price = 9800,
    #else
        .price = 1,
    #endif
        .description = COMPOUND_STRING(
            "Raises the maximum\n"
            "PP of a selected\n"
            "move."),
        .descricao = COMPOUND_STRING(
            "Aumenta o PP máximo\n"
            "de um golpe\n"
            "selecionado."),
        .descricion = COMPOUND_STRING(
            "Aumenta el PP\n"
            "máximo de un mov.\n"
            "seleccionado."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STAT_BOOST_DRINK,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PPUp,
        .effect = gItemEffect_PPUp,
        .flingPower = 30,
        .iconPic = gItemIcon_PPUp,
        .iconPalette = gItemIconPalette_PPUp,
    },

    [ITEM_PP_MAX] =
    {
        .name = ITEM_NAME("PP Max"),
        .nombre = ITEM_NAME("PP max."),
        .pluralName = ITEM_PLURAL_NAME("PP Maxes"),
        .price = (I_PRICE >= GEN_7) ? 10000 : 9800,
        .description = COMPOUND_STRING(
            "Raises the PP of a\n"
            "move to its maximum\n"
            "points."),
        .descricao = COMPOUND_STRING(
            "Eleva o PP de um\n"
            "golpe aos seus\n"
            "pontos máximos."),
        .descricion = COMPOUND_STRING(
            "Eleva el PP de una\n"
            "jugada a sus puntos\n"
            "máximos."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STAT_BOOST_DRINK,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PPUp,
        .effect = gItemEffect_PPMax,
        .flingPower = 30,
        .iconPic = gItemIcon_PPMax,
        .iconPalette = gItemIconPalette_PPMax,
    },

// EV Feathers

    [ITEM_HEALTH_FEATHER] =
    {
        .name = ITEM_NAME("Health Feather"),
        .nombre = ITEM_NAME("Pluma de salud"),
        .price = (I_PRICE >= GEN_7) ? 300 : 3000,
        .description = sHealthFeatherDesc,
        .descricao = COMPOUND_STRING(
            "Um item que sobe o\n"
            "HP base de um\n"
            "Pokémon."),
        .descricion = COMPOUND_STRING(
            "Un elemento que\n"
            "sobe el HP base de\n"
            "un Pokémon."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STAT_BOOST_FEATHER,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .effect = gItemEffect_HpFeather,
        .flingPower = 20,
        .iconPic = gItemIcon_EVFeather,
        .iconPalette = gItemIconPalette_HealthFeather,
    },

    [ITEM_MUSCLE_FEATHER] =
    {
        .name = ITEM_NAME("Muscle Feather"),
        .nombre = ITEM_NAME("Pluma muscular"),
        .price = (I_PRICE >= GEN_7) ? 300 : 3000,
        .description = sMuscleFeatherDesc,
        .descricao = COMPOUND_STRING(
            "Um item que sobe o\n"
            "Atq. base de um\n"
            "Pokémon."),
        .descricion = COMPOUND_STRING(
            "Un objeto que sobe\n"
            "el Atq. base de un\n"
            "Pokémon."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STAT_BOOST_FEATHER,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .effect = gItemEffect_AtkFeather,
        .flingPower = 20,
        .iconPic = gItemIcon_EVFeather,
        .iconPalette = gItemIconPalette_MuscleFeather,
    },

    [ITEM_RESIST_FEATHER] =
    {
        .name = ITEM_NAME("Resist Feather"),
        .nombre = ITEM_NAME("Resistir pluma"),
        .price = (I_PRICE >= GEN_7) ? 300 : 3000,
        .description = sResistFeatherDesc,
        .descricao = COMPOUND_STRING(
            "Um item que sobe a\n"
            "Def. básica de um\n"
            "Pokémon."),
        .descricion = COMPOUND_STRING(
            "Un objeto que sobe\n"
            "la defensa base de\n"
            "un Pokémon."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STAT_BOOST_FEATHER,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .effect = gItemEffect_DefFeather,
        .flingPower = 20,
        .iconPic = gItemIcon_EVFeather,
        .iconPalette = gItemIconPalette_ResistFeather,
    },

    [ITEM_GENIUS_FEATHER] =
    {
        .name = ITEM_NAME("Genius Feather"),
        .nombre = ITEM_NAME("Pluma de genio"),
        .price = (I_PRICE >= GEN_7) ? 300 : 3000,
        .description = sGeniusFeatherDesc,
        .descricao = COMPOUND_STRING(
            "Um item que sobe o\n"
            "Sp base. Atk. de um\n"
            "Pokémon."),
        .descricion = COMPOUND_STRING(
            "Un elemento que\n"
            "eleva el Sp base.\n"
            "Atk. de un Pokémon."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STAT_BOOST_FEATHER,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .effect = gItemEffect_SpatkFeather,
        .flingPower = 20,
        .iconPic = gItemIcon_EVFeather,
        .iconPalette = gItemIconPalette_GeniusFeather,
    },

    [ITEM_CLEVER_FEATHER] =
    {
        .name = ITEM_NAME("Clever Feather"),
        .nombre = ITEM_NAME("Pluma inteligente"),
        .price = (I_PRICE >= GEN_7) ? 300 : 3000,
        .description = sCleverFeatherDesc,
        .descricao = COMPOUND_STRING(
            "Um item sobe Sp\n"
            "base.\n"
            "Definitivamente."),
        .descricion = COMPOUND_STRING(
            "Un elemento que\n"
            "eleva el Sp base.\n"
            "Def. de un Pokémon."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STAT_BOOST_FEATHER,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .effect = gItemEffect_SpdefFeather,
        .flingPower = 20,
        .iconPic = gItemIcon_EVFeather,
        .iconPalette = gItemIconPalette_CleverFeather,
    },

    [ITEM_SWIFT_FEATHER] =
    {
        .name = ITEM_NAME("Swift Feather"),
        .nombre = ITEM_NAME("Pluma veloz"),
        .price = (I_PRICE >= GEN_7) ? 300 : 3000,
        .description = sSwiftFeatherDesc,
        .descricao = COMPOUND_STRING(
            "Um item que sobe a\n"
            "Vel. base de um\n"
            "Pokémon."),
        .descricion = COMPOUND_STRING(
            "Un elemento que\n"
            "sobe la Vel. base\n"
            "de un Pokémon."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STAT_BOOST_FEATHER,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .effect = gItemEffect_SpeedFeather,
        .flingPower = 20,
        .iconPic = gItemIcon_EVFeather,
        .iconPalette = gItemIconPalette_SwiftFeather,
    },

// Ability Modifiers

    [ITEM_ABILITY_CAPSULE] =
    {
        .name = ITEM_NAME("Ability Capsule"),
        .nombre = ITEM_NAME("Caps. de habil."),
    #if I_PRICE >= GEN_9
        .price = 100000,
    #elif I_PRICE >= GEN_7
        .price = 10000,
    #else
        .price = 1000,
    #endif
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "Switches a Poké-\n"
            "mon's ability."),
        .descricao = COMPOUND_STRING(
            "Muda a habilidade\n"
            "de um Pokémon."),
        .descricion = COMPOUND_STRING(
            "Cambia la habilidad\n"
            "de un Pokémon."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FIELD_USE,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_AbilityCapsule,
        .iconPic = gItemIcon_AbilityCapsule,
        .iconPalette = gItemIconPalette_AbilityCapsule,
    },

    [ITEM_ABILITY_PATCH] =
    {
        .name = ITEM_NAME("Ability Patch"),
        .nombre = ITEM_NAME("Parche de habil."),
        .pluralName = ITEM_PLURAL_NAME("Ability Patches"),
        .price = (I_PRICE >= GEN_9) ? 250000 : 20,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "Turns the ability\n"
            "of a Pokémon into a\n"
            "rare ability."),
        .descricao = COMPOUND_STRING(
            "Transforma a\n"
            "habilidade de um\n"
            "Pokémon em uma."),
        .descricion = COMPOUND_STRING(
            "Convierte la\n"
            "habilidad de un\n"
            "Pokémon en una."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FIELD_USE,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_AbilityPatch,
        .iconPic = gItemIcon_AbilityPatch,
        .iconPalette = gItemIconPalette_AbilityPatch,
    },

// Mints

    [ITEM_LONELY_MINT] =
    {
        .name = ITEM_NAME("Lonely Mint"),
        .nombre = ITEM_NAME("Menta solitaria"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
            "Can be smelled. It\n"
            "ups Atk., but cuts\n"
            "Def."),
        .descricao = COMPOUND_STRING(
            "Pode ser cheirado.\n"
            "Aumenta o Atq., mas\n"
            "reduz a Def."),
        .descricion = COMPOUND_STRING(
            "Se puede oler.\n"
            "Aumenta el Atq.,\n"
            "pero reduce la."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_NATURE_MINT,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_LONELY,
        .flingPower = 10,
        .iconPic = gItemIcon_Mint,
        .iconPalette = gItemIconPalette_RedMint,
    },

    [ITEM_ADAMANT_MINT] =
    {
        .name = ITEM_NAME("Adamant Mint"),
        .nombre = ITEM_NAME("Menta Adamante"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
            "Can be smelled. It\n"
            "ups Atk., but cuts\n"
            "Sp. Atk."),
        .descricao = COMPOUND_STRING(
            "Pode ser cheirado.\n"
            "Aumenta o Atq., mas\n"
            "reduz o Sp. Atk."),
        .descricion = COMPOUND_STRING(
            "Se puede oler.\n"
            "Aumenta el Atq.,\n"
            "pero reduce el Sp."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_NATURE_MINT,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_ADAMANT,
        .flingPower = 10,
        .iconPic = gItemIcon_Mint,
        .iconPalette = gItemIconPalette_RedMint,
    },

    [ITEM_NAUGHTY_MINT] =
    {
        .name = ITEM_NAME("Naughty Mint"),
        .nombre = ITEM_NAME("menta traviesa"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
            "Can be smelled. It\n"
            "ups Atk., but cuts\n"
            "Sp. Def."),
        .descricao = COMPOUND_STRING(
            "Pode ser cheirado.\n"
            "Aumenta o Atq., mas\n"
            "reduz o Sp."),
        .descricion = COMPOUND_STRING(
            "Se puede oler.\n"
            "Aumenta el Atq.,\n"
            "pero reduce el Sp."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_NATURE_MINT,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_NAUGHTY,
        .flingPower = 10,
        .iconPic = gItemIcon_Mint,
        .iconPalette = gItemIconPalette_RedMint,
    },

    [ITEM_BRAVE_MINT] =
    {
        .name = ITEM_NAME("Brave Mint"),
        .nombre = ITEM_NAME("Menta valiente"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
            "Can be smelled. It\n"
            "ups Atk., but cuts\n"
            "Speed."),
        .descricao = COMPOUND_STRING(
            "Pode ser cheirado.\n"
            "Aumenta o Atq., mas\n"
            "reduz a Vel."),
        .descricion = COMPOUND_STRING(
            "Se puede oler.\n"
            "Aumenta el Atq.,\n"
            "pero reduce la."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_NATURE_MINT,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_BRAVE,
        .flingPower = 10,
        .iconPic = gItemIcon_Mint,
        .iconPalette = gItemIconPalette_RedMint,
    },

    [ITEM_BOLD_MINT] =
    {
        .name = ITEM_NAME("Bold Mint"),
        .nombre = ITEM_NAME("Menta atrevida"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
            "Can be smelled. It\n"
            "ups Def., but cuts\n"
            "Atk."),
        .descricao = COMPOUND_STRING(
            "Pode ser cheirado.\n"
            "Aumenta a Def., mas\n"
            "reduz o Atq."),
        .descricion = COMPOUND_STRING(
            "Se puede oler.\n"
            "Aumenta la Def.,\n"
            "pero reduce el."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_NATURE_MINT,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_BOLD,
        .flingPower = 10,
        .iconPic = gItemIcon_Mint,
        .iconPalette = gItemIconPalette_BlueMint,
    },

    [ITEM_IMPISH_MINT] =
    {
        .name = ITEM_NAME("Impish Mint"),
        .nombre = ITEM_NAME("Menta traviesa"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
            "Can be smelled. It\n"
            "ups Def., but cuts\n"
            "Sp. Atk."),
        .descricao = COMPOUND_STRING(
            "Pode ser cheirado.\n"
            "Aumenta a Def., mas\n"
            "reduz Sp. Atk."),
        .descricion = COMPOUND_STRING(
            "Se puede oler.\n"
            "Aumenta la defensa,\n"
            "pero reduce la Sp."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_NATURE_MINT,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_IMPISH,
        .flingPower = 10,
        .iconPic = gItemIcon_Mint,
        .iconPalette = gItemIconPalette_BlueMint,
    },

    [ITEM_LAX_MINT] =
    {
        .name = ITEM_NAME("Lax Mint"),
        .nombre = ITEM_NAME("Menta laxa"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
            "Can be smelled. It\n"
            "ups Def., but cuts\n"
            "Sp. Def."),
        .descricao = COMPOUND_STRING(
            "Pode ser cheirado.\n"
            "Aumenta a Def., mas\n"
            "reduz Sp."),
        .descricion = COMPOUND_STRING(
            "Se puede oler.\n"
            "Aumenta la defensa,\n"
            "pero reduce la Sp."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_NATURE_MINT,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_LAX,
        .flingPower = 10,
        .iconPic = gItemIcon_Mint,
        .iconPalette = gItemIconPalette_BlueMint,
    },

    [ITEM_RELAXED_MINT] =
    {
        .name = ITEM_NAME("Relaxed Mint"),
        .nombre = ITEM_NAME("Menta relajada"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
            "Can be smelled. It\n"
            "ups Def., but cuts\n"
            "Speed."),
        .descricao = COMPOUND_STRING(
            "Pode ser cheirado.\n"
            "Aumenta a Def., mas\n"
            "reduz a Vel."),
        .descricion = COMPOUND_STRING(
            "Se puede oler.\n"
            "Aumenta la defensa,\n"
            "pero reduce la."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_NATURE_MINT,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_RELAXED,
        .flingPower = 10,
        .iconPic = gItemIcon_Mint,
        .iconPalette = gItemIconPalette_BlueMint,
    },

    [ITEM_MODEST_MINT] =
    {
        .name = ITEM_NAME("Modest Mint"),
        .nombre = ITEM_NAME("Menta modesta"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
            "Can be smelled. It\n"
            "ups Sp. Atk, but\n"
            "cuts Atk."),
        .descricao = COMPOUND_STRING(
            "Pode ser cheirado.\n"
            "Levanta Sp. Atk,\n"
            "mas reduz o Atq."),
        .descricion = COMPOUND_STRING(
            "Se puede oler. Sube\n"
            "Sp. Atk, pero\n"
            "reduce el Atq."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_NATURE_MINT,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_MODEST,
        .flingPower = 10,
        .iconPic = gItemIcon_Mint,
        .iconPalette = gItemIconPalette_LightBlueMint,
    },

    [ITEM_MILD_MINT] =
    {
        .name = ITEM_NAME("Mild Mint"),
        .nombre = ITEM_NAME("Menta suave"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
            "Can be smelled. It\n"
            "ups Sp. Atk, but\n"
            "cuts Def."),
        .descricao = COMPOUND_STRING(
            "Pode ser cheirado.\n"
            "Levanta Sp. Atk,\n"
            "mas reduz a Def."),
        .descricion = COMPOUND_STRING(
            "Se puede oler. Sube\n"
            "Sp. Atk, pero\n"
            "reduce la Def."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_NATURE_MINT,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_MILD,
        .flingPower = 10,
        .iconPic = gItemIcon_Mint,
        .iconPalette = gItemIconPalette_LightBlueMint,
    },

    [ITEM_RASH_MINT] =
    {
        .name = ITEM_NAME("Rash Mint"),
        .nombre = ITEM_NAME("Menta erupcion"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
            "Can be smelled. It\n"
            "ups Sp. Atk, but\n"
            "cuts Sp. Def."),
        .descricao = COMPOUND_STRING(
            "Pode ser cheirado.\n"
            "Levanta Sp. Atk,\n"
            "mas reduz Sp."),
        .descricion = COMPOUND_STRING(
            "Se puede oler. Sube\n"
            "Sp. Atk, pero\n"
            "reduce Sp. Def."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_NATURE_MINT,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_RASH,
        .flingPower = 10,
        .iconPic = gItemIcon_Mint,
        .iconPalette = gItemIconPalette_LightBlueMint,
    },

    [ITEM_QUIET_MINT] =
    {
        .name = ITEM_NAME("Quiet Mint"),
        .nombre = ITEM_NAME("Menta tranquila"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
            "Can be smelled. It\n"
            "ups Sp. Atk, but\n"
            "cuts Speed."),
        .descricao = COMPOUND_STRING(
            "Pode ser cheirado.\n"
            "Levanta Sp. Atk,\n"
            "mas reduz a Vel."),
        .descricion = COMPOUND_STRING(
            "Se puede oler. Sube\n"
            "Sp. Atk, pero\n"
            "reduce la Vel."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_NATURE_MINT,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_QUIET,
        .flingPower = 10,
        .iconPic = gItemIcon_Mint,
        .iconPalette = gItemIconPalette_LightBlueMint,
    },

    [ITEM_CALM_MINT] =
    {
        .name = ITEM_NAME("Calm Mint"),
        .nombre = ITEM_NAME("Menta tranquila"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
            "Can be smelled. It\n"
            "ups Sp. Def, but\n"
            "cuts Atk."),
        .descricao = COMPOUND_STRING(
            "Pode ser cheirado.\n"
            "Levanta Sp. Def,\n"
            "mas reduz o Atq."),
        .descricion = COMPOUND_STRING(
            "Se puede oler. Sube\n"
            "Sp. Def, pero\n"
            "reduce el Atq."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_NATURE_MINT,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_CALM,
        .flingPower = 10,
        .iconPic = gItemIcon_Mint,
        .iconPalette = gItemIconPalette_PinkMint,
    },

    [ITEM_GENTLE_MINT] =
    {
        .name = ITEM_NAME("Gentle Mint"),
        .nombre = ITEM_NAME("Menta suave"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
            "Can be smelled. It\n"
            "ups Sp. Def, but\n"
            "cuts Def."),
        .descricao = COMPOUND_STRING(
            "Pode ser cheirado.\n"
            "Levanta Sp. Def,\n"
            "mas reduz a Def."),
        .descricion = COMPOUND_STRING(
            "Se puede oler. Sube\n"
            "Sp. Def, pero\n"
            "reduce la Def."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_NATURE_MINT,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_GENTLE,
        .flingPower = 10,
        .iconPic = gItemIcon_Mint,
        .iconPalette = gItemIconPalette_PinkMint,
    },

    [ITEM_CAREFUL_MINT] =
    {
        .name = ITEM_NAME("Careful Mint"),
        .nombre = ITEM_NAME("Menta cuidadosa"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
            "Can be smelled. It\n"
            "ups Sp. Def, but\n"
            "cuts Sp. Atk."),
        .descricao = COMPOUND_STRING(
            "Pode ser cheirado.\n"
            "Levanta Sp. Def,\n"
            "mas reduz Sp. Atk."),
        .descricion = COMPOUND_STRING(
            "Se puede oler. Sube\n"
            "Sp. Def, pero\n"
            "reduce Sp. Atk."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_NATURE_MINT,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_CAREFUL,
        .flingPower = 10,
        .iconPic = gItemIcon_Mint,
        .iconPalette = gItemIconPalette_PinkMint,
    },

    [ITEM_SASSY_MINT] =
    {
        .name = ITEM_NAME("Sassy Mint"),
        .nombre = ITEM_NAME("Menta atrevida"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
            "Can be smelled. It\n"
            "ups Sp. Def, but\n"
            "cuts Speed."),
        .descricao = COMPOUND_STRING(
            "Pode ser cheirado.\n"
            "Levanta Sp. Def,\n"
            "mas reduz a Vel."),
        .descricion = COMPOUND_STRING(
            "Se puede oler. Sube\n"
            "Sp. Def, pero\n"
            "reduce la Vel."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_NATURE_MINT,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_SASSY,
        .flingPower = 10,
        .iconPic = gItemIcon_Mint,
        .iconPalette = gItemIconPalette_PinkMint,
    },

    [ITEM_TIMID_MINT] =
    {
        .name = ITEM_NAME("Timid Mint"),
        .nombre = ITEM_NAME("Menta timida"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
            "Can be smelled. It\n"
            "ups Speed, but cuts\n"
            "Atk."),
        .descricao = COMPOUND_STRING(
            "Pode ser cheirado.\n"
            "Aumenta a Vel., mas\n"
            "reduz o Atq."),
        .descricion = COMPOUND_STRING(
            "Se puede oler.\n"
            "Aumenta la Vel.,\n"
            "pero reduce el."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_NATURE_MINT,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_TIMID,
        .flingPower = 10,
        .iconPic = gItemIcon_Mint,
        .iconPalette = gItemIconPalette_GreenMint,
    },

    [ITEM_HASTY_MINT] =
    {
        .name = ITEM_NAME("Hasty Mint"),
        .nombre = ITEM_NAME("Menta apresurada"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
            "Can be smelled. It\n"
            "ups Speed, but cuts\n"
            "Def."),
        .descricao = COMPOUND_STRING(
            "Pode ser cheirado.\n"
            "Aumenta a Vel., mas\n"
            "reduz a Def."),
        .descricion = COMPOUND_STRING(
            "Se puede oler.\n"
            "Aumenta la Vel.,\n"
            "pero reduce la."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_NATURE_MINT,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_HASTY,
        .flingPower = 10,
        .iconPic = gItemIcon_Mint,
        .iconPalette = gItemIconPalette_GreenMint,
    },

    [ITEM_JOLLY_MINT] =
    {
        .name = ITEM_NAME("Jolly Mint"),
        .nombre = ITEM_NAME("Menta alegre"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
            "Can be smelled. It\n"
            "ups Speed, but cuts\n"
            "Sp. Atk."),
        .descricao = COMPOUND_STRING(
            "Pode ser cheirado.\n"
            "Aumenta a Vel., mas\n"
            "reduz o Sp. Atk."),
        .descricion = COMPOUND_STRING(
            "Se puede oler.\n"
            "Aumenta la Vel.,\n"
            "pero reduce la Sp."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_NATURE_MINT,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_JOLLY,
        .flingPower = 10,
        .iconPic = gItemIcon_Mint,
        .iconPalette = gItemIconPalette_GreenMint,
    },

    [ITEM_NAIVE_MINT] =
    {
        .name = ITEM_NAME("Naive Mint"),
        .nombre = ITEM_NAME("Menta ingenua"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
            "Can be smelled. It\n"
            "ups Speed, but cuts\n"
            "Sp. Def."),
        .descricao = COMPOUND_STRING(
            "Pode ser cheirado.\n"
            "Aumenta a Vel., mas\n"
            "reduz o Sp."),
        .descricion = COMPOUND_STRING(
            "Se puede oler.\n"
            "Aumenta la Vel.,\n"
            "pero reduce la Sp."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_NATURE_MINT,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_NAIVE,
        .flingPower = 10,
        .iconPic = gItemIcon_Mint,
        .iconPalette = gItemIconPalette_GreenMint,
    },

    [ITEM_SERIOUS_MINT] =
    {
        .name = ITEM_NAME("Serious Mint"),
        .nombre = ITEM_NAME("Menta seria"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
            "Can be smelled. It\n"
            "makes each stat\n"
            "grow equally."),
        .descricao = COMPOUND_STRING(
            "Pode ser cheirado.\n"
            "Faz com que cada\n"
            "estatística cresça."),
        .descricion = COMPOUND_STRING(
            "Se puede oler. Hace\n"
            "cada estadística\n"
            "crezca por igual."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_NATURE_MINT,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_SERIOUS,
        .flingPower = 10,
        .iconPic = gItemIcon_Mint,
        .iconPalette = gItemIconPalette_YellowMint,
    },

// Candy

    [ITEM_RARE_CANDY] =
    {
        .name = ITEM_NAME("Rare Candy"),
        .nombre = ITEM_NAME("Caramelo raro"),
        .pluralName = ITEM_PLURAL_NAME("Rare Candies"),
        .price = (I_PRICE >= GEN_7) ? 10000 : 4800,
        .description = COMPOUND_STRING(
            "Raises the level of\n"
            "a Pokémon by one."),
        .descricao = COMPOUND_STRING(
            "Aumenta o nível de\n"
            "um Pokémon em um."),
        .descricion = COMPOUND_STRING(
            "Sube el nivel de un\n"
            "Pokémon en uno."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_LEVEL_UP_ITEM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_RareCandy,
        .effect = gItemEffect_RareCandy,
        .flingPower = 30,
        .iconPic = gItemIcon_RareCandy,
        .iconPalette = gItemIconPalette_RareCandy,
    },

    [ITEM_EXP_CANDY_XS] =
    {
        .name = ITEM_NAME("Exp. Candy XS"),
        .nombre = ITEM_NAME("Exp. Caramelo XS"),
        .pluralName = ITEM_PLURAL_NAME("Exp. Candies XS"),
        .price = 20,
        .holdEffectParam = EXP_100,
        .description = COMPOUND_STRING(
            "Gives a very small\n"
            "amount of Exp. to a\n"
            "single Pokémon."),
        .descricao = COMPOUND_STRING(
            "Dá uma quantidade\n"
            "muito pequena de\n"
            "Exp. para um único."),
        .descricion = COMPOUND_STRING(
            "Da una cantidad muy\n"
            "pequeña de Exp. a\n"
            "un solo Pokémon."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_LEVEL_UP_ITEM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_RareCandy,
        .effect = gItemEffect_RareCandy,
        .flingPower = 30,
        .iconPic = gItemIcon_ExpCandyXS,
        .iconPalette = gItemIconPalette_ExpCandies,
    },

    [ITEM_EXP_CANDY_S] =
    {
        .name = ITEM_NAME("Exp. Candy S"),
        .nombre = ITEM_NAME("Exp. caramelos"),
        .pluralName = ITEM_PLURAL_NAME("Exp. Candies S"),
        .price = 240,
        .holdEffectParam = EXP_800,
        .description = COMPOUND_STRING(
            "Gives a small\n"
            "amount of Exp. to a\n"
            "single Pokémon."),
        .descricao = COMPOUND_STRING(
            "Dá uma pequena\n"
            "quantidade de Exp.\n"
            "para um único."),
        .descricion = COMPOUND_STRING(
            "Da una pequeña\n"
            "cantidad de Exp. a\n"
            "un solo Pokémon."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_LEVEL_UP_ITEM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_RareCandy,
        .effect = gItemEffect_RareCandy,
        .flingPower = 30,
        .iconPic = gItemIcon_ExpCandyS,
        .iconPalette = gItemIconPalette_ExpCandies,
    },

    [ITEM_EXP_CANDY_M] =
    {
        .name = ITEM_NAME("Exp. Candy M"),
        .nombre = ITEM_NAME("Exp. caramelo m"),
        .pluralName = ITEM_PLURAL_NAME("Exp. Candies M"),
        .price = 1000,
        .holdEffectParam = EXP_3000,
        .description = COMPOUND_STRING(
            "Gives a moderate\n"
            "amount of Exp. to a\n"
            "single Pokémon."),
        .descricao = COMPOUND_STRING(
            "Dá uma quantidade\n"
            "moderada de Exp.\n"
            "para um único."),
        .descricion = COMPOUND_STRING(
            "Da una cantidad\n"
            "moderada de Exp. a\n"
            "un solo Pokémon."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_LEVEL_UP_ITEM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_RareCandy,
        .effect = gItemEffect_RareCandy,
        .flingPower = 30,
        .iconPic = gItemIcon_ExpCandyM,
        .iconPalette = gItemIconPalette_ExpCandies,
    },

    [ITEM_EXP_CANDY_L] =
    {
        .name = ITEM_NAME("Exp. Candy L"),
        .nombre = ITEM_NAME("Exp. caramelo l"),
        .pluralName = ITEM_PLURAL_NAME("Exp. Candies L"),
        .price = 3000,
        .holdEffectParam = EXP_10000,
        .description = COMPOUND_STRING(
            "Gives a large\n"
            "amount of Exp. to a\n"
            "single Pokémon."),
        .descricao = COMPOUND_STRING(
            "Dá uma grande\n"
            "quantidade de Exp.\n"
            "para um único."),
        .descricion = COMPOUND_STRING(
            "Da una gran\n"
            "cantidad de Exp. a\n"
            "un solo Pokémon."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_LEVEL_UP_ITEM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_RareCandy,
        .effect = gItemEffect_RareCandy,
        .flingPower = 30,
        .iconPic = gItemIcon_ExpCandyL,
        .iconPalette = gItemIconPalette_ExpCandies,
    },

    [ITEM_EXP_CANDY_XL] =
    {
        .name = ITEM_NAME("Exp. Candy XL"),
        .nombre = ITEM_NAME("Exp. Caramelo XL"),
        .pluralName = ITEM_PLURAL_NAME("Exp. Candies XL"),
        .price = 10000,
        .holdEffectParam = EXP_30000,
        .description = COMPOUND_STRING(
            "Gives a very large\n"
            "amount of Exp. to a\n"
            "single Pokémon."),
        .descricao = COMPOUND_STRING(
            "Dá uma quantidade\n"
            "muito grande de\n"
            "Exp. para um único."),
        .descricion = COMPOUND_STRING(
            "Da una gran\n"
            "cantidad de Exp. a\n"
            "un solo Pokémon."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_LEVEL_UP_ITEM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_RareCandy,
        .effect = gItemEffect_RareCandy,
        .flingPower = 30,
        .iconPic = gItemIcon_ExpCandyXL,
        .iconPalette = gItemIconPalette_ExpCandies,
    },

    [ITEM_DYNAMAX_CANDY] =
    {
        .name = ITEM_NAME("Dynamax Candy"),
        .nombre = ITEM_NAME("Caramelo Dinamax"),
        .pluralName = ITEM_PLURAL_NAME("Dynamax Candies"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Raises the Dynamax\n"
            "Level of a single\n"
            "Pokémon by one."),
        .descricao = COMPOUND_STRING(
            "Aumenta o nível\n"
            "Dynamax de um único\n"
            "Pokémon em um."),
        .descricion = COMPOUND_STRING(
            "Aumenta en uno el\n"
            "nivel Dynamax de un\n"
            "solo Pokémon."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_LEVEL_UP_ITEM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_DynamaxCandy,
        .flingPower = 30,
        .iconPic = gItemIcon_DynamaxCandy,
        .iconPalette = gItemIconPalette_DynamaxCandy,
    },

// Medicinal Flutes

    [ITEM_BLUE_FLUTE] =
    {
        .name = ITEM_NAME("Blue Flute"),
        .nombre = ITEM_NAME("Flauta azul"),
        .price = (I_PRICE >= GEN_7) ? 20 : 100,
        .description = COMPOUND_STRING(
            "A glass flute that\n"
            "awakens sleeping\n"
            "Pokémon."),
        .descricao = COMPOUND_STRING(
            "Uma flauta vidro\n"
            "desperta Pokémon\n"
            "adormecidos."),
        .descricion = COMPOUND_STRING(
            "Una flauta de\n"
            "cristal que\n"
            "despierta a los."),
        .notConsumed = TRUE,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FLUTE,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_Awakening,
        .flingPower = 30,
        .iconPic = gItemIcon_Flute,
        .iconPalette = gItemIconPalette_BlueFlute,
    },

    [ITEM_YELLOW_FLUTE] =
    {
        .name = ITEM_NAME("Yellow Flute"),
        .nombre = ITEM_NAME("Flauta amarilla"),
        .price = (I_PRICE >= GEN_7) ? 20 : 300,
        .description = COMPOUND_STRING(
            "A glass flute that\n"
            "snaps Pokémon out\n"
            "of confusion."),
        .descricao = COMPOUND_STRING(
            "Uma flauta de vidro\n"
            "que tira os Pokémon\n"
            "da confusão."),
        .descricion = COMPOUND_STRING(
            "Una flauta de\n"
            "cristal que saca a\n"
            "los Pokémon de la."),
        .notConsumed = TRUE,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FLUTE,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_YellowFlute,
        .flingPower = 30,
        .iconPic = gItemIcon_Flute,
        .iconPalette = gItemIconPalette_YellowFlute,
    },

    [ITEM_RED_FLUTE] =
    {
        .name = ITEM_NAME("Red Flute"),
        .nombre = ITEM_NAME("flauta roja"),
        .price = (I_PRICE >= GEN_7) ? 20 : 200,
        .description = COMPOUND_STRING(
            "A glass flute that\n"
            "snaps Pokémon out\n"
            "of attraction."),
        .descricao = COMPOUND_STRING(
            "Uma flauta de vidro\n"
            "que tira os Pokémon\n"
            "da atração."),
        .descricion = COMPOUND_STRING(
            "Una flauta de\n"
            "cristal que saca a\n"
            "los Pokémon de su."),
        .notConsumed = TRUE,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FLUTE,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_RedFlute,
        .flingPower = 30,
        .iconPic = gItemIcon_Flute,
        .iconPalette = gItemIconPalette_RedFlute,
    },

// Encounter-modifying Flutes

    [ITEM_BLACK_FLUTE] =
    {
        .name = ITEM_NAME("Black Flute"),
        .nombre = ITEM_NAME("Flauta Negra"),
        .price = (I_PRICE >= GEN_7) ? 20 : 400,
        .holdEffectParam = 50,
        .description = COMPOUND_STRING(
            "A glass flute that\n"
            "keeps away wild\n"
            "Pokémon."),
        .descricao = COMPOUND_STRING(
            "Uma flauta de vidro\n"
            "que afasta Pokémon\n"
            "selv."),
        .descricion = COMPOUND_STRING(
            "Una flauta cristal\n"
            "mantiene alejados\n"
            "los."),
        .notConsumed = TRUE,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FLUTE,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_BlackWhiteFlute,
        .flingPower = 30,
        .iconPic = gItemIcon_Flute,
        .iconPalette = gItemIconPalette_BlackFlute,
    },

    [ITEM_WHITE_FLUTE] =
    {
        .name = ITEM_NAME("White Flute"),
        .nombre = ITEM_NAME("Flauta blanca"),
        .price = (I_PRICE >= GEN_7) ? 20 : 500,
        .holdEffectParam = 150,
        .description = COMPOUND_STRING(
            "A glass flute that\n"
            "lures wild Pokémon."),
        .descricao = COMPOUND_STRING(
            "Uma flauta de vidro\n"
            "que atrai Pokémon\n"
            "selv."),
        .descricion = COMPOUND_STRING(
            "Una flauta de\n"
            "cristal que atrae a\n"
            "Pokémon salvajes."),
        .notConsumed = TRUE,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FLUTE,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_BlackWhiteFlute,
        .flingPower = 30,
        .iconPic = gItemIcon_Flute,
        .iconPalette = gItemIconPalette_WhiteFlute,
    },

// Encounter Modifiers

    [ITEM_REPEL] =
    {
        .name = ITEM_NAME("Repel"),
        .nombre = ITEM_NAME("Repeler"),
        .price = (I_PRICE >= GEN_7) ? 400 : 350,
        .holdEffectParam = 100,
        .description = COMPOUND_STRING(
            "Repels weak wild\n"
            "Pokémon for 100\n"
            "steps."),
        .descricao = COMPOUND_STRING(
            "Repele Pokémon\n"
            "selv. fracos por\n"
            "100 passos."),
        .descricion = COMPOUND_STRING(
            "Repele Pokémon\n"
            "salvajes débiles\n"
            "durante 100 pasos."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FIELD_USE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Repel,
        .flingPower = 30,
        .iconPic = gItemIcon_Repel,
        .iconPalette = gItemIconPalette_Repel,
    },

    [ITEM_SUPER_REPEL] =
    {
        .name = ITEM_NAME("Super Repel"),
        .nombre = ITEM_NAME("Super repeler"),
        .price = (I_PRICE >= GEN_7) ? 700 : 500,
        .holdEffectParam = 200,
        .description = COMPOUND_STRING(
            "Repels weak wild\n"
            "Pokémon for 200\n"
            "steps."),
        .descricao = COMPOUND_STRING(
            "Repele Pokémon\n"
            "selv. fracos por\n"
            "200 passos."),
        .descricion = COMPOUND_STRING(
            "Repele Pokémon\n"
            "salvajes débiles\n"
            "durante 200 pasos."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FIELD_USE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Repel,
        .flingPower = 30,
        .iconPic = gItemIcon_Repel,
        .iconPalette = gItemIconPalette_SuperRepel,
    },

    [ITEM_MAX_REPEL] =
    {
        .name = ITEM_NAME("Max Repel"),
        .nombre = ITEM_NAME("Repeler maximo"),
        .price = (I_PRICE >= GEN_7) ? 900 : 700,
        .holdEffectParam = 250,
        .description = COMPOUND_STRING(
            "Repels weak wild\n"
            "Pokémon for 250\n"
            "steps."),
        .descricao = COMPOUND_STRING(
            "Repele Pokémon\n"
            "selv. fracos por\n"
            "250 passos."),
        .descricion = COMPOUND_STRING(
            "Repele Pokémon\n"
            "salvajes débiles\n"
            "durante 250 pasos."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FIELD_USE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Repel,
        .flingPower = 30,
        .iconPic = gItemIcon_Repel,
        .iconPalette = gItemIconPalette_MaxRepel,
    },

    [ITEM_LURE] =
    {
        .name = ITEM_NAME("Lure"),
        .nombre = ITEM_NAME("senuelo"),
        .price = 400,
        .holdEffectParam = 100,
        .description = COMPOUND_STRING(
            "Makes Pokémon more\n"
            "likely to appear\n"
            "for 100 steps."),
        .descricao = COMPOUND_STRING(
            "Aumenta\n"
            "probabilidade\n"
            "Pokémon aparecer."),
        .descricion = COMPOUND_STRING(
            "Hace sea más\n"
            "probable aparezcan\n"
            "Pokémon en"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FIELD_USE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Lure,
        .secondaryId = 0,
        .flingPower = 30,
        .iconPic = gItemIcon_Lure,
        .iconPalette = gItemIconPalette_Lure,
    },

    [ITEM_SUPER_LURE] =
    {
        .name = ITEM_NAME("Super Lure"),
        .nombre = ITEM_NAME("Super senuelo"),
        .price = 700,
        .holdEffectParam = 200,
        .description = COMPOUND_STRING(
            "Makes Pokémon more\n"
            "likely to appear\n"
            "for 200 steps."),
        .descricao = COMPOUND_STRING(
            "Aumenta\n"
            "probabilidade\n"
            "Pokémon aparecer."),
        .descricion = COMPOUND_STRING(
            "Hace sea más\n"
            "probable aparezcan\n"
            "Pokémon en"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FIELD_USE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Lure,
        .secondaryId = 0,
        .flingPower = 30,
        .iconPic = gItemIcon_Lure,
        .iconPalette = gItemIconPalette_SuperLure,
    },

    [ITEM_MAX_LURE] =
    {
        .name = ITEM_NAME("Max Lure"),
        .nombre = ITEM_NAME("Senuelo maximo"),
        .price = 900,
        .holdEffectParam = 250,
        .description = COMPOUND_STRING(
            "Makes Pokémon more\n"
            "likely to appear\n"
            "for 250 steps."),
        .descricao = COMPOUND_STRING(
            "Aumenta\n"
            "probabilidade\n"
            "Pokémon aparecer."),
        .descricion = COMPOUND_STRING(
            "Hace sea más\n"
            "probable aparezcan\n"
            "Pokémon en"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FIELD_USE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Lure,
        .secondaryId = 0,
        .flingPower = 30,
        .iconPic = gItemIcon_Lure,
        .iconPalette = gItemIconPalette_MaxLure,
    },

    [ITEM_ESCAPE_ROPE] =
    {
        .name = ITEM_NAME("Escape Rope"),
        .nombre = ITEM_NAME("Cuerda de escape"),
        .description = COMPOUND_STRING(
            "Use to escape\n"
            "instantly from a\n"
            "cave or a dungeon."),
        .descricao = COMPOUND_STRING(
            "Use para escapar\n"
            "instantaneamente de\n"
            "uma caverna ou."),
        .descricion = COMPOUND_STRING(
            "Úselo para escapar\n"
            "instantáneamente de\n"
            "una cueva o."),
    #if I_KEY_ESCAPE_ROPE >= GEN_8
        .price = 0,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
    #else
        .price = (I_PRICE >= GEN_7) ? 1000 : 550,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FIELD_USE,
    #endif
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_EscapeRope,
        .flingPower = 30,
        .iconPic = gItemIcon_EscapeRope,
        .iconPalette = gItemIconPalette_EscapeRope,
    },

// X Items

    [ITEM_X_ATTACK] =
    {
        .name = ITEM_NAME("X Attack"),
        .nombre = ITEM_NAME("Ataque X"),
        .price = (I_PRICE >= GEN_7) ? 1000 : 500,
        .holdEffectParam = X_ITEM_STAGES,
        .description = COMPOUND_STRING(
        #if B_X_ITEMS_BUFF >= GEN_7
            "Sharply boosts stat\n"
            "Atk. during one\n"
            "battle."),
        .descricao = COMPOUND_STRING(
            "Aumenta muito o\n"
            "Atq. estatístico\n"
            "durante uma luta."),
        .descricion = COMPOUND_STRING(
            "Aumenta mucho las\n"
            "estadísticas de\n"
            "Atq. durante una."),
        #else
            "Raises the stat\n"
            "Attack during one\n"
            "battle."),
        #endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_X_ITEM,
        .type = B_X_ITEMS_CROSSUSE ? ITEM_USE_BATTLER : ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = EFFECT_ITEM_INCREASE_STAT,
        .effect = gItemEffect_XAttack,
        .flingPower = 30,
        .iconPic = gItemIcon_BattleStatItem,
        .iconPalette = gItemIconPalette_XAttack,
    },

    [ITEM_X_DEFENSE] =
    {
        .name = ITEM_NAME("X Defense"),
        .nombre = ITEM_NAME("Defensa X"),
        .price = (I_PRICE >= GEN_7) ? 2000 : 550,
        .holdEffectParam = X_ITEM_STAGES,
        .description = COMPOUND_STRING(
        #if B_X_ITEMS_BUFF >= GEN_7
            "Sharply boosts stat\n"
            "Def. during one\n"
            "battle."),
        .descricao = COMPOUND_STRING(
            "Aumenta muito a\n"
            "Def. estatística\n"
            "durante uma luta."),
        .descricion = COMPOUND_STRING(
            "Aumenta mucho las\n"
            "estadísticas Def.\n"
            "durante una."),
        #else
            "Raises the stat\n"
            "Defense during one\n"
            "battle."),
        #endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_X_ITEM,
        .type = B_X_ITEMS_CROSSUSE ? ITEM_USE_BATTLER : ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = EFFECT_ITEM_INCREASE_STAT,
        .effect = gItemEffect_XDefense,
        .flingPower = 30,
        .iconPic = gItemIcon_BattleStatItem,
        .iconPalette = gItemIconPalette_XDefend,
    },

    [ITEM_X_SP_ATK] =
    {
        .name = ITEM_NAME("X Sp. Atk"),
        .nombre = ITEM_NAME("X Sp. Atk"),
        .price = (I_PRICE >= GEN_7) ? 1000 : 350,
        .holdEffectParam = X_ITEM_STAGES,
        .description = COMPOUND_STRING(
        #if B_X_ITEMS_BUFF >= GEN_7
            "Sharply boosts stat\n"
            "Sp. Atk during one\n"
            "battle."),
        .descricao = COMPOUND_STRING(
            "Aumenta\n"
            "acentuadamente stat\n"
            "Sp. Atk durante"),
        .descricion = COMPOUND_STRING(
            "Aumenta bruscamente\n"
            "la estadística Sp.\n"
            "Atk durante una."),
        #else
            "Raises the stat Sp.\n"
            "Atk during one\n"
            "battle."),
        #endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_X_ITEM,
        .type = B_X_ITEMS_CROSSUSE ? ITEM_USE_BATTLER : ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = EFFECT_ITEM_INCREASE_STAT,
        .effect = gItemEffect_XSpecialAttack,
        .flingPower = 30,
        .iconPic = gItemIcon_BattleStatItem,
        .iconPalette = gItemIconPalette_XSpecial,
    },

    [ITEM_X_SP_DEF] =
    {
        .name = ITEM_NAME("X Sp. Def"),
        .nombre = ITEM_NAME("X Sp. definicion"),
        .price = (I_PRICE >= GEN_7) ? 2000 : 350,
        .holdEffectParam = X_ITEM_STAGES,
        .description = COMPOUND_STRING(
        #if B_X_ITEMS_BUFF >= GEN_7
            "Sharply boosts stat\n"
            "Sp. Def during one\n"
            "battle."),
        .descricao = COMPOUND_STRING(
            "Aumenta\n"
            "acentuadamente stat\n"
            "Sp. Def durante"),
        .descricion = COMPOUND_STRING(
            "Aumenta bruscamente\n"
            "la estadística Sp.\n"
            "Def durante una."),
        #else
            "Raises the stat Sp.\n"
            "Def during one\n"
            "battle."),
        #endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_X_ITEM,
        .type = B_X_ITEMS_CROSSUSE ? ITEM_USE_BATTLER : ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = EFFECT_ITEM_INCREASE_STAT,
        .effect = gItemEffect_XSpecialDefense,
        .flingPower = 30,
        .iconPic = gItemIcon_BattleStatItem,
        .iconPalette = gItemIconPalette_XSpecialDefense,
    },

    [ITEM_X_SPEED] =
    {
        .name = ITEM_NAME("X Speed"),
        .nombre = ITEM_NAME("Velocidad X"),
        .price = (I_PRICE >= GEN_7) ? 1000 : 350,
        .holdEffectParam = X_ITEM_STAGES,
        .description = COMPOUND_STRING(
        #if B_X_ITEMS_BUFF >= GEN_7
            "Sharply boosts stat\n"
            "Speed during one\n"
            "battle."),
        .descricao = COMPOUND_STRING(
            "Aumenta muito a\n"
            "Vel. estatística\n"
            "durante uma luta."),
        .descricion = COMPOUND_STRING(
            "Aumenta mucho la\n"
            "Vel. estadística\n"
            "durante una."),
        #else
            "Raises the stat\n"
            "Speed during one\n"
            "battle."),
        #endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_X_ITEM,
        .type = B_X_ITEMS_CROSSUSE ? ITEM_USE_BATTLER : ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = EFFECT_ITEM_INCREASE_STAT,
        .effect = gItemEffect_XSpeed,
        .flingPower = 30,
        .iconPic = gItemIcon_BattleStatItem,
        .iconPalette = gItemIconPalette_XSpeed,
    },

    [ITEM_X_ACCURACY] =
    {
        .name = ITEM_NAME("X Accuracy"),
        .nombre = ITEM_NAME("X Precision"),
        .pluralName = ITEM_PLURAL_NAME("X Accuracies"),
        .price = (I_PRICE >= GEN_7) ? 1000 : 950,
        .holdEffectParam = X_ITEM_STAGES,
        .description = COMPOUND_STRING(
        #if B_X_ITEMS_BUFF >= GEN_7
            "Sharply boosts move\n"
            "acc. during one\n"
            "battle."),
        .descricao = COMPOUND_STRING(
            "Aumenta muito a\n"
            "prec. do golpe\n"
            "durante uma luta."),
        .descricion = COMPOUND_STRING(
            "Aumenta mucho la\n"
            "precisión de los\n"
            "movs. durante una."),
        #else
            "Raises accuracy of\n"
            "attack moves during\n"
            "one battle."),
        #endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_X_ITEM,
        .type = B_X_ITEMS_CROSSUSE ? ITEM_USE_BATTLER : ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = EFFECT_ITEM_INCREASE_STAT,
        .effect = gItemEffect_XAccuracy,
        .flingPower = 30,
        .iconPic = gItemIcon_BattleStatItem,
        .iconPalette = gItemIconPalette_XAccuracy,
    },

    [ITEM_DIRE_HIT] =
    {
        .name = ITEM_NAME("Dire Hit"),
        .nombre = ITEM_NAME("Golpe terrible"),
        .price = (I_PRICE >= GEN_7) ? 1000 : 650,
        .description = COMPOUND_STRING(
            "Raises the\n"
            "critical-hit ratio\n"
            "during one battle."),
        .descricao = COMPOUND_STRING(
            "Aumenta a taxa de\n"
            "acerto crítico\n"
            "durante uma luta."),
        .descricion = COMPOUND_STRING(
            "Aumenta la\n"
            "proporción golpes\n"
            "críticos durante."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_X_ITEM,
        .type = B_X_ITEMS_CROSSUSE ? ITEM_USE_BATTLER : ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = EFFECT_ITEM_SET_FOCUS_ENERGY,
        .effect = gItemEffect_DireHit,
        .flingPower = 30,
        .iconPic = gItemIcon_BattleStatItem,
        .iconPalette = gItemIconPalette_DireHit,
    },

    [ITEM_GUARD_SPEC] =
    {
        .name = ITEM_NAME("Guard Spec."),
        .nombre = ITEM_NAME("Guard Spec."),
        .pluralName = ITEM_PLURAL_NAME("Guard Specs."),
        .price = (I_PRICE >= GEN_7) ? 1500 : 700,
        .description = COMPOUND_STRING(
            "Prevents stat\n"
            "reduction when used\n"
            "in battle."),
        .descricao = COMPOUND_STRING(
            "Impede a redução de\n"
            "estatísticas quando\n"
            "usado em luta."),
        .descricion = COMPOUND_STRING(
            "Previene la\n"
            "reducción\n"
            "estadísticas."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_X_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = EFFECT_ITEM_SET_MIST,
        .effect = gItemEffect_GuardSpec,
        .flingPower = 30,
        .iconPic = gItemIcon_BattleStatItem,
        .iconPalette = gItemIconPalette_GuardSpec,
    },

    [ITEM_POKE_DOLL] =
    {
        .name = ITEM_NAME("Poké Doll"),
        .nombre = ITEM_NAME("muneca poke"),
    #if I_PRICE >= GEN_8
        .price = 300,
    #elif I_PRICE == GEN_7
        .price = 100,
    #else
        .price = 1000,
    #endif
        .description = sPokeDollDesc,
        .descricao = COMPOUND_STRING(
            "Use para fugir\n"
            "qualquer luta com\n"
            "Pokémon selvagem."),
        .descricion = COMPOUND_STRING(
            "Úsalo para huir de\n"
            "cualquier batalla\n"
            "con un Pokémon."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_BATTLE_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = EFFECT_ITEM_ESCAPE,
        .flingPower = 30,
        .iconPic = gItemIcon_PokeDoll,
        .iconPalette = gItemIconPalette_PokeDoll,
    },

    [ITEM_FLUFFY_TAIL] =
    {
        .name = ITEM_NAME("Fluffy Tail"),
        .nombre = ITEM_NAME("Cola esponjosa"),
        .price = (I_PRICE >= GEN_7) ? 100 : 1000,
        .description = sPokeDollDesc,
        .descricao = COMPOUND_STRING(
            "Use para fugir\n"
            "qualquer luta com\n"
            "Pokémon selvagem."),
        .descricion = COMPOUND_STRING(
            "Úsalo para huir de\n"
            "cualquier batalla\n"
            "con un Pokémon."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_BATTLE_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = EFFECT_ITEM_ESCAPE,
        .flingPower = 30,
        .iconPic = gItemIcon_FluffyTail,
        .iconPalette = gItemIconPalette_FluffyTail,
    },

    [ITEM_POKE_TOY] =
    {
        .name = ITEM_NAME("Poké Toy"),
        .nombre = ITEM_NAME("Juguete Poke"),
        .price = (I_PRICE >= GEN_7) ? 100 : 1000,
        .description = sPokeDollDesc,
        .descricao = COMPOUND_STRING(
            "Use para fugir\n"
            "qualquer luta com\n"
            "Pokémon selvagem."),
        .descricion = COMPOUND_STRING(
            "Úsalo para huir de\n"
            "cualquier batalla\n"
            "con un Pokémon."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_BATTLE_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = EFFECT_ITEM_ESCAPE,
        .flingPower = 30,
        .iconPic = gItemIcon_PokeToy,
        .iconPalette = gItemIconPalette_PokeToy,
    },

    [ITEM_MAX_MUSHROOMS] =
    {
        .name = ITEM_NAME("Max Mushrooms"),
        .nombre = ITEM_NAME("Hongos maximos"),
        .pluralName = ITEM_PLURAL_NAME("Max Mushrooms"),
        .price = 8000,
        .description = COMPOUND_STRING(
            "Raises every stat\n"
            "during one battle\n"
            "by one stage."),
        .descricao = COMPOUND_STRING(
            "Aumenta todas\n"
            "estatísticas\n"
            "durante luta em"),
        .descricion = COMPOUND_STRING(
            "Aumenta cada\n"
            "estadística durante\n"
            "una batalla en un."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_BATTLE_ITEM,
        .type = B_X_ITEMS_CROSSUSE ? ITEM_USE_BATTLER : ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = EFFECT_ITEM_INCREASE_ALL_STATS,
        .flingPower = 30,
        .iconPic = gItemIcon_MaxMushrooms,
        .iconPalette = gItemIconPalette_MaxMushrooms,
    },

// Treasures

    [ITEM_BOTTLE_CAP] =
    {
        .name = ITEM_NAME("Bottle Cap"),
        .nombre = ITEM_NAME("tapa de botella"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 5000,
        .description = COMPOUND_STRING(
            "A beautiful bottle\n"
            "cap that gives off\n"
            "a silver gleam."),
        .descricao = COMPOUND_STRING(
            "Uma linda tampa de\n"
            "garrafa que emite\n"
            "um brilho prateado."),
        .descricion = COMPOUND_STRING(
            "Una preciosa tapa\n"
            "botella desprende\n"
            "un brillo."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SELLABLE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_BottleCap,
        .iconPalette = gItemIconPalette_BottleCap,
    },

    [ITEM_GOLD_BOTTLE_CAP] =
    {
        .name = ITEM_NAME("Gold Bottle Cap"),
        .nombre = ITEM_NAME("Gold Bottle Cap"),
        .price = (I_PRICE >= GEN_9) ? 60000 : 10000,
        .description = COMPOUND_STRING(
            "A beautiful bottle\n"
            "cap that gives off\n"
            "a golden gleam."),
        .descricao = COMPOUND_STRING(
            "Uma linda tampa de\n"
            "garrafa que emite\n"
            "um brilho dourado."),
        .descricion = COMPOUND_STRING(
            "Una preciosa tapa\n"
            "botella desprende\n"
            "un brillo."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SELLABLE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_BottleCap,
        .iconPalette = gItemIconPalette_GoldBottleCap,
    },

    [ITEM_NUGGET] =
    {
        .name = ITEM_NAME("Nugget"),
        .nombre = ITEM_NAME("pepita"),
        .price = 10000 * TREASURE_FACTOR,
        .description = COMPOUND_STRING(
            "A nugget of pure\n"
            "gold. Can be sold\n"
            "at a high price."),
        .descricao = COMPOUND_STRING(
            "Uma pepita de ouro\n"
            "puro. Pode vender\n"
            "por um preço alto."),
        .descricion = COMPOUND_STRING(
            "Una pepita de oro\n"
            "puro. Se puede\n"
            "vender a un precio."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SELLABLE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_Nugget,
        .iconPalette = gItemIconPalette_Nugget,
    },

    [ITEM_BIG_NUGGET] =
    {
        .name = ITEM_NAME("Big Nugget"),
        .nombre = ITEM_NAME("pepita grande"),
    #if I_PRICE >= GEN_7
        .price = 40000 * TREASURE_FACTOR,
    #elif I_PRICE == GEN_6
        .price = 20000,
    #else
        .price = 0,
    #endif
        .description = COMPOUND_STRING(
            "A big nugget made\n"
            "of gold, sellable\n"
            "at a high price."),
        .descricao = COMPOUND_STRING(
            "Uma grande pepita\n"
            "feita de ouro,\n"
            "vendável por um."),
        .descricion = COMPOUND_STRING(
            "Una gran pepita de\n"
            "oro que se puede\n"
            "vender a un precio."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SELLABLE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = B_UPDATED_MOVE_DATA >= GEN_8 ? 130 : 80,
        .iconPic = gItemIcon_BigNugget,
        .iconPalette = gItemIconPalette_BigNugget,
    },

    [ITEM_TINY_MUSHROOM] =
    {
        .name = ITEM_NAME("Tiny Mushroom"),
        .nombre = ITEM_NAME("Hongo pequeno"),
        .price = 500 * TREASURE_FACTOR,
        .description = COMPOUND_STRING(
            "A plain mushroom\n"
            "that would sell at\n"
            "a cheap price."),
        .descricao = COMPOUND_STRING(
            "Um cogumelo simples\n"
            "seria vendido por\n"
            "preço barato."),
        .descricion = COMPOUND_STRING(
            "Un hongo simple que\n"
            "se vendería a un\n"
            "precio barato."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SELLABLE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_TinyMushroom,
        .iconPalette = gItemIconPalette_Mushroom,
    },

    [ITEM_BIG_MUSHROOM] =
    {
        .name = ITEM_NAME("Big Mushroom"),
        .nombre = ITEM_NAME("Hongo grande"),
        .price = 5000 * TREASURE_FACTOR,
        .description = sBigMushroomDesc,
        .descricao = COMPOUND_STRING(
            "Um cogumelo raro\n"
            "que seria vendido\n"
            "por um preço alto."),
        .descricion = COMPOUND_STRING(
            "Un hongo raro que\n"
            "se vendería a un\n"
            "precio elevado."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SELLABLE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_BigMushroom,
        .iconPalette = gItemIconPalette_Mushroom,
    },

    [ITEM_BALM_MUSHROOM] =
    {
        .name = ITEM_NAME("Balm Mushroom"),
        .nombre = ITEM_NAME("Hongo Balsamo"),
    #if I_PRICE >= GEN_7
        .price = 15000 * TREASURE_FACTOR,
    #elif I_PRICE == GEN_6
        .price = 12500,
    #else
        .price = 0,
    #endif
        .description = sBigMushroomDesc,
        .descricao = COMPOUND_STRING(
            "Um cogumelo raro\n"
            "que seria vendido\n"
            "por um preço alto."),
        .descricion = COMPOUND_STRING(
            "Un hongo raro que\n"
            "se vendería a un\n"
            "precio elevado."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SELLABLE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_BalmMushroom,
        .iconPalette = gItemIconPalette_BalmMushroom,
    },

    [ITEM_PEARL] =
    {
        .name = ITEM_NAME("Pearl"),
        .nombre = ITEM_NAME("perla"),
        .price = (I_PRICE >= GEN_7) ? 2000 * TREASURE_FACTOR: 1400,
        .description = COMPOUND_STRING(
            "A pretty pearl that\n"
            "would sell at a\n"
            "cheap price."),
        .descricao = COMPOUND_STRING(
            "Uma linda pérola\n"
            "seria vendida por\n"
            "preço barato."),
        .descricion = COMPOUND_STRING(
            "Una bonita perla\n"
            "que se vendería a\n"
            "un precio barato."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SELLABLE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_Pearl,
        .iconPalette = gItemIconPalette_Pearl,
    },

    [ITEM_BIG_PEARL] =
    {
        .name = ITEM_NAME("Big Pearl"),
        .nombre = ITEM_NAME("gran perla"),
        .price = (I_PRICE >= GEN_7) ? 8000 * TREASURE_FACTOR: 7500,
        .description = COMPOUND_STRING(
            "A lovely large\n"
            "pearl would sell at\n"
            "high price."),
        .descricao = COMPOUND_STRING(
            "Uma linda pérola\n"
            "grande seria\n"
            "vendida por preço"),
        .descricion = COMPOUND_STRING(
            "Una hermosa perla\n"
            "grande vendería un\n"
            "precio"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SELLABLE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_BigPearl,
        .iconPalette = gItemIconPalette_Pearl,
    },

    [ITEM_PEARL_STRING] =
    {
        .name = ITEM_NAME("Pearl String"),
        .nombre = ITEM_NAME("Cadena de perlas"),
    #if I_PRICE >= GEN_8
        .price = 20000 * TREASURE_FACTOR,
    #elif I_PRICE == GEN_7
        .price = 30000,
    #elif I_PRICE == GEN_6
        .price = 15000,
    #else
        .price = 0,
    #endif
        .description = COMPOUND_STRING(
            "Very large pearls\n"
            "that would sell at\n"
            "a high price."),
        .descricao = COMPOUND_STRING(
            "Pérolas muito\n"
            "grandes que seriam\n"
            "vendidas por um."),
        .descricion = COMPOUND_STRING(
            "Perlas muy grandes\n"
            "que se venderían a\n"
            "un precio elevado."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SELLABLE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_PearlString,
        .iconPalette = gItemIconPalette_PearlString,
    },

    [ITEM_STARDUST] =
    {
        .name = ITEM_NAME("Stardust"),
        .nombre = ITEM_NAME("polvo de estrellas"),
        .price = (I_PRICE >= GEN_7) ? 3000 * TREASURE_FACTOR: 2000,
        .description = COMPOUND_STRING(
            "Beautiful red sand.\n"
            "Can be sold at a\n"
            "high price."),
        .descricao = COMPOUND_STRING(
            "Linda areia\n"
            "vermelha. Pode\n"
            "vender por preço."),
        .descricion = COMPOUND_STRING(
            "Hermosa arena roja.\n"
            "Se puede vender a\n"
            "un precio elevado."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SELLABLE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_Sand,
        .iconPalette = gItemIconPalette_Star,
    },

    [ITEM_STAR_PIECE] =
    {
        .name = ITEM_NAME("Star Piece"),
        .nombre = ITEM_NAME("pieza de estrella"),
        .price = (I_PRICE >= GEN_7) ? 12000 * TREASURE_FACTOR: 9800,
        .description = COMPOUND_STRING(
            "A red gem shard. It\n"
            "would sell for a\n"
            "very high price."),
        .descricao = COMPOUND_STRING(
            "Um fragmento gema\n"
            "vermelha. Seria\n"
            "vendido por preço"),
        .descricion = COMPOUND_STRING(
            "Un fragmento gema\n"
            "roja. Se vendería\n"
            "por un precio muy."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SELLABLE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_StarPiece,
        .iconPalette = gItemIconPalette_Star,
    },

    [ITEM_COMET_SHARD] =
    {
        .name = ITEM_NAME("Comet Shard"),
        .nombre = ITEM_NAME("Fragmento de cometa"),
    #if I_PRICE >= GEN_8
        .price = 25000 * TREASURE_FACTOR,
    #elif I_PRICE == GEN_7
        .price = 60000,
    #elif I_PRICE == GEN_6
        .price = 30000,
    #else
        .price = 0,
    #endif
        .description = COMPOUND_STRING(
            "A comet's shard. It\n"
            "would sell for a\n"
            "high price."),
        .descricao = COMPOUND_STRING(
            "O fragmento cometa.\n"
            "Seria vendido por\n"
            "preço"),
        .descricion = COMPOUND_STRING(
            "El fragmento de un\n"
            "cometa. Se vendería\n"
            "por un precio."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SELLABLE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_StarPiece,
        .iconPalette = gItemIconPalette_CometShard,
    },

    [ITEM_SHOAL_SALT] =
    {
        .name = ITEM_NAME("Shoal Salt"),
        .nombre = ITEM_NAME("Sal del banco"),
        .price = 20,
        .description = COMPOUND_STRING(
            "Salt obtained from\n"
            "deep inside the\n"
            "Shoal Cave."),
        .descricao = COMPOUND_STRING(
            "Sal obtido nas\n"
            "profundezas da\n"
            "Caverna Shoal."),
        .descricion = COMPOUND_STRING(
            "Sal obtenida de las\n"
            "profundidades de la\n"
            "Cueva Shoal."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SELLABLE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_Powder,
        .iconPalette = gItemIconPalette_ShoalSalt,
    },

    [ITEM_SHOAL_SHELL] =
    {
        .name = ITEM_NAME("Shoal Shell"),
        .nombre = ITEM_NAME("Concha de banco"),
        .price = 20,
        .description = COMPOUND_STRING(
            "A seashell found\n"
            "deep inside the\n"
            "Shoal Cave."),
        .descricao = COMPOUND_STRING(
            "Uma concha\n"
            "encontrada nas\n"
            "profundezas da."),
        .descricion = COMPOUND_STRING(
            "Una concha marina\n"
            "encontrada en lo\n"
            "profundo la cueva"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SELLABLE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_ShoalShell,
        .iconPalette = gItemIconPalette_Shell,
    },

    [ITEM_RED_SHARD] =
    {
        .name = ITEM_NAME("Red Shard"),
        .nombre = ITEM_NAME("Fragmento rojo"),
        .price = (I_PRICE >= GEN_7) ? 1000 : 200,
        .description = sShardsDesc,
        .descricao = COMPOUND_STRING(
            "Um fragmento de um\n"
            "item antigo. Pode\n"
            "vender barato."),
        .descricion = COMPOUND_STRING(
            "Un fragmento un\n"
            "objeto antiguo. Se\n"
            "puede vender."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SHARD,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_Shard,
        .iconPalette = gItemIconPalette_RedShard,
    },

    [ITEM_BLUE_SHARD] =
    {
        .name = ITEM_NAME("Blue Shard"),
        .nombre = ITEM_NAME("Fragmento azul"),
        .price = (I_PRICE >= GEN_7) ? 1000 : 200,
        .description = sShardsDesc,
        .descricao = COMPOUND_STRING(
            "Um fragmento de um\n"
            "item antigo. Pode\n"
            "vender barato."),
        .descricion = COMPOUND_STRING(
            "Un fragmento un\n"
            "objeto antiguo. Se\n"
            "puede vender."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SHARD,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_Shard,
        .iconPalette = gItemIconPalette_BlueShard,
    },

    [ITEM_YELLOW_SHARD] =
    {
        .name = ITEM_NAME("Yellow Shard"),
        .nombre = ITEM_NAME("Fragmento amarillo"),
        .price = (I_PRICE >= GEN_7) ? 1000 : 200,
        .description = sShardsDesc,
        .descricao = COMPOUND_STRING(
            "Um fragmento de um\n"
            "item antigo. Pode\n"
            "vender barato."),
        .descricion = COMPOUND_STRING(
            "Un fragmento un\n"
            "objeto antiguo. Se\n"
            "puede vender."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SHARD,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_Shard,
        .iconPalette = gItemIconPalette_YellowShard,
    },

    [ITEM_GREEN_SHARD] =
    {
        .name = ITEM_NAME("Green Shard"),
        .nombre = ITEM_NAME("Fragmento verde"),
        .price = (I_PRICE >= GEN_7) ? 1000 : 200,
        .description = sShardsDesc,
        .descricao = COMPOUND_STRING(
            "Um fragmento de um\n"
            "item antigo. Pode\n"
            "vender barato."),
        .descricion = COMPOUND_STRING(
            "Un fragmento un\n"
            "objeto antiguo. Se\n"
            "puede vender."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SHARD,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_Shard,
        .iconPalette = gItemIconPalette_GreenShard,
    },

    [ITEM_HEART_SCALE] =
    {
        .name = ITEM_NAME("Heart Scale"),
        .nombre = ITEM_NAME("Escala del corazon"),
        .price = 100,
        .description = COMPOUND_STRING(
            "A lovely scale. It\n"
            "is coveted by\n"
            "collectors."),
        .descricao = COMPOUND_STRING(
            "Uma escala\n"
            "adorável. É\n"
            "cobiçado por."),
        .descricion = COMPOUND_STRING(
            "Una escala\n"
            "preciosa. Es\n"
            "codiciado por los."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SELLABLE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_HeartScale,
        .iconPalette = gItemIconPalette_HeartScale,
    },

    [ITEM_HONEY] =
    {
        .name = ITEM_NAME("Honey"),
        .nombre = ITEM_NAME("miel"),
        .pluralName = ITEM_PLURAL_NAME("Honey"),
    #if I_PRICE >= GEN_8
        .price = 900,
    #elif I_PRICE == GEN_7
        .price = 300,
    #else
        .price = 100,
    #endif
        .description = COMPOUND_STRING(
            "Sweet honey that\n"
            "attracts wild\n"
            "Pokémon when used."),
        .descricao = COMPOUND_STRING(
            "Doce mel que atrai\n"
            "Pokémon selv.\n"
            "quando usado."),
        .descricion = COMPOUND_STRING(
            "Miel dulce que\n"
            "atrae a los Pokémon\n"
            "salvajes cuando se."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STATUS_RECOVERY,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Honey,
        .flingPower = 30,
        .iconPic = gItemIcon_Honey,
        .iconPalette = gItemIconPalette_Honey,
    },

    [ITEM_RARE_BONE] =
    {
        .name = ITEM_NAME("Rare Bone"),
        .nombre = ITEM_NAME("Hueso raro"),
        .price = (I_PRICE >= GEN_7) ? 5000 * TREASURE_FACTOR: 10000,
        .description = COMPOUND_STRING(
            "A very rare bone.\n"
            "It can be sold at a\n"
            "high price."),
        .descricao = COMPOUND_STRING(
            "Um osso muito raro.\n"
            "Pode vender por um\n"
            "preço alto."),
        .descricion = COMPOUND_STRING(
            "Un hueso muy raro.\n"
            "Se puede vender a\n"
            "un precio elevado."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SELLABLE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
        .iconPic = gItemIcon_Bone,
        .iconPalette = gItemIconPalette_Bone,
    },

    [ITEM_ODD_KEYSTONE] =
    {
        .name = ITEM_NAME("Odd Keystone"),
        .nombre = ITEM_NAME("Odd Keystone"),
        .price = 2100,
        .description = COMPOUND_STRING(
            "Voices can be heard\n"
            "from this odd stone\n"
            "occasionally."),
        .descricao = COMPOUND_STRING(
            "Vozes podem ser\n"
            "ouvidas\n"
            "ocasionalmente."),
        .descricion = COMPOUND_STRING(
            "De vez en cuando se\n"
            "pueden escuchar\n"
            "voces provenientes."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SELLABLE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_OddKeystone,
        .iconPalette = gItemIconPalette_OddKeystone,
    },

    [ITEM_PRETTY_FEATHER] =
    {
        .name = ITEM_NAME("Pretty Feather"),
        .nombre = ITEM_NAME("bonita pluma"),
        .price = (I_PRICE >= GEN_7) ? 1000 * TREASURE_FACTOR: 200,
        .description = COMPOUND_STRING(
            "A beautiful yet\n"
            "plain feather that\n"
            "does nothing."),
        .descricao = COMPOUND_STRING(
            "Uma pena linda, mas\n"
            "simples, que não\n"
            "faz nada."),
        .descricion = COMPOUND_STRING(
            "Una pluma hermosa\n"
            "pero sencilla que\n"
            "no hace nada."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SELLABLE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 20,
        .iconPic = gItemIcon_PrettyFeather,
        .iconPalette = gItemIconPalette_PrettyFeather,
    },

    [ITEM_RELIC_COPPER] =
    {
        .name = ITEM_NAME("Relic Copper"),
        .nombre = ITEM_NAME("Reliquia de cobre"),
        .price = 0,
        .description = COMPOUND_STRING(
            "A copper coin used\n"
            "long ago. It sells\n"
            "at a high price."),
        .descricao = COMPOUND_STRING(
            "Uma moeda cobre\n"
            "usada há tempo. É\n"
            "vendido por"),
        .descricion = COMPOUND_STRING(
            "Una moneda cobre\n"
            "utilizada hace\n"
            "mucho tiempo. Se."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_RELIC,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_RelicCoin,
        .iconPalette = gItemIconPalette_RelicCopper,
    },

    [ITEM_RELIC_SILVER] =
    {
        .name = ITEM_NAME("Relic Silver"),
        .nombre = ITEM_NAME("Reliquia Plata"),
        .price = 0,
        .description = COMPOUND_STRING(
            "A silver coin used\n"
            "long ago. It sells\n"
            "at a high price."),
        .descricao = COMPOUND_STRING(
            "Uma moeda prata\n"
            "usada há tempo. É\n"
            "vendido por"),
        .descricion = COMPOUND_STRING(
            "Una moneda plata\n"
            "utilizada hace\n"
            "mucho tiempo. Se."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_RELIC,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_RelicCoin,
        .iconPalette = gItemIconPalette_RelicSilver,
    },

    [ITEM_RELIC_GOLD] =
    {
        .name = ITEM_NAME("Relic Gold"),
        .nombre = ITEM_NAME("Reliquia de oro"),
        .price = (I_PRICE >= GEN_6) ? 60000 : 0,
        .description = COMPOUND_STRING(
            "A gold coin used\n"
            "long ago. It sells\n"
            "at a high price."),
        .descricao = COMPOUND_STRING(
            "Uma moeda ouro\n"
            "usada há tempo. É\n"
            "vendido por"),
        .descricion = COMPOUND_STRING(
            "Una moneda oro\n"
            "utilizada hace\n"
            "mucho tiempo. Se."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_RELIC,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_RelicCoin,
        .iconPalette = gItemIconPalette_RelicGold,
    },

    [ITEM_RELIC_VASE] =
    {
        .name = ITEM_NAME("Relic Vase"),
        .nombre = ITEM_NAME("Jarron reliquia"),
        .price = 0,
        .description = COMPOUND_STRING(
            "A vase made long\n"
            "ago. It sells at a\n"
            "high price."),
        .descricao = COMPOUND_STRING(
            "Um vaso feito há\n"
            "tempo. É vendido\n"
            "por preço"),
        .descricion = COMPOUND_STRING(
            "Un jarrón hecho\n"
            "hace mucho tiempo.\n"
            "Se vende un precio."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_RELIC,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_RelicVase,
        .iconPalette = gItemIconPalette_Relics,
    },

    [ITEM_RELIC_BAND] =
    {
        .name = ITEM_NAME("Relic Band"),
        .nombre = ITEM_NAME("Banda de reliquia"),
        .price = 0,
        .description = COMPOUND_STRING(
            "An old bracelet. It\n"
            "sells at a high\n"
            "price."),
        .descricao = COMPOUND_STRING(
            "Uma pulseira\n"
            "antiga. É vendido\n"
            "por um preço alto."),
        .descricion = COMPOUND_STRING(
            "Una pulsera vieja.\n"
            "Se vende a un\n"
            "precio elevado."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_RELIC,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_RelicBand,
        .iconPalette = gItemIconPalette_Relics,
    },

    [ITEM_RELIC_STATUE] =
    {
        .name = ITEM_NAME("Relic Statue"),
        .nombre = ITEM_NAME("Estatua de reliquia"),
        .price = 0,
        .description = COMPOUND_STRING(
            "An old statue. It\n"
            "sells at a high\n"
            "price."),
        .descricao = COMPOUND_STRING(
            "Uma estátua antiga.\n"
            "É vendido por um\n"
            "preço alto."),
        .descricion = COMPOUND_STRING(
            "Una vieja estatua.\n"
            "Se vende a un\n"
            "precio elevado."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_RELIC,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_RelicStatue,
        .iconPalette = gItemIconPalette_Relics,
    },

    [ITEM_RELIC_CROWN] =
    {
        .name = ITEM_NAME("Relic Crown"),
        .nombre = ITEM_NAME("Corona de reliquia"),
        .price = 0,
        .description = COMPOUND_STRING(
            "An old crown. It\n"
            "sells at a high\n"
            "price."),
        .descricao = COMPOUND_STRING(
            "Uma coroa antiga. É\n"
            "vendido por um\n"
            "preço alto."),
        .descricion = COMPOUND_STRING(
            "Una vieja corona.\n"
            "Se vende a un\n"
            "precio elevado."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_RELIC,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_RelicCrown,
        .iconPalette = gItemIconPalette_Relics,
    },

    [ITEM_STRANGE_SOUVENIR] =
    {
        .name = ITEM_NAME("Strange Souvenir"),
        .nombre = ITEM_NAME("Recuerdo extrano"),
        .price = (I_PRICE >= GEN_7) ? 3000 : 10,
        .description = COMPOUND_STRING(
            "An ornament that\n"
            "depicts a Pokémon\n"
            "from Alola."),
        .descricao = COMPOUND_STRING(
            "Um ornamento que\n"
            "representa um\n"
            "Pokémon de Alola."),
        .descricion = COMPOUND_STRING(
            "Un adorno que\n"
            "representa un\n"
            "Pokémon de Alola."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_RELIC,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_StrangeSouvenir,
        .iconPalette = gItemIconPalette_StrangeSouvenir,
    },

// Fossils

    [ITEM_HELIX_FOSSIL] =
    {
        .name = ITEM_NAME("Helix Fossil"),
        .nombre = ITEM_NAME("Fosil de helice"),
        .description = COMPOUND_STRING(
            "A piece of an\n"
            "ancient marine\n"
            "Pokémon's seashell."),
        .descricao = COMPOUND_STRING(
            "Um pedaço da concha\n"
            "de um antigo\n"
            "Pokémon marinho."),
        .descricion = COMPOUND_STRING(
            "Un trozo de concha\n"
            "de un antiguo\n"
            "Pokémon marino."),
    #if I_KEY_FOSSILS >= GEN_4
        .price = (I_PRICE >= GEN_7) ? 7000: 1000,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FOSSIL,
    #else
        .price = 0,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
    #endif
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
        .iconPic = gItemIcon_HelixFossil,
        .iconPalette = gItemIconPalette_KantoFossil,
    },

    [ITEM_DOME_FOSSIL] =
    {
        .name = ITEM_NAME("Dome Fossil"),
        .nombre = ITEM_NAME("Fosil de cupula"),
        .description = COMPOUND_STRING(
            "A piece of an\n"
            "ancient marine\n"
            "Pokémon's shell."),
        .descricao = COMPOUND_STRING(
            "Um pedaço da concha\n"
            "de um antigo\n"
            "Pokémon marinho."),
        .descricion = COMPOUND_STRING(
            "Un trozo del\n"
            "caparazón de un\n"
            "antiguo Pokémon."),
    #if I_KEY_FOSSILS >= GEN_4
        .price = (I_PRICE >= GEN_7) ? 7000: 1000,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FOSSIL,
    #else
        .price = 0,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
    #endif
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
        .iconPic = gItemIcon_DomeFossil,
        .iconPalette = gItemIconPalette_KantoFossil,
    },

    [ITEM_OLD_AMBER] =
    {
        .name = ITEM_NAME("Old Amber"),
        .nombre = ITEM_NAME("Ambar viejo"),
        .description = COMPOUND_STRING(
            "A stone containing\n"
            "the genes of an\n"
            "ancient Pokémon."),
        .descricao = COMPOUND_STRING(
            "Uma pedra contendo\n"
            "os genes de um\n"
            "Pokémon antigo."),
        .descricion = COMPOUND_STRING(
            "Una piedra que\n"
            "contiene los genes\n"
            "de un Pokémon."),
    #if I_KEY_FOSSILS >= GEN_4
        .price = 1000,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FOSSIL,
    #else
        .price = 0,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
    #endif
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
        .iconPic = gItemIcon_OldAmber,
        .iconPalette = gItemIconPalette_OldAmber,
    },

    [ITEM_ROOT_FOSSIL] =
    {
        .name = ITEM_NAME("Root Fossil"),
        .nombre = ITEM_NAME("Fosil de raiz"),
        .description = sRootFossilDesc,
        .descricao = COMPOUND_STRING(
            "Um fóssil de um\n"
            "antigo Pokémon que\n"
            "vive no fundo do."),
        .descricion = COMPOUND_STRING(
            "Un fósil un Pokémon\n"
            "antiguo habitaba en\n"
            "el fondo"),
    #if I_KEY_FOSSILS >= GEN_4
        .price = (I_PRICE >= GEN_7) ? 7000: 1000,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FOSSIL,
    #else
        .price = 0,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
    #endif
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
        .iconPic = gItemIcon_RootFossil,
        .iconPalette = gItemIconPalette_HoennFossil,
    },

    [ITEM_CLAW_FOSSIL] =
    {
        .name = ITEM_NAME("Claw Fossil"),
        .nombre = ITEM_NAME("Fosil de garra"),
        .description = sRootFossilDesc,
        .descricao = COMPOUND_STRING(
            "Um fóssil de um\n"
            "antigo Pokémon que\n"
            "vive no fundo do."),
        .descricion = COMPOUND_STRING(
            "Un fósil un Pokémon\n"
            "antiguo habitaba en\n"
            "el fondo"),
    #if I_KEY_FOSSILS >= GEN_4
        .price = (I_PRICE >= GEN_7) ? 7000: 1000,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FOSSIL,
    #else
        .price = 0,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
    #endif
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
        .iconPic = gItemIcon_ClawFossil,
        .iconPalette = gItemIconPalette_HoennFossil,
    },

    [ITEM_ARMOR_FOSSIL] =
    {
        .name = ITEM_NAME("Armor Fossil"),
        .nombre = ITEM_NAME("Armadura fosil"),
        .price = (I_PRICE >= GEN_7) ? 7000: 1000,
        .description = COMPOUND_STRING(
            "A piece of a\n"
            "prehistoric Poké-\n"
            "mon's head."),
        .descricao = COMPOUND_STRING(
            "Um pedaço da cabeça\n"
            "de um Pokémon\n"
            "pré-histórico."),
        .descricion = COMPOUND_STRING(
            "Un trozo de cabeza\n"
            "de un Pokémon\n"
            "prehistórico."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FOSSIL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
        .iconPic = gItemIcon_ArmorFossil,
        .iconPalette = gItemIconPalette_ArmorFossil,
    },

    [ITEM_SKULL_FOSSIL] =
    {
        .name = ITEM_NAME("Skull Fossil"),
        .nombre = ITEM_NAME("Craneo fosil"),
        .price = (I_PRICE >= GEN_7) ? 7000: 1000,
        .description = COMPOUND_STRING(
            "A piece of a\n"
            "prehistoric Poké-\n"
            "mon's collar."),
        .descricao = COMPOUND_STRING(
            "Um pedaço coleira\n"
            "Pokémon\n"
            "pré-histórico."),
        .descricion = COMPOUND_STRING(
            "Un trozo del collar\n"
            "de un Pokémon\n"
            "prehistórico."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FOSSIL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
        .iconPic = gItemIcon_SkullFossil,
        .iconPalette = gItemIconPalette_SkullFossil,
    },

    [ITEM_COVER_FOSSIL] =
    {
        .name = ITEM_NAME("Cover Fossil"),
        .nombre = ITEM_NAME("Cubrir Fosil"),
        .price = (I_PRICE >= GEN_7) ? 7000: 1000,
        .description = COMPOUND_STRING(
            "A piece of a\n"
            "prehistoric Poké-\n"
            "mon's back."),
        .descricao = COMPOUND_STRING(
            "Um pedaço costas\n"
            "Pokémon\n"
            "pré-histórico."),
        .descricion = COMPOUND_STRING(
            "Un trozo de la\n"
            "espalda de un\n"
            "Pokémon."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FOSSIL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
        .iconPic = gItemIcon_CoverFossil,
        .iconPalette = gItemIconPalette_CoverFossil,
    },

    [ITEM_PLUME_FOSSIL] =
    {
        .name = ITEM_NAME("Plume Fossil"),
        .nombre = ITEM_NAME("Fosil de penacho"),
        .price = (I_PRICE >= GEN_7) ? 7000: 1000,
        .description = COMPOUND_STRING(
            "A piece of a\n"
            "prehistoric Poké-\n"
            "mon's wing."),
        .descricao = COMPOUND_STRING(
            "Um pedaço da asa de\n"
            "um Pokémon\n"
            "pré-histórico."),
        .descricion = COMPOUND_STRING(
            "Un trozo del ala de\n"
            "un Pokémon\n"
            "prehistórico."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FOSSIL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
        .iconPic = gItemIcon_PlumeFossil,
        .iconPalette = gItemIconPalette_PlumeFossil,
    },

    [ITEM_JAW_FOSSIL] =
    {
        .name = ITEM_NAME("Jaw Fossil"),
        .nombre = ITEM_NAME("Fosil de mandibula"),
        .price = (I_PRICE >= GEN_7) ? 7000: 1000,
        .description = COMPOUND_STRING(
            "A piece of a\n"
            "prehistoric Poké-\n"
            "mon's large jaw."),
        .descricao = COMPOUND_STRING(
            "Um pedaço da grande\n"
            "mandíbula de um\n"
            "Pokémon."),
        .descricion = COMPOUND_STRING(
            "Un trozo de la gran\n"
            "mandíbula de un\n"
            "Pokémon."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FOSSIL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
        .iconPic = gItemIcon_JawFossil,
        .iconPalette = gItemIconPalette_JawFossil,
    },

    [ITEM_SAIL_FOSSIL] =
    {
        .name = ITEM_NAME("Sail Fossil"),
        .nombre = ITEM_NAME("Fosil de vela"),
        .price = (I_PRICE >= GEN_7) ? 7000: 1000,
        .description = COMPOUND_STRING(
            "A piece of a\n"
            "prehistoric Poké-\n"
            "mon's skin sail."),
        .descricao = COMPOUND_STRING(
            "Um pedaço vela pele\n"
            "Pokémon\n"
            "pré-histórico."),
        .descricion = COMPOUND_STRING(
            "Un trozo de vela de\n"
            "piel de un Pokémon\n"
            "prehistórico."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FOSSIL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
        .iconPic = gItemIcon_SailFossil,
        .iconPalette = gItemIconPalette_SailFossil,
    },

    [ITEM_FOSSILIZED_BIRD] =
    {
        .name = ITEM_NAME("Fossilized Bird"),
        .nombre = ITEM_NAME("Pajaro fosilizado"),
        .price = 5000,
        .description = COMPOUND_STRING(
            "A fossil of an\n"
            "ancient, sky-\n"
            "soaring Pokémon."),
        .descricao = COMPOUND_STRING(
            "Um fóssil de um\n"
            "antigo Pokémon que\n"
            "voava pelos céus."),
        .descricion = COMPOUND_STRING(
            "Un fósil de un\n"
            "Pokémon antiguo que\n"
            "se eleva por los."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FOSSIL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
        .iconPic = gItemIcon_FossilizedBird,
        .iconPalette = gItemIconPalette_FossilizedBird,
    },

    [ITEM_FOSSILIZED_FISH] =
    {
        .name = ITEM_NAME("Fossilized Fish"),
        .nombre = ITEM_NAME("Peces fosilizados"),
        .pluralName = ITEM_PLURAL_NAME("Fossilized Fish"),
        .price = 5000,
        .description = sFossilizedFishDesc,
        .descricao = COMPOUND_STRING(
            "Um fóssil de um\n"
            "antigo Pokémon que\n"
            "vivia no mar."),
        .descricion = COMPOUND_STRING(
            "Un fósil de un\n"
            "Pokémon antiguo que\n"
            "habitaba en el mar."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FOSSIL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
        .iconPic = gItemIcon_FossilizedFish,
        .iconPalette = gItemIconPalette_FossilizedFish,
    },

    [ITEM_FOSSILIZED_DRAKE] =
    {
        .name = ITEM_NAME("Fossilized Drake"),
        .nombre = ITEM_NAME("Draco fosilizado"),
        .price = 5000,
        .description = COMPOUND_STRING(
            "A fossil of an\n"
            "ancient, land-\n"
            "roaming Pokémon."),
        .descricao = COMPOUND_STRING(
            "Um fóssil de um\n"
            "antigo Pokémon que\n"
            "vagueia pela terra."),
        .descricion = COMPOUND_STRING(
            "Un fósil de un\n"
            "antiguo Pokémon\n"
            "terrestre."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FOSSIL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
        .iconPic = gItemIcon_FossilizedDrake,
        .iconPalette = gItemIconPalette_FossilizedDrake,
    },

    [ITEM_FOSSILIZED_DINO] =
    {
        .name = ITEM_NAME("Fossilized Dino"),
        .nombre = ITEM_NAME("Fossilized Dino"),
        .price = 5000,
        .description = sFossilizedFishDesc,
        .descricao = COMPOUND_STRING(
            "Um fóssil de um\n"
            "antigo Pokémon que\n"
            "vivia no mar."),
        .descricion = COMPOUND_STRING(
            "Un fósil de un\n"
            "Pokémon antiguo que\n"
            "habitaba en el mar."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FOSSIL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
        .iconPic = gItemIcon_FossilizedDino,
        .iconPalette = gItemIconPalette_FossilizedDino,
    },

// Mulch

    [ITEM_GROWTH_MULCH] =
    {
        .name = ITEM_NAME("Growth Mulch"),
        .nombre = ITEM_NAME("Growth Mulch"),
        .pluralName = ITEM_PLURAL_NAME("Growth Mulch"),
        .price = 200,
    #if OW_BERRY_MULCH_USAGE == TRUE
        .description = COMPOUND_STRING(
            "A fertilizer that\n"
            "accelerates the\n"
            "growth of Berries."),
    #else
        .description = sGenericMulchDesc,
    #endif

        .descricao = COMPOUND_STRING(
            "Um fertilizante que\n"
            "acelera o\n"
            "crescimento das."),
        .descricion = COMPOUND_STRING(
            "Un fertilizante que\n"
            "acelera el\n"
            "crecimiento de las."),        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GROWTH,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = ITEM_TO_MULCH(ITEM_GROWTH_MULCH),
        .flingPower = 30,
        .iconPic = gItemIcon_Mulch,
        .iconPalette = gItemIconPalette_GrowthMulch,
    },

    [ITEM_DAMP_MULCH] =
    {
        .name = ITEM_NAME("Damp Mulch"),
        .nombre = ITEM_NAME("mant. humedo"),
        .pluralName = ITEM_PLURAL_NAME("Damp Mulch"),
        .price = 200,
    #if OW_BERRY_MULCH_USAGE == TRUE
        .description = COMPOUND_STRING(
            "A fertilizer that\n"
            "decelerates the\n"
            "growth of Berries."),
    #else
        .description = sGenericMulchDesc,
    #endif

        .descricao = COMPOUND_STRING(
            "Um fertilizante que\n"
            "desacelera o\n"
            "crescimento das."),
        .descricion = COMPOUND_STRING(
            "Un fertilizante que\n"
            "desacelera el\n"
            "crecimiento de las."),        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GROWTH,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = ITEM_TO_MULCH(ITEM_DAMP_MULCH),
        .flingPower = 30,
        .iconPic = gItemIcon_Mulch,
        .iconPalette = gItemIconPalette_DampMulch,
    },

    [ITEM_STABLE_MULCH] =
    {
        .name = ITEM_NAME("Stable Mulch"),
        .nombre = ITEM_NAME("Mantillo estable"),
        .pluralName = ITEM_PLURAL_NAME("Stable Mulch"),
        .price = 200,
    #if OW_BERRY_MULCH_USAGE == TRUE
        .description = COMPOUND_STRING(
            "A fertilizer that\n"
            "ups the life time\n"
            "of Berry trees."),
    #else
        .description = sGenericMulchDesc,
    #endif

        .descricao = COMPOUND_STRING(
            "Um fertilizante que\n"
            "sobe a vida útil\n"
            "das árvores Berry."),
        .descricion = COMPOUND_STRING(
            "Un fertilizante que\n"
            "sobe la vida útil\n"
            "de los árboles de."),        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GROWTH,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = ITEM_TO_MULCH(ITEM_STABLE_MULCH),
        .flingPower = 30,
        .iconPic = gItemIcon_StableMulch,
        .iconPalette = gItemIconPalette_StableMulch,
    },

    [ITEM_GOOEY_MULCH] =
    {
        .name = ITEM_NAME("Gooey Mulch"),
        .nombre = ITEM_NAME("mant. pegajoso"),
        .pluralName = ITEM_PLURAL_NAME("Gooey Mulch"),
        .price = 200,
    #if OW_BERRY_MULCH_USAGE == TRUE
        .description = COMPOUND_STRING(
            "A fertilizer that\n"
            "makes more Berries\n"
            "regrow after fall."),
    #else
        .description = sGenericMulchDesc,
    #endif

        .descricao = COMPOUND_STRING(
            "Um fertilizante que\n"
            "faz com que mais\n"
            "frutas voltem a."),
        .descricion = COMPOUND_STRING(
            "Un fertilizante que\n"
            "hace que más bayas\n"
            "vuelvan a crecer."),        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GROWTH,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = ITEM_TO_MULCH(ITEM_GOOEY_MULCH),
        .flingPower = 30,
        .iconPic = gItemIcon_Mulch,
        .iconPalette = gItemIconPalette_GooeyMulch,
    },

    [ITEM_RICH_MULCH] =
    {
        .name = ITEM_NAME("Rich Mulch"),
        .nombre = ITEM_NAME("Mantillo rico"),
        .pluralName = ITEM_PLURAL_NAME("Rich Mulch"),
        .price = 200,
    #if OW_BERRY_MULCH_USAGE == TRUE
        .description = COMPOUND_STRING(
            "A fertilizer that\n"
            "ups the number of\n"
            "Berries harvested."),
    #else
        .description = sGenericMulchDesc,
    #endif

        .descricao = COMPOUND_STRING(
            "Um fertilizante que\n"
            "sobe o número de\n"
            "frutas colhidas."),
        .descricion = COMPOUND_STRING(
            "Un fertilizante que\n"
            "sobe el número de\n"
            "Bayas recolectadas."),        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GROWTH,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = ITEM_TO_MULCH(ITEM_RICH_MULCH),
        .flingPower = 30,
        .iconPic = gItemIcon_Mulch,
        .iconPalette = gItemIconPalette_RichMulch,
    },

    [ITEM_SURPRISE_MULCH] =
    {
        .name = ITEM_NAME("Surprise Mulch"),
        .nombre = ITEM_NAME("Mantillo sorpresa"),
        .pluralName = ITEM_PLURAL_NAME("Surprise Mulch"),
        .price = 200,
    #if OW_BERRY_MULCH_USAGE == TRUE
        .description = COMPOUND_STRING(
            "A fertilizer that\n"
            "ups the chance of\n"
            "Berry mutations."),
    #else
        .description = sGenericMulchDesc,
    #endif

        .descricao = COMPOUND_STRING(
            "Um fertilizante que\n"
            "sobe a chance de\n"
            "mutações em Berry."),
        .descricion = COMPOUND_STRING(
            "Un fertilizante\n"
            "sobe las\n"
            "posibilidades"),        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GROWTH,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = ITEM_TO_MULCH(ITEM_SURPRISE_MULCH),
        .flingPower = 30,
        .iconPic = gItemIcon_Mulch,
        .iconPalette = gItemIconPalette_SurpriseMulch,
    },

    [ITEM_BOOST_MULCH] =
    {
        .name = ITEM_NAME("Boost Mulch"),
        .nombre = ITEM_NAME("Imp. el mant."),
        .pluralName = ITEM_PLURAL_NAME("Boost Mulch"),
        .price = 200,
    #if OW_BERRY_MULCH_USAGE == TRUE
        .description = COMPOUND_STRING(
            "A fertilizer that\n"
            "ups the dry speed\n"
            "of soft soil."),
    #else
        .description = sGenericMulchDesc,
    #endif

        .descricao = COMPOUND_STRING(
            "Um fertilizante que\n"
            "sobe a Vel. de\n"
            "secagem do solo."),
        .descricion = COMPOUND_STRING(
            "Un fertilizante\n"
            "sobe la Vel. secado\n"
            "los suelos"),        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GROWTH,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = ITEM_TO_MULCH(ITEM_BOOST_MULCH),
        .flingPower = 30,
        .iconPic = gItemIcon_Mulch,
        .iconPalette = gItemIconPalette_BoostMulch,
    },

    [ITEM_AMAZE_MULCH] =
    {
        .name = ITEM_NAME("Amaze Mulch"),
        .nombre = ITEM_NAME("Sorprender mant."),
        .pluralName = ITEM_PLURAL_NAME("Amaze Mulch"),
        .price = 200,
    #if OW_BERRY_MULCH_USAGE == TRUE
        .description = COMPOUND_STRING(
            "A fertilizer Rich\n"
            "Surprising and\n"
            "Boosting as well."),
    #else
        .description = sGenericMulchDesc,
    #endif

        .descricao = COMPOUND_STRING(
            "Um fertilizante\n"
            "rico, surpreendente\n"
            "e estimulante."),
        .descricion = COMPOUND_STRING(
            "Un abono rico que\n"
            "sorprende y\n"
            "potencia a la vez."),        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GROWTH,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = ITEM_TO_MULCH(ITEM_AMAZE_MULCH),
        .flingPower = 30,
        .iconPic = gItemIcon_Mulch,
        .iconPalette = gItemIconPalette_AmazeMulch,
    },

// Apricorns
    #if (I_PRICE >= GEN_8 || I_PRICE <= GEN_2)
        #define APRICORN_PRICE 200
    #elif I_PRICE >= GEN_5
        #define APRICORN_PRICE 20
    #else
        #define APRICORN_PRICE 0
    #endif

    [ITEM_RED_APRICORN] =
    {
        .name = ITEM_NAME("Red Apricorn"),
        .nombre = ITEM_NAME("Albaricornio rojo"),
        .price = APRICORN_PRICE,
        .description = COMPOUND_STRING(
            "A red apricorn. It\n"
            "assails your\n"
            "nostrils."),
        .descricao = COMPOUND_STRING(
            "Um damasco\n"
            "vermelho. Isso\n"
            "ataca suas narinas."),
        .descricion = COMPOUND_STRING(
            "Un albaricoque\n"
            "rojo. Asalta tus\n"
            "fosas nasales."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GROWTH,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_Apricorn,
        .iconPalette = gItemIconPalette_RedApricorn,
    },

    [ITEM_BLUE_APRICORN] =
    {
        .name = ITEM_NAME("Blue Apricorn"),
        .nombre = ITEM_NAME("Albaricornio azul"),
        .price = APRICORN_PRICE,
        .description = COMPOUND_STRING(
            "A blue apricorn. It\n"
            "smells a bit like\n"
            "grass."),
        .descricao = COMPOUND_STRING(
            "Um damasco azul.\n"
            "Cheira pouco a\n"
            "grama."),
        .descricion = COMPOUND_STRING(
            "Un albaricoque\n"
            "azul. Huele un poco\n"
            "a hierba."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GROWTH,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_Apricorn,
        .iconPalette = gItemIconPalette_BlueApricorn,
    },

    [ITEM_YELLOW_APRICORN] =
    {
        .name = ITEM_NAME("Yellow Apricorn"),
        .nombre = ITEM_NAME("Yellow Apricorn"),
        .price = APRICORN_PRICE,
        .description = COMPOUND_STRING(
            "A yellow apricorn.\n"
            "It has an invigor-\n"
            "ating scent."),
        .descricao = COMPOUND_STRING(
            "Um damasco amarelo.\n"
            "Tem um aroma\n"
            "revigorante."),
        .descricion = COMPOUND_STRING(
            "Un albaricoque\n"
            "amarillo. Tiene un\n"
            "aroma vigorizante."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GROWTH,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_Apricorn,
        .iconPalette = gItemIconPalette_YellowApricorn,
    },

    [ITEM_GREEN_APRICORN] =
    {
        .name = ITEM_NAME("Green Apricorn"),
        .nombre = ITEM_NAME("Albaricornio verde"),
        .price = APRICORN_PRICE,
        .description = COMPOUND_STRING(
            "A green apricorn.\n"
            "It has a strange,\n"
            "aromatic scent."),
        .descricao = COMPOUND_STRING(
            "Um damasco verde.\n"
            "Tem um cheiro\n"
            "estranho e."),
        .descricion = COMPOUND_STRING(
            "Un albaricoque\n"
            "verde. Tiene un\n"
            "olor extraño y."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GROWTH,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_Apricorn,
        .iconPalette = gItemIconPalette_GreenApricorn,
    },

    [ITEM_PINK_APRICORN] =
    {
        .name = ITEM_NAME("Pink Apricorn"),
        .nombre = ITEM_NAME("Albaricornio rosado"),
        .price = APRICORN_PRICE,
        .description = COMPOUND_STRING(
            "A pink apricorn. It\n"
            "has a nice, sweet\n"
            "scent."),
        .descricao = COMPOUND_STRING(
            "Um damasco rosa.\n"
            "Tem um aroma\n"
            "agradável e doce."),
        .descricion = COMPOUND_STRING(
            "Un albaricoque\n"
            "rosado. Tiene un\n"
            "aroma agradable y."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GROWTH,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_Apricorn,
        .iconPalette = gItemIconPalette_PinkApricorn,
    },

    [ITEM_WHITE_APRICORN] =
    {
        .name = ITEM_NAME("White Apricorn"),
        .nombre = ITEM_NAME("Albaricornio blanco"),
        .price = APRICORN_PRICE,
        .description = COMPOUND_STRING(
            "A white apricorn.\n"
            "It doesn't smell\n"
            "like anything."),
        .descricao = COMPOUND_STRING(
            "Um damasco branco.\n"
            "Não cheira a nada."),
        .descricion = COMPOUND_STRING(
            "Un albaricoque\n"
            "blanco. No huele a\n"
            "nada."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GROWTH,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_Apricorn,
        .iconPalette = gItemIconPalette_WhiteApricorn,
    },

    [ITEM_BLACK_APRICORN] =
    {
        .name = ITEM_NAME("Black Apricorn"),
        .nombre = ITEM_NAME("Albaricornio negro"),
        .price = APRICORN_PRICE,
        .description = COMPOUND_STRING(
            "A black apricorn.\n"
            "It has an inde-\n"
            "scribable scent."),
        .descricao = COMPOUND_STRING(
            "Um damasco preto.\n"
            "Tem um aroma\n"
            "indescritível."),
        .descricion = COMPOUND_STRING(
            "Un albaricoque\n"
            "negro. Tiene un\n"
            "olor."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GROWTH,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_Apricorn,
        .iconPalette = gItemIconPalette_BlackApricorn,
    },

    [ITEM_WISHING_PIECE] =
    {
        .name = ITEM_NAME("Wishing Piece"),
        .nombre = ITEM_NAME("Pieza de deseos"),
        .price = 20,
        .description = COMPOUND_STRING(
            "Throw into a {PKMN} Den\n"
            "to attract Dynamax\n"
            "Pokémon."),
        .descricao = COMPOUND_STRING(
            "Jogue em um Den\n"
            "Pokémon para atrair\n"
            "Pokémon Dynamax."),
        .descricion = COMPOUND_STRING(
            "Llévalo una guarida\n"
            "Pokémon para atraer\n"
            "Pokémon."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SELLABLE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse, // Todo
        .flingPower = 50,
        .iconPic = gItemIcon_WishingPiece,
        .iconPalette = gItemIconPalette_WishingPiece,
    },

    [ITEM_GALARICA_TWIG] =
    {
        .name = ITEM_NAME("Galarica Twig"),
        .nombre = ITEM_NAME("Ramita de Galarica"),
        .price = 20 * TREASURE_FACTOR,
        .description = COMPOUND_STRING(
            "A twig from a tree\n"
            "in Galar called\n"
            "Galarica."),
        .descricao = COMPOUND_STRING(
            "Um galho de uma\n"
            "árvore em Galar\n"
            "chamada Galarica."),
        .descricion = COMPOUND_STRING(
            "Una ramita de un\n"
            "árbol de Galar\n"
            "llamado Galarica."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_GalaricaTwig,
        .iconPalette = gItemIconPalette_GalaricaItem,
    },

    [ITEM_ARMORITE_ORE] =
    {
        .name = ITEM_NAME("Armorite Ore"),
        .nombre = ITEM_NAME("Mineral de armorita"),
        .pluralName = ITEM_PLURAL_NAME("Armorite Ore"),
        .price = 20,
        .description = COMPOUND_STRING(
            "A rare ore. Can be\n"
            "found in the Isle\n"
            "of Armor at Galar."),
        .descricao = COMPOUND_STRING(
            "Um minério raro.\n"
            "Pode ser encontrado\n"
            "na Ilha Armadura."),
        .descricion = COMPOUND_STRING(
            "Un mineral raro. Se\n"
            "puede encontrar en\n"
            "la Isla de la."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_ArmoriteOre,
        .iconPalette = gItemIconPalette_ArmoriteOre,
    },

    [ITEM_DYNITE_ORE] =
    {
        .name = ITEM_NAME("Dynite Ore"),
        .nombre = ITEM_NAME("Mineral de dinata"),
        .pluralName = ITEM_PLURAL_NAME("Dynite Ore"),
        .price = 20,
        .description = COMPOUND_STRING(
            "A mysterious ore.\n"
            "It can be found in\n"
            "Galar's Max Lair."),
        .descricao = COMPOUND_STRING(
            "Um minério\n"
            "misterioso. Ele\n"
            "pode ser encontrad."),
        .descricion = COMPOUND_STRING(
            "Un mineral\n"
            "misterioso. Se\n"
            "puede encontrar en."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_DyniteOre,
        .iconPalette = gItemIconPalette_DyniteOre,
    },

// Mail

    [ITEM_ORANGE_MAIL] =
    {
        .name = ITEM_NAME("Orange Mail"),
        .nombre = ITEM_NAME("Correo naranja"),
        .pluralName = ITEM_PLURAL_NAME("Orange Mail"),
        .price = 50,
        .description = COMPOUND_STRING(
            "A Zigzagoon-print\n"
            "Mail to be held by\n"
            "a Pokémon."),
        .descricao = COMPOUND_STRING(
            "Uma correspondência\n"
            "com impressão\n"
            "Zigzagoon para ser."),
        .descricion = COMPOUND_STRING(
            "Un correo con\n"
            "estampado de\n"
            "Zigzagoon para ser."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MAIL,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_ORANGE_MAIL),
        .iconPic = gItemIcon_OrangeMail,
        .iconPalette = gItemIconPalette_OrangeMail,
    },

    [ITEM_HARBOR_MAIL] =
    {
        .name = ITEM_NAME("Harbor Mail"),
        .nombre = ITEM_NAME("Correo del puerto"),
        .pluralName = ITEM_PLURAL_NAME("Harbor Mail"),
        .price = 50,
        .description = COMPOUND_STRING(
            "A Wingull-print\n"
            "Mail to be held by\n"
            "a Pokémon."),
        .descricao = COMPOUND_STRING(
            "Uma correspondência\n"
            "com impressão de\n"
            "Wingull para ser."),
        .descricion = COMPOUND_STRING(
            "Un correo con\n"
            "impresión Wingull\n"
            "llevará un."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MAIL,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_HARBOR_MAIL),
        .iconPic = gItemIcon_HarborMail,
        .iconPalette = gItemIconPalette_HarborMail,
    },

    [ITEM_GLITTER_MAIL] =
    {
        .name = ITEM_NAME("Glitter Mail"),
        .nombre = ITEM_NAME("Correo brillante"),
        .pluralName = ITEM_PLURAL_NAME("Glitter Mail"),
        .price = 50,
        .description = COMPOUND_STRING(
            "A Pikachu-print\n"
            "Mail to be held by\n"
            "a Pokémon."),
        .descricao = COMPOUND_STRING(
            "Uma correspondência\n"
            "com impressão do\n"
            "Pikachu para ser."),
        .descricion = COMPOUND_STRING(
            "Un correo con\n"
            "estampado Pikachu\n"
            "llevará un."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MAIL,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_GLITTER_MAIL),
        .iconPic = gItemIcon_GlitterMail,
        .iconPalette = gItemIconPalette_GlitterMail,
    },

    [ITEM_MECH_MAIL] =
    {
        .name = ITEM_NAME("Mech Mail"),
        .nombre = ITEM_NAME("Correo mecanico"),
        .pluralName = ITEM_PLURAL_NAME("Mech Mail"),
        .price = 50,
        .description = COMPOUND_STRING(
            "A Magnemite-print\n"
            "Mail to be held by\n"
            "a Pokémon."),
        .descricao = COMPOUND_STRING(
            "Uma correspondência\n"
            "com impressão de\n"
            "Magnemite para ser."),
        .descricion = COMPOUND_STRING(
            "Un correo con\n"
            "impresión de\n"
            "Magnemite que."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MAIL,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_MECH_MAIL),
        .iconPic = gItemIcon_MechMail,
        .iconPalette = gItemIconPalette_MechMail,
    },

    [ITEM_WOOD_MAIL] =
    {
        .name = ITEM_NAME("Wood Mail"),
        .nombre = ITEM_NAME("Correo de madera"),
        .pluralName = ITEM_PLURAL_NAME("Wood Mail"),
        .price = 50,
        .description = COMPOUND_STRING(
            "A Slakoth-print\n"
            "Mail to be held by\n"
            "a Pokémon."),
        .descricao = COMPOUND_STRING(
            "Uma correspondência\n"
            "com impressão\n"
            "Slakoth para ser."),
        .descricion = COMPOUND_STRING(
            "Un correo con\n"
            "impresión Slakoth\n"
            "llevará un."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MAIL,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_WOOD_MAIL),
        .iconPic = gItemIcon_WoodMail,
        .iconPalette = gItemIconPalette_WoodMail,
    },

    [ITEM_WAVE_MAIL] =
    {
        .name = ITEM_NAME("Wave Mail"),
        .nombre = ITEM_NAME("Correo de onda"),
        .pluralName = ITEM_PLURAL_NAME("Wave Mail"),
        .price = 50,
        .description = COMPOUND_STRING(
            "A Wailmer-print\n"
            "Mail to be held by\n"
            "a Pokémon."),
        .descricao = COMPOUND_STRING(
            "Uma correspondência\n"
            "com impressão de\n"
            "Wailmer para ser."),
        .descricion = COMPOUND_STRING(
            "Un correo con\n"
            "impresión Wailmer\n"
            "llevará un."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MAIL,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_WAVE_MAIL),
        .iconPic = gItemIcon_WaveMail,
        .iconPalette = gItemIconPalette_WaveMail,
    },

    [ITEM_BEAD_MAIL] =
    {
        .name = ITEM_NAME("Bead Mail"),
        .nombre = ITEM_NAME("Correo de cuentas"),
        .pluralName = ITEM_PLURAL_NAME("Bead Mail"),
        .price = 50,
        .description = sBeadMailDesc,
        .descricao = COMPOUND_STRING(
            "Correio\n"
            "apresentando esboço\n"
            "Pokémon segura."),
        .descricion = COMPOUND_STRING(
            "Correo con un\n"
            "boceto del Pokémon\n"
            "retenido."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MAIL,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_BEAD_MAIL),
        .iconPic = gItemIcon_BeadMail,
        .iconPalette = gItemIconPalette_BeadMail,
    },

    [ITEM_SHADOW_MAIL] =
    {
        .name = ITEM_NAME("Shadow Mail"),
        .nombre = ITEM_NAME("Correo en la sombra"),
        .pluralName = ITEM_PLURAL_NAME("Shadow Mail"),
        .price = 50,
        .description = COMPOUND_STRING(
            "A Duskull-print\n"
            "Mail to be held by\n"
            "a Pokémon."),
        .descricao = COMPOUND_STRING(
            "Uma correspondência\n"
            "com impressão\n"
            "Duskull para ser."),
        .descricion = COMPOUND_STRING(
            "Un correo con\n"
            "impresión Duskull\n"
            "llevará un."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MAIL,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_SHADOW_MAIL),
        .iconPic = gItemIcon_ShadowMail,
        .iconPalette = gItemIconPalette_ShadowMail,
    },

    [ITEM_TROPIC_MAIL] =
    {
        .name = ITEM_NAME("Tropic Mail"),
        .nombre = ITEM_NAME("Correo tropical"),
        .pluralName = ITEM_PLURAL_NAME("Tropic Mail"),
        .price = 50,
        .description = COMPOUND_STRING(
            "A Bellossom-print\n"
            "Mail to be held by\n"
            "a Pokémon."),
        .descricao = COMPOUND_STRING(
            "Uma correspondência\n"
            "com impressão\n"
            "Bellossom para ser."),
        .descricion = COMPOUND_STRING(
            "Un correo con\n"
            "impresión de\n"
            "Bellossom que."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MAIL,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_TROPIC_MAIL),
        .iconPic = gItemIcon_TropicMail,
        .iconPalette = gItemIconPalette_TropicMail,
    },

    [ITEM_DREAM_MAIL] =
    {
        .name = ITEM_NAME("Dream Mail"),
        .nombre = ITEM_NAME("Correo de ensueno"),
        .pluralName = ITEM_PLURAL_NAME("Dream Mail"),
        .price = 50,
        .description = sBeadMailDesc,
        .descricao = COMPOUND_STRING(
            "Correio\n"
            "apresentando esboço\n"
            "Pokémon segura."),
        .descricion = COMPOUND_STRING(
            "Correo con un\n"
            "boceto del Pokémon\n"
            "retenido."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MAIL,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_DREAM_MAIL),
        .iconPic = gItemIcon_DreamMail,
        .iconPalette = gItemIconPalette_DreamMail,
    },

    [ITEM_FAB_MAIL] =
    {
        .name = ITEM_NAME("Fab Mail"),
        .nombre = ITEM_NAME("correo fabuloso"),
        .pluralName = ITEM_PLURAL_NAME("Fab Mail"),
        .price = 50,
        .description = COMPOUND_STRING(
            "A gorgeous-print\n"
            "Mail to be held by\n"
            "a Pokémon."),
        .descricao = COMPOUND_STRING(
            "Uma correspondência\n"
            "com estampa linda\n"
            "para ser segurada."),
        .descricion = COMPOUND_STRING(
            "Un correo con una\n"
            "impresión preciosa\n"
            "para lo lleve un"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MAIL,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_FAB_MAIL),
        .iconPic = gItemIcon_FabMail,
        .iconPalette = gItemIconPalette_FabMail,
    },

    [ITEM_RETRO_MAIL] =
    {
        .name = ITEM_NAME("Retro Mail"),
        .nombre = ITEM_NAME("Correo retro"),
        .pluralName = ITEM_PLURAL_NAME("Retro Mail"),
        .price = 50,
        .description = COMPOUND_STRING(
            "Mail featuring the\n"
            "drawings of three\n"
            "Pokémon."),
        .descricao = COMPOUND_STRING(
            "Mail apresentando\n"
            "os desenhos de três\n"
            "Pokémon."),
        .descricion = COMPOUND_STRING(
            "Correo con los\n"
            "dibujos de tres\n"
            "Pokémon."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MAIL,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_RETRO_MAIL),
        .iconPic = gItemIcon_RetroMail,
        .iconPalette = gItemIconPalette_RetroMail,
    },

// Evolution Items

    [ITEM_FIRE_STONE] =
    {
        .name = ITEM_NAME("Fire Stone"),
        .nombre = ITEM_NAME("P. de fuego"),
        .price = (I_PRICE >= GEN_7) ? 3000 : 2100,
        .description = sEvolutionStoneDesc,
        .descricao = COMPOUND_STRING(
            "Faz certas espécies\n"
            "de Pokémon\n"
            "evoluírem."),
        .descricion = COMPOUND_STRING(
            "Hace que ciertas\n"
            "especies de Pokémon\n"
            "evolucionen."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_STONE,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
        .iconPic = gItemIcon_FireStone,
        .iconPalette = gItemIconPalette_FireStone,
    },

    [ITEM_WATER_STONE] =
    {
        .name = ITEM_NAME("Water Stone"),
        .nombre = ITEM_NAME("P. de agua"),
        .price = (I_PRICE >= GEN_7) ? 3000 : 2100,
        .description = sEvolutionStoneDesc,
        .descricao = COMPOUND_STRING(
            "Faz certas espécies\n"
            "de Pokémon\n"
            "evoluírem."),
        .descricion = COMPOUND_STRING(
            "Hace que ciertas\n"
            "especies de Pokémon\n"
            "evolucionen."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_STONE,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
        .iconPic = gItemIcon_WaterStone,
        .iconPalette = gItemIconPalette_WaterStone,
    },

    [ITEM_THUNDER_STONE] =
    {
        .name = ITEM_NAME("Thunder Stone"),
        .nombre = ITEM_NAME("P. del trueno"),
        .price = (I_PRICE >= GEN_7) ? 3000 : 2100,
        .description = sEvolutionStoneDesc,
        .descricao = COMPOUND_STRING(
            "Faz certas espécies\n"
            "de Pokémon\n"
            "evoluírem."),
        .descricion = COMPOUND_STRING(
            "Hace que ciertas\n"
            "especies de Pokémon\n"
            "evolucionen."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_STONE,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
        .iconPic = gItemIcon_ThunderStone,
        .iconPalette = gItemIconPalette_ThunderStone,
    },

    [ITEM_LEAF_STONE] =
    {
        .name = ITEM_NAME("Leaf Stone"),
        .nombre = ITEM_NAME("P. de hoja"),
        .price = (I_PRICE >= GEN_7) ? 3000 : 2100,
        .description = sEvolutionStoneDesc,
        .descricao = COMPOUND_STRING(
            "Faz certas espécies\n"
            "de Pokémon\n"
            "evoluírem."),
        .descricion = COMPOUND_STRING(
            "Hace que ciertas\n"
            "especies de Pokémon\n"
            "evolucionen."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_STONE,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
        .iconPic = gItemIcon_LeafStone,
        .iconPalette = gItemIconPalette_LeafStone,
    },

    [ITEM_ICE_STONE] =
    {
        .name = ITEM_NAME("Ice Stone"),
        .nombre = ITEM_NAME("P. de hielo"),
        .price = (I_PRICE >= GEN_7) ? 3000 : 2100,
        .description = sEvolutionStoneDesc,
        .descricao = COMPOUND_STRING(
            "Faz certas espécies\n"
            "de Pokémon\n"
            "evoluírem."),
        .descricion = COMPOUND_STRING(
            "Hace que ciertas\n"
            "especies de Pokémon\n"
            "evolucionen."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_STONE,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
        .iconPic = gItemIcon_IceStone,
        .iconPalette = gItemIconPalette_IceStone,
    },

    [ITEM_SUN_STONE] =
    {
        .name = ITEM_NAME("Sun Stone"),
        .nombre = ITEM_NAME("P. del Sol"),
        .price = (I_PRICE >= GEN_7) ? 3000 : 2100,
        .description = sEvolutionStoneDesc,
        .descricao = COMPOUND_STRING(
            "Faz certas espécies\n"
            "de Pokémon\n"
            "evoluírem."),
        .descricion = COMPOUND_STRING(
            "Hace que ciertas\n"
            "especies de Pokémon\n"
            "evolucionen."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_STONE,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
        .iconPic = gItemIcon_SunStone,
        .iconPalette = gItemIconPalette_SunStone,
    },

    [ITEM_MOON_STONE] =
    {
        .name = ITEM_NAME("Moon Stone"),
        .nombre = ITEM_NAME("P. Luna"),
    #if I_PRICE >= GEN_7
        .price = 3000,
    #elif I_PRICE >= GEN_4
        .price = 2100,
    #elif I_PRICE == GEN_3
        .price = 0,
    #else
        .price = 1,
    #endif
        .description = sEvolutionStoneDesc,
        .descricao = COMPOUND_STRING(
            "Faz certas espécies\n"
            "de Pokémon\n"
            "evoluírem."),
        .descricion = COMPOUND_STRING(
            "Hace que ciertas\n"
            "especies de Pokémon\n"
            "evolucionen."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_STONE,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
        .iconPic = gItemIcon_MoonStone,
        .iconPalette = gItemIconPalette_MoonStone,
    },

    [ITEM_SHINY_STONE] =
    {
        .name = ITEM_NAME("Shiny Stone"),
        .nombre = ITEM_NAME("P. brillante"),
        .price = (I_PRICE >= GEN_7) ? 3000 : 2100,
        .description = sEvolutionStoneDesc,
        .descricao = COMPOUND_STRING(
            "Faz certas espécies\n"
            "de Pokémon\n"
            "evoluírem."),
        .descricion = COMPOUND_STRING(
            "Hace que ciertas\n"
            "especies de Pokémon\n"
            "evolucionen."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_STONE,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
        .iconPic = gItemIcon_ShinyStone,
        .iconPalette = gItemIconPalette_ShinyStone,
    },

    [ITEM_DUSK_STONE] =
    {
        .name = ITEM_NAME("Dusk Stone"),
        .nombre = ITEM_NAME("P. del noche"),
        .price = (I_PRICE >= GEN_7) ? 3000 : 2100,
        .description = sEvolutionStoneDesc,
        .descricao = COMPOUND_STRING(
            "Faz certas espécies\n"
            "de Pokémon\n"
            "evoluírem."),
        .descricion = COMPOUND_STRING(
            "Hace que ciertas\n"
            "especies de Pokémon\n"
            "evolucionen."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_STONE,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 80,
        .iconPic = gItemIcon_DuskStone,
        .iconPalette = gItemIconPalette_DuskStone,
    },

    [ITEM_DAWN_STONE] =
    {
        .name = ITEM_NAME("Dawn Stone"),
        .nombre = ITEM_NAME("P. del amanecer"),
        .price = (I_PRICE >= GEN_7) ? 3000 : 2100,
        .description = sEvolutionStoneDesc,
        .descricao = COMPOUND_STRING(
            "Faz certas espécies\n"
            "de Pokémon\n"
            "evoluírem."),
        .descricion = COMPOUND_STRING(
            "Hace que ciertas\n"
            "especies de Pokémon\n"
            "evolucionen."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_STONE,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 80,
        .iconPic = gItemIcon_DawnStone,
        .iconPalette = gItemIconPalette_DawnStone,
    },

    [ITEM_SWEET_APPLE] =
    {
        .name = ITEM_NAME("Sweet Apple"),
        .nombre = ITEM_NAME("manzana dulce"),
        .price = 2200,
        .description = COMPOUND_STRING(
            "A very sweet apple\n"
            "that makes certain\n"
            "Pokémon evolve."),
        .descricao = COMPOUND_STRING(
            "Uma maçã muito doce\n"
            "que faz evolui\n"
            "certos Pokémon."),
        .descricion = COMPOUND_STRING(
            "Una manzana muy\n"
            "dulce que hace\n"
            "evolucionar a."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
        .iconPic = gItemIcon_SweetApple,
        .iconPalette = gItemIconPalette_SweetApple,
    },

    [ITEM_TART_APPLE] =
    {
        .name = ITEM_NAME("Tart Apple"),
        .nombre = ITEM_NAME("tarta de manzana"),
        .price = 2200,
        .description = COMPOUND_STRING(
            "A very tart apple\n"
            "that makes certain\n"
            "Pokémon evolve."),
        .descricao = COMPOUND_STRING(
            "Uma maçã azeda faz\n"
            "evolui certos\n"
            "Pokémon."),
        .descricion = COMPOUND_STRING(
            "Una manzana muy\n"
            "ácida que hace\n"
            "evolucionar a."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
        .iconPic = gItemIcon_TartApple,
        .iconPalette = gItemIconPalette_TartApple,
    },

    [ITEM_CRACKED_POT] =
    {
        .name = ITEM_NAME("Cracked Pot"),
        .nombre = ITEM_NAME("Olla rota"),
        .price = 1600,
        .description = COMPOUND_STRING(
            "A cracked teapot\n"
            "that makes certain\n"
            "Pokémon evolve."),
        .descricao = COMPOUND_STRING(
            "Um bule rachado que\n"
            "faz certos Pokémon\n"
            "evoluírem."),
        .descricion = COMPOUND_STRING(
            "Una tetera rota que\n"
            "hace evolucionar a\n"
            "ciertos Pokémon."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 80,
        .iconPic = gItemIcon_CrackedPot,
        .iconPalette = gItemIconPalette_Pot,
    },

    [ITEM_CHIPPED_POT] =
    {
        .name = ITEM_NAME("Chipped Pot"),
        .nombre = ITEM_NAME("Olla astillada"),
        .price = 38000,
        .description = COMPOUND_STRING(
            "A chipped teapot\n"
            "that makes certain\n"
            "Pokémon evolve."),
        .descricao = COMPOUND_STRING(
            "Um bule lascado que\n"
            "faz certos Pokémon\n"
            "evoluírem."),
        .descricion = COMPOUND_STRING(
            "Una tetera\n"
            "desportillada que\n"
            "hace evolucionar a."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 80,
        .iconPic = gItemIcon_ChippedPot,
        .iconPalette = gItemIconPalette_Pot,
    },

    [ITEM_GALARICA_CUFF] =
    {
        .name = ITEM_NAME("Galarica Cuff"),
        .nombre = ITEM_NAME("Brazalete Galarica"),
        .price = (I_PRICE >= GEN_9) ? 3000 : 6000,
        .description = COMPOUND_STRING(
            "A cuff from Galar\n"
            "that makes certain\n"
            "Pokémon evolve."),
        .descricao = COMPOUND_STRING(
            "Um manguito Galar\n"
            "faz certos Pokémon\n"
            "evoluírem."),
        .descricion = COMPOUND_STRING(
            "Un brazalete de\n"
            "Galar que hace\n"
            "evolucionar a."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
        .iconPic = gItemIcon_GalaricaCuff,
        .iconPalette = gItemIconPalette_GalaricaItem,
    },

    [ITEM_GALARICA_WREATH] =
    {
        .name = ITEM_NAME("Galarica Wreath"),
        .nombre = ITEM_NAME("Corona de Galarica"),
        .price = (I_PRICE >= GEN_9) ? 3000 : 6000,
        .description = COMPOUND_STRING(
            "A wreath made in\n"
            "Galar. Makes some\n"
            "Pokémon evolve."),
        .descricao = COMPOUND_STRING(
            "Uma coroa feita em\n"
            "Galar. Faz alguns\n"
            "Pokémon evoluírem."),
        .descricion = COMPOUND_STRING(
            "Una corona hecha en\n"
            "Galar. Hace que\n"
            "algunos Pokémon."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
        .iconPic = gItemIcon_GalaricaWreath,
        .iconPalette = gItemIconPalette_GalaricaItem,
    },

    [ITEM_DRAGON_SCALE] =
    {
        .name = ITEM_NAME("Dragon Scale"),
        .nombre = ITEM_NAME("Escama de dragon"),
        .price = (I_PRICE >= GEN_7) ? 2000 * TREASURE_FACTOR : 2100,
        .holdEffectParam = 10,
        .description = COMPOUND_STRING(
            "A strange scale\n"
            "held by Dragon-\n"
            "type Pokémon."),
        .descricao = COMPOUND_STRING(
            "Uma escama estranha\n"
            "mantida por Pokémon\n"
            "do tipo Dragão."),
        .descricion = COMPOUND_STRING(
            "Una extraña escama\n"
            "que sostienen los\n"
            "Pokémon de tipo."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = EVO_HELD_ITEM_TYPE,
        .fieldUseFunc = EVO_HELD_ITEM_FIELD_FUNC,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
        .iconPic = gItemIcon_DragonScale,
        .iconPalette = gItemIconPalette_DragonScale,
    },

    [ITEM_UPGRADE] =
    {
        .name = ITEM_NAME("Upgrade"),
        .nombre = ITEM_NAME("Actualizar"),
        .price = (I_PRICE >= GEN_7) ? 2000 * TREASURE_FACTOR : 2100,
        .description = COMPOUND_STRING(
            "A peculiar box made\n"
            "by Silph Co."),
        .descricao = COMPOUND_STRING(
            "Uma caixa peculiar\n"
            "feita pela Silph\n"
            "Co."),
        .descricion = COMPOUND_STRING(
            "Una peculiar caja\n"
            "fabricada por Silph\n"
            "Co."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = EVO_HELD_ITEM_TYPE,
        .fieldUseFunc = EVO_HELD_ITEM_FIELD_FUNC,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
        .iconPic = gItemIcon_Upgrade,
        .iconPalette = gItemIconPalette_Upgrade,
    },

    [ITEM_PROTECTOR] =
    {
        .name = ITEM_NAME("Protector"),
        .nombre = ITEM_NAME("protectora"),
        .price = (I_PRICE >= GEN_7) ? 2000 * TREASURE_FACTOR : 2100,
        .description = COMPOUND_STRING(
            "Loved by a certain\n"
            "Pokémon. It's stiff\n"
            "and heavy."),
        .descricao = COMPOUND_STRING(
            "Amado por um certo\n"
            "Pokémon. É duro e\n"
            "pesado."),
        .descricion = COMPOUND_STRING(
            "Amado por cierto\n"
            "Pokémon. Es rígido\n"
            "y pesado."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = EVO_HELD_ITEM_TYPE,
        .fieldUseFunc = EVO_HELD_ITEM_FIELD_FUNC,
        .effect = gItemEffect_EvoItem,
        .flingPower = 80,
        .iconPic = gItemIcon_Protector,
        .iconPalette = gItemIconPalette_Protector,
    },

    [ITEM_ELECTIRIZER] =
    {
        .name = ITEM_NAME("Electirizer"),
        .nombre = ITEM_NAME("Electirizador"),
        .price = (I_PRICE >= GEN_7) ? 2000 * TREASURE_FACTOR : 2100,
        .description = COMPOUND_STRING(
            "Loved by a certain\n"
            "Pokémon. It's full\n"
            "of electric energy."),
        .descricao = COMPOUND_STRING(
            "Amado por certo\n"
            "Pokémon. Está cheio\n"
            "energia elétrica."),
        .descricion = COMPOUND_STRING(
            "Amado por cierto\n"
            "Pokémon. Está lleno\n"
            "de energía."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = EVO_HELD_ITEM_TYPE,
        .fieldUseFunc = EVO_HELD_ITEM_FIELD_FUNC,
        .effect = gItemEffect_EvoItem,
        .flingPower = 80,
        .iconPic = gItemIcon_Electirizer,
        .iconPalette = gItemIconPalette_Electirizer,
    },

    [ITEM_MAGMARIZER] =
    {
        .name = ITEM_NAME("Magmarizer"),
        .nombre = ITEM_NAME("Magmarizador"),
        .price = (I_PRICE >= GEN_7) ? 2000 * TREASURE_FACTOR : 2100,
        .description = COMPOUND_STRING(
            "Loved by a certain\n"
            "Pokémon. It's full\n"
            "of magma energy."),
        .descricao = COMPOUND_STRING(
            "Amado por um certo\n"
            "Pokémon. Está cheio\n"
            "de energia."),
        .descricion = COMPOUND_STRING(
            "Amado por cierto\n"
            "Pokémon. Está lleno\n"
            "de energía magma."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = EVO_HELD_ITEM_TYPE,
        .fieldUseFunc = EVO_HELD_ITEM_FIELD_FUNC,
        .effect = gItemEffect_EvoItem,
        .flingPower = 80,
        .iconPic = gItemIcon_Magmarizer,
        .iconPalette = gItemIconPalette_Magmarizer,
    },

    [ITEM_DUBIOUS_DISC] =
    {
        .name = ITEM_NAME("Dubious Disc"),
        .nombre = ITEM_NAME("Disco dudoso"),
        .price = (I_PRICE >= GEN_7) ? 2000 * TREASURE_FACTOR : 2100,
        .description = COMPOUND_STRING(
            "A clear device\n"
            "overflowing with\n"
            "dubious data."),
        .descricao = COMPOUND_STRING(
            "Um dispositivo\n"
            "claro repleto de\n"
            "dados duvidosos."),
        .descricion = COMPOUND_STRING(
            "Un dispositivo\n"
            "claro repleto de\n"
            "datos dudosos."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = EVO_HELD_ITEM_TYPE,
        .fieldUseFunc = EVO_HELD_ITEM_FIELD_FUNC,
        .effect = gItemEffect_EvoItem,
        .flingPower = 50,
        .iconPic = gItemIcon_DubiousDisc,
        .iconPalette = gItemIconPalette_DubiousDisc,
    },

    [ITEM_REAPER_CLOTH] =
    {
        .name = ITEM_NAME("Reaper Cloth"),
        .nombre = ITEM_NAME("Pano de segador"),
        .price = (I_PRICE >= GEN_7) ? 2000 * TREASURE_FACTOR : 2100,
        .description = COMPOUND_STRING(
            "Loved by a certain\n"
            "Pokémon. Imbued\n"
            "with spirit energy."),
        .descricao = COMPOUND_STRING(
            "Amado por um certo\n"
            "Pokémon. Imbuído de\n"
            "energia espiritual."),
        .descricion = COMPOUND_STRING(
            "Amado por cierto\n"
            "Pokémon. Imbuido de\n"
            "energía espiritual."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = EVO_HELD_ITEM_TYPE,
        .fieldUseFunc = EVO_HELD_ITEM_FIELD_FUNC,
        .effect = gItemEffect_EvoItem,
        .flingPower = 10,
        .iconPic = gItemIcon_ReaperCloth,
        .iconPalette = gItemIconPalette_ReaperCloth,
    },

    [ITEM_PRISM_SCALE] =
    {
        .name = ITEM_NAME("Prism Scale"),
        .nombre = ITEM_NAME("Escala de prisma"),
    #if I_PRICE >= GEN_9
        .price = 3000,
    #elif I_PRICE >= GEN_7
        .price = 2000,
    #else
        .price = 500,
    #endif
        .description = COMPOUND_STRING(
            "A mysterious scale\n"
            "that evolves a\n"
            "certain Pokémon."),
        .descricao = COMPOUND_STRING(
            "Uma escala\n"
            "misteriosa que\n"
            "evolui um certo."),
        .descricion = COMPOUND_STRING(
            "Una escama\n"
            "misteriosa\n"
            "evoluciona cierto."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = EVO_HELD_ITEM_TYPE,
        .fieldUseFunc = EVO_HELD_ITEM_FIELD_FUNC,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
        .iconPic = gItemIcon_PrismScale,
        .iconPalette = gItemIconPalette_PrismScale,
    },

    [ITEM_WHIPPED_DREAM] =
    {
        .name = ITEM_NAME("Whipped Dream"),
        .nombre = ITEM_NAME("Sueno azotado"),
        .price = (I_PRICE >= GEN_7) ? 2000 * TREASURE_FACTOR : 2100,
        .description = COMPOUND_STRING(
            "A soft and sweet\n"
            "treat loved by a\n"
            "certain Pokémon."),
        .descricao = COMPOUND_STRING(
            "Uma guloseima suave\n"
            "e doce adorada por\n"
            "um certo Pokémon."),
        .descricion = COMPOUND_STRING(
            "Una golosina suave\n"
            "y dulce amada por\n"
            "cierto Pokémon."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = EVO_HELD_ITEM_TYPE,
        .fieldUseFunc = EVO_HELD_ITEM_FIELD_FUNC,
        .effect = gItemEffect_EvoItem,
        .flingPower = 80,
        .iconPic = gItemIcon_WhippedDream,
        .iconPalette = gItemIconPalette_WhippedDream,
    },

    [ITEM_SACHET] =
    {
        .name = ITEM_NAME("Sachet"),
        .nombre = ITEM_NAME("bolsita"),
        .price = (I_PRICE >= GEN_7) ? 2000 * TREASURE_FACTOR : 2100,
        .description = COMPOUND_STRING(
            "A sachet of strong\n"
            "perfumes, loved by\n"
            "a certain Pokémon."),
        .descricao = COMPOUND_STRING(
            "Um sachê perfumes\n"
            "fortes, adorado por\n"
            "certo Pokémon."),
        .descricion = COMPOUND_STRING(
            "Un sobre perfumes\n"
            "fuertes, adorado\n"
            "por cierto Pokémon."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = EVO_HELD_ITEM_TYPE,
        .fieldUseFunc = EVO_HELD_ITEM_FIELD_FUNC,
        .effect = gItemEffect_EvoItem,
        .flingPower = 80,
        .iconPic = gItemIcon_Sachet,
        .iconPalette = gItemIconPalette_Sachet,
    },

    [ITEM_OVAL_STONE] =
    {
        .name = ITEM_NAME("Oval Stone"),
        .nombre = ITEM_NAME("P. Ovalada"),
        .price = (I_PRICE >= GEN_7) ? 2000 : 2100,
        .description = COMPOUND_STRING(
            "Peculiar stone that\n"
            "evolves a certain\n"
            "Pokémon."),
        .descricao = COMPOUND_STRING(
            "Pedra peculiar\n"
            "evolui determinado\n"
            "Pokémon."),
        .descricion = COMPOUND_STRING(
            "Piedra peculiar que\n"
            "hace evolucionar a\n"
            "un determinado."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = EVO_HELD_ITEM_TYPE,
        .fieldUseFunc = EVO_HELD_ITEM_FIELD_FUNC,
        .effect = gItemEffect_EvoItem,
        .flingPower = 80,
        .iconPic = gItemIcon_OvalStone,
        .iconPalette = gItemIconPalette_OvalStone,
    },

    [ITEM_STRAWBERRY_SWEET] =
    {
        .name = ITEM_NAME("Strawberry Sweet"),
        .nombre = ITEM_NAME("dulce de fresa"),
        .price = 500 * TREASURE_FACTOR,
        .description = COMPOUND_STRING(
            "Strawberry-shaped\n"
            "sweet loved by\n"
            "Milcery."),
        .descricao = COMPOUND_STRING(
            "Doce em formato de\n"
            "morango adorado por\n"
            "Milcery."),
        .descricion = COMPOUND_STRING(
            "Dulce con forma de\n"
            "fresa adorado por\n"
            "Milcery."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_StrawberrySweet,
        .iconPalette = gItemIconPalette_StrawberrySweet,
    },

    [ITEM_LOVE_SWEET] =
    {
        .name = ITEM_NAME("Love Sweet"),
        .nombre = ITEM_NAME("amor dulce"),
        .price = 500 * TREASURE_FACTOR,
        .description = COMPOUND_STRING(
            "A heart-shaped\n"
            "sweet loved by\n"
            "Milcery."),
        .descricao = COMPOUND_STRING(
            "Um doce em formato\n"
            "de coração adorado\n"
            "por Milcery."),
        .descricion = COMPOUND_STRING(
            "Un dulce en forma\n"
            "de corazón amado\n"
            "por Milcery."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_LoveSweet,
        .iconPalette = gItemIconPalette_LoveSweet,
    },

    [ITEM_BERRY_SWEET] =
    {
        .name = ITEM_NAME("Berry Sweet"),
        .nombre = ITEM_NAME("Dulce de bayas"),
        .price = 500 * TREASURE_FACTOR,
        .description = COMPOUND_STRING(
            "A berry-shaped\n"
            "sweet loved by\n"
            "Milcery."),
        .descricao = COMPOUND_STRING(
            "Um doce em forma de\n"
            "baga adorado por\n"
            "Milcery."),
        .descricion = COMPOUND_STRING(
            "Un dulce con forma\n"
            "de baya adorado por\n"
            "Milcery."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_BerrySweet,
        .iconPalette = gItemIconPalette_BerrySweet,
    },

    [ITEM_CLOVER_SWEET] =
    {
        .name = ITEM_NAME("Clover Sweet"),
        .nombre = ITEM_NAME("trebol dulce"),
        .price = 500 * TREASURE_FACTOR,
        .description = COMPOUND_STRING(
            "A clover-shaped\n"
            "sweet loved by\n"
            "Milcery."),
        .descricao = COMPOUND_STRING(
            "Um doce em forma de\n"
            "trevo adorado por\n"
            "Milcery."),
        .descricion = COMPOUND_STRING(
            "Un dulce con forma\n"
            "de trébol adorado\n"
            "por Milcery."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_CloverSweet,
        .iconPalette = gItemIconPalette_CloverSweet,
    },

    [ITEM_FLOWER_SWEET] =
    {
        .name = ITEM_NAME("Flower Sweet"),
        .nombre = ITEM_NAME("flor dulce"),
        .price = 500 * TREASURE_FACTOR,
        .description = COMPOUND_STRING(
            "A flower-shaped\n"
            "sweet loved by\n"
            "Milcery."),
        .descricao = COMPOUND_STRING(
            "Um doce em forma de\n"
            "flor adorado por\n"
            "Milcery."),
        .descricion = COMPOUND_STRING(
            "Un dulce con forma\n"
            "de flor adorado por\n"
            "Milcery."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_FlowerSweet,
        .iconPalette = gItemIconPalette_FlowerSweet,
    },

    [ITEM_STAR_SWEET] =
    {
        .name = ITEM_NAME("Star Sweet"),
        .nombre = ITEM_NAME("estrella dulce"),
        .price = 500 * TREASURE_FACTOR,
        .description = COMPOUND_STRING(
            "A star-shaped sweet\n"
            "loved by Milcery."),
        .descricao = COMPOUND_STRING(
            "Um doce em forma de\n"
            "estrela adorado por\n"
            "Milcery."),
        .descricion = COMPOUND_STRING(
            "Un dulce en forma\n"
            "de estrella adorado\n"
            "por Milcery."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_StarSweet,
        .iconPalette = gItemIconPalette_StarSweet,
    },

    [ITEM_RIBBON_SWEET] =
    {
        .name = ITEM_NAME("Ribbon Sweet"),
        .nombre = ITEM_NAME("cinta dulce"),
        .price = 500 * TREASURE_FACTOR,
        .description = COMPOUND_STRING(
            "A ribbon-shaped\n"
            "sweet loved by\n"
            "Milcery."),
        .descricao = COMPOUND_STRING(
            "Um doce em forma de\n"
            "fita adorado por\n"
            "Milcery."),
        .descricion = COMPOUND_STRING(
            "Un dulce en forma\n"
            "de cinta que adora\n"
            "Milcery."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_RibbonSweet,
        .iconPalette = gItemIconPalette_RibbonSweet,
    },

    [ITEM_EVERSTONE] =
    {
        .name = ITEM_NAME("Everstone"),
        .nombre = ITEM_NAME("P. Eterna"),
        .price = (I_PRICE >= GEN_7) ? 3000 : 200,
        .holdEffect = HOLD_EFFECT_PREVENT_EVOLVE,
        .description = COMPOUND_STRING(
            "A wondrous hold\n"
            "item that prevents\n"
            "evolution."),
        .descricao = COMPOUND_STRING(
            "Um item de retenção\n"
            "maravilhoso que\n"
            "impede a evolução."),
        .descricion = COMPOUND_STRING(
            "Un objeto\n"
            "maravilloso impide\n"
            "la evolución."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_Everstone,
        .iconPalette = gItemIconPalette_Everstone,
    },

// Nectars

    [ITEM_RED_NECTAR] =
    {
        .name = ITEM_NAME("Red Nectar"),
        .nombre = ITEM_NAME("Nectar rojo"),
        .price = 300,
        .holdEffectParam = 0,
        .description = sNectarDesc,
        .descricao = COMPOUND_STRING(
            "Néctar de flores\n"
            "que altera a forma\n"
            "de certos Pokémon."),
        .descricion = COMPOUND_STRING(
            "Néctar de flores\n"
            "que cambia la forma\n"
            "de ciertos Pokémon."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_NECTAR,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_FormChange_ConsumedOnUse,
        .flingPower = 10,
        .iconPic = gItemIcon_Nectar,
        .iconPalette = gItemIconPalette_RedNectar,
    },

    [ITEM_YELLOW_NECTAR] =
    {
        .name = ITEM_NAME("Yellow Nectar"),
        .nombre = ITEM_NAME("Nectar amarillo"),
        .price = 300,
        .holdEffectParam = 0,
        .description = sNectarDesc,
        .descricao = COMPOUND_STRING(
            "Néctar de flores\n"
            "que altera a forma\n"
            "de certos Pokémon."),
        .descricion = COMPOUND_STRING(
            "Néctar de flores\n"
            "que cambia la forma\n"
            "de ciertos Pokémon."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_NECTAR,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_FormChange_ConsumedOnUse,
        .flingPower = 10,
        .iconPic = gItemIcon_Nectar,
        .iconPalette = gItemIconPalette_YellowNectar,
    },

    [ITEM_PINK_NECTAR] =
    {
        .name = ITEM_NAME("Pink Nectar"),
        .nombre = ITEM_NAME("Nectar Rosa"),
        .price = 300,
        .holdEffectParam = 0,
        .description = sNectarDesc,
        .descricao = COMPOUND_STRING(
            "Néctar de flores\n"
            "que altera a forma\n"
            "de certos Pokémon."),
        .descricion = COMPOUND_STRING(
            "Néctar de flores\n"
            "que cambia la forma\n"
            "de ciertos Pokémon."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_NECTAR,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_FormChange_ConsumedOnUse,
        .flingPower = 10,
        .iconPic = gItemIcon_Nectar,
        .iconPalette = gItemIconPalette_PinkNectar,
    },

    [ITEM_PURPLE_NECTAR] =
    {
        .name = ITEM_NAME("Purple Nectar"),
        .nombre = ITEM_NAME("Nectar Purpura"),
        .price = 300,
        .holdEffectParam = 0,
        .description = sNectarDesc,
        .descricao = COMPOUND_STRING(
            "Néctar de flores\n"
            "que altera a forma\n"
            "de certos Pokémon."),
        .descricion = COMPOUND_STRING(
            "Néctar de flores\n"
            "que cambia la forma\n"
            "de ciertos Pokémon."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_NECTAR,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_FormChange_ConsumedOnUse,
        .flingPower = 10,
        .iconPic = gItemIcon_Nectar,
        .iconPalette = gItemIconPalette_PurpleNectar,
    },

// Plates

    [ITEM_FLAME_PLATE] =
    {
        .name = ITEM_NAME("Flame Plate"),
        .nombre = ITEM_NAME("Placa de llama"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "A tablet that ups\n"
            "the power of\n"
            "Fire-type moves."),
        .descricao = COMPOUND_STRING(
            "Um tablet que sobe\n"
            "o poder dos golpes\n"
            "do tipo Fogo."),
        .descricion = COMPOUND_STRING(
            "Una tableta que\n"
            "sobe el poder de\n"
            "los movs. tipo."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_PLATE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FIRE,
        .flingPower = 90,
        .iconPic = gItemIcon_Plate,
        .iconPalette = gItemIconPalette_FlamePlate,
    },

    [ITEM_SPLASH_PLATE] =
    {
        .name = ITEM_NAME("Splash Plate"),
        .nombre = ITEM_NAME("Splash Plate"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "A tablet that ups\n"
            "the power of\n"
            "Water-type moves."),
        .descricao = COMPOUND_STRING(
            "Um tablet que sobe\n"
            "o poder dos golpes\n"
            "do tipo Água."),
        .descricion = COMPOUND_STRING(
            "Una tableta que\n"
            "sobe el poder de\n"
            "los movs. de tipo."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_PLATE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_WATER,
        .flingPower = 90,
        .iconPic = gItemIcon_Plate,
        .iconPalette = gItemIconPalette_SplashPlate,
    },

    [ITEM_ZAP_PLATE] =
    {
        .name = ITEM_NAME("Zap Plate"),
        .nombre = ITEM_NAME("Placa de descarga"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "A tablet that ups\n"
            "the power of Elec-\n"
            "tric-type moves."),
        .descricao = COMPOUND_STRING(
            "Um tablet que sobe\n"
            "o poder dos golpes\n"
            "do tipo."),
        .descricion = COMPOUND_STRING(
            "Una tableta que\n"
            "sobe el poder de\n"
            "los movs. de tipo."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_PLATE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ELECTRIC,
        .flingPower = 90,
        .iconPic = gItemIcon_Plate,
        .iconPalette = gItemIconPalette_ZapPlate,
    },

    [ITEM_MEADOW_PLATE] =
    {
        .name = ITEM_NAME("Meadow Plate"),
        .nombre = ITEM_NAME("Plato de pradera"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "A tablet that ups\n"
            "the power of\n"
            "Grass-type moves."),
        .descricao = COMPOUND_STRING(
            "Um tablet que sobe\n"
            "o poder dos golpes\n"
            "do tipo."),
        .descricion = COMPOUND_STRING(
            "Una tableta que\n"
            "sobe el poder de\n"
            "los movs. tipo."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_PLATE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_GRASS,
        .flingPower = 90,
        .iconPic = gItemIcon_Plate,
        .iconPalette = gItemIconPalette_MeadowPlate,
    },

    [ITEM_ICICLE_PLATE] =
    {
        .name = ITEM_NAME("Icicle Plate"),
        .nombre = ITEM_NAME("Placa de carambano"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "A tablet that ups\n"
            "the power of\n"
            "Ice-type moves."),
        .descricao = COMPOUND_STRING(
            "Um tablet que sobe\n"
            "o poder dos golpes\n"
            "do tipo Ice."),
        .descricion = COMPOUND_STRING(
            "Una tableta que\n"
            "sobe el poder de\n"
            "los movs. tipo."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_PLATE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ICE,
        .flingPower = 90,
        .iconPic = gItemIcon_Plate,
        .iconPalette = gItemIconPalette_IciclePlate,
    },

    [ITEM_FIST_PLATE] =
    {
        .name = ITEM_NAME("Fist Plate"),
        .nombre = ITEM_NAME("Placa de puno"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "A tablet that ups\n"
            "the power of Fight-\n"
            "ing-type moves."),
        .descricao = COMPOUND_STRING(
            "Um tablet que sobe\n"
            "o poder dos golpes\n"
            "do tipo."),
        .descricion = COMPOUND_STRING(
            "Una tableta que\n"
            "sobe el poder de\n"
            "los movs. de tipo."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_PLATE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FIGHTING,
        .flingPower = 90,
        .iconPic = gItemIcon_Plate,
        .iconPalette = gItemIconPalette_FistPlate,
    },

    [ITEM_TOXIC_PLATE] =
    {
        .name = ITEM_NAME("Toxic Plate"),
        .nombre = ITEM_NAME("Placa toxica"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "A tablet that ups\n"
            "the power of\n"
            "Poison-type moves."),
        .descricao = COMPOUND_STRING(
            "Um tablet que sobe\n"
            "o poder dos golpes\n"
            "do tipo."),
        .descricion = COMPOUND_STRING(
            "Una tableta que\n"
            "sobe el poder de\n"
            "los movs. tipo."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_PLATE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_POISON,
        .flingPower = 90,
        .iconPic = gItemIcon_Plate,
        .iconPalette = gItemIconPalette_ToxicPlate,
    },

    [ITEM_EARTH_PLATE] =
    {
        .name = ITEM_NAME("Earth Plate"),
        .nombre = ITEM_NAME("Placa de tierra"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "A tablet that ups\n"
            "the power of\n"
            "Ground-type moves."),
        .descricao = COMPOUND_STRING(
            "Um tablet que sobe\n"
            "o poder dos golpes\n"
            "do tipo."),
        .descricion = COMPOUND_STRING(
            "Una tableta que\n"
            "sobe el poder de\n"
            "los movs. de tipo."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_PLATE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_GROUND,
        .flingPower = 90,
        .iconPic = gItemIcon_Plate,
        .iconPalette = gItemIconPalette_EarthPlate,
    },

    [ITEM_SKY_PLATE] =
    {
        .name = ITEM_NAME("Sky Plate"),
        .nombre = ITEM_NAME("Placa del cielo"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "A tablet that ups\n"
            "the power of\n"
            "Flying-type moves."),
        .descricao = COMPOUND_STRING(
            "Um tablet que sobe\n"
            "o poder dos golpes\n"
            "do tipo."),
        .descricion = COMPOUND_STRING(
            "Una tableta que\n"
            "sobe el poder de\n"
            "los movs. de tipo."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_PLATE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FLYING,
        .flingPower = 90,
        .iconPic = gItemIcon_Plate,
        .iconPalette = gItemIconPalette_SkyPlate,
    },

    [ITEM_MIND_PLATE] =
    {
        .name = ITEM_NAME("Mind Plate"),
        .nombre = ITEM_NAME("Placa mental"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "A tablet that ups\n"
            "the power of Psy\n"
            "chic-type moves."),
        .descricao = COMPOUND_STRING(
            "Um tablet que sobe\n"
            "o poder dos golpes\n"
            "do tipo Psy."),
        .descricion = COMPOUND_STRING(
            "Una tablet potencia\n"
            "el poder los movs.\n"
            "tipo."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_PLATE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_PSYCHIC,
        .flingPower = 90,
        .iconPic = gItemIcon_Plate,
        .iconPalette = gItemIconPalette_MindPlate,
    },

    [ITEM_INSECT_PLATE] =
    {
        .name = ITEM_NAME("Insect Plate"),
        .nombre = ITEM_NAME("Plato de insectos"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "A tablet that ups\n"
            "the power of\n"
            "Bug-type moves."),
        .descricao = COMPOUND_STRING(
            "Um tablet que sobe\n"
            "o poder dos golpes\n"
            "do tipo Bug."),
        .descricion = COMPOUND_STRING(
            "Una tableta que\n"
            "sobe el poder de\n"
            "los movs. tipo Bug."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_PLATE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_BUG,
        .flingPower = 90,
        .iconPic = gItemIcon_Plate,
        .iconPalette = gItemIconPalette_InsectPlate,
    },

    [ITEM_STONE_PLATE] =
    {
        .name = ITEM_NAME("Stone Plate"),
        .nombre = ITEM_NAME("Placa de piedra"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "A tablet that ups\n"
            "the power of\n"
            "Rock-type moves."),
        .descricao = COMPOUND_STRING(
            "Um tablet que sobe\n"
            "o poder dos golpes\n"
            "do tipo Rock."),
        .descricion = COMPOUND_STRING(
            "Una tableta sobe el\n"
            "poder los movs.\n"
            "tipo Roca."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_PLATE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ROCK,
        .flingPower = 90,
        .iconPic = gItemIcon_Plate,
        .iconPalette = gItemIconPalette_StonePlate,
    },

    [ITEM_SPOOKY_PLATE] =
    {
        .name = ITEM_NAME("Spooky Plate"),
        .nombre = ITEM_NAME("Plato espeluznante"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "A tablet that ups\n"
            "the power of\n"
            "Ghost-type moves."),
        .descricao = COMPOUND_STRING(
            "Um tablet que sobe\n"
            "o poder dos golpes\n"
            "do tipo."),
        .descricion = COMPOUND_STRING(
            "Una tableta que\n"
            "sobe el poder de\n"
            "los movs. tipo."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_PLATE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_GHOST,
        .flingPower = 90,
        .iconPic = gItemIcon_Plate,
        .iconPalette = gItemIconPalette_SpookyPlate,
    },

    [ITEM_DRACO_PLATE] =
    {
        .name = ITEM_NAME("Draco Plate"),
        .nombre = ITEM_NAME("Placa Draco"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "A tablet that ups\n"
            "the power of\n"
            "Dragon-type moves."),
        .descricao = COMPOUND_STRING(
            "Um tablet que sobe\n"
            "o poder dos golpes\n"
            "do tipo."),
        .descricion = COMPOUND_STRING(
            "Una tableta que\n"
            "sobe el poder de\n"
            "los movs. tipo."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_PLATE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_DRAGON,
        .flingPower = 90,
        .iconPic = gItemIcon_Plate,
        .iconPalette = gItemIconPalette_DracoPlate,
    },

    [ITEM_DREAD_PLATE] =
    {
        .name = ITEM_NAME("Dread Plate"),
        .nombre = ITEM_NAME("Placa aterradora"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "A tablet that ups\n"
            "the power of\n"
            "Dark-type moves."),
        .descricao = COMPOUND_STRING(
            "Um tablet que sobe\n"
            "o poder dos golpes\n"
            "do tipo Dark."),
        .descricion = COMPOUND_STRING(
            "Una tableta que\n"
            "sobe el poder de\n"
            "los movs. de tipo."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_PLATE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_DARK,
        .flingPower = 90,
        .iconPic = gItemIcon_Plate,
        .iconPalette = gItemIconPalette_DreadPlate,
    },

    [ITEM_IRON_PLATE] =
    {
        .name = ITEM_NAME("Iron Plate"),
        .nombre = ITEM_NAME("Placa de hierro"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "A tablet that ups\n"
            "the power of\n"
            "Steel-type moves."),
        .descricao = COMPOUND_STRING(
            "Um tablet que sobe\n"
            "o poder dos golpes\n"
            "do tipo."),
        .descricion = COMPOUND_STRING(
            "Una tableta que\n"
            "sobe el poder de\n"
            "los movs. tipo."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_PLATE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_STEEL,
        .flingPower = 90,
        .iconPic = gItemIcon_Plate,
        .iconPalette = gItemIconPalette_IronPlate,
    },

    [ITEM_PIXIE_PLATE] =
    {
        .name = ITEM_NAME("Pixie Plate"),
        .nombre = ITEM_NAME("Plato de Hada"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "A tablet that ups\n"
            "the power of\n"
            "Fairy-type moves."),
        .descricao = COMPOUND_STRING(
            "Um tablet que sobe\n"
            "o poder dos golpes\n"
            "do tipo."),
        .descricion = COMPOUND_STRING(
            "Una tableta sobe el\n"
            "poder los movs.\n"
            "tipo Hada."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_PLATE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FAIRY,
        .flingPower = 90,
        .iconPic = gItemIcon_Plate,
        .iconPalette = gItemIconPalette_PixiePlate,
    },

// Drives

    [ITEM_DOUSE_DRIVE] =
    {
        .name = ITEM_NAME("Douse Drive"),
        .nombre = ITEM_NAME("Unidad de apagado"),
        .price = (I_PRICE >= GEN_7) ? 0 : 1000,
        .holdEffect = HOLD_EFFECT_DRIVE,
        .description = COMPOUND_STRING(
            "Changes Genesect's\n"
            "Techno Blast to\n"
            "Water-type."),
        .descricao = COMPOUND_STRING(
            "Muda o Techno Blast\n"
            "de Genesect para o\n"
            "tipo Água."),
        .descricion = COMPOUND_STRING(
            "Cambia el Techno\n"
            "Blast de Genesect a\n"
            "tipo Agua."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_DRIVE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_WATER,
        .flingPower = 70,
        .iconPic = gItemIcon_Drive,
        .iconPalette = gItemIconPalette_DouseDrive,
    },

    [ITEM_SHOCK_DRIVE] =
    {
        .name = ITEM_NAME("Shock Drive"),
        .nombre = ITEM_NAME("Impulsion de choque"),
        .price = (I_PRICE >= GEN_7) ? 0 : 1000,
        .holdEffect = HOLD_EFFECT_DRIVE,
        .description = COMPOUND_STRING(
            "Changes Genesect's\n"
            "Techno Blast to\n"
            "Electric-type."),
        .descricao = COMPOUND_STRING(
            "Muda o Techno Blast\n"
            "do Genesect para o\n"
            "tipo Elétrico."),
        .descricion = COMPOUND_STRING(
            "Cambia el Techno\n"
            "Blast de Genesect a\n"
            "tipo eléctrico."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_DRIVE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ELECTRIC,
        .flingPower = 70,
        .iconPic = gItemIcon_Drive,
        .iconPalette = gItemIconPalette_ShockDrive,
    },

    [ITEM_BURN_DRIVE] =
    {
        .name = ITEM_NAME("Burn Drive"),
        .nombre = ITEM_NAME("Grabar unid."),
        .price = (I_PRICE >= GEN_7) ? 0 : 1000,
        .holdEffect = HOLD_EFFECT_DRIVE,
        .description = COMPOUND_STRING(
            "Changes Genesect's\n"
            "Techno Blast to\n"
            "Fire-type."),
        .descricao = COMPOUND_STRING(
            "Muda o Techno Blast\n"
            "do Genesect para o\n"
            "tipo Fire."),
        .descricion = COMPOUND_STRING(
            "Cambia el Techno\n"
            "Blast de Genesect a\n"
            "tipo Fuego."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_DRIVE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FIRE,
        .flingPower = 70,
        .iconPic = gItemIcon_Drive,
        .iconPalette = gItemIconPalette_BurnDrive,
    },

    [ITEM_CHILL_DRIVE] =
    {
        .name = ITEM_NAME("Chill Drive"),
        .nombre = ITEM_NAME("Chill Drive"),
        .price = (I_PRICE >= GEN_7) ? 0 : 1000,
        .holdEffect = HOLD_EFFECT_DRIVE,
        .description = COMPOUND_STRING(
            "Changes Genesect's\n"
            "Techno Blast to\n"
            "Ice-type."),
        .descricao = COMPOUND_STRING(
            "Muda o Techno Blast\n"
            "de Genesect para o\n"
            "tipo Ice."),
        .descricion = COMPOUND_STRING(
            "Cambia el Techno\n"
            "Blast de Genesect a\n"
            "tipo Hielo."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_DRIVE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ICE,
        .flingPower = 70,
        .iconPic = gItemIcon_Drive,
        .iconPalette = gItemIconPalette_ChillDrive,
    },

// Memories

    [ITEM_FIRE_MEMORY] =
    {
        .name = ITEM_NAME("Fire Memory"),
        .nombre = ITEM_NAME("Memoria de fuego"),
        .pluralName = ITEM_PLURAL_NAME("Fire Memories"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "A disc with Fire\n"
            "type data. It swaps\n"
            "Silvally's type."),
        .descricao = COMPOUND_STRING(
            "Um disco com dados\n"
            "do tipo Fire. Ele\n"
            "troca o tipo de."),
        .descricion = COMPOUND_STRING(
            "Un disco con datos\n"
            "tipo Fire. Cambia\n"
            "el tipo Silvally."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEMORY,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FIRE,
        .flingPower = 50,
        .iconPic = gItemIcon_FireMemory,
        .iconPalette = gItemIconPalette_FireMemory,
    },

    [ITEM_WATER_MEMORY] =
    {
        .name = ITEM_NAME("Water Memory"),
        .nombre = ITEM_NAME("Memoria del agua"),
        .pluralName = ITEM_PLURAL_NAME("Water Memories"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "A disc with Water\n"
            "type data. It swaps\n"
            "Silvally's type."),
        .descricao = COMPOUND_STRING(
            "Um disco com dados\n"
            "do tipo Água. Ele\n"
            "troca o tipo de."),
        .descricion = COMPOUND_STRING(
            "Un disco con datos\n"
            "tipo Agua. Cambia\n"
            "el tipo Silvally."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEMORY,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_WATER,
        .flingPower = 50,
        .iconPic = gItemIcon_WaterMemory,
        .iconPalette = gItemIconPalette_WaterMemory,
    },

    [ITEM_ELECTRIC_MEMORY] =
    {
        .name = ITEM_NAME("Electric Memory"),
        .nombre = ITEM_NAME("Memoria electrica"),
        .pluralName = ITEM_PLURAL_NAME("Electric Memories"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "A disc Electric\n"
            "type data. It swaps\n"
            "Silvally's type."),
        .descricao = COMPOUND_STRING(
            "Um disco com dados\n"
            "tipo Electric. Ele\n"
            "troca tipo"),
        .descricion = COMPOUND_STRING(
            "Un disco con datos\n"
            "de tipo Eléctrico.\n"
            "Cambia el tipo de."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEMORY,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ELECTRIC,
        .flingPower = 50,
        .iconPic = gItemIcon_ElectricMemory,
        .iconPalette = gItemIconPalette_ElectricMemory,
    },

    [ITEM_GRASS_MEMORY] =
    {
        .name = ITEM_NAME("Grass Memory"),
        .nombre = ITEM_NAME("Memoria de hierba"),
        .pluralName = ITEM_PLURAL_NAME("Grass Memories"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "A disc with Grass\n"
            "type data. It swaps\n"
            "Silvally's type."),
        .descricao = COMPOUND_STRING(
            "Um disco com dados\n"
            "do tipo Grass. Ele\n"
            "troca o tipo de."),
        .descricion = COMPOUND_STRING(
            "Un disco con datos\n"
            "tipo Grass. Cambia\n"
            "el tipo Silvally."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEMORY,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_GRASS,
        .flingPower = 50,
        .iconPic = gItemIcon_GrassMemory,
        .iconPalette = gItemIconPalette_GrassMemory,
    },

    [ITEM_ICE_MEMORY] =
    {
        .name = ITEM_NAME("Ice Memory"),
        .nombre = ITEM_NAME("Memoria de hielo"),
        .pluralName = ITEM_PLURAL_NAME("Ice Memories"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "A disc with Ice\n"
            "type data. It swaps\n"
            "Silvally's type."),
        .descricao = COMPOUND_STRING(
            "Um disco com dados\n"
            "do tipo Ice. Ele\n"
            "troca o tipo de."),
        .descricion = COMPOUND_STRING(
            "Un disco con datos\n"
            "tipo Ice. Cambia el\n"
            "tipo de Silvally."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEMORY,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ICE,
        .flingPower = 50,
        .iconPic = gItemIcon_IceMemory,
        .iconPalette = gItemIconPalette_IceMemory,
    },

    [ITEM_FIGHTING_MEMORY] =
    {
        .name = ITEM_NAME("Fighting Memory"),
        .nombre = ITEM_NAME("Memoria de lucha"),
        .pluralName = ITEM_PLURAL_NAME("Fighting Memories"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "Disc with Fighting\n"
            "type data. It swaps\n"
            "Silvally's type."),
        .descricao = COMPOUND_STRING(
            "Disco com dados do\n"
            "tipo Fighting. Ele\n"
            "troca o tipo de."),
        .descricion = COMPOUND_STRING(
            "Disco con datos\n"
            "tipo Fighting.\n"
            "Cambia el tipo."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEMORY,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FIGHTING,
        .flingPower = 50,
        .iconPic = gItemIcon_FightingMemory,
        .iconPalette = gItemIconPalette_FightingMemory,
    },

    [ITEM_POISON_MEMORY] =
    {
        .name = ITEM_NAME("Poison Memory"),
        .nombre = ITEM_NAME("Memoria venenosa"),
        .pluralName = ITEM_PLURAL_NAME("Poison Memories"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "A disc with Poison\n"
            "type data. It swaps\n"
            "Silvally's type."),
        .descricao = COMPOUND_STRING(
            "Um disco com dados\n"
            "do tipo Poison. Ele\n"
            "troca o tipo de."),
        .descricion = COMPOUND_STRING(
            "Un disco con datos\n"
            "tipo Poison. Cambia\n"
            "el tipo Silvally."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEMORY,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_POISON,
        .flingPower = 50,
        .iconPic = gItemIcon_PoisonMemory,
        .iconPalette = gItemIconPalette_PoisonMemory,
    },

    [ITEM_GROUND_MEMORY] =
    {
        .name = ITEM_NAME("Ground Memory"),
        .nombre = ITEM_NAME("Memoria de tierra"),
        .pluralName = ITEM_PLURAL_NAME("Ground Memories"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "A disc with Ground\n"
            "type data. It swaps\n"
            "Silvally's type."),
        .descricao = COMPOUND_STRING(
            "Um disco com dados\n"
            "do tipo Ground. Ele\n"
            "troca o tipo de."),
        .descricion = COMPOUND_STRING(
            "Un disco con datos\n"
            "de tipo Ground.\n"
            "Cambia el tipo de."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEMORY,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_GROUND,
        .flingPower = 50,
        .iconPic = gItemIcon_GroundMemory,
        .iconPalette = gItemIconPalette_GroundMemory,
    },

    [ITEM_FLYING_MEMORY] =
    {
        .name = ITEM_NAME("Flying Memory"),
        .nombre = ITEM_NAME("Memoria voladora"),
        .pluralName = ITEM_PLURAL_NAME("Flying Memories"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "A disc with Flying\n"
            "type data. It swaps\n"
            "Silvally's type."),
        .descricao = COMPOUND_STRING(
            "Um disco com dados\n"
            "do tipo Flying. Ele\n"
            "troca o tipo de."),
        .descricion = COMPOUND_STRING(
            "Un disco con datos\n"
            "tipo Flying. Cambia\n"
            "el tipo Silvally."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEMORY,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FLYING,
        .flingPower = 50,
        .iconPic = gItemIcon_FlyingMemory,
        .iconPalette = gItemIconPalette_FlyingMemory,
    },

    [ITEM_PSYCHIC_MEMORY] =
    {
        .name = ITEM_NAME("Psychic Memory"),
        .nombre = ITEM_NAME("Memoria psiquica"),
        .pluralName = ITEM_PLURAL_NAME("Psychic Memories"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "A disc with Psychic\n"
            "type data. It swaps\n"
            "Silvally's type."),
        .descricao = COMPOUND_STRING(
            "Um disco com dados\n"
            "tipo Psíquico. Ele\n"
            "troca tipo"),
        .descricion = COMPOUND_STRING(
            "Un disco con datos\n"
            "de tipo Psíquico.\n"
            "Cambia el tipo de."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEMORY,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_PSYCHIC,
        .flingPower = 50,
        .iconPic = gItemIcon_PsychicMemory,
        .iconPalette = gItemIconPalette_PsychicMemory,
    },

    [ITEM_BUG_MEMORY] =
    {
        .name = ITEM_NAME("Bug Memory"),
        .nombre = ITEM_NAME("Memoria de errores"),
        .pluralName = ITEM_PLURAL_NAME("Bug Memories"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "A disc with Bug\n"
            "type data. It swaps\n"
            "Silvally's type."),
        .descricao = COMPOUND_STRING(
            "Um disco com dados\n"
            "do tipo Bug. Ele\n"
            "troca o tipo de."),
        .descricion = COMPOUND_STRING(
            "Un disco con datos\n"
            "tipo Bug. Cambia el\n"
            "tipo Silvally."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEMORY,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_BUG,
        .flingPower = 50,
        .iconPic = gItemIcon_BugMemory,
        .iconPalette = gItemIconPalette_BugMemory,
    },

    [ITEM_ROCK_MEMORY] =
    {
        .name = ITEM_NAME("Rock Memory"),
        .nombre = ITEM_NAME("Memoria del rock"),
        .pluralName = ITEM_PLURAL_NAME("Rock Memories"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "A disc with Rock\n"
            "type data. It swaps\n"
            "Silvally's type."),
        .descricao = COMPOUND_STRING(
            "Um disco com dados\n"
            "do tipo Rock. Ele\n"
            "troca o tipo de."),
        .descricion = COMPOUND_STRING(
            "Un disco con datos\n"
            "tipo Rock. Cambia\n"
            "el tipo Silvally."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEMORY,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ROCK,
        .flingPower = 50,
        .iconPic = gItemIcon_RockMemory,
        .iconPalette = gItemIconPalette_RockMemory,
    },

    [ITEM_GHOST_MEMORY] =
    {
        .name = ITEM_NAME("Ghost Memory"),
        .nombre = ITEM_NAME("Memoria fantasma"),
        .pluralName = ITEM_PLURAL_NAME("Ghost Memories"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "A disc with Ghost\n"
            "type data. It swaps\n"
            "Silvally's type."),
        .descricao = COMPOUND_STRING(
            "Um disco com dados\n"
            "do tipo Ghost. Ele\n"
            "troca o tipo de."),
        .descricion = COMPOUND_STRING(
            "Un disco con datos\n"
            "tipo Ghost. Cambia\n"
            "el tipo Silvally."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEMORY,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_GHOST,
        .flingPower = 50,
        .iconPic = gItemIcon_GhostMemory,
        .iconPalette = gItemIconPalette_GhostMemory,
    },

    [ITEM_DRAGON_MEMORY] =
    {
        .name = ITEM_NAME("Dragon Memory"),
        .nombre = ITEM_NAME("Memoria del Dragon"),
        .pluralName = ITEM_PLURAL_NAME("Dragon Memories"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "A disc with Dragon\n"
            "type data. It swaps\n"
            "Silvally's type."),
        .descricao = COMPOUND_STRING(
            "Um disco com dados\n"
            "do tipo Dragon. Ele\n"
            "troca o tipo de."),
        .descricion = COMPOUND_STRING(
            "Un disco con datos\n"
            "tipo Dragon. Cambia\n"
            "el tipo Silvally."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEMORY,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_DRAGON,
        .flingPower = 50,
        .iconPic = gItemIcon_DragonMemory,
        .iconPalette = gItemIconPalette_DragonMemory,
    },

    [ITEM_DARK_MEMORY] =
    {
        .name = ITEM_NAME("Dark Memory"),
        .nombre = ITEM_NAME("Memoria oscura"),
        .pluralName = ITEM_PLURAL_NAME("Dark Memories"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "A disc with Dark\n"
            "type data. It swaps\n"
            "Silvally's type."),
        .descricao = COMPOUND_STRING(
            "Um disco com dados\n"
            "do tipo Dark. Ele\n"
            "troca o tipo de."),
        .descricion = COMPOUND_STRING(
            "Un disco con datos\n"
            "tipo Dark. Cambia\n"
            "el tipo Silvally."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEMORY,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_DARK,
        .flingPower = 50,
        .iconPic = gItemIcon_DarkMemory,
        .iconPalette = gItemIconPalette_DarkMemory,
    },

    [ITEM_STEEL_MEMORY] =
    {
        .name = ITEM_NAME("Steel Memory"),
        .nombre = ITEM_NAME("Memoria de acero"),
        .pluralName = ITEM_PLURAL_NAME("Steel Memories"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "A disc with Steel\n"
            "type data. It swaps\n"
            "Silvally's type."),
        .descricao = COMPOUND_STRING(
            "Um disco com dados\n"
            "do tipo Steel. Ele\n"
            "troca o tipo de."),
        .descricion = COMPOUND_STRING(
            "Un disco con datos\n"
            "tipo Steel. Cambia\n"
            "el tipo Silvally."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEMORY,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_STEEL,
        .flingPower = 50,
        .iconPic = gItemIcon_SteelMemory,
        .iconPalette = gItemIconPalette_SteelMemory,
    },

    [ITEM_FAIRY_MEMORY] =
    {
        .name = ITEM_NAME("Fairy Memory"),
        .nombre = ITEM_NAME("Memoria de hadas"),
        .pluralName = ITEM_PLURAL_NAME("Fairy Memories"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "A disc with Fairy\n"
            "type data. It swaps\n"
            "Silvally's type."),
        .descricao = COMPOUND_STRING(
            "Um disco com dados\n"
            "do tipo Fairy. Ele\n"
            "troca o tipo de."),
        .descricion = COMPOUND_STRING(
            "Un disco con datos\n"
            "tipo Fairy. Cambia\n"
            "el tipo Silvally."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEMORY,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FAIRY,
        .flingPower = 50,
        .iconPic = gItemIcon_FairyMemory,
        .iconPalette = gItemIconPalette_FairyMemory,
    },

    [ITEM_RUSTED_SWORD] =
    {
        .name = ITEM_NAME("Rusted Sword"),
        .nombre = ITEM_NAME("Espada oxidada"),
        .price = 0,
        .description = COMPOUND_STRING(
            "A rusty sword. A\n"
            "hero used it to\n"
            "halt a disaster."),
        .descricao = COMPOUND_STRING(
            "Uma espada\n"
            "enferrujada. Um\n"
            "herói usou isso."),
        .descricion = COMPOUND_STRING(
            "Una espada oxidada.\n"
            "Un héroe lo utilizó\n"
            "para detener un."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SPECIAL_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_RustedSword,
        .iconPalette = gItemIconPalette_RustedWeapons,
    },

    [ITEM_RUSTED_SHIELD] =
    {
        .name = ITEM_NAME("Rusted Shield"),
        .nombre = ITEM_NAME("Escudo oxidado"),
        .price = 0,
        .description = COMPOUND_STRING(
            "A rusty shield. A\n"
            "hero used it to\n"
            "halt a disaster."),
        .descricao = COMPOUND_STRING(
            "Um escudo\n"
            "enferrujado. Um\n"
            "herói usou isso."),
        .descricion = COMPOUND_STRING(
            "Un escudo oxidado.\n"
            "Un héroe lo utilizó\n"
            "para detener un."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SPECIAL_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_RustedShield,
        .iconPalette = gItemIconPalette_RustedWeapons,
    },

// Colored Orbs

    [ITEM_RED_ORB] =
    {
        .name = ITEM_NAME("Red Orb"),
        .nombre = ITEM_NAME("Orbe rojo"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_PRIMAL_ORB,
        .description = COMPOUND_STRING(
            "A red, glowing orb\n"
            "said to contain an\n"
            "ancient power."),
        .descricao = COMPOUND_STRING(
            "Um orbe vermelho e\n"
            "brilhante\n"
            "supostamente."),
        .descricion = COMPOUND_STRING(
            "Un orbe rojo y\n"
            "brillante dice\n"
            "contiene un"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SPECIAL_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_RedOrb,
        .iconPalette = gItemIconPalette_RedOrb,
    },

    [ITEM_BLUE_ORB] =
    {
        .name = ITEM_NAME("Blue Orb"),
        .nombre = ITEM_NAME("Orbe azul"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_PRIMAL_ORB,
        .description = COMPOUND_STRING(
            "A blue, glowing orb\n"
            "said to contain an\n"
            "ancient power."),
        .descricao = COMPOUND_STRING(
            "Um orbe azul\n"
            "brilhante\n"
            "supostamente."),
        .descricion = COMPOUND_STRING(
            "Un orbe azul\n"
            "brillante dice\n"
            "contiene un"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SPECIAL_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_BlueOrb,
        .iconPalette = gItemIconPalette_BlueOrb,
    },

// Mega Stones

    [ITEM_VENUSAURITE] =
    {
        .name = ITEM_NAME("Venusaurite"),
        .nombre = ITEM_NAME("Venusaurita"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "This stone enables\n"
            "Venusaur to Mega\n"
            "Evolve in battle."),
        .descricao = COMPOUND_STRING(
            "Esta pedra permite\n"
            "que Venusaur\n"
            "megaevolua em."),
        .descricion = COMPOUND_STRING(
            "Esta piedra permite\n"
            "a Venusaur\n"
            "megaevolucionar en."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Venusaurite,
        .iconPalette = gItemIconPalette_Venusaurite,
    },

    [ITEM_CHARIZARDITE_X] =
    {
        .name = ITEM_NAME("Charizardite X"),
        .nombre = ITEM_NAME("Charizardita X"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = sCharizarditeDesc,
        .descricao = COMPOUND_STRING(
            "Esta pedra permite\n"
            "que Charizard\n"
            "megaevolua em."),
        .descricion = COMPOUND_STRING(
            "Esta piedra le\n"
            "permite a Charizard\n"
            "megaevolucionar en."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_CharizarditeX,
        .iconPalette = gItemIconPalette_CharizarditeX,
    },

    [ITEM_CHARIZARDITE_Y] =
    {
        .name = ITEM_NAME("Charizardite Y"),
        .nombre = ITEM_NAME("Charizardita Y"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = sCharizarditeDesc,
        .descricao = COMPOUND_STRING(
            "Esta pedra permite\n"
            "que Charizard\n"
            "megaevolua em."),
        .descricion = COMPOUND_STRING(
            "Esta piedra le\n"
            "permite a Charizard\n"
            "megaevolucionar en."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_CharizarditeY,
        .iconPalette = gItemIconPalette_CharizarditeY,
    },

    [ITEM_BLASTOISINITE] =
    {
        .name = ITEM_NAME("Blastoisinite"),
        .nombre = ITEM_NAME("Blastoisinita"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "This stone enables\n"
            "Blastoise to Mega\n"
            "Evolve in battle."),
        .descricao = COMPOUND_STRING(
            "Esta pedra permite\n"
            "que Blastoise\n"
            "megaevolua em."),
        .descricion = COMPOUND_STRING(
            "Esta piedra permite\n"
            "a Blastoise\n"
            "megaevolucionar en."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Blastoisinite,
        .iconPalette = gItemIconPalette_Blastoisinite,
    },

    [ITEM_BEEDRILLITE] =
    {
        .name = ITEM_NAME("Beedrillite"),
        .nombre = ITEM_NAME("beedrillita"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "This stone enables\n"
            "Beedrill to Mega\n"
            "Evolve in battle."),
        .descricao = COMPOUND_STRING(
            "Esta pedra permite\n"
            "que Beedrill\n"
            "megaevolua em."),
        .descricion = COMPOUND_STRING(
            "Esta piedra permite\n"
            "a Beedrill\n"
            "megaevolucionar en."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Beedrillite,
        .iconPalette = gItemIconPalette_Beedrillite,
    },

    [ITEM_PIDGEOTITE] =
    {
        .name = ITEM_NAME("Pidgeotite"),
        .nombre = ITEM_NAME("Pidgeotita"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "This stone enables\n"
            "Pidgeot to Mega\n"
            "Evolve in battle."),
        .descricao = COMPOUND_STRING(
            "Esta pedra permite\n"
            "que Pidgeot\n"
            "megaevolua em."),
        .descricion = COMPOUND_STRING(
            "Esta piedra permite\n"
            "a Pidgeot\n"
            "megaevolucionar en."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Pidgeotite,
        .iconPalette = gItemIconPalette_Pidgeotite,
    },

    [ITEM_ALAKAZITE] =
    {
        .name = ITEM_NAME("Alakazite"),
        .nombre = ITEM_NAME("Alakazita"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "This stone enables\n"
            "Alakazam to Mega\n"
            "Evolve in battle."),
        .descricao = COMPOUND_STRING(
            "Esta pedra permite\n"
            "que Alakazam\n"
            "megaevolua em."),
        .descricion = COMPOUND_STRING(
            "Esta piedra le\n"
            "permite a Alakazam\n"
            "megaevolucionar en."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Alakazite,
        .iconPalette = gItemIconPalette_Alakazite,
    },

    [ITEM_SLOWBRONITE] =
    {
        .name = ITEM_NAME("Slowbronite"),
        .nombre = ITEM_NAME("Bronita lenta"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "This stone enables\n"
            "Slowbro to Mega\n"
            "Evolve in battle."),
        .descricao = COMPOUND_STRING(
            "Esta pedra permite\n"
            "que Slowbro\n"
            "megaevolua na."),
        .descricion = COMPOUND_STRING(
            "Esta piedra permite\n"
            "a Slowbro\n"
            "megaevolucionar en."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Slowbronite,
        .iconPalette = gItemIconPalette_Slowbronite,
    },

    [ITEM_GENGARITE] =
    {
        .name = ITEM_NAME("Gengarite"),
        .nombre = ITEM_NAME("Gengarita"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "This stone enables\n"
            "Gengar to Mega\n"
            "Evolve in battle."),
        .descricao = COMPOUND_STRING(
            "Esta pedra permite\n"
            "que Gengar\n"
            "megaevolua em."),
        .descricion = COMPOUND_STRING(
            "Esta piedra le\n"
            "permite a Gengar\n"
            "megaevolucionar en."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Gengarite,
        .iconPalette = gItemIconPalette_Gengarite,
    },

    [ITEM_KANGASKHANITE] =
    {
        .name = ITEM_NAME("Kangaskhanite"),
        .nombre = ITEM_NAME("Kangaskhanita"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "This stone enables\n"
            "Kangaskhan to Mega\n"
            "Evolve in battle."),
        .descricao = COMPOUND_STRING(
            "Esta pedra permite\n"
            "que Kangaskhan\n"
            "megaevolua em."),
        .descricion = COMPOUND_STRING(
            "Esta piedra permite\n"
            "a Kangaskhan\n"
            "megaevolucionar en."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Kangaskhanite,
        .iconPalette = gItemIconPalette_Kangaskhanite,
    },

    [ITEM_PINSIRITE] =
    {
        .name = ITEM_NAME("Pinsirite"),
        .nombre = ITEM_NAME("pinsirita"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "This stone enables\n"
            "Pinsir to Mega\n"
            "Evolve in battle."),
        .descricao = COMPOUND_STRING(
            "Esta pedra permite\n"
            "que Pinsir\n"
            "megaevolua em."),
        .descricion = COMPOUND_STRING(
            "Esta piedra le\n"
            "permite a Pinsir\n"
            "megaevolucionar en."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Pinsirite,
        .iconPalette = gItemIconPalette_Pinsirite,
    },

    [ITEM_GYARADOSITE] =
    {
        .name = ITEM_NAME("Gyaradosite"),
        .nombre = ITEM_NAME("Gyaradosita"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "This stone enables\n"
            "Gyarados to Mega\n"
            "Evolve in battle."),
        .descricao = COMPOUND_STRING(
            "Esta pedra permite\n"
            "que Gyarados\n"
            "megaevolua em."),
        .descricion = COMPOUND_STRING(
            "Esta piedra permite\n"
            "a Gyarados\n"
            "megaevolucionar en."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Gyaradosite,
        .iconPalette = gItemIconPalette_Gyaradosite,
    },

    [ITEM_AERODACTYLITE] =
    {
        .name = ITEM_NAME("Aerodactylite"),
        .nombre = ITEM_NAME("aerodactilita"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "This stone enables\n"
            "Aerodactyl to Mega\n"
            "Evolve in battle."),
        .descricao = COMPOUND_STRING(
            "Esta pedra permite\n"
            "que Aerodactyl\n"
            "megaevolua em."),
        .descricion = COMPOUND_STRING(
            "Esta piedra permite\n"
            "a Aerodactyl\n"
            "megaevolucionar en."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Aerodactylite,
        .iconPalette = gItemIconPalette_Aerodactylite,
    },

    [ITEM_MEWTWONITE_X] =
    {
        .name = ITEM_NAME("Mewtwonite X"),
        .nombre = ITEM_NAME("Mewtwonita X"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = sMewtwoniteDesc,
        .descricao = COMPOUND_STRING(
            "Esta pedra permite\n"
            "que Mewtwo\n"
            "megaevolua em."),
        .descricion = COMPOUND_STRING(
            "Esta piedra permite\n"
            "a Mewtwo\n"
            "megaevolucionar en."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_MewtwoniteX,
        .iconPalette = gItemIconPalette_MewtwoniteX,
    },

    [ITEM_MEWTWONITE_Y] =
    {
        .name = ITEM_NAME("Mewtwonite Y"),
        .nombre = ITEM_NAME("Mewtwonita Y"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = sMewtwoniteDesc,
        .descricao = COMPOUND_STRING(
            "Esta pedra permite\n"
            "que Mewtwo\n"
            "megaevolua em."),
        .descricion = COMPOUND_STRING(
            "Esta piedra permite\n"
            "a Mewtwo\n"
            "megaevolucionar en."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_MewtwoniteY,
        .iconPalette = gItemIconPalette_MewtwoniteY,
    },

    [ITEM_AMPHAROSITE] =
    {
        .name = ITEM_NAME("Ampharosite"),
        .nombre = ITEM_NAME("anfarosita"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "This stone enables\n"
            "Ampharos to Mega\n"
            "Evolve in battle."),
        .descricao = COMPOUND_STRING(
            "Esta pedra permite\n"
            "que Ampharos\n"
            "megaevolua em."),
        .descricion = COMPOUND_STRING(
            "Esta piedra permite\n"
            "a Ampharos\n"
            "megaevolucionar en."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Ampharosite,
        .iconPalette = gItemIconPalette_Ampharosite,
    },

    [ITEM_STEELIXITE] =
    {
        .name = ITEM_NAME("Steelixite"),
        .nombre = ITEM_NAME("Steelixita"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "This stone enables\n"
            "Steelix to Mega\n"
            "Evolve in battle."),
        .descricao = COMPOUND_STRING(
            "Esta pedra permite\n"
            "que Steelix\n"
            "megaevolua em."),
        .descricion = COMPOUND_STRING(
            "Esta piedra permite\n"
            "a Steelix\n"
            "megaevolucionar en."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Steelixite,
        .iconPalette = gItemIconPalette_Steelixite,
    },

    [ITEM_SCIZORITE] =
    {
        .name = ITEM_NAME("Scizorite"),
        .nombre = ITEM_NAME("scizorita"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "This stone enables\n"
            "Scizor to Mega\n"
            "Evolve in battle."),
        .descricao = COMPOUND_STRING(
            "Esta pedra permite\n"
            "que Scizor\n"
            "megaevolua em."),
        .descricion = COMPOUND_STRING(
            "Esta piedra le\n"
            "permite a Scizor\n"
            "megaevolucionar en."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Scizorite,
        .iconPalette = gItemIconPalette_Scizorite,
    },

    [ITEM_HERACRONITE] =
    {
        .name = ITEM_NAME("Heracronite"),
        .nombre = ITEM_NAME("Heracronita"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "This stone enables\n"
            "Heracross to Mega\n"
            "Evolve in battle."),
        .descricao = COMPOUND_STRING(
            "Esta pedra permite\n"
            "que Heracross\n"
            "megaevolua em."),
        .descricion = COMPOUND_STRING(
            "Esta piedra permite\n"
            "a Heracross\n"
            "megaevolucionar en."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Heracronite,
        .iconPalette = gItemIconPalette_Heracronite,
    },

    [ITEM_HOUNDOOMINITE] =
    {
        .name = ITEM_NAME("Houndoominite"),
        .nombre = ITEM_NAME("Houndoominita"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "This stone enables\n"
            "Houndoom to Mega\n"
            "Evolve in battle."),
        .descricao = COMPOUND_STRING(
            "Esta pedra permite\n"
            "que Houndoom\n"
            "megaevolua em."),
        .descricion = COMPOUND_STRING(
            "Esta piedra permite\n"
            "a Houndoom\n"
            "megaevolucionar en."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Houndoominite,
        .iconPalette = gItemIconPalette_Houndoominite,
    },

    [ITEM_TYRANITARITE] =
    {
        .name = ITEM_NAME("Tyranitarite"),
        .nombre = ITEM_NAME("tiranitarita"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "This stone enables\n"
            "Tyranitar to Mega\n"
            "Evolve in battle."),
        .descricao = COMPOUND_STRING(
            "Esta pedra permite\n"
            "que Tyranitar\n"
            "megaevolua em."),
        .descricion = COMPOUND_STRING(
            "Esta piedra permite\n"
            "a Tyranitar\n"
            "megaevolucionar en."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Tyranitarite,
        .iconPalette = gItemIconPalette_Tyranitarite,
    },

    [ITEM_SCEPTILITE] =
    {
        .name = ITEM_NAME("Sceptilite"),
        .nombre = ITEM_NAME("esceptilita"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "This stone enables\n"
            "Sceptile to Mega\n"
            "Evolve in battle."),
        .descricao = COMPOUND_STRING(
            "Esta pedra permite\n"
            "que Sceptile\n"
            "megaevolua em."),
        .descricion = COMPOUND_STRING(
            "Esta piedra permite\n"
            "a Sceptile\n"
            "megaevolucionar en."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Sceptilite,
        .iconPalette = gItemIconPalette_Sceptilite,
    },

    [ITEM_BLAZIKENITE] =
    {
        .name = ITEM_NAME("Blazikenite"),
        .nombre = ITEM_NAME("Blazikenita"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "This stone enables\n"
            "Blaziken to Mega\n"
            "Evolve in battle."),
        .descricao = COMPOUND_STRING(
            "Esta pedra permite\n"
            "que Blaziken\n"
            "megaevolua em."),
        .descricion = COMPOUND_STRING(
            "Esta piedra permite\n"
            "a Blaziken\n"
            "megaevolucionar en."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Blazikenite,
        .iconPalette = gItemIconPalette_Blazikenite,
    },

    [ITEM_SWAMPERTITE] =
    {
        .name = ITEM_NAME("Swampertite"),
        .nombre = ITEM_NAME("Swampertita"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "This stone enables\n"
            "Swampert to Mega\n"
            "Evolve in battle."),
        .descricao = COMPOUND_STRING(
            "Esta pedra permite\n"
            "que Swampert\n"
            "megaevolua em."),
        .descricion = COMPOUND_STRING(
            "Esta piedra permite\n"
            "a Swampert\n"
            "megaevolucionar en."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Swampertite,
        .iconPalette = gItemIconPalette_Swampertite,
    },

    [ITEM_GARDEVOIRITE] =
    {
        .name = ITEM_NAME("Gardevoirite"),
        .nombre = ITEM_NAME("Gardevoirita"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "This stone enables\n"
            "Gardevoir to Mega\n"
            "Evolve in battle."),
        .descricao = COMPOUND_STRING(
            "Esta pedra permite\n"
            "que Gardevoir\n"
            "megaevolua em."),
        .descricion = COMPOUND_STRING(
            "Esta piedra permite\n"
            "a Gardevoir\n"
            "megaevolucionar en."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Gardevoirite,
        .iconPalette = gItemIconPalette_Gardevoirite,
    },

    [ITEM_SABLENITE] =
    {
        .name = ITEM_NAME("Sablenite"),
        .nombre = ITEM_NAME("Sablenita"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "This stone enables\n"
            "Sableye to Mega\n"
            "Evolve in battle."),
        .descricao = COMPOUND_STRING(
            "Esta pedra permite\n"
            "que Sableye\n"
            "megaevolua em."),
        .descricion = COMPOUND_STRING(
            "Esta piedra le\n"
            "permite a Sableye\n"
            "megaevolucionar en."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Sablenite,
        .iconPalette = gItemIconPalette_Sablenite,
    },

    [ITEM_MAWILITE] =
    {
        .name = ITEM_NAME("Mawilite"),
        .nombre = ITEM_NAME("mawilita"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "This stone enables\n"
            "Mawile to Mega\n"
            "Evolve in battle."),
        .descricao = COMPOUND_STRING(
            "Esta pedra permite\n"
            "que Mawile\n"
            "megaevolua em."),
        .descricion = COMPOUND_STRING(
            "Esta piedra le\n"
            "permite a Mawile\n"
            "megaevolucionar en."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Mawilite,
        .iconPalette = gItemIconPalette_Mawilite,
    },

    [ITEM_AGGRONITE] =
    {
        .name = ITEM_NAME("Aggronite"),
        .nombre = ITEM_NAME("agronita"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "This stone enables\n"
            "Aggron to Mega\n"
            "Evolve in battle."),
        .descricao = COMPOUND_STRING(
            "Esta pedra permite\n"
            "que Aggron\n"
            "megaevolua em."),
        .descricion = COMPOUND_STRING(
            "Esta piedra le\n"
            "permite a Aggron\n"
            "megaevolucionar en."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Aggronite,
        .iconPalette = gItemIconPalette_Aggronite,
    },

    [ITEM_MEDICHAMITE] =
    {
        .name = ITEM_NAME("Medichamite"),
        .nombre = ITEM_NAME("Medichamita"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "This stone enables\n"
            "Medicham to Mega\n"
            "Evolve in battle."),
        .descricao = COMPOUND_STRING(
            "Esta pedra permite\n"
            "que Medicham\n"
            "megaevolua em."),
        .descricion = COMPOUND_STRING(
            "Esta piedra permite\n"
            "a Medicham\n"
            "megaevolucionar en."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Medichamite,
        .iconPalette = gItemIconPalette_Medichamite,
    },

    [ITEM_MANECTITE] =
    {
        .name = ITEM_NAME("Manectite"),
        .nombre = ITEM_NAME("manectita"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "This stone enables\n"
            "Manectric to Mega\n"
            "Evolve in battle."),
        .descricao = COMPOUND_STRING(
            "Esta pedra permite\n"
            "que Manectric\n"
            "megaevolua em."),
        .descricion = COMPOUND_STRING(
            "Esta piedra permite\n"
            "a Manectric\n"
            "megaevolucionar en."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Manectite,
        .iconPalette = gItemIconPalette_Manectite,
    },

    [ITEM_SHARPEDONITE] =
    {
        .name = ITEM_NAME("Sharpedonite"),
        .nombre = ITEM_NAME("Sharpedonita"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "This stone enables\n"
            "Sharpedo to Mega\n"
            "Evolve in battle."),
        .descricao = COMPOUND_STRING(
            "Esta pedra permite\n"
            "que Sharpedo\n"
            "megaevolua em."),
        .descricion = COMPOUND_STRING(
            "Esta piedra le\n"
            "permite a Sharpedo\n"
            "megaevolucionar en."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Sharpedonite,
        .iconPalette = gItemIconPalette_Sharpedonite,
    },

    [ITEM_CAMERUPTITE] =
    {
        .name = ITEM_NAME("Cameruptite"),
        .nombre = ITEM_NAME("cameruptita"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "This stone enables\n"
            "Camerupt to Mega\n"
            "Evolve in battle."),
        .descricao = COMPOUND_STRING(
            "Esta pedra permite\n"
            "que Camerupt\n"
            "megaevolua em."),
        .descricion = COMPOUND_STRING(
            "Esta piedra permite\n"
            "a Camerupt\n"
            "megaevolucionar en."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Cameruptite,
        .iconPalette = gItemIconPalette_Cameruptite,
    },

    [ITEM_ALTARIANITE] =
    {
        .name = ITEM_NAME("Altarianite"),
        .nombre = ITEM_NAME("altarianita"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "This stone enables\n"
            "Altaria to Mega\n"
            "Evolve in battle."),
        .descricao = COMPOUND_STRING(
            "Esta pedra permite\n"
            "que Altaria\n"
            "megaevolua em."),
        .descricion = COMPOUND_STRING(
            "Esta piedra le\n"
            "permite a Altaria\n"
            "megaevolucionar en."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Altarianite,
        .iconPalette = gItemIconPalette_Altarianite,
    },

    [ITEM_BANETTITE] =
    {
        .name = ITEM_NAME("Banettite"),
        .nombre = ITEM_NAME("banettita"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "This stone enables\n"
            "Banette to Mega\n"
            "Evolve in battle."),
        .descricao = COMPOUND_STRING(
            "Esta pedra permite\n"
            "que Banette\n"
            "megaevolua em."),
        .descricion = COMPOUND_STRING(
            "Esta piedra permite\n"
            "a Banette\n"
            "megaevolucionar en."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Banettite,
        .iconPalette = gItemIconPalette_Banettite,
    },

    [ITEM_ABSOLITE] =
    {
        .name = ITEM_NAME("Absolite"),
        .nombre = ITEM_NAME("absoluto"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = sAbsoliteDesc,
        .descricao = COMPOUND_STRING(
            "Esta pedra permite\n"
            "que Absol\n"
            "megaevolua na luta."),
        .descricion = COMPOUND_STRING(
            "Esta piedra le\n"
            "permite a Absol\n"
            "megaevolucionar en."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Absolite,
        .iconPalette = gItemIconPalette_Absolite,
    },

    [ITEM_GLALITITE] =
    {
        .name = ITEM_NAME("Glalitite"),
        .nombre = ITEM_NAME("Glalitita"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "This stone enables\n"
            "Glalie to Mega\n"
            "Evolve in battle."),
        .descricao = COMPOUND_STRING(
            "Esta pedra permite\n"
            "que Glalie\n"
            "megaevolua em."),
        .descricion = COMPOUND_STRING(
            "Esta piedra le\n"
            "permite a Glalie\n"
            "megaevolucionar en."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Glalitite,
        .iconPalette = gItemIconPalette_Glalitite,
    },

    [ITEM_SALAMENCITE] =
    {
        .name = ITEM_NAME("Salamencite"),
        .nombre = ITEM_NAME("salamencita"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "This stone enables\n"
            "Salamence to Mega\n"
            "Evolve in battle."),
        .descricao = COMPOUND_STRING(
            "Esta pedra permite\n"
            "que Salamence\n"
            "megaevolua em."),
        .descricion = COMPOUND_STRING(
            "Esta piedra permite\n"
            "a Salamence\n"
            "megaevolucionar en."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Salamencite,
        .iconPalette = gItemIconPalette_Salamencite,
    },

    [ITEM_METAGROSSITE] =
    {
        .name = ITEM_NAME("Metagrossite"),
        .nombre = ITEM_NAME("metagrosita"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "This stone enables\n"
            "Metagross to Mega\n"
            "Evolve in battle."),
        .descricao = COMPOUND_STRING(
            "Esta pedra permite\n"
            "que Metagross\n"
            "megaevolua em."),
        .descricion = COMPOUND_STRING(
            "Esta piedra permite\n"
            "a Metagross\n"
            "megaevolucionar en."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Metagrossite,
        .iconPalette = gItemIconPalette_Metagrossite,
    },

    [ITEM_LATIASITE] =
    {
        .name = ITEM_NAME("Latiasite"),
        .nombre = ITEM_NAME("Latiasita"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "This stone enables\n"
            "Latias to Mega\n"
            "Evolve in battle."),
        .descricao = COMPOUND_STRING(
            "Esta pedra permite\n"
            "que Latias\n"
            "megaevolua em."),
        .descricion = COMPOUND_STRING(
            "Esta piedra le\n"
            "permite a Latias\n"
            "megaevolucionar en."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Latiasite,
        .iconPalette = gItemIconPalette_Latiasite,
    },

    [ITEM_LATIOSITE] =
    {
        .name = ITEM_NAME("Latiosite"),
        .nombre = ITEM_NAME("latiosita"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "This stone enables\n"
            "Latios to Mega\n"
            "Evolve in battle."),
        .descricao = COMPOUND_STRING(
            "Esta pedra permite\n"
            "que Latios\n"
            "megaevolua na."),
        .descricion = COMPOUND_STRING(
            "Esta piedra permite\n"
            "a Latios\n"
            "megaevolucionar en."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Latiosite,
        .iconPalette = gItemIconPalette_Latiosite,
    },

    [ITEM_LOPUNNITE] =
    {
        .name = ITEM_NAME("Lopunnite"),
        .nombre = ITEM_NAME("Lopunnita"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "This stone enables\n"
            "Lopunny to Mega\n"
            "Evolve in battle."),
        .descricao = COMPOUND_STRING(
            "Esta pedra permite\n"
            "que Lopunny\n"
            "megaevolua em."),
        .descricion = COMPOUND_STRING(
            "Esta piedra le\n"
            "permite a Lopunny\n"
            "megaevolucionar en."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Lopunnite,
        .iconPalette = gItemIconPalette_Lopunnite,
    },

    [ITEM_GARCHOMPITE] =
    {
        .name = ITEM_NAME("Garchompite"),
        .nombre = ITEM_NAME("Garchompita"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = sGarchompiteDesc,
        .descricao = COMPOUND_STRING(
            "Esta pedra permite\n"
            "que Garchomp\n"
            "megaevolua na."),
        .descricion = COMPOUND_STRING(
            "Esta piedra le\n"
            "permite a Garchomp\n"
            "megaevolucionar en."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Garchompite,
        .iconPalette = gItemIconPalette_Garchompite,
    },

    [ITEM_LUCARIONITE] =
    {
        .name = ITEM_NAME("Lucarionite"),
        .nombre = ITEM_NAME("lucarionita"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = sLucarioniteDesc,
        .descricao = COMPOUND_STRING(
            "Esta pedra permite\n"
            "que Lucario\n"
            "megaevolua em."),
        .descricion = COMPOUND_STRING(
            "Esta piedra le\n"
            "permite a Lucario\n"
            "megaevolucionar en."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Lucarionite,
        .iconPalette = gItemIconPalette_Lucarionite,
    },

    [ITEM_ABOMASITE] =
    {
        .name = ITEM_NAME("Abomasite"),
        .nombre = ITEM_NAME("abomasita"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "This stone enables\n"
            "Abomasnow to Mega\n"
            "Evolve in battle."),
        .descricao = COMPOUND_STRING(
            "Esta pedra permite\n"
            "que Abomasnow\n"
            "megaevolua em."),
        .descricion = COMPOUND_STRING(
            "Esta piedra le\n"
            "permite a Abomasnow\n"
            "megaevolucionar en."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Abomasite,
        .iconPalette = gItemIconPalette_Abomasite,
    },

    [ITEM_GALLADITE] =
    {
        .name = ITEM_NAME("Galladite"),
        .nombre = ITEM_NAME("galadita"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "This stone enables\n"
            "Gallade to Mega\n"
            "Evolve in battle."),
        .descricao = COMPOUND_STRING(
            "Esta pedra permite\n"
            "que Gallade\n"
            "megaevolua em."),
        .descricion = COMPOUND_STRING(
            "Esta piedra permite\n"
            "a Gallade\n"
            "megaevolucionar en."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Galladite,
        .iconPalette = gItemIconPalette_Galladite,
    },

    [ITEM_AUDINITE] =
    {
        .name = ITEM_NAME("Audinite"),
        .nombre = ITEM_NAME("Audinita"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "This stone enables\n"
            "Audino to Mega\n"
            "Evolve in battle."),
        .descricao = COMPOUND_STRING(
            "Esta pedra permite\n"
            "que Audino\n"
            "megaevolua em."),
        .descricion = COMPOUND_STRING(
            "Esta piedra le\n"
            "permite a Audino\n"
            "megaevolucionar en."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Audinite,
        .iconPalette = gItemIconPalette_Audinite,
    },

    [ITEM_DIANCITE] =
    {
        .name = ITEM_NAME("Diancite"),
        .nombre = ITEM_NAME("diancita"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "This stone enables\n"
            "Diancie to Mega\n"
            "Evolve in battle."),
        .descricao = COMPOUND_STRING(
            "Esta pedra permite\n"
            "que Diancie\n"
            "Megaevolua em."),
        .descricion = COMPOUND_STRING(
            "Esta piedra le\n"
            "permite a Diancie\n"
            "megaevolucionar en."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Diancite,
        .iconPalette = gItemIconPalette_Diancite,
    },

    [ITEM_CLEFABLITE] =
    {
        .name = ITEM_NAME("Clefablite"),
        .nombre = ITEM_NAME("Clefablita"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "This stone enables\n"
            "Clefable to Mega\n"
            "Evolve in battle."),
        .descricao = COMPOUND_STRING(
            "Esta pedra permite\n"
            "que Clefable\n"
            "megaevolua em."),
        .descricion = COMPOUND_STRING(
            "Esta piedra le\n"
            "permite a Clefable\n"
            "megaevolucionar en."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Clefablite,
        .iconPalette = gItemIconPalette_Clefablite,
    },

    [ITEM_VICTREEBELITE] =
    {
        .name = ITEM_NAME("Victreebelite"),
        .nombre = ITEM_NAME("Victreebelita"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "This stone enables\n"
            "Victreebel to Mega\n"
            "Evolve in battle."),
        .descricao = COMPOUND_STRING(
            "Esta pedra permite\n"
            "que Victreebel\n"
            "megaevolua em."),
        .descricion = COMPOUND_STRING(
            "Esta piedra permite\n"
            "a Victreebel\n"
            "megaevolucionar en."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Victreebelite,
        .iconPalette = gItemIconPalette_Victreebelite,
    },

    [ITEM_STARMINITE] =
    {
        .name = ITEM_NAME("Starminite"),
        .nombre = ITEM_NAME("Starminita"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "This stone enables\n"
            "Starmie to Mega\n"
            "Evolve in battle."),
        .descricao = COMPOUND_STRING(
            "Esta pedra permite\n"
            "que Starmie\n"
            "megaevolua em."),
        .descricion = COMPOUND_STRING(
            "Esta piedra le\n"
            "permite a Starmie\n"
            "megaevolucionar en."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Starminite,
        .iconPalette = gItemIconPalette_Starminite,
    },

    [ITEM_DRAGONINITE] =
    {
        .name = ITEM_NAME("Dragoninite"),
        .nombre = ITEM_NAME("Dragoninita"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "This stone enables\n"
            "Dragonite to Mega\n"
            "Evolve in battle."),
        .descricao = COMPOUND_STRING(
            "Esta pedra permite\n"
            "que Dragonite\n"
            "megaevolua em."),
        .descricion = COMPOUND_STRING(
            "Esta piedra permite\n"
            "a Dragonite\n"
            "megaevolucionar en."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Dragoninite,
        .iconPalette = gItemIconPalette_Dragoninite,
    },

    [ITEM_MEGANIUMITE] =
    {
        .name = ITEM_NAME("Meganiumite"),
        .nombre = ITEM_NAME("meganiumita"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "This stone enables\n"
            "Meganium to Mega\n"
            "Evolve in battle."),
        .descricao = COMPOUND_STRING(
            "Esta pedra permite\n"
            "que Meganium\n"
            "megaevolua em."),
        .descricion = COMPOUND_STRING(
            "Esta piedra permite\n"
            "a Meganium\n"
            "megaevolucionar en."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Meganiumite,
        .iconPalette = gItemIconPalette_Meganiumite,
    },

    [ITEM_FERALIGITE] =
    {
        .name = ITEM_NAME("Feraligite"),
        .nombre = ITEM_NAME("feraligita"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "This stone enables\n"
            "Feraligatr to Mega\n"
            "Evolve in battle."),
        .descricao = COMPOUND_STRING(
            "Esta pedra permite\n"
            "que Feraligatr\n"
            "megaevolua em."),
        .descricion = COMPOUND_STRING(
            "Esta piedra permite\n"
            "a Feraligatr\n"
            "megaevolucionar en."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Feraligite,
        .iconPalette = gItemIconPalette_Feraligite,
    },

    [ITEM_SKARMORITE] =
    {
        .name = ITEM_NAME("Skarmorite"),
        .nombre = ITEM_NAME("Skamorita"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "This stone enables\n"
            "Skarmory to Mega\n"
            "Evolve in battle."),
        .descricao = COMPOUND_STRING(
            "Esta pedra permite\n"
            "que Skarmory\n"
            "megaevolua em."),
        .descricion = COMPOUND_STRING(
            "Esta piedra permite\n"
            "a Skarmory\n"
            "megaevolucionar en."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Skarmorite,
        .iconPalette = gItemIconPalette_Skarmorite,
    },

    [ITEM_FROSLASSITE] =
    {
        .name = ITEM_NAME("Froslassite"),
        .nombre = ITEM_NAME("froslassita"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "This stone enables\n"
            "Froslass to Mega\n"
            "Evolve in battle."),
        .descricao = COMPOUND_STRING(
            "Esta pedra permite\n"
            "que Froslass\n"
            "megaevolua em."),
        .descricion = COMPOUND_STRING(
            "Esta piedra permite\n"
            "a Froslass\n"
            "megaevolucionar en."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Froslassite,
        .iconPalette = gItemIconPalette_Froslassite,
    },

    [ITEM_EMBOARITE] =
    {
        .name = ITEM_NAME("Emboarite"),
        .nombre = ITEM_NAME("Emboarita"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "This stone enables\n"
            "Emboar to Mega\n"
            "Evolve in battle."),
        .descricao = COMPOUND_STRING(
            "Esta pedra permite\n"
            "que Emboar\n"
            "megaevolua em."),
        .descricion = COMPOUND_STRING(
            "Esta piedra permite\n"
            "a Emboar\n"
            "megaevolucionar en."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Emboarite,
        .iconPalette = gItemIconPalette_Emboarite,
    },

    [ITEM_EXCADRITE] =
    {
        .name = ITEM_NAME("Excadrite"),
        .nombre = ITEM_NAME("excadrita"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "This stone enables\n"
            "Excadrill to Mega\n"
            "Evolve in battle."),
        .descricao = COMPOUND_STRING(
            "Esta pedra permite\n"
            "que Excadrill\n"
            "megaevolua em."),
        .descricion = COMPOUND_STRING(
            "Esta piedra permite\n"
            "a Excadrill\n"
            "megaevolucionar en."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Excadrite,
        .iconPalette = gItemIconPalette_Excadrite,
    },

    [ITEM_SCOLIPITE] =
    {
        .name = ITEM_NAME("Scolipite"),
        .nombre = ITEM_NAME("escolipita"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "This stone enables\n"
            "Scolipede to Mega\n"
            "Evolve in battle."),
        .descricao = COMPOUND_STRING(
            "Esta pedra permite\n"
            "que Scolipede\n"
            "megaevolua em."),
        .descricion = COMPOUND_STRING(
            "Esta piedra permite\n"
            "a Scolipede\n"
            "megaevolucionar en."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Scolipite,
        .iconPalette = gItemIconPalette_Scolipite,
    },

    [ITEM_SCRAFTINITE] =
    {
        .name = ITEM_NAME("Scraftinite"),
        .nombre = ITEM_NAME("Craftinita"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "This stone enables\n"
            "Scrafty to Mega\n"
            "Evolve in battle."),
        .descricao = COMPOUND_STRING(
            "Esta pedra permite\n"
            "que Scrafty\n"
            "megaevolua em."),
        .descricion = COMPOUND_STRING(
            "Esta piedra permite\n"
            "a Scrafty\n"
            "megaevolucionar en."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Scraftinite,
        .iconPalette = gItemIconPalette_Scraftinite,
    },

    [ITEM_EELEKTROSSITE] =
    {
        .name = ITEM_NAME("Eelektrossite"),
        .nombre = ITEM_NAME("Eelektrosita"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "This stone enables\n"
            "Eelektross to Mega\n"
            "Evolve in battle."),
        .descricao = COMPOUND_STRING(
            "Esta pedra permite\n"
            "que Eelektross\n"
            "megaevolua em."),
        .descricion = COMPOUND_STRING(
            "Esta piedra permite\n"
            "a Eelektross\n"
            "megaevolucionar en."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Eelektrossite,
        .iconPalette = gItemIconPalette_Eelektrossite,
    },

    [ITEM_CHANDELURITE] =
    {
        .name = ITEM_NAME("Chandelurite"),
        .nombre = ITEM_NAME("candelurita"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "This stone enables\n"
            "Chandelure to Mega\n"
            "Evolve in battle."),
        .descricao = COMPOUND_STRING(
            "Esta pedra permite\n"
            "que Chandelure\n"
            "Megaevolua em."),
        .descricion = COMPOUND_STRING(
            "Esta piedra le\n"
            "permite Chandelure\n"
            "megaevolucionar en."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Chandelurite,
        .iconPalette = gItemIconPalette_Chandelurite,
    },

    [ITEM_CHESNAUGHTITE] =
    {
        .name = ITEM_NAME("Chesnaughtite"),
        .nombre = ITEM_NAME("chesnaughtita"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "This stone enables\n"
            "Chesnaught to Mega\n"
            "Evolve in battle."),
        .descricao = COMPOUND_STRING(
            "Esta pedra permite\n"
            "que Chesnaught\n"
            "megaevolua em."),
        .descricion = COMPOUND_STRING(
            "Esta piedra le\n"
            "permite Chesnaught\n"
            "megaevolucionar en."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Chesnaughtite,
        .iconPalette = gItemIconPalette_Chesnaughtite,
    },

    [ITEM_DELPHOXITE] =
    {
        .name = ITEM_NAME("Delphoxite"),
        .nombre = ITEM_NAME("Delfoxita"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "This stone enables\n"
            "Delphox to Mega\n"
            "Evolve in battle."),
        .descricao = COMPOUND_STRING(
            "Esta pedra permite\n"
            "que Delphox\n"
            "megaevolua em."),
        .descricion = COMPOUND_STRING(
            "Esta piedra permite\n"
            "a Delphox\n"
            "megaevolucionar en."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Delphoxite,
        .iconPalette = gItemIconPalette_Delphoxite,
    },

    [ITEM_GRENINJITE] =
    {
        .name = ITEM_NAME("Greninjite"),
        .nombre = ITEM_NAME("Greninjita"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "This stone enables\n"
            "Greninja to Mega\n"
            "Evolve in battle."),
        .descricao = COMPOUND_STRING(
            "Esta pedra permite\n"
            "que Greninja\n"
            "megaevolua em."),
        .descricion = COMPOUND_STRING(
            "Esta piedra permite\n"
            "a Greninja\n"
            "megaevolucionar en."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Greninjite,
        .iconPalette = gItemIconPalette_Greninjite,
    },

    [ITEM_PYROARITE] =
    {
        .name = ITEM_NAME("Pyroarite"),
        .nombre = ITEM_NAME("piroarita"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "This stone enables\n"
            "Pyroar to Mega\n"
            "Evolve in battle."),
        .descricao = COMPOUND_STRING(
            "Esta pedra permite\n"
            "que Pyroar\n"
            "megaevolua em."),
        .descricion = COMPOUND_STRING(
            "Esta piedra permite\n"
            "a Pyroar\n"
            "megaevolucionar en."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Pyroarite,
        .iconPalette = gItemIconPalette_Pyroarite,
    },

    [ITEM_FLOETTITE] =
    {
        .name = ITEM_NAME("Floettite"),
        .nombre = ITEM_NAME("floettita"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "This stone enables\n"
            "Floette to Mega\n"
            "Evolve in battle."),
        .descricao = COMPOUND_STRING(
            "Esta pedra permite\n"
            "que Floette\n"
            "megaevolua na."),
        .descricion = COMPOUND_STRING(
            "Esta piedra permite\n"
            "a Floette\n"
            "megaevolucionar en."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Floettite,
        .iconPalette = gItemIconPalette_Floettite,
    },

    [ITEM_MALAMARITE] =
    {
        .name = ITEM_NAME("Malamarite"),
        .nombre = ITEM_NAME("malamarita"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "This stone enables\n"
            "Malamar to Mega\n"
            "Evolve in battle."),
        .descricao = COMPOUND_STRING(
            "Esta pedra permite\n"
            "que Malamar\n"
            "megaevolua em."),
        .descricion = COMPOUND_STRING(
            "Esta piedra permite\n"
            "a Malamar\n"
            "megaevolucionar en."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Malamarite,
        .iconPalette = gItemIconPalette_Malamarite,
    },

    [ITEM_BARBARACITE] =
    {
        .name = ITEM_NAME("Barbaracite"),
        .nombre = ITEM_NAME("barbarcita"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "This stone enables\n"
            "Barbaracle to Mega\n"
            "Evolve in battle."),
        .descricao = COMPOUND_STRING(
            "Esta pedra permite\n"
            "que Barbaracle\n"
            "megaevolua em."),
        .descricion = COMPOUND_STRING(
            "Esta piedra permite\n"
            "a Barbaracle\n"
            "megaevolucionar en."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Barbaracite,
        .iconPalette = gItemIconPalette_Barbaracite,
    },

    [ITEM_DRAGALGITE] =
    {
        .name = ITEM_NAME("Dragalgite"),
        .nombre = ITEM_NAME("dragalgita"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "This stone enables\n"
            "Dragalge to Mega\n"
            "Evolve in battle."),
        .descricao = COMPOUND_STRING(
            "Esta pedra permite\n"
            "que Dragalge\n"
            "megaevolua em."),
        .descricion = COMPOUND_STRING(
            "Esta piedra permite\n"
            "a Dragalge\n"
            "megaevolucionar en."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Dragalgite,
        .iconPalette = gItemIconPalette_Dragalgite,
    },

    [ITEM_HAWLUCHANITE] =
    {
        .name = ITEM_NAME("Hawluchanite"),
        .nombre = ITEM_NAME("haluchanita"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "This stone enables\n"
            "Hawlucha to Mega\n"
            "Evolve in battle."),
        .descricao = COMPOUND_STRING(
            "Esta pedra permite\n"
            "que Hawlucha\n"
            "megaevolua em."),
        .descricion = COMPOUND_STRING(
            "Esta piedra permite\n"
            "a Hawlucha\n"
            "megaevolucionar en."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Hawluchanite,
        .iconPalette = gItemIconPalette_Hawluchanite,
    },

    [ITEM_ZYGARDITE] =
    {
        .name = ITEM_NAME("Zygardite"),
        .nombre = ITEM_NAME("Zygardita"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "This stone enables\n"
            "Zygarde to Mega\n"
            "Evolve in battle."),
        .descricao = COMPOUND_STRING(
            "Esta pedra permite\n"
            "que Zygarde\n"
            "megaevolua em."),
        .descricion = COMPOUND_STRING(
            "Esta piedra permite\n"
            "a Zygarde\n"
            "megaevolucionar en."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Zygardite,
        .iconPalette = gItemIconPalette_Zygardite,
    },

    [ITEM_DRAMPANITE] =
    {
        .name = ITEM_NAME("Drampanite"),
        .nombre = ITEM_NAME("Drampanita"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "This stone enables\n"
            "Drampa to Mega\n"
            "Evolve in battle."),
        .descricao = COMPOUND_STRING(
            "Esta pedra permite\n"
            "que Drampa\n"
            "megaevolua em."),
        .descricion = COMPOUND_STRING(
            "Esta piedra permite\n"
            "a Drampa\n"
            "megaevolucionar en."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Drampanite,
        .iconPalette = gItemIconPalette_Drampanite,
    },

    [ITEM_FALINKSITE] =
    {
        .name = ITEM_NAME("Falinksite"),
        .nombre = ITEM_NAME("sitio falink"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "This stone enables\n"
            "Falinks to Mega\n"
            "Evolve in battle."),
        .descricao = COMPOUND_STRING(
            "Esta pedra permite\n"
            "que Falinks\n"
            "megaevoluam em."),
        .descricion = COMPOUND_STRING(
            "Esta piedra permite\n"
            "a Falinks\n"
            "megaevolucionar en."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Falinksite,
        .iconPalette = gItemIconPalette_Falinksite,
    },

    [ITEM_HEATRANITE] =
    {
        .name = ITEM_NAME("Heatranite"),
        .nombre = ITEM_NAME("heatranita"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "This stone enables\n"
            "Heatran to Mega\n"
            "Evolve in battle."),
        .descricao = COMPOUND_STRING(
            "Esta pedra permite\n"
            "que Heatran\n"
            "megaevolua em."),
        .descricion = COMPOUND_STRING(
            "Esta piedra permite\n"
            "a Heatran\n"
            "megaevolucionar en."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Heatranite,
        .iconPalette = gItemIconPalette_Heatranite,
    },

    [ITEM_DARKRANITE] =
    {
        .name = ITEM_NAME("Darkranite"),
        .nombre = ITEM_NAME("Darkranita"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "This stone enables\n"
            "Darkrai to Mega\n"
            "Evolve in battle."),
        .descricao = COMPOUND_STRING(
            "Esta pedra permite\n"
            "que Darkrai\n"
            "megaevolua em."),
        .descricion = COMPOUND_STRING(
            "Esta piedra permite\n"
            "a Darkrai\n"
            "megaevolucionar en."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Darkranite,
        .iconPalette = gItemIconPalette_Darkranite,
    },

    [ITEM_ZERAORITE] =
    {
        .name = ITEM_NAME("Zeraorite"),
        .nombre = ITEM_NAME("zeraorita"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "This stone enables\n"
            "Zeraora to Mega\n"
            "Evolve in battle."),
        .descricao = COMPOUND_STRING(
            "Esta pedra permite\n"
            "que Zeraora\n"
            "Megaevolua em."),
        .descricion = COMPOUND_STRING(
            "Esta piedra permite\n"
            "a Zeraora\n"
            "megaevolucionar en."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Zeraorite,
        .iconPalette = gItemIconPalette_Zeraorite,
    },

    [ITEM_RAICHUNITE_X] =
    {
        .name = ITEM_NAME("Raichunite X"),
        .nombre = ITEM_NAME("Raichunita X"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = sRaichuniteDesc,
        .descricao = COMPOUND_STRING(
            "Esta pedra permite\n"
            "que Raichu\n"
            "megaevolua em."),
        .descricion = COMPOUND_STRING(
            "Esta piedra le\n"
            "permite a Raichu\n"
            "megaevolucionar en."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_RaichuniteX,
        .iconPalette = gItemIconPalette_RaichuniteX,
    },

    [ITEM_RAICHUNITE_Y] =
    {
        .name = ITEM_NAME("Raichunite Y"),
        .nombre = ITEM_NAME("Raichunita Y"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = sRaichuniteDesc,
        .descricao = COMPOUND_STRING(
            "Esta pedra permite\n"
            "que Raichu\n"
            "megaevolua em."),
        .descricion = COMPOUND_STRING(
            "Esta piedra le\n"
            "permite a Raichu\n"
            "megaevolucionar en."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_RaichuniteY,
        .iconPalette = gItemIconPalette_RaichuniteY,
    },

    [ITEM_CHIMECHITE] =
    {
        .name = ITEM_NAME("Chimechite"),
        .nombre = ITEM_NAME("chimechita"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "This stone enables\n"
            "Chimecho to Mega\n"
            "Evolve in battle."),
        .descricao = COMPOUND_STRING(
            "Esta pedra permite\n"
            "que Chimecho\n"
            "megaevolua em."),
        .descricion = COMPOUND_STRING(
            "Esta piedra le\n"
            "permite a Chimecho\n"
            "megaevolucionar en."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Chimechite,
        .iconPalette = gItemIconPalette_Chimechite,
    },

    [ITEM_ABSOLITE_Z] =
    {
        .name = ITEM_NAME("Absolite Z"),
        .nombre = ITEM_NAME("Z absoluta"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = sAbsoliteDesc,
        .descricao = COMPOUND_STRING(
            "Esta pedra permite\n"
            "que Absol\n"
            "megaevolua na luta."),
        .descricion = COMPOUND_STRING(
            "Esta piedra le\n"
            "permite a Absol\n"
            "megaevolucionar en."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_AbsoliteZ,
        .iconPalette = gItemIconPalette_AbsoliteZ,
    },

    [ITEM_STARAPTITE] =
    {
        .name = ITEM_NAME("Staraptite"),
        .nombre = ITEM_NAME("Staraptita"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "This stone enables\n"
            "Staraptor to Mega\n"
            "Evolve in battle."),
        .descricao = COMPOUND_STRING(
            "Esta pedra permite\n"
            "que o Staraptor\n"
            "megaevolua em."),
        .descricion = COMPOUND_STRING(
            "Esta piedra permite\n"
            "a Staraptor\n"
            "megaevolucionar en."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Staraptite,
        .iconPalette = gItemIconPalette_Staraptite,
    },

    [ITEM_GARCHOMPITE_Z] =
    {
        .name = ITEM_NAME("Garchompite Z"),
        .nombre = ITEM_NAME("Garchompite Z"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = sGarchompiteDesc,
        .descricao = COMPOUND_STRING(
            "Esta pedra permite\n"
            "que Garchomp\n"
            "megaevolua na."),
        .descricion = COMPOUND_STRING(
            "Esta piedra le\n"
            "permite a Garchomp\n"
            "megaevolucionar en."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_GarchompiteZ,
        .iconPalette = gItemIconPalette_GarchompiteZ,
    },

    [ITEM_LUCARIONITE_Z] =
    {
        .name = ITEM_NAME("Lucarionite Z"),
        .nombre = ITEM_NAME("Lucarionita Z"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = sLucarioniteDesc,
        .descricao = COMPOUND_STRING(
            "Esta pedra permite\n"
            "que Lucario\n"
            "megaevolua em."),
        .descricion = COMPOUND_STRING(
            "Esta piedra le\n"
            "permite a Lucario\n"
            "megaevolucionar en."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_LucarioniteZ,
        .iconPalette = gItemIconPalette_LucarioniteZ,
    },

    [ITEM_GOLURKITE] =
    {
        .name = ITEM_NAME("Golurkite"),
        .nombre = ITEM_NAME("Golurkita"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "This stone enables\n"
            "Golurk to Mega\n"
            "Evolve in battle."),
        .descricao = COMPOUND_STRING(
            "Esta pedra permite\n"
            "que Golurk\n"
            "megaevolua na."),
        .descricion = COMPOUND_STRING(
            "Esta piedra le\n"
            "permite a Golurk\n"
            "megaevolucionar en."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Golurkite,
        .iconPalette = gItemIconPalette_Golurkite,
    },

    [ITEM_MEOWSTICITE] =
    {
        .name = ITEM_NAME("Meowsticite"),
        .nombre = ITEM_NAME("Miausticita"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "This stone enables\n"
            "Meowstic to Mega\n"
            "Evolve in battle."),
        .descricao = COMPOUND_STRING(
            "Esta pedra permite\n"
            "que Meowstic\n"
            "megaevolua em."),
        .descricion = COMPOUND_STRING(
            "Esta piedra permite\n"
            "a Meowstic\n"
            "megaevolucionar en."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Meowsticite,
        .iconPalette = gItemIconPalette_Meowsticite,
    },

    [ITEM_CRABOMINITE] =
    {
        .name = ITEM_NAME("Crabominite"),
        .nombre = ITEM_NAME("Crabominita"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "This stone enables\n"
            "Crabominable to\n"
            "Mega in battle."),
        .descricao = COMPOUND_STRING(
            "Esta pedra permite\n"
            "que Crabominable\n"
            "seja Mega em."),
        .descricion = COMPOUND_STRING(
            "Esta piedra permite\n"
            "Crabominable\n"
            "convertirse en."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Crabominite,
        .iconPalette = gItemIconPalette_Crabominite,
    },

    [ITEM_GOLISOPITE] =
    {
        .name = ITEM_NAME("Golisopite"),
        .nombre = ITEM_NAME("golisopita"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "This stone enables\n"
            "Golisopod to Mega\n"
            "Evolve in battle."),
        .descricao = COMPOUND_STRING(
            "Esta pedra permite\n"
            "que Golisopod\n"
            "megaevolua em."),
        .descricion = COMPOUND_STRING(
            "Esta piedra permite\n"
            "a Golisopod\n"
            "megaevolucionar en."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Golisopite,
        .iconPalette = gItemIconPalette_Golisopite,
    },

    [ITEM_MAGEARNITE] =
    {
        .name = ITEM_NAME("Magearnite"),
        .nombre = ITEM_NAME("Magearnita"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "This stone enables\n"
            "Magearna to Mega\n"
            "Evolve in battle."),
        .descricao = COMPOUND_STRING(
            "Esta pedra permite\n"
            "que Magearna\n"
            "megaevolua em."),
        .descricion = COMPOUND_STRING(
            "Esta piedra permite\n"
            "a Magearna\n"
            "megaevolucionar en."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Magearnite,
        .iconPalette = gItemIconPalette_Magearnite,
    },

    [ITEM_SCOVILLAINITE] =
    {
        .name = ITEM_NAME("Scovillainite"),
        .nombre = ITEM_NAME("Scovillainita"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "This stone enables\n"
            "Scovillain to Mega\n"
            "Evolve in battle."),
        .descricao = COMPOUND_STRING(
            "Esta pedra permite\n"
            "que Scovillain\n"
            "megaevolua em."),
        .descricion = COMPOUND_STRING(
            "Esta piedra permite\n"
            "a Scovillain\n"
            "megaevolucionar en."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Scovillainite,
        .iconPalette = gItemIconPalette_Scovillainite,
    },

    [ITEM_BAXCALIBRITE] =
    {
        .name = ITEM_NAME("Baxcalibrite"),
        .nombre = ITEM_NAME("Baxcalibrita"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "This stone enables\n"
            "Baxcalibur to Mega\n"
            "Evolve in battle."),
        .descricao = COMPOUND_STRING(
            "Esta pedra permite\n"
            "que Baxcalibur\n"
            "megaevolua em."),
        .descricion = COMPOUND_STRING(
            "Esta piedra permite\n"
            "a Baxcalibur\n"
            "megaevolucionar en."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Baxcalibrite,
        .iconPalette = gItemIconPalette_Baxcalibrite,
    },

    [ITEM_TATSUGIRINITE] =
    {
        .name = ITEM_NAME("Tatsugirinite"),
        .nombre = ITEM_NAME("Tatsugirinita"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "This stone enables\n"
            "Tatsugiri to Mega\n"
            "Evolve in battle."),
        .descricao = COMPOUND_STRING(
            "Esta pedra permite\n"
            "que Tatsugiri\n"
            "megaevolua em."),
        .descricion = COMPOUND_STRING(
            "Esta piedra le\n"
            "permite a Tatsugiri\n"
            "megaevolucionar en."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Tatsugirinite,
        .iconPalette = gItemIconPalette_Tatsugirinite,
    },

    [ITEM_GLIMMORANITE] =
    {
        .name = ITEM_NAME("Glimmoranite"),
        .nombre = ITEM_NAME("Glimmoranita"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "This stone enables\n"
            "Glimmora to Mega\n"
            "Evolve in battle."),
        .descricao = COMPOUND_STRING(
            "Esta pedra permite\n"
            "que Glimmora\n"
            "megaevolua em."),
        .descricion = COMPOUND_STRING(
            "Esta piedra permite\n"
            "a Glimmora\n"
            "megaevolucionar en."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Glimmoranite,
        .iconPalette = gItemIconPalette_Glimmoranite,
    },

// Gems
    #if I_PRICE >= GEN_9
        #define GEM_PRICE 15000
    #elif I_PRICE >= GEN_7
        #define GEM_PRICE 4000
    #else
        #define GEM_PRICE 200
    #endif

    [ITEM_NORMAL_GEM] =
    {
        .name = ITEM_NAME("Normal Gem"),
        .nombre = ITEM_NAME("Gema normal"),
        .price = GEM_PRICE,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "Increases the power\n"
            "of Normal Type\n"
            "moves."),
        .descricao = COMPOUND_STRING(
            "Aumenta o poder dos\n"
            "golpes do Tipo\n"
            "Normal."),
        .descricion = COMPOUND_STRING(
            "Aumenta el poder de\n"
            "los movs. de tipo\n"
            "normal."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_NORMAL,
        .iconPic = gItemIcon_TypeGem,
        .iconPalette = gItemIconPalette_NormalGem,
    },

    [ITEM_FIRE_GEM] =
    {
        .name = ITEM_NAME("Fire Gem"),
        .nombre = ITEM_NAME("Gema de fuego"),
        .price = GEM_PRICE,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "Increases the power\n"
            "of Fire Type moves."),
        .descricao = COMPOUND_STRING(
            "Aumenta o poder dos\n"
            "golpes do Tipo\n"
            "Fogo."),
        .descricion = COMPOUND_STRING(
            "Aumenta el poder de\n"
            "los movs. de tipo\n"
            "Fuego."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FIRE,
        .iconPic = gItemIcon_TypeGem,
        .iconPalette = gItemIconPalette_FireGem,
    },

    [ITEM_WATER_GEM] =
    {
        .name = ITEM_NAME("Water Gem"),
        .nombre = ITEM_NAME("Gema de agua"),
        .price = GEM_PRICE,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "Increases the power\n"
            "of Water Type\n"
            "moves."),
        .descricao = COMPOUND_STRING(
            "Aumenta o poder dos\n"
            "golpes do tipo\n"
            "Água."),
        .descricion = COMPOUND_STRING(
            "Aumenta el poder de\n"
            "los movs. de tipo\n"
            "agua."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_WATER,
        .iconPic = gItemIcon_TypeGem,
        .iconPalette = gItemIconPalette_WaterGem,
    },

    [ITEM_ELECTRIC_GEM] =
    {
        .name = ITEM_NAME("Electric Gem"),
        .nombre = ITEM_NAME("Gema electrica"),
        .price = GEM_PRICE,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "Increases the power\n"
            "of Electric Type\n"
            "moves."),
        .descricao = COMPOUND_STRING(
            "Aumenta o poder dos\n"
            "golpes do tipo\n"
            "elétrico."),
        .descricion = COMPOUND_STRING(
            "Aumenta el poder de\n"
            "los movs. de tipo\n"
            "eléctrico."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ELECTRIC,
        .iconPic = gItemIcon_TypeGem,
        .iconPalette = gItemIconPalette_ElectricGem,
    },

    [ITEM_GRASS_GEM] =
    {
        .name = ITEM_NAME("Grass Gem"),
        .nombre = ITEM_NAME("Gema de hierba"),
        .price = GEM_PRICE,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "Increases the power\n"
            "of Grass Type\n"
            "moves."),
        .descricao = COMPOUND_STRING(
            "Aumenta o poder dos\n"
            "golpes do tipo\n"
            "Grama."),
        .descricion = COMPOUND_STRING(
            "Aumenta el poder de\n"
            "los movs. tipo\n"
            "hierba."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_GRASS,
        .iconPic = gItemIcon_TypeGem,
        .iconPalette = gItemIconPalette_GrassGem,
    },

    [ITEM_ICE_GEM] =
    {
        .name = ITEM_NAME("Ice Gem"),
        .nombre = ITEM_NAME("Gema de hielo"),
        .price = GEM_PRICE,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "Increases the power\n"
            "of Ice Type moves."),
        .descricao = COMPOUND_STRING(
            "Aumenta o poder dos\n"
            "golpes do tipo Ice."),
        .descricion = COMPOUND_STRING(
            "Aumenta el poder de\n"
            "los movs. de tipo\n"
            "hielo."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ICE,
        .iconPic = gItemIcon_TypeGem,
        .iconPalette = gItemIconPalette_IceGem,
    },

    [ITEM_FIGHTING_GEM] =
    {
        .name = ITEM_NAME("Fighting Gem"),
        .nombre = ITEM_NAME("Gema de lucha"),
        .price = GEM_PRICE,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "Increases the power\n"
            "of Fighting Type\n"
            "moves."),
        .descricao = COMPOUND_STRING(
            "Aumenta o poder dos\n"
            "golpes do tipo\n"
            "Fighting."),
        .descricion = COMPOUND_STRING(
            "Aumenta el poder de\n"
            "los movs. de tipo\n"
            "lucha."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FIGHTING,
        .iconPic = gItemIcon_TypeGem,
        .iconPalette = gItemIconPalette_FightingGem,
    },

    [ITEM_POISON_GEM] =
    {
        .name = ITEM_NAME("Poison Gem"),
        .nombre = ITEM_NAME("Gema venenosa"),
        .price = GEM_PRICE,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "Increases the power\n"
            "of Poison Type\n"
            "moves."),
        .descricao = COMPOUND_STRING(
            "Aumenta o poder dos\n"
            "golpes do tipo\n"
            "Poison."),
        .descricion = COMPOUND_STRING(
            "Aumenta el poder de\n"
            "los movs. de tipo\n"
            "Veneno."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_POISON,
        .iconPic = gItemIcon_TypeGem,
        .iconPalette = gItemIconPalette_PoisonGem,
    },

    [ITEM_GROUND_GEM] =
    {
        .name = ITEM_NAME("Ground Gem"),
        .nombre = ITEM_NAME("Gema molida"),
        .price = GEM_PRICE,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "Increases the power\n"
            "of Ground Type\n"
            "moves."),
        .descricao = COMPOUND_STRING(
            "Aumenta o poder dos\n"
            "golpes do tipo\n"
            "Ground."),
        .descricion = COMPOUND_STRING(
            "Aumenta el poder de\n"
            "los movs. de tipo\n"
            "suelo."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_GROUND,
        .iconPic = gItemIcon_TypeGem,
        .iconPalette = gItemIconPalette_GroundGem,
    },

    [ITEM_FLYING_GEM] =
    {
        .name = ITEM_NAME("Flying Gem"),
        .nombre = ITEM_NAME("Gema voladora"),
        .price = GEM_PRICE,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "Increases the power\n"
            "of Flying Type\n"
            "moves."),
        .descricao = COMPOUND_STRING(
            "Aumenta o poder dos\n"
            "golpes do Tipo\n"
            "Voador."),
        .descricion = COMPOUND_STRING(
            "Aumenta el poder de\n"
            "los movs. de tipo\n"
            "volador."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FLYING,
        .iconPic = gItemIcon_TypeGem,
        .iconPalette = gItemIconPalette_FlyingGem,
    },

    [ITEM_PSYCHIC_GEM] =
    {
        .name = ITEM_NAME("Psychic Gem"),
        .nombre = ITEM_NAME("Gema psiquica"),
        .price = GEM_PRICE,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "Increases the power\n"
            "of Psychic Type\n"
            "moves."),
        .descricao = COMPOUND_STRING(
            "Aumenta o poder dos\n"
            "golpes do Tipo\n"
            "Psíquico."),
        .descricion = COMPOUND_STRING(
            "Aumenta el poder de\n"
            "los movs. de tipo\n"
            "psíquico."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_PSYCHIC,
        .iconPic = gItemIcon_TypeGem,
        .iconPalette = gItemIconPalette_PsychicGem,
    },

    [ITEM_BUG_GEM] =
    {
        .name = ITEM_NAME("Bug Gem"),
        .nombre = ITEM_NAME("Gema de insecto"),
        .price = GEM_PRICE,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "Increases the power\n"
            "of Bug Type moves."),
        .descricao = COMPOUND_STRING(
            "Aumenta o poder dos\n"
            "golpes do tipo Bug."),
        .descricion = COMPOUND_STRING(
            "Aumenta el poder de\n"
            "los movs. tipo Bug."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_BUG,
        .iconPic = gItemIcon_TypeGem,
        .iconPalette = gItemIconPalette_BugGem,
    },

    [ITEM_ROCK_GEM] =
    {
        .name = ITEM_NAME("Rock Gem"),
        .nombre = ITEM_NAME("Gema de roca"),
        .price = GEM_PRICE,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "Increases the power\n"
            "of Rock Type moves."),
        .descricao = COMPOUND_STRING(
            "Aumenta o poder dos\n"
            "golpes do tipo\n"
            "Rock."),
        .descricion = COMPOUND_STRING(
            "Aumenta el poder de\n"
            "los movs. tipo\n"
            "roca."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ROCK,
        .iconPic = gItemIcon_TypeGem,
        .iconPalette = gItemIconPalette_RockGem,
    },

    [ITEM_GHOST_GEM] =
    {
        .name = ITEM_NAME("Ghost Gem"),
        .nombre = ITEM_NAME("Gema fantasma"),
        .price = GEM_PRICE,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "Increases the power\n"
            "of Ghost Type\n"
            "moves."),
        .descricao = COMPOUND_STRING(
            "Aumenta o poder dos\n"
            "golpes do tipo\n"
            "Ghost."),
        .descricion = COMPOUND_STRING(
            "Aumenta el poder de\n"
            "los movs. de tipo\n"
            "fantasma."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_GHOST,
        .iconPic = gItemIcon_TypeGem,
        .iconPalette = gItemIconPalette_GhostGem,
    },

    [ITEM_DRAGON_GEM] =
    {
        .name = ITEM_NAME("Dragon Gem"),
        .nombre = ITEM_NAME("Gema del dragon"),
        .price = GEM_PRICE,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "Increases the power\n"
            "of Dragon Type\n"
            "moves."),
        .descricao = COMPOUND_STRING(
            "Aumenta o poder dos\n"
            "golpes do tipo\n"
            "Dragão."),
        .descricion = COMPOUND_STRING(
            "Aumenta el poder de\n"
            "los movs. tipo\n"
            "Dragón."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_DRAGON,
        .iconPic = gItemIcon_TypeGem,
        .iconPalette = gItemIconPalette_DragonGem,
    },

    [ITEM_DARK_GEM] =
    {
        .name = ITEM_NAME("Dark Gem"),
        .nombre = ITEM_NAME("Gema Oscura"),
        .price = GEM_PRICE,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "Increases the power\n"
            "of Dark Type moves."),
        .descricao = COMPOUND_STRING(
            "Aumenta o poder dos\n"
            "golpes do tipo\n"
            "Dark."),
        .descricion = COMPOUND_STRING(
            "Aumenta el poder de\n"
            "los movs. de tipo\n"
            "oscuro."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_DARK,
        .iconPic = gItemIcon_TypeGem,
        .iconPalette = gItemIconPalette_DarkGem,
    },

    [ITEM_STEEL_GEM] =
    {
        .name = ITEM_NAME("Steel Gem"),
        .nombre = ITEM_NAME("Gema de acero"),
        .price = GEM_PRICE,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "Increases the power\n"
            "of Steel Type\n"
            "moves."),
        .descricao = COMPOUND_STRING(
            "Aumenta o poder dos\n"
            "golpes do tipo\n"
            "Steel."),
        .descricion = COMPOUND_STRING(
            "Aumenta el poder de\n"
            "los movs. de tipo\n"
            "acero."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_STEEL,
        .iconPic = gItemIcon_TypeGem,
        .iconPalette = gItemIconPalette_SteelGem,
    },

    [ITEM_FAIRY_GEM] =
    {
        .name = ITEM_NAME("Fairy Gem"),
        .nombre = ITEM_NAME("Gema de hadas"),
        .price = GEM_PRICE,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "Increases the power\n"
            "of Fairy Type\n"
            "moves."),
        .descricao = COMPOUND_STRING(
            "Aumenta o poder dos\n"
            "golpes do tipo\n"
            "Fairy."),
        .descricion = COMPOUND_STRING(
            "Aumenta el poder de\n"
            "los movs. tipo\n"
            "Hada."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FAIRY,
        .iconPic = gItemIcon_TypeGem,
        .iconPalette = gItemIconPalette_FairyGem,
    },

// Z-Crystals

    [ITEM_NORMALIUM_Z] =
    {
        .name = ITEM_NAME("Normalium Z"),
        .nombre = ITEM_NAME("Normalio Z"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Upgrade Normal-\n"
            "type moves into\n"
            "Z-Moves."),
        .descricao = COMPOUND_STRING(
            "Atualize golpes do\n"
            "tipo Normal para\n"
            "Z-Moves."),
        .descricion = COMPOUND_STRING(
            "Mejora los movs. de\n"
            "tipo normal a movs.\n"
            "Z."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_NORMAL,
        .iconPic = gItemIcon_NormaliumZ,
        .iconPalette = gItemIconPalette_NormaliumZ,
    },

    [ITEM_FIRIUM_Z] =
    {
        .name = ITEM_NAME("Firium Z"),
        .nombre = ITEM_NAME("Firio Z"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Upgrade Fire- type\n"
            "moves into Z-Moves."),
        .descricao = COMPOUND_STRING(
            "Atualize golpes do\n"
            "tipo Fire para\n"
            "Z-Moves."),
        .descricion = COMPOUND_STRING(
            "Mejora los movs.\n"
            "tipo Fuego a movs.\n"
            "Z."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FIRE,
        .iconPic = gItemIcon_FiriumZ,
        .iconPalette = gItemIconPalette_FiriumZ,
    },

    [ITEM_WATERIUM_Z] =
    {
        .name = ITEM_NAME("Waterium Z"),
        .nombre = ITEM_NAME("Waterio Z"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Upgrade Water- type\n"
            "moves into Z-Moves."),
        .descricao = COMPOUND_STRING(
            "Atualize golpes do\n"
            "tipo Água para\n"
            "Z-Moves."),
        .descricion = COMPOUND_STRING(
            "Mejora los movs.\n"
            "tipo agua a movs.\n"
            "Z."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_WATER,
        .iconPic = gItemIcon_WateriumZ,
        .iconPalette = gItemIconPalette_WateriumZ,
    },

    [ITEM_ELECTRIUM_Z] =
    {
        .name = ITEM_NAME("Electrium Z"),
        .nombre = ITEM_NAME("Electrio Z"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Upgrade Electric-\n"
            "type moves into\n"
            "Z-Moves."),
        .descricao = COMPOUND_STRING(
            "Atualize golpes do\n"
            "tipo elétrico para\n"
            "Z-Moves."),
        .descricion = COMPOUND_STRING(
            "Mejora los movs. de\n"
            "tipo eléctrico a\n"
            "movs. Z."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ELECTRIC,
        .iconPic = gItemIcon_ElectriumZ,
        .iconPalette = gItemIconPalette_ElectriumZ,
    },

    [ITEM_GRASSIUM_Z] =
    {
        .name = ITEM_NAME("Grassium Z"),
        .nombre = ITEM_NAME("Hierba Z"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Upgrade Grass- type\n"
            "moves into Z-Moves."),
        .descricao = COMPOUND_STRING(
            "Atualize golpes do\n"
            "tipo Grass para\n"
            "Z-Moves."),
        .descricion = COMPOUND_STRING(
            "Mejora los movs.\n"
            "tipo hierba a movs.\n"
            "Z."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_GRASS,
        .iconPic = gItemIcon_GrassiumZ,
        .iconPalette = gItemIconPalette_GrassiumZ,
    },

    [ITEM_ICIUM_Z] =
    {
        .name = ITEM_NAME("Icium Z"),
        .nombre = ITEM_NAME("hielo z"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Upgrade Ice- type\n"
            "moves into Z-Moves."),
        .descricao = COMPOUND_STRING(
            "Atualize golpes do\n"
            "tipo Ice para\n"
            "Z-Moves."),
        .descricion = COMPOUND_STRING(
            "Mejora los movs.\n"
            "tipo Hielo a movs.\n"
            "Z."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ICE,
        .iconPic = gItemIcon_IciumZ,
        .iconPalette = gItemIconPalette_IciumZ,
    },

    [ITEM_FIGHTINIUM_Z] =
    {
        .name = ITEM_NAME("Fightinium Z"),
        .nombre = ITEM_NAME("Fightinio Z"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Upgrade Fighting-\n"
            "type moves into\n"
            "Z-Moves."),
        .descricao = COMPOUND_STRING(
            "Atualize golpes do\n"
            "tipo Fighting para\n"
            "Z-Moves."),
        .descricion = COMPOUND_STRING(
            "Mejora los movs. de\n"
            "tipo Fighting a\n"
            "Z-Moves."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FIGHTING,
        .iconPic = gItemIcon_FightiniumZ,
        .iconPalette = gItemIconPalette_FightiniumZ,
    },

    [ITEM_POISONIUM_Z] =
    {
        .name = ITEM_NAME("Poisonium Z"),
        .nombre = ITEM_NAME("Veneno Z"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Upgrade Poison-\n"
            "type moves into\n"
            "Z-Moves."),
        .descricao = COMPOUND_STRING(
            "Atualize golpes do\n"
            "tipo Poison para\n"
            "Z-Moves."),
        .descricion = COMPOUND_STRING(
            "Mejora los movs.\n"
            "tipo Veneno a movs.\n"
            "Z."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_POISON,
        .iconPic = gItemIcon_PoisoniumZ,
        .iconPalette = gItemIconPalette_PoisoniumZ,
    },

    [ITEM_GROUNDIUM_Z] =
    {
        .name = ITEM_NAME("Groundium Z"),
        .nombre = ITEM_NAME("Groundio Z"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Upgrade Ground-\n"
            "type moves into\n"
            "Z-Moves."),
        .descricao = COMPOUND_STRING(
            "Atualize golpes do\n"
            "tipo Ground para\n"
            "Z-Moves."),
        .descricion = COMPOUND_STRING(
            "Mejora los movs. de\n"
            "tipo Tierra a movs.\n"
            "Z."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_GROUND,
        .iconPic = gItemIcon_GroundiumZ,
        .iconPalette = gItemIconPalette_GroundiumZ,
    },

    [ITEM_FLYINIUM_Z] =
    {
        .name = ITEM_NAME("Flyinium Z"),
        .nombre = ITEM_NAME("Flyinio Z"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Upgrade Flying-\n"
            "type moves into\n"
            "Z-Moves."),
        .descricao = COMPOUND_STRING(
            "Atualize golpes do\n"
            "tipo Flying para\n"
            "Z-Moves."),
        .descricion = COMPOUND_STRING(
            "Mejora los movs. de\n"
            "tipo volador a\n"
            "movs. Z."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FLYING,
        .iconPic = gItemIcon_FlyiniumZ,
        .iconPalette = gItemIconPalette_FlyiniumZ,
    },

    [ITEM_PSYCHIUM_Z] =
    {
        .name = ITEM_NAME("Psychium Z"),
        .nombre = ITEM_NAME("Psiquio Z"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Upgrade Psychic-\n"
            "type moves into\n"
            "Z-Moves."),
        .descricao = COMPOUND_STRING(
            "Atualize golpes do\n"
            "tipo Psychic para\n"
            "Z-Moves."),
        .descricion = COMPOUND_STRING(
            "Mejora los movs. de\n"
            "tipo psíquico a\n"
            "movs. Z."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_PSYCHIC,
        .iconPic = gItemIcon_PsychiumZ,
        .iconPalette = gItemIconPalette_PsychiumZ,
    },

    [ITEM_BUGINIUM_Z] =
    {
        .name = ITEM_NAME("Buginium Z"),
        .nombre = ITEM_NAME("Buginio Z"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Upgrade Bug- type\n"
            "moves into Z-Moves."),
        .descricao = COMPOUND_STRING(
            "Atualize golpes do\n"
            "tipo Bug para\n"
            "Z-Moves."),
        .descricion = COMPOUND_STRING(
            "Mejora los movs.\n"
            "tipo Bug a movs. Z."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_BUG,
        .iconPic = gItemIcon_BuginiumZ,
        .iconPalette = gItemIconPalette_BuginiumZ,
    },

    [ITEM_ROCKIUM_Z] =
    {
        .name = ITEM_NAME("Rockium Z"),
        .nombre = ITEM_NAME("Rockio Z"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Upgrade Rock- type\n"
            "moves into Z-Moves."),
        .descricao = COMPOUND_STRING(
            "Atualize golpes do\n"
            "tipo Rock para\n"
            "Z-Moves."),
        .descricion = COMPOUND_STRING(
            "Mejora los movs.\n"
            "tipo Roca a movs.\n"
            "Z."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ROCK,
        .iconPic = gItemIcon_RockiumZ,
        .iconPalette = gItemIconPalette_RockiumZ,
    },

    [ITEM_GHOSTIUM_Z] =
    {
        .name = ITEM_NAME("Ghostium Z"),
        .nombre = ITEM_NAME("Fantasma Z"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Upgrade Ghost- type\n"
            "moves into Z-Moves."),
        .descricao = COMPOUND_STRING(
            "Atualize golpes do\n"
            "tipo Ghost para\n"
            "Z-Moves."),
        .descricion = COMPOUND_STRING(
            "Mejora los movs.\n"
            "tipo fantasma a\n"
            "movs. Z."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_GHOST,
        .iconPic = gItemIcon_GhostiumZ,
        .iconPalette = gItemIconPalette_GhostiumZ,
    },

    [ITEM_DRAGONIUM_Z] =
    {
        .name = ITEM_NAME("Dragonium Z"),
        .nombre = ITEM_NAME("Dragonio Z"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Upgrade Dragon-\n"
            "type moves into\n"
            "Z-Moves."),
        .descricao = COMPOUND_STRING(
            "Atualize golpes do\n"
            "tipo Dragão para\n"
            "Z-Moves."),
        .descricion = COMPOUND_STRING(
            "Mejora los movs.\n"
            "tipo Dragón a movs.\n"
            "Z."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_DRAGON,
        .iconPic = gItemIcon_DragoniumZ,
        .iconPalette = gItemIconPalette_DragoniumZ,
    },

    [ITEM_DARKINIUM_Z] =
    {
        .name = ITEM_NAME("Darkinium Z"),
        .nombre = ITEM_NAME("Darkinio Z"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Upgrade Dark- type\n"
            "moves into Z-Moves."),
        .descricao = COMPOUND_STRING(
            "Atualize golpes do\n"
            "tipo Dark para\n"
            "Z-Moves."),
        .descricion = COMPOUND_STRING(
            "Mejora los movs. de\n"
            "tipo oscuro a movs.\n"
            "Z."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_DARK,
        .iconPic = gItemIcon_DarkiniumZ,
        .iconPalette = gItemIconPalette_DarkiniumZ,
    },

    [ITEM_STEELIUM_Z] =
    {
        .name = ITEM_NAME("Steelium Z"),
        .nombre = ITEM_NAME("Steelio Z"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Upgrade Steel- type\n"
            "moves into Z-Moves."),
        .descricao = COMPOUND_STRING(
            "Atualize golpes do\n"
            "tipo Steel para\n"
            "Z-Moves."),
        .descricion = COMPOUND_STRING(
            "Mejora los movs. de\n"
            "tipo acero a movs.\n"
            "Z."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_STEEL,
        .iconPic = gItemIcon_SteeliumZ,
        .iconPalette = gItemIconPalette_SteeliumZ,
    },

    [ITEM_FAIRIUM_Z] =
    {
        .name = ITEM_NAME("Fairium Z"),
        .nombre = ITEM_NAME("Fairio Z"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Upgrade Fairy- type\n"
            "moves into Z-Moves."),
        .descricao = COMPOUND_STRING(
            "Atualize golpes do\n"
            "tipo Fairy para\n"
            "Z-Moves."),
        .descricion = COMPOUND_STRING(
            "Mejora los movs.\n"
            "tipo Hada a movs.\n"
            "Z."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FAIRY,
        .iconPic = gItemIcon_FairiumZ,
        .iconPalette = gItemIconPalette_FairiumZ,
    },

    [ITEM_PIKANIUM_Z] =
    {
        .name = ITEM_NAME("Pikanium Z"),
        .nombre = ITEM_NAME("Pikanio Z"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Upgrade Pikachu's\n"
            "Volt Tackle into a\n"
            "Z-Move."),
        .descricao = COMPOUND_STRING(
            "Atualize o Volt\n"
            "Tackle do Pikachu\n"
            "para um Z-Move."),
        .descricion = COMPOUND_STRING(
            "Mejora el Volt\n"
            "Tackle de Pikachu a\n"
            "un mov. Z."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 255,  // signature z move
        .iconPic = gItemIcon_PikaniumZ,
        .iconPalette = gItemIconPalette_PikaniumZ,
    },

    [ITEM_EEVIUM_Z] =
    {
        .name = ITEM_NAME("Eevium Z"),
        .nombre = ITEM_NAME("Eevium Z"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Upgrade Eevee's\n"
            "Last Resort into a\n"
            "Z-Move."),
        .descricao = COMPOUND_STRING(
            "Atualize o último\n"
            "recurso do Eevee\n"
            "para um Z-Move."),
        .descricion = COMPOUND_STRING(
            "Mejora el último\n"
            "recurso de Eevee y\n"
            "conviértelo en un."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 255,  // signature z move
        .iconPic = gItemIcon_EeviumZ,
        .iconPalette = gItemIconPalette_EeviumZ,
    },

    [ITEM_SNORLIUM_Z] =
    {
        .name = ITEM_NAME("Snorlium Z"),
        .nombre = ITEM_NAME("Snorlio Z"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Upgrade Snorlax's\n"
            "Giga Impact into a\n"
            "Z-Move."),
        .descricao = COMPOUND_STRING(
            "Atualize o Giga\n"
            "Impact do Snorlax\n"
            "para um Z-Move."),
        .descricion = COMPOUND_STRING(
            "Mejora el Giga\n"
            "Impacto de Snorlax\n"
            "a un mov. Z."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 255,  // signature z move
        .iconPic = gItemIcon_SnorliumZ,
        .iconPalette = gItemIconPalette_SnorliumZ,
    },

    [ITEM_MEWNIUM_Z] =
    {
        .name = ITEM_NAME("Mewnium Z"),
        .nombre = ITEM_NAME("Mewnio Z"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Upgrade Mew's\n"
            "Psychic into a\n"
            "Z-Move."),
        .descricao = COMPOUND_STRING(
            "Atualize o Psychic\n"
            "de Mew para um\n"
            "Z-Move."),
        .descricion = COMPOUND_STRING(
            "Mejora el psíquico\n"
            "de Mew a un mov. Z."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 255,  // signature z move
        .iconPic = gItemIcon_MewniumZ,
        .iconPalette = gItemIconPalette_MewniumZ,
    },

    [ITEM_DECIDIUM_Z] =
    {
        .name = ITEM_NAME("Decidium Z"),
        .nombre = ITEM_NAME("Decidio Z"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Upgrade Decidu-\n"
            "eye's Spirit Sha-\n"
            "ckle into a Z-Move."),
        .descricao = COMPOUND_STRING(
            "Atualize Spirit\n"
            "Shackle Decidueye\n"
            "para Z-Move."),
        .descricion = COMPOUND_STRING(
            "Mejora el Spirit\n"
            "Shackle Decidu-eye\n"
            "un mov."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 255,  // signature z move
        .iconPic = gItemIcon_DecidiumZ,
        .iconPalette = gItemIconPalette_DecidiumZ,
    },

    [ITEM_INCINIUM_Z] =
    {
        .name = ITEM_NAME("Incinium Z"),
        .nombre = ITEM_NAME("Incinio Z"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Upgrade Incine-\n"
            "roar's Darkest La-\n"
            "riat into a Z-Move."),
        .descricao = COMPOUND_STRING(
            "Atualize Darkest\n"
            "Lariat Incineroar\n"
            "para Z-Move."),
        .descricion = COMPOUND_STRING(
            "Mejora el Lariat\n"
            "más oscuro\n"
            "Incineroar y."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 255,  // signature z move
        .iconPic = gItemIcon_InciniumZ,
        .iconPalette = gItemIconPalette_InciniumZ,
    },

    [ITEM_PRIMARIUM_Z] =
    {
        .name = ITEM_NAME("Primarium Z"),
        .nombre = ITEM_NAME("Primario Z"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Upgrade Primarina's\n"
            "Sparkling Aria into\n"
            "a Z-Move."),
        .descricao = COMPOUND_STRING(
            "Atualize Sparkling\n"
            "Aria Primarina para\n"
            "Z-Move."),
        .descricion = COMPOUND_STRING(
            "Mejora el Sparkling\n"
            "Aria de Primarina\n"
            "en un mov. Z."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 255,  // signature z move
        .iconPic = gItemIcon_PrimariumZ,
        .iconPalette = gItemIconPalette_PrimariumZ,
    },

    [ITEM_LYCANIUM_Z] =
    {
        .name = ITEM_NAME("Lycanium Z"),
        .nombre = ITEM_NAME("Licanio Z"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Upgrade Lycanroc's\n"
            "Stone Edge into a\n"
            "Z-Move."),
        .descricao = COMPOUND_STRING(
            "Atualize Stone Edge\n"
            "de Lycanroc em um\n"
            "Z-Move."),
        .descricion = COMPOUND_STRING(
            "Mejora el Stone\n"
            "Edge de Lycanroc a\n"
            "un mov. Z."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 255,  // signature z move
        .iconPic = gItemIcon_LycaniumZ,
        .iconPalette = gItemIconPalette_LycaniumZ,
    },

    [ITEM_MIMIKIUM_Z] =
    {
        .name = ITEM_NAME("Mimikium Z"),
        .nombre = ITEM_NAME("Mimikium Z"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Upgrade Mimikyu's\n"
            "Play Rough into a\n"
            "Z-Move."),
        .descricao = COMPOUND_STRING(
            "Atualize o Play\n"
            "Rough de Mimikyu\n"
            "para um Z-Move."),
        .descricion = COMPOUND_STRING(
            "Mejora el Play\n"
            "Rough de Mimikyu a\n"
            "un mov. Z."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 255,  // signature z move
        .iconPic = gItemIcon_MimikiumZ,
        .iconPalette = gItemIconPalette_MimikiumZ,
    },

    [ITEM_KOMMONIUM_Z] =
    {
        .name = ITEM_NAME("Kommonium Z"),
        .nombre = ITEM_NAME("Kommonio Z"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Upgrade Kommo-o's\n"
            "Clanging Scales\n"
            "into a Z-Move."),
        .descricao = COMPOUND_STRING(
            "Atualize as escalas\n"
            "clandestinas de\n"
            "Kommo-o para um."),
        .descricion = COMPOUND_STRING(
            "Mejora las escamas\n"
            "resonantes de\n"
            "Kommo-o para."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 255,  // signature z move
        .iconPic = gItemIcon_KommoniumZ,
        .iconPalette = gItemIconPalette_KommoniumZ,
    },

    [ITEM_TAPUNIUM_Z] =
    {
        .name = ITEM_NAME("Tapunium Z"),
        .nombre = ITEM_NAME("Tapunio Z"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Upgrade the tapus'\n"
            "Nature's Madness\n"
            "into a Z-Move."),
        .descricao = COMPOUND_STRING(
            "Atualize a Nature's\n"
            "Madness do tapus\n"
            "para um Z-Move."),
        .descricion = COMPOUND_STRING(
            "Mejora la locura la\n"
            "naturaleza los\n"
            "tapus un mov. Z."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 255,  //signature z move
        .iconPic = gItemIcon_TapuniumZ,
        .iconPalette = gItemIconPalette_TapuniumZ,
    },

    [ITEM_SOLGANIUM_Z] =
    {
        .name = ITEM_NAME("Solganium Z"),
        .nombre = ITEM_NAME("Solganio Z"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Upgrade Solgaleo's\n"
            "Sunsteel Strike\n"
            "into a Z-Move."),
        .descricao = COMPOUND_STRING(
            "Atualize o Sunsteel\n"
            "Strike de Solgaleo\n"
            "para um Z-Move."),
        .descricion = COMPOUND_STRING(
            "Mejora el Golpe de\n"
            "acero solar de\n"
            "Solgaleo a un mov."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 255,  // signature z move
        .iconPic = gItemIcon_SolganiumZ,
        .iconPalette = gItemIconPalette_SolganiumZ,
    },

    [ITEM_LUNALIUM_Z] =
    {
        .name = ITEM_NAME("Lunalium Z"),
        .nombre = ITEM_NAME("Lunalio Z"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Upgrade Lunala's\n"
            "Moongeist Beam into\n"
            "a Z-Move."),
        .descricao = COMPOUND_STRING(
            "Atualize Moongeist\n"
            "Beam Lunala para\n"
            "Z-Move."),
        .descricion = COMPOUND_STRING(
            "Mejora el rayo\n"
            "lunar Lunala para\n"
            "convertirlo en un."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 255,  // signature z move
        .iconPic = gItemIcon_LunaliumZ,
        .iconPalette = gItemIconPalette_LunaliumZ,
    },

    [ITEM_MARSHADIUM_Z] =
    {
        .name = ITEM_NAME("Marshadium Z"),
        .nombre = ITEM_NAME("marshadio Z"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Upgrade Marsha-\n"
            "dow's Spectral Thi-\n"
            "ef into a Z-Move."),
        .descricao = COMPOUND_STRING(
            "Atualize o Spectral\n"
            "Thief de Marshadow\n"
            "para um Z-Move."),
        .descricion = COMPOUND_STRING(
            "Mejora el Ladrón\n"
            "espectral de\n"
            "Marshadow."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 255,  // signature z move
        .iconPic = gItemIcon_MarshadiumZ,
        .iconPalette = gItemIconPalette_MarshadiumZ,
    },

    [ITEM_ALORAICHIUM_Z] =
    {
        .name = ITEM_NAME("Aloraichium Z"),
        .nombre = ITEM_NAME("Aloraichio Z"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Upgrade Alolan\n"
            "Raichu's Thunder-\n"
            "bolt into a Z-Move."),
        .descricao = COMPOUND_STRING(
            "Atualize o\n"
            "Thunderbolt de\n"
            "Alolan Raichu para."),
        .descricion = COMPOUND_STRING(
            "Mejora el Rayo de\n"
            "Alolan Raichu y\n"
            "conviértelo en un."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 255,  // signature z move
        .iconPic = gItemIcon_AloraichiumZ,
        .iconPalette = gItemIconPalette_AloraichiumZ,
    },

    [ITEM_PIKASHUNIUM_Z] =
    {
        .name = ITEM_NAME("Pikashunium Z"),
        .nombre = ITEM_NAME("Pikashunio Z"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Upgrade Pikachu w/\n"
            "a cap's Thunderbolt\n"
            "into a Z-Move."),
        .descricao = COMPOUND_STRING(
            "Atualize Pikachu\n"
            "com Thunderbolt de\n"
            "boné em um Z-Move."),
        .descricion = COMPOUND_STRING(
            "Mejora a Pikachu\n"
            "con el Thunderbolt\n"
            "de una gorra y."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 255,  // signature z move
        .iconPic = gItemIcon_PikashuniumZ,
        .iconPalette = gItemIconPalette_PikashuniumZ,
    },

    [ITEM_ULTRANECROZIUM_Z] =
    {
        .name = ITEM_NAME("Ultranecrozium Z"),
        .nombre = ITEM_NAME("Ultranecrocio Z"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "A crystal to turn\n"
            "fused Necrozma into\n"
            "a new form."),
        .descricao = COMPOUND_STRING(
            "Um cristal para\n"
            "transformar\n"
            "Necrozma fundido."),
        .descricion = COMPOUND_STRING(
            "Un cristal para\n"
            "convertir Necrozma\n"
            "fusionado en una."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 255, //signature z move
        .iconPic = gItemIcon_UltranecroziumZ,
        .iconPalette = gItemIconPalette_UltranecroziumZ,
    },

// Species-specific Held Items

    [ITEM_LIGHT_BALL] =
    {
        .name = ITEM_NAME("Light Ball"),
        .nombre = ITEM_NAME("bola de luz"),
        .price = (I_PRICE >= GEN_7) ? 1000 : 100,
        .holdEffect = HOLD_EFFECT_LIGHT_BALL,
        .description = COMPOUND_STRING(
            "A hold item that\n"
            "boosts the Atk and\n"
            "Sp. Atk of Pikachu."),
        .descricao = COMPOUND_STRING(
            "Um item de espera\n"
            "que sobe o Atk e o\n"
            "Sp. Atq. do."),
        .descricion = COMPOUND_STRING(
            "Un elemento\n"
            "retenido sobe el\n"
            "Atk y el Sp. Atk"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_LightBall,
        .iconPalette = gItemIconPalette_LightBall,
    },

    [ITEM_LEEK] =
    {
        .name = ITEM_NAME("Leek"),
        .nombre = ITEM_NAME("puerro"),
        .price = (I_PRICE >= GEN_7) ? 1000 : 200,
        .holdEffect = HOLD_EFFECT_LEEK,
        .description = COMPOUND_STRING(
            "A hold item that\n"
            "boosts Farfetch'd's\n"
            "critical-hit ratio."),
        .descricao = COMPOUND_STRING(
            "Um item de retenção\n"
            "que sobe a taxa de\n"
            "acerto crítico de"),
        .descricion = COMPOUND_STRING(
            "Un elemento\n"
            "retenido sobe la\n"
            "proporción golpes"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 60,
        .iconPic = gItemIcon_Leek,
        .iconPalette = gItemIconPalette_Leek,
    },

    [ITEM_THICK_CLUB] =
    {
        .name = ITEM_NAME("Thick Club"),
        .nombre = ITEM_NAME("club grueso"),
        .price = (I_PRICE >= GEN_7) ? 1000 : 500,
        .holdEffect = HOLD_EFFECT_THICK_CLUB,
        .description = COMPOUND_STRING(
            "A hold item that\n"
            "boosts Cubone or\n"
            "Marowak's Atk."),
        .descricao = COMPOUND_STRING(
            "Um item de espera\n"
            "que sobe o Atq. de\n"
            "Cubone ou."),
        .descricion = COMPOUND_STRING(
            "Un elemento de\n"
            "retención que sobe\n"
            "el Atq. de"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 90,
        .iconPic = gItemIcon_Bone,
        .iconPalette = gItemIconPalette_Bone,
    },

    [ITEM_LUCKY_PUNCH] =
    {
        .name = ITEM_NAME("Lucky Punch"),
        .nombre = ITEM_NAME("Golpe de la suerte"),
        .pluralName = ITEM_PLURAL_NAME("Lucky Punches"),
        .price = (I_PRICE >= GEN_7) ? 1000 : 10,
        .holdEffect = HOLD_EFFECT_LUCKY_PUNCH,
        .description = COMPOUND_STRING(
            "A hold item that\n"
            "boosts Chansey's\n"
            "critical-hit rate."),
        .descricao = COMPOUND_STRING(
            "Um item de retenção\n"
            "que sobe a taxa de\n"
            "acerto crítico de"),
        .descricion = COMPOUND_STRING(
            "Un elemento\n"
            "retenido sobe la\n"
            "tasa golpes."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 40,
        .iconPic = gItemIcon_LuckyPunch,
        .iconPalette = gItemIconPalette_LuckyPunch,
    },

    [ITEM_METAL_POWDER] =
    {
        .name = ITEM_NAME("Metal Powder"),
        .nombre = ITEM_NAME("Polvo metalico"),
        .price = (I_PRICE >= GEN_7) ? 1000 : 10,
        .holdEffect = HOLD_EFFECT_METAL_POWDER,
        .description = COMPOUND_STRING(
            "A hold item that\n"
            "boosts Ditto's\n"
            "Def."),
        .descricao = COMPOUND_STRING(
            "Um item de espera\n"
            "que sobe a Def. de\n"
            "Ditto."),
        .descricion = COMPOUND_STRING(
            "Un elemento de\n"
            "retención que sobe\n"
            "la defensa."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_DittoPowder,
        .iconPalette = gItemIconPalette_MetalPowder,
    },

    [ITEM_QUICK_POWDER] =
    {
        .name = ITEM_NAME("Quick Powder"),
        .nombre = ITEM_NAME("Polvo rapido"),
        .price = (I_PRICE >= GEN_7) ? 1000 : 10,
        .holdEffect = HOLD_EFFECT_QUICK_POWDER,
        .description = COMPOUND_STRING(
            "A hold item that\n"
            "boosts the Speed of\n"
            "Ditto."),
        .descricao = COMPOUND_STRING(
            "Um item de espera\n"
            "que sobe a Vel. do\n"
            "Ditto."),
        .descricion = COMPOUND_STRING(
            "Un elemento de\n"
            "retención que sobe\n"
            "la Vel. de."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_DittoPowder,
        .iconPalette = gItemIconPalette_QuickPowder,
    },

    [ITEM_DEEP_SEA_SCALE] =
    {
        .name = ITEM_NAME("Deep Sea Scale"),
        .nombre = ITEM_NAME("Deep Sea Scale"),
        .price = (I_PRICE >= GEN_7) ? 2000 : 200,
        .holdEffect = HOLD_EFFECT_DEEP_SEA_SCALE,
        .description = COMPOUND_STRING(
            "A hold item that\n"
            "boosts the Sp. Def\n"
            "of Clamperl."),
        .descricao = COMPOUND_STRING(
            "Um item de espera\n"
            "que sobe o Sp. Def.\n"
            "de Clamperl."),
        .descricion = COMPOUND_STRING(
            "Un elemento de\n"
            "retención que sobe\n"
            "el Sp. Def."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = EVO_HELD_ITEM_TYPE,
        .fieldUseFunc = EVO_HELD_ITEM_FIELD_FUNC,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
        .iconPic = gItemIcon_DeepSeaScale,
        .iconPalette = gItemIconPalette_DeepSeaScale,
    },

    [ITEM_DEEP_SEA_TOOTH] =
    {
        .name = ITEM_NAME("Deep Sea Tooth"),
        .nombre = ITEM_NAME("Deep Sea Tooth"),
        .pluralName = ITEM_PLURAL_NAME("Deep Sea Teeth"),
        .price = (I_PRICE >= GEN_7) ? 2000 : 200,
        .holdEffect = HOLD_EFFECT_DEEP_SEA_TOOTH,
        .description = COMPOUND_STRING(
            "A hold item that\n"
            "boosts the Sp. Atk\n"
            "of Clamperl."),
        .descricao = COMPOUND_STRING(
            "Um item de espera\n"
            "que sobe o Sp. Atq.\n"
            "de Clamperl."),
        .descricion = COMPOUND_STRING(
            "Un elemento de\n"
            "retención que sobe\n"
            "el Sp. Atq."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = EVO_HELD_ITEM_TYPE,
        .fieldUseFunc = EVO_HELD_ITEM_FIELD_FUNC,
        .effect = gItemEffect_EvoItem,
        .flingPower = 90,
        .iconPic = gItemIcon_DeepSeaTooth,
        .iconPalette = gItemIconPalette_DeepSeaTooth,
    },

    [ITEM_SOUL_DEW] =
    {
        .name = ITEM_NAME("Soul Dew"),
        .nombre = ITEM_NAME("Rocio del alma"),
        .price = (I_PRICE >= GEN_7) ? 0 : 200,
        .holdEffect = HOLD_EFFECT_SOUL_DEW,
        .holdEffectParam = B_SOUL_DEW_BOOST >= GEN_7 ? 20 : 50,
        .description = COMPOUND_STRING(
        #if B_SOUL_DEW_BOOST >= GEN_7
            "Powers up Latios' &\n"
            "Latias' Psychic and\n"
            "Dragon-type moves."),
        .descricao = COMPOUND_STRING(
            "Aumenta os golpes\n"
            "psíquicos e do tipo\n"
            "dragão de Latios e."),
        .descricion = COMPOUND_STRING(
            "Potencia los movs.\n"
            "psíquicos y de tipo\n"
            "dragón de Latios y."),
        #else
            "Hold item: raises\n"
            "Sp. Atk & Sp. Def\n"
            "of Latios & Latias."),
        #endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SPECIAL_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_SoulDew,
        .iconPalette = gItemIconPalette_SoulDew,
    },

    [ITEM_ADAMANT_ORB] =
    {
        .name = ITEM_NAME("Adamant Orb"),
        .nombre = ITEM_NAME("Orbe Adamant"),
        .price = (I_PRICE >= GEN_7) ? 0 : 10000,
        .holdEffect = HOLD_EFFECT_ADAMANT_ORB,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "Powers up Dialga's\n"
            "Dragon and Steel-\n"
            "type moves."),
        .descricao = COMPOUND_STRING(
            "Potencializa os\n"
            "golpes do tipo\n"
            "Dragão e Aço de."),
        .descricion = COMPOUND_STRING(
            "Potencia los movs.\n"
            "tipo Dragón y Acero\n"
            "de Dialga."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SPECIAL_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 60,
        .iconPic = gItemIcon_AdamantOrb,
        .iconPalette = gItemIconPalette_AdamantOrb,
    },

    [ITEM_LUSTROUS_ORB] =
    {
        .name = ITEM_NAME("Lustrous Orb"),
        .nombre = ITEM_NAME("Orbe brillante"),
        .price = (I_PRICE >= GEN_7) ? 0 : 10000,
        .holdEffect = HOLD_EFFECT_LUSTROUS_ORB,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "Powers up Palkia's\n"
            "Dragon and Water-\n"
            "type moves."),
        .descricao = COMPOUND_STRING(
            "Potencializa os\n"
            "golpes do tipo\n"
            "Dragão e Água de."),
        .descricion = COMPOUND_STRING(
            "Potencia los movs.\n"
            "tipo Dragón y Agua\n"
            "de Palkia."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SPECIAL_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 60,
        .iconPic = gItemIcon_LustrousOrb,
        .iconPalette = gItemIconPalette_LustrousOrb,
    },

    [ITEM_GRISEOUS_ORB] =
    {
        .name = ITEM_NAME("Griseous Orb"),
        .nombre = ITEM_NAME("Orbe grisaceo"),
        .price = (I_PRICE >= GEN_7) ? 0 : 10000,
        .holdEffect = HOLD_EFFECT_GRISEOUS_ORB,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "Boosts Giratina's\n"
            "Dragon and Ghost-\n"
            "type moves."),
        .descricao = COMPOUND_STRING(
            "Aumenta os golpes\n"
            "do tipo Dragão e\n"
            "Fantasma de."),
        .descricion = COMPOUND_STRING(
            "Potencia los movs.\n"
            "tipo Dragón y\n"
            "Fantasma de."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SPECIAL_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 60,
        .iconPic = gItemIcon_GriseousOrb,
        .iconPalette = gItemIconPalette_GriseousOrb,
    },

// Incenses

    [ITEM_SEA_INCENSE] =
    {
        .name = ITEM_NAME("Sea Incense"),
        .nombre = ITEM_NAME("Incienso de mar"),
        .price = (I_PRICE >= GEN_7) ? 2000 : 9600,
        .holdEffect = HOLD_EFFECT_TYPE_POWER,
        .holdEffectParam = I_TYPE_BOOST_POWER >= GEN_4 ? 20 : 5,
        .description = sSeaIncenseDesc,
        .descricao = COMPOUND_STRING(
            "Um item retenção\n"
            "sobe pouco golpes\n"
            "tipo Água."),
        .descricion = COMPOUND_STRING(
            "Un elemento de\n"
            "retención que\n"
            "potencia poco los."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_INCENSE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_WATER,
        .flingPower = 10,
        .iconPic = gItemIcon_SeaIncense,
        .iconPalette = gItemIconPalette_SeaIncense,
    },

    [ITEM_LAX_INCENSE] =
    {
        .name = ITEM_NAME("Lax Incense"),
        .nombre = ITEM_NAME("Incienso laxo"),
        .price = (I_PRICE >= GEN_7) ? 5000 : 9600,
        .holdEffect = HOLD_EFFECT_EVASION_UP,
    #if I_LAX_INCENSE_BOOST >= GEN_4
        .holdEffectParam = 10,
        .description = COMPOUND_STRING(
            "A hold item that\n"
            "cuts the foe's\n"
            "acc."),
    #else
        .holdEffectParam = 5,
        .description = COMPOUND_STRING(
            "A hold item that\n"
            "mildly cuts the\n"
            "foe's acc."),
    #endif

        .descricao = COMPOUND_STRING(
            "Um item de retenção\n"
            "que diminui a prec.\n"
            "do alvo."),
        .descricion = COMPOUND_STRING(
            "Un objeto retención\n"
            "reduce la precisión\n"
            "del."),        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_INCENSE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_LaxIncense,
        .iconPalette = gItemIconPalette_LaxIncense,
    },

    [ITEM_ODD_INCENSE] =
    {
        .name = ITEM_NAME("Odd Incense"),
        .nombre = ITEM_NAME("Incienso extrano"),
        .price = (I_PRICE >= GEN_7) ? 2000 : 9600,
        .holdEffect = HOLD_EFFECT_TYPE_POWER,
        .holdEffectParam = 20,
        .description = sOddIncenseDesc,
        .descricao = COMPOUND_STRING(
            "Um item de retenção\n"
            "que sobe golpes do\n"
            "tipo Psíquico."),
        .descricion = COMPOUND_STRING(
            "Un elemento de\n"
            "retención que\n"
            "potencia los movs."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_INCENSE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_PSYCHIC,
        .flingPower = 10,
        .iconPic = gItemIcon_OddIncense,
        .iconPalette = gItemIconPalette_OddIncense,
    },

    [ITEM_ROCK_INCENSE] =
    {
        .name = ITEM_NAME("Rock Incense"),
        .nombre = ITEM_NAME("Incienso de roca"),
        .price = (I_PRICE >= GEN_7) ? 2000 : 9600,
        .holdEffect = HOLD_EFFECT_TYPE_POWER,
        .holdEffectParam = 20,
        .description = sRockIncenseDesc,
        .descricao = COMPOUND_STRING(
            "Um item de retenção\n"
            "que sobe o poder\n"
            "dos golpes do tipo."),
        .descricion = COMPOUND_STRING(
            "Un elemento de\n"
            "retención que sobe\n"
            "el poder de."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_INCENSE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ROCK,
        .flingPower = 10,
        .iconPic = gItemIcon_RockIncense,
        .iconPalette = gItemIconPalette_RockIncense,
    },

    [ITEM_FULL_INCENSE] =
    {
        .name = ITEM_NAME("Full Incense"),
        .nombre = ITEM_NAME("Incienso completo"),
        .price = (I_PRICE >= GEN_7) ? 5000 : 9600,
        .holdEffect = HOLD_EFFECT_LAGGING_TAIL,
        .holdEffectParam = 5,
        .description = sFullIncenseDesc,
        .descricao = COMPOUND_STRING(
            "Um item retido faz\n"
            "com suporte mova\n"
            "mais"),
        .descricion = COMPOUND_STRING(
            "Un objeto retenido\n"
            "que hace que quien\n"
            "lo posee se mueva."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_INCENSE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_FullIncense,
        .iconPalette = gItemIconPalette_FullIncense,
    },

    [ITEM_WAVE_INCENSE] =
    {
        .name = ITEM_NAME("Wave Incense"),
        .nombre = ITEM_NAME("Incienso Ola"),
        .price = (I_PRICE >= GEN_7) ? 2000 : 9600,
        .holdEffect = HOLD_EFFECT_TYPE_POWER,
        .holdEffectParam = 20,
        .description = sSeaIncenseDesc,
        .descricao = COMPOUND_STRING(
            "Um item retenção\n"
            "sobe pouco golpes\n"
            "tipo Água."),
        .descricion = COMPOUND_STRING(
            "Un elemento de\n"
            "retención que\n"
            "potencia poco los."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_INCENSE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_WATER,
        .flingPower = 10,
        .iconPic = gItemIcon_WaveIncense,
        .iconPalette = gItemIconPalette_WaveIncense,
    },

    [ITEM_ROSE_INCENSE] =
    {
        .name = ITEM_NAME("Rose Incense"),
        .nombre = ITEM_NAME("Incienso de rosas"),
        .price = (I_PRICE >= GEN_7) ? 2000 : 9600,
        .holdEffect = HOLD_EFFECT_TYPE_POWER,
        .holdEffectParam = 20,
        .description = sRoseIncenseDesc,
        .descricao = COMPOUND_STRING(
            "Um item de retenção\n"
            "que sobe o poder\n"
            "dos golpes do tipo."),
        .descricion = COMPOUND_STRING(
            "Un elemento de\n"
            "retención que sobe\n"
            "el poder de."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_INCENSE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_GRASS,
        .flingPower = 10,
        .iconPic = gItemIcon_RoseIncense,
        .iconPalette = gItemIconPalette_RoseIncense,
    },

    [ITEM_LUCK_INCENSE] =
    {
        .name = ITEM_NAME("Luck Incense"),
        .nombre = ITEM_NAME("Luck Incense"),
        .price = (I_PRICE >= GEN_7) ? 11000 : 9600,
        .holdEffect = HOLD_EFFECT_DOUBLE_PRIZE,
        .description = sLuckIncenseDesc,
        .descricao = COMPOUND_STRING(
            "Dobra o dinheiro na\n"
            "luta se o titular\n"
            "participar."),
        .descricion = COMPOUND_STRING(
            "Duplica el dinero\n"
            "en la batalla si el\n"
            "poseedor participa."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_INCENSE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_LuckIncense,
        .iconPalette = gItemIconPalette_LuckIncense,
    },

    [ITEM_PURE_INCENSE] =
    {
        .name = ITEM_NAME("Pure Incense"),
        .nombre = ITEM_NAME("Incienso Puro"),
        .price = (I_PRICE >= GEN_7) ? 6000 : 9600,
        .holdEffect = HOLD_EFFECT_REPEL,
        .description = sPureIncenseDesc,
        .descricao = COMPOUND_STRING(
            "Um item de retenção\n"
            "que ajuda a repelir\n"
            "Pokémon selv."),
        .descricion = COMPOUND_STRING(
            "Un objeto de\n"
            "retención que ayuda\n"
            "a repeler Pokémon."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_INCENSE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_PureIncense,
        .iconPalette = gItemIconPalette_PureIncense,
    },

// Contest Scarves

    [ITEM_RED_SCARF] =
    {
        .name = ITEM_NAME("Red Scarf"),
        .nombre = ITEM_NAME("Bufanda roja"),
        .pluralName = ITEM_PLURAL_NAME("Red Scarves"),
        .price = 100,
        .description = COMPOUND_STRING(
            "A hold item that\n"
            "boosts Cool in\n"
            "Contests."),
        .descricao = COMPOUND_STRING(
            "Um item de espera\n"
            "que sobe o Cool em\n"
            "concursos."),
        .descricion = COMPOUND_STRING(
            "Un elemento de\n"
            "retención que sobe\n"
            "la calma en."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_CONTEST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_Scarf,
        .iconPalette = gItemIconPalette_RedScarf,
    },

    [ITEM_BLUE_SCARF] =
    {
        .name = ITEM_NAME("Blue Scarf"),
        .nombre = ITEM_NAME("Bufanda azul"),
        .pluralName = ITEM_PLURAL_NAME("Blue Scarves"),
        .price = 100,
        .description = COMPOUND_STRING(
            "A hold item that\n"
            "boosts Beauty in\n"
            "Contests."),
        .descricao = COMPOUND_STRING(
            "Um item de espera\n"
            "que sobe a Beleza\n"
            "em Concursos."),
        .descricion = COMPOUND_STRING(
            "Un elemento de\n"
            "retención que sobe\n"
            "la belleza."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_CONTEST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_Scarf,
        .iconPalette = gItemIconPalette_BlueScarf,
    },

    [ITEM_PINK_SCARF] =
    {
        .name = ITEM_NAME("Pink Scarf"),
        .nombre = ITEM_NAME("Bufanda rosa"),
        .pluralName = ITEM_PLURAL_NAME("Pink Scarves"),
        .price = 100,
        .description = COMPOUND_STRING(
            "A hold item that\n"
            "boosts Cute in\n"
            "Contests."),
        .descricao = COMPOUND_STRING(
            "Um item de espera\n"
            "que sobe o Cute em\n"
            "concursos."),
        .descricion = COMPOUND_STRING(
            "Un elemento\n"
            "retenido genera\n"
            "Cute en los."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_CONTEST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_Scarf,
        .iconPalette = gItemIconPalette_PinkScarf,
    },

    [ITEM_GREEN_SCARF] =
    {
        .name = ITEM_NAME("Green Scarf"),
        .nombre = ITEM_NAME("Bufanda verde"),
        .pluralName = ITEM_PLURAL_NAME("Green Scarves"),
        .price = 100,
        .description = COMPOUND_STRING(
            "A hold item that\n"
            "boosts Smart in\n"
            "Contests."),
        .descricao = COMPOUND_STRING(
            "Um item de espera\n"
            "que sobe a\n"
            "Inteligência em."),
        .descricion = COMPOUND_STRING(
            "Un elemento de\n"
            "retención que sobe\n"
            "la."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_CONTEST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_Scarf,
        .iconPalette = gItemIconPalette_GreenScarf,
    },

    [ITEM_YELLOW_SCARF] =
    {
        .name = ITEM_NAME("Yellow Scarf"),
        .nombre = ITEM_NAME("Bufanda amarilla"),
        .pluralName = ITEM_PLURAL_NAME("Yellow Scarves"),
        .price = 100,
        .description = COMPOUND_STRING(
            "A hold item that\n"
            "boosts Tough in\n"
            "Contests."),
        .descricao = COMPOUND_STRING(
            "Um item de espera\n"
            "que sobe a\n"
            "Resistência em."),
        .descricion = COMPOUND_STRING(
            "Un elemento de\n"
            "retención que sobe\n"
            "la dureza en"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_CONTEST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_Scarf,
        .iconPalette = gItemIconPalette_YellowScarf,
    },

// EV Gain Modifiers

    [ITEM_MACHO_BRACE] =
    {
        .name = ITEM_NAME("Macho Brace"),
        .nombre = ITEM_NAME("Macho Brace"),
        .price = 3000,
        .holdEffect = HOLD_EFFECT_MACHO_BRACE,
        .description = COMPOUND_STRING(
            "A hold item that\n"
            "promotes growth,\n"
            "but cuts Speed."),
        .descricao = COMPOUND_STRING(
            "Um item de retenção\n"
            "que promove o\n"
            "crescimento, mas."),
        .descricion = COMPOUND_STRING(
            "Un elemento de\n"
            "retención que\n"
            "promueve el."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EV_BOOST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 60,
        .iconPic = gItemIcon_MachoBrace,
        .iconPalette = gItemIconPalette_MachoBrace,
    },

    [ITEM_POWER_WEIGHT] =
    {
        .name = ITEM_NAME("Power Weight"),
        .nombre = ITEM_NAME("Peso de potencia"),
        .price = (I_PRICE >= GEN_9) ? 10000 : 3000,
        .holdEffect = HOLD_EFFECT_POWER_ITEM,
        .holdEffectParam = POWER_ITEM_BOOST,
        .description = COMPOUND_STRING(
            "A hold item that\n"
            "promotes HP gain,\n"
            "but cuts Speed."),
        .descricao = COMPOUND_STRING(
            "Um item de retenção\n"
            "que promove o ganho\n"
            "de HP, mas reduz a."),
        .descricion = COMPOUND_STRING(
            "Un elemento\n"
            "retención promueve\n"
            "la ganancia"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EV_BOOST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = STAT_HP,
        .flingPower = 70,
        .iconPic = gItemIcon_PowerWeight,
        .iconPalette = gItemIconPalette_PowerWeight,
    },

    [ITEM_POWER_BRACER] =
    {
        .name = ITEM_NAME("Power Bracer"),
        .nombre = ITEM_NAME("Brazalete de poder"),
        .price = (I_PRICE >= GEN_9) ? 10000 : 3000,
        .holdEffect = HOLD_EFFECT_POWER_ITEM,
        .holdEffectParam = POWER_ITEM_BOOST,
        .description = COMPOUND_STRING(
            "A hold item that\n"
            "promotes Atk gain,\n"
            "but cuts Speed."),
        .descricao = COMPOUND_STRING(
            "Um item retenção\n"
            "promove ganho Atk,\n"
            "mas reduz"),
        .descricion = COMPOUND_STRING(
            "Un elemento\n"
            "retención promueve\n"
            "la ganancia"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EV_BOOST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = STAT_ATK,
        .flingPower = 70,
        .iconPic = gItemIcon_PowerBracer,
        .iconPalette = gItemIconPalette_PowerBracer,
    },

    [ITEM_POWER_BELT] =
    {
        .name = ITEM_NAME("Power Belt"),
        .nombre = ITEM_NAME("Cinturon de poder"),
        .price = (I_PRICE >= GEN_9) ? 10000 : 3000,
        .holdEffect = HOLD_EFFECT_POWER_ITEM,
        .holdEffectParam = POWER_ITEM_BOOST,
        .description = COMPOUND_STRING(
            "A hold item that\n"
            "promotes Def gain,\n"
            "but cuts Speed."),
        .descricao = COMPOUND_STRING(
            "Um item de retenção\n"
            "que promove ganho\n"
            "de Def, mas reduz."),
        .descricion = COMPOUND_STRING(
            "Un elemento\n"
            "retención promueve\n"
            "la ganancia"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EV_BOOST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = STAT_DEF,
        .flingPower = 70,
        .iconPic = gItemIcon_PowerBelt,
        .iconPalette = gItemIconPalette_PowerBelt,
    },

    [ITEM_POWER_LENS] =
    {
        .name = ITEM_NAME("Power Lens"),
        .nombre = ITEM_NAME("Lente de potencia"),
        .pluralName = ITEM_PLURAL_NAME("Power Lenses"),
        .price = (I_PRICE >= GEN_9) ? 10000 : 3000,
        .holdEffect = HOLD_EFFECT_POWER_ITEM,
        .holdEffectParam = POWER_ITEM_BOOST,
        .description = COMPOUND_STRING(
            "Hold item that pro-\n"
            "motes Sp. Atk gain,\n"
            "but cuts Speed."),
        .descricao = COMPOUND_STRING(
            "Segure item promova\n"
            "Sp. Ganho Atk, mas\n"
            "reduz Vel."),
        .descricion = COMPOUND_STRING(
            "Mantenga artículos\n"
            "que promuevan Sp.\n"
            "Ganancia de Atq.,."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EV_BOOST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = STAT_SPATK,
        .flingPower = 70,
        .iconPic = gItemIcon_PowerLens,
        .iconPalette = gItemIconPalette_PowerLens,
    },

    [ITEM_POWER_BAND] =
    {
        .name = ITEM_NAME("Power Band"),
        .nombre = ITEM_NAME("Banda de poder"),
        .price = (I_PRICE >= GEN_9) ? 10000 : 3000,
        .holdEffect = HOLD_EFFECT_POWER_ITEM,
        .holdEffectParam = POWER_ITEM_BOOST,
        .description = COMPOUND_STRING(
            "Hold item that pro-\n"
            "motes Sp. Def gain,\n"
            "but cuts Speed."),
        .descricao = COMPOUND_STRING(
            "Segure item promova\n"
            "Sp. Ganho\n"
            "definição, mas."),
        .descricion = COMPOUND_STRING(
            "Mantenga artículos\n"
            "que promuevan Sp.\n"
            "Ganancia de."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EV_BOOST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = STAT_SPDEF,
        .flingPower = 70,
        .iconPic = gItemIcon_PowerBand,
        .iconPalette = gItemIconPalette_PowerBand,
    },

    [ITEM_POWER_ANKLET] =
    {
        .name = ITEM_NAME("Power Anklet"),
        .nombre = ITEM_NAME("Tobillera de poder"),
        .price = (I_PRICE >= GEN_9) ? 10000 : 3000,
        .holdEffect = HOLD_EFFECT_POWER_ITEM,
        .holdEffectParam = POWER_ITEM_BOOST,
        .description = COMPOUND_STRING(
            "A hold item that\n"
            "promotes Spd gain,\n"
            "but cuts Speed."),
        .descricao = COMPOUND_STRING(
            "Um item de retenção\n"
            "que promove ganho\n"
            "de Vel., mas reduz."),
        .descricion = COMPOUND_STRING(
            "Un elemento\n"
            "retención promueve\n"
            "la ganancia"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EV_BOOST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = STAT_SPEED,
        .flingPower = 70,
        .iconPic = gItemIcon_PowerAnklet,
        .iconPalette = gItemIconPalette_PowerAnklet,
    },

// Type-boosting Held Items
    #if I_PRICE >= GEN_9
        #define TYPE_BOOSTING_PRICE 3000
    #elif I_PRICE >= GEN_7
        #define TYPE_BOOSTING_PRICE 1000
    #else
        #define TYPE_BOOSTING_PRICE 100
    #endif

    [ITEM_SILK_SCARF] =
    {
        .name = ITEM_NAME("Silk Scarf"),
        .nombre = ITEM_NAME("Bufanda de seda"),
        .pluralName = ITEM_PLURAL_NAME("Silk Scarves"),
        .price = TYPE_BOOSTING_PRICE,
        .holdEffect = HOLD_EFFECT_TYPE_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "A hold item that\n"
            "boosts the power of\n"
            "Normal-type moves."),
        .descricao = COMPOUND_STRING(
            "Um item de retenção\n"
            "que sobe o poder\n"
            "dos golpes do tipo."),
        .descricion = COMPOUND_STRING(
            "Un elemento de\n"
            "retención que sobe\n"
            "el poder de."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TYPE_BOOST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_NORMAL,
        .flingPower = 10,
        .iconPic = gItemIcon_SilkScarf,
        .iconPalette = gItemIconPalette_SilkScarf,
    },

    [ITEM_CHARCOAL] =
    {
        .name = ITEM_NAME("Charcoal"),
        .nombre = ITEM_NAME("carbon"),
    #if I_PRICE >= GEN_9
        .price = 3000,
    #elif I_PRICE >= GEN_7
        .price = 1000,
    #else
        .price = 9800,
    #endif
        .holdEffect = HOLD_EFFECT_TYPE_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "A hold item that\n"
            "boosts the power of\n"
            "Fire-type moves."),
        .descricao = COMPOUND_STRING(
            "Um item de retenção\n"
            "que sobe o poder\n"
            "dos golpes do tipo."),
        .descricion = COMPOUND_STRING(
            "Un elemento de\n"
            "retención que sobe\n"
            "el poder de."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TYPE_BOOST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FIRE,
        .flingPower = 30,
        .iconPic = gItemIcon_Charcoal,
        .iconPalette = gItemIconPalette_Charcoal,
    },

    [ITEM_MYSTIC_WATER] =
    {
        .name = ITEM_NAME("Mystic Water"),
        .nombre = ITEM_NAME("Agua mistica"),
        .price = TYPE_BOOSTING_PRICE,
        .holdEffect = HOLD_EFFECT_TYPE_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "A hold item that\n"
            "boosts the power of\n"
            "Water-type moves."),
        .descricao = COMPOUND_STRING(
            "Um item de retenção\n"
            "que sobe o poder\n"
            "dos golpes do tipo."),
        .descricion = COMPOUND_STRING(
            "Un elemento de\n"
            "retención que sobe\n"
            "el poder de."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TYPE_BOOST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_WATER,
        .flingPower = 30,
        .iconPic = gItemIcon_MysticWater,
        .iconPalette = gItemIconPalette_MysticWater,
    },

    [ITEM_MAGNET] =
    {
        .name = ITEM_NAME("Magnet"),
        .nombre = ITEM_NAME("Iman"),
        .price = TYPE_BOOSTING_PRICE,
        .holdEffect = HOLD_EFFECT_TYPE_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "A hold item that\n"
            "boosts Electric-\n"
            "type moves."),
        .descricao = COMPOUND_STRING(
            "Um item de retenção\n"
            "que sobe golpes do\n"
            "tipo Elétrico."),
        .descricion = COMPOUND_STRING(
            "Un elemento de\n"
            "retención que\n"
            "potencia los movs."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TYPE_BOOST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ELECTRIC,
        .flingPower = 30,
        .iconPic = gItemIcon_Magnet,
        .iconPalette = gItemIconPalette_Magnet,
    },

    [ITEM_MIRACLE_SEED] =
    {
        .name = ITEM_NAME("Miracle Seed"),
        .nombre = ITEM_NAME("Semilla milagrosa"),
        .price = TYPE_BOOSTING_PRICE,
        .holdEffect = HOLD_EFFECT_TYPE_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = sRoseIncenseDesc,
        .descricao = COMPOUND_STRING(
            "Um item de retenção\n"
            "que sobe o poder\n"
            "dos golpes do tipo."),
        .descricion = COMPOUND_STRING(
            "Un elemento de\n"
            "retención que sobe\n"
            "el poder de."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TYPE_BOOST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_GRASS,
        .flingPower = 30,
        .iconPic = gItemIcon_MiracleSeed,
        .iconPalette = gItemIconPalette_MiracleSeed,
    },

    [ITEM_NEVER_MELT_ICE] =
    {
        .name = ITEM_NAME("Never-Melt Ice"),
        .nombre = ITEM_NAME("Never-Melt Ice"),
        .price = TYPE_BOOSTING_PRICE,
        .holdEffect = HOLD_EFFECT_TYPE_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "A hold item that\n"
            "boosts the power of\n"
            "Ice-type moves."),
        .descricao = COMPOUND_STRING(
            "Um item de retenção\n"
            "que sobe o poder\n"
            "dos golpes do tipo."),
        .descricion = COMPOUND_STRING(
            "Un elemento de\n"
            "retención que sobe\n"
            "el poder de."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TYPE_BOOST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ICE,
        .flingPower = 30,
        .iconPic = gItemIcon_NeverMeltIce,
        .iconPalette = gItemIconPalette_NeverMeltIce,
    },

    [ITEM_BLACK_BELT] =
    {
        .name = ITEM_NAME("Black Belt"),
        .nombre = ITEM_NAME("cinturon negro"),
        .price = TYPE_BOOSTING_PRICE,
        .holdEffect = HOLD_EFFECT_TYPE_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "A hold item that\n"
            "boosts Fighting-\n"
            "type moves."),
        .descricao = COMPOUND_STRING(
            "Um item de retenção\n"
            "que sobe golpes do\n"
            "tipo Fighting."),
        .descricion = COMPOUND_STRING(
            "Un elemento de\n"
            "retención que\n"
            "potencia los movs."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TYPE_BOOST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FIGHTING,
        .flingPower = 30,
        .iconPic = gItemIcon_BlackBelt,
        .iconPalette = gItemIconPalette_BlackTypeEnhancingItem,
    },

    [ITEM_POISON_BARB] =
    {
        .name = ITEM_NAME("Poison Barb"),
        .nombre = ITEM_NAME("Pua venenosa"),
        .price = TYPE_BOOSTING_PRICE,
        .holdEffect = HOLD_EFFECT_TYPE_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "A hold item that\n"
            "boosts the power of\n"
            "Poison-type moves."),
        .descricao = COMPOUND_STRING(
            "Um item de retenção\n"
            "que sobe o poder\n"
            "dos golpes do tipo."),
        .descricion = COMPOUND_STRING(
            "Un elemento de\n"
            "retención que sobe\n"
            "el poder de."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TYPE_BOOST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_POISON,
        .flingPower = 70,
        .iconPic = gItemIcon_PoisonBarb,
        .iconPalette = gItemIconPalette_PoisonBarb,
    },

    [ITEM_SOFT_SAND] =
    {
        .name = ITEM_NAME("Soft Sand"),
        .nombre = ITEM_NAME("Arena suave"),
        .pluralName = ITEM_PLURAL_NAME("Soft Sand"),
        .price = TYPE_BOOSTING_PRICE,
        .holdEffect = HOLD_EFFECT_TYPE_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "A hold item that\n"
            "boosts the power of\n"
            "Ground-type moves."),
        .descricao = COMPOUND_STRING(
            "Um item de retenção\n"
            "que sobe o poder\n"
            "dos golpes do tipo."),
        .descricion = COMPOUND_STRING(
            "Un elemento de\n"
            "retención que sobe\n"
            "el poder de."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TYPE_BOOST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_GROUND,
        .flingPower = 10,
        .iconPic = gItemIcon_Sand,
        .iconPalette = gItemIconPalette_SoftSand,
    },

    [ITEM_SHARP_BEAK] =
    {
        .name = ITEM_NAME("Sharp Beak"),
        .nombre = ITEM_NAME("Pico afilado"),
        .price = TYPE_BOOSTING_PRICE,
        .holdEffect = HOLD_EFFECT_TYPE_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "A hold item that\n"
            "boosts the power of\n"
            "Flying-type moves."),
        .descricao = COMPOUND_STRING(
            "Um item de retenção\n"
            "que sobe o poder\n"
            "dos golpes do tipo."),
        .descricion = COMPOUND_STRING(
            "Un elemento de\n"
            "retención que sobe\n"
            "el poder de."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TYPE_BOOST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FLYING,
        .flingPower = 50,
        .iconPic = gItemIcon_SharpBeak,
        .iconPalette = gItemIconPalette_SharpBeak,
    },

    [ITEM_TWISTED_SPOON] =
    {
        .name = ITEM_NAME("Twisted Spoon"),
        .nombre = ITEM_NAME("Cuchara torcida"),
        .price = TYPE_BOOSTING_PRICE,
        .holdEffect = HOLD_EFFECT_TYPE_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = sOddIncenseDesc,
        .descricao = COMPOUND_STRING(
            "Um item de retenção\n"
            "que sobe golpes do\n"
            "tipo Psíquico."),
        .descricion = COMPOUND_STRING(
            "Un elemento de\n"
            "retención que\n"
            "potencia los movs."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TYPE_BOOST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_PSYCHIC,
        .flingPower = 30,
        .iconPic = gItemIcon_TwistedSpoon,
        .iconPalette = gItemIconPalette_TwistedSpoon,
    },

    [ITEM_SILVER_POWDER] =
    {
        .name = ITEM_NAME("Silver Powder"),
        .nombre = ITEM_NAME("Polvo de plata"),
        .price = TYPE_BOOSTING_PRICE,
        .holdEffect = HOLD_EFFECT_TYPE_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "A hold item that\n"
            "boosts the power of\n"
            "Bug-type moves."),
        .descricao = COMPOUND_STRING(
            "Um item de retenção\n"
            "que sobe o poder\n"
            "dos golpes do tipo."),
        .descricion = COMPOUND_STRING(
            "Un elemento de\n"
            "retención que sobe\n"
            "el poder de."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TYPE_BOOST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_BUG,
        .flingPower = 10,
        .iconPic = gItemIcon_SilverPowder,
        .iconPalette = gItemIconPalette_SilverPowder,
    },

    [ITEM_HARD_STONE] =
    {
        .name = ITEM_NAME("Hard Stone"),
        .nombre = ITEM_NAME("P. dura"),
        .price = TYPE_BOOSTING_PRICE,
        .holdEffect = HOLD_EFFECT_TYPE_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = sRockIncenseDesc,
        .descricao = COMPOUND_STRING(
            "Um item de retenção\n"
            "que sobe o poder\n"
            "dos golpes do tipo."),
        .descricion = COMPOUND_STRING(
            "Un elemento de\n"
            "retención que sobe\n"
            "el poder de."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TYPE_BOOST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ROCK,
        .flingPower = 100,
        .iconPic = gItemIcon_HardStone,
        .iconPalette = gItemIconPalette_HardStone,
    },

    [ITEM_SPELL_TAG] =
    {
        .name = ITEM_NAME("Spell Tag"),
        .nombre = ITEM_NAME("Etiq. de hechizo"),
        .price = TYPE_BOOSTING_PRICE,
        .holdEffect = HOLD_EFFECT_TYPE_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "A hold item that\n"
            "boosts the power of\n"
            "Ghost-type moves."),
        .descricao = COMPOUND_STRING(
            "Um item de retenção\n"
            "que sobe o poder\n"
            "dos golpes do tipo."),
        .descricion = COMPOUND_STRING(
            "Un elemento de\n"
            "retención que sobe\n"
            "el poder de."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TYPE_BOOST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_GHOST,
        .flingPower = 30,
        .iconPic = gItemIcon_SpellTag,
        .iconPalette = gItemIconPalette_SpellTag,
    },

    [ITEM_DRAGON_FANG] =
    {
        .name = ITEM_NAME("Dragon Fang"),
        .nombre = ITEM_NAME("colmillo de dragon"),
        .price = TYPE_BOOSTING_PRICE,
        .holdEffect = HOLD_EFFECT_TYPE_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "A hold item that\n"
            "boosts the power of\n"
            "Dragon-type moves."),
        .descricao = COMPOUND_STRING(
            "Um item de retenção\n"
            "que sobe o poder\n"
            "dos golpes do tipo."),
        .descricion = COMPOUND_STRING(
            "Un objeto de\n"
            "retención que sobe\n"
            "el poder de."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TYPE_BOOST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_DRAGON,
        .flingPower = 70,
        .iconPic = gItemIcon_DragonFang,
        .iconPalette = gItemIconPalette_DragonFang,
    },

    [ITEM_BLACK_GLASSES] =
    {
        .name = ITEM_NAME("Black Glasses"),
        .nombre = ITEM_NAME("Gafas Negras"),
        .pluralName = ITEM_PLURAL_NAME("Black Glasses"),
        .price = TYPE_BOOSTING_PRICE,
        .holdEffect = HOLD_EFFECT_TYPE_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "A hold item that\n"
            "boosts the power of\n"
            "Dark-type moves."),
        .descricao = COMPOUND_STRING(
            "Um item de retenção\n"
            "que sobe o poder\n"
            "dos golpes do tipo."),
        .descricion = COMPOUND_STRING(
            "Un elemento de\n"
            "retención que sobe\n"
            "el poder de."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TYPE_BOOST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_DARK,
        .flingPower = 30,
        .iconPic = gItemIcon_BlackGlasses,
        .iconPalette = gItemIconPalette_BlackTypeEnhancingItem,
    },

    [ITEM_METAL_COAT] =
    {
        .name = ITEM_NAME("Metal Coat"),
        .nombre = ITEM_NAME("Metal Coat"),
    #if I_PRICE >= GEN_9
        .price = 3000,
    #elif I_PRICE >= GEN_7
        .price = 2000,
    #else
        .price = 100,
    #endif
        .holdEffect = HOLD_EFFECT_TYPE_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "A hold item that\n"
            "boosts the power of\n"
            "Steel-type moves."),
        .descricao = COMPOUND_STRING(
            "Um item de retenção\n"
            "que sobe o poder\n"
            "dos golpes do tipo."),
        .descricion = COMPOUND_STRING(
            "Un elemento de\n"
            "retención que sobe\n"
            "el poder de."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TYPE_BOOST_HELD_ITEM,
        .type = EVO_HELD_ITEM_TYPE,
        .fieldUseFunc = EVO_HELD_ITEM_FIELD_FUNC,
        .effect = gItemEffect_EvoItem,
        .secondaryId = TYPE_STEEL,
        .flingPower = 30,
        .iconPic = gItemIcon_MetalCoat,
        .iconPalette = gItemIconPalette_MetalCoat,
    },

// Choice Items

    [ITEM_CHOICE_BAND] =
    {
        .name = ITEM_NAME("Choice Band"),
        .nombre = ITEM_NAME("Banda eleg."),
    #if I_PRICE >= GEN_9
        .price = 100000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 100,
    #endif
        .holdEffect = HOLD_EFFECT_CHOICE_BAND,
        .description = COMPOUND_STRING(
            "Boosts Atk., but\n"
            "allows the use of\n"
            "only one move."),
        .descricao = COMPOUND_STRING(
            "Aumenta o Atq., mas\n"
            "permite o uso de\n"
            "apenas um golpe."),
        .descricion = COMPOUND_STRING(
            "Aumenta el Atq.,\n"
            "pero permite el uso\n"
            "de un solo mov."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_ChoiceBand,
        .iconPalette = gItemIconPalette_ChoiceBand,
    },

    [ITEM_CHOICE_SPECS] =
    {
        .name = ITEM_NAME("Choice Specs"),
        .nombre = ITEM_NAME("Choice Specs"),
        .pluralName = ITEM_PLURAL_NAME("Choice Specs"),
    #if I_PRICE >= GEN_9
        .price = 100000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 100,
    #endif
        .holdEffect = HOLD_EFFECT_CHOICE_SPECS,
        .description = COMPOUND_STRING(
            "Boosts Sp. Atk, but\n"
            "allows the use of\n"
            "only one move."),
        .descricao = COMPOUND_STRING(
            "Aumenta Sp. Atk,\n"
            "mas permite o uso\n"
            "de apenas um golpe."),
        .descricion = COMPOUND_STRING(
            "Aumenta Sp. Atk,\n"
            "pero permite el uso\n"
            "de un solo mov."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_ChoiceSpecs,
        .iconPalette = gItemIconPalette_ChoiceSpecs,
    },

    [ITEM_CHOICE_SCARF] =
    {
        .name = ITEM_NAME("Choice Scarf"),
        .nombre = ITEM_NAME("Eleccion Panuelo"),
        .pluralName = ITEM_PLURAL_NAME("Choice Scarves"),
    #if I_PRICE >= GEN_9
        .price = 100000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 100,
    #endif
        .holdEffect = HOLD_EFFECT_CHOICE_SCARF,
        .description = COMPOUND_STRING(
            "Boosts Speed, but\n"
            "allows the use of\n"
            "only one move."),
        .descricao = COMPOUND_STRING(
            "Aumenta a Vel., mas\n"
            "permite o uso de\n"
            "apenas um golpe."),
        .descricion = COMPOUND_STRING(
            "Aumenta la Vel.,\n"
            "pero permite el uso\n"
            "de un solo mov."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_ChoiceScarf,
        .iconPalette = gItemIconPalette_ChoiceScarf,
    },

// Status Orbs

    [ITEM_FLAME_ORB] =
    {
        .name = ITEM_NAME("Flame Orb"),
        .nombre = ITEM_NAME("Orbe de llamas"),
    #if I_PRICE >= GEN_9
        .price = 15000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_FLAME_ORB,
        .description = COMPOUND_STRING(
            "A bizarre orb that\n"
            "inflicts a burn on\n"
            "holder in battle."),
        .descricao = COMPOUND_STRING(
            "Um orbe bizarro que\n"
            "queima o titular em\n"
            "luta."),
        .descricion = COMPOUND_STRING(
            "Un orbe extraño que\n"
            "inflige una\n"
            "quemadura al."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_FlameOrb,
        .iconPalette = gItemIconPalette_FlameOrb,
    },

    [ITEM_TOXIC_ORB] =
    {
        .name = ITEM_NAME("Toxic Orb"),
        .nombre = ITEM_NAME("Orbe toxico"),
    #if I_PRICE >= GEN_9
        .price = 15000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_TOXIC_ORB,
        .description = COMPOUND_STRING(
            "A bizarre orb that\n"
            "badly poisons the\n"
            "holder in battle."),
        .descricao = COMPOUND_STRING(
            "Um orbe bizarro que\n"
            "envenena gravemente\n"
            "o portador em."),
        .descricion = COMPOUND_STRING(
            "Un orbe extraño\n"
            "envenena gravemente\n"
            "quien lo posee en."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_ToxicOrb,
        .iconPalette = gItemIconPalette_ToxicOrb,
    },

// Weather Rocks

    [ITEM_DAMP_ROCK] =
    {
        .name = ITEM_NAME("Damp Rock"),
        .nombre = ITEM_NAME("Roca humeda"),
    #if I_PRICE >= GEN_9
        .price = 8000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_DAMP_ROCK,
        .description = COMPOUND_STRING(
            "Extends the length\n"
            "of Rain Dance if\n"
            "used by the holder."),
        .descricao = COMPOUND_STRING(
            "Estende a duração\n"
            "do Rain Dance se\n"
            "usado pelo titular."),
        .descricion = COMPOUND_STRING(
            "Extiende la\n"
            "duración Rain Dance\n"
            "si lo usa el."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 60,
        .iconPic = gItemIcon_DampRock,
        .iconPalette = gItemIconPalette_DampRock,
    },

    [ITEM_HEAT_ROCK] =
    {
        .name = ITEM_NAME("Heat Rock"),
        .nombre = ITEM_NAME("Roca de calor"),
    #if I_PRICE >= GEN_9
        .price = 8000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_HEAT_ROCK,
        .description = COMPOUND_STRING(
            "Extends the length\n"
            "of Sunny Day if\n"
            "used by the holder."),
        .descricao = COMPOUND_STRING(
            "Prolonga a duração\n"
            "do Sunny Day se\n"
            "usado pelo titular."),
        .descricion = COMPOUND_STRING(
            "Extiende la\n"
            "duración Sunny Day\n"
            "si lo utiliza el."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 60,
        .iconPic = gItemIcon_HeatRock,
        .iconPalette = gItemIconPalette_HeatRock,
    },

    [ITEM_SMOOTH_ROCK] =
    {
        .name = ITEM_NAME("Smooth Rock"),
        .nombre = ITEM_NAME("Roca Lisa"),
    #if I_PRICE >= GEN_9
        .price = 8000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_SMOOTH_ROCK,
        .description = COMPOUND_STRING(
            "Extends the length\n"
            "of Sandstorm if\n"
            "used by the holder."),
        .descricao = COMPOUND_STRING(
            "Estende a duração\n"
            "do Sandstorm se\n"
            "usado pelo titular."),
        .descricion = COMPOUND_STRING(
            "Extiende la\n"
            "duración Sandstorm\n"
            "si lo usa el."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_SmoothRock,
        .iconPalette = gItemIconPalette_SmoothRock,
    },

    [ITEM_ICY_ROCK] =
    {
        .name = ITEM_NAME("Icy Rock"),
        .nombre = ITEM_NAME("roca helada"),
    #if I_PRICE >= GEN_9
        .price = 8000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_ICY_ROCK,
    #if B_PREFERRED_ICE_WEATHER == B_ICE_WEATHER_HAIL
        .description = COMPOUND_STRING(
            "Extends the length\n"
            "of the move Hail\n"
            "used by the holder."),
    #elif B_PREFERRED_ICE_WEATHER == B_ICE_WEATHER_SNOW
        .description = COMPOUND_STRING(
            "Extends the length\n"
            "of Snowscape if\n"
            "used by the holder."),
    #else
        .description = COMPOUND_STRING(
            "Extends the length\n"
            "of cold weathers\n"
            "used by the holder."),
    #endif

        .descricao = COMPOUND_STRING(
            "Estende a duração\n"
            "do golpe Hail usado\n"
            "pelo titular."),
        .descricion = COMPOUND_STRING(
            "Extiende la\n"
            "duración del mov.\n"
            "Hail utilizado por."),        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 40,
        .iconPic = gItemIcon_IcyRock,
        .iconPalette = gItemIconPalette_IcyRock,
    },

// Terrain Seeds

    [ITEM_ELECTRIC_SEED] =
    {
        .name = ITEM_NAME("Electric Seed"),
        .nombre = ITEM_NAME("Semilla electrica"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 4000,
        .holdEffect = HOLD_EFFECT_TERRAIN_SEED,
        .holdEffectParam = HOLD_EFFECT_PARAM_ELECTRIC_TERRAIN,
        .description = COMPOUND_STRING(
            "Boosts Def. on\n"
            "Electric Terrain,\n"
            "but only one time."),
        .descricao = COMPOUND_STRING(
            "Aumenta a Def. em\n"
            "Terreno Elétrico,\n"
            "mas apenas uma vez."),
        .descricion = COMPOUND_STRING(
            "Aumenta la defensa\n"
            "en terreno\n"
            "eléctrico, pero."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_TerrainSeed,
        .iconPalette = gItemIconPalette_ElectricSeed,
    },

    [ITEM_PSYCHIC_SEED] =
    {
        .name = ITEM_NAME("Psychic Seed"),
        .nombre = ITEM_NAME("Semilla psiquica"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 4000,
        .holdEffect = HOLD_EFFECT_TERRAIN_SEED,
        .holdEffectParam = HOLD_EFFECT_PARAM_PSYCHIC_TERRAIN,
        .description = COMPOUND_STRING(
            "Boosts Sp. Def. on\n"
            "Psychic Terrain,\n"
            "but only one time."),
        .descricao = COMPOUND_STRING(
            "Aumenta Sp.\n"
            "Definitivamente. em\n"
            "Psychic Terrain."),
        .descricion = COMPOUND_STRING(
            "Aumenta Sp. Def. en\n"
            "Psychic Terrain,\n"
            "pero solo una vez."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_TerrainSeed,
        .iconPalette = gItemIconPalette_PsychicSeed,
    },

    [ITEM_MISTY_SEED] =
    {
        .name = ITEM_NAME("Misty Seed"),
        .nombre = ITEM_NAME("Semilla brumosa"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 4000,
        .holdEffect = HOLD_EFFECT_TERRAIN_SEED,
        .holdEffectParam = HOLD_EFFECT_PARAM_MISTY_TERRAIN,
        .description = COMPOUND_STRING(
            "Boosts Sp. Def. on\n"
            "Misty Terrain, but\n"
            "only one time."),
        .descricao = COMPOUND_STRING(
            "Aumenta Sp.\n"
            "Definitivamente. em\n"
            "Misty Terrain, mas."),
        .descricion = COMPOUND_STRING(
            "Aumenta Sp. Def. en\n"
            "Misty Terrain, pero\n"
            "solo una vez."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_TerrainSeed,
        .iconPalette = gItemIconPalette_MistySeed,
    },

    [ITEM_GRASSY_SEED] =
    {
        .name = ITEM_NAME("Grassy Seed"),
        .nombre = ITEM_NAME("Semilla de hierba"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 4000,
        .holdEffect = HOLD_EFFECT_TERRAIN_SEED,
        .holdEffectParam = HOLD_EFFECT_PARAM_GRASSY_TERRAIN,
        .description = COMPOUND_STRING(
            "Boosts Def. on\n"
            "Grassy Terrain, but\n"
            "only one time."),
        .descricao = COMPOUND_STRING(
            "Aumenta a Def. em\n"
            "terreno gramado,\n"
            "mas apenas uma vez."),
        .descricion = COMPOUND_STRING(
            "Aumenta la defensa\n"
            "en terreno cubierto\n"
            "hierba, pero sólo"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_TerrainSeed,
        .iconPalette = gItemIconPalette_GrassySeed,
    },

// Type-activated Stat Modifiers

    [ITEM_ABSORB_BULB] =
    {
        .name = ITEM_NAME("Absorb Bulb"),
        .nombre = ITEM_NAME("Absorb. la bomb."),
    #if I_PRICE >= GEN_9
        .price = 5000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_ABSORB_BULB,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "Raises Sp. Atk if\n"
            "holder hit by\n"
            "Water-type move."),
        .descricao = COMPOUND_STRING(
            "Aumenta Sp. Ataca\n"
            "se o titular for\n"
            "atingido por um."),
        .descricion = COMPOUND_STRING(
            "Aumenta sp. Atk si\n"
            "el poseedor es\n"
            "golpeado por un."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_AbsorbBulb,
        .iconPalette = gItemIconPalette_AbsorbBulb,
    },

    [ITEM_CELL_BATTERY] =
    {
        .name = ITEM_NAME("Cell Battery"),
        .nombre = ITEM_NAME("Bateria de celda"),
        .pluralName = ITEM_PLURAL_NAME("Cell Batteries"),
    #if I_PRICE >= GEN_9
        .price = 5000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_CELL_BATTERY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "Raises Atk. if the\n"
            "holder is hit by an\n"
            "Electric move."),
        .descricao = COMPOUND_STRING(
            "Aumenta Atq.\n"
            "titular for\n"
            "atingido por golpe."),
        .descricion = COMPOUND_STRING(
            "Aumenta el Atq. si\n"
            "el portador es\n"
            "golpeado por un."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_CellBattery,
        .iconPalette = gItemIconPalette_CellBattery,
    },

    [ITEM_LUMINOUS_MOSS] =
    {
        .name = ITEM_NAME("Luminous Moss"),
        .nombre = ITEM_NAME("musgo luminoso"),
        .pluralName = ITEM_PLURAL_NAME("Luminous Moss"),
    #if I_PRICE >= GEN_9
        .price = 5000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 1000,
    #endif
        .holdEffect = HOLD_EFFECT_LUMINOUS_MOSS,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "Raises Sp. Def if\n"
            "holder hit by\n"
            "Water-type move."),
        .descricao = COMPOUND_STRING(
            "Aumenta Sp. Def\n"
            "titular for\n"
            "atingido por golpe."),
        .descricion = COMPOUND_STRING(
            "Aumenta sp. Def si\n"
            "el poseedor es\n"
            "golpeado por un."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_LuminousMoss,
        .iconPalette = gItemIconPalette_LuminousMoss,
    },

    [ITEM_SNOWBALL] =
    {
        .name = ITEM_NAME("Snowball"),
        .nombre = ITEM_NAME("bola de nieve"),
    #if I_PRICE >= GEN_9
        .price = 5000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_SNOWBALL,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "Raises Atk if its\n"
            "holder is hit by an\n"
            "Ice-type move."),
        .descricao = COMPOUND_STRING(
            "Aumenta Atk seu\n"
            "titular for\n"
            "atingido por golpe."),
        .descricion = COMPOUND_STRING(
            "Aumenta el Atk si\n"
            "su portador es\n"
            "golpeado por un."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_Snowball,
        .iconPalette = gItemIconPalette_Snowball,
    },

// Misc. Held Items

    [ITEM_BRIGHT_POWDER] =
    {
        .name = ITEM_NAME("Bright Powder"),
        .nombre = ITEM_NAME("Polvo brillante"),
    #if I_PRICE >= GEN_9
        .price = 30000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 10,
    #endif
        .holdEffect = HOLD_EFFECT_EVASION_UP,
        .holdEffectParam = 10,
        .description = COMPOUND_STRING(
            "A hold item that\n"
            "casts a glare to\n"
            "reduce acc."),
        .descricao = COMPOUND_STRING(
            "Um item de retenção\n"
            "que lança brilho\n"
            "para reduzir a."),
        .descricion = COMPOUND_STRING(
            "Un elemento de\n"
            "sujeción que\n"
            "proyecta un."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_BrightPowder,
        .iconPalette = gItemIconPalette_BrightPowder,
    },

    [ITEM_WHITE_HERB] =
    {
        .name = ITEM_NAME("White Herb"),
        .nombre = ITEM_NAME("Hierba blanca"),
    #if I_PRICE >= GEN_9
        .price = 20000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 100,
    #endif
        .holdEffect = HOLD_EFFECT_WHITE_HERB,
        .description = COMPOUND_STRING(
            "A hold item that\n"
            "heals any lowered\n"
            "stat."),
        .descricao = COMPOUND_STRING(
            "Um item de retenção\n"
            "que cura qualquer\n"
            "estatística"),
        .descricion = COMPOUND_STRING(
            "Un elemento\n"
            "retenido que cura\n"
            "cualquier."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_InBattleHerb,
        .iconPalette = gItemIconPalette_WhiteHerb,
    },

    [ITEM_EXP_SHARE] =
    {
        .name = ITEM_NAME("Exp. Share"),
        .nombre = ITEM_NAME("Exp. Compartir"),
        .holdEffect = HOLD_EFFECT_EXP_SHARE,
    #if I_EXP_SHARE_ITEM >= GEN_6
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING(
            "This device gives\n"
            "exp. to other party\n"
            "members."),
        .pocket = POCKET_KEY_ITEMS,
    #else
        .price = (I_PRICE == GEN_1) ? 1 : 3000,
        .description = COMPOUND_STRING(
            "A hold item that\n"
            "gets Exp. points\n"
            "from battles."),
        .descricao = COMPOUND_STRING(
            "Este dispositivo dá\n"
            "exp. para outros\n"
            "membros do partido."),
        .descricion = COMPOUND_STRING(
            "Este dispositivo da\n"
            "exp. a otros\n"
            "miembros del."),
        .pocket = POCKET_ITEMS,
    #endif
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_ExpShare,
        .flingPower = 30,
        .iconPic = gItemIcon_ExpShare,
        .iconPalette = gItemIconPalette_ExpShare,
    },

    [ITEM_QUICK_CLAW] =
    {
        .name = ITEM_NAME("Quick Claw"),
        .nombre = ITEM_NAME("Garra rapida"),
    #if I_PRICE >= GEN_9
        .price = 8000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 100,
    #endif
        .holdEffect = HOLD_EFFECT_QUICK_CLAW,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "A hold item that\n"
            "occasionally allows\n"
            "the first strike."),
        .descricao = COMPOUND_STRING(
            "Um item de retenção\n"
            "que ocasionalmente\n"
            "permite o primeiro."),
        .descricion = COMPOUND_STRING(
            "Un elemento de\n"
            "retención que\n"
            "ocasionalmente."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_QuickClaw,
        .iconPalette = gItemIconPalette_QuickClaw,
    },

    [ITEM_SOOTHE_BELL] =
    {
        .name = ITEM_NAME("Soothe Bell"),
        .nombre = ITEM_NAME("Calmar la campana"),
    #if I_PRICE >= GEN_9
        .price = 5000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 100,
    #endif
        .holdEffect = HOLD_EFFECT_FRIENDSHIP_UP,
        .description = COMPOUND_STRING(
            "A hold item that\n"
            "calms spirits and\n"
            "fosters friendship."),
        .descricao = COMPOUND_STRING(
            "Um item apoio\n"
            "acalma espíritos e\n"
            "promove amizade."),
        .descricion = COMPOUND_STRING(
            "Un elemento de\n"
            "sujeción que calma\n"
            "los espíritus y."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_SootheBell,
        .iconPalette = gItemIconPalette_SootheBell,
    },

    [ITEM_MENTAL_HERB] =
    {
        .name = ITEM_NAME("Mental Herb"),
        .nombre = ITEM_NAME("Hierba mental"),
    #if I_PRICE >= GEN_9
        .price = 10000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 100,
    #endif
        .holdEffect = HOLD_EFFECT_MENTAL_HERB,
        .description = COMPOUND_STRING(
        #if B_MENTAL_HERB >= GEN_5
            "Snaps Pokémon out\n"
            "of move-binding\n"
            "effects."),
        .descricao = COMPOUND_STRING(
            "Tira Pokémon\n"
            "efeitos vinculação\n"
            "golpe."),
        .descricion = COMPOUND_STRING(
            "Libera los Pokémon\n"
            "los efectos\n"
            "vinculación"),
        #else
            "A hold item that\n"
            "snaps Pokémon out\n"
            "of infatuation."),
        #endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_InBattleHerb,
        .iconPalette = gItemIconPalette_MentalHerb,
    },

    [ITEM_KINGS_ROCK] =
    {
        .name = ITEM_NAME("King's Rock"),
        .nombre = ITEM_NAME("Roca del Rey"),
    #if I_PRICE >= GEN_9
        .price = 10000,
    #elif I_PRICE >= GEN_7
        .price = 5000,
    #else
        .price = 100,
    #endif
        .holdEffect = HOLD_EFFECT_FLINCH,
        .holdEffectParam = 10,
        .description = sKingsRockDesc,
        .descricao = COMPOUND_STRING(
            "Um item de retenção\n"
            "que pode causar\n"
            "estremecimento."),
        .descricion = COMPOUND_STRING(
            "Un objeto de\n"
            "sujeción que puede\n"
            "provocar un."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = EVO_HELD_ITEM_TYPE,
        .fieldUseFunc = EVO_HELD_ITEM_FIELD_FUNC,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
        .iconPic = gItemIcon_KingsRock,
        .iconPalette = gItemIconPalette_KingsRock,
    },

    [ITEM_AMULET_COIN] =
    {
        .name = ITEM_NAME("Amulet Coin"),
        .nombre = ITEM_NAME("Moneda Amuleto"),
    #if I_PRICE >= GEN_9
        .price = 30000,
    #elif I_PRICE >= GEN_7
        .price = 10000,
    #else
        .price = 100,
    #endif
        .holdEffect = HOLD_EFFECT_DOUBLE_PRIZE,
        .description = sLuckIncenseDesc,
        .descricao = COMPOUND_STRING(
            "Dobra o dinheiro na\n"
            "luta se o titular\n"
            "participar."),
        .descricion = COMPOUND_STRING(
            "Duplica el dinero\n"
            "en la batalla si el\n"
            "poseedor participa."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_AmuletCoin,
        .iconPalette = gItemIconPalette_AmuletCoin,
    },

    [ITEM_CLEANSE_TAG] =
    {
        .name = ITEM_NAME("Cleanse Tag"),
        .nombre = ITEM_NAME("Etiq. de limp."),
        .price = (I_PRICE >= GEN_7) ? 5000 : 200,
        .holdEffect = HOLD_EFFECT_REPEL,
        .description = sPureIncenseDesc,
        .descricao = COMPOUND_STRING(
            "Um item de retenção\n"
            "que ajuda a repelir\n"
            "Pokémon selv."),
        .descricion = COMPOUND_STRING(
            "Un objeto de\n"
            "retención que ayuda\n"
            "a repeler Pokémon."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_CleanseTag,
        .iconPalette = gItemIconPalette_CleanseTag,
    },

    [ITEM_SMOKE_BALL] =
    {
        .name = ITEM_NAME("Smoke Ball"),
        .nombre = ITEM_NAME("bola de humo"),
    #if I_PRICE >= GEN_9
        .price = 15000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_CAN_ALWAYS_RUN,
        .description = COMPOUND_STRING(
            "A hold item that\n"
            "assures fleeing\n"
            "from wild Pokémon."),
        .descricao = COMPOUND_STRING(
            "Um item de retenção\n"
            "que garante a fuga\n"
            "de Pokémon."),
        .descricion = COMPOUND_STRING(
            "Un objeto de\n"
            "retención que\n"
            "asegura huir de."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_SmokeBall,
        .iconPalette = gItemIconPalette_SmokeBall,
    },

    [ITEM_FOCUS_BAND] =
    {
        .name = ITEM_NAME("Focus Band"),
        .nombre = ITEM_NAME("Banda de enfoque"),
    #if I_PRICE >= GEN_9
        .price = 10000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_FOCUS_BAND,
        .holdEffectParam = 10,
        .description = COMPOUND_STRING(
            "A hold item that\n"
            "occasionally\n"
            "prevents fainting."),
        .descricao = COMPOUND_STRING(
            "Um item de apoio\n"
            "que ocasionalmente\n"
            "evita desmaios."),
        .descricion = COMPOUND_STRING(
            "Un elemento de\n"
            "sujeción que\n"
            "previene."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_FocusBand,
        .iconPalette = gItemIconPalette_FocusBand,
    },

    [ITEM_LUCKY_EGG] =
    {
        .name = ITEM_NAME("Lucky Egg"),
        .nombre = ITEM_NAME("huevo de la suerte"),
        .price = (I_PRICE >= GEN_7) ? 10000 : 200,
        .holdEffect = HOLD_EFFECT_LUCKY_EGG,
        .description = COMPOUND_STRING(
            "A hold item that\n"
            "boosts Exp. points\n"
            "earned in battle."),
        .descricao = COMPOUND_STRING(
            "Um item de retenção\n"
            "que sobe Exp.\n"
            "pontos ganhos em."),
        .descricion = COMPOUND_STRING(
            "Un elemento de\n"
            "retención que sobe\n"
            "la Exp."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_LuckyEgg,
        .iconPalette = gItemIconPalette_LuckyEgg,
    },

    [ITEM_SCOPE_LENS] =
    {
        .name = ITEM_NAME("Scope Lens"),
        .nombre = ITEM_NAME("Lente de alcance"),
        .pluralName = ITEM_PLURAL_NAME("Scope Lenses"),
    #if I_PRICE >= GEN_9
        .price = 15000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 100,
    #endif
        .holdEffect = HOLD_EFFECT_SCOPE_LENS,
        .description = COMPOUND_STRING(
            "A hold item that\n"
            "improves the\n"
            "critical-hit rate."),
        .descricao = COMPOUND_STRING(
            "Um item de retenção\n"
            "que melhora a taxa\n"
            "de acerto crítico."),
        .descricion = COMPOUND_STRING(
            "Un elemento\n"
            "retención mejora la\n"
            "tasa golpes."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_ScopeLens,
        .iconPalette = gItemIconPalette_ScopeLens,
    },

    [ITEM_LEFTOVERS] =
    {
        .name = ITEM_NAME("Leftovers"),
        .nombre = ITEM_NAME("Sobras"),
        .pluralName = ITEM_PLURAL_NAME("Leftovers"),
    #if I_PRICE >= GEN_9
        .price = 20000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_LEFTOVERS,
        .holdEffectParam = 10,
        .description = COMPOUND_STRING(
            "A hold item that\n"
            "gradually heals HP\n"
            "in battle."),
        .descricao = COMPOUND_STRING(
            "Um item retenção\n"
            "cura gradualmente\n"
            "HP em"),
        .descricion = COMPOUND_STRING(
            "Un elemento de\n"
            "retención que cura."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_Leftovers,
        .iconPalette = gItemIconPalette_Leftovers,
    },

    [ITEM_SHELL_BELL] =
    {
        .name = ITEM_NAME("Shell Bell"),
        .nombre = ITEM_NAME("Campana de concha"),
    #if I_PRICE >= GEN_9
        .price = 20000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_SHELL_BELL,
        .holdEffectParam = 8,
        .description = COMPOUND_STRING(
            "A hold item that\n"
            "heals HP upon\n"
            "striking the foe."),
        .descricao = COMPOUND_STRING(
            "Um item de retenção\n"
            "que cura HP ao\n"
            "atingir o alvo."),
        .descricion = COMPOUND_STRING(
            "Un elemento de\n"
            "retención que cura\n"
            "HP al."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_ShellBell,
        .iconPalette = gItemIconPalette_Shell,
    },

    [ITEM_WIDE_LENS] =
    {
        .name = ITEM_NAME("Wide Lens"),
        .nombre = ITEM_NAME("Lente ancha"),
        .pluralName = ITEM_PLURAL_NAME("Wide Lenses"),
    #if I_PRICE >= GEN_9
        .price = 20000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_WIDE_LENS,
        .holdEffectParam = 10,
        .description = COMPOUND_STRING(
            "A magnifying lens\n"
            "that boosts the\n"
            "acc. of moves."),
        .descricao = COMPOUND_STRING(
            "Uma lente de\n"
            "aumento que sobe a\n"
            "prec. dos golpes."),
        .descricion = COMPOUND_STRING(
            "Una lupa que sobe\n"
            "la precisión de los\n"
            "movs."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_WideLens,
        .iconPalette = gItemIconPalette_WideLens,
    },

    [ITEM_MUSCLE_BAND] =
    {
        .name = ITEM_NAME("Muscle Band"),
        .nombre = ITEM_NAME("banda muscular"),
    #if I_PRICE >= GEN_9
        .price = 8000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_MUSCLE_BAND,
        .holdEffectParam = 10,
        .description = COMPOUND_STRING(
            "A headband that\n"
            "boosts the power of\n"
            "physical moves."),
        .descricao = COMPOUND_STRING(
            "Uma faixa para a\n"
            "cabeça que sobe o\n"
            "poder dos golpes."),
        .descricion = COMPOUND_STRING(
            "Una diadema\n"
            "potencia el poder\n"
            "los movs. físicos."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_MuscleBand,
        .iconPalette = gItemIconPalette_MuscleBand,
    },

    [ITEM_WISE_GLASSES] =
    {
        .name = ITEM_NAME("Wise Glasses"),
        .nombre = ITEM_NAME("Gafas sabias"),
        .pluralName = ITEM_PLURAL_NAME("Wise Glasses"),
    #if I_PRICE >= GEN_9
        .price = 8000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_WISE_GLASSES,
        .holdEffectParam = 10,
        .description = COMPOUND_STRING(
            "A pair of glasses\n"
            "that ups the power\n"
            "of special moves."),
        .descricao = COMPOUND_STRING(
            "Um par óculos sobe\n"
            "poder golpes\n"
            "especiais."),
        .descricion = COMPOUND_STRING(
            "Un par de gafas que\n"
            "aumentan el poder\n"
            "de los movs."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_WiseGlasses,
        .iconPalette = gItemIconPalette_WiseGlasses,
    },

    [ITEM_EXPERT_BELT] =
    {
        .name = ITEM_NAME("Expert Belt"),
        .nombre = ITEM_NAME("Cinturon experto"),
    #if I_PRICE >= GEN_9
        .price = 30000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_EXPERT_BELT,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "A belt that boosts\n"
            "the power of super\n"
            "effective moves."),
        .descricao = COMPOUND_STRING(
            "Um cinto que sobe o\n"
            "poder de golpes\n"
            "supereficazes."),
        .descricion = COMPOUND_STRING(
            "Un cinturón que\n"
            "potencia el poder\n"
            "de los movs. súper."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_ExpertBelt,
        .iconPalette = gItemIconPalette_ExpertBelt,
    },

    [ITEM_LIGHT_CLAY] =
    {
        .name = ITEM_NAME("Light Clay"),
        .nombre = ITEM_NAME("Arcilla ligera"),
    #if I_PRICE >= GEN_9
        .price = 20000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_LIGHT_CLAY,
        .description = COMPOUND_STRING(
            "Extends the length\n"
            "of barrier moves\n"
            "used by the holder."),
        .descricao = COMPOUND_STRING(
            "Amplia comprimento\n"
            "golpes barreira\n"
            "usados pelo"),
        .descricion = COMPOUND_STRING(
            "Extiende la\n"
            "duración los movs.\n"
            "barrera utilizados."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_LightClay,
        .iconPalette = gItemIconPalette_LightClay,
    },

    [ITEM_LIFE_ORB] =
    {
        .name = ITEM_NAME("Life Orb"),
        .nombre = ITEM_NAME("Orbe de vida"),
    #if I_PRICE >= GEN_9
        .price = 50000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_LIFE_ORB,
        .description = COMPOUND_STRING(
            "Boosts move power\n"
            "but holder loses HP\n"
            "with each attack."),
        .descricao = COMPOUND_STRING(
            "Aumenta poder\n"
            "golpe, mas titular\n"
            "perde HP cada."),
        .descricion = COMPOUND_STRING(
            "Aumenta el poder de\n"
            "mov. pero el\n"
            "poseedor pierde HP."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_LifeOrb,
        .iconPalette = gItemIconPalette_LifeOrb,
    },

    [ITEM_POWER_HERB] =
    {
        .name = ITEM_NAME("Power Herb"),
        .nombre = ITEM_NAME("Hierba de poder"),
    #if I_PRICE >= GEN_9
        .price = 30000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 100,
    #endif
        .holdEffect = HOLD_EFFECT_POWER_HERB,
        .description = COMPOUND_STRING(
            "Allows immediate\n"
            "use of a move that\n"
            "charges first."),
        .descricao = COMPOUND_STRING(
            "Permite o uso\n"
            "imediato de um\n"
            "golpe que carrega."),
        .descricion = COMPOUND_STRING(
            "Permite el uso\n"
            "inmediato un mov.\n"
            "carga primero."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_PowerHerb,
        .iconPalette = gItemIconPalette_PowerHerb,
    },

    [ITEM_FOCUS_SASH] =
    {
        .name = ITEM_NAME("Focus Sash"),
        .nombre = ITEM_NAME("Faja de enfoque"),
        .pluralName = ITEM_PLURAL_NAME("Focus Sashes"),
    #if I_PRICE >= GEN_9
        .price = 50000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_FOCUS_SASH,
        .description = COMPOUND_STRING(
            "If the holder has\n"
            "full HP, it endures\n"
            "KO hits with 1 HP."),
        .descricao = COMPOUND_STRING(
            "Se titular tiver HP\n"
            "completo, ele\n"
            "suporta KO com 1."),
        .descricion = COMPOUND_STRING(
            "Si el poseedor\n"
            "tiene HP completo,\n"
            "soporta golpes KO."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_FocusSash,
        .iconPalette = gItemIconPalette_FocusSash,
    },

    [ITEM_ZOOM_LENS] =
    {
        .name = ITEM_NAME("Zoom Lens"),
        .nombre = ITEM_NAME("Lente de zoom"),
        .pluralName = ITEM_PLURAL_NAME("Zoom Lenses"),
    #if I_PRICE >= GEN_9
        .price = 10000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_ZOOM_LENS,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "If the holder moves\n"
            "after the foe,\n"
            "it'll boost acc."),
        .descricao = COMPOUND_STRING(
            "Se titular mover\n"
            "atrás alvo, isso\n"
            "aumentará"),
        .descricion = COMPOUND_STRING(
            "Si el portador\n"
            "mueve detrás del\n"
            "rival, aumentará."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_ZoomLens,
        .iconPalette = gItemIconPalette_ZoomLens,
    },

    [ITEM_METRONOME] =
    {
        .name = ITEM_NAME("Metronome"),
        .nombre = ITEM_NAME("metronomo"),
    #if I_PRICE >= GEN_9
        .price = 15000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_METRONOME,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "A held item that\n"
            "boosts a move used\n"
            "consecutively."),
        .descricao = COMPOUND_STRING(
            "Um item segurado\n"
            "que sobe um golpe\n"
            "usado."),
        .descricion = COMPOUND_STRING(
            "Un elemento\n"
            "retenido potencia\n"
            "un mov. usado."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_Metronome,
        .iconPalette = gItemIconPalette_Metronome,
    },

    [ITEM_IRON_BALL] =
    {
        .name = ITEM_NAME("Iron Ball"),
        .nombre = ITEM_NAME("bola de hierro"),
    #if I_PRICE >= GEN_9
        .price = 20000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_IRON_BALL,
        .description = COMPOUND_STRING(
            "Cuts Speed and\n"
            "becomes vulnerable\n"
            "to Ground moves."),
        .descricao = COMPOUND_STRING(
            "Reduz a Vel. e fica\n"
            "vulnerável a golpes\n"
            "terrestres."),
        .descricion = COMPOUND_STRING(
            "Reduce la Vel. y se\n"
            "vuelve vulnerable a\n"
            "los movs."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 130,
        .iconPic = gItemIcon_IronBall,
        .iconPalette = gItemIconPalette_IronBall,
    },

    [ITEM_LAGGING_TAIL] =
    {
        .name = ITEM_NAME("Lagging Tail"),
        .nombre = ITEM_NAME("Cola rezagada"),
    #if I_PRICE >= GEN_9
        .price = 20000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_LAGGING_TAIL,
        .description = sFullIncenseDesc,
        .descricao = COMPOUND_STRING(
            "Um item retido faz\n"
            "com suporte mova\n"
            "mais"),
        .descricion = COMPOUND_STRING(
            "Un objeto retenido\n"
            "que hace que quien\n"
            "lo posee se mueva."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_LaggingTail,
        .iconPalette = gItemIconPalette_LaggingTail,
    },

    [ITEM_DESTINY_KNOT] =
    {
        .name = ITEM_NAME("Destiny Knot"),
        .nombre = ITEM_NAME("Nudo del destino"),
    #if I_PRICE >= GEN_9
        .price = 20000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_DESTINY_KNOT,
        .description = COMPOUND_STRING(
            "If the holder falls\n"
            "in love, the foe\n"
            "does too."),
        .descricao = COMPOUND_STRING(
            "Se o detentor se\n"
            "apaixonar, o alvo\n"
            "tambem."),
        .descricion = COMPOUND_STRING(
            "Si el poseedor se\n"
            "enamora, el rival\n"
            "también lo hace."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_DestinyKnot,
        .iconPalette = gItemIconPalette_DestinyKnot,
    },

    [ITEM_BLACK_SLUDGE] =
    {
        .name = ITEM_NAME("Black Sludge"),
        .nombre = ITEM_NAME("Lodo negro"),
    #if I_PRICE >= GEN_9
        .price = 10000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_BLACK_SLUDGE,
        .description = COMPOUND_STRING(
            "Restores HP for\n"
            "Poison-types.\n"
            "Damages all others."),
        .descricao = COMPOUND_STRING(
            "Restaura HP para\n"
            "tipos Poison.\n"
            "Danifica todos os."),
        .descricion = COMPOUND_STRING(
            "Restaura HP para\n"
            "los tipos Veneno.\n"
            "Daña todos los."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_BlackSludge,
        .iconPalette = gItemIconPalette_BlackSludge,
    },

    [ITEM_GRIP_CLAW] =
    {
        .name = ITEM_NAME("Grip Claw"),
        .nombre = ITEM_NAME("Garra de agarre"),
    #if I_PRICE >= GEN_9
        .price = 10000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_GRIP_CLAW,
        .description = COMPOUND_STRING(
            "A held item that\n"
            "extends binding\n"
            "moves like Wrap."),
        .descricao = COMPOUND_STRING(
            "Um item retido que\n"
            "estende golpes de\n"
            "ligação como Wrap."),
        .descricion = COMPOUND_STRING(
            "Un elemento\n"
            "retenido extiende\n"
            "movs. vinculantes."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 90,
        .iconPic = gItemIcon_GripClaw,
        .iconPalette = gItemIconPalette_GripClaw,
    },

    [ITEM_STICKY_BARB] =
    {
        .name = ITEM_NAME("Sticky Barb"),
        .nombre = ITEM_NAME("pua pegajosa"),
    #if I_PRICE >= GEN_9
        .price = 10000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_STICKY_BARB,
        .description = COMPOUND_STRING(
            "Damages the holder\n"
            "each turn. May\n"
            "latch on to foes."),
        .descricao = COMPOUND_STRING(
            "Danifica titular\n"
            "cada turno. Pode\n"
            "agarrar aos alvos."),
        .descricion = COMPOUND_STRING(
            "Daña el soporte en\n"
            "cada vuelta. Puede\n"
            "aferrarse a los."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_StickyBarb,
        .iconPalette = gItemIconPalette_StickyBarb,
    },

    [ITEM_SHED_SHELL] =
    {
        .name = ITEM_NAME("Shed Shell"),
        .nombre = ITEM_NAME("Concha de cobertizo"),
    #if I_PRICE >= GEN_9
        .price = 20000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 100,
    #endif
        .holdEffect = HOLD_EFFECT_SHED_SHELL,
        .description = COMPOUND_STRING(
            "Allows the holder\n"
            "to switch out\n"
            "without fail."),
        .descricao = COMPOUND_STRING(
            "Permite que o\n"
            "suporte seja\n"
            "desligado sem."),
        .descricion = COMPOUND_STRING(
            "Permite que el\n"
            "soporte se apague\n"
            "sin falta."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_ShedShell,
        .iconPalette = gItemIconPalette_ShedShell,
    },

    [ITEM_BIG_ROOT] =
    {
        .name = ITEM_NAME("Big Root"),
        .nombre = ITEM_NAME("Raiz grande"),
    #if I_PRICE >= GEN_9
        .price = 10000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_BIG_ROOT,
        .holdEffectParam = 30,
        .description = COMPOUND_STRING(
            "A held item that\n"
            "ups the power of\n"
            "HP-stealing moves."),
        .descricao = COMPOUND_STRING(
            "Um item que sobe o\n"
            "poder dos golpes de\n"
            "roubo de HP."),
        .descricion = COMPOUND_STRING(
            "Un objeto retenido\n"
            "que sobe el poder\n"
            "de los movs. para."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_BigRoot,
        .iconPalette = gItemIconPalette_BigRoot,
    },

    [ITEM_RAZOR_CLAW] =
    {
        .name = ITEM_NAME("Razor Claw"),
        .nombre = ITEM_NAME("Garra de afeitar"),
    #if I_PRICE >= GEN_9
        .price = 15000,
    #elif I_PRICE >= GEN_7
        .price = 5000,
    #else
        .price = 2100,
    #endif
        .holdEffect = HOLD_EFFECT_SCOPE_LENS,
        .description = COMPOUND_STRING(
            "A hooked claw that\n"
            "ups the holder's\n"
            "critical-hit ratio."),
        .descricao = COMPOUND_STRING(
            "Uma garra em forma\n"
            "de gancho que sobe\n"
            "a taxa de."),
        .descricion = COMPOUND_STRING(
            "Una garra en forma\n"
            "de gancho que sobe\n"
            "la."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = EVO_HELD_ITEM_TYPE,
        .fieldUseFunc = EVO_HELD_ITEM_FIELD_FUNC,
        .effect = gItemEffect_EvoItem,
        .flingPower = 80,
        .iconPic = gItemIcon_RazorClaw,
        .iconPalette = gItemIconPalette_RazorClaw,
    },

    [ITEM_RAZOR_FANG] =
    {
        .name = ITEM_NAME("Razor Fang"),
        .nombre = ITEM_NAME("Colmillo navaja"),
    #if I_PRICE >= GEN_9
        .price = 15000,
    #elif I_PRICE >= GEN_7
        .price = 5000,
    #else
        .price = 2100,
    #endif
        .holdEffect = HOLD_EFFECT_FLINCH,
        .holdEffectParam = 10,
        .description = sKingsRockDesc,
        .descricao = COMPOUND_STRING(
            "Um item de retenção\n"
            "que pode causar\n"
            "estremecimento."),
        .descricion = COMPOUND_STRING(
            "Un objeto de\n"
            "sujeción que puede\n"
            "provocar un."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = EVO_HELD_ITEM_TYPE,
        .fieldUseFunc = EVO_HELD_ITEM_FIELD_FUNC,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
        .iconPic = gItemIcon_RazorFang,
        .iconPalette = gItemIconPalette_RazorFang,
    },

    [ITEM_EVIOLITE] =
    {
        .name = ITEM_NAME("Eviolite"),
        .nombre = ITEM_NAME("Eviolita"),
    #if I_PRICE >= GEN_9
        .price = 50000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_EVIOLITE,
        .holdEffectParam = 50,
        .description = COMPOUND_STRING(
            "Raises the Def and\n"
            "Sp. Def of Pokémon\n"
            "that can evolve."),
        .descricao = COMPOUND_STRING(
            "Aumenta a Def e Sp.\n"
            "Def de Pokémon que\n"
            "podem evolui."),
        .descricion = COMPOUND_STRING(
            "Aumenta la Def y\n"
            "Sp. Def Pokémon\n"
            "pueden evolucionar."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 40,
        .iconPic = gItemIcon_Eviolite,
        .iconPalette = gItemIconPalette_Eviolite,
    },

    [ITEM_FLOAT_STONE] =
    {
        .name = ITEM_NAME("Float Stone"),
        .nombre = ITEM_NAME("P. flotante"),
    #if I_PRICE >= GEN_9
        .price = 10000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_FLOAT_STONE,
        .description = COMPOUND_STRING(
            "It's so light when\n"
            "held, halves\n"
            "Pokémon's weight."),
        .descricao = COMPOUND_STRING(
            "É tão leve quando\n"
            "segurado, reduz\n"
            "pela metade"),
        .descricion = COMPOUND_STRING(
            "Es tan ligero\n"
            "cuando sostiene,\n"
            "pesa la mitad un"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_FloatStone,
        .iconPalette = gItemIconPalette_FloatStone,
    },

    [ITEM_ROCKY_HELMET] =
    {
        .name = ITEM_NAME("Rocky Helmet"),
        .nombre = ITEM_NAME("Casco rocoso"),
    #if I_PRICE >= GEN_9
        .price = 50000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_ROCKY_HELMET,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "Hurts the foe if\n"
            "they touch its\n"
            "holder."),
        .descricao = COMPOUND_STRING(
            "Ferirá o alvo se\n"
            "ele tocar em seu\n"
            "portador."),
        .descricion = COMPOUND_STRING(
            "Daña al rival si\n"
            "toca a su portador."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 60,
        .iconPic = gItemIcon_RockyHelmet,
        .iconPalette = gItemIconPalette_RockyHelmet,
    },

    [ITEM_AIR_BALLOON] =
    {
        .name = ITEM_NAME("Air Balloon"),
        .nombre = ITEM_NAME("globo aerostatico"),
    #if I_PRICE >= GEN_9
        .price = 15000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_AIR_BALLOON,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "Makes the holder\n"
            "float but bursts if\n"
            "hit by an attack."),
        .descricao = COMPOUND_STRING(
            "Faz suporte\n"
            "flutuar, mas\n"
            "explode for."),
        .descricion = COMPOUND_STRING(
            "Hace que el soporte\n"
            "flote pero explota\n"
            "si lo golpea un."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_AirBalloon,
        .iconPalette = gItemIconPalette_AirBalloon,
    },

    [ITEM_RED_CARD] =
    {
        .name = ITEM_NAME("Red Card"),
        .nombre = ITEM_NAME("tarjeta roja"),
    #if I_PRICE >= GEN_9
        .price = 3000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_RED_CARD,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "Switches out the\n"
            "foe if they hit the\n"
            "holder."),
        .descricao = COMPOUND_STRING(
            "Troca o alvo se ele\n"
            "acertar o suporte."),
        .descricion = COMPOUND_STRING(
            "Cambia al rival si\n"
            "golpea al portador."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_RedCard,
        .iconPalette = gItemIconPalette_RedCard,
    },

    [ITEM_RING_TARGET] =
    {
        .name = ITEM_NAME("Ring Target"),
        .nombre = ITEM_NAME("Objetivo de anillo"),
    #if I_PRICE >= GEN_9
        .price = 10000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_RING_TARGET,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "Moves that usually\n"
            "have no effect will\n"
            "hit the holder."),
        .descricao = COMPOUND_STRING(
            "Movimentos que\n"
            "normalmente não\n"
            "surtem efeito."),
        .descricion = COMPOUND_STRING(
            "Los movs.\n"
            "normalmente no\n"
            "tienen ningún."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_RingTarget,
        .iconPalette = gItemIconPalette_RingTarget,
    },

    [ITEM_BINDING_BAND] =
    {
        .name = ITEM_NAME("Binding Band"),
        .nombre = ITEM_NAME("Banda vinculante"),
    #if I_PRICE >= GEN_9
        .price = 20000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_BINDING_BAND,
        .description = COMPOUND_STRING(
            "Increases the power\n"
            "of binding moves\n"
            "when held."),
        .descricao = COMPOUND_STRING(
            "Aumenta o poder dos\n"
            "golpes de ligação\n"
            "quando segurado."),
        .descricion = COMPOUND_STRING(
            "Aumenta el poder de\n"
            "los movs.\n"
            "vinculantes cuando."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_BindingBand,
        .iconPalette = gItemIconPalette_BindingBand,
    },

    [ITEM_EJECT_BUTTON] =
    {
        .name = ITEM_NAME("Eject Button"),
        .nombre = ITEM_NAME("Boton de exp."),
    #if I_PRICE >= GEN_9
        .price = 30000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_EJECT_BUTTON,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "Switches out the\n"
            "user if they're hit\n"
            "by the foe."),
        .descricao = COMPOUND_STRING(
            "Troca o usu. se ele\n"
            "for atingido pelo\n"
            "alvo."),
        .descricion = COMPOUND_STRING(
            "Cambia al usu. si\n"
            "es golpeado por el\n"
            "rival."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_EjectButton,
        .iconPalette = gItemIconPalette_EjectButton,
    },

    [ITEM_WEAKNESS_POLICY] =
    {
        .name = ITEM_NAME("Weakness Policy"),
        .nombre = ITEM_NAME("Weakness Policy"),
        .pluralName = ITEM_PLURAL_NAME("Weakness Policies"),
        .price = (I_PRICE >= GEN_9) ? 50000 : 1000,
        .holdEffect = HOLD_EFFECT_WEAKNESS_POLICY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "If hit by a super-\n"
            "effective move, ups\n"
            "Atk and Sp. Atk."),
        .descricao = COMPOUND_STRING(
            "Se for atingido por\n"
            "um golpe\n"
            "supereficaz, sobe"),
        .descricion = COMPOUND_STRING(
            "Si es golpeado por\n"
            "un mov. súper\n"
            "efectivo, sobe."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_WeaknessPolicy,
        .iconPalette = gItemIconPalette_WeaknessPolicy,
    },

    [ITEM_ASSAULT_VEST] =
    {
        .name = ITEM_NAME("Assault Vest"),
        .nombre = ITEM_NAME("Chaleco de asalto"),
        .price = (I_PRICE >= GEN_9) ? 50000 : 1000,
        .holdEffect = HOLD_EFFECT_ASSAULT_VEST,
        .holdEffectParam = 50,
        .description = COMPOUND_STRING(
            "Raises Sp. Def but\n"
            "prevents the use of\n"
            "status moves."),
        .descricao = COMPOUND_STRING(
            "Aumenta Sp. Def,\n"
            "mas impede o uso de\n"
            "golpes de status."),
        .descricion = COMPOUND_STRING(
            "Aumenta sp. Def\n"
            "pero evita el uso\n"
            "de movs. de estado."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_AssaultVest,
        .iconPalette = gItemIconPalette_AssaultVest,
    },

    [ITEM_SAFETY_GOGGLES] =
    {
        .name = ITEM_NAME("Safety Goggles"),
        .nombre = ITEM_NAME("Gafas de seguridad"),
        .pluralName = ITEM_PLURAL_NAME("Safety Goggles"),
    #if I_PRICE >= GEN_9
        .price = 20000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 1000,
    #endif
        .holdEffect = HOLD_EFFECT_SAFETY_GOGGLES,
        .description = COMPOUND_STRING(
            "Protect from\n"
            "weather damage and\n"
            "powder moves."),
        .descricao = COMPOUND_STRING(
            "Proteja contra\n"
            "danos climáticos e\n"
            "golpes de pólvora."),
        .descricion = COMPOUND_STRING(
            "Protéjalo los daños\n"
            "causados por el\n"
            "clima y los movs."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_SafetyGoggles,
        .iconPalette = gItemIconPalette_SafetyGoggles,
    },

    [ITEM_ADRENALINE_ORB] =
    {
        .name = ITEM_NAME("Adrenaline Orb"),
        .nombre = ITEM_NAME("Orbe de adrenalina"),
    #if I_PRICE >= GEN_9
        .price = 5000,
    #elif I_PRICE == GEN_8
        .price = 4000,
    #else
        .price = 300,
    #endif
        .holdEffect = HOLD_EFFECT_ADRENALINE_ORB,
        .description = COMPOUND_STRING(
            "This orb boosts\n"
            "Speed if the holder\n"
            "is intimidated."),
        .descricao = COMPOUND_STRING(
            "Este orbe sobe a\n"
            "Vel. se o titular\n"
            "ficar intimidado."),
        .descricion = COMPOUND_STRING(
            "Este orbe sobe la\n"
            "Vel. si quien lo\n"
            "posee se siente."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_AdrenalineOrb,
        .iconPalette = gItemIconPalette_AdrenalineOrb,
    },

    [ITEM_TERRAIN_EXTENDER] =
    {
        .name = ITEM_NAME("Terrain Extender"),
        .nombre = ITEM_NAME("Extensor de terreno"),
        .price = (I_PRICE >= GEN_9) ? 15000 : 4000,
        .holdEffect = HOLD_EFFECT_TERRAIN_EXTENDER,
        .description = COMPOUND_STRING(
            "Extends the length\n"
            "of the active\n"
            "battle terrain."),
        .descricao = COMPOUND_STRING(
            "Amplia a extensão\n"
            "do terreno de luta\n"
            "ativo."),
        .descricion = COMPOUND_STRING(
            "Extiende la\n"
            "longitud del\n"
            "terreno batalla."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 60,
        .iconPic = gItemIcon_TerrainExtender,
        .iconPalette = gItemIconPalette_TerrainExtender,
    },

    [ITEM_PROTECTIVE_PADS] =
    {
        .name = ITEM_NAME("Protective Pads"),
        .nombre = ITEM_NAME("Protective Pads"),
        .pluralName = ITEM_PLURAL_NAME("Protective Pads"),
        .price = (I_PRICE >= GEN_9) ? 15000 : 4000,
        .holdEffect = HOLD_EFFECT_PROTECTIVE_PADS,
        .description = COMPOUND_STRING(
            "Guard the holder\n"
            "from contact move\n"
            "effects."),
        .descricao = COMPOUND_STRING(
            "Proteja o suporte\n"
            "dos efeitos de\n"
            "golpe por contato."),
        .descricion = COMPOUND_STRING(
            "Proteja el soporte\n"
            "de los efectos del\n"
            "mov. de contacto."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_ProtectivePads,
        .iconPalette = gItemIconPalette_ProtectivePads,
    },

    [ITEM_THROAT_SPRAY] =
    {
        .name = ITEM_NAME("Throat Spray"),
        .nombre = ITEM_NAME("Throat Spray"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 4000,
        .holdEffect = HOLD_EFFECT_THROAT_SPRAY,
        .description = COMPOUND_STRING(
            "Raises Sp. Atk. if\n"
            "the holder uses a\n"
            "sound-based move."),
        .descricao = COMPOUND_STRING(
            "Aumenta Sp. Atk. se\n"
            "o titular usar um\n"
            "golpe baseado em."),
        .descricion = COMPOUND_STRING(
            "Aumenta sp. Atk. si\n"
            "el poseedor utiliza\n"
            "un mov. basado en."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_ThroatSpray,
        .iconPalette = gItemIconPalette_ThroatSpray,
    },

    [ITEM_EJECT_PACK] =
    {
        .name = ITEM_NAME("Eject Pack"),
        .nombre = ITEM_NAME("Paq. de exp."),
        .price = (I_PRICE >= GEN_9) ? 30000 : 4000,
        .holdEffect = HOLD_EFFECT_EJECT_PACK,
        .description = COMPOUND_STRING(
            "Forces the user to\n"
            "switch if its stats\n"
            "are lowered."),
        .descricao = COMPOUND_STRING(
            "Força o usu. a\n"
            "mudar se suas\n"
            "estatísticas forem."),
        .descricion = COMPOUND_STRING(
            "Obliga al usu. a\n"
            "cambiar si sus\n"
            "estadísticas."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 50,
        .iconPic = gItemIcon_EjectPack,
        .iconPalette = gItemIconPalette_EjectPack,
    },

    [ITEM_HEAVY_DUTY_BOOTS] =
    {
        .name = ITEM_NAME("Heavy-Duty Boots"),
        .nombre = ITEM_NAME("Botas resistentes"),
        .pluralName = ITEM_PLURAL_NAME("Heavy-Duty Boots"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 4000,
        .holdEffect = HOLD_EFFECT_HEAVY_DUTY_BOOTS,
        .description = COMPOUND_STRING(
            "Boots that prevent\n"
            "effects of traps\n"
            "set in the field."),
        .descricao = COMPOUND_STRING(
            "Botas evitam\n"
            "efeitos armadilhas\n"
            "colocadas"),
        .descricion = COMPOUND_STRING(
            "Botas que previenen\n"
            "efectos de trampas\n"
            "colocadas en el."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_HeavyDutyBoots,
        .iconPalette = gItemIconPalette_HeavyDutyBoots,
    },

    [ITEM_BLUNDER_POLICY] =
    {
        .name = ITEM_NAME("Blunder Policy"),
        .nombre = ITEM_NAME("Politica de errores"),
        .pluralName = ITEM_PLURAL_NAME("Blunder Policies"),
        .price = (I_PRICE >= GEN_9) ? 30000 : 4000,
        .holdEffect = HOLD_EFFECT_BLUNDER_POLICY,
        .description = COMPOUND_STRING(
            "Raises Speed if the\n"
            "user misses due to\n"
            "Accuracy."),
        .descricao = COMPOUND_STRING(
            "Aumenta a Vel. se o\n"
            "usu. errar devido à\n"
            "prec."),
        .descricion = COMPOUND_STRING(
            "Aumenta la Vel. si\n"
            "el usu. falla\n"
            "debido a la."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_BlunderPolicy,
        .iconPalette = gItemIconPalette_BlunderPolicy,
    },

    [ITEM_ROOM_SERVICE] =
    {
        .name = ITEM_NAME("Room Service"),
        .nombre = ITEM_NAME("Room Service"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 4000,
        .holdEffect = HOLD_EFFECT_ROOM_SERVICE,
        .description = COMPOUND_STRING(
            "Lowers Speed if\n"
            "Trick Room is\n"
            "active."),
        .descricao = COMPOUND_STRING(
            "Reduz a Vel. se\n"
            "Trick Room estiver\n"
            "ativo."),
        .descricion = COMPOUND_STRING(
            "Reduce la Vel. si\n"
            "Trick Room está\n"
            "activo."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
        .iconPic = gItemIcon_RoomService,
        .iconPalette = gItemIconPalette_RoomService,
    },

    [ITEM_UTILITY_UMBRELLA] =
    {
        .name = ITEM_NAME("Utility Umbrella"),
        .nombre = ITEM_NAME("Paraguas utilitario"),
        .price = (I_PRICE >= GEN_9) ? 15000 : 4000,
        .holdEffect = HOLD_EFFECT_UTILITY_UMBRELLA,
        .description = COMPOUND_STRING(
            "An umbrella that\n"
            "protects from\n"
            "weather effects."),
        .descricao = COMPOUND_STRING(
            "Um guarda-chuva que\n"
            "protege dos efeitos\n"
            "climáticos."),
        .descricion = COMPOUND_STRING(
            "Un paraguas que\n"
            "protege de los\n"
            "efectos del clima."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 60,
        .iconPic = gItemIcon_UtilityUmbrella,
        .iconPalette = gItemIconPalette_UtilityUmbrella,
    },

// Berries

    [ITEM_CHERI_BERRY] =
    {
        .name = ITEM_NAME("Cheri Berry"),
        .nombre = ITEM_NAME("Cheri Berry"),
        .pluralName = ITEM_PLURAL_NAME("Cheri Berries"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_CURE_PAR,
        .description = COMPOUND_STRING(
            "A hold item that\n"
            "heals paralysis in\n"
            "battle."),
        .descricao = COMPOUND_STRING(
            "Um item de retenção\n"
            "que cura a\n"
            "paralisia em luta."),
        .descricion = COMPOUND_STRING(
            "Un objeto de\n"
            "retención que cura\n"
            "la parálisis en la."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_ParalyzeHeal,
        .flingPower = 10,
        .iconPic = gItemIcon_CheriBerry,
        .iconPalette = gItemIconPalette_CheriBerry,
    },

    [ITEM_CHESTO_BERRY] =
    {
        .name = ITEM_NAME("Chesto Berry"),
        .nombre = ITEM_NAME("Chesto Berry"),
        .pluralName = ITEM_PLURAL_NAME("Chesto Berries"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_CURE_SLP,
        .description = COMPOUND_STRING(
            "A hold item that\n"
            "awakens Pokémon in\n"
            "battle."),
        .descricao = COMPOUND_STRING(
            "Um item de espera\n"
            "que desperta\n"
            "Pokémon em luta."),
        .descricion = COMPOUND_STRING(
            "Un objeto que\n"
            "despierta a los\n"
            "Pokémon en la."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_Awakening,
        .flingPower = 10,
        .iconPic = gItemIcon_ChestoBerry,
        .iconPalette = gItemIconPalette_ChestoBerry,
    },

    [ITEM_PECHA_BERRY] =
    {
        .name = ITEM_NAME("Pecha Berry"),
        .nombre = ITEM_NAME("Baya de Pecha"),
        .pluralName = ITEM_PLURAL_NAME("Pecha Berries"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_CURE_PSN,
        .description = COMPOUND_STRING(
            "A hold item that\n"
            "heals poisoning in\n"
            "battle."),
        .descricao = COMPOUND_STRING(
            "Um item de retenção\n"
            "que cura\n"
            "envenenamento em."),
        .descricion = COMPOUND_STRING(
            "Un objeto retención\n"
            "cura el\n"
            "envenenamiento en"),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_Antidote,
        .flingPower = 10,
        .iconPic = gItemIcon_PechaBerry,
        .iconPalette = gItemIconPalette_PechaBerry,
    },

    [ITEM_RAWST_BERRY] =
    {
        .name = ITEM_NAME("Rawst Berry"),
        .nombre = ITEM_NAME("Baya mas cruda"),
        .pluralName = ITEM_PLURAL_NAME("Rawst Berries"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_CURE_BRN,
        .description = COMPOUND_STRING(
            "A hold item that\n"
            "heals a burn in\n"
            "battle."),
        .descricao = COMPOUND_STRING(
            "Um item de retenção\n"
            "que cura uma\n"
            "queimadura em."),
        .descricion = COMPOUND_STRING(
            "Un objeto de\n"
            "retención que cura\n"
            "una quemadura en."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_BurnHeal,
        .flingPower = 10,
        .iconPic = gItemIcon_RawstBerry,
        .iconPalette = gItemIconPalette_RawstBerry,
    },

    [ITEM_ASPEAR_BERRY] =
    {
        .name = ITEM_NAME("Aspear Berry"),
        .nombre = ITEM_NAME("Aspear Berry"),
        .pluralName = ITEM_PLURAL_NAME("Aspear Berries"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_CURE_FRZ,
        .description = COMPOUND_STRING(
            "A hold item that\n"
            "defrosts Pokémon in\n"
            "battle."),
        .descricao = COMPOUND_STRING(
            "Um item de retenção\n"
            "que descongela\n"
            "Pokémon em luta."),
        .descricion = COMPOUND_STRING(
            "Un objeto de\n"
            "retención que\n"
            "descongela a los."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_IceHeal,
        .flingPower = 10,
        .iconPic = gItemIcon_AspearBerry,
        .iconPalette = gItemIconPalette_AspearBerry,
    },

    [ITEM_LEPPA_BERRY] =
    {
        .name = ITEM_NAME("Leppa Berry"),
        .nombre = ITEM_NAME("baya leppa"),
        .pluralName = ITEM_PLURAL_NAME("Leppa Berries"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RESTORE_PP,
        .holdEffectParam = 10,
        .description = COMPOUND_STRING(
            "A hold item that\n"
            "heals 10 PP in\n"
            "battle."),
        .descricao = COMPOUND_STRING(
            "Um item de retenção\n"
            "que cura 10 PP em\n"
            "luta."),
        .descricion = COMPOUND_STRING(
            "Un objeto de\n"
            "retención que cura\n"
            "10 PP en."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU_MOVES,
        .fieldUseFunc = ItemUseOutOfBattle_PPRecovery,
        .battleUsage = EFFECT_ITEM_RESTORE_PP,
        .effect = gItemEffect_LeppaBerry,
        .flingPower = 10,
        .iconPic = gItemIcon_LeppaBerry,
        .iconPalette = gItemIconPalette_LeppaBerry,
    },

    [ITEM_ORAN_BERRY] =
    {
        .name = ITEM_NAME("Oran Berry"),
        .nombre = ITEM_NAME("Baya de Oran"),
        .pluralName = ITEM_PLURAL_NAME("Oran Berries"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RESTORE_HP,
        .holdEffectParam = 10,
        .description = COMPOUND_STRING(
            "A hold item that\n"
            "heals 10 HP in\n"
            "battle."),
        .descricao = COMPOUND_STRING(
            "Um item de retenção\n"
            "que cura 10 HP em\n"
            "luta."),
        .descricion = COMPOUND_STRING(
            "Un objeto de\n"
            "retención que cura\n"
            "10 HP en."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_RESTORE_HP,
        .effect = gItemEffect_OranBerry,
        .flingPower = 10,
        .iconPic = gItemIcon_OranBerry,
        .iconPalette = gItemIconPalette_OranBerry,
    },

    [ITEM_PERSIM_BERRY] =
    {
        .name = ITEM_NAME("Persim Berry"),
        .nombre = ITEM_NAME("Baya de caqui"),
        .pluralName = ITEM_PLURAL_NAME("Persim Berries"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_CURE_CONFUSION,
        .description = COMPOUND_STRING(
            "A hold item that\n"
            "heals confusion in\n"
            "battle."),
        .descricao = COMPOUND_STRING(
            "Um item de retenção\n"
            "que cura a confusão\n"
            "na luta."),
        .descricion = COMPOUND_STRING(
            "Un objeto de\n"
            "retención que cura\n"
            "la confusión en la."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_PersimBerry,
        .flingPower = 10,
        .iconPic = gItemIcon_PersimBerry,
        .iconPalette = gItemIconPalette_PersimBerry,
    },

    [ITEM_LUM_BERRY] =
    {
        .name = ITEM_NAME("Lum Berry"),
        .nombre = ITEM_NAME("berry"),
        .pluralName = ITEM_PLURAL_NAME("Lum Berries"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_CURE_STATUS,
        .description = COMPOUND_STRING(
            "A hold item that\n"
            "heals any status\n"
            "problem in battle."),
        .descricao = COMPOUND_STRING(
            "Um item de retenção\n"
            "que cura qualquer\n"
            "problema de status."),
        .descricion = COMPOUND_STRING(
            "Un elemento\n"
            "retenido cura\n"
            "cualquier problema."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_FullHeal,
        .flingPower = 10,
        .iconPic = gItemIcon_LumBerry,
        .iconPalette = gItemIconPalette_LumBerry,
    },

    [ITEM_SITRUS_BERRY] =
    {
        .name = ITEM_NAME("Sitrus Berry"),
        .nombre = ITEM_NAME("Baya de sitrico"),
        .pluralName = ITEM_PLURAL_NAME("Sitrus Berries"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
    #if I_SITRUS_BERRY_HEAL >= GEN_4
        .holdEffect = HOLD_EFFECT_RESTORE_PCT_HP,
        .holdEffectParam = 25,
        .description = COMPOUND_STRING(
            "A hold item that\n"
            "heals the user's HP\n"
            "a little."),
    #else
        .holdEffect = HOLD_EFFECT_RESTORE_HP,
        .holdEffectParam = 30,
        .description = COMPOUND_STRING(
            "A hold item that\n"
            "heals 30 HP in\n"
            "battle."),
    #endif

        .descricao = COMPOUND_STRING(
            "Um item de espera\n"
            "que cura pouco o HP\n"
            "do usu."),
        .descricion = COMPOUND_STRING(
            "Un elemento de\n"
            "retención que cura\n"
            "un poco el."),        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_RESTORE_HP,
        .effect = gItemEffect_SitrusBerry,
        .flingPower = 10,
        .iconPic = gItemIcon_SitrusBerry,
        .iconPalette = gItemIconPalette_SitrusBerry,
    },

    [ITEM_FIGY_BERRY] =
    {
        .name = ITEM_NAME("Figy Berry"),
        .nombre = ITEM_NAME("Baya de higo"),
        .pluralName = ITEM_PLURAL_NAME("Figy Berries"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_CONFUSE_SPICY,
        .holdEffectParam = CONFUSE_BERRY_HEAL_FRACTION,
        .description = sFigyBerryDesc,
        .descricao = COMPOUND_STRING(
            "Um item de retenção\n"
            "que cura HP, mas\n"
            "pode confundir."),
        .descricion = COMPOUND_STRING(
            "Un elemento de\n"
            "retención que cura\n"
            "HP pero que"),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_FigyBerry,
        .iconPalette = gItemIconPalette_FigyBerry,
    },

    [ITEM_WIKI_BERRY] =
    {
        .name = ITEM_NAME("Wiki Berry"),
        .nombre = ITEM_NAME("Baya Wiki"),
        .pluralName = ITEM_PLURAL_NAME("Wiki Berries"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_CONFUSE_DRY,
        .holdEffectParam = CONFUSE_BERRY_HEAL_FRACTION,
        .description = sFigyBerryDesc,
        .descricao = COMPOUND_STRING(
            "Um item de retenção\n"
            "que cura HP, mas\n"
            "pode confundir."),
        .descricion = COMPOUND_STRING(
            "Un elemento de\n"
            "retención que cura\n"
            "HP pero que"),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_WikiBerry,
        .iconPalette = gItemIconPalette_WikiBerry,
    },

    [ITEM_MAGO_BERRY] =
    {
        .name = ITEM_NAME("Mago Berry"),
        .nombre = ITEM_NAME("Baya de Mago"),
        .pluralName = ITEM_PLURAL_NAME("Mago Berries"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_CONFUSE_SWEET,
        .holdEffectParam = CONFUSE_BERRY_HEAL_FRACTION,
        .description = sFigyBerryDesc,
        .descricao = COMPOUND_STRING(
            "Um item de retenção\n"
            "que cura HP, mas\n"
            "pode confundir."),
        .descricion = COMPOUND_STRING(
            "Un elemento de\n"
            "retención que cura\n"
            "HP pero que"),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_MagoBerry,
        .iconPalette = gItemIconPalette_MagoBerry,
    },

    [ITEM_AGUAV_BERRY] =
    {
        .name = ITEM_NAME("Aguav Berry"),
        .nombre = ITEM_NAME("Baya de Aguav"),
        .pluralName = ITEM_PLURAL_NAME("Aguav Berries"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_CONFUSE_BITTER,
        .holdEffectParam = CONFUSE_BERRY_HEAL_FRACTION,
        .description = sFigyBerryDesc,
        .descricao = COMPOUND_STRING(
            "Um item de retenção\n"
            "que cura HP, mas\n"
            "pode confundir."),
        .descricion = COMPOUND_STRING(
            "Un elemento de\n"
            "retención que cura\n"
            "HP pero que"),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_AguavBerry,
        .iconPalette = gItemIconPalette_AguavBerry,
    },

    [ITEM_IAPAPA_BERRY] =
    {
        .name = ITEM_NAME("Iapapa Berry"),
        .nombre = ITEM_NAME("Baya de yapapa"),
        .pluralName = ITEM_PLURAL_NAME("Iapapa Berries"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_CONFUSE_SOUR,
        .holdEffectParam = CONFUSE_BERRY_HEAL_FRACTION,
        .description = sFigyBerryDesc,
        .descricao = COMPOUND_STRING(
            "Um item de retenção\n"
            "que cura HP, mas\n"
            "pode confundir."),
        .descricion = COMPOUND_STRING(
            "Un elemento de\n"
            "retención que cura\n"
            "HP pero que"),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_IapapaBerry,
        .iconPalette = gItemIconPalette_IapapaBerry,
    },

    [ITEM_RAZZ_BERRY] =
    {
        .name = ITEM_NAME("Razz Berry"),
        .nombre = ITEM_NAME("Bayas de frambuesa"),
        .pluralName = ITEM_PLURAL_NAME("Razz Berries"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
            "{POKEBLOCK} ingredient. Plant\n"
            "in loamy soil to\n"
            "grow Razz."),
        .descricao = COMPOUND_STRING(
            "Ingrediente {POKEBLOCK}.\n"
            "Plante em solo\n"
            "argiloso."),
        .descricion = COMPOUND_STRING(
            "{POKEBLOCK} ingrediente.\n"
            "Plante en suelo\n"
            "arcilloso."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_RazzBerry,
        .iconPalette = gItemIconPalette_RazzBerry,
    },

    [ITEM_BLUK_BERRY] =
    {
        .name = ITEM_NAME("Bluk Berry"),
        .nombre = ITEM_NAME("baya azul"),
        .pluralName = ITEM_PLURAL_NAME("Bluk Berries"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
            "{POKEBLOCK} ingredient. Plant\n"
            "in loamy soil to\n"
            "grow Bluk."),
        .descricao = COMPOUND_STRING(
            "Ingrediente {POKEBLOCK}.\n"
            "Plante em solo\n"
            "argiloso."),
        .descricion = COMPOUND_STRING(
            "{POKEBLOCK} ingrediente.\n"
            "Plante en suelo\n"
            "arcilloso."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_BlukBerry,
        .iconPalette = gItemIconPalette_BlukBerry,
    },

    [ITEM_NANAB_BERRY] =
    {
        .name = ITEM_NAME("Nanab Berry"),
        .nombre = ITEM_NAME("Baya Nanab"),
        .pluralName = ITEM_PLURAL_NAME("Nanab Berries"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
            "{POKEBLOCK} ingredient. Plant\n"
            "in loamy soil to\n"
            "grow Nanab."),
        .descricao = COMPOUND_STRING(
            "Ingrediente {POKEBLOCK}.\n"
            "Plante em solo\n"
            "argiloso."),
        .descricion = COMPOUND_STRING(
            "{POKEBLOCK} ingrediente.\n"
            "Plante en suelo\n"
            "arcilloso."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_NanabBerry,
        .iconPalette = gItemIconPalette_NanabBerry,
    },

    [ITEM_WEPEAR_BERRY] =
    {
        .name = ITEM_NAME("Wepear Berry"),
        .nombre = ITEM_NAME("Baya Wepear"),
        .pluralName = ITEM_PLURAL_NAME("Wepear Berries"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
            "{POKEBLOCK} ingredient. Plant\n"
            "in loamy soil to\n"
            "grow Wepear."),
        .descricao = COMPOUND_STRING(
            "Ingrediente {POKEBLOCK}.\n"
            "Plante em solo\n"
            "argiloso."),
        .descricion = COMPOUND_STRING(
            "{POKEBLOCK} ingrediente.\n"
            "Plante en suelo\n"
            "arcilloso."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_WepearBerry,
        .iconPalette = gItemIconPalette_WepearBerry,
    },

    [ITEM_PINAP_BERRY] =
    {
        .name = ITEM_NAME("Pinap Berry"),
        .nombre = ITEM_NAME("Baya de pina"),
        .pluralName = ITEM_PLURAL_NAME("Pinap Berries"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
            "{POKEBLOCK} ingredient. Plant\n"
            "in loamy soil to\n"
            "grow Pinap."),
        .descricao = COMPOUND_STRING(
            "Ingrediente {POKEBLOCK}.\n"
            "Plante em solo\n"
            "argiloso."),
        .descricion = COMPOUND_STRING(
            "{POKEBLOCK} ingrediente.\n"
            "Plante en suelo\n"
            "arcilloso."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_PinapBerry,
        .iconPalette = gItemIconPalette_PinapBerry,
    },

    [ITEM_POMEG_BERRY] =
    {
        .name = ITEM_NAME("Pomeg Berry"),
        .nombre = ITEM_NAME("baya de pomeg"),
        .pluralName = ITEM_PLURAL_NAME("Pomeg Berries"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
            "Makes a Pokémon\n"
            "friendly but cuts\n"
            "base HP."),
        .descricao = COMPOUND_STRING(
            "Torna um Pokémon\n"
            "amigável, mas reduz\n"
            "o HP base."),
        .descricion = COMPOUND_STRING(
            "Hace que un Pokémon\n"
            "sea amigable pero\n"
            "reduce el HP base."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_ReduceEV,
        .effect = gItemEffect_PomegBerry,
        .flingPower = 10,
        .iconPic = gItemIcon_PomegBerry,
        .iconPalette = gItemIconPalette_PomegBerry,
    },

    [ITEM_KELPSY_BERRY] =
    {
        .name = ITEM_NAME("Kelpsy Berry"),
        .nombre = ITEM_NAME("Baya Kelpsia"),
        .pluralName = ITEM_PLURAL_NAME("Kelpsy Berries"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
            "Makes a Pokémon\n"
            "friendly but cuts\n"
            "base Atk."),
        .descricao = COMPOUND_STRING(
            "Torna um Pokémon\n"
            "amigável, mas reduz\n"
            "o Atq. base."),
        .descricion = COMPOUND_STRING(
            "Hace que un Pokémon\n"
            "sea amigable pero\n"
            "reduce el Atq."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_ReduceEV,
        .effect = gItemEffect_KelpsyBerry,
        .flingPower = 10,
        .iconPic = gItemIcon_KelpsyBerry,
        .iconPalette = gItemIconPalette_KelpsyBerry,
    },

    [ITEM_QUALOT_BERRY] =
    {
        .name = ITEM_NAME("Qualot Berry"),
        .nombre = ITEM_NAME("Baya de qualot"),
        .pluralName = ITEM_PLURAL_NAME("Qualot Berries"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
            "Makes a Pokémon\n"
            "friendly but cuts\n"
            "base Def."),
        .descricao = COMPOUND_STRING(
            "Torna um Pokémon\n"
            "amigável, mas reduz\n"
            "a Def. base."),
        .descricion = COMPOUND_STRING(
            "Hace que un Pokémon\n"
            "sea amigable pero\n"
            "reduce la defensa."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_ReduceEV,
        .effect = gItemEffect_QualotBerry,
        .flingPower = 10,
        .iconPic = gItemIcon_QualotBerry,
        .iconPalette = gItemIconPalette_QualotBerry,
    },

    [ITEM_HONDEW_BERRY] =
    {
        .name = ITEM_NAME("Hondew Berry"),
        .nombre = ITEM_NAME("Baya Hondew"),
        .pluralName = ITEM_PLURAL_NAME("Hondew Berries"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
            "Makes a Pokémon\n"
            "friendly but cuts\n"
            "base Sp. Atk."),
        .descricao = COMPOUND_STRING(
            "Torna um Pokémon\n"
            "amigável, mas reduz\n"
            "o Sp base. Atk."),
        .descricion = COMPOUND_STRING(
            "Hace que un Pokémon\n"
            "sea amigable pero\n"
            "reduce el Sp base."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_ReduceEV,
        .effect = gItemEffect_HondewBerry,
        .flingPower = 10,
        .iconPic = gItemIcon_HondewBerry,
        .iconPalette = gItemIconPalette_HondewBerry,
    },

    [ITEM_GREPA_BERRY] =
    {
        .name = ITEM_NAME("Grepa Berry"),
        .nombre = ITEM_NAME("Baya de grepa"),
        .pluralName = ITEM_PLURAL_NAME("Grepa Berries"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
            "Makes a Pokémon\n"
            "friendly but cuts\n"
            "base Sp. Def."),
        .descricao = COMPOUND_STRING(
            "Torna um Pokémon\n"
            "amigável, mas reduz\n"
            "o Sp base."),
        .descricion = COMPOUND_STRING(
            "Hace que un Pokémon\n"
            "sea amigable pero\n"
            "reduce el Sp base."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_ReduceEV,
        .effect = gItemEffect_GrepaBerry,
        .flingPower = 10,
        .iconPic = gItemIcon_GrepaBerry,
        .iconPalette = gItemIconPalette_GrepaBerry,
    },

    [ITEM_TAMATO_BERRY] =
    {
        .name = ITEM_NAME("Tamato Berry"),
        .nombre = ITEM_NAME("Baya de tamato"),
        .pluralName = ITEM_PLURAL_NAME("Tamato Berries"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
            "Makes a Pokémon\n"
            "friendly but cuts\n"
            "base Speed."),
        .descricao = COMPOUND_STRING(
            "Torna um Pokémon\n"
            "amigável, mas reduz\n"
            "a Vel. base."),
        .descricion = COMPOUND_STRING(
            "Hace un Pokémon sea\n"
            "amigable pero\n"
            "reduce la Vel."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_ReduceEV,
        .effect = gItemEffect_TamatoBerry,
        .flingPower = 10,
        .iconPic = gItemIcon_TamatoBerry,
        .iconPalette = gItemIconPalette_TamatoBerry,
    },

    [ITEM_CORNN_BERRY] =
    {
        .name = ITEM_NAME("Cornn Berry"),
        .nombre = ITEM_NAME("baya de maiz"),
        .pluralName = ITEM_PLURAL_NAME("Cornn Berries"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
            "{POKEBLOCK} ingredient. Plant\n"
            "in loamy soil to\n"
            "grow Cornn."),
        .descricao = COMPOUND_STRING(
            "Ingrediente {POKEBLOCK}.\n"
            "Plante em solo\n"
            "argiloso."),
        .descricion = COMPOUND_STRING(
            "{POKEBLOCK} ingrediente.\n"
            "Plante en suelo\n"
            "arcilloso."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_CornnBerry,
        .iconPalette = gItemIconPalette_CornnBerry,
    },

    [ITEM_MAGOST_BERRY] =
    {
        .name = ITEM_NAME("Magost Berry"),
        .nombre = ITEM_NAME("Baya de magost"),
        .pluralName = ITEM_PLURAL_NAME("Magost Berries"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
            "{POKEBLOCK} ingredient. Plant\n"
            "in loamy soil to\n"
            "grow Magost."),
        .descricao = COMPOUND_STRING(
            "Ingrediente {POKEBLOCK}.\n"
            "Plante em solo\n"
            "argiloso."),
        .descricion = COMPOUND_STRING(
            "{POKEBLOCK} ingrediente.\n"
            "Plante en suelo\n"
            "arcilloso."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_MagostBerry,
        .iconPalette = gItemIconPalette_MagostBerry,
    },

    [ITEM_RABUTA_BERRY] =
    {
        .name = ITEM_NAME("Rabuta Berry"),
        .nombre = ITEM_NAME("Baya de rabuta"),
        .pluralName = ITEM_PLURAL_NAME("Rabuta Berries"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
            "{POKEBLOCK} ingredient. Plant\n"
            "in loamy soil to\n"
            "grow Rabuta."),
        .descricao = COMPOUND_STRING(
            "Ingrediente {POKEBLOCK}.\n"
            "Plante em solo\n"
            "argiloso."),
        .descricion = COMPOUND_STRING(
            "{POKEBLOCK} ingrediente.\n"
            "Plante en suelo\n"
            "arcilloso."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_RabutaBerry,
        .iconPalette = gItemIconPalette_RabutaBerry,
    },

    [ITEM_NOMEL_BERRY] =
    {
        .name = ITEM_NAME("Nomel Berry"),
        .nombre = ITEM_NAME("Nomel Berry"),
        .pluralName = ITEM_PLURAL_NAME("Nomel Berries"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
            "{POKEBLOCK} ingredient. Plant\n"
            "in loamy soil to\n"
            "grow Nomel."),
        .descricao = COMPOUND_STRING(
            "Ingrediente {POKEBLOCK}.\n"
            "Plante em solo\n"
            "argiloso."),
        .descricion = COMPOUND_STRING(
            "{POKEBLOCK} ingrediente.\n"
            "Plante en suelo\n"
            "arcilloso."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_NomelBerry,
        .iconPalette = gItemIconPalette_NomelBerry,
    },

    [ITEM_SPELON_BERRY] =
    {
        .name = ITEM_NAME("Spelon Berry"),
        .nombre = ITEM_NAME("Baya de espelon"),
        .pluralName = ITEM_PLURAL_NAME("Spelon Berries"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
            "{POKEBLOCK} ingredient. Plant\n"
            "in loamy soil to\n"
            "grow Spelon."),
        .descricao = COMPOUND_STRING(
            "Ingrediente {POKEBLOCK}.\n"
            "Plante em solo\n"
            "argiloso."),
        .descricion = COMPOUND_STRING(
            "{POKEBLOCK} ingrediente.\n"
            "Plante en suelo\n"
            "arcilloso."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_SpelonBerry,
        .iconPalette = gItemIconPalette_SpelonBerry,
    },

    [ITEM_PAMTRE_BERRY] =
    {
        .name = ITEM_NAME("Pamtre Berry"),
        .nombre = ITEM_NAME("Pamtre Berry"),
        .pluralName = ITEM_PLURAL_NAME("Pamtre Berries"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
            "{POKEBLOCK} ingredient. Plant\n"
            "in loamy soil to\n"
            "grow Pamtre."),
        .descricao = COMPOUND_STRING(
            "Ingrediente {POKEBLOCK}.\n"
            "Plante em solo\n"
            "argiloso."),
        .descricion = COMPOUND_STRING(
            "{POKEBLOCK} ingrediente.\n"
            "Plante en suelo\n"
            "arcilloso."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_PamtreBerry,
        .iconPalette = gItemIconPalette_PamtreBerry,
    },

    [ITEM_WATMEL_BERRY] =
    {
        .name = ITEM_NAME("Watmel Berry"),
        .nombre = ITEM_NAME("Baya de watmel"),
        .pluralName = ITEM_PLURAL_NAME("Watmel Berries"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
            "{POKEBLOCK} ingredient. Plant\n"
            "in loamy soil to\n"
            "grow Watmel."),
        .descricao = COMPOUND_STRING(
            "Ingrediente {POKEBLOCK}.\n"
            "Plante em solo\n"
            "argiloso."),
        .descricion = COMPOUND_STRING(
            "{POKEBLOCK} ingrediente.\n"
            "Plante en suelo\n"
            "arcilloso."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_WatmelBerry,
        .iconPalette = gItemIconPalette_WatmelBerry,
    },

    [ITEM_DURIN_BERRY] =
    {
        .name = ITEM_NAME("Durin Berry"),
        .nombre = ITEM_NAME("baya durin"),
        .pluralName = ITEM_PLURAL_NAME("Durin Berries"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
            "{POKEBLOCK} ingredient. Plant\n"
            "in loamy soil to\n"
            "grow Durin."),
        .descricao = COMPOUND_STRING(
            "Ingrediente {POKEBLOCK}.\n"
            "Plante em solo\n"
            "argiloso."),
        .descricion = COMPOUND_STRING(
            "{POKEBLOCK} ingrediente.\n"
            "Plante en suelo\n"
            "arcilloso."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_DurinBerry,
        .iconPalette = gItemIconPalette_DurinBerry,
    },

    [ITEM_BELUE_BERRY] =
    {
        .name = ITEM_NAME("Belue Berry"),
        .nombre = ITEM_NAME("baya belue"),
        .pluralName = ITEM_PLURAL_NAME("Belue Berries"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
            "{POKEBLOCK} ingredient. Plant\n"
            "in loamy soil to\n"
            "grow Belue."),
        .descricao = COMPOUND_STRING(
            "Ingrediente {POKEBLOCK}.\n"
            "Plante em solo\n"
            "argiloso."),
        .descricion = COMPOUND_STRING(
            "{POKEBLOCK} ingrediente.\n"
            "Plante en suelo\n"
            "arcilloso."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_BelueBerry,
        .iconPalette = gItemIconPalette_BelueBerry,
    },

    [ITEM_CHILAN_BERRY] =
    {
        .name = ITEM_NAME("Chilan Berry"),
        .nombre = ITEM_NAME("Baya chilena"),
        .pluralName = ITEM_PLURAL_NAME("Chilan Berries"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_NORMAL,
        .description = COMPOUND_STRING(
            "A hold item that\n"
            "weakens a Normal\n"
            "move."),
        .descricao = COMPOUND_STRING(
            "Um item de retenção\n"
            "que enfraquece um\n"
            "golpe Normal."),
        .descricion = COMPOUND_STRING(
            "Un elemento de\n"
            "retención que\n"
            "debilita un mov."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_ChilanBerry,
        .iconPalette = gItemIconPalette_ChilanBerry,
    },

    [ITEM_OCCA_BERRY] =
    {
        .name = ITEM_NAME("Occa Berry"),
        .nombre = ITEM_NAME("baya de occa"),
        .pluralName = ITEM_PLURAL_NAME("Occa Berries"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_FIRE,
        .description = COMPOUND_STRING(
            "A hold item that\n"
            "weakens a Fire move\n"
            "if weak to it."),
        .descricao = COMPOUND_STRING(
            "Um item retenção\n"
            "enfraquece golpe\n"
            "Fogo for"),
        .descricion = COMPOUND_STRING(
            "Un elemento\n"
            "retención debilita\n"
            "un mov."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_OccaBerry,
        .iconPalette = gItemIconPalette_OccaBerry,
    },

    [ITEM_PASSHO_BERRY] =
    {
        .name = ITEM_NAME("Passho Berry"),
        .nombre = ITEM_NAME("Baya pasho"),
        .pluralName = ITEM_PLURAL_NAME("Passho Berries"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_WATER,
        .description = COMPOUND_STRING(
            "A hold item that\n"
            "weakens a Water\n"
            "move if weak to it."),
        .descricao = COMPOUND_STRING(
            "Um item de retenção\n"
            "que enfraquece um\n"
            "golpe Água se for."),
        .descricion = COMPOUND_STRING(
            "Un elemento\n"
            "retención debilita\n"
            "un mov."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_PasshoBerry,
        .iconPalette = gItemIconPalette_PasshoBerry,
    },

    [ITEM_WACAN_BERRY] =
    {
        .name = ITEM_NAME("Wacan Berry"),
        .nombre = ITEM_NAME("Baya de Wacan"),
        .pluralName = ITEM_PLURAL_NAME("Wacan Berries"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_ELECTRIC,
        .description = COMPOUND_STRING(
            "A hold item that\n"
            "weakens a Electric\n"
            "move if weak to it."),
        .descricao = COMPOUND_STRING(
            "Um item de retenção\n"
            "que enfraquece um\n"
            "golpe elétrico se."),
        .descricion = COMPOUND_STRING(
            "Un elemento de\n"
            "retención que\n"
            "debilita un mov."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_WacanBerry,
        .iconPalette = gItemIconPalette_WacanBerry,
    },

    [ITEM_RINDO_BERRY] =
    {
        .name = ITEM_NAME("Rindo Berry"),
        .nombre = ITEM_NAME("Rindo Berry"),
        .pluralName = ITEM_PLURAL_NAME("Rindo Berries"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_GRASS,
        .description = COMPOUND_STRING(
            "A hold item that\n"
            "weakens a Grass\n"
            "move if weak to it."),
        .descricao = COMPOUND_STRING(
            "Um item de retenção\n"
            "que enfraquece um\n"
            "golpe de grama se."),
        .descricion = COMPOUND_STRING(
            "Un elemento\n"
            "retención debilita\n"
            "un mov."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_RindoBerry,
        .iconPalette = gItemIconPalette_RindoBerry,
    },

    [ITEM_YACHE_BERRY] =
    {
        .name = ITEM_NAME("Yache Berry"),
        .nombre = ITEM_NAME("Yache Berry"),
        .pluralName = ITEM_PLURAL_NAME("Yache Berries"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_ICE,
        .description = COMPOUND_STRING(
            "A hold item that\n"
            "weakens a Ice move\n"
            "if weak to it."),
        .descricao = COMPOUND_STRING(
            "Um item retenção\n"
            "enfraquece golpe\n"
            "Gelo for"),
        .descricion = COMPOUND_STRING(
            "Un elemento\n"
            "retención debilita\n"
            "un mov."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_YacheBerry,
        .iconPalette = gItemIconPalette_YacheBerry,
    },

    [ITEM_CHOPLE_BERRY] =
    {
        .name = ITEM_NAME("Chople Berry"),
        .nombre = ITEM_NAME("Baya picada"),
        .pluralName = ITEM_PLURAL_NAME("Chople Berries"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_FIGHTING,
        .description = COMPOUND_STRING(
            "A hold item that\n"
            "weakens a Fighting\n"
            "move if weak to it."),
        .descricao = COMPOUND_STRING(
            "Um item retenção\n"
            "enfraquece golpe\n"
            "Luta for"),
        .descricion = COMPOUND_STRING(
            "Un elemento\n"
            "retención debilita\n"
            "un mov."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_ChopleBerry,
        .iconPalette = gItemIconPalette_ChopleBerry,
    },

    [ITEM_KEBIA_BERRY] =
    {
        .name = ITEM_NAME("Kebia Berry"),
        .nombre = ITEM_NAME("Kebia Berry"),
        .pluralName = ITEM_PLURAL_NAME("Kebia Berries"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_POISON,
        .description = COMPOUND_STRING(
            "A hold item that\n"
            "weakens a Poison\n"
            "move if weak to it."),
        .descricao = COMPOUND_STRING(
            "Um item retenção\n"
            "enfraquece golpe\n"
            "Veneno for."),
        .descricion = COMPOUND_STRING(
            "Un elemento de\n"
            "retención que\n"
            "debilita un mov."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_KebiaBerry,
        .iconPalette = gItemIconPalette_KebiaBerry,
    },

    [ITEM_SHUCA_BERRY] =
    {
        .name = ITEM_NAME("Shuca Berry"),
        .nombre = ITEM_NAME("Baya Shuca"),
        .pluralName = ITEM_PLURAL_NAME("Shuca Berries"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_GROUND,
        .description = COMPOUND_STRING(
            "A hold item that\n"
            "weakens a Ground\n"
            "move if weak to it."),
        .descricao = COMPOUND_STRING(
            "Um item de retenção\n"
            "que enfraquece um\n"
            "golpe terrestre se."),
        .descricion = COMPOUND_STRING(
            "Un elemento de\n"
            "retención que\n"
            "debilita un mov."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_ShucaBerry,
        .iconPalette = gItemIconPalette_ShucaBerry,
    },

    [ITEM_COBA_BERRY] =
    {
        .name = ITEM_NAME("Coba Berry"),
        .nombre = ITEM_NAME("Baya de Coba"),
        .pluralName = ITEM_PLURAL_NAME("Coba Berries"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_FLYING,
        .description = COMPOUND_STRING(
            "A hold item that\n"
            "weakens a Flying\n"
            "move if weak to it."),
        .descricao = COMPOUND_STRING(
            "Um item retenção\n"
            "enfraquece golpe\n"
            "Voador for."),
        .descricion = COMPOUND_STRING(
            "Un elemento\n"
            "retención debilita\n"
            "un mov."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_CobaBerry,
        .iconPalette = gItemIconPalette_CobaBerry,
    },

    [ITEM_PAYAPA_BERRY] =
    {
        .name = ITEM_NAME("Payapa Berry"),
        .nombre = ITEM_NAME("Baya De Payapa"),
        .pluralName = ITEM_PLURAL_NAME("Payapa Berries"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_PSYCHIC,
        .description = COMPOUND_STRING(
            "A hold item that\n"
            "weakens a Psychic\n"
            "move if weak to it."),
        .descricao = COMPOUND_STRING(
            "Um item de retenção\n"
            "que enfraquece um\n"
            "golpe psíquico se."),
        .descricion = COMPOUND_STRING(
            "Un elemento de\n"
            "retención que\n"
            "debilita un mov."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_PayapaBerry,
        .iconPalette = gItemIconPalette_PayapaBerry,
    },

    [ITEM_TANGA_BERRY] =
    {
        .name = ITEM_NAME("Tanga Berry"),
        .nombre = ITEM_NAME("baya de tanga"),
        .pluralName = ITEM_PLURAL_NAME("Tanga Berries"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_BUG,
        .description = COMPOUND_STRING(
            "A hold item that\n"
            "weakens a Bug move\n"
            "if weak to it."),
        .descricao = COMPOUND_STRING(
            "Um item retenção\n"
            "enfraquece golpe\n"
            "Bug for."),
        .descricion = COMPOUND_STRING(
            "Un elemento\n"
            "retención debilita\n"
            "un mov."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_TangaBerry,
        .iconPalette = gItemIconPalette_TangaBerry,
    },

    [ITEM_CHARTI_BERRY] =
    {
        .name = ITEM_NAME("Charti Berry"),
        .nombre = ITEM_NAME("baya charti"),
        .pluralName = ITEM_PLURAL_NAME("Charti Berries"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_ROCK,
        .description = COMPOUND_STRING(
            "A hold item that\n"
            "weakens a Rock move\n"
            "if weak to it."),
        .descricao = COMPOUND_STRING(
            "Um item de retenção\n"
            "que enfraquece um\n"
            "golpe Rock se for."),
        .descricion = COMPOUND_STRING(
            "Un elemento\n"
            "retención debilita\n"
            "un mov."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_ChartiBerry,
        .iconPalette = gItemIconPalette_ChartiBerry,
    },

    [ITEM_KASIB_BERRY] =
    {
        .name = ITEM_NAME("Kasib Berry"),
        .nombre = ITEM_NAME("Kasib Berry"),
        .pluralName = ITEM_PLURAL_NAME("Kasib Berries"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_GHOST,
        .description = COMPOUND_STRING(
            "A hold item that\n"
            "weakens a Ghost\n"
            "move if weak to it."),
        .descricao = COMPOUND_STRING(
            "Um item de retenção\n"
            "que enfraquece um\n"
            "golpe Fantasma se."),
        .descricion = COMPOUND_STRING(
            "Un elemento de\n"
            "retención que\n"
            "debilita un mov."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_KasibBerry,
        .iconPalette = gItemIconPalette_KasibBerry,
    },

    [ITEM_HABAN_BERRY] =
    {
        .name = ITEM_NAME("Haban Berry"),
        .nombre = ITEM_NAME("baya habana"),
        .pluralName = ITEM_PLURAL_NAME("Haban Berries"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_DRAGON,
        .description = COMPOUND_STRING(
            "A hold item that\n"
            "weakens a Dragon\n"
            "move if weak to it."),
        .descricao = COMPOUND_STRING(
            "Um item de retenção\n"
            "que enfraquece um\n"
            "golpe do Dragão se."),
        .descricion = COMPOUND_STRING(
            "Un elemento\n"
            "retención debilita\n"
            "el mov."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_HabanBerry,
        .iconPalette = gItemIconPalette_HabanBerry,
    },

    [ITEM_COLBUR_BERRY] =
    {
        .name = ITEM_NAME("Colbur Berry"),
        .nombre = ITEM_NAME("Baya de Colbur"),
        .pluralName = ITEM_PLURAL_NAME("Colbur Berries"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_DARK,
        .description = COMPOUND_STRING(
            "A hold item that\n"
            "weakens a Dark move\n"
            "if weak to it."),
        .descricao = COMPOUND_STRING(
            "Um item retenção\n"
            "enfraquece golpe\n"
            "Trevas"),
        .descricion = COMPOUND_STRING(
            "Un elemento de\n"
            "retención que\n"
            "debilita un mov."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_ColburBerry,
        .iconPalette = gItemIconPalette_ColburBerry,
    },

    [ITEM_BABIRI_BERRY] =
    {
        .name = ITEM_NAME("Babiri Berry"),
        .nombre = ITEM_NAME("Baya Babiri"),
        .pluralName = ITEM_PLURAL_NAME("Babiri Berries"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_STEEL,
        .description = COMPOUND_STRING(
            "A hold item that\n"
            "weakens a Steel\n"
            "move if weak to it."),
        .descricao = COMPOUND_STRING(
            "Um item retenção\n"
            "enfraquece golpe\n"
            "Aço for."),
        .descricion = COMPOUND_STRING(
            "Un elemento\n"
            "retención debilita\n"
            "un mov."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_BabiriBerry,
        .iconPalette = gItemIconPalette_BabiriBerry,
    },

    [ITEM_ROSELI_BERRY] =
    {
        .name = ITEM_NAME("Roseli Berry"),
        .nombre = ITEM_NAME("rosali berry"),
        .pluralName = ITEM_PLURAL_NAME("Roseli Berries"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_FAIRY,
        .description = COMPOUND_STRING(
            "A hold item that\n"
            "weakens a Fairy\n"
            "move if weak to it."),
        .descricao = COMPOUND_STRING(
            "Um item retenção\n"
            "enfraquece golpe\n"
            "Fada for"),
        .descricion = COMPOUND_STRING(
            "Un elemento\n"
            "retención debilita\n"
            "un mov."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_RoseliBerry,
        .iconPalette = gItemIconPalette_RoseliBerry,
    },

    [ITEM_LIECHI_BERRY] =
    {
        .name = ITEM_NAME("Liechi Berry"),
        .nombre = ITEM_NAME("Baya de Liechi"),
        .pluralName = ITEM_PLURAL_NAME("Liechi Berries"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_ATTACK_UP,
        .holdEffectParam = 4,
        .description = COMPOUND_STRING(
            "A hold item that\n"
            "boosts Atk. in a\n"
            "pinch."),
        .descricao = COMPOUND_STRING(
            "Um item de retenção\n"
            "que sobe o Atq.\n"
            "rapidamente."),
        .descricion = COMPOUND_STRING(
            "Un elemento de\n"
            "retención que sobe\n"
            "el Atq. en"),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_LiechiBerry,
        .iconPalette = gItemIconPalette_LiechiBerry,
    },

    [ITEM_GANLON_BERRY] =
    {
        .name = ITEM_NAME("Ganlon Berry"),
        .nombre = ITEM_NAME("Baya de Ganlon"),
        .pluralName = ITEM_PLURAL_NAME("Ganlon Berries"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_DEFENSE_UP,
        .holdEffectParam = 4,
        .description = COMPOUND_STRING(
            "A hold item that\n"
            "boosts Def. in a\n"
            "pinch."),
        .descricao = COMPOUND_STRING(
            "Um item de retenção\n"
            "que sobe a Def.\n"
            "rapidamente."),
        .descricion = COMPOUND_STRING(
            "Un elemento de\n"
            "retención que sobe\n"
            "la defensa."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_GanlonBerry,
        .iconPalette = gItemIconPalette_GanlonBerry,
    },

    [ITEM_SALAC_BERRY] =
    {
        .name = ITEM_NAME("Salac Berry"),
        .nombre = ITEM_NAME("Baya de salac"),
        .pluralName = ITEM_PLURAL_NAME("Salac Berries"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_SPEED_UP,
        .holdEffectParam = 4,
        .description = COMPOUND_STRING(
            "A hold item that\n"
            "boosts Speed in a\n"
            "pinch."),
        .descricao = COMPOUND_STRING(
            "Um item de retenção\n"
            "que sobe a Vel.\n"
            "rapidamente."),
        .descricion = COMPOUND_STRING(
            "Un elemento de\n"
            "retención que sobe\n"
            "la Vel. en."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_SalacBerry,
        .iconPalette = gItemIconPalette_SalacBerry,
    },

    [ITEM_PETAYA_BERRY] =
    {
        .name = ITEM_NAME("Petaya Berry"),
        .nombre = ITEM_NAME("Baya de Petaya"),
        .pluralName = ITEM_PLURAL_NAME("Petaya Berries"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_SP_ATTACK_UP,
        .holdEffectParam = 4,
        .description = COMPOUND_STRING(
            "A hold item that\n"
            "boosts Sp. Atk in a\n"
            "pinch."),
        .descricao = COMPOUND_STRING(
            "Um item de espera\n"
            "que sobe Sp. Atk em\n"
            "apuros."),
        .descricion = COMPOUND_STRING(
            "Un elemento\n"
            "retenido sobe Sp.\n"
            "Atk en caso apuro."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_PetayaBerry,
        .iconPalette = gItemIconPalette_PetayaBerry,
    },

    [ITEM_APICOT_BERRY] =
    {
        .name = ITEM_NAME("Apicot Berry"),
        .nombre = ITEM_NAME("Baya de apicota"),
        .pluralName = ITEM_PLURAL_NAME("Apicot Berries"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_SP_DEFENSE_UP,
        .holdEffectParam = 4,
        .description = COMPOUND_STRING(
            "A hold item that\n"
            "boosts Sp. Def in a\n"
            "pinch."),
        .descricao = COMPOUND_STRING(
            "Um item de espera\n"
            "que sobe Sp.\n"
            "Definitivamente em."),
        .descricion = COMPOUND_STRING(
            "Un elemento\n"
            "retenido sobe Sp.\n"
            "Definitivamente en."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_ApicotBerry,
        .iconPalette = gItemIconPalette_ApicotBerry,
    },

    [ITEM_LANSAT_BERRY] =
    {
        .name = ITEM_NAME("Lansat Berry"),
        .nombre = ITEM_NAME("Baya Lansat"),
        .pluralName = ITEM_PLURAL_NAME("Lansat Berries"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_CRITICAL_UP,
        .holdEffectParam = 4,
        .description = COMPOUND_STRING(
            "A hold item ups\n"
            "critical- hit rate\n"
            "in pinch."),
        .descricao = COMPOUND_STRING(
            "Um item de retenção\n"
            "que sobe\n"
            "rapidamente a taxa."),
        .descricion = COMPOUND_STRING(
            "Un elemento de\n"
            "retención que sobe\n"
            "la tasa de."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_LansatBerry,
        .iconPalette = gItemIconPalette_LansatBerry,
    },

    [ITEM_STARF_BERRY] =
    {
        .name = ITEM_NAME("Starf Berry"),
        .nombre = ITEM_NAME("baya estrella"),
        .pluralName = ITEM_PLURAL_NAME("Starf Berries"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RANDOM_STAT_UP,
        .holdEffectParam = 4,
        .description = COMPOUND_STRING(
            "A hold item that\n"
            "greatly boosts a\n"
            "stat in a pinch."),
        .descricao = COMPOUND_STRING(
            "Um item de retenção\n"
            "que sobe muito uma\n"
            "estatística em."),
        .descricion = COMPOUND_STRING(
            "Un elemento de\n"
            "retención que sobe\n"
            "mucho una."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_StarfBerry,
        .iconPalette = gItemIconPalette_StarfBerry,
    },

    [ITEM_ENIGMA_BERRY] =
    {
        .name = ITEM_NAME("Enigma Berry"),
        .nombre = ITEM_NAME("Baya Enigma"),
        .pluralName = ITEM_PLURAL_NAME("Enigma Berries"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_ENIGMA_BERRY,
        .description = COMPOUND_STRING(
            "A hold item that\n"
            "heals from super\n"
            "effective moves."),
        .descricao = COMPOUND_STRING(
            "Um item de retenção\n"
            "que cura com golpes\n"
            "supereficazes."),
        .descricion = COMPOUND_STRING(
            "Un elemento de\n"
            "retención que cura\n"
            "con movs. súper."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_EnigmaBerry,
        .iconPalette = gItemIconPalette_EnigmaBerry,
    },

    [ITEM_MICLE_BERRY] =
    {
        .name = ITEM_NAME("Micle Berry"),
        .nombre = ITEM_NAME("Micle Berry"),
        .pluralName = ITEM_PLURAL_NAME("Micle Berries"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_MICLE_BERRY,
        .holdEffectParam = 4,
        .description = COMPOUND_STRING(
            "When held, it ups\n"
            "the Accuracy of a\n"
            "move in a pinch."),
        .descricao = COMPOUND_STRING(
            "Quando segurado,\n"
            "sobe a prec. de um\n"
            "golpe em."),
        .descricion = COMPOUND_STRING(
            "Cuando se mantiene\n"
            "presionado, sobe la\n"
            "precisión de un."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_MicleBerry,
        .iconPalette = gItemIconPalette_MicleBerry,
    },

    [ITEM_CUSTAP_BERRY] =
    {
        .name = ITEM_NAME("Custap Berry"),
        .nombre = ITEM_NAME("Baya de Custap"),
        .pluralName = ITEM_PLURAL_NAME("Custap Berries"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_CUSTAP_BERRY,
        .holdEffectParam = 4,
        .description = COMPOUND_STRING(
            "It allows a Pokémon\n"
            "in a pinch to move\n"
            "first just once."),
        .descricao = COMPOUND_STRING(
            "Ele permite Pokémon\n"
            "em apuros mova\n"
            "primeiro apenas"),
        .descricion = COMPOUND_STRING(
            "Permite un Pokémon\n"
            "en apuros mueva\n"
            "primero solo."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_CustapBerry,
        .iconPalette = gItemIconPalette_CustapBerry,
    },

    [ITEM_JABOCA_BERRY] =
    {
        .name = ITEM_NAME("Jaboca Berry"),
        .nombre = ITEM_NAME("Baya de Jaboca"),
        .pluralName = ITEM_PLURAL_NAME("Jaboca Berries"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_JABOCA_BERRY,
        .description = COMPOUND_STRING(
            "If hit by physical\n"
            "move, will hurt\n"
            "attacker bit."),
        .descricao = COMPOUND_STRING(
            "Se for atingido por\n"
            "um golpe físico,\n"
            "machucará pouco o."),
        .descricion = COMPOUND_STRING(
            "Si lo golpea con un\n"
            "mov. físico,\n"
            "lastimará un poco."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_JabocaBerry,
        .iconPalette = gItemIconPalette_JabocaBerry,
    },

    [ITEM_ROWAP_BERRY] =
    {
        .name = ITEM_NAME("Rowap Berry"),
        .nombre = ITEM_NAME("Baya de Rowap"),
        .pluralName = ITEM_PLURAL_NAME("Rowap Berries"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_ROWAP_BERRY,
        .description = COMPOUND_STRING(
            "If hit by a special\n"
            "move, it will hurt\n"
            "the attacker a bit."),
        .descricao = COMPOUND_STRING(
            "Se for atingido por\n"
            "um golpe esp.,\n"
            "machucará pouco o."),
        .descricion = COMPOUND_STRING(
            "Si lo golpea un\n"
            "mov. esp., dañará\n"
            "un poco al."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_RowapBerry,
        .iconPalette = gItemIconPalette_RowapBerry,
    },

    [ITEM_KEE_BERRY] =
    {
        .name = ITEM_NAME("Kee Berry"),
        .nombre = ITEM_NAME("Kee Berry"),
        .pluralName = ITEM_PLURAL_NAME("Kee Berries"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_KEE_BERRY,
        .description = COMPOUND_STRING(
            "If hit by physical\n"
            "move, boosts Def.\n"
            "bit."),
        .descricao = COMPOUND_STRING(
            "Se for atingido por\n"
            "um golpe físico,\n"
            "sobe pouco a."),
        .descricion = COMPOUND_STRING(
            "Si es golpeado por\n"
            "un mov. físico,\n"
            "sobe un poco la."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_KeeBerry,
        .iconPalette = gItemIconPalette_KeeBerry,
    },

    [ITEM_MARANGA_BERRY] =
    {
        .name = ITEM_NAME("Maranga Berry"),
        .nombre = ITEM_NAME("Baya de Maranga"),
        .pluralName = ITEM_PLURAL_NAME("Maranga Berries"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_MARANGA_BERRY,
        .description = COMPOUND_STRING(
            "If hit by a special\n"
            "move, it boosts the\n"
            "Sp. Def. a bit."),
        .descricao = COMPOUND_STRING(
            "Se for atingido por\n"
            "um golpe esp., sobe\n"
            "o Sp."),
        .descricion = COMPOUND_STRING(
            "Si es golpeado por\n"
            "un mov. esp., sobe\n"
            "el Sp. Def."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_MarangaBerry,
        .iconPalette = gItemIconPalette_MarangaBerry,
    },

    [ITEM_ENIGMA_BERRY_E_READER] =
    {
        .name = ITEM_NAME("Enigma Berry"),
        .nombre = ITEM_NAME("Baya Enigma"),
        .pluralName = ITEM_PLURAL_NAME("Enigma Berries"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
            "{POKEBLOCK} ingredient. Plant\n"
            "in loamy soil to\n"
            "grow a mystery."),
        .descricao = COMPOUND_STRING(
            "Ingrediente {POKEBLOCK}.\n"
            "Plante em solo\n"
            "argiloso."),
        .descricion = COMPOUND_STRING(
            "{POKEBLOCK} ingrediente.\n"
            "Plante en suelo\n"
            "arcilloso."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU, // Type handled by ItemUseOutOfBattle_EnigmaBerry
        .fieldUseFunc = ItemUseOutOfBattle_EnigmaBerry,
        .battleUsage = EFFECT_ITEM_ENIGMA_BERRY_EREADER,
        .flingPower = 10,
        .iconPic = gItemIcon_EnigmaBerry,
        .iconPalette = gItemIconPalette_EnigmaBerry,
    },

// TMs/HMs. They don't have a set flingPower, as that's handled by GetFlingPowerFromItemId.

    [ITEM_TM_TAKE_DOWN] =
    {
        .name = ITEM_NAME("TM01"),
        .nombre = ITEM_NAME("MT01"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "A risky charge\n"
            "attack that also\n"
            "hurts the user."),
        .descricao = COMPOUND_STRING(
            "Carga arriscada que\n"
            "fere tambem o usu."),
        .descricion = COMPOUND_STRING(
            "Ataque de carga\n"
            "arriscada, también\n"
            "hiere al usu."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_CHARM] =
    {
        .name = ITEM_NAME("TM02"),
        .nombre = ITEM_NAME("MT02"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Charms the foe and\n"
            "greatly cuts its\n"
            "Atk."),
        .descricao = COMPOUND_STRING(
            "Encanta o inimigo e\n"
            "reduz drasticamente\n"
            "seu Atq."),
        .descricion = COMPOUND_STRING(
            "Encanta al enemigo\n"
            "y reduce\n"
            "drásticamente su."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_FAKE_TEARS] =
    {
        .name = ITEM_NAME("TM03"),
        .nombre = ITEM_NAME("MT03"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Feigns crying to\n"
            "greatly lower the\n"
            "foe's Sp. Def."),
        .descricao = COMPOUND_STRING(
            "Finge chorar para\n"
            "diminuir muito o\n"
            "Sp. Def. inimigo."),
        .descricion = COMPOUND_STRING(
            "Finge llorar para\n"
            "reducir bruscamente\n"
            "Sp. Def. rival."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_AGILITY] =
    {
        .name = ITEM_NAME("TM04"),
        .nombre = ITEM_NAME("MT04"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Relaxes the body to\n"
            "greatly boost\n"
            "Speed."),
        .descricao = COMPOUND_STRING(
            "Relaxa o corpo para\n"
            "subir muito a\n"
            "Velocidade."),
        .descricion = COMPOUND_STRING(
            "Relaja cuerpo para\n"
            "aumentar mucho\n"
            "velocidad."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_PROTECT] =
    {
        .name = ITEM_NAME("TM05"),
        .nombre = ITEM_NAME("MT05"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Protects the user\n"
            "from all attacks\n"
            "this turn."),
        .descricao = COMPOUND_STRING(
            "Protege o usu. de\n"
            "todos os ataques\n"
            "neste turno."),
        .descricion = COMPOUND_STRING(
            "Protege al usu. de\n"
            "todos los ataques\n"
            "este turno."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_FIRE_FANG] =
    {
        .name = ITEM_NAME("TM06"),
        .nombre = ITEM_NAME("MT06"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "May cause flinching\n"
            "or leave the foe\n"
            "with a burn."),
        .descricao = COMPOUND_STRING(
            "Pode causar\n"
            "hesitação ou deixar\n"
            "o inimigo queimado."),
        .descricion = COMPOUND_STRING(
            "Puede provocar\n"
            "estrem. o dejar al\n"
            "enemigo quemado."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_THUNDER_FANG] =
    {
        .name = ITEM_NAME("TM07"),
        .nombre = ITEM_NAME("MT07"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "May cause flinching\n"
            "or leave the foe\n"
            "paralyzed."),
        .descricao = COMPOUND_STRING(
            "Pode causar recuo\n"
            "ou paralisar o\n"
            "inimigo."),
        .descricion = COMPOUND_STRING(
            "Puede provocar\n"
            "estrem. o dejar al\n"
            "enemigo paralizado."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_ICE_FANG] =
    {
        .name = ITEM_NAME("TM08"),
        .nombre = ITEM_NAME("MT08"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "May cause flinching\n"
            "or leave the foe\n"
            "with frostbite."),
        .descricao = COMPOUND_STRING(
            "Pode causar\n"
            "hesitação ou deixar\n"
            "com frostbite."),
        .descricion = COMPOUND_STRING(
            "Puede provocar\n"
            "estrem. o dejar con\n"
            "frostbite."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_WATER_PULSE] =
    {
        .name = ITEM_NAME("TM09"),
        .nombre = ITEM_NAME("MT09"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Attacks ultrasonic\n"
            "waves. May confuse\n"
            "foe."),
        .descricao = COMPOUND_STRING(
            "Ataca com ondas\n"
            "ultrasônicas pode\n"
            "confundir inimigo."),
        .descricion = COMPOUND_STRING(
            "Ondas ultrasónicas\n"
            "que pueden causar\n"
            "confusión."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_LOW_KICK] =
    {
        .name = ITEM_NAME("TM10"),
        .nombre = ITEM_NAME("MT10"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "A kick inflicts\n"
            "more damage on\n"
            "heavier foes."),
        .descricao = COMPOUND_STRING(
            "Chute que causa\n"
            "mais dano em alvos\n"
            "pesados."),
        .descricion = COMPOUND_STRING(
            "Patada que daña más\n"
            "a enemigos pesados."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_ACID_SPRAY] =
    {
        .name = ITEM_NAME("TM11"),
        .nombre = ITEM_NAME("MT11"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Sprays acid that\n"
            "greatly cuts Sp.\n"
            "Def."),
        .descricao = COMPOUND_STRING(
            "Borrifa ácido\n"
            "derrete pele. Reduz\n"
            "Sp. Def."),
        .descricion = COMPOUND_STRING(
            "Rocía un ácido\n"
            "derrite piel.\n"
            "Reduce mucho Sp."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_ACROBATICS] =
    {
        .name = ITEM_NAME("TM12"),
        .nombre = ITEM_NAME("MT12"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Does double damage\n"
            "if the user has no\n"
            "item."),
        .descricao = COMPOUND_STRING(
            "Causa dano duplo se\n"
            "usu. não tiver\n"
            "nenhum item."),
        .descricion = COMPOUND_STRING(
            "Hace doble daño si\n"
            "usu. no tiene\n"
            "ningún objeto."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_STRUGGLE_BUG] =
    {
        .name = ITEM_NAME("TM13"),
        .nombre = ITEM_NAME("MT13"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Resisting, the user\n"
            "attacks the foes.\n"
            "Lowers Sp. Atk."),
        .descricao = COMPOUND_STRING(
            "Ataca inimigos e\n"
            "baixa muito o Atq.\n"
            "Esp."),
        .descricion = COMPOUND_STRING(
            "Al resistir, usu.\n"
            "ataca a enemigos.\n"
            "Reduce Sp. Atk."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_PSYBEAM] =
    {
        .name = ITEM_NAME("TM14"),
        .nombre = ITEM_NAME("MT14"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Fires a peculiar\n"
            "ray that may\n"
            "confuse the foe."),
        .descricao = COMPOUND_STRING(
            "Lança raio peculiar\n"
            "pode confundir\n"
            "inimigo."),
        .descricion = COMPOUND_STRING(
            "Rayo peculiar que\n"
            "puede confundir al\n"
            "enemigo."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_CONFUSE_RAY] =
    {
        .name = ITEM_NAME("TM15"),
        .nombre = ITEM_NAME("MT15"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "A sinister ray that\n"
            "confuses the foe."),
        .descricao = COMPOUND_STRING(
            "Um raio sinistro\n"
            "que confunde o\n"
            "inimigo."),
        .descricion = COMPOUND_STRING(
            "Un rayo siniestro\n"
            "que confunde al\n"
            "enemigo."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_THIEF] =
    {
        .name = ITEM_NAME("TM16"),
        .nombre = ITEM_NAME("MT16"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "While attacking, it\n"
            "may steal the foe's\n"
            "held item."),
        .descricao = COMPOUND_STRING(
            "Ao atacar, pode\n"
            "roubar o item do\n"
            "inimigo."),
        .descricion = COMPOUND_STRING(
            "Al atacar, puede\n"
            "robar el objeto del\n"
            "enemigo."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_DISARMING_VOICE] =
    {
        .name = ITEM_NAME("TM17"),
        .nombre = ITEM_NAME("MT17"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Lets out a charming\n"
            "cry that cannot be\n"
            "evaded."),
        .descricao = COMPOUND_STRING(
            "Solta um grito\n"
            "encantador que não\n"
            "pode ser evitado."),
        .descricion = COMPOUND_STRING(
            "Deja un grito\n"
            "encant. que no se\n"
            "puede eludir."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_TRAILBLAZE] =
    {
        .name = ITEM_NAME("TM18"),
        .nombre = ITEM_NAME("MT18"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "The user attacks\n"
            "suddenly, raising\n"
            "its Speed."),
        .descricao = COMPOUND_STRING(
            "O usu. ataca de\n"
            "repente, aumentando\n"
            "sua Velocidade."),
        .descricion = COMPOUND_STRING(
            "El usu. ataca de\n"
            "repente, aumentando\n"
            "su Velocidad."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_POUNCE] =
    {
        .name = ITEM_NAME("TM19"),
        .nombre = ITEM_NAME("MT19"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "The user pounces on\n"
            "the foe, lowering\n"
            "its Speed."),
        .descricao = COMPOUND_STRING(
            "O usu. ataca o\n"
            "inimigo, diminuindo\n"
            "sua Velocidade."),
        .descricion = COMPOUND_STRING(
            "Se abalanza y\n"
            "reduce Velocidad\n"
            "del enemigo."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_CHILLING_WATER] =
    {
        .name = ITEM_NAME("TM20"),
        .nombre = ITEM_NAME("MT20"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Ice-cold water cuts\n"
            "the target Atk."),
        .descricao = COMPOUND_STRING(
            "Uma ducha com água\n"
            "gelada diminui o\n"
            "Ataque do alvo."),
        .descricion = COMPOUND_STRING(
            "Una ducha con agua\n"
            "helada reduce Atq.\n"
            "objetivo."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_CHARGE_BEAM] =
    {
        .name = ITEM_NAME("TM21"),
        .nombre = ITEM_NAME("MT21"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Fires a beam of\n"
            "electricity. May\n"
            "raise Sp. Atk."),
        .descricao = COMPOUND_STRING(
            "Dispara feixe\n"
            "eletricidade. Pode\n"
            "aumentar Atq. Esp."),
        .descricion = COMPOUND_STRING(
            "Dispara un rayo\n"
            "electr. Puede\n"
            "aumentar Sp. Atk."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_FACADE] =
    {
        .name = ITEM_NAME("TM22"),
        .nombre = ITEM_NAME("MT22"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Boosts power when\n"
            "burned, paralyzed,\n"
            "or poisoned."),
        .descricao = COMPOUND_STRING(
            "Aumenta o poder\n"
            "quando queimado,\n"
            "parali. ou envene."),
        .descricion = COMPOUND_STRING(
            "Aumenta poder\n"
            "cuando se quema, se\n"
            "o se envene."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_POISON_TAIL] =
    {
        .name = ITEM_NAME("TM23"),
        .nombre = ITEM_NAME("MT23"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Has a high\n"
            "critical-hit ratio.\n"
            "May also poison."),
        .descricao = COMPOUND_STRING(
            "Tem alta taxa\n"
            "acerto crítico.\n"
            "Também pode envene."),
        .descricion = COMPOUND_STRING(
            "Tiene una alta\n"
            "golpes También\n"
            "puede envene."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_AERIAL_ACE] =
    {
        .name = ITEM_NAME("TM24"),
        .nombre = ITEM_NAME("MT24"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "An extremely speedy\n"
            "and unavoidable\n"
            "attack."),
        .descricao = COMPOUND_STRING(
            "Um Atq.\n"
            "extremamente rápido\n"
            "e inevitável."),
        .descricion = COMPOUND_STRING(
            "Un Atq.\n"
            "extremadamente\n"
            "rápido e."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_BULLDOZE] =
    {
        .name = ITEM_NAME("TM25"),
        .nombre = ITEM_NAME("MT25"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Stomps down on the\n"
            "ground. Hits all\n"
            "and cuts Speed."),
        .descricao = COMPOUND_STRING(
            "Pisa no chão.\n"
            "Atinge todos e\n"
            "diminui Velocidade."),
        .descricion = COMPOUND_STRING(
            "Pisotea el suelo.\n"
            "Golpea todos y\n"
            "reduce la."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_HEX] =
    {
        .name = ITEM_NAME("TM26"),
        .nombre = ITEM_NAME("MT26"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Does double damage\n"
            "if the foe has a\n"
            "status problem."),
        .descricao = COMPOUND_STRING(
            "Causa dobro dano se\n"
            "alvo tiver problema\n"
            "de estado."),
        .descricion = COMPOUND_STRING(
            "Hace doble daño si\n"
            "enemigo tiene un\n"
            "problema estado."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_SNARL] =
    {
        .name = ITEM_NAME("TM27"),
        .nombre = ITEM_NAME("MT27"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Yells and rants at\n"
            "the foe lowering\n"
            "its Sp. Atk."),
        .descricao = COMPOUND_STRING(
            "Grita e reclama com\n"
            "inimigo diminuindo\n"
            "seu Atq. Esp."),
        .descricion = COMPOUND_STRING(
            "Grita y contra\n"
            "enemigo que reduce\n"
            "su Atq. Esp."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_METAL_CLAW] =
    {
        .name = ITEM_NAME("TM28"),
        .nombre = ITEM_NAME("MT28"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "A claw attack that\n"
            "may raise the\n"
            "user's Atk."),
        .descricao = COMPOUND_STRING(
            "Um Atq. garra que\n"
            "pode aumentar o\n"
            "Atq. usu."),
        .descricion = COMPOUND_STRING(
            "Un Atq. garra que\n"
            "puede aumentar Atq.\n"
            "usu."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_MAGICAL_LEAF] =
    {
        .name = ITEM_NAME("TM29"),
        .nombre = ITEM_NAME("MT29"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Attacks with a\n"
            "strange leaf that\n"
            "cannot be evaded."),
        .descricao = COMPOUND_STRING(
            "Ataca com uma folha\n"
            "estranha que não\n"
            "pode ser evitada."),
        .descricion = COMPOUND_STRING(
            "Ataca con una hoja\n"
            "extraña que no se\n"
            "puede evadir."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_ICY_WIND] =
    {
        .name = ITEM_NAME("TM30"),
        .nombre = ITEM_NAME("MT30"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "A chilling attack\n"
            "that cuts the foe's\n"
            "Speed."),
        .descricao = COMPOUND_STRING(
            "Um Atq. assustador\n"
            "que reduz a Vel. do\n"
            "inimigo."),
        .descricion = COMPOUND_STRING(
            "Ataque helado que\n"
            "reduce Velocidad\n"
            "del enemigo."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_MUD_SHOT] =
    {
        .name = ITEM_NAME("TM31"),
        .nombre = ITEM_NAME("MT31"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Hurls mud at the\n"
            "foe and cuts Speed."),
        .descricao = COMPOUND_STRING(
            "Lança lama no\n"
            "inimigo e reduz a\n"
            "Velocidade."),
        .descricion = COMPOUND_STRING(
            "Lanza barro al\n"
            "enemigo y reduce la\n"
            "Velocidad."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_ROCK_TOMB] =
    {
        .name = ITEM_NAME("TM32"),
        .nombre = ITEM_NAME("MT32"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Stops the foe from\n"
            "moving with rocks\n"
            "and cuts Speed."),
        .descricao = COMPOUND_STRING(
            "Impede que inimigo\n"
            "se mova com pedras\n"
            "e reduz a Vel."),
        .descricion = COMPOUND_STRING(
            "Impide que enemigo\n"
            "se mueva con rocas\n"
            "y corta Vel."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_DRAINING_KISS] =
    {
        .name = ITEM_NAME("TM33"),
        .nombre = ITEM_NAME("MT33"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "A kiss attack that\n"
            "drains HP to heal\n"
            "the user."),
        .descricao = COMPOUND_STRING(
            "Beijo que drena HP\n"
            "para curar o usu."),
        .descricion = COMPOUND_STRING(
            "Beso que drena PS\n"
            "para curar al usu."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_FLAME_CHARGE] =
    {
        .name = ITEM_NAME("TM34"),
        .nombre = ITEM_NAME("MT34"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Attacks in a cloak\n"
            "of flames. Raises\n"
            "Speed."),
        .descricao = COMPOUND_STRING(
            "Ataca em um manto\n"
            "de chamas. Aumenta\n"
            "a Velocidade."),
        .descricion = COMPOUND_STRING(
            "Ataca en un manto\n"
            "de llamas. Aumenta\n"
            "la Velocidad."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_AIR_CUTTER] =
    {
        .name = ITEM_NAME("TM35"),
        .nombre = ITEM_NAME("MT35"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Hacks razorlike\n"
            "wind. High\n"
            "critical-hit ratio."),
        .descricao = COMPOUND_STRING(
            "Corta com vento\n"
            "afiado. Alta taxa\n"
            "de acerto crítico."),
        .descricion = COMPOUND_STRING(
            "Viento afilado.\n"
            "Suele dar golpes\n"
            "críticos."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_STORED_POWER] =
    {
        .name = ITEM_NAME("TM36"),
        .nombre = ITEM_NAME("MT36"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "The higher the\n"
            "user's stats the\n"
            "more damage caused."),
        .descricao = COMPOUND_STRING(
            "Quanto maiores os\n"
            "stats mais danos\n"
            "serão causados."),
        .descricion = COMPOUND_STRING(
            "Cuanto más altas\n"
            "sean stats usu.,\n"
            "más daño causará."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_NIGHT_SHADE] =
    {
        .name = ITEM_NAME("TM37"),
        .nombre = ITEM_NAME("MT37"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Inflicts damage\n"
            "identical to the\n"
            "user's level."),
        .descricao = COMPOUND_STRING(
            "Inflige dano\n"
            "idêntico ao nível\n"
            "do usu."),
        .descricion = COMPOUND_STRING(
            "Inflige daño\n"
            "idéntico al nivel\n"
            "del usu."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_DRAGON_TAIL] =
    {
        .name = ITEM_NAME("TM38"),
        .nombre = ITEM_NAME("MT38"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Knocks the target\n"
            "away and ends the\n"
            "battle."),
        .descricao = COMPOUND_STRING(
            "Afasta o alvo e\n"
            "encerra a luta."),
        .descricion = COMPOUND_STRING(
            "Aleja al objetivo y\n"
            "termina el combate."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_VENOSHOCK] =
    {
        .name = ITEM_NAME("TM39"),
        .nombre = ITEM_NAME("MT39"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Does double damage\n"
            "if the foe is\n"
            "poisoned."),
        .descricao = COMPOUND_STRING(
            "Causa o dobro do\n"
            "dano se o inimigo\n"
            "estiver envenenado."),
        .descricion = COMPOUND_STRING(
            "Hace el doble de\n"
            "daño si el enemigo\n"
            "está envenenado."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_AVALANCHE] =
    {
        .name = ITEM_NAME("TM40"),
        .nombre = ITEM_NAME("MT40"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "An attack that\n"
            "doubles in power if\n"
            "the user was hit."),
        .descricao = COMPOUND_STRING(
            "Dobra o poder se o\n"
            "usu. foi atingido."),
        .descricion = COMPOUND_STRING(
            "Dobla su poder si\n"
            "el usu. fue\n"
            "golpeado."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_ENDURE] =
    {
        .name = ITEM_NAME("TM41"),
        .nombre = ITEM_NAME("MT41"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Endures any attack\n"
            "for 1 turn, leaving\n"
            "at least 1HP."),
        .descricao = COMPOUND_STRING(
            "Suporta Atq. por 1\n"
            "turno, deixando\n"
            "pelo menos 1HP."),
        .descricion = COMPOUND_STRING(
            "Resiste 1 turno y\n"
            "deja al menos 1 PS."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_VOLT_SWITCH] =
    {
        .name = ITEM_NAME("TM42"),
        .nombre = ITEM_NAME("MT42"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "After attacking,\n"
            "the user switches\n"
            "out."),
        .descricao = COMPOUND_STRING(
            "Após atacar, o usu.\n"
            "troca de lugar."),
        .descricion = COMPOUND_STRING(
            "Tras atacar, el\n"
            "usu. cambia de\n"
            "lugar."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_SUNNY_DAY] =
    {
        .name = ITEM_NAME("TM43"),
        .nombre = ITEM_NAME("MT43"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Boosts the power of\n"
            "Fire- type moves\n"
            "for 5 turns."),
        .descricao = COMPOUND_STRING(
            "Aumenta o poder de\n"
            "golpes tipo Fogo\n"
            "por 5 turnos."),
        .descricion = COMPOUND_STRING(
            "Aumenta poder\n"
            "movimientos tipo\n"
            "Fuego por 5 turnos."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_RAIN_DANCE] =
    {
        .name = ITEM_NAME("TM44"),
        .nombre = ITEM_NAME("MT44"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Boosts the power of\n"
            "Water- type moves\n"
            "for 5 turns."),
        .descricao = COMPOUND_STRING(
            "Aumenta o poder\n"
            "golpes tipo Água\n"
            "por 5 turnos."),
        .descricion = COMPOUND_STRING(
            "Aumenta poder\n"
            "movimientos tipo\n"
            "Agua por 5 turnos."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_SANDSTORM] =
    {
        .name = ITEM_NAME("TM45"),
        .nombre = ITEM_NAME("MT45"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Causes a sandstorm\n"
            "that rages for\n"
            "several turns."),
        .descricao = COMPOUND_STRING(
            "Causa tempestade\n"
            "areia que dura\n"
            "vários turnos."),
        .descricion = COMPOUND_STRING(
            "Provoca una\n"
            "tormenta arena que\n"
            "dura varios turnos."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_SNOWSCAPE] =
    {
        .name = ITEM_NAME("TM46"),
        .nombre = ITEM_NAME("MT46"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Summons a hailstorm\n"
            "that strikes every\n"
            "turn."),
        .descricao = COMPOUND_STRING(
            "Invoca tempestade\n"
            "de neve que dura\n"
            "por cinco turnos."),
        .descricion = COMPOUND_STRING(
            "Invoca una tormenta\n"
            "de nieve que dura\n"
            "cinco turnos."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_SMART_STRIKE] =
    {
        .name = ITEM_NAME("TM47"),
        .nombre = ITEM_NAME("MT47"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Hits with an\n"
            "accurate horn that\n"
            "never misses."),
        .descricao = COMPOUND_STRING(
            "Bate com uma buzina\n"
            "precisa que nunca\n"
            "erra."),
        .descricion = COMPOUND_STRING(
            "Golpea con una\n"
            "bocina precisa que\n"
            "nunca falla."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_PSYSHOCK] =
    {
        .name = ITEM_NAME("TM48"),
        .nombre = ITEM_NAME("MT48"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Attacks with a\n"
            "psychic wave that\n"
            "hits Def."),
        .descricao = COMPOUND_STRING(
            "Ataca com onda\n"
            "psíquica que atinge\n"
            "a Defesa."),
        .descricion = COMPOUND_STRING(
            "Ataca con onda\n"
            "psíquica que golpea\n"
            "Defensa."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_DIG] =
    {
        .name = ITEM_NAME("TM49"),
        .nombre = ITEM_NAME("MT49"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Digs underground\n"
            "the first turn and\n"
            "strikes next turn."),
        .descricao = COMPOUND_STRING(
            "Cava subsolo no 1º\n"
            "turno e ataca no\n"
            "próximo turno."),
        .descricion = COMPOUND_STRING(
            "Excava bajo tierra\n"
            "en primer turno y\n"
            "ataca en siguiente."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_BULLET_SEED] =
    {
        .name = ITEM_NAME("TM50"),
        .nombre = ITEM_NAME("MT50"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Shoots 2 to 5 seeds\n"
            "in a row to strike\n"
            "the foe."),
        .descricao = COMPOUND_STRING(
            "Dispara de 2 a 5\n"
            "sementes seguidas\n"
            "contra o alvo."),
        .descricion = COMPOUND_STRING(
            "Dispara 2 a 5\n"
            "seguidas para\n"
            "golpear al enemigo."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_BRICK_BREAK] =
    {
        .name = ITEM_NAME("TM51"),
        .nombre = ITEM_NAME("MT51"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Destroys barriers\n"
            "such as REFLECT and\n"
            "causes damage."),
        .descricao = COMPOUND_STRING(
            "Destrói barreiras\n"
            "como REFLECT e\n"
            "causa danos."),
        .descricion = COMPOUND_STRING(
            "Destruye barreras\n"
            "como REFLECT y\n"
            "causa daño."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_ZEN_HEADBUTT] =
    {
        .name = ITEM_NAME("TM52"),
        .nombre = ITEM_NAME("MT52"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Hits with a strong\n"
            "head- butt. May\n"
            "cause flinching."),
        .descricao = COMPOUND_STRING(
            "Golpeia com forte\n"
            "cabeçada. Pode\n"
            "causar hesitação."),
        .descricion = COMPOUND_STRING(
            "Golpea con un\n"
            "fuerte cabeza.\n"
            "Puede provocar."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_U_TURN] =
    {
        .name = ITEM_NAME("TM53"),
        .nombre = ITEM_NAME("MT53"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "After attacking,\n"
            "the user switches\n"
            "out."),
        .descricao = COMPOUND_STRING(
            "Após atacar, o usu.\n"
            "troca de lugar."),
        .descricion = COMPOUND_STRING(
            "Tras atacar, el\n"
            "usu. cambia de\n"
            "lugar."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_SHADOW_CLAW] =
    {
        .name = ITEM_NAME("TM54"),
        .nombre = ITEM_NAME("MT54"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Strikes with a\n"
            "shadow claw. High\n"
            "critical-hit ratio."),
        .descricao = COMPOUND_STRING(
            "Ataca com uma garra\n"
            "sombria. Alta taxa\n"
            "de acerto crítico."),
        .descricion = COMPOUND_STRING(
            "Golpea con una\n"
            "garra sombra. Alta\n"
            "propor. golpes."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_FOUL_PLAY] =
    {
        .name = ITEM_NAME("TM55"),
        .nombre = ITEM_NAME("MT55"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "The higher the\n"
            "foe's Atk. the more\n"
            "damage caused."),
        .descricao = COMPOUND_STRING(
            "Quanto maior o\n"
            "Ataque maior será o\n"
            "dano causado."),
        .descricion = COMPOUND_STRING(
            "Cuanto mayor sea\n"
            "Atq. enemigo, más\n"
            "daño causará."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_PSYCHIC_FANGS] =
    {
        .name = ITEM_NAME("TM56"),
        .nombre = ITEM_NAME("MT56"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Chomps with psychic\n"
            "fangs. Destroys any\n"
            "barriers."),
        .descricao = COMPOUND_STRING(
            "Morde com presas\n"
            "psíquicas. Destrói\n"
            "quaisquer."),
        .descricion = COMPOUND_STRING(
            "Muerde con\n"
            "colmillos psíqui.\n"
            "Destruye cualquier."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_BULK_UP] =
    {
        .name = ITEM_NAME("TM57"),
        .nombre = ITEM_NAME("MT57"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Bulks up the body\n"
            "to boost both Atk.\n"
            "and Def."),
        .descricao = COMPOUND_STRING(
            "Aumenta volume\n"
            "corporal para subir\n"
            "Atq. e Def."),
        .descricion = COMPOUND_STRING(
            "Aumenta volumen\n"
            "corporal para subir\n"
            "Atq. y Def."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_CALM_MIND] =
    {
        .name = ITEM_NAME("TM58"),
        .nombre = ITEM_NAME("MT58"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Raises Sp. Atk and\n"
            "Sp. Def by focusing\n"
            "the mind."),
        .descricao = COMPOUND_STRING(
            "Aumenta Atq. Esp. e\n"
            "Def. Esp. ao focar\n"
            "a mente."),
        .descricion = COMPOUND_STRING(
            "Aumenta Sp. Atk y\n"
            "Sp. Def. al\n"
            "concentrar la."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_BODY_SLAM] =
    {
        .name = ITEM_NAME("TM59"),
        .nombre = ITEM_NAME("MT59"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "A full-body slam\n"
            "that may cause\n"
            "paralysis."),
        .descricao = COMPOUND_STRING(
            "Um golpe de corpo\n"
            "inteiro que pode\n"
            "causar paralisia."),
        .descricion = COMPOUND_STRING(
            "Un golpe de cuerpo\n"
            "enteroque puede\n"
            "causar parálisis."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_FIRE_PUNCH] =
    {
        .name = ITEM_NAME("TM60"),
        .nombre = ITEM_NAME("MT60"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "A fiery punch that\n"
            "may burn the foe."),
        .descricao = COMPOUND_STRING(
            "Um soco flamejante\n"
            "que pode queimar o\n"
            "inimigo."),
        .descricion = COMPOUND_STRING(
            "Un puñetazo\n"
            "flameante que puede\n"
            "quemar al oponente."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_THUNDER_PUNCH] =
    {
        .name = ITEM_NAME("TM61"),
        .nombre = ITEM_NAME("MT61"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "An electrified\n"
            "punch that may\n"
            "paralyze the foe."),
        .descricao = COMPOUND_STRING(
            "Um soco\n"
            "eletrificado pode\n"
            "paralisar inimigo."),
        .descricion = COMPOUND_STRING(
            "Un puñetazo\n"
            "electrico que puede\n"
            "paral. al objetivo."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_ICE_PUNCH] =
    {
        .name = ITEM_NAME("TM62"),
        .nombre = ITEM_NAME("MT62"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "An icy punch that\n"
            "may leave the foe\n"
            "with frostbite."),
        .descricao = COMPOUND_STRING(
            "Um soco gelado que\n"
            "pode deixar alvo\n"
            "com frostbite."),
        .descricion = COMPOUND_STRING(
            "Un puñetazo helado\n"
            "que puede dejar con\n"
            "frostbite."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_SLEEP_TALK] =
    {
        .name = ITEM_NAME("TM63"),
        .nombre = ITEM_NAME("MT63"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Uses an available\n"
            "move randomly while\n"
            "asleep."),
        .descricao = COMPOUND_STRING(
            "Usa um golpe ao\n"
            "acaso enquanto\n"
            "dorme."),
        .descricion = COMPOUND_STRING(
            "Utiliza un movimi.\n"
            "dispon. al azar si\n"
            "duerme."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_SEED_BOMB] =
    {
        .name = ITEM_NAME("TM64"),
        .nombre = ITEM_NAME("MT64"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "A barrage of hard\n"
            "seeds is fired at\n"
            "the foe."),
        .descricao = COMPOUND_STRING(
            "Dispara sementes\n"
            "duras contra o\n"
            "inimigo."),
        .descricion = COMPOUND_STRING(
            "Dispara una ráfaga\n"
            "de semillas duras\n"
            "contra rival."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_ELECTRO_BALL] =
    {
        .name = ITEM_NAME("TM65"),
        .nombre = ITEM_NAME("MT65"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Hurls an orb that\n"
            "does more damage to\n"
            "slower foes."),
        .descricao = COMPOUND_STRING(
            "Orbe que causa mais\n"
            "dano a alvos mais\n"
            "lentos."),
        .descricion = COMPOUND_STRING(
            "Lanza un orbe causa\n"
            "más daño enemigos\n"
            "más lentos."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_DRAIN_PUNCH] =
    {
        .name = ITEM_NAME("TM66"),
        .nombre = ITEM_NAME("MT66"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "An energy-draining\n"
            "punch that heals\n"
            "the user."),
        .descricao = COMPOUND_STRING(
            "Soco que drena\n"
            "energia e cura o\n"
            "usu."),
        .descricion = COMPOUND_STRING(
            "Puño que drena\n"
            "energía y cura al\n"
            "usu."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_REFLECT] =
    {
        .name = ITEM_NAME("TM67"),
        .nombre = ITEM_NAME("MT67"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Wall of light cuts\n"
            "physical damage for\n"
            "5 turns."),
        .descricao = COMPOUND_STRING(
            "Parede de luz corta\n"
            "dano físico por 5\n"
            "turnos."),
        .descricion = COMPOUND_STRING(
            "El muro luz reduce\n"
            "daño físico por 5\n"
            "turnos."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_LIGHT_SCREEN] =
    {
        .name = ITEM_NAME("TM68"),
        .nombre = ITEM_NAME("MT68"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Wall of light cuts\n"
            "special damage for\n"
            "5 turns."),
        .descricao = COMPOUND_STRING(
            "Parede de luz corta\n"
            "dano esp. por 5\n"
            "turnos."),
        .descricion = COMPOUND_STRING(
            "El muro de luz\n"
            "corta el daño esp.\n"
            "durante 5 turnos."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_DRAGON_CLAW] =
    {
        .name = ITEM_NAME("TM69"),
        .nombre = ITEM_NAME("MT69"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Slashes the foe\n"
            "with sharp claws."),
        .descricao = COMPOUND_STRING(
            "Corta o inimigo com\n"
            "garras afiadas."),
        .descricion = COMPOUND_STRING(
            "Corta al enemigo\n"
            "con garras\n"
            "afiladas."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_DAZZLING_GLEAM] =
    {
        .name = ITEM_NAME("TM70"),
        .nombre = ITEM_NAME("MT70"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Damages foes by\n"
            "emitting a bright\n"
            "flash."),
        .descricao = COMPOUND_STRING(
            "Danifica os\n"
            "inimigos emitindo\n"
            "um flash brilhante."),
        .descricion = COMPOUND_STRING(
            "Daña a enemigos\n"
            "emitiendo un\n"
            "destello brillante."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_METRONOME] =
    {
        .name = ITEM_NAME("TM71"),
        .nombre = ITEM_NAME("MT71"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Waggles a finger to\n"
            "use any Pokémon\n"
            "move at random."),
        .descricao = COMPOUND_STRING(
            "Balança dedo para\n"
            "usar golpe Pokémon\n"
            "aleatório."),
        .descricion = COMPOUND_STRING(
            "Mueve un dedo para\n"
            "usar movimiento\n"
            "Pokémon al azar."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_GRASS_KNOT] =
    {
        .name = ITEM_NAME("TM72"),
        .nombre = ITEM_NAME("MT72"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "A snare attack that\n"
            "does more damage to\n"
            "heavier foes."),
        .descricao = COMPOUND_STRING(
            "Armadilha que causa\n"
            "mais dano a alvos\n"
            "pesados."),
        .descricion = COMPOUND_STRING(
            "Trampa que causa\n"
            "más daño a rivales\n"
            "pesados."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_THUNDER_WAVE] =
    {
        .name = ITEM_NAME("TM73"),
        .nombre = ITEM_NAME("MT73"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "A weak jolt of\n"
            "electricity that\n"
            "paralyzes the foe."),
        .descricao = COMPOUND_STRING(
            "Um choque fraco\n"
            "eletricidade que\n"
            "paralisa o inimigo."),
        .descricion = COMPOUND_STRING(
            "Una débil descarga\n"
            "eléctrica paraliza\n"
            "al enemigo."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_POISON_JAB] =
    {
        .name = ITEM_NAME("TM74"),
        .nombre = ITEM_NAME("MT74"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "A stabbing attack\n"
            "that may poison the\n"
            "foe."),
        .descricao = COMPOUND_STRING(
            "Ataque perfurante\n"
            "que pode envenenar\n"
            "o inimigo."),
        .descricion = COMPOUND_STRING(
            "Un Atq. punzante\n"
            "que puede envenenar\n"
            "al enemigo."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_STOMPING_TANTRUM] =
    {
        .name = ITEM_NAME("TM75"),
        .nombre = ITEM_NAME("MT75"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Stomps around\n"
            "angrily. Stronger\n"
            "after a failure."),
        .descricao = COMPOUND_STRING(
            "Pisoteia com raiva.\n"
            "Fica mais forte\n"
            "após falhar."),
        .descricion = COMPOUND_STRING(
            "Pisotea con rabia.\n"
            "Se vuelve más\n"
            "fuerte tras fallar."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_REST] =
    {
        .name = ITEM_NAME("TM76"),
        .nombre = ITEM_NAME("MT76"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "The user sleeps for\n"
            "2 turns, restoring\n"
            "HP and status."),
        .descricao = COMPOUND_STRING(
            "O usu. dorme por 2\n"
            "turnos, restau. HP\n"
            "e estado."),
        .descricion = COMPOUND_STRING(
            "El usu. duerme por\n"
            "2 turnos, restau.\n"
            "PS y estado."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_ROCK_SLIDE] =
    {
        .name = ITEM_NAME("TM77"),
        .nombre = ITEM_NAME("MT77"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Large boulders are\n"
            "hurled. May cause\n"
            "flinching."),
        .descricao = COMPOUND_STRING(
            "Grandes pedras são\n"
            "jogadas, Pode\n"
            "causar hesitação."),
        .descricion = COMPOUND_STRING(
            "Se arrojan grandes\n"
            "rocas. Puede\n"
            "provocar estreme."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_TAUNT] =
    {
        .name = ITEM_NAME("TM78"),
        .nombre = ITEM_NAME("MT78"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Taunts the foe into\n"
            "only using attack\n"
            "moves."),
        .descricao = COMPOUND_STRING(
            "Força o inimigo a\n"
            "usar só golpes de\n"
            "Atq."),
        .descricion = COMPOUND_STRING(
            "Se burla rival para\n"
            "que solo use\n"
            "movimientos Atq."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_SWORDS_DANCE] =
    {
        .name = ITEM_NAME("TM79"),
        .nombre = ITEM_NAME("MT79"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "A fighting dance\n"
            "that greatly boosts\n"
            "Atk."),
        .descricao = COMPOUND_STRING(
            "Uma dança de luta\n"
            "que sobe muito o\n"
            "Ataque."),
        .descricion = COMPOUND_STRING(
            "Una danza de lucha\n"
            "que sobe mucho el\n"
            "Ataque."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_BODY_PRESS] =
    {
        .name = ITEM_NAME("TM80"),
        .nombre = ITEM_NAME("MT80"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Does more damage\n"
            "the higher the\n"
            "user's Def."),
        .descricao = COMPOUND_STRING(
            "Causa mais dano\n"
            "quanto maior for a\n"
            "Def do usu."),
        .descricion = COMPOUND_STRING(
            "Hace más daño\n"
            "cuanto mayor sea la\n"
            "Def del usu."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_SPIKES] =
    {
        .name = ITEM_NAME("TM81"),
        .nombre = ITEM_NAME("MT81"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Sets spikes that\n"
            "hurt a foe\n"
            "switching in."),
        .descricao = COMPOUND_STRING(
            "Seta espinhos que\n"
            "machucam o inimigo\n"
            "que entra."),
        .descricion = COMPOUND_STRING(
            "Coloca púas que\n"
            "hieren a un rival\n"
            "que entra."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_TOXIC_SPIKES] =
    {
        .name = ITEM_NAME("TM82"),
        .nombre = ITEM_NAME("MT82"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Sets spikes that\n"
            "poison a foe\n"
            "switching in."),
        .descricao = COMPOUND_STRING(
            "Coloca espinhos que\n"
            "envenenam o inimigo\n"
            "que entra."),
        .descricion = COMPOUND_STRING(
            "Coloca púas que\n"
            "envenenan el\n"
            "enemigo que entra."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_FLASH_CANNON] =
    {
        .name = ITEM_NAME("TM83"),
        .nombre = ITEM_NAME("MT83"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Releases a blast of\n"
            "light that may\n"
            "lower Sp. Def."),
        .descricao = COMPOUND_STRING(
            "Libera explosão luz\n"
            "que pode diminuir\n"
            "Def. Esp."),
        .descricion = COMPOUND_STRING(
            "Libera una ráfaga\n"
            "de luz que puede\n"
            "reducir Sp. Def."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_DARK_PULSE] =
    {
        .name = ITEM_NAME("TM84"),
        .nombre = ITEM_NAME("MT84"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Attacks with a\n"
            "horrible aura. May\n"
            "cause flinching."),
        .descricao = COMPOUND_STRING(
            "Ataca com uma aura\n"
            "horrível. Pode\n"
            "causar hesitação."),
        .descricion = COMPOUND_STRING(
            "Ataca con un aura\n"
            "horrible. Puede\n"
            "provocar estrem."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_LEECH_LIFE] =
    {
        .name = ITEM_NAME("TM85"),
        .nombre = ITEM_NAME("MT85"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "An attack that\n"
            "steals half the\n"
            "damage inflicted."),
        .descricao = COMPOUND_STRING(
            "Um Atq. que rouba\n"
            "metade do dano\n"
            "infligido."),
        .descricion = COMPOUND_STRING(
            "Un Atq. que roba la\n"
            "mitad del daño\n"
            "infligido."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_EERIE_IMPULSE] =
    {
        .name = ITEM_NAME("TM86"),
        .nombre = ITEM_NAME("MT86"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Exposes foe to\n"
            "pulse greatly cuts\n"
            "Sp. Atk."),
        .descricao = COMPOUND_STRING(
            "Expõe inimigo a\n"
            "pulso que corta\n"
            "muito Atq. Esp."),
        .descricion = COMPOUND_STRING(
            "Expone al enemigo a\n"
            "un pulso que corta\n"
            "brusca. a Sp. Atk."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_IRON_HEAD] =
    {
        .name = ITEM_NAME("TM87"),
        .nombre = ITEM_NAME("MT87"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Slams the foe with\n"
            "a hard head. May\n"
            "cause flinching."),
        .descricao = COMPOUND_STRING(
            "Golpeia inimigo com\n"
            "a cabeça dura. Pode\n"
            "causar hesitação."),
        .descricion = COMPOUND_STRING(
            "Cabeza dura que\n"
            "puede provocar\n"
            "estremecimiento."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_DRAGON_DANCE] =
    {
        .name = ITEM_NAME("TM88"),
        .nombre = ITEM_NAME("MT88"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "A mystical dance\n"
            "that ups Atk. and\n"
            "Speed."),
        .descricao = COMPOUND_STRING(
            "Uma dança mística\n"
            "que sobe o Ataque e\n"
            "a Velocidade."),
        .descricion = COMPOUND_STRING(
            "Una danza mística\n"
            "que sobe Ataque y\n"
            "Velocidad."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_POWER_GEM] =
    {
        .name = ITEM_NAME("TM89"),
        .nombre = ITEM_NAME("MT89"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Attacks rays of\n"
            "light sparkle like\n"
            "diamonds."),
        .descricao = COMPOUND_STRING(
            "Ataca com raios de\n"
            "luz que brilham\n"
            "como diamantes."),
        .descricion = COMPOUND_STRING(
            "Ataca con rayos de\n"
            "luz que brillan\n"
            "como diamantes."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_GUNK_SHOT] =
    {
        .name = ITEM_NAME("TM90"),
        .nombre = ITEM_NAME("MT90"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Shoots filthy\n"
            "garbage at the foe.\n"
            "May also poison."),
        .descricao = COMPOUND_STRING(
            "Atira lixo imundo\n"
            "no inimigo. Também\n"
            "pode envene."),
        .descricion = COMPOUND_STRING(
            "Dispara basura\n"
            "sucia al También\n"
            "puede envene."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_SUBSTITUTE] =
    {
        .name = ITEM_NAME("TM91"),
        .nombre = ITEM_NAME("MT91"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Creates a decoy\n"
            "using 1/4 of the\n"
            "user's maximum HP."),
        .descricao = COMPOUND_STRING(
            "Cria uma isca\n"
            "usando 1/4 do HP\n"
            "máximo do usu."),
        .descricion = COMPOUND_STRING(
            "Crea un señuelo\n"
            "usando 1/4 del HP\n"
            "máximo del usu."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_IRON_DEFENSE] =
    {
        .name = ITEM_NAME("TM92"),
        .nombre = ITEM_NAME("MT92"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Hardens the body's\n"
            "surface to greatly\n"
            "raise Def."),
        .descricao = COMPOUND_STRING(
            "Endurece superfície\n"
            "corpo para aumentar\n"
            "muito a Def."),
        .descricion = COMPOUND_STRING(
            "Endurece superficie\n"
            "cuerpo para\n"
            "aumentar mucho la."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_WILL_O_WISP] =
    {
        .name = ITEM_NAME("TM93"),
        .nombre = ITEM_NAME("MT93"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Inflicts a burn on\n"
            "the foe with\n"
            "intense fire."),
        .descricao = COMPOUND_STRING(
            "Fogo sinistro que\n"
            "queima o inimigo."),
        .descricion = COMPOUND_STRING(
            "Inflige una\n"
            "quemadura al\n"
            "enemigo con fuego."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_LIQUIDATION] =
    {
        .name = ITEM_NAME("TM94"),
        .nombre = ITEM_NAME("MT94"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Slams the foe with\n"
            "water. Can lower\n"
            "Def."),
        .descricao = COMPOUND_STRING(
            "Golpeia o inimigo\n"
            "com água. Pode\n"
            "diminuir a Defesa."),
        .descricion = COMPOUND_STRING(
            "Golpea al enemigo\n"
            "con agua. Puede\n"
            "reducir la Defensa."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_GIGA_DRAIN] =
    {
        .name = ITEM_NAME("TM95"),
        .nombre = ITEM_NAME("MT95"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "An attack that\n"
            "steals half the\n"
            "damage inflicted."),
        .descricao = COMPOUND_STRING(
            "Um Atq. que rouba\n"
            "metade do dano\n"
            "infligido."),
        .descricion = COMPOUND_STRING(
            "Un Atq. que roba la\n"
            "mitad del daño\n"
            "infligido."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_FIRE_BLAST] =
    {
        .name = ITEM_NAME("TM96"),
        .nombre = ITEM_NAME("MT96"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Incinerates the\n"
            "target. May cause a\n"
            "burn."),
        .descricao = COMPOUND_STRING(
            "Incinera tudo o que\n"
            "atinge. Pode causar\n"
            "queimaduras."),
        .descricion = COMPOUND_STRING(
            "Incinera todo lo\n"
            "que golpea. Puede\n"
            "causar quemaduras."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_FLAMETHROWER] =
    {
        .name = ITEM_NAME("TM97"),
        .nombre = ITEM_NAME("MT97"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "A powerful fire\n"
            "attack that may\n"
            "inflict a burn."),
        .descricao = COMPOUND_STRING(
            "Um Atq. de fogo\n"
            "potente, pode\n"
            "causar queimadura."),
        .descricion = COMPOUND_STRING(
            "Un Atq. de fuego\n"
            "potente, puede\n"
            "causar quemadura."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_SHADOW_BALL] =
    {
        .name = ITEM_NAME("TM98"),
        .nombre = ITEM_NAME("MT98"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Hurls a black blob\n"
            "that may lower the\n"
            "foe's Sp. Def."),
        .descricao = COMPOUND_STRING(
            "Lança massa negra\n"
            "que pode baixar a\n"
            "Def. Esp. do alvo."),
        .descricion = COMPOUND_STRING(
            "Lanza una masa\n"
            "negra que puede\n"
            "reducir Sp Def."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_ENERGY_BALL] =
    {
        .name = ITEM_NAME("TM99"),
        .nombre = ITEM_NAME("MT99"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Draws power from\n"
            "nature to attack.\n"
            "May lower Sp. Def."),
        .descricao = COMPOUND_STRING(
            "Extrai poder para\n"
            "atacar. Pode\n"
            "diminuir Def. Esp."),
        .descricion = COMPOUND_STRING(
            "Extrae poder para\n"
            "atacar. Puede\n"
            "reducir Def. Esp."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_PSYCHIC] =
    {
        .name = ITEM_NAME("TM100"),
        .nombre = ITEM_NAME("MT100"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "A powerful psychic\n"
            "attack that may\n"
            "lower Sp. Def."),
        .descricao = COMPOUND_STRING(
            "Um poderoso Atq.\n"
            "psíquico que pode\n"
            "diminuir Sp. Def."),
        .descricion = COMPOUND_STRING(
            "Un poderoso Atq.\n"
            "psíquico que puede\n"
            "reducir Sp. Def."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_ICE_SPINNER] =
    {
        .name = ITEM_NAME("TM101"),
        .nombre = ITEM_NAME("MT101"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Ice-covered feet\n"
            "hit foe and destroy\n"
            "terrain."),
        .descricao = COMPOUND_STRING(
            "Pés cobertos gelo\n"
            "atingem alvo e\n"
            "destroem terreno."),
        .descricion = COMPOUND_STRING(
            "Pies cubiertos\n"
            "hielo golpean rival\n"
            "y destruyen."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_THUNDERBOLT] =
    {
        .name = ITEM_NAME("TM102"),
        .nombre = ITEM_NAME("MT102"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "A strong electrical\n"
            "attack that may\n"
            "paralyze the foe."),
        .descricao = COMPOUND_STRING(
            "Um forte Atq.\n"
            "elétrico pode\n"
            "paralisar inimigo."),
        .descricion = COMPOUND_STRING(
            "Ataque eléctrico\n"
            "que puede causar\n"
            "parálisis."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_PLAY_ROUGH] =
    {
        .name = ITEM_NAME("TM103"),
        .nombre = ITEM_NAME("MT103"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Plays rough with\n"
            "the foe. May lower\n"
            "Atk."),
        .descricao = COMPOUND_STRING(
            "Joga duro com o\n"
            "inimigo. Pode\n"
            "diminuir o Ataque."),
        .descricion = COMPOUND_STRING(
            "Juega duro con el\n"
            "enemigo. Puede\n"
            "reducir el Ataque."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_EARTH_POWER] =
    {
        .name = ITEM_NAME("TM104"),
        .nombre = ITEM_NAME("MT104"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Makes the ground\n"
            "erupt with power.\n"
            "May lower Sp. Def."),
        .descricao = COMPOUND_STRING(
            "Erupção no chão.\n"
            "Pode baixar a Def.\n"
            "Esp."),
        .descricion = COMPOUND_STRING(
            "Erupción del suelo.\n"
            "Puede bajar la Def.\n"
            "Esp."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_ICE_BEAM] =
    {
        .name = ITEM_NAME("TM105"),
        .nombre = ITEM_NAME("MT105"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Blasts the foe with\n"
            "an icy beam. May\n"
            "cause frostbite."),
        .descricao = COMPOUND_STRING(
            "Lança raio de gelo\n"
            "no alvo. Pode\n"
            "causar frostbite."),
        .descricion = COMPOUND_STRING(
            "Lanza un rayo de\n"
            "hielo. Puede causar\n"
            "frostbite."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_NASTY_PLOT] =
    {
        .name = ITEM_NAME("TM106"),
        .nombre = ITEM_NAME("MT106"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Thinks bad thoughts\n"
            "to greatly boost\n"
            "Sp. Atk."),
        .descricao = COMPOUND_STRING(
            "Tem pensamentos\n"
            "ruins para aumentar\n"
            "muito o Atq. Esp."),
        .descricion = COMPOUND_STRING(
            "Malos planes que\n"
            "suben mucho el Sp.\n"
            "Atk."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_HYDRO_PUMP] =
    {
        .name = ITEM_NAME("TM107"),
        .nombre = ITEM_NAME("MT107"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Blasts water at\n"
            "high power to\n"
            "strike the foe."),
        .descricao = COMPOUND_STRING(
            "Jorra água com alto\n"
            "poder para atingir\n"
            "o inimigo."),
        .descricion = COMPOUND_STRING(
            "Lanza agua con gran\n"
            "fuerza para golpear\n"
            "al enemigo."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_BLIZZARD] =
    {
        .name = ITEM_NAME("TM108"),
        .nombre = ITEM_NAME("MT108"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Hits the foes with\n"
            "an icy storm. May\n"
            "cause frostbite."),
        .descricao = COMPOUND_STRING(
            "Tempestade de gelo\n"
            "que pode causar\n"
            "frostbite."),
        .descricion = COMPOUND_STRING(
            "Ataca con una\n"
            "tormenta de hielo.\n"
            "Puede frostbite."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_EARTHQUAKE] =
    {
        .name = ITEM_NAME("TM109"),
        .nombre = ITEM_NAME("MT109"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "A powerful quake\n"
            "that hits all other\n"
            "POKéMON."),
        .descricao = COMPOUND_STRING(
            "Um terremoto que\n"
            "atinge todos os\n"
            "outros POKéMON."),
        .descricion = COMPOUND_STRING(
            "Un terremoto que\n"
            "golpea a todos\n"
            "demás POKéMON."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_SLUDGE_BOMB] =
    {
        .name = ITEM_NAME("TM110"),
        .nombre = ITEM_NAME("MT110"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Sludge is hurled to\n"
            "inflict damage. May\n"
            "also poison."),
        .descricao = COMPOUND_STRING(
            "Lama é jogada para\n"
            "causar danos.\n"
            "Também pode envene."),
        .descricion = COMPOUND_STRING(
            "Arroja lodo. Puede\n"
            "envenenar al\n"
            "enemigo."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_STONE_EDGE] =
    {
        .name = ITEM_NAME("TM111"),
        .nombre = ITEM_NAME("MT111"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Stabs the foe with\n"
            "stones. High\n"
            "critical-hit ratio."),
        .descricao = COMPOUND_STRING(
            "Apunhala inimigo\n"
            "com pedras. Alta\n"
            "taxa acerto."),
        .descricion = COMPOUND_STRING(
            "Piedras afiladas.\n"
            "Suele dar golpes\n"
            "críticos."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_OVERHEAT] =
    {
        .name = ITEM_NAME("TM112"),
        .nombre = ITEM_NAME("MT112"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Allows a full-power\n"
            "attack, but greatly\n"
            "cuts Sp. Atk."),
        .descricao = COMPOUND_STRING(
            "Permite Atq. com\n"
            "força total, reduz\n"
            "muito Sp. Atq."),
        .descricion = COMPOUND_STRING(
            "Permite un Atq. a\n"
            "máxima pot., reduce\n"
            "mucho Sp. Atq."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_FOCUS_BLAST] =
    {
        .name = ITEM_NAME("TM113"),
        .nombre = ITEM_NAME("MT113"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Attacks at full\n"
            "power. May lower\n"
            "Sp. Def."),
        .descricao = COMPOUND_STRING(
            "Ataca com força\n"
            "total. Pode\n"
            "diminuir Def. Esp."),
        .descricion = COMPOUND_STRING(
            "Ataca a máxima\n"
            "potencia. Puede\n"
            "reducir Def. Esp."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_LEAF_STORM] =
    {
        .name = ITEM_NAME("TM114"),
        .nombre = ITEM_NAME("MT114"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Whips up a storm of\n"
            "leaves. Harshly\n"
            "cuts the Sp. Atk."),
        .descricao = COMPOUND_STRING(
            "Levanta tempestade\n"
            "folhas. Reduz muito\n"
            "o Atq. Esp."),
        .descricion = COMPOUND_STRING(
            "Provoca una\n"
            "tormenta hojas.\n"
            "Baja bruscamente."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_HURRICANE] =
    {
        .name = ITEM_NAME("TM115"),
        .nombre = ITEM_NAME("MT115"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Traps the foe in a\n"
            "fierce wind. May\n"
            "cause confusion."),
        .descricao = COMPOUND_STRING(
            "Prende inimigo com\n"
            "vento forte. Pode\n"
            "causar confusão."),
        .descricion = COMPOUND_STRING(
            "Atrapa al con un\n"
            "viento feroz. Puede\n"
            "causar confus."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_FLARE_BLITZ] =
    {
        .name = ITEM_NAME("TM116"),
        .nombre = ITEM_NAME("MT116"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "A charge that may\n"
            "burn the foe. Also\n"
            "hurts the user."),
        .descricao = COMPOUND_STRING(
            "Uma carga que pode\n"
            "queimar o alvo, mas\n"
            "machuca o usu."),
        .descricion = COMPOUND_STRING(
            "Una carga que puede\n"
            "quemar enemigo,\n"
            "pero hiere al user."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_THUNDER] =
    {
        .name = ITEM_NAME("TM117"),
        .nombre = ITEM_NAME("MT117"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "A lightning attack\n"
            "that may cause\n"
            "paralysis."),
        .descricao = COMPOUND_STRING(
            "Um Atq. relâmpago\n"
            "que pode causar\n"
            "paralisia."),
        .descricion = COMPOUND_STRING(
            "Un Atq. relámpago\n"
            "que puede causar\n"
            "parálisis."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_CLOSE_COMBAT] =
    {
        .name = ITEM_NAME("TM118"),
        .nombre = ITEM_NAME("MT118"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "A close attack that\n"
            "cuts Def. and Sp.\n"
            "Def."),
        .descricao = COMPOUND_STRING(
            "Ataque próximo que\n"
            "baixa Def. e Sp.\n"
            "Def."),
        .descricion = COMPOUND_STRING(
            "Ataque cercano que\n"
            "baja Def. y Def.\n"
            "Esp."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_DRACO_METEOR] =
    {
        .name = ITEM_NAME("TM119"),
        .nombre = ITEM_NAME("MT119"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Casts comets onto\n"
            "the foe. Harshly\n"
            "cuts the Sp. Atk."),
        .descricao = COMPOUND_STRING(
            "Lança cometas no\n"
            "inimigo. Reduz\n"
            "muito o Atq. Esp."),
        .descricion = COMPOUND_STRING(
            "Arroja cometas\n"
            "sobre Baja brusca.\n"
            "Sp. Atk."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_TERA_BLAST] =
    {
        .name = ITEM_NAME("TM120"),
        .nombre = ITEM_NAME("MT120"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "If Terastallized,\n"
            "uses the user's\n"
            "Tera type."),
        .descricao = COMPOUND_STRING(
            "Se estiver Terast.\n"
            "ele acerta com seu\n"
            "tipo Tera."),
        .descricion = COMPOUND_STRING(
            "Si usu. está\n"
            "Terast. acierta con\n"
            "su tipo Tera."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_HM_CUT] =
    {
        .name = ITEM_NAME("HM01"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Attacks the foe\n"
            "with sharp blades\n"
            "or claws."),
        .importance = 1,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_HM_FLY] =
    {
        .name = ITEM_NAME("HM02"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Flies up on the\n"
            "first turn, then\n"
            "attacks next turn."),
        .importance = 1,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_HM_SURF] =
    {
        .name = ITEM_NAME("HM03"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Creates a huge\n"
            "wave, then crashes\n"
            "it down on the foe."),
        .importance = 1,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_HM_STRENGTH] =
    {
        .name = ITEM_NAME("HM04"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Builds enormous\n"
            "power, then slams\n"
            "the foe."),
        .importance = 1,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_HM_FLASH] =
    {
        .name = ITEM_NAME("HM05"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Looses a powerful\n"
            "blast of light that\n"
            "cuts acc."),
        .importance = 1,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_HM_ROCK_SMASH] =
    {
        .name = ITEM_NAME("HM06"),
        .price = 0,
        .description = COMPOUND_STRING(
            "A rock-crushingly\n"
            "tough attack that\n"
            "may lower Def."),
        .importance = 1,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_HM_WATERFALL] =
    {
        .name = ITEM_NAME("HM07"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Attacks foe enough\n"
            "power to climb\n"
            "waterfalls."),
        .importance = 1,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_HM_DIVE] =
    {
        .name = ITEM_NAME("HM08"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Dives underwater\n"
            "the 1st turn, then\n"
            "attacks next turn."),
        .importance = 1,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },


// Charms

    [ITEM_OVAL_CHARM] =
    {
        .name = ITEM_NAME("Oval Charm"),
        .nombre = ITEM_NAME("Encanto Ovalado"),
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING(
            "Raises the chance\n"
            "of finding eggs at\n"
            "the daycare."),
        .descricao = COMPOUND_STRING(
            "Aumenta a chance de\n"
            "encontrar ovos na\n"
            "creche."),
        .descricion = COMPOUND_STRING(
            "Aumenta la\n"
            "posibilidad\n"
            "encontrar huevos."),
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_OvalCharm,
        .iconPalette = gItemIconPalette_OvalCharm,
    },

    [ITEM_SHINY_CHARM] =
    {
        .name = ITEM_NAME("Shiny Charm"),
        .nombre = ITEM_NAME("Encanto brillante"),
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING(
            "A charm that will\n"
            "raise the chance of\n"
            "Shiny Pokémon."),
        .descricao = COMPOUND_STRING(
            "Um amuleto que\n"
            "aumentará a chance\n"
            "de Pokémon Shiny."),
        .descricion = COMPOUND_STRING(
            "Un amuleto que\n"
            "aumentará las\n"
            "posibilidades de."),
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_ShinyCharm,
        .iconPalette = gItemIconPalette_ShinyCharm,
    },

    [ITEM_CATCHING_CHARM] =
    {
        .name = ITEM_NAME("Catching Charm"),
        .nombre = ITEM_NAME("Encanto atrapante"),
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING(
            "A charm that boosts\n"
            "the chance of\n"
            "Critical Captures."),
        .descricao = COMPOUND_STRING(
            "Um amuleto que sobe\n"
            "a chance de\n"
            "Capturas Críticas."),
        .descricion = COMPOUND_STRING(
            "Un amuleto que sobe\n"
            "la posibilidad de."),
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_CatchingCharm,
        .iconPalette = gItemIconPalette_CatchingCharm,
    },

    [ITEM_EXP_CHARM] =
    {
        .name = ITEM_NAME("Exp. Charm"),
        .nombre = ITEM_NAME("Exp. encanto"),
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING(
            "A charm that boosts\n"
            "the amount of Exp.\n"
            "earned in battle."),
        .descricao = COMPOUND_STRING(
            "Um amuleto que sobe\n"
            "a quantidade de\n"
            "Exp. conquistado."),
        .descricion = COMPOUND_STRING(
            "Un amuleto que sobe\n"
            "la cantidad de Exp.\n"
            "ganado en."),
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_ExpCharm,
        .iconPalette = gItemIconPalette_ExpCharm,
    },

// Form-changing Key Items

    [ITEM_ROTOM_CATALOG] =
    {
        .name = ITEM_NAME("Rotom Catalog"),
        .nombre = ITEM_NAME("Catalogo Rotom"),
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING(
            "A catalog full of\n"
            "devices liked by\n"
            "Rotom."),
        .descricao = COMPOUND_STRING(
            "Um catálogo repleto\n"
            "de dispositivos\n"
            "apreciados pela."),
        .descricion = COMPOUND_STRING(
            "Un catálogo repleto\n"
            "de dispositivos del\n"
            "agrado de Rotom."),
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_RotomCatalog,
        .iconPic = gItemIcon_RotomCatalog,
        .iconPalette = gItemIconPalette_RotomCatalog,
    },

    [ITEM_GRACIDEA] =
    {
        .name = ITEM_NAME("Gracidea"),
        .nombre = ITEM_NAME("Gracidea"),
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING(
            "Bouquets made with\n"
            "it are offered as a\n"
            "token of gratitude."),
        .descricao = COMPOUND_STRING(
            "Buquês feitos com\n"
            "ele são oferecidos\n"
            "como forma de."),
        .descricion = COMPOUND_STRING(
            "Los ramos\n"
            "elaborados con él\n"
            "ofrecen como."),
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_FormChange,
        .iconPic = gItemIcon_Gracidea,
        .iconPalette = gItemIconPalette_Gracidea,
    },

    [ITEM_REVEAL_GLASS] =
    {
        .name = ITEM_NAME("Reveal Glass"),
        .nombre = ITEM_NAME("Revelar vidrio"),
        .pluralName = ITEM_PLURAL_NAME("Reveal Glasses"),
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING(
            "This glass returns\n"
            "a Pokémon back to\n"
            "its original form."),
        .descricao = COMPOUND_STRING(
            "Este copo retorna\n"
            "um Pokémon à sua\n"
            "forma original."),
        .descricion = COMPOUND_STRING(
            "Este vaso devuelve\n"
            "un Pokémon a su\n"
            "forma original."),
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_FormChange,
        .iconPic = gItemIcon_RevealGlass,
        .iconPalette = gItemIconPalette_RevealGlass,
    },

    [ITEM_DNA_SPLICERS] =
    {
        .name = ITEM_NAME("DNA Splicers"),
        .nombre = ITEM_NAME("Empalmes de ADN"),
        .pluralName = ITEM_PLURAL_NAME("DNA Splicers"),
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING(
            "Splicer that fuses\n"
            "Kyurem and a\n"
            "certain Pokémon."),
        .descricao = COMPOUND_STRING(
            "Splicer que funde\n"
            "Kyurem e um certo\n"
            "Pokémon."),
        .descricion = COMPOUND_STRING(
            "Splicer que fusiona\n"
            "a Kyurem y cierto\n"
            "Pokémon."),
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Fusion,
        .iconPic = gItemIcon_DNASplicers,
        .iconPalette = gItemIconPalette_DNASplicers,
    },

    [ITEM_ZYGARDE_CUBE] =
    {
        .name = ITEM_NAME("Zygarde Cube"),
        .nombre = ITEM_NAME("Cubo Zygarde"),
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING(
            "An item to store\n"
            "Zygarde Cores and\n"
            "Cells."),
        .descricao = COMPOUND_STRING(
            "Um item para\n"
            "armazenar núcleos e\n"
            "células Zygarde."),
        .descricion = COMPOUND_STRING(
            "Un artículo para\n"
            "almacenar núcleos y\n"
            "células de Zygarde."),
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_ZygardeCube,
        .iconPic = gItemIcon_ZygardeCube,
        .iconPalette = gItemIconPalette_ZygardeCube,
    },

    [ITEM_PRISON_BOTTLE] =
    {
        .name = ITEM_NAME("Prison Bottle"),
        .nombre = ITEM_NAME("Botella de prision"),
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING(
            "A bottle used to\n"
            "seal a certain\n"
            "Pokémon long ago."),
        .descricao = COMPOUND_STRING(
            "Uma garrafa usada\n"
            "para selar um certo\n"
            "Pokémon há muito."),
        .descricion = COMPOUND_STRING(
            "Una botella\n"
            "utilizada para\n"
            "sellar a cierto."),
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_FormChange,
        .iconPic = gItemIcon_PrisonBottle,
        .iconPalette = gItemIconPalette_PrisonBottle,
    },

    [ITEM_N_SOLARIZER] =
    {
        .name = ITEM_NAME("N-Solarizer"),
        .nombre = ITEM_NAME("N-Solarizador"),
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING(
            "A device to fuse\n"
            "and split Necrozma\n"
            "using a Solgaleo."),
        .descricao = COMPOUND_STRING(
            "Um dispositivo para\n"
            "fundir e dividir\n"
            "Necrozma usando um."),
        .descricion = COMPOUND_STRING(
            "Un dispositivo para\n"
            "fusionar y dividir\n"
            "Necrozma usando un."),
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Fusion,
        .iconPic = gItemIcon_NecrozmaFuser,
        .iconPalette = gItemIconPalette_NSolarizer,
    },

    [ITEM_N_LUNARIZER] =
    {
        .name = ITEM_NAME("N-Lunarizer"),
        .nombre = ITEM_NAME("N-lunarizador"),
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING(
            "A device to fuse\n"
            "and split Necrozma\n"
            "using a Lunala."),
        .descricao = COMPOUND_STRING(
            "Um dispositivo para\n"
            "fundir e dividir\n"
            "Necrozma usando um."),
        .descricion = COMPOUND_STRING(
            "Un dispositivo para\n"
            "fusionar y dividir\n"
            "Necrozma usando."),
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Fusion,
        .iconPic = gItemIcon_NecrozmaFuser,
        .iconPalette = gItemIconPalette_NLunarizer,
    },

    [ITEM_REINS_OF_UNITY] =
    {
        .name = ITEM_NAME("Reins of Unity"),
        .nombre = ITEM_NAME("Riend. de la unid."),
        .pluralName = ITEM_PLURAL_NAME("Reins of Unity"),
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING(
            "Reins that unite\n"
            "Calyrex with its\n"
            "beloved steed."),
        .descricao = COMPOUND_STRING(
            "Rédeas que unem\n"
            "Calyrex ao seu\n"
            "querido corcel."),
        .descricion = COMPOUND_STRING(
            "Riendas que unen a\n"
            "Calyrex con su\n"
            "querido corcel."),
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Fusion,
        .iconPic = gItemIcon_ReinsOfUnity,
        .iconPalette = gItemIconPalette_ReinsOfUnity,
    },

// Battle Mechanic Key Items

    [ITEM_MEGA_RING] =
    {
        .name = ITEM_NAME("Mega Ring"),
        .nombre = ITEM_NAME("Mega Anillo"),
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING(
            "Enables {PKMN} holding\n"
            "their Mega Stone to\n"
            "Mega Evolve."),
        .descricao = COMPOUND_STRING(
            "Permite que Pokémon\n"
            "segure sua Mega\n"
            "Stone para Mega."),
        .descricion = COMPOUND_STRING(
            "Permite que Pokémon\n"
            "sostenga su Mega\n"
            "Piedra para Mega."),
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_MegaRing,
        .iconPalette = gItemIconPalette_MegaRing,
    },

    [ITEM_Z_POWER_RING] =
    {
        .name = ITEM_NAME("Z-Power Ring"),
        .nombre = ITEM_NAME("Anillo de poder Z"),
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING(
            "A strange ring that\n"
            "enables Z-Move\n"
            "usage."),
        .descricao = COMPOUND_STRING(
            "Um anel estranho\n"
            "que permite o uso\n"
            "do Z-Move."),
        .descricion = COMPOUND_STRING(
            "Un anillo extraño\n"
            "que permite el uso\n"
            "de Z-Move."),
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_ZPowerRing,
        .iconPalette = gItemIconPalette_ZPowerRing,
    },

    [ITEM_DYNAMAX_BAND] =
    {
        .name = ITEM_NAME("Dynamax Band"),
        .nombre = ITEM_NAME("Banda dinamax"),
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING(
            "A band carrying a\n"
            "Wishing Star that\n"
            "allows Dynamaxing."),
        .descricao = COMPOUND_STRING(
            "Uma banda\n"
            "carregando Wishing\n"
            "Star permite."),
        .descricion = COMPOUND_STRING(
            "Una banda lleva una\n"
            "Wishing Star\n"
            "permite Dynamaxing."),
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_DynamaxBand,
        .iconPalette = gItemIconPalette_DynamaxBand,
    },

// Misc. Key Items

    [ITEM_BICYCLE] =
    {
        .name = ITEM_NAME("Bike"),
        .nombre = ITEM_NAME("bici"),
        .price = 0,
        .description = COMPOUND_STRING(
            "A folding bicycle\n"
            "that is faster than\n"
            "the Running Shoes."),
        .descricao = COMPOUND_STRING(
            "Uma bicicleta\n"
            "dobrável é mais\n"
            "rápida tênis."),
        .descricion = COMPOUND_STRING(
            "Una bicicleta\n"
            "plegable más rápida\n"
            "que las zapatillas."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Bike,
        .secondaryId = STANDARD_BIKE,
        .iconPic = gItemIcon_Bicycle,
        .iconPalette = gItemIconPalette_Bicycle,
    },

    [ITEM_MACH_BIKE] =
    {
        .name = ITEM_NAME("Mach Bike"),
        .nombre = ITEM_NAME("Bicicleta Mach"),
        .price = 0,
        .description = COMPOUND_STRING(
            "A folding bicycle\n"
            "that doubles your\n"
            "speed or better."),
        .descricao = COMPOUND_STRING(
            "Uma bicicleta\n"
            "dobrável duplica\n"
            "sua Vel. ou."),
        .descricion = COMPOUND_STRING(
            "Una bicicleta\n"
            "plegable duplica tu\n"
            "Vel. mejor."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Bike,
        .secondaryId = MACH_BIKE,
        .iconPic = gItemIcon_MachBike,
        .iconPalette = gItemIconPalette_MachBike,
    },

    [ITEM_ACRO_BIKE] =
    {
        .name = ITEM_NAME("Acro Bike"),
        .nombre = ITEM_NAME("bici acro"),
        .price = 0,
        .description = COMPOUND_STRING(
            "A folding bicycle\n"
            "capable of jumps\n"
            "and wheelies."),
        .descricao = COMPOUND_STRING(
            "Uma bicicleta\n"
            "dobrável capaz\n"
            "saltos e."),
        .descricion = COMPOUND_STRING(
            "Una bicicleta\n"
            "plegable capaz de\n"
            "realizar saltos y."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Bike,
        .secondaryId = ACRO_BIKE,
        .iconPic = gItemIcon_AcroBike,
        .iconPalette = gItemIconPalette_AcroBike,
    },

    [ITEM_OLD_ROD] =
    {
        .name = ITEM_NAME("Old Rod"),
        .nombre = ITEM_NAME("Vara vieja"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Use by any body of\n"
            "water to fish for\n"
            "wild Pokémon."),
        .descricao = COMPOUND_STRING(
            "Use em qualquer\n"
            "corpo de água para\n"
            "pescar Pokémon."),
        .descricion = COMPOUND_STRING(
            "Úselo en cualquier\n"
            "cuerpo de agua para\n"
            "pescar Pokémon."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Rod,
        .secondaryId = OLD_ROD,
        .iconPic = gItemIcon_OldRod,
        .iconPalette = gItemIconPalette_OldRod,
    },

    [ITEM_GOOD_ROD] =
    {
        .name = ITEM_NAME("Good Rod"),
        .nombre = ITEM_NAME("buena vara"),
        .price = 0,
        .description = COMPOUND_STRING(
            "A decent fishing\n"
            "rod for catch wild\n"
            "Pokémon."),
        .descricao = COMPOUND_STRING(
            "Uma vara de pescar\n"
            "decente para pegar\n"
            "Pokémon."),
        .descricion = COMPOUND_STRING(
            "Una caña de pescar\n"
            "decente para pegar\n"
            "Pokémon."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Rod,
        .secondaryId = GOOD_ROD,
        .iconPic = gItemIcon_GoodRod,
        .iconPalette = gItemIconPalette_GoodRod,
    },

    [ITEM_SUPER_ROD] =
    {
        .name = ITEM_NAME("Super Rod"),
        .nombre = ITEM_NAME("Super cana"),
        .price = 0,
        .description = COMPOUND_STRING(
            "The best fishing\n"
            "rod for catch wild\n"
            "Pokémon."),
        .descricao = COMPOUND_STRING(
            "A melhor vara de\n"
            "pescar para pegar\n"
            "Pokémon selv."),
        .descricion = COMPOUND_STRING(
            "La mejor caña de\n"
            "pescar para pegar\n"
            "Pokémon salvajes."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Rod,
        .secondaryId = SUPER_ROD,
        .iconPic = gItemIcon_SuperRod,
        .iconPalette = gItemIconPalette_SuperRod,
    },

    [ITEM_DOWSING_MACHINE] =
    {
        .name = ITEM_NAME("Dowsing Machine"),
        .nombre = ITEM_NAME("Dowsing Machine"),
        .price = 0,
        .description = COMPOUND_STRING(
            "A device signals\n"
            "invisible item by\n"
            "sound."),
        .descricao = COMPOUND_STRING(
            "Um dispositivo que\n"
            "sinaliza um item\n"
            "invisível por som."),
        .descricion = COMPOUND_STRING(
            "Un dispositivo que\n"
            "señala un objeto\n"
            "invisible mediante."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Itemfinder,
        .iconPic = gItemIcon_DowsingMachine,
        .iconPalette = gItemIconPalette_DowsingMachine,
    },

    [ITEM_TOWN_MAP] =
    {
        .name = ITEM_NAME("Town Map"),
        .nombre = ITEM_NAME("Mapa de la ciudad"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Can be viewed\n"
            "anytime. Shows your\n"
            "present location."),
        .descricao = COMPOUND_STRING(
            "Pode ser\n"
            "visualizado\n"
            "qualquer momento."),
        .descricion = COMPOUND_STRING(
            "Se puede ver en\n"
            "cualquier momento.\n"
            "Muestra su."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TownMap,
        .iconPic = gItemIcon_TownMap,
        .iconPalette = gItemIconPalette_TownMap,
    },

    [ITEM_VS_SEEKER] =
    {
        .name = ITEM_NAME("Vs. Seeker"),
        .nombre = ITEM_NAME("vs. buscador"),
        .price = 0,
        .description = COMPOUND_STRING(
            "A rechargeable unit\n"
            "that flags battle-\n"
            "ready Trainers."),
        .descricao = COMPOUND_STRING(
            "Uma unidade\n"
            "recarregável\n"
            "sinaliza."),
        .descricion = COMPOUND_STRING(
            "Una unidad\n"
            "recargable que\n"
            "señala a los."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_FIELD,
    #if I_VS_SEEKER_CHARGING != 0
        .fieldUseFunc = FieldUseFunc_VsSeeker,
    #else
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    #endif
        .iconPic = gItemIcon_VsSeeker,
        .iconPalette = gItemIconPalette_VsSeeker,
    },

    [ITEM_TM_CASE] =
    {
        .name = ITEM_NAME("TM Case"),
        .price = 0,
        .description = COMPOUND_STRING(
            "A convenient case\n"
            "that holds TMs and\n"
            "HMs."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_TMCase,
        .iconPalette = gItemIconPalette_TMCase,
    },

    [ITEM_BERRY_POUCH] =
    {
        .name = ITEM_NAME("Berry Pouch"),
        .nombre = ITEM_NAME("Bolsa de bayas"),
        .pluralName = ITEM_PLURAL_NAME("Berry Pouches"),
        .price = 0,
        .description = COMPOUND_STRING(
            "A convenient\n"
            "container that\n"
            "holds Berries."),
        .descricao = COMPOUND_STRING(
            "Um recipiente\n"
            "conveniente que\n"
            "contém frutas."),
        .descricion = COMPOUND_STRING(
            "Un práctico\n"
            "recipiente que\n"
            "contiene bayas."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_BerryPouch,
        .iconPalette = gItemIconPalette_BerryPouch,
    },

    [ITEM_POKEMON_BOX_LINK] =
    {
        .name = ITEM_NAME("{PKMN} Box Link"),
        .nombre = ITEM_NAME("{PKMN} Box Link"),
        .price = 0,
        .description = COMPOUND_STRING(
            "This device grants\n"
            "access to the {PKMN}\n"
            "Storage System."),
        .descricao = COMPOUND_STRING(
            "Este dispositivo\n"
            "concede acesso ao\n"
            "sistema de."),
        .descricion = COMPOUND_STRING(
            "Este dispositivo\n"
            "otorga acceso al\n"
            "sistema de."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_PokemonBoxLink,
        .iconPic = gItemIcon_PokemonBoxLink,
        .iconPalette = gItemIconPalette_PokemonBoxLink,
    },

    [ITEM_COIN_CASE] =
    {
        .name = ITEM_NAME("Coin Case"),
        .nombre = ITEM_NAME("Caja de monedas"),
        .price = 0,
        .description = COMPOUND_STRING(
            "A case that holds\n"
            "up to 9,999 Coins."),
        .descricao = COMPOUND_STRING(
            "Uma caixa que\n"
            "comporta até 9.999\n"
            "moedas."),
        .descricion = COMPOUND_STRING(
            "Un estuche con\n"
            "capacidad para 9999\n"
            "monedas."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CoinCase,
        .iconPic = gItemIcon_CoinCase,
        .iconPalette = gItemIconPalette_CoinCase,
    },

    [ITEM_POWDER_JAR] =
    {
        .name = ITEM_NAME("Powder Jar"),
        .nombre = ITEM_NAME("Tarro de polvo"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Stores Berry Powder\n"
            "made using a Berry\n"
            "Crusher."),
        .descricao = COMPOUND_STRING(
            "Armazena Berry\n"
            "Powder feito usando\n"
            "um Berry Crusher."),
        .descricion = COMPOUND_STRING(
            "Almacena polvo de\n"
            "bayas elaborado con\n"
            "un triturador de."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PowderJar,
        .iconPic = gItemIcon_PowderJar,
        .iconPalette = gItemIconPalette_PowderJar,
    },

    [ITEM_WAILMER_PAIL] =
    {
        .name = ITEM_NAME("Wailmer Pail"),
        .nombre = ITEM_NAME("Cubo de Waimer"),
        .price = 0,
        .description = COMPOUND_STRING(
            "A tool used for\n"
            "watering Berries\n"
            "and plants."),
        .descricao = COMPOUND_STRING(
            "Uma ferramenta\n"
            "usada para regar\n"
            "frutas e plantas."),
        .descricion = COMPOUND_STRING(
            "Una herramienta\n"
            "utilizada para\n"
            "regar bayas y."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_WailmerPail,
        .iconPic = gItemIcon_WailmerPail,
        .iconPalette = gItemIconPalette_WailmerPail,
    },

    [ITEM_POKE_RADAR] =
    {
        .name = ITEM_NAME("Poké Radar"),
        .nombre = ITEM_NAME("Poke radar"),
        .price = 0,
        .description = COMPOUND_STRING(
            "A tool used to\n"
            "search out Pokémon\n"
            "hiding in grass."),
        .descricao = COMPOUND_STRING(
            "Uma ferramenta\n"
            "usada para procurar\n"
            "Pokémon escondidos."),
        .descricion = COMPOUND_STRING(
            "Una herramienta\n"
            "utilizada para\n"
            "buscar Pokémon."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse, // Todo
        .iconPic = gItemIcon_PokeRadar,
        .iconPalette = gItemIconPalette_PokeRadar,
    },

    [ITEM_POKEBLOCK_CASE] =
    {
        .name = ITEM_NAME("{POKEBLOCK} Case"),
        .nombre = ITEM_NAME("Caso {POKEBLOCK}"),
        .price = 0,
        .description = COMPOUND_STRING(
            "A case for holding\n"
            "{POKEBLOCK}s made with a Berry\n"
            "Blender."),
        .descricao = COMPOUND_STRING(
            "Um estojo para\n"
            "guardar {POKEBLOCK}s feito com\n"
            "um Berry."),
        .descricion = COMPOUND_STRING(
            "Un estuche para\n"
            "guardar {POKEBLOCK} hecho con\n"
            "una Berry."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_PBLOCK_CASE,
        .fieldUseFunc = ItemUseOutOfBattle_PokeblockCase,
        .iconPic = gItemIcon_PokeblockCase,
        .iconPalette = gItemIconPalette_PokeblockCase,
    },

    [ITEM_SOOT_SACK] =
    {
        .name = ITEM_NAME("Soot Sack"),
        .nombre = ITEM_NAME("Saco de hollin"),
        .price = 0,
        .description = COMPOUND_STRING(
            "A sack used to\n"
            "gather and hold\n"
            "volcanic ash."),
        .descricao = COMPOUND_STRING(
            "Um saco usado para\n"
            "coletar e armazenar\n"
            "cinzas vulcânicas."),
        .descricion = COMPOUND_STRING(
            "Saco utilizado para\n"
            "recoger y guardar\n"
            "cenizas volcánicas."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_SootSack,
        .iconPalette = gItemIconPalette_SootSack,
    },

    [ITEM_POKE_FLUTE] =
    {
        .name = ITEM_NAME("Poké Flute"),
        .nombre = ITEM_NAME("Flauta Poke"),
        .price = 0,
        .description = COMPOUND_STRING(
            "A sweet-sounding\n"
            "flute that awakens\n"
            "Pokémon."),
        .descricao = COMPOUND_STRING(
            "Uma flauta de som\n"
            "doce que desperta\n"
            "Pokémon."),
        .descricion = COMPOUND_STRING(
            "Una flauta dulce\n"
            "sonido despierta\n"
            "los Pokémon."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PokeFlute,
        .battleUsage = EFFECT_ITEM_USE_POKE_FLUTE,
        .iconPic = gItemIcon_PokeFlute,
        .iconPalette = gItemIconPalette_PokeFlute,
    },

    [ITEM_FAME_CHECKER] =
    {
        .name = ITEM_NAME("Fame Checker"),
        .nombre = ITEM_NAME("Comprobador de fama"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Stores information\n"
            "on famous people\n"
            "for instant recall."),
        .descricao = COMPOUND_STRING(
            "Armazena\n"
            "informações sobre\n"
            "pessoas famosas."),
        .descricion = COMPOUND_STRING(
            "Almacena\n"
            "información sobre\n"
            "personajes famosos."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_FameChecker,
        .iconPalette = gItemIconPalette_FameChecker,
    },

    [ITEM_TEACHY_TV] =
    {
        .name = ITEM_NAME("Teachy TV"),
        .nombre = ITEM_NAME("TV didactica"),
        .price = 0,
        .description = COMPOUND_STRING(
            "A TV set tuned to\n"
            "an advice program\n"
            "for Trainers."),
        .descricao = COMPOUND_STRING(
            "Uma televisão\n"
            "sintonizada com um\n"
            "programa de."),
        .descricion = COMPOUND_STRING(
            "Un televisor\n"
            "sintonizado con un\n"
            "programa consejos"),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_TeachyTV,
        .iconPalette = gItemIconPalette_TeachyTV,
    },

// Story Key Items

    [ITEM_SS_TICKET] =
    {
        .name = ITEM_NAME("S.S. Ticket"),
        .nombre = ITEM_NAME("Boleto SS"),
        .price = 0,
        .description = COMPOUND_STRING(
            "The ticket required\n"
            "for sailing on a\n"
            "ferry."),
        .descricao = COMPOUND_STRING(
            "O bilhete\n"
            "necessário para\n"
            "navegar em balsa."),
        .descricion = COMPOUND_STRING(
            "El billete\n"
            "necesario para\n"
            "navegar en un."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_SSTicket,
        .iconPalette = gItemIconPalette_SSTicket,
    },

    [ITEM_EON_TICKET] =
    {
        .name = ITEM_NAME("Eon Ticket"),
        .nombre = ITEM_NAME("Boleto de Eon"),
        .price = 0,
        .description = COMPOUND_STRING(
            "The ticket for a\n"
            "ferry to a distant\n"
            "southern island."),
        .descricao = COMPOUND_STRING(
            "A passagem de uma\n"
            "balsa para uma ilha\n"
            "distante ao sul."),
        .descricion = COMPOUND_STRING(
            "El billete de ferry\n"
            "a una lejana isla\n"
            "del sur."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 1,
        .iconPic = gItemIcon_EonTicket,
        .iconPalette = gItemIconPalette_EonTicket,
    },

    [ITEM_MYSTIC_TICKET] =
    {
        .name = ITEM_NAME("Mystic Ticket"),
        .nombre = ITEM_NAME("Boleto mistico"),
        .price = 0,
        .description = COMPOUND_STRING(
            "A ticket required\n"
            "to board the ship\n"
            "to Navel Rock."),
        .descricao = COMPOUND_STRING(
            "É necessário um\n"
            "bilhete para\n"
            "embarcar no navio."),
        .descricion = COMPOUND_STRING(
            "Se requiere un\n"
            "boleto para abordar\n"
            "el barco hacia."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_MysticTicket,
        .iconPalette = gItemIconPalette_MysticTicket,
    },

    [ITEM_AURORA_TICKET] =
    {
        .name = ITEM_NAME("Aurora Ticket"),
        .nombre = ITEM_NAME("Boleto Aurora"),
        .price = 0,
        .description = COMPOUND_STRING(
            "A ticket required\n"
            "to board the ship\n"
            "to Birth Island."),
        .descricao = COMPOUND_STRING(
            "É necessário um\n"
            "bilhete para\n"
            "embarcar no navio."),
        .descricion = COMPOUND_STRING(
            "Se requiere un\n"
            "boleto para abordar\n"
            "el barco hacia."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_AuroraTicket,
        .iconPalette = gItemIconPalette_AuroraTicket,
    },

    [ITEM_OLD_SEA_MAP] =
    {
        .name = ITEM_NAME("Old Sea Map"),
        .nombre = ITEM_NAME("Ant. mapa mar"),
        .price = 0,
        .description = COMPOUND_STRING(
            "A faded sea chart\n"
            "shows way to\n"
            "certain island."),
        .descricao = COMPOUND_STRING(
            "Um mapa marítimo\n"
            "desbotado mostra\n"
            "caminho para"),
        .descricion = COMPOUND_STRING(
            "Una carta marítima\n"
            "descolorida muestra\n"
            "el camino"),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_OldSeaMap,
        .iconPalette = gItemIconPalette_OldSeaMap,
    },

    [ITEM_LETTER] =
    {
        .name = ITEM_NAME("Letter"),
        .nombre = ITEM_NAME("carta"),
        .price = 0,
        .description = COMPOUND_STRING(
            "A letter to Steven\n"
            "from the President\n"
            "of the Devon Corp."),
        .descricao = COMPOUND_STRING(
            "Uma carta para\n"
            "Steven presidente\n"
            "Devon Corp."),
        .descricion = COMPOUND_STRING(
            "Una carta a Steven\n"
            "del presidente de\n"
            "Devon Corp."),
        .importance = 2,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_Letter,
        .iconPalette = gItemIconPalette_LavaCookieAndLetter,
    },

    [ITEM_DEVON_PARTS] =
    {
        .name = ITEM_NAME("Devon Parts"),
        .nombre = ITEM_NAME("Piezas de Devon"),
        .pluralName = ITEM_PLURAL_NAME("Devon Parts"),
        .price = 0,
        .description = COMPOUND_STRING(
            "A package that\n"
            "contains Devon's\n"
            "machine parts."),
        .descricao = COMPOUND_STRING(
            "Um pacote que\n"
            "contém peças da\n"
            "máquina Devon."),
        .descricion = COMPOUND_STRING(
            "Un paquete contiene\n"
            "piezas la máquina\n"
            "Devon."),
        .importance = 2,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_DevonParts,
        .iconPalette = gItemIconPalette_DevonParts,
    },

    [ITEM_GO_GOGGLES] =
    {
        .name = ITEM_NAME("Go-Goggles"),
        .nombre = ITEM_NAME("Goggles"),
        .pluralName = ITEM_PLURAL_NAME("Go-Goggles"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Nifty goggles that\n"
            "protect eyes from\n"
            "desert sandstorms."),
        .descricao = COMPOUND_STRING(
            "Óculos elegantes\n"
            "protegem olhos\n"
            "tempestades"),
        .descricion = COMPOUND_STRING(
            "Ingeniosas gafas\n"
            "protegen los ojos\n"
            "las tormentas"),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_GoGoggles,
        .iconPalette = gItemIconPalette_GoGoggles,
    },

    [ITEM_DEVON_SCOPE] =
    {
        .name = ITEM_NAME("Devon Scope"),
        .nombre = ITEM_NAME("Alcance de Devon"),
        .price = 0,
        .description = COMPOUND_STRING(
            "A device by Devon\n"
            "that signals any\n"
            "unseeable Pokémon."),
        .descricao = COMPOUND_STRING(
            "Um dispositivo da\n"
            "Devon que sinaliza\n"
            "qualquer Pokémon."),
        .descricion = COMPOUND_STRING(
            "Un dispositivo de\n"
            "Devon que señala a\n"
            "cualquier Pokémon."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_DevonScope,
        .iconPalette = gItemIconPalette_DevonScope,
    },

    [ITEM_BASEMENT_KEY] =
    {
        .name = ITEM_NAME("Basement Key"),
        .nombre = ITEM_NAME("Llave del sotano"),
        .price = 0,
        .description = COMPOUND_STRING(
            "The key for New\n"
            "Mauville beneath\n"
            "Mauville City."),
        .descricao = COMPOUND_STRING(
            "A chave para New\n"
            "Mauville abaixo da\n"
            "cidade de Mauville."),
        .descricion = COMPOUND_STRING(
            "La clave de New\n"
            "Mauville debajo de\n"
            "la ciudad de."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_BasementKey,
        .iconPalette = gItemIconPalette_OldKey,
    },

    [ITEM_SCANNER] =
    {
        .name = ITEM_NAME("Scanner"),
        .nombre = ITEM_NAME("Escaner"),
        .price = 0,
        .description = COMPOUND_STRING(
            "A device found\n"
            "inside the\n"
            "Abandoned Ship."),
        .descricao = COMPOUND_STRING(
            "Um dispositivo\n"
            "encontrado dentro\n"
            "navio abandonado."),
        .descricion = COMPOUND_STRING(
            "Un dispositivo\n"
            "encontrado dentro\n"
            "del Barco."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_Scanner,
        .iconPalette = gItemIconPalette_Scanner,
    },

    [ITEM_STORAGE_KEY] =
    {
        .name = ITEM_NAME("Storage Key"),
        .nombre = ITEM_NAME("Storage Key"),
        .price = 0,
        .description = COMPOUND_STRING(
            "The key to the\n"
            "storage inside the\n"
            "Abandoned Ship."),
        .descricao = COMPOUND_STRING(
            "A chave para\n"
            "armazenamento\n"
            "dentro Navio."),
        .descricion = COMPOUND_STRING(
            "La llave del\n"
            "almacenamiento\n"
            "dentro del Barco."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_StorageKey,
        .iconPalette = gItemIconPalette_OldKey,
    },

    [ITEM_KEY_TO_ROOM_1] =
    {
        .name = ITEM_NAME("Key to Room 1"),
        .nombre = ITEM_NAME("Key to Room 1"),
        .pluralName = ITEM_PLURAL_NAME("Keys to Room 1"),
        .price = 0,
        .description = sKeyToRoomDesc,
        .descricao = COMPOUND_STRING(
            "Uma chave que abre\n"
            "uma porta dentro do\n"
            "Navio Abandonado."),
        .descricion = COMPOUND_STRING(
            "Una llave que abre\n"
            "una puerta dentro\n"
            "del Barco."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_KeyToRoom1,
        .iconPalette = gItemIconPalette_Key,
    },

    [ITEM_KEY_TO_ROOM_2] =
    {
        .name = ITEM_NAME("Key to Room 2"),
        .nombre = ITEM_NAME("Key to Room 2"),
        .pluralName = ITEM_PLURAL_NAME("Keys to Room 2"),
        .price = 0,
        .description = sKeyToRoomDesc,
        .descricao = COMPOUND_STRING(
            "Uma chave que abre\n"
            "uma porta dentro do\n"
            "Navio Abandonado."),
        .descricion = COMPOUND_STRING(
            "Una llave que abre\n"
            "una puerta dentro\n"
            "del Barco."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_KeyToRoom2,
        .iconPalette = gItemIconPalette_Key,
    },

    [ITEM_KEY_TO_ROOM_4] =
    {
        .name = ITEM_NAME("Key to Room 4"),
        .nombre = ITEM_NAME("Key to Room 4"),
        .pluralName = ITEM_PLURAL_NAME("Keys to Room 4"),
        .price = 0,
        .description = sKeyToRoomDesc,
        .descricao = COMPOUND_STRING(
            "Uma chave que abre\n"
            "uma porta dentro do\n"
            "Navio Abandonado."),
        .descricion = COMPOUND_STRING(
            "Una llave que abre\n"
            "una puerta dentro\n"
            "del Barco."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_KeyToRoom4,
        .iconPalette = gItemIconPalette_Key,
    },

    [ITEM_KEY_TO_ROOM_6] =
    {
        .name = ITEM_NAME("Key to Room 6"),
        .nombre = ITEM_NAME("Key to Room 6"),
        .pluralName = ITEM_PLURAL_NAME("Keys to Room 6"),
        .price = 0,
        .description = sKeyToRoomDesc,
        .descricao = COMPOUND_STRING(
            "Uma chave que abre\n"
            "uma porta dentro do\n"
            "Navio Abandonado."),
        .descricion = COMPOUND_STRING(
            "Una llave que abre\n"
            "una puerta dentro\n"
            "del Barco."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_KeyToRoom6,
        .iconPalette = gItemIconPalette_Key,
    },

    [ITEM_METEORITE] =
    {
        .name = ITEM_NAME("Meteorite"),
        .nombre = ITEM_NAME("Meteorito"),
        .price = 0,
        .description = COMPOUND_STRING(
            "A meteorite found\n"
            "at Meteor Falls."),
        .descricao = COMPOUND_STRING(
            "Um meteorito\n"
            "encontrado em\n"
            "Meteor Falls."),
        .descricion = COMPOUND_STRING(
            "Un meteorito\n"
            "encontrado en\n"
            "Meteor Falls."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_FormChange,
        .iconPic = gItemIcon_Meteorite,
        .iconPalette = gItemIconPalette_Meteorite,
    },

    [ITEM_MAGMA_EMBLEM] =
    {
        .name = ITEM_NAME("Magma Emblem"),
        .nombre = ITEM_NAME("Emblema de magma"),
        .price = 0,
        .description = COMPOUND_STRING(
            "A medal-like item\n"
            "in same shape as\n"
            "Team Magma's mark."),
        .descricao = COMPOUND_STRING(
            "Um item semelhante\n"
            "medalha no mesmo\n"
            "formato marca"),
        .descricion = COMPOUND_STRING(
            "Un objeto parecido\n"
            "una medalla con la\n"
            "misma forma la."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_MagmaEmblem,
        .iconPalette = gItemIconPalette_MagmaEmblem,
    },

    [ITEM_CONTEST_PASS] =
    {
        .name = ITEM_NAME("Contest Pass"),
        .nombre = ITEM_NAME("Pase de concurso"),
        .pluralName = ITEM_PLURAL_NAME("Contest Passes"),
        .price = 0,
        .description = COMPOUND_STRING(
            "The pass required\n"
            "for entering\n"
            "Pokémon Contests."),
        .descricao = COMPOUND_STRING(
            "O passe necessário\n"
            "para participar de\n"
            "concursos Pokémon."),
        .descricion = COMPOUND_STRING(
            "El pase necesario\n"
            "para participar en\n"
            "los Concursos."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_ContestPass,
        .iconPalette = gItemIconPalette_ContestPass,
    },

    [ITEM_PARCEL] =
    {
        .name = ITEM_NAME("Parcel"),
        .nombre = ITEM_NAME("paquete"),
        .price = 0,
        .description = COMPOUND_STRING(
            "A parcel for Prof.\n"
            "Oak from a Pokémon\n"
            "Mart's clerk."),
        .descricao = COMPOUND_STRING(
            "Um pacote para o\n"
            "Prof. Oak do\n"
            "balconista de um."),
        .descricion = COMPOUND_STRING(
            "Un paquete para el\n"
            "profesor Oak de\n"
            "parte del empleado."),
        .importance = 2,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_Parcel,
        .iconPalette = gItemIconPalette_Parcel,
    },

    [ITEM_SECRET_KEY] =
    {
        .name = ITEM_NAME("Secret Key"),
        .nombre = ITEM_NAME("clave secreta"),
        .price = 0,
        .description = COMPOUND_STRING(
            "The key to the\n"
            "Cinnabar Island\n"
            "Gym's entrance."),
        .descricao = COMPOUND_STRING(
            "A chave para a\n"
            "entrada do Ginásio\n"
            "da Ilha Cinnabar."),
        .descricion = COMPOUND_STRING(
            "La llave la entrada\n"
            "del gimnasio\n"
            "Cinnabar Island."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_SecretKey,
        .iconPalette = gItemIconPalette_SecretKey,
    },

    [ITEM_BIKE_VOUCHER] =
    {
        .name = ITEM_NAME("Bike Voucher"),
        .nombre = ITEM_NAME("Bono de bici"),
        .price = 0,
        .description = COMPOUND_STRING(
            "A voucher for\n"
            "obtaining a bicycle\n"
            "from the Bike Shop."),
        .descricao = COMPOUND_STRING(
            "Um voucher para\n"
            "obtenção de uma\n"
            "bicicleta na Bike."),
        .descricion = COMPOUND_STRING(
            "Un bono para\n"
            "adquirir una\n"
            "bicicleta en Bike."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_BikeVoucher,
        .iconPalette = gItemIconPalette_BikeVoucher,
    },

    [ITEM_GOLD_TEETH] =
    {
        .name = ITEM_NAME("Gold Teeth"),
        .nombre = ITEM_NAME("Dientes de oro"),
        .pluralName = ITEM_PLURAL_NAME("Gold Teeth"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Gold dentures lost\n"
            "by the Safari\n"
            "Zone's Warden."),
        .descricao = COMPOUND_STRING(
            "Dentaduras de ouro\n"
            "perdidas pelo\n"
            "Diretor da Safari."),
        .descricion = COMPOUND_STRING(
            "Dentaduras postizas\n"
            "de oro perdidas por\n"
            "el guardián de la."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_GoldTeeth,
        .iconPalette = gItemIconPalette_GoldTeeth,
    },

    [ITEM_CARD_KEY] =
    {
        .name = ITEM_NAME("Card Key"),
        .nombre = ITEM_NAME("Clave de tarjeta"),
        .price = 0,
        .description = COMPOUND_STRING(
            "A card-type door\n"
            "key used in Silph\n"
            "Co's office."),
        .descricao = COMPOUND_STRING(
            "Uma chave porta\n"
            "tipo cartão usada\n"
            "no escritório."),
        .descricion = COMPOUND_STRING(
            "Una llave de puerta\n"
            "tipo tarjeta\n"
            "utilizada en la."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_CardKey,
        .iconPalette = gItemIconPalette_CardKey,
    },

    [ITEM_LIFT_KEY] =
    {
        .name = ITEM_NAME("Lift Key"),
        .nombre = ITEM_NAME("Llave de elevacion"),
        .price = 0,
        .description = COMPOUND_STRING(
            "An elevator key\n"
            "used in Team\n"
            "Rocket's Hideout."),
        .descricao = COMPOUND_STRING(
            "Uma chave de\n"
            "elevador usada no\n"
            "Esconderijo da."),
        .descricion = COMPOUND_STRING(
            "Una llave ascensor\n"
            "utilizada en el\n"
            "escondite del."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_LiftKey,
        .iconPalette = gItemIconPalette_Key,
    },

    [ITEM_SILPH_SCOPE] =
    {
        .name = ITEM_NAME("Silph Scope"),
        .nombre = ITEM_NAME("Mira telescopica"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Silph Co's scope\n"
            "makes unseeable\n"
            "POKéMON visible."),
        .descricao = COMPOUND_STRING(
            "O escopo da Silph\n"
            "Co torna visível o\n"
            "Pokémon invisível."),
        .descricion = COMPOUND_STRING(
            "La mira de Silph Co\n"
            "hace visibles los\n"
            "Pokémon invisibles."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_SilphScope,
        .iconPalette = gItemIconPalette_SilphScope,
    },

    [ITEM_TRI_PASS] =
    {
        .name = ITEM_NAME("Tri-Pass"),
        .nombre = ITEM_NAME("triple pase"),
        .pluralName = ITEM_PLURAL_NAME("Tri-Passes"),
        .price = 0,
        .description = COMPOUND_STRING(
            "A pass for ferries\n"
            "between One, Two,\n"
            "and Three Island."),
        .descricao = COMPOUND_STRING(
            "Um passe para\n"
            "balsas entre ilhas\n"
            "Um, Dois e Três."),
        .descricion = COMPOUND_STRING(
            "Un pase para\n"
            "ferries entre One,\n"
            "Two y Three Island."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_TriPass,
        .iconPalette = gItemIconPalette_TriPass,
    },

    [ITEM_RAINBOW_PASS] =
    {
        .name = ITEM_NAME("Rainbow Pass"),
        .nombre = ITEM_NAME("Pase arcoiris"),
        .pluralName = ITEM_PLURAL_NAME("Rainbow Passes"),
        .price = 0,
        .description = COMPOUND_STRING(
            "For ferries serving\n"
            "Vermilion and the\n"
            "Sevii Islands."),
        .descricao = COMPOUND_STRING(
            "Para balsas que\n"
            "servem Vermilion e\n"
            "as Ilhas Sevii."),
        .descricion = COMPOUND_STRING(
            "Para ferries que\n"
            "sirven a Vermilion\n"
            "y las islas Sevii."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_RainbowPass,
        .iconPalette = gItemIconPalette_RainbowPass,
    },

    [ITEM_TEA] =
    {
        .name = ITEM_NAME("Tea"),
        .nombre = ITEM_NAME("te"),
        .pluralName = ITEM_PLURAL_NAME("Tea"),
        .price = 0,
        .description = COMPOUND_STRING(
            "A thirst-quenching\n"
            "tea prepared by an\n"
            "old lady."),
        .descricao = COMPOUND_STRING(
            "Um chá para matar a\n"
            "sede preparado por\n"
            "uma senhora idosa."),
        .descricion = COMPOUND_STRING(
            "Un té para calmar\n"
            "la sed preparado\n"
            "por una anciana."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_Tea,
        .iconPalette = gItemIconPalette_Tea,
    },

    [ITEM_RUBY] =
    {
        .name = ITEM_NAME("Ruby"),
        .nombre = ITEM_NAME("rubi"),
        .pluralName = ITEM_PLURAL_NAME("Rubies"),
        .price = 0,
        .description = COMPOUND_STRING(
            "An exquisite, red-\n"
            "glowing gem that\n"
            "symbolizes passion."),
        .descricao = COMPOUND_STRING(
            "Uma joia requintada\n"
            "de brilho vermelho\n"
            "que simboliza a."),
        .descricion = COMPOUND_STRING(
            "Una exquisita gema\n"
            "de color rojo\n"
            "brillante que."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_Gem,
        .iconPalette = gItemIconPalette_Ruby,
    },

    [ITEM_SAPPHIRE] =
    {
        .name = ITEM_NAME("Sapphire"),
        .nombre = ITEM_NAME("Zafiro"),
        .price = 0,
        .description = COMPOUND_STRING(
            "A brilliant blue\n"
            "gem that symbolizes\n"
            "honesty."),
        .descricao = COMPOUND_STRING(
            "Uma joia azul\n"
            "brilhante que\n"
            "simboliza a."),
        .descricion = COMPOUND_STRING(
            "Una gema azul\n"
            "brillante que\n"
            "simboliza la."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_Gem,
        .iconPalette = gItemIconPalette_Sapphire,
    },

    [ITEM_ABILITY_SHIELD] =
    {
        .name = ITEM_NAME("Ability Shield"),
        .nombre = ITEM_NAME("Escudo de habil."),
        .price = 20000,
        .holdEffect = HOLD_EFFECT_ABILITY_SHIELD,
        .description = COMPOUND_STRING(
            "Ability changes are\n"
            "prevented for this\n"
            "items's holder."),
        .descricao = COMPOUND_STRING(
            "Alterações de\n"
            "habilidade são\n"
            "evitadas para o."),
        .descricion = COMPOUND_STRING(
            "Se evitan cambios\n"
            "habilidad para el\n"
            "poseedor este."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_AbilityShield,
        .iconPalette = gItemIconPalette_AbilityShield,
    },

// GEN 9 ITEMS

    [ITEM_CLEAR_AMULET] =
    {
        .name = ITEM_NAME("Clear Amulet"),
        .nombre = ITEM_NAME("Amuleto claro"),
        .price = 30000,
        .holdEffect = HOLD_EFFECT_CLEAR_AMULET,
        .description = COMPOUND_STRING(
            "Stat lowering is\n"
            "prevented for this\n"
            "items's holder."),
        .descricao = COMPOUND_STRING(
            "A redução de\n"
            "estatísticas é\n"
            "evitada para o."),
        .descricion = COMPOUND_STRING(
            "Se evita la\n"
            "reducción\n"
            "estadísticas para."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_ClearAmulet,
        .iconPalette = gItemIconPalette_ClearAmulet,
    },

    [ITEM_PUNCHING_GLOVE] =
    {
        .name = ITEM_NAME("Punching Glove"),
        .nombre = ITEM_NAME("Guante de boxeo"),
        .price = 15000,
        .holdEffect = HOLD_EFFECT_PUNCHING_GLOVE,
        .description = COMPOUND_STRING(
            "Powers up punching\n"
            "moves and removes\n"
            "their contact."),
        .descricao = COMPOUND_STRING(
            "Aumenta os golpes\n"
            "de soco e remove o\n"
            "contato."),
        .descricion = COMPOUND_STRING(
            "Potencia los movs.\n"
            "puñetazo y elimina\n"
            "su contacto."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_PunchingGlove,
        .iconPalette = gItemIconPalette_PunchingGlove,
    },

    [ITEM_COVERT_CLOAK] =
    {
        .name = ITEM_NAME("Covert Cloak"),
        .nombre = ITEM_NAME("Capa encubierta"),
        .price = 20000,
        .holdEffect = HOLD_EFFECT_COVERT_CLOAK,
        .description = COMPOUND_STRING(
            "Protects holder\n"
            "from additional\n"
            "effects of moves."),
        .descricao = COMPOUND_STRING(
            "Protege titular\n"
            "efeitos adicionais\n"
            "golpes."),
        .descricion = COMPOUND_STRING(
            "Protege al titular\n"
            "de efectos\n"
            "adicionales de los."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_CovertCloak,
        .iconPalette = gItemIconPalette_CovertCloak,
    },

    [ITEM_LOADED_DICE] =
    {
        .name = ITEM_NAME("Loaded Dice"),
        .nombre = ITEM_NAME("Dados cargados"),
        .pluralName = ITEM_PLURAL_NAME("Loaded Dice"),
        .price = 20000,
        .holdEffect = HOLD_EFFECT_LOADED_DICE,
        .description = COMPOUND_STRING(
            "Rolls high numbers.\n"
            "Multihit strikes\n"
            "hit more times."),
        .descricao = COMPOUND_STRING(
            "Rola números altos.\n"
            "Golpes Multihit\n"
            "acertam mais vezes."),
        .descricion = COMPOUND_STRING(
            "Tira números altos.\n"
            "Los golpes\n"
            "múltiples golpean."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_LoadedDice,
        .iconPalette = gItemIconPalette_LoadedDice,
    },

    [ITEM_AUSPICIOUS_ARMOR] =
    {
        .name = ITEM_NAME("Auspicious Armor"),
        .nombre = ITEM_NAME("Armadura auspiciosa"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Armor inhabited by\n"
            "auspicious wishes.\n"
            "Causes evolution."),
        .descricao = COMPOUND_STRING(
            "Armadura habitada\n"
            "por desejos\n"
            "auspiciosos. Causa."),
        .descricion = COMPOUND_STRING(
            "Armadura habitada\n"
            "por deseos\n"
            "auspiciosos."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
        .iconPic = gItemIcon_AuspiciousArmor,
        .iconPalette = gItemIconPalette_AuspiciousArmor,
    },

    [ITEM_BOOSTER_ENERGY] =
    {
        .name = ITEM_NAME("Booster Energy"),
        .nombre = ITEM_NAME("Energia de refuerzo"),
        .pluralName = ITEM_PLURAL_NAME("Booster Energies"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_BOOSTER_ENERGY,
        .description = COMPOUND_STRING(
            "Encapsuled energy\n"
            "ups Pokémon with\n"
            "certain Abilities."),
        .descricao = COMPOUND_STRING(
            "A energia\n"
            "encapsulada sobe\n"
            "Pokémon com certas."),
        .descricion = COMPOUND_STRING(
            "La energía\n"
            "encapsulada sobe\n"
            "los Pokémon con."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_BoosterEnergy,
        .iconPalette = gItemIconPalette_BoosterEnergy,
    },

    [ITEM_BIG_BAMBOO_SHOOT] =
    {
        .name = ITEM_NAME("Big Bamboo Shoot"),
        .nombre = ITEM_NAME("Big Bamboo Shoot"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "A large and rare\n"
            "bamboo shoot. Best\n"
            "sold to gourmands."),
        .descricao = COMPOUND_STRING(
            "Um grande e raro\n"
            "broto bambu. Melhor\n"
            "vendido para."),
        .descricion = COMPOUND_STRING(
            "Un brote bambú\n"
            "grande y raro.\n"
            "Mejor vendido los."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SELLABLE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_BigBambooShoot,
        .iconPalette = gItemIconPalette_BigBambooShoot,
    },

    [ITEM_GIMMIGHOUL_COIN] =
    {
        .name = ITEM_NAME("Gimmighoul Coin"),
        .nombre = ITEM_NAME("Moneda Gimmighoul"),
        .price = 400,
        .description = COMPOUND_STRING(
            "Gimmighoul hoard\n"
            "and treasure these\n"
            "curious coins."),
        .descricao = COMPOUND_STRING(
            "Gimmighoul acumula\n"
            "e valoriza essas\n"
            "moedas curiosas."),
        .descricion = COMPOUND_STRING(
            "Gimmighoul atesora\n"
            "y atesora estas\n"
            "curiosas monedas."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_GimmighoulCoin,
        .iconPalette = gItemIconPalette_GimmighoulCoin,
    },

    [ITEM_LEADERS_CREST] =
    {
        .name = ITEM_NAME("Leader's Crest"),
        .nombre = ITEM_NAME("Cresta del lider"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "A shard of an old\n"
            "blade of some sort.\n"
            "Held by Bisharp."),
        .descricao = COMPOUND_STRING(
            "Um fragmento algum\n"
            "tipo lâmina antiga.\n"
            "Realizado."),
        .descricion = COMPOUND_STRING(
            "Un fragmento una\n"
            "vieja espada algún\n"
            "tipo. En manos"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_LeadersCrest,
        .iconPalette = gItemIconPalette_LeadersCrest,
    },

    [ITEM_MALICIOUS_ARMOR] =
    {
        .name = ITEM_NAME("Malicious Armor"),
        .nombre = ITEM_NAME("Armadura maliciosa"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Armor inhabited by\n"
            "malicious will.\n"
            "Causes evolution."),
        .descricao = COMPOUND_STRING(
            "Armadura habitada\n"
            "por vontade\n"
            "maliciosa. Causa."),
        .descricion = COMPOUND_STRING(
            "Armadura habitada\n"
            "por voluntad\n"
            "maliciosa. Provoca."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
        .iconPic = gItemIcon_MaliciousArmor,
        .iconPalette = gItemIconPalette_MaliciousArmor,
    },

    [ITEM_MIRROR_HERB] =
    {
        .name = ITEM_NAME("Mirror Herb"),
        .nombre = ITEM_NAME("Hierba espejo"),
        .price = 30000,
        .holdEffect = HOLD_EFFECT_MIRROR_HERB,
        .description = COMPOUND_STRING(
            "Mirrors an enemy's\n"
            "stat increases but\n"
            "only once."),
        .descricao = COMPOUND_STRING(
            "Espelha aumentos\n"
            "estatísticas alvo,\n"
            "mas apenas."),
        .descricion = COMPOUND_STRING(
            "Refleja los\n"
            "aumentos\n"
            "estadísticas un."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_MirrorHerb,
        .iconPalette = gItemIconPalette_MirrorHerb,
    },

    [ITEM_SCROLL_OF_DARKNESS] =
    {
        .name = ITEM_NAME("Scroll of Darkness"),
        .nombre = ITEM_NAME("Scroll of Darkness"),
        .pluralName = ITEM_PLURAL_NAME("Scrolls of Darkness"),
        .price = 0,
        .description = COMPOUND_STRING(
            "A peculiar scroll\n"
            "with secrets of the\n"
            "dark path."),
        .descricao = COMPOUND_STRING(
            "Uma espécie\n"
            "pergaminho com\n"
            "segredos caminho."),
        .descricion = COMPOUND_STRING(
            "Un peculiar\n"
            "pergamino con\n"
            "secretos del."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .iconPic = gItemIcon_ScrollOfDarkness,
        .iconPalette = gItemIconPalette_ScrollOfDarkness,
    },

    [ITEM_SCROLL_OF_WATERS] =
    {
        .name = ITEM_NAME("Scroll of Waters"),
        .nombre = ITEM_NAME("Pergamino de aguas"),
        .pluralName = ITEM_PLURAL_NAME("Scrolls of Waters"),
        .price = 0,
        .description = COMPOUND_STRING(
            "A peculiar scroll\n"
            "with secrets of the\n"
            "water path."),
        .descricao = COMPOUND_STRING(
            "Uma espécie\n"
            "pergaminho com\n"
            "segredos caminho."),
        .descricion = COMPOUND_STRING(
            "Un peculiar\n"
            "pergamino con\n"
            "secretos del."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .iconPic = gItemIcon_ScrollOfWaters,
        .iconPalette = gItemIconPalette_ScrollOfWaters,
    },

    [ITEM_TERA_ORB] =
    {
        .name = ITEM_NAME("Tera Orb"),
        .nombre = ITEM_NAME("Orbe de Tera"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Energy charges can\n"
            "be used to cause\n"
            "Terastallization."),
        .descricao = COMPOUND_STRING(
            "Cargas de energia\n"
            "podem ser usadas\n"
            "para causar."),
        .descricion = COMPOUND_STRING(
            "Las cargas de\n"
            "energía se pueden\n"
            "utilizar para."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_TeraOrb,
        .iconPalette = gItemIconPalette_TeraOrb,
    },

    [ITEM_TINY_BAMBOO_SHOOT] =
    {
        .name = ITEM_NAME("Tiny Bamboo Shoot"),
        .nombre = ITEM_NAME("Tiny Bamboo Shoot"),
        .price = 750,
        .description = COMPOUND_STRING(
            "A small and rare\n"
            "bamboo shoot. Best\n"
            "sold to gourmands."),
        .descricao = COMPOUND_STRING(
            "Um pequeno e raro\n"
            "broto bambu. Melhor\n"
            "vendido para."),
        .descricion = COMPOUND_STRING(
            "Un pequeño y raro\n"
            "brote bambú. Mejor\n"
            "vendido los."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SELLABLE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_TinyBambooShoot,
        .iconPalette = gItemIconPalette_TinyBambooShoot,
    },

    [ITEM_BUG_TERA_SHARD] =
    {
        .name = ITEM_NAME("Bug Tera Shard"),
        .nombre = ITEM_NAME("Bug Tera Shard"),
        .price = 0,
        .description = sTeraShardDesc,
        .descricao = COMPOUND_STRING(
            "Esses fragmentos\n"
            "podem se formar\n"
            "quando um Pokémon."),
        .descricion = COMPOUND_STRING(
            "Estos fragmentos\n"
            "pueden formarse\n"
            "cuando un Pokémon."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TERA_SHARD,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_TeraShard,
        .iconPalette = gItemIconPalette_BugTeraShard,
    },

    [ITEM_DARK_TERA_SHARD] =
    {
        .name = ITEM_NAME("Dark Tera Shard"),
        .nombre = ITEM_NAME("Dark Tera Shard"),
        .price = 0,
        .description = sTeraShardDesc,
        .descricao = COMPOUND_STRING(
            "Esses fragmentos\n"
            "podem se formar\n"
            "quando um Pokémon."),
        .descricion = COMPOUND_STRING(
            "Estos fragmentos\n"
            "pueden formarse\n"
            "cuando un Pokémon."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TERA_SHARD,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_TeraShard,
        .iconPalette = gItemIconPalette_DarkTeraShard,
    },

    [ITEM_DRAGON_TERA_SHARD] =
    {
        .name = ITEM_NAME("Dragon Tera Shard"),
        .nombre = ITEM_NAME("Dragon Tera Shard"),
        .price = 0,
        .description = sTeraShardDesc,
        .descricao = COMPOUND_STRING(
            "Esses fragmentos\n"
            "podem se formar\n"
            "quando um Pokémon."),
        .descricion = COMPOUND_STRING(
            "Estos fragmentos\n"
            "pueden formarse\n"
            "cuando un Pokémon."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TERA_SHARD,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_TeraShard,
        .iconPalette = gItemIconPalette_DragonTeraShard,
    },

    [ITEM_ELECTRIC_TERA_SHARD] =
    {
        .name = ITEM_NAME("Electric Tera Shard"),
        .nombre = ITEM_NAME("Electric Tera Shard"),
        .price = 0,
        .description = sTeraShardDesc,
        .descricao = COMPOUND_STRING(
            "Esses fragmentos\n"
            "podem se formar\n"
            "quando um Pokémon."),
        .descricion = COMPOUND_STRING(
            "Estos fragmentos\n"
            "pueden formarse\n"
            "cuando un Pokémon."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TERA_SHARD,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_TeraShard,
        .iconPalette = gItemIconPalette_ElectricTeraShard,
    },

    [ITEM_FAIRY_TERA_SHARD] =
    {
        .name = ITEM_NAME("Fairy Tera Shard"),
        .nombre = ITEM_NAME("Fairy Tera Shard"),
        .price = 0,
        .description = sTeraShardDesc,
        .descricao = COMPOUND_STRING(
            "Esses fragmentos\n"
            "podem se formar\n"
            "quando um Pokémon."),
        .descricion = COMPOUND_STRING(
            "Estos fragmentos\n"
            "pueden formarse\n"
            "cuando un Pokémon."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TERA_SHARD,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_TeraShard,
        .iconPalette = gItemIconPalette_FairyTeraShard,
    },

    [ITEM_FIGHTING_TERA_SHARD] =
    {
        .name = ITEM_NAME("Fighting Tera Shard"),
        .nombre = ITEM_NAME("Fighting Tera Shard"),
        .price = 0,
        .description = sTeraShardDesc,
        .descricao = COMPOUND_STRING(
            "Esses fragmentos\n"
            "podem se formar\n"
            "quando um Pokémon."),
        .descricion = COMPOUND_STRING(
            "Estos fragmentos\n"
            "pueden formarse\n"
            "cuando un Pokémon."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TERA_SHARD,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_TeraShard,
        .iconPalette = gItemIconPalette_FightingTeraShard,
    },

    [ITEM_FIRE_TERA_SHARD] =
    {
        .name = ITEM_NAME("Fire Tera Shard"),
        .nombre = ITEM_NAME("Fire Tera Shard"),
        .price = 0,
        .description = sTeraShardDesc,
        .descricao = COMPOUND_STRING(
            "Esses fragmentos\n"
            "podem se formar\n"
            "quando um Pokémon."),
        .descricion = COMPOUND_STRING(
            "Estos fragmentos\n"
            "pueden formarse\n"
            "cuando un Pokémon."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TERA_SHARD,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_TeraShard,
        .iconPalette = gItemIconPalette_FireTeraShard,
    },

    [ITEM_FLYING_TERA_SHARD] =
    {
        .name = ITEM_NAME("Flying Tera Shard"),
        .nombre = ITEM_NAME("Flying Tera Shard"),
        .price = 0,
        .description = sTeraShardDesc,
        .descricao = COMPOUND_STRING(
            "Esses fragmentos\n"
            "podem se formar\n"
            "quando um Pokémon."),
        .descricion = COMPOUND_STRING(
            "Estos fragmentos\n"
            "pueden formarse\n"
            "cuando un Pokémon."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TERA_SHARD,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_TeraShard,
        .iconPalette = gItemIconPalette_FlyingTeraShard,
    },

    [ITEM_GHOST_TERA_SHARD] =
    {
        .name = ITEM_NAME("Ghost Tera Shard"),
        .nombre = ITEM_NAME("Ghost Tera Shard"),
        .price = 0,
        .description = sTeraShardDesc,
        .descricao = COMPOUND_STRING(
            "Esses fragmentos\n"
            "podem se formar\n"
            "quando um Pokémon."),
        .descricion = COMPOUND_STRING(
            "Estos fragmentos\n"
            "pueden formarse\n"
            "cuando un Pokémon."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TERA_SHARD,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_TeraShard,
        .iconPalette = gItemIconPalette_GhostTeraShard,
    },

    [ITEM_GRASS_TERA_SHARD] =
    {
        .name = ITEM_NAME("Grass Tera Shard"),
        .nombre = ITEM_NAME("Grass Tera Shard"),
        .price = 0,
        .description = sTeraShardDesc,
        .descricao = COMPOUND_STRING(
            "Esses fragmentos\n"
            "podem se formar\n"
            "quando um Pokémon."),
        .descricion = COMPOUND_STRING(
            "Estos fragmentos\n"
            "pueden formarse\n"
            "cuando un Pokémon."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TERA_SHARD,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_TeraShard,
        .iconPalette = gItemIconPalette_GrassTeraShard,
    },

    [ITEM_GROUND_TERA_SHARD] =
    {
        .name = ITEM_NAME("Ground Tera Shard"),
        .nombre = ITEM_NAME("Ground Tera Shard"),
        .price = 0,
        .description = sTeraShardDesc,
        .descricao = COMPOUND_STRING(
            "Esses fragmentos\n"
            "podem se formar\n"
            "quando um Pokémon."),
        .descricion = COMPOUND_STRING(
            "Estos fragmentos\n"
            "pueden formarse\n"
            "cuando un Pokémon."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TERA_SHARD,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_TeraShard,
        .iconPalette = gItemIconPalette_GroundTeraShard,
    },

    [ITEM_ICE_TERA_SHARD] =
    {
        .name = ITEM_NAME("Ice Tera Shard"),
        .nombre = ITEM_NAME("Ice Tera Shard"),
        .price = 0,
        .description = sTeraShardDesc,
        .descricao = COMPOUND_STRING(
            "Esses fragmentos\n"
            "podem se formar\n"
            "quando um Pokémon."),
        .descricion = COMPOUND_STRING(
            "Estos fragmentos\n"
            "pueden formarse\n"
            "cuando un Pokémon."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TERA_SHARD,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_TeraShard,
        .iconPalette = gItemIconPalette_IceTeraShard,
    },

    [ITEM_NORMAL_TERA_SHARD] =
    {
        .name = ITEM_NAME("Normal Tera Shard"),
        .nombre = ITEM_NAME("Normal Tera Shard"),
        .price = 0,
        .description = sTeraShardDesc,
        .descricao = COMPOUND_STRING(
            "Esses fragmentos\n"
            "podem se formar\n"
            "quando um Pokémon."),
        .descricion = COMPOUND_STRING(
            "Estos fragmentos\n"
            "pueden formarse\n"
            "cuando un Pokémon."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TERA_SHARD,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_TeraShard,
        .iconPalette = gItemIconPalette_NormalTeraShard,
    },

    [ITEM_POISON_TERA_SHARD] =
    {
        .name = ITEM_NAME("Poison Tera Shard"),
        .nombre = ITEM_NAME("Poison Tera Shard"),
        .price = 0,
        .description = sTeraShardDesc,
        .descricao = COMPOUND_STRING(
            "Esses fragmentos\n"
            "podem se formar\n"
            "quando um Pokémon."),
        .descricion = COMPOUND_STRING(
            "Estos fragmentos\n"
            "pueden formarse\n"
            "cuando un Pokémon."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TERA_SHARD,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_TeraShard,
        .iconPalette = gItemIconPalette_PoisonTeraShard,
    },

    [ITEM_PSYCHIC_TERA_SHARD] =
    {
        .name = ITEM_NAME("Psychic Tera Shard"),
        .nombre = ITEM_NAME("Psychic Tera Shard"),
        .price = 0,
        .description = sTeraShardDesc,
        .descricao = COMPOUND_STRING(
            "Esses fragmentos\n"
            "podem se formar\n"
            "quando um Pokémon."),
        .descricion = COMPOUND_STRING(
            "Estos fragmentos\n"
            "pueden formarse\n"
            "cuando un Pokémon."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TERA_SHARD,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_TeraShard,
        .iconPalette = gItemIconPalette_PsychicTeraShard,
    },

    [ITEM_ROCK_TERA_SHARD] =
    {
        .name = ITEM_NAME("Rock Tera Shard"),
        .nombre = ITEM_NAME("Rock Tera Shard"),
        .price = 0,
        .description = sTeraShardDesc,
        .descricao = COMPOUND_STRING(
            "Esses fragmentos\n"
            "podem se formar\n"
            "quando um Pokémon."),
        .descricion = COMPOUND_STRING(
            "Estos fragmentos\n"
            "pueden formarse\n"
            "cuando un Pokémon."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TERA_SHARD,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_TeraShard,
        .iconPalette = gItemIconPalette_RockTeraShard,
    },

    [ITEM_STEEL_TERA_SHARD] =
    {
        .name = ITEM_NAME("Steel Tera Shard"),
        .nombre = ITEM_NAME("Steel Tera Shard"),
        .price = 0,
        .description = sTeraShardDesc,
        .descricao = COMPOUND_STRING(
            "Esses fragmentos\n"
            "podem se formar\n"
            "quando um Pokémon."),
        .descricion = COMPOUND_STRING(
            "Estos fragmentos\n"
            "pueden formarse\n"
            "cuando un Pokémon."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TERA_SHARD,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_TeraShard,
        .iconPalette = gItemIconPalette_SteelTeraShard,
    },

    [ITEM_WATER_TERA_SHARD] =
    {
        .name = ITEM_NAME("Water Tera Shard"),
        .nombre = ITEM_NAME("Water Tera Shard"),
        .price = 0,
        .description = sTeraShardDesc,
        .descricao = COMPOUND_STRING(
            "Esses fragmentos\n"
            "podem se formar\n"
            "quando um Pokémon."),
        .descricion = COMPOUND_STRING(
            "Estos fragmentos\n"
            "pueden formarse\n"
            "cuando un Pokémon."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TERA_SHARD,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_TeraShard,
        .iconPalette = gItemIconPalette_WaterTeraShard,
    },

    [ITEM_ADAMANT_CRYSTAL] =
    {
        .name = ITEM_NAME("Adamant Crystal"),
        .nombre = ITEM_NAME("Cristal Adamante"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_ADAMANT_ORB,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "A large, glowing\n"
            "gem that lets\n"
            "Dialga change form."),
        .descricao = COMPOUND_STRING(
            "Uma joia grande e\n"
            "brilhante que\n"
            "permite que Dialga."),
        .descricion = COMPOUND_STRING(
            "Una gema grande y\n"
            "brillante que\n"
            "permite a Dialga."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 60,
        .iconPic = gItemIcon_AdamantCrystal,
        .iconPalette = gItemIconPalette_AdamantCrystal,
    },

    [ITEM_GRISEOUS_CORE] =
    {
        .name = ITEM_NAME("Griseous Core"),
        .nombre = ITEM_NAME("Nucleo grisaceo"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_GRISEOUS_ORB,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "A large, glowing\n"
            "gem lets Giratina\n"
            "change form."),
        .descricao = COMPOUND_STRING(
            "Uma joia grande e\n"
            "brilhante permite\n"
            "Giratina"),
        .descricion = COMPOUND_STRING(
            "Una gema grande y\n"
            "brillante que\n"
            "permite a Giratina."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 60,
        .iconPic = gItemIcon_GriseousCore,
        .iconPalette = gItemIconPalette_GriseousCore,
    },

    [ITEM_LUSTROUS_GLOBE] =
    {
        .name = ITEM_NAME("Lustrous Globe"),
        .nombre = ITEM_NAME("Globo brillante"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_LUSTROUS_ORB,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "A large, glowing\n"
            "gem that lets\n"
            "Palkia change form."),
        .descricao = COMPOUND_STRING(
            "Uma joia grande e\n"
            "brilhante que\n"
            "permite que Palkia."),
        .descricion = COMPOUND_STRING(
            "Una gema grande y\n"
            "brillante que le\n"
            "permite a Palkia."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 60,
        .iconPic = gItemIcon_LustrousGlobe,
        .iconPalette = gItemIconPalette_LustrousGlobe,
    },

    [ITEM_BLACK_AUGURITE] =
    {
        .name = ITEM_NAME("Black Augurite"),
        .nombre = ITEM_NAME("Augurita negra"),
        .price = 8000,
        .description = COMPOUND_STRING(
            "A black stone that\n"
            "makes some Pokémon\n"
            "evolve."),
        .descricao = COMPOUND_STRING(
            "Uma pedra negra que\n"
            "faz alguns Pokémon\n"
            "evolui."),
        .descricion = COMPOUND_STRING(
            "Una piedra negra\n"
            "hace evolucionar\n"
            "algunos Pokémon."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
        .iconPic = gItemIcon_BlackAugurite,
        .iconPalette = gItemIconPalette_BlackAugurite,
    },

    [ITEM_LINKING_CORD] =
    {
        .name = ITEM_NAME("Linking Cord"),
        .nombre = ITEM_NAME("Cable de conexion"),
        .price = 8000,
        .description = COMPOUND_STRING(
            "A mysterious string\n"
            "that makes some\n"
            "Pokémon evolve."),
        .descricao = COMPOUND_STRING(
            "Uma corda\n"
            "misteriosa faz\n"
            "alguns Pokémon."),
        .descricion = COMPOUND_STRING(
            "Un hilo misterioso\n"
            "hace evolucionar\n"
            "algunos Pokémon."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
        .iconPic = gItemIcon_LinkingCord,
        .iconPalette = gItemIconPalette_LinkingCord,
    },

    [ITEM_PEAT_BLOCK] =
    {
        .name = ITEM_NAME("Peat Block"),
        .nombre = ITEM_NAME("Bloque de turba"),
        .price = 10000,
        .description = COMPOUND_STRING(
            "A block of material\n"
            "that makes some\n"
            "Pokémon evolve."),
        .descricao = COMPOUND_STRING(
            "Um bloco material\n"
            "faz alguns Pokémon\n"
            "evoluírem."),
        .descricion = COMPOUND_STRING(
            "Un bloque de\n"
            "material que hace\n"
            "evolucionar a."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
        .iconPic = gItemIcon_PeatBlock,
        .iconPalette = gItemIconPalette_PeatBlock,
    },

    [ITEM_BERSERK_GENE] =
    {
        .name = ITEM_NAME("Berserk Gene"),
        .nombre = ITEM_NAME("Gen loco"),
        .price = 20,
        .holdEffect = HOLD_EFFECT_BERSERK_GENE,
        .description = COMPOUND_STRING(
            "Sharply boosts\n"
            "Atk., but causes\n"
            "lasting confusion."),
        .descricao = COMPOUND_STRING(
            "Aumenta muito o\n"
            "Atq., mas causa\n"
            "confusão duradoura."),
        .descricion = COMPOUND_STRING(
            "Aumenta\n"
            "considerablemente\n"
            "el Atq., pero."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_BerserkGene,
        .iconPalette = gItemIconPalette_BerserkGene,
    },

    [ITEM_FAIRY_FEATHER] =
    {
        .name = ITEM_NAME("Fairy Feather"),
        .nombre = ITEM_NAME("Pluma de hada"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_TYPE_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "A hold item that\n"
            "boosts the power of\n"
            "Fairy-type moves."),
        .descricao = COMPOUND_STRING(
            "Um item de retenção\n"
            "que sobe o poder\n"
            "dos golpes do tipo."),
        .descricion = COMPOUND_STRING(
            "Un elemento de\n"
            "retención que sobe\n"
            "el poder de."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TYPE_BOOST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FAIRY,
        .flingPower = 10,
        .iconPic = gItemIcon_FairyFeather,
        .iconPalette = gItemIconPalette_FairyFeather,
    },

    [ITEM_SYRUPY_APPLE] =
    {
        .name = ITEM_NAME("Syrupy Apple"),
        .nombre = ITEM_NAME("Manzana almibarada"),
        .price = 2200,
        .description = COMPOUND_STRING(
            "A very syrupy apple\n"
            "that makes certain\n"
            "Pokémon evolve."),
        .descricao = COMPOUND_STRING(
            "Uma maçã muito\n"
            "melosa que faz\n"
            "evolui certos."),
        .descricion = COMPOUND_STRING(
            "Una manzana muy\n"
            "almibarada que hace\n"
            "evolucionar a."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
        .iconPic = gItemIcon_SyrupyApple,
        .iconPalette = gItemIconPalette_SyrupyApple,
    },

    [ITEM_UNREMARKABLE_TEACUP] =
    {
        .name = ITEM_NAME("Unremarkable Teacup"),
        .nombre = ITEM_NAME("Unremarkable Teacup"),
        .price = 1600,
        .description = COMPOUND_STRING(
            "A cracked teacup\n"
            "that makes certain\n"
            "Pokémon evolve."),
        .descricao = COMPOUND_STRING(
            "Uma xícara de chá\n"
            "quebrada que faz\n"
            "certos Pokémon."),
        .descricion = COMPOUND_STRING(
            "Una taza té rota\n"
            "hace evolucionar\n"
            "ciertos Pokémon."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 80,
        .iconPic = gItemIcon_UnremarkableTeacup,
        .iconPalette = gItemIconPalette_UnremarkableTeacup,
    },

    [ITEM_MASTERPIECE_TEACUP] =
    {
        .name = ITEM_NAME("Masterpiece Teacup"),
        .nombre = ITEM_NAME("Masterpiece Teacup"),
        .price = 38000,
        .description = COMPOUND_STRING(
            "A chipped teacup\n"
            "that makes certain\n"
            "Pokémon evolve."),
        .descricao = COMPOUND_STRING(
            "Uma xícara de chá\n"
            "lascada que faz\n"
            "certos Pokémon."),
        .descricion = COMPOUND_STRING(
            "Una taza de té\n"
            "desconchada que\n"
            "hace evolucionar a."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 80,
        .iconPic = gItemIcon_MasterpieceTeacup,
        .iconPalette = gItemIconPalette_MasterpieceTeacup,
    },

    [ITEM_CORNERSTONE_MASK] =
    {
        .name = ITEM_NAME("Cornerstone Mask"),
        .nombre = ITEM_NAME("Cornerstone Mask"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_OGERPON_MASK,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "Allows Ogerpon to\n"
            "wield the Rock-\n"
            "type in battle."),
        .descricao = COMPOUND_STRING(
            "Permite que Ogerpon\n"
            "use o tipo Rock em\n"
            "luta."),
        .descricion = COMPOUND_STRING(
            "Le permite Ogerpon\n"
            "empuñar el tipo\n"
            "Roca en batalla."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SPECIAL_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_CornerstoneMask,
        .iconPalette = gItemIconPalette_CornerstoneMask,
    },

    [ITEM_WELLSPRING_MASK] =
    {
        .name = ITEM_NAME("Wellspring Mask"),
        .nombre = ITEM_NAME("Mascara de fuente"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_OGERPON_MASK,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "Allows Ogerpon to\n"
            "wield the Water-\n"
            "type in battle."),
        .descricao = COMPOUND_STRING(
            "Permite que Ogerpon\n"
            "use o tipo Água em\n"
            "luta."),
        .descricion = COMPOUND_STRING(
            "Le permite Ogerpon\n"
            "manejar el tipo\n"
            "Agua en batalla."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SPECIAL_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_WellspringMask,
        .iconPalette = gItemIconPalette_WellspringMask,
    },

    [ITEM_HEARTHFLAME_MASK] =
    {
        .name = ITEM_NAME("Hearthflame Mask"),
        .nombre = ITEM_NAME("Hearthflame Mask"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_OGERPON_MASK,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "Allows Ogerpon to\n"
            "wield the Fire-\n"
            "type in battle."),
        .descricao = COMPOUND_STRING(
            "Permite que Ogerpon\n"
            "empunhe o tipo Fogo\n"
            "em luta."),
        .descricion = COMPOUND_STRING(
            "Le permite Ogerpon\n"
            "empuñar el tipo\n"
            "Fuego en batalla."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SPECIAL_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_HearthflameMask,
        .iconPalette = gItemIconPalette_HearthflameMask,
    },

    [ITEM_HEALTH_MOCHI] =
    {
        .name = ITEM_NAME("Health Mochi"),
        .nombre = ITEM_NAME("Salud Mochi"),
        .pluralName = ITEM_PLURAL_NAME("Health Mochi"),
        .price = 500,
        .description = sHealthFeatherDesc,
        .descricao = COMPOUND_STRING(
            "Um item que sobe o\n"
            "HP base de um\n"
            "Pokémon."),
        .descricion = COMPOUND_STRING(
            "Un elemento que\n"
            "sobe el HP base de\n"
            "un Pokémon."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STAT_BOOST_MOCHI,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .effect = gItemEffect_HpMochi,
        .flingPower = 30,
        .iconPic = gItemIcon_Mochi,
        .iconPalette = gItemIconPalette_HealthMochi,
    },

    [ITEM_MUSCLE_MOCHI] =
    {
        .name = ITEM_NAME("Muscle Mochi"),
        .nombre = ITEM_NAME("Mochi muscular"),
        .pluralName = ITEM_PLURAL_NAME("Muscle Mochi"),
        .price = 500,
        .description = sMuscleFeatherDesc,
        .descricao = COMPOUND_STRING(
            "Um item que sobe o\n"
            "Atq. base de um\n"
            "Pokémon."),
        .descricion = COMPOUND_STRING(
            "Un objeto que sobe\n"
            "el Atq. base de un\n"
            "Pokémon."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STAT_BOOST_MOCHI,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .effect = gItemEffect_AtkMochi,
        .flingPower = 30,
        .iconPic = gItemIcon_Mochi,
        .iconPalette = gItemIconPalette_MuscleMochi,
    },

    [ITEM_RESIST_MOCHI] =
    {
        .name = ITEM_NAME("Resist Mochi"),
        .nombre = ITEM_NAME("Resistir Mochi"),
        .pluralName = ITEM_PLURAL_NAME("Resist Mochi"),
        .price = 500,
        .description = sResistFeatherDesc,
        .descricao = COMPOUND_STRING(
            "Um item que sobe a\n"
            "Def. básica de um\n"
            "Pokémon."),
        .descricion = COMPOUND_STRING(
            "Un objeto que sobe\n"
            "la defensa base de\n"
            "un Pokémon."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STAT_BOOST_MOCHI,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .effect = gItemEffect_DefMochi,
        .flingPower = 30,
        .iconPic = gItemIcon_Mochi,
        .iconPalette = gItemIconPalette_ResistMochi,
    },

    [ITEM_GENIUS_MOCHI] =
    {
        .name = ITEM_NAME("Genius Mochi"),
        .nombre = ITEM_NAME("Genio Mochi"),
        .pluralName = ITEM_PLURAL_NAME("Genius Mochi"),
        .price = 500,
        .description = sGeniusFeatherDesc,
        .descricao = COMPOUND_STRING(
            "Um item que sobe o\n"
            "Sp base. Atk. de um\n"
            "Pokémon."),
        .descricion = COMPOUND_STRING(
            "Un elemento que\n"
            "eleva el Sp base.\n"
            "Atk. de un Pokémon."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STAT_BOOST_MOCHI,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .effect = gItemEffect_SpatkMochi,
        .flingPower = 30,
        .iconPic = gItemIcon_Mochi,
        .iconPalette = gItemIconPalette_GeniusMochi,
    },

    [ITEM_CLEVER_MOCHI] =
    {
        .name = ITEM_NAME("Clever Mochi"),
        .nombre = ITEM_NAME("Mochi inteligente"),
        .pluralName = ITEM_PLURAL_NAME("Clever Mochi"),
        .price = 500,
        .description = sCleverFeatherDesc,
        .descricao = COMPOUND_STRING(
            "Um item sobe Sp\n"
            "base.\n"
            "Definitivamente."),
        .descricion = COMPOUND_STRING(
            "Un elemento que\n"
            "eleva el Sp base.\n"
            "Def. de un Pokémon."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STAT_BOOST_MOCHI,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .effect = gItemEffect_SpdefMochi,
        .flingPower = 30,
        .iconPic = gItemIcon_Mochi,
        .iconPalette = gItemIconPalette_CleverMochi,
    },

    [ITEM_SWIFT_MOCHI] =
    {
        .name = ITEM_NAME("Swift Mochi"),
        .nombre = ITEM_NAME("Mochi veloz"),
        .pluralName = ITEM_PLURAL_NAME("Swift Mochi"),
        .price = 500,
        .description = sSwiftFeatherDesc,
        .descricao = COMPOUND_STRING(
            "Um item que sobe a\n"
            "Vel. base de um\n"
            "Pokémon."),
        .descricion = COMPOUND_STRING(
            "Un elemento que\n"
            "sobe la Vel. base\n"
            "de un Pokémon."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STAT_BOOST_MOCHI,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .effect = gItemEffect_SpeedMochi,
        .flingPower = 30,
        .iconPic = gItemIcon_Mochi,
        .iconPalette = gItemIconPalette_SwiftMochi,
    },

    [ITEM_FRESH_START_MOCHI] =
    {
        .name = ITEM_NAME("Fresh-Start Mochi"),
        .nombre = ITEM_NAME("Fresh-Start Mochi"),
        .pluralName = ITEM_PLURAL_NAME("Fresh-Start Mochi"),
        .price = 300,
        .description = COMPOUND_STRING(
            "An item that resets\n"
            "all base points of\n"
            "a Pokémon."),
        .descricao = COMPOUND_STRING(
            "Um item que zera\n"
            "todos os pontos\n"
            "base de um Pokémon."),
        .descricion = COMPOUND_STRING(
            "Un elemento\n"
            "restablece todos\n"
            "los puntos base un."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STAT_BOOST_MOCHI,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_ResetEVs,
        .effect = gItemEffect_ResetMochi,
        .flingPower = 30,
        .iconPic = gItemIcon_Mochi,
        .iconPalette = gItemIconPalette_FreshStartMochi,
    },

    [ITEM_GLIMMERING_CHARM] =
    {
        .name = ITEM_NAME("Glimmering Charm"),
        .nombre = ITEM_NAME("Encanto reluciente"),
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING(
            "A charm that will\n"
            "raise the shards\n"
            "from Tera Raids."),
        .descricao = COMPOUND_STRING(
            "Um amuleto irá\n"
            "levantar fragmentos\n"
            "Tera."),
        .descricion = COMPOUND_STRING(
            "Un amuleto que\n"
            "levantará los\n"
            "fragmentos de Tera."),
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_GlimmeringCharm,
        .iconPalette = gItemIconPalette_GlimmeringCharm,
    },

    [ITEM_METAL_ALLOY] =
    {
        .name = ITEM_NAME("Metal Alloy"),
        .nombre = ITEM_NAME("Aleacion de metales"),
        .price = 6000,
        .description = COMPOUND_STRING(
            "A peculiar metal\n"
            "that makes certain\n"
            "Pokémon evolve."),
        .descricao = COMPOUND_STRING(
            "Um metal peculiar\n"
            "que faz evolui\n"
            "certos Pokémon."),
        .descricion = COMPOUND_STRING(
            "Un metal peculiar\n"
            "hace evolucionar\n"
            "ciertos Pokémon."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .iconPic = gItemIcon_MetalAlloy,
        .iconPalette = gItemIconPalette_MetalAlloy,
    },

    [ITEM_STELLAR_TERA_SHARD] =
    {
        .name = ITEM_NAME("Stellar Tera Shard"),
        .nombre = ITEM_NAME("Stellar Tera Shard"),
        .price = 0,
        .description = sTeraShardDesc,
        .descricao = COMPOUND_STRING(
            "Esses fragmentos\n"
            "podem se formar\n"
            "quando um Pokémon."),
        .descricion = COMPOUND_STRING(
            "Estos fragmentos\n"
            "pueden formarse\n"
            "cuando un Pokémon."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TERA_SHARD,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_StellarTeraShard,
        .iconPalette = gItemIconPalette_StellarTeraShard,
    },

    [ITEM_JUBILIFE_MUFFIN] =
    {
        .name = ITEM_NAME("Jubilife Muffin"),
        .nombre = ITEM_NAME("Muffin Jubileo"),
        .price = 250,
        .description = sFullHealDesc,
        .descricao = COMPOUND_STRING(
            "Cura todos os\n"
            "problemas de status\n"
            "de um Pokémon."),
        .descricion = COMPOUND_STRING(
            "Cura todos los\n"
            "problemas de estado\n"
            "de un Pokémon."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STATUS_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_FullHeal,
        .flingPower = 30,
        .iconPic = gItemIcon_JubilifeMuffin,
        .iconPalette = gItemIconPalette_JubilifeMuffin,
    },

    [ITEM_REMEDY] =
    {
        .name = ITEM_NAME("Remedy"),
        .nombre = ITEM_NAME("Remedio"),
        .pluralName = ITEM_PLURAL_NAME("Remedies"),
        .price = 150,
        .description = COMPOUND_STRING(
            "A bitter powder\n"
            "that heals HP by 20\n"
            "points."),
        .descricao = COMPOUND_STRING(
            "Um pó amargo que\n"
            "cura o HP em 20\n"
            "pontos."),
        .descricion = COMPOUND_STRING(
            "Un polvo amargo que\n"
            "cura HP en 20\n"
            "puntos."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HEALTH_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_RESTORE_HP,
        .effect = gItemEffect_Remedy,
        .flingPower = 30,
        .iconPic = gItemIcon_Remedy,
        .iconPalette = gItemIconPalette_Remedy,
    },

    [ITEM_FINE_REMEDY] =
    {
        .name = ITEM_NAME("Fine Remedy"),
        .nombre = ITEM_NAME("Buen remedio"),
        .pluralName = ITEM_PLURAL_NAME("Fine Remedies"),
        .price = 150,
        .description = COMPOUND_STRING(
            "A bitter powder\n"
            "that heals HP"
        #if I_HEALTH_RECOVERY >= GEN_7
            "by 60 points."),
        .descricao = COMPOUND_STRING(
            "Um pó amargo que\n"
            "cura o HP em 60\n"
            "pontos."),
        .descricion = COMPOUND_STRING(
            "Un polvo amargo que\n"
            "cura HP en 60\n"
            "puntos."),
        #else
            "by 50 points."),
        #endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HEALTH_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_RESTORE_HP,
        .effect = gItemEffect_FineRemedy,
        .flingPower = 30,
        .iconPic = gItemIcon_FineRemedy,
        .iconPalette = gItemIconPalette_FineRemedy,
    },

    [ITEM_SUPERB_REMEDY] =
    {
        .name = ITEM_NAME("Superb Remedy"),
        .nombre = ITEM_NAME("Excelente remedio"),
        .pluralName = ITEM_PLURAL_NAME("Superb Remedies"),
        .price = 750,
        .description = COMPOUND_STRING(
            "A bitter powder\n"
            "that heals HP"
        #if I_HEALTH_RECOVERY >= GEN_7
            "by 120 points."),
        .descricao = COMPOUND_STRING(
            "Um pó amargo que\n"
            "cura o HP em 120\n"
            "pontos."),
        .descricion = COMPOUND_STRING(
            "Un polvo amargo que\n"
            "cura HP en 120\n"
            "puntos."),
        #else
            "by 200 points."),
        #endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HEALTH_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_RESTORE_HP,
        .effect = gItemEffect_SuperbRemedy,
        .flingPower = 30,
        .iconPic = gItemIcon_SuperbRemedy,
        .iconPalette = gItemIconPalette_SuperbRemedy,
    },

    [ITEM_AUX_EVASION] =
    {
        .name = ITEM_NAME("Aux Evasion"),
        .nombre = ITEM_NAME("Evasion auxiliar"),
        .price = 800,
        .holdEffectParam = X_ITEM_STAGES,
        .description = COMPOUND_STRING(
        #if B_X_ITEMS_BUFF >= GEN_7
            "Sharply boosts\n"
            "evasiveness during\n"
            "one battle."),
        .descricao = COMPOUND_STRING(
            "Aumenta muito a\n"
            "evasão durante uma\n"
            "luta."),
        .descricion = COMPOUND_STRING(
            "Aumenta mucho la\n"
            "evasión durante una\n"
            "batalla."),
        #else
            "Raises evasiveness\n"
            "during one battle."),
        #endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_AUX_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        //.effect = currently missing
        .iconPic = gItemIcon_AuxBottle,
        .iconPalette = gItemIconPalette_AuxEvasion,
    },

    [ITEM_AUX_GUARD] =
    {
        .name = ITEM_NAME("Aux Guard"),
        .nombre = ITEM_NAME("Guardia auxiliar"),
        .price = 400,
        .holdEffectParam = X_ITEM_STAGES,
        .description = COMPOUND_STRING(
        #if B_X_ITEMS_BUFF >= GEN_7
            "Sharply boosts\n"
            "defenses during one\n"
            "battle."),
        .descricao = COMPOUND_STRING(
            "Aumenta muito as\n"
            "defesas durante uma\n"
            "luta."),
        .descricion = COMPOUND_STRING(
            "Aumenta mucho las\n"
            "defensas durante\n"
            "una batalla."),
        #else
            "Raises defenses\n"
            "during one battle."),
        #endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_AUX_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        //.effect = currently missing
        .iconPic = gItemIcon_AuxBottle,
        .iconPalette = gItemIconPalette_AuxGuard,
    },

    [ITEM_AUX_POWER] =
    {
        .name = ITEM_NAME("Aux Power"),
        .nombre = ITEM_NAME("Aux Power"),
        .price = 400,
        .holdEffectParam = X_ITEM_STAGES,
        .description = COMPOUND_STRING(
        #if B_X_ITEMS_BUFF >= GEN_7
            "Sharply boosts\n"
            "offenses during one\n"
            "battle."),
        .descricao = COMPOUND_STRING(
            "Aumenta muito as\n"
            "ofensas durante uma\n"
            "luta."),
        .descricion = COMPOUND_STRING(
            "Aumenta mucho las\n"
            "ofensas durante una\n"
            "batalla."),
        #else
            "Raises offenses\n"
            "during one battle."),
        #endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_AUX_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        //.effect = currently missing
        .iconPic = gItemIcon_AuxBottle,
        .iconPalette = gItemIconPalette_AuxPower,
    },

    [ITEM_AUX_POWERGUARD] =
    {
        .name = ITEM_NAME("Aux Powerguard"),
        .nombre = ITEM_NAME("Aux Powerguard"),
        .price = 1200,
        .holdEffectParam = X_ITEM_STAGES,
        .description = COMPOUND_STRING(
        #if B_X_ITEMS_BUFF >= GEN_7
            "Sharply boosts\n"
            "offense & defense\n"
            "during one battle."),
        .descricao = COMPOUND_STRING(
            "Aumenta muito o\n"
            "Atq. e a Def.\n"
            "durante uma luta."),
        .descricion = COMPOUND_STRING(
            "Aumenta mucho la\n"
            "ofensiva y la\n"
            "defensa durante."),
        #else
            "Raises offense and\n"
            "defense during one\n"
            "battle."),
        #endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_AUX_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        //.effect = currently missing
        .iconPic = gItemIcon_AuxPowerguard,
        .iconPalette = gItemIconPalette_AuxPowerguard,
    },

    [ITEM_CHOICE_DUMPLING] =
    {
        .name = ITEM_NAME("Choice Dumpling"),
        .nombre = ITEM_NAME("Masa eleg."),
        .price = 1200,
        .description = sQuestionMarksDesc,
        .descricao = COMPOUND_STRING(
            "?????"),
        .descricion = COMPOUND_STRING(
            "?????"),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        //.effect = currently missing
        .iconPic = gItemIcon_ChoiceDumpling,
        .iconPalette = gItemIconPalette_ChoiceDumpling,
    },

    [ITEM_SWAP_SNACK] =
    {
        .name = ITEM_NAME("Swap Snack"),
        .nombre = ITEM_NAME("Swap Snack"),
        .price = 1200,
        .description = sQuestionMarksDesc,
        .descricao = COMPOUND_STRING(
            "?????"),
        .descricion = COMPOUND_STRING(
            "?????"),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        //.effect = currently missing
        .iconPic = gItemIcon_SwapSnack,
        .iconPalette = gItemIconPalette_SwapSnack,
    },

    [ITEM_TWICE_SPICED_RADISH] =
    {
        .name = ITEM_NAME("Twice-Spiced Radish"),
        .nombre = ITEM_NAME("Twice-Spiced Radish"),
        .pluralName = ITEM_PLURAL_NAME("Twice-Spiced Radishes"),
        .price = 1600,
        .description = sQuestionMarksDesc,
        .descricao = COMPOUND_STRING(
            "?????"),
        .descricion = COMPOUND_STRING(
            "?????"),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        //.effect = currently missing
        .iconPic = gItemIcon_TwiceSpicedRadish,
        .iconPalette = gItemIconPalette_TwiceSpicedRadish,
    },

    [ITEM_POKESHI_DOLL] =
    {
        .name = ITEM_NAME("Pokéshi Doll"),
        .nombre = ITEM_NAME("Muneca Pokeshi"),
        .price = 2000,
        .description = COMPOUND_STRING(
            "A wooden toy\n"
            "resembling a Poké-\n"
            "mon. Can be sold."),
        .descricao = COMPOUND_STRING(
            "Um brinquedo de\n"
            "madeira semelhante\n"
            "a um Pokémon. Pode."),
        .descricion = COMPOUND_STRING(
            "Un juguete madera\n"
            "parece un Pokémon.\n"
            "Se puede."),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SELLABLE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_PokeshiDoll,
        .iconPalette = gItemIconPalette_PokeshiDoll,
    },

    [ITEM_ULTRA_REPEL] =
    {
        .name = ITEM_NAME("Ultra Repel"),
        .nombre = ITEM_NAME("Ultra repeler"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Prevents weak wild\n"
            "Pokémon from\n"
            "appearing."),
        .descricao = COMPOUND_STRING(
            "Impede o\n"
            "aparecimento de\n"
            "Pokémon selv."),
        .descricion = COMPOUND_STRING(
            "Evita que aparezcan\n"
            "Pokémon salvajes\n"
            "débiles."),
        .pocket = POCKET_KEY_ITEMS,
        .sortType = ITEM_TYPE_FIELD_USE,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = FieldUseFunc_UltraRepel,
        .iconPic = gItemIcon_UltraRepel,
        .iconPalette = gItemIconPalette_UltraRepel,
    },
};

#undef ITEM_NAME
#undef ITEM_PLURAL_NAME
