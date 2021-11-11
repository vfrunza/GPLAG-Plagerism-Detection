#include <stdio.h>

int dva_od_tri(int* niz1,int n1,int* niz2,int n2,int* niz3,int n3)  {   
	    int i=0,j=0;;
	    int niz4[100];
	    int br=0;
	    int jedan=0;
		int dva=0;
	    
	    while(i<n1) {
	        for(j=0;j<br;j++) {
	            if(niz1[i]==niz4[j]) {
	            	break;
	            }
	        }
	        if(j==br) {
	        	niz4[br]=niz1[i];
	        	br++;
	     }
	     i++;
	    }
	     i=0;
	     while(i<n2) {
	        for(j=0;j<br;j++) {
	            if(niz2[i]==niz4[j]) {
	            	break;
	            }
	        }
	        if(j==br) {
	        	niz4[br++]=niz2[i];
	     }
	     i++;
	     }
	     i=0;
	      while(i<n3) {
	        for(j=0;j<br;j++) {
	            if(niz3[i]==niz4[j]) {
	            	break;
	            }
	        }
	        if(j==br) {
	        	niz4[br++]=niz3[i];
	     }
	     i++;
	   }
	     i=0;
            while(i<br) {
            	jedan=0;
            	for(j=0;j<n1;j++)
            		{
            			if(niz1[j]==niz4[i]) {
            				jedan++;
            				break;
            				
            			}
            		}
            		for(j=0;j<n2;j++)
            		{
            			if(niz2[j]==niz4[i]) {
            				jedan++;
            				break;
            			}
            		}
            			for(j=0;j<n3;j++) {
            		
            			if(niz3[j]==niz4[i]) {
            				jedan++;
            				break;
            			}
            		}
            		if(jedan==2)dva++;
            		i++;
            		}
      	return dva;
           	     
	 }
	   
int main()
{

return 0;
}
