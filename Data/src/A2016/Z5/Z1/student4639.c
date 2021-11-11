#include <stdio.h>
struct Student {
	char ime[20],prezime[20];
	int ocjene[50];
	int br_ocjena;
};
float prosj(int *ocj,int brocj){
	int suma=0,i;
	for(i=0;i<brocj;i++){
		if(ocj[i]==5) return 5;
		suma=suma+ocj[i];
	}
	if (suma==0) return 5;
	return (float)suma/brocj;
}
int leks(char*i1,char*p1,char*i2,char*p2){
	while(*p1!=0 && *p2!=0){
		if(*p1<*p2) return 1;
		if(*p1>*p2) return 2;
		p1++;
		p2++;
	}
	if(*p1!=0) return 2;
	if(*p2!=0) return 1;
	while(*i1!=0 && *i2!=0){
		if(*i1<*i2) return 1;
		if(*i1>*i2) return 2;
		i1++;
		i2++;
	}
	if(*i1!=0) return 2;
	if(*i2!=0) return 1;
	return 0;
}
int genijalci(struct Student *niz, int velicina, float prosjek){
	int veci,i,j,max1=0,max2=0,max3=0;
	float t,p1=0,p2=0,p3=0;
	for(i=0;i<velicina;i++){
		if(prosjek>prosj(niz[i].ocjene,niz[i].br_ocjena)){
			for (j=i;j<velicina-1;j++){
				niz[j]=niz[j+1];
			}
			i--;
			velicina--;
		}
	}
	for(i=0;i<velicina;i++){
		t=(prosj(niz[i].ocjene,niz[i].br_ocjena));
		if(t>p1){
			p3=p2;
			max3=max2;
			p2=p1;
			max2=max1;
			p1=t;
			max1=i;
		}
		else if(t==p1){
			veci=leks(niz[i].ime,niz[i].prezime,niz[max1].ime,niz[max1].prezime);
			if(veci==1){
				p3=p2;
				max3=max2;
				p2=p1;
				max2=max1;
				p1=t;
				max1=i;
			}
			else if(veci==2){
				veci=leks(niz[i].ime,niz[i].prezime,niz[max2].ime,niz[max2].prezime);
				if(veci==1){
					p3=p2;
					max3=max2;
					p2=t;
					max2=i;
				}
				else if(veci==2){
					veci=leks(niz[i].ime,niz[i].prezime,niz[max3].ime,niz[max3].prezime);
					if(veci==1 || veci==0){	
						p3=t;
						max3=i;
					}
				}	
			}
			else if(veci==0){
				p3=p2;
				max3=max2;
				p2=t;
				max2=i;
			}
		}
		else if(t>p2){
			p3=p2;
			max3=max2;
			p2=t;
			max2=i;
		}
		else if(t==p2){
			veci=leks(niz[i].ime,niz[i].prezime,niz[max2].ime,niz[max2].prezime);
			if(veci==1){
				p3=p2;
				max3=max2;
				p2=t;
				max2=i;
			}
			else if(veci==2){
				veci=leks(niz[i].ime,niz[i].prezime,niz[max3].ime,niz[max3].prezime);
				if(veci==1){
					p3=t;
					max3=i;
				}
			}
			else if(veci==0){
				p3=t;
				max3=i;
			}
		}
		else if(t>p3){
			p3=t;
			max3=i;
		}
		else if(t==p3){
			veci=leks(niz[i].ime,niz[i].prezime,niz[max3].ime,niz[max3].prezime);
			if(veci==1){
				p3=t;
				max3=i;
			}
		}
	}
	if(p1>0) printf("\n%s %s",niz[max1].prezime,niz[max1].ime);
	if(p2>0) printf("\n%s %s",niz[max2].prezime,niz[max2].ime);
	if(p3>0) printf("\n%s %s",niz[max3].prezime,niz[max3].ime);	
	return velicina;
}
int main() {
	struct Student studenti[4] ={
	{ "Mujo", "Mujic", { 7,7,7,7,8}, 5}, 
	{ "Beba", "Bebic", { 6,6,6,6,6}, 5},
	{ "Mujo", "Mujic", { 7,7,7,7,8}, 5}, 
	{ "Fata", "Fatic", { 7,7,7,8,8}, 5},
};
genijalci(studenti, 4, 6.5);
	return 0;
}
