#include <iostream>

using namespace std;

class ChairMan {
	//1.���캯��˽�л�
private:
	ChairMan() {
		cout << "����ChairMan Ĭ�Ϲ��캯��" << endl;
	}
	ChairMan(const ChairMan &cm) {
		
	}
//public:
	static ChairMan *singleMan;
public:
	//�ṩget�������� ��ϯ
	static ChairMan *getInstance() {
		return singleMan;
	}
};

ChairMan *ChairMan::singleMan = new ChairMan;

void test0() {
	//ChairMan::singleMan;        //static ChairMan *singleMan;  Ϊpublicʱ��
	//ChairMan::singleMan = NULL;    //��static ChairMan *singleManΪpublicʱ��  �����˶����������
	//Ϊ�˱������������ʹ����Ϊ˽�У�ͨget��������
	ChairMan *cm1 = ChairMan::getInstance();
	ChairMan *cm2 = ChairMan::getInstance();
	if (cm1 == cm2) {
		cout << "��ͬ" << endl;  //static ��̬����  ��������
	}

	//ChairMan *cm3 = new ChairMan(*cm2);   //�������� �� public ʱ��
	//if (cm1 == cm3) {
	//	cout << "��ͬ" << endl;
	//}
	//else {
	//	cout << "����ͬ" << endl;  //Ϊ�˱��ⲻ��ͬ�����  ��Ҫ��  ��������  ����˽�л�
	//}

}

int main() {
	cout << "main����" << endl;  //����ChairMan Ĭ�Ϲ��캯��  ������  main����
	test0();
	return 0;
}
