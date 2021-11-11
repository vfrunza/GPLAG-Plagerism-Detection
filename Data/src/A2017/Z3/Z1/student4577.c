#include <stdio.h>
int dva_od_tri(int a[],int vela,int b[],int velb,int c[],int velc){
	int i,j,z,pbr,br=0,izadji,napolje;
	for(i=0;i<vela;i++){
		izadji=0;
		pbr=0;
		for(j=i-1;j>=0;j--){
			if(a[j]==a[i] ){
				izadji=1;
				break;
			}
		}
		
			if(izadji==0){
				for(j=0;j<velb;j++){
					if(a[i]==b[j]){
						pbr++;
						break;
					}
				}
				for(j=0;j<velc;j++){
					if(a[i]==c[j]){
						pbr++;
						break;
					}
				}
				if(pbr==1) br++;
			}
	}
		for(i=0;i<velb;i++){
		izadji=0;
		pbr=0;
		
		for(j=i-1;j>=0;j--){
			if(b[j]==b[i] ){
				izadji=1;
				break;
			}
		}
		if(izadji==0){
			for(j=0;j<velc;j++){
				napolje=0;
				for(z=j-1;z>0;z--){
					if(c[j]==c[z])
						napolje=1;
						break;
				}
				if(napolje==1)
					continue;
				
				
				if(b[i]==c[j]){
					
					
					pbr=1;
					for(z=0;z<vela;z++){
						if(a[z]==b[i]){
							pbr=2;
							break;
						}
					}
					if(pbr==1) br++;
					}
				}
			}
		}
	
	return br;
}
	
	
int main() {
	//int niza[5]={1,3,1,2,8};
	//int nizb[4]={1,4,3,7};
	//int nizc[5]={2,5,1,7,8};
	// int rez=dva_od_tri(niza,5,nizb,4,nizc,5);
	 //printf("%d",rez);

	return 0;
}

