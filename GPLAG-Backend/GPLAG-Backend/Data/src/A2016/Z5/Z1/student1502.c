#include <stdio.h>
#define eps 0.00000000000001

struct Student {
	char ime[20], prezime[20];
	int ocjene[50];
	int br_ocjena;
};

int genijalci(struct Student s[], int vel, double p){
	int i,j,k;
	int d=vel;
	int l=0;
	double niz[100];
	double prosjek = 5.0;
	for(i=0; i<vel;i++){
		int suma = 0;
		int test=1;
		if(s[i].br_ocjena == 0){
			prosjek=5.0;
			test=0;
			niz[l]=prosjek;
			l++;
		} 
		for(j=0;j<s[i].br_ocjena;j++){
			suma+=s[i].ocjene[j];
			if(s[i].ocjene[j] == 5){
				prosjek = 5.0;
				test = 0;
				niz[l] = prosjek;
				l++;
				break;
			} 
		}
		if(test==1){
			prosjek=suma/(s[i].br_ocjena*1.0);
			niz[l]=prosjek;
			l++;
		}
		if(prosjek-p < 0.0){
			for(k=i;k<vel-1;k++){
				s[k]=s[k+1];
			}
			vel--;
			i--;
			l--;
		}
	
	}

 double max=0;
 	int index1 = -1,index2 = -1,index3 = -1;
		for(j=0;j<vel;j++){
			if(max<niz[j]) {
				max=niz[j];
				index1=j;
			}
			if(max-niz[j]<eps && j!=0){
				char *q=&s[j].prezime[0],*t=&s[index1].prezime[0];
				int temp=0;
				while(*q!='\0' && *t!='\0'){
					
					if(*q<*t){ index1=j;
					temp++;
						break;
					}
					else if(*t<*q){
						break;	
					} 
					q++; t++;
				}
				if(temp==0){
				char *q=&s[j].ime[0],*t=&s[index1].ime[0];
				
				while(*q!='\0' && *t!='\0'){
					
					if(*q<*t){ index1=j;
					
						break;
					}
					else if(*t<*q){
						break;	
					} 
					q++; t++;
				}
					
				}
			}
			
		}
		max = 0;
		for(k=0;k<vel;k++){
			if(k != index1 && niz[k]>max){
				max=niz[k];
				index2=k;
			}
			if(max-niz[k]<eps && k!=0 && k!=index1){
				char *q=&s[k].prezime[0],*t=&s[index2].prezime[0];
				int temp=0;
				while(*q!='\0' && *t!='\0'){
					
					if(*q<*t){ index2=j;
					temp++;
						break;
					}
					else if(*t<*q){
						break;	
					} 
					q++; t++;
				}
				if(temp==0){
				char *q=&s[k].ime[0],*t=&s[index2].ime[0];
				
				while(*q!='\0' && *t!='\0'){
					
					if(*q<*t){ index2=k;
					
						break;
					}
					else if(*t<*q){
						break;	
					} 
					q++; t++;
				}
					
				}
			}
			
		    
		
			
		}
		max = 0;
		for(i=0;i<vel;i++){
			if(i != index2 && i != index1 && niz[i]>max){
				max=niz[i];
				index3=i;
			}
			if(max-niz[i]<eps && i!=0 && i!=index1 && i!= index2){
				char *q=&s[i].prezime[0],*t=&s[index3].prezime[0];
				int temp=0;
				while(*q!='\0' && *t!='\0'){
					
					if(*q<*t){ index3=i;
					temp++;
						break;
					}
					else if(*t<*q){
						break;	
					} 
					q++; t++;
				}
				if(temp==0){
				char *q=&s[i].ime[0],*t=&s[index3].ime[0];
				
				while(*q!='\0' && *t!='\0'){
					
					if(*q<*t){ index3=i;
					
						break;
					}
					else if(*t<*q){
						break;	
					} 
					q++; t++;
				}
					
				}
			}
			
		
			
		}
		if(index1 != -1) printf("%s %s \n",s[index1].prezime,s[index1].ime);
		if(index2 != -1) printf("%s %s \n",s[index2].prezime,s[index2].ime);
		if(index3 != -1) printf("%s %s \n",s[index3].prezime,s[index3].ime);
		
	//printf("%d, %d, %d", index1, index2, index3);
return vel;
}
int main() {

	return 0;
}
