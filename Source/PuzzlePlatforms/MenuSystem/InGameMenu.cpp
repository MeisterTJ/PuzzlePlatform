// Fill out your copyright notice in the Description page of Project Settings.


#include "InGameMenu.h"
#include "Components/Button.h"

bool UInGameMenu::Initialize()
{
	bool Success = Super::Initialize();
	if (!Success) return false;

	if (!ensure(P_CancelBtn_ != nullptr)) return false;
	P_CancelBtn_->OnClicked.AddDynamic(this, &UInGameMenu::CancelPressed);

	if (!ensure(P_QuitBtn_ != nullptr)) return false;
	P_QuitBtn_->OnClicked.AddDynamic(this, &UInGameMenu::QuitPressed);

	return true;
}

// ��� ��ư�� ������ ��� �ΰ��� �޴��� ������. 
void UInGameMenu::CancelPressed()
{
	Teardown();
}

// ���� ��ư�� ������ ��� ������ �����ϰų�, ȣ��Ʈ�� ������ ���´�.
void UInGameMenu::QuitPressed()
{
	if(MenuInterface_ != nullptr)
	{
		Teardown();
		// ���� �޴��� ���ư���. 
		MenuInterface_->LoadMainMenu();
	}
}
