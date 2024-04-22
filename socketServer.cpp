#include <iostream>
#include <thread>
#include <sockpp/tcp_acceptor.h>
#include <sockpp/version.h>

using std::cout;
using std::endl;

void run(sockpp::tcp_socket sock)
{
	ssize_t n;
	char buf[512];

	while ((n = sock.read(buf, sizeof(buf))) > 0)
		sock.write_n(buf, n);

	cout << "Connection closed from " << sock.peer_address() << endl;
}

// --------------------------------------------------------------------------
// The main thread runs the TCP port acceptor. Each time a connection is
// made a new thread is spawned to handle it leaving this main thread to
// immediately wait for the next incoming connection.

int main()
{
	cout << "Sample TCP echo server for 'sockpp' "
		<< sockpp::SOCKPP_VERSION << '\n' << endl;

	// in_port_t port = (argc > 1) ? atoi(argv[1]) : 12345;
  in_port_t port = 2547;
	sockpp::initialize();

	sockpp::tcp_acceptor acc(port);

	if (!acc) {
		std::cerr << "Error creating the acceptor: " << acc.last_error_str() << endl;
		return 1;
	}
	cout << "Awaiting connections on port " << port << endl;

	while (true) {
		sockpp::inet_address peer;

		// Accept a new client connection
		sockpp::tcp_socket sock = acc.accept(&peer);
		cout << "Received a connection request from " << peer << endl;

		if (!sock) {
			std::cerr << "Error accepting incoming connection: " 
				<< acc.last_error_str() << endl;
		}
		else {
			// Create a thread and transfer the new stream to it.
			std::thread thr(run, std::move(sock));
			thr.detach();
		};
	};

	return 0;
}