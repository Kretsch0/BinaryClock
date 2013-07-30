#include <exception>
#include "pin.h"

Pin::Pin(const std::string& lName, const int lPinNumber,const bool lSetAsOutPut):
mName(lName),
mPinNumber(lPinNumber),
mIsValid(false)
{
	if(mPinNumber != C_UNDEFINED)
		mIsValid = true;

	if(lSetAsOutPut && isIsValid())
		setAsOutPut();
}

Pin::~Pin() {}

/*
 * Writes a value
 */
void Pin::writeValue(const int lValue)
{
	if(mIsValid)
		GPIO_Write(mPinNumber, lValue);
}

/*
 * Set a pin as a output pin
 */
void Pin::setAsOutPut()
{
	setGPIO_Out(mPinNumber);
}
