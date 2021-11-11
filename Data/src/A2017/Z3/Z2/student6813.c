#include <stdio.h>
#include<math.h>

void zaokruzi1(float *niz,int vel)
{
    float *p=niz;
    while(p<niz+vel) {
        *p *=10;
        *p= round(*p);
        *p /= 10;
        p++;
    }
}
int saberi(float a)
{
    int suma=0;
    int b;

    b=a*10;
    if(b<0)
        b=-b;

    while(b>0) {
        suma+=b%10;
        b /=10;
    }
    return suma;
}
void preslozi(float *p,int vel,int k)
{
    zaokruzi1(p,vel);
    int i,j;
    float tmp;
    for(i = 0; i < vel; i++) {
        for(j = 0; j < vel-1; j++) {
            if(saberi(p[j+1]) >= k && saberi(p[j]) < k) {
                tmp = p[j];
                p[j] = p[j+1];
                p[j+1] = tmp;
            }
        }
    }

}

int main()
{

    return 0;
}
