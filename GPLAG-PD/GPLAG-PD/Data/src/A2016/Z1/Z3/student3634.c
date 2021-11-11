#include <stdio.h>

int main() {
	char a;
	int c=0, b=0, s=0, v=0, p=0, max=0, ukupno_vozila=0;
	char max_boja;
	float procenat;
	
	printf("Unesite vozila: ");
	for(;;) {
		scanf("%c", &a);
	if(a=='C' || a=='c') { c++; 
		if(c>max) { max=c;
		max_boja=a;
	}
	}
	else if(a=='B' || a=='b') { b++; 
		if(b>max) { max=b;
		max_boja=a;
	}
	}
	else if(a=='S' || a=='s') { s++; 
		if(s>max) { max=s;
		max_boja=a;
	}
	}
	else if(a=='V' || a=='v') { v++; 
		if(v>max) { max=v;
		max_boja=a;
	}
	}
	else if(a=='P' || a=='p') { p++; 
		if(p>max) { max=p;
		max_boja=a;
	}
	}
	
	else if(a=='K' || a=='k') break;
	else printf("Neispravan unos\n");
	}
	ukupno_vozila=b+v+s+c+p;
	procenat=(max/(float)(ukupno_vozila))*100;
	
	printf("Ukupno evidentirano %d vozila.\n", ukupno_vozila);
	if(ukupno_vozila==0) { printf("Najpopularnija boja je crna (0.00%%)."); }
	else if(max_boja=='B' || max_boja=='b')  { printf("Najpopularnija boja je bijela (%.2f%%).", procenat); }
	else if(max_boja=='S' || max_boja=='s') { printf("Najpopularnija boja je siva (%.2f%%).", procenat); }
	else if(max_boja=='V' || max_boja=='v') { printf("Najpopularnija boja je crvena (%.2f%%).", procenat); }
	else if(max_boja=='P' || max_boja=='p') { printf("Najpopularnija boja je plava (%.2f%%).", procenat); }
	else printf("Najpopularnija boja je crna (%.2f%%).", procenat); 
	
	
	return 0;
}
