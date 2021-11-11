#include <stdio.h>


int daj_prost()  
 { static int i=1; 
    i++;            //staticka varijabla jer ova funkcija, nakon sto vrati jedan prost broj, treba pri sljedecem pozivu vratiti sljedeci prost broj
 int prost=1,j;
 
 
 
 while(prost==1) {
 for (j=2;j<i;j++){      //petlja koja generise prirodne brojeve i, kada se ispuni uslov da je broj i prost, vratit ce ga funkciji main (return i)
 	
 	if(i%j==0) {     
 		prost=0;
 		break;
 	}
 
 }
 	if (prost==1) {   //broj i je prost, vraca ga funkciji main
 		return i;
 	}
 	
 	else{                 //broj i nije prost, povecaj i za jedan i nastavi sa while petljom
 		i++;
 		prost=1;
 	}
 	
 	
 	
 }
 return 0;
 }

int main() {
	int a,b,prostibroj,s=0,i;
	do{
	printf("Unesite brojeve A i B: ");
	scanf("%d %d", &a, &b);
	if(a>=b){
		printf("A nije manje od B.\n");
		
	}
	else if(a<=0){
		printf("A nije prirodan broj.\n");
	}
	else if(b<=0){
		printf("B nije prirodan broj.\n");
	}
	
	}while((a>=b) || (a<=0) || (b<=0));
	
 
    	for(i=0;i<b;i++){    //b je uvijek veci broj pa cemo toliko puta ponoviti petlju
		
		prostibroj=daj_prost();   //poziv funkcije daj_prost koja ce vratiti po jedan prost broj iz zadatog opsega prvi svakom pozivu
		if(prostibroj>a && prostibroj<b) {
			
			s=s+prostibroj;              //sabiranje prostih brojeva iz opsega
		}
		
		
	}
    
	
	printf("Suma prostih brojeva izmedju %d i %d je %d.", a,b,s);
	
	
	return 0;
}
