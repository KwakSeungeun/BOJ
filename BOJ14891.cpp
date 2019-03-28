#include <iostream>
#include <string>
#include <math.h>
using namespace std;

string src[4];
int k; // È¸Àü È½¼ö
int result;

void solution(int loc, int dir,bool left_flag, bool right_flag) {
	if (loc < 0 || loc >3) return;
	// ¿ÞÂÊ
	if (loc - 1 >= 0 && left_flag) {
		if (src[loc - 1].at(2) != src[loc].at(6)) solution(loc-1, dir*(-1),true, false);
	}
	//¿À¸¥ÂÊ
	if (loc + 1 < 4 && right_flag) {
		if (src[loc + 1].at(6) != src[loc].at(2)) solution(loc + 1, dir*(-1),false,true);
	}

	//È¸Àü
	string temp;
	if (dir == 1) {
		temp = src[loc].at(7);
		src[loc] = temp + src[loc].substr(0, 7);
	}
	else if (dir == -1) {
		temp = src[loc].at(0);
		src[loc] = src[loc].substr(1, 7) + temp;
	}
	return;
}

int main() {
	for (int i = 0; i < 4; i++) {
		cin >> src[i];
	}
	cin >> k;
	int loc, dir = 0;
	for (int m = 0; m < k; m++) {
		cin >> loc;
		cin >> dir;
		solution(loc-1, dir,true, true);
	}
	int result = 0;
	for (int i = 0; i < 4; i++) {
		if (src[i].at(0) == '0') continue; //N±Ø
		result += pow(2, i);
	}
	cout << result;
	return 0;
}