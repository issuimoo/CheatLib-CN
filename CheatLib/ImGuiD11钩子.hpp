#include <d3d11.h>
#include <dxgi.h>
#include <d3dcompiler.h>
#pragma comment (lib, "D3dcompiler.lib")
#pragma comment (lib, "d3d11.lib")
#pragma comment (lib, "dxgi.lib")
namespace DX11���� {
	bool ��װDX11����(void (*����ѭ��)(), HMODULE ģ����, std::string ImGui����Ŀ¼, float �����С, unsigned char* ����, ID3D11Device* DX11�豸ָ��, ID3D11DeviceContext* DX11�豸����, ID3D11RenderTargetView* DX11����ȾĿ����ͼ, IDXGISwapChain* DX11������);
}