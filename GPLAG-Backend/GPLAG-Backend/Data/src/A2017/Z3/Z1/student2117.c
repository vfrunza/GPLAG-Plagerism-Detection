#include <stdio.h>


int dva_od_tri(int a[], int i, int b[], int j, int c[], int k){
	int p,q,r,z,brojac=0,ispitivac=0;
   /*if((a[p]==a[p-1]) && p!=0 && p<i-1) p++;
            
                if((b[q]==b[q-1]) && q!=0 && q<j-1) q++;
               
               if((c[r] == c[r-1]) && r!=0 && r<k-1) r++;*/
  
 
     for ( p = 0; p < i; p++)
     {   
         for ( q = 0; q < j; q++)
         {    
          ispitivac = 0;
          
          
          if( a[p] == b[q] ){
              for( r = 0; r < k; r++){
                
                if (b[q] == c[r]){
                 ispitivac = 0; 
                 break;
                } else{
                 ispitivac = 1;
              }
               
              }
          if (ispitivac == 1){ brojac++; 
          
          }
         }
         if(a[p] == b[q] && k==0){
          brojac++;
         }
     }
     
     }
    
     
     
    
      for ( q = 0; q < j; q++)
      {  
          for ( r = 0; r < k; r++)
          { 
           ispitivac = 0;
           if(b[q] == c[r])
           {
               for( p = 0; p < i; p++)
               { 
               if(c[r] == a[p])
               {
                ispitivac = 0;
                break;
               }
               else ispitivac = 1;
                
               }
               
               if (ispitivac == 1){brojac++;
                
               }
           }
           if(b[q]==c[r] && i==0){
            brojac++;
           }
          
      }
      }
      
     
     
    
      for( p = 0; p < i; p++)
 		   {    
 		       for( r = 0; r < k; r++)
 		       { 
 		        ispitivac = 0;
 		       if (a[p] == c[r]){
 		           for ( q = 0; q < j; q++)
 		           {  
 		              
 		               if(c[r] == b[q])
 		               {
 		                ispitivac = 0;
 		                break;
 		               } else ispitivac = 1;
 		               
 		               
 		           }
 		           if(ispitivac == 1){ brojac++;
 		            
 		           }
 		       }
 		       if(a[p] == c[r] && j==0){
 		        brojac++;
 		       }
 		   }
 		   
 		   }
     
   
	
return brojac;	
}
int main() {
   
	  
	 


	return 0;
}
