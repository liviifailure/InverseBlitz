#include "global.h"
#include "menu.h"
#include "party_menu.h"
#include "item_menu.h"
#include "item_use.h" // Needed for ItemUseCB_RareCandy
#include "pokemon.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "constants/party_menu.h"
#include "constants/songs.h"
#include "constants/moves.h"
#include "fldeff.h"
#include "event_data.h"

static void Task_SoftboiledRestoreHealth(u8 taskId);
//static void Task_DisplayHPRestoredMessage(u8 taskId);
static void Task_FinishSoftboiled(u8 taskId);
static void CantUseSoftboiledOnMon(u8 taskId);

bool32 SetUpFieldMove_SoftBoiled(void)
{
    u16 maxHp;
    u16 hp;
    u16 minHp;

    maxHp = GetMonData(&gPlayerParty[GetCursorSelectionMonId()], MON_DATA_MAX_HP);
    hp = GetMonData(&gPlayerParty[GetCursorSelectionMonId()], MON_DATA_HP);

    minHp = (maxHp / 5);
    if (hp > minHp)
        return TRUE;
    return FALSE;
}

void ChooseMonForSoftboiled(u8 taskId)
{
    gPartyMenu.action = PARTY_ACTION_SOFTBOILED;
    gPartyMenu.slotId2 =  gPartyMenu.slotId;
    AnimatePartySlot(GetCursorSelectionMonId(), 1);
    DisplayPartyMenuStdMessage(PARTY_MSG_USE_ON_WHICH_MON);
    gTasks[taskId].func = Task_HandleChooseMonInput;
}

void Task_TryUseSoftboiledOnPartyMon(u8 taskId)
{
    u8 userPartyId = gPartyMenu.slotId;
    u8 recipientPartyId = gPartyMenu.slotId2;
    u16 move;
    int i;

    if (recipientPartyId > PARTY_SIZE)
    {
        gPartyMenu.action = 0;
        DisplayPartyMenuStdMessage(PARTY_MSG_CHOOSE_MON);
        gTasks[taskId].func = Task_HandleChooseMonInput;
        return;
    }
    
    // Check if the user knows MOVE_MILK_DRINK
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        move = GetMonData(&gPlayerParty[userPartyId], MON_DATA_MOVE1 + i);
        if (move == MOVE_MILK_DRINK)
        {
            if (userPartyId == recipientPartyId) // Cannot use on self
            {
                CantUseSoftboiledOnMon(taskId);
                return;
            }
            Task_SoftboiledRestoreHealth(taskId); // Skip HP reduction for Milk Drink
            return;
        }
    }

      //   if (GetMonData(&gPlayerParty[recipientPartyId], MON_DATA_HP) == 0 || userPartyId == recipientPartyId || GetMonData(&gPlayerParty[recipientPartyId], MON_DATA_MAX_HP) == GetMonData(&gPlayerParty[recipientPartyId], MON_DATA_HP))
     //    {
     //        CantUseSoftboiledOnMon(taskId);
     //        return;
    //     }

    // Take away Softboiled user's health first (-1)
     //    PlaySE(SE_USE_ITEM);
     //    PartyMenuModifyHP(taskId, userPartyId, -1, GetMonData(&gPlayerParty[userPartyId], MON_DATA_MAX_HP)/5, Task_SoftboiledRestoreHealth);
}

static void Task_SoftboiledRestoreHealth(u8 taskId)
{
    PlaySE(SE_USE_ITEM);
    
    u8 userPartyId = gPartyMenu.slotId;
    u8 recipientPartyId = gPartyMenu.slotId2;
    u16 move;
    int i;

    // Check if the user knows MOVE_MILK_DRINK
    for (i = 0; i < MAX_MON_MOVES; i++) // This loop is now also in Task_TryUseSoftboiledOnPartyMon
    {
        move = GetMonData(&gPlayerParty[userPartyId], MON_DATA_MOVE1 + i);
        if (move == MOVE_MILK_DRINK) 
        {
            // Set persistent flag so this species group can no longer use Milk Drink from the party menu
            u16 userSpecies = GetMonData(&gPlayerParty[userPartyId], MON_DATA_SPECIES);
            if (userSpecies == SPECIES_MAREEP)
                FlagSet(FLAG_MAREEP_USED_MILK_DRINK);
            else if (userSpecies == SPECIES_FLAAFFY)
                FlagSet(FLAG_MAREEP_USED_MILK_DRINK);
            else if (userSpecies == SPECIES_AMPHAROS)
                FlagSet(FLAG_MAREEP_USED_MILK_DRINK);
            else if (userSpecies == SPECIES_SKIDDO)
                FlagSet(FLAG_SKIDDO_USED_MILK_DRINK);
            else if (userSpecies == SPECIES_GOGOAT)
                FlagSet(FLAG_SKIDDO_USED_MILK_DRINK);
            else if (userSpecies == SPECIES_SMEARGLE)
                FlagSet(FLAG_SMEARGLE_USED_MILK_DRINK);
            else if (userSpecies == SPECIES_MILTANK)
                FlagSet(FLAG_MILTANK_USED_MILK_DRINK);

            gSpecialVar_ItemId = ITEM_RARE_CANDY; // Simulate using a Rare Candy
            gIsFromFieldMove = TRUE;
            gPartyMenu.slotId = recipientPartyId; // Target the recipient Pokémon
            ItemUseCB_RareCandy(taskId, Task_FinishSoftboiled); // Call Rare Candy logic, then finish Milk Drink flow
            return; // Prevent standard Softboiled HP restoration
        }
    }
    // This part is now only for Soft-Boiled
    //    PartyMenuModifyHP(taskId, gPartyMenu.slotId2, 1, GetMonData(&gPlayerParty[gPartyMenu.slotId], MON_DATA_MAX_HP)/5, Task_DisplayHPRestoredMessage);
}

//static void Task_DisplayHPRestoredMessage(u8 taskId)
//{
//    GetMonNickname(&gPlayerParty[gPartyMenu.slotId2], gStringVar1);
//    StringExpandPlaceholders(gStringVar4, gText_PkmnHPRestoredByVar2);
//    DisplayPartyMenuMessage(gStringVar4, FALSE);
//    ScheduleBgCopyTilemapToVram(2);
//    gTasks[taskId].func = Task_FinishSoftboiled;
// }

static void Task_FinishSoftboiled(u8 taskId)
{
    gPartyMenu.action = 0;
    AnimatePartySlot(gPartyMenu.slotId, 0);
    gPartyMenu.slotId = gPartyMenu.slotId2;
    AnimatePartySlot(gPartyMenu.slotId2, 1);
    ClearStdWindowAndFrameToTransparent(6, FALSE);
    ClearWindowTilemap(6);
    DisplayPartyMenuStdMessage(PARTY_MSG_CHOOSE_MON);
    gTasks[taskId].func = Task_HandleChooseMonInput;
}

static void Task_ChooseNewMonForSoftboiled(u8 taskId)
{
    if (IsPartyMenuTextPrinterActive() == TRUE)
        return;
    DisplayPartyMenuStdMessage(PARTY_MSG_USE_ON_WHICH_MON);
    gTasks[taskId].func = Task_HandleChooseMonInput;
}

static void CantUseSoftboiledOnMon(u8 taskId)
{
    PlaySE(SE_SELECT);
    DisplayPartyMenuMessage(gText_CantBeUsedOnPkmn, FALSE);
    ScheduleBgCopyTilemapToVram(2);
    gTasks[taskId].func = Task_ChooseNewMonForSoftboiled;
}
