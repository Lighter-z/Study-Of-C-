#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <deque>
#include <numeric>
#include <ctime>
using namespace std;

/*
����24��ѡ�֣����� �÷� ���
ÿһ��ÿһ��ȡǰ��������һ�ֱ���  ÿ��6��
*/

class Spaker {
public:
	string name_;    //����
	int score_[3];  //ÿ�ֱ����÷�
};

void CreatSpaker(vector<int> & v, map<int, Spaker> & m) {
	string name_speed = "ABCDEFGHIGKLMNOPQRSTUVWX";
	for (int i = 0; i < name_speed.size(); i++) {
		string name = "ѡ��";
		name += name_speed[i];

		Spaker sp;
		sp.name_ = name;
		for (int j = 0; j < 3; j++) {
			sp.score_[j] = 0;
		}
		v.push_back(i);  //���0-23
		m.insert(make_pair(i, sp));
	}
}

//��ǩ
void SpeechDraw(vector<int> v) {
	//ϴ��
	random_shuffle(v.begin(), v.end());
}

//1���ڼ���  2��v1����ѡ�ֱ��  2��m��ѡ�ֱ�ŵľ���ѡ��  3��v2����ѡ�ֱ������
void SpeechContest(int index, vector<int>&v1, map<int, Spaker> &m, vector<int> &v2) {
	multimap<int, int, greater<int>> group_map;  //key ����  value���
	int num = 0;
	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++) {
		num++;
		deque<int> d;
		//10����ί���
		for (int i = 0; i < 10; i++) {
			int score = rand() % 41 + 60;
			d.push_back(score);
		}

		//����
		sort(d.begin(), d.end());
		//ȥ�������߷�
		d.pop_back();
		d.pop_front();

		//�ۼƷ���
		int sum = accumulate(d.begin(), d.end(), 0);
		int avg = sum / d.size();
		
		//��ƽ���ַ���������
		m[*it].score_[index - 1] = avg;

		//��ʱ��������6����  
		group_map.insert(make_pair(avg, (*it)));
		if (num % 6 == 0) {
			//cout << "С��ɼ�" << endl;
			//for (multimap<int, int, greater<int>>::iterator mit = group_map.begin(); mit != group_map.end(); mit++) {
			//	cout << "�÷֣�" << mit->first << " ������" << m[mit->second].name_ << " �÷֣�" << m[mit->second].score_[index - 1] << endl;
			//	
			//}

			//ȡǰ��
			int cout = 0;
			for (multimap<int, int, greater<int>>::iterator mit = group_map.begin(); mit != group_map.end(), cout < 3; cout++, mit++) {
				v2.push_back(mit->second);
			}

			group_map.clear();  //�����ʱ����
		}
	}
	for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

void ShowScore(int index, vector<int> & v, map<int, Spaker> & m) {
	cout << "��" << index << "�֣������ɼ�����" << endl;
	for (map<int, Spaker>::iterator it = m.begin(); it != m.end(); it++) {
		cout << "ѡ�ֱ�ţ�" << it->first << " ������" << it->second.name_ << " �÷֣�" << it->second.score_[index - 1] << endl;

	}
	cout << "����ѡ�ֱ��" << endl;
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

int main() {
	//���������
	srand((unsigned int)time(NULL));

	vector<int> v1;  //ѡ�ֱ��
	map<int, Spaker> m;  //���ѡ�ֱ�;����ѡ��

	CreatSpaker(v1, m);  //����ѡ��

	SpeechDraw(v1);  //��ǩ
	vector<int> v2;  //������һ�ֱ�������Ա���
	SpeechContest(1, v1, m, v2);  //����
	ShowScore(1, v2, m);  //��ʾ�������

	SpeechDraw(v2);
	vector<int> v3;
	SpeechContest(2, v2, m, v3);
	ShowScore(2, v3, m);

	SpeechDraw(v3);
	vector<int> v4;
	SpeechContest(3, v3, m, v4);
	ShowScore(3, v4, m);

	//for (map<int, Spaker>::iterator it = m.begin(); it != m.end(); it++) {
	//	cout << "��ţ�" << it->first << "  ������" << it->second.name_ << endl;
	//}

	
	return 0;
}









