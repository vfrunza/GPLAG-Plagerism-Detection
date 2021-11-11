#include <stdio.h>

struct Student {
	char ime[20],prezime[20];
	int ocjene[50];
	int br_ocjena;
};

double pr(int ocjene[],int broj){
	int* k;
	int i;
	k=ocjene;
	double srednja_ocjena;
	srednja_ocjena=0;
	i=0;
	while(i<broj){
		if(*k==5) return 5;
		srednja_ocjena+=*k;
		k++;i++;
	}
	srednja_ocjena/=broj;
	return srednja_ocjena;
}


int vel(char rijec[]){
	char* p=rijec;
	int brojac;
	brojac=0;
	while(*p!='\0'){
		brojac++;
		p++;
	}
	return brojac;
}


int Isti(char jedan[],char dva[]){
	char* t=jedan; char* z=dva;
	if(vel(jedan)!=vel(dva)) return 0;
	while(*t!='\0'){
		if(*z!=*t) return 0;
		z++;t++;
	}
	return 1;
}





void prepisic(char prvi[],char drugi[]){
	char* p=prvi;
	char* q=drugi;
	while(*p!='\0'){
		*q=*p;
		q++;
		p++;
	}
	*q='\0';
}

void prepisi(int prvi[],int drugi[],int br_ocjena){
	int i;
	int* p=prvi;
	int* q=drugi;
	for(i=0;i<br_ocjena;i++){
		*q=*p;
		q++;
		p++;
	}
}

void zamijeni(struct Student* A, struct Student* B){
	char imee[15];
	char prezimee[15];
	int ocjenee[50];
	int bbroj;
	int broj;
	int velicina1;
	int velicina2;
	velicina1=vel(A->ime);
	velicina2=vel(B->ime);
	int v=0;
	int i=0;
	
	if(Isti(A->prezime,B->prezime)){
	//	printf("%d",Isti(A.prezime,B.prezime));
		if(velicina1>velicina2)broj=velicina2;
	    	else{broj=velicina1;}
	    	
	    	while(i<broj){
	    		if(A->ime[i]>B->ime[i]){ v=5;break;}
	    	i++;	}
	    		
	    	
	    		if(v==5 || (v==0 && velicina2<velicina1)){
	    		prepisic(B->ime,imee);
				prepisic(B->prezime,prezimee);
				prepisi(B->ocjene,ocjenee,B->br_ocjena);
				bbroj=B->br_ocjena;
				
				
				prepisic(A->ime,B->ime);
				prepisic(A->prezime,B->prezime);
				prepisi(A->ocjene,B->ocjene,A->br_ocjena);
				B->br_ocjena=A->br_ocjena;
				
				prepisic(imee,A->ime);
				prepisic(prezimee,A->prezime);
				prepisi(ocjenee,A->ocjene,bbroj);
				A->br_ocjena=bbroj;
		
	    		}
	}
	
	else{
		velicina1=vel(A->prezime);
		velicina2=vel(B->prezime);
			if(velicina1>velicina2)broj=velicina2;
	    	else{broj=velicina1;}
	    	while(i<broj){
	    		if(A->prezime[i]>B->prezime[i]) v=5;
	    	i++;	}
	    		
	    		
	    		if(v==5 || (v==0 && velicina2<velicina1)){
	    		prepisic(B->ime,imee);
				prepisic(B->prezime,prezimee);
				prepisi(B->ocjene,ocjenee,B->br_ocjena);
				bbroj=B->br_ocjena;
				
				
				prepisic(A->ime,B->ime);
				prepisic(A->prezime,B->prezime);
				prepisi(A->ocjene,B->ocjene,A->br_ocjena);
				B->br_ocjena=A->br_ocjena;
				
				prepisic(imee,A->ime);
				prepisic(prezimee,A->prezime);
				prepisi(ocjenee,A->ocjene,bbroj);
				A->br_ocjena=bbroj;
				
	    		}
	    	
	}
}



void prepisi_nazad(struct Student n[],struct Student niz[],int velicina){
	int i;
	struct Student* a=n;
	struct Student* b=niz;
	for(i=0;i<velicina;i++){
		prepisic(a->ime,b->ime);
		prepisic(a->prezime,b->prezime);
		prepisi(a->ocjene,b->ocjene,a->br_ocjena);
		b->br_ocjena=a->br_ocjena;
		a++;
		b++;
	}
}



void Sortiraj_n(struct Student n[],int brojac){
	
	int i,j;
	struct Student* s=n;

	char imee[20];
	char prezimee[20];
	int ocjenee[50];
	int bbroj;

	struct Student* p=n;

	for(i=0;i<brojac;i++){
		s=p;
		s+=1;
		for(j=i+1;j<brojac;j++){
			if(pr(p->ocjene,p->br_ocjena)<pr(s->ocjene,s->br_ocjena)){
			
				prepisic(p->ime,imee);
				prepisic(p->prezime,prezimee);
				prepisi(p->ocjene,ocjenee,p->br_ocjena);
				bbroj=p->br_ocjena;
				
				
				prepisic(s->ime,p->ime);
				prepisic(s->prezime,p->prezime);
				prepisi(s->ocjene,p->ocjene,s->br_ocjena);
				p->br_ocjena=s->br_ocjena;
				
				prepisic(imee,s->ime);
				prepisic(prezimee,s->prezime);
				prepisi(ocjenee,s->ocjene,bbroj);
				s->br_ocjena=bbroj;
				
				
			}
			s+=1;
		}
		p+=1;
	}
	p=n;
/*	for(i=0;i<brojac;i++)
	{printf ("%s %s",p->ime,p->prezime); printf("\n");p++;}*/
double k,h;
	p=n;
	for(i=0;i<brojac;i++){
		s=p;
		s+=1;
		for(j=i+1;j<brojac;j++){
			k=pr(p->ocjene,p->br_ocjena);
             h=pr(s->ocjene,s->br_ocjena);

			if(h==k){
				zamijeni(p,s);
				
			}
				s+=1;
		}
		
		p+=1;
	}
		
	
	p=n;
	if(brojac>3) brojac=3;
	for(i=0;i<brojac;i++)
	{
		printf("%s %s\n",p->prezime,p->ime);
		p+=1;
	}
}

int genijalci(struct Student niz[],int velicina,double prosjek){
	struct Student n[100];
	struct Student* p=niz;
	struct Student* q=n;
	double prosjek1;
    int i;
    int brojac; brojac=0;
   // double prosjeci[10];
   
   
  for(i=0;i<velicina;i++){

if(p->br_ocjena==0) prosjek1=5.00;

else{
	prosjek1=pr(p->ocjene,p->br_ocjena);}
	/*printf("%lf\n",prosjek1);*/
	if(prosjek1>=prosjek){
		prepisi(p->ocjene,q->ocjene,p->br_ocjena);
		prepisic(p->ime,q->ime);
		prepisic(p->prezime,q->prezime);
		q->br_ocjena=p->br_ocjena;
		brojac++;
		q++;
		}
	p++;
}
if(brojac==0) return brojac;
     p=niz;
     q=p;
     q++;
     
	prepisi_nazad(n,niz,brojac);
	q=n;

	
	Sortiraj_n (n,brojac);

	return brojac;
}
int main() {
struct Student studenti[] = {

            {"Meho", "Behic", {10, 9}, 2},
            {"Meho", "Aehic", {10, 8}, 2},
            {"Meho", "Cehic", {10, 9, 8, 7, 6}, 5},
            {"Meho", "Dehic", {6, 9}, 2},
            {"Meho", "Zehic", {10}, 1},
            {"Meho", "Oehic", {10, 9, 9, 9}, 4}
        };
    }

