#include <stdio.h>

int main() {
	int i, j, k, m, n, p;
	float a, b, c, a1, a2, a3, a4, a5, b1, b2, b3, b4, b5, c1, c2, c3, c4, c5;
	printf ("Unesite bodove za Tarika:\n");
	printf ("I parcijalni ispit: ");
	scanf ("%f", &a1);
	if (a1<0 || a1>20) {
		printf ("Neispravan broj bodova");
		return 0;
	} else {
		printf ("II parcijalni ispit: ");
		scanf ("%f", &a2);
	} if (a2<0 || a2>20) {
		printf ("Neispravan broj bodova");
		return 0;
	} else {
		printf ("Prisustvo: ");
		scanf ("%f", &a3);
	} if (a3<0 || a3>10) {
		printf ("Neispravan broj bodova");
		return 0;
	} else {
		printf ("Zadace: ");
		scanf ("%f", &a4);
	} if (a4<0 || a4>10) {
		printf ("Neispravan broj bodova");
		return 0;
	} else {
		printf ("Zavrsni ispit: ");
		scanf ("%f", &a5);
	} if (a5<0 || a5>40) {
		printf ("Neispravan broj bodova");
		return 0;
	}
	printf ("Unesite bodove za Bojana:\n");
	printf ("I parcijalni ispit: ");
	scanf ("%f", &b1);
	if (b1<0 || b1>20) {
		printf ("Neispravan broj bodova");
		return 0;
	} else {
		printf ("II parcijalni ispit: ");
		scanf ("%f", &b2);
	} if (b2<0 || b2>20) {
		printf ("Neispravan broj bodova");
		return 0;
	} else {
		printf ("Prisustvo: ");
		scanf ("%f", &b3);
	} if (b3<0 || b3>10) {
		printf ("Neispravan broj bodova");
		return 0;
	} else {
		printf ("Zadace: ");
		scanf ("%f", &b4);
	} if (b4<0 || b4>10) {
		printf ("Neispravan broj bodova");
		return 0;
	} else {
		printf ("Zavrsni ispit: ");
		scanf ("%f", &b5);
	} if (b5<0 || b5>40) {
		printf ("Neispravan broj bodova");
		return 0;
	}
	printf ("Unesite bodove za Mirzu:\n");
	printf ("I parcijalni ispit: ");
	scanf ("%f", &c1);
	if (c1<0 || c1>20) {
		printf ("Neispravan broj bodova");
		return 0;
	} else {
		printf ("II parcijalni ispit: ");
		scanf ("%f", &c2);
	} if (c2<0 || c2>20) {
		printf ("Neispravan broj bodova");
		return 0;
	} else {
		printf ("Prisustvo: ");
		scanf ("%f", &c3);
	} if (c3<0 || c3>10) {
		printf ("Neispravan broj bodova");
		return 0;
	} else {
		printf ("Zadace: ");
		scanf ("%f", &c4);
	} if (c4<0 || c4>10) {
		printf ("Neispravan broj bodova");
		return 0;
	} else {
		printf ("Zavrsni ispit: ");
		scanf ("%f", &c5);
	} if (c5<0 || c5>40) {
		printf ("Neispravan broj bodova");
		return 0;
	}
	a=a1+a2+a3+a4+a5;
	b=b1+b2+b3+b4+b5;
	c=c1+c2+c3+c4+c5;
	if (a<55) {
		i=0;
	} else {
		i=1;
		if (a>=55 && a<65) {
			m=6;
		} else {
			if (a>=65 && a<75) {
				m=7;
			} else {
				if (a>=75 && a<85) {
					m=8;
				} else {
					if (a>=85 && a<95) {
						m=9;
					} else {
						m=10;
					}
				}
			}
		}
	}
	if (b<55) {
		j=0;
	} else {
		j=1;
		if (b>=55 && b<65) {
			n=6;
		} else {
			if (b>=65 && b<75) {
				n=7;
			} else {
				if (b>=75 && b<85) {
					n=8;
				} else {
					if (b>=85 && b<95) {
						n=9;
					} else {
						n=10;
					}
				}
			}
		}
	}
	if (c<55) {
		k=0;
	} else {
		k=1;
		if (c>=55 && c<65) {
			p=6;
		} else {
			if (c>=65 && c<75) {
				p=7;
			} else {
				if (c>=75 && c<85) {
					p=8;
				} else {
					if (c>=85 && c<95) {
						p=9;
					} else {
						p=10;
					}
				}
			}
		}
	}
	if (i+j+k==0) {
		printf ("Nijedan student nije polozio.\n");
	} else {
		if (i+j+k==1) {
			printf ("Jedan student je polozio.\n");
		} else {
			if (i+j+k==2) {
				printf ("Dva studenta su polozila.\n");
			} else {
				printf ("Sva tri studenta su polozila.\n");
				if (m==n && n==p) {
					printf ("Sva tri studenta imaju istu ocjenu.");
				} else {
					if (m==n || n==p) {
						printf ("Dva od tri studenta imaju istu ocjenu.");
					} else {
						printf ("Svaki student ima razlicitu ocjenu.");
					}
				}
			}
		}
	}
	return 0;
}
