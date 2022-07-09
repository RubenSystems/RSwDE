//
//  WebServer.cpp
//  RSwDE
//
//  Created by Ruben Ticehurst-James on 28/06/2022.
//

#include "../headers/WebServer.hpp"
#include "../headers/Header.hpp"

#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <future>


namespace rswde {
	WebServer::WebServer(int port): port(port) { }

	void WebServer::start(Callback completion) {
		int server_fd, valread;
		
		int opt = 1;
		struct sockaddr_in address;
		int addrlen = sizeof(address);
		char buffer[1024] = { 0 };
		
		
	
	 
		// Creating socket file descriptor
		if ((server_fd = socket(AF_INET, SOCK_STREAM, 0))
			== 0) {
			perror("socket failed");
			exit(EXIT_FAILURE);
		}
	 
		// Forcefully attaching socket to the port 8080
		if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEPORT, &opt, sizeof(opt))) {
			perror("setsockopt");
			exit(EXIT_FAILURE);
		}
		
		if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
			perror("setsockopt 2");
			exit(EXIT_FAILURE);
		}
		address.sin_family = AF_INET;
		address.sin_addr.s_addr = INADDR_ANY;
		address.sin_port = htons(this->port);
	 
		// Forcefully attaching socket to the port 8080
		if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
			perror("bind failed");
			exit(EXIT_FAILURE);
		}
		if (listen(server_fd, 10) < 0) {
			perror("listen");
			exit(EXIT_FAILURE);
		}
		while (true) {
			int new_socket;
			if ((new_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen)) < 0) {
				perror("accept");
				exit(EXIT_FAILURE);
			}
			valread = (int)read(new_socket, buffer, 1024);
			const auto future = std::async(std::launch::async, [&buffer, &completion, new_socket](){
				core::Text response = completion(buffer);
				::send(new_socket, response.c_string(), response.size(), 0);
				::close(new_socket);
			});
			//		printf("%s\n", );
			
		}
		
//		::shutdown(server_fd, SHUT_RDWR);
	}

	void WebServer::shutdown(){}
}

