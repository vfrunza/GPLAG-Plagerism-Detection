#include <stdio.h>

struct Student {
	char ime[20];
	char prezime[20];
	int ocjene[50];
	int br_ocjena;
};

int genijalci (struct Student *studenti, int vel, float maxi_prosjek){
	int i, j, k, provjera=0;
	
	/*prvo izbacujemo one sa ocjenom 5*/
	for(i=0; i<vel; i++){
		for(j=0; j<studenti[i].br_ocjena; j++){
			if(studenti[i].ocjene[j]==5){
				k=i;
				for(k=i; k<vel-1; k++) *(studenti+k)=*(studenti+k+1);
				vel--;
				i--;
				j=0;
				provjera=1;
				break;
			}
			if(provjera==1) break;
	} j=0;
	/*studenti koji nemaju ocjena*/
	if(studenti[i].br_ocjena==0 && provjera!=1){
			k=i;
				for(k=i; k<vel-1; k++) *(studenti+k)=*(studenti+k+1);
				vel--;
				i--;
				j=0;
				break;
		
	} 
	provjera=0;
}
float p1=0, p2=0, p3=0, p4=0, p;
int index1=0, index2=0, index3=0, index4=0, suma_ocj=0;
i=0;

/*racunamo prosjeke studenata, i odredjumo top 3 */
for(i=0; i<vel; i++){
	for(j=0; j<studenti[i].br_ocjena; j++) suma_ocj+=studenti[i].ocjene[j];
	p=suma_ocj/(float)studenti[i].br_ocjena;
	if(p<maxi_prosjek){
			k=i;
				for(k=i; k<vel-1; k++) *(studenti+k)=*(studenti+k+1);
				vel--;
				i--;
				j=0;
				
	}
	else if(p>=p1){
		p4=p3;
		p3=p2;
		p2=p1;
		p1=p;
		index4=index3;
		index3=index2;
		index2=index1;
		index1=i;
	}
	else if(p>=p2){
		p4=p3;
		p3=p2;
		p2=p;
		index4=index3;
		index3=index2;
		index2=i;
	}
	else if(p>=p3){
		p4=p3;
		p3=p;
		index4=index3;
		index3=i;
	}
	
	suma_ocj=0;
}
/*p4 i index4 je rezervna varijabla ukoliko na 3. mejstu se nalaze 2 osobe sa istim prosjekom, biramo po leksikograf.*/
int h=0;
	for(h; h<4; h++){
	if(studenti[index4].ime[h]<studenti[index3].ime[h]){
		struct Student temp;
		temp=studenti[index3];
		studenti[index3]=studenti[index4];
		studenti[index4]=temp;
	}}


if(p2==p3){
/*	int gotovo=0;*/
	
/*	for(h=0; h<5; h++){
		if(studenti[index3].prezime[h]<studenti[index2].prezime[h]){
				struct Student temp;
		temp=studenti[index2];
		studenti[index2]=studenti[index3];
		studenti[index3]=temp;
		gotovo=1;
		h=5;
		
		}
	}
if(gotovo==1) h=4;*/
	for(h=0; h<4; h++){
	if(studenti[index3].ime[h]<studenti[index2].ime[h]){
		struct Student temp;
		temp=studenti[index2];
		studenti[index2]=studenti[index3];
		studenti[index3]=temp;
	}}
}

if(p1>=maxi_prosjek) printf("%s %s\n", studenti[index1].prezime, studenti[index1].ime);
if(p2>=maxi_prosjek) printf("%s %s\n", studenti[index2].prezime, studenti[index2].ime);
if(p3>=maxi_prosjek) printf("%s %s\n", studenti[index3].prezime, studenti[index3].ime);


return vel;
}




int main() {
	printf("Zadaća 5, Zadatak 1");
	struct Student studenti[] = {

            {"Meho", "Behic", {10, 9}, 2},
            {"Meho", "Aehic", {10, 8}, 2},
            {"Meho", "Cehic", {10, 9, 8, 7, 6}, 5},
            {"Meho", "Dehic", {6, 9}, 2},
            {"Meho", "Zehic", {10}, 1},
            {"Meho", "Oehic", {10, 9, 9, 9}, 4}
        };
        int vel = sizeof studenti / sizeof studenti[0], i;
        
        vel = genijalci(studenti, vel, 9.);
        
        printf("Vel: %dStudenti:", vel);
        
        for (i = 0; i < vel; ++i)
            printf ("%s %s", studenti[i].prezime, studenti[i].ime);
    

	return 0;
}
