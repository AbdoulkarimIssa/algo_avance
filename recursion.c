#include <stdio.h>
#include <stdlib.h>

// Iterative Function

int fact_i (int n) {
	int i;
	int acc;
	acc=1;
		for (i=1;i<=n;i++) {
			acc=acc*i;
		}
	return acc;
}

// Recursive Function

int fact_r (int n, int acc) {
	if (n==0) {
		return 1*acc;
	}
	else {
		return fact_r(n-1,acc*n);
	}
}


int main () {
	int n;
	int acc=0;
	int choice;
	printf("Entrez un nombre entier : \n");
	scanf("%d", &n);
	printf("Choisissez entre le mode itératif \"1\" et le mode récursif \"2\" : \n");
	scanf("%d", &choice);
	if (choice==1) {
		acc=fact_i(n);
		printf("La factorielle de %d en itératif est %d \n", n, acc);
	}
	else {
		acc=fact_r(n,1);
		printf("La factorielle de %d en récursif est %d", n, acc);
	}
	return 0;
}
