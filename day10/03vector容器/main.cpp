#include <iostream>
//֧��������� ��Ծʽ
#include <vector>
//��֧����Ծʽ����
#include <list>

using namespace std;
/*
vector<T> v; //����ģ��ʵ����ʵ�� Ĭ�Ϲ��캯��
vector(v.begin(), v.end());  //��v[v.begin(), v.end()]�����е�Ԫ�ؿ���������
vector(n, elm);  //���캯�� ��n��elm����������
vector(const vector & vec);  //�������캯��

���ӣ�
int arr[] = {1, 1, 2 ,3};
���ø�ֵ����
vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));  //��һ��Ԫ��   ���һ��Ԫ�ص���һ��λ��

���ø�ֵ����
assign(beg, end);  //��[beg, end]�����е����ݿ���������
assign(n, elm);  //��n��elm����������
vector& operator = (const vector & vec);  //���صȺŲ�����
swap(vec);  //��vec�뱾���Ԫ�ؽ��л���

��С����
sizeof();  //����������Ԫ�ظ���
empty();  //�ж������Ƿ�Ϊ��
resize(int num);  //����ָ����������Ϊnum  �������䳤����Ĭ��ֵ�����λ�ã���������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ��
resize(int num, elm);  //����ָ����������Ϊnum��  �������䳤����ʹ��elm�����λ�ã���������̣���ɾ�������������ȵ�Ԫ��
capacity();  //��������
reserve(int len);  //����Ԥ��len��Ԫ�س��ȣ�Ԥ��λ�ò���ʼ����Ԫ�ز��ɷ���
*/

void test01(void) {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
		cout << v.capacity() << endl;  //v.capacity()����������
	}

}

void printVector(vector<int> &v) {
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it;
	}
	cout << endl;
}
void test02() {
	vector<int> v1;
	int arr[] = { 10, 20, 30, 40 };

	vector<int> v2(arr, arr + sizeof(arr) / sizeof(arr[0]));//��һ��Ԫ��  ���һ��Ԫ�ص���һ��λ��
	vector<int> v3(v2.begin(), v2.end());
	printVector(v2);
	printVector(v3);

	vector<int> v4(5, 40);
	printVector(v4);

	vector<int> v5(v4);
	printVector(v5);

	v5.assign(v2.begin(), v2.end());
	printVector(v5);
	v4.assign(5, 10);
	printVector(v4);

	v3 = v4;
	printVector(v3);
	v2.swap(v3);
	printVector(v2);

	cout << v2.size() << endl;
	vector<int> v6;
	cout << v6.empty() << endl;  //�շ���1
	cout << v6.size() << endl;  //0
	cout << "������" << v6.capacity() << endl;

	v6.resize(10);
	cout << v6.size() << endl;  //10
	cout << "������" << v6.capacity() << endl;
	v6.resize(20, 1);
	printVector(v6);
	
	v6.resize(15, 2);
	printVector(v6);
}

//����swap�����ռ�
void test03(void) {
	vector<int> v1;
	for (int i = 0; i < 10000; i++) {
		v1.push_back(i);
	}
	cout << "v1��������" << v1.capacity() << endl;  //12138
	cout << "v1�Ĵ�С��" << v1.size() << endl;  //10000

	v1.resize(3);
	cout << "v1��������" << v1.capacity() << endl;  //12138
	cout << "v1�Ĵ�С��" << v1.size() << endl;  //3 
	//��С��С��  ����û�б�  �������Դ�˷�

	//����swap
	vector<int>(v1).swap(v1);
	cout << "v1��������" << v1.capacity() << endl;  //3
	cout << "v1�Ĵ�С��" << v1.size() << endl;  //3 
	/*
	���ͣ�vector<int>(v1).swap(v1);
		vector<int> (v1)//��ʼ����������
		.swap()  //v1���������󽻻�ָ��ָ��ĵ�ַ   ��������ָ��v1�ĵ�ַ   v1ָ����������ĵ�ַ
		���д�������� ��������ͻᱻ����  ֮ǰ��12138�Ŀռ�Ҳ�ͱ�������
	*/

}

/*
vextor���ݴ洢����
at(int index);  //��������index��ָ�������  ���Խ�磬�׳�out_of_rang�쳣
operator[];  //����index��ָ�������  Խ��ֱ�ӱ���
front();  //���������е�һ������
back();  //�������������һ������

�����ɾ������
insert(const_iterator pos, int count, ele);  //������ָ��λ��pos����count��Ԫ��ele
push_back(ele);  //β������Ԫ��ele
pop_back();  //ɾ��β�����һ��Ԫ��
erase(const_iterator start, const_iterator end);  //ɾ�������� start �� end֮���Ԫ��
erase(const_iterator pos);  //ɾ��������ָ���Ԫ��
clear();//ɾ������������Ԫ��
*/

void test04(void) {
	vector<int> v1;
	v1 = { 1,2,3 };
	
	cout << v1[2] << endl;
	cout << v1.front() << endl;
	cout << v1.back() << endl;

	v1.push_back(10);
	cout << v1.back() << endl;

	v1.insert(v1.begin(),100);
	cout << v1.front() << endl;
	printVector(v1);

	v1.insert(v1.begin(), 2, 100);
	printVector(v1);

	v1.pop_back();
	cout << v1.back() << endl;

	v1.erase(v1.begin());

	v1.erase(v1.begin(), v1.end());

	v1.clear();
}

//�������
//reverse_iterator  ���������
void test05(void) {
	vector<int> v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
	}
	//�������
	printVector(v1);

	//�������
	//reverse_iterator  ���������
	for (vector<int>::reverse_iterator rit = v1.rbegin(); rit != v1.rend(); rit++) {
		cout << *rit;
	}
	cout << endl;

	//vector�����������������  ֧����Ծʽ����
	vector<int>::iterator itBegin = v1.begin();
	itBegin += 3;
	//�������д�������� �������������������ʵ�����

	//list�������������
	list<int> l;
	for (int i = 0; i < 10; i++) {
		l.push_back(i);
	}
	list<int>::iterator LitBegin = l.begin();
	//l += 3;
	//����  list���Բ������������
}

int main() {
	//test01();
	//test02();
	//test03();
	//test04();
	test05();
	return 0;
}
