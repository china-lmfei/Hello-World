#include<iostream>
using namespace std;

#define INF 0x3f3f3f3f //�����

//Merge���� ���Ѿ��ù鲢�����źõ�����������ϵ�һ��
void Merge(int arr[], int left, int mid, int right) {
	//input: arr[left, mid]; arr[mid+1, right]
	int n1 = mid - left + 1; //������鳤��
	int n2 = right - mid; //�ұ����鳤��
	int* L = new int[n1 + 1];
	int* R = new int[n2 + 1];
	//ΪL R��ֵ
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

//�鲢����������
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