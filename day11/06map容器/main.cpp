#include <iostream>
#include <string>
#include <map>
using namespace std;

/*
map��ֵ����
map & operator=(const map & mp);  //���صȺ������
swap(mp);  //������������

map��С����
size();  //����������Ԫ�صĸ���
empty();  //�ж������Ƿ�Ϊ��

map��������
map.insert(elem);  //�������в���Ԫ��  ����ֵ��pair<iterator, iterator>

//���ӣ�
map<int, int> map;
map.insert(pair<int, int>(1, 5));
map.insert(make_pair(2,2));
map.insert(map<int, int>::value_type(3, 3));
map[4] = 4;

mapɾ������
clear();  //�������
erase(pos);  //ɾ��pos��������ָ��Ԫ�أ�������һ��Ԫ�صĵ�����
erase(beg, end);  //ɾ������[beg, end]�е�Ԫ�أ�������һ��Ԫ�صĵ�����
erase(keyElem);  //ɾ��������key = keyElm�Ķ���

map���Ҳ���
find(key);  //���Ҽ�key�Ƿ���ڣ������ڣ����ظü���Ԫ�صĵ��������������ڣ�����map.end()
count(keyElm);  //����������keyΪkeyElem�Ķ����������map��˵��Ҫô��0 Ҫô��1   ��multimap��˵ ֵ���ܴ���1
lower_bound(keyElm);  //���ص�һ��Key>=keyElmԪ�صĵ�����
upper_bound(keyElm);  //���ص�һ��Key>keyElmԪ�صĵ�����
equal_range(keyElm);  //����������key��keyElm��ȵ������޵�����������
//
*/

void printMap(map<int, int> & m) {
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
		cout << "Key = " << it->first << "  Value = " << it->second << endl;
	}
}

void findMap(map<int, int> & m, int key) {
	map<int, int>::iterator pos = m.find(key);
	if (pos != m.end()) {
		cout << "find  key = " << pos->first << "  value = " << pos->second << endl;
	}
	else {
		cout << "not find!" << endl;
	}
}

void test01(void) {
	//�Զ�����keyֵ��С��������
	map<int, int> m1;
	m1.insert(pair<int, int>(1, 10));
	m1.insert(make_pair(2, 20));
	m1.insert(map<int, int>::value_type(3, 30));
	m1[4] = 0;
	printMap(m1);

	cout << "m1 size = " << m1.size() << endl;
	
	findMap(m1, 1);

	map<int, int>::iterator ret = m1.lower_bound(3);
	if (ret != m1.end()) {
		cout << "lower_bound  find   key = " << ret->first << "  value = " << ret->second << endl;
	}
	else {
		cout << "not find" << endl;
	}

	map<int, int>::iterator ret1 = m1.upper_bound(3);
	if (ret1 != m1.end()) {
		cout << "upper_bound  find   key = " << ret1->first << "  value = " << ret1->second << endl;
	}
	else {
		cout << "not find" << endl;
	}

	pair<map<int, int>::iterator, map<int, int>::iterator> ret2 = m1.equal_range(3);
	if (ret2.first != m1.end()) {
		cout << "equal_rang  find first  key = " << ret2.first->first << "  value = " << ret2.first->second << endl;
	}
	else {
		cout << "equal_rang not find" << endl;
	}

	if (ret2.second != m1.end()) {
		cout << "equal_rang  find  second  key = " << ret2.second->first << "  value = " << ret2.second->second << endl;
	}
	else {
		cout << "equal_rang not find" << endl;
	}
}

//����
//�Ӵ�С����
class myCompareMap {
public:
	bool operator()(int v1, int v2) const {
		return v1 > v2;
	}
};

void printMapMyCompare(map<int, int, myCompareMap> & m) {
	for (map<int, int, myCompareMap>::iterator it = m.begin(); it != m.end(); it++) {
		cout << "Key = " << it->first << "  Value = " << it->second << endl;
	}
}

void test02() {
	map<int, int, myCompareMap> m1;
	m1.insert(pair<int, int>(1, 10));
	m1.insert(make_pair(2, 20));
	m1[3] = 30;
	printMapMyCompare(m1);
}

int main() {
	//test01();
	test02();
	return 0;
}
