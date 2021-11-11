#include <stdio.h>

int main () {
    int br_c=0,br_b=0,br_s=0,br_v=0,br_p=0,uk,max;
    char c='c';
    float pr_c,pr_b,pr_s,pr_v,pr_p;
    printf ("Unesite vozila: ");
    while (1){
        scanf ("%c",&c);

    if (c=='c' || c=='C')
        br_c++;
    else if (c=='b' || c=='B')
        br_b++;
    else if (c=='s' || c=='S')
        br_s++;
    else if (c=='v' || c=='V')
        br_v++;
    else if (c=='p' || c=='P')
        br_p++;
    else if (c=='k' || c=='K')
        break;
    else
        printf ("Neispravan unos\n");
        
    }   
    uk=br_c+br_b+br_s+br_v+br_p;
    printf ("Ukupno evidentirano %d vozila.",uk);
    max=br_c;
    if (br_b>max) max=br_b;
    if (br_s>max) max=br_s;
    if (br_v>max) max=br_v;
    if (br_p>max) max=br_p;
    
    if (br_c==max){
    pr_c=(float)br_c/uk*100;
    if (uk==0) pr_c=0;
    printf ("\nNajpopularnija boja je crna (%.2f%%).",pr_c);
    }
    else if (br_b==max){
    pr_b=(float)br_b/uk*100;
    printf ("\nNajpopularnija boja je bijela (%.2f%%).",pr_b);
    }
    else if (br_s==max){
    pr_s=(float)br_s/uk*100;
    printf ("\nNajpopularnija boja je siva (%.2f%%).",pr_s);
    }
    else if (br_v==max){
    pr_v=(float)br_v/uk*100;
    printf ("\nNajpopularnija boja je crvena (%.2f%%).",pr_v);
    }
    else if (br_p==max){
    pr_p=(float)br_p/uk*100;
    printf ("\nNajpopularnija boja je plava (%.2f%%).",pr_p);
    }

    return 0;
    
}