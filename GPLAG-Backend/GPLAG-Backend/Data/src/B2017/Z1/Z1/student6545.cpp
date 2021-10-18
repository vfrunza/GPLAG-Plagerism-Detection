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
#include <limits>
#include <math.h>

bool DaLiJeProst(int n)
{	int i;

	if(n == 0)
		return false;
	if (n < 0)
	    n = -n;
	if(n < 2) 
		return 0;
	
	
	for (i = 2; i <= sqrt(n); i++){
		if(n % i == 0)
		return false;
	}
	return true;
}

bool DaLiJeTernarniSimetricni(int t)
{
    std::string s;
    int i, j;
    
    if (t < 0)
        t = -t;
    
    do {
        s.push_back(t % 3 + '0');
        t /= 3;
    } while (t > 0);
        
    i = 0;
    j = s.length() - 1;
    while (i < j) {
        if (s.at(i) != s.at(j))
            return false;
        i++;
        j--;
    }
                
    return true;
}

std::vector<int> IzdvojiSimetricneTernarne(std::vector<int> a, bool b)
{
    std::vector<int> c;
    bool prost, simetrican;
    
    for (int i = 0 ; i < a.size(); i++) {
        prost = DaLiJeProst(a.at(i));
        simetrican = DaLiJeTernarniSimetricni(a.at(i));
        if (simetrican) {
            if (b == true) {
                if (prost)
                    c.push_back(a.at(i));  
            }
            else if (!prost) 
                c.push_back(a.at(i));
        }
    }
    
    return c;
}

int main ()
{
    std::vector<int> a, b;
    int i, broj;
    
    std::cout << "Unesite elemente vektora (-1 za kraj): ";
    while (true) {
        std::cin >> broj;
        if (broj == -1)
            break;
        a.push_back(broj);
    }
    
    std::cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";    
    do {
        std::cin >> broj;
        if (broj == 1) {
            b = IzdvojiSimetricneTernarne(a, true);
            if (b.size() == 0)
                std::cout << "Nema prostih simetricnih brojeva u vektoru.";
            else {
                std::cout << "Prosti simetricni brojevi iz vektora su: ";
                for (int i = 0; i < b.size(); i++) {
                    if (i > 0)
                        std::cout << ", ";
                    std::cout << b.at(i);
                }
                std::cout << ".";
            }
            break;
        }
        else if (broj == 0) {
            b = IzdvojiSimetricneTernarne(a, false);
            if (b.size() == 0)
                std::cout << "Nema slozenih simetricnih brojeva u vektoru.";
            else {
                std::cout << "Slozeni simetricni brojevi iz vektora su: ";
                for (int i = 0; i < b.size(); i++) {
                    if (i > 0)
                        std::cout << ", ";
                    std::cout << b.at(i);
                }
                std::cout << ".";
            }
            break;
        }
        else
            std::cout << "Neispravan unos! Unesite ponovo: ";
    } while (true);
    
    return 0;
}