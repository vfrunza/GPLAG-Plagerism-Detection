#include <stdio.h>

int main() {
	
	int t, n1[10], n2[10], i, j, t1, t11, t2, t12, t3, t13, t4, t14, t5, t15, t6, t16, t7, t17, t8, t18, t9, t19, t10, t20;
	printf("Unesite broj tacaka: ");
	do{
		scanf("%d", &t);
		if(t>10 || t<1){ 
			printf("Pogresan unos\n");
			printf("Unesite broj tacaka: ");
		}
	
	}while(t>10 || t<1);
	
	for(i=0; i<t; i++){
		printf("Unesite %d. tacku: ", i+1);
		scanf("%d %d", &n1[i], &n2[i]);
		if( n1[i]<0 || n1[i]>19 || n2[i]<0 || n2[i]>19 ){
			printf("Pogresan unos\n");
			i--;
		}
	}
	t1=n1[0];  t11=n2[0];
	t2=n1[1];  t12=n2[1];
	t3=n1[2];  t13=n2[2];
	t4=n1[3];  t14=n2[3];
	t5=n1[4];  t15=n2[4];
	t6=n1[5];  t16=n2[5];
	t7=n1[6];  t17=n2[6];
	t8=n1[7];  t18=n2[7];
	t9=n1[8];  t19=n2[8];
	t10=n1[9]; t20=n2[9];
	
	if(t==1){
		for(i=0; i<20; i++){
		for(j=0; j<20; j++){
			if(j == t1 && i == t11){
				printf("*");
			}else{
				printf(" ");
			}
		}
		printf("\n");
	}
	
	}else if(t==2){
		for(i=0; i<20; i++){
		for(j=0; j<20; j++){
			if((j == t1 && i == t11) || (j == t2 && i == t12)){
				printf("*");
			}else{
				printf(" ");
			}
		}
		printf("\n");
	}
	
	}else if(t==3){
		for(i=0; i<20; i++){
		for(j=0; j<20; j++){
			if((j == t1 && i == t11) || (j == t2 && i == t12) || (j == t3 && i == t13)){
				printf("*");
			}else{
				printf(" ");
			}
		}
		printf("\n");
	}
	
	}else if(t==4){
		for(i=0; i<20; i++){
		for(j=0; j<20; j++){
			if((j == t1 && i == t11) || (j == t2 && i == t12) || (j == t3 && i == t13) || (j == t4 && i == t14)){
				printf("*");
			}else{
				printf(" ");
			}
		}
		printf("\n");
	}
	
	}else if(t==5){
		for(i=0; i<20; i++){
		    for(j=0; j<20; j++){
			    if((j == t1 && i == t11) || (j == t2 && i == t12) || (j == t3 && i == t13) || (j == t4 && i == t14) || (j == t5 && i == t15)){
				     printf("*");
			    }else{
				     printf(" ");
			    }
		}
		printf("\n");
	}
	
	}else if(t==6){
		for(i=0; i<20; i++){
		for(j=0; j<20; j++){
			if((j == t1 && i == t11) || (j == t2 && i == t12) || (j == t3 && i == t13) || (j == t4 && i == t14) || (j == t5 && i == t15) || (j == t6 && i ==t16 )){
				printf("*");
			}else{
				printf(" ");
			}
		}
		printf("\n");
	}
	
	}else if(t==7){
		for(i=0; i<20; i++){
		for(j=0; j<20; j++){
			if((j == t1 && i == t11) || (j == t2 && i == t12) || (j == t3 && i == t13) || (j == t4 && i == t14) || (j == t5 && i == t15) || (j == t6 && i ==t16 ) || (j == t7 && i == t17)){
				printf("*");
			}else{
				printf(" ");
			}
		}
		printf("\n");
	}
	
	}else if(t==8){
		for(i=0; i<20; i++){
		for(j=0; j<20; j++){
			if((j == t1 && i == t11) || (j == t2 && i == t12) || (j == t3 && i == t13) || (j == t4 && i == t14) || (j == t5 && i == t15) || (j == t6 && i ==t16 ) || (j == t7 && i == t17) || (j == t8 && i == t18)){
				printf("*");
			}else{
				printf(" ");
			}
		}
		printf("\n");
	}
	
	}else if(t==9){
		for(i=0; i<20; i++){
		for(j=0; j<20; j++){
			if((j == t1 && i == t11) || (j == t2 && i == t12) || (j == t3 && i == t13) || (j == t4 && i == t14) || (j == t5 && i == t15) || (j == t6 && i ==t16 ) || (j == t7 && i == t17) || (j == t8 && i == t18) || (j == t9 && i == t19)){
				printf("*");
			}else{
				printf(" ");
			}
		}
		printf("\n");
	}
	}else{
	for(i=0; i<20; i++){
		for(j=0; j<20; j++){
			if((j == t1 && i == t11) || (j == t2 && i == t12) || (j ==t3 && i == t13) || (j == t4 && i == t14) || (j == t5 && i == t15) || (j == t6 && i == t16) || (j == t7 && i == t17) || (j == t8 && i == t18)||(j == t9 && i == t19) || (j == t10 && i == t20)){
				printf("*");
			}else{
				printf(" ");
			}
		}
		printf("\n");
	}
	}

	return 0;
}
