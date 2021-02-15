// Fill out your copyright notice in the Description page of Project Settings.


#include "PuzzlePlatformsGameInstance.h"
#include "Engine/Engine.h"
#include "UObject/ConstructorHelpers.h"
#include "Blueprint/UserWidget.h"
#include "MenuSystem/MainMenu.h"

UPuzzlePlatformsGameInstance::UPuzzlePlatformsGameInstance(const FObjectInitializer& ObjectInitializer)
{
	// �޴� ���� �������Ʈ�� �����´�.
	const ConstructorHelpers::FClassFinder<UUserWidget> MenuBPClass(TEXT("/Game/MenuSystem/WBP_MainMenu"));
	if (!ensure(MenuBPClass.Class != nullptr)) return;

	MenuClass = MenuBPClass.Class;

	// �ΰ��� �޴� ���� �������Ʈ�� �����´�.
	const ConstructorHelpers::FClassFinder<UUserWidget> InGameMenuBPClass(TEXT("/Game/MenuSystem/WBP_InGameMenu"));
	if (!ensure(InGameMenuBPClass.Class != nullptr)) return;

	InGameMenuClass = InGameMenuBPClass.Class;
}

auto UPuzzlePlatformsGameInstance::Init() -> void
{
	UE_LOG(LogTemp, Warning, TEXT("GameInstance Init"));
	UE_LOG(LogTemp, Warning, TEXT("Found class %s"), *MenuClass->GetName());
}

// ���� ���� �� �޴��� �ε��ϴ� �Լ�(�������Ʈ���� ȣ���Ѵ�.)
void UPuzzlePlatformsGameInstance::LoadMenu()
{
	if (!ensure(MenuClass != nullptr)) return;
	Menu_ = CreateWidget<UMainMenu>(this, MenuClass);
	if (!ensure(Menu_ != nullptr)) return;

	Menu_->Setup();
	// �޴� ����Ŭ������ �����ν��Ͻ� �������̽��� �����ϵ��� �Ѵ�. 
	Menu_->SetMenuInterface(this);
}

void UPuzzlePlatformsGameInstance::LoadInGameMenu()
{
	if (!ensure(InGameMenuClass != nullptr)) return;
	UMenuWidget* InGameMenu = CreateWidget<UMenuWidget>(this, InGameMenuClass);
	if (!ensure(InGameMenu != nullptr)) return;

	// ȭ�鿡 ��Ÿ������ �Ѵ�.
	InGameMenu->Setup();
	InGameMenu->SetMenuInterface(this);
}

void UPuzzlePlatformsGameInstance::Host()
{
	if(Menu_ != nullptr)
	{
		// �޴��� �����Ѵٸ� �㹮��.
		Menu_->Teardown();
	}
	
	UEngine* Engine = GetEngine();
	if (!ensure(Engine != nullptr)) return;
	 
	// 2�� ���� �ʷϻ����� Hosting �ؽ�Ʈ�� ����. 
	Engine->AddOnScreenDebugMessage(0, 2, FColor::Green, TEXT("Hosting"));

	UWorld* World = GetWorld();
	if (!ensure(World != nullptr)) return;

	// Jumps the server to new level, If bAbsoulte is true and we are using seemless traveling
	// listen���� �ٸ� Ŭ���̾�Ʈ�� ���� �� �ֵ��� ����д�. (�� ���� �ٸ� Ŭ���̾�Ʈ���� ���� �Ұ�)
	World->ServerTravel("/Game/PuzzlePlatforms/Maps/ThirdPersonExampleMap?listen");
}

// Ŭ���̾�Ʈ -> �������ϰ� �ִ� ������ �����Ѵ�.
void UPuzzlePlatformsGameInstance::Join(const FString& Address)
{
	if (Menu_ != nullptr)
	{
		// �޴��� �����Ѵٸ� �㹮��.
		Menu_->Teardown();
	}
	
	UEngine* Engine = GetEngine();
	if (!ensure(Engine != nullptr)) return;

	Engine->AddOnScreenDebugMessage(0, 5, FColor::Green, FString::Printf(TEXT("Joining %s"), *Address));

	APlayerController* PlayerController = GetFirstLocalPlayerController();
	if (!ensure(PlayerController != nullptr)) return;

	// Address�� ������ ���� �� ������ ������ �̵�?
	// PlayerController�� ClientTravel�� ���� ���� ����
	PlayerController->ClientTravel(Address, ETravelType::TRAVEL_Absolute);
}
