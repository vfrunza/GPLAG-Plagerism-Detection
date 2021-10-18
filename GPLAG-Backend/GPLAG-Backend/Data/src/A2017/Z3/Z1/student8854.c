#include<stdio.h>
int pomocna(int niz[],int vel,int broj){
    int *k=niz; int true=0;
    while(k<niz+vel){
        if(*k==broj){
            true=1;
            break;
        }
        k++;
    }
    return true;
}
void prepisi(int niz1[],int vel1,int niz2[]){
    int i;
    for(i=0;i<vel1;i++){
        niz2[i]=niz1[i];
    }
}
int izbaciiste(int niz1[],int vel){
    int i,j,k;
    for(i=0;i<vel-1;i++){
        for(j=i+1;j<vel;j++){
            if(niz1[i]==niz1[j]){
                for(k=j;k<vel-1;k++){
                    niz1[k]=niz1[k+1];
                }
                vel--;
                j--;
            }
        }
    }
    return vel;
    
}
int dva_od_tri(int niz1[],int vel1,int niz2[],int vel2,int niz3[],int vel3){
    int vela=vel1,velb=vel2,velc=vel3,a=0,b=0,brojac=0;
    int niza[50],nizb[50],nizc[50];
    int *p1=niza;
    int *p2=nizb;
    prepisi(niz1,vel1,niza);
    prepisi(niz2,vel2,nizb);
    prepisi(niz3,vel3,nizc);
    vela=izbaciiste(niza,vel1);
    velb=izbaciiste(nizb,vel2);
    velc=izbaciiste(nizc,vel3);
    while(p1<niza+vela){
        a=pomocna(nizb,velb,*p1);
        b=pomocna(nizc,velc,*p1);
        if((a==1&&b==0)||(a==0&&b==1))
            brojac++;
        p1++;
    }
    a=0;b=0;
    p1=niza;
    p2=nizb;
    while(p2<nizb+velb){
        a=pomocna(niza,vela,*p2);
        b=pomocna(nizc,velc,*p2);
        if(a==0 && b==1) brojac++;
        p2++;
    }
    return brojac;
}

int main(){
    int niz1[] = {1, 2, 3, 5};
    int niz2[] = {1, 2, 4, 6, 7};
    int niz3[] = {1, 3, 4, 8, 9, 10};
    int rez = dva_od_tri(niz1, 4, niz2, 5, niz3, 6);
printf("%d", rez);
    return 0;
}