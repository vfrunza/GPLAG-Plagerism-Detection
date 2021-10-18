#include <stdio.h>

int provjeri(char *s){
    char a[100][100]={""};
    int i=0, j=0,k=0, brojac=0, zagrade=0, kontrola=0, n=0, l=0, suma=0, b=0;
    char *p=s, *q=s;
    
    while(*q){
        if(*q=='<')zagrade++;
        if(*q=='>')zagrade--;
        if(zagrade==-1){
          //  printf("ne valjaju zagrade");
            return 0;
            }
        q++;
    }
    if(zagrade>0){
      //  printf("nq valjaju zagrade");
        return 0;
        
    }
    
    while(*p){
        if(*p=='<' && *(p+1)!='/'){
            p++;
            if(*p==' ')return 0;
            while(*p!=' ' && *p!='>'){
                a[brojac][j]=*p;
                p++;
                j++;
            }
            a[brojac][j]='\0';
            j=0;
            brojac++;
        }
        else if(*p=='<' && *(p+1)=='/'){
            p++;
            if(*(p+1)==' ')return 0;
            while(*p!=' ' && *p!='>'){
                a[brojac][j]=*p;
                p++;
                j++;
            }
            a[brojac][j]='\0';
            j=0;
            brojac++;
            
        }
        else p++;
    }
    b=brojac;
/*for(i=0;i<brojac;i++){
    for(k=0;k<20;k++){
        printf("%c",a[i][k]);
    }
    printf("\n");
}
printf("\n");*/
for(i=0;i<brojac;i++){
    if(a[i][0]=='/'){
        for(k=i-1;k<i;k++){
            for(j=0;j<20;j++){
                if(a[k][j]!=a[k+1][j+1])kontrola=1;
            }
        }
        if(kontrola==0){
            for(n=i-1;n<brojac;n++){
                for(l=0;l<20;l++){
                    a[n][l]=a[n+1][l];
                }
        }
        
        brojac--;
        for(n=i-1;n<brojac;n++){
            for(l=0;l<20;l++){
                a[n][l]=a[n+1][l];
            }
        }
        brojac--;
        suma++;
    }
    else return 0;
}
}
//printf("%d",suma);

return 1;
}

int main() {
    char s[]="<div armin></div><div><a></a>";
	int x=-1;
	x=provjeri(s);
	printf("\n");
	printf("%d",x);
	return 0;
}
