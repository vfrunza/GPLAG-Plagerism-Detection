//OVO JE RJESENJE REDOVNOG ISPITNOG ROKA IZ 2017.GODINE
//PRVI ZADATAK:
/*#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

int main ()
{
    std::vector<std::list<int>>v{{1,2,3}, {1,1,1}, {0,0,0}, {5,4,6}};

    std::sort(v.begin(), v.end(), [](std::list<int>l1, std::list<int>l2) {
        int suma1(0), suma2(0);
        for(int x : l1)
            suma1 += x;

        for(int x : l2)
            suma2 += x;

        return suma1 < suma2;
    });

    for(int i = 0; i < v.size(); i++) {
        for(int x : v[i]) std::cout<<x<<" ";
        std::cout<<std::endl;
    }

    return 0;
}*/
//DRUGI ZADATAK:
/*#include <iostream>
#include <vector>
#include <math.h>
#include <stdexcept>

bool DaLiJeKub(int n)
{
    if (n == 0) return 1;
    for(int i = 1; i <= sqrt(n); i++) {
        if(n == i * i * i) return 1;
    }
    return 0;
}

std::vector<bool> Kub(std::vector<int>v)
{
    std::vector<bool>rez;
    for(int i = 0; i < v.size(); i++) {
        if(v.at(i) < 0) throw std::domain_error("Broj ne smije biti negativan!");
        rez.push_back(DaLiJeKub(v.at(i)));
    }
    return rez;
}

int main()
{
    try{
    std::vector<int>v {2, 3, 8, 27, 1, 0};
    std::vector<bool>vek = Kub(v);
    for(int i = 0; i < vek.size(); i++)
    std::cout<<vek.at(i)<<" ";
    }catch(std::domain_error e){
        std::cout<<e.what();
    }

    return 0;
}*/
//TRECI ZADATAK:
/*#include <iostream>
#include <vector>
#include <deque>

template <typename it1, typename it2, typename F>

auto PopuniPoKriteriju(it1 p1, it1 p2, it2 p3, it2 p4, F fun) -> decltype(*p1 + *p1)
{
    typedef typename std::remove_reference<decltype(*p1)>::type tipElementa;

    tipElementa suma{};
    while(p1 != p2) {
        *p3 = fun(*p1);
        suma += *p1;
        p3++;
        p1++;
    }
    p4 = p3;
    return suma;
}

int main()
{
    std::cout<<"Koliko zelite elemenata?"<<std::endl;
    int n;
    std::cin>>n;
    std::vector<int>v;
    std::cout<<"Unesite elemente: ";
    for(int i = 0; i < n; i++) {
        int broj;
        std::cin>>broj;
        v.push_back(broj);
    }
    std::deque<int>d(n);
    PopuniPoKriteriju(v.begin(), v.end(), d.begin(), d.end(), [](int x) {
        return x * x;
    });
    for(int i = 0; i < n; i++)
        std::cout<<d.at(i)<<" ";
    return 0;
}*/
//CETVRTI ZADATAK:
/*#include <iostream>
#include <string>
#include <stdexcept>

void DodajStudenta(std::string **p, int vel, std::string ime)
{
    for(int i = 0; i < vel; i++) {
        if(p[i] == nullptr) {
            try {
                p[i] = new std::string(ime);
                return;
            } catch(...) {
                throw std::logic_error("Nedovoljno memorije");
            }
        }
    }
    std::string**novi = nullptr;
     try {
         novi = new std::string*[vel + 10]{};
         for(int i = 0; i < vel; i++) {
             novi[i] = p[i];
         }
         try {
             novi[vel] = new std::string(ime);
             delete [] p;
             p = novi;
         } catch(...) {
             delete [] p;
             throw std::logic_error("Nedovoljno memorije");
         }
     } catch(...) {
         throw std::logic_error("Nedovoljno memorije");
     }
}
int main()
{
    std::string **p = nullptr;
    int vel(2);
    try {
        p = new std::string*[vel] {};
        p[0] = new std::string("Dzana");
        p[1] = new std::string("Amna");
        try {
            DodajStudenta(p, vel, "Hana");
            vel += 10;
            std::cout<<"Slijedi ispis studenata ukljucujuci novog studenta: "<<std::endl;
        } catch(...) {
            std::cout<<"Nazalost desila se greska pri dodavanju novog studenta!"<<std::endl<<"Slijedi ispis studenata bez novog"<<std::endl;
        }
        for(int i = 0; i < vel; i++) {
            if(p[i] = nullptr) {
                std::cout<<"Null pok"<<std::endl;
            } else {
                std::cout<<*p[i]<<std::endl;
            }
        }
        for(int i = 0; i < vel; i++) {
            delete p[i];
            delete [] p;
        }} catch(...) {
            if( p != nullptr)
                for(int i = 0; i < vel; i++) delete p[i];
            delete [] p;
            std::cout<<"Greska pri alokaciji";
        }

    return 0;
}*/
//PETI ZADATAK:
/*#include <iostream>
#include <string>
#include <cctype>
#include <vector>

bool DaLiJeCifra(char c)
{
    return c >= '0' && c <= '9';

}
bool DaLiJeSlovo(char c)
{
    c = toupper(c);
    return c >= 'A' && c <= 'Z';
}
bool DaLiJeInterpunkcijskiZnak(char c)
{
    return (!DaLiJeSlovo(c) && !DaLiJeCifra(c));
}

std::vector<int>IzdvojiBrojeve(std::string s)
{
    std::vector<int> v;

    for(int i = 0; i < s.length(); i++) {
        if(DaLiJeCifra(s[i])) {
            if(i == 0 || s[i - 1] == ' ') {
                int broj = 0;
                while(i < s.length() && DaLiJeCifra(s[i])) {
                    broj = broj * 10 + s[i] - '0';
                    i++;
                }
                if(i == s.length() || DaLiJeInterpunkcijskiZnak(s[i])) {
                    v.push_back(broj);
                }
            }
        }
    }
    return v;
}
int main()
{
    std::string s("120 studenata od kojih samo 3 voliBheh ali 50 ih je polozilo poy!");
    std::vector<int>vek (IzdvojiBrojeve(s));

    for(int i = 0 ; i < vek.size(); i++) {
        std::cout<<vek.at(i)<<" ";
    }
    return 0;
}*/
//SESTI ZADATAK:
/*#include <iostream>
#include <vector>
#include <deque>
#include <stdexcept>

std::deque<double> Transformiraj(std::vector<std::vector<double>>&mat)
{
    if(mat.size() == 0) throw std::domain_error("Parametar nema formu matrice!");
    for(int i = 0; i < mat.size(); i++) {
        if(mat[i].size() != mat[0].size()) throw std::domain_error("Parametar nema formu matrice!");
    }

    std::deque<double>d (mat[0].size(), 0);

    for(int i = 0; i < mat.size(); i++){
        int velicinaReda = mat[i].size();
        for(int j = 0; j < mat[i].size()/2; j++){
            auto tmp = mat[i][j];
            mat[i][j] = mat[i][velicinaReda - 1 - j];
            mat[i][velicinaReda - 1 - j] = tmp;
        }
        for(j = 0; j < mat[i].size(); j++){
            d[j] += mat[i][j];
        }
    }
    return d;

}*/
//SEDMI ZADATAK:
/*#include <iostream>
#include <vector>
#include <stdexcept>

int DajBrojCifara(int broj){
    int broj_cifara = 0;
    if(broj == 0) return 1;
    while (broj != 0){
        broj_cifara++;
        broj /= 10;
    }
    return broj_cifara;
}


std::vector<int> Zdatak7(std::vector<long long int>v){
    std::vector<int> vek;
    for(int i = 0; i < v.size(); i++){
        if(v.at(i) < 0) throw std::domain_error("Broj ne smije biti negativan!");
        vek.push_back(DajBrojCifara(v.at(i)));
    }
    return vek;
}

int main()
{
    try{
        std::vector<long long int>proba{1, 10, 0, 100, 999, 1000, 12345, 444444, 1, 2};
        std::vector<int>rez(Zdatak7(proba));
        for(int x : rez) std::cout<<x<<" ";
    }
    catch(std::domain_error e){
        std::cout<<e.what();
    }
    return 0;
}*/
//OSMI ZADATAK:
/*#include <iostream>
#include <list>
#include <deque>
#include <algorithm>


int main()
{
    std::deque<std::list<int>>d{{1,2,3}, {2,4,5}, {2,4,5,6,7,8}, {2,4,5,67}};

    std::sort(d.begin(), d.end(), [](std::list<int> l1, std::list<int> l2) {
        int brojac_parnih1(0), brojac_parnih2(0);

        for(int x : l1)
            if(x % 2 == 0) brojac_parnih1++;

        for(int x : l2)
            if(x % 2 == 0) brojac_parnih2++;

        return brojac_parnih1 < brojac_parnih2;
    });

    for(int i = 0; i < d.size(); i++) {
        for(int x : d.at(i)) std::cout<<x<<" ";
        std::cout<<std::endl;
    }
    return 0;
}*/
//DEVETI ZADATAK:
/*#include <iostream>
#include <string>
#include <stdexcept>
#include <string.h>

std::string **smanji(std::string **p, int vel, int nova_vel)
{
    std::string **pok = nullptr;
    pok = new std::string*[nova_vel]{};
    int brojac = 0;
    for(int i = 0; i < vel; i++) {
        if( p[i] != nullptr) {
            pok[brojac] = p[i];
            brojac++;
        }
    }
    delete [] p;
    return pok;
}


void ObrisiStudenta(std::string **p, int vel, std::string ime)
{
    bool postoji(0);
    for(int i = 0; i < vel; i++) {
        if(p[i] != nullptr && ime == *(p[i])) {
            postoji = 1;
            delete p[i];
            p[i] = nullptr;
        }
        if(postoji == 0) throw std::logic_error("Student nije evidentiran");

        int brojacNullPokazivaca(0);
        for(int i = 0; i < vel; i++) {
            if(p[i] == nullptr) brojacNullPokazivaca++;
        }
        if(brojacNullPokazivaca > vel/4) {
            try {
                p = smanji(p, vel, vel - brojacNullPokazivaca);
            } catch(...) {

            }
        }
    }
}*/


int main()
{
    return 0;
}
