#include "WinApp.h"
#include "Message.h"
#include "input.h"
#include "DirectXCommon.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	//ウィンドウ生成
	WinApp* win = nullptr;
	win = WinApp::GetInstance();
	win->CreateWindow_(L"あ");

	Message* message;	//メッセージ
	message = Message::GetInstance();

	//DirectX初期化処理
	DirectXCommon* dxCommon = nullptr;
	dxCommon = DirectXCommon::GetInstance();
	dxCommon->Initialize(win);

	//キーボード
	Input* input = nullptr;
	input = Input::GetInstance();
	input->Initialize(win);

	//ゲームループ
	while (true)
	{
		//メッセージがある？
		message->Update();

		////バックバッファの番号を取得(2つなので0番か1番)
		//UINT bbIndex = dx->GetSwapChain()->GetCurrentBackBufferIndex();

		//// 1. リソースバリアに書き込み可能に変更
		//D3D12_RESOURCE_BARRIER barrierDesc{};
		//barrierDesc.Transition.pResource = dx->backBuffers[bbIndex].Get();	//バックバッファを指定
		//barrierDesc.Transition.StateBefore = D3D12_RESOURCE_STATE_PRESENT;	//表示状態から
		//barrierDesc.Transition.StateAfter = D3D12_RESOURCE_STATE_RENDER_TARGET;	//描画状態へ
		//dx->GetCommandList()->ResourceBarrier(1, &barrierDesc);

		//// 2. 描画先の変更
		//// レンダーターゲットビューのハンドルを取得
		//D3D12_CPU_DESCRIPTOR_HANDLE rtvHandle = dx->GetRtvHeap()->GetCPUDescriptorHandleForHeapStart();
		//rtvHandle.ptr += bbIndex * dx->GetDevice()->GetDescriptorHandleIncrementSize(dx->rtvHeapDesc.Type);
		//D3D12_CPU_DESCRIPTOR_HANDLE dsvHandle = dsvHeap->GetCPUDescriptorHandleForHeapStart();
		//dx->GetCommandList()->OMSetRenderTargets(1, &rtvHandle, false, &dsvHandle);

		//// 3. 画面クリアコマンド   R     G    B    A
		//FLOAT clearColor[] = { 0.1f,0.25f,0.5f,0.0f };
		//dx->GetCommandList()->ClearRenderTargetView(rtvHandle, clearColor, 0, nullptr);
		//dx->GetCommandList()->ClearDepthStencilView(dsvHandle, D3D12_CLEAR_FLAG_DEPTH, 1.0f, 0, 0, nullptr);

		//// 4. 描画コマンド

		//// 5. リソースバリアを書き込み禁止に
		//barrierDesc.Transition.StateBefore = D3D12_RESOURCE_STATE_RENDER_TARGET;	//描画状態から
		//barrierDesc.Transition.StateAfter = D3D12_RESOURCE_STATE_PRESENT;			//表示状態へ
		//dx->GetCommandList()->ResourceBarrier(1, &barrierDesc);

		////命令のクローズ
		//result = dx->GetCommandList()->Close();
		//assert(SUCCEEDED(result));
		////コマンドリストの実行
		//ID3D12CommandList* commandLists[] = { dx->GetCommandList() };
		//dx->GetCommandQueue()->ExecuteCommandLists(1, commandLists);

		////画面に表示するバッファをクリップ
		//result = dx->GetSwapChain()->Present(1, 0);
		//assert(SUCCEEDED(result));


		////コマンドの実行完了を待つ
		//dx->GetCommandQueue()->Signal(dx->GetFence(), ++dx->fenceVal);
		//if (dx->GetFence()->GetCompletedValue() != dx->fenceVal)
		//{
		//	HANDLE event = CreateEvent(nullptr, false, false, nullptr);
		//	dx->GetFence()->SetEventOnCompletion(dx->fenceVal, event);
		//	if (event != NULL) {
		//		WaitForSingleObject(event, INFINITE);
		//	}
		//	if (event != NULL) {
		//		CloseHandle(event);
		//	}
		//}

		////キューをクリア
		//result = dx->GetCommandAllocator()->Reset();
		//assert(SUCCEEDED(result));
		////再びコマンドリストを貯める準備
		//result = dx->GetCommandList()->Reset(dx->GetCommandAllocator(), nullptr);
		//assert(SUCCEEDED(result));


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