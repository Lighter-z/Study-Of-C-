#include <iostream>
#include <fstream>
using namespace std;

//д�ļ�
void writeFile(void) {
	//������ķ�ʽ���ļ�
	//��ʽһ
	//ofstream ofs("./test.txt", ios::out | ios::trunc);

	//��ʽ��
	ofstream ofs;
	ofs.open("./test.txt", ios::out | ios::trunc);
	if (!ofs.is_open()) {
		cout << "�ļ���ʧ��" << endl;
	}
	ofs << "354565" << endl;
}

//���ļ�
void readFile(void) {
	ifstream ifs;
	ifs.open("./test.txt", ios::in);

	if (!ifs.is_open()) {
		cout << "�ļ���ʧ��" << endl;
	}

	//��ȡ
	//��ʽһ
	char buf[1024];
	while (ifs >> buf) {  //���ж�ȡ
		cout << buf << endl;
	}

	//��ʽ��
	//char buf[1024];
	//while (!ifs.eof()) {  //ifs.eof()�Ƿ�����ļ�β
	//	ifs.getline(buf, strlen(buf));
	//	cout << buf << endl;
	//}

	////��ʽ��  
	////�������ַ���ȡ  ���Ƽ�
	//char c;
	//while ((c = ifs.get()) != EOF) {  //EOF�ļ�β
	//	cout << c;
	//}

}

void test01(void) {
	writeFile();
	readFile();
}

int main(void) {
	test01();
	return 0;
}
