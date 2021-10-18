#include <stdio.h>

int dva_od_tri(int niz1[], int velicina1, int niz2[], int velicina2, int niz3[], int velicina3)
{
int brojac=0, brojac1=0, brojac2=0, brojac3=0, dokle;
int i=0, j=0, preskoci=0;

if (velicina1>=velicina2) dokle=velicina1;
else dokle=velicina2;
for(i=0; i<velicina1; i++){
	brojac1=0;
	brojac2=0;
	brojac3=0;
	preskoci=0;
	if(dokle==velicina1){
		for(j=0; j<velicina1; j++) {
		if(niz1[i]==niz1[j] && j>=i) brojac1++;
			else if(niz1[i]==niz1[j] && j<i) {preskoci=1; break;}
		}
		if(preskoci==0){
			for(j=0; j<velicina2; j++){
				if(niz1[i]==niz2[j]) brojac2++;
				}
				for(j=0; j<velicina3; j++){
					if(niz1[i]==niz3[j]) brojac3++;
				}
	}
	} 
	else {
		for(j=0; j<velicina2; j++){
		if(niz2[i]==niz2[j] && j<i) {preskoci=1; break;}
		else if(niz2[i]==niz2[j] && j>=i) brojac2++;
		}
		if(preskoci==0){
		for(j=0; j<velicina1; j++){
			if(niz2[i]==niz1[j]) brojac1++;
		}
		for(j=0; j<velicina3; j++){
			if(niz2[i]==niz3[j]) brojac3++;
		  }
    	}
	}
	if(brojac1>=1 && brojac2>=1 && brojac3==0) brojac++;
}

if(velicina1>=velicina3) dokle=velicina1;
else dokle=velicina3;
for(i=0; i<dokle; i++){
	brojac1=0;
	brojac2=0;
	brojac3=0;
	preskoci=0;
	if(velicina1==dokle){
		
		for(j=0; j<velicina1; j++){
			if(niz1[i]==niz1[j] && i<j) {preskoci=1; break;}
			else if(niz1[i]==niz1[j] && i>=j) brojac1++;
		}
		if(preskoci==0){
		for(j=0; j<velicina2; j++){
			if(niz1[i]==niz2[j]) brojac2++;
		}
		for(j=0; j<velicina3; j++){
			if(niz1[i]==niz3[j]) brojac3++;
		  }
    	}
	}
	else {
		for(j=0; j<velicina3; j++){
			if(niz3[i]==niz3[j] && j<i) {preskoci=1; break;}
			else if(niz3[i]==niz3[j] && i>=j) brojac3++;
		}
		if(preskoci==0){
		for(j=0; j<velicina1; j++){
			if(niz3[i]==niz1[j]) brojac1++;
		}
		for(j=0; j<velicina2; j++){
			if(niz3[i]==niz2[j]) brojac2++;
		}
	  }
	}
	if(brojac1>=1 && brojac2==0 && brojac3>=1) brojac++;

}

if(velicina2>=velicina3) dokle=velicina2;
else dokle=velicina3;
for(i=0; i<dokle; i++){
	brojac1=0;
	brojac2=0;
	brojac3=0;
	preskoci=0;
	if(velicina2==dokle){
		
		for(j=0; j<velicina2; j++){
			if(niz2[i]==niz2[j] && j<i) {preskoci=1; break;}
			else if(niz2[i]==niz2[j] && i>=j) brojac2++;
		}
		if(preskoci==0){
		
	for(j=0; j<velicina1; j++){
		if(niz2[i]==niz1[j]) brojac1++;
	}
	for(j=0; j<velicina3; j++){
		if(niz2[i]==niz3[j]) brojac3++;
     	}
      }
	}
  else{
  	for(j=0; j<velicina3; j++){
  		if(niz3[i]==niz3[j] && j<i) {preskoci=1; break;} 
  		else if(niz3[i]==niz3[j] && i>=j) brojac3++;
  	}
  	if(preskoci==0){
  	for(j=0; j<velicina1; j++){
  		if(niz3[i]==niz1[j]) brojac1++;
  	}
  	for(j=0; j<velicina2; j++){
  		if(niz3[i]==niz2[j]) brojac2++;
  	}
  }
  }
  if(brojac1==0 && brojac2>=1 && brojac3>=1) brojac++;
}
return brojac;
}

int main () {
	int niz1[10], niz2[10], niz3[10], n1,n2,n3, i, brojac, rez;
	
	printf("Unesite duzinu prvog niza:");
	scanf("%d", &n1);
	printf("Unesite elemente prvog niza:");
	for(i=0; i<n1; i++){
	scanf("%d", &niz1[i]);
	}
	printf("Unesite duzinu drugog niza:");
	scanf("%d", &n2);
	printf("Unesite elemente drugog niza:");
	for(i=0; i<n2; i++){
	scanf("%d", &niz2[i]);
	}
	printf("Unesite duzinu treceg niza:");
	scanf("%d", &n3);
	printf("Unesite elemente treceg niza:");
	for(i=0; i<n3; i++) {
	scanf("%d", &niz3[i]);
	}
	
	printf("%d ", dva_od_tri(niz1, n1, niz2, n2, niz3, n3));
	
	return 0;
}
