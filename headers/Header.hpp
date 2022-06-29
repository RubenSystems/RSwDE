//
//  Header.hpp
//  RSwDE
//
//  Created by Ruben Ticehurst-James on 28/06/2022.
//

#ifndef Header_hpp
#define Header_hpp

#include <stdio.h>
#include "../core/Array.h"
#include "../core/Text.h"


struct HeaderItem {
	std::string key;
	std::string value;
};

class Header {
	
	
	private:
		core::Array<HeaderItem> headers;
};

#endif /* Header_hpp */
