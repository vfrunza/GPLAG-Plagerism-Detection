#include <stdio.h>
#include <math.h>


int izbacivanje1(int br_2,int cifre)
{  int  novo=0;  int br=0;
	while(br_2!=0){
	
	if(fabs(br_2%10)!=cifre ){
	br=br+ br_2 % 10 * pow(10,novo);
	novo++;
		
	}
	

		
	br_2=br_2 / 10;
	}
	return 1;
}

	








int main() {
	
	
	int brojevi[6]={12,35,67,-2,45,234};
	int cifre[4]={3,5,2,4};
	
	cifre[1]=4;
	
	return 0;
}
