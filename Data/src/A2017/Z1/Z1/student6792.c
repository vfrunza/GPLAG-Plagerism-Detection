#include <stdio.h>

int main ()
{
    char T,B,M,P,H,C,novi_red;
    float rp,fp,bp,rh,fh,bh,rc,fc,bc,cr,cf,cb;

    printf("Unesite jelo za Tarika: ");
    scanf("%c",&T);
    scanf("%c", &novi_red);
    printf("Unesite jelo za Bojana: ");
    scanf("%c",&B);
    scanf("%c", &novi_red);
    printf("Unesite jelo za Mirzu: ");
    scanf("%c",&M);
    scanf("%c", &novi_red);

    /*cijena restorana - cr; cijena fast_food-a - cf; cijena bistroa - cb*/
    /*pizza*/
    rp=6.80;/*u restoranu*/
    fp=8.00;/*u fast_food-u*/
    bp=5.30;/*u bistrou*/

    /*hamburger*/
    rh=3.30; /*u restoranu*/
    fh=3.00; /*u fast_food-u*/
    bh=5.00; /*u bistrou*/

    /*cevapi*/
    rc=5.00; /*u restoranu*/
    fc=3.90; /*u fast_food-u*/
    bc=6.00; /*u bistrou*/

    if(T=='P' && B=='P' && M=='P') {
        cr=rp+rp+rp;
        cf=fp+fp+fp;
        cb=bp+bp+bp;

        if (cr>cf && cr>cb)
            printf("Najjeftiniji je Restoran \"Kod konja i konjušara\" (%g KM).",cr);
        else if (cf>cr && cf>cb)
            printf("Najjeftiniji je Fast-food \"Trovac\" (%g KM).",cf);
        else if (cb>cr && cb>cf)
            printf("Najjeftiniji je Bistro \"Lorelei\" (%g KM).",cb);
    } else if(T=='P' && B=='P' && M=='H') {
        cr=rp+rp+rh;
        cf=fp+fp+fh;
        cb=bp+bp+bh;

        if (cr>cf && cr>cb)
            printf("Najjeftiniji je Restoran \"Kod konja i konjušara\" (%g KM).",cr);
        else if (cf>cr && cf>cb)
            printf("Najjeftiniji je Fast-food \"Trovac\" (%g KM).",cf);
        else if (cb>cr && cb>cf)
            printf("Najjeftiniji je Bistro \"Lorelei\" (%g KM).",cb);
    } else if(T=='P' && B=='P' && M=='C') {
        cr=rp+rp+rc;
        cf=fp+fp+fc;
        cb=bp+bp+bc;
        if (cr>cf && cr>cb)
            printf("Najjeftiniji je Restoran \"Kod konja i konjušara\" (%g KM).",cr);
        else if (cf>cr && cf>cb)
            printf("Najjeftiniji je Fast-food \"Trovac\" (%g KM).",cf);
        else if (cb>cr && cb>cf)
            printf("Najjeftiniji je Bistro \"Lorelei\" (%g KM).",cb);
    } else if(T=='P' && B=='H' && M=='H') {
        cr=rp+rh+rh;
        cf=fp+rh+fh;
        cb=bp+bh+bh;
        if (cr>cf && cr>cb)
            printf("Najjeftiniji je Restoran \"Kod konja i konjušara\" (%g KM).",cr);
        else if (cf>cr && cf>cb)
            printf("Najjeftiniji je Fast-food \"Trovac\" (%g KM).",cf);
        else if (cb>cr && cb>cf)
            printf("Najjeftiniji je Bistro \"Lorelei\" (%g KM).",cb);
    } else if(T=='P' && B=='C' && M=='C') {
        cr=rp+rc+rc;
        cf=fp+fc+fc;
        cb=bp+bc+bc;
        if (cr>cf && cr>cb)
            printf("Najjeftiniji je Restoran \"Kod konja i konjušara\" (%g KM).",cr);
        else if (cf>cr && cf>cb)
            printf("Najjeftiniji je Fast-food \"Trovac\" (%g KM).",cf);
        else if (cb>cr && cb>cf)
            printf("Najjeftiniji je Bistro \"Lorelei\" (%g KM).",cb);
    } else if(T=='P' && B=='H' && M=='C') {
        cr=rp+rh+rc;
        cf=fp+fh+fc;
        cb=bp+bh+bc;
        if (cr>cf && cr>cb)
            printf("Najjeftiniji je Restoran \"Kod konja i konjušara\" (%g KM).",cr);
        else if (cf>cr && cf>cb)
            printf("Najjeftiniji je Fast-food \"Trovac\" (%g KM).",cf);
        else if (cb>cr && cb>cf)
            printf("Najjeftiniji je Bistro \"Lorelei\" (%g KM).",cb);
    } else if(T=='P' && B=='C' && M=='H') {
        cr=rp+rc+rh;
        cf=fp+fc+fh;
        cb=bp+bc+bh;
        if (cr>cf && cr>cb)
            printf("Najjeftiniji je Restoran \"Kod konja i konjušara\" (%g KM).",cr);
        else if (cf>cr && cf>cb)
            printf("Najjeftiniji je Fast-food \"Trovac\" (%g KM).",cf);
        else if (cb>cr && cb>cf)
            printf("Najjeftiniji je Bistro \"Lorelei\" (%g KM).",cb);
    } else if(T=='P' && B=='H' && M=='P') {
        cr=rp+rh+rp;
        cf=fp+fh+fp;
        cb=bp+bh+bp;
        if (cr>cf && cr>cb)
            printf("Najjeftiniji je Restoran \"Kod konja i konjušara\" (%g KM).",cr);
        else if (cf>cr && cf>cb)
            printf("Najjeftiniji je Fast-food \"Trovac\" (%g KM).",cf);
        else if (cb>cr && cb>cf)
            printf("Najjeftiniji je Bistro \"Lorelei\" (%g KM).",cb);
    } else if(T=='P' && B=='C' && M=='P') {
        cr=rp+rc+rp;
        cf=fp+fc+fp;
        cb=bp+bc+bp;
        if (cr>cf && cr>cb)
            printf("Najjeftiniji je Restoran \"Kod konja i konjušara\" (%g KM).",cr);
        else if (cf>cr && cf>cb)
            printf("Najjeftiniji je Fast-food \"Trovac\" (%g KM).",cf);
        else if (cb>cr && cb>cf)
            printf("Najjeftiniji je Bistro \"Lorelei\" (%g KM).",cb);
    } else if(T=='H' && B=='H' && M=='H') {
        cr=rh+rh+rh;
        cf=fh+fh+fh;
        cb=bh+bh+bh;
        if (cr>cf && cr>cb)
            printf("Najjeftiniji je Restoran \"Kod konja i konjušara\" (%g KM).",cr);
        else if (cf>cr && cf>cb)
            printf("Najjeftiniji je Fast-food \"Trovac\" (%g KM).",cf);
        else if (cb>cr && cb>cf)
            printf("Najjeftiniji je Bistro \"Lorelei\" (%g KM).",cb);
    } else if(T=='H' && B=='H' && M=='P') {
        cr=rh+rh+rp;
        cf=fh+fh+fp;
        cb=bh+bh+bp;
        if (cr>cf && cr>cb)
            printf("Najjeftiniji je Restoran \"Kod konja i konjušara\" (%g KM).",cr);
        else if (cf>cr && cf>cb)
            printf("Najjeftiniji je Fast-food \"Trovac\" (%g KM).",cf);
        else if (cb>cr && cb>cf)
            printf("Najjeftiniji je Bistro \"Lorelei\" (%g KM).",cb);
    } else if(T=='H' && B=='H' && M=='C') {
        cr=rh+rh+rc;
        cf=fh+fh+fc;
        cb=bh+bh+bc;
        if (cr>cf && cr>cb)
            printf("Najjeftiniji je Restoran \"Kod konja i konjušara\" (%g KM).",cr);
        else if (cf>cr && cf>cb)
            printf("Najjeftiniji je Fast-food \"Trovac\" (%g KM).",cf);
        else if (cb>cr && cb>cf)
            printf("Najjeftiniji je Bistro \"Lorelei\" (%g KM).",cb);
    } else if(T=='H' && B=='P' && M=='P') {
        cr=rh+rp+rp;
        cf=fh+fp+fp;
        cb=bh+bp+bp;
        if (cr>cf && cr>cb)
            printf("Najjeftiniji je Restoran \"Kod konja i konjušara\" (%g KM).",cr);
        else if (cf>cr && cf>cb)
            printf("Najjeftiniji je Fast-food \"Trovac\" (%g KM).",cf);
        else if (cb>cr && cb>cf)
            printf("Najjeftiniji je Bistro \"Lorelei\" (%g KM).",cb);
    } else if(T=='H' && B=='C' && M=='C') {
        cr=rh+rc+rc;
        cf=fh+fc+fc;
        cb=bh+bc+bc;
        if (cr>cf && cr>cb)
            printf("Najjeftiniji je Restoran \"Kod konja i konjušara\" (%g KM).",cr);
        else if (cf>cr && cf>cb)
            printf("Najjeftiniji je Fast-food \"Trovac\" (%g KM).",cf);
        else if (cb>cr && cb>cf)
            printf("Najjeftiniji je Bistro \"Lorelei\" (%g KM).",cb);
    } else if(T=='H' && B=='P' && M=='C') {
        cr=rh+rp+rc;
        cf=fh+fp+fc;
        cb=bh+bp+bc;
        if (cr>cf && cr>cb)
            printf("Najjeftiniji je Restoran \"Kod konja i konjušara\" (%g KM).",cr);
        else if (cf>cr && cf>cb)
            printf("Najjeftiniji je Fast-food \"Trovac\" (%g KM).",cf);
        else if (cb>cr && cb>cf)
            printf("Najjeftiniji je Bistro \"Lorelei\" (%g KM).",cb);
    } else if(T=='H' && B=='C' && M=='P') {
        cr=rh+rc+rp;
        cf=fh+fc+fp;
        cb=bh+bc+bp;
        if (cr>cf && cr>cb)
            printf("Najjeftiniji je Restoran \"Kod konja i konjušara\" (%g KM).",cr);
        else if (cf>cr && cf>cb)
            printf("Najjeftiniji je Fast-food \"Trovac\" (%g KM).",cf);
        else if (cb>cr && cb>cf)
            printf("Najjeftiniji je Bistro \"Lorelei\" (%g KM).",cb);
    } else if(T=='H' && B=='P' && M=='H') {
        cr=rh+rp+rh;
        cf=fh+fp+fh;
        cb=bh+bp+bh;
        if (cr>cf && cr>cb)
            printf("Najjeftiniji je Restoran \"Kod konja i konjušara\" (%g KM).",cr);
        else if (cf>cr && cf>cb)
            printf("Najjeftiniji je Fast-food \"Trovac\" (%g KM).",cf);
        else if (cb>cr && cb>cf)
            printf("Najjeftiniji je Bistro \"Lorelei\" (%g KM).",cb);
    } else if(T=='H' && B=='C' && M=='H') {
        cr=rh+rc+rh;
        cf=fh+fc+fh;
        cb=bh+bc+bh;
        if (cr>cf && cr>cb)
            printf("Najjeftiniji je Restoran \"Kod konja i konjušara\" (%g KM).",cr);
        else if (cf>cr && cf>cb)
            printf("Najjeftiniji je Fast-food \"Trovac\" (%g KM).",cf);
        else if (cb>cr && cb>cf)
            printf("Najjeftiniji je Bistro \"Lorelei\" (%g KM).",cb);
    } else if(T=='C' && B=='C' && M=='C') {
        cr=rc+rc+rc;
        cf=fc+fc+fc;
        cb=bc+bc+bc;
        if (cr>cf && cr>cb)
            printf("Najjeftiniji je Restoran \"Kod konja i konjušara\" (%g KM).",cr);
        else if (cf>cr && cf>cb)
            printf("Najjeftiniji je Fast-food \"Trovac\" (%g KM).",cf);
        else if (cb>cr && cb>cf)
            printf("Najjeftiniji je Bistro \"Lorelei\" (%g KM).",cb);
    } else if(T=='C' && B=='C' && M=='P') {
        cr=rc+rc+rp;
        cf=fc+fc+fp;
        cb=bc+bc+bp;
        if (cr>cf && cr>cb)
            printf("Najjeftiniji je Restoran \"Kod konja i konjušara\" (%g KM).",cr);
        else if (cf>cr && cf>cb)
            printf("Najjeftiniji je Fast-food \"Trovac\" (%g KM).",cf);
        else if (cb>cr && cb>cf)
            printf("Najjeftiniji je Bistro \"Lorelei\" (%g KM).",cb);
    } else if(T=='C' && B=='C' && M=='H') {
        cr=rc+rc+rh;
        cf=fc+fc+fh;
        cb=bc+bc+bh;
        if (cr>cf && cr>cb)
            printf("Najjeftiniji je Restoran \"Kod konja i konjušara\" (%g KM).",cr);
        else if (cf>cr && cf>cb)
            printf("Najjeftiniji je Fast-food \"Trovac\" (%g KM).",cf);
        else if (cb>cr && cb>cf)
            printf("Najjeftiniji je Bistro \"Lorelei\" (%g KM).",cb);
    } else if(T=='C' && B=='P' && M=='P') {
        cr=rc+rp+rp;
        cf=fc+fp+fp;
        cb=bc+bp+bp;
        if (cr>cf && cr>cb)
            printf("Najjeftiniji je Restoran \"Kod konja i konjušara\" (%g KM).",cr);
        else if (cf>cr && cf>cb)
            printf("Najjeftiniji je Fast-food \"Trovac\" (%g KM).",cf);
        else if (cb>cr && cb>cf)
            printf("Najjeftiniji je Bistro \"Lorelei\" (%g KM).",cb);
    } else if(T=='C' && B=='H' && M=='H') {
        cr=rc+rh+rh;
        cf=fc+fh+fh;
        cb=bc+bh+bh;
        if (cr>cf && cr>cb)
            printf("Najjeftiniji je Restoran \"Kod konja i konjušara\" (%g KM).",cr);
        else if (cf>cr && cf>cb)
            printf("Najjeftiniji je Fast-food \"Trovac\" (%g KM).",cf);
        else if (cb>cr && cb>cf)
            printf("Najjeftiniji je Bistro \"Lorelei\" (%g KM).",cb);
    } else if(T=='C' && B=='P' && M=='H') {
        cr=rc+rp+rh;
        cf=fc+fp+fh;
        cb=bc+bp+bh;
        if (cr>cf && cr>cb)
            printf("Najjeftiniji je Restoran \"Kod konja i konjušara\" (%g KM).",cr);
        else if (cf>cr && cf>cb)
            printf("Najjeftiniji je Fast-food \"Trovac\" (%g KM).",cf);
        else if (cb>cr && cb>cf)
            printf("Najjeftiniji je Bistro \"Lorelei\" (%g KM).",cb);
    } else if(T=='C' && B=='H' && M=='P') {
        cr=rc+rh+rp;
        cf=fc+fh+fp;
        cb=bc+bh+bp;
        if (cr>cf && cr>cb)
            printf("Najjeftiniji je Restoran \"Kod konja i konjušara\" (%g KM).",cr);
        else if (cf>cr && cf>cb)
            printf("Najjeftiniji je Fast-food \"Trovac\" (%g KM).",cf);
        else if (cb>cr && cb>cf)
            printf("Najjeftiniji je Bistro \"Lorelei\" (%g KM).",cb);
    } else if(T=='C' && B=='H' && M=='C') {
        cr=rc+rh+rc;
        cf=fc+fh+fc;
        cb=bc+bh+bc;
        if (cr>cf && cr>cb)
            printf("Najjeftiniji je Restoran \"Kod konja i konjušara\" (%g KM).",cr);
        else if (cf>cr && cf>cb)
            printf("Najjeftiniji je Fast-food \"Trovac\" (%g KM).",cf);
        else if (cb>cr && cb>cf)
            printf("Najjeftiniji je Bistro \"Lorelei\" (%g KM).",cb);
    } else if(T=='C' && B=='P' && M=='C') {
        cr=rc+rp+rc;
        cf=fc+fp+fc;
        cb=bc+bp+bc;
        if (cr>cf && cr>cb)
            printf("Najjeftiniji je Restoran \"Kod konja i konjušara\" (%g KM).",cr);
        else if (cf>cr && cf>cb)
            printf("Najjeftiniji je Fast-food \"Trovac\" (%g KM).",cf);
        else if (cb>cr && cb>cf)
            printf("Najjeftiniji je Bistro \"Lorelei\" (%g KM).",cb);
    }



    return 0;
}
