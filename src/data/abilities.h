const struct AbilityInfo gAbilitiesInfo[ABILITIES_COUNT] =
{
    [ABILITY_NONE] =
    {
        .name = _("-------"),
        .nome = _("-------"),
        .nombre = _("-------"),
        .description = COMPOUND_STRING("No special ability."),
        .descricao = COMPOUND_STRING("Sem habilidade especial."),
        .descripcion = COMPOUND_STRING("Sin habilidad especial."),
        .aiRating = 0,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_STENCH] =
    {
        .name = _("Stench"),
        .nome = _("Fedor"),
        .nombre = _("Hedor"),
        .description = COMPOUND_STRING("May cause a foe to flinch."),
        .descricao = COMPOUND_STRING("Pode fazer o rival recuar."),
        .descripcion = COMPOUND_STRING("Puede hacer retroceder."),
        .aiRating = 1,
    },

    [ABILITY_DRIZZLE] =
    {
        .name = _("Drizzle"),
        .nome = _("Chuvisco"),
        .nombre = _("Llovizna"),
        .description = COMPOUND_STRING("Summons rain in battle."),
        .descricao = COMPOUND_STRING("Invoca chuva na batalha."),
        .descripcion = COMPOUND_STRING("Invoca lluvia en combate."),
        .aiRating = 9,
    },

    [ABILITY_SPEED_BOOST] =
    {
        .name = _("Speed Boost"),
        .nome = _("Acelerador"),
        .nombre = _("Impulso"),
        .description = COMPOUND_STRING("Gradually boosts Speed."),
        .descricao = COMPOUND_STRING("Aumenta a Speed gradualmente."),
        .descripcion = COMPOUND_STRING("Aumenta la Speed gradualmente."),
        .aiRating = 9,
    },

    [ABILITY_BATTLE_ARMOR] =
    {
        .name = _("Battle Armor"),
        .nome = _("Armadura Batalha"),
        .nombre = _("Armadura Batalla"),
        .description = COMPOUND_STRING("Blocks critical hits."),
        .descricao = COMPOUND_STRING("Bloqueia golpes criticos."),
        .descripcion = COMPOUND_STRING("Bloquea golpes criticos."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_STURDY] =
    {
        .name = _("Sturdy"),
        .nome = _("Robustez"),
        .nombre = _("Robustez"),
        .description = COMPOUND_STRING("Negates 1-hit KO attacks."),
        .descricao = COMPOUND_STRING("Evita golpes OHKO."),
        .descripcion = COMPOUND_STRING("Evita golpes OHKO."),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_DAMP] =
    {
        .name = _("Damp"),
        .nome = _("Umidade"),
        .nombre = _("Humedad"),
        .description = COMPOUND_STRING("Prevents self-destruction."),
        .descricao = COMPOUND_STRING("Impede autodestruicao."),
        .descripcion = COMPOUND_STRING("Impide autodestruccion."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_LIMBER] =
    {
        .name = _("Limber"),
        .nome = _("Flexibilidade"),
        .nombre = _("Flexibilidad"),
        .description = COMPOUND_STRING("Prevents paralysis."),
        .descricao = COMPOUND_STRING("Impede paralisia."),
        .descripcion = COMPOUND_STRING("Impide paralisis."),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_SAND_VEIL] =
    {
        .name = _("Sand Veil"),
        .nome = _("Véu de Areia"),
        .nombre = _("Velo Arena"),
        .description = COMPOUND_STRING("Ups evasion in a sandstorm."),
        .descricao = COMPOUND_STRING("Aumenta evasao na temp. areia."),
        .descripcion = COMPOUND_STRING("Sube evasion en torm. arena."),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_STATIC] =
    {
        .name = _("Static"),
        .nome = _("Estática"),
        .nombre = _("Elec. Estática"),
        .description = COMPOUND_STRING("Paralyzes on contact."),
        .descricao = COMPOUND_STRING("Paralisa no contato."),
        .descripcion = COMPOUND_STRING("Paraliza al contacto."),
        .aiRating = 4,
    },

    [ABILITY_VOLT_ABSORB] =
    {
        .name = _("Volt Absorb"),
        .nome = _("Absorve Volts"),
        .nombre = _("Absorbe Elec"),
        .description = COMPOUND_STRING("Turns electricity into HP."),
        .descricao = COMPOUND_STRING("Transforma eletricidade em HP."),
        .descripcion = COMPOUND_STRING("Convierte electricidad en PS."),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_WATER_ABSORB] =
    {
        .name = _("Water Absorb"),
        .nome = _("Absorve Água"),
        .nombre = _("Absorbe Agua"),
        .description = COMPOUND_STRING("Changes water into HP."),
        .descricao = COMPOUND_STRING("Transforma água em HP."),
        .descripcion = COMPOUND_STRING("Convierte agua en PS."),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_OBLIVIOUS] =
    {
        .name = _("Oblivious"),
        .nome = _("Insensível"),
        .nombre = _("Despiste"),
        .description = COMPOUND_STRING("Prevents attraction."),
        .descricao = COMPOUND_STRING("Impede atracão."),
        .descripcion = COMPOUND_STRING("Impide atraccion."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_CLOUD_NINE] =
    {
        .name = _("Cloud Nine"),
        .nome = _("Climatização"),
        .nombre = _("Aclimatación"),
        .description = COMPOUND_STRING("Negates weather effects."),
        .descricao = COMPOUND_STRING("Nega efeitos do clima."),
        .descripcion = COMPOUND_STRING("Niega efectos del clima."),
        .aiRating = 5,
    },

    [ABILITY_COMPOUND_EYES] =
    {
        .name = _("Compound Eyes"),
        .nome = _("Olhos Compostos"),
        .nombre = _("Ojo Compuesto"),
        .description = COMPOUND_STRING("Raises accuracy."),
        .descricao = COMPOUND_STRING("Aumenta a precisao."),
        .descripcion = COMPOUND_STRING("Sube la precision."),
        .aiRating = 7,
    },

    [ABILITY_INSOMNIA] =
    {
        .name = _("Insomnia"),
        .nome = _("Insônia"),
        .nombre = _("Insomnio"),
        .description = COMPOUND_STRING("Prevents sleep."),
        .descricao = COMPOUND_STRING("Impede sono."),
        .descripcion = COMPOUND_STRING("Impide dormir."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_COLOR_CHANGE] =
    {
        .name = _("Color Change"),
        .nome = _("Troca de Cor"),
        .nombre = _("Cambio Color"),
        .description = COMPOUND_STRING("Changes type to foe's move."),
        .descricao = COMPOUND_STRING("Muda o tipo para golpe inimigo."),
        .descripcion = COMPOUND_STRING("Cambia tipo por golpe del rival."),
        .aiRating = 2,
    },

    [ABILITY_IMMUNITY] =
    {
        .name = _("Immunity"),
        .nome = _("Imunidade"),
        .nombre = _("Inmunidad"),
        .description = COMPOUND_STRING("Prevents poisoning."),
        .descricao = COMPOUND_STRING("Impede envenenamento."),
        .descripcion = COMPOUND_STRING("Impide veneno."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_FLASH_FIRE] =
    {
        .name = _("Flash Fire"),
        .nome = _("Fogo Brilhante"),
        .nombre = _("Absorbe Fuego"),
        .description = COMPOUND_STRING("Powers up if hit by fire."),
        .descricao = COMPOUND_STRING("Fortalece se atingido por Fogo."),
        .descripcion = COMPOUND_STRING("Fortalece si golpeado por fuego."),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_SHIELD_DUST] =
    {
        .name = _("Shield Dust"),
        .nome = _("Escudo de Poeira"),
        .nombre = _("Polvo Escudo"),
        .description = COMPOUND_STRING("Prevents added effects."),
        .descricao = COMPOUND_STRING("Impede efeitos extras."),
        .descripcion = COMPOUND_STRING("Impide efectos extra."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_OWN_TEMPO] =
    {
        .name = _("Own Tempo"),
        .nome = _("Ritmo Próprio"),
        .nombre = _("Ritmo Propio"),
        .description = COMPOUND_STRING("Prevents confusion."),
        .descricao = COMPOUND_STRING("Impede confusao."),
        .descripcion = COMPOUND_STRING("Impide confusion."),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_SUCTION_CUPS] =
    {
        .name = _("Suction Cups"),
        .nome = _("Ventosas"),
        .nombre = _("Ventosas"),
        .description = COMPOUND_STRING("Firmly anchors the body."),
        .descricao = COMPOUND_STRING("Prende firmemente o corpo."),
        .descripcion = COMPOUND_STRING("Ancla bien el cuerpo."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_INTIMIDATE] =
    {
        .name = _("Intimidate"),
        .nome = _("Intimidação"),
        .nombre = _("Intimidación"),
        .description = COMPOUND_STRING("Lowers the foe's Attack."),
        .descricao = COMPOUND_STRING("Baixa o Atq. do rival."),
        .descripcion = COMPOUND_STRING("Baja el Atq. del rival."),
        .aiRating = 7,
    },

    [ABILITY_SHADOW_TAG] =
    {
        .name = _("Shadow Tag"),
        .nome = _("Fio de Sombra"),
        .nombre = _("Sombra Trampa"),
        .description = COMPOUND_STRING("Prevents the foe's escape."),
        .descricao = COMPOUND_STRING("Impede fuga do rival."),
        .descripcion = COMPOUND_STRING("Impide huida del rival."),
        .aiRating = 10,
    },

    [ABILITY_ROUGH_SKIN] =
    {
        .name = _("Rough Skin"),
        .nome = _("Pele Áspera"),
        .nombre = _("Piel Tosca"),
        .description = COMPOUND_STRING("Hurts to touch."),
        .descricao = COMPOUND_STRING("Machuca no contato."),
        .descripcion = COMPOUND_STRING("Duele al contacto."),
        .aiRating = 6,
    },

    [ABILITY_WONDER_GUARD] =
    {
        .name = _("Wonder Guard"),
        .nome = _("Defesa Mágica"),
        .nombre = _("Superguarda"),
        .description = COMPOUND_STRING("Only “Supereffective” hits."),
        .descricao = COMPOUND_STRING("So golpes superefetivos."),
        .descripcion = COMPOUND_STRING("Solo golpes supereficaces."),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .breakable = TRUE,
    },

    [ABILITY_LEVITATE] =
    {
        .name = _("Levitate"),
        .nome = _("Levitação"),
        .nombre = _("Levitación"),
        .description = COMPOUND_STRING("Not hit by Ground attacks."),
        .descricao = COMPOUND_STRING("Imune a golpes Terrestres."),
        .descripcion = COMPOUND_STRING("Inmune a golpes Tierra."),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_EFFECT_SPORE] =
    {
        .name = _("Effect Spore"),
        .nome = _("Efeito Esporo"),
        .nombre = _("Efecto Espora"),
        .description = COMPOUND_STRING("Leaves spores on contact."),
        .descricao = COMPOUND_STRING("Deixa esporos no contato."),
        .descripcion = COMPOUND_STRING("Deja esporas al contacto."),
        .aiRating = 4,
    },

    [ABILITY_SYNCHRONIZE] =
    {
        .name = _("Synchronize"),
        .nome = _("Sincronia"),
        .nombre = _("Sincronía"),
        .description = COMPOUND_STRING("Passes on status problems."),
        .descricao = COMPOUND_STRING("Passa problemas de estado."),
        .descripcion = COMPOUND_STRING("Pasa problemas de estado."),
        .aiRating = 4,
    },

    [ABILITY_CLEAR_BODY] =
    {
        .name = _("Clear Body"),
        .nome = _("Corpo Claro"),
        .nombre = _("Cuerpo Puro"),
        .description = COMPOUND_STRING("Prevents ability reduction."),
        .descricao = COMPOUND_STRING("Impede baixar stats."),
        .descripcion = COMPOUND_STRING("Impide bajar stats."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_NATURAL_CURE] =
    {
        .name = _("Natural Cure"),
        .nome = _("Cura Natural"),
        .nombre = _("Cura Natural"),
        .description = COMPOUND_STRING("Heals upon switching out."),
        .descricao = COMPOUND_STRING("Cura ao sair de campo."),
        .descripcion = COMPOUND_STRING("Se cura al salir."),
        .aiRating = 7,
    },

    [ABILITY_LIGHTNING_ROD] =
    {
        .name = _("Lightning Rod"),
        .nome = _("Para-Raios"),
        .nombre = _("Pararrayos"),
        .description = COMPOUND_STRING("Draws electrical moves."),
        .descricao = COMPOUND_STRING("Atrai golpes Eletricos."),
        .descripcion = COMPOUND_STRING("Atrae golpes Electricos."),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_SERENE_GRACE] =
    {
        .name = _("Serene Grace"),
        .nome = _("Graça Serena"),
        .nombre = _("Dicha"),
        .description = COMPOUND_STRING("Promotes added effects."),
        .descricao = COMPOUND_STRING("Favorece efeitos extras."),
        .descripcion = COMPOUND_STRING("Favorece efectos extra."),
        .aiRating = 8,
    },

    [ABILITY_SWIFT_SWIM] =
    {
        .name = _("Swift Swim"),
        .nome = _("Nado Rápido"),
        .nombre = _("Nado Rápido"),
        .description = COMPOUND_STRING("Raises Speed in rain."),
        .descricao = COMPOUND_STRING("Aumenta Velocidade na chuva."),
        .descripcion = COMPOUND_STRING("Sube Velocidad con lluvia."),
        .aiRating = 6,
    },

    [ABILITY_CHLOROPHYLL] =
    {
        .name = _("Chlorophyll"),
        .nome = _("Clorofila"),
        .nombre = _("Clorofila"),
        .description = COMPOUND_STRING("Raises Speed in sunshine."),
        .descricao = COMPOUND_STRING("Aumenta Velocidade no sol"),
        .descripcion = COMPOUND_STRING("Sube Velocidad en el sol"),
        .aiRating = 6,
    },

    [ABILITY_ILLUMINATE] =
    {
        .name = _("Illuminate"),
        .nome = _("Iluminação"),
        .nombre = _("Iluminación"),
        .description = COMPOUND_STRING("Encounter rate increases."),
        .descricao = COMPOUND_STRING("Aumenta taxa de encontros."),
        .descripcion = COMPOUND_STRING("Aumenta tasa de encuentros."),
        .aiRating = 0,
        .breakable = TRUE,
    },

    [ABILITY_TRACE] =
    {
        .name = _("Trace"),
        .nome = _("Traçar"),
        .nombre = _("Rastro"),
        .description = COMPOUND_STRING("Copies special ability."),
        .descricao = COMPOUND_STRING("Copia habilidade especial"),
        .descripcion = COMPOUND_STRING("Copia ability especial"),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeTraced = TRUE, //B_UPDATED_ABILITY_DATA >= GEN_4
    },

    [ABILITY_HUGE_POWER] =
    {
        .name = _("Huge Power"),
        .nome = _("Poderzão"),
        .nombre = _("Potencia"),
        .description = COMPOUND_STRING("Raises Attack."),
        .descricao = COMPOUND_STRING("Aumenta Ataque."),
        .descripcion = COMPOUND_STRING("Sube Ataque."),
        .aiRating = 10,
    },

    [ABILITY_POISON_POINT] =
    {
        .name = _("Poison Point"),
        .nome = _("Ponto de Veneno"),
        .nombre = _("Punto Tóxico"),
        .description = COMPOUND_STRING("Poisons foe on contact."),
        .descricao = COMPOUND_STRING("Envenena oponente no contato."),
        .descripcion = COMPOUND_STRING("Envenena al oponente al contacto."),
        .aiRating = 4,
    },

    [ABILITY_INNER_FOCUS] =
    {
        .name = _("Inner Focus"),
        .nome = _("Força Interior"),
        .nombre = _("Foco Interno"),
        .description = COMPOUND_STRING("Prevents flinching."),
        .descricao = COMPOUND_STRING("Impede recuo."),
        .descripcion = COMPOUND_STRING("Impide reculo."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_MAGMA_ARMOR] =
    {
        .name = _("Magma Armor"),
        .nome = _("Armadura Magma"),
        .nombre = _("Escudo Magma"),
        .description = COMPOUND_STRING("Prevents freezing."),
        .descricao = COMPOUND_STRING("Impede congelamento."),
        .descripcion = COMPOUND_STRING("Impide congelación."),
        .aiRating = 1,
        .breakable = TRUE,
    },

    [ABILITY_WATER_VEIL] =
    {
        .name = _("Water Veil"),
        .nome = _("Véu de Água"),
        .nombre = _("Velo Agua"),
        .description = COMPOUND_STRING("Prevents burns."),
        .descricao = COMPOUND_STRING("Impede queimaduras."),
        .descripcion = COMPOUND_STRING("Impide quemaduras."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_MAGNET_PULL] =
    {
        .name = _("Magnet Pull"),
        .nome = _("Magnetismo"),
        .nombre = _("Imán"),
        .description = COMPOUND_STRING("Traps Steel-type Pokémon."),
        .descricao = COMPOUND_STRING("Prende Pokémon de tipo Aço."),
        .descripcion = COMPOUND_STRING("Prende Pokémon de tipo Acero."),
        .aiRating = 9,
    },

    [ABILITY_SOUNDPROOF] =
    {
        .name = _("Soundproof"),
        .nome = _("Antirruído"),
        .nombre = _("Insonorizar"),
        .description = COMPOUND_STRING("Avoids sound-based moves."),
        .descricao = COMPOUND_STRING("Evita golpes sonoros."),
        .descripcion = COMPOUND_STRING("Evita golpes sonoros."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_RAIN_DISH] =
    {
        .name = _("Rain Dish"),
        .nome = _("Prato de Chuva"),
        .nombre = _("Cura Lluvia"),
        .description = COMPOUND_STRING("Slight HP recovery in rain."),
        .descricao = COMPOUND_STRING("Recupera um pouco de HP na chuva."),
        .descripcion = COMPOUND_STRING("Recupera algo de PS con lluvia."),
        .aiRating = 3,
    },

    [ABILITY_SAND_STREAM] =
    {
        .name = _("Sand Stream"),
        .nome = _("Fluxo de Areia"),
        .nombre = _("Chorro Arena"),
        .description = COMPOUND_STRING("Summons a sandstorm."),
        .descricao = COMPOUND_STRING("Invoca uma tempestade areia."),
        .descripcion = COMPOUND_STRING("Invoca tormenta de arena."),
        .aiRating = 9,
    },

    [ABILITY_PRESSURE] =
    {
        .name = _("Pressure"),
        .nome = _("Pressão"),
        .nombre = _("Presión"),
        .description = COMPOUND_STRING("Raises foe's PP usage."),
        .descricao = COMPOUND_STRING("Aumenta consumo de PP do inimigo."),
        .descripcion = COMPOUND_STRING("Aumenta consumo de PP del rival."),
        .aiRating = 5,
    },

    [ABILITY_THICK_FAT] =
    {
        .name = _("Thick Fat"),
        .nome = _("Gordura Espessa"),
        .nombre = _("Sebo"),
        .description = COMPOUND_STRING("Heat-and-cold protection."),
        .descricao = COMPOUND_STRING("Protege contra calor e frio."),
        .descripcion = COMPOUND_STRING("Protege contra calor y frio."),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_EARLY_BIRD] =
    {
        .name = _("Early Bird"),
        .nome = _("Madrugar"),
        .nombre = _("Madrugar"),
        .description = COMPOUND_STRING("Awakens quickly from sleep."),
        .descricao = COMPOUND_STRING("Acorda mais rápido do sono."),
        .descripcion = COMPOUND_STRING("Despierta más rápido del sueño."),
        .aiRating = 4,
    },

    [ABILITY_FLAME_BODY] =
    {
        .name = _("Flame Body"),
        .nome = _("Corpo Flamejante"),
        .nombre = _("Cuerpo Llama"),
        .description = COMPOUND_STRING("Burns the foe on contact."),
        .descricao = COMPOUND_STRING("Queima o oponente no contato."),
        .descripcion = COMPOUND_STRING("Quema al oponente al contacto."),
        .aiRating = 4,
    },

    [ABILITY_RUN_AWAY] =
    {
        .name = _("Run Away"),
        .nome = _("Fuga"),
        .nombre = _("Fuga"),
        .description = COMPOUND_STRING("Makes escaping easier."),
        .descricao = COMPOUND_STRING("Facilita a fuga."),
        .descripcion = COMPOUND_STRING("Facilita la huida."),
        .aiRating = 0,
    },

    [ABILITY_KEEN_EYE] =
    {
        .name = _("Keen Eye"),
        .nome = _("Olhar Aguçado"),
        .nombre = _("Vista Lince"),
        .description = COMPOUND_STRING("Prevents loss of accuracy."),
        .descricao = COMPOUND_STRING("Impede a perca de precisao."),
        .descripcion = COMPOUND_STRING("Impide la pérdida de precisión."),
        .aiRating = 1,
        .breakable = TRUE,
    },

    [ABILITY_HYPER_CUTTER] =
    {
        .name = _("Hyper Cutter"),
        .nome = _("Hipercorte"),
        .nombre = _("Corte Fuerte"),
        .description = COMPOUND_STRING("Prevents Attack reduction."),
        .descricao = COMPOUND_STRING("Impede a redução de Atq."),
        .descripcion = COMPOUND_STRING("Impide la reducción de Atq."),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_PICKUP] =
    {
        .name = _("Pickup"),
        .nome = _("Pegar"),
        .nombre = _("Recogida"),
        .description = COMPOUND_STRING("May pick up items."),
        .descricao = COMPOUND_STRING("Pode pegar itens."),
        .descripcion = COMPOUND_STRING("Puede recoger objetos."),
        .aiRating = 1,
    },

    [ABILITY_TRUANT] =
    {
        .name = _("Truant"),
        .nome = _("Preguiça"),
        .nombre = _("Ausente"),
        .description = COMPOUND_STRING("Moves only every two turns."),
        .descricao = COMPOUND_STRING("Ataca apenas a cada dois turnos."),
        .descripcion = COMPOUND_STRING("Ataca solo cada dos turnos."),
        .aiRating = -2,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_HUSTLE] =
    {
        .name = _("Hustle"),
        .nome = _("Entusiasmo"),
        .nombre = _("Entusiasmo"),
        .description = COMPOUND_STRING("Trades accuracy for power."),
        .descricao = COMPOUND_STRING("Troca precisão por poder."),
        .descripcion = COMPOUND_STRING("Cambia precisión por poder."),
        .aiRating = 7,
    },

    [ABILITY_CUTE_CHARM] =
    {
        .name = _("Cute Charm"),
        .nome = _("Charme Fofo"),
        .nombre = _("Gran Encanto"),
        .description = COMPOUND_STRING("Infatuates on contact."),
        .descricao = COMPOUND_STRING("Apaixona ao contato."),
        .descripcion = COMPOUND_STRING("Enamora al contacto."),
        .aiRating = 2,
    },

    [ABILITY_PLUS] =
    {
        .name = _("Plus"),
        .nome = _("Mais"),
        .nombre = _("Más"),
        .description = COMPOUND_STRING("Powers up with Minus."),
        .descricao = COMPOUND_STRING("Fortalece com Minus."),
        .descripcion = COMPOUND_STRING("Fortalece con Minus."),
        .aiRating = 0,
    },

    [ABILITY_MINUS] =
    {
        .name = _("Minus"),
        .nome = _("Menos"),
        .nombre = _("Menos"),
        .description = COMPOUND_STRING("Powers up with Plus."),
        .descricao = COMPOUND_STRING("Fortalece com Plus."),
        .descripcion = COMPOUND_STRING("Fortalece con Plus."),
        .aiRating = 0,
    },

    [ABILITY_FORECAST] =
    {
        .name = _("Forecast"),
        .nome = _("Aclimatação"),
        .nombre = _("Predicción"),
        .description = COMPOUND_STRING("Changes with the weather."),
        .descricao = COMPOUND_STRING("Muda com o clima"),
        .descripcion = COMPOUND_STRING("Cambia con el clima"),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeTraced = B_UPDATED_ABILITY_DATA >= GEN_4,
        .failsOnImposter = B_UPDATED_ABILITY_DATA >= GEN_5,
    },

    [ABILITY_STICKY_HOLD] =
    {
        .name = _("Sticky Hold"),
        .nome = _("Viscosidade"),
        .nombre = _("Viscosidad"),
        .description = COMPOUND_STRING("Prevents item theft."),
        .descricao = COMPOUND_STRING("Previne roubo de item."),
        .descripcion = COMPOUND_STRING("Previene robo de objetos."),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_SHED_SKIN] =
    {
        .name = _("Shed Skin"),
        .nome = _("Pele Vertente"),
        .nombre = _("Mudar"),
        .description = COMPOUND_STRING("Heals the body by shedding."),
        .descricao = COMPOUND_STRING("Cura-se ao trocar de pele."),
        .descripcion = COMPOUND_STRING("Se cura al mudar de piel."),
        .aiRating = 7,
    },

    [ABILITY_GUTS] =
    {
        .name = _("Guts"),
        .nome = _("Tenacidade"),
        .nombre = _("Agallas"),
        .description = COMPOUND_STRING("Ups Attack if suffering."),
        .descricao = COMPOUND_STRING("Aum. Atq. se estiver sofrendo."),
        .descripcion = COMPOUND_STRING("Sube Atq. si está sufriendo."),
        .aiRating = 6,
    },

    [ABILITY_MARVEL_SCALE] =
    {
        .name = _("Marvel Scale"),
        .nome = _("Escama Especial"),
        .nombre = _("Escama Especial"),
        .description = COMPOUND_STRING("Ups Defense if suffering."),
        .descricao = COMPOUND_STRING("Aum. Def. se estiver sofrendo."),
        .descripcion = COMPOUND_STRING("Sube Def. si está sufriendo."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_LIQUID_OOZE] =
    {
        .name = _("Liquid Ooze"),
        .nome = _("Lodo Líquido"),
        .nombre = _("Lodo Líquido"),
        .description = COMPOUND_STRING("Draining causes injury."),
        .descricao = COMPOUND_STRING("Absorção causa ferimentos."),
        .descripcion = COMPOUND_STRING("La absorción causa daño."),
        .aiRating = 3,
    },

    [ABILITY_OVERGROW] =
    {
        .name = _("Overgrow"),
        .nome = _("Supercrescimento"),
        .nombre = _("Espesura"),
        .description = COMPOUND_STRING("Ups Grass moves in a pinch."),
        .descricao = COMPOUND_STRING("Aumenta golpes Grama em aperto."),
        .descripcion = COMPOUND_STRING("Sube golpes Planta en apuros."),
        .aiRating = 5,
    },

    [ABILITY_BLAZE] =
    {
        .name = _("Blaze"),
        .nome = _("Incêndio"),
        .nombre = _("Mar Llamas"),
        .description = COMPOUND_STRING("Ups Fire moves in a pinch."),
        .descricao = COMPOUND_STRING("Aumenta golpes Fogo em aperto."),
        .descripcion = COMPOUND_STRING("Sube golpes Fuego en apuros."),
        .aiRating = 5,
    },

    [ABILITY_TORRENT] =
    {
        .name = _("Torrent"),
        .nome = _("Dilúvio"),
        .nombre = _("Torrente"),
        .description = COMPOUND_STRING("Ups Water moves in a pinch."),
        .descricao = COMPOUND_STRING("Aumenta golpes Água em aperto."),
        .descripcion = COMPOUND_STRING("Sube golpes Agua en apuros."),
        .aiRating = 5,
    },

    [ABILITY_SWARM] =
    {
        .name = _("Swarm"),
        .nome = _("Enxame"),
        .nombre = _("Enjambre"),
        .description = COMPOUND_STRING("Ups Bug moves in a pinch."),
        .descricao = COMPOUND_STRING("Aumenta golpes Inseto em aperto."),
        .descripcion = COMPOUND_STRING("Sube golpes Bicho en apuros."),
        .aiRating = 5,
    },

    [ABILITY_ROCK_HEAD] =
    {
        .name = _("Rock Head"),
        .nome = _("Cabeça de Pedra"),
        .nombre = _("Cabeza Roca"),
        .description = COMPOUND_STRING("Prevents recoil damage."),
        .descricao = COMPOUND_STRING("Previne dano de recuo."),
        .descripcion = COMPOUND_STRING("Previene daño de retroceso."),
        .aiRating = 5,
    },

    [ABILITY_DROUGHT] =
    {
        .name = _("Drought"),
        .nome = _("Seca"),
        .nombre = _("Sequía"),
        .description = COMPOUND_STRING("Summons sunlight in battle."),
        .descricao = COMPOUND_STRING("Invoca luz solar na batalha."),
        .descripcion = COMPOUND_STRING("Invoca luz solar en batalla."),
        .aiRating = 9,
    },

    [ABILITY_ARENA_TRAP] =
    {
        .name = _("Arena Trap"),
        .nome = _("Armadilharia"),
        .nombre = _("Trampa Arena"),
        .description = COMPOUND_STRING("Prevents fleeing."),
        .descricao = COMPOUND_STRING("Impede fuga."),
        .descripcion = COMPOUND_STRING("Impide huida."),
        .aiRating = 9,
    },

    [ABILITY_VITAL_SPIRIT] =
    {
        .name = _("Vital Spirit"),
        .nome = _("Espírito Vital"),
        .nombre = _("Espíritu Vital"),
        .description = COMPOUND_STRING("Prevents sleep."),
        .descricao = COMPOUND_STRING("Impede sono."),
        .descripcion = COMPOUND_STRING("Impide dormir."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_WHITE_SMOKE] =
    {
        .name = _("White Smoke"),
        .nome = _("Fumaça Branca"),
        .nombre = _("Humo Blanco"),
        .description = COMPOUND_STRING("Prevents ability reduction."),
        .descricao = COMPOUND_STRING("Impede baixar stats."),
        .descripcion = COMPOUND_STRING("Impide bajar stats."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_PURE_POWER] =
    {
        .name = _("Pure Power"),
        .nome = _("Poder Puro"),
        .nombre = _("Energía Pura"),
        .description = COMPOUND_STRING("Raises Attack."),
        .descricao = COMPOUND_STRING("Aumenta Atq."),
        .descripcion = COMPOUND_STRING("Sube Atq."),
        .aiRating = 10,
    },

    [ABILITY_SHELL_ARMOR] =
    {
        .name = _("Shell Armor"),
        .nome = _("Armadura Concha"),
        .nombre = _("Caparazón"),
        .description = COMPOUND_STRING("Blocks critical hits."),
        .descricao = COMPOUND_STRING("Bloqueia golpes criticos."),
        .descripcion = COMPOUND_STRING("Bloquea golpes criticos."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_AIR_LOCK] =
    {
        .name = _("Air Lock"),
        .nome = _("Bloqueio Aéreo"),
        .nombre = _("Bucle Aire"),
        .description = COMPOUND_STRING("Negates weather effects."),
        .descricao = COMPOUND_STRING("Nega efeitos do clima."),
        .descripcion = COMPOUND_STRING("Niega efectos del clima."),
        .aiRating = 5,
    },

    [ABILITY_TANGLED_FEET] =
    {
        .name = _("Tangled Feet"),
        .nome = _("Pés Laçados"),
        .nombre = _("Tumbos"),
        .description = COMPOUND_STRING("Ups evasion if confused."),
        .descricao = COMPOUND_STRING("Aumenta evasão se confuso."),
        .descripcion = COMPOUND_STRING("Sube evasión si está confuso."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_MOTOR_DRIVE] =
    {
        .name = _("Motor Drive"),
        .nome = _("Impulso Motor"),
        .nombre = _("Electromotor"),
        .description = COMPOUND_STRING("Electricity raises Speed."),
        .descricao = COMPOUND_STRING("Eletricidade aumenta Vel."),
        .descripcion = COMPOUND_STRING("Electricidad aumenta Vel."),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_RIVALRY] =
    {
        .name = _("Rivalry"),
        .nome = _("Rivalidade"),
        .nombre = _("Rivalidad"),
        .description = COMPOUND_STRING("Powers up against rivals."),
        .descricao = COMPOUND_STRING("Aumenta poder contra rivais."),
        .descripcion = COMPOUND_STRING("Aumenta poder contra rivales."),
        .aiRating = 1,
    },

    [ABILITY_STEADFAST] =
    {
        .name = _("Steadfast"),
        .nome = _("Inabalável"),
        .nombre = _("Impasible"),
        .description = COMPOUND_STRING("Flinching raises Speed."),
        .descricao = COMPOUND_STRING("Ao recuar, aumenta a Velocidade."),
        .descripcion = COMPOUND_STRING("Al recular, aumenta la Velocidad."),
        .aiRating = 2,
    },

    [ABILITY_SNOW_CLOAK] =
    {
        .name = _("Snow Cloak"),
        .nome = _("Manto Nevado"),
        .nombre = _("Manto Níveo"),
        .description = COMPOUND_STRING("Ups evasion in Hail or Snow."),
        .descricao = COMPOUND_STRING("Aumenta evasão na neve/granizo."),
        .descripcion = COMPOUND_STRING("Sube evasión con granizo/nieve."),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_GLUTTONY] =
    {
        .name = _("Gluttony"),
        .nome = _("Gula"),
        .nombre = _("Gula"),
        .description = COMPOUND_STRING("Eats Berries early."),
        .descricao = COMPOUND_STRING("Come Berries mais cedo."),
        .descripcion = COMPOUND_STRING("Come Berries más temprano."),
        .aiRating = 3,
    },

    [ABILITY_ANGER_POINT] =
    {
        .name = _("Anger Point"),
        .nome = _("Ponto de Fúria"),
        .nombre = _("Irascible"),
        .description = COMPOUND_STRING("Critical hits raise Attack."),
        .descricao = COMPOUND_STRING("Golpes críticos aumentam o Atq."),
        .descripcion = COMPOUND_STRING("Golpes críticos aumentan el Atq."),
        .aiRating = 4,
    },

    [ABILITY_UNBURDEN] =
    {
        .name = _("Unburden"),
        .nome = _("Alígero"),
        .nombre = _("Liviano"),
        .description = COMPOUND_STRING("Using a hold item ups Speed."),
        .descricao = COMPOUND_STRING("Dobra a Speed se perder o item."),
        .descripcion = COMPOUND_STRING("Duplica la Vel. con objeto."),
        .aiRating = 7,
    },

    [ABILITY_HEATPROOF] =
    {
        .name = _("Heatproof"),
        .nome = _("Ignífugo"),
        .nombre = _("Ignífugo"),
        .description = COMPOUND_STRING("Heat and burn protection."),
        .descricao = COMPOUND_STRING("Proteção contra calor."),
        .descripcion = COMPOUND_STRING("Protección contra el calor."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_SIMPLE] =
    {
        .name = _("Simple"),
        .nome = _("Simplificar"),
        .nombre = _("Simple"),
        .description = COMPOUND_STRING("Prone to wild stat changes."),
        .descricao = COMPOUND_STRING("Dobra as mudanças de estado."),
        .descripcion = COMPOUND_STRING("Dobla los cambios de estado."),
        .aiRating = 8,
        .breakable = TRUE,
    },

    [ABILITY_DRY_SKIN] =
    {
        .name = _("Dry Skin"),
        .nome = _("Pele Seca"),
        .nombre = _("Piel Seca"),
        .description = COMPOUND_STRING("Prefers moisture to heat."),
        .descricao = COMPOUND_STRING("Prefere umidade ao calor."),
        .descripcion = COMPOUND_STRING("Prefiere la humedad al calor."),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_DOWNLOAD] =
    {
        .name = _("Download"),
        .nome = _("Download"),
        .nombre = _("Descarga"),
        .description = COMPOUND_STRING("Adjusts power favorably."),
        .descricao = COMPOUND_STRING("Ajusta o poder favoravelmente."),
        .descripcion = COMPOUND_STRING("Ajusta el poder favorablemente."),
        .aiRating = 7,
    },

    [ABILITY_IRON_FIST] =
    {
        .name = _("Iron Fist"),
        .nome = _("Punho de Ferro"),
        .nombre = _("Puño Férreo"),
        .description = COMPOUND_STRING("Boosts punching moves."),
        .descricao = COMPOUND_STRING("Aumenta golpes de soco."),
        .descripcion = COMPOUND_STRING("Aumenta golpes de puño."),
        .aiRating = 6,
    },

    [ABILITY_POISON_HEAL] =
    {
        .name = _("Poison Heal"),
        .nome = _("Veneno Curador"),
        .nombre = _("Antídoto"),
        .description = COMPOUND_STRING("Restores HP if poisoned."),
        .descricao = COMPOUND_STRING("Restaura HP se envenenado."),
        .descripcion = COMPOUND_STRING("Restaura PS si envenenado."),
        .aiRating = 8,
    },

    [ABILITY_ADAPTABILITY] =
    {
        .name = _("Adaptability"),
        .nome = _("Adaptabilidade"),
        .nombre = _("Adaptable"),
        .description = COMPOUND_STRING("Boosts same type attacks."),
        .descricao = COMPOUND_STRING("Impulsiona ataques do mesmo tipo."),
        .descripcion = COMPOUND_STRING("Impulsiona ataques do mesmo tipo."),
        .aiRating = 8,
    },

    [ABILITY_SKILL_LINK] =
    {
        .name = _("Skill Link"),
        .nome = _("Encadeado"),
        .nombre = _("Encadenado"),
        .description = COMPOUND_STRING("Multi-hit moves hit 5 times."),
        .descricao = COMPOUND_STRING("Golpes Multi-hit acertam 5 vezes."),
        .descripcion = COMPOUND_STRING("Golpes Multi-hit acertan 5 veces."),
        .aiRating = 7,
    },

    [ABILITY_HYDRATION] =
    {
        .name = _("Hydration"),
        .nome = _("Hidratação"),
        .nombre = _("Hidratación"),
        .description = COMPOUND_STRING("Cures status in rain."),
        .descricao = COMPOUND_STRING("Cura estado na chuva."),
        .descripcion = COMPOUND_STRING("Cura estado con lluvia."),
        .aiRating = 4,
    },

    [ABILITY_SOLAR_POWER] =
    {
        .name = _("Solar Power"),
        .nome = _("Poder Solar"),
        .nombre = _("Poder Solar"),
        .description = COMPOUND_STRING("Powers up in sunshine."),
        .descricao = COMPOUND_STRING("Troca HP por poder na luz do sol."),
        .descripcion = COMPOUND_STRING("Cambia PS por poder con luz solar."),
        .aiRating = 3,
    },

    [ABILITY_QUICK_FEET] =
    {
        .name = _("Quick Feet"),
        .nome = _("Pés Rápidos"),
        .nombre = _("Pies Rápidos"),
        .description = COMPOUND_STRING("Ups Speed if suffering."),
        .descricao = COMPOUND_STRING("Aum. Vel. se estiver sofrendo."),
        .descripcion = COMPOUND_STRING("Sube Vel. si está sufriendo."),
        .aiRating = 5,
    },

    [ABILITY_NORMALIZE] =
    {
        .name = _("Normalize"),
        .nome = _("Normalidade"),
        .nombre = _("Normalidad"),
        .description = COMPOUND_STRING("Moves become Normal-type."),
        .descricao = COMPOUND_STRING("Golpes se tornam tipo Normal."),
        .descripcion = COMPOUND_STRING("Golpes se tornam tipo Normal."),
        .aiRating = -1,
    },

    [ABILITY_SNIPER] =
    {
        .name = _("Sniper"),
        .nome = _("Franco-Atirador"),
        .nombre = _("Francotirador"),
        .description = COMPOUND_STRING("Boosts critical hits."),
        .descricao = COMPOUND_STRING("Impulsiona golpes criticos."),
        .descripcion = COMPOUND_STRING("Impulsiona golpes criticos."),
        .aiRating = 3,
    },

    [ABILITY_MAGIC_GUARD] =
    {
        .name = _("Magic Guard"),
        .nome = _("Escudo Mágico"),
        .nombre = _("Muro Mágico"),
        .description = COMPOUND_STRING("Only damaged by attacks."),
        .descricao = COMPOUND_STRING("Só sofre dano de ataques."),
        .descripcion = COMPOUND_STRING("Sólo sufre daño de ataques."),
        .aiRating = 9,
    },

    [ABILITY_NO_GUARD] =
    {
        .name = _("No Guard"),
        .nome = _("Indefeso"),
        .nombre = _("Indefenso"),
        .description = COMPOUND_STRING("Ensures that all moves hit."),
        .descricao = COMPOUND_STRING("Garante que todo golpe atinja."),
        .descripcion = COMPOUND_STRING("Asegura que todo golpe atinja."),
        .aiRating = 8,
    },

    [ABILITY_STALL] =
    {
        .name = _("Stall"),
        .nome = _("Adiar"),
        .nombre = _("Rezagado"),
        .description = COMPOUND_STRING("Always moves last."),
        .descricao = COMPOUND_STRING("Siempre ataca por último."),
        .descripcion = COMPOUND_STRING("Siempre ataca por último."),
        .aiRating = -1,
    },

    [ABILITY_TECHNICIAN] =
    {
        .name = _("Technician"),
        .nome = _("Técnico"),
        .nombre = _("Experto"),
        .description = COMPOUND_STRING("Boosts weaker moves."),
        .descricao = COMPOUND_STRING("Impulsiona golpes fracos."),
        .descripcion = COMPOUND_STRING("Impulsiona golpes fracos."),
        .aiRating = 8,
    },

    [ABILITY_LEAF_GUARD] =
    {
        .name = _("Leaf Guard"),
        .nome = _("Guarda Folha"),
        .nombre = _("Defensa Hoja"),
        .description = COMPOUND_STRING("Blocks status in sunshine."),
        .descricao = COMPOUND_STRING("Bloqueia estado na luz solar."),
        .descripcion = COMPOUND_STRING("Bloquea estado con luz solar."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_KLUTZ] =
    {
        .name = _("Klutz"),
        .nome = _("Desajeitado"),
        .nombre = _("Zoquete"),
        .description = COMPOUND_STRING("Can't use hold items."),
        .descricao = COMPOUND_STRING("Nao pode segurar itens."),
        .descripcion = COMPOUND_STRING("No puede equipar objetos."),
        .aiRating = -1,
    },

    [ABILITY_MOLD_BREAKER] =
    {
        .name = _("Mold Breaker"),
        .nome = _("Quebra-Molde"),
        .nombre = _("Rompemoldes"),
        .description = COMPOUND_STRING("Moves hit through abilities."),
        .descricao = COMPOUND_STRING("Golpes atravessam habilidades."),
        .descripcion = COMPOUND_STRING("Golpes atraviesan habilidades."),
        .aiRating = 7,
    },

    [ABILITY_SUPER_LUCK] =
    {
        .name = _("Super Luck"),
        .nome = _("Supersorte"),
        .nombre = _("Afortunado"),
        .description = COMPOUND_STRING("Critical hits land often."),
        .descricao = COMPOUND_STRING("Facilita golpes críticos."),
        .descripcion = COMPOUND_STRING("Facilita golpes críticos."),
        .aiRating = 3,
    },

    [ABILITY_AFTERMATH] =
    {
        .name = _("Aftermath"),
        .nome = _("Resultado"),
        .nombre = _("Detonación"),
        .description = COMPOUND_STRING("Fainting damages the foe."),
        .descricao = COMPOUND_STRING("Desmaiar causa dano ao inimigo."),
        .descripcion = COMPOUND_STRING("Desmayar causa daño al rival."),
        .aiRating = 5,
    },

    [ABILITY_ANTICIPATION] =
    {
        .name = _("Anticipation"),
        .nome = _("Antecipação"),
        .nombre = _("Anticipación"),
        .description = COMPOUND_STRING("Senses dangerous moves."),
        .descricao = COMPOUND_STRING("Detecta golpes super-efetivos."),
        .descripcion = COMPOUND_STRING("Detecta golpes super-efectivos."),
        .aiRating = 2,
    },

    [ABILITY_FOREWARN] =
    {
        .name = _("Forewarn"),
        .nome = _("Profecia"),
        .nombre = _("Alerta"),
        .description = COMPOUND_STRING("Determines a foe's move."),
        .descricao = COMPOUND_STRING("Revela o golpe do oponente."),
        .descripcion = COMPOUND_STRING("Define el golpe del rival."),
        .aiRating = 2,
    },

    [ABILITY_UNAWARE] =
    {
        .name = _("Unaware"),
        .nome = _("Ignorância"),
        .nombre = _("Ignorante"),
        .description = COMPOUND_STRING("Ignores stat changes."),
        .descricao = COMPOUND_STRING("Ignora mudanças de stats."),
        .descripcion = COMPOUND_STRING("Ignora cambios de stats."),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_TINTED_LENS] =
    {
        .name = _("Tinted Lens"),
        .nome = _("Lentes Tingidas"),
        .nombre = _("Cromolente"),
        .description = COMPOUND_STRING("Ups “not very effective”."),
        .descricao = COMPOUND_STRING("Aumenta golpes “pouco efetivos”."),
        .descripcion = COMPOUND_STRING("Aumenta golpes “poco efectivos”."),
        .aiRating = 7,
    },

    [ABILITY_FILTER] =
    {
        .name = _("Filter"),
        .nome = _("Filtro"),
        .nombre = _("Filtro"),
        .description = COMPOUND_STRING("Weakens “supereffective”."),
        .descricao = COMPOUND_STRING("Enfraquece “super efetivos”."),
        .descripcion = COMPOUND_STRING("Enfraquece “super efectivos”."),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_SLOW_START] =
    {
        .name = _("Slow Start"),
        .nome = _("Começo Lento"),
        .nombre = _("Inicio Lento"),
        .description = COMPOUND_STRING("Takes a while to get going."),
        .descricao = COMPOUND_STRING("Demora um pouco para engrenar."),
        .descripcion = COMPOUND_STRING("Demora un poco para engranar."),
        .aiRating = -2,
    },

    [ABILITY_SCRAPPY] =
    {
        .name = _("Scrappy"),
        .nome = _("Intrépido"),
        .nombre = _("Intrépido"),
        .description = COMPOUND_STRING("Hits Ghost-type Pokémon."),
        .descricao = COMPOUND_STRING("Golpes atingirem Tipo Fantasma."),
        .descripcion = COMPOUND_STRING("Golpes atingirem Tipo Fantasma."),
        .aiRating = 6,
    },

    [ABILITY_STORM_DRAIN] =
    {
        .name = _("Storm Drain"),
        .nome = _("Drenagem"),
        .nombre = _("Colector"),
        .description = COMPOUND_STRING("Draws in Water moves."),
        .descricao = COMPOUND_STRING("Atrai água para subir o Sp. Atk."),
        .descripcion = COMPOUND_STRING("Atrae agua para subir el Sp. Atq."),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_ICE_BODY] =
    {
        .name = _("Ice Body"),
        .nome = _("Corpo Gélido"),
        .nombre = _("Gélido"),
        .description = COMPOUND_STRING("HP recovery in Hail or Snow."),
        .descricao = COMPOUND_STRING("Recupera HP no granizo/neve."),
        .descripcion = COMPOUND_STRING("Recupera PS con granizo/nieve."),
        .aiRating = 3,
    },

    [ABILITY_SOLID_ROCK] =
    {
        .name = _("Solid Rock"),
        .nome = _("Rocha Sólida"),
        .nombre = _("Roca Sólida"),
        .description = COMPOUND_STRING("Weakens “supereffective”."),
        .descricao = COMPOUND_STRING("Enfraquece “super efetivos”."),
        .descripcion = COMPOUND_STRING("Enfraquece “super efectivos”."),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_SNOW_WARNING] =
    {
        .name = _("Snow Warning"),
        .nome = _("Alerta de Neve"),
        .nombre = _("Nevada"),
    #if B_SNOW_WARNING >= GEN_9
        .description = COMPOUND_STRING("Summons snow in battle."),
        .descricao = COMPOUND_STRING("Invoca neve na batalha."),
        .descripcion = COMPOUND_STRING("Invoca nieve en batalla."),
    #else
        .description = COMPOUND_STRING("Summons hail in battle."),
    #endif
        .aiRating = 8,
    },

    [ABILITY_HONEY_GATHER] =
    {
        .name = _("Honey Gather"),
        .nome = _("Pegar Mel"),
        .nombre = _("Recogemiel"),
        .description = COMPOUND_STRING("May gather Honey."),
        .descricao = COMPOUND_STRING("Pode pegar Mel."),
        .descripcion = COMPOUND_STRING("Puede recoger Miel."),
        .aiRating = 0,
    },

    [ABILITY_FRISK] =
    {
        .name = _("Frisk"),
        .nome = _("Bisbilhotar"),
        .nombre = _("Cacheo"),
        .description = COMPOUND_STRING("Checks a foe's item."),
        .descricao = COMPOUND_STRING("Revela o item do oponente."),
        .descripcion = COMPOUND_STRING("Ve el item del rival."),
        .aiRating = 3,
    },

    [ABILITY_RECKLESS] =
    {
        .name = _("Reckless"),
        .nome = _("Imprudência"),
        .nombre = _("Audaz"),
        .description = COMPOUND_STRING("Boosts moves with recoil."),
        .descricao = COMPOUND_STRING("Impulsiona golpes com recuo."),
        .descripcion = COMPOUND_STRING("Impulsiona golpes con reculo."),
        .aiRating = 6,
    },

    [ABILITY_MULTITYPE] =
    {
        .name = _("Multitype"),
        .nome = _("Multitipo"),
        .nombre = _("Multitipo"),
        .description = COMPOUND_STRING("Changes type to its Plate."),
        .descricao = COMPOUND_STRING("Tipo muda com a Placa."),
        .descripcion = COMPOUND_STRING("Tipo cambia con la Placa."),
        .aiRating = 8,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = B_UPDATED_ABILITY_DATA >= GEN_5,
    },

    [ABILITY_FLOWER_GIFT] =
    {
        .name = _("Flower Gift"),
        .nome = _("Presente Floral"),
        .nombre = _("Don Floral"),
        .description = COMPOUND_STRING("Allies power up in sunshine."),
        .descricao = COMPOUND_STRING("Aliados se fortalecem no sol."),
        .descripcion = COMPOUND_STRING("Aliados se fortalecen con sol."),
        .aiRating = 4,
        .cantBeCopied = TRUE,
        .cantBeTraced = B_UPDATED_ABILITY_DATA >= GEN_5,
        .breakable = TRUE,
    },

    [ABILITY_BAD_DREAMS] =
    {
        .name = _("Bad Dreams"),
        .nome = _("Pesadelos"),
        .nombre = _("Mal Sueño"),
        .description = COMPOUND_STRING("Damages sleeping Pokémon."),
        .descricao = COMPOUND_STRING("Machuca Pokémon sonolentos."),
        .descripcion = COMPOUND_STRING("Daña a Pokémon dormidos."),
        .aiRating = 4,
    },

    [ABILITY_PICKPOCKET] =
    {
        .name = _("Pickpocket"),
        .nome = _("Furto"),
        .nombre = _("Hurto"),
        .description = COMPOUND_STRING("Steals the foe's held item."),
        .descricao = COMPOUND_STRING("Rouba o item do oponente."),
        .descripcion = COMPOUND_STRING("Roba el item del rival."),
        .aiRating = 3,
    },

    [ABILITY_SHEER_FORCE] =
    {
        .name = _("Sheer Force"),
        .nome = _("Força Absoluta"),
        .nombre = _("Potencia Bruta"),
        .description = COMPOUND_STRING("Trades effects for power."),
        .descricao = COMPOUND_STRING("Troca efeitos por poder."),
        .descripcion = COMPOUND_STRING("Cambia efectos por poder."),
        .aiRating = 8,
    },

    [ABILITY_CONTRARY] =
    {
        .name = _("Contrary"),
        .nome = _("Contrário"),
        .nombre = _("Respondón"),
        .description = COMPOUND_STRING("Inverts stat changes."),
        .descricao = COMPOUND_STRING("Inverte mudanças de estado."),
        .descripcion = COMPOUND_STRING("Invierte cambios de estado."),
        .aiRating = 8,
        .breakable = TRUE,
    },

    [ABILITY_UNNERVE] =
    {
        .name = _("Unnerve"),
        .nome = _("Enervar"),
        .nombre = _("Nerviosismo"),
        .description = COMPOUND_STRING("Foes can't eat Berries."),
        .descricao = COMPOUND_STRING("Oponentes não podem comer bagas."),
        .descripcion = COMPOUND_STRING("Rivales no pueden comer bayas."),
        .aiRating = 3,
    },

    [ABILITY_DEFIANT] =
    {
        .name = _("Defiant"),
        .nome = _("Desafiador"),
        .nombre = _("Competitivo"),
        .description = COMPOUND_STRING("Lowered stats up Attack."),
        .descricao = COMPOUND_STRING("Stats baixados aumentam Atq."),
        .descripcion = COMPOUND_STRING("Stats bajados aumentan Atq."),
        .aiRating = 5,
    },

    [ABILITY_DEFEATIST] =
    {
        .name = _("Defeatist"),
        .nome = _("Derrotista"),
        .nombre = _("Flaqueza"),
        .description = COMPOUND_STRING("Gives up at half HP."),
        .descricao = COMPOUND_STRING("Desiste com o HP pela metade."),
        .descripcion = COMPOUND_STRING("Se rinde con el PS a la mitad."),
        .aiRating = -1,
    },

    [ABILITY_CURSED_BODY] =
    {
        .name = _("Cursed Body"),
        .nome = _("Corpo Maldito"),
        .nombre = _("Cuerpo Maldito"),
        .description = COMPOUND_STRING("Disables moves on contact."),
        .descricao = COMPOUND_STRING("Desativa golpes ao contato."),
        .descripcion = COMPOUND_STRING("Desactiva golpes al contacto."),
        .aiRating = 4,
    },

    [ABILITY_HEALER] =
    {
        .name = _("Healer"),
        .nome = _("Cura"),
        .nombre = _("Alma Cura"),
        .description = COMPOUND_STRING("Heals partner Pokémon."),
        .descricao = COMPOUND_STRING("Cura Pokémon parceiro."),
        .descripcion = COMPOUND_STRING("Cura Pokémon compañero."),
        .aiRating = 0,
    },

    [ABILITY_FRIEND_GUARD] =
    {
        .name = _("Friend Guard"),
        .nome = _("Proteção Amiga"),
        .nombre = _("Compiescolta"),
        .description = COMPOUND_STRING("Lowers damage to partner."),
        .descricao = COMPOUND_STRING("Baixa dano ao parceiro."),
        .descripcion = COMPOUND_STRING("Baja daño al compañero."),
        .aiRating = 0,
        .breakable = TRUE,
    },

    [ABILITY_WEAK_ARMOR] =
    {
        .name = _("Weak Armor"),
        .nome = _("Armadura Frágil"),
        .nombre = _("Armadura Frágil"),
        .description = COMPOUND_STRING("Its stats change when hit."),
        .descricao = COMPOUND_STRING("Seus stats mudam quando atingido."),
        .descripcion = COMPOUND_STRING("Sus stats cambian si golpeado."),
        .aiRating = 2,
    },

    [ABILITY_HEAVY_METAL] =
    {
        .name = _("Heavy Metal"),
        .nome = _("Metal Pesado"),
        .nombre = _("Metal Pesado"),
        .description = COMPOUND_STRING("Doubles weight."),
        .descricao = COMPOUND_STRING("Dobra o peso."),
        .descripcion = COMPOUND_STRING("Dobra el peso."),
        .aiRating = -1,
        .breakable = TRUE,
    },

    [ABILITY_LIGHT_METAL] =
    {
        .name = _("Light Metal"),
        .nome = _("Metal Leve"),
        .nombre = _("Metal Liviano"),
        .description = COMPOUND_STRING("Halves weight."),
        .descricao = COMPOUND_STRING("Diminui peso pela metade."),
        .descripcion = COMPOUND_STRING("Disminuye peso a la mitad."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_MULTISCALE] =
    {
        .name = _("Multiscale"),
        .nome = _("Multiescamas"),
        .nombre = _("Multiescamas"),
        .description = COMPOUND_STRING("Halves damage at full HP."),
        .descricao = COMPOUND_STRING("Reduz dano se o HP está cheio."),
        .descripcion = COMPOUND_STRING("Reduce daño si el PS está lleno."),
        .aiRating = 8,
        .breakable = TRUE,
    },

    [ABILITY_TOXIC_BOOST] =
    {
        .name = _("Toxic Boost"),
        .nome = _("Impulso Tóxico"),
        .nombre = _("Ímpetu Tóxico"),
        .description = COMPOUND_STRING("Ups Attack if poisoned."),
        .descricao = COMPOUND_STRING("Aumenta Atq. se envenenado."),
        .descripcion = COMPOUND_STRING("Sube Atq. si envenenado."),
        .aiRating = 6,
    },

    [ABILITY_FLARE_BOOST] =
    {
        .name = _("Flare Boost"),
        .nome = _("Impulso Ardente"),
        .nombre = _("Ímpetu Ardiente"),
        .description = COMPOUND_STRING("Ups Sp. Atk if burned."),
        .descricao = COMPOUND_STRING("Aumenta Atq. Esp. se queimado."),
        .descripcion = COMPOUND_STRING("Sube Atq. Esp. si quemado."),
        .aiRating = 5,
    },

    [ABILITY_HARVEST] =
    {
        .name = _("Harvest"),
        .nome = _("Colheita"),
        .nombre = _("Cosecha"),
        .description = COMPOUND_STRING("May recycle a used Berry."),
        .descricao = COMPOUND_STRING("Pode reciclar Berrie consumida."),
        .descripcion = COMPOUND_STRING("Puede reciclar una baya consumida."),
        .aiRating = 5,
    },

    [ABILITY_TELEPATHY] =
    {
        .name = _("Telepathy"),
        .nome = _("Telepatia"),
        .nombre = _("Telepatía"),
        .description = COMPOUND_STRING("Can't be damaged by an ally."),
        .descricao = COMPOUND_STRING("Nao pode ser atingido pelo aliado."),
        .descripcion = COMPOUND_STRING("No puede ser dañado por un aliado."),
        .aiRating = 0,
        .breakable = TRUE,
    },

    [ABILITY_MOODY] =
    {
        .name = _("Moody"),
        .nome = _("Mau-Humor"),
        .nombre = _("Veleta"),
        .description = COMPOUND_STRING("Stats change gradually."),
        .descricao = COMPOUND_STRING("Stats change gradualiado"),
        .descripcion = COMPOUND_STRING("Stats change gradualiado"),
        .aiRating = 10,
    },

    [ABILITY_OVERCOAT] =
    {
        .name = _("Overcoat"),
        .nome = _("Invólucro"),
        .nombre = _("Funda"),
        .description = COMPOUND_STRING("Blocks weather and powder."),
        .descricao = COMPOUND_STRING("Bloqueia clima e pó."),
        .descripcion = COMPOUND_STRING("Bloquea clima y polvo."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_POISON_TOUCH] =
    {
        .name = _("Poison Touch"),
        .nome = _("Toque Venenoso"),
        .nombre = _("Toque Tóxico"),
        .description = COMPOUND_STRING("Poisons foe on contact."),
        .descricao = COMPOUND_STRING("Evenena rival no contato."),
        .descripcion = COMPOUND_STRING("Envenena rival al contacto."),
        .aiRating = 4,
    },

    [ABILITY_REGENERATOR] =
    {
        .name = _("Regenerator"),
        .nome = _("Regeneração"),
        .nombre = _("Regeneración"),
        .description = COMPOUND_STRING("Heals upon switching out."),
        .descricao = COMPOUND_STRING("Cura ao sair de campo."),
        .descripcion = COMPOUND_STRING("Se cura al salir."),
        .aiRating = 8,
    },

    [ABILITY_BIG_PECKS] =
    {
        .name = _("Big Pecks"),
        .nome = _("Peito Estufado"),
        .nombre = _("Sacapecho"),
        .description = COMPOUND_STRING("Prevents Defense loss."),
        .descricao = COMPOUND_STRING("Impede perca de Defesa"),
        .descripcion = COMPOUND_STRING("Impide pérdida de Defensa"),
        .aiRating = 1,
        .breakable = TRUE,
    },

    [ABILITY_SAND_RUSH] =
    {
        .name = _("Sand Rush"),
        .nome = _("Ímpeto de Areia"),
        .nombre = _("Ímpetu Arena"),
        .description = COMPOUND_STRING("Ups Speed in a sandstorm."),
        .descricao = COMPOUND_STRING("Aumenta Vel. em temp. de areia."),
        .descripcion = COMPOUND_STRING("Sube Vel. en temp. de arena."),
        .aiRating = 6,
    },

    [ABILITY_WONDER_SKIN] =
    {
        .name = _("Wonder Skin"),
        .nome = _("Pele Milagrosa"),
        .nombre = _("Piel Milagro"),
        .description = COMPOUND_STRING("May avoid status problems."),
        .descricao = COMPOUND_STRING("Pode evitar problemas de estado."),
        .descripcion = COMPOUND_STRING("Puede evitar problemas de estado."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_ANALYTIC] =
    {
        .name = _("Analytic"),
        .nome = _("Analisar"),
        .nombre = _("Cálculo Final"),
        .description = COMPOUND_STRING("Moving last boosts power."),
        .descricao = COMPOUND_STRING("Atacar por último aumenta poder."),
        .descripcion = COMPOUND_STRING("Si actúa último, aumenta el poder."),
        .aiRating = 5,
    },

    [ABILITY_ILLUSION] =
    {
        .name = _("Illusion"),
        .nome = _("Ilusão"),
        .nombre = _("Ilusión"),
        .description = COMPOUND_STRING("Appears as a partner."),
        .descricao = COMPOUND_STRING("Aparece como um parceiro."),
        .descripcion = COMPOUND_STRING("Aparece como un parceiro."),
        .aiRating = 8,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_IMPOSTER] =
    {
        .name = _("Imposter"),
        .nome = _("Impostor"),
        .nombre = _("Impostor"),
        .description = COMPOUND_STRING("Transforms into the foe."),
        .descricao = COMPOUND_STRING("Se transforma no oponente."),
        .descripcion = COMPOUND_STRING("Se transforma en el rival."),
        .aiRating = 9,
        .cantBeCopied = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_INFILTRATOR] =
    {
        .name = _("Infiltrator"),
        .nome = _("Infiltrado"),
        .nombre = _("Allanamiento"),
        .description = COMPOUND_STRING("Passes through barriers."),
        .descricao = COMPOUND_STRING("Passa através de barreiras."),
        .descripcion = COMPOUND_STRING("Pasa a través de barreras."),
        .aiRating = 6,
    },

    [ABILITY_MUMMY] =
    {
        .name = _("Mummy"),
        .nome = _("Múmia"),
        .nombre = _("Momia"),
        .description = COMPOUND_STRING("Spreads with contact."),
        .descricao = COMPOUND_STRING("Se espalha no contato"),
        .descripcion = COMPOUND_STRING("Se espalha al contacto"),
        .aiRating = 5,
    },

    [ABILITY_MOXIE] =
    {
        .name = _("Moxie"),
        .nome = _("Arrogância"),
        .nombre = _("Autoestima"),
        .description = COMPOUND_STRING("KOs raise Attack."),
        .descricao = COMPOUND_STRING("Nocautes aumentam Atq."),
        .descripcion = COMPOUND_STRING("Nocauts aumentan Atq."),
        .aiRating = 7,
    },

    [ABILITY_JUSTIFIED] =
    {
        .name = _("Justified"),
        .nome = _("Justiceiro"),
        .nombre = _("Justiciero"),
        .description = COMPOUND_STRING("Dark hits raise Attack."),
        .descricao = COMPOUND_STRING("Golpes Noturno aumentam o Atq."),
        .descripcion = COMPOUND_STRING("Golpes Siniestro aumentan el Atq."),
        .aiRating = 4,
    },

    [ABILITY_RATTLED] =
    {
        .name = _("Rattled"),
        .nome = _("Covardia"),
        .nombre = _("Cobardía"),
        .description = COMPOUND_STRING("Raises Speed when scared."),
        .descricao = COMPOUND_STRING("Se assustar, aumenta a Vel."),
        .descripcion = COMPOUND_STRING("Si se asusta, aumenta la Vel."),
        .aiRating = 3,
    },

    [ABILITY_MAGIC_BOUNCE] =
    {
        .name = _("Magic Bounce"),
        .nome = _("Espelho Mágico"),
        .nombre = _("Espejo Mágico"),
        .description = COMPOUND_STRING("Reflects status moves."),
        .descricao = COMPOUND_STRING("Reflete golpes de estado."),
        .descripcion = COMPOUND_STRING("Refleja golpes de estado."),
        .aiRating = 9,
        .breakable = TRUE,
    },

    [ABILITY_SAP_SIPPER] =
    {
        .name = _("Sap Sipper"),
        .nome = _("Suga-Seiva"),
        .nombre = _("Herbívoro"),
        .description = COMPOUND_STRING("Grass increases Attack."),
        .descricao = COMPOUND_STRING("Planta aumenta Atq."),
        .descripcion = COMPOUND_STRING("Planta aumenta Atq."),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_PRANKSTER] =
    {
        .name = _("Prankster"),
        .nome = _("Travessura"),
        .nombre = _("Bromista"),
        .description = COMPOUND_STRING("Status moves go first."),
        .descricao = COMPOUND_STRING("Golpes de estado vão primeiro."),
        .descripcion = COMPOUND_STRING("Golpes de estado van primero."),
        .aiRating = 8,
    },

    [ABILITY_SAND_FORCE] =
    {
        .name = _("Sand Force"),
        .nome = _("Força da Areia"),
        .nombre = _("Poder Arena"),
        .description = COMPOUND_STRING("Powers up in a sandstorm."),
        .descricao = COMPOUND_STRING("Poder aumenta em temp. de areia"),
        .descripcion = COMPOUND_STRING("Poder aumenta en temp. de arena"),
        .aiRating = 4,
    },

    [ABILITY_IRON_BARBS] =
    {
        .name = _("Iron Barbs"),
        .nome = _("Espinhos de Aço"),
        .nombre = _("Punta Acero"),
        .description = COMPOUND_STRING("Hurts to touch."),
        .descricao = COMPOUND_STRING("Machuca no contato."),
        .descripcion = COMPOUND_STRING("Duele al contacto."),
        .aiRating = 6,
    },

    [ABILITY_ZEN_MODE] =
    {
        .name = _("Zen Mode"),
        .nome = _("Modo Zen"),
        .nombre = _("Modo Daruma"),
        .description = COMPOUND_STRING("Transforms at half HP."),
        .descricao = COMPOUND_STRING("Se transforma com HP na metade."),
        .descripcion = COMPOUND_STRING("Se transforma con HP a la mitad."),
        .aiRating = -1,
        .cantBeCopied = TRUE,
        .cantBeSwapped = B_UPDATED_ABILITY_DATA >= GEN_7,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = B_UPDATED_ABILITY_DATA >= GEN_7,
        .cantBeOverwritten = B_UPDATED_ABILITY_DATA >= GEN_7,
        .failsOnImposter = TRUE,
    },

    [ABILITY_VICTORY_STAR] =
    {
        .name = _("Victory Star"),
        .nome = _("Estrela Vitória"),
        .nombre = _("Tinovictoria"),
        .description = COMPOUND_STRING("Raises party accuracy."),
        .descricao = COMPOUND_STRING("Aumenta a precisão do time."),
        .descripcion = COMPOUND_STRING("Aumenta la precisión del equipo."),
        .aiRating = 6,
    },

    [ABILITY_TURBOBLAZE] =
    {
        .name = _("Turboblaze"),
        .nome = _("Turbochama"),
        .nombre = _("Turbollama"),
        .description = COMPOUND_STRING("Moves hit through abilities."),
        .descricao = COMPOUND_STRING("Golpes atravessam habilidades."),
        .descripcion = COMPOUND_STRING("Golpes atraviesan habilidades."),
        .aiRating = 7,
    },

    [ABILITY_TERAVOLT] =
    {
        .name = _("Teravolt"),
        .nome = _("Teravoltagem"),
        .nombre = _("Terravoltaje"),
        .description = COMPOUND_STRING("Moves hit through abilities."),
        .descricao = COMPOUND_STRING("Golpes atravessam habilidades."),
        .descripcion = COMPOUND_STRING("Golpes atraviesan habilidades."),
        .aiRating = 7,
    },

    [ABILITY_AROMA_VEIL] =
    {
        .name = _("Aroma Veil"),
        .nome = _("Véu Aromático"),
        .nombre = _("Velo Aroma"),
        .description = COMPOUND_STRING("Prevents limiting of moves."),
        .descricao = COMPOUND_STRING("Impede restrição de golpes."),
        .descripcion = COMPOUND_STRING("Impide restricción de golpes."),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_FLOWER_VEIL] =
    {
        .name = _("Flower Veil"),
        .nome = _("Véu de Flores"),
        .nombre = _("Velo Flor"),
        .description = COMPOUND_STRING("Protects Grass-types."),
        .descricao = COMPOUND_STRING("Protege Tipo Grama."),
        .descripcion = COMPOUND_STRING("Protege Tipo Planta."),
        .aiRating = 0,
        .breakable = TRUE,
    },

    [ABILITY_CHEEK_POUCH] =
    {
        .name = _("Cheek Pouch"),
        .nome = _("Bochechões"),
        .nombre = _("Carrillo"),
        .description = COMPOUND_STRING("Eating Berries restores HP."),
        .descricao = COMPOUND_STRING("Restaura HP ao comer Berries."),
        .descripcion = COMPOUND_STRING("Restaura PS al comer Bayas."),
        .aiRating = 4,
    },

    [ABILITY_PROTEAN] =
    {
        .name = _("Protean"),
        .nome = _("Proteico"),
        .nombre = _("Mutatipo"),
        .description = COMPOUND_STRING("Changes type to used move."),
        .descricao = COMPOUND_STRING("Muda tipo para golpe usado."),
        .descripcion = COMPOUND_STRING("Cambia tipo para golpe usado."),
        .aiRating = 8,
    },

    [ABILITY_FUR_COAT] =
    {
        .name = _("Fur Coat"),
        .nome = _("Camada de Pelos"),
        .nombre = _("Pelaje Recio"),
        .description = COMPOUND_STRING("Raises Defense."),
        .descricao = COMPOUND_STRING("Aumenta Defesa."),
        .descripcion = COMPOUND_STRING("Sube Defensa."),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_MAGICIAN] =
    {
        .name = _("Magician"),
        .nome = _("Mágico"),
        .nombre = _("Prestidigitador"),
        .description = COMPOUND_STRING("Steals the foe's held item."),
        .descricao = COMPOUND_STRING("Rouba o item do oponente."),
        .descripcion = COMPOUND_STRING("Roba el item del rival."),
        .aiRating = 3,
    },

    [ABILITY_BULLETPROOF] =
    {
        .name = _("Bulletproof"),
        .nome = _("Blindado"),
        .nombre = _("Antibalas"),
        .description = COMPOUND_STRING("Avoids some projectiles."),
        .descricao = COMPOUND_STRING("Evita gospes bola e bomba."),
        .descripcion = COMPOUND_STRING("Evita golpes bola y bomba."),
        .breakable = TRUE,
        .aiRating = 7,
    },

    [ABILITY_COMPETITIVE] =
    {
        .name = _("Competitive"),
        .nome = _("Competitivo"),
        .nombre = _("Tenacidad"),
        .description = COMPOUND_STRING("Lowered stats up Sp. Atk."),
        .descricao = COMPOUND_STRING("Reduzir stats aumenta Atq. Esp."),
        .descripcion = COMPOUND_STRING("Reducir stats aumenta Atq. Esp."),
        .aiRating = 5,
    },

    [ABILITY_STRONG_JAW] =
    {
        .name = _("Strong Jaw"),
        .nome = _("Mandíbula Forte"),
        .nombre = _("Mandíbula Fuerte"),
        .description = COMPOUND_STRING("Boosts biting moves."),
        .descricao = COMPOUND_STRING("Impulsiona golpes mordida."),
        .descripcion = COMPOUND_STRING("Impulsiona golpes mordida."),
        .aiRating = 6,
    },

    [ABILITY_REFRIGERATE] =
    {
        .name = _("Refrigerate"),
        .nome = _("Refrigeração"),
        .nombre = _("Piel Helada"),
        .description = COMPOUND_STRING("Normal moves become Ice."),
        .descricao = COMPOUND_STRING("Golpes Normal se tornam Gelo."),
        .descripcion = COMPOUND_STRING("Golpes Normal se tornan Hielo."),
        .aiRating = 8,
    },

    [ABILITY_SWEET_VEIL] =
    {
        .name = _("Sweet Veil"),
        .nome = _("Véu Doce"),
        .nombre = _("Velo Dulce"),
        .description = COMPOUND_STRING("Prevents party from sleep."),
        .descricao = COMPOUND_STRING("Impede a equipe de dormir."),
        .descripcion = COMPOUND_STRING("Impide que el equipo se duerma."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_STANCE_CHANGE] =
    {
        .name = _("Stance Change"),
        .nome = _("Troca de Postura"),
        .nombre = _("Cambio Táctico"),
        .description = COMPOUND_STRING("Transforms as it battles."),
        .descricao = COMPOUND_STRING("Troca de forma em batalha."),
        .descripcion = COMPOUND_STRING("Cambia de forma en batalla."),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_GALE_WINGS] =
    {
        .name = _("Gale Wings"),
        .nome = _("Asas de Vendaval"),
        .nombre = _("Alas Vendaval"),
        .description = COMPOUND_STRING("Flying moves go first."),
        .descricao = COMPOUND_STRING("Golpes Voador vão primeiro."),
        .descripcion = COMPOUND_STRING("Golpes Volador van primero."),
        .aiRating = 6,
    },

    [ABILITY_MEGA_LAUNCHER] =
    {
        .name = _("Mega Launcher"),
        .nome = _("Megalançamento"),
        .nombre = _("Megadisparador"),
        .description = COMPOUND_STRING("Boosts pulse moves."),
        .descricao = COMPOUND_STRING("Impulsiona golpes pulso."),
        .descripcion = COMPOUND_STRING("Impulsiona golpes pulso."),
        .aiRating = 7,
    },

    [ABILITY_GRASS_PELT] =
    {
        .name = _("Grass Pelt"),
        .nome = _("Manto Frondoso"),
        .nombre = _("Manto Frondoso"),
        .description = COMPOUND_STRING("Ups Defense in grass."),
        .descricao = COMPOUND_STRING("Aumenta Def. em campo grama."),
        .descripcion = COMPOUND_STRING("Aumenta Def. en campo hierba."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_SYMBIOSIS] =
    {
        .name = _("Symbiosis"),
        .nome = _("Simbiose"),
        .nombre = _("Simbiosis"),
        .description = COMPOUND_STRING("Passes its item to an ally."),
        .descricao = COMPOUND_STRING("Passa seu item para um aliado."),
        .descripcion = COMPOUND_STRING("Pasa su objeto a un aliado."),
        .aiRating = 0,
    },

    [ABILITY_TOUGH_CLAWS] =
    {
        .name = _("Tough Claws"),
        .nome = _("Garras Duras"),
        .nombre = _("Garra Dura"),
        .description = COMPOUND_STRING("Boosts contact moves."),
        .descricao = COMPOUND_STRING("Impulsiona golpes de contato."),
        .descripcion = COMPOUND_STRING("Sube golpes de contacto."),
        .aiRating = 7,
    },

    [ABILITY_PIXILATE] =
    {
        .name = _("Pixilate"),
        .nome = _("Mãos de Fada"),
        .nombre = _("Piel Feérica"),
        .description = COMPOUND_STRING("Normal moves become Fairy."),
        .descricao = COMPOUND_STRING("Golpes Normal se tornam Fada."),
        .descripcion = COMPOUND_STRING("Golpes Normal se tornan Hada."),
        .aiRating = 8,
    },

    [ABILITY_GOOEY] =
    {
        .name = _("Gooey"),
        .nome = _("Pegajoso"),
        .nombre = _("Baba"),
        .description = COMPOUND_STRING("Lowers Speed on contact."),
        .descricao = COMPOUND_STRING("Baixa Vel. no contato."),
        .descripcion = COMPOUND_STRING("Baja Vel. on contacto."),
        .aiRating = 5,
    },

    [ABILITY_AERILATE] =
    {
        .name = _("Aerilate"),
        .nome = _("Aeração"),
        .nombre = _("Piel Celeste"),
        .description = COMPOUND_STRING("Normal moves become Flying."),
        .descricao = COMPOUND_STRING("Golpes Normal se tornam Voador."),
        .descripcion = COMPOUND_STRING("Golpes Normal se tornan Volador."),
        .aiRating = 8,
    },

    [ABILITY_PARENTAL_BOND] =
    {
        .name = _("Parental Bond"),
        .nome = _("Laço Familiar"),
        .nombre = _("Amor Filial"),
        .description = COMPOUND_STRING("Moves hit twice."),
        .descricao = COMPOUND_STRING("Golpes atingem duas vezes."),
        .descripcion = COMPOUND_STRING("Golpes golpean dos veces."),
        .aiRating = 10,
    },

    [ABILITY_DARK_AURA] =
    {
        .name = _("Dark Aura"),
        .nome = _("Aura Negra"),
        .nombre = _("Aura Oscura"),
        .description = COMPOUND_STRING("Boosts Dark moves."),
        .descricao = COMPOUND_STRING("Impulsiona golpes Sombrio."),
        .descripcion = COMPOUND_STRING("Sube golpes Siniestro."),
        .aiRating = 6,
        .breakable = B_UPDATED_ABILITY_DATA < GEN_8,
    },

    [ABILITY_FAIRY_AURA] =
    {
        .name = _("Fairy Aura"),
        .nome = _("Aura Feérica"),
        .nombre = _("Aura Feérica"),
        .description = COMPOUND_STRING("Boosts Fairy moves."),
        .descricao = COMPOUND_STRING("Impulsiona golpes Fada."),
        .descripcion = COMPOUND_STRING("Sube golpes Hada."),
        .aiRating = 6,
        .breakable = B_UPDATED_ABILITY_DATA < GEN_8,
    },

    [ABILITY_AURA_BREAK] =
    {
        .name = _("Aura Break"),
        .nome = _("Rompe-Auras"),
        .nombre = _("Rompeaura"),
        .description = COMPOUND_STRING("Reverse aura abilities."),
        .descricao = COMPOUND_STRING("Reverte habilidades de aura."),
        .descripcion = COMPOUND_STRING("Revierte habilidades de aura."),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_PRIMORDIAL_SEA] =
    {
        .name = _("Primordial Sea"),
        .nome = _("Mar Primordial"),
        .nombre = _("Mar del Albor"),
        .description = COMPOUND_STRING("Summons heavy rain."),
        .descricao = COMPOUND_STRING("Invoca chuva pesada."),
        .descripcion = COMPOUND_STRING("Invoca lluvia pesada."),
        .aiRating = 10,
    },

    [ABILITY_DESOLATE_LAND] =
    {
        .name = _("Desolate Land"),
        .nome = _("Terra Desolada"),
        .nombre = _("Tierra del Ocaso"),
        .description = COMPOUND_STRING("Summons intense sunlight."),
        .descricao = COMPOUND_STRING("Invoca luz solar intensa."),
        .descripcion = COMPOUND_STRING("Invoca luz solar intensa."),
        .aiRating = 10,
    },

    [ABILITY_DELTA_STREAM] =
    {
        .name = _("Delta Stream"),
        .nome = _("Correnteza Delta"),
        .nombre = _("Ráfaga Delta"),
        .description = COMPOUND_STRING("Summons strong winds."),
        .descricao = COMPOUND_STRING("Invoca ventos fortes."),
        .descripcion = COMPOUND_STRING("Invoca ventos fortes."),
        .aiRating = 10,
    },

    [ABILITY_STAMINA] =
    {
        .name = _("Stamina"),
        .nome = _("Estamina"),
        .nombre = _("Firmeza"),
        .description = COMPOUND_STRING("Boosts Defense when hit."),
        .descricao = COMPOUND_STRING("Aumenta Def. quando é acertado."),
        .descripcion = COMPOUND_STRING("Aumenta Def. cuando es golpeado."),
        .aiRating = 6,
    },

    [ABILITY_WIMP_OUT] =
    {
        .name = _("Wimp Out"),
        .nome = _("Amarelar"),
        .nombre = _("Huida"),
        .description = COMPOUND_STRING("Flees at half HP."),
        .descricao = COMPOUND_STRING("Foge na metade do HP."),
        .descripcion = COMPOUND_STRING("Huye a la mitad del HP."),
        .aiRating = 3,
    },

    [ABILITY_EMERGENCY_EXIT] =
    {
        .name = _("Emergency Exit"),
        .nome = _("Fuga Automática"),
        .nombre = _("Retirada"),
        .description = COMPOUND_STRING("Flees at half HP."),
        .descricao = COMPOUND_STRING("Foge na metade do HP."),
        .descripcion = COMPOUND_STRING("Huye a la mitad del HP."),
        .aiRating = 3,
    },

    [ABILITY_WATER_COMPACTION] =
    {
        .name = _("Water Compaction"),
        .nome = _("Hidrorreforço"),
        .nombre = _("Hidrorrefuerzo"),
        .description = COMPOUND_STRING("Water boosts Defense."),
        .descricao = COMPOUND_STRING("Água impulsiona Defefesa."),
        .descripcion = COMPOUND_STRING("Água sube Defensa."),
        .aiRating = 4,
    },

    [ABILITY_MERCILESS] =
    {
        .name = _("Merciless"),
        .nome = _("Crueldade"),
        .nombre = _("Ensañamiento"),
        .description = COMPOUND_STRING("Criticals poisoned foes."),
        .descricao = COMPOUND_STRING("Dá críticos em alvos envenenados."),
        .descripcion = COMPOUND_STRING("Da críticos a rivales envenenados."),
        .aiRating = 4,
    },

    [ABILITY_SHIELDS_DOWN] =
    {
        .name = _("Shields Down"),
        .nome = _("Escudos Baixos"),
        .nombre = _("Escudo Limitado"),
        .description = COMPOUND_STRING("Shell breaks at half HP."),
        .descricao = COMPOUND_STRING("Concha quebra na metade do HP."),
        .descripcion = COMPOUND_STRING("Concha se rompe a la mitad del PS."),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_STAKEOUT] =
    {
        .name = _("Stakeout"),
        .nome = _("Vigilância"),
        .nombre = _("Vigilante"),
        .description = COMPOUND_STRING("Stronger as foes switch in."),
        .descricao = COMPOUND_STRING("Mais forte quando o rival troca."),
        .descripcion = COMPOUND_STRING("Más fuerte cuando el rival cambia."),
        .aiRating = 6,
    },

    [ABILITY_WATER_BUBBLE] =
    {
        .name = _("Water Bubble"),
        .nome = _("Bolha de Água"),
        .nombre = _("Pompa"),
        .description = COMPOUND_STRING("Guards from fire and burns."),
        .descricao = COMPOUND_STRING("Protege de fogo e queimaduras."),
        .descripcion = COMPOUND_STRING("Protege de fuego y quemaduras."),
        .aiRating = 8,
        .breakable = TRUE,
    },

    [ABILITY_STEELWORKER] =
    {
        .name = _("Steelworker"),
        .nome = _("Metalista"),
        .nombre = _("Acero Templado"),
        .description = COMPOUND_STRING("Powers up Steel moves."),
        .descricao = COMPOUND_STRING("Aumenta poder de golpes Aço."),
        .descripcion = COMPOUND_STRING("Sube poder de golpes Acero."),
        .aiRating = 6,
    },

    [ABILITY_BERSERK] =
    {
        .name = _("Berserk"),
        .nome = _("Furioso"),
        .nombre = _("Cólera"),
        .description = COMPOUND_STRING("Boosts Sp. Atk at low HP."),
        .descricao = COMPOUND_STRING("Aumenta Atq. Esp. com pouco HP."),
        .descripcion = COMPOUND_STRING("Sube Atq. Esp. con poco HP."),
        .aiRating = 5,
    },

    [ABILITY_SLUSH_RUSH] =
    {
        .name = _("Slush Rush"),
        .nome = _("Ímpeto de Neve"),
        .nombre = _("Quitanieves"),
        .description = COMPOUND_STRING("Raises Speed in Hail/Snow."),
        .descricao = COMPOUND_STRING("Aumenta Vel. em granizo/neve."),
        .descripcion = COMPOUND_STRING("Sube Vel. en granizo/nieve."),
        .aiRating = 5,
    },

    [ABILITY_LONG_REACH] =
    {
        .name = _("Long Reach"),
        .nome = _("Longo Alcance"),
        .nombre = _("Remoto"),
        .description = COMPOUND_STRING("Never makes contact."),
        .descricao = COMPOUND_STRING("Nunca faz contato."),
        .descripcion = COMPOUND_STRING("Nunca hace contacto."),
        .aiRating = 3,
    },

    [ABILITY_LIQUID_VOICE] =
    {
        .name = _("Liquid Voice"),
        .nome = _("Voz Líquida"),
        .nombre = _("Voz Fluida"),
        .description = COMPOUND_STRING("Makes sound moves Water."),
        .descricao = COMPOUND_STRING("Transforma golpes som em Agua."),
        .descripcion = COMPOUND_STRING("Transforma golpes sonido en Agua."),
        .aiRating = 5,
    },

    [ABILITY_TRIAGE] =
    {
        .name = _("Triage"),
        .nome = _("Triagem"),
        .nombre = _("Primer Auxilio"),
        .description = COMPOUND_STRING("Healing moves go first."),
        .descricao = COMPOUND_STRING("Golpes de cura vão primeiro."),
        .descripcion = COMPOUND_STRING("Golpes de cura van primero."),
        .aiRating = 7,
    },

    [ABILITY_GALVANIZE] =
    {
        .name = _("Galvanize"),
        .nome = _("Crosta Elétrica"),
        .nombre = _("Piel Eléctrica"),
        .description = COMPOUND_STRING("Normal moves turn Electric."),
        .descricao = COMPOUND_STRING("Golpes Normal viram Eletrico."),
        .descripcion = COMPOUND_STRING("Golpes Normal se tornan Eléctric."),
        .aiRating = 8,
    },

    [ABILITY_SURGE_SURFER] =
    {
        .name = _("Surge Surfer"),
        .nome = _("Cauda Surfista"),
        .nombre = _("Cola Surf"),
        .description = COMPOUND_STRING("Faster on electricity."),
        .descricao = COMPOUND_STRING("Mais rápido na eletricidade."),
        .descripcion = COMPOUND_STRING("Más rápido en electricidad."),
        .aiRating = 4,
    },

    [ABILITY_SCHOOLING] =
    {
        .name = _("Schooling"),
        .nome = _("Cardume"),
        .nombre = _("Banco"),
        .description = COMPOUND_STRING("Forms a school when strong."),
        .descricao = COMPOUND_STRING("Forma um cardume quando forte."),
        .descripcion = COMPOUND_STRING("Forma un banco cuando fuerte."),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_DISGUISE] =
    {
        .name = _("Disguise"),
        .nome = _("Disfarce"),
        .nombre = _("Disfraz"),
        .description = COMPOUND_STRING("Decoy protects it once."),
        .descricao = COMPOUND_STRING("Isca o protege uma vez."),
        .descripcion = COMPOUND_STRING("Isca lo protege una vez."),
        .aiRating = 8,
        .breakable = TRUE,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_BATTLE_BOND] =
    {
        .name = _("Battle Bond"),
        .nome = _("Forte Vínculo"),
        .nombre = _("Fuerte Afecto"),
        .description = COMPOUND_STRING("Changes form after a KO."),
        .descricao = COMPOUND_STRING("Muda forma após um nocaute."),
        .descripcion = COMPOUND_STRING("Cambia forma después de un KO."),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_POWER_CONSTRUCT] =
    {
        .name = _("Power Construct"),
        .nome = _("Agrupamento"),
        .nombre = _("Agrupamiento"),
        .description = COMPOUND_STRING("Cells aid it when weakened."),
        .descricao = COMPOUND_STRING("Células o ajudam ao enfraquecer."),
        .descripcion = COMPOUND_STRING("Células lo ayudan al debilitarse."),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_CORROSION] =
    {
        .name = _("Corrosion"),
        .nome = _("Corrosão"),
        .nombre = _("Corrosión"),
        .description = COMPOUND_STRING("Poisons any type."),
        .descricao = COMPOUND_STRING("Evenena qualquer tipo."),
        .descripcion = COMPOUND_STRING("Envenena cualquier tipo."),
        .aiRating = 5,
    },

    [ABILITY_COMATOSE] =
    {
        .name = _("Comatose"),
        .nome = _("Comatoso"),
        .nombre = _("Letargo Perenne"),
        .description = COMPOUND_STRING("Always drowsing."),
        .descricao = COMPOUND_STRING("Sempre sonolento."),
        .descripcion = COMPOUND_STRING("Siempre somnoliento."),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_QUEENLY_MAJESTY] =
    {
        .name = _("Queenly Majesty"),
        .nome = _("Presença Régia"),
        .nombre = _("Regia Presencia"),
        .description = COMPOUND_STRING("Protects from priority."),
        .descricao = COMPOUND_STRING("Protege de prioridade."),
        .descripcion = COMPOUND_STRING("Protege de prioridad."),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_INNARDS_OUT] =
    {
        .name = _("Innards Out"),
        .nome = _("Probóscide"),
        .nombre = _("Revés"),
        .description = COMPOUND_STRING("Hurts foe when defeated."),
        .descricao = COMPOUND_STRING("Causa dano ao ser derrotado."),
        .descripcion = COMPOUND_STRING("Causa daño al ser derrotado."),
        .aiRating = 5,
    },

    [ABILITY_DANCER] =
    {
        .name = _("Dancer"),
        .nome = _("Dançarino"),
        .nombre = _("Pareja de Baile"),
        .description = COMPOUND_STRING("Dances along with others."),
        .descricao = COMPOUND_STRING("Dança junto com outros."),
        .descripcion = COMPOUND_STRING("Baila junto con otros."),
        .aiRating = 5,
    },

    [ABILITY_BATTERY] =
    {
        .name = _("Battery"),
        .nome = _("Bateria"),
        .nombre = _("Batería"),
        .description = COMPOUND_STRING("Boosts ally's Sp. Atk."),
        .descricao = COMPOUND_STRING("Aumenta Atq. Esp. do aliado."),
        .descripcion = COMPOUND_STRING("Sube Atq. Esp. del aliado."),
        .aiRating = 0,
    },

    [ABILITY_FLUFFY] =
    {
        .name = _("Fluffy"),
        .nome = _("Macio"),
        .nombre = _("Peluche"),
        .description = COMPOUND_STRING("Tougher but flammable."),
        .descricao = COMPOUND_STRING("Resistente, mas inflamável."),
        .descripcion = COMPOUND_STRING("Resistente, pero inflamable."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_DAZZLING] =
    {
        .name = _("Dazzling"),
        .nome = _("Corpo Vívido"),
        .nombre = _("Cuerpo Vívido"),
        .description = COMPOUND_STRING("Protects from priority."),
        .descricao = COMPOUND_STRING("Protege de prioridade."),
        .descripcion = COMPOUND_STRING("Protege de prioridad."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_SOUL_HEART] =
    {
        .name = _("Soul-Heart"),
        .nome = _("Coralma"),
        .nombre = _("Coránima"),
        .description = COMPOUND_STRING("KOs raise Sp. Atk."),
        .descricao = COMPOUND_STRING("Nocáutes sobem Atq. Esp."),
        .descripcion = COMPOUND_STRING("Nocáutes sube Atq. Esp."),
        .aiRating = 7,
    },

    [ABILITY_TANGLING_HAIR] =
    {
        .name = _("Tangling Hair"),
        .nome = _("Cabelo Bagunçado"),
        .nombre = _("Rizos Rebeldes"),
        .description = COMPOUND_STRING("Lowers Speed on contact."),
        .descricao = COMPOUND_STRING("Baixa Vel. no contato"),
        .descripcion = COMPOUND_STRING("Baja Vel. on contacto"),
        .aiRating = 5,
    },

    [ABILITY_RECEIVER] =
    {
        .name = _("Receiver"),
        .nome = _("Receptor"),
        .nombre = _("Receptor"),
        .description = COMPOUND_STRING("Copies ally's ability."),
        .descricao = COMPOUND_STRING("Copia habilidade do aliado."),
        .descripcion = COMPOUND_STRING("Copia habilidad del aliado."),
        .aiRating = 0,
        .cantBeCopied = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_POWER_OF_ALCHEMY] =
    {
        .name = _("Power Of Alchemy"),
        .nome = _("Reação Química"),
        .nombre = _("Reacción Química"),
        .description = COMPOUND_STRING("Copies ally's ability."),
        .descricao = COMPOUND_STRING("Copia habilidade do aliado."),
        .descripcion = COMPOUND_STRING("Copia habilidad del aliado."),
        .aiRating = 0,
        .cantBeCopied = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_BEAST_BOOST] =
    {
        .name = _("Beast Boost"),
        .nome = _("Ultraimpulso"),
        .nombre = _("Ultraimpulso"),
        .description = COMPOUND_STRING("KOs boost best stat."),
        .descricao = COMPOUND_STRING("Nocáutes sobem melhor stat."),
        .descripcion = COMPOUND_STRING("Nocáutes sube mejor stat."),
        .aiRating = 7,
    },

    [ABILITY_RKS_SYSTEM] =
    {
        .name = _("RKS System"),
        .nome = _("Sistema Alfa"),
        .nombre = _("Sistema Alfa"),
        .description = COMPOUND_STRING("Memories change its type."),
        .descricao = COMPOUND_STRING("Memórias mudam seu tipo."),
        .descripcion = COMPOUND_STRING("Memorias cambian su tipo."),
        .aiRating = 8,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_ELECTRIC_SURGE] =
    {
        .name = _("Electric Surge"),
        .nome = _("Eletrogênese"),
        .nombre = _("Electrogénesis"),
        .description = COMPOUND_STRING("Field becomes Electric."),
        .descricao = COMPOUND_STRING("Terreno torna-se Elétrico."),
        .descripcion = COMPOUND_STRING("El terreno se vuelve Eléctrico."),
        .aiRating = 8,
    },

    [ABILITY_PSYCHIC_SURGE] =
    {
        .name = _("Psychic Surge"),
        .nome = _("Psicogênese"),
        .nombre = _("Psicogénesis"),
        .description = COMPOUND_STRING("Field becomes weird."),
        .descricao = COMPOUND_STRING("Terreno torna-se estranho."),
        .descripcion = COMPOUND_STRING("El terreno se vuelve extraño."),
        .aiRating = 8,
    },

    [ABILITY_MISTY_SURGE] =
    {
        .name = _("Misty Surge"),
        .nome = _("Nebulogênese"),
        .nombre = _("Nebulogénesis"),
        .description = COMPOUND_STRING("Field becomes misty."),
        .descricao = COMPOUND_STRING("Terreno torna-se Nublado."),
        .descripcion = COMPOUND_STRING("El terreno se vuelve Nublado."),
        .aiRating = 8,
    },

    [ABILITY_GRASSY_SURGE] =
    {
        .name = _("Grassy Surge"),
        .nome = _("Herbogênese"),
        .nombre = _("Herbogénesis"),
        .description = COMPOUND_STRING("Field becomes grassy."),
        .descricao = COMPOUND_STRING("Terreno torna-se gramado."),
        .descripcion = COMPOUND_STRING("El terreno se vuelve de hierba."),
        .aiRating = 8,
    },

    [ABILITY_FULL_METAL_BODY] =
    {
        .name = _("Full Metal Body"),
        .nome = _("Corpo Metálico"),
        .nombre = _("Guardia Metálica"),
        .description = COMPOUND_STRING("Prevents stat reduction."),
        .descricao = COMPOUND_STRING("Impede redução de stat."),
        .descripcion = COMPOUND_STRING("Impide reducción de stat."),
        .aiRating = 4,
    },

    [ABILITY_SHADOW_SHIELD] =
    {
        .name = _("Shadow Shield"),
        .nome = _("Escudo Sombrio"),
        .nombre = _("Guardia Espectro"),
        .description = COMPOUND_STRING("Halves damage at full HP."),
        .descricao = COMPOUND_STRING("Reduz dano se o HP está cheio."),
        .descripcion = COMPOUND_STRING("Reduce daño si el PS está lleno."),
        .aiRating = 8,
    },

    [ABILITY_PRISM_ARMOR] =
    {
        .name = _("Prism Armor"),
        .nome = _("Armadura Prisma"),
        .nombre = _("Armadura Prisma"),
        .description = COMPOUND_STRING("Weakens “supereffective”."),
        .descricao = COMPOUND_STRING("Enfraquece “super efetivos”."),
        .descripcion = COMPOUND_STRING("Enfraquece “super efectivos”."),
        .aiRating = 6,
    },

    [ABILITY_NEUROFORCE] =
    {
        .name = _("Neuroforce"),
        .nome = _("Força Neural"),
        .nombre = _("Fuerza Cerebral"),
        .description = COMPOUND_STRING("Ups “supereffective”."),
        .descricao = COMPOUND_STRING("Aumenta “super efetivos”."),
        .descripcion = COMPOUND_STRING("Sube ““super efectivos”."),
        .aiRating = 6,
    },

    [ABILITY_INTREPID_SWORD] =
    {
        .name = _("Intrepid Sword"),
        .nome = _("Espada Intrépida"),
        .nombre = _("Espada Indómita"),
        .description = COMPOUND_STRING("Ups Attack on entry."),
        .descricao = COMPOUND_STRING("Aumenta Atq. na entrada."),
        .descripcion = COMPOUND_STRING("Sube Atq. en la entrada."),
        .aiRating = 3,
    },

    [ABILITY_DAUNTLESS_SHIELD] =
    {
        .name = _("Dauntless Shield"),
        .nome = _("Escudo Destemido"),
        .nombre = _("Escudo Recio"),
        .description = COMPOUND_STRING("Ups Defense on entry."),
        .descricao = COMPOUND_STRING("Aumenta Def. na entrada."),
        .descripcion = COMPOUND_STRING("Sube Def. en la entrada."),
        .aiRating = 3,
    },

    [ABILITY_LIBERO] =
    {
        .name = _("Libero"),
        .nome = _("Líbero"),
        .nombre = _("Líbero"),
        .description = COMPOUND_STRING("Changes type to move's."),
        .descricao = COMPOUND_STRING("Muda tipo para golpe usado."),
        .descripcion = COMPOUND_STRING("Cambia tipo para golpe usado."),
    },

    [ABILITY_BALL_FETCH] =
    {
        .name = _("Ball Fetch"),
        .nome = _("Pega Bola"),
        .nombre = _("Recogebolas"),
        .description = COMPOUND_STRING("Fetches failed Poké Ball."),
        .descricao = COMPOUND_STRING("Recupera Pokébola falhada."),
        .descripcion = COMPOUND_STRING("Recupera Poké Ball fallida."),
        .aiRating = 0,
    },

    [ABILITY_COTTON_DOWN] =
    {
        .name = _("Cotton Down"),
        .nome = _("Algodao Solto"),
        .nombre = _("Pelusa"),
        .description = COMPOUND_STRING("Lower Speed of all when hit."),
        .descricao = COMPOUND_STRING("Baixa Vel. de todos se acertado."),
        .descripcion = COMPOUND_STRING("Baja Vel. de todos si golpeado."),
        .aiRating = 3,
    },

    [ABILITY_PROPELLER_TAIL] =
    {
        .name = _("Propeller Tail"),
        .nome = _("Cauda Helice"),
        .nombre = _("Hélice Caudal"),
        .description = COMPOUND_STRING("Ignores foe's redirection."),
        .descricao = COMPOUND_STRING("Ignora redirecionamento do rival."),
        .descripcion = COMPOUND_STRING("Ignora la redirección del rival."),
        .aiRating = 2,
    },

    [ABILITY_MIRROR_ARMOR] =
    {
        .name = _("Mirror Armor"),
        .nome = _("Armad. Espelho"),
        .nombre = _("Coraza Reflejo"),
        .description = COMPOUND_STRING("Reflect stat decreases."),
        .descricao = COMPOUND_STRING("Reflete redução de stat."),
        .descripcion = COMPOUND_STRING("Refleja reducción de stat."),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_GULP_MISSILE] =
    {
        .name = _("Gulp Missile"),
        .nome = _("Míssil Glutão"),
        .nombre = _("Tragamisil"),
        .description = COMPOUND_STRING("If hit, spits prey from sea."),
        .descricao = COMPOUND_STRING("Se atingido, cospe presa marinha."),
        .descripcion = COMPOUND_STRING("Si golpeado, escupe presa marina."),
        .aiRating = 3,
        .cantBeSwapped = B_UPDATED_ABILITY_DATA < GEN_9,
        .cantBeCopied = B_UPDATED_ABILITY_DATA < GEN_9,
        .cantBeTraced = B_UPDATED_ABILITY_DATA < GEN_9,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_STALWART] =
    {
        .name = _("Stalwart"),
        .nome = _("Obstinação"),
        .nombre = _("Acérrimo"),
        .description = COMPOUND_STRING("Ignores foe's redirection."),
        .descricao = COMPOUND_STRING("Ignora redirecionamento do rival."),
        .descripcion = COMPOUND_STRING("Ignora la redirección del rival."),
        .aiRating = 2,
    },

    [ABILITY_STEAM_ENGINE] =
    {
        .name = _("Steam Engine"),
        .nome = _("Motor a Vapor"),
        .nombre = _("Combustible"),
        .description = COMPOUND_STRING("Fire or Water hits up Speed."),
        .descricao = COMPOUND_STRING("Golpes Fogo/Água sobem Vel."),
        .descripcion = COMPOUND_STRING("Golpes Fuego/Agua sube la Vel."),
        .aiRating = 3,
    },

    [ABILITY_PUNK_ROCK] =
    {
        .name = _("Punk Rock"),
        .nome = _("Punk Rock"),
        .nombre = _("Punk Rock"),
        .description = COMPOUND_STRING("Ups and resists sound."),
        .descricao = COMPOUND_STRING("Aumenta e resiste a som."),
        .descripcion = COMPOUND_STRING("Aumenta y resiste a sonido."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_SAND_SPIT] =
    {
        .name = _("Sand Spit"),
        .nome = _("Lançareia"),
        .nombre = _("Expulsarena"),
        .description = COMPOUND_STRING("Creates a sandstorm if hit."),
        .descricao = COMPOUND_STRING("Cria uma temp. areia se acertado."),
        .descripcion = COMPOUND_STRING("Crea una tor. arena si golpeado."),
        .aiRating = 5,
    },

    [ABILITY_ICE_SCALES] =
    {
        .name = _("Ice Scales"),
        .nome = _("Escama de Gelo"),
        .nombre = _("Escama de Hielo"),
        .description = COMPOUND_STRING("Halves special damage."),
        .descricao = COMPOUND_STRING("Reduz dano special à metade."),
        .descripcion = COMPOUND_STRING("Reduce daño especial a la mitad."),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_RIPEN] =
    {
        .name = _("Ripen"),
        .nome = _("Amadurecer"),
        .nombre = _("Maduración"),
        .description = COMPOUND_STRING("Doubles effect of Berries."),
        .descricao = COMPOUND_STRING("Dobra o efeito de berries."),
        .descripcion = COMPOUND_STRING("Dobla el efecto de las bayas."),
        .aiRating = 4,
    },

    [ABILITY_ICE_FACE] =
    {
        .name = _("Ice Face"),
        .nome = _("Cara de Gelo"),
        .nombre = _("Cara de Hielo"),
        .description = COMPOUND_STRING("Hail or Snow renew free hit."),
        .descricao = COMPOUND_STRING("Granizo/Neve renovam golpe livre."),
        .descripcion = COMPOUND_STRING("Gran./Nieve renuevan golpe libre."),
        .aiRating = 4,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .breakable = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_POWER_SPOT] =
    {
        .name = _("Power Spot"),
        .nome = _("Fonte de Energia"),
        .nombre = _("Fuente Energía"),
        .description = COMPOUND_STRING("Powers up ally moves."),
        .descricao = COMPOUND_STRING("Potencializa golpes de aliado."),
        .descripcion = COMPOUND_STRING("Potencia movimientos aliados."),
        .aiRating = 2,
    },

    [ABILITY_MIMICRY] =
    {
        .name = _("Mimicry"),
        .nome = _("Mimetismo"),
        .nombre = _("Mimetismo"),
        .description = COMPOUND_STRING("Changes type on terrain."),
        .descricao = COMPOUND_STRING("Muda tipo em terreno."),
        .descripcion = COMPOUND_STRING("Cambia tipo en el terreno."),
        .aiRating = 2,
    },

    [ABILITY_SCREEN_CLEANER] =
    {
        .name = _("Screen Cleaner"),
        .nome = _("Limpa-Vidro"),
        .nombre = _("Antibarrera"),
        .description = COMPOUND_STRING("Removes walls of light."),
        .descricao = COMPOUND_STRING("Remove barreiras de luz."),
        .descripcion = COMPOUND_STRING("Elimina barreras de luz."),
        .aiRating = 3,
    },

    [ABILITY_STEELY_SPIRIT] =
    {
        .name = _("Steely Spirit"),
        .nome = _("Espírito Férreo"),
        .nombre = _("Alma Acerada"),
        .description = COMPOUND_STRING("Boosts ally's Steel moves."),
        .descricao = COMPOUND_STRING("Fortalece golpes Aço do aliado."),
        .descripcion = COMPOUND_STRING("Sube movimientos de Acero aliados."),
        .aiRating = 2,
    },

    [ABILITY_PERISH_BODY] =
    {
        .name = _("Perish Body"),
        .nome = _("Corpo Perecido"),
        .nombre = _("Cuerpo Mortal"),
        .description = COMPOUND_STRING("Foe faints in 3 turns if hit."),
        .descricao = COMPOUND_STRING("Oponente desmaia em 3 turnos."),
        .descripcion = COMPOUND_STRING("El rival se desmaya en 3 turnos."),
        .aiRating = -1,
    },

    [ABILITY_WANDERING_SPIRIT] =
    {
        .name = _("Wandering Spirit"),
        .nome = _("Espírito Errante"),
        .nombre = _("Alma Errante"),
        .description = COMPOUND_STRING("Trade abilities on contact."),
        .descricao = COMPOUND_STRING("Troca habilidaes no contato."),
        .descripcion = COMPOUND_STRING("Cambia habilidades al contacto."),
        .aiRating = 2,
    },

    [ABILITY_GORILLA_TACTICS] =
    {
        .name = _("Gorilla Tactics"),
        .nome = _("Tatica Gorila"),
        .nombre = _("Monotema"),
        .description = COMPOUND_STRING("Ups Attack and locks move."),
        .descricao = COMPOUND_STRING("Aumenta Atq. e prende golpe."),
        .descripcion = COMPOUND_STRING("Sube Atq. y bloquea movimiento."),
        .aiRating = 4,
    },

    [ABILITY_NEUTRALIZING_GAS] =
    {
        .name = _("Neutralizing Gas"),
        .nome = _("Gas Neutro"),
        .nombre = _("Gas Reactivo"),
        .description = COMPOUND_STRING("All Abilities are nullified."),
        .descricao = COMPOUND_STRING("Todas Habilidades são anuladas."),
        .descripcion = COMPOUND_STRING("Todas Habilidades son anuladas."),
        .aiRating = 5,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_PASTEL_VEIL] =
    {
        .name = _("Pastel Veil"),
        .nome = _("Veu Pastel"),
        .nombre = _("Velo Pastel"),
        .description = COMPOUND_STRING("Protects team from poison."),
        .descricao = COMPOUND_STRING("Protege a equipe de veneno."),
        .descripcion = COMPOUND_STRING("Protege al equipo de veneno."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_HUNGER_SWITCH] =
    {
        .name = _("Hunger Switch"),
        .nome = _("Mudapetite"),
        .nombre = _("Mutapetito"),
        .description = COMPOUND_STRING("Changes form each turn."),
        .descricao = COMPOUND_STRING("Muda forma a cada turno."),
        .descripcion = COMPOUND_STRING("Cambia forma a cada turno."),
        .aiRating = 2,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_QUICK_DRAW] =
    {
        .name = _("Quick Draw"),
        .nome = _("Reação Rápida"),
        .nombre = _("Mano Rápida"),
        .description = COMPOUND_STRING("Moves first occasionally."),
        .descricao = COMPOUND_STRING("Move-se primeiro ocasionalmente."),
        .descripcion = COMPOUND_STRING("Mueve primero ocasionalmente."),
        .aiRating = 4,
    },

    [ABILITY_UNSEEN_FIST] =
    {
        .name = _("Unseen Fist"),
        .nome = _("Punho Invisível"),
        .nombre = _("Puño Invisible"),
        .description = COMPOUND_STRING("Contact evades protection."),
        .descricao = COMPOUND_STRING("Contato ignora proteção."),
        .descripcion = COMPOUND_STRING("Contacto ignora protección."),
        .aiRating = 6,
    },

    [ABILITY_CURIOUS_MEDICINE] =
    {
        .name = _("Curious Medicine"),
        .nome = _("Remédio Estranho"),
        .nombre = _("Medicina Extraña"),
        .description = COMPOUND_STRING("Remove ally's stat changes."),
        .descricao = COMPOUND_STRING("Remove mudanças de stat do aliado."),
        .descripcion = COMPOUND_STRING("Regola cambios de stat del aliado."),
        .aiRating = 3,
    },

    [ABILITY_TRANSISTOR] =
    {
        .name = _("Transistor"),
        .nome = _("Transistor"),
        .nombre = _("Transistor"),
        .description = COMPOUND_STRING("Ups Electric-type moves."),
        .descricao = COMPOUND_STRING("Aumenta golpes tipo Eletrico."),
        .descripcion = COMPOUND_STRING("Sube golpes tipo Electrico."),
        .aiRating = 6,
    },

    [ABILITY_DRAGONS_MAW] =
    {
        .name = _("Dragon's Maw"),
        .nome = _("Boca de Dragao"),
        .nombre = _("Mandíbula Dragón"),
        .description = COMPOUND_STRING("Ups Dragon-type moves."),
        .descricao = COMPOUND_STRING("Aumenta golpes tipo Dragao."),
        .descripcion = COMPOUND_STRING("Sube golpes tipo Dragón."),
        .aiRating = 6,
    },

    [ABILITY_CHILLING_NEIGH] =
    {
        .name = _("Chilling Neigh"),
        .nome = _("Relincho Branco"),
        .nombre = _("Relincho Blanco"),
        .description = COMPOUND_STRING("KOs boost Attack stat."),
        .descricao = COMPOUND_STRING("Nocautes aumentam Atq."),
        .descripcion = COMPOUND_STRING("Nocauts aumentan Atq."),
        .aiRating = 7,
    },

    [ABILITY_GRIM_NEIGH] =
    {
        .name = _("Grim Neigh"),
        .nome = _("Relincho Negro"),
        .nombre = _("Relincho Negro"),
        .description = COMPOUND_STRING("KOs boost Sp. Atk stat."),
        .descricao = COMPOUND_STRING("Nocautes aumentam Atq. Esp."),
        .descripcion = COMPOUND_STRING("Nocauts aumentan Atq. Esp."),
        .aiRating = 7,
    },

    [ABILITY_AS_ONE_ICE_RIDER] =
    {
        .name = _("As One"),
        .nome = _("Unisono Gelido"),
        .nombre = _("Unisono Gelido"),
        .description = COMPOUND_STRING("Unnerve and Chilling Neigh."),
        .descricao = COMPOUND_STRING("Unnerve and Chilling Neigh"),
        .descripcion = COMPOUND_STRING("Unnerve and Chilling Neigh"),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_AS_ONE_SHADOW_RIDER] =
    {
        .name = _("As One"),
        .nome = _("Unisono Sombrio"),
        .nombre = _("Unisono Umbrio"),
        .description = COMPOUND_STRING("Unnerve and Grim Neigh."),
        .descricao = COMPOUND_STRING("Unnerve and Grim Neigh"),
        .descripcion = COMPOUND_STRING("Unnerve and Grim Neigh"),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_LINGERING_AROMA] =
    {
        .name = _("Lingering Aroma"),
        .nome = _("Aroma Persist."),
        .nombre = _("Olor Persistente"),
        .description = COMPOUND_STRING("Spreads with contact."),
        .descricao = COMPOUND_STRING("Se espalha com contato"),
        .descripcion = COMPOUND_STRING("Se esparce con contacto"),
        .aiRating = 5,
    },

    [ABILITY_SEED_SOWER] =
    {
        .name = _("Seed Sower"),
        .nome = _("Semeador"),
        .nombre = _("Disemillar"),
        .description = COMPOUND_STRING("Affects terrain when hit."),
        .descricao = COMPOUND_STRING("Afeta o terreno se atingido."),
        .descripcion = COMPOUND_STRING("Afecta el terreno si golpeado."),
        .aiRating = 5,
    },

    [ABILITY_THERMAL_EXCHANGE] =
    {
        .name = _("Thermal Exchange"),
        .nome = _("Troca Termal"),
        .nombre = _("Termoscambio"),
        .description = COMPOUND_STRING("Fire hits up Attack."),
        .descricao = COMPOUND_STRING("Golpes de Fogo aumentam Atq."),
        .descripcion = COMPOUND_STRING("Golpes de Fuego aumentan Atq."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_ANGER_SHELL] =
    {
        .name = _("Anger Shell"),
        .nome = _("Carapaça da Ira"),
        .nombre = _("Coraza Ira"),
        .description = COMPOUND_STRING("Gets angry at half HP."),
        .descricao = COMPOUND_STRING("Se enfurece com metade do HP."),
        .descripcion = COMPOUND_STRING("Se enfurece Con la mitad de PS."),
        .aiRating = 3,
    },

    [ABILITY_PURIFYING_SALT] =
    {
        .name = _("Purifying Salt"),
        .nome = _("Sal Purificador"),
        .nombre = _("Sal Purificadora"),
        .description = COMPOUND_STRING("Protected by pure salts."),
        .descricao = COMPOUND_STRING("Protegido por sais puros."),
        .descripcion = COMPOUND_STRING("Protegido por sales puros."),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_WELL_BAKED_BODY] =
    {
        .name = _("Well-Baked Body"),
        .nome = _("Corpo Bem Assado"),
        .nombre = _("Cuerpo Horneado"),
        .description = COMPOUND_STRING("Strengthened by Fire."),
        .descricao = COMPOUND_STRING("Fortalecido por Fogo."),
        .descripcion = COMPOUND_STRING("Fortalecido por Fuego."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_WIND_RIDER] =
    {
        .name = _("Wind Rider"),
        .nome = _("Filho do Vento"),
        .nombre = _("Surcavientos"),
        .description = COMPOUND_STRING("Ups Attack if hit by wind."),
        .descricao = COMPOUND_STRING("Aum. Atq. se acertado por vento."),
        .descripcion = COMPOUND_STRING("Aum. Atq. si golpeado por viento."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_GUARD_DOG] =
    {
        .name = _("Guard Dog"),
        .nome = _("Cão de Guarda"),
        .nombre = _("Perro Guardián"),
        .description = COMPOUND_STRING("Cannot be intimidated."),
        .descricao = COMPOUND_STRING("Nao pode ser intimidado."),
        .descripcion = COMPOUND_STRING("No puede ser intimidado."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_ROCKY_PAYLOAD] =
    {
        .name = _("Rocky Payload"),
        .nome = _("Carga Rochosa"),
        .nombre = _("Transportarrocas"),
        .description = COMPOUND_STRING("Powers up Rock moves."),
        .descricao = COMPOUND_STRING("Fortalece golpes de Pedra."),
        .descripcion = COMPOUND_STRING("Potencia movimientos de Roca."),
        .aiRating = 6,
    },

    [ABILITY_WIND_POWER] =
    {
        .name = _("Wind Power"),
        .nome = _("Energia Eólica"),
        .nombre = _("Energía Eólica"),
        .description = COMPOUND_STRING("Gets charged by wind."),
        .descricao = COMPOUND_STRING("É carregado pelo vento."),
        .descripcion = COMPOUND_STRING("Se carga con el viento."),
        .aiRating = 4,
    },

    [ABILITY_ZERO_TO_HERO] =
    {
        .name = _("Zero to Hero"),
        .nome = _("De Zero a Herói"),
        .nombre = _("Cambio Heroico"),
        .description = COMPOUND_STRING("Changes form on switch out."),
        .descricao = COMPOUND_STRING("Muda forma na troca."),
        .descripcion = COMPOUND_STRING("Cambia forma al cambiar."),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_COMMANDER] =
    {
        .name = _("Commander"),
        .nome = _("Comandante"),
        .nombre = _("Comandar"),
        .description = COMPOUND_STRING("Commands from Dondozo."),
        .descricao = COMPOUND_STRING("Comanda do Dondozo"),
        .descripcion = COMPOUND_STRING("Comanda del Dondozo"),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_ELECTROMORPHOSIS] =
    {
        .name = _("Electromorphosis"),
        .nome = _("Electromorfose"),
        .nombre = _("Dinamo"),
        .description = COMPOUND_STRING("Gets Charged when hit."),
        .descricao = COMPOUND_STRING("Carrega se quando atingido."),
        .descripcion = COMPOUND_STRING("Se carga cuando es golpeado."),
        .aiRating = 5,
    },

    [ABILITY_PROTOSYNTHESIS] =
    {
        .name = _("Protosynthesis"),
        .nome = _("Protosíntese"),
        .nombre = _("Paleosíntesis"),
        .description = COMPOUND_STRING("Sun boosts best stat."),
        .descricao = COMPOUND_STRING("Sol fortalece melhor stat."),
        .descripcion = COMPOUND_STRING("Sol potencia mejor stat."),
        .aiRating = 7,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_QUARK_DRIVE] =
    {
        .name = _("Quark Drive"),
        .nome = _("Impulso Quark"),
        .nombre = _("Carga Cuark"),
        .description = COMPOUND_STRING("Elec. field ups best stat."),
        .descricao = COMPOUND_STRING("Campo Elec. sobe melhor stat."),
        .descripcion = COMPOUND_STRING("Campo Elec. sube mejor stat."),
        .aiRating = 7,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_GOOD_AS_GOLD] =
    {
        .name = _("Good as Gold"),
        .nome = _("Ouro Puro"),
        .nombre = _("Cuerpo Áureo"),
        .description = COMPOUND_STRING("Avoids status moves."),
        .descricao = COMPOUND_STRING("Evita golpes de estado."),
        .descripcion = COMPOUND_STRING("Evita golpes de estado."),
        .aiRating = 8,
        .breakable = TRUE,
    },

    [ABILITY_VESSEL_OF_RUIN] =
    {
        .name = _("Vessel of Ruin"),
        .nome = _("Urna da Ruína"),
        .nombre = _("Caldero Debacle"),
        .description = COMPOUND_STRING("Lowers foes' sp. damage."),
        .descricao = COMPOUND_STRING("Baixa dano sp. do oponente."),
        .descripcion = COMPOUND_STRING("Baja daño sp. del oponente."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_SWORD_OF_RUIN] =
    {
        .name = _("Sword of Ruin"),
        .nome = _("Espada da Ruína"),
        .nombre = _("Espada Debacle"),
        .description = COMPOUND_STRING("Lowers foes' Defense."),
        .descricao = COMPOUND_STRING("Baixa Def. do oponente."),
        .descripcion = COMPOUND_STRING("Baja Def. del oponente."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_TABLETS_OF_RUIN] =
    {
        .name = _("Tablets of Ruin"),
        .nome = _("Tábuas da Ruína"),
        .nombre = _("Tablilla Debacle"),
        .description = COMPOUND_STRING("Lowers foes' damage."),
        .descricao = COMPOUND_STRING("Baixa dano do oponente."),
        .descripcion = COMPOUND_STRING("Baja daño del oponente."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_BEADS_OF_RUIN] =
    {
        .name = _("Beads of Ruin"),
        .nome = _("Pérolas da Ruína"),
        .nombre = _("Abalorio Debacle"),
        .description = COMPOUND_STRING("Lowers foes' Sp. Defense."),
        .descricao = COMPOUND_STRING("Baixa Def. Esp. do oponente."),
        .descripcion = COMPOUND_STRING("Baja Def. Esp. del oponente."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_ORICHALCUM_PULSE] =
    {
        .name = _("Orichalcum Pulse"),
        .nome = _("Pulso Oricalco"),
        .nombre = _("Latido Oricalco"),
        .description = COMPOUND_STRING("Summons sunlight in battle."),
        .descricao = COMPOUND_STRING("Invoca luz solar em batalha."),
        .descripcion = COMPOUND_STRING("Invoca luz solar en batalla."),
        .aiRating = 8,
        .cantBeSwapped = TRUE,
        .cantBeCopied = TRUE,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_HADRON_ENGINE] =
    {
        .name = _("Hadron Engine"),
        .nome = _("Motor Hádron"),
        .nombre = _("Motor Hadrónico"),
        .description = COMPOUND_STRING("Field becomes Electric."),
        .descricao = COMPOUND_STRING("Terreno se torna Eletrico."),
        .descripcion = COMPOUND_STRING("El terreno se vuelve Eléctrico."),
        .aiRating = 8,
        .cantBeSwapped = TRUE,
        .cantBeCopied = TRUE,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_OPPORTUNIST] =
    {
        .name = _("Opportunist"),
        .nome = _("Oportunista"),
        .nombre = _("Oportunista"),
        .description = COMPOUND_STRING("Copies foe's stat change."),
        .descricao = COMPOUND_STRING("Copia mudança de stat do rival."),
        .descripcion = COMPOUND_STRING("Copia cambio de stat del rival."),
        .aiRating = 5,
    },

    [ABILITY_CUD_CHEW] =
    {
        .name = _("Cud Chew"),
        .nome = _("Ruminante"),
        .nombre = _("Rumia"),
        .description = COMPOUND_STRING("Eats a used berry again."),
        .descricao = COMPOUND_STRING("Come uma berry usada novamente."),
        .descripcion = COMPOUND_STRING("Come una baya usada nuevamente."),
        .aiRating = 4,
    },

    [ABILITY_SHARPNESS] =
    {
        .name = _("Sharpness"),
        .nome = _("Afiação"),
        .nombre = _("Cortante"),
        .description = COMPOUND_STRING("Strengthens slicing moves."),
        .descricao = COMPOUND_STRING("Fortalece golpes de corte."),
        .descripcion = COMPOUND_STRING("Potencia movimientos cortantes."),
        .aiRating = 7,
    },

    [ABILITY_SUPREME_OVERLORD] =
    {
        .name = _("Supreme Overlord"),
        .nome = _("Senhor Supremo"),
        .nombre = _("General Supremo"),
        .description = COMPOUND_STRING("Inherits fallen's strength."),
        .descricao = COMPOUND_STRING("Herda força do aliado caído."),
        .descripcion = COMPOUND_STRING("Hereda fuerza del aliado caído."),
        .aiRating = 6,
    },

    [ABILITY_COSTAR] =
    {
        .name = _("Costar"),
        .nome = _("Dupla Dinâmica"),
        .nombre = _("Unísono"),
        .description = COMPOUND_STRING("Copies ally's stat changes."),
        .descricao = COMPOUND_STRING("Copia mudança de stat do aliado."),
        .descripcion = COMPOUND_STRING("Copia cambio de stat del aliado."),
        .aiRating = 5,
    },

    [ABILITY_TOXIC_DEBRIS] =
    {
        .name = _("Toxic Debris"),
        .nome = _("Detrito Tóxico"),
        .nombre = _("Capa Tóxica"),
        .description = COMPOUND_STRING("Throws poison spikes if hit."),
        .descricao = COMPOUND_STRING("Solta espinhos veneno se acertado."),
        .descripcion = COMPOUND_STRING("Si golpeado, lanza púas venenosas."),
        .aiRating = 4,
    },

    [ABILITY_ARMOR_TAIL] =
    {
        .name = _("Armor Tail"),
        .nome = _("Cauda Armadura"),
        .nombre = _("Cola Armadura"),
        .description = COMPOUND_STRING("Protects from priority."),
        .descricao = COMPOUND_STRING("Protege de prioridade."),
        .descripcion = COMPOUND_STRING("Protege de prioridad."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_EARTH_EATER] =
    {
        .name = _("Earth Eater"),
        .nome = _("Comedor de Terra"),
        .nombre = _("Geofagia"),
        .description = COMPOUND_STRING("Eats ground to heal HP."),
        .descricao = COMPOUND_STRING("Come terra para curar HP."),
        .descripcion = COMPOUND_STRING("Come tierra para curar PS."),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_MYCELIUM_MIGHT] =
    {
        .name = _("Mycelium Might"),
        .nome = _("Poder do Micélio"),
        .nombre = _("Poder Fúngico"),
        .description = COMPOUND_STRING("Status moves never fail."),
        .descricao = COMPOUND_STRING("Golpes de estado nunca falham."),
        .descripcion = COMPOUND_STRING("Golpes de estado nunca fallan."),
        .aiRating = 2,
    },

    [ABILITY_HOSPITALITY] =
    {
        .name = _("Hospitality"),
        .nome = _("Hospitalidade"),
        .nombre = _("Hospitalidad"),
        .description = COMPOUND_STRING("Restores ally's HP."),
        .descricao = COMPOUND_STRING("Restaura HP do aliado."),
        .descripcion = COMPOUND_STRING("Restaura PS del aliado."),
        .aiRating = 5,
    },

    [ABILITY_MINDS_EYE] =
    {
        .name = _("Mind's Eye"),
        .nome = _("Olho Mental"),
        .nombre = _("Ojo mental"),
        .description = COMPOUND_STRING("Keen Eye and Scrappy."),
        .descricao = COMPOUND_STRING("Keen Eye and Scrappy"),
        .descripcion = COMPOUND_STRING("Keen Eye and Scrappy"),
        .aiRating = 8,
        .breakable = TRUE,
    },

    [ABILITY_EMBODY_ASPECT_TEAL_MASK] =
    {
        .name = _("Embody Aspect"),
        .nome = _("Aspecto Turquesa"),
        .nombre = _("Aspecto Turquesa"),
        .description = COMPOUND_STRING("Raises Speed."),
        .descricao = COMPOUND_STRING("Aumenta Velocidade."),
        .descripcion = COMPOUND_STRING("Sube Velocidad."),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_EMBODY_ASPECT_HEARTHFLAME_MASK] =
    {
        .name = _("Embody Aspect"),
        .nome = _("Aspecto Flama"),
        .nombre = _("Aspecto Hoguera"),
        .description = COMPOUND_STRING("Raises Attack."),
        .descricao = COMPOUND_STRING("Aumenta Ataque."),
        .descripcion = COMPOUND_STRING("Sube Ataque."),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_EMBODY_ASPECT_WELLSPRING_MASK] =
    {
        .name = _("Embody Aspect"),
        .nome = _("Aspecto Fonte"),
        .nombre = _("Aspecto Fuente"),
        .description = COMPOUND_STRING("Raises Sp. Def."),
        .descricao = COMPOUND_STRING("Aumenta Def. Esp."),
        .descripcion = COMPOUND_STRING("Sube Def. Esp."),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_EMBODY_ASPECT_CORNERSTONE_MASK] =
    {
        .name = _("Embody Aspect"),
        .nome = _("Aspecto Rocha"),
        .nombre = _("Aspecto Roca"),
        .description = COMPOUND_STRING("Raises Defense."),
        .descricao = COMPOUND_STRING("Aumenta Defesa."),
        .descripcion = COMPOUND_STRING("Sube Defensa."),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_TOXIC_CHAIN] =
    {
        .name = _("Toxic Chain"),
        .nome = _("Corrente Tóxica"),
        .nombre = _("Cadena tóxica"),
        .description = COMPOUND_STRING("Moves can poison."),
        .descricao = COMPOUND_STRING("Golpes podem envenenar."),
        .descripcion = COMPOUND_STRING("Golpes pueden envenenar."),
        .aiRating = 8,
    },

    [ABILITY_SUPERSWEET_SYRUP] =
    {
        .name = _("Supersweet Syrup"),
        .nome = _("Calda Adocicada"),
        .nombre = _("Néctar dulce"),
        .description = COMPOUND_STRING("Lowers the foe's Evasion."),
        .descricao = COMPOUND_STRING("Baixa Evasão do oponente."),
        .descripcion = COMPOUND_STRING("Baja Evasión del oponente."),
        .aiRating = 5,
    },

    [ABILITY_TERA_SHIFT] =
    {
        .name = _("Tera Shift"),
        .nome = _("Mudança Tera"),
        .nombre = _("Teracambio"),
        .description = COMPOUND_STRING("Terastallizes upon entry."),
        .descricao = COMPOUND_STRING("Teracristaliza ao entrar."),
        .descripcion = COMPOUND_STRING("Teracristaliza al entrar."),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_TERA_SHELL] =
    {
        .name = _("Tera Shell"),
        .nome = _("Casco Tera"),
        .nombre = _("Teracaparazón"),
        .description = COMPOUND_STRING("Resists all at full HP."),
        .descricao = COMPOUND_STRING("Resiste a tudo com HP cheio."),
        .descripcion = COMPOUND_STRING("Resiste a todo con PS lleno."),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .breakable = TRUE,
    },

    [ABILITY_TERAFORM_ZERO] =
    {
        .name = _("Teraform Zero"),
        .nome = _("Teraforma Zero"),
        .nombre = _("Teraformación 0"),
        .description = COMPOUND_STRING("Zeroes weather and terrain."),
        .descricao = COMPOUND_STRING("Zera clima e terreno."),
        .descripcion = COMPOUND_STRING("Zera clima y terreno."),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_POISON_PUPPETEER] =
    {
        .name = _("Poison Puppeteer"),
        .nome = _("Titere Toxico"),
        .nombre = _("Títere tóxico"),
        .description = COMPOUND_STRING("Confuses poisoned foes."),
        .descricao = COMPOUND_STRING("Confunde oponentes envenenados."),
        .descripcion = COMPOUND_STRING("Confunde rivales envenenados."),
        .aiRating = 8,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_PIERCING_DRILL] =
    {
        .name = _("Piercing Drill"),
        .description = COMPOUND_STRING("Contact evades protection."),
    },

    [ABILITY_DRAGONIZE] =
    {
        .name = _("Dragonize"),
        .description = COMPOUND_STRING("Normal moves turn Dragon."),
    },

    [ABILITY_313] =
    {
        .name = _("-------"),
        .description = COMPOUND_STRING("No special ability."),
    },

    [ABILITY_314] =
    {
        .name = _("-------"),
        .description = COMPOUND_STRING("No special ability."),
    },

    [ABILITY_MEGA_SOL] =
    {
        .name = _("Mega Sol"),
        .description = COMPOUND_STRING("Acts like under sun."),
    },

    [ABILITY_316] =
    {
        .name = _("-------"),
        .description = COMPOUND_STRING("No special ability."),
    },

    [ABILITY_317] =
    {
        .name = _("-------"),
        .description = COMPOUND_STRING("No special ability."),
    },

    [ABILITY_SPICY_SPRAY] =
    {
        .name = _("Spicy Spray"),
        .description = COMPOUND_STRING("Burns the foe when damaged."),
    },
};
