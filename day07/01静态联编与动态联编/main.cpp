#include <iostream>

//��̬��̬��  ��������
//��̬��̬��  �麯���̳�
//��̬���ࣺ  ����׶ΰ󶨵�ַ
//��̬���ࣺ  ��ַ��󶨣�����ʱ��󶨵�ַ
//��̬�� ��������û���ָ�룬ָ������

using namespace std;

//��̬����
class Animal1 {
public:
	void speak(void) {
		cout << "����˵��" << endl;
	}
};

class Cat :
	public Animal1 {

public:
	void speak(void) {
		cout << "è˵��" << endl;
	}
};

//��̬����
class Animal2 {
public:
	virtual void speak(void) {
		cout << "����˵��" << endl;
	}
};

class Dog :
	public Animal2 {
public:
	void speak(void) {
		cout << "��˵��" << endl;
	}
};

class Sheep :
	public Animal2 {
public:
	void speak(void) {
		cout << "��˵��" << endl;
	}
};

// ��̬����   
//����doSpeak   doSpeak������ַ�綼�󶨺���    ���ڱ���׶ξ�ȷ�����˵�ַ��      //���     ��̬����   
void doSpeak1(Animal1 & animal) {
	animal.speak();
}

//����cat.speak()  �Ͳ�����ǰ�󶨺�����Ҫ������ʱ����ȥȷ��Ҫ�󶨺�����ַ
//��̬����  doSpeak()������Ϊ�麯��   �ڸ����������麯����virtual��  �����˶�̬  
//��̬�� ��������û���ָ�룬ָ������
void doSpeak2(Animal2 & animal) {     //Animal2 & animal = cat
	animal.speak();
}


void test01(void) {
	Cat cat;
	Dog dog;
	Sheep sheep;
	//��������˼̳�  ����������������ת��
	doSpeak1(cat);   //è˵��
	doSpeak2(dog);   //��˵��
	doSpeak2(sheep);  //��˵��

	//����ָ��ָ������
	Animal2 *animal = new Dog;
	animal->speak();
}

int main(void) {
	test01();
	return 0;
}