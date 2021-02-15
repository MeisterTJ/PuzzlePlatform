// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "MenuInterface.generated.h"

/*
 * 인터페이스 클래스는 (잠재적으로) 무관한 클래스 세트가 공통의 함수 세트를 구현할 수 있도록 하는 데 쓰입니다.
 * 그대로라면 유사성이 없었을 크고 복잡한 클래스들에 어떤 게임 함수 기능을 공유시키고자 하는 경우 매우 좋습니다.
 * 예를 들어 트리거 볼륨에 들어서면 함정이 발동되거나, 적에게 경보가 울리거나, 플레이어에게 점수를 주는 시스템을 가진 게임이 있다 칩시다.
 * 함정, 적, 점수에서 ReactToTrigger (트리거에 반응) 함수를 구현하면 될 것입니다.
 * 하지만 함정은 AActor 에서 파생될 수도, 적은 특수 APawn 또는 ACharacter 서브클래스일 수도, 점수는 UDataAsset 일 수도 있습니다.
 * 이 모든 클래스에 공유 함수 기능이 필요하지만, UObject 말고는 공통 조상이 없습니다. 이럴 때 인터페이스를 추천합니다.
 */

// This class does not need to be modified.
/*
 *  UInterface 클래스는 실제 인터페이스가 아니다.
 *  언리얼 엔진의 리플렉션 시스템에 보이도록 하기 위해서만 존재하는 비어 있는 클래스이다.
 *  그러므로 이 인터페이스에는 어떠한 것도 작성하지 않는다.
 */
UINTERFACE(MinimalAPI)	// 인터페이스 클래스는 UINTERFACE 매크로를 사용한다, UInterface를 상속한다.
class UMenuInterface : public UInterface
{
	GENERATED_BODY()
};


// 구현하는 클래스에서 실제로 상속받는 인터페이스
class PUZZLEPLATFORMS_API IMenuInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void Host() = 0;
	virtual void Join(const FString& Address) = 0;
};
