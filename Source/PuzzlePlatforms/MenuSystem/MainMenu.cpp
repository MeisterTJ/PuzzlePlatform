// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenu.h"
#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"
#include "Components/EditableText.h"

// �ʱ�ȭ �Լ�
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
		// �������̽��� �Լ� ȣ��
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

// ���� �޴��� ���ư���.
void UMainMenu::OpenMainMenu()
{
	if (!ensure(P_MenuSwitcher_ != nullptr)) return;
	if (!ensure(P_MainMenu_ != nullptr)) return;

	// ���θ޴��� ��Ƽ�� �������� �Ѵ�. 
	P_MenuSwitcher_->SetActiveWidget(P_MainMenu_);
}


// ���� �޴��� ����.
void UMainMenu::OpenJoinMenu()
{
	if (!ensure(P_MenuSwitcher_ != nullptr)) return; 
	if (!ensure(P_JoinMenu_ != nullptr)) return;

	// ���θ޴��� ��Ƽ�� �������� �Ѵ�. 
	P_MenuSwitcher_->SetActiveWidget(P_JoinMenu_);
}
