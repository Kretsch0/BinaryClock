#ifndef TIME_H_
#define TIME_H_
#include <time.h>
class Time {
public:
	Time();
	virtual ~Time();

	/*
	 * Returns the hour
	 */
	int& getHour() const {
		return lHour;
	}

	/*
	 * Returns the minute
	 */
	int& getMin() const {
		return lMin;
	}

	/*
	 * Returns the second
	 */
	int& getSec() const {
		return lSec;
	}

private:

	time_t lTime;

	struct tm *lTimeStruct; //forward decl. of the time struct

	int &lSec;

	int &lMin;

	int &lHour;

};

#endif /* TIME_H_ */
