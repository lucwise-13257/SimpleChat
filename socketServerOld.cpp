#include <iostream>
#include <thread>
#include <sockpp/tcp_acceptor.h>
#include <sockpp/version.h>

using std::cout;
using std::endl;

// using namespace std;

void run(sockpp::tcp_socket sock) {
    cout << "running thing" << endl;
};

int main() {
    cout << "Socket Server Starting." << endl;
    in_port_t port = 2547;
    sockpp::initialize();
    std::error_code ec;
    sockpp::tcp_acceptor acc(port, 4);
    if (ec) {
        std::cerr << "Error creating acceptor: " << ec.message() << endl;
    };
    cout << "Listening for connections on: " << port << endl;
    while (true) {
        sockpp::inet_address peer;
        auto res = acc.accept(&peer);
        if (!res) {
            std::cerr << "Error accepting incoming connection: " << res.last_error_str() << endl;
        }
        else {
            cout << "Recieved connection request from " << peer << endl;
            auto sock = res.release();
            std::thread thr(run, std::move(sock));
            thr.detach();
        };
    };
    cout << "Exiting" << endl;
    return 0;
};