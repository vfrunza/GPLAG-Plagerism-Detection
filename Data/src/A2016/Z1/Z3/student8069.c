#include <stdio.h>

int main() {
	char boja;
	float u=0;
	float c=0;
	float b=0;
	float s=0;
	float v=0;
	float p=0;
	float posto;
	printf("Unesite vozila: ");
	scanf("%c",&boja);
	while(boja!='K'&&boja!='k'){
		if (boja=='c'||boja=='C')c++;
		else if(boja=='b'||boja=='B')b++;
		else if(boja=='s'||boja=='S')s++;
		else if(boja=='v'||boja=='V')v++;
		else if(boja=='p'||boja=='P')p++;
		
		if(boja!='K'&&boja!='k'&&boja!='C'&&boja!='c'&&boja!='B'&&boja!='b'&&boja!='s'&&boja!='S'&&boja!='v'&&boja!='V'&&boja!='p'&&boja!='P'){
			printf("Neispravan unos\n");
		}
		scanf("%c",&boja);
	
	}u=c+b+s+v+p;
	printf("Ukupno evidentirano %.f vozila.\n",u);
		/*if(u=0){
			printf("Najpopularnija boja je crna (0.00%%).");
	}*/
	if(c>=b&&c>=s&&c>=v&&c>=p){
		if(u==0)posto=0;
		else {posto=(float)(c*100/u);}
		printf("Najpopularnija boja je crna (%.2f%%).",posto);
		
	}
	else if(b>c&&b>=s&&b>=v&&b>=p){
		posto=(float)(b*100/u);
		printf("Najpopularnija boja je bijela (%.2f%%).",posto);
	}
	else if(s>c&&s>b&&s>=v&&s>=p){
		posto=(float)(s*100/u);
		printf("Najpopularnija boja je siva (%.2f%%).",posto);
	}
	else if(v>c&&v>b&&v>s&&v>=p){
		posto=(float)(v*100/u);
		printf("Najpopularnija boja je crvena (%.2f%%).",posto);
	}
	else if(p>c&&p>b&&p>s&&p>v){
		posto=(float)(p*100/u);
		printf("Najpopularnija boja je plava (%.2f%%).",posto);
	}

	
	return 0;
}
