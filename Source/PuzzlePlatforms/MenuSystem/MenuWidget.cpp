// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuWidget.h"

void UMenuWidget::SetMenuInterface(IMenuInterface* _MenuInterface)
{
	this->MenuInterface_ = _MenuInterface;
}

// 인스턴스에서 호출하는 Setup 함수
void UMenuWidget::Setup()
{
	// 메뉴를 뷰포트에 추가한다. 
	this->AddToViewport();

	// 존재하는 로컬 플레이어들 중 가장 첫 번째 것을 반환한다. (게임인스턴스에서 사용하던거라 주석처리)
	// APlayerController* PlayerController = GetFirstLocalPlayerController();

	// 현재 월드를 가져오기
	UWorld* World = GetWorld();
	if (!ensure(World != nullptr)) return;

	APlayerController* PlayerController = World->GetFirstPlayerController();
	if (!ensure(PlayerController != nullptr)) return;

	// FInputModeDataBase를 상속받는 UI용 인풋모드
	FInputModeUIOnly InputModeData;

	// 인풋 포커스를 메뉴 위젯으로 해놓는다.
	InputModeData.SetWidgetToFocus(this->TakeWidget());

	// 마우스를 뷰포트 영역 밖으로도 벗어날 수 있도록 잠그지 않는다. 
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);

	// 플레이어 컨트롤러에 인풋모드 세팅
	PlayerController->SetInputMode(InputModeData);

	// 마우스 커서를 보이도록 한다. 
	PlayerController->bShowMouseCursor = true;
}

// 메인메뉴를 허무는 함수 Host, Join 할 때 호출
void UMenuWidget::Teardown()
{
	// 현재 메뉴를 뷰포트에서 제거한다.
	this->RemoveFromViewport();

	UWorld* World = GetWorld();
	if (!ensure(World != nullptr)) return;

	APlayerController* PlayerController = World->GetFirstPlayerController();
	if (!ensure(PlayerController != nullptr)) return;

	// GameOnly 모드를 세팅하면 키보드, 마우스 동작이 작동한다.
	const FInputModeGameOnly InputModeData;
	PlayerController->SetInputMode(InputModeData);

	// 커서가 안보이도록 한다.
	PlayerController->bShowMouseCursor = false;
}