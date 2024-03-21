#include<iostream>
#include <windows.h> // ���� Windows ƽ̨�ض���ͷ�ļ����������ܼ�����
#include <stdlib.h> // ������׼�⺯����ͷ�ļ�

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
	long long head, tail, freq; // �������������ͱ��������ڼ�ʱ

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
	// ��ȡ���ܼ�������Ƶ�ʣ������� CLOCKS_PER_SEC
	QueryPerformanceFrequency((LARGE_INTEGER*)&freq);

	// ��ȡ��ʼʱ��
	QueryPerformanceCounter((LARGE_INTEGER*)&head);
	for (int i = 0; i < 1000; i++) {
		test(n, a, b, c);
	}
	// ��ȡ����ʱ��
	QueryPerformanceCounter((LARGE_INTEGER*)&tail);

	// �������ʱ�䣬��λΪ����
	cout << "Col: " << (tail - head) * 1000.0 / freq << "ms" << endl;


	delete[] a;
	delete[] c;
	for (int i = 0; i < 700; ++i) {
		delete[] b[i];
	}
	delete[] b;

}