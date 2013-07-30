#include "converttobin.h"

/*
 * Each value will be converted from DEC to BIN
 * The "invert"-parameter make the numbers inverted
 * Example: normal 		= 20 (DEC) -> 10100 (BIN)
 * 			inverted 	= 20 (DEC) -> 00101 (BIN)
 */
const std::vector<int> ConvertToBin::toBin(const int lValue,const bool lInvert)
{
	std::vector<int> lReturn;
	int lTemp = lValue;
	if(lInvert)// invert = 20 (DEC) -> 00101 (BIN)
	{
		while(lTemp > 0)
		{
			if( lTemp % 2)
				lReturn.push_back(1);
			else
				lReturn.push_back(0);

			lTemp = lTemp / 2;
		}

		while(lReturn.size() < 4)
			lReturn.push_back(0);
	}
	else  // no invert = 20 (DEC ) -> 10100 (BIN)
	{
		while(lTemp > 0)
		{
			if( lTemp % 2)
				lReturn.insert(lReturn.begin(),1);
			else
				lReturn.insert(lReturn.begin(),0);

			lTemp = lTemp / 2;
		}

		while(lReturn.size() < 4)
			lReturn.insert(lReturn.begin(),0);
	}

	return lReturn;
}


/*
 * Take a list of values from DEC to BIN.
 * The "invert"-parameter make the numbers inverted
 * Example: normal 		= 20 (DEC) -> 10100 (BIN)
 * 			inverted 	= 20 (DEC) -> 00101 (BIN)
 */
const std::vector< std::vector<int> > ConvertToBin::convertValues( const std::vector<int> &lValues,const bool lInvert){
	std::vector< std::vector<int> > lReturn;
	std::vector<int>::const_iterator it;
	for(it = lValues.begin(); it != lValues.end(); it++)
	{
		lReturn.push_back(toBin((*it),lInvert));
	}

	return lReturn;
}

