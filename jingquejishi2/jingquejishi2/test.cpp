#include<iostream>
#include <windows.h> // 包含 Windows 平台特定的头文件，用于性能计数器
#include <stdlib.h> // 包含标准库函数的头文件

using namespace std;
void test(int n, int* a, int** b, int*& sum) {
	for (int i = 0; i < n; i++)
		sum[i] = 0.0;
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < n; i++) {
			sum[i] += b[j][i] * a[j];
		}
	}
}
int main() {
	long long head, tail, freq; // 声明三个长整型变量，用于计时

	int n = 700;
	int* a = new int[700];
	int** b = new int* [700];
	int* c = new int[700];
	for (int i = 0; i < 700; i++) {
		b[i] = new int[700];
	}
	for (int i = 0; i < 700; i++) {
		for (int j = 0; j < 700; j++) {
			b[i][j] = i + j;
		}
	}
	for (int i = 0; i < 700; i++) {
		a[i] = i;
	}
	// 获取性能计数器的频率，类似于 CLOCKS_PER_SEC
	QueryPerformanceFrequency((LARGE_INTEGER*)&freq);

	// 获取开始时间
	QueryPerformanceCounter((LARGE_INTEGER*)&head);
	for (int i = 0; i < 1000; i++) {
		test(n, a, b, c);
	}
	// 获取结束时间
	QueryPerformanceCounter((LARGE_INTEGER*)&tail);

	// 输出计算时间，单位为毫秒
	cout << "Col: " << (tail - head) * 1000.0 / freq << "ms" << endl;


	delete[] a;
	delete[] c;
	for (int i = 0; i < 700; ++i) {
		delete[] b[i];
	}
	delete[] b;

}