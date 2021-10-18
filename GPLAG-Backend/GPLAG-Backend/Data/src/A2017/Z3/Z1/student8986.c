#include <stdio.h>


int dva_od_tri(int* niz1,int vel1,int* niz2,int vel2,int* niz3,int vel3){
	
	int *p,*q,i,j,k,temp,pom1[1000],pom2[1000],pom3[1000],zavrsni[1000],brojaci[1000]={0},broj_clanova=0;
	

/* Kopira elemente iz nizova koje prima funkcija u pomocne nizove */
	for(i=0;i<vel1;i++){
	    pom1[i]=niz1[i];
	}
	
	for(i=0;i<vel2;i++){
	    pom2[i]=niz2[i];
	}
	
	for(i=0;i<vel3;i++){
	    pom3[i]=niz3[i];
	}
	

/* Sortira prvi pomocni niz po velicini od najmanjeg ka najvecem */
	p=q=pom1;
		
		while(p<pom1+vel1){
		while(q<pom1+vel1){
			
			if(*q<*p){
				temp=*q;
				*q=*p;
				*p=temp;
			} q++;
			
		}
		
		p++;
		q=p;
	}
	
/* Izbaci elemente koji se ponavljaju iz sortiranog prvog pomocnog niza */
    for (i = 0; i < vel1; i++) {
      for (j = i + 1; j < vel1;) {
         if (pom1[j] == pom1[i]) {
            for (k = j; k < vel1; k++) {
               pom1[k] = pom1[k + 1];
            }
            vel1--;
         } else
            j++;
      }
   }


/* Sortira drugi pomocni niz po velicini od najmanjeg ka najvecem */
	p=q=pom2;
		
		while(p<pom2+vel2){
		while(q<pom2+vel2){
			
			if(*q<*p){
				temp=*q;
				*q=*p;
				*p=temp;
			} q++;
			
		}
		
		p++;
		q=p;
	}
	
/* Izbaci elemente koji se ponavljaju iz sortiranog drugog pomocnog niza */
    for (i = 0; i < vel2; i++) {
      for (j = i + 1; j < vel2;) {
         if (pom2[j] == pom2[i]) {
            for (k = j; k < vel2; k++) {
               pom2[k] = pom2[k + 1];
            }
            vel2--;
         } else
            j++;
      }
   }



/* Sortira treci pomocni niz po velicini od najmanjeg ka najvecem */
	p=q=pom3;
		
		while(p<pom3+vel3){
		while(q<pom3+vel3){
			
			if(*q<*p){
				temp=*q;
				*q=*p;
				*p=temp;
			} q++;
			
		}
		
		p++;
		q=p;
	}
	
/* Izbaci elemente koji se ponavljaju iz sortiranog treceg pomocnog niza */
    for (i = 0; i < vel3; i++) {
      for (j = i + 1; j < vel3;) {
         if (pom3[j] == pom3[i]) {
            for (k = j; k < vel3; k++) {
               pom3[k] = pom3[k + 1];
            }
            vel3--;
         } else
            j++;
      }
   }


/* Spaja tri sortirana pomocna niza bez ponavljajucih vrijednosti u zavrsni niz */
 
for(i=0;i<vel1;i++){
	zavrsni[i]=pom1[i];
}

j=0;
for(i=vel1;i<vel2+vel1;i++){
	zavrsni[i]=pom2[j++];
}

k=0;
for(i=vel2+vel1;i<vel3+vel2+vel1;i++){
	zavrsni[i]=pom3[k++];
}

 
/* Sortira elemente zavrsnog niza od najmanjeg ka najvecem */	
	p=q=zavrsni;
		
		while(p<zavrsni+vel1+vel2+vel3){
		while(q<zavrsni+vel1+vel2+vel3){
			
			if(*q<*p){
				temp=*q;
				*q=*p;
				*p=temp;
			} q++;
			
		}
		
		p++;
		q=p;
	}

/* Broji koliko puta se ponavlja cifra u zavrsnom nizu - broj clanova raste samo ako se broj ponavlja dva puta */
	for (i=0;i<vel1+vel2+vel3;i++) {
	 brojaci[zavrsni[i]]++;
     if(brojaci[zavrsni[i]]==2)broj_clanova++;
     if(brojaci[zavrsni[i]]==3 && broj_clanova>0)broj_clanova--;
    }

return broj_clanova;
	
}

int main() {
	
	int niz1[1000],niz2[1000],niz3[1000],i,v1,v2,v3;
	
	scanf("%d %d %d",&v1,&v2,&v3);
	
	for(i=0;i<v1;i++)scanf("%d",&niz1[i]);
	for(i=0;i<v2;i++)scanf("%d",&niz2[i]);
	for(i=0;i<v3;i++)scanf("%d",&niz3[i]);
	
	printf("%d",dva_od_tri(niz1,v1,niz2,v2,niz3,v3));
	
	return 0;
}
