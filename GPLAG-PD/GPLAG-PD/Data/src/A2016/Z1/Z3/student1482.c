#include<stdio.h>
#include<ctype.h>
int main () {
char t;
float b=0,p=0,c=0,s=0,ps=0,v=0,pv=0,pb=0,pc=0,pp=0,n=0;
int u=0;
printf ("Unesite vozila: ");
while (1)
{
    scanf ("%c",&t);
    if(!isdigit(t))
    {
        if (t=='c' || t=='C')
        {
            c++;
            u++;
            pc+=(1./u);
        }
        else if(t=='b' || t=='B')
        {
            b++;
            u++;
            pb+=(1./u);
        }
         else if(t=='v' || t=='V')
        {
            v++;
            u++;
            pv+=(1./u);
        }
         else if(t=='p' || t=='P')
        {
            p++;
            u++;
            pp+=(1./u);
        }
         else if(t=='s' || t=='S')
        {
            s++;
            u++;
            ps+=(1./u);
        }
         else if(t=='k' || t=='K')
        {
            break;
        }
        else
        printf("Neispravan unos\n");
        }
        else printf("Neispravan unos\n");
}
printf("Ukupno evidentirano %d vozila.",u);
if(u==0)
{
    n=0;
    printf("\nNajpopularnija boja je crna (%.2f%%).",n);
}
else if((s<p && b<p && c<p &&v<p) || (s<=p && b<=p && c<=p && v<=p && ps<pp && pb<pp && pc<pp && pv<pp))
{
    n=(p/u)*100;
    printf("\nNajpopularnija boja je plava (%.2f%%).",n); 
}
else if ((s<b && p<b && c<b && v<b) || (s<=b && b>=p && c<=b && v<=b && ps<pb && pb>pp && pc<pb && pv<pb))
{ n=(b/u)*100;;
    printf("\nNajpopularnija boja je bijela (%.2f%%).",n); 
}
else if ((s>b && b<s && c<s && v<s) || (s>=p && b<=s && c<=s && v<=s && ps>pp && pb<ps && pc<ps && pv<ps))
{ n=(s/u)*100;;
 printf("\nNajpopularnija boja je siva (%.2f%%).",n);
}
else if ((s<v && b<v && c<v && v>p) || (s<=v && b<=v && c<=v && v>p && ps<pv && pb<pv && pc<pv && pv>pp))
{ n=(v/u)*100;;
 printf("\nNajpopularnija boja je crvena (%.2f%%).",n);
}
else if((s<c && b<c && c>p && v<c) || (s<=c && b<=c && c>=p && v<=c && ps<pc && pb<pc && pc>pp && pv<pc))
{ n=(c/u)*100;;
printf("\nNajpopularnija boja je crna (%.2f%%).",n);
}
return 0;
}

