// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MenuInterface.h"
#include "Blueprint/UserWidget.h"
#include "MenuWidget.generated.h"

/**
 *		Menu, InGameMenu 의 공통 부모 클래스
 */
UCLASS()
class PUZZLEPLATFORMS_API UMenuWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void SetMenuInterface(IMenuInterface* _MenuInterface);
	
	void Setup();
	void Teardown();
	
protected:
	// DIP(의존성 역전법칙) 을 지키기 위해 인터페이스(추상)에 의존한다. 
	IMenuInterface* MenuInterface_;
};
