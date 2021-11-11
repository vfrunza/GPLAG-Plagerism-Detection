#include <stdio.h>

int dva_od_tri(int niz1[],int velicina1,int niz2[],int velicina2,int niz3[],int velicina3)
{
    int i,j,f,r,h,counter=0,noviExist=0;
    int velicinaTemp1=0,velicinaTemp2=0,velicinaTemp3=0,nizTemp1[100],nizTemp2[100],nizTemp3[100];
    int postoji=0;

    for(i=0; i<velicina1; i++) {
        postoji=0;
        for(j=0; j<velicinaTemp1; j++) {
            if(niz1[i]==nizTemp1[j])postoji=1;
        }
        if(postoji==0) {
            nizTemp1[velicinaTemp1]=niz1[i];
            velicinaTemp1++;
        }
    }

    for(i=0; i<velicina2; i++) {
        postoji=0;
        for(j=0;j <velicinaTemp2; j++) {
            if(niz2[i]==nizTemp2[j])postoji=1;
        }
        if(postoji==0) {
            nizTemp2[velicinaTemp2]=niz2[i];
            velicinaTemp2++;
        }
    }

    for(i=0; i<velicina3; i++) {
        postoji=0;
        for(j=0; j<velicinaTemp3; j++) {
            if(niz3[i]==nizTemp3[j])postoji=1;
        }
        if(postoji==0) {
            nizTemp3[velicinaTemp3]=niz3[i];
            velicinaTemp3++;
        }
    }

    for(i=0; i<velicinaTemp1; i++) { //prva provjera
        noviExist=0;
        for(j=0; j<velicinaTemp2; j++) {
            if(nizTemp1[i]==nizTemp2[j]) {
                noviExist=1;
                for(f=0; f<velicinaTemp1; f++) {
                    for(r=0; r<velicinaTemp2; r++) {
                        for(h=0; h<velicinaTemp3; h++) {
                            if(nizTemp1[f]==nizTemp1[i] && nizTemp2[r]==nizTemp1[i] && nizTemp3[h]==nizTemp1[i])
                                noviExist=0;
                        }
                    }
                }
            }
        }
        if(noviExist==1)counter++;
    }

    for(i=0; i<velicinaTemp2; i++) { //druga provjera
        noviExist=0;
        for(j=0; j<velicinaTemp3; j++) {
            if(nizTemp2[i]==nizTemp3[j]) {
                noviExist=1;
                for(f=0; f<velicinaTemp1; f++) {
                    for(r=0; r<velicinaTemp2; r++) {
                        for(h=0; h<velicinaTemp3; h++) {
                            if(nizTemp1[f]==nizTemp2[i] && nizTemp2[r]==nizTemp2[i] && nizTemp3[h]==nizTemp2[i])
                                noviExist=0;
                        }
                    }
                }
            }
        }
        if(noviExist==1)counter++;
    }

    for(i=0; i<velicinaTemp1; i++) { //treca provjera
        noviExist=0;
        for(j=0; j<velicinaTemp3; j++) {
            if(nizTemp1[i]==nizTemp3[j]) {
                noviExist=1;
                for(f=0; f<velicinaTemp1; f++) {
                    for(r=0; r<velicinaTemp2; r++)
                        for(h=0; h<velicinaTemp3; h++)
                            if(nizTemp1[f]==nizTemp1[i] && nizTemp2[r]==nizTemp1[i] && nizTemp3[h]==nizTemp1[i])
                                noviExist=0;
                }
            }
        }
        if(noviExist==1)counter++;
    }

    return counter;
}

int main()
{
    int i,j,exist=0,niz1[100],niz2[100],niz3[100],velicina1,velicina2,velicina3;
    int nizTemp1[100],nizTemp2[100],nizTemp3[100],velicinaTemp1=0,velicinaTemp2=0,velicinaTemp3=0;
    int rez;

    printf("Unesite velicinu prvog niza: ");
    scanf("%d",&velicina1);
    printf("Unesite clanove prvog niza: ");
    for(i=0; i<velicina1; i++) {
        scanf("%d",&niz1[i]);
        if(i==0) {
            nizTemp1[velicinaTemp1]=niz1[i];
            ++velicinaTemp1;
        } else {
            for(j=0; j<velicinaTemp1; j++) {
                if(nizTemp1[j]==niz1[i]) {
                    exist=1;
                }

            }
            if(exist==0) {
                nizTemp1[velicinaTemp1]=niz1[i];

                ++velicinaTemp1;
            }
        }
    }

    printf("Unesite velicinu drugog niza: ");
    scanf("%d",&velicina2);
    printf("Unesite clanove drugog niza: ");
    for(i=0; i<velicina2; i++) {
        scanf("%d",&niz2[i]);
        if(i==0){
            nizTemp2[velicinaTemp2]=niz2[i];
            ++velicinaTemp2;
        }else{
            for(j=0;j<velicinaTemp2;j++){
                if(nizTemp2[j]==niz2[i]){
                    exist=1;
                }
                if(exist==0){
                    nizTemp2[velicinaTemp2]=niz2[i];
                    ++velicinaTemp2;
                }
            }
        }
    }
    
    printf("Unesite velicinu treceg niza: ");
    scanf("%d",&velicina3);
    printf("Unesite clanove treceg reda: ");
    for(i=0;i<velicina3;i++){
        scanf("%d",&niz3[i]);
        if(i==0){
            nizTemp3[velicinaTemp3]=niz3[i];
            ++velicinaTemp3;
        }else{
            for(j=0;j<velicinaTemp3;j++){
                if(nizTemp3[j]==niz3[i]){
                    exist=1;
                }
                if(exist==0){
                    nizTemp3[velicinaTemp3]=niz3[i];
                    ++velicinaTemp3;
                }
            }
        }
    }

    rez=dva_od_tri(nizTemp1,velicinaTemp1,nizTemp2,velicinaTemp2,nizTemp3,velicinaTemp3);
        printf("%d",rez);
    return 0;
}