#pragma once

#include <wrl.h>
#include "WinApp.h"

#define DIRECTINPUT_VERSION 0x0800 // DirectInput�̃o�[�W�����w��
using namespace Microsoft::WRL;
#include <dinput.h>

#pragma comment(lib, "dinput8.lib")
#pragma comment(lib, "dxguid.lib")

class Input
{
public:
	static Input* GetInstance();
	void Initialize(WinApp* winApp);
	void Update();
public:
	//�E�B���h�E
	WinApp* winApp_ = nullptr;

	ComPtr<IDirectInput8> directInput;
	//�L�[�{�[�h
	ComPtr<IDirectInputDevice8> keyboard;
	BYTE key[256] = {};
};

