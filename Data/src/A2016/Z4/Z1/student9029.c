#include <stdio.h>

int da_li_je_ista(char *niz, int vel, char* max_rijec, char *pocetak){
	
	int i=0;
	
	if(niz!=pocetak){ 
		if(((*(niz-1)>=65 && *(niz-1)<=90) || (*(niz-1)>=97 && *(niz-1)<=122)))
	       return 0;}
	
	for(i=0;i<vel;i++){
		if(*niz!=*max_rijec){
		   if(*niz>*max_rijec){
		   	if(*niz!=*max_rijec+32)
		   	   return 0 ;
		   }
		   if(*niz<*max_rijec){
		   	if(*niz!=*max_rijec-32)
		   	   return 0 ;
		   }
		}
		if(*niz=='\0') return 0;
		niz++; max_rijec++;
	}
	
    if(*(niz)!='\0'){
	    if(((*(niz)>=65 && *(niz)<=90) || (*(niz)>=97 && *(niz)<=122)))
	    return 0;}
	    
	return 1;
}

char * izbaci_najcescu(char *niz){
	
	char max_rijec1[100]="", max_rijec2[100]="";
	int pon1=0, pon2=0, ista=0, velicina2=0, velicina1=0,j;
	char* temp,* pocetak, *pok_na_max2, *ostatak;
	
	pocetak=niz;
	temp=niz;
	
	while(*temp!='\0'){
		niz=temp;
		pon2=0;
		velicina2=0;
		while((*niz<65 || *niz>122 || (*niz>90 && *niz<97)) && *niz!='\0')
			niz++;
			if(*niz=='\0') break;
	    pon2++;
	    while(((*niz>=65 && *niz<=90) || (*niz>=97 && *niz<=122)) && *niz!='\0'){
	    	max_rijec2[velicina2]=*niz;
			niz++; velicina2++;
	    }
	    pok_na_max2=niz;
	    
	    while(*niz!='\0'){
	    	while((*niz<65 || *niz>122 || (*niz>90 && *niz<97)) && *niz!='\0') niz++;
	    	if(*niz=='\0') break;
	    	ista=da_li_je_ista(niz, velicina2, max_rijec2, pocetak);
	    	if(ista==1){pon2++; for(j=0;j<velicina2;j++)niz++; }
	    	if(*niz=='\0') break;
	    	niz++;
	    	
	    }
	   if(pon2>pon1){
	   	    pon1=pon2;
	   	    for(j=0;j<velicina2;j++) max_rijec1[j]=max_rijec2[j]; 
	   	       velicina1=velicina2;}
	   	       
	   temp=pok_na_max2;
	}

	niz=pocetak;
		
    while(*niz!='\0'){
	    while((*niz<65 || *niz>122 || (*niz>90 && *niz<97)) && *niz!='\0') niz++;
	        if(*niz=='\0')break;
	    	ista=da_li_je_ista(niz, velicina1, max_rijec1, pocetak);
	    	if(ista==1){
	    		ostatak=niz+velicina1;temp=niz-1;
	    		while(*ostatak!='\0' && niz!='\0'){
	    			*niz=*ostatak;
	    			niz++;ostatak++;
	    		}
	    		*niz='\0';
	    		niz=temp;
	    	}
	    	niz++;
	    	if(*niz=='\0') break;
	    }
	return pocetak;
}

int main(){
	char niz[2000000];

	printf("%s", izbaci_najcescu(niz));
	return 0;
}