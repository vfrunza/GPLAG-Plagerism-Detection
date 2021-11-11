#include <stdio.h>

int main() {
/*	printf("Zadaća 2, Zadatak 1"); */
int n;
int i, j;

do {
	printf ("Unesite broj N:");
	scanf ("%d", &n);
	if (n%4!=0 || n<8)
		printf (" Neispravno N!");
	printf ("\n");
}
while (n%4!=0 || n<8);

for (i=0; i<n/2; i++) {
	for (j=0; j<n/2; j++) {
		if (i==j)
			printf ("\\");
		else
			if (i+j==(n/2)-1)
				printf ("/");
			else 
				printf (" ");
	}
	for (j=n/2; j<n; j++) {
		if ((i==0 || i==(n/2)-1) && (j==n/2 || j==n-1))
			printf ("+");
		else
			if ((i==0 || i==(n/2)-1) && j>n/2 && j<n-1)
				printf ("-");
			else
				if (i!=0 && i!=(n/2)-1 && (j==n/2 || j==n-1))
					printf ("|");
				else
					printf (" ");
	}
	printf ("\n");
}
for (i=n/2; i<n; i++) {
	for (j=0; j<n/2; j++) {
		if((i==n/2 || i==n-1) && (j==0 || j==(n/2)-1))
			printf ("+");
		else
			if((i==n/2 || i==n-1) && (j>0 || j<(n/2)-1))
				printf ("-");
			else
				if (i>n/2 && i<n-1 && (j==0 || j==(n/2)-1))
					printf ("|");
				else
					printf (" ");
	}
	for (j=n/2; j<n; j++) {
		if ((i==n-(n/4)-1 || i==n-(n/4)) && (j==n-(n/4)-1 || j==n-(n/4)))
			printf ("+");
		else
			if (i==n-(n/4)-1 || i==n-(n/4))
				printf ("-");
			else
				if (j==n-(n/4)-1 || j==n-(n/4))
					printf ("|");
				else 
					printf (" ");
		
	}
	printf ("\n");
}
	return 0;
}
