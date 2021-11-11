#include <stdio.h>

int main() {
	
	char a;
	int c,b,s,v,p;
	float UK,nc,nb,ns,nv,np;
	
	c=0;
	b=0;
	s=0;
	v=0;
	p=0;
	
	printf("Unesite vozila: ");
	for(;;){
		
		scanf("%c",&a);
		
		if(a=='C' || a=='c'){
			c++;
			continue;
		}
		if(a=='S' || a=='s'){
			s++;
			continue;
		}
		if(a=='B' || a=='b'){
			b++;
			continue;
		}
		if(a=='V' || a=='v'){
			v++;
			continue;
		}
		if(a=='P' || a=='p'){
			p++;
			continue;
		}
		if(a!='C' && a!='c' && a!='S' && a!='s' && a!='V' && a!='v' && a!='B' &&a!='b' && a!='P' && a!='p' && a!='k' && a!='K'){
			
			printf("Neispravan unos\n");
			continue;
		
		}
		if(a=='k' || a=='K') break;
		
	}
	
		UK=c+b+s+v+p;
		
		nc=(c/UK)*100;
		nb=(b/UK)*100;
		ns=(s/UK)*100;
		nv=(v/UK)*100;
		np=(p/UK)*100;
	
	printf("Ukupno evidentirano %.f vozila.\n",UK);
	
	if(c==0 && s==0 && v==0 && b==0 && p==0){
		printf("Najpopularnija boja je crna (0.00%%).");
		return 0;
	}
	
	if(c>=b && c>=s && c>=v && c>=p){
		printf("Najpopularnija boja je crna (%.2f%%).",nc);
	}
	else if(b>c && b>=s && b>=v && b>=p){
		printf("Najpopularnija boja je bijela (%.2f%%).",nb);
	}
	else if(s>c && s>b && s>=v && s>=p){
		printf("Najpopularnija boja je siva (%.2f%%).",ns);
	}
	else if(v>c && v>b && v>s && v>=p){
		printf("Najpopularnija boja je crvena (%.2f%%).",nv);
	}
	else if(p>c && p>b && p>s && p>v){
		printf("Najpopularnija boja je plava (%.2f%%).",np);
	}
	
	return 0;
}
