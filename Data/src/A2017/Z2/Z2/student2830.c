#include <stdio.h>

int main()
{
    int	a[100]= {0},br[101]= {0},c[101]= {0},d[101]= {0},b,f=0;
    int i=0,k=0,l=0,temp=0,j=0,n=0,r=0,s=0,t=0;
    printf("Unesite velicinu niza: ");
    scanf("%d",&n);
    printf("Unesite clanove niza: ");
    for(i=0; i<n; i++) {

        do  {
            scanf("%d",&a[i]);
        } while(a[i]<0);
    }
    i=0;

    for(j=0; j<n; j++) {
        l=0;
        if(a[j]<10 || a[j]%10!=0){
        do {
            c[i]=a[j]%10;
            i++;
            l++; 

            a[j]=a[j]/10;

        } while(a[j]%10!=0 || a[j]/10!=0);}
        else {
        do {
            c[i]=a[j]%10;
            i++;
            l++;

            a[j]=a[j]/10;

        } while(a[j]/10!=0 || a[j]%10!=0);}

        for(k=i-l; k<(i-l/2); k++) {
            r++;
            temp=c[k];
            c[k]=c[i-r];
            c[i-r]=temp;
        }
        r=0;

    }
     

    for(j=0; j<i; j++) {
        if(br[c[j]]==0) br[c[j]]++;
        
        if(c[j]==c[j+1]) {
            if((br[c[j]]>1) && (j!=0) && (c[j]!=c[j-1])) {
                
                br[c[j]+11]++;
            } else {
                if(br[c[j]+11]>1) br[c[j]+11]++;
                else br[c[j]]++;
            }
        }


    }


    for(j=0; j<i; j++) {
        if(j==0 || c[j]!=c[j-1]) {
            d[s]=c[j];
            s=s+2;
            t++;
        }


    }
    s=1;

    for(j=0; j<i; j++) {
        if(j==0 || c[j]!=c[j-1]) {
            if(j!=0) {
                for(b=j-1; b>0; b--) {
                    if(c[j]==c[b]) {
                        f=1;
                        break;
                    }
                }
            } else f=0;
            if(f==0)
                d[s]=br[c[j]];
            else d[s]=br[c[j]+11]+1;
            s=s+2;
            t++;
        }


    }

    printf("Finalni niz glasi:\n");
    for(j=0; j<t; j++) {
        if(j==t-1)
            printf("%d",d[j]);
        else printf("%d ",d[j]);

    }




    return 0;

}