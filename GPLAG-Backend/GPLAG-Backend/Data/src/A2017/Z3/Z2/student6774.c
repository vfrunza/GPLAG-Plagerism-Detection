#include <stdio.h>
#include<math.h>
#define VelNiza 9999

void zaokruzi1(float niz[],int vel) {
	int i;
	/*  ZAOKRUZAVA NIZ NA JEDNU DECIMALU*/
	for(i=0;i<vel;i++){
		*niz=round(*niz*10)/10;
		niz++;
	}

}
void preslozi(float niz[],int vel, int k){
	zaokruzi1(niz,vel);
	int suma=0,temp=0,brojac1=0,brojac2=0,i,j;
	float niz1[VelNiza],niz2[VelNiza];


	for(i=0;i<vel;i++){
		suma =0;
		/*PRVO POVECAVA NIZ ZA 10 PUTA TE STAVLJA APSOLUTNU VRIJEDNOST KAKO BI MOGLI LIJEPO ODSJECAT POJEDINE CLANOVE*/
		temp=(fabs)(*(niz+i)*10);
	    /* IZRACUNAVAMO SUMU INDIVIDUALNIH CIFRI BROJEVA TE AKO JE TA CIFRA VECA ILI JEDNAKA K TI BROJEVI IDU U NIZ2. A AKO JE TA SUMA MANJA OD K TI BROJEVI IDU U NIZ1*/
			suma=suma+temp%10;
			temp=temp/10;
		}while(temp>0);
		if(suma<k){
			niz1[brojac1]=*(niz+i);
			brojac1++;
		}
		else if(suma>=k){
			niz2[brojac2]=*(niz+i);
			brojac2++;
		}
	}
	/*REDA BROJEVE U GLAVNI NIZ S TIM DA PRVO STAVLJA BROJEVE IZ NIZA2 GDJE SU SMJESTENI BROJEVI CIJA JE SUMA VECA ILI JEDNAKA OD K A ZATIM BROJEVE IZ NIZA1 GDJE SU SMJESTENI BROJEVI CIJA JE SUMA CIFARA MANJA OD K */
	for(i=0;i<vel;i++){
		if(i<brojac2)*(niz+i)=*(niz2+i);
		else *(niz+i)=*(niz1+i-brojac2);
		
	}
	
}	
int main(){
	return 0;
}