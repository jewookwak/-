#include<iostream>
#include <vector>
using namespace std;

void quickSort(int* data, int start, int end) {
    if (start >= end) return;
    int pivot = start;  // ���� ��
    int i = start + 1;
    int j = end;

    while (i <= j) {
        while (data[i] <=
            data[pivot])  // Ű ������ ū �� ���������� ���������� �̵�
            i++;
        while (data[j] >= data[pivot] &&
            j > start)  // Ű ������ ���� �� ���� ������ �������� �̵�
            j--;
        if (i > j)  //���� ������ ���¸� pivot �� ��ü
        {
            int temp = data[j];
            data[j] = data[pivot];
            data[pivot] = temp;
        }
        else {
            int temp = data[j];
            data[j] = data[i];
            data[i] = temp;
        }
        // ��� ȣ��
        quickSort(data, start, j - 1);
        quickSort(data, j + 1, end);
    }
}

int main()
{
    int n1;
    cin >> n1;
    int array1[100000], array2[100000];

    for (int i = 0; i < n1; i++)
        cin >> array1[i];

    int n2;
    cin >> n2;

    for (int i = 0; i < n2; i++)
        cin >> array2[i];


    int data[7] = { 38,27,43,9,3,82,10 };
    int len = 7;

    quickSort(vec2, 0, len - 1);

    for (int i = 0; i < len; i++) cout << data[i] << ' ';
}
    