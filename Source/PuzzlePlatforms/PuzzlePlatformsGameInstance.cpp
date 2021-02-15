// Fill out your copyright notice in the Description page of Project Settings.


#include "PuzzlePlatformsGameInstance.h"
#include "Engine/Engine.h"
#include "UObject/ConstructorHelpers.h"
#include "Blueprint/UserWidget.h"
#include "MenuSystem/MainMenu.h"

UPuzzlePlatformsGameInstance::UPuzzlePlatformsGameInstance(const FObjectInitializer& ObjectInitializer)
{
	// 메뉴 위젯 블루프린트를 가져온다.
	const ConstructorHelpers::FClassFinder<UUserWidget> MenuBPClass(TEXT("/Game/MenuSystem/WBP_MainMenu"));
	if (!ensure(MenuBPClass.Class != nullptr)) return;

	MenuClass = MenuBPClass.Class;

	// 인게임 메뉴 위젯 블루프린트를 가져온다.
	const ConstructorHelpers::FClassFinder<UUserWidget> InGameMenuBPClass(TEXT("/Game/MenuSystem/WBP_InGameMenu"));
	if (!ensure(InGameMenuBPClass.Class != nullptr)) return;

	InGameMenuClass = InGameMenuBPClass.Class;
}

auto UPuzzlePlatformsGameInstance::Init() -> void
{
	UE_LOG(LogTemp, Warning, TEXT("GameInstance Init"));
	UE_LOG(LogTemp, Warning, TEXT("Found class %s"), *MenuClass->GetName());
}

// 게임 실행 후 메뉴를 로드하는 함수(블루프린트에서 호출한다.)
void UPuzzlePlatformsGameInstance::LoadMenu()
{
	if (!ensure(MenuClass != nullptr)) return;
	Menu_ = CreateWidget<UMainMenu>(this, MenuClass);
	if (!ensure(Menu_ != nullptr)) return;

	Menu_->Setup();
	// 메뉴 위젯클래스가 게임인스턴스 인터페이스를 의존하도록 한다. 
	Menu_->SetMenuInterface(this);
}

void UPuzzlePlatformsGameInstance::LoadInGameMenu()
{
	if (!ensure(InGameMenuClass != nullptr)) return;
	UMenuWidget* InGameMenu = CreateWidget<UMenuWidget>(this, InGameMenuClass);
	if (!ensure(InGameMenu != nullptr)) return;

	// 화면에 나타나도록 한다.
	InGameMenu->Setup();
	InGameMenu->SetMenuInterface(this);
}

void UPuzzlePlatformsGameInstance::Host()
{
	if(Menu_ != nullptr)
	{
		// 메뉴가 존재한다면 허문다.
		Menu_->Teardown();
	}
	
	UEngine* Engine = GetEngine();
	if (!ensure(Engine != nullptr)) return;
	 
	// 2초 동안 초록색으로 Hosting 텍스트를 띄운다. 
	Engine->AddOnScreenDebugMessage(0, 2, FColor::Green, TEXT("Hosting"));

	UWorld* World = GetWorld();
	if (!ensure(World != nullptr)) return;

	// Jumps the server to new level, If bAbsoulte is true and we are using seemless traveling
	// listen으로 다른 클라이언트를 받을 수 있도록 열어둔다. (안 열면 다른 클라이언트에서 접속 불가)
	World->ServerTravel("/Game/PuzzlePlatforms/Maps/ThirdPersonExampleMap?listen");
}

// 클라이언트 -> 리스닝하고 있는 서버로 접속한다.
void UPuzzlePlatformsGameInstance::Join(const FString& Address)
{
	if (Menu_ != nullptr)
	{
		// 메뉴가 존재한다면 허문다.
		Menu_->Teardown();
	}
	
	UEngine* Engine = GetEngine();
	if (!ensure(Engine != nullptr)) return;

	Engine->AddOnScreenDebugMessage(0, 5, FColor::Green, FString::Printf(TEXT("Joining %s"), *Address));

	APlayerController* PlayerController = GetFirstLocalPlayerController();
	if (!ensure(PlayerController != nullptr)) return;

	// Address로 서버에 접속 및 서버의 레벨로 이동?
	// PlayerController가 ClientTravel을 함을 잊지 말자
	PlayerController->ClientTravel(Address, ETravelType::TRAVEL_Absolute);
}
