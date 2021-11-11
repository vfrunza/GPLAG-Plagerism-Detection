#include <stdio.h>

float * zaokruzil (float *p, int duzina){
	int intOdFloata;
	float floatOdInta;
	int i;
	for (i=0;i<duzina;i++){
		*(p+i)=*(p+i)*100;
		intOdFloata=(int)*(p+i);
		floatOdInta=(float)(intOdFloata);
		*(p+i)= floatOdInta;
		if(intOdFloata%10>=5){
			*(p+i)=*(p+i)+10;
		}
		*(p+i)=*(p+i)/10;
		intOdFloata=(int)*(p+i);
		floatOdInta=(float)intOdFloata;
		*(p+i)= floatOdInta;
		*(p+i)=*(p+i)/10;
	}
	return p;
}

float * preslozi (float *p, int k,int duzina){
	float noviNiz[5];
	float *noviNizp;
	int testniNiz[5];
	int intOdFloata;
	int i;
	int j;
	int g;
	int b;
	int suma;
	noviNizp = &noviNiz[0];
	j=0;
	p=zaokruzil(p,duzina);
	for (i=0;i<duzina;i++){
		*(p+i)=*(p+i)*10;
		intOdFloata=(int)*(p+i);
		suma=0;
		while (intOdFloata>0){
			suma=suma + intOdFloata%10;
			intOdFloata=intOdFloata/10;
		}
		if (suma>=k){
			*(p+i)=*(p+i)/10;
			*(noviNizp+j) = *(p+i);
			testniNiz[j] = i;
			j++;
		}
	}
	b=j;
	for (i=0;i<duzina;i++){
		for(g=0;g<b;g++){
			if ( i==testniNiz[g]){
				break;
			}
		}
			if(i==testniNiz[g]){
				continue;
			}
			*(p+i)=*(p+i)/10;
			*(noviNizp+j)=*(p+i);
			j++;
		}
	for (i=0;i<5;i++){
		printf("%f\n",*(noviNizp+i));
	}
	return noviNizp;
}

int main() {
	float testniNiz[5]={13.1, 15.749999, 15.75, 9.222, 78.1};
	float *p;
	int i;
	p=&testniNiz[0];
	i=5;
	p=preslozi(testniNiz,14,i);
	for (i=0;i<5;i++){
		printf("%f\n",*(p+i));
	}
	return 0;
}
