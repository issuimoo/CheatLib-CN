/*
	--------------------------------------------------------
	2022-12-7 None!
	--------------------------------------------------------
*/
#include <ImGui��չ.hpp>
#include <unordered_set>
static std::unordered_set<void*> ������;
namespace ImGui {
	void ����������(void* ��ָ��, bool ��״̬)
	{
		if (��״̬)
			if(������.count(��ָ��) == 0)
				������.insert(��ָ��);
		else
			if (������.count(��ָ��) > 0)
				������.erase(��ָ��);
	}
	bool ������״̬()
	{
		return ������.size() > 0;
	}
	ImVec4 ʮ������ת��ɫ(std::string ʮ������)
	{
		int r, g, b, a;
		sscanf_s(ʮ������.c_str(), "%02x%02x%02x%02x", &r, &g, &b, &a);
		ImVec4 color{ (float(r) / 255), (float(g) / 255), (float(b) / 255), (float(a) / 255) };
		return color;
	}
	void Ĭ������()
	{
		auto& styles = ImGui::GetStyle();

		// Colors
		auto colors = styles.Colors;
		colors[ImGuiCol_Border] = ʮ������ת��ɫ("26383FFF");
		colors[ImGuiCol_BorderShadow] = ʮ������ת��ɫ("33333300");
		colors[ImGuiCol_Button] = ʮ������ת��ɫ("23303DFF");
		colors[ImGuiCol_ButtonActive] = ʮ������ת��ɫ("474968FF");
		colors[ImGuiCol_ButtonHovered] = ʮ������ת��ɫ("444C70FF");
		colors[ImGuiCol_CheckMark] = ʮ������ת��ɫ("A5BCDBFF");
		colors[ImGuiCol_ChildBg] = ʮ������ת��ɫ("1E262BFF");
		colors[ImGuiCol_DragDropTarget] = ʮ������ת��ɫ("FFFF00E5");
		colors[ImGuiCol_FrameBg] = ʮ������ת��ɫ("2D3F44FF");
		colors[ImGuiCol_FrameBgActive] = ʮ������ת��ɫ("30383DFF");
		colors[ImGuiCol_FrameBgHovered] = ʮ������ת��ɫ("26303DFF");
		colors[ImGuiCol_Header] = ʮ������ת��ɫ("0000003D");
		colors[ImGuiCol_HeaderActive] = ʮ������ת��ɫ("0070EAFF");
		colors[ImGuiCol_HeaderHovered] = ʮ������ת��ɫ("1E2833CC");
		colors[ImGuiCol_MenuBarBg] = ʮ������ת��ɫ("1E232DFF");
		colors[ImGuiCol_ModalWindowDimBg] = ʮ������ת��ɫ("CCCCCC59");
		colors[ImGuiCol_NavHighlight] = ʮ������ת��ɫ("4296F9FF");
		colors[ImGuiCol_NavWindowingDimBg] = ʮ������ת��ɫ("CCCCCC33");
		colors[ImGuiCol_NavWindowingHighlight] = ʮ������ת��ɫ("FFFFFFB2");
		colors[ImGuiCol_PlotHistogram] = ʮ������ת��ɫ("E5B200FF");
		colors[ImGuiCol_PlotHistogramHovered] = ʮ������ת��ɫ("FF9900FF");
		colors[ImGuiCol_PlotLines] = ʮ������ת��ɫ("9B9B9BFF");
		colors[ImGuiCol_PlotLinesHovered] = ʮ������ת��ɫ("FF6D59FF");
		colors[ImGuiCol_PopupBg] = ʮ������ת��ɫ("14161CEF");
		colors[ImGuiCol_ResizeGrip] = ʮ������ת��ɫ("A3C9F93F");
		colors[ImGuiCol_ResizeGripActive] = ʮ������ת��ɫ("6D8CB2F2");
		colors[ImGuiCol_ResizeGripHovered] = ʮ������ת��ɫ("A5BFDDAA");
		colors[ImGuiCol_ScrollbarBg] = ʮ������ת��ɫ("1C1C1C63");
		colors[ImGuiCol_ScrollbarGrab] = ʮ������ת��ɫ("875E5EFF");
		colors[ImGuiCol_ScrollbarGrabActive] = ʮ������ת��ɫ("8E1919FF");
		colors[ImGuiCol_ScrollbarGrabHovered] = ʮ������ת��ɫ("7C3A3AFF");
		colors[ImGuiCol_Separator] = ʮ������ת��ɫ("333F49FF");
		colors[ImGuiCol_SeparatorActive] = ʮ������ת��ɫ("6B91BFFF");
		colors[ImGuiCol_SeparatorHovered] = ʮ������ת��ɫ("4F7299C6");
		colors[ImGuiCol_SliderGrab] = ʮ������ת��ɫ("5977ADFF");
		colors[ImGuiCol_SliderGrabActive] = ʮ������ת��ɫ("ADCCFFFF");
		colors[ImGuiCol_Tab] = ʮ������ת��ɫ("1C262BFF");
		colors[ImGuiCol_TabActive] = ʮ������ת��ɫ("333F49FF");
		colors[ImGuiCol_TabHovered] = ʮ������ת��ɫ("969696CC");
		colors[ImGuiCol_TabUnfocused] = ʮ������ת��ɫ("1C262BFF");
		colors[ImGuiCol_TabUnfocusedActive] = ʮ������ת��ɫ("1C262BFF");
		colors[ImGuiCol_TableBorderLight] = ʮ������ת��ɫ("3A3A3FFF");
		colors[ImGuiCol_TableBorderStrong] = ʮ������ת��ɫ("4F4F59FF");
		colors[ImGuiCol_TableHeaderBg] = ʮ������ת��ɫ("303033FF");
		colors[ImGuiCol_TableRowBg] = ʮ������ת��ɫ("333F49FF");
		colors[ImGuiCol_TableRowBgAlt] = ʮ������ת��ɫ("1C262BFF");
		colors[ImGuiCol_Text] = ʮ������ת��ɫ("F2F4F9FF");
		colors[ImGuiCol_TextDisabled] = ʮ������ת��ɫ("2B353DFF");
		colors[ImGuiCol_TextSelectedBg] = ʮ������ת��ɫ("4296F959");
		colors[ImGuiCol_TitleBg] = ʮ������ת��ɫ("232D38A5");
		colors[ImGuiCol_TitleBgActive] = ʮ������ת��ɫ("212830FF");
		colors[ImGuiCol_TitleBgCollapsed] = ʮ������ת��ɫ("26262682");
		colors[ImGuiCol_WindowBg] = ʮ������ת��ɫ("1E2623FF");

		//Styles
		styles.Alpha = 1.0;
		styles.AntiAliasedFill = true;
		styles.AntiAliasedLines = true;
		styles.AntiAliasedLinesUseTex = true;
		styles.ButtonTextAlign = ImVec2(0.5, 0.5);
		styles.CellPadding = ImVec2(4.0, 2.0);
		styles.ChildBorderSize = 1.0;
		styles.ChildRounding = 5.0;
		styles.CircleTessellationMaxError = 0.30000001192092896;
		styles.ColorButtonPosition = 1;
		styles.ColumnsMinSpacing = 6.0;
		styles.CurveTessellationTol = 1.25;
		styles.DisabledAlpha = 0.6000000238418579;
		styles.DisplaySafeAreaPadding = ImVec2(3.0, 3.0);
		styles.DisplayWindowPadding = ImVec2(19.0, 19.0);
		styles.FrameBorderSize = 0.0;
		styles.FramePadding = ImVec2(4.0, 3.0);
		styles.FrameRounding = 4.0;
		styles.GrabMinSize = 10.0;
		styles.GrabRounding = 4.0;
		styles.IndentSpacing = 21.0;
		styles.ItemInnerSpacing = ImVec2(4.0, 4.0);
		styles.ItemSpacing = ImVec2(8.0, 4.0);
		styles.LogSliderDeadzone = 4.0;
		styles.MouseCursorScale = 1.0;
		styles.PopupBorderSize = 1.0;
		styles.PopupRounding = 0.0;
		styles.ScrollbarRounding = 9.0;
		styles.ScrollbarSize = 14.0;
		styles.SelectableTextAlign = ImVec2(0.0, 0.0);
		styles.TabBorderSize = 0.0;
		styles.TabMinWidthForCloseButton = 0.0;
		styles.TabRounding = 4.0;
		styles.TouchExtraPadding = ImVec2(0.0, 0.0);
		styles.WindowBorderSize = 1.0;
		styles.WindowMenuButtonPosition = 0;
		styles.WindowMinSize = ImVec2(32.0, 32.0);
		styles.WindowPadding = ImVec2(8.0, 8.0);
		styles.WindowRounding = 0.0;
		styles.WindowTitleAlign = ImVec2(0.0, 0.5);
	}
}