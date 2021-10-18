#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void unesi(char niz[], int velicina) {
    char znak = getchar();
    if (znak == '\n') znak=getchar();
    int i = 0;
    while (i < velicina-1 && znak != '\n') {
        niz[i] = znak;
        i++;
        znak = getchar();
    }
    niz[i]='\0';
}
struct Student 
{
	char ime[20];
	char prezime[20];
	int ocjene[50];
	int br_ocjena;
};
int uporedi(struct Student student1,struct Student student2)
{
    char *p1=student1.prezime, *p2=student2.prezime;
    char *i1=student1.ime, *i2=student2.ime;
    while(*p1!='\0' && *p2!='\0')
    {
        if(*p1 < *p2)return 0;
        else if(*p1 > *p2)return 1;
        p1++;
        p2++;
    }
    if(*p1==0 && *p2==0)
    {
        while((*i1!=0 && *i2!=0))
        {
            if(*i1 < *i2) return 0;
            else if(*i1 > *i2) return 1;
            i1++;
            i2++;
        }
        if(*i1!=0)return 1;
        else if(*i2!=0)return 0;
    }
    
    else if(*p1!='\0')return 1;
    else if(*p2!='\0')return 0;
    return 0;
}

int genijalci(struct Student niz[], int vel, float prosjek_2)
{
    int i,j;
    float Prosjek1;
    
   for(i=0;i<vel;i++)
   {
       Prosjek1=0;
       int suma=0,rendom=0;
       for(j=0;j<niz[i].br_ocjena;j++)
       {
           Prosjek1=0;
           if(niz[i].ocjene[j]==5)
           {
               rendom=1;
           }
           suma+=niz[i].ocjene[j];
       }
       if(rendom==1 || niz[i].br_ocjena==0)
       {
           Prosjek1=5.00;
       }
       else
        {
            Prosjek1=(float)suma/niz[i].br_ocjena;
        }
        if(Prosjek1<prosjek_2)
        {
            for(j=i;j<vel-1;j++)
            {
                niz[j]=niz[j+1];
            }
            vel--;
            i--;
        }
   }
        
        
   float nizp[100];
   float max=0;
   for(i=0;i<vel;i++)
   {
       Prosjek1=0;
       int suma=0,rendom=0;
       for(j=0;j<niz[i].br_ocjena;j++)
       {
           if(niz[i].ocjene[j]==5)
           {
               rendom=1;
           }
           suma+=niz[i].ocjene[j];
       }
       if(rendom==1 || niz[i].br_ocjena==0)
       {
           Prosjek1=5.00;
       }
       else
        {
            Prosjek1=(float)suma/niz[i].br_ocjena;
        }
        nizp[i]=Prosjek1;
       
   }
    
    int zapamti=0,brojac=0,maxindeks1=0,maxindeks2=0,maxindeks3=0;
    while(brojac<3 && brojac<vel)
    {
    for(i=0;i<vel;i++)
    {
        if(nizp[i]>max)
        {
            max=nizp[i];
            zapamti=i;
          
    }
        
    }
    brojac++;
    if(brojac==1)
    maxindeks1=zapamti;
    else if(brojac==2)
    maxindeks2=zapamti;
    else if(brojac==3)
    maxindeks3=zapamti;
    
    nizp[zapamti]=-1.;

        int dupli=0,zapamti2=0;
        for(i=0;i<vel;i++)
        {
            
            
           if(fabs(nizp[i] - max)<0.00001)
            {
                dupli=1;
                zapamti2=i;
            }
        }
        if(dupli==1)
        {
            if(uporedi(niz[zapamti],niz[zapamti2])==0)
            {
                if(brojac==1)
                    maxindeks1=zapamti;
                else if(brojac==2)
                    maxindeks2=zapamti;
                 else if(brojac==3)
                    maxindeks3=zapamti;
                    
                    brojac++;
                    
                    if(brojac==1)
                    maxindeks1=zapamti2;
                else if(brojac==2)
                    maxindeks2=zapamti2;
                 else if(brojac==3)
                    maxindeks3=zapamti2;
            }
            else if(uporedi(niz[zapamti],niz[zapamti2])==1)
            {
                if(brojac==1)
                    maxindeks1=zapamti2;
                else if(brojac==2)
                    maxindeks2=zapamti2;
                 else if(brojac==3)
                    maxindeks3=zapamti2;
                    brojac++;
                    if(brojac==1)
                    maxindeks1=zapamti;
                else if(brojac==2)
                    maxindeks2=zapamti;
                 else if(brojac==3)
                    maxindeks3=zapamti;

        }
        nizp[zapamti2]=-1.;
        dupli=0;
        }
        max=0;
    }
        
                
            
                
                printf("%s %s\n",niz[maxindeks1].prezime,niz[maxindeks1].ime);
                
                
                 printf("%s %s\n",niz[maxindeks2].prezime,niz[maxindeks2].ime);
                 
                 
                 printf("%s %s\n",niz[maxindeks3].prezime,niz[maxindeks3].ime);
            
     
            
           
           
     
    
    
        
     
     return vel;   
        
}
int main() 
{
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
