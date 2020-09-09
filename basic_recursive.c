//Basic recursive


//fact function

int Fact(int n){
	if (n==0) return n;
	else return n*Fact(n-1);
}

//fibonacci

int FibRec(int n){
	if ( n<=1 ) return 1;
	else return FibRec(n-1) + FibRec(n-2);
}

//C(k,n)

#include <stdio.h>
#include <conio.h>

#define MAX_LENGTH 100

typedef struct LIST{
	int elements[MAX_LENGTH];
	int last;
}list_type;

void insert(list_type *, int, int);
void showList(list_type L);
int main(){
	list_type L = {{1,2,3,4,5,6}, 6};
	int x, p;
	printf("Gia tri ban muon insert la: ");
	scanf("%d", &x);
	printf("\nVi tri ban muon insert la: ");
	scanf("%d", &p);
	insert(&L, x, p);
	showList(L);
}

void insert(list_type *L, int x, int p) {
	if(p > (*L).last || p < 0) {
		printf("Your position is incorrect!!!");
	} else {
		for (int i=(*L).last; i>=p; i--) {
			(*L).elements[i+1] = (*L).elements[i];
		}
		(*L).last = (*L).last + 1;
		(*L).elements[p] = x;
	}
	
}

void showList(list_type L) {
	for (int i=0; i<L.last; i++) {
		printf("\t%d\t", L.elements[i]);
	}
}
