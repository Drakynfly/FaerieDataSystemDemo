// Copyright Guy (Drakynfly) Lundvall. All Rights Reserved.


#include "SpecifiersTestActor.h"

// Sets default values
ASpecifiersTestActor::ASpecifiersTestActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ReadOnlySquirrel_Def = CreateDefaultSubobject<USquirrel>("ReadOnlySquirrel_Def");

	ReadWriteSquirrel_Def = CreateDefaultSubobject<USquirrel>("ReadWriteSquirrel_Def");

	ReadOnlySquirrelInner_Def = CreateDefaultSubobject<USquirrel>("ReadOnlySquirrelInner_Def");

	ReadWriteSquirrelInner_Def = CreateDefaultSubobject<USquirrel>("ReadWriteSquirrelInner_Def");
}