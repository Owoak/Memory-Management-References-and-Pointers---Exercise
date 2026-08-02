#include <sstream>
#include <iostream>

const int maxSize = 100;
using namespace std;

int* readArray(int& count) {
	string input;
	getline(cin, input);
	istringstream buffer(input);
	int* arr = new int[maxSize];

	bool FirstTime = true;
	do {
		if (!FirstTime) {
			count++;
		}
		else {
			FirstTime = false;
		}
		if (count >= maxSize) {
			cerr << "OUT OF BOUNDS INPUT";
			count--;
			break;
		}
	} while (buffer >> arr[count]);

	return arr;
}

void removeNegatives(int* arr, int& count) {
	for (int i = 0; i < count; i++) {
		if (*(arr + i) < 0) {
			for (int removes = i; removes < count - 1; removes++) {
				int* ponterFirst = arr + removes;
				int* ponterSecond = arr + removes + 1;
				*ponterFirst = *ponterSecond;
			}
			count--;
			i--;
		}
	}
}
void printbackWard(int* arr, const int& count) {
	int* endPtr = arr + count - 1;
	while (endPtr != arr) {
		cout << *endPtr << ' ';
		endPtr--;
	}
	cout << *arr;
}

int main()
{
	int count = 0;
	int* arr = readArray(count);
	if (count == 0) {
		cout << "empty";
		delete[]arr;
		return 0;
	}

	removeNegatives(arr, count);
	if (count == 0) {
		cout << "empty";
		delete[]arr;
		return 0;
	}

	printbackWard(arr, count);

	delete[]arr;
	return 0;
}