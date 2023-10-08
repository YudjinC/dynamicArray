#include <iostream>
#include <ctime>

using namespace std;

void inputArr(int *arr, int sizeArr);
void outputArr(int *arr, int sizeArr);
void pushForward(int *&arr, int &sezeArr, int pushValue);
void pushBack(int *&arr, int &sizeArr, int pushValue);
void deleteForward(int *&arr, int &sizeArr);
void deleteBack(int *&arr, int &sizeArr);

int main() {
	srand(time(NULL));

	int sizeArr;
	int *arr;

	cout << "Input size arr:" << endl;
	cin >> sizeArr;

	arr = new int[sizeArr];

	cout << "Fill arr:" << endl;
	inputArr(arr, sizeArr);
	outputArr(arr, sizeArr);
	cout << endl;

	cout << "Push forward value:" << endl;
	pushForward(arr, sizeArr, rand() % 90);
	outputArr(arr, sizeArr);
	cout << endl;

	cout << "Push back value:" << endl;
	pushBack(arr, sizeArr, rand() % 90);
	outputArr(arr, sizeArr);
	cout << endl;

	cout << "Delete forward value:" << endl;
	deleteForward(arr, sizeArr);
	outputArr(arr, sizeArr);
	cout << endl;

	cout << "Delete back value:" << endl;
	deleteBack(arr, sizeArr);
	outputArr(arr, sizeArr);
	cout << endl;

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

void pushForward(int *&arr, int &sizeArr, int pushValue) {
	int *newArr = new int[++sizeArr];
	newArr[0] = pushValue;
	
	for (int i = 0, j = 1; i < sizeArr - 1; i++, j++) {
		newArr[j] = arr[i];
	}

	arr = newArr;
}

void pushBack(int *&arr, int &sizeArr, int pushValue) {
	int *newArr = new int[sizeArr + 1];
	for (int i = 0; i < sizeArr; i++) {
		newArr[i] = arr[i];
	}

	newArr[sizeArr++] = pushValue;

	arr = newArr;
}

void deleteForward(int*& arr, int& sizeArr) {
	int *newArr = new int[--sizeArr];
	for (int i = 1, j = 0; i < sizeArr + 1; i++, j++) {
		newArr[j] = arr[i];
	}

	arr = newArr;
}

void deleteBack(int *&arr, int &sizeArr) {
	int* newArr = new int[--sizeArr];
	for (int i = 0; i < sizeArr; i++) {
		newArr[i] = arr[i];
	}

	arr = newArr;
}