// Copyright Guy (Drakynfly) Lundvall. All Rights Reserved.

#include "SerializationTest/FaerieDataSaveGameExample.h"
#include "FaerieItemContainerBase.h"
#include "FaerieEquipmentManager.h"

void UFaerieDataSaveGameExample::Read(const UFaerieItemContainerBase* Container)
{
	SaveData = Container->MakeSaveData();
}

void UFaerieDataSaveGameExample::Write(UFaerieItemContainerBase* Container)
{
	Container->LoadSaveData(SaveData);
}

void UFaerieDataSaveGameExample::ReadEquipment(const UFaerieEquipmentManager* Equipment)
{
	SaveData = Equipment->MakeSaveData();
}

void UFaerieDataSaveGameExample::WriteEquipment(UFaerieEquipmentManager* Equipment)
{
	Equipment->LoadSaveData(SaveData);
}