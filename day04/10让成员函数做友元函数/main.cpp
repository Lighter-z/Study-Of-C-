#include <iostream>
#include <string>

using namespace std;

//ֻ��visit�� ��Ԫ����  ���� visit2 ����Ԫ����
class Building {
	//������Ԫ��
	friend void googGay::visit();
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
	cout << "�û������ڷ���" << this->building->SittingRoom << endl;
	cout << "�û������ڷ���" << this->building->BedRoom << endl;
}

void googGay::visit2()
{
	cout << "�û������ڷ���" << this->building->SittingRoom << endl;
	//cout << "�û������ڷ���" << this->building->BedRoom << endl;
}



void test01() {
	googGay gg;
	gg.visit();
}

int main() {
	test01();
	return 0;
}


