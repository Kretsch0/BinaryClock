#include "control.h"
Control::Control(const std::vector<std::vector<boost::shared_ptr<Pin> > >& lPins):
mPins(lPins){}

Control::~Control() {}


/*
 * Converts the actual time to a binary.
 * Example: 20 (DEC) -> 10100 (BIN)
 */
std::vector< std::vector<int> > Control::timeToBin(){
	std::vector<int> lTemp;
	boost::shared_ptr<Time> lTime(new Time());

	lTemp.push_back(lTime->getSec() % 10); // last digit
	lTemp.push_back(lTime->getSec() / 10); // first digit

	lTemp.push_back(lTime->getMin() % 10); // last digit
	lTemp.push_back(lTime->getMin() / 10); // first digit

	lTemp.push_back(lTime->getHour() % 10); // last digit
	lTemp.push_back(lTime->getHour() / 10); // first digit

	//second parameter is the invert parameter ( 20 is NOT 10100 but 00101)
	std::vector< std::vector<int> > lBinValues = ConvertToBin::convertValues(lTemp, true);
	return lBinValues;
}

/*
 * This method will be triggered every loop.
 */
void Control::run()
{
	unsigned int outer, inner = 0;

	//writes each value to each pin
	try{
		for(outer = 0; outer < mPins.size(); outer++)
		{
			for(inner = 0; inner < mPins.at(outer).size(); inner++)
			{
				std::cout << "pin : " <<
						mPins.at(outer).at(inner)->getName() << " || " << outer << " - " << inner <<" = " << timeToBin().at(outer).at(inner);

				if(mPins.at(outer).at(inner)->isIsValid())
				{
					mPins.at(outer).at(inner)->writeValue(timeToBin().at(outer).at(inner)); // write the value to the pin
					std::cout << " done " <<std::endl;
				}
				else
				{
					std::cout << "\n";
				}
			}
		}
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}


