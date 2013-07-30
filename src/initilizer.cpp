#include "initilizer.h"
#include "GPIO/gpioUtil.h"
#include <iostream>
using namespace std;

Initilizer::Initilizer() {
	pinMapping();

}

Initilizer::~Initilizer() {}

/*
 * This instantiates the connection between the GPIO-PIN and the Pin-Object
 * witch we use to interact with the GPIO port
 */
void Initilizer::pinMapping()
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
	 * INFO: The "Rasperry pi" has not enough pins for the binary clock.
	 * 	     Thus the two following blocks are only to see that the logic works fine.
	 * 	     With the blocks we see the seconds moving.
	 * TODO: Buy a bit-shift-register or port expander or export the code to a
	 * 		 Arduino ( possible that give some errors with external libraries like boost )
	 */

	boost::shared_ptr<Pin> lPin0_0(new Pin("lPin0_0", 14, true)); // the third parameter says its a output signal
	boost::shared_ptr<Pin> lPin1_0(new Pin("lPin1_0", 15, true));
	boost::shared_ptr<Pin> lPin2_0(new Pin("lPin2_0", 18, true));
	boost::shared_ptr<Pin> lPin3_0(new Pin("lPin3_0", 23, true));
	lTempPins.push_back(lPin0_0);
	lTempPins.push_back(lPin1_0);
	lTempPins.push_back(lPin2_0);
	lTempPins.push_back(lPin3_0);
	lPins.push_back(lTempPins);

	boost::shared_ptr<Pin> lPin0_1 (new Pin("lPin0_1", 11, true));
	boost::shared_ptr<Pin> lPin1_1 (new Pin("lPin1_1", 9, true));
	boost::shared_ptr<Pin> lPin2_1 (new Pin("lPin2_1", 10, true));
	boost::shared_ptr<Pin> lPin3_1 (new Pin("lPin3_1", 22, true));
	lTempPins.clear();
	lTempPins.push_back(lPin0_1);
	lTempPins.push_back(lPin1_1);
	lTempPins.push_back(lPin2_1);
	lTempPins.push_back(lPin3_1);
	lPins.push_back(lTempPins);

	boost::shared_ptr<Pin> lPin0_2 (new Pin("lPin0_2", Pin::C_UNDEFINED, true));
	boost::shared_ptr<Pin> lPin1_2 (new Pin("lPin1_2", Pin::C_UNDEFINED, true));
	boost::shared_ptr<Pin> lPin2_2 (new Pin("lPin2_2", Pin::C_UNDEFINED, true));
	boost::shared_ptr<Pin> lPin3_2 (new Pin("lPin3_2", Pin::C_UNDEFINED, true));
	lTempPins.clear();
	lTempPins.push_back(lPin0_2);
	lTempPins.push_back(lPin1_2);
	lTempPins.push_back(lPin2_2);
	lTempPins.push_back(lPin3_2);
	lPins.push_back(lTempPins);

	boost::shared_ptr<Pin> lPin0_3 (new Pin("lPin0_3", Pin::C_UNDEFINED, true));
	boost::shared_ptr<Pin> lPin1_3 (new Pin("lPin1_3", Pin::C_UNDEFINED, true));
	boost::shared_ptr<Pin> lPin2_3 (new Pin("lPin2_3", Pin::C_UNDEFINED, true));
	boost::shared_ptr<Pin> lPin3_3 (new Pin("lPin3_3", Pin::C_UNDEFINED, true));
	lTempPins.clear();
	lTempPins.push_back(lPin0_3);
	lTempPins.push_back(lPin1_3);
	lTempPins.push_back(lPin2_3);
	lTempPins.push_back(lPin3_3);
	lPins.push_back(lTempPins);

	boost::shared_ptr<Pin> lPin0_4 (new Pin("lPin0_4", Pin::C_UNDEFINED, true));
	boost::shared_ptr<Pin> lPin1_4 (new Pin("lPin1_4", Pin::C_UNDEFINED, true));
	boost::shared_ptr<Pin> lPin2_4 (new Pin("lPin2_4", Pin::C_UNDEFINED, true));
	boost::shared_ptr<Pin> lPin3_4 (new Pin("lPin3_4", Pin::C_UNDEFINED, true));
	lTempPins.clear();
	lTempPins.push_back(lPin0_4);
	lTempPins.push_back(lPin1_4);
	lTempPins.push_back(lPin2_4);
	lTempPins.push_back(lPin3_4);
	lPins.push_back(lTempPins);

	boost::shared_ptr<Pin> lPin0_5 (new Pin("lPin0_5", Pin::C_UNDEFINED, true));
	boost::shared_ptr<Pin> lPin1_5 (new Pin("lPin1_5", Pin::C_UNDEFINED, true));
	boost::shared_ptr<Pin> lPin2_5 (new Pin("lPin2_5", Pin::C_UNDEFINED, true));
	boost::shared_ptr<Pin> lPin3_5 (new Pin("lPin3_5", Pin::C_UNDEFINED, true));
	lTempPins.clear();
	lTempPins.push_back(lPin0_5);
	lTempPins.push_back(lPin1_5);
	lTempPins.push_back(lPin2_5);
	lTempPins.push_back(lPin3_5);
	lPins.push_back(lTempPins);

	this->lPins = lPins;
}
