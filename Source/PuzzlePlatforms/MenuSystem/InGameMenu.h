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
	// 취소 버튼
	UPROPERTY(meta = (BindWidget))
	class UButton* P_CancelBtn_;

	// 종료 버튼
	UPROPERTY(meta = (BindWidget))
	class UButton* P_QuitBtn_;

	UFUNCTION()
	void CancelPressed();

	UFUNCTION()
	void QuitPressed();
};
