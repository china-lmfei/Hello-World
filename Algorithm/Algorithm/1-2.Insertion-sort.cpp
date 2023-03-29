#include<iostream>
using namespace std;

//²åÈëÅÅĞò(ÕıĞò)
void insertion_sort(int arr[], int len) {
	for (int j = 1; j < len; ++j) {
		int key = arr[j];
		int i = j - 1;
		while (i >= 0 && arr[i] > key) {
			arr[i + 1] = arr[i];
			--i;
		}
		arr[i + 1] = key;
	}
	for (int t = 0; t < len; ++t) {
		cout << arr[t] << endl;
	}
};
/*
int main() {
	int arr[5] = { 5,4,3,2,1 };
	insertion_sort(arr, 5);
}*/