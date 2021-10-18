#include <iostream>
#include <vector>
#include <cmath>


//Funkcija za konverziju broja iz dekadnog u ternarni brojni sistem
std::vector<int> PretvoriUTernarni (int n) {
    std::vector<int>cifre;
    do{
        cifre.push_back(std::abs(n%3));
        n/=3;
    }while(n!=0);
    return cifre;
}

//Funkcija kojom ispitujemo da li je broj opaki
bool DaLiJeOpaki (std::vector<int> cifre) {
    bool opaki(false);
    int broj0(0);
    int broj1(0);
    int broj2(0);
    for(int i=0; i<cifre.size(); i++) {
        if(cifre[i]==0) broj0++;
        if(cifre[i]==1) broj1++;
        if(cifre[i]==2) broj2++;
    }
    if(broj0%2==0 && broj1%2==0 &&broj2%2==0)
        opaki = true;
    return opaki;
}

//Funkcija kojom ispitujemo da li je broj odvratni
bool DaLiJeOdvratni (std::vector<int> cifre) {
    bool odvratni(false);
    int broj0(0);
    int broj1(0);
    int broj2(0);
    for(int i=0;i<cifre.size();i++) {
        if(cifre[i]==0) broj0++;
        if(cifre[i]==1) broj1++;
        if(cifre[i]==2) broj2++;
    }
    std::vector<int>pomocni;
    if(broj0>0) pomocni.push_back(broj0);
    if(broj1>0) pomocni.push_back(broj1);
    if(broj2>0) pomocni.push_back(broj2);
    bool neparan(true);
    for(int i=0;i<pomocni.size(); i++) {
        if(pomocni[i]%2==0) {
            neparan = false;
            break;
        }
    }
    if(neparan) odvratni = true;
    return odvratni;
}

//Funkcija kojom obezbjedjujemo da ne dodje do ponavljanja istih elemenata vektora
std::vector<int> ObrisiDuple(std::vector<int> v) {
    std::vector<int> v2;
    for(auto x : v) {
        bool j= true;
        for(auto y : v2) if(x==y) j = false;
        if(j) v2.push_back(x);
    }
    return v2;
}

std::vector<int> IzdvojiGadne (std::vector<int> v, bool opaki) {
    std::vector<int> a;
    if(opaki) {
        for(int i=0; i<v.size(); i++) {
            long int clan = static_cast<long int>(v[i]);
            if(clan<0) {
                if(DaLiJeOpaki(PretvoriUTernarni(std::abs(clan))))
                    a.push_back(clan);
            }
            else {
                if(DaLiJeOpaki(PretvoriUTernarni(v[i])))
                    a.push_back(clan);
            }
        }
    }
    else {
        for(int i=0; i<v.size(); i++) {
            long int clan  = static_cast<long int>(v[i]);
            if(clan<0) {
                if(DaLiJeOdvratni(PretvoriUTernarni(std::abs(clan))))
                    a.push_back(clan);
            }
            else {
                if(DaLiJeOdvratni(PretvoriUTernarni(clan)))
                    a.push_back(clan);
            }
        }
    }
    a = ObrisiDuple(a);
    return a;
}


int main () {
	
    std::vector<int> v;
    int n;
    //Unosimo elemente vektora, sve dok ne unesemo 0
    std::cout << "Unesite brojeve (0 za prekid unosa): ";
    for(;;){
        std::cin >> n;
        if(n==0) break;
        v.push_back(n);
    }
    
    std::vector<int> a = IzdvojiGadne(v,1);
	//Ispisujemo opake brojeve
    std::cout << "Opaki: ";
	for(auto x : a) {
	        std::cout << x << " ";
	}
	
	std::cout << std::endl;
	
	std::vector<int> b = IzdvojiGadne(v,0);
	//Ispisujemo odvratne brojeve
	std::cout << "Odvratni: ";
	for(auto x : b) {
	        std::cout << x << " ";
	}
	
	return 0;
}
	