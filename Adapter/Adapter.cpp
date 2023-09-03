#include <iostream>
#include <memory>
using namespace std;

class USASocket{
	public:
		void useacharge(){
			cout << "USA plug is charging" << endl;
		}
};
class AsianSocket{
	public:
		void asiancharge(){
			cout << "Germany plug is charging" << endl;
		}
};


class EuropeSocket{
	public:
		virtual void europecharge(int type) = 0;
};

class SocketAdapter : public EuropeSocket , public USASocket , public AsianSocket{
	public:
		void europecharge(int type){
			switch(type){
				case 1:
					useacharge();
					break;
				case 2:
					asiancharge();
					break;
				default:
					break;
			}

		}
};

int main(){
	unique_ptr<EuropeSocket> socket = make_unique<SocketAdapter>();
	socket->europecharge(2);
	return 0;
}