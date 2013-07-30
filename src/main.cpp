#include <boost/shared_ptr.hpp>
#include <unistd.h>

#include "control.h"
#include "initilizer.h"

int main()
{
	boost::shared_ptr<Initilizer> lInit(new Initilizer());
	boost::shared_ptr<Control> lControl(new Control(lInit->getPins()));


	//Very simple loop. ( update time = 1 Second)
	while (1)
	{
		lControl->run();
		sleep(1);
	}
	return 0;
}
