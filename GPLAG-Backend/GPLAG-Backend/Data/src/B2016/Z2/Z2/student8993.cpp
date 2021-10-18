// B 16/17, Zadaća 2, Zadatak 2
//	Autotestovi by Enil Pajic (epajic1@etf.unsa.ba | @eon : etf.ba)
//	NAPOMENA: i javni ATo-vi su dio postavke!	
#include <iostream>
#include <iterator>
#include <iomanip>
#include <deque>
#include <vector>
#include <stdexcept>

enum class SmjerKretanja {NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo};

template <typename triD>
auto IzdvojiDijagonale3D (triD kont, SmjerKretanja smjer)-> typename std::remove_reference<decltype(*kont.begin())>::type {
    typename triD::iterator poc_kont(kont.begin());
    typename triD::iterator kraj_kont(kont.end());
    //int ploha=kont.size();
    int redova= (*kont.begin()).size();
    int kolona= (*(*kont.begin()).begin()).size();
    while(poc_kont != kraj_kont){
        auto i=(*poc_kont).begin();
        while (i != (*poc_kont).end()) {
            if((*i).size() != kolona) throw std::domain_error("Redovi nemaju isti broj elemenata");
            i++;
        }
        poc_kont++;
    }
    while (poc_kont != kraj_kont) {
        if((*poc_kont).size()!=redova) throw std::domain_error ("Plohe nemaju isti broj redova");
    }
    
    typename std::remove_reference<decltype(*kont.begin())>::type rezultat;
    //typename std::remove_reference<decltype (*rezultat.begin())>::type red;
    //int br(0);
    //if(smjer==SmjerKretanja::NaprijedNazad || smjer==SmjerKretanja::NazadNaprijed) br=kont.size();
    //else if( smjer == SmjerKretanja::GoreDolje || smjer== SmjerKretanja::DoljeGore) br=redova;
    //else br=kolona;
    
    if(smjer==SmjerKretanja::NaprijedNazad){
        for(int i=0; i<kont.size(); i++){
            typename std::remove_reference<decltype (*rezultat.begin())>::type red;
            for(int j=0; j<kont.at(i).size() && j<kont.at(i).at(i).size(); j++)
            red.push_back(kont.at(i).at(j).at(j));
            rezultat.push_back(red);
        }
    }
    else if(smjer==SmjerKretanja::NazadNaprijed){
        for(int i=kont.size()-1 ; i>=0; i--){
            typename std::remove_reference<decltype (*rezultat.begin())>::type red;
            int j(kolona-1);
            for(int k=0; k<redova && j>=0; k++){ red.push_back(kont.at(i).at(k).at(j)); j--;}
            rezultat.push_back(red);
        }
    }
    else if(smjer==SmjerKretanja::GoreDolje){
        for(int i=0; i<redova; i++){
            typename std::remove_reference<decltype (*rezultat.begin())>::type red;
            int j=kont.size()-1; 
            for(int k=0; k<kont.size() && j>=0 ; k++){red.push_back(kont.at(j).at(i).at(k)); j--;} 
            rezultat.push_back(red);
        }
    }
    else if(smjer==SmjerKretanja::DoljeGore){
        for(int i=redova-1; i>=0; i--){
            typename std::remove_reference<decltype (*rezultat.begin())>::type red;
            int j=kont.size()-1;
            for(int k=kolona-1; k>=0 && j>=0; k--){ red.push_back(kont.at(j).at(i).at(k)); j--;}
            rezultat.push_back(red);
        }
    }
    else if(smjer==SmjerKretanja::LijevoDesno){
        for(int i=0; i<kolona; i++){
            typename std::remove_reference<decltype (*rezultat.begin())>::type red;
            int j=kont.size()-1;
            for(int k=0; k<redova && j>=0; k++){ red.push_back(kont.at(j).at(k).at(i)); j--;}
            rezultat.push_back(red);
        }
    }
    else if(smjer==SmjerKretanja::DesnoLijevo){
        for(int i=kolona-1; i>=0; i--){
            typename std::remove_reference<decltype (*rezultat.begin())>::type red;
            int j=0;
            for(int k=0; k<redova && j<kont.size(); k++) {red.push_back(kont.at(j).at(k).at(i)); j++;}
            rezultat.push_back(red);
        }
    }
   
    
    
    
    return rezultat;
}


int main ()
{ /*
    try{
        
    int a,b,c;
    std::cout<<"Unesite dimenzije (x y z): ";
    std::cin>>a>>b>>c;
    if (a<0 || b<0 || c<0) {std::cout << "Neispravne dimenzije kontejnera!" << std::endl; return 0;}
    std::vector<std::deque<std::deque<int>>> v;
    v.resize(a);
    for(int i=0; i<a; i++) v[i].resize(b);
    for(int i=0; i<a; i++) { for (int j=0; j<b; j++) v[i][j].resize(c);}
    std::cout<<"Unesite elemente kontejnera: "<<std::endl;
    for(int i=0; i<a; i++){
        for(int j=0; j<b; j++){
            for(int k=0; k<c; k++){
                std::cin>>v[i][j][k];
            }
        }
    }
    int s;
    
    
        std::cout << "Unesite smjer kretanja [0 - 5]: ";
        std::cin>>s;
        if(s>=0 && s<=5){
        std::deque<std::deque<int>> rez=IzdvojiDijagonale3D(v,SmjerKretanja(s));
        if(s==0) std::cout << "NaprijedNazad: "<<std::endl;
        else if(s==1) std::cout << "NazadNaprijed: "<<std::endl;
        else if( s==2) std::cout << "GoreDolje: "<<std::endl;
        else if(s==3) std::cout << "DoljeGore: "<<std::endl;
        else if(s==4) std::cout << "LijevoDesno: "<<std::endl;
        else if(s==5) std::cout << "DesnoLijevo: "<<std::endl;
        for(int i=0; i<rez.size(); i++){
            for(int j=0; j<rez[i].size(); j++){ std::cout.width(4); std::cout<<rez[i][j];}
            std::cout<<std::endl;
            }
            return 0;
            //break;
        }
        else 
            std::cout << "Smjer kretanja nije ispravan!" << std::endl; 
            //if(s<0) break;}
            //br++;
        
    }
    catch(std::domain_error iz){
        std::cout << iz.what() << std::endl;
    }*/
    {//AT18 (skriveni): prazna matrica (0x0x0)
    std::deque<std::deque<std::vector<double>>> kont;
    auto p1 = IzdvojiDijagonale3D (kont, SmjerKretanja::NaprijedNazad);
    auto p2 = IzdvojiDijagonale3D (kont, SmjerKretanja::NazadNaprijed);
    auto p3 = IzdvojiDijagonale3D (kont, SmjerKretanja::GoreDolje);
    auto p4 = IzdvojiDijagonale3D (kont, SmjerKretanja::DoljeGore);
    auto p5 = IzdvojiDijagonale3D (kont, SmjerKretanja::LijevoDesno);
    auto p6 = IzdvojiDijagonale3D (kont, SmjerKretanja::DesnoLijevo);
    std::cout << p1.size() << " " << p2.size() << " " << p3.size() << " "
              << p4.size() << " " << p5.size() << " " << p6.size();
}

	return 0;
}