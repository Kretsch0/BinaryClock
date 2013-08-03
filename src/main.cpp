#include <boost/shared_ptr.hpp>
#include <unistd.h>

#include "control.h"
#include "Initializer.h"

int main()
{
	boost::shared_ptr<Initializer> lInit(new Initializer());
	boost::shared_ptr<Control> lControl(new Control(lInit->getPins()));


	//Very simple loop. ( update time = 1 Second)
	while (1)
	{
		lControl->run();
		sleep(1);
	}
	return 0;
}
