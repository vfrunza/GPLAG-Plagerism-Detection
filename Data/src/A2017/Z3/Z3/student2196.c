#include <stdio.h>
#include <math.h>

int izbaci_cifre(int a1[], int el1, int a2[], int el2){
	int i, j, temp1=0, temp2=0, br=1, t;
	for(i=0; i<el2; i++){
		if(a2[i]<0 || a2[i]>9){
			return 0;
		}
		else{
			for(j=0; j<el2; j++){
				if(j!=i){
					if(a2[i]==a2[j]) return 0;
				}
			}
		}
	}
	for(i=0; i<el1; i++){
		br=1;
		temp1=fabs(a1[i]);
		if(el2==0) temp2=temp1;
		else{ temp2=0;
			while(temp1>0){
				for(j=0; j<el2; j++){
					t=0;
					if(temp1%10==a2[j]){
						t=1;
						break;
					}
				}
				if(t==0){
					temp2+=temp1%10*br;
					br*=10;
				}
				temp1=temp1/10;
			}
		}
		if(a1[i]>0) a1[i]=temp2;
		else a1[i]=-temp2;
	}
	return 1;
	
}

int main() {
	
	return 0;
}
