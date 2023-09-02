#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
//-1 0 1
class Car{
	int position;
    std::vector<class Observer*> observerList;
	
	public:
	
	int getPosition(){ return position;}
	void setPosition(int value){
		position = value;
		notify();
	}
	void notify();
	
	void attach(Observer* obs){
		observerList.push_back(obs);
	}
	void detach(Observer* obs){
		observerList.erase( std::remove(observerList.begin(), observerList.end() , obs) , observerList.end());
	}
};	
	


class Observer{
	Car* _car;
public:
	Observer(Car* car){
		_car = car;
		_car->attach(this);
	}
	virtual void update() = 0;
protected:
	Car* getCar(){ return _car;}
};
void Car::notify() {
    for(int i=0; i<observerList.size(); ++i){
        observerList[i]->update();
    }
}
class LeftObserver : public Observer{
public:
	LeftObserver(Car* car) : Observer(car){}
	void update(){
		int pos = getCar()->getPosition();
		if(pos < 0){
			cout << "Left Side" << endl;
		}
	}
};

class RightObserver : public Observer{
public:
	RightObserver(Car* car) : Observer(car){}
	void update(){
		int pos = getCar()->getPosition();
		if(pos > 0){
			cout << "Right Side" << endl;
		}
	}
};

class MiddleObserver : public Observer{
public:
	MiddleObserver(Car* car) : Observer(car){}
	void update(){
		int pos = getCar()->getPosition();
		if(pos = 0){
			cout << "Middle Side" << endl;
		}
	}
};

int main(){
	Car *car = new Car();
	LeftObserver lo(car);
	RightObserver ro(car);
	MiddleObserver mo(car);
	
	cout << "hit left right button to drive a car in your sity!! and pess Esc to clese" << endl;
	char pressedButton;
    bool breakLoop = false;
 
    while(breakLoop == false) {
        cin >> pressedButton;
 cout << pressedButton << endl;
        switch(pressedButton){
            case 108:{ // l -->  pressed for left side
                car->setPosition(-1);
                break;
            }
            case 99:{ // c --> pressed for center
                car->setPosition(0);
                break;
            }
            case 114:{ // r --> pressed for right side
                car->setPosition(1);
                break;
            }
            case 98:{ // b --> pressed for break
                breakLoop = true;
                break;
            }
            default : {
                cout << "please drive carfully!!" << endl;
                break;
            }
        }
    }
    cout << "Byee..." << endl;
	
	delete car;
	return 0;
}