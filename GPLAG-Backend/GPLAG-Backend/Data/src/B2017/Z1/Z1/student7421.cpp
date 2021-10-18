/*B 2017/2018, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.	
*/
#include <iostream>
#include <vector>

bool DaLiJeProstBroj(int broj){
	long long int n(broj);
	if(n<0)n*=-1; // da ne gleda minus, mozda bdue greska za ono minimalni onaj broj integera; // mozda long long int stavit n da je.. stavio linija iznad
	if(n==1 || n==0 || n==-1)return false;
	for(int i=2; i*i<=n; i++){
		if(n%i==0)return false;
	}	
	return true;
}

std::vector<int> PretvoriUTernarni (int broj){
	std::vector<int> pretvoren_broj; // cifra po cifra;
	long long int n(broj);
	if(n<0)n*=-1;//isto ko linija 17
	
	int brojac(0);
	for(int i=1; i<n/3; i*=3)brojac++;  // i<n/3 a bilo i*3<n
	
	for(int stepen=brojac; stepen>=0; stepen--){
		long long int umnozak(1), cifra(0); // umnozak je 3 na stepen, a cifra je kolko moze puta stati umnozak u broj n;
		for(int j=0; j<stepen; j++){
			umnozak*=3;
		}
		long long int pomocna=umnozak;
		while(umnozak<=n){
			cifra++;
			umnozak+=pomocna;
		}
		umnozak-=pomocna;
		pretvoren_broj.push_back(cifra);
		n-=umnozak;
	}
	return pretvoren_broj;
}

bool DaLiJeSimetrican (std::vector<int> cifre){
	int j(cifre.size()-1);
	for(int i=0; i<cifre.size(); i++){
		if(cifre.at(i)!=cifre.at(j)) return false;
		j--;
	}
	return true;
}

std::vector<int> IzdvojiSimetricneTernarne(std::vector<int> brojevi, bool uslov){ //uslov true = prosti brojevi; uslov false = slozeni brojevi;
	std::vector<int> rjesenje, privremeni;
	for(auto x : brojevi){ // smjesta proste/slozene brojeve u rjesenje
		if(uslov && DaLiJeProstBroj(x))privremeni.push_back(x);
		else if(!uslov && !DaLiJeProstBroj(x))privremeni.push_back(x);
	}
	for(int i=0; i<privremeni.size(); i++){
		if(DaLiJeSimetrican(PretvoriUTernarni(privremeni.at(i)))){
			
			bool ind_za_duplikate(true);
			for(int z=0; z<rjesenje.size(); z++){
				if(privremeni.at(i)==rjesenje.at(z))ind_za_duplikate=false;
			}
			
			if(ind_za_duplikate)rjesenje.push_back(privremeni.at(i));
			
		}
	}
	return rjesenje; 
}

int main ()
{
	std::vector<int> brojevi;
	std::cout << "Unesite elemente vektora (-1 za kraj): ";
	while(1){
		int broj;
		std::cin >> broj;
		if(broj==-1)break;
		brojevi.push_back(broj);
	}
	int uslov;
	std::cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	for(;;){
		std::cin >> uslov;
		if (uslov==1 || uslov==0)break;
		std::cout << "Neispravan unos! Unesite ponovo: ";
    }
	std::vector<int> rjesenje(IzdvojiSimetricneTernarne(brojevi, uslov));
	if(rjesenje.size()!=0){
		if(uslov) std::cout << "Prosti simetricni brojevi iz vektora su:";
		else std::cout << "Slozeni simetricni brojevi iz vektora su:";
		for(int i=0; i<rjesenje.size(); i++){
			std::cout << " " << rjesenje.at(i);
			if(i!=rjesenje.size()-1)std::cout << ",";
			else std::cout << ".";
		}
	}
	else if(uslov)std::cout << "Nema prostih simetricnih brojeva u vektoru.";
	else std::cout << "Nema slozenih simetricnih brojeva u vektoru.";
	return 0;
}