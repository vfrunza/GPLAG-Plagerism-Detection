#include <stdio.h>
#define PI 3.1415926


int main() 
{
	int brojUglova;
	printf ("Unesite broj uglova: ");
	scanf ("%d", &brojUglova);
	if (brojUglova >=500 || brojUglova <=0)
		return 0;
	   
	float niz[500];
	int i, j;
	
	for (i=0; i<brojUglova; i++)
	{
		float temp;
		scanf ("%f", &temp); 
		niz[i]=temp;
	}
	printf("Uglovi su:\n");
	for(i = 0; i < brojUglova; i++){
		char negativan = '0';
		if(niz[i] < 0){
			negativan = '1';
			niz[i] *= -1;
		}
		int stepen = niz[i] * 180.0/PI, minute = (niz[i] * 180.0/PI - stepen)*60.0;
		int sekunde = ((niz[i] * 180.0/PI - stepen)*60.0 - minute)* 60.0 + 1/2.0;
		if(sekunde >= 60){
			minute++;
			sekunde%=60;
		}
		if(minute >= 60){
			stepen++;
			minute%=60;
		}
		if(sekunde <= 30){
			if(negativan == '1')
				stepen *= -1;
			printf("%d stepeni %d minuta %d sekundi\n", stepen, minute, sekunde);
		}else{
			if(i == brojUglova - 1)
				brojUglova--;
			else{
				for(j = i + 1; j < brojUglova; j++){
					float temp = niz[j - 1];
					niz[j - 1] = niz[j];
					niz[j] = temp;
				}
			brojUglova--;
			if(i - 1  >= -1)
				i--;
			}	
		}
	}
	//    int stepen = niz[i]*180.0/PI;
	//   int minute = (niz[i]*180.0/PI - stepen)*60.0;
	//	int sekunde = ((niz[i]*180.0/PI - stepen)*60.0 - minute)*60.0 + 1/2.;
	return 0;
}
