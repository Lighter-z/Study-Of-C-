#include <iostream>

using namespace std;

class Club {
private:
	double club_l;
	double club_w;
	double club_h;
public:
	void SetL(const double l) {
		club_l = l;
	}
	void SetW(const double w) {
		club_w = w;
	}
	void SetH(const double h) {
		club_h = h;
	}
	double GetClubArea() {
		return 2 * (club_l * club_w + club_l * club_h + club_w * club_h);
	}
	double GetClubVolume() {
		return club_h * club_l * club_w;
	}
	bool CompareClubByClass(Club &c) {
		if (GetClubArea() == c.GetClubArea() && GetClubVolume() == c.GetClubVolume()) {
			return true;
		}
		return false;
	}
};

bool isSame(Club &club1,Club &club2) {
	if (club1.GetClubArea() == club2.GetClubArea() && club2.GetClubVolume() == club2.GetClubVolume()) {
		return true;
	}
	return false;
}

void Club1(void) {
	Club c1;
	c1.SetH(1);
	c1.SetL(2);
	c1.SetW(3);

	cout << "Club 1 Area = " << c1.GetClubArea() << endl;
	cout << "Club 1 Volume = " << c1.GetClubVolume() << endl;
	
	Club c2;
	c2.SetH(3);
	c2.SetL(2);
	c2.SetW(3);

	cout << "Club 1 Area = " << c2.GetClubArea() << endl;
	cout << "Club 1 Volume = " << c2.GetClubVolume() << endl;

	bool ret = isSame(c1,c2);
	if (ret) {
		cout << "相等" << endl;
	}
	else {
		cout << "不相等" << endl;
	}

	bool ret_class = c1.CompareClubByClass(c2);
	if (ret_class) {
		cout << "相等" << endl;
	}
	else {
		cout << "不相等" << endl;
	}
}

int main() {
	Club1();
	return 0;
}
