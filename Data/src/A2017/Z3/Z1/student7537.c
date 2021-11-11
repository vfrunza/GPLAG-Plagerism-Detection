#include <stdio.h>

int dva_od_tri(int* niz1, int vel1, int* niz2, int vel2, int* niz3, int vel3){
	int i, j, p, br2=0, br3=0, k, br=0, e1=niz1[0], e2=niz2[0], e3=niz3[0], p1[1000]={0}, p2[1000]={0}, p3[1000]={0}, a1, a2, a3;
	for(i=0; i<vel1; i++)
	p1[i]=niz1[i];
	for(i=0; i<vel2; i++)
	p2[i]=niz2[i];
	for(i=0; i<vel3; i++)
	p3[i]=niz3[i];
	a1=vel1; a2=vel2; a3=vel3;
	
	for(j=1; j<vel1; j++){
	for(i=j; i<vel1; i++)
	if(e1==niz1[i]){ if(i==vel1-1) vel1--;
	else {for(p=i; p<vel1-1; p++)
		niz1[p]=niz1[p+1];
		vel1--;
		i--;
	}} e1=niz1[j];}

	
	for(j=1; j<vel2; j++){
	for(i=j; i<vel2; i++)
	if(e2==niz2[i]){ if(i==vel2-1) vel2--;
	else {for(p=i; p<vel2-1; p++)
		niz2[p]=niz2[p+1];
		vel2--;
		i--;
	}} e2=niz2[j];}

	
	for(j=1; j<vel3; j++){
	for(i=j; i<vel3; i++)
	if(e3==niz3[i]){ if(i==vel3-1) vel3--;
	else {for(p=i; p<vel3-1; p++)
		niz3[p]=niz3[p+1];
		vel3--;
		i--;
	}} e3=niz3[j];}

	
		for(i=0; i<vel1; i++){ 
		for(j=0; j<vel2; j++) 
			if(niz1[i]==niz2[j]){ 
				br2++; break;}
			
		for(p=0; p<vel3; p++)
			if(niz3[p]==niz1[i]){ 
			    br3++; break;}
			    
		if(br2==br3 && br2!=0) {
			br2=br3=0;
			if(j==vel2-1) vel2--;
		    else {
			for(k=j; k<vel2-1; k++){
			    niz2[k]=niz2[k+1];
				} vel2--;}
			if(p==vel3-1) vel3--;
			else{ for(k=p; k<vel3-1; k++){
			    niz3[k]=niz3[k+1];
				} vel3--;}}
		    
				
		 else {
			br+=br2+br3;
			br2=br3=0;
		}
	}
	for(i=0; i<vel2; i++)
		for(j=0; j<vel3; j++)
			if(niz2[i]==niz3[j]) 
				br++;
	for(i=0; i<a1; i++)
	niz1[i]=p1[i];
	for(i=0; i<a2; i++)
	niz2[i]=p2[i];
    for(i=0; i<a3; i++)
	niz3[i]=p3[i];
	
	return br;
}

int main(){
	int niz1[100], niz2[100], niz3[100], vel1, vel2, vel3, i=0;
	scanf("%d", &vel1);
	for(i=0; i<vel1; i++)
		scanf("%d", &niz1[i]);
	scanf("%d", &vel2);
	for(i=0; i<vel2; i++)
		scanf("%d", &niz2[i]);
	scanf("%d", &vel3);
	for(i=0; i<vel3; i++)
		scanf("%d", &niz3[i]);
	printf("%d", dva_od_tri(niz1, vel1, niz2, vel2, niz3, vel3));
	return 0;
}
