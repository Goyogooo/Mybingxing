#include<iostream>
#include <windows.h> // ���� Windows ƽ̨�ض���ͷ�ļ����������ܼ�����
#include <stdlib.h> // ������׼�⺯����ͷ�ļ�

using namespace std;
void mytest(int n, int* a, int& sum) {
	for (int m = n; m > 1; m /= 2) {// log(n)������
		for (int i = 0; i < m / 2; i++)
			a[i] = a[i * 2] + a[i * 2 + 1]; // ����Ԫ����������洢��������ǰ��
		// a[0]Ϊ���ս��
	}
	sum = a[0];
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