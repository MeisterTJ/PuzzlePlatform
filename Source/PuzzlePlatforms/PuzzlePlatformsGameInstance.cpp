// Fill out your copyright notice in the Description page of Project Settings.


#include "PuzzlePlatformsGameInstance.h"
#include "Engine/Engine.h"

UPuzzlePlatformsGameInstance::UPuzzlePlatformsGameInstance(const FObjectInitializer& ObjectInitializer)
{
	UE_LOG(LogTemp, Warning, TEXT("GameInstance Constructor"));
}

void UPuzzlePlatformsGameInstance::Init()
{
	UE_LOG(LogTemp, Warning, TEXT("GameInstance Init"));
}

void UPuzzlePlatformsGameInstance::Host()
{
	UEngine* Engine = GetEngine();
	if (!ensure(Engine != nullptr)) return;

	// 2�� ���� �ʷϻ����� Hosting �ؽ�Ʈ�� ����. 
	Engine->AddOnScreenDebugMessage(0, 2, FColor::Green, TEXT("Hosting"));

	UWorld* World = GetWorld();
	if (!ensure(World != nullptr)) return;

	// Jumps the server to new level, If bAbsoulte is true and we are using seemless traveling
	// listen���� �ٸ� Ŭ���̾�Ʈ�� ���� �� �ֵ��� ����д�. (�ȿ��� �ٸ� Ŭ���̾�Ʈ���� ���� �Ұ�)
	World->ServerTravel("/Game/ThirdPersonCPP/Maps/ThirdPersonExampleMap?listen");
}

// Ŭ���̾�Ʈ -> �������ϰ� �ִ� ������ �����Ѵ�.
void UPuzzlePlatformsGameInstance::Join(const FString& Address)
{
	UEngine* Engine = GetEngine();
	if (!ensure(Engine != nullptr)) return;

	Engine->AddOnScreenDebugMessage(0, 5, FColor::Green, FString::Printf(TEXT("Joining %s"), *Address));

	APlayerController* PlayerController = GetFirstLocalPlayerController();
	if (!ensure(PlayerController != nullptr)) return;

	// Address�� ������ ���� �� ������ ������ �̵�?
	PlayerController->ClientTravel(Address, ETravelType::TRAVEL_Absolute);
}
