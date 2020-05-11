#include "pch.h"
#include "SettingsWindow.hpp"

SettingsWindow::SettingsWindow(const wxString& title, const wxPoint& pos, const wxSize& size)
		: wxFrame(nullptr, MAINWINDOW, title, pos, size) 
{
	wxBoxSizer* bSizer = new wxBoxSizer(wxHORIZONTAL);
	this->MenuBarSetup();

	this->SetSizeHints(wxDefaultSize, wxDefaultSize, wxDefaultSize);
	this->Connect(wxEVT_CLOSE_WINDOW, wxCloseEventHandler(SettingsWindow::OnCloseWindow));
	this->Connect(ToolBarId::TB_CLOSE, wxEVT_COMMAND_TOOL_CLICKED, 
		wxCommandEventHandler(SettingsWindow::OnExit));
}

SettingsWindow::~SettingsWindow()
{

}

void SettingsWindow::OnExit(wxCommandEvent& event)
{
	Close(true);
}

void SettingsWindow::OnCloseWindow(wxCloseEvent& event)
{
	event.Skip();
}

void SettingsWindow::MenuBarSetup()
{
	toolBar = this->CreateToolBar(
		/*wxTB_FLAT |*/ wxTB_HORIZONTAL | wxTB_HORZ_LAYOUT | wxTB_TEXT | wxTB_NOICONS,
		MW_TOOLBAR);
	TB_ChangeBackground = toolBar->AddTool(TB_CHANGEBG, wxT("Change Background"),
		wxNullBitmap, wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, nullptr);

	toolBar->AddSeparator();

	TB_CloseWindow = toolBar->AddTool(TB_CLOSE, wxT("Close Window"),
		wxNullBitmap, wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, nullptr);

	TB_QuitProgram = toolBar->AddTool(TB_QUIT, wxT("Quit Program"),
		wxNullBitmap, wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, nullptr);

	toolBar->Realize();
}