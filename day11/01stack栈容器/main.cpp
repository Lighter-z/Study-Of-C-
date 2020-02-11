#include <iostream>
#include <stack>
using namespace std;
/*
ջ �Ƚ����  ���ܱ��� û�е�����
stack���캯��
stack<T> s;  //stack������ģ��  Ĭ�Ϲ���
stack(const stack & stk);  //�������캯��

��ֵ����
stack& operator=(const stack & stk);  //���صȺŲ�����

���ݴ�ȡ����
push(elem);  //��ջ���������
pop();  //ɾ��ջ������
top();  //����ջ������

stack��С����
empty();  //�ж�ջ�Ƿ�Ϊ��
size();  //����ջ�Ĵ�С
*/

void test01(void) {
	stack<int> s1;
	s1.push(10);
	s1.push(20);
	s1.push(30);

	while (s1.empty() != true) {
		cout << "ջ��С��" << s1.size() << " " << "ջ�����ݣ�" << s1.top() << endl;
		s1.pop();
	}
	cout << "ջ��С��" << s1.size() << endl;
}

int main() {
	test01();
	return 0;
}
