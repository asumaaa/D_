#include "WinApp.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	//ウィンドウ生成
	WinApp* win = nullptr;
	win = WinApp::GetInstance();
	win->CreateWindow_(L"あ");

	//ゲームループ
	while (true)
	{
		//ウィンドウクラスを登録解除
		win->deleteWindow();
	}
	return 0;
}