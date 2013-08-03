#ifndef PIN_H_
#define PIN_H_

#include <string>
#include "GPIO/wiringPi/wiringPi.h"
class Pin {
public:
	static const int C_UNDEFINED = 0;

	explicit Pin(const std::string& lName, const int lPinNumber);
	virtual ~Pin();

	/*
	 * Writes a value
	 */
	void writeValue(const int lValue);

	/*
	 * If the Pin was not "C_UNDEFINED" the object is valid
	 */
	const bool isIsValid() const {
		return mIsValid;
	}

	/*
	 * Returns the name of the Pin
	 */
	const std::string& getName() const {
		return mName;
	}

	/*
	 * Returns the Number of the pin
	 * Number = the GPIO port
	 */
	const int getPinNumber() const {
		return mPinNumber;
	}

private:

	const std::string mName;
	const int mPinNumber;
	bool mIsValid;
};

#endif /* PIN_H_ */
