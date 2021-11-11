#include <stdio.h>

int prost(int i){
	int j, br=0;
	for(j=1; j<=i;j++){
		if(i%j==0)br++;
	}
	if(br==2)return 1;
	else return 0;
}

int daj_prost(){
	static int i=1;
	tu: i++;
	if(prost(i))return i;
	else goto tu;
}


int main() {
	int A=0,B=0,suma=0,x=0;
do{ printf("\nUnesite brojeve A i B: ");
	scanf("%d %d", &A, &B);
	if(A>=B)printf("A nije manje od B.");
	else if(A<=0)printf("A nije prirodan broj.");
  }
while(A>=B || A<=0 || B<=0);

printf("Suma prostih brojeva izmedju %d i %d je ",A,B);
do{x=daj_prost();
	if(x>A && x<B)
	suma=suma+x;
  }
while(x<B);

printf("%d.", suma);

return  0;}
