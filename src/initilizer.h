/*
 * initilizer.h
 *
 *  Created on: 27.07.2013
 *      Author: Jendrik
 */

#ifndef INITILIZER_H_
#define INITILIZER_H_
#include <vector>
#include "time.h"
#include "converttobin.h"
#include "pin.h"
#include "boost/shared_ptr.hpp"
class Initilizer {
public:
	Initilizer();
	virtual ~Initilizer();

	const std::vector<std::vector<boost::shared_ptr<Pin> > > &getPins() const {
		return lPins;
	}

private:
	/*
	 * This instantiates the connection between the GPIO-PIN and the Pin-Object
	 * witch we use to interact with the GPIO port
	 */
	void pinMapping();

	/*
	 * The setup for the WiringPi library
	 */
	void setUpWiringPi();

	std::vector< std::vector<boost::shared_ptr<Pin> > > lPins;
};


#endif /* INITILIZER_H_ */
