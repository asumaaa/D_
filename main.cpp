#include "WinApp.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	//�E�B���h�E����
	WinApp* win = nullptr;
	win = WinApp::GetInstance();
	win->CreateWindow_(L"��");

	//�Q�[�����[�v
	while (true)
	{
		//�E�B���h�E�N���X��o�^����
		win->deleteWindow();
	}
	return 0;
}