#include "initializer.h"
#include "GPIO/wiringPi/wiringPi.h"
#include "GPIO/wiringPi/sr595.h"
#include <iostream>
using namespace std;

Initializer::Initializer() {
	setUpWiringPi();
	pinMapping();
}

Initializer::~Initializer() {}

/*
 * This instantiates the connection between the GPIO-PIN and the Pin-Object
 * witch we use to interact with the GPIO port
 */
void Initializer::pinMapping()
{
	std::vector< std::vector<boost::shared_ptr<Pin> > > lPins;
	std::vector<boost::shared_ptr<Pin> > lTempPins;

	/*
	 * This is the Pin mapping.
	 *
	 * The following picture is a plan how the lamps from the binary clock
	 * are connected.
	 *
	 *
	 *     		[3,4]  	|     	[3,2] 	|     	[3,0]	3
	 *
	 *     		[2,4]  	| [2,3]	[2,2] 	| [2,1]	[2,0]	2
	 *
	 * [1,5]	[1,4]	| [1,3]	[1,2] 	| [1,1]	[1,0]	1
	 *
	 * [0,5]	[0,4]  	| [0,3]	[0,2] 	| [0,1]	[0,0]	0
	 *
	 *	 5		  4			3 	  2			1	  0
	 *
	 *
	 * Later we iterate over the list and map the pin to a binary value.( 0 or 1)
	 * We iterate forward over the list -> started with [0,0] then [0,1] and so on..
	 * This means the binary values must be inverted in later steps ( 20 is NOT 10100 but 00101 )
	 */

	/*
	 * INFO: I bought a Bit shifting register of type (74HC959N).
	 * The Second parameter is the pin value this was emulated
	 * by the "wiringPi"-lib.
	 */

	boost::shared_ptr<Pin> lPin0_0(new Pin("lPin0_0", 253));
	boost::shared_ptr<Pin> lPin1_0(new Pin("lPin1_0", 254));
	boost::shared_ptr<Pin> lPin2_0(new Pin("lPin2_0", 255));
	boost::shared_ptr<Pin> lPin3_0(new Pin("lPin3_0", 256));
	lTempPins.push_back(lPin0_0);
	lTempPins.push_back(lPin1_0);
	lTempPins.push_back(lPin2_0);
	lTempPins.push_back(lPin3_0);
	lPins.push_back(lTempPins);

	boost::shared_ptr<Pin> lPin0_1 (new Pin("lPin0_1", 257));
	boost::shared_ptr<Pin> lPin1_1 (new Pin("lPin1_1", 258));
	boost::shared_ptr<Pin> lPin2_1 (new Pin("lPin2_1", 259));
	boost::shared_ptr<Pin> lPin3_1 (new Pin("lPin3_1", Pin::C_UNDEFINED));
	lTempPins.clear();
	lTempPins.push_back(lPin0_1);
	lTempPins.push_back(lPin1_1);
	lTempPins.push_back(lPin2_1);
	lTempPins.push_back(lPin3_1);
	lPins.push_back(lTempPins);

	boost::shared_ptr<Pin> lPin0_2 (new Pin("lPin0_2", 246));
	boost::shared_ptr<Pin> lPin1_2 (new Pin("lPin1_2", 247));
	boost::shared_ptr<Pin> lPin2_2 (new Pin("lPin2_2", 248));
	boost::shared_ptr<Pin> lPin3_2 (new Pin("lPin3_2", 249));
	lTempPins.clear();
	lTempPins.push_back(lPin0_2);
	lTempPins.push_back(lPin1_2);
	lTempPins.push_back(lPin2_2);
	lTempPins.push_back(lPin3_2);
	lPins.push_back(lTempPins);

	boost::shared_ptr<Pin> lPin0_3 (new Pin("lPin0_3", 250));
	boost::shared_ptr<Pin> lPin1_3 (new Pin("lPin1_3", 251));
	boost::shared_ptr<Pin> lPin2_3 (new Pin("lPin2_3", 252));
	boost::shared_ptr<Pin> lPin3_3 (new Pin("lPin3_3", Pin::C_UNDEFINED));
	lTempPins.clear();
	lTempPins.push_back(lPin0_3);
	lTempPins.push_back(lPin1_3);
	lTempPins.push_back(lPin2_3);
	lTempPins.push_back(lPin3_3);
	lPins.push_back(lTempPins);

	boost::shared_ptr<Pin> lPin0_4 (new Pin("lPin0_4", 240));
	boost::shared_ptr<Pin> lPin1_4 (new Pin("lPin1_4", 241));
	boost::shared_ptr<Pin> lPin2_4 (new Pin("lPin2_4", 242));
	boost::shared_ptr<Pin> lPin3_4 (new Pin("lPin3_4", 243));
	lTempPins.clear();
	lTempPins.push_back(lPin0_4);
	lTempPins.push_back(lPin1_4);
	lTempPins.push_back(lPin2_4);
	lTempPins.push_back(lPin3_4);
	lPins.push_back(lTempPins);

	boost::shared_ptr<Pin> lPin0_5 (new Pin("lPin0_5", 244));
	boost::shared_ptr<Pin> lPin1_5 (new Pin("lPin1_5", 245));
	boost::shared_ptr<Pin> lPin2_5 (new Pin("lPin2_5", Pin::C_UNDEFINED));
	boost::shared_ptr<Pin> lPin3_5 (new Pin("lPin3_5", Pin::C_UNDEFINED));
	lTempPins.clear();
	lTempPins.push_back(lPin0_5);
	lTempPins.push_back(lPin1_5);
	lTempPins.push_back(lPin2_5);
	lTempPins.push_back(lPin3_5);
	lPins.push_back(lTempPins);

	this->lPins = lPins;
}

/*
 * The setup for the WiringPi library
 */
void Initializer::setUpWiringPi()
{
	wiringPiSetup () ;

	// 24 pins = 240 Pin base
	//    Use wiringPi pins 0, 1 & 2 for data, clock and latch
	sr595Setup (240, 24, 0, 1, 2) ; //own function
}
