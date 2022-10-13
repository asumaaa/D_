#include "WinApp.h"
#include "Message.h"
#include "input.h"
#include "DirectXCommon.h"
#include "GameScene.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	//�E�B���h�E����
	WinApp* win = nullptr;
	win = WinApp::GetInstance();
	win->CreateWindow_(L"��");


	Message* message;
	message = Message::GetInstance();

	//DirectX����������
	DirectXCommon* dxCommon = nullptr;
	dxCommon = DirectXCommon::GetInstance();
	dxCommon->Initialize(win);

	//�L�[�{�[�h
	Input* input = nullptr;
	input = Input::GetInstance();
	input->Initialize(win);

	// �Q�[���V�[��
	GameScene* gameScene = nullptr;
	gameScene = new GameScene();
	gameScene->Initialize();

	//�Q�[�����[�v
	while (true)
	{
		//���b�Z�[�W������H
		message->Update();

		//�Q�[���V�[���X�V
		gameScene->Update();

		//�`�揈��
		dxCommon->PreDraw();
		//���̊Ԃɕ`�揈��������
		gameScene->Draw();

		//�`�揈���I��
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