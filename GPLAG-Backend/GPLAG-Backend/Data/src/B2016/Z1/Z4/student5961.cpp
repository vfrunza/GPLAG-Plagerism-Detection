#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>

std::string ObrniFraze(std::string recenica, std::vector<std::string> fraze){   //Obrce fraze
    for(int i(0); i < fraze.size(); i++){
        for(int j(0); j < recenica.length(); j++){
            if(j <= recenica.length()-fraze[i].length() && recenica.substr(j, fraze[i].length()) == fraze[i]){   //testira da li je to ta fraza
                for(int k(fraze[i].length()-1); k >= 0; k--){
                    recenica[j] = fraze[i][k];
                    j++;
                }
                j--;
            }
        }
    }
    return recenica;
}

bool NeispravneFraze(std::vector<std::string> fraze){   //Testira ispravnost fraza za pigLatin
    for(std::string s : fraze){
        for(char c : s){
            if(c < 'A' || (c > 'Z' && c < 'a') || c > 'z') return true;    //Ako nije slovo onda fraze nisu ispravne za pigLatin
        }
    }
    return false;
}

std::string IzmijeniSve(std::string recenica){   //Ako je vektor s frazama prazan mijenjaju se sve rijeci po pigLatinu
    for(long long i(0); i < recenica.length(); i++){ // ako duzina recenice je veca od int belaj - masha
        if(recenica[i] >= 'A' && recenica[i] <= 'Z' || recenica[i] >= 'a' && recenica[i] <= 'z'){
            long long k(i);
            std::string zamjena;
            while((recenica[k+1] >= 'A' && recenica[k+1] <= 'Z' || recenica[k+1] >= 'a' && recenica[k+1] <= 'z') && k+1 < recenica.length()){ // rijec podrazumjeva bilo koju rijec omedjenu sa 2karaktera ne samo razmak - masha
                zamjena.push_back(recenica[k+1]);
                k++;
            }
            zamjena.push_back(recenica[i]); zamjena.push_back('a'); zamjena.push_back('y');
            recenica = recenica.substr(0, i) + zamjena + recenica.substr(i+zamjena.length()-2, recenica.length()-i-zamjena.length()+2);
            // ako je i negativno kojim slucajem belaj opet -masha
            i+= zamjena.length();
        }
    }
    return recenica;
}

bool vecIzmijenjena(std::vector<std::string> fraze, std::string s){
    for(long long i(0); i < fraze.size(); i++){
        std::string pomocni = fraze[i].substr(1, fraze[i].length()-1) + fraze[i][0] + "ay";
        if(s == pomocni) return true;
    }
    return false;
}

std::string IzmijeniUPigLatin(std::string recenica, std::vector<std::string> rijec){
    if(NeispravneFraze(rijec)) throw std::domain_error("Nekorektan izbor rijeci");
    if (!rijec.size()){
        recenica = IzmijeniSve(recenica);
        return recenica;
    }
    for(long long i(0); i < rijec.size(); i++){
        for(long long j(0); j < recenica.length(); j++){
            if((recenica[j] >= 'A' && recenica[j] <= 'Z' || recenica[j] >= 'a' && recenica[j] <= 'z') && j <= recenica.length()-rijec[i].length() && recenica.substr(j, rijec[i].length()) == rijec[i]){
                if(vecIzmijenjena(rijec, recenica.substr(j, rijec[i].length()))) break;
                std::string zamjena;
                for(long long k(1); k < rijec[i].length(); k++){
                    zamjena.push_back(rijec[i][k]);
                }
                zamjena.push_back(rijec[i][0]); zamjena.push_back('a'); zamjena.push_back('y');
                recenica = recenica.substr(0, j) + zamjena + recenica.substr(j+rijec[i].length(), recenica.length()-(j+rijec[i].length()));
                j += zamjena.length();
            }
        }
    }
    return recenica;
}

int main() {
    std::string recenica;
    std::cout<<"Unesite recenicu: ";
    std::getline(std::cin, recenica);
    std::cout<<"Unesite fraze: ";
    std::vector<std::string> fraze;
    for(;;){
        std::string unos;
        std::getline(std::cin, unos);
        if(!unos.length()) break;
        fraze.push_back(unos);
    }
    try{
        std::string pig_latin = IzmijeniUPigLatin(recenica, fraze);
        std::cout << "Recenica nakon PigLatin transformacije: " << pig_latin;
    }
    catch(std::domain_error izuzetak){
        std::cout << "Izuzetak: " <<  izuzetak.what();
    }
    std::cout << std::endl << "Recenica nakon obrtanja fraza: " << ObrniFraze(recenica, fraze);
}