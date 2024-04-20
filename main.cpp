#include <iostream>
#include <wx/wx.h>

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

wxIMPLEMENT_APP(App);

MainFrame::MainFrame() : wxFrame(nullptr, wxID_ANY, "Downloader") {
  wxPanel* panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize);
  panel->SetBackgroundColour(wxColor(32,54,98));
  wxBoxSizer* vertSizer = new wxBoxSizer(wxVERTICAL);


  this->Center(wxBOTH);
};

bool App::OnInit() {
  MainFrame* mainFrame = new MainFrame();
  mainFrame->Show();
  return true;
};