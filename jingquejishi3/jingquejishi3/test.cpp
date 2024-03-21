#include<iostream>
#include <windows.h> // 包含 Windows 平台特定的头文件，用于性能计数器
#include <stdlib.h> // 包含标准库函数的头文件

using namespace std;
void mytest(int n, int* a, int& sum) {
	for (int i = 0; i < n; i++)
		sum += a[i];
}

int main() {
	long long head, tail, freq; // 声明三个长整型变量，用于计时

	int n = 700;
	int c;
	int* a = new int[700];
	for (int i = 0; i < 700; i++) {
		a[i] = i;
	}
	QueryPerformanceFrequency((LARGE_INTEGER*)&freq);

	// 获取开始时间
	QueryPerformanceCounter((LARGE_INTEGER*)&head);
	for (int i = 0; i < 10000; i++) {
		c = 0;
		mytest(n, a, c);
	}
	QueryPerformanceCounter((LARGE_INTEGER*)&tail);

	// 输出计算时间，单位为毫秒
	cout << "Col: " << (tail - head) * 1000.0 / freq << "ms" << endl;
	delete[]a;
}