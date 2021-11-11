#include <stdio.h>
struct Student{
	char ime[20],prezime[20];
	int ocjene[50];
	int br_ocjena;
};
void Napisi(struct Student student){
	printf("%s %s\n",student.prezime,student.ime);
}
int uporedi(char* s1,char* s2){
	while(*s1!='\0' && *s2!='\0'){
		if(*s1<*s2) return -1;
		if(*s1>*s2) return 1;
	}
	if(*s1!='\0')return 1;
	if(*s2!='\0')return -1;
	return 0;
}
int Prosjek(struct Student student){
	int i;
	float suma=0;
	float prosjek;
	if(student.br_ocjena==0){
		prosjek=5;
		return prosjek;
	}
	for(i=0;i<student.br_ocjena;i++){
		if(student.ocjene[i]==5){
			break;
			prosjek=5;
			return prosjek;
		}
	}
	for(i=0;i<student.br_ocjena;i++){
		suma+=student.ocjene[i];
	}
	prosjek=(float)suma/student.br_ocjena;
	return prosjek;
}


int genijalci(struct Student studenti[],int velicina,float prosjek){
	int i;
	int j;
	for(i=0;i<velicina;i++){
		if(Prosjek(studenti[i])<prosjek){
			for(j=i;j<velicina-1;j++){
				studenti[j]=studenti[j+1];
			}
			velicina--;
			i--;
		}
	}
	for(i=0;i<velicina;i++){
		Napisi(studenti[i]);
	}
	return velicina;
	
	}
	

int main() {
	 struct Student studenti[5] ={
	{ "Mujo", "Mujic", { 7,7,7,7,8}, 5}, 
	{ "Pero", "Peric", { 8,8,8,8,7}, 5}, 
	{ "Beba", "Bebic", { 6,6,6,6,6}, 5},
	{ "Mujo", "Mujic", { 7,7,7,7,8}, 5}, 
	{ "Fata", "Fatic", { 7,7,7,8,8}, 5}, 
};
genijalci(studenti, 5, 6.5);
    
        
        
    
	
	return 0;
}
