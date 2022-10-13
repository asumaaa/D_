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

		////�o�b�N�o�b�t�@�̔ԍ����擾(2�Ȃ̂�0�Ԃ�1��)
		//UINT bbIndex = dx->GetSwapChain()->GetCurrentBackBufferIndex();

		//// 1. ���\�[�X�o���A�ɏ������݉\�ɕύX
		//D3D12_RESOURCE_BARRIER barrierDesc{};
		//barrierDesc.Transition.pResource = dx->backBuffers[bbIndex].Get();	//�o�b�N�o�b�t�@���w��
		//barrierDesc.Transition.StateBefore = D3D12_RESOURCE_STATE_PRESENT;	//�\����Ԃ���
		//barrierDesc.Transition.StateAfter = D3D12_RESOURCE_STATE_RENDER_TARGET;	//�`���Ԃ�
		//dx->GetCommandList()->ResourceBarrier(1, &barrierDesc);

		//// 2. �`���̕ύX
		//// �����_�[�^�[�Q�b�g�r���[�̃n���h�����擾
		//D3D12_CPU_DESCRIPTOR_HANDLE rtvHandle = dx->GetRtvHeap()->GetCPUDescriptorHandleForHeapStart();
		//rtvHandle.ptr += bbIndex * dx->GetDevice()->GetDescriptorHandleIncrementSize(dx->rtvHeapDesc.Type);
		//D3D12_CPU_DESCRIPTOR_HANDLE dsvHandle = dsvHeap->GetCPUDescriptorHandleForHeapStart();
		//dx->GetCommandList()->OMSetRenderTargets(1, &rtvHandle, false, &dsvHandle);

		//// 3. ��ʃN���A�R�}���h   R     G    B    A
		//FLOAT clearColor[] = { 0.1f,0.25f,0.5f,0.0f };
		//dx->GetCommandList()->ClearRenderTargetView(rtvHandle, clearColor, 0, nullptr);
		//dx->GetCommandList()->ClearDepthStencilView(dsvHandle, D3D12_CLEAR_FLAG_DEPTH, 1.0f, 0, 0, nullptr);

		//// 4. �`��R�}���h

		//// 5. ���\�[�X�o���A���������݋֎~��
		//barrierDesc.Transition.StateBefore = D3D12_RESOURCE_STATE_RENDER_TARGET;	//�`���Ԃ���
		//barrierDesc.Transition.StateAfter = D3D12_RESOURCE_STATE_PRESENT;			//�\����Ԃ�
		//dx->GetCommandList()->ResourceBarrier(1, &barrierDesc);

		////���߂̃N���[�Y
		//result = dx->GetCommandList()->Close();
		//assert(SUCCEEDED(result));
		////�R�}���h���X�g�̎��s
		//ID3D12CommandList* commandLists[] = { dx->GetCommandList() };
		//dx->GetCommandQueue()->ExecuteCommandLists(1, commandLists);

		////��ʂɕ\������o�b�t�@���N���b�v
		//result = dx->GetSwapChain()->Present(1, 0);
		//assert(SUCCEEDED(result));


		////�R�}���h�̎��s������҂�
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

		////�L���[���N���A
		//result = dx->GetCommandAllocator()->Reset();
		//assert(SUCCEEDED(result));
		////�ĂуR�}���h���X�g�𒙂߂鏀��
		//result = dx->GetCommandList()->Reset(dx->GetCommandAllocator(), nullptr);
		//assert(SUCCEEDED(result));


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