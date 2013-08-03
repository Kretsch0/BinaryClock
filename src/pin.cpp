#include <exception>
#include "pin.h"

Pin::Pin(const std::string& lName, const int lPinNumber):
mName(lName),
mPinNumber(lPinNumber),
mIsValid(false)
{
	if(mPinNumber != C_UNDEFINED)
		mIsValid = true;
}

Pin::~Pin() {}

/*
 * Writes a value
 */
void Pin::writeValue(const int lValue)
{
	if(mIsValid)
		digitalWrite (mPinNumber,lValue);
}
