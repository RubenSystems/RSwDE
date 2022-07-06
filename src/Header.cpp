//
//  Header.cpp
//  RSwDE
//
//  Created by Ruben Ticehurst-James on 28/06/2022.
//

#include "Header.hpp"



namespace rswde {

	
	void Header::add(const HeaderItem & header) {
		this->headers.add(header);
	}
	
	core::Text Header::generate() {
		core::Text generatedHeader = "HTTP/1.1 200 OK\n";
//		//		Content-Length: 6\nServer: RubenSystems RSwDE\n\nHello!\r\n
//
		for (int i = 0; i < headers.size(); i ++) {
			generatedHeader += headers[i].key;
			generatedHeader += core::Text(": ");
			generatedHeader += headers[i].value;
			generatedHeader += core::Text("\n");
		}

		generatedHeader += core::Text("\nHello!\r\n");
		return generatedHeader;
	}
}


