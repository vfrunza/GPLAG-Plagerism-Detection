#include <stdio.h>
#include <math.h>
#include <string.h>

int main() {
    int c=0,v=0,p=0,b=0,s=0;
    float zbir=0;
     char t='n';
     printf("Unesite vozila: ");
      while(t!=75 && t!=107)
      {
       scanf("%c",&t);
       if(t==75 || t==107)
       break;
       if(t!=67 && t!=99 && t!=66 && t!=98 && t!=83 && t!=115 && t!=86 && t!=118 && t!=80 && t!=112)
       printf("Neispravan unos\n");
                             
                          
                            if(t==67 || t==99)
                              c++;
                           
                             if(t==66 || t==98)
                               b++;
                   
                               if(t==83 || t==115)
                                s++;
                          
                             
                                if(t==86 || t==118)
                                 v++;
                           
                          
                                 if(t==80 || t==112)
                                  p++;}
      
                                
                                  zbir=c+b+s+v+p;
                                  if(zbir==0.){
                                   printf("Ukupno evidentirano %g vozila.\nNajpopularnija boja je crna (%.2f%%).",zbir,zbir);
                                  }
                                  else {
                                printf("Ukupno evidentirano %g vozila.", zbir);
                                if(c>b && c>s && c>v && c>p)
                                printf("\nNajpopularnija boja je crna (%.2f%%). ",((c/zbir)*100));
                                else {
                                if(b>c && b>s && b>v && b>p)
                                 printf("\nNajpopularnija boja je bijela (%.2f%%). ",((b/zbir)*100));
                                 else {
                                 if(s>c && s>b && s>v && s>p)
                                  printf("\nNajpopularnija boja je siva (%.2f%%).",((s/zbir)*100));
                                 else {
                                   if(v>c && v>b && v>s && v>p)
                                   printf("\nNajpopularnija boja je crvena (%.2f%%).",((v/zbir)*100));
                                else {
                                   if(p>c && p>b && p>v && p>s)
                                    printf("\nNajpopularnija boja je plava (%.2f%%).",((p/zbir)*100));
                                   
                                   else {
                                      if(c==s || c==p || c==v)
                                     printf("\nNajpopularnija boja je crna (%.2f%%).",((c/zbir)*100));
                                    else {
                                       if(b==s || b==p || b==v)
                                     printf("\nNajpopularnija boja je bijela (%.2f%%).",((b/zbir)*100));
                              else {
                                     if(s==v || s==p)
                                    printf("\nNajpopularnija boja je siva (%.2f%%).",((s/zbir)*100));
                                    else {
                                    if(v==p)
                                    printf("\nNajpopularnija boja je crvena (%.2f%%).",((v/zbir)*100));
                                    }
                              }
                                    }
                                    
                                   }
                                }
                                 }
                                 }
                                }
                                  }
                                return 0;
}