// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MenuWidget.h"
#include "InGameMenu.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEPLATFORMS_API UInGameMenu : public UMenuWidget
{
	GENERATED_BODY()

protected:
	virtual bool Initialize() override;

private:
	// ��� ��ư
	UPROPERTY(meta = (BindWidget))
	class UButton* P_CancelBtn_;

	// ���� ��ư
	UPROPERTY(meta = (BindWidget))
	class UButton* P_QuitBtn_;

	UFUNCTION()
	void CancelPressed();

	UFUNCTION()
	void QuitPressed();
};
