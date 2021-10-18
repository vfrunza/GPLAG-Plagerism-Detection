#include <iostream>
#include <stdexcept>
#include <deque>
#include <vector>
#include <type_traits>
#include <iomanip>
#include <cmath>
enum class SmjerKretanja {NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo};
template <typename tip>
auto PjescaniSat(tip &kont, SmjerKretanja smjer) ->typename std::remove_reference<decltype(kont.at(0))>::type{
    typename std::remove_reference<decltype(kont.at(0))>::type matrica(0);
    typename std::remove_reference<decltype(kont.at(0).at(0))>::type red(0);
    
    for(int i=0; i<kont.size();i++)
        for(int j=0; j<kont.at(i).size();j++)
            if(kont.at(0).at(0).size()!=kont.at(i).at(j).size())throw std::domain_error("Redovi nemaju isti broj elemenata");
    
    for(int i=0; i<kont.size();i++)
        if(kont.at(0).size()!=kont.at(i).size())throw std::domain_error("Plohe nemaju isti broj redova");
   
    if(smjer==SmjerKretanja::NaprijedNazad){
        for(int i=0; i<kont.size();i++){
           red.resize(0);
           for(int j=0; j<kont.at(i).size();j++)
              for(int k=0; k<kont.at(i).at(j).size();k++)
                   if(k==j)red.push_back(kont.at(i).at(j).at(k));
                   
           if(red.size()!=0)matrica.push_back(red);
        }
    }else if(smjer==SmjerKretanja::NazadNaprijed){
         for(int i=kont.size()-1; i>=0;i--){
           red.resize(0);
           for(int j=0; j<kont.at(i).size();j++){
              for(int k=kont.at(i).at(j).size()-1; k>=0;k--){
                   if(kont.at(i).at(j).size()-1-k==j)red.push_back(kont.at(i).at(j).at(k));
               }
           }
           if(red.size()!=0)matrica.push_back(red);
        }
    }else if(smjer==SmjerKretanja::GoreDolje){
        if(kont.size()!=0)
            for(int j=0; j<kont.at(0).size();j++){
                red.resize(0);
                for(int i=kont.size()-1; i>=0;i--){
                    for(int k=0; k<kont.at(i).at(j).size();k++){
                       if(k==kont.size()-1-i)red.push_back(kont.at(i).at(j).at(k));
                    }
                }
                if(red.size()!=0)matrica.push_back(red);
            }
    }else if(smjer==SmjerKretanja::DoljeGore){
        if(kont.size()!=0)
            for(int j=kont.at(0).size()-1; j>=0;j--){
                red.resize(0);
                for(int i=kont.size()-1; i>=0;i--){
                    for(int k=kont.at(i).at(j).size()-1; k>=0;k--){
                       if(kont.at(i).at(j).size()-1-k==kont.size()-1-i)red.push_back(kont.at(i).at(j).at(k));
                    }
                }
                if(red.size()!=0)matrica.push_back(red);
            }
    }else if(smjer==SmjerKretanja::LijevoDesno){
        if(kont.size()!=0)
            if(kont.at(0).size()!=0)
                for(int k=0; k<kont.at(0).at(0).size();k++){
                    red.resize(0);
                    for(int j=0; j<kont.at(0).size();j++){
                        for(int i=kont.size()-1;i>=0;i--){
                            if(kont.size()-1-i==j)red.push_back(kont.at(i).at(j).at(k));
                        }
                    }
                    if(red.size()!=0)matrica.push_back(red);
                }
    
    }else if(smjer==SmjerKretanja::DesnoLijevo){
        if(kont.size()!=0)
            if(kont.at(0).size()!=0)
                for(int k=kont.at(0).at(0).size()-1; k>=0;k--){
                    red.resize(0);
                    for(int j=0; j<kont.at(0).size();j++){
                        for(int i=0;i<kont.size();i++){
                            if(i==j)red.push_back(kont.at(i).at(j).at(k));
                        }
                    }
                    if(red.size()!=0)matrica.push_back(red);
                }
    }
    return matrica;
}
int main (){   
    int x(0),y(0),z(0);
    double xa(-1),ya(-1),za(-1);
    std::cout<<"Unesite dimenzije (x y z): ";
    std::cin>>xa>>ya>>za;
    if(!std::cin){std::cout<<"Neispravne dimenzije kontejnera!"; return 0;}
    else{
        if(std::cin.peek()!='\n' || std::fabs(xa-int(xa))>0.0001 || std::fabs(ya-int(ya))>0.0001 || std::fabs(za-int(za))>0.0001){
            std::cout<<"Neispravne dimenzije kontejnera!"; return 0;
        }
        x=int(xa);
        y=int(ya);
        z=int(za);
    }
    if(x<0 ||y<0 ||z<0){std::cout<<"Neispravne dimenzije kontejnera!"; return 0;}
    std::vector<std::deque<std::deque<int>>> konta(x,std::deque<std::deque<int>>(y,std::deque<int>(z)));
    std::cout<<"Unesite elemente kontejnera: "<<std::endl;
    for(int i=0; i<x;i++)
        for(int j=0; j<y;j++)
            for(int k=0;k<z;k++)
                std::cin>>konta[i][j][k];
    
    std::cout<<"Unesite smjer kretanja [0 - 5]: ";
    int s(0);
    std::cin>>s;
    SmjerKretanja sm;
    bool ok(true);
    switch(s){
        case 0: sm=SmjerKretanja::NaprijedNazad; std::cout<<"NaprijedNazad: "<<std::endl; break;
        case 1: sm=SmjerKretanja::NazadNaprijed; std::cout<<"NazadNaprijed: "<<std::endl; break;
        case 2: sm=SmjerKretanja::GoreDolje; std::cout<<"GoreDolje: "<<std::endl; break;
        case 3: sm=SmjerKretanja::DoljeGore; std::cout<<"DoljeGore: "<<std::endl; break;
        case 4: sm=SmjerKretanja::LijevoDesno; std::cout<<"LijevoDesno: "<<std::endl; break;
        case 5: sm=SmjerKretanja::DesnoLijevo; std::cout<<"DesnoLijevo: "<<std::endl; break;
        default: ok=false; break;
    }
    if(ok){
        try{
            auto a=PjescaniSat(konta,sm);
            for(int i=0; i<a.size();i++){
               for(int j=0; j<a.at(i).size();j++){
                    std::cout<<std::setw(4)<<std::right<<a.at(i).at(j);
               }
                std::cout<<std::endl;
            }  
        }catch(std::domain_error a){
            std::cout<<a.what()<<std::endl;
        }
   }else std::cout<<"Smjer kretanja nije ispravan!"<<std::endl;
	return 0;
}