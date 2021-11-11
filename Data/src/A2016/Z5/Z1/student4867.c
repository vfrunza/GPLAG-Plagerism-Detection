#include <stdio.h>
#include <math.h>
#include <string.h>
#define epsilon 0.0001

struct Student{
    char ime[20], prezime[20];
    int ocjene[50];
    int br_ocjena;
};

double prosjekocjena(int ocjene[], int broj_ocjena){
    int suma=0; int i=0;
    double prosjek;
    if(broj_ocjena>0) {
       /*suma ocjena*/
       suma=0;
     /*for(i=0; i<broj_ocjena; i++) {
           
           if(ocjene[i]==5){
               prosjek=5.0; return prosjek;
       }
       suma=suma+ocjene[i];
    }
    */ i=0;
    while(i<broj_ocjena) {
        if(ocjene[i]==5) { prosjek=5.0; return prosjek; }
        suma=suma+ocjene[i];
        i++;
    }
     prosjek=(double)suma/broj_ocjena;
}
else prosjek=5.0;

return prosjek;
}

int trazi(struct Student *studenti,int brojstudenata,double maxprosjek,char top3_ime[3][20],char top3_prezime[3][20]){
    int i=0,j=0;
    int pronadjeno=0;
    int ima=0; /* Ako ima isto ime i prezime, brojac*/
    double prosjek;

    for(i=0;i<brojstudenata;i++){
        prosjek=prosjekocjena(studenti[i].ocjene,studenti[i].br_ocjena);
        if((fabs(prosjek-maxprosjek) < epsilon) == 1){
        if(strcmp(studenti[i].ime, top3_ime[0])<0){/*ime prije*/
        j=2;
        while(j>0) {
            
            strcpy(top3_ime[j],top3_ime[j-1]);
            strcpy(top3_prezime[j],top3_prezime[j-1]);
            j--;
     }
        strcpy(top3_ime[0],studenti[i].ime);
        strcpy(top3_prezime[0],studenti[i].prezime);
        pronadjeno++;
    }
    else if(strcmp(studenti[i].ime,top3_ime[0])>0){
        /*Ime poslije*/
        if(pronadjeno==2){
            if(strcmp(studenti[i].ime,top3_ime[1])>0){/*Ime poslije drugog */
                strcpy(top3_ime[2],studenti[i].ime);
                strcpy(top3_prezime[2],studenti[i].prezime);
                pronadjeno++;
        }
        else if(strcmp(studenti[i].ime,top3_ime[1])<0){
            /*Ime prije drugog */
            for(j=2;j>1;j--){
                strcpy(top3_ime[j],top3_ime[j-1]);
                strcpy(top3_prezime[j],top3_prezime[j-1]);
            }
            strcpy(top3_ime[1],studenti[i].ime);
            strcpy(top3_ime[1],studenti[i].prezime);
            pronadjeno++;
         }
           /*Isto ime kao drugi na listi,sada provjerava prezimena*/
    }
        else{
            for(j=2;j>1;j--){
            strcpy(top3_ime[j],top3_ime[j-1]);
            strcpy(top3_prezime[j],top3_prezime[j-1]);
        }
            strcpy(top3_ime[1],studenti[i].ime);
            strcpy(top3_prezime[1],studenti[i].prezime);
            pronadjeno++;
            }
        }
        else if(strcmp(studenti[i].ime,top3_ime[0])==0){
            if(strcmp(top3_prezime[0],studenti[i].prezime)<0){
                /*Prezime prije*/
                for(j=2;j>0;j--){
                    strcpy(top3_ime[j],top3_ime[j-1]);
                    strcpy(top3_prezime[j],top3_prezime[j-1]);
                }
                strcpy(top3_ime[0],studenti[i].ime);
                strcpy(top3_prezime[0],studenti[i].prezime);
                pronadjeno++;
            }
        else if(strcmp(top3_prezime[0],studenti[i].prezime)>0){
            /*prezime poslije*/
            for(j=2;j>1;j--){
                strcpy(top3_ime[j],top3_ime[j-1]);
                strcpy(top3_prezime[j],top3_prezime[j-1]);
            }
            strcpy(top3_ime[1],studenti[i].ime);
            strcpy(top3_prezime[1],studenti[i].prezime);
            pronadjeno++;
        }
        else{/*Ako je i ime i prezime isto*/
            if(ima==0){ima=1; pronadjeno++;}
            else{
                for(j=2;j>1;j--){
                    strcpy(top3_ime[j],top3_ime[j-1]);
                    strcpy(top3_prezime[j],top3_prezime[j-1]);
                }
                strcpy(top3_ime[1],studenti[i].ime);
                strcpy(top3_prezime[1],studenti[i].prezime);
                pronadjeno++;
                }
            }
        }
    }
}
    return pronadjeno;
}

int genijalci(struct Student *studenti, int brojstudenata, double dovoljanprosjek) {
    int i=0, j=0, k=0;
    int pronadjeno=0, a=0;
    char top3_ime[3][20]={"","",""};
    char top3_prezime[3][20]={"","",""};
    double prosjek=0, maxprosjek1, maxprosjek2, maxprosjek3, minimalni;
    
    for(i=0; i<brojstudenata; i++) {
        prosjek=prosjekocjena(studenti[i].ocjene, studenti[i].br_ocjena);
        if(prosjek<dovoljanprosjek) {
            for(j=i; j<brojstudenata-1;j++) {
                studenti[j]=studenti[j+1];
            }
            i--;
            brojstudenata--;
        }
    }
    if(brojstudenata>0) {
    maxprosjek1=0; maxprosjek2=0; maxprosjek3=0;
    minimalni=prosjekocjena(studenti[i].ocjene,studenti[i].br_ocjena);
    for(i=0;i<brojstudenata;i++) {
        prosjek=prosjekocjena(studenti[0].ocjene,studenti[0].br_ocjena);
        if(prosjek<minimalni){ minimalni=prosjek;
            maxprosjek1=prosjek;
            strcpy(top3_ime[0],studenti[i].ime);
            strcpy(top3_prezime[0],studenti[i].prezime);
         }
         maxprosjek1=minimalni;
            for(i=0;i<brojstudenata;i++){
                prosjek=prosjekocjena(studenti[i].ocjene,studenti[i].br_ocjena);
                if(prosjek>=maxprosjek1){
                    maxprosjek1=prosjek;
                    strcpy(top3_ime[0],studenti[i].ime);
                    strcpy(top3_prezime[0],studenti[i].prezime);
                }
            }
    pronadjeno=trazi(studenti,brojstudenata,maxprosjek1,top3_ime, top3_prezime);
    if(pronadjeno<=3){
            a=pronadjeno;
        for(j=0;j<pronadjeno;j++){
            for(k=0;k<20;k++){
                if(top3_prezime[j][k]=='\0')break;
                printf("%c",top3_prezime[j][k]);
            }
            printf(" ");
            for(k=0;k<20;k++){
                if(top3_ime[j][k]=='\0')break;
                printf("%c",top3_ime[j][k]);
            }
            printf("\n");
        }
    }
    else if(pronadjeno>0) {
        a=3;
        for(j=0;j<3;j++){
            for(k=0;k<20;k++){
                if(top3_prezime[j][k]=='\0')break;
                printf("%c",top3_prezime[j][k]);
            }
            printf(" ");
            for(k=0;k<20;k++){
                if(top3_ime[j][k]=='\0')break;
                printf("%c",top3_ime[j][k]);
            }
            printf("\n");
        }
    }
    
    a=pronadjeno;

    if(a<3 && brojstudenata>1){
        maxprosjek2=minimalni;
        for(i=0;i<brojstudenata;i++){
            prosjek=prosjekocjena(studenti[i].ocjene,studenti[i].br_ocjena);
            if(prosjek>=maxprosjek2 && (fabs(maxprosjek1-prosjek)<epsilon)==0){
                maxprosjek2=prosjek;
                strcpy(top3_ime[0],studenti[i].ime);
                strcpy(top3_prezime[0],studenti[i].prezime);
            }
        }
        
        pronadjeno=trazi(studenti,brojstudenata, maxprosjek2, top3_ime, top3_prezime);
        if((a+pronadjeno)<3) {
            for(j=0;j<pronadjeno;j++){
                for(k=0;k<20;k++){
                    if(top3_prezime[j][k]=='\0')break;
                    printf("%c",top3_prezime[j][k]);
                }
                printf(" ");
                for(k=0;k<20;k++){
                    if(top3_ime[j][k]=='\0')break;
                    printf("%c",top3_ime[j][k]);
            }
            printf("\n");
        }
    }
    else{
        for(j=0; j<3-a; j++) {
            for(k=0; k<20;k++) {
                if(top3_prezime[j][k]=='\0')break;
                printf("%c",top3_prezime[j][k]);
            }
            printf(" ");
            for(k=0;k<20;k++) {
            
                if(top3_ime[j][k]=='\0')break;
                printf("%c",top3_ime[j][k]);
            }
            printf("\n");
        }
    }
    a+=pronadjeno;
    if(a<3 && a<brojstudenata) {
        maxprosjek3=minimalni;
        for(i=0;i<brojstudenata;i++){
            prosjek=prosjekocjena(studenti[i].ocjene,studenti[i].br_ocjena);
            if(prosjek>=maxprosjek3 && (fabs(maxprosjek1-prosjek) < epsilon)==0 && (fabs(maxprosjek2-prosjek)<epsilon)==0){
                maxprosjek3=prosjek;
                strcpy(top3_ime[0],studenti[i].ime);
                strcpy(top3_prezime[0],studenti[i].prezime);
            }
        }
        pronadjeno=trazi(studenti,brojstudenata, maxprosjek3, top3_ime, top3_prezime);
        if((a+pronadjeno)<3) {
            for(j=0;j<pronadjeno;j++){
                for(k=0;k<20;k++){
                    if(top3_prezime[j][k]=='\0')break;
                    printf("%c",top3_prezime[j][k]);
                }
                printf(" ");
                for(k=0;k<20; k++) {
                    if(top3_ime[j][k]=='\0')break;
                    printf("%c",top3_ime[j][k]);
                }
                printf("\n");
            }
        }
        
        else {
            for(j=0;j<3-a;j++){
                for(k=0;k<20;k++){
                    if(top3_prezime[j][k]=='\0')break;
                    printf("%c",top3_prezime[j][k]);
                }
                printf(" ");
                k=0;
                while(k<20){
                    if(top3_ime[j][k]=='\0')break;
                    printf("%c",top3_ime[j][k]);
                    k++; }
                    printf("\n");
                }
            }
        }
    }
} 
}

return brojstudenata;
}


int main() {
 
    return 0;
}
