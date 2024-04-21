#include <iostream>
#include <thread>
#include <string>
#include <masesk/EasySocket.hpp>

using std::cout;
using std::endl;
using std::string;

void run(const string& data) {
    cout << "Recieved data: " << data << endl;
};


int main() {
    cout << "Socket Server Starting" << endl;
    cout << "Listening for connections on port: 2547" << endl;
    masesk::EasySocket socketManager;
    socketManager.socketListen("Main", 2547, &run);
    
    return 0;
};