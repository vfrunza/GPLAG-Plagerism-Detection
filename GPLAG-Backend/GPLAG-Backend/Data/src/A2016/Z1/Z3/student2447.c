#include <stdio.h>

int main() {
	
	int i,c=0,b=0,s=0,v=0,p=0,z;
	float k;
	char n;
	
	printf("Unesite vozila: ");

		for(i=0;;i++){
		scanf("%c",&n);
		if(n=='K' || n=='k') break;
		
		else if(n!='C' && n!='c' && n!='B' && n!='b' && n!='S' && n!='s' && n!='V' && n!='v' && n!='P' && n!='p'){
			printf("Neispravan unos\n");
			continue;
		}
			else if(n=='c' || n=='C'){
				c++;
			
		}else if(n=='b' || n=='B'){
			b++;
		}else if(n=='s' || n=='S'){
			s++;
		}else if(n=='v' || n=='V'){
			v++;
		}else if(n=='p' || n=='P'){
			p++;
		}
			
		
	}
	
	z=c+b+s+v+p;

	
	printf("Ukupno evidentirano %d vozila.\n",z);
	if(z==0){
		printf("Najpopularnija boja je crna (0.00%%).\n");
	}
	
	
	 else if(c>=b && c>=s && c>=v && c>=p){
		k=(float)(100*c)/z;
			printf("Najpopularnija boja je crna (%.2f%%).\n",k);
	
	}
	else if(b>=c && b>=s && b>=v && b>=p){
		k=(float)(100*b)/z;
			printf("Najpopularnija boja je bijela (%.2f%%).\n",k);
			
	}
	else if(s>=c && s>=b && s>=v && s>=p){
		k=(float)(100*s)/z;
			printf("Najpopularnija boja je siva (%.2f%%).\n",k);
			
	}
	else if(v>=c && v>=b && v>=s && v>=p){
		k=(float)(100*v)/z;
			printf("Najpopularnija boja je crvena (%.2f%%).\n",k);
			
	}
	else if(p>=c && p>=b && p>=s && p>=v){
		k=(float)(100*p)/z;
			printf("Najpopularnija boja je plava (%.2f%%).\n",k);
			
	}
	
		return 0;
}
