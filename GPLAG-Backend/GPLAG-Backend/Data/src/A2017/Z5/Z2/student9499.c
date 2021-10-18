#include <stdio.h>
#include <math.h>
#define ERR	0.001
#define SIZE	50
#define SQR(x) ((x)*(x))

/* structures for objects */
enum TipOblika { TACKA = 0, KRUZNICA, PRAVOUGAONIK, TROUGAO };
typedef enum TipOblika TipOblika;

struct Tacka {
	double x,y;
};
struct Kruznica {
	struct Tacka centar;
	double radijus;
};
struct Pravougaonik {
	struct Tacka dole_lijevo;
	double visina, sirina;
};
struct Trougao {
	struct Tacka vrh1, vrh2, vrh3;
};
struct Oblik {
	int tip;
	struct Kruznica circle;
	struct Pravougaonik rectangle;
	struct Trougao triangle;
	struct Tacka point;
};

/* input functions prototypes */
struct Tacka unos_tacke();
struct Kruznica unos_kruznice();
struct Pravougaonik unos_pravougaonika();
struct Trougao unos_trougla();

/* check for same types */
double distance(struct Tacka t1, struct Tacka t2) {
	return (SQR(t1.x - t2.x) + SQR(t1.y - t2.y));
}

/* triangle area */
double trigArea(struct Tacka t1, struct Tacka t2, struct Tacka t3) {
	return (fabs(t1.x*(t2.y - t3.y) + t2.x*(t3.y - t1.y) + t3.x*(t1.y - t2.y))/2);
}

/* point in triangle */
int trianglePoint(struct Tacka t, struct Trougao tr) {
	double Area = trigArea(tr.vrh1, tr.vrh2, tr.vrh3);
	double newArea[3], summedArea = 0.;
	
	newArea[0] = trigArea(t, tr.vrh1, tr.vrh2);
	newArea[1] = trigArea(t, tr.vrh2, tr.vrh3);
	newArea[2] = trigArea(t, tr.vrh1, tr.vrh3);
	summedArea = newArea[0] + newArea[1] + newArea[2];
	
	if(fabs(summedArea - Area) < ERR)
		return 1;
	else if(newArea[0] < ERR || newArea[1] < ERR || newArea[1] < ERR)
		if(fabs(summedArea/2 - Area) < ERR)
			return 1;
	return 0;
}

/* check if a point is in rectangle */
int tacka_pravougaonik(struct Tacka point, struct Pravougaonik pravougaonik) {
	struct Tacka gore_desno, dole_lijevo;
	dole_lijevo = pravougaonik.dole_lijevo;
	gore_desno.x = dole_lijevo.x + pravougaonik.sirina;
	gore_desno.y = dole_lijevo.y + pravougaonik.visina;
	if(((dole_lijevo.x - point.x) > ERR) || ((point.x - gore_desno.x) > ERR))
		return 0;
	if(((dole_lijevo.y - point.y) > ERR) || ((point.y - gore_desno.y) > ERR))
		return 0;
	return 1;	
}

/* point in circle */
int tacka_krug(struct Tacka t, struct Kruznica k) {
	double dist = distance(t, k.centar);
	if((SQR(k.radijus) - dist) > ERR) 
		return 1;
	return 0;
}

/* circle - rectangle */
int circle_rectangle(struct Kruznica circle, struct Pravougaonik rectangle) {
	struct Tacka t[4];
	int _validity = 0;
	t[0].x = circle.centar.x; 					t[0].y = circle.centar.y + circle.radijus;
	t[1].x = t[0].x;							t[1].y = circle.centar.y - circle.radijus;
	t[2].x = circle.centar.x - circle.radijus;		t[2].y = circle.centar.y;
	t[3].x = circle.centar.x + circle.radijus;		t[3].y = t[2].y;

	_validity = tacka_pravougaonik(t[0], rectangle) + tacka_pravougaonik(t[1], rectangle);
	_validity += tacka_pravougaonik(t[2], rectangle) + tacka_pravougaonik(t[3], rectangle);
	if(_validity == 4) return 1;
	return 0;
}

/* mathematically proven to check if circle crosses triangle */
int lineCross(struct Tacka centar, struct Tacka t1, struct Tacka t2, double R) {
	double k, koef;
	if(fabs(t2.x - t1.x) < ERR) k = 0;
	else k = (t2.y - t1.y)/(t2.x - t1.x);
	koef = (SQR(R*k) + SQR(R) - SQR(centar.x*k) + 2*centar.x*centar.y*k + 2*centar.x*SQR(k)*t1.x - 2*centar.x*k*t1.y - SQR(centar.y) - 2*centar.y*k*t1.x + 2*centar.y*t1.y - SQR(k*t1.x) + 2*k*t1.x*t1.y - SQR(t1.y));
	if(koef > ERR)
		return 1;
	return 0;
}

int circle_triangle(struct Kruznica circle, struct Trougao triangle) {
	int _validity = 0;
	if(!trianglePoint(circle.centar, triangle))
		return 0;
	_validity = lineCross(circle.centar, triangle.vrh1, triangle.vrh2, (circle.radijus));
	if(_validity > 0) return 0;
	_validity = lineCross(circle.centar, triangle.vrh1, triangle.vrh3, (circle.radijus));
	if(_validity > 0) return 0;
	_validity = lineCross(circle.centar, triangle.vrh2, triangle.vrh3, (circle.radijus));
	if(_validity > 0) return 0;
	return 1;
}

int triangle_circle(struct Trougao triangle, struct Kruznica circle) {
	int _validity = 0;
	_validity = tacka_krug(triangle.vrh1, circle) + tacka_krug(triangle.vrh2, circle) + tacka_krug(triangle.vrh2, circle);
	if(_validity == 3) 
		return 1;
	return 0;
}

int rectangle_triangle(struct Pravougaonik rectangle, struct Trougao triangle) {
	struct Tacka t[4];
	int _validity = 0;
	t[0].x = rectangle.dole_lijevo.x;					 	t[0].y = rectangle.dole_lijevo.y;
	t[1].x = rectangle.dole_lijevo.x + rectangle.sirina;		t[1].y = t[0].y;
	t[2].x = t[0].x; 									t[2].y = rectangle.dole_lijevo.y + rectangle.visina;
	t[3].x = t[1].x;									t[3].y = t[2].y;
	
	_validity = trianglePoint(t[0], triangle) + trianglePoint(t[1], triangle);
	_validity += trianglePoint(t[2], triangle) + trianglePoint(t[3], triangle);
	if(_validity == 4) return 1;
	return 0;
}

/* FUNCTION TO IMPLEMENT */
int obuhvata(void* oblik1, enum TipOblika tip1, void* oblik2, enum TipOblika tip2) {
	/* initial */
	int _validity = 0;
	double deltax = 0, deltay = 0;
	
	/* convert the types */
	struct Oblik shape1, shape2;
	if(tip1 == TACKA) { struct Tacka* shape = (struct Tacka*) oblik1; 						shape1.point = *shape; }
	else if(tip1 == KRUZNICA) { struct Kruznica* shape = (struct Kruznica*) oblik1; 			shape1.circle = *shape; }
	else if(tip1 == PRAVOUGAONIK) { struct Pravougaonik* shape = (struct Pravougaonik*) oblik1; 	shape1.rectangle = *shape; }
	else if(tip1 == TROUGAO) { struct Trougao* shape = (struct Trougao*) oblik1; 				shape1.triangle = *shape; }
	shape1.tip = tip1;
	
	if(tip2 == TACKA) { struct Tacka* shape = (struct Tacka*) oblik2; 						shape2.point = *shape; }
	else if(tip2 == KRUZNICA) { struct Kruznica* shape = (struct Kruznica*) oblik2; 			shape2.circle = *shape; }
	else if(tip2 == PRAVOUGAONIK) { struct Pravougaonik* shape = (struct Pravougaonik*) oblik2; 	shape2.rectangle = *shape; }
	else if(tip2 == TROUGAO) { struct Trougao* shape = (struct Trougao*) oblik2; 				shape2.triangle = *shape; }
	shape2.tip = tip1;
	
	/* start testing */
	if(tip1 == tip2) {
		/* point - point */
		if(tip1 == TACKA) {
			if(distance(shape1.point, shape2.point) < ERR)
				return 1;
		}
		/* circle - circle */
		else if(tip1 == KRUZNICA) {
			if((distance(shape1.circle.centar, shape2.circle.centar) + shape2.circle.radijus)-ERR < (shape1.circle.radijus)) 
				return 1;
		}
		/* rectangle - rectangle */
		else if(tip1 == PRAVOUGAONIK) {
			deltax = (shape1.rectangle.dole_lijevo.x - shape2.rectangle.dole_lijevo.x);
			deltay = (shape1.rectangle.dole_lijevo.y - shape2.rectangle.dole_lijevo.y);
			if((deltax < ERR) && (deltay < ERR) &&
				((shape1.rectangle.visina-shape2.rectangle.visina+deltay) > -ERR) &&
				((shape1.rectangle.sirina-shape2.rectangle.sirina+deltax) > -ERR))
				return 1;
		}
		/* triangle - triangle */
		else if(tip1 == TROUGAO) {
			_validity = trianglePoint(shape2.triangle.vrh1, shape1.triangle);
			_validity += trianglePoint(shape2.triangle.vrh2, shape1.triangle);
			_validity += trianglePoint(shape2.triangle.vrh3, shape1.triangle);
			if(_validity == 3) return 1;
		}
		return 0;
	}
	else {
		/* point in bodies */
		if(tip2 == TACKA) {
			if(tip1 == KRUZNICA) {
				if(shape1.circle.radijus > ERR) return (tacka_krug(shape2.point, shape1.circle));
				else return (distance(shape2.point, shape1.circle.centar) < ERR);
			}
			else if(tip1 == PRAVOUGAONIK) {
				if(shape1.rectangle.visina > ERR || shape1.rectangle.sirina > ERR) return (tacka_pravougaonik(shape2.point, shape1.rectangle));
				else return (distance(shape1.rectangle.dole_lijevo, shape2.point) < ERR);
			}
			else if(tip1 == TROUGAO) return (trianglePoint(shape2.point, shape1.triangle));
		}
		/* circle in bodies */
		else if(tip2 == KRUZNICA) {
			if(tip1 == TACKA)			return ((fabs(shape2.circle.radijus) < ERR) && (distance(shape2.circle.centar, shape1.point) < ERR));
			else if(tip1 == PRAVOUGAONIK) return (circle_rectangle(shape2.circle, shape1.rectangle));
			else if(tip1 == TROUGAO)		return (circle_triangle(shape2.circle, shape1.triangle));
		}
		/* rectangle in bodies */
		else if(tip2 == PRAVOUGAONIK) {
			if(tip1 == TACKA) 			return ((fabs(shape2.rectangle.visina) < ERR) && (fabs(shape2.rectangle.sirina) < ERR) && (distance(shape2.rectangle.dole_lijevo, shape1.point) < ERR));
			else if(tip1 == KRUZNICA) 	return (!circle_rectangle(shape1.circle, shape2.rectangle));
			else if(tip1 == TROUGAO) 	return (rectangle_triangle(shape2.rectangle, shape1.triangle));
		}
		/* triangle in bodies */
		else if(tip2 == TROUGAO) {
			if(tip1 == TACKA) {
				int check = ((distance(shape2.triangle.vrh1, shape1.point) < ERR) 
						&& (distance(shape2.triangle.vrh2, shape1.point) < ERR) 
						&& (distance(shape2.triangle.vrh3, shape1.point) < ERR));
				return check;
			}
			else if(tip1 == KRUZNICA) 	return (triangle_circle(shape2.triangle, shape1.circle));
			else if(tip1 == PRAVOUGAONIK) 
				return (tacka_pravougaonik(shape2.triangle.vrh1, shape1.rectangle) && 
				tacka_pravougaonik(shape2.triangle.vrh2, shape1.rectangle) && 
				tacka_pravougaonik(shape2.triangle.vrh3, shape1.rectangle));
		}
	}
	return 0;
}

/* main function */
int main() {
	/* initial */
	int i = 0, j = 0, n = 0, tip, _checked = 0, _num = 0;
	struct Oblik oblik[SIZE];
	
	/* input */
	do {
		printf("Unesite broj oblika: "); scanf("%d", &n);
	} while (n > SIZE || n < 1);
	
	do {
		printf("Odaberite tip %d. oblika (1 - tacka, 2 - kruznica, 3 - pravougaonik, 4 - trougao): ", i+1); 
		scanf("%d", &tip);
		if(tip < 1 || tip > 4) printf("Nepoznat tip oblika %d!\n", tip);
		else {
			switch(tip) {
				case 1: printf("Unesite tacku: "); oblik[i].point = unos_tacke(); break;
				case 2: oblik[i].circle = unos_kruznice(); break;
				case 3: oblik[i].rectangle = unos_pravougaonika(); break;
				case 4: oblik[i].triangle = unos_trougla(); break;
			}
			oblik[i].tip = tip-1;
			i++;
		}
	} while(i < n);
	
	printf("\n");
	/* print */
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			if(j != i) {
				/* hate this part of the code // lackness */
				_num = oblik[i].tip*4 + oblik[j].tip;
				switch(_num) {
					case 0: _checked = obuhvata(&oblik[i].point, TACKA, &oblik[j].point, TACKA); break;
					case 1: _checked = obuhvata(&oblik[i].point, TACKA, &oblik[j].circle, KRUZNICA); break;
					case 2: _checked = obuhvata(&oblik[i].point, TACKA, &oblik[j].rectangle, PRAVOUGAONIK); break;
					case 3: _checked = obuhvata(&oblik[i].point, TACKA, &oblik[j].triangle, TROUGAO); break;
					case 4: _checked = obuhvata(&oblik[i].circle, KRUZNICA, &oblik[j].point, TACKA); break;
					case 5: _checked = obuhvata(&oblik[i].circle, KRUZNICA, &oblik[j].circle, KRUZNICA); break;
					case 6: _checked = obuhvata(&oblik[i].circle, KRUZNICA, &oblik[j].rectangle, PRAVOUGAONIK); break;
					case 7: _checked = obuhvata(&oblik[i].circle, KRUZNICA, &oblik[j].triangle, TROUGAO); break;
					case 8: _checked = obuhvata(&oblik[i].rectangle, PRAVOUGAONIK, &oblik[j].point, TACKA); break;
					case 9: _checked = obuhvata(&oblik[i].rectangle, PRAVOUGAONIK, &oblik[j].circle, KRUZNICA); break;
					case 10: _checked = obuhvata(&oblik[i].rectangle, PRAVOUGAONIK, &oblik[j].rectangle, PRAVOUGAONIK); break;
					case 11: _checked = obuhvata(&oblik[i].rectangle, PRAVOUGAONIK, &oblik[j].triangle, TROUGAO); break;
					case 12: _checked = obuhvata(&oblik[i].triangle, TROUGAO, &oblik[j].point, TACKA); break;
					case 13: _checked = obuhvata(&oblik[i].triangle, TROUGAO, &oblik[j].circle, KRUZNICA); break;
					case 14: _checked = obuhvata(&oblik[i].triangle, TROUGAO, &oblik[j].rectangle, PRAVOUGAONIK); break;
					case 15: _checked = obuhvata(&oblik[i].triangle, TROUGAO, &oblik[j].triangle, TROUGAO); break;
					default: _checked = 0;
				}
				if(_checked) printf("Oblik %d obuhvata oblik %d.\n", i+1, j+1);
			}
		}
	}
	return 0;
}

/* input functions */
struct Tacka unos_tacke() {
	struct Tacka t;
	printf ("koordinate x,y: "); scanf ("%lf,%lf", &t.x, &t.y);
	return t;
}
struct Kruznica unos_kruznice() {
	struct Kruznica k;
	printf ("Unesite centar kruznice: "); k.centar = unos_tacke();
	printf ("Unesite poluprecnik kruznice: "); scanf("%lf", &k.radijus);
	return k;
}
struct Pravougaonik unos_pravougaonika() {
	struct Pravougaonik p;
	printf("Unesite donji lijevi ugao: "); p.dole_lijevo = unos_tacke();
	printf("Unesite sirinu: "); scanf("%lf", &p.sirina);
	printf("Unesite visinu: "); scanf("%lf", &p.visina);
	return p;
}
struct Trougao unos_trougla() {
	struct Trougao t;
	printf("Unesite prvi vrh: "); t.vrh1 = unos_tacke();
	printf("Unesite drugi vrh: "); t.vrh2 = unos_tacke();
	printf("Unesite treci vrh: "); t.vrh3 = unos_tacke();
	return t;
}