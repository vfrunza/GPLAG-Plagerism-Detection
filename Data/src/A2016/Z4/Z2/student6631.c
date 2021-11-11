#include <stdio.h>
char* kodiraj(char* txt, char* povrat){
	char* pamti=povrat, *pmt=txt, tmpp;
	int mat[95][2],i,j,temp,tmp;
	for(i=0;i<95;i++){
		mat[i][0]=0;
		mat[i][1]=i+32;
	}
	while(*txt!='\0'){
	mat[(*txt)-32][0]++;
	txt++;
	}
	for(i=0;i<94;i++){
	for(j=i;j<95;j++){
		if(mat[i][0]<mat[j][0] || (mat[i][0]== mat[j][0] && mat[i][1] > mat[j][1])){
			temp=mat[i][0];
			tmp=mat[i][1];
			mat[i][0]=mat[j][0];
			mat[i][1]=mat[j][1];
			mat[j][0]=temp;
			mat[j][1]=tmp;
		}
	}}
	
	for(i=0;i<95;i++) mat[i][0]= 126 - i;
	povrat=pamti;
	for(i=0;i<95;i++){
		*povrat=mat[i][1];
		povrat++;
	}
	*povrat='\0';
	for(i=0;i<94;i++){
		for(j=i; j<95;j++){
			if(mat[i][1]>mat[j][1]){
				temp = mat[i][0];
				tmp= mat[i][1];
				mat[i][0]=mat[j][0];
				mat[i][1]=mat[j][1];
				mat[j][0]=temp;
				mat[j][1]=tmp;
			}
		}
			
	}
	txt=pmt;
	tmpp = *txt;
	while(tmpp != '\0'){
		*txt= mat[tmpp-32][0];
		txt++;
		tmpp=*txt;
	}
	
	*povrat='\0';
	
	return pmt;
}

char* dekodiraj(char* txt, char* dekod){
	char*pmt=txt,tmpp;
	int mat[95][2],i,j,temp,tmp;
	for(i=0;i<95;i++){
		mat[i][0]=0;
		mat[i][1]=i+32;
	}
	while(*txt!='\0'){
		mat[(*txt)-32][0]++;
		txt++;
	}
	for(i=0;i<94;i++){
		for(j=i;j<95;j++){
			if(mat[i][0]<mat[j][0]|| (mat[i][0]==mat[j][0]&& mat[i][1]<mat[j][1])){
				temp=mat[i][0];
				tmp=mat[i][1];
				mat[i][0]=mat[j][0];
				mat[i][1]=mat[j][1];
				mat[j][0]=temp;
				mat[j][1]=tmp;
			}
		}
	}
	for(i=0;i<95;i++){mat[i][0]=*dekod; dekod++;}
	
	for(i=0;i<94;i++){
		for(j=i;j<95;j++){
		if(mat[i][1]>mat[j][1]){
			temp=mat[i][0];
			tmp=mat[i][1];
			mat[i][0]=mat[j][0];
			mat[i][1]=mat[j][1];
			mat[j][0]=temp;
			mat[j][1]=tmp;
			}	
		}
	}
	txt=pmt;
	tmpp=*txt;
	while(tmpp!='\0'){
		*txt=mat[tmpp-32][0];
		txt++;
		tmpp=*txt;
	}
	return pmt;
}



int main() {
	char tekst[]="LLMLNLNMONM",sifrarnik[100]="",*pok;
	pok=kodiraj(tekst,sifrarnik);
	pok=dekodiraj(tekst,sifrarnik);
	while(*pok!='\0'){
	printf("%c",*pok);
	pok++;
	}
	return 0;
}
