#include <iostream>
#include <ctime>

using namespace std;

void inputArr(int *arr, int sizeArr);
void outputArr(int *arr, int sizeArr);
void pushBack(int *&arr, int &sizeArr, int pushValue);

int main() {
	srand(time(NULL));

	int sizeArr;
	int *arr;

	cout << "Input size arr:" << endl;
	cin >> sizeArr;

	arr = new int[sizeArr];

	inputArr(arr, sizeArr);
	outputArr(arr, sizeArr);

	pushBack(arr, sizeArr, rand() % 90);
	outputArr(arr, sizeArr);

	delete[] arr;
	arr = nullptr;
}

void inputArr(int *arr, int sizeArr) {
	for (int i = 0; i < sizeArr; i++) {
		arr[i] = rand() & 90;
	}
}

void outputArr(int *arr, int sizeArr) {
	for (int i = 0; i < sizeArr; i++) {
		cout << arr[i] << "\t";
	}
	cout << endl;
}

void pushBack(int *&arr, int &sizeArr, int pushValue) {
	int *newArr = new int[sizeArr + 1];
	for (int i = 0; i < sizeArr; i++) {
		newArr[i] = arr[i];
	}

	newArr[sizeArr++] = pushValue;

	arr = newArr;

	newArr = nullptr;
}