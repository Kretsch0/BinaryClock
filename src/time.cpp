#include "time.h"
#include <iostream>
Time::Time():
lTime(time(0)),
lTimeStruct(localtime(&lTime)),
lSec(lTimeStruct->tm_sec),
lMin(lTimeStruct->tm_min),
lHour(lTimeStruct->tm_hour){}

Time::~Time() {}

