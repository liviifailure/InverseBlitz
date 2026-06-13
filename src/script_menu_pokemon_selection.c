#include "global.h"
#include "script.h"
#include "random.h"
#include "script_menu.h"
#include "string_util.h"
#include "strings.h"
#include "pokemon.h"
#include "constants/species.h"
#include "data/pokemon/form_species_tables.h"
#include "constants/flags.h"
#include "event_data.h"

static const u8 sText_Random[] = _("Random");
static const u8 sText_MysteryEgg[] = _("Mystery Egg");

struct GiftPokemon
{
    u16 species;
    u8 cost;
};

static const struct GiftPokemon sGiftPokemonList[] = {
    {SPECIES_ABRA, 0},
    {SPECIES_AIPOM, 0},
    {SPECIES_ANORITH, 0},
    {SPECIES_ARROKUDA, 0},
    {SPECIES_AUDINO, 0},
    {SPECIES_AXEW, 0},
    {SPECIES_BALTOY, 0},
    {SPECIES_BARBOACH, 0},
    {SPECIES_BELLSPROUT, 0},
    {SPECIES_BERGMITE, 0},
    {SPECIES_BIDOOF, 0},
    {SPECIES_BRAMBLIN, 0},
    {SPECIES_BRONZOR, 0},
    {SPECIES_CAPSAKID, 0},
    {SPECIES_CARBINK, 0},
    {SPECIES_CARNIVINE, 0},
    {SPECIES_CATERPIE, 0},
    {SPECIES_CHATOT, 0},
    {SPECIES_CHERUBI, 0},
    {SPECIES_CHIKORITA, 0},
    {SPECIES_COMBEE, 0},
    {SPECIES_COMFEY, 0},
    {SPECIES_CRABRAWLER, 0},
    {SPECIES_CRAMORANT, 0},
    {SPECIES_CRANIDOS, 0},
    {SPECIES_CUBCHOO, 0},
    {SPECIES_DARUMAKA_GALAR, 0},
    {SPECIES_DEDENNE, 0},
    {SPECIES_DEINO, 0},
    {SPECIES_DELIBIRD, 0},
    {SPECIES_DIGLETT_ALOLA, 0},
    {SPECIES_DODUO, 0},
    {SPECIES_DRATINI, 0},
    {SPECIES_DREEPY, 0},
    {SPECIES_DROWZEE, 0},
    {SPECIES_DUNSPARCE, 0},
    {SPECIES_DWEBBLE, 0},
    {SPECIES_EISCUE_ICE, 0},
    {SPECIES_FARFETCHD, 0},
    {SPECIES_FERROSEED, 0},
    {SPECIES_FINNEON, 0},
    {SPECIES_FLITTLE, 0},
    {SPECIES_FOMANTIS, 0},
    {SPECIES_FOONGUS, 0},
    {SPECIES_GEODUDE_ALOLA, 0},
    {SPECIES_GIMMIGHOUL, 0},
    {SPECIES_GIRAFARIG, 0},
    {SPECIES_GLAMEOW, 0},
    {SPECIES_GLIMMET, 0},
    {SPECIES_GOLDEEN, 0},
    {SPECIES_GOLETT, 0},
    {SPECIES_GRIMER, 0},
    {SPECIES_GROOKEY, 0},
    {SPECIES_GROWLITHE_HISUI, 0},
    {SPECIES_GULPIN, 0},
    {SPECIES_HAPPINY, 0},
    {SPECIES_HOOTHOOT, 0},
    {SPECIES_HOPPIP, 0},
    {SPECIES_ILLUMISE, 0},
    {SPECIES_KABUTO, 0},
    {SPECIES_KARRABLAST, 0},
    {SPECIES_KECLEON, 0},
    {SPECIES_KLEFKI, 0},
    {SPECIES_KLINK, 0},
    {SPECIES_KOFFING, 0},
    {SPECIES_KOMALA, 0},
    {SPECIES_KRABBY, 0},
    {SPECIES_KRICKETOT, 0},
    {SPECIES_KUBFU, 0},
    {SPECIES_LARVESTA, 0},
    {SPECIES_LECHONK, 0},
    {SPECIES_LEDYBA, 0},
    {SPECIES_LICKITUNG, 0},
    {SPECIES_LILEEP, 0},
    {SPECIES_LUVDISC, 0},
    {SPECIES_MAGIKARP, 0},
    {SPECIES_MAREANIE, 0},
    {SPECIES_MASCHIFF, 0},
    {SPECIES_MEOWTH_ALOLA, 0},
    {SPECIES_MIENFOO, 0},
    {SPECIES_MILCERY, 0},
    {SPECIES_MORPEKO, 0},
    {SPECIES_MUNNA, 0},
    {SPECIES_NACLI, 0},
    {SPECIES_NATU, 0},
    {SPECIES_NIDORAN_F, 0},
    {SPECIES_NIDORAN_M, 0},
    {SPECIES_OMANYTE, 0},
    {SPECIES_PACHIRISU, 0},
    {SPECIES_PANPOUR, 0},
    {SPECIES_PANSAGE, 0},
    {SPECIES_PATRAT, 0},
    {SPECIES_PAWMI, 0},
    {SPECIES_PAWNIARD, 0},
    {SPECIES_PETILIL, 0},
    {SPECIES_PHIONE, 0},
    {SPECIES_PIDGEY, 0},
    {SPECIES_PIDOVE, 0},
    {SPECIES_PINCURCHIN, 0},
    {SPECIES_PINECO, 0},
    {SPECIES_POIPOLE, 0},
    {SPECIES_POLTCHAGEIST, 0},
    {SPECIES_PONYTA_GALAR, 0},
    {SPECIES_PSYDUCK, 0},
    {SPECIES_PUMPKABOO, 0},
    {SPECIES_PYUKUMUKU, 0},
    {SPECIES_QUAXLY, 0},
    {SPECIES_QWILFISH_HISUI, 0},
    {SPECIES_RATTATA_ALOLA, 0},
    {SPECIES_RELLOR, 0},
    {SPECIES_RHYHORN, 0},
    {SPECIES_SANDSHREW, 0},
    {SPECIES_SCORBUNNY, 0},
    {SPECIES_SEEDOT, 0},
    {SPECIES_SEEL, 0},
    {SPECIES_SENTRET, 0},
    {SPECIES_SHELMET, 0},
    {SPECIES_SHIELDON, 0},
    {SPECIES_SILICOBRA, 0},
    {SPECIES_SINISTEA, 0},
    {SPECIES_SKITTY, 0},
    {SPECIES_SKWOVET, 0},
    {SPECIES_SLOWPOKE, 0},
    {SPECIES_SLUGMA, 0},
    {SPECIES_SMOOCHUM, 0},
    {SPECIES_SNOM, 0},
    {SPECIES_SOBBLE, 0},
    {SPECIES_SPEAROW, 0},
    {SPECIES_SPINARAK, 0},
    {SPECIES_SPINDA, 0},
    {SPECIES_SPRIGATITO, 0},
    {SPECIES_STUNFISK_GALAR, 0},
    {SPECIES_STUNKY, 0},
    {SPECIES_SUNKERN, 0},
    {SPECIES_SWABLU, 0},
    {SPECIES_TADBULB, 0},
    {SPECIES_TAILLOW, 0},
    {SPECIES_TANDEMAUS, 0},
    {SPECIES_TANGELA, 0},
    {SPECIES_TATSUGIRI, 0},
    {SPECIES_TEPIG, 0},
    {SPECIES_TOEDSCOOL, 0},
    {SPECIES_TOXEL, 0},
    {SPECIES_VANILLITE, 0},
    {SPECIES_VELUZA, 0},
    {SPECIES_VENONAT, 0},
    {SPECIES_VOLBEAT, 0},
    {SPECIES_VOLTORB, 0},
    {SPECIES_VULLABY, 0},
    {SPECIES_VULPIX, 0},
    {SPECIES_WHISMUR, 0},
    {SPECIES_WIGLETT, 0},
    {SPECIES_WIMPOD, 0},
    {SPECIES_WOOBAT, 0},
    {SPECIES_WOOLOO, 0},
    {SPECIES_WOOPER, 0},
    {SPECIES_WURMPLE, 0},
    {SPECIES_WYNAUT, 0},
    {SPECIES_YAMASK_GALAR, 0},
    {SPECIES_YUNGOOS, 0},
    {SPECIES_ZIGZAGOON, 0},
    {SPECIES_ZORUA_HISUI, 0}
};

static const struct GiftPokemon sGiftPokemonList2[] = {
    {SPECIES_EEVEE, 0},
    {SPECIES_TAUROS_PALDEA_BLAZE, 0},
    {SPECIES_TAUROS_PALDEA_AQUA, 0},
    {SPECIES_DITTO, 0},
    {SPECIES_AERODACTYL, 0},
    {SPECIES_GLIGAR, 0},
    {SPECIES_SHUCKLE, 0},
    {SPECIES_LUNATONE, 0},
    {SPECIES_SOLROCK, 0},
    {SPECIES_SPIRITOMB, 0},
    {SPECIES_THROH, 0},
    {SPECIES_SAWK, 0},
    {SPECIES_BASCULIN_WHITE_STRIPED, 0},
    {SPECIES_MARACTUS, 0},
    {SPECIES_SIGILYPH, 0},
    {SPECIES_STUNFISK, 0},
    {SPECIES_DRUDDIGON, 0},
    {SPECIES_FURFROU, 0},
    {SPECIES_ORANGURU, 0},
    {SPECIES_PASSIMIAN, 0},
    {SPECIES_TYPE_NULL, 0},
    {SPECIES_BRUXISH, 0},
    {SPECIES_INDEEDEE_F, 0},
    {SPECIES_DRACOVISH, 0},
    {SPECIES_ARCTOZOLT, 0},
    {SPECIES_DURALUDON, 0},
    {SPECIES_SQUAWKABILLY, 0},
    {SPECIES_CYCLIZAR, 0},
    {SPECIES_ORTHWORM, 0},
    {SPECIES_FLAMIGO, 0},
    {SPECIES_DONDOZO, 0}
};

u8 GetGiftMonCost(u16 species)
{
    u32 i;
    for (i = 0; i < ARRAY_COUNT(sGiftPokemonList); i++)
    {
        if (sGiftPokemonList[i].species == species)
            return sGiftPokemonList[i].cost;
    }
    for (i = 0; i < ARRAY_COUNT(sGiftPokemonList2); i++)
    {
        if (sGiftPokemonList2[i].species == species)
            return sGiftPokemonList2[i].cost;
    }
    return 0;
}

// This function builds the list of Pokémon for the multichoice menu.
void BuildGiftPokemonMenu(void)
{
    u32 i;
    u16 species;

    ScriptMenu_ClearDynMultichoice();

    for (i = 0; i < ARRAY_COUNT(sGiftPokemonList); i++)
    {
        species = sGiftPokemonList[i].species;
        if (species == SPECIES_MINIOR_CORE)
        {
            species = SPECIES_MINIOR_CORE_RED + (Random() % (SPECIES_MINIOR_CORE_VIOLET - SPECIES_MINIOR_CORE_RED + 1));
            ScriptMenu_AddDynmultichoice(gSpeciesInfo[SPECIES_MINIOR].speciesName, species, 0);
        }
        else if (species == SPECIES_FLABEBE)
        {
            species = sFlabebeFormSpeciesIdTable[Random() % (ARRAY_COUNT(sFlabebeFormSpeciesIdTable) - 1)];
            ScriptMenu_AddDynmultichoice(gSpeciesInfo[SPECIES_FLABEBE].speciesName, species, 0);
        }
        else if (species == SPECIES_SCATTERBUG)
        {
            species = sScatterbugFormSpeciesIdTable[Random() % (ARRAY_COUNT(sScatterbugFormSpeciesIdTable) - 1)];
            ScriptMenu_AddDynmultichoice(gSpeciesInfo[SPECIES_SCATTERBUG].speciesName, species, 0);
        }
        else if (species == SPECIES_DEERLING)
        {
            species = sDeerlingFormSpeciesIdTable[Random() % (ARRAY_COUNT(sDeerlingFormSpeciesIdTable) - 1)];
            ScriptMenu_AddDynmultichoice(gSpeciesInfo[SPECIES_DEERLING].speciesName, species, 0);
        }
        else if (species == SPECIES_EGG)
        {
            ScriptMenu_AddDynmultichoice(sText_MysteryEgg, species, 0);
            ScriptMenu_AddDynmultichoice(sText_Random, 1000, 0);
        }
        else
            ScriptMenu_AddDynmultichoice(gSpeciesInfo[species].speciesName, species, 0);
    }

    ScriptMenu_AddDynmultichoice(gText_Finished, 999, -1);
}

void BuildGiftPokemonMenu2(void)
{
    u32 i;

    ScriptMenu_ClearDynMultichoice();

    for (i = 0; i < ARRAY_COUNT(sGiftPokemonList2); i++)
        ScriptMenu_AddDynmultichoice(gSpeciesInfo[sGiftPokemonList2[i].species].speciesName, sGiftPokemonList2[i].species, 0);

    ScriptMenu_AddDynmultichoice(gText_Finished, 999, -1);
}
