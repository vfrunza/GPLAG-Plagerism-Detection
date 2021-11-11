#include <stdio.h>

int dva_od_tri(int niz1[],int vel1,int niz2[],int vel2,int niz3[],int vel3){
	int brojac2=0,dva_puta=1;
	int i,j,k;
	int brojaci[101]={0};
	//trazimo broj koji se nalazi u prvom i drugom nizu 
	for(i=0;i<vel1;i++){
		for(j=0;j<vel2;j++){
			if(niz1[i]==niz2[j]){
				
				dva_puta=1;
				for(k=0;k<vel3;k++){
					if(niz2[j]==niz3[k]){
					dva_puta=0;
					break;
					}
				}
			
			if(!dva_puta){
				break;
			}else if(dva_puta){
				if(brojaci[niz1[i]]==0){
					brojac2++;
					brojaci[niz1[i]]++;
				}
			}		
		}
	}	
}
//trazimo broj koji se nalazi u drugom i trecem nizu
	brojaci[101]=0;
	for(i=0;i<vel3;i++){
		for(j=0;j<vel2;j++){
			if(niz3[i]==niz2[j]){
			
				dva_puta=1;
				for(k=0;k<vel1;k++){
					if(niz2[j]==niz1[k]){
					dva_puta=0;
					break;
					}
				}
			
			if(!dva_puta){
				break;
			}else if(dva_puta){
				if(brojaci[niz2[j]]==0){
					brojac2++;
					brojaci[niz2[j]]++;
				}
			}
		}
	}
}
	//trazimo broj koji se nalazi u prvom i trecem nizu
    brojaci[101]=0;
	for(i=0;i<vel1;i++){
		for(j=0;j<vel3;j++){
			if(niz1[i]==niz3[j]){
			//ako nadjemo broj u drugom nizu prekidamo petlju
				dva_puta=1;
				for(k=0;k<vel2;k++){
					if(niz3[j]==niz2[k]){
					dva_puta=0;
					break;
					}
				}
			
			if(!dva_puta){
				break;
			}else if(dva_puta){
				if(brojaci[niz1[i]]==0){
					brojac2++;
					brojaci[niz1[i]]++;
				}
			}
		}
	}
		
}
	
return brojac2;
}
int main() {
	int i,j,k;
    int niz1[]={1, 2, 3, 4};
    int niz2[]={2, 3, 4, 5};
    int niz3[]={3, 4, 5, 6};
    int brojac=dva_od_tri(niz1,4,niz2,4,niz3,4);
    printf("%d\n",brojac);
    for(i=0;i<4;i++){
    	printf("%d",niz1[i]);
    }for(j=0;j<4;j++){
    	printf("%d",niz2[j]);
    }for(k=0;k<4;k++){
    	printf("%d",niz3[k]);
    }
	return 0;
}
