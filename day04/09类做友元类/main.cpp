#include <iostream>
#include <string>

using namespace std;

class Building {
	//������Ԫ��
	friend class googGay;
public:
	Building() {
		this->BedRoom = "����";
		this->SittingRoom = "����";
	}
	string SittingRoom;

private:
	string BedRoom;
};

class googGay {
public:
	googGay();
	void visit();
private:
	Building * building;

};

googGay::googGay()
{
	building = new Building;
}

void googGay::visit()
{
	cout << "�û������ڷ���" << this->building->SittingRoom << endl;
	cout << "�û������ڷ���" << this->building->BedRoom << endl;
}



void test01() {
	googGay gg;
	gg.visit();
}

int main() {
	test01();
	return 0;
}


