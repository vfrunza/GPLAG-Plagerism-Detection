/*B 2017/2018, Zadaća 2, Zadatak 3

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za
	autotestove javiti se na forum (c2).
*/
#include <iostream>
#include <vector>
#include <stdexcept>
#include <new>
#include <algorithm>
#include <iomanip>
#include <cmath>


bool JesuLiJednaki(double x, double y, double Eps = 1e-10) //funkcija kojom poredimo jednakost dva broja tipa double
{
	return ( std::fabs(x-y) <= Eps*(std::fabs(x)+std::fabs(y)) );
}

template<typename CjelobrojniTip>
int Period(const std::vector<CjelobrojniTip> &v)
{
    int period(0);
    for(int i=1; i<int(v.size()); i++) {
        bool jest_period(1);
        for(int j=0; j<(int(v.size()) - i); j++) {
            if(v.at(j)!=v.at(j+i)) jest_period=false;
        }
        if(jest_period) {
            period = i;
            break;
        }
    }
    return period;
}


void UnistiMatricuF(int **mat, int br_redova)
{
    if(!mat) return;
    for(int i=0; i<br_redova; i++) delete[] mat[i];
    delete[] mat;
}

void UnistiMatricuK(int **mat, int br_redova)
{
    if(!mat) return;
    delete[] mat[0];
    delete[] mat;
}


template<typename CjelobrojniTip>
int **AlocirajFragmentirano(const std::vector<CjelobrojniTip> &v, int &koliko_puta)
{
    int velicina(v.size());
    if (velicina==0) throw ("Prazan vektor!");
    int period(0);
    period = Period(v);
    if(period==0) {
        koliko_puta = 2;
        period = velicina;
    } else {
        koliko_puta = std::count(v.begin(), v.end(), v.at(0));
    }

    int br_elemenata(0);
    for(int i=0; i<velicina; i++) {
        if(v.at(i)<=0) throw std::domain_error("Neispravan vektor!");
        br_elemenata += v.at(i);
    }
    if(period==velicina) { //ako je period jednak velicini tada se svi elementi ponavljaju jos jednom
        for(int i=0; i<velicina; i++) br_elemenata += v.at(i);
    } else {
        int k(0);
        k = (int(v.size()))%period; //broj elemenata koji čine zadnji period u vektoru
        if(k!=0) {
            int i(0);
            while(i<(period-k)) {
                br_elemenata += v.at(i+k);
                i++;
            }
        }
    }
    int m(period*koliko_puta);
    int **mat(new int*[m] {});
    try {
        int i(0);
        for(i=0; i<velicina; i++) {
            mat[i] = new int[v.at(i)];
        }
        if(period==velicina) {
            for(int j=0; j<velicina; j++) {
                mat[i] = new int[v.at(j)];
                i++;
            }
        } else {
            int k(0);
            k = (int(v.size()))%period; //broj elemenata koji čine zadnji period u vektoru
            if(k!=0) {
                int j(0);
                while(j<(period-k)) {
                    mat[i] = new int[v.at(j+k)];
                    i++;
                    j++;
                }
            }
        }
        i = 0;
        auto max(std::max_element(v.begin(), v.end()));
        for(i=0; i<velicina; i++) {
            for(int j=0; j<v.at(i); j++) {
                mat[i][j] = *max -v.at(i) + j + 1;
            }
        }
        if(period==velicina) {
            for(int j=0; j<velicina; j++) {
                for(int k=0; k<v.at(j); k++) {
                    mat[i][k] = *max -v.at(j) + k + 1;
                }
                i++;
            }
        } else {
            int k(0);
            k = (int(v.size()))%period; //broj elemenata koji čine zadnji period u vektoru
            if(k!=0) {
                int j(0);
                while(j<(period-k)) {
                    for(int r=0; r<v.at(j+k); r++) {
                        mat[i][r] = *max -v.at(j+k) + r + 1;
                    }
                    i++;
                    j++;
                }
            }
        }

        return mat;

    } catch(...) {
        UnistiMatricuF(mat, m);
        throw;
    }

}

template<typename CjelobrojniTip>
int ** AlocirajKontinualno(const std::vector<CjelobrojniTip> &v, int &koliko_puta)
{
    int velicina(v.size()); //broj redova
    if (velicina==0) throw ("Prazan vektor!");
    int period(0);
    period = Period(v);
    if(period==0) {
        koliko_puta = 2;
        period = velicina;
    } else {
        koliko_puta = std::count(v.begin(), v.end(), v.at(0));
    }

    int br_elemenata(0);
    for(int i=0; i<velicina; i++) {
        if(v.at(i)<=0) throw std::domain_error("Neispravan vektor!");
        br_elemenata += v.at(i);
    }
    if(period==velicina) { //ako je period jednak velicini tada se svi elementi ponavljaju jos jednom
        for(int i=0; i<velicina; i++) br_elemenata += v.at(i);
    } else {
        int k(0);
        k = (int(v.size()))%period; //broj elemenata koji čine zadnji period u vektoru
        if(k!=0) {
            int i(0);
            while(i<(period-k)) {
                br_elemenata += v.at(i+k);
                i++;
            }
        }
    }
    int m(period*koliko_puta);
    int **mat(new int*[m] {});
    try {
        mat[0] = new int[br_elemenata];
        int temp(v.at(0));
        int i(1);
        for(i=1; i<velicina; i++) {
            mat[i] = mat[0] + temp;
            temp += v.at(i);
        }
        if(period==velicina) { //dodatna alokacija ako je period jednak velicini
            for(int j=0; j<velicina; j++) {
                mat[i] = mat[0] + temp;
                temp += v.at(j);
                i++;
            }
        } else { //dodatna alokacija za period razlicit od velicine
            int k(0);
            k = (int(v.size()))%period; //broj elemenata koji čine zadnji period u vektoru
            if(k!=0) {
                int j(0);
                while(j<(period-k)) {
                    mat[i] = mat[0] + temp;
                    temp += v.at(j+k);
                    j++;
                    i++;
                }
            }
        }
        i = 0;
        for(i=0; i<velicina; i++) {
            for(int j=0; j<v.at(i); j++) {
                mat[i][j] = v.at(i) - j;
            }
        }
        if(period==velicina) {
            for(int j=0; j<velicina; j++) {
                for(int k=0; k<v.at(j); k++) {
                    mat[i][k] = v.at(j) - k;
                }
                i++;
            }
        } else {
            int k(0);
            k = (int(v.size()))%period; //broj elemenata koji čine zadnji period u vektoru
            if(k!=0) {
                int j(0);
                while(j<(period-k)) {
                    for(int r=0; r<v.at(j+k); r++) {  //(j+k) je index onog elementa u nizu koji sljedeci dolazi da se popuni period
                        mat[i][r] = v.at(j+k) - r;
                    }
                    j++;
                    i++;
                }
            }
        }

        return mat;

    } catch(...) {
        UnistiMatricuK(mat, m);
        throw;
    }

}



int main ()
{

    std::cout<<"Unesite broj elemenata vektora: ";
    int n;
    
    double vel;
	for(;;) {
		std::cin>>vel;
		if(std::cin) {
			int provjera;
			provjera = vel;
			if(vel<0 || !JesuLiJednaki(provjera, vel)) std::cout<<"Neispravan unos! Unesite ponovo: ";
			else {
			    n = vel;
			    break;
			}
		} else {
			std::cout<<"Neispravan unos! Unesite ponovo: ";
			std::cin.clear();
			std::cin.ignore(10000, '\n');
		}
	}
    
    std::vector<int> v(n);
    std::cout<<"Unesite elemente vektora: ";
    
    for(int i=0; i<n; i++) {
		for(;;) {
			std::cin>>v.at(i);
			if(std::cin) break;
			std::cout<<"Neispravan unos! Unesite ponovo: ";
			std::cin.clear();
			std::cin.ignore(10000, '\n');
		}
	}
    
    std::cout<<"Odaberite alokaciju: 1 - fragmentirana, 0 - kontinualna: ";
    bool t;
    double testni;
	for(;;) {
		std::cin>>testni;
		if(std::cin) {
			if(JesuLiJednaki(testni, 1)) {
				t = true;
				break;
			} else if(JesuLiJednaki(testni,0)) {
				t = false;
				break;
			} else std::cout<<"Neispravan unos! Unesite ponovo: ";
		} else {
			std::cout<<"Neispravan unos! Unesite ponovo: ";
			std::cin.clear();
			std::cin.ignore(10000, '\n');
		}
	}
    
    int koliko_puta(0);
    int **mat1(nullptr);
    int **mat2(nullptr);
    int period(Period(v));
    if(period==0) period = n;
    try {
        if(t) {
            mat1 = AlocirajFragmentirano(v, koliko_puta);
            int i(0);
            std::cout<<"Dinamicki alocirana matrica:\n";
            for(i=0; i<n; i++) {
                for(int j=0; j<v.at(i); j++) {
                    std::cout<<std::left<<std::setw(3)<<mat1[i][j];
                }
                std::cout<<"\n";
            }
            for(int j=i; j<koliko_puta*period; j++) {
                for(int k=0; k<v.at(i-period); k++) {
                    std::cout<<std::left<<std::setw(3)<<mat1[i][k];
                }
                std::cout<<"\n";
                i++;
            }
            UnistiMatricuF(mat1, period*koliko_puta);

        } else {
            mat2 = AlocirajKontinualno(v, koliko_puta);
            int i(0);
            std::cout<<"Dinamicki alocirana matrica:\n";
            for(i=0; i<n; i++) {
                for(int j=0; j<v.at(i); j++) {
                    std::cout<<std::left<<std::setw(3)<<mat2[i][j];
                }
                std::cout<<"\n";
            }
            for(int j=i; j<koliko_puta*period; j++) {
                for(int k=0; k<v.at(i-period); k++) {
                    std::cout<<std::left<<std::setw(3)<<mat2[i][k];
                }
                std::cout<<"\n";
                i++;
            }
            UnistiMatricuK(mat2, period*koliko_puta);
        }

    } catch(const char poruka[]) {
        UnistiMatricuF(mat1, period*koliko_puta);
        UnistiMatricuK(mat2, period*koliko_puta);
        std::cout<<"Izuzetak: "<<poruka<<std::endl;
    } catch(std::domain_error izuzetak1) {
        UnistiMatricuF(mat1, period*koliko_puta);
        UnistiMatricuK(mat2, period*koliko_puta);
        std::cout<<"Izuzetak: "<<izuzetak1.what()<<std::endl;
    } catch(std::bad_alloc) {
        UnistiMatricuF(mat1, period*koliko_puta);
        UnistiMatricuK(mat2, period*koliko_puta);
        std::cout<<"Izuzetak: Greska pri alokaciji.";
    } catch(...) {
        UnistiMatricuF(mat1, period*koliko_puta);
        UnistiMatricuK(mat2, period*koliko_puta);
        std::cout<<"Doslo je do greske.";
    }

    return 0;
}