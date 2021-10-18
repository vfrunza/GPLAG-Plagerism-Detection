#include <stdio.h>
#include <math.h>
int main()
{
    int i,j,k,n,x,t,z;
    int a[100],b[2000];
    /*-1 ce biti vrijednost onog clana niza koji nece biti potreban,
    a to ce biti handy kad budem premjestao niz na prvih nekoliko mjesta,
    koliko to bude potrebno*/
    for(i=0; i<400; i++)
        b[i]=b[i+400]=b[i+800]=b[i+1200]=b[i+1600]=-1;

    printf("Unesite velicinu niza: ");
    do
    scanf("%d",&n);
    while(n<0||n>100);
    printf("Unesite clanove niza: ");


    for(i=0,k=0; i<n; i++) {
        
        do {
           
            scanf("%d",a+i);
        } while(a[i]<0 );
        /*prebrojavam koliko ukupno cu imati cifara u opticaju*/
        
        t=*(a+i);
        if(t==0)k++;
        else k+=log10(a[i])+1;
    }
    /*prolazim kroz pocetni niz i uzimam cifre i storam u finalni */
    for(i=k*2-2,j=n-1; i>-1; i-=2) {
        if(a[j]==0) {
            b[i]=0;
            j--;
        } else {
            b[i]=a[j]%10;
            a[j]/=10;

            if(a[j]==0)j--;
        }
    }
    /*x mi je brojacko mjesto i ono se promijeni svaki put kad se while prekine,
        tj. kad naiđe različit član
    z mi je vodeci clan podniza uzastopnih jednakih clanova*/
    /*    x=1;
        z=b[0];
        b[x]=1;*/
    for(i=2,x=1,z=b[0],b[x]=1; i<2*k; i+=2) {
        while(z==b[i]) {
            b[x]++;
            b[i]=-1;
            /*svaki clan koji je jednak prvom clanu podniza uzastopnih
            jednakih clanova, a nije prvi clan, ce postati -1,
            tj. nepotreban */
            i+=2;
        }
        x=i+1;
        z=b[i];
        b[x]=1;
    }
    /*prolazim kroz niz da isprebacujem sve clanove sto blize pocetku
    da nemam nepotrebnih clanova između clanova finalnog niza*/
    for(i=0; i<2*k; i++)
        for(j=0; j<2*k-1; j++) {
            if(b[j]==-1) {
                b[j]=b[j+1];
                b[j+1]=-1;
            }

        }

    printf("Finalni niz glasi:\n");
    /*ispisujem niz sve dok se ne pojavi broj manji od nula,
    a to je nepoetreban clan*/
    i=0;
    while(b[i]>=0&&i<2*k) {
        printf("%d",b[i]);
        if(b[i++ +1]!=-1)printf(" ");
        
    }

    return 0;
}