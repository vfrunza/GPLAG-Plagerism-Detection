
#include <iostream>

using namespace std;

void mergeBrisanjeKolizija(int* A, int &vel, int l, int p, int q, int u, int* B){
    int indeks=0;
    int pocetak=l;
    while(1){
        bool imaMinus=false;
        if(A[l]==-1){
            l=p;
            imaMinus=true;
        }
        if(A[q]==-1){
            q=u;
            imaMinus=true;
        }
        if(imaMinus)break;
        if(A[l]<A[q]){
            B[indeks]=A[l];
            l++;
        } else {
            B[indeks]=A[q];
            q++;
        }
        indeks++;
        while(l<=p){
            if(A[l]==-1){
                l=p+1;
                break;
            }
            if(A[l]/100==B[indeks-1]/100){
                l++;
                vel--;
            } else break;
        }
        if(l==p+1)break;
        while(q<=u){
            if(A[q]==-1){
                q=u+1;
                break;
            }
            if(A[q]/100==B[indeks-1]/100){
                q++;
                vel--;
            } else break;
        }
        if(q==u)break;
    }
    while(l<=p){
        if(A[l]==-1){
            l=p+1;
            break;
        }
        B[indeks]=A[l];
        indeks++;
        l++;
        while(l<=p){
            if(A[l]/100==B[indeks-1]/100){
                l++;
                vel--;
            } else break;
        }
        if(l==p+1)break;
    }
    while(q<=u){
        if(A[q]==-1){
            q=u+1;
            break;
        }
        B[indeks]=A[q];
        indeks++;
        q++;
        while(q<=u){
            if(A[q]/100==B[indeks-1]/100){
                q++;
                vel--;
            } else break;
        }
        if(q==u+1)break;
    }
    for(int i=0;i<indeks;i++){
        A[pocetak+i]=B[i];
    }
    for(int i=indeks;i<(u-pocetak+1);i++){
        A[pocetak+i]=-1;
    }
}

void merges(int* A, int poc, int kraj, int &vel, int* B){
    if(kraj-poc<1)return;
    merges(A, poc, (poc+kraj)/2, vel, B);
    merges(A, (poc+kraj)/2+1, kraj, vel, B);
    mergeBrisanjeKolizija(A, vel, poc, (poc+kraj)/2, (poc+kraj)/2+1, kraj, B);
    for(int i=0;i<vel;i++)cout<<B[i]<<" "; cout<<endl;
} 
/*
template<typename t>
void merge2(t* A, int vel, int pa, int za, int pb, int zb, int *B)
{
    int i=pa, j=pb, k=0;
    t* a= new t[vel];
    while(i<=x && j<=z)
    {
        if(niz[i]<=niz[j]) a[k++]=niz[i++];
        else a[k++]=niz[j++];
    }
    while(i<=x) a[k++]=niz[i++];
    while(j<=z) a[k++]=niz[j++];
    k=0;
    for(int i=p; i<=z; ++i) niz[i]=a[k++];
    delete [] a;
}

template<typename Tip>
void merge_sort(Tip* niz, int vel, int p=-1, int z=-1) 
{
    if(p==-1 && z==-1) { p=0; z=vel-1;}
    if(p<z)
    {
        int x=p+(z-p)/2;
        merge_sort(niz,vel,p,x);
        merge_sort(niz,vel,x+1,z);
        merge2(niz,vel,p,z,x);
    }
}
*/
int main()
{
    int A[]={1, 101, 72, 15, 57, 258, 300, 359, 700, 568, 453, 789};
    int B[]={0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int vel=12;
    merges(A, 0, 11, vel, B);
    cout<<vel<<"\n";
    for(int i=0;i<12;i++){
        cout<<A[i]<<" ";
    }
    return 0;
}
