#include <iostream>

using namespace std;

template<typename T>
void Swap(T & a, T & b) {
	T temp;
	temp = a;
	a = b;
	b = temp;
}
//排序  从大到小
template<class T>
void Sort(T arr[], int len) {
	for (int i = 0; i < len; i++) {
		int max = i;
		for (int j = i + 1; j < len; j++) {
			if (arr[max] < arr[j]) {
				max = j;
			}
		}
		if (max != i) {
			Swap(arr[max], arr[i]);
		}
	}
}
//输出数组模板
template<class T>
void printArray(T arr[], int len) {
	for (int i = 0; i < len; i++) {
		cout << arr[i] << endl;
	}
}

void test01(){
	char arr[] = "helloworld";
	Sort(arr, (sizeof(arr) / sizeof(arr[0])));
	printArray(arr, (sizeof(arr) / sizeof(arr[0])));

	int arr2[] = {1,3,4,5};
	Sort(arr2, (sizeof(arr2) / sizeof(arr2[0])));
	printArray(arr2, (sizeof(arr2) / sizeof(arr2[0])));
}

int main() {
	test01();
	return 0;
}
