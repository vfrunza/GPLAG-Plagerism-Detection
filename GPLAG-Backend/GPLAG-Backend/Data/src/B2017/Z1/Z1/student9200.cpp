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
#include <cmath>


bool DaLiJeProst (int n){
	bool prost{true};
	if (n<0) n*=-1;
	if (n==0){
	    prost=false;
	    return prost;
	}
	for (int i=2;i<=sqrt(n);i++){
	if (n<0) {prost=false;
			break;
			} else
			if (n==1 || n==0 ) {prost=false;                                           
				break;
			} else


			if (n==3 || n==2) {prost=true;
				break;
			}else if (n%i==0) prost=false;
			if(i==n) break;
		}
	
	return prost;
}

std::vector<int> IzdvojiSimetricneTernarne(std::vector<int> v1,bool a){
    std::vector<int> v_prostih;
    std::vector<int> v_slozenih;
    
    for (auto b:v1){
        std::vector<int> ternarni_vektor;
        std::vector<int> rev_ternarni;
        bool simetrican_je(false);
        bool prost(false);
        simetrican_je=false;
        prost=false;
        int tmp=b;
        if (tmp<0) tmp*=-1;
        if (tmp==1) continue;
        do {
            
            int ostatak=tmp%3;
            tmp=tmp/3;
            ternarni_vektor.push_back(ostatak);
        }while(tmp!=0);
            rev_ternarni=ternarni_vektor;
            for (int k=0;k<rev_ternarni.size()/2;k++)
            std::swap(rev_ternarni.at(k),rev_ternarni.at(rev_ternarni.size()-k-1));
            if (rev_ternarni==ternarni_vektor)  simetrican_je=true;
            prost=DaLiJeProst(b);
            if (simetrican_je && prost){
                v_prostih.push_back(b);
            }
            if (simetrican_je && !prost )
                v_slozenih.push_back(b);
    }
    if (a) return v_prostih;
    else return v_slozenih;
}

int main()
{
       int unos;
    std::cout << "Unesite elemente vektora (-1 za kraj): ";
    std::vector<int> v;
    do{
      std::cin >> unos;
      if(unos==-1) continue;
      v.push_back(unos);
    }while(unos!=-1);
    std::cout <<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
    int zahtjev;
    do {
    std::cin >> zahtjev;
    if (zahtjev!=0 && zahtjev!=1) std::cout <<"Neispravan unos! Unesite ponovo: ";
    }while(zahtjev!=0 && zahtjev!=1);
    std::vector <int> v1;
    v1=IzdvojiSimetricneTernarne(v,zahtjev);
    if (zahtjev) {
        if (v1.size()==0) std::cout <<"Nema prostih simetricnih brojeva u vektoru.";
        else{
        std::cout<<"Prosti simetricni brojevi iz vektora su: ";
        for (int i=0;i<v1.size()-1;i++)
        std::cout << v1.at(i) << ", ";
        std::cout << v1.at(v1.size()-1)<<".";
        }
    }else {
        if (v1.size()==0) std::cout <<"Nema slozenih simetricnih brojeva u vektoru.";
        else{
        std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
        for (int i=0;i<v1.size()-1;i++)
        std::cout << v1.at(i) << ", ";
        std::cout << v1.at(v1.size()-1)<<".";
        }
    }                                                        
}
