#include <stdio.h>
#include <string.h>
struct Student{
	char ime[20], prezime [20];
	int ocjene[50];
	int br_ocjena;
};

double daj_prosijek(int *ocjene,int br_ocjena){
	int i;
	double suma=0;
	if(br_ocjena==0)
		return 5.0;
	for(i=0;i<br_ocjena;i++){
		if(*(ocjene + i)<6)
			return 5.0;
		suma+=*(ocjene+i);
	}
	return suma/br_ocjena;
	
}

	
        
int genijalci(struct Student niz[500], int velicina, double prosijek){
	int i, max1=0, max2=0, max3=0, j, brojac1=0, brojac2=0, brojac3=0;
	double pr[50000];
	//printf("%d\n", niz[0].ocjene[1]);
	for(i=0;i<velicina;i++){
		pr[i]=daj_prosijek(niz[i].ocjene, niz[i].br_ocjena);
		
		if(pr[i]+0.01<prosijek){
			for(j=i;j<velicina-1;j++)
				niz[j]=niz[j+1];
			velicina--;
			i--;
			
		}
	}
	
	if(velicina>=1){
		for(i=0;i<velicina;i++){
			if(pr[i]==pr[max1]){
				if(strcmp(niz[i].prezime,niz[max1].prezime)<0){
						max1=i;	
						continue;
					}
					if(strcmp(niz[i].prezime,niz[max1].prezime)==0){
						if(strcmp(niz[i].ime,niz[max1].ime)<0){
							max1=i;	
							continue;
						}
					}
			}
			if(pr[i]>pr[max1]){
				max1=i;
			}
		}
		printf("%s %s\n", niz[max1].prezime, niz[max1].ime);
	}
	//nadje najveci clan i ispise ga
	if(velicina>=2){
		for(i=0;i<velicina;i++){
			if(i==0&&i==max1 )max2++;
			if(i==max1) continue ;
			if(pr[i]==pr[max2]){
				if(strcmp(niz[i].prezime,niz[max2].prezime)<0){
					max2=i;	
					continue;
				}
				if(strcmp(niz[i].prezime,niz[max2].prezime)==0){
					if(strcmp(niz[i].ime,niz[max2].ime)<0){
						max2=i;	
						continue;
					}
				}
			}
			if(pr[i]>pr[max2]){
				max2=i;
			}
			
		}
		printf("%s %s\n", niz[max2].prezime, niz[max2].ime);
	}
	//nadje 2. najveci clan i ispise ga
	if(velicina>=3){
		for(i=0;i<velicina;i++){
			if(i==0&&(i==max1|| i==max2)) max3++;
			if(i==max1 || i==max2) continue ;
			if(pr[i]==pr[max3]){
				if(strcmp(niz[i].prezime,niz[max3].prezime)<0){
					max3=i;	
					continue;
				}
				if(strcmp(niz[i].prezime,niz[max3].prezime)==0){
					if(strcmp(niz[i].ime,niz[max3].ime)<0){
						max3=i;	
						continue;
					}
				}
			}
			if(pr[i]>pr[max3]){
				max3=i;
			}
			
		}
		printf("%s %s\n", niz[max3].prezime, niz[max3].ime);
	}
	//nadje 3. najveci clan i ispise ga
	return velicina;
}
int main() {
	struct Student niz[3] = {
	{ "Beba", "Bebic", { 6,6,6,6,6}, 5},
	{ "Mujo", "Mujic", { 7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,8,8}, 29}, 
	{ "Fata", "Fatic", { 7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,8}, 29}, 
	};
    int p=genijalci(niz,3,7.0);
	return 0;
}
