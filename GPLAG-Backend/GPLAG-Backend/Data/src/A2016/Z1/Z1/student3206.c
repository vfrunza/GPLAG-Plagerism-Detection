#include <stdio.h>

int main() {
	double t1,t2,tz,tp,ti,m1,m2,mz,mp,mi,b1,b2,bz,bi,bp,t,m,b;
	int o1,o2,o3;
	printf("Unesite bodove za Tarika: ");
	printf("\nI parcijalni ispit: ");
	scanf("%lf",&t1);
	if(t1<0 || t1>20){
	printf("\nNeispravan broj bodova");
	return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf",&t2);
	if(t2<0 || t2>20){
	    printf("\nNeispravan broj bodova");
	return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf",&tp);
	if(tp<0 || tp>10){
	    printf("Neispravan broj bodova");
	return 0;
	}
	printf("Zadace: ");
	scanf("%lf",&tz);
	if(tz<0 || tz>10){
	    printf("Neispravan broj bodova");
	return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf",&ti);
	if(ti<0 || ti>40){
	    printf("Nesipravan broj bodova");
	return 0;
	}
	printf("Unesite bodove za Bojana: ");
	printf("\nI parcijalni ispit: ");
	scanf("%lf",&b1);
	if(b1<0 || b1>20){
	    printf("Neispravan broj bodova");
	return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf",&b2);
	if(b2<0 || b2>20){
	    printf("Neispravan broj bodova");
	return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf",&bp);
	if(bp<0 || bp>10){
	    printf("Neispravan broj bodova");
	return 0;
	}
    printf("Zadace: ");
    scanf("%lf",&bz);
    if(bz<0 || bz>10){
        printf("Neispravan broj bodova");
	return 0;
    }
    printf("Zavrsni ispit: ");
    scanf("%lf",&bi);
    if(bi<0 || bi>40){
        printf("Neispravan broj bodova");
	return 0;
    }
    printf("Unesite bodove za Mirzu: ");
    printf("\nI parcijalni ispit: ");
    scanf("%lf",&m1);
    if(m1<0 || m1>20){
        printf("Neispravan broj bodova");
	return 0;
    }
    printf("II parcijalni ispit: ");
    scanf("%lf",&m2);
    if(m2<0 || m2>20){
        printf("Neispravan broj bodova");
	return 0;
    }
    printf("Prisustvo: ");
    scanf("%lf",&mp);
    if(mp<0 || mp>10){
        printf("Neispravan broj bodova");
	return 0;
    }
    printf("Zadace: ");
    scanf("%lf",&mz);
    if(mz<0 || mz>10){
        printf("Neispravan broj bodova");
	return 0;
    }
    printf("Zavrsni ispit: ");
    scanf("%lf",&mi);
    if(mi<0 || mi>40){
        printf("Neispravan broj bodova");
	return 0;
    }
    	t=t1+t2+tp+tz+ti;
    	m=m1+m2+mp+mz+mi;
    	b=b1+b2+bp+bz+bi;
        if(t<65){
        o1=6;
        }
        else if(t<75){
        o1=7;
        }
        else if(t<85){
        o1=8;
        }
        else if(t<92){
        o1=9;
        }
        else{
        o1=10;
        }
        if(m<65){
        o2=6;
        }
        else if(m<75){
        o2=7;
        }
        else if(m<85){
        o2=8;
        }
        else if(m<92){
        o2=9;
        }
        else{
        o2=10;
        }
        if(b<65){
        o3=6;
        }
        else if(b<75){
        o3=7;
        }
        else if(b<85){
        o3=8;
        }
        else if(b<92){
        o3=9;
        }
        else{
        o3=10;
        }
        if(t<55 && m<55 && b<55)
        printf("Nijedan student nije polozio.");
        else if(t>=55 && m>=55 && b>=55){
        printf("Sva tri studenta su polozila.");
        if(o1==o2 && o2==o3)
        printf("\nSva tri studenta imaju istu ocjenu.");
        else if(o1==o2 || o2==o3 || o1==o3)
        printf("\nDva od tri studenta imaju istu ocjenu.");
        else
        printf("\nSvaki student ima razlicitu ocjenu.");
        }
        else if(t>=55 && m<55 && b<55 || t<55 && m>=55 && b<55 || t<55 && m<55 && b>=55)
        printf("Jedan student je polozio.");
        else
        printf("Dva studenta su polozila.");
	return 0;
}
