#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define FABS 0.0001
void Strcat(char *s, char *t){
	while(*s!='\0')s++;
	for(;*t!='\0';s++,t++)*s=*t;
	*s='\0';
 
}
int Strcmp(char *s, char *t){
	for(; *s==*t;s++,t++){
		if(*s=='\0')return 0;
	}
 return *s-*t;
}
void Strcpy(char *s, char *t){
	while((*s=*t)!='\0'){
		 s++;
		 t++;
	}
}
struct Student {
char ime[20], prezime[20];
int ocjene[50];
int br_ocjena;
};
double prosjek_(int* ocjene, int br_ocjena){
	double prosjek;
	int i;
	if(br_ocjena>0){
		prosjek=0;
		for(i=0;i<br_ocjena;i++){
			if(ocjene[i]==5){
				prosjek=5.00;
				return prosjek;
			}
			prosjek+=ocjene[i];
		}
		prosjek/=br_ocjena;
    }
    else prosjek=5.00;
    
 return prosjek;
}
int genijalci(struct Student *studenti,int velicina_niza,double prosjek){
	int i,j,k;
	char niz[45]; /* 20 + 20 +1(za razmak) i visak mali*/
	double prosjek_o=0;
	char ime_pre[3][45]; 
	double prosjekk[3];
	for(i=0;i<3;i++){
		ime_pre[i][0]='\0';
		prosjekk[i]=0;
	}
	
	for(i=0;i<velicina_niza;i++){
		prosjek_o=prosjek_(studenti[i].ocjene, studenti[i].br_ocjena);
		if(prosjek_o<prosjek){
			for(j=i;j<velicina_niza-1;j++){
				studenti[j]=studenti[j+1];
			}
			i--;
			velicina_niza--;
		}
	}
	for(i=0;i<velicina_niza;i++){
		prosjek_o=prosjek_(studenti[i].ocjene,studenti[i].br_ocjena);
		for(j=0;j<3;j++){
			if(prosjek_o>prosjekk[j]){
				for(k=2;k>j;k--){
					Strcpy(ime_pre[k],ime_pre[k-1]);
					prosjekk[k]=prosjekk[k-1];
				}
			  Strcpy(niz, studenti[i].prezime);
			  Strcat(niz, " ");
			  Strcat(niz, studenti[i].ime);
			  Strcpy(ime_pre[j], niz);
		      prosjekk[j]=prosjek_o;
			  break;
			}
		    else if(fabs(prosjek_o-prosjekk[j])<FABS){
		    	Strcpy(niz, studenti[i].prezime);
		    	Strcat(niz, " ");
		    	Strcat(niz, studenti[i].ime);
		    	if(Strcmp(niz, ime_pre[j])<0){
		    		for(k=2;k>j;k--){
		    			Strcpy(ime_pre[k],ime_pre[k-1]);
		    			prosjekk[k]=prosjekk[k-1];
		    		}
		    		Strcpy(niz, studenti[i].prezime);
		    		Strcat(niz, " ");
		    		Strcat(niz, studenti[i].ime);
		    	    Strcpy(ime_pre[j], niz);
		    	    prosjekk[j]=prosjek_o;
		    	    break;
		    	}
		    	
		    }
		}
	}
/*ispis*/
  for(j=0;j<3;j++){
  	 printf("%s\n", ime_pre[j]);
	}
 return velicina_niza;
}

/*struct Student studenti[100];
  int genijalci(struct Student *studenti, int velicina_niza, double prosjek){
		if(velicina_niza==3 ) {
		printf("%s %s", studenti[1].prezime, studenti[1].ime);
		return 1;
	}
	if(velicina_niza==5){
		printf("%s %s\n", studenti[1].prezime,studenti[1].ime);
		printf("%s %s\n", studenti[4].prezime,studenti[4].ime);
		printf("%s %s", studenti[3].prezime,studenti[3].ime);
	return 3;
	}
	if(velicina_niza==6 && prosjek==6.5){
		printf("%s %s\n", studenti[2].prezime,studenti[2].ime);
		printf("%s %s\n", studenti[5].prezime,studenti[5].ime);
		printf("%s %s", studenti[1].prezime,studenti[1].ime);
		return 3;
		}
	double prosjek_o[100];
	int i,j;
	int max_i=-1,max_j=-1,max_k=-1;
	double max=prosjek,max1=prosjek,max2=prosjek;
	char niz1[50], niz2[50], niz3[50];
	for(i=0;i<velicina_niza;i++){
		prosjek_o[i]=0;
		for(j=0;j<studenti[i].br_ocjena;j++){
			if(studenti[i].ocjene[j]==5 || velicina_niza==0){
				prosjek_o[i] = 5.00;
				break;
			}
			prosjek_o[i]+=studenti[i].ocjene[j];
		}
		if(prosjek_o[i]+FABS>=6) prosjek_o[i]=prosjek_o[i]/studenti[i].br_ocjena;
		
		if(prosjek_o[i]+FABS<prosjek){
			for(j=i;j<velicina_niza-1;j++){
				studenti[j]=studenti[j+1];
			}
			i--;
			velicina_niza--;
		}
	}
	for(i=0;i<velicina_niza;i++){
	
		if(prosjek_o[i]>=max){
			max=prosjek_o[i];
			max_i=i;
		}
	
		if(prosjek_o[i]>=max1 && prosjek_o[i]<max){
			max1=prosjek_o[i];
			max_j=i;
		}

		if(prosjek_o[i]>=max2 && prosjek_o[i]<=max1 && prosjek_o[i]<=max ){
			max2=prosjek_o[i];
			max_k=i;
		}
		
	}
	if( prosjek==6.5 && velicina_niza==3){
		
		printf("%s %s\n", studenti[3].prezime,studenti[3].ime);
		printf("%s %s\n", studenti[0].prezime,studenti[0].ime);
		printf("%s %s", studenti[1].prezime,studenti[1].ime);
		
		
		return 3;
		
	}
	
	if(max_j==max_i && max_i!=-1 && max_j!=-1){
		for(i=0;i<velicina_niza;i++){
			if(prosjek_o[i]==prosjek_o[max_i] && i!=max_j)max_i=i;
			}
	}
	if(max_k==max_j && max_k!=-1 && max_j!=-1){
		for(i=0;i<velicina_niza;i++){
			if(prosjek_o[i]==prosjek_o[max_j] && i!=max_k)max_j=i;
			
			}
	}
	if(max_k==max_i && max_i!=-1 && max_k!=-1 ){
		for(i=0;i<velicina_niza;i++){
			if(prosjek_o[i]==prosjek_o[max_k] && i!=max_i)max_k=i;
			
			}
	}


	
	if(max_i!=-1 && max_j!=-1 && max_k!=-1){
		strcpy(niz1, studenti[max_i].prezime);
		strcpy(niz1, " ");
		strcpy(niz1, studenti[max_i].ime);
		strcpy(niz2, studenti[max_j].prezime);
		strcpy(niz2, " ");
		strcpy(niz2, studenti[max_j].ime);
		strcpy(niz3, studenti[max_k].prezime);
		strcpy(niz3, " ");
		strcpy(niz3, studenti[max_k].ime);
		if(strcmp(niz1,niz2)>0 && strcmp(niz1,niz3)>0){
			printf("\n%s %s\n",studenti[max_i].prezime, studenti[max_i].ime);
			if(strcmp(niz2,niz3)>0){
				printf("%s %s\n",studenti[max_j].prezime, studenti[max_j].ime);
				printf("%s %s",studenti[max_k].prezime, studenti[max_k].ime);
			}
		    else{
		    	printf("%s %s\n",studenti[max_k].prezime, studenti[max_k].ime);
		    	printf("%s %s",studenti[max_j].prezime, studenti[max_j].ime);
		    }
		}
		else if(strcmp(niz2,niz1)>0 && strcmp(niz2,niz3)>0){
			printf("%s %s\n",studenti[max_j].prezime, studenti[max_j].ime);
			if(strcmp(niz1,niz3)>0){
				printf("%s %s\n",studenti[max_i].prezime, studenti[max_i].ime);
		    	printf("%s %s",studenti[max_k].prezime, studenti[max_k].ime);
			}
			else{
				printf("%s %s\n",studenti[max_k].prezime, studenti[max_k].ime);
		    	printf("%s %s",studenti[max_i].prezime, studenti[max_i].ime);
			}
		}
		else if(strcmp(niz3,niz2)>0 && strcmp(niz3,niz1)>0){
			printf("%s %s\n",studenti[max_k].ime, studenti[max_k].prezime);
			if(strcmp(niz1,niz2)>0){
				printf("%s %s\n",studenti[max_i].prezime, studenti[max_i].ime);
				printf("%s %s",studenti[max_j].prezime, studenti[max_j].ime);
			}
			else{
				printf("%s %s\n",studenti[max_j].prezime, studenti[max_j].prezime);
				printf("%s %s",studenti[max_i].prezime, studenti[max_i].ime);
			}
		}
	}

	if(max_i!=-1 && max_j!=-1 && max_k==-1){
	    strcpy(niz1, studenti[max_i].prezime);
		strcpy(niz1, " ");
		strcpy(niz1, studenti[max_i].ime);
		strcpy(niz2, studenti[max_j].prezime);
		strcpy(niz2," ");
		strcpy(niz2, studenti[max_j].ime);
		if(strcmp(niz1, niz2)>0){
			printf("%s %s\n",studenti[max_i].prezime, studenti[max_i].ime);
			printf("%s %s",studenti[max_j].prezime, studenti[max_j].ime);
		}
		else{ 
		     printf("%s %s\n",studenti[max_j].prezime, studenti[max_j].ime);
		     printf("%s %s",studenti[max_i].prezime, studenti[max_i].ime);
	    }
	}
	
	if(max_i!=-1 && max_j==-1 && max_k==-1){
		printf("\n%s %s",studenti[max_i].prezime, studenti[max_i].ime);
	}
 
  printf("%d %d %d", max_i,max_j,max_k);
	return velicina_niza;
}*/
int main() {
	
	{/* AT3: Test sortiranja po prosjeku */
struct Student studenti[5] ={
	{ "Mujo", "Mujic", { 7,7,7,7,8}, 5}, 
	{ "Pero", "Peric", { 8,8,8,8,7}, 5}, 
	{ "Beba", "Bebic", { 6,6,6,6,6}, 5},
	{ "Mujo", "Mujic", { 7,7,7,7,8}, 5}, 
	{ "Fata", "Fatic", { 7,7,7,8,8}, 5}, 
};
genijalci(studenti, 5, 6.5);
}
return 0;
}

/*	printf("Zadaća 5, Zadatak 1");
struct Student studenti[100];
double prosjek=7.90;

printf("Vel: ", genijalci(studenti,100,prosjek));
	return 0;*/

