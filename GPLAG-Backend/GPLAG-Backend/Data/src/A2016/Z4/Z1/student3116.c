#include <stdio.h>
#include <ctype.h>
 
 char pom[1000];
 char* PronadjiNajcescu(char *s)
 {
     
     char *p=s,*q,*pt,*kt,*pt1,*pm,*km,*a,*t,*r;
     int br=0,isti,max=0,i=0;
     
 
     
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
 
 int main()
 {
  
 char t[]=" Koristio sam auto-stop da dodjem do znaka stop ali prije stopa sam otvorio dekstop kompjutera stop";
 printf("'%s'", izbaci_najcescu(t));

  return 0;
 }