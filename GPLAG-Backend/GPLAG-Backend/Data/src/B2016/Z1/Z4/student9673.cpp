/*B 2016/2017, Zadaća 1, Zadatak 4 */
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

typedef std::vector<std::string> VektorStringova;

bool Slovo(char znak){
    return ((znak>='a' && znak<='z') || (znak>='A' && znak<='Z'));
}

std::string ObrniFraze(std::string recenica, VektorStringova spisak){
    
    for(int k=0; k<spisak.size(); k++){
        for(int i=0; i<recenica.length(); i++){
            int pocetak(0), kraj(0), j(0), pamti_mjesto(0);
                if(recenica[i]==spisak[k][j]){
                    pocetak=i;
                    pamti_mjesto=i;
                    while(j<spisak[k].length() && i<recenica.length() && recenica[i]==spisak[k][j]){
                        i++;
                        j++;
                    }
                    if(j==spisak[k].length()){
                        kraj=i-1;
                        if(i==recenica.length()){
                            i=recenica.length()-1;
                            kraj=i;
                        }
                        for(int p=pocetak; p<=pocetak+(kraj-pocetak)/2; p++){
                            char pomocna=recenica[p];
                            recenica[p]=recenica[pocetak+kraj-p];
                            recenica[pocetak+kraj-p]=pomocna;
                        } 
                    }
                i=pamti_mjesto;   
                }
        }
    }
    return recenica;
}

std::string IzmijeniUPigLatin(std::string recenica, VektorStringova spisak){
    
    for(int i=0; i<spisak.size(); i++){
        for(int j=0; j<spisak[i].length(); j++){
            if(!Slovo(spisak[i][j]))throw std::domain_error("Nekorektan izbor rijeci");
        }
    }
    
    if(!spisak.size()){ 
        bool TrazimKraj(false);
        int pocetak(0), kraj(0);
        
        for(int i=0; i<recenica.length(); i++){
            if(Slovo(recenica[i]) && (i==0 || !Slovo(recenica[i-1]))){
                pocetak=i;
                TrazimKraj=true;
            }
            if((i==recenica.length()-1 || !Slovo(recenica[i])) && TrazimKraj){
                TrazimKraj=false;
                if(i==recenica.length()-1)kraj=i;
                else kraj=i-1;
                recenica.insert(recenica.begin()+kraj+1, recenica[pocetak]);
                recenica.erase(recenica.begin()+pocetak);
                recenica.insert(recenica.begin()+kraj+1, 'a');
                recenica.insert(recenica.begin()+kraj+2, 'y');
            }
        }
    }
    
    else{
        for(int i=0; i<recenica.length(); i++){
            for(int k=0; k<spisak.size(); k++){
                int pocetak(0), kraj(0);
                    int j(0);
                    if(recenica[i]==spisak[k][j] && (i==0 || !Slovo(recenica[i-1]))){
                        pocetak=i;
                        while(j<spisak[k].length() && i<recenica.length() && recenica[i]==spisak[k][j] && Slovo(recenica[i])){
                            i++;
                            j++;
                        }
                        if(j==spisak[k].length() && !Slovo(recenica[i])){
                            kraj=i-1;
                            if(i==recenica.length()){
                                i=recenica.length()-1;
                                kraj=i;
                            }
                        recenica.insert(recenica.begin()+kraj+1, recenica[pocetak]);
                        recenica.erase(recenica.begin()+pocetak);
                        recenica.insert(recenica.begin()+kraj+1, 'a');
                        recenica.insert(recenica.begin()+kraj+2, 'y');
                        }
                    }
                }
            }
        }
    return recenica;
}

int main ()
{
    VektorStringova spisak;
    std::string ubaci, recenica;
    
    std::cout << "Unesite recenicu: ";
    std::getline(std::cin, recenica);
    std::cout << "Unesite fraze: ";
    while(std::cin.peek()!='\n'){
        std::getline(std::cin, ubaci);
        spisak.push_back(ubaci);
    }
    try{
    std::string pig(IzmijeniUPigLatin(recenica, spisak));
    std::cout << "Recenica nakon PigLatin transformacije: " << pig << std::endl;
    }
    catch(std::domain_error izuzetak){
        std::cout << "Izuzetak: " << izuzetak.what() << std::endl;
    }
    std::string obrnuta(ObrniFraze(recenica, spisak));
    std::cout << "Recenica nakon obrtanja fraza: " << obrnuta << std::endl;
    return 0;
}
