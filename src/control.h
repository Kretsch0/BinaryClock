#ifndef CONTROL_H_
#define CONTROL_H_
#include <vector>
#include "boost/shared_ptr.hpp"
#include "initializer.h"

class Control {
public:
	explicit Control(const std::vector<std::vector<boost::shared_ptr<Pin> > >& lPins);
	virtual ~Control();

	/*
	 * This method will be triggered every loop.
	 */
	void run();

private:
	/*
	 * Converts the actual time to a binary.
	 * Example: 20 (DEC) -> 10100 (BIN)
	 */
	std::vector< std::vector<int> >timeToBin();

	const std::vector<std::vector<boost::shared_ptr<Pin> > >& mPins;
};

#endif /* CONTROL_H_ */
