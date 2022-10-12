#pragma once
#include "dxgidebug.h"
#include <d3d12.h>

class Message
{
public:
	static Message* GetInstance();
	void Update();
	//Xボタンで終了メッセ時が来たらゲームループを抜ける 
	bool ExitGameloop();
public:
	MSG msg{};
};
