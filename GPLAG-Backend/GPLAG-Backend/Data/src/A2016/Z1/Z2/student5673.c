#include <stdio.h>

int main() {
		float a,b,c,d,e,f;
		printf("Unesite a1,b1,a2,b2: ");
		scanf("%f,%f,%f,%f",&a,&b,&c,&d);
		if((a==c) && (b==d)){
			printf("Poklapaju se");
			return 0;
		}
		if(a==c){
			printf("Paralelne su");
			return 0;
		}
		else{
			e=(d-b)/(a-c);
			f=a*e+b;
			if(f==0.0 && e==0.0){
				printf("Prave se sijeku u tacci(0.00,0.00");
				return 0;
			}
			printf("Prave se sijeku u tacci (%.1f,%.1f)",e,f);
		}
	return 0;
}
