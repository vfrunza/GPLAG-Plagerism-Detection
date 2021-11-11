#include <stdio.h>

int dva_od_tri(const int niz1[], int vel1,const int niz2[],int vel2,const int niz3[],int vel3){
  
  int i,j,k,p,nevalja=0;
  int ima=0,br=0;
 
  for(i=0;i<vel1;i++){
      ima=0;
      for(j=0;j<vel2;j++){
          if(niz1[i]==niz2[j])
          ima=1;
      }
      for(k=0;k<vel3;k++){
          if(niz1[i]==niz3[k])
            ima=0;
      }
      if(ima==1) {
          for(p=0;p<i;p++)
            if(niz1[i]==niz1[p]) nevalja=1;
         if(nevalja!=1)
          br++;
         nevalja=0;
      }
  }
  
  
  for(i=0;i<vel1;i++){
      ima=0;
      for(j=0;j<vel3;j++){
          if(niz1[i]==niz3[j])
                ima=1;
      }
      for(k=0;k<vel2;k++){
          if(niz1[i]==niz2[k])
          ima=0;
      }
      if(ima==1) {
          for(p=0;p<i;p++)
            if(niz1[i]==niz1[p]) nevalja=1;
         if(nevalja!=1)
          br++;
         nevalja=0;
      }
      
  }
 
 for(i=0;i<vel2;i++){
     ima=0;
     for(j=0;j<vel3;j++){
         if(niz2[i]==niz3[j])
         ima=1;
     }
     for(k=0;k<vel1;k++){
         if(niz2[i]==niz1[k])
         ima=0;
     }
      if(ima==1) {
          for(p=0;p<i;p++)
            if(niz2[i]==niz2[p]) nevalja=1;
         if(nevalja!=1)
          br++;
         nevalja=0;
      }
     
 }
 
return br;  
}


int main (){
int niz1[] = {1, 2, 3, 5};
int niz2[] = {1, 2, 4, 6, 7};
int niz3[] = {1, 3, 4, 8, 9, 10};
int rez = dva_od_tri(niz1, 4, niz2, 5, niz3, 6);
printf("%d", rez);
	return 0;
}
