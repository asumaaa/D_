#include "WinApp.h"
#include "Message.h"
#include "input.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	//ウィンドウ生成
	WinApp* win = nullptr;
	win = WinApp::GetInstance();
	win->CreateWindow_(L"あ");

	Message* message;	//メッセージ
	message = Message::GetInstance();

	//キーボード
	Input* input = nullptr;
	input = Input::GetInstance();
	input->Initialize(win);

	//ゲームループ
	while (true)
	{
		//メッセージがある？
		message->Update();

		//Xボタンで終了メッセ時が来たらゲームループを抜ける 
		if (message->ExitGameloop() == 1)
		{
			break;
		}

		//ウィンドウクラスを登録解除
		win->deleteWindow();
	}
	return 0;
}