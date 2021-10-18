#include <stdio.h>
int provjeri_duzine(char *s, int niz[], int vel){

	char *p=s; 
	int brojac = 0, i=0;
		if(*p=='\0' && vel==0) return 1; 
		
	   char *p1=p; /*da broji rijeci, kada su ne-slova na kraju stringa*/
  	  int brojacnovi=0, razmak=1;
  while(*p1!='\0'){

  	 if(!((*p1>= 'a' && *p1<= 'z') || (*p1 >= 'A' && *p1<= 'Z'))) razmak=1;
  	 else if(razmak==1){
  	 	razmak=0;
  	 	brojacnovi++;
  	 }
  p1++;
  }
    if(brojacnovi!=vel) return 0; /*za ne-slova*/
  
	while(*p!= '\0'&& i< vel) {
		brojac=0;
		while(!((*p >= 'a' && *p<= 'z') || (*p >= 'A' && *p<= 'Z')) && *p!='\0') p++; /*preskoci sve poceten razmake, ako ih ima*/
	     	while(((*p >= 'a' && *p<= 'z') || (*p >= 'A' && *p<= 'Z')) && *p!='\0'){ p++;
	        	brojac++;
	        
		}
		
	
	   if(niz[i]!=brojac) return 0;
		i++;
	}  

			while(!((*p >= 'a' && *p<= 'z') || (*p >= 'A' && *p<= 'Z')) && *p!='\0') p++;
  

	if(i==vel && *p=='\0')
	 
   return 1;
	else return 0;

}
  
int main()
{
	
	return 0;
}
