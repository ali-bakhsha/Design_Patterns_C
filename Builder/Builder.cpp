#include <iostream>
#include <string>
using namespace std;

// use builder design pattern to make a Car with complex objects like engine body , .. step by step
class Car{
	string _Car;
	string _body;
	string _engine;
public:
	Car(string CarType):_Car(CarType){}
	
	//setters
	void setEngine(string type){_engine = type;}
	void setBody(string body) {_body = body;}
	
	//getters
	string getEngine(){return _engine;}
	string getBody(){return _body;}
	
	void show(){
		cout << "Car Type: "  << _Car << endl;
		cout << "Engine Type: " << _engine  << endl;
		cout << "Body Type: "   << _body << endl<<endl;
	}
};
// abstract class for builder
class CarBuilder{
protected:
	Car* _Car;
public:
	virtual void getPartsDone() = 0;
	virtual void buildEngine() = 0;
	virtual void buildBody() = 0;
	
	Car* getCar(){return _Car;}
};
class BenzBuilder: public CarBuilder{
	public:
		void getPartsDone(){_Car = new Car("Jet Car");}
		void buildEngine(){_Car->setEngine("Jet Engine");}
		void buildBody(){_Car->setBody("Jet Body");}
};

class ToyotaBuilder: public CarBuilder{
	public:
		void getPartsDone(){_Car = new Car("Pro Car");}
		void buildEngine(){_Car->setEngine("Pro Engine");}
		void buildBody(){_Car->setBody("Pro Body");}
};

class Director{
	public:
		Car* createCar(CarBuilder *builder){
			builder->getPartsDone();
			builder->buildEngine();
			builder->buildBody();
			return builder->getCar();
		}
	
};
int main(){
	Director dir;
	BenzBuilder bb;
	ToyotaBuilder tb;
	
	Car *benz = dir.createCar(&bb);
	Car *toyota = dir.createCar(&tb);
	
	benz->show();
	toyota->show();
	
	delete benz;
	delete toyota;
}