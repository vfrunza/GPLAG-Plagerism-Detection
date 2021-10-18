#include <stdio.h>

int main() {
	 double a, b, c, d, e, f, g, h, o, p, r, s, t, u, v, sum1, sum2, sum3;
	 int t1, b1, m1;
		printf("Unesite bodove za Tarika:\n");
		
	printf("I parcijalni ispit: ");
	scanf("%lf", &a);
	if (a>20||a<0){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf", &b);
		if (b>20||b<0){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf", &c);
		if (c>10||c<0){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%lf", &d);
		if (d>10||d<0){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf", &e);
		if (e>40||e<0){
		printf("Neispravan broj bodova");
		return 0;
	}
		printf("Unesite bodove za Bojana:\n");
	printf("I parcijalni ispit: ");
	scanf("%lf", &f);
		if (f>20||f<0){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf", &g);
		if (g>20||g<0){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf", &h);
		if (h>10||h<0){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%lf", &o);
		if (o>10||o<0){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf", &p);
		if (p>40||p<0){
		printf("Neispravan broj bodova");
		return 0;
	}
		printf("Unesite bodove za Mirzu:\n");
	printf("I parcijalni ispit: ");
	scanf("%lf", &r);
		if (r>20||r<0){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf", &s);
		if (s>20||s<0){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf", &t);
		if (t>10||t<0){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%lf", &u);
		if (u>10||u<0){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf", &v);
		if (v>40||v<0){
		printf("Neispravan broj bodova");
		return 0;
	}
	sum1=(a+b+c+d+e);
	sum2=(f+g+h+o+p);
	sum3=(r+s+t+u+v);

		if(sum1<55.00 && sum2<55.00 && sum3<55.00){
			printf("Nijedan student nije polozio.");
		}
			else if(sum1>=55.00 && sum2<55.00 && sum3<55.00 || sum2>=55.00 && sum1<55.00 && sum3<55.00 || sum3>=55.00 && sum1<55.00 && sum2<55.00){
			printf("Jedan student je polozio.\n");
		}
			else if(sum1>=55.00 && sum2>=55.00 && sum3<55.00 || sum1>=55.00 && sum3>=55.00 && sum2<55.00 || sum2>=55.00 && sum3>=55.00 && sum1<55.00){
				printf("Dva studenta su polozila.\n");
			}
			else if (sum1>=55.00 && sum2>=55.00 && sum3>=55.00){
				printf("Sva tri studenta su polozila.\n");
			}

		if(sum1>=55.00 && sum1<65){
		t1=6;}
			if(sum1>=65.00 && sum1<75){
		t1=7;}
			if(sum1>=75.00 && sum1<85){
		t1=8;}
			if(sum1>=85.00 && sum1<92){
		t1=9;}
			if(sum1>=92.00 && sum1<100){
		t1=10;}
		
		if(sum2>=55.00 && sum2<65){
		b1=6;}
			if(sum2>=65.00 && sum2<75){
		b1=7;}
			if(sum2>=75.00 && sum2<85){
		b1=8;}
			if(sum2>=85.00 && sum2<92){
		b1=9;}
			if(sum2>=92.00 && sum2<100){
		b1=10;}
		
		if(sum3>=55.00 && sum3<65){
		m1=6;}
			if(sum3>=65.00 && sum3<75){
		m1=7;}
			if(sum3>=75.00 && sum3<85){
		m1=8;}
			if(sum3>=85.00 && sum3<92){
		m1=9;}
			if(sum3>=92.00 && sum3<100){
		m1=10;}
		
			if(sum1>=55.00 && sum2>=55.00 && sum3>=55.00){
		if(t1==b1 && b1==m1 && t1==m1){
			printf("Sva tri studenta imaju istu ocjenu.");
		}
		else if(t1==b1 || t1==m1 || m1==b1){
			printf("Dva od tri studenta imaju istu ocjenu.");
		}
		else if(t1!=b1 && b1!=m1 && t1!=m1){
			printf("Svaki student ima razlicitu ocjenu.");
		}
	}		
	return 0;
}
