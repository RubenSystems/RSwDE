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
#include "Generatable.h"

struct HeaderItem : Generatable {
	core::Text key;
	core::Text value;
	
	
};

class Header : Generatable {
	
	
	private:
		core::Array<HeaderItem> headers;
};

#endif /* Header_hpp */
