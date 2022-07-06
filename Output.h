//
//  Output.h
//  RSwDE
//
//  Created by Ruben Ticehurst-James on 01/07/2022.
//

#ifndef Output_h
#define Output_h


#define _DEBUG true

#if _DEBUG
	#include <iostream>
	#define out(value) (std::cout << value << std::endl)
#else
	#define out(value)
#endif


#endif /* Output_h */
