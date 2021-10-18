#include <stdio.h>

int dva_od_tri(int niz1[],int vel1,int niz2[],int vel2,int niz3[],int vel3) {
	int i,j,z,ima1=0,ima2=0,br=0,ima=0,bio=0;
	
if(niz1==niz2 && niz1==niz3) return 0;

	for(i=0;i<vel1;i++){
		ima1=0;
		ima2=0;
		bio=0;
		for(z=0;z<i;z++) {
			if(niz1[i]==niz1[z]) bio=1;
		}
		if(bio==0) {
			for(j=0;j<vel2;j++){
				if(niz1[i]==niz2[j]) ima1=1;
			}
			for(j=0;j<vel3;j++) {
				if(niz1[i]==niz3[j]) ima2=1;
			}
			if(ima1!=ima2) br++;
		    }
		}
    
    	for(i=0;i<vel2;i++){
    		ima=0;
    		bio=0;
    		for(z=0;z<i;z++) {
			if(niz2[i]==niz2[z]) bio=1;
		
		}
		for(z=0;z<vel1;z++){
			if(niz1[z]==niz2[i]) bio=1;
		}
		
		if(bio==0) {
    		for(j=0;j<vel3;j++){
    			if(niz2[i]==niz3[j]) ima=1;
    		}
    		if(ima==1) br++;
    	
    	}
    }
        return br;
	}

int main() {
	/*printf("Zadaća 3, Zadatak 1");*/
	
	return 0;
}
