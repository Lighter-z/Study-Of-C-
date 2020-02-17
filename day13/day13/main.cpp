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
产生24名选手，姓名 得分 编号
每一轮每一组取前三进入下一轮比赛  每组6人
*/

class Spaker {
public:
	string name_;    //姓名
	int score_[3];  //每轮比赛得分
};

void CreatSpaker(vector<int> & v, map<int, Spaker> & m) {
	string name_speed = "ABCDEFGHIGKLMNOPQRSTUVWX";
	for (int i = 0; i < name_speed.size(); i++) {
		string name = "选手";
		name += name_speed[i];

		Spaker sp;
		sp.name_ = name;
		for (int j = 0; j < 3; j++) {
			sp.score_[j] = 0;
		}
		v.push_back(i);  //编号0-23
		m.insert(make_pair(i, sp));
	}
}

//抽签
void SpeechDraw(vector<int> v) {
	//洗牌
	random_shuffle(v.begin(), v.end());
}

//1、第几轮  2、v1比赛选手编号  2、m是选手编号的具体选手  3、v2晋级选手编号容器
void SpeechContest(int index, vector<int>&v1, map<int, Spaker> &m, vector<int> &v2) {
	multimap<int, int, greater<int>> group_map;  //key 分数  value编号
	int num = 0;
	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++) {
		num++;
		deque<int> d;
		//10个评委打分
		for (int i = 0; i < 10; i++) {
			int score = rand() % 41 + 60;
			d.push_back(score);
		}

		//排序
		sort(d.begin(), d.end());
		//去除最低最高分
		d.pop_back();
		d.pop_front();

		//累计分数
		int sum = accumulate(d.begin(), d.end(), 0);
		int avg = sum / d.size();
		
		//将平均分放入容器中
		m[*it].score_[index - 1] = avg;

		//临时容器保存6个人  
		group_map.insert(make_pair(avg, (*it)));
		if (num % 6 == 0) {
			//cout << "小组成绩" << endl;
			//for (multimap<int, int, greater<int>>::iterator mit = group_map.begin(); mit != group_map.end(); mit++) {
			//	cout << "得分：" << mit->first << " 姓名：" << m[mit->second].name_ << " 得分：" << m[mit->second].score_[index - 1] << endl;
			//	
			//}

			//取前三
			int cout = 0;
			for (multimap<int, int, greater<int>>::iterator mit = group_map.begin(); mit != group_map.end(), cout < 3; cout++, mit++) {
				v2.push_back(mit->second);
			}

			group_map.clear();  //清空临时容器
		}
	}
	for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

void ShowScore(int index, vector<int> & v, map<int, Spaker> & m) {
	cout << "第" << index << "轮，比赛成绩如下" << endl;
	for (map<int, Spaker>::iterator it = m.begin(); it != m.end(); it++) {
		cout << "选手编号：" << it->first << " 姓名：" << it->second.name_ << " 得分：" << it->second.score_[index - 1] << endl;

	}
	cout << "晋级选手编号" << endl;
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

int main() {
	//随机数种子
	srand((unsigned int)time(NULL));

	vector<int> v1;  //选手编号
	map<int, Spaker> m;  //存放选手编和具体的选手

	CreatSpaker(v1, m);  //创建选手

	SpeechDraw(v1);  //抽签
	vector<int> v2;  //进入下一轮比赛的人员编号
	SpeechContest(1, v1, m, v2);  //比赛
	ShowScore(1, v2, m);  //显示比赛结果

	SpeechDraw(v2);
	vector<int> v3;
	SpeechContest(2, v2, m, v3);
	ShowScore(2, v3, m);

	SpeechDraw(v3);
	vector<int> v4;
	SpeechContest(3, v3, m, v4);
	ShowScore(3, v4, m);

	//for (map<int, Spaker>::iterator it = m.begin(); it != m.end(); it++) {
	//	cout << "编号：" << it->first << "  姓名：" << it->second.name_ << endl;
	//}

	
	return 0;
}









