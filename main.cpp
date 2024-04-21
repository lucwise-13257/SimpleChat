#include <iostream>
#include <thread>
#include <string>
#include <wx/wx.h>
#include <masesk/EasySocket.hpp>

class App : public wxApp {
public:
  bool OnInit() override;
};

class MainFrame : public wxFrame {
public:
  MainFrame();

private:
  void OnExit(wxCommandEvent& event);
};

enum {
  FILE_MENU = 1
};

wxIMPLEMENT_APP(App);

MainFrame::MainFrame() : wxFrame(nullptr, wxID_ANY, "SimpleChat") {
  wxPanel* panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize);
  panel->SetBackgroundColour(wxColor(32,54,98));
  // Menu Stuff
  wxMenuBar* menuBar = new wxMenuBar;
  wxMenu* fileMenu = new wxMenu;
  fileMenu->Append(FILE_MENU, "Quit");
  Bind(wxEVT_MENU, &MainFrame::OnExit, this, FILE_MENU);
  menuBar->Append(fileMenu, "File");
  SetMenuBar(menuBar);

  wxTextCtrl* msgBox = new wxTextCtrl;
  
  wxBoxSizer* horizSizer = new wxBoxSizer(wxHORIZONTAL);
  horizSizer->Add(panel, 1, wxEXPAND | wxALL);
  this->SetSize(wxSize(800, 600));
  this->Center(wxBOTH);

};

bool App::OnInit() {
  MainFrame* mainFrame = new MainFrame();
  mainFrame->Show();
  return true;
};


void MainFrame::OnExit(wxCommandEvent& event) {
  Close();
};