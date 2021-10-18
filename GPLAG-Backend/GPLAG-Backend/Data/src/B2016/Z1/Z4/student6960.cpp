#include <iostream>
#include <vector>
#include <string>
#include <cmath>

std::string ObrniString (std::string String) {
    std::string Rezultat;
    for(int i=String.length()-1; i>=0; i--) {
        Rezultat.push_back(String.at(i));
    }
    return Rezultat;
    
}

std::string IzmijeniUPigLatin (std::string Recenica, std::vector <std::string> Spisak) {
    std::string pomocni;
    for(int i=0; i<Spisak.size(); i++) {
        for(int j=0; j<Spisak.at(i).size(); j++) {
            for(int k=0; k<Recenica.size; k++)
            while(Recenica.at(k)==Spisak.at(i).at(j)) pomocni.push_back(Recenica.at(k));
        }
    }
    
    
}
std::vector<std::string> ObrniFraze (std::string Recenica, std::vector <std::string> Spisak) {
    std::string Rezultat;
    //Provjera za bacanje izuzetka: 
   /*for(int i=0; i<Spisak.size(); i++) { //Prolazi kroz elemente vektora, uzima rijec po rijec
        for (char x: Spisak.at(i) ) { //Uzima slovo po slovo jedne rijeci
            if (x=="č")// || x=='ć' || x=='š' || x=='đ' || x=='ž')
            throw std::domain_error("Nekorektan izbor rijeci");
        }}*/
            std::string s;
            std::vector<bool> VektorBool(0);
            int brojac(0);
            
                std::vector<std::string> Recenica_vek ;
                for (int j =0 ; j< Recenica.length();j++)
                {
                  
                    if (!std::isspace(Recenica.at(j))) 
                    s=s+Recenica.at(j);
                    else {
                        Recenica_vek.push_back(s);
                        s="";
                        
                    }
                }
                
                
                for(int i=0; i<Recenica_vek.size(); i++) {
                    for(int j=0; j<Spisak.size(); j++) {
                         if (Recenica_vek.at(i)==Spisak.at(j))
                         Recenica_vek.at(i)=ObrniString(Recenica_vek.at(i));
                        }
                }
                    /*for(int i=0; i<Spisak.size(); i++) {
                        for(int j=0; j<Recenica_vek.size(); j++) {
                            if (Spisak.at(i)==Recenica_vek.at(j)) {
                                VektorBool.at(j)=true;
                            }
                        }
                    }
                    
                    for(int i=0; i<Recenica_vek.size(); i++) {
                        if(VektorBool.at(i)==true) {
                            Recenica_vek.at(i)=ObrniString(Recenica_vek.at(i));
                        }
                    }*/
                    
                    
                //}
                
                /*for(int i=0; i<Recenica_vek.size(); i++) {
                    Rezultat+=Recenica_vek.at(i);
                    if(i!=Recenica_vek.size()-1) Rezultat+=" ";
                }*/
                    
                
            
            
        return Recenica_vek;
    }
    
    


int main () {
    std::cout<<"Unesite recenicu: ";
    std::string UnesenaRecenica;
    std::getline(std::cin, UnesenaRecenica);
    std::cout<<"Unesite fraze: ";
    std::vector <std::string> VektorFraza;
    std::string ZaUnos;
   
    while(std::getline(std::cin, ZaUnos), std::cin.peek()!='\n') { //Provjeriti
        VektorFraza.push_back(ZaUnos); 
        ZaUnos.resize(0);
        std::cin.ignore(1000,'\n');
    }
    
   
    /*try {
        std::cout<<"Recenica nakon PigLatin transformacije: "<<
    } catch (std::domain_error izuzetak) {
        std::cout<<izuzetak.what()<<"\n";
    }*/
    std::cout<<"Recenica nakon obrtanja fraza: ";
    std::vector <std::string> Ispis;
    Ispis=ObrniFraze(UnesenaRecenica, VektorFraza);
    
    for(auto c:Ispis) std::cout<<c<<" ";
    
	return 0;
}