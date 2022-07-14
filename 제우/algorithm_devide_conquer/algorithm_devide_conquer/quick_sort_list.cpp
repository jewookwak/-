#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
//QuickSort   
int n, cnt, quick[10000001];

void quickSort(int i, int j)
{
	if (i >= j) return;
	int pivot = quick[(i + j) / 2];
	int left = i;
	int right = j;

	while (left <= right)
	{
		while (quick[left] < pivot) left++;
		while (quick[right] > pivot) right--; // use index first and then 
		if (left <= right)
		{
			swap(quick[left], quick[right]);  // swap the array 
			left++; right--;
		}
	}
	quickSort(i, right);
	quickSort(left, j);
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &quick[i]);

	quickSort(0, n - 1);

	for (int j = 0; j < n; j++) // Ãâ·Â
		printf("%d\n", quick[j]);
}