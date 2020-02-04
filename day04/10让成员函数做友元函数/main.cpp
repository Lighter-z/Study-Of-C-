#include <iostream>
#include <string>

using namespace std;

//只让visit做 友元函数  不让 visit2 做友元函数
class Building {
	//类做友元类
	friend void googGay::visit();
public:
	Building() {
		this->BedRoom = "卧室";
		this->SittingRoom = "客厅";
	}
	string SittingRoom;

private:
	string BedRoom;
};

class googGay {
public:
	googGay();
	void visit();
	void visit2();
private:
	Building * building;

};

googGay::googGay()
{
	building = new Building;
}

void googGay::visit()
{
	cout << "好基友正在访问" << this->building->SittingRoom << endl;
	cout << "好基友正在访问" << this->building->BedRoom << endl;
}

void googGay::visit2()
{
	cout << "好基友正在访问" << this->building->SittingRoom << endl;
	//cout << "好基友正在访问" << this->building->BedRoom << endl;
}



void test01() {
	googGay gg;
	gg.visit();
}

int main() {
	test01();
	return 0;
}


