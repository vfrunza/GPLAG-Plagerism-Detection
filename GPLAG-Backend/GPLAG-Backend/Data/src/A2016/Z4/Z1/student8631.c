#include <stdio.h>
#include <ctype.h>
 
 char string [1000];
 // funckija koja prebrojava koliko te rijeci ima u ostatku stringa//
 int najcesca(char*pok_string, char*pt, char*kt ){
  char *pt1, *t, *r;
  int pretpostavka, br=1;
  while(*pok_string!='\0')
               {
                 if(tolower(*pok_string)>='a' && tolower(*pok_string)<='z')
                 {
                   pt1=pok_string;
                   while(tolower(*pok_string)>='a' && tolower(*pok_string)<='z')
                    pok_string++;
                   if(*pok_string==' ' || *pok_string=='\0')
                   {
                     pretpostavka=1;
                     t=pt;
                     r=pt1;
                     while(t!=kt)
                     {
                       if(tolower(*t++)!=tolower(*r++))
                       {
                        pretpostavka=0;
                        break;
                       }
                       
                     }
                     if(pretpostavka==1) br++;
                   }
                 } else pok_string++;
               }
 return br;
 } 
 
 char* PronadjiNajcescu(char *s)
 {
     
     char *p=s,*pok_string,*pt,*kt,*pm,*km,*a;
     int br=0,max=0,i=0;
     
 
  
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
              pok_string=p;
              
              br=najcesca(pok_string,pt, kt);
               if(br>max)
               {
                string[i]=*pt;
                pm=pt;
                km=kt;
                max=br;
                i=0;
                while(pm!=km)
                {
                 string [i++]=*pm++;
    
                      }
                  string [i]='\0';
               }
           }
        }else p++;
    }
   
   
   
   a=&string [0];
  

  return a;
 }
 //funkcija izbacuje najcescu rijec //
 char* izbaci_najcescu(char* s)
 {
   char *p=s,*pt,*kt,*pok_string,*pok,*t;
   int jeste;

   if(*s=='\0') return 0;
    
  
   pok=PronadjiNajcescu(p);
  
 
   while(*p!='\0')  
   {
     if(tolower(*p)>='a' && tolower(*p)<='z' && (*(p+1)!=' ' || *(p+1)=='\0'))
     {
        pt=p;pok_string=p;
         while(tolower(*p)>='a' && tolower(*p)<='z')
            p++;
            
        t=pok;
        jeste=1;
        kt=p;
       
        while(pt!=kt ) 
        { 
          if(tolower(*t++)!=tolower(*pt++))  //poredimo najcescu rijec sa ostalim rijecima//
          {
           jeste=0;
           break;
          }
        }
        
        
        if(jeste==1) // ako je pronadjena najcesca rijec u stringu izbacujemo rijec //
        {
          while(*kt!='\0')
          {
           *pok_string++=*kt++;
          }
          *pok_string='\0';
          p=p-(kt-pok_string);
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