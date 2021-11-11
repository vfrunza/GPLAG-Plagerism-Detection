#include <stdio.h>
int main() {
	int a,x,y,z,t=0;
	int i,j;
	do{
		if(t>0){/* Unos */
			printf(" Neispravno N!\n");
		}
	printf("Unesite broj N:");
	scanf("%d",&a);	
		t++;
	}while(a<8||a%4!=0);
	printf("\n");
/*  Pomocne varijable */
	x=(a/2)+1;
	y=(a/4)+(a/2)+1;
	z=(a/4)+(a/2);
	for(i=1;i<=a;i++){
		for(j=1;j<=a;j++){
			if(i<=(a/2)&&j<=(a/2)){
			 if(i==j&&i<=(a/4)&&j<=(a/4)){
			 		printf("\\");
			 }
			else if(i+j==x&&i<=(a/4)&&j>(a/4)){
			 		printf("/");
			 }
			 else if(i==j&&i>(a/4)&&j>(a/4)){
			 	printf("\\");
			 	
			 }else if(i+j==x&&i>(a/4)&&j<=(a/4)){
			 	printf("/");
			 }
			 else{
			 	printf(" ");
			 }
			}/*gornji lijevi 	kvadrant	 GOTOV*/
			if(i<=(a/2)&&j>(a/2)){
				if((i==1||i==(a/2))&&(j==x||j==a)){
					printf("+");
				}else if((i==1||i==(a/2))&&(j!=x&&j!=a)){
					printf("-");
				}else if((i!=1&&i!=(a/2))&&(j==x||j==a)){
					printf("|");
				}
				else{
					printf(" ");
				}
				if(j==a){
					printf("\n");
				}}/*gornji  desni 	kvadrant 	 GOTOV*/
			if(i>(a/2)&&j<=(a/2)){
				if((i==x||i==(a))&&(j==1||j==(a/2))){
					printf("+");
				}else if((i==x||i==a)&&(j!=1&&j!=(a/2))){
					printf("-");
				}else if((i!=x&&i!=a)&&(j==1||j==(a/2))){
					printf("|");
				}
				else{
					printf(" ");
				}
				if(j==a){
					printf("\n");
				}}/*donji  	lijevi 	kvadrant 	 GOTOV*/
			if(i>(a/2)&&j>(a/2)){
					if((i==((a/2)+(a/4))||i==((a/2)+(a/4)+1))){
						if((j==(a/2)+(a/4))||j==((a/2)+(a/4)+1)){
							printf("+");
						}
						else printf("-");
					}
					if(i!=z&&i!=y){
						if(j==z||j==y){
							printf("|");
						}
						else{
							printf(" ");
						}
					}
				if(j==a){
					printf("\n");
				}}/*donji 	desni 	kvadrant	 GOTOV*/
		}
	}
	return 0;
}