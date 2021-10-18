#include <iostream>
#include <stdexcept>
#include <deque>
#include <vector>
#include <type_traits>
#include <iomanip>

enum class SmjerKretanja {NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo};  
template<typename tip>
   void DaLiJeGrbava(tip kocka){
     for(int i=0; i<kocka.size(); i++){
         for(int j=0; j<kocka.at(i).size();j++){
             if(kocka.at(0).at(0).size()!=kocka.at(i).at(j).size())
                throw std::domain_error("Redovi nemaju isti broj elemenata"); 
         }
     }
     for(int k=0; k<kocka.size();k++)
        if(kocka.at(0).size()!=kocka.at(k).size())
            throw std::domain_error("Plohe nemaju isti broj redova");
 }
template<typename tip>
    int KojiVelicina(tip kocka, SmjerKretanja smijer){
        if(smijer==SmjerKretanja::NaprijedNazad || smijer==SmjerKretanja::NazadNaprijed){
            if(kocka.at(0).at(0).size()<=kocka.at(0).size())
                return kocka.at(0).at(0).size();
            else 
                return kocka.at(0).size();
        }
 
        else if(smijer==SmjerKretanja::LijevoDesno || smijer==SmjerKretanja::DesnoLijevo){
            if(kocka.at(0).size()>kocka.size())
                return kocka.size();
            else 
                return kocka.at(0).size();
            
        } 
        else if(smijer==SmjerKretanja::GoreDolje || smijer==SmjerKretanja::DoljeGore){
            if(kocka.at(0).at(0).size()>=kocka.size())
                return kocka.size();
            else
                return kocka.at(0).at(0).size();
        }    
        return -1;
    }
template <typename tip>
    auto IzdvojiDijagonale3D(tip kocka, SmjerKretanja smijer)->typename std::remove_reference<decltype( kocka.at(0) )>::type{
        
        try {
            DaLiJeGrbava(kocka);
        }
        catch (...) {
            throw ;
        }
        typename std::remove_reference<decltype(kocka.at(0))>::type dijagonale{};
        if(kocka.size()==0 || kocka.at(0).size()==0 || kocka.at(0).at(0).size()==0)
            return dijagonale;
        
        int n=KojiVelicina(kocka, smijer);
        
        if(smijer==SmjerKretanja::NazadNaprijed){
            dijagonale.resize(kocka.size());
            for(int i=kocka.size()-1; i>=0; i--){
                for(int j=0; j<n;  j++){
                    dijagonale.at(kocka.size()-1-i).push_back(kocka.at(i).at(j).at(kocka.at(0).at(0).size()-1-j));
                }
            }
        } 
        else if(smijer==SmjerKretanja::NaprijedNazad){
            for(int i=0; i<kocka.size(); i++){
                dijagonale.push_back(typename std::remove_reference<decltype(kocka.at(0).at(0))>::type{});
                for(int j=0; j<n;  j++){
                    dijagonale.at(i).push_back(kocka.at(i).at(j).at(j));
                }
            }
        } 
        else if(smijer==SmjerKretanja::LijevoDesno){
            for(int i=0; i<kocka.at(0).at(0).size(); i++){
                dijagonale.push_back(typename std::remove_reference<decltype(kocka.at(0).at(0))>::type{});
                for(int j=0; j<n;  j++){
                    dijagonale.at(i).push_back(kocka.at(kocka.size()-1-j).at(j).at(i));
                }
            }
        }
        else if(smijer==SmjerKretanja::DesnoLijevo){
            dijagonale.resize(kocka.at(0).at(0).size());
            for(int i=kocka.at(0).at(0).size()-1; i>=0; i--){
                for(int j=0; j<n;  j++){
                    dijagonale.at(kocka.at(0).at(0).size()-1-i).push_back(kocka.at(j).at(j).at(i));
                }
            }
        } 
        
        else if(smijer==SmjerKretanja::GoreDolje){
            for(int i=0; i<kocka.at(0).size(); i++){
                dijagonale.push_back(typename std::remove_reference<decltype(kocka.at(0).at(0))>::type{});
                for(int j=0; j<n;  j++){
                    dijagonale.at(i).push_back(kocka.at(kocka.size()-1-j).at(i).at(j));
                }
            }  
        } 
        else if(smijer==SmjerKretanja::DoljeGore){
            dijagonale.resize(kocka.at(0).size());
            for(int i=kocka.at(0).size()-1; i>=0; i--){
                for(int j=0; j<n;  j++){
                    dijagonale.at(kocka.at(0).size()-1-i).push_back(kocka.at(kocka.size()-1-j).at(i).at(kocka.at(0).at(0).size()-j-1));
                }
            }
        }
        return dijagonale;
    }
int main (){
     int x,y,z;
     std::cout << "Unesite dimenzije (x y z): ";
     std::cin >> x;
     std::cin >> y;
     std::cin >> z;
     if(x<0 || y<0 || z<0){
         std::cout << "Neispravne dimenzije kontejnera!";
         return 0;
     }
     std::deque<std::deque<std::vector<int>>> matrica(x, std::deque<std::vector<int>>(y,std::vector<int>(z)));
     std::cout <<"Unesite elemente kontejnera: " << std::endl;
     for(int i=0; i<x; i++){
        for(int j=0; j<y; j++){
            for(int k=0; k<z; k++){
                std::cin >> matrica.at(i).at(j).at(k);    
            }   
         }   
     }
     int n;
     std::cout << "Unesite smjer kretanja [0 - 5]: "; 
     std::cin >> n;
     if(n<0 || n>5){
         std::cout << "Smjer kretanja nije ispravan!\n";
         return 0;
     }
     std::vector<SmjerKretanja> niz={SmjerKretanja::NaprijedNazad, SmjerKretanja::NazadNaprijed, SmjerKretanja::GoreDolje, SmjerKretanja::DoljeGore, SmjerKretanja::LijevoDesno, SmjerKretanja::DesnoLijevo};
     std::vector<std::string> nizs={"NaprijedNazad", "NazadNaprijed", "GoreDolje", "DoljeGore", "LijevoDesno", "DesnoLijevo"};
     try {
         auto izlaz=IzdvojiDijagonale3D(matrica,niz.at(n));
         std::cout << nizs.at(n) <<":"<< std::endl;
         for(int i=0; i<izlaz.size();i++){
            for(int j=0; j<izlaz.at(i).size();j++){
                std::cout.width (4);
                std::cout << izlaz.at(i).at(j); 
            }
            std::cout  << std::endl;
         }
     }
     catch (std::domain_error error) {
         std::cout <<"Izuzetak: "<< error.what() << std::endl;
     }
	return 0;
}