#include<stdio.h>
int drugi(int niz[],int velicina)
{
   int i,max1,indmax1=0,indmax2,p=0;
   max1=niz[0];
   
   

   for(i=1;i<velicina;i++){
       if(niz[i]>max1){
           max1=niz[i];
           indmax1=i;
           
   }
}   
    for(i=0;i<velicina;i++){
        
        if(i!=indmax1)
        { 
            if (p==0){ 
            indmax2=i; 
            p=1;
            if(niz[i]==indmax1){
            p=0;
            }
        }
            if(niz[i]>niz[indmax2] && niz[i]!=niz[indmax2] && niz[i]!=max1)
            indmax2=i;
        }
      
}
   if(p==0)
   return -1;
   else
   return indmax2;

}



int main()
{
  int niz[] = {10,5,4,9,8,3,-1};
  printf("Unesite niz brojeva: ");
printf("Indeks drugog po velicini je: %d", drugi(niz, 7));
return 0;	
}