#include <stdio.h>

int main() {
	
	int i,n,a,b,m,br1,br2,br3,br4,duzina,p,n_unazad;
	
	br1=0;
	br2=0;
	br3=0;
	br4=0;
	duzina=0;
	n_unazad=0;
	
	printf("Unesite broj: ");
	scanf("%d",&n);
	
	if(n%10==n){
		printf("0");
		return 0;
	}
	
	p = n;
	while(p/=10){
		duzina++;
	}
	
	while(n!=0){
		n_unazad = n_unazad*10;
		n_unazad = n_unazad + n%10;
		n = n/10;
	}
	
	n = n_unazad;
	for(i=0; i<duzina; i++){
		
		if(br1==0){
			a = n%10;
			n = n/10;
			br1++;
		}
		else if(br1!=0){
			a = b;
		}
		
		b = n%10;
		n = n/10;
	
		m = a-b;
		br3++;
		
		if(m<0){
			m = m * (-1);
		}
		
		if(br2==0){
			if(m==0){
				br4++;
				continue;
			}
			else br2++;
		}
		
		printf("%d",m);
	}
	
	if(br3==br4){
		printf("0");
	}
	
	return 0;
}
