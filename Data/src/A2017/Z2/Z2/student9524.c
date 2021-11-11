#include <stdio.h>
#define PI 3.1415926

int main() {

	int n , i , j;
	float sec , min , step ;
	float niz[500]={0} ;

	do{
		printf("Unesite broj uglova: ");
		scanf("%d" , &n);

		if(n<1||n>500)
		printf("Pogresan unos\n");
	}
	while(n<1||n>500);

	for (i=0 ; i<n ; i++)
	{scanf("%f",&niz[i]);}

	for(i=0; i<n ; i++) {
		niz[i]=niz[i]*180./PI ;


	}

	for (i=0 ; i<n ; i++) {
		step=(int)niz[i];
		min=(niz[i]-(int)niz[i])*60 ;
		sec=(min-(int)min)*60 ;
		if(sec>30) {

			for(j=i ; j<n-1 ; j++) {
				niz[j]=niz[j+1];}


		i--;
		n--;
	}
	}

		printf ("Uglovi su: \n") ;
		for(i=0 ; i<n ; i++) {

			step=(int)niz[i];
			min=(niz[i]-(int)niz[i])*60 ;
			sec=(min-(int)min)*60 ;
			if(sec+0.5>(int)sec+1) sec=(int)sec+1;

			printf("%d stepeni %d minuta %d sekundi\n", (int)step ,(int) min ,(int) sec);

		}

	return 0;
}