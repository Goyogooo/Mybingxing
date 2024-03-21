#include<iostream>
#include <windows.h> // ���� Windows ƽ̨�ض���ͷ�ļ����������ܼ�����
#include <stdlib.h> // ������׼�⺯����ͷ�ļ�

using namespace std;
void mytest(int n, int* a, int& sum) {
	for (int i = 0; i < n; i++)
		sum += a[i];
}

int main() {
	long long head, tail, freq; // �������������ͱ��������ڼ�ʱ

	int n = 700;
	int c;
	int* a = new int[700];
	for (int i = 0; i < 700; i++) {
		a[i] = i;
	}
	QueryPerformanceFrequency((LARGE_INTEGER*)&freq);

	// ��ȡ��ʼʱ��
	QueryPerformanceCounter((LARGE_INTEGER*)&head);
	for (int i = 0; i < 10000; i++) {
		c = 0;
		mytest(n, a, c);
	}
	QueryPerformanceCounter((LARGE_INTEGER*)&tail);

	// �������ʱ�䣬��λΪ����
	cout << "Col: " << (tail - head) * 1000.0 / freq << "ms" << endl;
	delete[]a;
}