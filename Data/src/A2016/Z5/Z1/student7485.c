#include <stdio.h>
#include <string.h>
#define epsilon 0.0001

void unesi (char *niz,int vel){
    int i=0;
    char znak=getchar();
    if (znak=='\n');
    znak=getchar();
    while(i<vel-1 && znak!='\0'){
        niz[i++]=znak;
        znak=getchar();
    }

    niz[i]='\0';
}
struct Student {
    char ime[20], prezime[20];
    int ocjene[50];
    int br_ocjena;
};
int genijalci(struct Student *studenti, int vel, float prosjek){
    int i,j,zbir_ocjena=0,logicka_varijabla,studentski_broj[3]={0};
    float prosjek_trenutnog_studenta=5.0,najbolji[3]={0};
    for (i=0;i<vel;i++){
        //trazenje prosjeka
        zbir_ocjena=0;
        logicka_varijabla=1;
        if(studenti[i].br_ocjena==0){
            prosjek_trenutnog_studenta=5.0;
            logicka_varijabla=0;
        }
        for (j=0;j<studenti[i].br_ocjena;j++){
            if (studenti[i].ocjene[j]==5){
                logicka_varijabla=0;
                prosjek_trenutnog_studenta=5.0;
                break;
            }
            else zbir_ocjena+=studenti[i].ocjene[j];
        }
        if(logicka_varijabla)
        prosjek_trenutnog_studenta=(float)zbir_ocjena/studenti[i].br_ocjena;
        //izbacivanje
        if (prosjek_trenutnog_studenta<prosjek){
            j=i;
            while(j<vel-1){
                studenti[j]=studenti[j+1];
                j++;
            }
            vel--;    
            i--;
            continue;
        }
        //izdvajanje najboljih studenata
    if(prosjek_trenutnog_studenta>najbolji[0] || ((prosjek_trenutnog_studenta==najbolji[0] && strcmp(studenti[i].prezime,studenti[studentski_broj[0]].prezime)<0)||
    (prosjek_trenutnog_studenta==najbolji[0] && strcmp(studenti[i].prezime,studenti[studentski_broj[0]].prezime)==0 && strcmp(studenti[i].ime,studenti[studentski_broj[0]].ime)<0))){
          najbolji[2]=najbolji[1];
          najbolji[1]=najbolji[0];
          najbolji[0]=prosjek_trenutnog_studenta;
          studentski_broj[2]=studentski_broj[1];
          studentski_broj[1]=studentski_broj[0];
          studentski_broj[0]=i;
      }
      else if(prosjek_trenutnog_studenta>najbolji[1] || ((prosjek_trenutnog_studenta==najbolji[1] && strcmp(studenti[i].prezime,studenti[studentski_broj[1]].prezime)<0)|| 
      (prosjek_trenutnog_studenta==najbolji[1] && strcmp(studenti[i].prezime,studenti[studentski_broj[1]].prezime)==0 && strcmp(studenti[i].ime,studenti[studentski_broj[1]].ime)<0))){
          najbolji[2]=najbolji[1];
          najbolji[1]=prosjek_trenutnog_studenta;
          studentski_broj[2]=studentski_broj[1];
          studentski_broj[1]=i;
      }
     else if(prosjek_trenutnog_studenta>najbolji[2] || ((prosjek_trenutnog_studenta==najbolji[2] && strcmp(studenti[i].prezime,studenti[studentski_broj[2]].prezime)<0)|| 
     (prosjek_trenutnog_studenta==najbolji[2] && strcmp(studenti[i].prezime,studenti[studentski_broj[2]].prezime)==0 && strcmp(studenti[i].ime,studenti[studentski_broj[2]].ime)<0))){
    najbolji[2]=prosjek_trenutnog_studenta;
    studentski_broj[2]=i;
      }
    }
    //ispis potrabnih studenata
    if(najbolji[0]!=0) printf("%s %s\n",studenti[studentski_broj[0]].prezime,studenti[studentski_broj[0]].ime);
    if(najbolji[1]!=0) printf("%s %s\n",studenti[studentski_broj[1]].prezime,studenti[studentski_broj[1]].ime);
    if(najbolji[2]!=0) printf("%s %s\n",studenti[studentski_broj[2]].prezime,studenti[studentski_broj[2]].ime);
    return vel;
}

int main(){
    struct Student studenti[100];
    int i=0,prekid;
    do{
        printf("Unesite ime i prezime studenta %d: ",i+1);
        unesi(studenti[i].ime,20);
        unesi(studenti[i].prezime,20);
        i++;
        printf("Ako ste zavrsili sa unosom studenata pritisnite 0, ako ne onda 1.");
        scanf("%d",&prekid);
    }while(i<100 && prekid);
    return 0;
}