#include <stdio.h>
#include <math.h>
#define PI 3.1415926
#define max 500
int main() {
	int UR;
	double niz[max],x,stepen,stepen2,y,minuta,minuta2,z,sekunda1,sekunda;
	int stepen1,minuta1,sekunda2, i,k=0,j,p=0;
	printf("Unesite broj uglova: ");
	scanf("%d", &UR);
	for(i=0;i<UR;i++){
	scanf("%lf", &niz[i]);}
		printf ("Uglovi su: \n");
	for(i=0;i<UR;i++){
		stepen=niz[i]*180/PI;
		stepen2=niz[i]*180/PI;
		stepen1=(int)stepen;
		
		y=stepen2-stepen1;
		minuta=y*60;
		minuta2=y*60;
		minuta1=(int)minuta;
		
		z=minuta2-minuta1;
		sekunda=z*60;
		sekunda1=z*60;
		x=sekunda1-(int)sekunda;
		if (x>=0.5){
			sekunda=sekunda+1;}
			else { 
				sekunda2=(int)sekunda;
				
			}
		
		p++;
		
	}
	for(k=0;k<p;k++){
			if (sekunda>30){
				for(j=k;j<p-1;j++){
		stepen=stepen+1;
		minuta=minuta+1;
		sekunda=sekunda+1;
	}
	p--;
	i--;
}
 
	}	


		for(k=0;k<p;k++){
			printf ("%d %d %d\n", stepen1, minuta1, sekunda2);
		}
	

	

	
	return 0;
}
