#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

void print(vector<string> src) {
	for (int i = 0; i < src.size(); i++) {
		cout << src[i] << endl;
	}
}

bool compareLength(string a , string b) {
	return a.length() < b.length();
}

void quickSort(vector<string> &src, int start, int end) {
	if (start >= end) {
		return;
	}

	int pivot = start;
	int i = start+1;
	int j = end;
	string temp;
	while (i <= j) {
		while (i <= end && src[pivot].compare(src[i]) > 0)	i++;
		while(j > start && src[pivot].compare(src[j]) < 0)	j--;
		if (i > j) {
			temp = src[j];
			src[j] = src[pivot];
			src[pivot] = temp;
		} else {
			temp = src[i];
			src[i] = src[j];
			src[j] = temp;
		}
	}
	quickSort(src, start,j - 1);
	quickSort(src, j + 1, end);
}

int main(void) {
	int N;
	cin >> N;
	vector<string> src;
	
	string input;
	for (int i = 0; i < N; i++) {
		cin >> input;
		src.push_back(input);
	}

	sort(src.begin(), src.end(), compareLength); //크기 순으로 정렬 O(N*logN)
	src.erase(unique(src.begin(), src.end()),src.end()); //중복 제거 O(N)

	// quicsort가 필요함 근데 O(N*N*logN) => N= 20,000 약 10^9 => 1초가 조금 넘을 것으로 예상.
	int count = 0;

	for (int i = 0; i < src.size()-1; i++) {
		if (src[i].length() != src[i+1].length()) {
			quickSort(src,i-count,i);
			count = 0;
		}else {
			count++;
		}
	}

	print(src);
	return 0;
}