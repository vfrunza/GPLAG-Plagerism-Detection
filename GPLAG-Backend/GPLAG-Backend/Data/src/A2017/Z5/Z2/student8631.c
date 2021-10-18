#include <stdio.h>
#include<math.h>

//enum TipOblika{TACKA, KRUZNICA, PRAVOUGAONIK, TROUGAO};

struct Tacka{
double x; 
double y; 
}; 
struct Kruznica {
 int r; 
 struct Tacka t; 
};
struct Pravougaonik{
 struct Tacka t; 
 int a, b; 
};
struct Trougao{
 struct Tacka a; 
 struct Tacka b;
 struct Tacka c;
};
enum TipOblika{TACKA, KRUZNICA, PRAVOUGAONIK, TROUGAO};
int obuhvata(void * oblik1, enum TipOblika to1, void * oblik2, enum TipOblika to2){
	
	if( to1==KRUZNICA) 
	{
		struct Kruznica *k=(struct Kruznica *) oblik1;
		if(to2==KRUZNICA){
			struct Kruznica *k1=(struct Kruznica *)  oblik2; 
			if((*k).r<(*k1).r)
			return 0; 
			return 1;
		}
		if(to2==TACKA){
			struct Tacka *t1=(struct Tacka* ) oblik2;
			int d= (pow((*t1).x-(*k).t.x,2)-pow((*t1).y-(*k).t.y,2));
			//if((k1.r+k1.t.x<t1.x && k1.r+k1.t.y<t1.y)  || (k1.r+k1.t.y<t1.x && k1.r+k1.t.x<t1.y)  )
			if(d<(*k).r)
			return 0; 
			return 1; 
		}
		if(to2==PRAVOUGAONIK){
		  struct Pravougaonik *p1=(struct Pravougaonik* ) oblik2; 
		  int d; 
		  d=(pow((*p1).t.x-(*k).t.x,2)-pow((*p1).t.y-(*k).t.y,2));
		  if( d<(*k).r)
		  return 0; 
		  return 1; 
		}
		if(to2==TROUGAO){
		 struct Trougao *tr1=(struct Trougao *) oblik2; 
		 int d1, d2, d3; 
		 d1=(pow(((*tr1).a.x-(*k).t.x), 2)-pow(((*tr1).a.y-(*k).t.y),2)); 
		 d2=(pow(((*tr1).b.x-(*k).t.x), 2)-pow(((*tr1).b.y-(*k).t.y),2));
		 d3=(pow(((*tr1).c.x-(*k).t.x), 2)-pow(((*tr1).c.y-(*k).t.y),2));
		 //if((k1.r+k1.t.x<tr1.a && (k1.r+k1.t.y<tr1.a)) && (k1.r+k1.t.x<tr1.b) && (k1.r+k1.t.x<tr1.c) ||)
		  if(d1<(*k).r &&d2<(*k).r && d3<(*k).r)  return 0; 
		  return 1; 
		}
	}
   if(to1==TACKA)
    {
    	 struct Tacka *t1=(struct Tacka *) oblik1; 
    	 if(to2== TACKA){
    	 	struct Tacka *t2=(struct Tacka *)  oblik2; 
    	 	
    	 	if((*t1).x!=(*t2).x || (*t1).y!=(*t2).y)  return 0; 
    	 	return 1; 
    	 }
    	 if(to2==KRUZNICA){
    	 	int d; 
    	 	struct Kruznica *k=(struct Kruznica*)  oblik2;
    	 	 d= (pow((*t1).x-(*k).t.x,2)-pow((*t1).y-(*k).t.y,2));
			if(d<(*k).r) return 0; 
    	 	return 1; 
    	 }
    	 if(to2==PRAVOUGAONIK){
    	 	int d; 
    	 	struct Pravougaonik *p1=(struct Pravougaonik*) oblik2;
    	     d=(pow((*t1).x-(*p1).t.x,2))-(pow((*t1).y-(*p1).t.y,2));
    	     if(d<(*p1).a && d<(*p1).b)
    	 	return 0; 
    	 	return 1; 
    	 }
    	 if(to2==TROUGAO){
    	 	struct Trougao *t=(struct Trougao *) oblik2; 
    	 	int d1, d2, d3; 
    	 	d1=((*t1).x-(*t).b.x)*((*t).a.y-(*t).b.y) -((*t).a.x-(*t).b.x)*((*t1).y-(*t).b.y);
    	 	d2=((*t1).x-(*t).c.x)*((*t).b.y-(*t).c.y) -((*t).b.x-(*t).c.x)*((*t1).y-(*t).c.y);
    	 	d3=((*t1).x-(*t).a.x)*((*t).c.y-(*t).a.y) -((*t).c.x-(*t).a.x)*((*t1).y-(*t).a.y);
    	 	if(d1==d2 && d2==d3)		
    	
    	 	 return 0; 
    	 	return 1; 
    	 }
    }
	if(to1==PRAVOUGAONIK)
	{
		struct Pravougaonik *p=(struct Pravougaonik*) oblik1; 
		if(to2==TACKA){
			int d; 
			struct Tacka *t1=(struct Tacka *) oblik2; 
			d=(pow((*t1).x-(*p).t.x,2))-(pow((*t1).y-(*p).t.y,2));
    	    if(d<(*p).a && d<(*p).b)
    	 	return 0; 
			return 1; 
 		}
 		if(to2==KRUZNICA){
 			struct Kruznica *k=(struct Kruznica*)  oblik2; 
 			int d; 
 			d=(pow((*p).t.x-(*k).t.x,2)-pow((*p).t.y-(*k).t.y,2));
		    if( d>(*k).r)
		  
 			return 0; 
 			return 1; 
 		}
	
 	if(to2==PRAVOUGAONIK){
 			struct Pravougaonik *p1=(struct Pravougaonik*) oblik2; 
 			if((((*p).t.x+(*p).a) < ((*p1).t.x))
 			|| ((*p).t.y+(*p).b<(*p1).t.y) 
 			|| ((*p).t.x>(*p1).t.x+(*p1).a) || ((*p).t.y>(*p1).t.y+(*p1).b))
 			return 0;
 			return 1; 
 		}
 		/*if(to2==TROUGAO) {
 			struct Trougao *t=(struct Trougao *) oblik2; 
 			if() return 0; 
 			return 1; 
 		}*/
	}
	if(to1==TROUGAO)
	{
		struct Trougao *t=(struct Trougao*) oblik1; 
		if(to2==TACKA){
			struct Tacka *t1=(struct Tacka*) oblik2; 
			int d1, d2, d3; 
    	 	d1=((*t1).x-(*t).b.x)*((*t).a.y-(*t).b.y) -((*t).a.x-(*t).b.x)*((*t1).y-(*t).b.y);
    	 	d2=((*t1).x-(*t).c.x)*((*t).b.y-(*t).c.y) -((*t).b.x-(*t).c.x)*((*t1).y-(*t).c.y);
    	 	d3=((*t1).x-(*t).a.x)*((*t).c.y-(*t).a.y) -((*t).c.x-(*t).a.x)*((*t1).y-(*t).a.y);
    	 	if(d1<d2 && d2<d3)		
    	
			 return 0; 
			return 1; 
		}
		if(to2==KRUZNICA){
			struct Kruznica *k=(struct Kruznica*) oblik2; 
			 int d1, d2, d3; 
		 d1=(pow(((*t).a.x-(*k).t.x), 2)-pow(((*t).a.y-(*k).t.y),2)); 
		 d2=(pow(((*t).b.x-(*k).t.x), 2)-pow(((*t).b.y-(*k).t.y),2));
		 d3=(pow(((*t).c.x-(*k).t.x), 2)-pow(((*t).c.y-(*k).t.y),2));
		 //if((k1.r+k1.t.x<tr1.a && (k1.r+k1.t.y<tr1.a)) && (k1.r+k1.t.x<tr1.b) && (k1.r+k1.t.x<tr1.c) ||)
		  if(d1<(*k).r &&d2<(*k).r && d3<(*k).r)  return 0; 
		
			 return 0; 
			return 1; 
		}
	/*	if(to2==PRAVOUGAONIK){
			struct Pravougaonik *p=(struct Pravougaonik*) oblik2; 
			if() return 0; 
			return 1; 
		}*/
		if(to2==TROUGAO){
			struct Trougao *tt=(struct Trougao*) oblik2; 
			if((*t).a.x>=(*tt).a.x &&( (*t).a.y>=(*tt).a.y)
			&& (*t).b.x>=(*tt).b.x &&( (*t).b.y>=(*tt).b.y) &&
			(*t).c.x>=(*tt).c.x &&( (*t).c.y>=(*tt).c.y)
			) return 1; 
			return 0; 
		}
		
	}
}
int main() 
{
	int n; 
	int tip;
	struct Tacka t; 
	struct Pravougaonik p; 
	struct Kruznica k; 
	struct Trougao trougao; 
	printf("Unesite broj oblika: "); 
	if(n<50) scanf("%d", &n);
    int i=0;
     while (i<=n) {
    printf("Odaberite tip %d. oblika (1 - tacka, 2 - kruznica, 3 - pravougaonik, 4 - trougao). ", i+1);
  	scanf("%d", &tip);
   if(tip>n) printf("Nepoznat tip oblika %d !", tip);
   if(n==1) { 
   printf("Unesite centar kruznice: koordinate x,y: %f, %f", k.t.x, k.t.y);
    printf("Unesite poluprecnik kruznice: %d", k.r);  
   }
    if(n==2) 
    printf("Unesite tacku: koordinate x, y: %f, %f ", t.x, t.y  );
    if(n==3) {
    printf("Unesite donji lijevi ugao: koordinate x, y: %f, %f", p.t.x, p.t.y); 
    printf("Unesite sirinu: %d", p.a); 
    printf("Unesite visinu: %d", p.b); }
    if(n==4) {
    printf("Unesite prvi vrh: koordinate x, y: %f, %f", trougao.a.x, trougao.a.y);
    printf("Unesite drugi vrh: koordinate x, y: %f, %f", trougao.b.x, trougao.b.y); 
    printf("Unesite treci vrh: koordinate x, y: %f, %f", trougao.c.x, trougao.c.y);
    }
    i++;
     } 
    return 0;
}

