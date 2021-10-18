/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <cmath>
std::vector<int> ternarni(int broj){
	std::vector<int> v(0);
	int cifra;
	while(broj!=0){
		cifra=fabs(broj%3);
		v.push_back(cifra);
		broj/=3;
	}
  return v;
}
bool opaki_cifre(int broj){
	bool istina;
	if(broj==0)return false;
	std::vector<int>v=ternarni(broj); //ovim smo dobili cifre u ternarnom obliku
	istina=true;
	for(int i=0;i<v.size();i++){
		int brojac(0);
		for(int j=0;j<v.size();j++){
			if(v[i]==v[j])brojac++;
		}
		if(brojac%2!=0) {
			istina=false;
			break;
		}
	}
	
	return istina;
	
}
bool odvratni_cifre(int broj){
	bool istina(true);
	std::vector<int>v(ternarni(broj));  //opet smo pozvali fju od koje zelimo cifre da dobijemo
	for(int i=0;i<v.size();i++){
		int brojac(0);
		for(int j=0;j<v.size();j++){
			if(v[i]==v[j])brojac++;
		}
		if(brojac%2==0){
			istina=false;
			break;
		}
	}
	return istina;
}
std::vector<int> izbaci_iste(std::vector<int> v){
	
	for(int i=0;i<v.size();i++){
		for(int j=i+1;j<v.size();j++){
			if(v[i]==v[j]){
				v.erase(v.begin()+j);
				i--;
				break;
			}
		}
	}
	return v;
}
std::vector<int> IzdvojiGadne(std::vector<int> v,bool istina){
	if(istina ==true){ //opaki(paran broj svake cifre koja se javi u ternarnom zapisu)
	int broj;
//	int b=odvratni_cifre(0);
//	std::cout<<"ISPIS : "<<b<<" ";
	std::vector<int>opaki;
	for(int i=0;i<v.size();i++){
		broj=v[i];
		
		if(opaki_cifre(broj)==true) opaki.push_back(v[i]);
	}
	opaki=izbaci_iste(opaki);
	return opaki;
    }
    else if(istina==false){
    	int broj;
    	std::vector<int> odvratni;
    	for(int i=0;i<v.size();i++){
    		broj=v[i];
    		if(odvratni_cifre(broj)==true) odvratni.push_back(v[i]);
    	}
    	odvratni=izbaci_iste(odvratni);
    	return odvratni;
    }
}
int main ()
{
	int broj;
	std::vector<int> v;
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	for(;;){
		std::cin>>broj;
		if(broj==0)break;
	    v.push_back(broj);
	}
	std::vector<int> opaki=IzdvojiGadne(v,true);
	std::cout<<"Opaki: ";
	for(int i=0;i<opaki.size();i++){
		std::cout<<opaki[i]<<" ";
	}
	std::cout<<std::endl;
	std::vector<int> odvratni=IzdvojiGadne(v,false);
	std::cout<<"Odvratni: ";
	for(int i=0;i<odvratni.size();i++){
		std::cout<<odvratni[i]<<" ";
	}
	return 0;
}