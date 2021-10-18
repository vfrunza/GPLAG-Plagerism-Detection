#include <stdio.h>

void sort(int *sortiraj,int *index)
{
    int i,j,temp;
    
     for(i=0;i<95;i++)
     {
            for(j=0;j<95;j++)
            {
                if(sortiraj[j]<sortiraj[i])
                {   
                    temp=sortiraj[i];
                    sortiraj[i]=sortiraj[j];
                    sortiraj[j]=temp;
                    
                    temp=index[i];
                    index[i]=index[j];
                    index[j]=temp;
                }
                if(sortiraj[i]==sortiraj[j] && index[j]>index[i])
                {
                    temp=index[i];
                    index[i]=index[j];
                    index[j]=temp;
            
            }
            
        }
     }
}


void stvorikljuc(char *kljuc,int *sortiraj,int *index)
{   
    int i;
     for(i=0;i<95;i++)
          {   
             if(sortiraj[i]!=0)
             {
              *kljuc=index[i]+32;
              kljuc++;
             }
         }
       
          for(i=0;i<95;i++)
          {
              if(sortiraj[i]==0) {*kljuc=index[i]+32; kljuc++;}
          }
          *kljuc='\0';
}

char *kodiraj(char *tekst,char *kljuc)
{
    char *p=tekst,*q;
    int niz[95];
    int sortiraj[95];
    int index[95];
    
    int i,br;

 
    
        for(i=0;i<95;i++)
            niz[i]=0;  
            
            
        while(*p!='\0')
            {   
                q=p;
                br=0;
                while(*q!='\0')
                {
                    if(*p==*q) br++;
                    q++;
                }
                if(niz[*p-32]==0) niz[*p-32]=br;
                p++;

            }
            
            for(i=0;i<95;i++)
                {
                    sortiraj[i]=niz[i];
                    index[i]=i;
                }
            
       
           
           sort(sortiraj,index);
           stvorikljuc(kljuc,sortiraj,index);
         
          
          
            p=tekst;
            q=kljuc;
            
            while(*p!='\0')
            {    q=kljuc;br=0;
                while(*q!='\0')
                {
                    if(*p==*q) {*p=126-br;break;}
                    br++;
                    q++;
                }
                p++;
            }
          
     return tekst;
     
}


char *dekodiraj(char *tekst,char *kljuc)
{
    char *p=tekst;
        
        while(*p!='\0')
        {
            *p=kljuc[126-*p];
            p++;
        }
    return tekst;
}

int main() {

    char tekst[] = "LLMLNLNMONM";
char sifrarnik[100] = "";
printf("%s", kodiraj(tekst, sifrarnik));
return 0;
}
    
    