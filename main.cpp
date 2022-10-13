#include "WinApp.h"
#include "Message.h"
#include "input.h"
#include "DirectXCommon.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	//�E�B���h�E����
	WinApp* win = nullptr;
	win = WinApp::GetInstance();
	win->CreateWindow_(L"��");

	Message* message;	//���b�Z�[�W
	message = Message::GetInstance();

	//DirectX����������
	DirectXCommon* dxCommon = nullptr;
	dxCommon = DirectXCommon::GetInstance();
	dxCommon->Initialize(win);

	//�L�[�{�[�h
	Input* input = nullptr;
	input = Input::GetInstance();
	input->Initialize(win);

	//�Q�[�����[�v
	while (true)
	{
		//���b�Z�[�W������H
		message->Update();

		dxCommon->PreDraw();

		//// 4. �`��R�}���h

		dxCommon->PostDraw();


		//X�{�^���ŏI�����b�Z����������Q�[�����[�v�𔲂��� 
		if (message->ExitGameloop() == 1)
		{
			break;
		}

		//�E�B���h�E�N���X��o�^����
		win->deleteWindow();
	}
	return 0;
}