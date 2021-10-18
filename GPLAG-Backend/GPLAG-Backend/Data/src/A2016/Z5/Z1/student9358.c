#include <stdio.h>
#include <string.h>
void unesi(char niz[], int velicina){
    char znak = getchar();
    if(znak=='\n') znak=getchar();
    int i=0;
    while(i<velicina-1 && znak!= '\n'){
        niz[i]=znak;
        i++;
        znak=getchar();
    }
    niz[i]='\0';
}

struct Student{
    char ime[20], prezime[20];
    int ocjene[50];
    int br_ocjena;
};

int genijalci(struct Student* s, int velicina, float prosjek){
    int i,suma=0,j,k,novavel,velicina2=0,b=0,pozicija1=0,pozicija2=0,postoji=0;
    struct Student temp;
    struct Student najbolji[100];
    struct Student student1={0};
    struct Student student2={0};
    struct Student student3={0};
    float max1=0,max2=0,max3=0;
    float prosjek1[100];
    float prosjek2[100]={0};
    for(i=0;i<velicina;i++){                                     /*izbacuje sve koji imaju bar jednu peticu*/
        postoji=0;
        for(j=0;j<(s+i)->br_ocjena;j++){
            if((s+i)->ocjene[j]==5) {postoji=1; break;}
        }
        if (postoji==1){
            for(k=i; k<velicina-1; k++){
                *(s+k)=*(s+k+1);
            }
        velicina--;
        i--;
        }
    }
    
    for(i=0;i<velicina;i++){                                 /*izbacuje one koji nemaju ocjena*/
        if((s+i)->br_ocjena==0) {
            for(k=i; k<velicina-1;k++){
                *(s+k)=*(s+k+1);
            }
        velicina--;
        i--;
        }
    }
    
    for(i=0;i<velicina;i++){                                /*izdvaja od preostalih one koji imaju prosjek veci ili jednak unesenom*/
        suma=0;
        for(j=0;j<(s+i)->br_ocjena;j++){
            suma=suma+(s+i)->ocjene[j];
        }
        prosjek1[i]=(float)suma/((s+i)->br_ocjena);
        /*printf("%.2f\n",prosjek1[i]);*/
        if(prosjek1[i]>=prosjek){
            prosjek2[velicina2]=prosjek1[i];
            najbolji[velicina2]=*(s+i);
            /*printf("%.2f ",prosjek2[velicina2]);
            printf("%s %s\n",najbolji[velicina2].ime, najbolji[velicina2].prezime);*/
            velicina2++;
            /*printf("%d\n",velicina2);*/
        }
    
        if (prosjek1[i]<prosjek){
            for(k=i; k<velicina-1; k++){
                *(s+k)=*(s+k+1);    
            }
            velicina--;
            i--;
        }  
    }
    
    
   novavel=velicina;
   for(i=0;i<novavel;i++){
       if(prosjek2[i]>max1) {
           max1=prosjek2[i];
           pozicija1=i;
           student1=*(s+i);
       }
   }
   
   for(i=0;i<novavel;i++){
       if(prosjek2[i]>max2 && prosjek2[i]<=max1 && i!=pozicija1){
            max2=prosjek2[i];
            pozicija2=i;
            student2=*(s+i);
       }
   }
   
   if((max1==max2) && (strcmp(student1.ime,student2.ime)<0)) {temp=student1;
                                             student1=student2;
                                             student2=temp;
    }
   
   for(i=0; i<novavel;i++){
       if(prosjek2[i]>max3 && prosjek2[i]<=max2 && i!=pozicija2){
           max3=prosjek2[i];
           student3=*(s+i);
       }
    }

       
    
    
    if((max2==max3) && (strcmp(student2.ime,student3.ime)<0)) {
        temp=student2;
                                             student2=student3;
                                             student3=temp;
    }
    
    if((max1==max3) && (strcmp(student1.ime,student3.ime)<0)) {temp=student1;
                                             student1=student3;
                                             student3=temp;
    }
    
     printf("\n%s %s \n%s %s \n%s %s",student1.prezime, student1.ime, student2.prezime, student2.ime, student3.prezime, student3.ime);
        
    
    
    
    /*printf("%.2f %.2f %.2f",max1,max2,max3);*/
     
    return novavel;   
}
struct Student unos_studenta(){
    struct Student s;
    int i=0;
    unesi(s.ime, 20);
    unesi(s.prezime, 20);
    scanf("%d", &s.br_ocjena);
    for(i=0;i<s.br_ocjena;i++)
    scanf("%d", &s.ocjene[i]);
    return s;
}

int main() {
    struct Student studenti[6] ={
	{ "Mujo", "Mujic", { 10,10,10,10,9}, 5}, 
	{ "Meho", "Mujic", { 7,7,7,7,8}, 5}, 
	{ "Pero", "Peric", { 8,8,8,8,7}, 5}, 
	{ "Beba", "Bebic", {}, 0},
	{ "Mujo", "Mujic", { 7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7}, 29}, 
	{ "Fata", "Fatic", { 7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,6}, 29}, 
};
int vel = genijalci(studenti, 6, 10);
printf("Vel: %d", vel);

	
	return 0;
}
