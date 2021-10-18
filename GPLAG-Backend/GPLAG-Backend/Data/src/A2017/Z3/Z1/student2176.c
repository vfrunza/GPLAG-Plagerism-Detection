#include <stdio.h>

int dva_od_tri(int *niz1,int vel1,int *niz2,int vel2,int *niz3,int vel3){
    int i=0,j=0,k=0,l=0,x=0,s=0;
    
    for(i=0;i<vel1;i++){
        for(k=0;k<i;k++){
            if(niz1[i]==niz1[k]){
                x=1;
                break;
            }
        }
        if(x){
            x=0;
            continue;
        }
        for(j=0;j<vel2;j++){
            if(niz1[i]==niz2[j]){
                for(l=0;l<vel3;l++){
                    if(niz1[i]==niz3[l])break;
                }
                if(l==vel3){
                s++;
                break;
                }
            }
        }
    }
    x=0;
    for(i=0;i<vel1;i++){
        for(k=0;k<i;k++){
            if(niz1[i]==niz1[k]){
                x=1;
                break;
            }
        }
        if(x){
            x=0;
            continue;
        }
        for(j=0;j<vel3;j++){
            if(niz1[i]==niz3[j]){
                for(l=0;l<vel2;l++){
                    if(niz1[i]==niz2[l])break;
                }
                if(l==vel2){
                    s++;
                    break;
                }
            }
        }
    }
    x=0;
    for(i=0;i<vel2;i++){
        for(k=0;k<i;k++){
            if(niz2[i]==niz2[k]){
                x=1;
                break;
            }
        }
        if(x){
            x=0;
            continue;
        }
        for(j=0;j<vel3;j++){
            if(niz2[i]==niz3[j]){
                for(l=0;l<vel1;l++){
                    if(niz2[i]==niz1[l])break;
                }
                if(l==vel1){
                    s++;
                    break;
                }
            }
        }
    }
    return s;
    
}

int main() {
	
	return 0;
}
