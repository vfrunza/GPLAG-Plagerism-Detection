#include <stdio.h>
#include <math.h>
#include <string.h>
#define eps 0.0000001

struct Student {
    char ime[20],prezime[20];
    int ocjene[50];
    int br_ocjena;
};
int genijalci(struct Student studenti[],int vel, float pr){
    int i,j, maxi;
    float prosjek[100]={0};
    float suma=0;
    for(i=0; i<vel; i++){
        suma=0;
        if(studenti[i].br_ocjena==0) prosjek[i]=0;
        else{
            for(j=0;j<studenti[i].br_ocjena;j++){
                suma+=studenti[i].ocjene[j];
                if(studenti[i].ocjene[j]==5) break;
            }
            if(j==studenti[i].br_ocjena) prosjek[i]=suma/studenti[i].br_ocjena;
            else prosjek[i]=5.0;
        }
    }
    for(i=0;i<vel;i++){
        if(prosjek[i]<pr){
            /*printf("%f", prosjek[i]);*/
            for(j=i;j<vel-1;j++){
                studenti[j]=studenti[j+1];
                prosjek[j]=prosjek[j+1];
            }
            vel--;
            i--;
        }
    }
    for(i=0; i<3; i++){
        maxi=0;
        for(j=0;j<vel;j++)
            if(prosjek[j]>prosjek[maxi] || (fabs(prosjek[j]-prosjek[maxi])<eps && (strcmp(studenti[j].prezime,studenti[maxi].prezime)<0 ||  strcmp(studenti[j].ime,studenti[maxi].ime)<0))) maxi=j;
        if(prosjek[maxi]>=pr) printf ("%s %s\n", studenti[maxi].prezime, studenti[maxi].ime);
        else break;
        prosjek[maxi]=5;
    }
    return vel;
}
int main(){
    struct Student studenti[3] = {
    { "Beba", "Bebic", {}, 0},
	{ "Mujo", "Mujic", { 7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7}, 29}, 
	{ "Fata", "Fatic", { 7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,6}, 29}, 
    };
    
    genijalci(studenti, 3, 7);

return 0;
}

