/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include<list>
#include<vector>
#include<set>
#include<string>
#include<stdexcept>
int duzina_imena(const std::string &S)
{
    auto it(std::begin(S));
    int brojac(0);
    while( it!=std::end(S) ) {
        while ( (!( ( *it>='a' && *it<='z' ) || ( *it>='0' && *it<='9' ) || ( *it>='A' && *it<='Z' )  )) && it!=std::end(S) ) { //preskacemo sve sto ne moze biti rijec
            it++;
        }
        while ( ( ( *it>='a' && *it<='z' ) || ( *it>='0' && *it<='9' ) || ( *it>='A' && *it<='Z' )  ) && it!=std::end(S) ) { //preskacemo sve sto ne moze biti rijec
            it++;
            brojac++;
        }
        if(it==std::end(S)) {
            break;
        }
        it++;
    }
    return brojac;
}

std::vector<std::set<std::string>>Razvrstavanje( const std::vector<std::string>&Imena, int n )
{

    if( n<1 || n>Imena.size() ) {
        throw std::logic_error("Razvrstavanje nemoguce");
    }
    int x(Imena.size()%n), y(Imena.size() / n);
    std::vector<std::set<std::string>>ekipe ;
    std::list<std::string>lista ;
    for(int i=0; i<Imena.size(); i++) {
        lista.push_back(Imena[i]);
    }
    auto it (std::begin(lista));
    std::set<std::string>pom  ;
    for(int i=0; i<n; i++) {
        if(i<x) {
            pom= {};
            for(int j=0; j<y+1; j++) {
                pom.insert(*it);
                int duzina(duzina_imena(*it));
                it=lista.erase(it);
                for(int k=1; k<duzina; k++) {
                    if(it==std::end(lista)) {
                        it=std::begin(lista);
                    }
                    if(it!=std::end(lista)) {
                        it++;
                    }
                    if(it==std::end(lista)) {
                        it=std::begin(lista);
                    }
                }
            }
            ekipe.push_back(pom);
        } else {
            pom= {};
            for(int j=0; j<y; j++) {
                pom.insert(*it);
                int duzina(duzina_imena(*it));
                it=lista.erase(it);
                for(int k=1; k<duzina; k++) {
                    if(it==std::end(lista)) {
                        it=std::begin(lista);
                    }
                    if(it!=std::end(lista)) {
                        it++;
                    }
                    if(it==std::end(lista)) {
                        it=std::begin(lista);
                    }
                }
            }
            ekipe.push_back(pom);
        }

    }
    return ekipe;
}

int main ()
{
    try {
        std::cout << "Unesite broj djece: ";
        int br_djece(0);
        std::cin >> br_djece;
        std::cin.ignore(10000, '\n');
        std::vector<std::string>Imena ;
        std::cout << "Unesite imena djece: ";
        for(int i=0; i<br_djece; i++) {
            std::string pom;
            std::getline(std::cin, pom);
            Imena.push_back(pom);
        }
        std::cout  << std::endl;
        std::cout << "Unesite broj timova: ";
        int n(0);
        std::cin >> n;
        auto ekipe ( Razvrstavanje(Imena,n)  );
        for(int i=0; i<n; i++) {
            std::cout << "Tim " <<i+1<<": ";
            auto it2(std::begin( ekipe[i] ));
            auto q(std::end( ekipe[i] ));
            q--;
            while(it2!=std::end(ekipe[i]) ) {
                if(it2==q) {
                    std::cout << *it2 ;
                } else {
                    std::cout << *it2 <<", ";
                }
                it2++;
            }
            std::cout << std::endl;
        }
    } catch(std::logic_error Izuzetak) {
        std::cout <<"Izuzetak: " <<Izuzetak.what() << std::endl;
    }
    return 0;
}
