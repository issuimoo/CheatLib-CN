/*
	--------------------------------------------------------
	2022-12-7 None!
	--------------------------------------------------------
*/
#include <Windows.h>
#include <string>
#include <detours.h>
#include <dwmapi.h>
#include <ImGuiD11����.hpp>
#include <imgui_impl_win32.h>
#include <imgui_impl_dx11.h>
#include <����̨.h>
#include <imgui.h>
#include <implot.h>
#include <imnodes.h>
#include <ImGui��չ.hpp>
#include <����.hpp>
#include <Font.h>
#pragma comment (lib, "winmm.lib")
#pragma comment (lib, "User32.lib")
#pragma comment (lib, "Gdi32.lib")
#pragma comment (lib, "shlwapi.lib")
#if _WIN32
#pragma comment (lib,"detours-x86.lib")
#else
#pragma comment (lib,"detours-x64.lib")
#endif
namespace DX11���� {
	ID3D11Device* �豸ָ�� = nullptr;
	ID3D11DeviceContext* �豸����;
	ID3D11RenderTargetView* ����ȾĿ����ͼ;
	typedef HRESULT(__stdcall* IDXGISwapChainPresent)(IDXGISwapChain* ������, UINT ͬ�����, UINT ����);
	static IDXGISwapChainPresent fnIDXGISwapChainPresent;
	struct ImGui���� {
		unsigned char* ����;
		float �����С;
		HMODULE ģ����;
		void (*����ѭ��)();
		std::string ImGui����Ŀ¼;
		bool ���Է��� = false;
		IDXGISwapChain* ������;
	}����;
	extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	static WNDPROC OriginalWndProcHandler;
	static LRESULT CALLBACK hWndProc(HWND ���ھ��, UINT ��Ϣ, WPARAM ״̬, LPARAM �ͻ���)
	{
		ImGuiIO& io = ImGui::GetIO();
		POINT mPos;
		GetCursorPos(&mPos);
		ScreenToClient(���ھ��, &mPos);
		ImGui::GetIO().MousePos.x = static_cast<float>(mPos.x);
		ImGui::GetIO().MousePos.y = static_cast<float>(mPos.y);

		ImGui_ImplWin32_WndProcHandler(���ھ��, ��Ϣ, ״̬, �ͻ���);

		short key;
		bool keyUpEvent = true;
		switch (��Ϣ)
		{
		case WM_LBUTTONUP:
			key = VK_LBUTTON;
			break;
		case WM_RBUTTONUP:
			key = VK_RBUTTON;
			break;
		case WM_MBUTTONUP:
			key = VK_MBUTTON;
			break;
		case WM_XBUTTONUP:
			key = GET_XBUTTON_WPARAM(״̬) == XBUTTON1 ? VK_XBUTTON1 : VK_XBUTTON2;
			break;
		case WM_KEYUP:
			key = static_cast<short>(״̬);
			break;
		default:
			keyUpEvent = false;
			break;
		}

		if (ImGui::������״̬())
			return true;

		return CallWindowProc(OriginalWndProcHandler, ���ھ��, ��Ϣ, ״̬, �ͻ���);
	}
	static HRESULT __stdcall Present_Hook(IDXGISwapChain* pChain, const UINT SyncInterval, const UINT Flags)
	{
		static BOOL g_bInitialised = false;
		if (!g_bInitialised)
		{
			auto result = (HRESULT)pChain->GetDevice(__uuidof(�豸ָ��), reinterpret_cast<void**>(&�豸ָ��));
			if (SUCCEEDED(result))
			{
				����.������ = pChain;
				�豸ָ��->GetImmediateContext(&�豸����);
				�������("GetImmediateContext\n");
				DXGI_SWAP_CHAIN_DESC sd;
				pChain->GetDesc(&sd);
				�������("GetDesc\n");
				ImGui::CreateContext();
				�������("ImGui::CreateContext\n");
				ImPlot::CreateContext();
				�������("ImGui::CreateContext\n");
				ImNodes::CreateContext();
				�������("ImNodes::CreateContext\n");
				ImGuiIO& io = ImGui::GetIO(); (void)io;
				io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
				if (����.���� != nullptr)
				{
					io.Fonts->AddFontFromMemoryTTF(����.����, sizeof(����.����), ����.�����С, NULL, io.Fonts->GetGlyphRangesChineseFull());
				}
				else
				{
					io.Fonts->AddFontFromMemoryTTF(Font::getallfont(), sizeof(Font::getallfont()), ����.�����С, NULL, io.Fonts->GetGlyphRangesChineseFull());
				}
				if (����.ImGui����Ŀ¼ == "")
				{
					io.IniFilename = std::string(����::ȡģ��·��(����.ģ����) + "\\imgui.ini").c_str();
				}
				else
				{
					io.IniFilename = ����.ImGui����Ŀ¼.c_str();
				}
				ImGui::Ĭ������();
				//Set OriginalWndProcHandler to the Address of the Original WndProc function
				OriginalWndProcHandler = reinterpret_cast<WNDPROC>(SetWindowLongPtr(sd.OutputWindow, GWLP_WNDPROC,
					reinterpret_cast<LONG_PTR>(hWndProc)));
				ImGui_ImplWin32_Init(sd.OutputWindow);
				ImGui_ImplDX11_Init(�豸ָ��, �豸����);
				ID3D11Texture2D* pBackBuffer;
				pChain->GetBuffer(0, __uuidof(ID3D11Texture2D), reinterpret_cast<LPVOID*>(&pBackBuffer));
				�豸ָ��->CreateRenderTargetView(pBackBuffer, nullptr, &����ȾĿ����ͼ);
				pBackBuffer->Release();
				io.SetPlatformImeDataFn = nullptr;
				g_bInitialised = true;
				����.���Է��� = g_bInitialised;
			}
		}
		if (g_bInitialised)
			ImGui_ImplDX11_NewFrame();
			ImGui_ImplWin32_NewFrame();
			ImGuiIO& io = ImGui::GetIO(); (void)io;
			ImGui::NewFrame();
			����.����ѭ��();
			ImGui::EndFrame();
			ImGui::Render();
			�豸����->OMSetRenderTargets(1, &����ȾĿ����ͼ, nullptr);
			ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
		return fnIDXGISwapChainPresent(pChain, SyncInterval, Flags);
	}
	bool ��װDX11����(void (*����ѭ��)(), HMODULE ģ����, std::string ImGui����Ŀ¼, float �����С, unsigned char* ����, ID3D11Device* DX11�豸ָ��, ID3D11DeviceContext* DX11�豸����, ID3D11RenderTargetView* DX11����ȾĿ����ͼ, IDXGISwapChain* DX11������) {
		����.���� = ����;����.�����С = �����С;����.����ѭ�� = ����ѭ��;����.ģ���� = ģ����;����.ImGui����Ŀ¼ = ImGui����Ŀ¼;
		WNDCLASSEX wc{ 0 };
		wc.cbSize = sizeof(wc);
		wc.lpfnWndProc = DefWindowProc;
		wc.lpszClassName = TEXT("Class");
		if (!RegisterClassEx(&wc))
		{
			�������("RegisterClassEx ����\n");
			return false;
		}
		HWND hWnd = CreateWindow(wc.lpszClassName, TEXT(""), WS_DISABLED, 0, 0, 0, 0, NULL, NULL, NULL, nullptr);
		IDXGISwapChain* pSwapChain;
		D3D_FEATURE_LEVEL featureLevel;
		DXGI_SWAP_CHAIN_DESC swapChainDesc;
		ZeroMemory(&swapChainDesc, sizeof(swapChainDesc));
		swapChainDesc.BufferCount = 1;
		swapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
		swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
		swapChainDesc.OutputWindow = hWnd;
		swapChainDesc.SampleDesc.Count = 1;
		swapChainDesc.Windowed = TRUE;  //((GetWindowLong(hWnd, GWL_STYLE) & WS_POPUP) != 0) ? FALSE : TRUE;
		swapChainDesc.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
		swapChainDesc.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
		swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
		// Main D3D11 Objects
		ID3D11DeviceContext* pContext = nullptr;
		ID3D11Device* pDevice = nullptr;
		if (FAILED(D3D11CreateDeviceAndSwapChain(nullptr, D3D_DRIVER_TYPE_WARP, nullptr, 0, nullptr, 1, D3D11_SDK_VERSION,
			&swapChainDesc, &pSwapChain, &pDevice, &featureLevel, &pContext)) &&
			FAILED(D3D11CreateDeviceAndSwapChain(nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, 0, nullptr, 0, D3D11_SDK_VERSION,
				&swapChainDesc, &pSwapChain, &pDevice, &featureLevel, &pContext)))
		{
			DestroyWindow(swapChainDesc.OutputWindow);
			UnregisterClass(wc.lpszClassName, GetModuleHandle(nullptr));
			�������("D3D11CreateDeviceAndSwapChain ����\n");
			return false;
		}
		const DWORD_PTR* pSwapChainVtable = reinterpret_cast<DWORD_PTR*>(pSwapChain);
		pSwapChainVtable = reinterpret_cast<DWORD_PTR*>(pSwapChainVtable[0]);
		auto swapChainPresent = reinterpret_cast<IDXGISwapChainPresent>(pSwapChainVtable[8]);
		pDevice->Release();
		pContext->Release();
		pSwapChain->Release();
		DestroyWindow(swapChainDesc.OutputWindow);
		UnregisterClass(wc.lpszClassName, GetModuleHandle(nullptr));
		if (swapChainPresent == nullptr)
		{
			�������("δ����DX11Present!\n");
			return false;
		}
		DetourTransactionBegin();
		�������("DetourTransactionBegin\n");
		DetourUpdateThread(GetCurrentThread());
		�������("DetourUpdateThread\n");
		DetourAttach(&(PVOID&)swapChainPresent, Present_Hook);
		�������("DetourAttach\n");
		DetourTransactionCommit();
		�������("DetourUpdateThread\n");
		while (!����.���Է���){DX11�豸ָ�� = �豸ָ��; DX11�豸���� = �豸����; DX11����ȾĿ����ͼ = ����ȾĿ����ͼ; DX11������ = ����.������;}
	}
}