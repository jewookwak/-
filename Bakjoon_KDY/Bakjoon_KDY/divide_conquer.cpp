#include<iostream>

void merge_sort_DC(int list[], int low, int high) {
	int middle;
	if (low £¼ high) {
		middle = (low + high) / 2;
		merge_sort_DC(list, low, middle);
		merge_sort_DC(list, middle + 1, high);
		merge(list, low, middle, high);
	}
}
void merge(int list[], int low, int mid, int high) {
	int n1 = low, n2 = mid + 1, s = low, sorted[MAX_SIZE], i;
	while (n1 <= mid && n2 <= high) {
		if (list[n1] <= list[n2]) sorted[s++] = list[n1++];
		else sorted[s++] = list[n2++];
	}
	if (n1 £¾ mid) while (n2 <= high) sorted[s++] = list[n2++];
	else while (n1 <= mid) sorted[s++] = list[n1++];
	for (i = low; i <= high; i++) list[i] = sorted[i];
}