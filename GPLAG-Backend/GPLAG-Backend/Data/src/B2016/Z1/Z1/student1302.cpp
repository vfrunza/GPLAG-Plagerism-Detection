#include <iostream>
#include <vector>
#include <cmath>

std::vector<int> PretvoriBroj (int broj){
	std::vector<int> pretvoren;
	std::vector<int> pretvoren1;
	int cifra;
	do{
		cifra = std::abs(broj);
		if(cifra % 3 == 0) pretvoren.push_back(0);
		else if (cifra % 3 == 1) pretvoren.push_back(1);
		else  pretvoren.push_back(2);
		broj=broj/3;
	}
	while (broj != 0);
	int j = 0;
	pretvoren1.resize(pretvoren.size());
	for(int i = pretvoren.size()-1; i>=0; --i){
		pretvoren1[i]= pretvoren[j++];
		//j++;
	}
	return pretvoren;
}

std::vector<int> Gadni1 (std::vector<int> v) {
	int brojacnula = 0, brojacjedan = 0, brojacdva = 0;
	int broj, brojj;
	bool jeste;
	std::vector<int> pretvorenivektor;
	std::vector<int> vracam;
	for (int i = 0; i<v.size(); ++i){
		jeste = false;
		broj = v[i];
		pretvorenivektor = PretvoriBroj(broj);
		for(int j = 0; j<pretvorenivektor.size(); ++j){
			brojj = pretvorenivektor[j];
			if(brojj == 0) brojacnula++;
			if(brojj == 1) brojacjedan++;
			if(brojj == 2) brojacdva++;
		}
		if( brojacnula%2==0 && brojacdva%2==0 && brojacjedan%2==0) {
			for( int k = 0; k<vracam.size(); k++){
				if(vracam[k]==v[i])
					jeste = true;
			}
			if(jeste == false) vracam.push_back(v[i]);
		}
	
	pretvorenivektor.erase(pretvorenivektor.begin(), pretvorenivektor.end());
	brojacdva = 0; brojacjedan = 0; brojacnula = 0; 
		}
	return vracam;
	
}

std::vector<int> Gadni2 (std::vector<int> v){
	int brojacnula = 0, brojacjedan = 0, brojacdva = 0;
	int broj, brojj;
	bool jeste;
	std::vector<int> pretvorenivektor;
	std::vector<int> vracam;
	for (int i = 0; i<v.size(); ++i){
		jeste = false;
		broj = v[i];
		pretvorenivektor = PretvoriBroj(broj);
		for(int j = 0; j<pretvorenivektor.size(); ++j){
			brojj = pretvorenivektor[j];
			if(brojj == 0) brojacnula++;
			if(brojj == 1) brojacjedan++;
			if(brojj == 2) brojacdva++;
		}
		if( (brojacdva%2!=0 || brojacdva==0) && (brojacjedan%2!=0 || brojacjedan==0) &&( brojacnula%2!=0|| brojacnula==0)) {
			for(int k = 0; k<vracam.size(); ++k){
				if(vracam[k]==v[i])
					jeste = true;
			}
			if(jeste == false) vracam.push_back(v[i]);
		}
	
	pretvorenivektor.erase(pretvorenivektor.begin(), pretvorenivektor.end());
	brojacdva = 0; brojacjedan = 0; brojacnula = 0; }
	return vracam;
}

std::vector<int> IzdvojiGadne (std::vector<int> v, bool logika){
	std::vector<int> vektorGadni1;
	std::vector<int> vektorGadni2;
	vektorGadni1 = Gadni1(v);	vektorGadni2 = Gadni2(v);
	if(logika==true)
		return vektorGadni1;
	else if (logika==false)
		return vektorGadni2;
}


int main (){
	int unos;
	std::vector<int> a;
	std::vector<int> gadni1;
	std::vector<int> gadni2;
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	do{
		std::cin>>unos;
		if(unos==0) goto nastavak;
		else a.push_back(unos);
	}
	while(unos!=0);
	nastavak:
	gadni1 = Gadni1(a); gadni2 = Gadni2(a);
	//a = PretvoriBroj(12);
	//for(int b : a){
	//	std::cout<<b;
	int b = gadni1.size();
	int c = gadni2.size();
	std::cout<<"Opaki: ";
	for(int i = 0; i < b; ++i)
		std::cout<<gadni1[i]<<" ";
	std::cout<<std::endl;
	std::cout<<"Odvratni: ";
	for(int i = 0; i < c; ++i)
		std::cout<<gadni2[i]<<" ";
	return 0;
}