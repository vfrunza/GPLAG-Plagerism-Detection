#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>

template <typename Tip>
bool TestPerioda (std::vector<Tip> V,int p)
{
    int i;
    if (p<1) return false;
    if (p>=V.size() || V.size()==1) return false;
    for (i=0; i<V.size()-p; i++) {
        if(int(V[i]-V[i+p])!=0)
            return false;
    }
    return true;
}

template <typename Tip>
Tip NajveciElement(std::vector<Tip> vektor)
{
    Tip naj(vektor.at(0));
    for (int i=0; i<vektor.size(); i++) {
        if (vektor.at(i)>naj)
            naj=vektor.at(i);

    }
    return naj;
}

template <typename Tip>
int SumaPerioda(std::vector<Tip> vektor,int p)
{
    int suma(0);
    for (int i=0; i<p; i++) {
        suma+=vektor.at(i);
    }
    return suma;
}

template <typename Tip>
Tip **AlocirajFragmentalno (const std::vector<Tip> &vektor, int &koliko_puta)
{
    if (vektor.size()==0) throw ("Prazan vektor!");
    for (int i=0; i<vektor.size(); i++) {
        if (vektor.at(i)<=0) throw std::domain_error("Neispravan vektor!");
    }
    koliko_puta=1;
    int period(vektor.size());
    bool pronadjen(false);
    for (int i=0; i<vektor.size(); i++) {
        if (TestPerioda(vektor,i)) {
            period=i;
            if (vektor.size()%i==0) {
                int j(0);
                while (vektor.at(j)==vektor.at(j+i)) {
                    j+=i;
                    koliko_puta++;
                    pronadjen=true;
                    if (j+i==vektor.size()) break;
                }
            } else {
                if (vektor.size()%i!=0) {
                    int j(0);
                    while (vektor.at(j)==vektor.at(j+i)) {
                        j+=i;
                        koliko_puta++;
                        pronadjen=true;
                        if (j+i>vektor.size()) break;
                    }
                }
            }
        } else if (i==vektor.size()-1) {
            koliko_puta=2;
            break;
        }
        if (pronadjen) break;
    }
    int naj(NajveciElement(vektor));
    try {
        Tip **dinamicka(new Tip*[koliko_puta*period]);
        try {
            for (int i=0; i<koliko_puta*period; i++) {
                int pom(i);
                while (pom>=period) pom-=period;
                dinamicka[i]=new Tip[*(vektor.begin()+pom)];
                for (int j=0; j<*(vektor.begin()+pom); j++) {
                    dinamicka[i][(*vektor.begin()+pom)-1-j]=naj-j;
                }
            }
            return dinamicka;
        } catch(std::bad_alloc) {
            for (int i=0; i<koliko_puta*period; i++) delete[] dinamicka[i];
            delete[] dinamicka;
            throw;
        }
    } catch (std::bad_alloc) {
        throw;
    }
}

template <typename Tip>
Tip **AlocirajKontinualno (const std::vector<Tip> &vektor, int &koliko_puta)
{
    if (vektor.size()==0) throw ("Prazan vektor!");
    for (int i=0; i<vektor.size(); i++) {
        if (vektor.at(i)<=0) throw std::domain_error("Neispravan vektor!");
    }
    koliko_puta=1;
    int period(vektor.size());
    bool pronadjen(false);
    for (int i=0; i<vektor.size(); i++) {
        if (TestPerioda(vektor,i)) {
            period=i;
            if (vektor.size()%i==0) {
                int j(0);
                while (vektor.at(j)==vektor.at(j+i)) {
                    j+=i;
                    koliko_puta++;
                    pronadjen=true;
                    if (j+i==vektor.size()) break;
                }
            } else {
                if (vektor.size()%i!=0) {
                    int j(0);
                    while (vektor.at(j)==vektor.at(j+i)) {
                        j+=i;
                        koliko_puta++;
                        pronadjen=true;
                        if (j+i>vektor.size()) break;
                    }
                }
            }
        } else if (i==vektor.size()-1) {
            koliko_puta=2;
            break;
        }
        if (pronadjen) break;
    }
    Tip **dinamicka(nullptr);
    int zbir(SumaPerioda(vektor,period));
    try {
        dinamicka=new Tip*[koliko_puta*period];
        *dinamicka=new Tip[zbir*koliko_puta];
        for (int i=0; i<vektor.at(0); i++) dinamicka[0][i]=vektor.at(0)-i;
        for (int i=1; i<koliko_puta*period; i++) {
            int pom(i-1);
            while (pom>=period) pom-=period;
            dinamicka[i]=dinamicka[i-1]+*(vektor.begin()+pom);
            pom++;
            while (pom>=period) pom-=period;
            for (int j=0; j<*(vektor.begin()+pom); j++) {
                dinamicka[i][j]=*(vektor.begin()+pom)-j;
            }
        }
        return dinamicka;
    } catch(std::bad_alloc) {
        delete[] dinamicka;
        throw;
    }
}











int main ()
{
    std::cout<<"Unesite broj elemenata vektora: ";
    int n;
    std::cin>>n;
    std::cout<<"Unesite elemente vektora: ";
    try {
        std::vector<int> vektor;
        while (vektor.size()!=n) {
            int broj;
            std::cin>>broj;
            vektor.push_back(broj);
        }
        std::cout<<"Odaberite alokaciju: 1 - fragmentirana, 0 - kontinualna: ";
        int alokacija,koliko;
        std::cin>>alokacija;
        if (alokacija==1) {
            int** dinamicka(AlocirajFragmentalno(vektor,koliko));
            std::cout<<"Dinamicki alocirana matrica: "<<std::endl;
            int period(vektor.size());
            for (int i=0; i<vektor.size(); i++) {
                if (TestPerioda(vektor,i)) {
                    period=i;
                    break;
                }
            }
            int vel=koliko*period;
            for (int i=0; i<vel; i++) {
                int pom(i);
                while (pom>=period) pom-=period;
                for (int j=0; j<*(vektor.begin()+pom); j++) {
                    std::cout<<std::left<<std::setw(3)<<dinamicka[i][j];
                }
                std::cout<<std::endl;
            }
            for (int i=0; i<vel; i++) delete[] dinamicka[i];
            delete[] dinamicka;
        } else if (alokacija==0) {
            int** dinamicka(AlocirajKontinualno(vektor,koliko));
            std::cout<<"Dinamicki alocirana matrica: "<<std::endl;
            int period(vektor.size());
            for (int i=0; i<vektor.size(); i++) {
                if (TestPerioda(vektor,i)) {
                    period=i;
                    break;
                }
            }
            int vel=koliko*period;
            for (int i=0; i<vel; i++) {
                int pom(i);
                while (pom>=period) pom-=period;
                for (int j=0; j<*(vektor.begin()+pom); j++) {
                    std::cout<<std::left<<std::setw(3)<<dinamicka[i][j];
                }
                std::cout<<std::endl;
            }
            delete[] *dinamicka;
            delete[] dinamicka;
        }
    } catch (std::domain_error d) {
        std::cout<<"Izuzetak: "<<d.what();
    } catch(std::bad_alloc) {
    } catch (const char izuzetak[]) {
        std::cout<<"Izuzetak: "<<izuzetak;
    }
    return 0;
}