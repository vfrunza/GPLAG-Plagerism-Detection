#include <stdio.h>
int dva_od_tri(int niz1[],int n1,int niz2[],int n2,int niz3[],int n3)
{
    int i,j,br=0,x=0,y=0;
    for(i=0; i<n1; i++) {
        for(j=0; j<n2; j++) {
            if(niz1[i]==niz2[j]) {
                br=br+1;
            }
        }
        for(j=0; j<n3; j++) {
            if(niz1[i]==niz3[j]) {
                br=br+1;
            }
        }
        if(br==1) {
            x=x+1;
        }
        br=0;
    }
    for(i=0; i<n2; i++) {
        for(j=0; j<n3; j++) {
            if(niz2[i]==niz3[j]) {
                br=br+1;
            }
        }
        
        if(br==1) {
            x=x+1;
        }
        br=0;
    }
    
    return x;
}

int main()
{

    return 0;
}
