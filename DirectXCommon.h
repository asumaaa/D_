#pragma once
#include <Windows.h>
#include <cstdlib>
#include <d3d12.h>
//#include <d3dx12.h>
#include <dxgi1_6.h>
#include <wrl.h>
#include <algorithm>
#include <cassert>
#include <vector>

#pragma comment(lib, "d3d12.lib")
#pragma comment(lib, "dxgi.lib")
#pragma comment(lib, "dxguid.lib")

#include "WinApp.h"

using namespace Microsoft::WRL;

class DirectXCommon
{
public:
	static DirectXCommon* GetInstance();
	//初期化
	void Initialize(WinApp* winApp);
	void InitializeDevice();			//デバイス関連
	void InitializeCommand();			//コマンド関連
	void InitializeSwapchain();			//スワップチェーン関連
	void InitializeRenderTargetView();	//レンダーターゲット関連
	void InitializeDepthBuffer();		//深度バッファ関連
	void InitializeFence();				//フェンス関連

	//描画

	//ゲッター
	ID3D12Device* GetDevice() { return device.Get(); }
	IDXGISwapChain4* GetSwapChain() { return swapChain.Get(); }
	ID3D12GraphicsCommandList* GetCommandList() { return commandList.Get(); }
	ID3D12Debug* GetDebugController() { return debugController.Get(); }
	IDXGIFactory7* GetDxgiFactory() { return dxgiFactory.Get(); }
	ID3D12CommandAllocator* GetCommandAllocator() { return commandAllocator.Get(); }
	ID3D12CommandQueue* GetCommandQueue() { return commandQueue.Get(); }
	ID3D12DescriptorHeap* GetRtvHeap() { return rtvHeap.Get(); }
	ID3D12Fence* GetFence() { return fence.Get(); }

	//メンバ変数
private:
	//ウィンドウ
	WinApp* winApp_ = nullptr;
	//DirectX
	/*ComPtr<ID3D12Device> device;*/
	Microsoft::WRL::ComPtr<ID3D12Device>device;
	/*ComPtr<IDXGIFactory7> dxgiFactory;*/
	Microsoft::WRL::ComPtr<IDXGIFactory7>dxgiFactory;
	ComPtr<IDXGISwapChain4> swapChain;
	ComPtr<ID3D12GraphicsCommandList> commandList;
	ComPtr<ID3D12Debug> debugController;
	ComPtr<ID3D12CommandAllocator> commandAllocator;
	ComPtr<ID3D12CommandQueue> commandQueue;
	ComPtr<ID3D12DescriptorHeap> rtvHeap;
	ComPtr<ID3D12Fence> fence;

public:
	D3D12_DESCRIPTOR_HEAP_DESC rtvHeapDesc{};
	std::vector<ComPtr<ID3D12Resource>>backBuffers;
	std::vector<ComPtr<IDXGIAdapter4>>adapters;
	ComPtr<IDXGIAdapter4> tmpAdapter;
	DXGI_SWAP_CHAIN_DESC1 swapChainDesc{};
	D3D12_RESOURCE_DESC depthResorceDesc{};	//深度バッファ

	UINT64 fenceVal = 0;
};



