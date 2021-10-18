#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define eps 0.001
#define max 50

enum TipOblika { TACKA, KRUZNICA, PRAVOUGAONIK, TROUGAO };

	struct Tacka{
		float x;
		float y;	
	};
	struct Kruznica{
		struct Tacka t;
		float radijus;
	};
	struct Pravougaonik{
		struct Tacka t;
		int sirina;
		int visina;
	};
	struct Trougao{
		struct Tacka t1,t2,t3;
	};
	
	struct Tacka unesi_tacku(){
		struct Tacka t;
		printf("koordinate x,y: ");
		scanf("%f",&t.x);
		scanf("%f",&t.y);

		return t;
	}
	
	struct Kruznica unesi_kruznicu(){
		struct Kruznica k;
		printf("Unesite centar kruznice: ");
		k.t=unesi_tacku();
		printf("Unesite poluprecnik kruznice: ");
		scanf("%f",&k.radijus);
		return k;
	}
	
	struct Pravougaonik unesi_pravougaonik(){
		struct Pravougaonik p;
		printf("Unesite donji lijevi ugao: ");
		p.t=unesi_tacku();
		printf("Unesite sirinu: ");
		scanf("%d", &p.sirina);
		printf("Unesite visinu: ");
		scanf("%d", &p.visina);
		return p;
	}
	
	struct Trougao unesi_trougao(){
		struct Trougao tr;
		printf("Unesite prvi vrh: ");
		tr.t1=unesi_tacku();
		printf("Unesite drugi vrh: ");
		tr.t2=unesi_tacku();
		printf("Unesite treci vrh: ");
		tr.t3=unesi_tacku();
		return tr;
	}
	
	float udaljenost_izmedju_dvije_tacke(struct Tacka *t1, struct Tacka *t2){
		float d=sqrt( ((*t1).x-(*t2).x) * ((*t1).x-(*t2).x) + ((*t1).y-(*t2).y) * ((*t1).y-(*t2).y) );
		return d;
	}
	
	int kruznica_pravougaonik(struct Kruznica* k, struct Pravougaonik* p){
		struct Tacka t;
		float d;
		float d1=sqrt( ((*p).sirina/2.)*((*p).sirina/2.) + ((*p).visina/2.)*((*p).visina/2.) );/*udaljenost centra pravouganika od vrha*/
		t.x=((*p).t.x+(*p).sirina)/2.;
		t.y=((*p).t.y+(*p).visina)/2.;/*koordinate centra pravougaonika*/
		d=udaljenost_izmedju_dvije_tacke(&t,&(*k).t);
		
		if(d+d1-(*k).radijus>eps) return 0;
		
		return 1;/*ako kruznica obuhvata pravougaonik*/
	}
	
	int kruznica_trougao(struct Kruznica* k, struct Trougao* tr){
		float d1=udaljenost_izmedju_dvije_tacke(&(*k).t,&(*tr).t1);
		float d2=udaljenost_izmedju_dvije_tacke(&(*k).t,&(*tr).t2);
		float d3=udaljenost_izmedju_dvije_tacke(&(*k).t,&(*tr).t3);
		if(d1-(*k).radijus>eps) return 0;
		if(d2-(*k).radijus>eps) return 0;
		if(d3-(*k).radijus>eps) return 0;
		return 1;
	}

	float povrsina_trougla(struct Tacka* t1, struct Tacka* t2, struct Tacka* t3){
		float suma;
		suma=abs((*t1).x*((*t2).y-(*t3).y)+(*t2).x*((*t3).y-(*t1).y)+(*t3).x*((*t1).y-(*t2).y));
		float P=suma/2.;
		return P;
	}
	
	float visina_trougla(float P, struct Tacka* t1, struct Tacka* t2){
		float d=udaljenost_izmedju_dvije_tacke(t1,t2);
		float h=2*P/d;
		return h;
	}
	
	int pravougaonik_tacka(struct Pravougaonik* p, struct Tacka* t){
		if(((*p).t.x-(*t).x)<eps && ((*p).t.y-(*t).y)<eps) return 1;
		if(((*p).t.x+(*p).sirina-(*t).x)>eps && ((*p).t.y+(*p).visina-(*t).y)>eps) return 1;
		
		return 0;
	}
	
	
	
	
	int obuhvata(void* oblik1, enum TipOblika to1, void* oblik2, enum TipOblika to2){
		if(to1==TACKA){
			struct Tacka* t1 = (struct Tacka*) oblik1;
			
			if(to2==TACKA){
				struct Tacka* t2 = (struct Tacka*) oblik2;
				if(abs((*t1).x-(*t2).x)<eps && abs((*t1).y-(*t2).y)<eps) return 1;
				else return 0;
			}
			
			if(to2==KRUZNICA){
				struct Kruznica* k2 = (struct Kruznica*) oblik2;
				if(abs((*t1).x-(*k2).t.x)>eps || abs((*t1).y-(*k2).t.y)>eps) return 0;
				if((*k2).radijus>eps) return 0;
				return 1;
			}
			
			if(to2==PRAVOUGAONIK){
				struct Pravougaonik* p2 = (struct Pravougaonik*) oblik2;
				if(abs((*t1).x-(*p2).t.x)>eps || abs((*t1).y-(*p2).t.y)>eps) return 0;
				if((*p2).sirina>eps || (*p2).visina>eps) return 0;
				return 1;
			}
			
			if(to2==TROUGAO){
				struct Trougao* tr2 = (struct Trougao*) oblik2;
				if(abs((*t1).x-(*tr2).t1.x)>eps || abs((*t1).y-(*tr2).t1.y)>eps) return 0;
				if(abs((*t1).x-(*tr2).t2.x)>eps || abs((*t1).y-(*tr2).t2.y)>eps) return 0;
				if(abs((*t1).x-(*tr2).t3.x)>eps || abs((*t1).y-(*tr2).t3.y)>eps) return 0;
				return 1;
			}
		}
		
		if(to1==KRUZNICA){
			struct Kruznica* k1 = (struct Kruznica*) oblik1;
			
			if(to2==TACKA){
				struct Tacka* t2 = (struct Tacka*) oblik2;
				float d=(udaljenost_izmedju_dvije_tacke(&(*k1).t,t2));
				if(abs(d-(*k1).radijus)>eps) return 0;
				return 1;
			}
		
			if(to2==KRUZNICA){
				struct Kruznica* k2 = (struct Kruznica*) oblik2;
				float d=(udaljenost_izmedju_dvije_tacke(&(*k1).t,&(*k2).t));
				if(abs(d+(*k2).radijus-(*k1).radijus)>eps) return 0;
				return 1;
			}
		
			if(to2==PRAVOUGAONIK){
				struct Pravougaonik* p2 = (struct Pravougaonik*) oblik2;
				int obuhvata1 = kruznica_pravougaonik(k1,p2);
				if(obuhvata1) return 1;
				return 0;
			}
			
			if(to2==TROUGAO){
				struct Trougao* tr2 = (struct Trougao*) oblik2;
				int obuhvata1 = kruznica_trougao(k1,tr2);
				if(obuhvata1) return 1;
				return 0;
			}
		}
		
		if(to1==TROUGAO){
			struct Trougao* tr1 = (struct Trougao*) oblik1;	
			
			if(to2==TACKA){
				struct Tacka* t2 = (struct Tacka*) oblik2;
				float Pt=povrsina_trougla(&(*tr1).t1,&(*tr1).t2,&(*tr1).t3);
				float P1=povrsina_trougla(t2,&(*tr1).t1,&(*tr1).t2);
				float P2=povrsina_trougla(t2,&(*tr1).t3,&(*tr1).t2);
				float P3=povrsina_trougla(t2,&(*tr1).t1,&(*tr1).t3);
				float Pu=P1+P2+P3;
				if(abs(Pt-Pu)<eps || (Pt-Pu)>eps) {
						return 1; 
					}
				else return 0;	
	
				return 1;
			}
			
			if(to2==KRUZNICA){
				struct Kruznica* k2 = (struct Kruznica*) oblik2;
				
				float P1=povrsina_trougla(&(*k2).t,&(*tr1).t1,&(*tr1).t2);
				float P2=povrsina_trougla(&(*k2).t,&(*tr1).t3,&(*tr1).t2);
				float P3=povrsina_trougla(&(*k2).t,&(*tr1).t1,&(*tr1).t3);
				float h1=visina_trougla(P1,&(*tr1).t1,&(*tr1).t2);
				float h2=visina_trougla(P2,&(*tr1).t3,&(*tr1).t2);
				float h3=visina_trougla(P3,&(*tr1).t1,&(*tr1).t3);
			
				if(h1-(*k2).radijus<eps) return 0;
				if(h2-(*k2).radijus<eps) return 0;
				if(h3-(*k2).radijus<eps) return 0;
	
				return 1;
			}
			
			if(to2==PRAVOUGAONIK){
				struct Pravougaonik* p2 = (struct Pravougaonik*) oblik2;
				float Pt=povrsina_trougla(&(*tr1).t1,&(*tr1).t2,&(*tr1).t3);
				float P1=povrsina_trougla(&(*tr1).t1,&(*tr1).t2,&(*p2).t);
				float P2=povrsina_trougla(&(*tr1).t3,&(*tr1).t2,&(*p2).t);
				float P3=povrsina_trougla(&(*tr1).t1,&(*tr1).t3,&(*p2).t);
				if((P3+P2+P1-Pt)>eps) return 0;
				
			}
			
			if (to2==TROUGAO){
				struct Trougao* tr2 = (struct Trougao*) oblik2;
				float Pt1=povrsina_trougla(&(*tr1).t1,&(*tr1).t2,&(*tr1).t3);
				float Pt2=povrsina_trougla(&(*tr2).t1,&(*tr2).t2,&(*tr2).t3);
				if(Pt2-Pt1>eps) return 0;
				float P1=povrsina_trougla(&(*tr1).t1,&(*tr1).t2,&(*tr2).t1);
				float P2=povrsina_trougla(&(*tr1).t1,&(*tr1).t3,&(*tr2).t1);
				float P3=povrsina_trougla(&(*tr1).t2,&(*tr1).t2,&(*tr2).t1);
				if(P1+P2+P3-Pt1>eps) return 0;
				P1=povrsina_trougla(&(*tr1).t1,&(*tr1).t2,&(*tr2).t2);
				P2=povrsina_trougla(&(*tr1).t1,&(*tr1).t3,&(*tr2).t2);
				P3=povrsina_trougla(&(*tr1).t2,&(*tr1).t2,&(*tr2).t2);
				if(P1+P2+P3-Pt1>eps) return 0;
				P1=povrsina_trougla(&(*tr1).t1,&(*tr1).t2,&(*tr2).t3);
				P2=povrsina_trougla(&(*tr1).t1,&(*tr1).t3,&(*tr2).t3);
				P3=povrsina_trougla(&(*tr1).t2,&(*tr1).t2,&(*tr2).t3);
				if(P1+P2+P3-Pt1>eps) return 0;
				return 1;
			}
		
		}
		
		if(to1==PRAVOUGAONIK){
			struct Pravougaonik* p1 = (struct Pravougaonik*) oblik1;
			
			if(to2==TACKA){
				struct Tacka* t2 = (struct Tacka*) oblik2;
				int obuhvata1=pravougaonik_tacka(p1,t2);
				if(obuhvata1) return 1;
				return 0;
			}
			if (to2==KRUZNICA) {
				struct Kruznica* k2 = (struct Kruznica*) oblik2;
				struct Tacka t1={0,0};
				struct Tacka t2={0,0};
				struct Tacka t3={0,0};
				(t1).x=(*p1).t.x+(*p1).sirina;
				(t1).y=(*p1).t.y;
				(t2).x=(*p1).t.x;
				(t2).y=(*p1).t.y+(*p1).visina;
				(t3).x=(*p1).t.x+(*p1).sirina;
				(t3).y=(*p1).t.y+(*p1).visina;
				
				float P1=povrsina_trougla(&(*k2).t,&(*p1).t,&t1);
				float P2=povrsina_trougla(&(*k2).t,&t1,&t3);
				float P3=povrsina_trougla(&(*k2).t,&t3,&t2);
				float P4=povrsina_trougla(&(*k2).t,&(*p1).t,&t2);
				
				float h1=visina_trougla(P1,&(*p1).t,&t1);
				float h2=visina_trougla(P2,&t1,&t3);
				float h3=visina_trougla(P3,&t3,&t2);
				float h4=visina_trougla(P4,&(*p1).t,&t2);
				
				float min=h1;
				if(min-h2<eps) min=h2;
				if(min-h3<eps) min=h3;
				if(min-h4<eps) min=h4;
				
				if((*k2).radijus-min>eps) return 0;
				return 1;
			}
			
			if(to2==TROUGAO){
				struct Trougao* tr2 = (struct Trougao*) oblik2;
				
				int obuhvata1=pravougaonik_tacka(p1,&(*tr2).t1);
				int obuhvata2=pravougaonik_tacka(p1,&(*tr2).t2);
				int obuhvata3=pravougaonik_tacka(p1,&(*tr2).t3);
					
				if(obuhvata1==1 && obuhvata2==1 && obuhvata3==1) return 1;
				return 0;
			}
			
			if(to2==PRAVOUGAONIK){
				struct Pravougaonik* p2 = (struct Pravougaonik*) oblik2;
				struct Tacka t1={0,0};
				struct Tacka t2={0,0};
				(t1).x=(*p1).t.x+(*p1).sirina;
				(t1).y=(*p1).t.y;
				(t2).x=(*p1).t.x;
				(t2).y=(*p1).t.y+(*p1).visina;
				
				float P1=povrsina_trougla(&(*p2).t,&(*p1).t,&t1);
				float P2=povrsina_trougla(&(*p2).t,&(*p1).t,&t2);
				float hvis=visina_trougla(P1,&(*p1).t,&t1);
				float hsir=visina_trougla(P2,&(*p1).t,&t2);
				
				if(hvis+(*p2).visina-(*p1).visina>eps) return 0;
				if(hsir+(*p2).sirina-(*p1).sirina>eps) return 0;
				return 1;
			}
		}
			
			
				
		
		return 0;
	}


int main() {
	struct Tacka t;
	struct Kruznica k;
	struct Pravougaonik p;
	struct Trougao tr;
	int DA;
	int i,j;
	int broj_oblika;
	int tip_oblika[max]={1};
	printf("Unesite broj oblika: ");
		while (1) {
			scanf("%d",&broj_oblika);
			if(broj_oblika<51 && broj_oblika>0) break;
		}
	
	for(i=0;i<broj_oblika;i++){
		DA=0;
		printf("Odaberite tip %d. oblika (1 - tacka, 2 - kruznica, 3 - pravougaonik, 4 - trougao): ",i+1);
		scanf("%d",&tip_oblika[i]);
		if(tip_oblika[i]>4 || tip_oblika[i]<1) {
			printf("Nepoznat tip oblika %d!\n",tip_oblika[i]);
			i--;
			DA=1;
		}
		if(!DA){
		if(tip_oblika[i]==1){
			printf("Unesite tacku: ");
			t=unesi_tacku();
		}
		if(tip_oblika[i]==2){
			k=unesi_kruznicu();
		}
		if(tip_oblika[i]==3){
			p=unesi_pravougaonik();
		}
		if(tip_oblika[i]==4){
			tr=unesi_trougao();
		
		}
		}
	}
	for(i=0;i<broj_oblika;i++){
		for(j=0;j<broj_oblika;j++){
			if(tip_oblika[i]==1 && tip_oblika[j]==2){
				if(obuhvata(&t,TACKA,&k,KRUZNICA)) printf("Oblik 1 obuhvata oblik 2.\n");
			}
			if(tip_oblika[i]==1 && tip_oblika[j]==3){
				if(obuhvata(&t,TACKA,&p,PRAVOUGAONIK)) printf("Oblik 1 obuhvata oblik 3.\n");
			}
			if(tip_oblika[i]==1 && tip_oblika[j]==4){
				if(obuhvata(&t,TACKA,&tr,TROUGAO)) printf("Oblik 1 obuhvata oblik 4.\n");
			}
			
			if(tip_oblika[i]==2 && tip_oblika[j]==1){
				if(obuhvata(&k,KRUZNICA,&t,TACKA)) printf("Oblik 2 obuhvata oblik 1.\n");
				}
		
			if(tip_oblika[i]==2 && tip_oblika[j]==3){
				if(obuhvata(&k,KRUZNICA,&p,PRAVOUGAONIK)) printf("Oblik 2 obuhvata oblik 3.\n");
			
			}
			if(tip_oblika[i]==2 && tip_oblika[j]==4){
				if(obuhvata(&k,KRUZNICA,&tr,TROUGAO)) printf("Oblik 2 obuhvata oblik 4.\n");
				
			}
			
			if(tip_oblika[i]==3 && tip_oblika[j]==1){
				if(obuhvata(&p,PRAVOUGAONIK,&t,TACKA)) printf("Oblik 3 obuhvata oblik 1.\n");
			
			}
			if(tip_oblika[i]==3 && tip_oblika[j]==2){
				if(obuhvata(&p,PRAVOUGAONIK,&k,KRUZNICA)) printf("Oblik 3 obuhvata oblik 2.\n");
			
			}
		
			if(tip_oblika[i]==3 && tip_oblika[j]==4){
				if(obuhvata(&p,PRAVOUGAONIK,&tr,TROUGAO)) printf("Oblik 3 obuhvata oblik 4.\n");
				
			}
			
			if(tip_oblika[i]==4 && tip_oblika[j]==1){
				if(obuhvata(&tr,TROUGAO,&t,TACKA)) printf("Oblik 4 obuhvata oblik 1.\n");
			
			}
			if(tip_oblika[i]==4 && tip_oblika[j]==2){
				if(obuhvata(&tr,TROUGAO,&k,KRUZNICA)) printf("Oblik 4 obuhvata oblik 2.\n");
			
			}
			if(tip_oblika[i]==4 && tip_oblika[j]==3){
				if(obuhvata(&tr,TROUGAO,&p,PRAVOUGAONIK)) printf("Oblik 4 obuhvata oblik 3.\n");
		
			}
		
		}
	}
	
	
	return 0;
}

























