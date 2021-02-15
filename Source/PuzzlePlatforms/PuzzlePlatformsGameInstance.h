// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MenuSystem/MenuInterface.h"
#include "PuzzlePlatformsGameInstance.generated.h"

/**
 *	IMenuInterface�� �����ϴ� �����ν��Ͻ�
 */
UCLASS()
class PUZZLEPLATFORMS_API UPuzzlePlatformsGameInstance : public UGameInstance, public IMenuInterface
{
	GENERATED_BODY()

public:
	UPuzzlePlatformsGameInstance(const FObjectInitializer& ObjectInitializer);
	virtual auto Init() -> void override;

	// �������Ʈ���� LoadMenu�� ȣ���� ���̴�. 
	UFUNCTION(BlueprintCallable)
	void LoadMenu();

	UFUNCTION(BlueprintCallable)
	void LoadInGameMenu();

	// Host �ܼ� ��ɾ� ���� 
	UFUNCTION(Exec)
	virtual void Host() override;

	UFUNCTION(Exec)
	virtual void Join(const FString& Address) override;

	virtual void LoadMainMenu() override;

private:
	TSubclassOf<class UUserWidget> MenuClass;
	class UMainMenu* Menu_;

	TSubclassOf<class UUserWidget> InGameMenuClass;
};
