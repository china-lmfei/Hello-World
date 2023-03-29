#include<iostream>
using namespace std;

#define INF 0x3f3f3f3f //无穷大

//Merge函数 将已经用归并排序排好的两个子数组合到一起
void Merge(int arr[], int left, int mid, int right) {
	//input: arr[left, mid]; arr[mid+1, right]
	int n1 = mid - left + 1; //左边数组长度
	int n2 = right - mid; //右边数组长度
	int* L = new int[n1 + 1];
	int* R = new int[n2 + 1];
	//为L R赋值
	for (int i = 0; i < n1; i++) {
		L[i] = arr[left + i];
	}
	for (int i = 0; i < n2; i++) {
		R[i] = arr[mid + i + 1];
	}
	L[n1] = INF;
	R[n2] = INF;
	int i = 0, j = 0;
	for (int k = left; k <= right; k++) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			++i;
		}
		else {
			arr[k] = R[j];
			++j;
		}
	}
	return;
};

//归并排序主函数
void MergeSort(int arr[], int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		MergeSort(arr, left, mid);
		MergeSort(arr, mid + 1, right);
		Merge(arr, left, mid, right);
	}
	return;
}

int main() {
	int arr[5] = { 5, 4, 3, 2, 1 };
	MergeSort(arr, 0, 4);
	for (int i = 0; i < 5; ++i) {
		cout << arr[i] << endl;
	}
}