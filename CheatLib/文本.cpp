/*
	--------------------------------------------------------
	2022-12-7 None!
	--------------------------------------------------------
*/
#include <codecvt>
namespace �ı� {
	std::string UTF16תUTF8(const std::wstring& UTF16�ı�)
	{
		static std::wstring_convert<std::codecvt_utf8<wchar_t>> strCnv;
		return strCnv.to_bytes(UTF16�ı�);
	}
}