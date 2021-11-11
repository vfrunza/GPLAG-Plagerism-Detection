#include <stdio.h>

int main()
{   char x;
    char* maxColor;
    int c=0, b=0, s=0, v=0, p=0, total;
    float y, max=0;
    printf("Unesite vozila: ");
    do {
    scanf("%c", &x);
    if(x=='C' || x=='c') { c++;
        if (c>max) { max = c; maxColor = "crna";
            }
    }   else if(x=='B' || x=='b') { b++;
            if (b>max) { max = b; maxColor = "bijela";
            }
    }
    else if(x=='S' || x=='s') { s++;
        if (s>max) { max = s; maxColor = "siva";
            }
    } else if(x=='V' || x=='v') { v++;
    if (v>max) { max = v; maxColor = "crvena";
            }
    }
    else if(x=='P' || x=='p') { p++;
    if (p>max) { max = p; maxColor = "plava";
            }
    } else if (x!='K'&& x!='k' && x!='\n') {
        printf("Neispravan unos\n");
            }
    }
    while (x!='K' && x!='k');
    total=c+b+s+v+p;
    y=(max/total)*100;
    printf("Ukupno evidentirano %i vozila.\n", total);
    if(total==0) {
        printf("Najpopularnija boja je crna (0.00%%).");
        } else {
    printf("Najpopularnija boja je %s (%.2f%%).", maxColor, y);
        }
    return 0;
}