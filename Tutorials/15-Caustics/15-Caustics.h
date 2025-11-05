#pragma once
#include "Framework.h"

class Tutorial15 : public Tutorial
{
public:
    struct AccelerationStructureBuffers
    {
        ID3D12ResourcePtr pScratch;
        ID3D12ResourcePtr pResult;
        ID3D12ResourcePtr pInstanceDesc;    // Used only for top-level AS
    };

    void onLoad(HWND winHandle, uint32_t winWidth, uint32_t winHeight) override;
    void onFrameRender() override;
    void onShutdown() override;
private:
    //////////////////////////////////////////////////////////////////////////
    // Tutorial 02 code
    //////////////////////////////////////////////////////////////////////////
    void initDXR(HWND winHandle, uint32_t winWidth, uint32_t winHeight);
    uint32_t beginFrame();
    void endFrame(uint32_t rtvIndex);
    HWND mHwnd = nullptr;
    ID3D12Device5Ptr mpDevice;
    ID3D12CommandQueuePtr mpCmdQueue;
    IDXGISwapChain3Ptr mpSwapChain;
    uvec2 mSwapChainSize;
    ID3D12GraphicsCommandList4Ptr mpCmdList;
    ID3D12FencePtr mpFence;
    HANDLE mFenceEvent;
    uint64_t mFenceValue = 0;

    struct
    {
        ID3D12CommandAllocatorPtr pCmdAllocator;
        ID3D12ResourcePtr pSwapChainBuffer;
        D3D12_CPU_DESCRIPTOR_HANDLE rtvHandle;
    } mFrameObjects[kDefaultSwapChainBuffers];


    // Heap data
    struct HeapData
    {
        ID3D12DescriptorHeapPtr pHeap;
        uint32_t usedEntries = 0;
    };
    HeapData mRtvHeap;
    static const uint32_t kRtvHeapSize = 3;

    //////////////////////////////////////////////////////////////////////////
    // Tutorial 03, Tutorial 11
    //////////////////////////////////////////////////////////////////////////
    void createAccelerationStructures();
    ID3D12ResourcePtr mpVertexBuffer[2];
    ID3D12ResourcePtr mpBottomLevelAS[2];
    AccelerationStructureBuffers mTopLevelBuffers;
    uint64_t mTlasSize = 0;

    //////////////////////////////////////////////////////////////////////////
    // Tutorial 04
    //////////////////////////////////////////////////////////////////////////
    void createRtPipelineState();
    ID3D12StateObjectPtr mpPipelineState;
    ID3D12RootSignaturePtr mpEmptyRootSig;

    //////////////////////////////////////////////////////////////////////////
    // Tutorial 05
    //////////////////////////////////////////////////////////////////////////
    void createShaderTable();
    ID3D12ResourcePtr mpShaderTable;
    uint32_t mShaderTableEntrySize = 0;

    //////////////////////////////////////////////////////////////////////////
    // Tutorial 06
    //////////////////////////////////////////////////////////////////////////
    void createShaderResources();
    ID3D12ResourcePtr mpOutputResource;
    ID3D12DescriptorHeapPtr mpSrvUavHeap;
    static const uint32_t kSrvUavHeapSize = 2;

    //////////////////////////////////////////////////////////////////////////
    // Tutorial 10
    //////////////////////////////////////////////////////////////////////////
    void createConstantBuffers();
    ID3D12ResourcePtr mpConstantBuffer[3];

    //////////////////////////////////////////////////////////////////////////
    // Tutorial 14
    //////////////////////////////////////////////////////////////////////////
    float mRotation = 0;
};