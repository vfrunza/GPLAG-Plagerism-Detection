#include <stdio.h>
#include <math.h>
int izbaci_cifre(int nizbr[],int a,int niz2[],int b)
{

	int i,j,k,brojac=0,brojac1=0,temp,noviBroj,temp1,cifra,l=0,q,m;
	
	double h,d;
	int brojac_c[100]= {0};
	int istina=1;
	int noviNiz[100]= {0};

	for(i=0; i<b; i++)
		for(j=i+1; j<b; j++)
			if(niz2[i]==niz2[j])
				brojac++;

	for(i=0; i<b; i++)
		if(niz2[i]<0 || niz2[i]>9)
			brojac1++;

	if(brojac !=0 || brojac1 !=0)
		return 0;



 else{

	for(i=0; i<a; i++) {
		temp=fabs(nizbr[i]);
		do {

			temp=temp/10;
			brojac_c[i]++;

		} while(temp!=0);

		/*treba ostat jedna cifra pri dijeljenju*/
		brojac_c[i]--;
	}


	for(k=0; k<a; k++) {
		temp1=fabs(nizbr[k]);
		noviBroj=0;

		do {


			cifra=temp1/(pow(10,brojac_c[k]));
			for(j=0; j<b; j++) {
				if(cifra!=niz2[j])
					istina=0;
				else {
					istina=1;
					break;

				}
			}
			/*pretpostavka je da se broj nalazi u drugom nizu */
			if(istina==0)
				noviBroj=noviBroj*10+cifra;


			d=pow(10,brojac_c[k]);
			h=cifra*d;

			temp1 -= h;
			brojac_c[k]--;

		} while(brojac_c[k]>=0);

		noviNiz[l]+=noviBroj;
		l++;
	}

	for(q=0; q<a; q++) {
		if(nizbr[q]<0) {
			noviNiz[q]*=-1;
		} else noviNiz[q]=noviNiz[q];

	}
  for(k=0;k<a;k++)
  nizbr[k]=noviNiz[k];
  
  return 1;
 }
}
int main()
{

	int i,a,b,rez,m;
	int niz1[100],niz2[100];



printf("Unesi velicinu prvog niza: ");
	scanf("%d",&a);

	for(i=0; i<a; i++)
		scanf("%d",&niz1[i]);

	printf("Unesi vel drugog niza: ");
	scanf("%d",&b);
	for(i=0; i<b; i++)
		scanf("%d",&niz2[i]);

  
	for(m=0; m<a; m++) {
        
		printf("%d ",izbaci_cifre(niz1,a,niz2,b));
	}


	return 0;
}
