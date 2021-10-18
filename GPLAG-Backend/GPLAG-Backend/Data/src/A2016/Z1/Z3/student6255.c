#include <stdio.h>

int main() {
	int cx=0,bx=0,sx=0,vx=0,px=0,brojac=0,brojac1=1000,brojac2=1000,brojac3=1000,brojac4=1000,brojac5=1000;
	char vozila='a';
	double crna=0, bijela=0, siva=0, crvena=0, plava=0;
	printf("Unesite vozila: ");
	while(vozila!='K' && vozila!='k'){
		scanf("%c",&vozila);
		if(vozila=='C' || vozila=='c') {
			cx++;
			brojac1=brojac;
		}
		else if(vozila=='B' || vozila=='b'){
			bx++;
			brojac2=brojac;
		}
		else if(vozila=='S' || vozila=='s'){
			sx++;
			brojac3=brojac;
		}
		else if(vozila=='V' || vozila=='v'){
			vx++;
			brojac4=brojac;
		}
		else if(vozila=='P' || vozila=='p') {
			px++;
			brojac5=brojac;
		}
		else if(vozila=='K' || vozila=='k') break;
		else {
			printf("Neispravan unos\n");
			brojac --;
		} 
		brojac++;
	} 
	printf("Ukupno evidentirano %d vozila.\n",brojac);
    if (cx==0 && bx==0 && sx==0 && vx==0 && px==0){
    	printf("Najpopularnija boja je crna (%.2f%%).",crna);
    }
	crna=((float)cx/brojac)*100;
	bijela=((float)bx/brojac)*100;
	siva=((float)sx/brojac)*100;
	crvena=((float)vx/brojac)*100;
	plava=((float)px/brojac)*100;
	 if(cx>bx && cx>sx && cx>vx && cx>px) printf("Najpopularnija boja je crna (%.2f%%).",crna);
   	 else if(bx>cx && bx>sx && bx>vx && bx>px) printf("Najpopularnija boja je bijela (%.2f%%).",bijela);
	 else if(sx>cx && sx>bx && sx>vx && sx>px) printf("Najpopularnija boja je siva (%.2f%%).",siva);
	 else if(vx>cx && vx>bx && vx>sx && vx>px) printf("Najpopularnija boja je crvena (%.2f%%).",crvena);
	 else if(px>cx && px>bx && px>sx && px>vx) printf("Najpopularnija boja je plava (%.2f%%).",plava);
	 else if(brojac1<brojac2 || brojac1<brojac3 || brojac1<brojac4 || brojac1<brojac5) printf("Najpopularnija boja je crna (%.2f%%).",crna);
	 else if(brojac2<brojac1 || brojac2<brojac3 || brojac2<brojac4 || brojac2<brojac5) printf("Najpopularnija boja je bijela (%.2f%%).",bijela);
	 else if(brojac3<brojac1 || brojac3<brojac2 || brojac3<brojac4 || brojac3<brojac5) printf("Najpopularnija boja je siva (%.2f%%).",siva);
	 else if(brojac4<brojac1 || brojac4<brojac2 || brojac4<brojac3 || brojac4<brojac5) printf("Najpopularnija boja je crvena (%.2f%%).",crvena);
	 else if(brojac5<brojac1 || brojac5<brojac4 || brojac5<brojac3 || brojac5<brojac4) printf("Najpopularnija boja je plava (%.2f%%).",plava);
	return 0;
}
