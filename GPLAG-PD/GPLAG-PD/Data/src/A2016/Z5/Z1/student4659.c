#include <stdio.h>
#include <math.h>
#include <string.h>

struct Student{
	char ime[20],prezime[20];
	int ocjene[50],br_ocjena;
};


int genijalci(struct Student *p,int vel,float prosjek){
	struct Student *i=p,*k;
	int j,sum;
	float prs=0,max1=0,max2=0,max3=0;
	
	struct Student *one=NULL;
	struct Student *two=NULL;
	struct Student *three=NULL;
	
	
	while(i!=(p+vel)){
		prs=0;
	    sum=0;
	    
		for(j=0;j<(i->br_ocjena);j++){
			if(i->ocjene[j]==5){
				prs=5.0;
				break;
			}
			sum+=(i->ocjene[j]);
		}
		if(fabs(prs-0)<0.000001){
			prs=sum/(double)(i->br_ocjena);
			if(prs>max1 && prs>max2 && prs>max3){
				max3=max2;
				   
				max2=max1;
				    
				max1=prs;
				   
			}
			if(prs<max1 && prs>max2 && prs>max3){
				max3=max2;
				   
				max2=prs;
				    
			}
			if(prs<max1 && prs<max2 && prs>max3){
				max3=prs;
				    
			}
		}
		if(prs<prosjek || (i->br_ocjena)==0){
			k=i;
			while(k+1!=p+vel){
				*(k)=*(k+1);
				k++;
			}
			i--;
			vel--;
		}
		i++;
	}
	i=p;
	while(i!=(p+vel)){
		    prs=0;
	        sum=0;
			for(j=0;j<(i->br_ocjena);j++){
			    if(i->ocjene[j]==5){
				    prs=5.0;
				    break;
			    }
			    sum+=(i->ocjene[j]);
		    }
		    
		    if(fabs(prs-0)<0.000001){
			    prs=sum/(double)(i->br_ocjena);
		    }
		    if(one==NULL){
		        if(prs==max1){
                    one=i;
		        }
		    }
		    if(prs==max1){    
		        if(strcmp(one->prezime,i->prezime)>0){
		        	three=two;
		        	two=one;
		        	one=i;
		        }
		        if(strcmp(one->prezime,i->prezime)==0){
		        	if(strcmp(one->ime,i->ime)>0){
		        		three=two;
		        		two=one;
		        		one=i;
		        	}
		        }
		        if(strcmp(one->prezime,i->prezime)==0){
		        	if(strcmp(one->ime,i->ime)==0){
		        		if(one!=i){
		        		    three=two;
		        		    two=one;
		        		    one=i;
		        		}
		        	}
		        }
		    }
	    i++;
    }
if(two==NULL){
    i=p;
    while(i!=(p+vel)){
		    prs=0;
	        sum=0;
			for(j=0;j<(i->br_ocjena);j++){
			    if(i->ocjene[j]==5){
				    prs=5.0;
				    break;
			    }
			    sum+=(i->ocjene[j]);
		    }
		    
		    if(fabs(prs-0)<0.000001){
			    prs=sum/(double)(i->br_ocjena);
		    }
		    if(two==NULL){
		        if(prs==max2){
                    two=i;
		        }
		    }
		    if(prs==max2){  
		        if(strcmp(two->prezime,i->prezime)>0){
		        	three=two;
		        	two=i;
		        }
		        if(strcmp(two->prezime,i->prezime)==0){
		        	if(strcmp(two->ime,i->ime)>0){
		        		three=two;
		        		two=i;
		        	}
		        
		        if(strcmp(two->prezime,i->prezime)<0){
		    	    if(three==NULL) three=i;;
		        }
		        
		        if(strcmp(two->prezime,i->prezime)==0){
		        	if(strcmp(two->ime,i->ime)==0){
		        		if(two!=i){
		        			three=two;
		        		    two=i;
		        		}    
		        	    }
		        	}
		    	}
		    }
	    i++;
    }
}

if(three==NULL){
    i=p;
    while(i!=(p+vel)){
		    prs=0;
	        sum=0;
			for(j=0;j<(i->br_ocjena);j++){
			    if(i->ocjene[j]==5){
				    prs=5.0;
				    break;
			    }
			    sum+=(i->ocjene[j]);
		    }
		    
		    if(fabs(prs-0)<0.000001){
			    prs=sum/(double)(i->br_ocjena);
		    }
		    if(three==NULL){
		        if(prs==max3){
                    three=i;
		        }
		    }
		    if(prs==max3){    
		        if(strcmp(three->prezime,i->prezime)>0){
		        	three=i;
		        }
		        if(strcmp(three->prezime,i->prezime)==0){
		        	if(strcmp(three->ime,i->ime)>0){
		        		three=i;
		        	}
		        }
		        
		        if(strcmp(three->prezime,i->prezime)<0){
		    	  if(three==NULL) three=i;
		    	}
		    }
	    i++;
    }
}
    if(one!=NULL) printf("%s %s\n",one->prezime,one->ime);
    if(two!=NULL) printf("%s %s\n",two->prezime,two->ime);
    if(three!=NULL) printf("%s %s\n",three->prezime,three->ime);

	return vel;
}

int main() {
	
	return 0;
}
