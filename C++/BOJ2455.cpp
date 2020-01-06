#include <iostream>
using namespace std;

int main() {
	int out, in;

	int max = 0;
	int current = 0;

	for (int i = 0; i < 4; i++) {
		cin >> out >> in;
		current -= out;
		current += in;
		if (max < current) max = current;
	}
	cout << max << endl;

	return 0;
}