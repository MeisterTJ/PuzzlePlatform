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

// 취소 버튼을 눌렀을 경우 인게임 메뉴를 내린다. 
void UInGameMenu::CancelPressed()
{
	Teardown();
}

// 종료 버튼을 눌렀을 경우 서버를 종료하거나, 호스트와 연결을 끊는다.
void UInGameMenu::QuitPressed()
{
	if(MenuInterface_ != nullptr)
	{
		Teardown();
		// 메인 메뉴로 돌아간다. 
		MenuInterface_->LoadMainMenu();
	}
}
