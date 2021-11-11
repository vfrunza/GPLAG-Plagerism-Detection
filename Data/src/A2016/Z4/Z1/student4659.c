#include <stdio.h>
char *izbaci_najcescu (char *s1){
	
	char *t=s1,*q1=NULL;
	char *p1=s1,*p2=NULL,*q2=NULL,*q3=NULL,*k=NULL,*z=NULL,*k1=NULL;
	int br,a=0;
	
	
	/*otvaramo petlju koja prolazi kroz dati string*/
	while(*s1!='\0'){
		
		/*postavljamo pokazivace na kraj i pocetak svake rijeci pojedinacno*/
		  if( ( (*(s1+1)>='A' && *(s1+1)<='Z') || (*(s1+1)>='a' && *(s1+1)<='z') ) && ( *s1<'A' || (*s1>'Z' && *s1<'a') || *s1>'z') )p1=s1+1;
		  if( ( (*s1>='A' && *s1<='Z') || (*s1>='a' && *s1<='z') ) && ( *(s1+1)<'A' || (*(s1+1)>'Z' && *(s1+1)<'a') || *(s1+1)>'z') )p2=s1+1;
		  if(p2!=NULL){
		  	
		  /*	pokazivac koji prolazi kroz ostatak rijeci */
		  	k=s1+1;
		  	br=1;
		  	 while(*k!='\0'){
		  	 	
		  	 	/*postavljamo pokazivace na kraj i pocetak svake rijeci pojedinacno osim vec gore uzete rijeci*/
		  	 	
		  		if( ( (*(k+1)>='A' && *(k+1)<='Z') || (*(k+1)>='a' && *(k+1)<='z') ) && ( *k<'A' || (*k>'Z' && *k<'a') || *k>'z') )q2=k+1;
		  		if( ( (*k>='A' && *k<='Z') || (*k>='a' && *k<='z') ) && ( *(k+1)<'A' || (*(k+1)>'Z' && *(k+1)<'a') || *(k+1)>'z') )q3=k+1;
		  		
		  		/*provjera da li su rijeci iste*/
		  		
		  		  if(q2!=NULL && q3!=NULL){
		  		  	char *k2=p1;
		  		  	while (k2!=p2){
		  		  		if(*k2!=*q2 && *k2!=*q2+32 && *k2!=*q2-32){
		  		  		q2=NULL;
		  		  		q3=NULL;	
		  		  		break;
		  		  		}
		  		  		q2++;
		  		  		k2++;
		  		  	}
		  		  	if(k2==p2 && q2!=q3){
		  		  		q3=NULL;
		  		  	}
		  		  	if(k2==p2 && q2==q3){ /*ako su jednake rijeci povecava se brojaac*/
		  		  		br++;
		  		  		q2=NULL;
		  		  		q3=NULL;
		  		    }
		  	    }
		  
		  k++;
		 }
		if(br>a){
			z=p1;
		    a=br;
		}
		p2=NULL;  
	 }
	
	
     s1++;  
	}
	
	/*najvise ponavljana rijec*/
	if(z==NULL){return t;}
	p1=z;
	
	while(*z!='\0'){
		if( *z<'A' || (*z>'Z' && *z<'a') || *z>'z'){
			
			break;
		}
		z++;
	}	
	p2=z;
	
	if(*z=='\0')z=t;
	
	/*brisanje najvise ponavljane rijeci*/
	while(*z<'A' || (*z>'Z' && *z<'a') || *z>'z')z++;
	q1=z;
	q2=q1;
	
	/*pokazivac prolazi kroz ostatak stringa*/
	
	while(*q1!='\0'){
		if( ( (*q1>='A' && *q1<='Z') || (*q1>='a' && *q1<='z') ) && ( *(q1+1)<'A' || (*(q1+1)>'Z' && *(q1+1)<'a') || *(q1+1)>'z') )q3=q1+1;        /*uzima pocetak i kraj rijeci*/
		if(q3!=NULL){
		k=p1;
		k1=q2;
		while(k!=p2){
			if(*k!=*k1 && *k!=*k1+32 && *k!=*k1-32)break;
			k1++;
			k++;
		}
		if(k==p2 && k1==q3){
			while(*q2!='\0'){
				*q2=*q3;
				if(*q2=='\0')break;
				q2++;
				q3++;
			 
			}
			q1=q1-(q3-q2);
		}
		
		}
		if( ( (*(q1+1)>='A' && *(q1+1)<='Z') || (*(q1+1)>='a' && *(q1+1)<='z') ) && ( *q1<'A' || (*q1>'Z' && *q1<'a') || *q1>'z') ){
			q2=q1+1;
			q3=NULL;
		}
		q1++;
	}
	
	/*brise rijec koja se najvise ponavlja*/
	while(*p1!='\0'){
		*p1=*p2;
		if(*p1=='\0')break;
		p1++;
		p2++;
	}
	return t;
}
int main() {
	char tekst[]={"JednaVeeeeeeeeeelikaRiiiiiiiiijec"};
	printf("%s",izbaci_najcescu(tekst));
	return 0;
}
