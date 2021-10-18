#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <tuple>
#include <stdexcept>
#include <set>


typedef std::map<std::string, std::vector<std::string>> Knjiga;

std::map<std::string, std::set<std::tuple<std::string, int, int>>> KreirajIndeksPonmova (Knjiga &knjiga){
    std::map<std::string, std::set<std::tuple<std::string, int, int> Zavrsna;
    
    for(auto it = knjiga.begin(); it != knjiga.end(); i++){
        auto pocetak_vektora = std::begin(it -> second);
        auto kraj_vektora = std::end (it -> end);
        
        for(auto i = pocetak_vektora; i != kraj_vektora; i++){
            int j = 0;
            while(i[j] == ' ')j++;
            int k = j;
            while(i[j] != ' ')j++;
            std::string pomocni = std::substr(k, j-k);
            std::vector<string> rijeci;
            bool postoji = true;
            for(int i = 0; i < rijeci.size();i++){
                if(pomocni == rijeci[i]){
                    postoji = true;
                    break;
                }
            }
            if(postoji == false){
                Zavrsna.insert({pomocni, {}})
                for(auto it2 = knjiga.begin(); it2 != knjiga.end();it2++){
                    for(auto i = pocetak_vektora; i != kraj_vektora; i++){
                        int j = 0;
                        while(i[j] == ' ')j++;
                        int k = j;
                        while(i[j] != ' ')j++;
                        std::string pomocni2 = std::substr(k, j-k);
                    }
                }
            }
        }
    }
}




int main(){
    
    return 0;
}