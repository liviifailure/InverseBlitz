#include "global.h"
#include "event_data.h"
#include "pokemon.h"
#include "constants/moves.h"
#include "constants/species.h"
#include "constants/items.h"
#include "evolution_scene.h"
#include "overworld.h"

// Checks if a specific species meets the Energy Guru's criteria
// Criteria: Evolves via Level Up > 30 AND the target species can evolve again.
static u16 GetEnergyGuruEvolutionTarget(u16 species)
{
    int i;
    const struct Evolution *evolutions = GetSpeciesEvolutions(species);

    if (evolutions == NULL)
        return SPECIES_NONE;

    for (i = 0; evolutions[i].method != EVOLUTIONS_END; i++)
    {
        if (evolutions[i].method == EVO_LEVEL && evolutions[i].param > 30)
        {
            // Check if the target species can evolve further
            const struct Evolution *targetEvolutions = GetSpeciesEvolutions(evolutions[i].targetSpecies);
            if (targetEvolutions != NULL && targetEvolutions[0].method != EVOLUTIONS_END)
            {
                return evolutions[i].targetSpecies;
            }
        }
    }

    return SPECIES_NONE;
}

void CheckPartyForEnergyGuruMon(void)
{
    int i;
    struct Pokemon *mon;
    u16 species;

    gSpecialVar_Result = FALSE;

    for (i = 0; i < gPlayerPartyCount; i++)
    {
        mon = &gPlayerParty[i];
        species = GetMonData(mon, MON_DATA_SPECIES, NULL);

        if (!GetMonData(mon, MON_DATA_IS_EGG, NULL) && GetEnergyGuruEvolutionTarget(species) != SPECIES_NONE)
        {
            gSpecialVar_Result = TRUE;
            return;
        }
    }
}

void CheckSelectedMonForEnergyGuru(void)
{
    u16 species;
    struct Pokemon *mon = &gPlayerParty[gSpecialVar_0x8004];

    gSpecialVar_Result = FALSE;

    if (GetMonData(mon, MON_DATA_IS_EGG, NULL))
        return;

    species = GetMonData(mon, MON_DATA_SPECIES, NULL);
    if (GetEnergyGuruEvolutionTarget(species) != SPECIES_NONE)
    {
        gSpecialVar_Result = TRUE;
    }
}

void TriggerEnergyGuruEvolution(void)
{
    u16 species;
    u16 targetSpecies;
    struct Pokemon *mon = &gPlayerParty[gSpecialVar_0x8004];

    species = GetMonData(mon, MON_DATA_SPECIES, NULL);
    targetSpecies = GetEnergyGuruEvolutionTarget(species);

    if (targetSpecies != SPECIES_NONE)
    {
        gCB2_AfterEvolution = CB2_ReturnToField;
        // Trigger evolution scene
        BeginEvolutionScene(mon, targetSpecies, TRUE, gSpecialVar_0x8004);
    }
}

// Checks if a specific species meets the Effort Ribbon Woman's criteria
// Criteria:
// 1. Current form didn't evolve from any pokemon (Base stage).
// 2. Evolves via Level Up > 36.
// 3. Target species cannot evolve further (Only evolves one more time).
static u16 GetEffortRibbonEvolutionTarget(u16 species)
{
    int i;
    const struct Evolution *evolutions;

    // Condition 1: Current form didn't evolve from any pokemon
    if (GetSpeciesPreEvolution(species) != SPECIES_NONE)
        return SPECIES_NONE;

    evolutions = GetSpeciesEvolutions(species);
    if (evolutions == NULL)
        return SPECIES_NONE;

    for (i = 0; evolutions[i].method != EVOLUTIONS_END; i++)
    {
        // Condition 2: Evolves via Level Up > 36
        if (evolutions[i].method == EVO_LEVEL && evolutions[i].param > 36)
        {
            // Condition 3: Target species cannot evolve further
            const struct Evolution *targetEvolutions = GetSpeciesEvolutions(evolutions[i].targetSpecies);
            if (targetEvolutions == NULL || targetEvolutions[0].method == EVOLUTIONS_END)
            {
                return evolutions[i].targetSpecies;
            }
        }
    }

    return SPECIES_NONE;
}

void CheckPartyForEffortRibbonMon(void)
{
    int i;
    struct Pokemon *mon;
    u16 species;

    gSpecialVar_Result = FALSE;

    for (i = 0; i < gPlayerPartyCount; i++)
    {
        mon = &gPlayerParty[i];
        species = GetMonData(mon, MON_DATA_SPECIES, NULL);

        if (!GetMonData(mon, MON_DATA_IS_EGG, NULL) && GetEffortRibbonEvolutionTarget(species) != SPECIES_NONE)
        {
            gSpecialVar_Result = TRUE;
            return;
        }
    }
}

void CheckSelectedMonForEffortRibbon(void)
{
    u16 species;
    struct Pokemon *mon = &gPlayerParty[gSpecialVar_0x8004];

    gSpecialVar_Result = FALSE;

    if (GetMonData(mon, MON_DATA_IS_EGG, NULL))
        return;

    species = GetMonData(mon, MON_DATA_SPECIES, NULL);
    if (GetEffortRibbonEvolutionTarget(species) != SPECIES_NONE)
    {
        gSpecialVar_Result = TRUE;
    }
}

void TriggerEffortRibbonEvolution(void)
{
    u16 species;
    u16 targetSpecies;
    struct Pokemon *mon = &gPlayerParty[gSpecialVar_0x8004];

    species = GetMonData(mon, MON_DATA_SPECIES, NULL);
    targetSpecies = GetEffortRibbonEvolutionTarget(species);

    if (targetSpecies != SPECIES_NONE)
    {
        gCB2_AfterEvolution = CB2_ReturnToField;
        // Trigger evolution scene
        BeginEvolutionScene(mon, targetSpecies, TRUE, gSpecialVar_0x8004);
    }
}