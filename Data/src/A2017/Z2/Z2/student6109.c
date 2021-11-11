#include <stdio.h>
#include <math.h>

int main() {
	int nizA[100], nizB[1000], nizC[1000], n, i, m, vb=0, k, c1, l=0, v_B=0, x, r, brojac=1, j, p;
	
	printf("Unesite velicinu niza: ");
	scanf("%d", &n);
	printf("Unesite clanove niza: ");
	for(i=0; i<n; i++){
		scanf("%d", &nizA[i]);
	}
	
	for(i=0; i<n; i++){
		vb=0;
		m=nizA[i];
		c1=m%10;
		vb++;
		m/=10;
		while(m!=0){
			c1=m%10;
			vb++;
			m/=10;
		} v_B+=vb;;
			k=nizA[i];
			if(vb==1){
				c1=k%10;
				k/=10;
				nizB[l]=c1;
			}
			 else if(vb!=1){
				c1=k/(pow(10,vb-1));
				nizB[l]=c1;
				x=pow(10,vb-1);
			    k%=x;
			    while(k!=0){
			        l++;
			    	vb--;
			    	if(vb==1){
			    		c1=k%10;
			    		k=k/10;
			    		nizB[l]=c1;
			    		break;
			    	}
				    c1=k/(pow(10,vb-1));
				    nizB[l]=c1;
				    x=pow(10,vb-1);
				    k%=x;
			    }
			} l++;
		}
	

	r=0;
	for(i=0; i<v_B; i++){
		brojac=1;
		for(j=i+1; j<v_B; j++){
			if(nizB[i]==nizB[j]){
			brojac++;
			for(p=i; p<v_B-1; p++){
				nizB[p+1]=nizB[p+2];
			} 
			v_B--;
			j--;
		    } else {
		    	break;
		    }
	}
		nizC[r]=nizB[i];
		nizC[r+1]=brojac;
		r+=2;
	}
	
	printf("Finalni niz glasi:\n");
	for(i=0; i<r; i++){
	printf("%d ", nizC[i]);
	}
	return 0;
}
