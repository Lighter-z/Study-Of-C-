#include <iostream>
#include <queue>
using namespace std;
/*
���� �Ƚ��ȳ�  ���ܱ��� û�е�����
queue���캯��
queue<T> queT;  //������ģ��ʵ��  Ĭ�Ϲ��캯��
queue(const queue & que);  //�������캯��


��ȡ ���� ɾ������
push(elem);  //�ڶ�β�������elem
pop();  //ɾ����ͷ��һ��Ԫ��
back();  //�������һ��Ԫ��
front();  //���ص�һ��Ԫ��

��ֵ����
queue & operator=(const queue & que);  //���صȺ������

��С����
empty();  //�ж��Ƿ�Ϊ��
size();  //���ض��д�С
*/

void test01(void) {
	queue<int> q1;
	q1.push(10);
	q1.push(20);
	q1.push(30);
	q1.push(40);

	cout << "��βԪ�أ�" << q1.back() << endl;

	while (!q1.empty()) {
		cout << "���д�С��" << q1.size() << "  ��ͷԪ�أ�" << q1.front() << "��βԪ�أ�" << q1.back() << endl;
		q1.pop();
	}
}

int main() {
	test01();
	return 0;
}
