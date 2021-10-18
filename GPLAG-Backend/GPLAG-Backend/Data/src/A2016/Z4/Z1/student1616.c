
#include <stdio.h>
#include <ctype.h>
 
 char pom[1000];
 //Vrsimo provjeru da li su sve brojevi u rijeci unesenog stringa//
 int samobrojevi(char *p) {
    while (*p!='\0') {
        if (*p>='A' && *p<='Z' || *p>='a' && *p<='z')
        return 1;
        p++;
    }
    return 0;
}
//Algoritam za pronalazak najcesce rijeci//
 char* PronadjiNajcescu(char *s)
 {
     
     char *p=s,*q,*pt,*kt,*pt1,*pm,*km,*a,*t,*r;
     int br=0,isti,max=0,i=0;
     //Provjera unesenog stringa//
      if (!(*s>='A' && *s<='Z' || *s>='a' && *s<='z' || *s==' '))
    return s;
    
    if (*p>='0' && *p<'9') {
            if (samobrojevi(p==0)) return s; 
    }
 
     
     while(*p!='\0')
     {
        if(tolower(*p)>='a' && tolower(*p)<='z')
        {
          pt=p;
          while(tolower(*p)>='a' && tolower(*p)<='z')
           p++;
           if(*p==' ' || *p=='\0')
           {
              kt=p;
              q=p;
              br=1;
               while(*q!='\0')
               {
                 if(tolower(*q)>='a' && tolower(*q)<='z')
                 {
                   pt1=q;
                   while(tolower(*q)>='a' && tolower(*q)<='z')
                    q++;
                   if(*q==' ' || *q=='\0')
                   {
                     isti=1;
                     t=pt;
                     r=pt1;
                     while(t!=kt)
                     {
                       if(tolower(*t++)!=tolower(*r++))
                       {
                        isti=0;
                        break;
                       }
                       
                     }
                     if(isti==1) br++;
                   }
                 } else q++;
               }
               if(br>max)
               {
                pm=pt;
                km=kt;
                max=br;
               }
           }
        }else p++;
    }
   
   
   while(pm!=km)
   {
     pom[i++]=*pm++;
    
   }
   pom[i]='\0';
   a=&pom[0];
  

  return a;
 }
 //Algoritam za izbacivanje najcesce nakon sto je pronademo u funkciji pronadji najcescu//
 char* izbaci_najcescu(char* s)
 {
   char *p=s,*pt,*kt,*q,*pok,*t;
   int jeste;

   if(*s=='\0') return 0;
    
  
   pok=PronadjiNajcescu(p);
  
 
   while(*p!='\0')
   {
     if(tolower(*p)>='a' && tolower(*p)<='z' && (*(p+1)!=' ' || *(p+1)=='\0'))
     {
        pt=p;q=p;
         while(tolower(*p)>='a' && tolower(*p)<='z')
            p++;
            
        t=pok;
        jeste=1;
        kt=p;
       
        while(pt!=kt )
        { 
          if(tolower(*t++)!=tolower(*pt++)) 
          {
           jeste=0;
           break;
          }
        }
        
        if(jeste==1)
        {
          while(*kt!='\0')
          {
           *q++=*kt++;
          }
          *q='\0';
          p=p-(kt-q);
        }
        

     }else p++;

   }
  
  return s;
 }
 
 int main() {
char string[]="";
    printf ("'%s'", izbaci_najcescu(string));
  return 0;
}