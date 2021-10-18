// B 16/17, Zadaća 2, Zadatak 2
//	Autotestovi by Enil Pajic (epajic1@etf.unsa.ba | @eon : etf.ba)
//	NAPOMENA: i javni ATo-vi su dio postavke!	
#include <iostream>
#include <vector>
#include <deque>
#include <stdexcept>
#include <type_traits>
#include <iomanip>
enum class SmjerKretanja {
    NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
};

template <typename Kontejner>
auto IzdvojiDijagonale3D(Kontejner kont, SmjerKretanja smjer) -> typename std::remove_reference<decltype(kont[0])>::type {
    
    for(int i(0); i<kont.size(); i++) {
        for(int j(0); j<(kont[i].size()-1); j++) 
            if(kont[i][j].size()!=kont[i][j+1].size()) throw std::domain_error("Redovi nemaju isti broj elemenata");
    }
    for(int i(0); i<(kont.size()-1); i++) 
        if(kont[i].size()!=kont[i+1].size()) throw std::domain_error("Plohe nemaju isti broj redova");
    typename std::remove_reference<decltype(kont[0])>::type rez;
    if(smjer==SmjerKretanja::NaprijedNazad) {
        int index(0);
        rez.resize(kont.size());
        for(int i(0); i<kont.size(); i++) {
            index=i;
            for(int j(0); j<kont[0].size(); j++) {
                for(int k(0); k<kont[0][0].size(); k++) {
                    if(j==k) rez[index].push_back(kont[i][j][k]);
                }
            }
        }
    }
    if(smjer==SmjerKretanja::NazadNaprijed) {
        for(int i(0); i<kont.size()/2; i++) {
            typename std::remove_reference<decltype(kont[0])>::type pom=kont[i];
            kont[i]=kont[kont.size()-1-i];
            kont[kont.size()-1-i]=pom;
        }
        int index(0);
        rez.resize(kont.size());
        for(int i(0); i<kont.size(); i++) {
            index=i;
            for(int j(0); j<kont[0].size(); j++) {
                for(int k(0); k<kont[0][0].size(); k++) {
                    if(k==(kont[0][0].size()-1-j)) rez[index].push_back(kont[i][j][k]);
                }
            }
        }
    }
    
    if(smjer==SmjerKretanja::LijevoDesno) {
    for(int i(0); i<kont.size()/2; i++) {
        typename std::remove_reference<decltype(kont[0])>::type pom=kont[i];
        kont[i]=kont[kont.size()-1-i];
        kont[kont.size()-1-i]=pom;
        }
     rez.resize(kont[0][0].size());
     int br(0);
     for(int l(0); l<kont[0][0].size(); l++) {
     typename std::remove_reference<decltype(kont[0])>::type matrica;
     matrica.resize(kont[0].size());
     int n(0);
     for(int i(0); i<kont.size(); i++) {
         for(int j(0); j<kont[0].size(); j++) {
             n=j;
             for(int k(0); k<kont[0][0].size(); k++)
               if(k==l) matrica[n].push_back(kont[i][j][k]);
         }
     }
        for(int i(0); i<matrica.size(); i++) {
            for(int j(0); j<matrica[0].size(); j++)
                if(i==j) rez[br].push_back(matrica[i][j]);
        }
        br++;
     }
    }
    if(smjer==SmjerKretanja::DesnoLijevo) {
        rez.resize(kont[0][0].size());
     int br(0);
     for(int l(0); l<kont[0][0].size(); l++) {
     typename std::remove_reference<decltype(kont[0])>::type matrica;
     matrica.resize(kont[0].size());
     int n(0);
     for(int i(0); i<kont.size(); i++) {
         for(int j(0); j<kont[0].size(); j++) {
             n=j;
             for(int k(0); k<kont[0][0].size(); k++)
               if(k==l) matrica[n].push_back(kont[i][j][k]);
         }
     }
        for(int i(0); i<matrica.size(); i++) {
            for(int j(0); j<matrica[0].size(); j++)
                if(i==j) rez[br].push_back(matrica[i][j]);
        }
        br++;
     }
     for(int i(0); i<rez.size()/2; i++) {
         typename std::remove_reference<decltype(kont[0][0])>::type pom=rez[i];
         rez[i]=rez[rez.size()-1-i];
         rez[rez.size()-1-i]=pom;
     }
    }
    if(smjer==SmjerKretanja::GoreDolje) {
        for(int i(0); i<kont.size()/2; i++) {
            typename std::remove_reference<decltype(kont[0])>::type pom=kont[i];
            kont[i]=kont[kont.size()-1-i];
            kont[kont.size()-1-i]=pom;
        }
        rez.resize(kont[0].size());
        int n(0);
        for(int i(0); i<kont.size(); i++) {
            for(int j(0); j<kont[0].size(); j++) {
                n=j;
                for(int k(0); k<kont[0][0].size(); k++)
                    if(k==i) rez[n].push_back(kont[i][j][k]);
         }
     }
    }
    if(smjer==SmjerKretanja::DoljeGore) {
        for(int i(0); i<kont.size()/2; i++) {
            typename std::remove_reference<decltype(kont[0])>::type pom=kont[i];
            kont[i]=kont[kont.size()-1-i];
            kont[kont.size()-1-i]=pom;
        }
  
        rez.resize(kont[0].size());
        int n(0);
        for(int i(0); i<kont.size(); i++) {
            for(int j(0); j<kont[0].size(); j++) {
                n=j;
                for(int k(0); k<kont[0][0].size(); k++)
                    if(k==kont[0][0].size()-1-i) rez[n].push_back(kont[i][j][k]);
         }
     }
       for(int i(0); i<rez.size()/2; i++) {
         typename std::remove_reference<decltype(kont[0][0])>::type pom=rez[i];
         rez[i]=rez[rez.size()-1-i];
         rez[rez.size()-1-i]=pom;
     }
    }
    return rez;
}

int main ()
{
    int a,b,c;
    std::cout<<"Unesite dimenzije (x y z): ";
    std::cin>>a>>b>>c;
    if(a<=0 || b<=0 || c<=0) {
        std::cout<<"Neispravne dimenzije kontejnera!";
        return 0;
    }
    std::cout<<"Unesite elemente kontejnera: ";
    std::cout<<std::endl;
    std::vector<std::deque<std::vector<int>>> kont;
    kont.resize(a);
    for(int i(0); i<a; i++) 
        kont[i].resize(b);
    
    for(int i(0); i<a; i++) 
        for(int j(0); j<b; j++)
            kont[i][j].resize(c);
    
    for(int i(0); i<a; i++)
        for(int j(0); j<b; j++)
            for(int k(0); k<c; k++)
                std::cin>>kont[i][j][k];
    
    std::cout<<"Unesite smjer kretanja [0 - 5]: ";
    int broj;
    std::cin>>broj;
    if(broj<0 || broj>5) {
        std::cout<<"Smjer kretanja nije ispravan!"<<std::endl;
        return 0;
    }
    try {
    SmjerKretanja kretanje = SmjerKretanja(broj);
    std::deque<std::vector<int>> rez = IzdvojiDijagonale3D(kont,kretanje);
    if(broj==0) std::cout<<"NaprijedNazad: "<<std::endl;
    else if(broj==1) std::cout<<"NazadNaprijed: "<<std::endl;
    else if(broj==2) std::cout<<"GoreDolje: "<<std::endl;
    else if(broj==3) std::cout<<"DoljeGore: "<<std::endl;
    else if(broj==4) std::cout<<"LijevoDesno: "<<std::endl;
    else if(broj==5) std::cout<<"DesnoLijevo: "<<std::endl;
    for(int i(0); i<rez.size(); i++) {
        for(int j(0); j<rez[i].size(); j++)
            std::cout<<std::setw(4)<<rez[i][j];
        std::cout<<std::endl;
    }
}
    catch(std::domain_error izuzetak) {
        std::cout<<izuzetak.what();
    }
	return 0;
}