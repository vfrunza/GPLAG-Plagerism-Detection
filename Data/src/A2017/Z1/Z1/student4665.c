#include <stdio.h>
#define p1 6.80
#define h1 3.30
#define c1 5.00
#define p2 8.00
#define h2 3.00
#define c2 3.90
#define p3 5.30
#define h3 5.00
#define c3 6.00
int main()
{
    float suma1,suma2,suma3,suma1a,suma2a,suma3a,suma1b,suma2b,suma3b,suma1c,suma2c,suma3c,suma1d,suma2d,suma3d,suma1e,suma2e,suma3e,suma1f,suma2f,suma3f,
    suma1g,suma2g,suma3g,suma1h,suma2h,suma3h,suma1i,suma2i,suma3i,
    popust1,popust1a,popust1b,popust1pc,popust1pcc,popust1d,popust1dd,popust1e,popust1ee,p1f,p1ff,pg,pgg,ph,phh,pih,pic,pip,
    suma1p,suma1pa,suma1pb,suma1pc,suma1pcc,suma1pd,suma1pdd,suma1pe,suma1pee,suma1pf,suma1pff,suma1pg,suma1pgg,suma1ph,suma1phh,sumapih,sumapic,sumapip;
    char tarik,bojan,mirza,novi_red;
    printf("Unesite jelo za Tarika: ");
    scanf("%c", &tarik);
    scanf("%c", &novi_red);
    printf("Unesite jelo za Bojana: ");
    scanf("%c", &bojan);
    scanf("%c", &novi_red);
    printf("Unesite jelo za Mirzu: ");
    scanf("%c", &mirza);
    scanf("%c", &novi_red);
    if(tarik=='H' && bojan=='H' && mirza=='H') {
        suma1=3*h1;
        suma2=3*h2;
        suma3=3*h3;
        popust1=h1/10;
        suma1p=suma1-3*popust1;
        if(suma1<suma2 && suma1<suma3) {
            printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", suma1);
        }else if(suma2<suma3 && suma2<suma1 && suma1p<suma2) {
            printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", suma2);
            printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", suma1p);
        }else if(suma2<suma3 && suma2<suma1){
            printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", suma2);
        }else if(suma3<suma1 && suma3<suma2 && suma1<suma3) {
            printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", suma3);
            printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", suma1p);
        }else if(suma3<suma2 && suma3<suma1){
            printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", suma3);
        }
    }else if(tarik=='P' && bojan=='P' && mirza=='P') {
        suma1a=3*p1;
        suma2a=3*p2;
        suma3a=3*p3;
        popust1a=p1/10;
        suma1pa=suma1a-3*popust1a;
        if(suma1a<suma2a && suma1a<suma3a) {
            printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", suma1a);
        }else if(suma2a<suma1a && suma2a<suma3a && suma1pa<suma2a) {
            printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", suma2a);
            printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", suma1pa);
        }else if(suma2a<suma1a && suma2a<suma3a){
            printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", suma2a);
        }else if(suma3a<suma1a && suma3a<suma2a && suma1pa<suma3a) {
            printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", suma3a);
            printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", suma1pa);
        }else if(suma3a<suma1a && suma3a<suma2a){
            printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", suma3a);
            }
        }else if(tarik=='C' && bojan=='C' && mirza=='C') {
        suma1b=3*c1;
        suma2b=3*c2;
        suma3b=3*c3;
        popust1b=c1/10;
        suma1pb=suma1b-3*popust1b;
        if(suma1b<suma2b && suma1b<suma3b) {
            printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", suma1b);
        }else if(suma2b<suma1b && suma2b<suma3b && suma1pb<suma2b) {
            printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", suma2b);
            printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", suma1pb);
        }else if(suma2b<suma1b && suma2b<suma3b){
            printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", suma2b);
        }else if(suma3b<suma1b && suma3b<suma2b && suma1pb<suma3b) {
            printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", suma3b);
            printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", suma1pb);
        }else if(suma3b<suma1b && suma3b<suma2b){
            printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", suma3b);
        }
        }else if((tarik=='H' && bojan=='H' && mirza=='C') || (tarik=='H' && bojan=='C' && mirza=='H') || (tarik=='C' && bojan=='H' && mirza=='H')) {
        suma1c=2*h1+c1;
        suma2c=2*h2+c2;
        suma3c=2*h3+c3;
        popust1pc=h1/10;
        popust1pcc=c1/10;
        suma1pc=suma1c-2*popust1pc;
        suma1pcc=suma1c-popust1pcc;
        if(suma1c<suma2c && suma1c<suma3c) {
            printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", suma1c);
        } else if(suma2c<suma1c && suma2c<suma3c && suma1pc<suma2c) {
            printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", suma2c);
            printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", suma1pc);
        } else if(suma2c<suma1c && suma2c<suma3c && suma1pcc<suma2c) {
             printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", suma2c);
             printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", suma1pcc);
        }else if(suma2c<suma1c && suma2c<suma3c){
            printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", suma2c);
        } else if(suma3c<suma1c && suma3c<suma2c && suma1pc<suma3c){
            printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", suma3c);
            printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", suma1pc);
        }else if(suma3c<suma1c && suma3c<suma2c && suma1pcc<suma3c){
            printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", suma3c);
            printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", suma1pcc);
        }else if(suma3c<suma1c && suma3c<suma2c){
            printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", suma3c);
        }
    }else if((tarik=='H' && bojan=='H' && mirza=='P') || (tarik=='H' && bojan=='P' && mirza=='H') || (tarik=='P' && bojan=='H' && mirza=='H')){
        suma1d=h1*2+p1;
        suma2d=h2*2+p2;
        suma3d=h3*2+p3;
        popust1d=h1/10;
        popust1dd=p1/10;
        suma1pd=suma1d-2*popust1d;
        suma1pdd=suma1d-popust1dd;
        if(suma1d<suma2d && suma1d<suma3d){
            printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", suma1d);
        }else if(suma2d<suma1d && suma2d<suma3d && suma1pd<suma2d){
            printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", suma2d);
            printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", suma1pd);
        }else if(suma2d<suma1d && suma2d<suma3d && suma1pdd<suma2d){
            printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", suma2d);
            printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", suma1pdd);
        }else if(suma2d<suma1d && suma2d<suma3d){
            printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", suma2d);
        }else if(suma3d<suma1d && suma3d<suma2d && suma1pd<suma3d){
            printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", suma3d);
            printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", suma1pd);
        }else if(suma3d<suma1d && suma3d<suma2d && suma1pdd<suma3d){
            printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", suma3d);
            printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", suma1pdd);
        }else if(suma3d<suma1d && suma3d<suma2d){
            printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", suma3d);
        }
    }else if((tarik=='P' && bojan=='P' && mirza=='H') || (tarik=='P' && bojan=='H' && mirza=='P') || (tarik=='H' && bojan=='P' && mirza=='P')){
        suma1e=p1*2+h1;
        suma2e=p2*2+h2;
        suma3e=p3*2+h3;
        popust1e=p1/10;
        popust1ee=h1/10;
        suma1pe=suma1e-2*popust1e;
        suma1pee=suma1e-popust1ee;
        if(suma1e<suma2e && suma1e<suma3e){
            printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", suma1e);
        }else if(suma2e<suma1e && suma2e<suma3e && suma1pe<suma2e){
            printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", suma2e);
            printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", suma1pe);
        }else if(suma2e<suma1e && suma2e<suma3e && suma1pee<suma2e){
            printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM)", suma2e);
            printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM)", suma1pee);
        }else if(suma2e<suma1e && suma2e<suma3e){
            printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM)", suma2e);
        }else if(suma3e<suma1e && suma3e<suma2e && suma1pe<suma3e){
            printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", suma3e);
            printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", suma1pe);
        }else if(suma3e<suma1e && suma3e<suma1e && suma1pee<suma3e){
            printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", suma3e);
            printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", suma1pee);
        }else if(suma3e<suma1e && suma3e<suma1e){
            printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", suma3e);
        }
    }else if((tarik=='P' && bojan=='P' && mirza=='C') || (tarik=='P' && bojan=='C' && mirza=='P') || (tarik=='C' && bojan=='P' && mirza=='P')){
        suma1f=p1*2+c1;
        suma2f=p2*2+c2;
        suma3f=p3*2+c3;
        p1f=p1/10;
        p1ff=c1/10;
        suma1pf=suma1f-2*p1f;
        suma1pff=suma1f-p1ff;
        if(suma1f<suma2f && suma1f<suma3f){
            printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", suma1f);
        }else if(suma2f<suma1f && suma2f<suma3f && suma1pf<suma2f){
            printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", suma2f);
            printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", suma1pf);
        }else if(suma2f<suma1f && suma2f<suma3f && suma1pff<suma2f){
            printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", suma2f);
            printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", suma1pff);
        }else if(suma2f<suma1f && suma2f<suma3f){
            printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", suma2f);
        }else if(suma3f<suma1f && suma3f<suma2f && suma1pf<suma3f){
            printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", suma3f);
            printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", suma1pf);
        }else if(suma3f<suma1f && suma3f<suma2f && suma1pff<suma3f){
            printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", suma3f);
            printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", suma1pff);
        }else if(suma3f<suma1f && suma3f<suma2f){
            printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", suma3f);
        }
    }else if((tarik=='C' && bojan=='C' && mirza=='H') || (tarik=='C' && bojan=='H' && mirza=='C') || (tarik=='H' && bojan=='C' && mirza=='C')){
        suma1g=2*c1+h1;
        suma2g=2*c2+h2;
        suma3g=2*c3+h3;
        pg=c1/10;
        pgg=h1/10;
        suma1pg=suma1g-2*pg;
        suma1pgg=suma1g-pgg;
        if(suma1g<suma2g && suma1g<suma3g){
        printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", suma1g);
        }else if(suma2g<suma1g && suma2g<suma3g && suma1pg<suma2g){
            printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", suma2g);
            printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", suma1pg);
        }else if(suma2g<suma1g && suma2g<suma3g && suma1pgg<suma2g){
            printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", suma2g);
            printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", suma1pgg);
        }else if(suma2g<suma1g && suma2g<suma3g){
            printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", suma2g);
        }else if(suma3g<suma1g && suma3g<suma2g && suma1pg<suma3g){
            printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", suma3g);
            printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", suma1pg);
        }else if(suma3g<suma1g && suma3g<suma2g && suma1pgg<suma3g){
            printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", suma3g);
            printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", suma1pgg);
        }else if(suma3g<suma1g && suma3g<suma2g){
            printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", suma3g);
        }
    }else if((tarik=='C' && bojan=='C' && mirza=='P') || (tarik=='C' && bojan=='P' && mirza=='C') || (tarik=='P' && bojan=='C' && mirza=='C')){
        suma1h=2*c1+p1;
        suma2h=2*c2+p2;
        suma3h=2*c3+p3;
        ph=c1/10;
        phh=p1/10;
        suma1ph=suma1h-ph;
        suma1phh=suma1h-phh;
        if(suma1h<suma2h && suma1h<suma3h){
            printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", suma1h);
        }else if(suma2h<suma1h && suma2h<suma3h && suma1ph<suma2h){
            printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", suma2h);
            printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", suma1ph);
        }else if(suma2h<suma3h && suma2h<suma1h && suma1phh<suma2h){
            printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", suma2h);
            printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", suma1phh);
        }else if(suma2h<suma3h && suma2h<suma1h){
            printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", suma2h);
        }else if(suma3h<suma1h && suma3h<suma2h && suma1ph<suma3h){
            printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", suma3h);
            printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", suma1ph);
        }else if(suma3h<suma1h && suma3h<suma2h && suma1phh<suma3h){
            printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", suma3h);
            printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", suma1phh);
        }else if(suma3h<suma1h && suma3h<suma2h){
            printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", suma3h);
        }
    }else if((tarik=='H' && bojan=='P' && mirza=='C') || (tarik=='P' && bojan=='H' && mirza=='C') || (tarik=='C' && bojan=='H' && mirza=='P') || (tarik=='P' && bojan=='C' && mirza=='H') || (tarik=='H' && mirza=='C' && mirza=='P') || (tarik=='C' && bojan=='P' && mirza=='H')){
        suma1i=h1+c1+p1;
        suma2i=h2+c2+p2;
        suma3i=h3+c3+p3;
        pih=h1/10;
        pic=c1/10;
        pip=p1/10;
        sumapih=suma1i-pih;
        sumapic=suma1i-pic;
        sumapip=suma1i-pip;
        if(suma1i<suma2i && suma1i<suma3i){
            printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).\n", suma1i);
        }else if(suma2i<suma1i && suma2i<suma3i && sumapih<suma2i && sumapih<sumapip && sumapih<sumapic){
            printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", suma2i);
            printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", sumapih);
        }else if(suma2i<suma1i && suma2i<suma3i && sumapic<suma2i && sumapic<sumapip && sumapic<sumapih){
            printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", suma2i);
            printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", sumapic);
        }else if(suma2i<suma1i && suma2i<suma3i && sumapip<suma2i && sumapip<sumapih && sumapip<sumapic){
            printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", suma2i);
            printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", sumapip);
        }else if(suma2i<suma1i && suma2i<suma3i){
            printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", suma2i);
        }else if(suma3i<suma1i && suma3i<suma2i && sumapih<suma2i && sumapih<sumapip && sumapih<sumapic){
            printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", suma3i);
            printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", sumapih);
        }else if(suma3i<suma1i && suma3i<suma2i && sumapic<suma3i && sumapic<sumapip && sumapic<sumapih){
            printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", suma3i);
            printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", sumapic);
        }else if(suma3i<suma1i && suma3i<suma2i && sumapip<suma3i && sumapip<sumapic && sumapip<sumapih){
            printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", suma3i);
            printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).\n", sumapip);
        }else if(suma3i<suma1i && suma3i<suma2i){
            printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", suma3i);
        }
    }
    return 0;
}
