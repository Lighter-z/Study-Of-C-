#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <map>
using namespace std;

/*
��˾��Ƹ5��Ա������Ҫָ��Ա�����ĸ����Ź���
*/

enum {
RENLI,
YANFA,
MEISHU
};

class Worker {
public:
	string name_;
	int money_;
};

void creatWorker(vector<Worker> & v, int num) {
	string nameSpeed = "ABCDE";
	for (int i = 0; i < num; i++) {
		string name = "Ա��";
		name += nameSpeed[i];

		int money = rand() % 10000 + 10000;

		Worker w;
		w.name_ = name;
		w.money_ = money;
		v.push_back(w);
	}
}

void setGroup(vector<Worker> & v, multimap<int, Worker> & m) {
	for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++) {
		int id = rand() % 3;
		m.insert(make_pair(id, (*it)));
	}
}

void printWorker(multimap<int, Worker> & m) {
	for (multimap<int, Worker>::iterator it = m.begin(); it != m.end(); it++) {
		cout << "������" << it->second.name_ << "  ����" << it->second.money_ << endl;
	}
}

void showSingleGroup(multimap<int, Worker> & m, int key) {
	multimap<int, Worker>::iterator pos = m.find(key);
	int index = 0;
	int num = m.count(key);
	for (; pos != m.end(), index < num; pos++, index++) {
		cout << "���֣�" << pos->second.name_ << "  ���ʣ�" << pos->second.money_ << endl;
	}
	cout << "------------------------" << endl;
}

void showGroup(multimap<int, Worker> & m) {
	cout << "--------��������--------" << endl;
	showSingleGroup(m, RENLI);

	cout << "--------�з�����--------" << endl;
	showSingleGroup(m, YANFA);

	cout << "--------��������--------" << endl;
	showSingleGroup(m, MEISHU);
}

int main() {
	vector<Worker> v;

	creatWorker(v, 5);

	multimap<int, Worker> m;
	setGroup(v, m);

	//���� �鿴Ա���Ƿ��������
	//printWorker(m);

	showGroup(m);
}