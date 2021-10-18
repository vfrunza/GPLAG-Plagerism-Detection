#include <stdio.h>
#include <math.h>

#define EPSILON 0.001

enum TipOblika {
	TACKA,
	KRUZNICA,
	PRAVOUGAONIK,
	TROUGAO
};

struct Tacka {
	double x, y;
};

struct Kruznica {
	struct Tacka centar;
	double radijus;
};

struct Pravougaonik {
	struct Tacka dolje_lijevo;
	double visina, sirina;
};

struct Trougao {
	struct Tacka tacka1, tacka2, tacka3;
};

union shapeGroup {
	struct Tacka point;
	struct Kruznica circle;
	struct Pravougaonik rect;
	struct Trougao triangle;
};

struct Oblik {
	enum TipOblika shapeType;
	
	union shapeGroup shape;
};

struct Tacka unos_tacke() {
	struct Tacka tmp;
	
	printf("koordinate x,y: ");
	scanf("%lf,%lf", &tmp.x, &tmp.y);
	
	return tmp;
}

double distance(struct Tacka, struct Tacka);
int isInPoint(struct Tacka*, void*, enum TipOblika);
int isInCircle(struct Kruznica*, void*, enum TipOblika);
int isInRect(struct Pravougaonik*, void*, enum TipOblika);
int isInTriangle(struct Trougao*, void*, enum TipOblika);
int obuhvata(void*, enum TipOblika, void*, enum TipOblika);

int main() {
	struct Oblik shapes[50];
	int n, type;
	int i, j;
	
	printf("Unesite broj oblika: ");
	scanf("%d", &n);
	
	for (i = 0; i < n; i++) {
		printf("Odaberite tip %d. oblika (1 - tacka, 2 - kruznica, 3 - pravougaonik, 4 - trougao): ", i + 1);
		scanf("%d", &type);
		
		if (type < 1 || type > 4) {
			printf("Nepoznat tip oblika %d!\n", type);
			i--;
			continue;
		}
		
		if (type == 1) {
			shapes[i].shapeType = TACKA;
			
			printf("Unesite tacku: ");
			shapes[i].shape.point = unos_tacke();
		}
		else if (type == 2) {
			shapes[i].shapeType = KRUZNICA;
			
			printf("Unesite centar kruznice: ");
			shapes[i].shape.circle.centar = unos_tacke();
			printf("Unesite poluprecnik kruznice: ");
			scanf("%lf", &shapes[i].shape.circle.radijus);
		}
		else if (type == 3) {
			shapes[i].shapeType = PRAVOUGAONIK;
			
			printf("Unesite donji lijevi ugao: ");
			shapes[i].shape.rect.dolje_lijevo = unos_tacke();
			printf("Unesite sirinu: ");
			scanf("%lf", &shapes[i].shape.rect.sirina);
			printf("Unesite visinu: ");
			scanf("%lf", &shapes[i].shape.rect.visina);
		}
		else {
			shapes[i].shapeType = TROUGAO;
			
			printf("Unesite prvi vrh: ");
			shapes[i].shape.triangle.tacka1 = unos_tacke();
			printf("Unesite drugi vrh: ");
			shapes[i].shape.triangle.tacka2 = unos_tacke();
			printf("Unesite treci vrh: ");
			shapes[i].shape.triangle.tacka3 = unos_tacke();
		}
	}
	
	printf("\n");
	
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			if (i != j && obuhvata(&shapes[i].shape, shapes[i].shapeType,
								   &shapes[j].shape, shapes[j].shapeType))
				printf("Oblik %d obuhvata oblik %d.\n", i + 1, j + 1);
	
	return 0;
}

int obuhvata(void* shape1, enum TipOblika shape1Type,
			 void* shape2, enum TipOblika shape2Type) {
	switch(shape1Type) {
		case TACKA:
			return isInPoint((struct Tacka*)(shape1), shape2, shape2Type);
		case KRUZNICA:
			return isInCircle((struct Kruznica*)(shape1), shape2, shape2Type);
		case PRAVOUGAONIK:
			return isInRect((struct Pravougaonik*)(shape1), shape2, shape2Type);
		case TROUGAO:
			return isInTriangle((struct Trougao*)(shape1), shape2, shape2Type);
	}
	
	return -1;
}

double distance(struct Tacka p1, struct Tacka p2) {
	return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

int isInPoint(struct Tacka* point, void* shape, enum TipOblika shapeType) {
	if (shapeType == TACKA)
		return fabs(point->x - ((struct Tacka*)(shape))->x) < EPSILON &&
			   fabs(point->y - ((struct Tacka*)(shape))->y) < EPSILON;
			   
	if (shapeType == KRUZNICA)
		return fabs(((struct Kruznica*)(shape))->radijus) < EPSILON &&
			   isInPoint(point, &(((struct Kruznica*)(shape))->centar), TACKA);
			   
	if (shapeType == PRAVOUGAONIK)
		return fabs(((struct Pravougaonik*)(shape))->sirina) < EPSILON &&
			   fabs(((struct Pravougaonik*)(shape))->visina) < EPSILON &&
			   isInPoint(point, &(((struct Pravougaonik*)(shape))->dolje_lijevo), TACKA);
			   
	if (shapeType == TROUGAO)
		return isInPoint(point, &(((struct Trougao*)(shape))->tacka1), TACKA) &&
			   isInPoint(point, &(((struct Trougao*)(shape))->tacka2), TACKA) &&
			   isInPoint(point, &(((struct Trougao*)(shape))->tacka3), TACKA);
			   
	return -1;
}

int isInCircle(struct Kruznica* circle, void* shape, enum TipOblika shapeType) {
	/* Ova tacka sluzi za pomoc ukoliko je oblik koji se treba nalaziti unutra pravougaonik */
	struct Tacka gore_desno;
	switch (shapeType) {
		case TACKA:
			return distance(circle->centar, *(struct Tacka*)(shape)) <= circle->radijus;
			
		case KRUZNICA:
			return (distance(circle->centar, ((struct Kruznica*)(shape))->centar)) +
				   (((struct Kruznica*)(shape))->radijus) <= circle->radijus;
				   
		case PRAVOUGAONIK:
			gore_desno.x = ((struct Pravougaonik*)(shape))->dolje_lijevo.x +
						   ((struct Pravougaonik*)(shape))->sirina;
			gore_desno.y = ((struct Pravougaonik*)(shape))->dolje_lijevo.y +
						   ((struct Pravougaonik*)(shape))->visina;
			return distance(circle->centar, gore_desno) <= circle->radijus &&
				   distance(circle->centar, ((struct Pravougaonik*)(shape))->dolje_lijevo) <= circle->radijus;
		
		case TROUGAO:
			return distance(circle->centar, ((struct Trougao*)(shape))->tacka1) <= circle->radijus &&
				   distance(circle->centar, ((struct Trougao*)(shape))->tacka2) <= circle->radijus &&
				   distance(circle->centar, ((struct Trougao*)(shape))->tacka3) <= circle->radijus;
	}
	
	return -1;
}

int isInRect(struct Pravougaonik* rect, void* shape, enum TipOblika shapeType) {
	if (shapeType == TACKA)
		return ((struct Tacka*)(shape))->x <= rect->dolje_lijevo.x + rect->sirina &&
			   ((struct Tacka*)(shape))->x >= rect->dolje_lijevo.x &&
			   ((struct Tacka*)(shape))->y <= rect->dolje_lijevo.y + rect->visina &&
			   ((struct Tacka*)(shape))->y >= rect->dolje_lijevo.y;
	
	if (shapeType == KRUZNICA) {
		struct Kruznica *k = (struct Kruznica*)(shape);
		return (k->centar.x + k->radijus <= rect->dolje_lijevo.x + rect->sirina) &&
			   (k->centar.x - k->radijus >= rect->dolje_lijevo.x) &&
			   (k->centar.y + k->radijus <= rect->dolje_lijevo.y + rect->visina) &&
			   (k->centar.y - k->radijus >= rect->dolje_lijevo.y);
	}
	
	if (shapeType == PRAVOUGAONIK) {
		struct Pravougaonik *p = (struct Pravougaonik*)(shape);
		return (p->dolje_lijevo.x + p->sirina <= rect->dolje_lijevo.x + rect->sirina) &&
			   (p->dolje_lijevo.x >= rect->dolje_lijevo.x) &&
			   (p->dolje_lijevo.y + p->visina <= rect->dolje_lijevo.y + rect->visina) &&
			   (p->dolje_lijevo.y >= rect->dolje_lijevo.y);
	}
	
	if (shapeType == TROUGAO) {
		struct Trougao *t = (struct Trougao*)(shape);
		
		return isInRect(rect, &(t->tacka1), TACKA) &&
			   isInRect(rect, &(t->tacka2), TACKA) &&
			   isInRect(rect, &(t->tacka3), TACKA);
	}
	
	return -1;
}

int isInTriangle(struct Trougao* triangle, void* shape, enum TipOblika shapeType) {
	if (fabs(triangle->tacka1.x - triangle->tacka2.x) < EPSILON &&
		fabs(triangle->tacka2.x - triangle->tacka3.x) < EPSILON &&
		fabs(triangle->tacka1.y - triangle->tacka2.y) < EPSILON &&
		fabs(triangle->tacka2.y - triangle->tacka3.y) < EPSILON)
		return isInPoint(&(triangle->tacka1), shape, shapeType);
	
	if (shapeType == TACKA) {
		struct Tacka *t = (struct Tacka*)(shape);
		
		/* Mozemo definirati vektore preko strukture tacka
		   Algoritam opisan na: http://blackpawn.com/texts/pointinpoly */
		struct Tacka v0, v1, vt;
		double dot00, dot01, dot0t, dot11, dot1t;
		double u, v;
		
		v0.x = triangle->tacka3.x - triangle->tacka1.x;
		v0.y = triangle->tacka3.y - triangle->tacka1.y;
		
		v1.x = triangle->tacka2.x - triangle->tacka1.x;
		v1.y = triangle->tacka2.y - triangle->tacka1.y;
		
		vt.x = t->x - triangle->tacka1.x;
		vt.y = t->y - triangle->tacka1.y;
		
		/* Racunanje skalarnog proizvoda izmedju svih vektora */
		dot00 = v0.x * v0.x + v0.y * v0.y;
		dot01 = v0.x * v1.x + v0.y * v1.y;
		dot0t = v0.x * vt.x + v0.y * vt.y;
		dot11 = v1.x * v1.x + v1.y * v1.y;
		dot1t = v1.x * vt.x + v1.y * vt.y;
		
		/* Racunanje koordinata tacke u bazi vectora [C-A] i [B-A] */
		u = (dot11 * dot0t - dot01 * dot1t) / (dot00 * dot11 - dot01 * dot01);
		v = (dot00 * dot1t - dot01 * dot0t) / (dot00 * dot11 - dot01 * dot01);
		
		return (u >= 0) && (v >= 0) && (u + v <= 1 + EPSILON);
	}
	
	if (shapeType == KRUZNICA) {
		struct Kruznica *k = (struct Kruznica*)(shape);
		
		struct Tacka v12, v13, v23;
		struct Tacka vp1, vp2;
		
		double dot12p, dot13p, dot23p;
		double v12sq, v13sq, v23sq;
		double vp1sq, vp2sq;
		
		v12.x = triangle->tacka2.x - triangle->tacka1.x;
		v12.y = triangle->tacka2.y - triangle->tacka1.y;
		
		v13.x = triangle->tacka3.x - triangle->tacka1.x;
		v13.y = triangle->tacka3.y - triangle->tacka1.y;
		
		v23.x = triangle->tacka3.x - triangle->tacka2.x;
		v23.y = triangle->tacka3.y - triangle->tacka2.y;
		
		vp1.x = -triangle->tacka1.x + k->centar.x;
		vp1.y = -triangle->tacka1.y + k->centar.y;
		
		vp2.x = -triangle->tacka2.x + k->centar.x;
		vp2.y = -triangle->tacka2.y + k->centar.y;
		
		dot12p = v12.x * vp1.x + v12.y * vp1.y;
		dot13p = v13.x * vp1.x + v13.y * vp1.y;
		dot23p = v23.x * vp2.x + v23.y * vp2.y;
		
		v12sq = v12.x * v12.x + v12.y * v12.y;
		v13sq = v13.x * v13.x + v13.y * v13.y;
		v23sq = v23.x * v23.x + v23.y * v23.y;
		
		vp1sq = vp1.x * vp1.x + vp1.y * vp1.y;
		vp2sq = vp2.x * vp2.x + vp2.y * vp2.y;
		
		/*printf("%5f %5f %5f\n", vp1sq - dot12p * dot12p / v12sq - (k->radijus) * (k->radijus),
							 vp1sq - dot13p * dot13p / v13sq,
							 vp2sq - dot23p * dot23p / v23sq);*/
		
		return isInTriangle(triangle, &(k->centar), TACKA) &&
			   vp1sq - dot12p * dot12p / v12sq - (k->radijus) * (k->radijus) > EPSILON &&
			   vp1sq - dot13p * dot13p / v13sq - (k->radijus) * (k->radijus) > EPSILON &&
			   vp2sq - dot23p * dot23p / v23sq - (k->radijus) * (k->radijus) > EPSILON;
	}
	
	if (shapeType == PRAVOUGAONIK) {
		struct Pravougaonik *p = (struct Pravougaonik*)(shape);
		struct Tacka gore_lijevo, dolje_desno, gore_desno;
		
		gore_lijevo.x = p->dolje_lijevo.x;
		gore_lijevo.y = p->dolje_lijevo.y + p->visina;
		
		dolje_desno.x = p->dolje_lijevo.x + p->sirina;
		dolje_desno.y = p->dolje_lijevo.y;
		
		gore_desno.x = p->dolje_lijevo.x + p->sirina;
		gore_desno.y = p->dolje_lijevo.y + p->visina;
		
		return isInTriangle(triangle, &(p->dolje_lijevo), TACKA) &&
			   isInTriangle(triangle, &gore_lijevo, TACKA) &&
			   isInTriangle(triangle, &dolje_desno, TACKA) &&
			   isInTriangle(triangle, &gore_desno, TACKA);
	}
	
	if (shapeType == TROUGAO) {
		struct Trougao *t = (struct Trougao*)(shape);
		
		return isInTriangle(triangle, &(t->tacka1), TACKA) &&
			   isInTriangle(triangle, &(t->tacka2), TACKA) &&
			   isInTriangle(triangle, &(t->tacka3), TACKA);
	}
	return -1;
}