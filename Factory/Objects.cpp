#ifndef __io__
#define __io__

#include <iostream>
using namespace std;

#endif
#include <string>

class Toy{
	protected:
		string name;
		float price;
	public:
		virtual void prepairParts() = 0;
		virtual void combineParts() = 0;
		virtual void asembleParts() = 0;
		virtual void applyLable() = 0;		
		virtual void showProduct() = 0;		
};

class Car : public Toy{
	// make all constructor private or protected
	public:
		void prepairParts() { cout << "Prepairing  Car Parts" << endl;}
		void combineParts() { cout << "Combining Car Parts" << endl;}
		void asembleParts() { cout << "Assembeling Car Parts" << endl;}
		void applyLable() 	{ cout << "Applying Car Lable" << endl; name = "Car"; price = 10;}		
		void showProduct() 	{ cout << "Name: " << name << " Price: " << price << endl; }		
};

class Bike : public Toy{
	// make all constructor private or protected
	public:
		void prepairParts() { cout << "Prepairing  Bike Parts" << endl;}
		void combineParts() { cout << "Combining Bike Parts" << endl;}
		void asembleParts() { cout << "Assembeling Bike Parts" << endl;}
		void applyLable() 	{ cout << "Applying Bike Lable" << endl; name = "Plane"; price = 20;}		
		void showProduct() 	{ cout << "Name: " << name << " Price: " << price << endl; }		
};

class Plane : public Toy{
	// make all constructor private or protected
	public:
		void prepairParts() { cout << "Prepairing  Plane Parts" << endl;}
		void combineParts() { cout << "Combining Plane Parts" << endl;}
		void asembleParts() { cout << "Assembeling Plane Parts" << endl;}
		void applyLable() 	{ cout << "Applying Plane Lable" << endl; name = "Plane"; price = 30;}		
		void showProduct() 	{ cout << "Name: " << name << " Price: " << price << endl; }		
};