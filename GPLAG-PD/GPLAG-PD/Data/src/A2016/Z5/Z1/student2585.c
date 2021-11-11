#include <stdio.h>
#include <string.h>

struct Student
{
   char ime[20], prezime[20];
   int ocjene[50];
   int br_ocjena;
};

int provjera (struct Student student, double prosjek)
{
    double pom=0; //prosjek 
    int broj=student.br_ocjena;
    int i;
    for(i=0; i<broj; i++)
    {
        if(student.ocjene[i]==5)
        {
            pom=5;
            break;
        }
        else 
        {
           pom=pom+student.ocjene[i]; 
        }
    }
    
        pom=pom/broj; 
        
    if(broj==0)
    {
        pom=5;
        return 1;
    }
    
    if(pom<prosjek)
    {
        return 1;
    }
    else return 0;
    
}

double daj_prosjek(struct Student student)
{
    double prosjek;
    int suma=0, broj=student.br_ocjena;
    int i;
    for(i=0; i<broj; i++)
    {
        suma=suma+student.ocjene[i];
    }
    prosjek=(double)suma/broj;
    return prosjek;
}


int genijalci (struct Student studenti[], int velicina, double prosjek)
{
    int i, j, izbaciti=0;
    int vel=velicina;
    for(i=0; i<vel; i++)
    {
        
        izbaciti=provjera(studenti[i], prosjek);
        if(izbaciti==1) 
        {
            //vrsimo izbacivanje
            for(j=i; j<vel-1; j++)
            {
                studenti[j]=studenti[j+1];
            }
            i--;
            vel--;
        }
    }
    if(vel==1)
    {
        printf("%s %s", studenti[0].prezime, studenti[0].ime);
    }
    else if(vel==2)
    {
        if(daj_prosjek(studenti[0])>=daj_prosjek(studenti[1]))
        {
            printf("%s %s", studenti[0].prezime, studenti[0].ime);
            printf("\n%s %s", studenti[1].prezime, studenti[1].ime);
        }
        else 
         {
            printf("%s %s", studenti[1].prezime, studenti[1].ime);
            printf("\n%s %s", studenti[0].prezime, studenti[0].ime);
        }
    }
    else if(vel>=3)
    {
        double prvi, drugi, treci;
        double niz[100]={0};
        double temp;

        for(i=0; i<vel; i++)
        {
            niz[i]=daj_prosjek(studenti[i]);
        }
        
        for(i=0; i<vel; i++)
        {
            for(j=i+1; j<vel; j++)
            {
                if(niz[i]<niz[j])
                {
                    temp=niz[j];
                    niz[j]=niz[i];
                    niz[i]=temp;
                }
            }
        }
        prvi=niz[0];
        drugi=niz[1];
        treci=niz[2];
        for(i=0; i<vel; i++)
        {
            niz[i]=daj_prosjek(studenti[i]);
        }
        for(i=0; i<vel; i++)
        {
            for(j=vel-1; j>i; j--)
            {
                if(niz[i]==niz[j] && niz[i]==prvi)
                {
                    char kon[100];
                    char pon[100];
                    strcpy(kon, studenti[i].prezime);
                    strcat(kon, studenti[i].ime);
                    
                    strcpy(pon, studenti[j].prezime);
                    strcat(pon, studenti[j].ime);
                    if(strcmp(kon,pon)<0)//(strcmp(studenti[i].prezime, studenti[j].prezime)<0) && (strcmp(studenti[i].ime, studenti[j].ime)<0)) 
                    {
                        niz[i]+=1;
                        prvi+=1;
                    }
                    else 
                    {
                        niz[j]+=1;
                        prvi+=1;
                    }
                }
                else if(niz[i]==niz[j] && niz[i]==drugi)
                {
                     char kon[100];
                    char pon[100];
                    strcpy(kon, studenti[i].prezime);
                    strcat(kon, studenti[i].ime);
                    
                    strcpy(pon, studenti[j].prezime);
                    strcat(pon, studenti[j].ime);
                    if(strcmp(kon,pon)<0) 
                    {
                        niz[i]+=1;
                        drugi+=1;
                    }
                    else 
                    {
                        niz[j]+=1;
                        drugi+=1;
                    }
                }
                else if(niz[i]==niz[j] && niz[i]==treci)
                {
                     char kon[100];
                    char pon[100];
                    strcpy(kon, studenti[i].prezime);
                    strcat(kon, studenti[i].ime);
                    
                    strcpy(pon, studenti[j].prezime);
                    strcat(pon, studenti[j].ime);
                    if((strcmp(kon,pon)<0) )
                    {
                        niz[i]+=1;
                        treci+=1;
                    }
                    else 
                    {
                        niz[j]+=1;
                        treci+=1;
                    }
                }
            }
        }
        for(i=0; i<vel; i++)
        {
            if(niz[i]==prvi)
            {
                printf("%s %s", studenti[i].prezime, studenti[i].ime);
                niz[i]=-1;
               break;
            }
        }
        
        
        for(i=0; i<vel; i++)
        {
            if(niz[i]==drugi)
            {
                printf("\n%s %s", studenti[i].prezime, studenti[i].ime);
                niz[i]=-1;
                break;
            }
        }
        
        
       for(i=0; i<vel; i++)
        {
            if(niz[i]==treci)
            {
                printf("\n%s %s", studenti[i].prezime, studenti[i].ime);
                niz[i]=-1;
                break;
            }
        }
    }
    return vel;
}


int main() {
    struct Student studenti[6] ={
	{ "Mujo", "Mujic", { 7,7,7,7,8}, 5}, 
	{ "Meho", "Mujic", { 7,7,7,7,8}, 5}, 
	{ "Pero", "Peric", { 8,8,8,8,7}, 5}, 
	{ "Beba", "Bebic", { 6,6,6,6,6}, 5},
	{ "Mujo", "Mujic", { 7,7,7,7,8}, 5}, 
	{ "Fata", "Fatic", { 7,7,7,7,8}, 5}, 
};
genijalci(studenti, 6, 6.5);
    
	return 0;
}
