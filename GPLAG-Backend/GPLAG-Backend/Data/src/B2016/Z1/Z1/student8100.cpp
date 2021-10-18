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

bool DaLiJeGadan(int a){
	std::vector<int> temp;
	if(a==0) return true;
	while(a!=0){
		temp.push_back(abs(a%3));
		a/=3;
	}
	int brojacnula(0), brojacjedan(0), brojacdva(0);
	for(int i(0); i<int(temp.size()); i++){
		if(temp[i]==0) brojacnula++;
		else if(temp[i]==1) brojacjedan++;
		else brojacdva++;
	}
	if(brojacnula%2==0 && brojacjedan%2==0 && brojacdva%2==0) return true;
	else if((brojacnula%2!=0 || brojacnula==0) && (brojacjedan%2!=0 || brojacjedan==0) && (brojacdva%2!=0 || brojacdva==0)) return true;
	else return false;
}

bool OpakIliOdvratan(int a){
	std::vector<int> temp;
	if(a==0) return false;
	while(a!=0){
		temp.push_back(abs(a%3));
		a/=3;
	}
	int brojacnula(0), brojacjedan(0), brojacdva(0);
	for(int i(0); i<int(temp.size()); i++){
		if(temp[i]==0) brojacnula++;
		else if(temp[i]==1) brojacjedan++;
		else brojacdva++;
	}
	if(abs(brojacnula%2)==0 && abs(brojacjedan%2)==0 && abs(brojacdva%2)==0) return true;
	else return false;
	//if((abs(brojacnula%2)!=0 || brojacnula==0) && (abs(brojacjedan%2)!=0 || brojacjedan==0) && (abs(brojacdva%2)!=0 || brojacdva==0)) return false;
}

std::vector<int> IzdvojiGadne (std::vector<int> niz, bool valja){
	if(niz.empty()) return niz;
	for(int i(0); i<int(niz.size()-1); i++){
		for(int j(i+1); j<int(niz.size()); j++){
			if(niz[i]==niz[j]){
				niz.erase(niz.begin() + j);
				j--;
			}
		}
	}
	std::vector<int> temp;
	for(int i(0); i<int(niz.size()); i++){
		if(DaLiJeGadan(niz[i])) temp.push_back(niz[i]);
	}
	std::vector<int> niyy;
	if(valja){
		for(int i(0); i<int(temp.size()); i++){
			if(OpakIliOdvratan(temp[i])) niyy.push_back(temp[i]);
		}
		return niyy;
	}
	else{
		for(int i(0); i<int(temp.size()); i++){
			if(!OpakIliOdvratan(temp[i])) niyy.push_back(temp[i]);
		}
		return niyy;
	}
}

int main ()
{
	std::vector<int> niz;
	int broj;
	std::cout << "Unesite brojeve (0 za prekid unosa): ";
	do{
		std::cin >> broj;
		if(broj!=0) niz.push_back(broj);
	}while(broj!=0);
	std::vector<int> opaki = IzdvojiGadne(niz, true);
	std::vector<int> odvratni = IzdvojiGadne(niz, false);
	std::cout << "Opaki: ";
	//if(!opaki.empty())
		for(int i(0); i<opaki.size(); i++) std::cout << opaki[i] << " ";
	std::cout << std::endl << "Odvratni: ";
	//if(!odvratni.empty())
		for(int i(0); i<odvratni.size(); i++) std::cout << odvratni[i] << " ";
	return 0;
}