#include <stdio.h>
#include <math.h>

int main() {
	int  x1, x, c, c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c100, c12, c123, c1234, c12345, c123456, c1234567, c12345678, c123456789;
	int br=0;
	printf("Unesite broj: ");
	scanf("%d", &x1);
	x=x1;
    if(x1<0) x=fabs(x1);
    x1=x;
      while(x1>0) {
      	c=x1%10;
      	br++;
      	x1=x1/10; 
  
      }
      
      
   
		c1=x%10;
		x=x/10;
		c2=x%10;
		x=x/10;
		c3=x%10;
		x=x/10;
		c4=x%10;
		x=x/10;
		c5=x%10;
		x=x/10;
		c6=x%10;
		x=x/10;
		c7=x%10;
		x=x/10;
		c8=x%10;
		x=x/10;
		c9=x%10;
		x=x/10;
		c10=x%10;
		x=x/10; 
		c12=c1-c2;
		c123=c2-c3;
		c1234=c3-c4;
		c12345=c4-c5;
		c123456=c5-c6;
		c1234567=c6-c7;
		c12345678=c7-c8;
		c123456789=c8-c9;
		c100=c9-c10;
		
		if(br==1) { printf("0"); return 0; }
	
		
		if(c12<0) c12=fabs(c12);
		if(c123<0) c123=fabs(c123);
		if(c1234<0) c1234=fabs(c1234);
		if(c12345<0) c12345=fabs(c12345);
		if(c123456<0) c123456=fabs(c123456);
		if(c1234567<0) c1234567=fabs(c1234567);
		if(c12345678<0) c12345678=fabs(c12345678);
		if(c123456789<0) c123456789=fabs(c123456789);
		if(c100<0) c100=fabs(c100);
		if(c12==0 && c123==0 && c1234==0 && c12345==0 && c123456==0)  { printf("%d", c12); return 0; }
		if(c12==0 && c123==0) { printf("%d", c12); return 0; }
		if(c12==0 && c123==0 && c1234==0 && c12345==0 && c123456==0 && c1234567==0) { printf("%d",c12); return 0; }
		if(c123==0 && c1234==0 && c12345==0 && c123456==0) { printf("%d", c12);  return 0; }
		
		if(br==2) printf("%d",c12);
		if(br==3) printf("%d%d",c123,c12);
		if(br==4) printf("%d%d%d",c1234,c123,c12);
		if(br==5) printf("%d%d%d%d",c12345,c1234,c123,c12);
		if(br==6) printf("%d%d%d%d%d",c123456,c12345,c1234,c123,c12);
		if(br==7) printf("%d%d%d%d%d%d",c1234567,c123456,c12345,c1234,c123,c12);
		if(br==8) printf("%d%d%d%d%d%d%d",c12345678,c1234567,c123456,c12345,c1234,c123,c12);
		if(br==9) printf("%d%d%d%d%d%d%d%d",c123456789,c12345678,c1234567,c123456,c12345,c1234,c123,c12);
		if(br==10) printf("%d%d%d%d%d%d%d%d%d",c100,c123456789,c12345678,c1234567,c123456,c12345,c1234,c123,c12);
       
	return 0;
}
