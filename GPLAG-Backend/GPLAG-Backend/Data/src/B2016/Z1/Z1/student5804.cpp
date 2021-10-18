/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<iostream>
#include<vector>
bool da_ne(int n){
	std::vector<int> brojaci{0,0,0};
	int x=n;
	int o;
		
	while(x!=0){
		o=x%3;
		for(int i=0; i<brojaci.size(); i++){
		if(o==i) brojaci[i]++;}
		x=x/3;
	}
	for(int i=0; i<brojaci.size(); i++){
	if((brojaci[0]%2==0 && brojaci[2]%2==0 && brojaci[1]%2==0) || (brojaci[0]%2!=0 && brojaci[1]%2!=0 && brojaci[2]%2!=0)) return 1;
	else return 0;}
}

std::vector<int> IzdvojiGadne(std::vector<int> V, bool da_ne(int n)){
	int *pp=V;
	int *pon=V;
	std::vector<int> NOVI;
	int pok_novi=NOVI;
	int ponavlja_se=0;
	while (*pp!=V.size()) *pp++;
	int *kraj=pp;
	pp=V;
	while(*pp!=V.size()){
		ponavlja_se=0;
		while(pon!=kraj){
			if(*pon==*pp) ponavlja_se=1;
			pon++;
		}
		if(ponavlja_se==0) *pok_novi++=*pp;
		pp++;
	}
	return NOVI;
}
int main ()
{
	return 0;
}