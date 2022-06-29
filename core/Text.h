//
//  Text.h
//  RSwDE
//
//  Created by Ruben Ticehurst-James on 29/06/2022.
//

#ifndef Text_h
#define Text_h


#include <string.h>

/*
 This is what most would describe as a string.
 
 */
namespace core {
	class Text {
		
		public:
			Text(const char * string) {
				unsigned int size = (unsigned int)strlen(string);
				data = new char[size + 1];
				data[size] = '\0';
				strcpy(data, string);
				this->stringSize = size;
				
			}
		
			~Text() {
				delete data;
			}
		
			Text operator + (const Text & other) {
				char buffer [stringSize + other.size() + 1];
				memmove(buffer, this->data, this->stringSize * sizeof(char));
				memmove(&(buffer[this->stringSize]), other.data, other.size() * sizeof(char));
				buffer[stringSize + other.size()] = '\0';
				return buffer;
			}
		
			unsigned int size() const {
				return stringSize;
			}
			
			
			
		private:
			char * data;
			int stringSize;
	};
}

#endif /* Text_h */
