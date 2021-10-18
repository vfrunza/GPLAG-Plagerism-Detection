/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <stdexcept>
#include <map>

typedef std::map<std::string, std::set<int>> mapetinaStringaiSkupa;

std::vector<std::string> VektorStringova( std::string rijeci ) {
    std::vector<std::string> vektor;
    
    for(int i=0; i < rijeci.length(); i++ ) {
        if( (rijeci[i] >= 'a' && rijeci[i] <= 'z') || (rijeci[i] >= '0' && rijeci[i] <= '9') ) {
            std::string rijec;
            
            while( (rijeci[i] >= 'a' && rijeci[i] <= 'z') || (rijeci[i] >= '0' && rijeci[i] <= '9') ) {
                rijec.push_back(rijeci[i]);
                if(i == rijeci.length()-1) break;
                else i++;
            }
            vektor.push_back(rijec);
        }
    }
    
    return vektor;
}


std::vector<std::string> IzostaviDuple( std::string rijeci ) {
    std::vector<std::string> vektor;
    vektor = VektorStringova(rijeci);
    
    std::sort(vektor.begin(),vektor.end());
    auto it = std::unique(vektor.begin(),vektor.end());
    vektor.erase(it,vektor.end());
    
    return vektor;
}

std::map<std::string, std::set<int>> KreirajIndeksPojmova( std::string rijeci ) {
    mapetinaStringaiSkupa mapaPozicija;
    for(char &slovo : rijeci) if( slovo >= 'A' && slovo <= 'Z' ) slovo += 'a' - 'A';
    std::vector<std::string> bezDuplikata = IzostaviDuple(rijeci);
    int j=0;
    
    for(auto i = 0; i < bezDuplikata.size(); i++) {
        for(auto it = 0; it < rijeci.length(); it++) {
            if(bezDuplikata[i][0] == rijeci[it]) {
                int pocetak = it;
                for(j = 0; j < bezDuplikata[i].length(); j++)
                while (bezDuplikata[i][j] == rijeci[it]) it++;
                
                if( ( pocetak == 0 || !( (rijeci[pocetak-1] >= 'a' && rijeci[pocetak-1]<= 'z') || (rijeci[pocetak-1] >= '0' && rijeci[pocetak-1] <= '9') ) ) && ( !( (rijeci[it] >= 'a' && rijeci[it]<= 'z') || (rijeci[it] >= '0' && rijeci[it] <= '9') ) || it == rijeci.length() ) && bezDuplikata[i].length() == it-pocetak ) mapaPozicija[bezDuplikata[i]].insert(pocetak);
            }
        }
    }
    
    return mapaPozicija;
}

std::set<int> PretraziIndeksPojmova(std::string rijec, mapetinaStringaiSkupa indexRijeci) {
    for(char &s : rijec) if( s >= 'A' && s <= 'Z' ) s += 'a' - 'A';
    
    if(!indexRijeci.count(rijec)) throw std::logic_error("Pojam nije nadjen");
    
    return indexRijeci[rijec];
}

void IspisiIndeksPojmova(mapetinaStringaiSkupa mapa) {
    for(auto it = mapa.begin(); it != mapa.end(); it++) {
        std::cout<<it->first<<": ";
        auto &vIt = it->second;
        int vel = std::distance((it->second).begin(), (it->second).end());
        for(int br : vIt) {
            vel--;
            if(vel == 0) std::cout<<br;
            else std::cout<<br<<",";
        }
        std::cout<<std::endl;
    }
}



int main ()
{
    mapetinaStringaiSkupa mapa;
    std::string s,r;
    
        std::cout<<"Unesite tekst: ";
        std::getline(std::cin, s);
       // s = "tp je najbolji predmet u ii semestru prve godine etfa da da tp cijelog etfa";
        mapa = KreirajIndeksPojmova(s);
        
       IspisiIndeksPojmova(mapa);
        
        do{
            std::cout<<"Unesite rijec: ";
            std::getline(std::cin, r);
            if( r == "." ) break;
            std::set<int> skup;
            try{
             skup = PretraziIndeksPojmova(r,mapa);
            } catch(std::logic_error) {
            std::cout << "Unesena rijec nije nadjena!" << std::endl;
            }
            
            for(int br : skup) std::cout<<br<<" ";
            std::cout<<std::endl;
            
        }while (r != ".");
            
        
        
        
    
    
	return 0;
}