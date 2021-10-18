#include <stdio.h>

struct Tacka {
    float x,y;
};

struct Kruznica {
    struct Tacka centar;
    float poluprecnik;
};

struct Pravougaonik {
    struct Tacka p1;
    int visina, sirina;
};

struct Trougao {
    struct Tacka vrh1;
    struct Tacka vrh2;
    struct Tacka vrh3;
};

enum TipOblika {TACKA, KRUZNICA, PRAVOUGAONIK, TROUGAO};

struct Tacka unos_tacke() {
    struct Tacka c;
    printf ("Unesite tacku: ");
    scanf ("%f%f", &c.x, &c.y);
    return c;
}

struct Kruznica unos_kruznice () {
    struct Kruznica k;
    printf ("Unesite centar kruznice: ");
    k.centar=unos_tacke();
    printf ("Unesite poluprecnik kruznice: ");
    scanf ("%f", &k.poluprecnik);
    return k;
}

struct Pravougaonik unos_pravougaonika () {
    struct Pravougaonik p;
    printf ("Unesite donji lijevi ugao: ");
    p.p1=unos_tacke();
    printf ("Unesite sirinu: ");
    scanf ("%d", &p.visina);
    printf ("Unesite visinu: ");
    scanf ("%d", &p.sirina);
    return p;
}

struct Trougao unos_trougla () {
    struct Trougao t;
    printf ("Unesite prvi vrh: ");
    t.vrh1=unos_tacke();
    printf ("Unesite drugi vrh: ");
    t.vrh2=unos_tacke();
    printf ("Unesite drugi vrh: ");
    t.vrh3=unos_tacke();
    return t;
}

struct Trougao unos_trougla () {
    struct Trougao t;
    printf ("Unesite prvi vrh: ");
    t.vrh1=unos_tacke();
    printf ("Unesite drugi vrh: ");
    t.vrh2=unos_tacke();
    printf ("Unesite drugi vrh: ");
    t.vrh3=unos_tacke();
    return t;
}

float maksimum (struct Tacka t1, struct Tacka t2) {
    int max;
    max=t1;
    if (t1>t2) {
        if (t1>t3) max=t1.x;
        else max=t3;
    }
    else {
        if (t2>t2) max=t2:
        else max=t3;
    }
  return max;  
}
    
float minimum (struct Tacka t1, struct Tacka t2) {
    int min;
    min=t1;
    if (t1<t2) {
        if (t1<t3) min=t1.x;
        else min=t3;
    }
    else {
        if (t2<t2) min=t2:
        else min=t3;
    }
    return min;
}
    
    int maxy;
    maxy=t1.y;
    if (t1.y>t2.y) {
        if (t1.y>t3.y) maxy=t1.y;
        else maxy=t3.y;
    }
    else {
        if (t2.y>t2.y) maxy=t2.y:
        else maxy=t3.y;
    }
    
     int miny;
    miny=t1.y;
    if (t1.y<t2.y) {
        if (t1.y<t3.y) miny=t1.y;
        else miny=t3.y;
    }
    else {
        if (t2.y<t2.y) miny=t2.y:
        else miny=t3.y;
    }
    
    return maxx;
}

int obuhvata (void* oblik1, TipOblika to1, void* oblik2, TipOblika to2) {
    if (to1==KRUZNICA) {
        struct Kruznica* k=(struct Kruznica*) oblik1;
       /* printf ("Kruznica sa radijusom %g\n", k->radijus);*/
    } 
    else if (to1==TROUGAO && to2==PRAVOUGAONIK) {
        struct Trougao* tr=(struct Trougao*) oblik2;
        tr->t.vrh1;
        tr->t.vrh2;
        tr->t.vrh3;
    }
}


int main() {
    int tip;
    int broj;
    int i;
	do {
	    i=0;
	    printf ("Unesite broj oblika: ");
	    scanf ("%d", &broj);
    	printf ("Odaberite tip %d. oblika (1-tacka, 2-kruznica, 3-pravougaonik, 4- trougao): ", i+1);
    	scanf ("%d", &tip[i]);
    	switch (tip[i]) {
    	    case 1:
    	    tip[i]=unos_tacke();
    	    case 2;
    	    tip[i]=unos_kruznice();
    	    case 3;
    	    tip[i]=unos_pravougaonika();
    	    case 4;
    	    tip[i]=unos_trougla();
    	    default: 
    	    printf ("Nepoznat tip oblika %d", &tip);
    	}
    	i++;
	} while (i>broj);
	
    funkc=obuhvata(broj[i],tip[i], broj[i+1], tip[i+1]);
    
	return 0;
}
