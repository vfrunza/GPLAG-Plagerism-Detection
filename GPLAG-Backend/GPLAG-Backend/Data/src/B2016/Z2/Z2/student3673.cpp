// B 16/17, Zadaća 2, Zadatak 2
//	Autotestovi by Enil Pajic (epajic1@etf.unsa.ba | @eon : etf.ba)
//	NAPOMENA: i javni ATo-vi su dio postavke!	
#include <iostream>
#include <vector> 
#include <string>
#include <deque>
#include <stdexcept>

using namespace std;

enum class SmjerKretanja {NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo};

template<typename kont2D,typename kont>
kont2D IzdvojiDijagonale3D(kont k,SmjerKretanja smjer){
    for(int i=0;i<k.size()-1;i++){
        if(k[i].size()!=k[i+1].size())throw domain_error("Plohe nemaju isti broj redova");
    }
     for(int i=0;i<k.size();i++){
        for(int j=0;j<k[i].size()-1;j++){
            if(k[i][j].size()!=k[i][j+1].size())throw domain_error("Redovi nemaju isti broj elemenata");
        }
    }
    kont2D vrati;int brojac(0);
    if(smjer==SmjerKretanja::NaprijedNazad){
    for(int i=0;i<k.size();i++){
        for(int j=0;j<k[i].size();j++){
            for(int l=0;l<k[i][j].size();l++){
                if(l==j)vrati[brojac].push_back(k[i][j][l]);
            }
        }brojac++;
    }
 }
 return vrati;
    
}

int main ()
{
    try{
    cout<<"Unesite dimenzije (x y z): ";
    int x,y,z;
    cin>>x>>y>>z;
    cout<<"Unesite elemente kontejnera: ";
    vector<deque<deque<int>>>kontejner(x,deque<deque<int>>(y,deque<int>(z)));
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            for(int k=0;k<z;k++){
                int el;
                cin>>el;
                kontejner[i][j][k]=el;
            }
        }
    }
    cout<<"Unesite smjer kretanja [0-5]: ";
    int smjer;
    cin>>smjer;
    SmjerKretanja s;
    switch (smjer){
        case 0:
        s=SmjerKretanja::NaprijedNazad;
        break;
        case 1:
        s=SmjerKretanja::NazadNaprijed;
        break;
        case 2:
        s=SmjerKretanja::GoreDolje;
        break;
        case 3:
        s=SmjerKretanja::DoljeGore;
        break;
        case 4:
        s=SmjerKretanja::LijevoDesno;
        break;
        case 5:
        s=SmjerKretanja::DesnoLijevo;
        break;
    }
    deque<deque<int>>d=IzdvojiDijagonale3D(kontejner,s);
    }
    catch(domain_error e){
        cout<<e.what();
    }
	return 0;
}