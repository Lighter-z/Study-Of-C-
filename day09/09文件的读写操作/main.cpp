#include <iostream>
#include <fstream>
using namespace std;

//写文件
void writeFile(void) {
	//以输出的方式打开文件
	//方式一
	//ofstream ofs("./test.txt", ios::out | ios::trunc);

	//方式二
	ofstream ofs;
	ofs.open("./test.txt", ios::out | ios::trunc);
	if (!ofs.is_open()) {
		cout << "文件打开失败" << endl;
	}
	ofs << "354565" << endl;
}

//读文件
void readFile(void) {
	ifstream ifs;
	ifs.open("./test.txt", ios::in);

	if (!ifs.is_open()) {
		cout << "文件打开失败" << endl;
	}

	//读取
	//方式一
	char buf[1024];
	while (ifs >> buf) {  //按行读取
		cout << buf << endl;
	}

	//方式二
	//char buf[1024];
	//while (!ifs.eof()) {  //ifs.eof()是否读到文件尾
	//	ifs.getline(buf, strlen(buf));
	//	cout << buf << endl;
	//}

	////方式三  
	////按单个字符读取  不推荐
	//char c;
	//while ((c = ifs.get()) != EOF) {  //EOF文件尾
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
