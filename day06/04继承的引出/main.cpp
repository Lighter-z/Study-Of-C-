#include <iostream>
#include <string>


using namespace std;

//class News {
//public:
//	void header() {
//		cout << "公共头部" << endl;
//	}
//	void fooler() {
//		cout << "公共底部" << endl;
//	}
//	void left() {
//		cout << "左侧列表" << endl;
//	}
//	void content() {
//		cout << "新闻" << endl;
//	}
//};
//
//class Entertainment {
//public:
//	void header() {
//		cout << "公共头部" << endl;
//	}
//	void fooler() {
//		cout << "公共底部" << endl;
//	}
//	void left() {
//		cout << "左侧列表" << endl;
//	}
//	void content() {
//		cout << "娱乐" << endl;
//	}
//};



//继承写法
//抽象一个基类  重复的代码都会写在这个类上
class BasePage {
public:
	void header() {
		cout << "公共头部" << endl;
	}
	void fooler() {
		cout << "公共底部" << endl;
	}
	void left() {
		cout << "左侧列表" << endl;
	}
};

class News : public BasePage {
public:
	void content() {
		cout << "新闻" << endl;
	}

};

class Entertainment : public BasePage {
public:
	void content() {
		cout << "娱乐" << endl;
	}
};

//BasePage 基类(父类)    Entertainment派生类(子类)

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
