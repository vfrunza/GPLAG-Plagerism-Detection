#include <stdio.h>
#include <stlib.h>
#include <math.h>

struct Tacka {
 double x,y;
};

struct Kruznica {
 Tacka centar;
 double poluprecnik;
};

struct Pravougaonik {
 Tacka*lijeviDonji;
 double visina,sirina;
};


struct Trougao {
 Tacka* prviVrh,drugiVrh,treciVrh;
};

