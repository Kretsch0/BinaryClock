#ifndef CONVERTTOBIN_H
#define CONVERTTOBIN_H

#include <vector>

class ConvertToBin
{
public:
	/*
	 * Each value will be converted from DEC to BIN
	 * The "invert"-parameter make the numbers inverted
     * Example: normal 		= 20 (DEC) -> 10100 (BIN)
     * 			inverted 	= 20 (DEC) -> 00101 (BIN)
	 */
    static const std::vector<int> toBin(const int lValue, const bool lInvert);

    /*
     * Take a list of values from DEC to BIN.
     * The "invert"-parameter make the numbers inverted
     * Example: normal 		= 20 (DEC) -> 10100 (BIN)
     * 			inverted 	= 20 (DEC) -> 00101 (BIN)
     */
    static const std::vector< std::vector<int> > convertValues( const std::vector<int> &lValues, const bool lInvert );
};

#endif // CONVERTTOBIN_H
