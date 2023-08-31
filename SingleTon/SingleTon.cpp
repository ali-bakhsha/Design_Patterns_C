#include <iostream>
#include <string>

using namespace std;

class ApplicationSetting{

	static ApplicationSetting* _instance;
	
	int _parameterSetting1;
	int _parameterSetting2;
	
	ApplicationSetting(): _parameterSetting1(100), _parameterSetting2(200){}; // default constructor
	ApplicationSetting(const ApplicationSetting& other): _parameterSetting1(other._parameterSetting1) , _parameterSetting2(other._parameterSetting2){}; // copy constructor
	
	ApplicationSetting operator=(const ApplicationSetting& other){
		_parameterSetting1 = other._parameterSetting1;
		_parameterSetting2 = other._parameterSetting2;
	}
	
	
	
	public:
		static ApplicationSetting* getInstance(){
			if(_instance == NULL){
				_instance = new ApplicationSetting();
			}
			return _instance;
		}
		
		// setters
		void setParameterSetting1(int param){
			_parameterSetting1 = param;
		}
		void setParameterSetting2(int param){
			_parameterSetting2 = param;
		}
		
		//getters
		int getParameterSetting1(){
			return _parameterSetting1;
		}
		int getParameterSetting2(){
			return _parameterSetting2;
		}
		
		void displaySetting(){
			cout << "Setting1: " << _parameterSetting1 << ", Setting2: " << _parameterSetting2 << endl; 
		}
};

ApplicationSetting* ApplicationSetting::_instance;
int main(){
	ApplicationSetting *setting1 = ApplicationSetting::getInstance();
	setting1->displaySetting();
	
	setting1->setParameterSetting1(1000);
	setting1->setParameterSetting2(2000);
	
	ApplicationSetting *setting2 = ApplicationSetting::getInstance();
	setting2->displaySetting();
	setting1->setParameterSetting1(10000);
	setting2->setParameterSetting2(20000);
	
	
	ApplicationSetting *setting3 = ApplicationSetting::getInstance();
	setting3->displaySetting();
	
	return 0;
}