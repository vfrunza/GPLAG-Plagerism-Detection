#include <stdio.h>
#include <string.h>
struct Student{
	char ime[20], prezime[20];
	int ocjene[50];
	int br_ocjena;
};

int genijalci(struct Student s[100],int vel,float prosjek){
	int i,j,t=0,t1=0,brmax[3]={0},k=0,br[100]={0};
	float suma=0,pr[100],max[3]={0},pr1[100],max1=0;
	for(i=0;i<vel;i++){
		if(s[i].ocjene[0]<5 || s[i].ocjene[0]>10){
			pr[i]=5.0;
		}
		else{
			for(j=0;j<s[i].br_ocjena;j++){
				suma=suma+s[i].ocjene[j];
				if(s[i].ocjene[j]==5){
					pr[i]=5.0;
					goto unos;
				}
			}
			pr[i]=suma/s[i].br_ocjena;
		}
		unos:;
		suma=0;
	}
	for(i=0;i<vel;i++){
		if(pr[i]<prosjek){
			for(j=i;j<vel-1;j++){
					s[j]=s[j+1];
					pr[j]=pr[j+1];
			}
			vel--;
			i--;
		}
	}
	for(i=0;i<vel;i++){
		pr1[i]=pr[i];
	}
	for(k=0;k<3;k++){
		for(i=0;i<vel;i++){
			if(pr1[i]>max[k]){
				max[k]=pr1[i];
			}
		}
		for(i=0;i<vel;i++){
			if(pr1[i]==max[k]){
				pr1[i]=0;
			}
		}
	}
	for(k=0;k<3;k++){
		for(i=0;i<vel;i++){
			if(pr[i]==max[k]){
				brmax[k]++;
			}
		}
	}
	for(k=0;k<3;k++){
		if(brmax[k]==1){
			for(i=0;i<vel;i++){
				if(pr[i]==max[k]){
					printf("\n%s %s",s[i].prezime,s[i].ime);
				}
			}
		}
		else if(brmax[k]==2){
			for(i=0;i<vel;i++){
				if(pr[i]==max[k]){
					for(j=i+1;j<vel;j++){
						if(pr[j]==max[k]){
							if((strcmp(s[i].prezime,s[j].prezime)>0)){
								printf("\n%s %s",s[i].prezime,s[i].ime);
							}
							else if((strcmp(s[i].prezime,s[j].prezime)<0)){
								printf("\n%s %s",s[j].prezime,s[j].ime);
							}
							else if((strcmp(s[i].prezime,s[j].prezime))==0){
								if((strcmp(s[i].ime,s[j].ime))>0){
									printf("\n%s %s",s[i].prezime,s[i].ime);
								}
								else if((strcmp(s[i].ime,s[j].ime)<=0)){
									printf("\n%s %s",s[j].prezime,s[j].ime);
								}
							}
						}
					}
				}
			}
		}
		else if(brmax[k]>=3){
			for(i=0;i<vel;i++){
				if(pr[i]==max[k]){
					for(j=i+1;j<vel;j++){
						if(pr[j]==max[k]){
							if((strcmp(s[i].prezime,s[j].prezime)>0)){
								br[i]++;
							}
							else if((strcmp(s[i].prezime,s[j].prezime)<0)){
								br[j]++;
							}
							else if((strcmp(s[i].prezime,s[j].prezime))==0){
								if((strcmp(s[i].ime,s[j].ime))>0){
									br[i]++;
								}
								else if((strcmp(s[i].ime,s[j].ime))<0){
									br[j]++;
								}
								else if((strcmp(s[i].ime,s[j].ime))==0){
									br[i]++;
									br[j]++;
								}
							}
						}
					}
				}
			}
			for(i=0;i<10;i++){
				printf("\n%d\n",br[i]);
			}
			for(i=0;i<vel;i++){
				for(j=0;j<vel;j++){
					if(br[j]>max1 && br[j]!=0){
						max1=br[j];
					}
				}
				for(j=0;j<vel;j++){
					if(br[j]==max1){
						printf("\n%s %s",s[j].prezime,s[j].ime);
						br[j]=0;
					}
				}
				max1=0;
			}
		}
	}
	return vel;
}
int main() {
	int i,j=0,f;
	float prosjek;
	struct Student s[100];
	printf("Unesite prosjek: ");
	scanf("%f",&prosjek);
	for(i=0;i<5;i++){
		printf("Unesite ime: ");
		scanf("%s",&s[i].ime);
		printf("Unesite prezime: ");
		scanf("%s",&s[i].prezime);
		printf("Unesite broj ocjena: ");
		scanf("%d",&s[i].br_ocjena);
		printf("Unesite ocjene: ");
		for(j=0;j<s[i].br_ocjena;j++){
			scanf("%d",&s[i].ocjene[j]);
		}
	}
	f=genijalci(s,10,prosjek);
	printf("Broj studenata nakon izbacivanja je: %d",f);
	return 0;
}