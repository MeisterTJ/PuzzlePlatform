// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

AMovingPlatform::AMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;	// 틱을 사용하겠다. (Tick 함수호출)
	SetMobility(EComponentMobility::Movable);	// 스태틱 메쉬 컴포넌트는 움직이기 위해서는 모빌리티를 변경해야 한다.
}

void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	// 리플리케이션은 서버에서만 의미가 있다.
	if (HasAuthority())
	{
		SetReplicates(true);		// 리플리케이션을 하도록 한다.
		SetReplicateMovement(true);	// 움직임을 동기화한다. 
	}

	GlobalStartLocation = GetActorLocation();

	// TargetLocation을 월드 포지션으로 변환.
	GlobalTargetLocation = GetTransform().TransformPosition(TargetLocation);
}

void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// 활성화된 트리거가 있다면
	if ( ActiveTriggers > 0 )
	{
		// 만약 서버측 액터라면 
		if (HasAuthority())
		{
			// 이 코드는 오직 서버에서만 작동한다.
			FVector Location = GetActorLocation();
			float JourneyLength = (GlobalTargetLocation - GlobalStartLocation).Size();	// 지점간의 거리
			float JourneyTravelled = (Location - GlobalStartLocation).Size();			// 시작지점부터 얼마나 떨어졌는가?

			// 떨어진 거리가 지점간의 거리보다 크면 스왑해서 반대 방향으로 가도록 한다.
			if (JourneyTravelled >= JourneyLength)
			{
				GlobalStartLocation += GlobalTargetLocation;
				GlobalTargetLocation = GlobalStartLocation - GlobalTargetLocation;
				GlobalStartLocation = GlobalStartLocation - GlobalTargetLocation;
			}


			// 월드 상에서의 TargetLocation - 월드 상에서의 Location
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
