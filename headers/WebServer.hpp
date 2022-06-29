//
//  WebServer.hpp
//  RSwDE
//
//  Created by Ruben Ticehurst-James on 28/06/2022.
//

#ifndef WebServer_hpp
#define WebServer_hpp

#include <stdio.h>

namespace RSwDE {
	class WebServer {
	public:
		
		WebServer(int port);
		
		void start();
		
		void shutdown();
		
	private:
		int port;
		
		
		
		
	};
}


#endif /* WebServer_hpp */
