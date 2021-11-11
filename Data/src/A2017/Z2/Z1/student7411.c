#include <stdio.h>
#include <math.h>

int main() {
	int a,s,b;
	char d='\\';
	do{ 
		printf("Unesite broj N: ");
		scanf("%d",&b);
		if(b<0||b<8||b%4==1)printf("Neispravno N");
		printf("\b");
	}
	while(b<0 || b<8|| b%4==1);
	printf("\b");
	for(a=0;a<b;a++){ 
		for(s=0;s<b;s++){
			if(a<(b/2)&&s<(b/2)){
				if(a==s) printf("%c",d);
				else if(s==(b/2)-1-a) printf("/");
				else printf(" ");
			}
			else if(a<b/2){
				if((a==0 && s==b/2)||(a==(b/2)-1 &&s ==b/2)||(a==0 && s==b-1)||(a==(b/2)-1 && s==b-1)) printf("+");
				else if(s==b/2||s==b-1) printf("|");
				else if(a==0||a==(b/2)-1) printf("-");
				else if (printf(" "));
			}
			else if(a>=b/2&&s<b/2){
			if((a==b/2 && s==0)||(a==b/2 &&s==b/2-1)||(a==b-1 && s==0)||(a==b-1 && s==(b/2)-1)) printf("+");
			else if(s==0||s==b/2-1) printf("|");
			else if(a==b/2||a==b-1) printf("-");
			else if (printf(" "));
			}
			else{
				if((a==(3*b)/4 && (s==(3*b)/4 || s==(3*b)/4-1)) || (a==(3*b)/4-1 && (s==(3*b)/4||s==(3*b)/4-1))) printf("+");
				else if(s==(3*b)/4||s==(3*b)/4-1)printf("|");
				else if(a==(3*b)/4||a==(3*b)/4-1)printf("-");
				else if (printf(" "));
			}
		}
		printf("\b");
	}
	return 0;
}
