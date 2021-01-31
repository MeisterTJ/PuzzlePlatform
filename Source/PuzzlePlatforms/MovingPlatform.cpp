// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

AMovingPlatform::AMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;	// ƽ�� ����ϰڴ�. (Tick �Լ�ȣ��)
	SetMobility(EComponentMobility::Movable);	// ����ƽ �޽� ������Ʈ�� �����̱� ���ؼ��� �����Ƽ�� �����ؾ� �Ѵ�.
}

void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	// ���ø����̼��� ���������� �ǹ̰� �ִ�.
	if (HasAuthority())
	{
		SetReplicates(true);		// ���ø����̼��� �ϵ��� �Ѵ�.
		SetReplicateMovement(true);	// �������� ����ȭ�Ѵ�. 
	}

	GlobalStartLocation = GetActorLocation();

	// TargetLocation�� ���� ���������� ��ȯ.
	GlobalTargetLocation = GetTransform().TransformPosition(TargetLocation);
}

void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Ȱ��ȭ�� Ʈ���Ű� �ִٸ�
	if ( ActiveTriggers > 0 )
	{
		// ���� ������ ���Ͷ�� 
		if (HasAuthority())
		{
			// �� �ڵ�� ���� ���������� �۵��Ѵ�.
			FVector Location = GetActorLocation();
			float JourneyLength = (GlobalTargetLocation - GlobalStartLocation).Size();	// �������� �Ÿ�
			float JourneyTravelled = (Location - GlobalStartLocation).Size();			// ������������ �󸶳� �������°�?

			// ������ �Ÿ��� �������� �Ÿ����� ũ�� �����ؼ� �ݴ� �������� ������ �Ѵ�.
			if (JourneyTravelled >= JourneyLength)
			{
				GlobalStartLocation += GlobalTargetLocation;
				GlobalTargetLocation = GlobalStartLocation - GlobalTargetLocation;
				GlobalStartLocation = GlobalStartLocation - GlobalTargetLocation;
			}


			// ���� �󿡼��� TargetLocation - ���� �󿡼��� Location
			FVector Direction = (GlobalTargetLocation - GlobalStartLocation).GetSafeNormal();
			Location += Speed * DeltaTime * Direction;
			SetActorLocation(Location);
		}
	}
}

void AMovingPlatform::AddActiveTrigger()
{
	ActiveTriggers++;
}

void AMovingPlatform::RemoveActiveTrigger()
{
	if (ActiveTriggers > 0)
	{
		ActiveTriggers--;
	}
}
