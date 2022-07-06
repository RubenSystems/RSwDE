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

#include <string>

namespace rswde {
	struct HeaderItem {

		
		core::Text key;
		core::Text value;
		

	};

	class Header : public Generatable {
		public:
		
			Header () : headers(10) {
				
			}
				
			core::Text generate();
		
			void add(const HeaderItem &);
		
		private:
			core::Array<HeaderItem> headers;
	};
}

#endif /* Header_hpp */
