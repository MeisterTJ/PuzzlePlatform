// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MenuInterface.h"
#include "Blueprint/UserWidget.h"
#include "MenuWidget.generated.h"

/**
 *		Menu, InGameMenu �� ���� �θ� Ŭ����
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
	// DIP(������ ������Ģ) �� ��Ű�� ���� �������̽�(�߻�)�� �����Ѵ�. 
	IMenuInterface* MenuInterface_;
};
