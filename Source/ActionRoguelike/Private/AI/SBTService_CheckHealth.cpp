// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/SBTService_CheckHealth.h"
#include "SAttributeComponent.h"
#include "BehaviorTree/BlackBoardComponent.h"
#include "AIController.h"



USBTService_CheckHealth::USBTService_CheckHealth() 
{
	LowHealthFraction = 0.3f;
}


void USBTService_CheckHealth::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* ModeMemory, float DeltaSeconds) 
{
	Super::TickNode(OwnerComp, ModeMemory, DeltaSeconds);

	APawn* AIPawn = OwnerComp.GetAIOwner()->GetPawn();
	if (ensure(AIPawn))
	{
		USAttributeComponent* AttributeComp = USAttributeComponent::GetAttributes(AIPawn);
		if (ensure(AttributeComp))
		{
			bool bLowHealth = (AttributeComp->GetHealth() / AttributeComp->GetHealthMax()) < LowHealthFraction;

			UBlackboardComponent* BlackBoardComp = OwnerComp.GetBlackboardComponent();
			BlackBoardComp->SetValueAsBool(LowHealthKey.SelectedKeyName, bLowHealth);
		}
	}
}