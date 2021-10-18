// B 16/17, Zadaća 2, Zadatak 2
//	Autotestovi by Enil Pajic (epajic1@etf.unsa.ba | @eon : etf.ba)
//	NAPOMENA: i javni ATo-vi su dio postavke!	
// dodati auto
//dodati tip

#include<iostream>
#include<vector> 
#include<deque>
#include<stdexcept>
#include<type_traits>
#include<iomanip>
#include<new>

enum class SmjerKretanja{ 
    NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
};

void KodIspisa(int n){
    if(n==0)std::cout<<"NaprijedNazad: "<<std::endl;
    else if(n==1)std::cout << "NazadNaprijed: " << std::endl;
    else if(n==2) std::cout << "GoreDolje: " << std::endl;
    else if (n==3)std::cout << "DoljeGore: " << std::endl;
    else if(n==4)std::cout << "LijevoDesno: "  << std::endl;
    else if(n==5)std::cout << "DesnoLijevo: " << std::endl;
}

template<typename kont>
auto IzdvojiDijagonale3D(kont K, SmjerKretanja smjer)->typename std::remove_reference<decltype(K[0])>::type{
    for(unsigned int i(0); i<K.size(); i++){
        for(unsigned int j(0); j<K[0].size();j++){
            if(K[0][0].size() != K[i][j].size()) throw std::domain_error("Redovi nemaju isti broj elemenata");
        }
    }
    for(unsigned int i(0); i<K.size(); i++){
        if(K[0].size()!=K[i].size()) throw std::domain_error("Plohe nemaju isti broj redova");
    }
    typename std::remove_reference<decltype(K[0])>::type dia;
   // std::vector<std::vector<double>> dia;
    if(smjer == SmjerKretanja::NaprijedNazad){
        
                dia.resize(K.size());
                
                for(unsigned int i(0); i<K.size(); i++){
                    for(unsigned int j(0); j<K[0].size()&&j<K[0][0].size();j++){
                        dia[i].push_back(K[i][j][j]);
                    }
                }
               
    }
    if(smjer == SmjerKretanja::NazadNaprijed){
        dia.resize(K.size());
        for(int i(int(K.size())-1), k(0); i>=0&& k<int(dia.size()); i--,k++){
            for(int j(0), z(int(K[0][0].size())-1); j<int(K[0].size()) && z>=0; j++,z--){
                dia[k].push_back(K[i][j][z]);
            }
        }
       
    }
    if(smjer == SmjerKretanja::DesnoLijevo){
        
        dia.resize(K[0][0].size());
        for(int i(0), k(int(K[0][0].size())-1);k>=0 && i<int(dia.size()); i++,k--){
            for(int j(0), z(0); j<int(K.size()) && z<int(K[0].size()); z++,j++){
                dia[i].push_back(K[j][z][k]);
            }
        }
        
    }
    if(smjer == SmjerKretanja::LijevoDesno){
        
        dia.resize(K[0][0].size());
        for(unsigned int i(0); i<K[0][0].size(); i++){
            for(int j(0), z(int(K.size())-1); z>=0 && j<int(K[0].size()); j++, z--){
                dia[i].push_back(K[z][j][i]);
            }
        }
        
    }
    if(smjer == SmjerKretanja::GoreDolje){
       
        dia.resize(K[0].size());
        for(unsigned int i(0); i<K[0].size(); i++){
            for( int j(int(K.size())-1), z(0); j>=0 && z<int(K[0][0].size());z++, j--){
                dia[i].push_back(K[j][i][z]);
            }
        }
       
    }
    if(smjer == SmjerKretanja::DoljeGore){
        
        dia.resize(K[0].size());
        for( int i(int(K[0].size())-1),k(0); i>=0 && k<int(dia.size()); i--, k++){
            for(int j(int(K.size())-1), z(int(K[0][0].size())-1); j>=0 &&z>=0; j--, z--){
                dia[k].push_back(K[j][i][z]);
            }
        }
    }
    /*typename std::remove_reference<decltype(K[0])>::type Kol(dia.size(), typename std::remove_reference<decltype(K[0][0])>::type(dia[0].size()));
    
    for(int i(0); i< int(dia.size());i++){
        for(int j(0); j<int(dia[0].size()); j++){
            Kol[i][j] = dia[i][j];
        }
    }*/
    
    return dia;
}

int main ()
{
    int x,y,z,n(8);
    std::vector<std::deque<std::deque<int> > > K;
    while(1){
    std::cout << "Unesite dimenzije (x y z): ";
    std::cin>>x>>y>>z;
    if(x<0 || y<0 || z<0){
        std::cout << "Neispravne dimenzije kontejnera!" << std::endl;
        return 0;
    }
    std::vector<std::deque<std::deque<int>>> M(x, std::deque<std::deque<int>>(y, std::deque<int>(z)));
    
    std::cout << "Unesite elemente kontejnera: ";
    for(auto &a: M){
        for(auto &b: a){
            for(auto &c : b){
                std::cin>>c;
            }
        }
    }
    
    
    std::cout << "\nUnesite smjer kretanja [0 - 5]: ";
    std::cin>>n;
    if(n>=0&&n<=5){K = std::move(M); break;}
    
    std::cout << "Smjer kretanja nije ispravan!" << std::endl;
    return 0;
    }
    SmjerKretanja smjer{SmjerKretanja(n)};
    try{
    auto D = IzdvojiDijagonale3D(K, smjer);
    KodIspisa(n);
    for(int i(0); i<int(D.size()); i++){
        for(int j(0); j<int(D[0].size()); j++) {std::cout <<std::setw(4)<< D[i][j];}
        std::cout  << std::endl;
    }
    
    }
    catch(std::domain_error e){
        std::cout << e.what() << std::endl;
    }
	return 0;
}