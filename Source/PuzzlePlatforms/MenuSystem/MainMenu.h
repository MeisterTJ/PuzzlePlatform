// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MenuWidget.h"
#include "MainMenu.generated.h"

/**
 *
 */
UCLASS()
class PUZZLEPLATFORMS_API UMainMenu : public UMenuWidget
{
	GENERATED_BODY()
	
protected:
	virtual bool Initialize() override;

private:
	// 메뉴를 바꿔주는 스위쳐
	UPROPERTY(meta = (BindWidget))
	class UWidgetSwitcher* P_MenuSwitcher_;

	UPROPERTY(meta = (BindWidget))
	class UWidget* P_MainMenu_;
	
	UPROPERTY(meta = (BindWidget))
	class UWidget* P_JoinMenu_;
	
	UPROPERTY(meta = (BindWidget))
	class UButton* P_HostBtn_;

	UPROPERTY(meta = (BindWidget))
	class UButton* P_JoinMenuBtn_;

	UPROPERTY(meta = (BindWidget))
	class UButton* P_BackBtn_;

	UPROPERTY(meta = (BindWidget))
	class UButton* P_JoinBtn_;

	// 게임 완전히 종료하는 버튼
	UPROPERTY(meta = (BindWidget))
	class UButton* P_QuitBtn_;

	// 수정가능한 IP Address 텍스트
	UPROPERTY(meta = (BindWidget))
	class UEditableText* P_IPAddress_;

	UFUNCTION()
	void HostServer();

	UFUNCTION()
	void JoinServer();
	
	UFUNCTION()
	void OpenMainMenu();

	UFUNCTION()
	void OpenJoinMenu();

	UFUNCTION()
	void QuitPressed();
};
