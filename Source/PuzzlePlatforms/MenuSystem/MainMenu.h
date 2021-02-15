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
	// �޴��� �ٲ��ִ� ������
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

	// ���� ������ �����ϴ� ��ư
	UPROPERTY(meta = (BindWidget))
	class UButton* P_QuitBtn_;

	// ���������� IP Address �ؽ�Ʈ
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
