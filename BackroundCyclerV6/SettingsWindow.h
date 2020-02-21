#pragma once
#include "pch.h"
enum
{
	ID_Hello = 1
};

class SettingsWindow : public wxFrame
{
public:
	SettingsWindow(const wxString& title, const wxPoint& pos, const wxSize& size);
	~SettingsWindow() override;
private:
	SettingsWindow() {}

protected:
	void OnHello(wxCommandEvent& event);
	void OnExit(wxCommandEvent& event);
	void OnAbout(wxCommandEvent& event);
	wxDECLARE_EVENT_TABLE();
};

