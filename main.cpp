#include <iostream>
#include <thread>
#include <string>
#include <chrono>
#include <wx/wx.h>
#include <sockpp/tcp_connector.h>

using std::cout;
using std::endl;

class App : public wxApp {
public:
  bool OnInit() override;
};

class MainFrame : public wxFrame {
public:
  MainFrame();

private:
  void OnExit(wxCommandEvent& event);
  void SendPing(wxCommandEvent& event);
};

enum {
  FILE_MENU = 1,
  MSG_BOX = 2,
  SEND_PING = 3
};

wxIMPLEMENT_APP(App);

MainFrame::MainFrame() : wxFrame(nullptr, wxID_ANY, "SimpleChat") {
  // wxPanel* panel = new wxPanel(this);
  this->SetBackgroundColour(wxColor(32,54,98));
  // panel->SetBackgroundColour(wxColor(32,54,98));
  // Menu Stuff
  wxMenuBar* menuBar = new wxMenuBar;
  wxMenu* fileMenu = new wxMenu;
  fileMenu->Append(FILE_MENU, "Quit");
  fileMenu->Append(SEND_PING, "Send Ping");
  Bind(wxEVT_MENU, &MainFrame::OnExit, this, FILE_MENU);
  Bind(wxEVT_MENU, &MainFrame::SendPing, this, SEND_PING);
  menuBar->Append(fileMenu, "File");
  SetMenuBar(menuBar);

  wxTextCtrl* msgBox = new wxTextCtrl(this, MSG_BOX);
  msgBox->SetValue("PlaceHolder");
  wxBoxSizer* vertSizer = new wxBoxSizer(wxVERTICAL);
  // vertSizer->Add(panel, 1, wxEXPAND | wxALL);
  vertSizer->Add(msgBox, 0, wxALIGN_CENTER | wxLEFT | wxRIGHT | wxBOTTOM);
  this->SetSizer(vertSizer);
  this->SetSize(wxSize(800, 600));
  this->Center(wxBOTH);

};

bool App::OnInit() {
  MainFrame* mainFrame = new MainFrame();
  mainFrame->Show();
  sockpp::initialize();
  return true;
};


void MainFrame::OnExit(wxCommandEvent& event) {
  Close();
};

void MainFrame::SendPing(wxCommandEvent& event) {
  in_port_t port = 2547;
  sockpp::tcp_connector conn({"localhost", port}, std::chrono::seconds(5));
  conn.write_n("Ping from SimpleChat", 21);
};