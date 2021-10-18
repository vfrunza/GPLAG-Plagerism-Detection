#include <iostream>
#include <stdexcept>
#include <vector>
#include <deque>
#include <type_traits>
#include <iomanip>
#include <string>

enum class SmjerKretanja {
 NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
};

template <typename kont_tip>
auto IzdvojiDijagonale3D( kont_tip kont, SmjerKretanja smjer) -> typename std::remove_reference<decltype(kont.at(0))>::type{
     typename std::remove_reference<decltype(kont.at(0))>::type matrica;

    for(int i=0; i<kont.size(); i++) {
        for(int j=0; j<kont.at(i).size(); j++) {
            if((kont.at(i)).at(j).size()!=(kont.at(0)).at(0).size())
            throw std::domain_error("Redovi nemaju isti broj elemenata");
        }
    }
    for(int i=0; i<kont.size(); i++) {
        if(kont.at(i).size()!=kont.at(i).size()) 
         throw std::domain_error("Plohe nemaju isti broj redova");
    }
    
if(smjer==SmjerKretanja::NaprijedNazad) {
int red=0;
    for(int i=0; i<kont.size(); i++) {
        for(int j=0; j<kont.at(0).size(); j++) {
            for(int k=0; k<((kont.at(0)).at(0)).size(); k++) {
            if(j==k) {
                matrica.resize(red+1);
                matrica.at(red).push_back(kont.at(i).at(j).at(k)); }
            }
        }
        red++;
    }
    return matrica;
}
if(smjer==SmjerKretanja::NazadNaprijed) {
int red=0;
    for(int i=kont.size()-1; i>=0; i--) {
        for(int j=0; j<kont.at(0).size(); j++) {
            for(int k=0; k<((kont.at(0)).at(0)).size(); k++) {
            if(j+k==kont.at(0).size()) {
                matrica.resize(red+1);
                matrica.at(red).push_back(kont.at(i).at(j).at(k)); }
            }
        }
        red++;
    }
    return matrica;
}
if (smjer==SmjerKretanja::GoreDolje) {
    matrica.resize(kont.at(0).size());
    for(int i=kont.size()-1; i>=0; i--) {
       for(int j=0; j<kont.at(0).size(); j++) {
            for(int k=0; k<((kont.at(0)).at(0)).size(); k++) {
                if (k+i==kont.size()-1)
                matrica.at(j).push_back(kont.at(i).at(j).at(k)); 
            }
            }
            
        }
    
    return matrica;
}
if (smjer==SmjerKretanja::DoljeGore) {
    matrica.resize(kont.at(0).size());
    for(int i=kont.size()-1; i>=0; i--) {
        int red=0;
       for(int j=kont.at(0).size()-1; j>=0; j--) {
            for(int k=((kont.at(0)).at(0)).size()-1; k>=0; k--) {
                if (k==((kont.at(0)).at(0)).size()-1-kont.size()+1+i) {
                matrica.at(red).push_back(kont.at(i).at(j).at(k)); 
                red++;}
            }
       }
    }
    return matrica;
}
if (smjer==SmjerKretanja::LijevoDesno) {
    matrica.resize(kont.at(0).at(0).size());
    for(int i=kont.size()-1; i>=0; i--) {
        int red=0;
       for(int j=0; j<kont.at(0).size(); j++) {
            for(int k=0; k<((kont.at(0)).at(0)).size(); k++) {
                if (j==kont.size()-1-i) {
                matrica.at(red).push_back(kont.at(i).at(j).at(k)); 
                red++;}
            }
            }
            
        }
    
    return matrica;
}
if (smjer==SmjerKretanja::DesnoLijevo) {
    matrica.resize(kont.at(0).at(0).size());
    for(int i=0; i<kont.size(); i++) {
        int red=0;
       for(int j=0; j<kont.at(0).size(); j++) {
            for(int k=((kont.at(0)).at(0)).size()-1; k>=0; k--) {
                if (j==i) {
                
                matrica.at(red).push_back(kont.at(i).at(j).at(k)); 
                red++;}
            }
       }
    }
    return matrica;
}
return matrica;
}

int main ()
{
    try{
    std::cout<<"Unesite dimenzije (x y z): ";
    int x, y, z;
    std::cin>>x>>y>>z;
    if(x<=0 || y<=0 || z<=0) throw std::domain_error("Neispravne dimenzije kontejnera!");
    std::cout<<"Unesite elemente kontejnera: "<<std::endl;
    std::vector<std::deque<std::deque<int>>> kon;
    kon.resize(x);
    for(int j=0; j<x; j++){
        kon[j].resize(y);
        for(int k=0; k<y; k++) {
            kon[j][k].resize(z);
        }
    }
    for(int i=0; i<x; i++)
        for(int j=0; j<y; j++)
            for(int k=0; k<z; k++) {
            int b=0;
                std::cin>>b;
                kon[i][j][k]=(b);
            }
            
    SmjerKretanja s;
    int n;
    std::cout<<"Unesite smjer kretanja [0 - 5]: ";
    std::cin>>n;
    
    if(n<0 || n>5) throw std::domain_error("Smjer kretanja nije ispravan!");
    s=SmjerKretanja(n);
    if(n==0)std::cout<<"NaprijedNazad: "<<std::endl;
    if(n==1)std::cout<<"NazadNaprijed: "<<std::endl;
    if(n==2)std::cout<<"GoreDolje: "<<std::endl;
    if(n==3)std::cout<<"DoljeGore: "<<std::endl;
    if(n==4)std::cout<<"LijevoDesno: "<<std::endl;
    if(n==5)std::cout<<"DesnoLijevo: "<<std::endl;
    std::deque<std::deque<int>> mat=IzdvojiDijagonale3D(kon, s);
    
    for (int i=0; i<mat.size(); i++) {
    for (int j=0; j<mat[0].size(); j++)
    std::cout<<std::setw(4)<<mat[i][j];
    std::cout<<std::endl;}
    }
    catch(std::domain_error i) {std::cout<<i.what()<<std::endl;}
    catch(...) {}

	return 0;
}