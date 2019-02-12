#include <iostream>

using namespace std;

class Station {
	int out_people;
	int in_people;

	public:
		Station(int out, int in) {
			out_people = out;
			in_people = in;
		};
		int getOutPeople() { return out_people; };
		int getInPeople() { return in_people; };
};

int main() {
	Station* stations[4];
	int out, in;

	for (int i = 0; i < 4; i++) {
		cin >> out;
		cin >> in;

		stations[i] = new Station(out, in);
	}

	int max = 0;
	int current = 0;

	for (int k = 0; k < 4; k++) {
		current -= stations[k]->getOutPeople();
		current += stations[k]->getInPeople();
		if (max < current) max = current;
	}
	cout << max << endl;

	return 0;
}