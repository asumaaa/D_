#pragma once
#include "dxgidebug.h"
#include <d3d12.h>

class Message
{
public:
	static Message* GetInstance();
	void Update();
	//X�{�^���ŏI�����b�Z����������Q�[�����[�v�𔲂��� 
	bool ExitGameloop();
public:
	MSG msg{};
};
