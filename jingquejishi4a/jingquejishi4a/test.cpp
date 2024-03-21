#include<iostream>
#include <windows.h> // 包含 Windows 平台特定的头文件，用于性能计数器
#include <stdlib.h> // 包含标准库函数的头文件

using namespace std;
void mytest(int n, int* a, int& sum) {
	int sum1 = 0; int sum2 = 0;
	for (int i = 0; i < n; i += 2) {
		sum1 += a[i];
		sum2 += a[i + 1];
	}
	sum = sum1 + sum2;
}

int main() {
	long long head, tail, freq; // 声明三个长整型变量，用于计时

	int n = 700;
	int c;
	int* a = new int[700];
	for (int i = 0; i < 700; i++) {
		a[i] = i;
	}

	// 获取性能计数器的频率，类似于 CLOCKS_PER_SEC
	QueryPerformanceFrequency((LARGE_INTEGER*)&freq);

	// 获取开始时间
	QueryPerformanceCounter((LARGE_INTEGER*)&head);

	for (int i = 0; i < 10000; i++) {
		c = 0;
		mytest(n, a, c);
	}

	// 获取结束时间
	QueryPerformanceCounter((LARGE_INTEGER*)&tail);

	// 输出计算时间，单位为毫秒
	cout << "Col: " << (tail - head) * 1000.0 / freq << "ms" << endl;

	delete[]a;
}