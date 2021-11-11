#include <stdio.h>
#include <string.h>

int leksikon(char *p,char *q){
	
	while(*p != '\0'){
		
		if(*p > *q)return 1;
		if(*p < *q)return 0;
		if(*q == '\0')return 1;
		p++;
	}	
	if(*p == '\0' && *q!='\0')return 0;
	if(*p =='\0' && *q == '\0')return 1;
}
void intcopy(int *p, int *q,int vel){
	int i = 0;
	
	while(i<vel){
		*p = *q;
		p++;
		q++;
		i++;
	}
}

struct Student{
	char ime[20];
	char prezime[20];
	int ocjene[50];
	int br_ocjena;
	
};

int genijalci(struct Student studenti[],int vel,double prosjek){
	
	
	int i;
	int j,k;
	double prosjek1 = 0, suma=0;
	double prosjeci[10000] = {0};
	int ind1 = -1,ind2 = -1,ind3 = -1;
	
	
	for(i=0;i<vel;i++){
	
		prosjek1 = 0;
		suma = 0;
		
		if(studenti[i].br_ocjena == 0){
			prosjek1 = 5.0;
			prosjeci[i] = prosjek1;
			
		}else {
			
			for(j=0;j<studenti[i].br_ocjena;j++){
				if(studenti[i].ocjene[j] == 5){
					prosjek1 = 5.0;
					prosjeci[i] = prosjek1;
					
					break;
				}else{
					suma += studenti[i].ocjene[j];
				}
			}
			
			if(suma!=0 && prosjek1!=5.0){
				prosjek1 = (double)suma/studenti[i].br_ocjena;
				prosjeci[i] = prosjek1;
				
			}
			
		}
		
			//izbacivanje!
			if(prosjek1< prosjek){
				for(k=i;k<vel-1;k++){
					studenti[k] = studenti[k+1];
				//	prosjeci[k] = prosjeci[k+1];
				}
				
				vel--;
				i--;
			}
		
		
	}

	i = 0;
	double max = 0;
	for(i=0;i<vel;i++){
		
		if(i==0){
			max = prosjeci[i];
			ind1 = i;
		}
		
		if(prosjeci[i] > max){
			max = prosjeci[i];
			ind1 = i;
		}else if(prosjeci[i] == max){
			if(strcmp(studenti[i].prezime,studenti[ind1].prezime) == 0){
				
				if(strcmp(studenti[i].ime,studenti[ind1].ime) <0){
					ind1 = i;
				}
			}else if(strcmp(studenti[i].prezime,studenti[ind1].prezime) < 0){
				ind1 = i;
			}
		}
	}
	
	max = 0;
	int flag = 1;
	for(i=0;i<vel;i++){
		
		if(i==ind1){
			continue;
		}
		if(flag == 1){
			max = prosjeci[i];
			ind2 = i;
			flag = 0;
		}
		
		if(prosjeci[i] > max){
			max = prosjeci[i];
			ind2 = i;
		}else if(prosjeci[i] == max){
			if(strcmp(studenti[i].prezime,studenti[ind2].prezime) == 0){
				
				if(strcmp(studenti[i].ime,studenti[ind2].ime) <0){
					ind2 = i;
				}
			}else if(strcmp(studenti[i].prezime,studenti[ind2].prezime) < 0){
				ind2 = i;
			}
		}
	}
	
	
	max = 0;
	flag = 1;
	for(i=0;i<vel;i++){
		
		if(i==ind1){
			continue;
		}
		if(i==ind2){
			continue;
		}
		
		if(flag == 1){
			max = prosjeci[i];
			ind3 = i;
			flag = 0;
		}
		
		if(prosjeci[i] > max){
			max = prosjeci[i];
			ind3 = i;
		}else if(prosjeci[i] == max){
			if(strcmp(studenti[i].prezime,studenti[ind3].prezime) == 0){
				
				if(strcmp(studenti[i].ime,studenti[ind3].ime) <0){
					ind3 = i;
				}
			}else if(strcmp(studenti[i].prezime,studenti[ind3].prezime) < 0){
				ind3 = i;
			}
		}
	}
	
	if(ind1 != -1)printf("%s %s\n",studenti[ind1].prezime,studenti[ind1].ime);
	if(ind2 != -1)printf("%s %s\n",studenti[ind2].prezime,studenti[ind2].ime);
	if(ind3 != -1)printf("%s %s\n",studenti[ind3].prezime,studenti[ind3].ime);
	
	
	return vel;
	
}


int main() {
	
	struct Student studenti[] = {

            {"Meho", "Antic", {8, 9}, 2},
            {"Meho", "Aehic", {10, 8}, 2},
            {"Meho", "Cehic", {10, 9, 8, 7, 6}, 5},
            {"Meho", "Dehic", {6, 9}, 2},
            {"Meho", "Zehic", {10}, 1},
            {"Meho", "Oehic", {10, 9, 9, 9}, 4}
        };
        
        int vel = sizeof studenti / sizeof studenti[0], i;
        
        vel = genijalci(studenti, vel, 9.);
        printf("Vel: %d\n", vel);
        
    

	return 0;
}


