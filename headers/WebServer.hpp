//
//  WebServer.hpp
//  RSwDE
//
//  Created by Ruben Ticehurst-James on 28/06/2022.
//

#ifndef WebServer_hpp
#define WebServer_hpp

#include <stdio.h>
#include "../core/Text.h"

namespace rswde {
	class WebServer {
	public:
		
		typedef core::Text (*Callback)(core::Text);
		
		WebServer(int port);
		
		void start(Callback);
		
		void shutdown();
		
	private:
		int port;
		
		
		
		
	};
}


#endif /* WebServer_hpp */
