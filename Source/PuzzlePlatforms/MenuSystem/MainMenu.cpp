// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenu.h"
#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"
#include "Components/EditableText.h"

// 초기화 함수
bool UMainMenu::Initialize()
{
	bool Success = Super::Initialize();
	if (!Success) return false;

	if (!ensure(P_HostBtn_ != nullptr)) return false;
	P_HostBtn_->OnClicked.AddDynamic(this, &UMainMenu::HostServer);
	if (!ensure(P_JoinBtn_ != nullptr)) return false;
	P_JoinBtn_->OnClicked.AddDynamic(this, &UMainMenu::JoinServer);
	if (!ensure(P_JoinMenuBtn_ != nullptr)) return false;
	P_JoinMenuBtn_->OnClicked.AddDynamic(this, &UMainMenu::OpenJoinMenu);
	if (!ensure(P_BackBtn_ != nullptr)) return false;
	P_BackBtn_->OnClicked.AddDynamic(this, &UMainMenu::OpenMainMenu);

	return true;
}

void UMainMenu::HostServer()
{
	UE_LOG(LogTemp, Warning, TEXT("I`m gonna host a server!"));

	if(MenuInterface_ != nullptr)
	{
		// 인터페이스의 함수 호출
		MenuInterface_->Host();
	}
}

void UMainMenu::JoinServer()
{
	if(MenuInterface_ != nullptr)
	{
		if (!ensure(P_IPAddress_ != nullptr)) return;
		const FString& Address = P_IPAddress_->GetText().ToString();
		MenuInterface_->Join(Address);
	}
}

// 메인 메뉴로 돌아간다.
void UMainMenu::OpenMainMenu()
{
	if (!ensure(P_MenuSwitcher_ != nullptr)) return;
	if (!ensure(P_MainMenu_ != nullptr)) return;

	// 메인메뉴를 액티브 위젯으로 한다. 
	P_MenuSwitcher_->SetActiveWidget(P_MainMenu_);
}


// 조인 메뉴를 연다.
void UMainMenu::OpenJoinMenu()
{
	if (!ensure(P_MenuSwitcher_ != nullptr)) return; 
	if (!ensure(P_JoinMenu_ != nullptr)) return;

	// 조인메뉴를 액티브 위젯으로 한다. 
	P_MenuSwitcher_->SetActiveWidget(P_JoinMenu_);
}
