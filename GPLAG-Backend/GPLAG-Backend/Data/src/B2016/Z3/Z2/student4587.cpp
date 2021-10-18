/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include<set>
#include<map>
#include<string>
#include<locale>
#include<algorithm>
#include<stdexcept>
std::map< std::string, std::set<int> >KreirajIndeksPojmova ( std::string S )
{
    std::map< std::string, std::set<int> >mapica;
    for(char &x : S) { // sva slova postavljamo na mala slova;
        x=std::tolower(x);
    }
    auto it (std::begin(S));
    while(it != std::end(S)) {

        while ( (!( ( *it>='a' && *it<='z' ) || ( *it>='0' && *it<='9' )  )) && it!=std::end(S) ) { //preskacemo sve sto ne moze biti rijec
            it++;
        }
        auto pom(it);
        while ( ( ( *it>='a' && *it<='z' ) || ( *it>='0' && *it<='9' )  ) && it!=std::end(S) ) { // brojimo znakoce rijeci
            it++;
        }
        auto pom2=pom-std::begin(S);
        int duzina=it-pom;
        std::string s;
        s=S.substr (pom2,duzina);
        if( mapica.find( s ) ==std::end(mapica) ) { //ako nema ovog para kreiramo ga
            std::set<int> skup;
            skup.insert(pom2);
            mapica[ s ]=skup;
        } else { // ako vec postoji onda u skup dodajemo lokaciju
            auto y (mapica.find( s ));
            ( (*y).second).insert(pom2);
        }
        if(it==std::end(S)) {
            break;
        }
        it++;
    }
    return mapica;
}

std::set<int> PretraziIndeksPojmova (std::string rijec, std::map<std::string, std::set<int>> mapa )
{
    for(char &x : rijec) { // sva slova postavljamo na mala slova;
        x=std::tolower(x);
    }
    auto it (mapa.find(rijec));
    if(it==std::end(mapa)) {
        throw std::logic_error("Pojam nije nadjen");
    }
    return (*it).second;
}

void IspisiIndeksPojmova(std::map<std::string, std::set<int>> MAPA)
{
    for(auto it(std::begin(MAPA)); it!=std::end(MAPA); it++) {
        std::cout << (*it).first <<": " ;
        for( auto j=std::begin( (*it).second ); j!=std::end( (*it).second ); j++ ) {
            if( j==std::max_element(std::begin( (*it).second ), std::end( (*it).second ) ) ) {
                std::cout << *j;
            } else {
                std::cout << *j <<",";
            }
        }
        std::cout  << std::endl;
    }
}

int main ()
{
    std::cout << "Unesite tekst: ";
    std::string tekst;
    std::getline(std::cin,tekst);
    auto mapa=KreirajIndeksPojmova(tekst);
    IspisiIndeksPojmova(mapa);
    for(;;) {
        std::cout << "Unesite rijec: ";
        std::string q;
        std::getline(std::cin,q);
        if(q==".") {
            break;
        }
        try {
            auto skup=PretraziIndeksPojmova(q,mapa);
            for ( auto i(std::begin(skup)); i!= std::end(skup); i++ ) {
                std::cout << *i <<" ";
            }
            std::cout  << std::endl;
        } catch(std::logic_error Izuzetak) {
            std::cout << "Unesena rijec nije nadjena!"<<std::endl;
        }
    }
    return 0;
}


//                           abc               cde    abc     