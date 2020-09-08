#include <stdio.h>
#include <conio.h>

void MERGE_SORT (int [], int, int);
void MERGE (int [], int, int, int);
void PRINT (int [], int);

int main(){
	int arr[] = {4, 5, -7, 9, -20, 1};
	int length = sizeof(arr)/sizeof(int);
	MERGE_SORT(arr, 0, length-1);
	PRINT(arr, length);
 
}

void MERGE_SORT (int a[], int start, int last) {
	if (start < last) {
		int middle = (start + last) / 2;
		MERGE_SORT(a, start, middle);
		MERGE_SORT(a, middle + 1, last);
		MERGE(a, start, middle, last);
	}
}

void MERGE (int a[], int start, int middle, int last) {
	printf("start : %d\t middle: %d\t last: %d\n", start, middle, last);
	int n1 = middle - start + 1;
	int n2 = last - middle;
	int L[n1], R[n2];

	for (int i=0; i < n1; i++) {
		L[i] = a[start + i];  
	}

	for (int j=0; j < n2; j++) {
		R[j] = a[middle + 1 + j];
	}

	int i,j, k = start;
	i=j=0;


	while (i < n1 && j < n2) {
		if (L[i] < R[j]) {
			a[k] = L[i];
			i++;
		} else {
			a[k] = R[j];
			j++;
		}
		k++;
	}

	while(i < n1) {
		a[k] = L[i];
		i++;
		k++;
	}

	while(j < n2) {
		a[k] = R[i];
		j++;
		k++;
	}
}

void PRINT (int a[], int length) {
	for (int i=0; i < length; i++ ) {
		printf("\t%d\t", a[i]);
	}
}