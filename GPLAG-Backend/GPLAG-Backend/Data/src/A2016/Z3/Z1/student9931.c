#include <stdio.h>
int daj_prost()
{
static int i,j,a=1,b=10000;
int w=0;
for(i=a;i<b;i++){a++;
	if(i==2){return i;}
	if(i%2==1){
		for(j=1;j<i;j++){
			if(i%j==0){
				w++;
			}
		}
		if(w==1){
		return i;
		} w=0;
	}
  }
  return 0;
}
int main() {
int a=0,b=0,suma=0,x,c;
unos:printf("Unesite brojeve A i B: ");
scanf("%d %d", &a,&b); 
if(a>=b){printf("A nije manje od B.\n");goto unos;}
else if(a<=0 || b<=0){printf("A nije prirodan broj.\n");goto unos;}
for(c=0;c <b;c++){
	x=daj_prost ();
if(x>a&&x<b&&x!=2) {
	suma=suma+x;
      }
  }
printf("Suma prostih brojeva izmedju %d i %d je %d.\n",a,b,suma);
return 0;
}