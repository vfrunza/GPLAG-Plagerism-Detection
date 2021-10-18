#include <stdio.h>

int main () {
    
    char a;
    
    int bc=0, bs=0, bp=0, bb=0, bv=0, max;
    
    float udio, sum;
    
    printf("Unesite vozila: ");
    do{
        
        scanf("%c", &a);
        
        if(a=='b'||a=='B'||a=='c'||a=='C'||a=='P'||a=='p'||a=='V'||a=='v'||a=='S'||a=='s'||a=='K'||a=='k'){
            
            if(a=='C'||a=='c'){bc=bc+1;}
            else if(a=='B'||a=='b'){bb=bb+1;}
            else if(a=='P'||a=='p'){bp=bp+1;}
            else if(a=='V'||a=='v'){bv=bv+1;}
            else if(a=='S'||a=='s'){bs=bs+1;}
            
        }
        
        
        else if(a!='b'&&a!='B'&&a!='c'&&a!='C'&&a!='P'&&a!='p'&&a!='V'&&a!='v'&&a!='S'&&a!='s'&&a!='K'&&a!='k'){printf("Neispravan unos\n");}
        
        }
    while(a!='K'&&a!='k');
    
    sum=bc+bp+bb+bv+bs;
    max=bc;
    
    if(bb>max) max=bb;
    if(bs>max) max=bs;
    if(bv>max) max=bv;
    if(bp>max) max=bp;
    
    udio=max*100/sum;
    
    if(sum==0) {printf("Ukupno evidentirano 0 vozila.\n"); {printf("Najpopularnija boja je crna (0.00%%).\n");}}
    else{printf("Ukupno evidentirano %g vozila.\n", sum);
        if(bc==max){printf("Najpopularnija boja je crna (%.2f%%).\n", udio);}
        else if(bb==max){printf("Najpopularnija boja je bijela (%.2f%%).\n", udio);}
        else if(bs==max){printf("Najpopularnija boja je siva (%.2f%%).\n", udio);}
        else if(bv==max){printf("Najpopularnija boja je crvena (%.2f%%).\n", udio);}
        else if(bp==max){printf("Najpopularnija boja je plava (%.2f%%).\n", udio);}
    }

    
    return 0;
}