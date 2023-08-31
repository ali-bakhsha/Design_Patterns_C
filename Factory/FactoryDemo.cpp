#include <iostream>
#include <string>

using namespace std;
#include "ToyFactory.cpp"
int main()
{
	cout << "Factroy design pattern" << endl;
	int type = 0;
	
	while(1){
		
		cout << "Enter type or zero to exit: " << endl;
		cin >> type;
		
		if(type == 0){ // exit the loop and program
			break;
		}
		
		Toy* v = ToyFactory::createToy(type);
		
		if(v){
			v->showProduct();
			delete v;
		}
	}
	cout << "Exit..." << endl;
		
	
	return 0;
}
	