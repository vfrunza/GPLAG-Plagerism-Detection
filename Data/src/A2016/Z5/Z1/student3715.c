#include <stdio.h>
#include <string.h>

struct Student {
	char ime[20],prezime[20];
	int ocjene[50];
	int br_ocjena;
};

float prosjek_Ocjena(int ocjene[], int vel)
{
    int i;
    if(vel == 0)
       return 5.0;
    float prosjek = 0;
    for(i = 0; i < vel; i++)
    {
        if(ocjene[i] == 5)
          return 5.0;
        
        prosjek += ocjene[i];  
    }
    
    return ((double)prosjek)/vel;
}

int strCmp(char a[], char b[])
{
    int i = 0;
    while(a[i] != '\0')
    {
        if(b[i] == '\0')
           return 2;
        else if(a[i] > b[i])
           return 2;
        else if(a[i] < b[i])
           return 1;
           
        i++;   
    }
    
    if(b[i] != '\0')
       return 1;
    
    return 0;
}

int jednakiFloat(float a, float b)
{
    if((a-b) > 0.000000001 || (a-b) < -0.000000001)
        return 0;
        
    return 1;    
}

int leksikografskiPoredak(char ime1[], char ime2[], char prezime1[], char prezime2[])
{
    if(strcmp(prezime1,prezime2) > 0)
       return strcmp(prezime1, prezime2);
       
    if(strcmp(ime1,ime2) > 0)
       return strcmp(ime1, ime2);
       
    return 0;   
}


int genijalci(struct Student studenti[], int br_studenata, float prosjek)
{
   
    int i, novaVelicina = 0;
    int prvi_drugi_treci[3] = {-1, -1, -1};
    
    for(i = 0; i < br_studenata; i++)
        if(prosjek_Ocjena(studenti[i].ocjene, studenti[i].br_ocjena) > prosjek)
             studenti[novaVelicina++] = studenti[i];
    
    for(i = 0; i < 3; i++)
    {
        int j, maxProsjek = -1;
        for(j = 0; j < novaVelicina; j++)
        {
            float tmpProsjek = prosjek_Ocjena(studenti[j].ocjene, studenti[j].br_ocjena);
            if(tmpProsjek > maxProsjek && j != prvi_drugi_treci[0] && j != prvi_drugi_treci[1] && j != prvi_drugi_treci[2])
            {
                maxProsjek = tmpProsjek;
                prvi_drugi_treci[i] = j;
            }
        }
    }
    
    /*kad imam slucaj da imam vise istih prosjeka moram poredati po leksikografskom poredku*/
    
    if(prvi_drugi_treci[1] != -1 && prvi_drugi_treci[2] != -1)
    {
        if(jednakiFloat(prosjek_Ocjena(studenti[prvi_drugi_treci[1]].ocjene, studenti[prvi_drugi_treci[1]].br_ocjena), prosjek_Ocjena(studenti[prvi_drugi_treci[2]].ocjene, studenti[prvi_drugi_treci[2]].br_ocjena)))
        {
            if(leksikografskiPoredak(studenti[prvi_drugi_treci[2]].ime, studenti[prvi_drugi_treci[2]].prezime, studenti[prvi_drugi_treci[1]].ime, studenti[prvi_drugi_treci[1]].prezime) == 1)
            {
                int tmp = prvi_drugi_treci[2];
                prvi_drugi_treci[2] = prvi_drugi_treci[1];
                prvi_drugi_treci[1] = tmp;
            }
        }
    }
    
    if(prvi_drugi_treci[0] != -1 && prvi_drugi_treci[1] != -1)
    {
        if(jednakiFloat(prosjek_Ocjena(studenti[prvi_drugi_treci[0]].ocjene, studenti[prvi_drugi_treci[0]].br_ocjena), prosjek_Ocjena(studenti[prvi_drugi_treci[1]].ocjene, studenti[prvi_drugi_treci[1]].br_ocjena)))
        {
            if(leksikografskiPoredak(studenti[prvi_drugi_treci[1]].ime, studenti[prvi_drugi_treci[1]].prezime, studenti[prvi_drugi_treci[0]].ime, studenti[prvi_drugi_treci[0]].prezime) == 1)
            {
                int tmp = prvi_drugi_treci[1];
                prvi_drugi_treci[1] = prvi_drugi_treci[0];
                prvi_drugi_treci[0] = tmp;
            }
        }
    }
    
    for(i = 0; i < 3; i++)
    {
        if(prvi_drugi_treci[i] == -1)
           continue;
           
        if(i > 0)
           printf("\n");
        printf("%s %s", studenti[prvi_drugi_treci[i]].prezime, studenti[prvi_drugi_treci[i]].ime);   
    }
    
    
    return novaVelicina;   
}
int main() {
	return 0;
}
