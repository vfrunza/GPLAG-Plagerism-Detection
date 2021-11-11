#include <stdio.h>
int dva_od_tri(int* niz1, int* niz2, int* niz3, int N1, int N2, int N3){
	int brojac1=0, brojac2=0, *i, j, k;
	int*p = niz1;
	int*q = niz2;
	int*r = niz3;		/* Ovo radimo da bi sačuvali niz i pomoću toga osiguravamo da se preskaču cifre koje ponavljamo. */
	
	while(p<niz1+N1){
		brojac1=0;
		for(i=niz1; i<p; i++)
			if(*i==*p) break;
		if(i<p)	{
			p++;
			continue; 
		}
		for(j=0; j<N2; j++){
			if(*p==*(q+j)){
				brojac1++;
				break;
			}	
		}
		for(k=0; k<N3; k++){
			if(*p==*(r+j)){
				brojac1++;
				break;
			}
		}
		if(brojac1==1) brojac2++; p++;
	} p=niz1;		/* Ovo radimo da bi vratili na staru vrijednost.*/
	
	while(q<niz2+N2){
		for(i=niz2; i<q; i++)
			if(*i==*q) break;
		if(i<q)	{
			q++;
			continue; 
		}
		for(j=0; j<N1; j++){
			if(*q==*(p+j)){
				brojac1++;
				break;
			}	
		}
		for(k=0; k<N3; k++){
			if(*q==*(r+j)){
				brojac1++;
				break;
			}
		}
		if(brojac1==1) brojac2++; q++;
	} q=niz2;
	
	while(r<niz3+N3){
		for(i=niz3; i<r; i++)
			if(*i==*r) break;
		if(i<r)	{
			r++;
			continue; 
		}
		for(j=0; j<N1; j++){
			if(*r==*(p+j)){
				brojac1++;
				break;
			}	
		}
		for(k=0; k<N2; k++){
			if(*r==*(q+j)){
				brojac1++;
				break;
			}
		}
		if(brojac1==1) brojac2++; r++;
	} r=niz3;
	
	return brojac2/2;		/* Dijelimo sa dva jer smo dva puta provjeravali. */
	
	
}
int main() {
	
	int niz1[]={1,2,3,5}, niz2[]={1,2,4,6,7}, niz3[]={1,3,4,8,9,10};
	
	printf("%d", dva_od_tri(niz1,niz2,niz3,4,5,6));

	return 0;
}
