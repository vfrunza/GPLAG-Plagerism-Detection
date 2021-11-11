#include <stdio.h>
#include <stdlib.h>


struct Student{
	char ime[20],prezime[20];
	int ocjene[50];
	int br_ocjena;
};

int komper(char pok1[], char pok2[]){
	int i=0;
	/*while(pok1[i]!='\0'){
		
		if(pok2[i]=='\0'){return 1;}
		if(pok1[i]==pok2[i]){
			i++;
		
		if(pok1[i]<pok2[i]){return -1;}
		if(pok1[i]>pok2[i]){return 1;}
		}
		else{
			if(pok2[i]=='\0'){return 1;}
			if(pok1[i]<pok2[i]){return -1;}
			if(pok1[i]>pok2[i]){return 1;}
		}
		
		i++;
	}*/
	while(*pok1!='\0' && *pok2!='\0')
	{
		if(*pok1<*pok2) return -1;
		if(*pok1>*pok2) return 1;
		pok1++;
		pok2++;
	}
	return 0;
}

int genijalci(struct Student *niz, int vel, float prosjek){
	int i;
	//int a=0,b=0,c=0;
	float max1=0,max2=0,max3=0;
	int brojacizbacenih=0;
	int j;
	int suma=0;
	int velicina=vel;
	int brojpreostalih;
	float prosek=0;
	int brojaca=0,brojacb=0,brojacc=0;

	struct Student niza[100];
	struct Student nizb[100];
	struct Student nizc[100];
	int p=0,q=0,r=0;
	
	for(i=0;i<vel;i++){
	//prosek=5;
	//printf("%d br ocjena  ",niz[i].br_ocjena);
		for(j=0;j<niz[i].br_ocjena;j++){
		if(niz[i].ocjene[j]==5){prosek=5;break;}
		suma=suma+niz[i].ocjene[j];}
	
		if(prosek!=5 || niz[i].br_ocjena!=0) {
		prosek=(float)suma/(float)niz[i].br_ocjena;
		}	
		if(niz[i].br_ocjena==0) {prosek=0; }
	//	printf("%f  %s     ",prosek,niz[i].ime);
		if(prosek<prosjek){
			for(j=i;j<vel-1;j++){
				niz[j]=niz[j+1];
			}
			vel--;
			i--;
		}
		suma=0;

	}
	prosek=0;
	brojpreostalih=vel;
	
	for(i=0;i<vel;i++){
		for(j=0;j<niz[i].br_ocjena;j++){
			suma=suma+niz[i].ocjene[j];}
			prosek=(float) suma/(float) niz[i].br_ocjena;
		
		if(max1<prosek){
			max1=prosek;
			//a=i;
		}
			suma=0;
		}
		
		
	for(i=0;i<vel;i++){
		for(j=0;j<niz[i].br_ocjena;j++){
			suma=suma+niz[i].ocjene[j];}
			prosek=(float) suma/ (float) niz[i].br_ocjena;
			
			if(max2<prosek && prosek<max1){
				max2=prosek;
				//b=i;
			}
			suma=0;
		}
	for(i=0;i<vel;i++){
		for(j=0;j<niz[i].br_ocjena;j++){
			suma=suma+niz[i].ocjene[j];}
			prosek=(float) suma / (float) niz[i].br_ocjena;
			if(max3<prosek && prosek<max2){
				max3=prosek;
				//c=i;
			}
			suma=0;
		}
		
		
	for(i=0;i<vel;i++){
		for(j=0;j<niz[i].br_ocjena;j++){
			suma=suma+niz[i].ocjene[j];}
			prosek=(float)suma/(float)niz[i].br_ocjena;
			
			if(max1==prosek){
				niza[p]=niz[i];
				p++;
				brojaca++;
			//	printf("%d     ",brojaca);
			}
			else if(max2==prosek){
				nizb[q]=niz[i];
				q++;
				brojacb++;
				//printf("%d       ",brojacb);
			}
			else if(max3==prosek){
				nizc[r]=niz[i];
				r++;
				brojacc++;
			}
			suma=0;
		}
/*	for(i=0;i<brojacb;i++){
		printf("%s   %s\n",nizb[i].ime,nizb[i].prezime);
	}	
	printf("\n");*/	
	char *pok1;
	char *pok2;
	struct Student temp;
	int c;
	for(i=0;i<brojaca;i++){
		for(j=i+1;j<brojaca;j++){
			pok1=niza[i].prezime;
			pok2=niza[j].prezime;

			c=komper(pok1,pok2);
				if(c==1){
				
					temp=niza[i];
					niza[i]=niza[j];
					niza[j]=temp;
					
				}
			}
		c=0;
		}
		int v=0;
	
	for(i=0;i<brojacb;i++){
		for(j=i+1;j<brojacb;j++){
			pok1=nizb[i].prezime;
			pok2=nizb[j].prezime;
			
			v=komper(pok1,pok2);
			if(v==1){	
			
				temp=nizb[i];
				nizb[i]=nizb[j];
				nizb[j]=temp;
			}
		}	
		//for(i=0;i<brojacb;i++)printf("%s   %s\n",nizb[i].ime,nizb[i].prezime);
		v=0;
		
	}

//	printf("%s    %s\n",nizc[i].ime);
	for(i=0;i<brojacc;i++){
		for(j=i+1;j<brojacc;j++){
			pok1=nizc[i].prezime;
			pok2=nizc[j].prezime;
			int k=komper(pok1,pok2);
			if(k==1){
				temp=nizc[i];
				nizc[i]=nizc[j];
				nizc[j]=temp;
			}
		}
	//	printf("%s     %s",nizc[i].prezime,nizc[i].ime);
	}
	
/*	if(brojpreostalih>0) printf("%s %s\n",niza[0].prezime,niza[0].ime);
    if(brojpreostalih>1) printf("%s %s\n",nizb[0].prezime,nizb[0].ime);
    if(brojpreostalih>2) printf("%s %s\n",nizc[0].prezime,nizc[0].ime);*/

	int ispis=0;
/*	for(i=0;i<brojacb;i++){
		printf("%s %s",nizb[i].prezime,nizb[i].ime);
	}*/
	if(brojaca<3) {
		for(i=0;i<brojaca;i++){
		printf("%s %s\n",niza[i].prezime,niza[i].ime); ispis++;
		}
		
	}
	else {
		for(i=0;i<3;i++){
			printf("%s %s\n",niza[i].prezime,niza[i].ime); ispis++;
		}
	}
	int pom=ispis;
	if(brojacb<3-ispis){
		for(i=0;i<brojacb;i++){
			printf("%s %s\n",nizb[i].prezime,nizb[i].ime); ispis++;
		}
	}
	else{
		for(i=0;i<3-pom;i++){
			printf("%s %s\n",nizb[i].prezime,nizb[i].ime); ispis++;
			
		}
	}
	pom=ispis;
	if(brojacc<3-ispis){
		for(i=0;i<brojacc;i++){
			printf("%s %s\n",nizc[i].prezime,nizc[i].ime); ispis++;
		}
	}
	else{
		for(i=0;i<3-pom;i++){
			printf("%s %s\n",nizc[i].prezime,nizc[i].ime);ispis++;
		}
	}
	return vel;
	
}
int main() {
	struct Student studenti[3]={
		{ "Mujo", "Mujic", {7,7,7,7,8}, 5},
		{ "Meho", "Mujic", {7,7,7,7,8}, 5},
		{ "Beba", "Bebic", {10,10,10,10,5},5},
		{ "Mujo", "Mujic", {7,7,7,7,8},5},
		{ "Fata", "Fatic", {7,7,7,7,8},5},
	};
	int c=genijalci(studenti,5,6.5);
	printf("%d",c);
	return 0;
}
