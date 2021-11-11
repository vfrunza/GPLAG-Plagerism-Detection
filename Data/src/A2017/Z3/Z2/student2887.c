#include <stdio.h>
#include <math.h>
void zaokruzi1(float niz[],int vel){
	float broj;
	int i,cifra,broj1,br=0,br1=0;
	for(i=0;i<vel;i++){
		br=0;
		if(niz[i]<0){
			niz[i]=fabs(niz[i]);
			br1++;
		}
		do{
			niz[i]=niz[i]*10;
			broj=niz[i] - (int) niz[i];
		    br++;
		}while(broj> 1e-6);
		broj1=fabs((int) niz[i]);
	if(br>1){
	do{
		br--;
		cifra=broj1%10;
		broj1=broj1/10;
		if(br==1 && cifra>=5 ){
			broj1+=1;
		}
		
	}while(br!=1);
	}if(br1==1){
	niz[i]=(broj1/10.)*(-1);
	br1=0;
	}else{
		niz[i]=broj1/10.;
	}
}
}
void preslozi(float niz[],int vel,int k){

	int broj,cifra,i,j,z,s,l,br1,p=0;
	int suma=0;
	float broj1;
	float niz1[100];
    zaokruzi1(niz,vel);
	for(i=0;i<vel;i++){
		suma=0;
		if((fabs(niz[i])-fabs((int) niz[i]))>1e-6){
			broj=(fabs(niz[i]))*10;
		}
		
		do{
			cifra=broj%10;
			broj=broj/10;
			suma=suma+cifra;
		}while(broj!=0);
		//ako je suma manja od k stavimo element te sume u pomocni niz
		if(suma<k){
			broj1=niz[i];
			for(l=p;l<p+1;l++){
				niz1[l]=broj1;
			}
			p++;
			br1=p;
			//uzbacujemo element iz pocetnog niza
			for(j=i;j<vel-1;j++){
				niz[j]=niz[j+1];
			}
			vel--;
			i--;
		}
		
	}
	//izbacene elemente vracamo u niz od posljednjeg elementa transformisanog niza
	for(i=vel;i<=vel+br1;i++){
		for(z=0;z<p;z++){
			niz[i]=niz1[z];
			for(s=z;s<p;s++){
				niz1[s]=niz1[s+1];
			}
			p--;
			z--;
			break;
		}
		
	}
	
}
int main() {
	int i,k;
	float niz[]={3.2, -4.301, -123.199, 1.1, 0.9};
	zaokruzi1(niz,5);
	for(i=0;i<5;i++){
		printf("%g ",niz[i]);
	}
	
	printf("\nUnesite k: ");
	scanf("%d",&k);
	preslozi(niz,5,k);
	for(i=0;i<5;i++){
		printf("%g\n",niz[i]);
	}
	return 0;
}
