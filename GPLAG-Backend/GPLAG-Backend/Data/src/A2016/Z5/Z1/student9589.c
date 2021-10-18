#include <stdio.h>
#include <string.h>

struct Student {

	char ime[20];
	char prezime[20];
	int ocjene[50];
	int br_ocjena;

};


int genijalci(struct Student x[],int vel,double prosjek)
{
	double pomoc=0;
	double suma=0;
	double max1,max2,max3;
double max;
	int j=0,i=0;
	double prosjeci[1000];
	int indeks1,indeks2,indeks3;
	for(i=0; i<vel; i++) {
		suma=0;
		pomoc=10;
		if(x[i].br_ocjena==0){
			prosjeci[i]=5;
			continue;
		}
		for(j=0; j<x[i].br_ocjena; j++) {
			if(x[i].ocjene[j]==5) {
				pomoc=5;
				break;
			}
			suma+=x[i].ocjene[j];
		}
		if(pomoc!=5) {
			pomoc=suma/x[i].br_ocjena;

		}
		prosjeci[i]=pomoc;

	}
	for(i=0; i<vel; i++) {
		if(prosjeci[i]<prosjek) {
			for(j=i; j<vel-1; j++) {
				x[j]=x[j+1];
				prosjeci[j]=prosjeci[j+1];
			}
			i--;

			vel--;
		}

	}
	max1=prosjeci[0];
	indeks1=0;
	for(i=0;i<vel;i++){
	
		if(max1<prosjeci[i]){
			max1=prosjeci[i];
			indeks1=i;
			
		}
	}
	for(i=0;i<vel;i++){
		if(max1==prosjeci[i]&&i!=indeks1){
			if(!strcmp(x[indeks1].prezime,x[i].prezime)){
				indeks1=indeks1;
			}else
			indeks1=i;
			
		}
	}
	max2=prosjeci[0];
	indeks2=0;

	for(i=0;i<vel;i++){
	
		if(max2<prosjeci[i]&&i!=indeks1){
		
			max2=prosjeci[i];
			indeks2=i;
			
		}
		else if(i!=indeks1){
			max2=prosjeci[i];
			indeks2=i;
		}
	}
		for(i=0;i<vel;i++){
		if(max2==prosjeci[i]&&i!=indeks1&&i!=indeks2){
			if(!strcmp(x[indeks2].prezime,x[i].prezime)){
				indeks2=indeks2;
			}else
			indeks2=i;
			
		}
	}
	max3=prosjeci[0];
	indeks3=0;
	for(i=0;i<vel;i++){
		if(i!=indeks1&&i!=indeks2&&max3<prosjeci[i]){
			max3=prosjeci[i];
			indeks3=i;
		}
		else if(i!=indeks1&&i!=indeks2){
			max3=prosjeci[i];
			indeks3=i;
		}
	}

		for(i=0;i<vel;i++){
		if(max3==prosjeci[i]&&i!=indeks1&&i!=indeks2&&i!=indeks3){
 if((strcmp(x[indeks3].prezime,x[i].prezime))==1){
indeks3=indeks3;
		}else if((strcmp(x[indeks3].prezime,x[i].prezime))==0)
		{
			if((strcmp(x[indeks3].ime,x[i].ime))==1){
				indeks3=i;
			}else if((strcmp(x[indeks3].ime,x[i].ime))==-1){
				indeks3=i;
			}
			else {indeks3=i;
}		
			
		}
	}
	
}
	if(vel==0){
		return vel;
	}

	if(indeks1!=indeks2&&indeks1!=indeks3&&indeks2!=indeks3){
		printf("%s %s\n",x[indeks1].prezime,x[indeks1].ime);
printf("%s %s\n",x[indeks2].prezime,x[indeks2].ime);
printf("%s %s\n",x[indeks3].prezime,x[indeks3].ime);}
else if(indeks1!=indeks2){
		printf("%s %s\n",x[indeks1].prezime,x[indeks1].ime);
printf("%s %s\n",x[indeks2].prezime,x[indeks2].ime);
}
else 	printf("%s %s\n",x[indeks1].prezime,x[indeks1].ime);

		
	

	return vel;

}
int main()
{

    
	return 0;
}
