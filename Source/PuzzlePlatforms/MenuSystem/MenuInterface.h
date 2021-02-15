// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "MenuInterface.generated.h"

/*
 * �������̽� Ŭ������ (����������) ������ Ŭ���� ��Ʈ�� ������ �Լ� ��Ʈ�� ������ �� �ֵ��� �ϴ� �� ���Դϴ�.
 * �״�ζ�� ���缺�� ������ ũ�� ������ Ŭ�����鿡 � ���� �Լ� ����� ������Ű���� �ϴ� ��� �ſ� �����ϴ�.
 * ���� ��� Ʈ���� ������ ���� ������ �ߵ��ǰų�, ������ �溸�� �︮�ų�, �÷��̾�� ������ �ִ� �ý����� ���� ������ �ִ� Ĩ�ô�.
 * ����, ��, �������� ReactToTrigger (Ʈ���ſ� ����) �Լ��� �����ϸ� �� ���Դϴ�.
 * ������ ������ AActor ���� �Ļ��� ����, ���� Ư�� APawn �Ǵ� ACharacter ����Ŭ������ ����, ������ UDataAsset �� ���� �ֽ��ϴ�.
 * �� ��� Ŭ������ ���� �Լ� ����� �ʿ�������, UObject ����� ���� ������ �����ϴ�. �̷� �� �������̽��� ��õ�մϴ�.
 */

// This class does not need to be modified.
/*
 *  UInterface Ŭ������ ���� �������̽��� �ƴϴ�.
 *  �𸮾� ������ ���÷��� �ý��ۿ� ���̵��� �ϱ� ���ؼ��� �����ϴ� ��� �ִ� Ŭ�����̴�.
 *  �׷��Ƿ� �� �������̽����� ��� �͵� �ۼ����� �ʴ´�.
 */
UINTERFACE(MinimalAPI)	// �������̽� Ŭ������ UINTERFACE ��ũ�θ� ����Ѵ�, UInterface�� ����Ѵ�.
class UMenuInterface : public UInterface
{
	GENERATED_BODY()
};


// �����ϴ� Ŭ�������� ������ ��ӹ޴� �������̽�
class PUZZLEPLATFORMS_API IMenuInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void Host() = 0;
	virtual void Join(const FString& Address) = 0;
};
