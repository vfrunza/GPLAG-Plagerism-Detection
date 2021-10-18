#include <stdio.h>

int main() {
	
	float a,b,c,d,x,y;
	float epsilon=0.00001;
	
	printf("Unesite a1,b1,a2,b2: ");
	scanf("%f,%f,%f,%f", &a,&b,&c,&d);
	

		
	
	
	if(((a-epsilon)<c && (a+epsilon)>c) && !((b-epsilon)<d && (b+epsilon)>d)){
		printf("Paralelne su");
	}

	else if (((a-epsilon)<c && (a+epsilon)>c) && ((b-epsilon)<d && (b+epsilon)>d)) {
		printf("Poklapaju se");
	}
    
	else {
		x=(d-b)/(a-c);
		y=((a*d)-(c*b))/(a-c);
		printf("Prave se sijeku u tacci (%.1f,%.1f)",x,y);
		
	}
	return 0;
}
