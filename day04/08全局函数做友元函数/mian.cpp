#include <iostream>
#include <string>

using namespace std;

class Building {
	//��Ԫ����
	friend void goodGay(Building * building);
public:
	Building() {
		this->BedRoom = "����";
		this->SittingRoom = "����";
	}
	string SittingRoom;

private:
	string BedRoom;

};

void goodGay(Building * building) {
	cout << building->SittingRoom << endl;
	cout << building->BedRoom << endl;
}

void test01() {
	Building *b = new Building;
	goodGay(b);
}


int main() {
	test01();
	return 0;
}
