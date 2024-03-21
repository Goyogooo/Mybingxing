#include<iostream>
#include <windows.h> // ���� Windows ƽ̨�ض���ͷ�ļ����������ܼ�����
#include <stdlib.h> // ������׼�⺯����ͷ�ļ�

using namespace std;
void mytest(int n, int* a, int& sum) {
	if (n == 1)
		return;
	else
	{
		for (int i = 0; i < n / 2; i++)
			a[i] += a[n - i - 1];
		n = n / 2;
		mytest(n, a, sum);
	}
}

int main() {
	long long head, tail, freq; // �������������ͱ��������ڼ�ʱ

	int n = 700;
	int c;
	int* a = new int[700];
	for (int i = 0; i < 700; i++) {
		a[i] = i;
	}
	// ��ȡ���ܼ�������Ƶ�ʣ������� CLOCKS_PER_SEC
	QueryPerformanceFrequency((LARGE_INTEGER*)&freq);

	// ��ȡ��ʼʱ��
	QueryPerformanceCounter((LARGE_INTEGER*)&head);

	for (int i = 0; i < 10000; i++) {
		c = 0;
		mytest(n, a, c);
	}

	// ��ȡ����ʱ��
	QueryPerformanceCounter((LARGE_INTEGER*)&tail);

	// �������ʱ�䣬��λΪ����
	cout << "Col: " << (tail - head) * 1000.0 / freq << "ms" << endl;

	delete[]a;
}