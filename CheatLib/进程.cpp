/*
	--------------------------------------------------------
	2022-12-7 None!
	--------------------------------------------------------
*/
#include <����.hpp>
#include <filesystem>
#include <����̨.h>
#include <TlHelp32.h>
#include <�ı�.hpp>
namespace ���� {
	std::string ȡģ��·��(HMODULE ģ����)
	{
		char pathOut[MAX_PATH] = {};
		GetModuleFileNameA(ģ����, pathOut, MAX_PATH);
		std::string Ŀ¼ = std::filesystem::path(pathOut).parent_path().string();
		return Ŀ¼;
	}
	DWORD ������ȡID(std::string ��������)
	{
		HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
		if (INVALID_HANDLE_VALUE == hSnapshot) {
			return NULL;
		}
		PROCESSENTRY32 pe = { sizeof(pe) };
		for (BOOL ret = Process32First(hSnapshot, &pe); ret; ret = Process32Next(hSnapshot, &pe)) {
			if (strcmp(pe.szExeFile, ��������.c_str()) == 0) {
				CloseHandle(hSnapshot);
				return pe.th32ProcessID;
			}
		}
		CloseHandle(hSnapshot);
		return 0;
	}
	std::string ����IDȡ��(DWORD ����ID)
	{
		HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
		if (INVALID_HANDLE_VALUE == hSnapshot) {
			return "";
		}
		PROCESSENTRY32 pe = { sizeof(pe) };
		for (BOOL ret = Process32First(hSnapshot, &pe); ret; ret = Process32Next(hSnapshot, &pe)) {
			if (pe.th32ProcessID == ����ID)
			{
				return (const char*)(pe.szExeFile[MAX_PATH]);
			}
		}
		CloseHandle(hSnapshot);
		return "";
	}
	PVOID ģ��ȡ������ַ(LPCSTR ģ������, LPCSTR ��������)
	{
		auto hModule = GetModuleHandleA(ģ������);
		if (hModule == NULL)
			return nullptr;
		return GetProcAddress(hModule, ��������);
	}
	HANDLE �򿪽���(DWORD ����ID)
	{
		return OpenProcess(PROCESS_ALL_ACCESS, false, ����ID);
	}
	LPDWORD �����߳�(void(*p))
	{
		LPDWORD ID = nullptr;
		CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)p, 0, 0, ID);
		return ID;
	}
	bool ������Ȩ()
	{
		HANDLE hToken = nullptr;
		if (FALSE == OpenProcessToken(GetCurrentProcess(), TOKEN_ALL_ACCESS, &hToken))
		{
			return false;
		}
		LUID luid;
		if (FALSE == LookupPrivilegeValue(nullptr, SE_DEBUG_NAME, &luid))
		{
			CloseHandle(hToken);
			return false;
		}
		TOKEN_PRIVILEGES Tok;
		Tok.PrivilegeCount = 1;
		Tok.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
		Tok.Privileges[0].Luid = luid;
		if (FALSE == AdjustTokenPrivileges(hToken, FALSE, &Tok, sizeof(Tok), nullptr, nullptr))
		{
			CloseHandle(hToken);
			return false;
		}

		if (GetLastError() == ERROR_NOT_ALL_ASSIGNED)
		{
			CloseHandle(hToken);
			return false;
		}

		CloseHandle(hToken);
		return true;
	}
}