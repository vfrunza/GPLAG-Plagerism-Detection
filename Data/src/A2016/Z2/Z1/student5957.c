#include <stdio.h>
#include <math.h>

int main() {
	int br,i=0,prvi,drugi,c,obr=0;
	printf("Unesite broj: ");
	scanf("%d",&br);
	if(br<0)
	br=-br;
	while(br>9){
		prvi=br%10;
		//printf("prvi=%d\n",prvi);
		br=br/10;
		
		drugi=br%10;
		//printf("drugi=%d\n",drugi);
		c=(prvi-drugi);
		if(c<0) c=-c;
		
	//	printf("razlika=%d\n",c);
		//printf("broj=%d\n",br);
		obr=obr+pow(10,i)*c;
		
		i++;
	}
	printf("%d",obr);
	
	return 0;
}
