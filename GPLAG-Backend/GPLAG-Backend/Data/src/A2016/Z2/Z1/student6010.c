#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
 int n, s, broj=0, a=0, deset=1, ost=0, uman1=0, uman2=0, razlika=0, i, j, done=0; 
 printf("Unesite broj: ");
 scanf("%d", &n);
 n=abs(n);
 s=n;
 do{ s/=10;
 broj++;
} while(s!=0);
 if(n>=0 && n<10) printf("0");
 else {
  a=broj;
  for(i=0; i<broj-1; i++) {
   a--;
   for(j=0; j<a; j++) {
    deset=10*deset;
   }
   ost=fabs(n%deset);
   uman1=fabs(n/deset);
   uman2=fabs((int)(10*ost/deset));
   razlika=fabs(uman1-uman2);

     if(uman1!=uman2) {printf("%d", razlika); 
     done=1;}
     if(uman1==uman2 && done==1) {printf("%d", razlika);}
     else if(uman1==uman2 && done!=1);
     deset=1;
     n=ost;
     ost=0;
     uman1=0;
     uman2=0;
  }
  if(done!=1) printf("%d", razlika);
 }
 return 0;
}
