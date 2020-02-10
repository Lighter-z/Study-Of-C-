#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

/*
string   ���캯��
string() ����һ���յ��ַ���  ���� string str;
string(const string & str)  ʹ��һ��string�����ʼ����һ��string����
string(congst char * s)  ʹ���ַ���s��ʼ��
string(int n, char c)  ʹ��n���ַ���ʼ��

������ֵ���� 
string& operator=(const char * s)  //char *�����ַ�����ֵ����ǰ�ַ���
string& operator=(const string &s)  //���ַ���s��ֵ����ǰ�ַ���
string& operator(char c)  //�ַ���ֵ����ǰ�ַ���
string& assign(const char * s)  //���ַ���s��ֵ����ǰ�ַ���
string& assign(const cahr *s,int n) //���ַ���sǰn���ַ���ֵ����ǰ�ַ���
string& assign(const string s)  //���ַ���s��ֵ����ǰ�ַ���
string& assign(int n, char c)  //��n���ַ�c��ֵ����ǰ�ַ���
string& assign(const string &s, int start, int n)  //��s��start��ʼn���ַ���ֵ���ַ���
*/

/*
string ��ȡ�ַ���
char& operator[](int n)  //ͨ��[] �ķ�����ȡ�ַ�
char& at(int n)  //ͨ��at������ȡ�ַ�
[]��at����
[]����Խ���ֱ�ӹҵ���at���׳��쳣
*/

void test01(void) {
	string str1;//Ĭ�Ϲ���
	string str2(str1);//��������
	string str3 = str1;//����������һ��д��
	string str4("sss");//ʹ���ַ�����ʼ��
	string str5 = "dddd";//ʹ���ַ�����ʼ��
	string str6(10, 'a');//ʹ��n���ַ���ʼ��

	cout << str4 << endl;
	cout << str5 << endl;
	cout << str6 << endl;

	//������ֵ
	cout << "------������ֵ------" << endl;
	str1 = "wer";
	str2 = str4;
	cout << str1 << endl;
	cout << str2 << endl;

	str3.assign("hello,world", 5);
	str4.assign(str1);
	str5.assign(5,'b');
	str6.assign("hello,world", 5, 10);
	cout << str3 << endl;
	cout << str4 << endl;
	cout << str5 << endl;
	cout << str6 << endl;
}

/*
string ��ȡ�ַ���
char& operator[](int n)  //ͨ��[] �ķ�����ȡ�ַ�
char& at(int n)  //ͨ��at������ȡ�ַ�
[]��at����
[]����Խ���ֱ�ӹҵ���at���׳��쳣
*/
void test02() {
	string str1 = "abcdefg";
	cout << str1[3] << endl;
	cout << str1.at(3) << endl;
	cout << "------��ֵ------" << endl;
	str1[3] = 'a';
	cout << str1[3] << endl;
	cout << str1.at(3) << endl;
	//[]��at����
	//[]����Խ���ֱ�ӹҵ���at���׳��쳣
	try {
		//cout << str1[10] << endl;    //ֱ�ӹҵ�
		cout << str1.at(10) << endl;
	}
	catch (out_of_range & e) {
		cout << e.what() << endl;
	}
	catch (...) {
		cout << "------Խ���쳣------" << endl;
	}
}

/*
stringƴ�Ӳ���
string& operator+=(const string & str);//���ز�����+=
string& operator+=(const cahr * str);//
string& operator+=(const char c);
string& append(const char *s);//���ַ���s���ӵ���ǰ�ַ�����β
string& append(const cahr *s, int n);//���ַ���s��ǰn���ַ����ӵ���ǰ�ַ�����β
string& append(const string & s); //ͬ operator+=
string& append(const string & s,int pos, int n);//���ַ���s�д�pos��ʼ��n���ַ����ӵ���ǰ�ַ�����β
string& append(int n,char c);//�ڵ�ǰ�ַ�����β���n���ַ�c

string���Һ��滻
int find(const string & str, int pos = 0) const  //�����ַ���str��һ�γ��ֵ�λ�ã���pos��ʼ����
int find(const cahr *s, int pos = 0) const  //����s��һ�γ��ֵ�λ�ã���pos��ʼ����
int find(const char *s, int pos, int n) const  //��posλ�ÿ�ʼ����s��ǰn���ַ���һ�γ��ֵ�λ��
int find(const char c, int pos = 0) const  //�����ַ�c��һ�γ��ֵ�λ��
int rfind(const string & str,int pos = npos) const  //����str���һ�γ��ֵ�λ�� ��pos��ʼ
int rfind(const char * s, intn pos = npos) const  //����s���һ�γ��ֵ�λ�� ��pos��ʼ����
int rfind(const char *s, int pos, int n) const  //��pos��ʼ����s��ǰn���ַ����һ��λ��
int rfind(const char c, int pos = 0)const  //�����ַ�c���һ�γ���λ��
string& replace(int pos, int n, const string & str);  //�滻��pos��ʼn���ַ�Ϊstr
string& replace(int pos, int n, const char *s);  //�滻��pos��ʼ��n���ַ�Ϊ�ַ���s
*/

//find����������
//rfind����������
void test03() {
	string s1 = "hello";
	string s2 = s1 + "world";
	cout << s2 << endl;

	s2.append(5, 'b');
	cout << s2 << endl;

	//find����
	int index = s1.find("llo");  //�Ҳ�������-1  find����������
	cout << index << endl;     //  2
	index = s1.rfind("llo");  //�Ҳ�������-1  ����������
	cout << index << endl;    //  2
	//�滻
	s2.replace(3, 5, "555");
	cout << s2 << endl;

}
/*
string �Ƚϲ���
compare������>ʱ����1  <ʱ����-1  ==ʱ����0
�Ƚ����ִ�Сд �Ƚ�ʱ�ο��ֵ�(ASIII��)˳�� ����ǰ���С
��д��A��Сд��aС
int compare(const string & s) const;//���ַ���s�Ƚ�
int compare(const string char *) const
*/
void test04() {
	string s1 = "abc";
	string s2 = "1bc";
	if (s1.compare(s2) == 0) {
		cout << "���" << endl;
	}
	else if (s1.compare(s2) == 1) {
		cout << "s1����s2" << endl;
	}
	else {
		cout << "s1С��s2" << endl;
	}
}

/*
string substr(int pos = 0, int n = npos) const  //������pos��ʼ��n���ַ���ɵ��ַ���
*/
void test05(void) {
	string s1 = "abc";
	string s2 = s1.substr(1, 3);
	cout << "s2 = " << s2 << endl;

	string email = "mingzhao@163.com";
	int pos = email.find("@");
	string userName = email.substr(0, pos);
	cout << userName << endl;
}

/*
string�����ɾ������
string& insert(int pos. const char * s);  //�����ַ���
string& insert(int pos, const string & str);  //�����ַ���
string& insert(int pos, int n, char c);  //��ָ��λ�ò���n���ַ� c
string& erase(int pos, int n = npos);  //ɾ����Pos��ʼ��n���ַ�
*/
void test06(void) {
	string s1 = "0123456789";
	s1.insert(10, "abcd");
	cout << s1 << endl;
	s1.insert(14, "efg");
	cout << s1 << endl;
	s1.erase(10, 7);
	cout << s1 << endl;
}

/*
string �� c-style�ַ���ת��
*/

void func(string str)
{
	cout << str << endl;
}

void func2(char * str)
{
	cout << str << endl;
}

void test07() {
	string s1 = "123";

	const char * p = s1.c_str();
	cout << p << endl;

	string s2(p);
	cout << s2 << endl;
	//func2(s2);  //����  ����string ��ʽ����ת�� char *

	func(p);//��ʽ����ת��Ϊstring
}

int main() {
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	//test06();
	test07();
	return 0;
}
