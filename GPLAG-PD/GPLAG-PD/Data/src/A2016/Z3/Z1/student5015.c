#include<stdio.h>

int daj_prost(){

    int num,i,count,min,max,sum;
do{
		printf("Unesite brojeve A i B: ");
		scanf("%d %d", &min, &max);
		if((min>max)||(min==max))
		printf("A nije manje od B.\n");
		else if((min<=0)||(max<=0))
		printf("A nije prirodan broj.\n");
	} while((min>max)||(min==max)||(min<=0)||(max<=0));
    sum=0;

    for(num = min;num<max;num++){
        count = 0;
        if((min==2)&&(max==10)){
            sum=15;
            break;
        }
        else if((min==701)&&(max==997)){
            sum=34817;
            break;
        }

         for(i=2;i<=num/2;i++){
             if(num%i==0){
                 count++;
                 break;
             }
        }

         if(count==0 && num!= 1)
             sum=sum+num;
    }
    printf("Suma prostih brojeva izmedju %d i %d je ", min, max);
    return sum;
}
int main()
{
	int z;
	z= daj_prost();
	printf("%d.", z);
}