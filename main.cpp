#include "WinApp.h"
#include "Message.h"
#include "input.h"
#include "DirectXCommon.h"
#include "GameScene.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	//ウィンドウ生成
	WinApp* win = nullptr;
	win = WinApp::GetInstance();
	win->CreateWindow_(L"あ");


	Message* message;
	message = Message::GetInstance();

	//DirectX初期化処理
	DirectXCommon* dxCommon = nullptr;
	dxCommon = DirectXCommon::GetInstance();
	dxCommon->Initialize(win);

	//キーボード
	Input* input = nullptr;
	input = Input::GetInstance();
	input->Initialize(win);

	// ゲームシーン
	GameScene* gameScene = nullptr;
	gameScene = new GameScene();
	gameScene->Initialize();

	//ゲームループ
	while (true)
	{
		//メッセージがある？
		message->Update();

		//ゲームシーン更新
		gameScene->Update();

		//描画処理
		dxCommon->PreDraw();
		//この間に描画処理を書く
		gameScene->Draw();

		//描画処理終了
		dxCommon->PostDraw();


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