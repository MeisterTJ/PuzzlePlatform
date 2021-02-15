// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuWidget.h"

void UMenuWidget::SetMenuInterface(IMenuInterface* _MenuInterface)
{
	this->MenuInterface_ = _MenuInterface;
}

// �ν��Ͻ����� ȣ���ϴ� Setup �Լ�
void UMenuWidget::Setup()
{
	// �޴��� ����Ʈ�� �߰��Ѵ�. 
	this->AddToViewport();

	// �����ϴ� ���� �÷��̾�� �� ���� ù ��° ���� ��ȯ�Ѵ�. (�����ν��Ͻ����� ����ϴ��Ŷ� �ּ�ó��)
	// APlayerController* PlayerController = GetFirstLocalPlayerController();

	// ���� ���带 ��������
	UWorld* World = GetWorld();
	if (!ensure(World != nullptr)) return;

	APlayerController* PlayerController = World->GetFirstPlayerController();
	if (!ensure(PlayerController != nullptr)) return;

	// FInputModeDataBase�� ��ӹ޴� UI�� ��ǲ���
	FInputModeUIOnly InputModeData;

	// ��ǲ ��Ŀ���� �޴� �������� �س��´�.
	InputModeData.SetWidgetToFocus(this->TakeWidget());

	// ���콺�� ����Ʈ ���� �����ε� ��� �� �ֵ��� ����� �ʴ´�. 
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);

	// �÷��̾� ��Ʈ�ѷ��� ��ǲ��� ����
	PlayerController->SetInputMode(InputModeData);

	// ���콺 Ŀ���� ���̵��� �Ѵ�. 
	PlayerController->bShowMouseCursor = true;
}

// ���θ޴��� �㹫�� �Լ� Host, Join �� �� ȣ��
void UMenuWidget::Teardown()
{
	// ���� �޴��� ����Ʈ���� �����Ѵ�.
	this->RemoveFromViewport();

	UWorld* World = GetWorld();
	if (!ensure(World != nullptr)) return;

	APlayerController* PlayerController = World->GetFirstPlayerController();
	if (!ensure(PlayerController != nullptr)) return;

	// GameOnly ��带 �����ϸ� Ű����, ���콺 ������ �۵��Ѵ�.
	const FInputModeGameOnly InputModeData;
	PlayerController->SetInputMode(InputModeData);

	// Ŀ���� �Ⱥ��̵��� �Ѵ�.
	PlayerController->bShowMouseCursor = false;
}