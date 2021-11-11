#include <stdio.h>
#include <math.h>
int main() {
	int broj,temp1,temp2,temp3,rez=0,okreni=0;
	printf("Unesite broj: ");
	scanf("%d",&broj);
	if(broj<0)
		broj*=-1;
	while(broj/10!=0){
		temp1=broj%10;
		broj/=10;
		temp2=broj%10;
		temp3=temp1-temp2;
		if(temp3<0)
			temp3*=-1;
		rez=rez*10+temp3;
		if(rez==0&&temp3==0)
			rez=1;
	}
	while(rez>0){
		okreni=okreni*10+rez%10;
		rez/=10;
	}
	printf("%d",okreni);
	return 0;
	
}
