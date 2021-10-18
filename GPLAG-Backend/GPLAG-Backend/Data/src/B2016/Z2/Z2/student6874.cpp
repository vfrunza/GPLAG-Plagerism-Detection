// B 16/17, Zadaća 2, Zadatak 2
//	Autotestovi by Enil Pajic (epajic1@etf.unsa.ba | @eon : etf.ba)
//	NAPOMENA: i javni ATo-vi su dio postavke!	

#include <iostream>
#include <deque>
#include <vector> 
#include <type_traits>
#include <stdexcept>
#include <iomanip>

enum class SmjerKretanja {
    NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
};


template <typename KontTip>
auto IzdvojiDijagonale3D (KontTip kont, SmjerKretanja smjer) ->typename std::remove_reference<decltype(kont[0])>::type {
    typename  std::remove_reference<decltype(kont[0])>::type matrica;
    if(kont.size()==0 || kont[0].size()==0)
      return matrica;
    for(int i=0; i<kont.size(); i++){
        if(kont[i].size()!=kont[0].size())
          throw std::domain_error("Plohe nemaju isti broj redova");
        for(int j=0; j<kont[i].size(); j++)
          if(kont[i][j].size()!=kont[i][0].size())
            throw std::domain_error("Redovi nemaju isti broj elemenata");
    }
    if(smjer==SmjerKretanja::NaprijedNazad){
       int a(0);
       for(int i=0; i<kont.size(); i++){
         matrica.resize(matrica.size() + 1);
         for(int j=0; j<kont[i].size(); j++){
            //matrica.resize(matrica.size() + 1);
            for(int k=0; k<kont[i][j].size(); k++  ){
                if(j==k){
                    matrica[a].push_back(kont[i][j][k]);
                }
            }
            
        }
        a++;
     }
    }
    if(smjer==SmjerKretanja::NazadNaprijed){
        int a(0);
        for(int i=kont.size()-1; i>=0; i--){
            matrica.resize(matrica.size() + 1);
            for(int j=0; j<kont[i].size(); j++){
                for(int k=kont[i][j].size()-1; k>=0; k--){
                    if(j+k == kont[i][j].size() - 1)
                       matrica[a].push_back(kont[i][j][k]);
                }
            }
            a++;
        }
    }
    if(smjer==SmjerKretanja::GoreDolje){
        int a(0);
        for(int i=0; i<kont[0].size(); i++){
            matrica.resize(matrica.size() + 1);
            for(int j=kont.size() - 1; j>=0; j--){
                for(int k=0; k<kont[0][0].size(); k++){
                    if(j+k==kont.size() - 1)
                      matrica[a].push_back(kont[j][i][k]);
                }
            }
            a++;
        }
    }
    if(smjer==SmjerKretanja::DoljeGore){
        int a(0);
        for(int i=kont[0].size()-1; i>=0; i--){
            matrica.resize(matrica.size() + 1);
            for(int j=kont.size() -1; j>=0;  j--){
                for(int k=kont[0][0].size() - 1; k>=0;   k--){
                    if(k-j==kont.size())
                      matrica[a].push_back(kont[j][i][k]);
                }
            }
            a++;
        }
    }
    if(smjer==SmjerKretanja::LijevoDesno){
        int a(0);
        for(int i=0; i<kont[0][0].size(); i++){
            matrica.resize(matrica.size() + 1);
            for(int j=0; j<kont[0].size(); j++){
                for(int k=kont.size() -1; k>=0;  k--){
                    if(j+k==kont.size() - 1)
                      matrica[a].push_back(kont[k][j][i]);
                }
            }
            a++;
        }
    }
    if(smjer==SmjerKretanja::DesnoLijevo){
        int a(0);
        for(int i=kont[0][0].size() - 1; i>=0; i--){
            matrica.resize(matrica.size() + 1);
            for(int j=0; j<kont[0].size(); j++){
                for(int k=0; k<kont.size(); k++){
                    if(j==k)
                      matrica[a].push_back(kont[k][j][i]);
                }
            }
            a++;
        }
    }
return matrica;
}




int main ()
{
    int x,y,z;
    std::cout<<"Unesite dimenzije (x y z): ";
    std::cin>>x>>y>>z;
    if(x<0 || y<0 || z<0){
        std::cout<<"Neispravne dimenzije kontejnera!"<<std::endl;
        return 0;
    }
    std::vector<std::deque<std::deque<int>>>  kontejner(x, std::deque<std::deque<int>>(y, std::deque<int>(z)) );
    std::cout<<"Unesite elemente kontejnera: "<<std::endl;
    for(int i=0; i<x; i++)
      for(int j=0; j<y; j++)
        for(int k=0; k<z; k++)
          std::cin>>kontejner[i][j][k];
    std::cout<<"Unesite smjer kretanja [0 - 5]: ";
    int l;
    std::cin>>l;
    try{
        //auto mat(IzdvojiDijagonale3D(kontejner, SmjerKretanja(l)));
       if(l==0)
         std::cout<<"NaprijedNazad: "<<std::endl;
       else if(l==1)
         std::cout<<"NazadNaprijed: "<<std::endl;
       else if(l==2)
         std::cout<<"GoreDolje: "<<std::endl;
    else if(l==3)
       std::cout<<"DoljeGore: "<<std::endl;
       else if(l==4)
         std::cout<<"LijevoDesno: "<<std::endl;
       else if(l==5)
         std::cout<<"DesnoLijevo: "<<std::endl;
       else  
         std::cout<<"Smjer kretanja nije ispravan!"<<std::endl;
        if(l>=0 && l<=5){
        auto mat(IzdvojiDijagonale3D(kontejner, SmjerKretanja(l)));
        
        for(int i=0; i<mat.size(); i++){
          for(int j=0; j<mat[i].size(); j++)
            std::cout<<std::setw(4)<<mat[i][j];
        std::cout<<std::endl;
            
        }
        }
    }
    catch(std::domain_error e){
        std::cout<<e.what()<<std::endl;
    }
    
	return 0;
}