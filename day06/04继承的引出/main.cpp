#include <iostream>
#include <string>


using namespace std;

//class News {
//public:
//	void header() {
//		cout << "����ͷ��" << endl;
//	}
//	void fooler() {
//		cout << "�����ײ�" << endl;
//	}
//	void left() {
//		cout << "����б�" << endl;
//	}
//	void content() {
//		cout << "����" << endl;
//	}
//};
//
//class Entertainment {
//public:
//	void header() {
//		cout << "����ͷ��" << endl;
//	}
//	void fooler() {
//		cout << "�����ײ�" << endl;
//	}
//	void left() {
//		cout << "����б�" << endl;
//	}
//	void content() {
//		cout << "����" << endl;
//	}
//};



//�̳�д��
//����һ������  �ظ��Ĵ��붼��д���������
class BasePage {
public:
	void header() {
		cout << "����ͷ��" << endl;
	}
	void fooler() {
		cout << "�����ײ�" << endl;
	}
	void left() {
		cout << "����б�" << endl;
	}
};

class News : public BasePage {
public:
	void content() {
		cout << "����" << endl;
	}

};

class Entertainment : public BasePage {
public:
	void content() {
		cout << "����" << endl;
	}
};

//BasePage ����(����)    Entertainment������(����)

void test01(void) {
	//News news;
	//news.header();
	//news.fooler();
	//news.left();
	//news.content();

	//Entertainment E;
	//E.header();
	//E.fooler();
	//E.left();
	//E.content();


	News news;
	news.content();
	news.header();
	news.fooler();
	news.left();
	
}

int main(void) {
	test01();
	return 0;
}
