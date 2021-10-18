#include <iostream>
#include <cctype>
#include <vector>
#include <algorithm>
#include <deque>
#include <cmath>
#include <type_traits>
#include <limits>
#include <iomanip>
#include <stdexcept>

enum class SmjerKretanja {NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo};

template <typename TipKont>
void ProvjeraKocke(TipKont a){
    for(int i=0; i<a.size(); i++){
        for(int j=0; j<a.at(i).size(); j++){
            if(a.at(i).at(j).size() != a.at(0).at(0).size() ) throw std::domain_error ("Redovi nemaju isti broj elemenata");
        }
        if(a.at(0).size() != a.at(i).size()) throw std::domain_error ("Plohe nemaju isti broj redova");
    }
}

template <typename Tip>
void NapraviMatricu(Tip &a, Tip &b, SmjerKretanja &c){
    int x;
    x = int(c);
    //resize
    if(x==1)a.resize(b.size());
    else if(x>=2 && x<=5)a.resize(b.at(0).size());
    
    
    for(int i=0; i<b.size(); i++){
        for(int j=0; j<b.at(i).size(); j++){
            if(x==1) a.at(a.size() - 1 - i).push_back(b.at(i).at(j));
            else if(x==2) a.at(j).push_back(b.at(b.size() - 1 - i).at(j));
            else if(x==3) a.at(a.size() - 1 - j).push_back(b.at(b.size()-1-i).at(j));
            else if(x==4) a.at(j).push_back(b.at(b.size()-1-i).at(j));
            else if(x==5) a.at(a.size() - 1 - j).push_back(b.at(i).at(j));
        }
    }
}


template <typename TipKont>
auto IzdvojiDijagonale3D(TipKont a, SmjerKretanja b)->typename std::remove_reference<decltype(a.at(0))>::type{
    ProvjeraKocke(a);
    int p;
    p=int(b);
    if(p<0 || p>5) throw p;
    typedef typename std::remove_reference<decltype(a.at(0))>::type MOJTIPKONT;
    MOJTIPKONT x , x_nije_transponovano, x_obrnuto, x_nije_transponovano_obrnuto;
    if(a.size()==0 || a.at(0).size()==0) return x;
    if(a.at(0).at(0).size()==0) return x;
    // PREBACIVANJE U 2D
    typedef typename std::remove_reference<decltype(a.at(0).at(0))>::type MOJTIPvek;
    for(int i=0; i<a.size(); i++){
        MOJTIPvek y, ry;
        for(int j=0; j<a.at(i).size(); j++){
            for(int k=0; k<a.at(i).at(j).size(); k++){
                std::cout << i << " i " << k << " a size je " << a.size() << std::endl;
                if(b==SmjerKretanja::NaprijedNazad){
                    if(j==k)y.push_back(a.at(i).at(j).at(k));
                }
                else if(b==SmjerKretanja::NazadNaprijed){
                    if(j+k==a.at(i).at(j).size() - 1) y.push_back(a.at(i).at(j).at(k));
                }
                else if(b==SmjerKretanja::GoreDolje){
                    if(i+k==a.size() - 1) y.push_back(a.at(i).at(j).at(k));
                }
                else if(b==SmjerKretanja::DoljeGore){
                    if(k-i==a.size()) ry.push_back(a.at(i).at(j).at(k));
                }
                else if(b==SmjerKretanja::LijevoDesno){
                    if(i+j==a.size() - 1) y.push_back(a.at(i).at(j).at(k));
                }
                else if(b==SmjerKretanja::DesnoLijevo){
                    if(i==j) ry.push_back(a.at(i).at(j).at(k));
                }
            }
        }
        if(b==SmjerKretanja::NaprijedNazad) x.push_back(y);
        else if(b==SmjerKretanja::NazadNaprijed) x_obrnuto.push_back(y);
        else if(b==SmjerKretanja::GoreDolje) x_nije_transponovano_obrnuto.push_back(y);
        else if(b==SmjerKretanja::DoljeGore) x_nije_transponovano_obrnuto.push_back(ry);
        else if(b==SmjerKretanja::LijevoDesno) x_nije_transponovano_obrnuto.push_back(y);
        else if(b==SmjerKretanja::DesnoLijevo) x_nije_transponovano.push_back(ry);
    }
        
        int k;
        k=int(b);
        if(k==0) return x;
        else if(k==1) NapraviMatricu(x,x_obrnuto,b);
        else if(k==2) NapraviMatricu(x,x_nije_transponovano_obrnuto,b);
        else if(k==3) NapraviMatricu(x,x_nije_transponovano_obrnuto,b);
        else if(k==4) NapraviMatricu(x,x_nije_transponovano_obrnuto,b);
        else if(k==5) NapraviMatricu(x,x_nije_transponovano,b);
        return x;
}

int main (){
    std::cout <<"Unesite dimenzije (x y z): ";
    int x,y,z;
    std::cin >> x >> y >> z;
    if(x<0 || y<0 || z<0)
    {
        std::cout <<"Neispravne dimenzije kontejnera!"<<std::endl;
        return 0;
    }
    std::cout << "Unesite elemente kontejnera: "<< std::endl;
    std::vector<std::vector<std::deque<int>>> Kocka;
    Kocka.resize(x);
    for(int i=0; i<Kocka.size(); i++) Kocka[i].resize(y);
    for(int i=0; i<Kocka.size(); i++){
        for(int j=0; j<Kocka[i].size(); j++) Kocka[i][j].resize(z);
    }
    for(int i=0; i<Kocka.size(); i++){
        for(int j=0; j<Kocka[i].size(); j++){
            for(int k=0; k<Kocka[i][j].size(); k++){
                int t;
                std::cin >> t;
                Kocka[i][j][k]=t;
            }
        }
    }
    std::cout << "Unesite smjer kretanja [0 - 5]: ";
    int t;
    std::cin >> t;
    try{
        if(t>=0 && t<=5){
            SmjerKretanja f;
        f=static_cast<SmjerKretanja>(t);
        auto Finishh = IzdvojiDijagonale3D(Kocka,f);
        if(t==0) std::cout <<"NaprijedNazad: "<< std::endl;
        else if(t==1) std::cout <<"NazadNaprijed: "<< std::endl;
        else if(t==2) std::cout <<"GoreDolje: "<< std::endl;
        else if(t==3) std::cout <<"DoljeGore: "<< std::endl;
        else if(t==4) std::cout <<"LijevoDesno: "<< std::endl;
        else if(t==5) std::cout <<"DesnoLijevo: "<< std::endl;
        for(int i=0; i<Finishh.size(); i++){
            for(int j=0; j<Finishh.at(i).size(); j++){
                std::cout << std::right <<std::setw(4) << Finishh.at(i).at(j);
            }
            std::cout << std::endl;
        }
        }
        else throw t;
    }
    catch(std::domain_error izuzetak){
        std::cout << izuzetak.what()<< std::endl;
    }
    catch(int t){
        std::cout << "Smjer kretanja nije ispravan!" << std::endl;
    }
        
	return 0;
}