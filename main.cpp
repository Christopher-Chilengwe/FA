///////////////////////////////////////////////////////////////
// main.cpp

/**************************************************************
* Author    :		 Sarkisian, Armond
* Date      :        17, December 2004
* Time      :        15:30 (PST)
* Software  :        Bank Account
* Version   :		 1.2
* Revision  :        0.1
* Completed :        22, December 2004 ; 14:40 (PST)
**************************************************************/
/**************************************************************
********************* PROGRAM UPDATES *************************
***************************************************************
* Date           :   07, August 2006
* Time           :   08:44 (PST)
* Change Request :   Removed const due to conflict issues with
*                    MSVS 2005
* Revision       :   0.1
***************************************************************
* Date           :   
* Time           :   
* Change Request :   
*                    
* Revision       :   
***************************************************************
* Date           :   
* Time           :   
* Change Request :   
*                    
* Revision       :   
***************************************************************
* Date           :   
* Time           :   
* Change Request :   
*                    
* Revision       :   
**************************************************************/
///////////////////////////////////////////////////////////////
#include "Account.h"
///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////
using std::cerr;
using std::exception;
using std::flush;
///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////
void clearScreen();
void doMain();
///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////
int main(int argc, char* argv[])
{
	try
	{
		doMain();
	}
	catch(const exception& e)
	{
		cerr << EXCEPTION << e.what() << '\n';
	}
	catch(...)
	{
		cerr << UNKNOWN_ERROR << '\n';
	}

	flush(cerr);

	clearScreen();

	return(EXIT_SUCCESS);
}
///////////////////////////////////////////////////////////////