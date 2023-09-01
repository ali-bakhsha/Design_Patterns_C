#ifndef __io__
#define __io__

#include <iostream>
using namespace std;

#endif

#define SIMPLE_CAR 1
//#define LUXURY_CAR 1

#include "CarFactory.cpp"

int main()
{
	#ifdef SIMPLE_CAR
		CarFactory* factory = new SimpleCarFactory;
	#elif LUXURY_CAR
		CarFactory* factory = new LuxuryCarFactory;
	#endif
	
	Car* car = factory->buildWholeCar();
	car->printDetails();
	
	return 0;
}