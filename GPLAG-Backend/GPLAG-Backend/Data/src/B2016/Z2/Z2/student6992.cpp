// B 16/17, Zadaća 2, Zadatak 2
//	Autotestovi by Enil Pajic (epajic1@etf.unsa.ba | @eon : etf.ba)
//	NAPOMENA: i javni ATo-vi su dio postavke!	
#include <iostream>
#include <vector>
#include <deque>
#include <iomanip>
#include <utility>
#include <typeinfo>
#include <memory>
#include <stdexcept>
using namespace std;
enum class SmjerKretanja {
    NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
};
template <typename tip3d>
/*NaprijedNazad*/
auto NaprijedNazad(tip3d kont)->typename remove_reference<decltype(kont.at(0))>::type  {
    typedef typename remove_reference<decltype(kont.at(0))>::type tip2d;
    typedef typename remove_reference<decltype(kont.at(0).at(0))>::type tip1d;
    tip2d rez;
    
    for(int i=0;i<(int)kont.size();i++){
        rez.push_back(tip1d());
        for(int j=0;j<(int)kont.at(i).size();j++){
            rez.at(i).push_back(kont.at(i).at(j).at(j));
        }
    }
    return rez;
}
template<typename tip3d>
/*NazadNaprijed*/
auto NazadNaprijed(tip3d kont) ->typename remove_reference<decltype(kont.at(0))>::type {
    typedef typename remove_reference<decltype(kont.at(0))>::type tip2d;
    typedef typename remove_reference<decltype(kont.at(0).at(0))>::type tip1d;
    tip2d rez;
    for(int i=0;i<(int)kont.size();i++){
        rez.push_back(tip1d());
        for(int j=0;j<(int)kont.at(i).size();j++){
            rez.at(i).push_back(kont.at(kont.size()-i-1).at(j).at(kont.at(0).at(0).size()-j-1));
        }
    }
    return rez;
}
template<typename tip3d>
/*GoreDolje*/
auto GoreDolje(tip3d kont) ->typename remove_reference<decltype(kont.at(0))>::type {
    typedef typename remove_reference<decltype(kont.at(0))>::type tip2d;
    typedef typename remove_reference<decltype(kont.at(0).at(0))>::type tip1d;
    tip2d rez;
    for(int i=0;i<(int)kont.at(0).size();i++){
        rez.push_back(tip1d());
        for(int j=0;j<(int)kont.size();j++){
            rez.at(i).push_back(kont.at(kont.size()-j-1).at(i).at(j));
        }
    }
    return rez;
}
template<typename tip3d>
auto DoljeGore(tip3d kont)-> typename remove_reference<decltype(kont.at(0))>::type {
    typedef typename remove_reference<decltype(kont.at(0))>::type tip2d;
    typedef typename remove_reference<decltype(kont.at(0).at(0))>::type tip1d;
    tip2d rez;
    for(int i=0;i<(int)kont.at(0).size();i++){
        rez.push_back(tip1d());
        for(int j=0;j<(int)kont.size();j++){
            rez.at(i).push_back(kont.at(kont.size()-j-1).at(kont.at(0).size()-i-1).at(kont.at(j).at(i).size()-j-1));
        }
    }
    return rez;
}
template<typename tip3d>
auto LijevoDesno(tip3d kont)-> typename remove_reference<decltype(kont.at(0))>::type {
    typedef typename remove_reference<decltype(kont.at(0))>::type tip2d;
    typedef typename remove_reference<decltype(kont.at(0).at(0))>::type tip1d;
    tip2d rez;
    for(int i=0;i<(int)kont.at(0).at(0).size();i++){
        rez.push_back(tip1d());
        for(int j=0;j<(int)kont.size();j++){
            rez.at(i).push_back(kont.at(kont.size()-j-1).at(j).at(i));
        }
    }
    return rez;
}
template<typename tip3d>
auto DesnoLijevo(tip3d kont)-> typename remove_reference<decltype(kont.at(0))>::type {
    typedef typename remove_reference<decltype(kont.at(0))>::type tip2d;
    typedef typename remove_reference<decltype(kont.at(0).at(0))>::type tip1d;
    tip2d rez;
    for(int i=0;i<(int)kont.at(0).at(0).size();i++){
        rez.push_back(tip1d());
        for(int j=0;j<(int)kont.size();j++){
            rez.at(i).push_back(kont.at(j).at(j).at(kont.at(0).at(0).size()-i-1));
        }
    }
    
    return rez;
}
template <typename tip3d>
auto IzdvojiDijagonale3D(tip3d kont, SmjerKretanja sk) -> typename remove_reference<decltype(kont.at(0))>::type {
    int velRedova=(int)kont.at(0).size();
    int velElem=(int)kont.at(0).at(0).size();
    for(int i=0;i<(int)kont.size();i++){
        if((int)kont.at(i).size()!=velRedova) throw domain_error("Plohe nemaju isti broj redova");
        for(int j=0;j<velRedova;j++)
            if((int)kont.at(i).at(j).size()!=velElem) throw domain_error("Redovi nemaju isti broj elemenata");
    }
    typedef typename remove_reference<decltype(kont.at(0))>::type tip2d;
    tip2d rez;
    
    switch(sk){
        case SmjerKretanja::DesnoLijevo:
            rez=DesnoLijevo(kont);
            break;
        case SmjerKretanja::DoljeGore:
            rez=DoljeGore(kont);
            break;
        case SmjerKretanja::GoreDolje:
            rez=GoreDolje(kont);
            break;
        case SmjerKretanja::LijevoDesno:
            rez=LijevoDesno(kont);
            break;
        case SmjerKretanja::NaprijedNazad:
            rez=NaprijedNazad(kont);
            break;
        case SmjerKretanja::NazadNaprijed:
            rez=NazadNaprijed(kont);
            break;
        default:
            cout<<"Ne valja smjer kretanja" << endl;
            break;
        
    }
    return rez;
}
int main ()
{ 
    try{
        int x, y, z;
        vector<deque<deque<int>>> kvadar;
        cout<<"Unesite dimenzije (x y z): ";
        cin>>x>>y>>z;
        if(x<0 || y<0 || z<0) throw "Neispravne dimenzije kontejnera!";
        cout<<"Unesite elemente kontejnera: "<<endl;
        for(int i=0;i<x;i++){
            kvadar.push_back(deque<deque<int>>());
            for(int j=0;j<y;j++){
                kvadar.at(i).push_back(deque<int>(z));
                for(int k=0;k<z;k++)
                cin>>kvadar.at(i).at(j).at(k);
            }
        }
        int smjer;
        cout<<"Unesite smjer kretanja [0 - 5]: ";
        cin>>smjer;
        if(smjer<0 || smjer>5) throw "Smjer kretanja nije ispravan!";
        
        deque<deque<int>> mat= IzdvojiDijagonale3D(kvadar, SmjerKretanja(smjer));
        switch(smjer){
            case 0:
                cout<<"NaprijedNazad: "<<endl;
                break;
            case 1:
                cout<<"NazadNaprijed: "<<endl;
                break;
            case 2:
                cout<<"GoreDolje: "<<endl;
                break;
            case 3:
                cout<<"DoljeGore: "<<endl;
                break;
            case 4:
                cout<<"LijevoDesno: "<<endl;
                break;
            case 5:
                cout<<"DesnoLijevo: "<<endl;
                break;
        }
        for(auto x : mat){
            for(auto y : x) cout.width(4), cout<<y;
            cout<<endl;
        }
    }
    catch(exception &e){
        cout<<e.what()<<endl;
    }
    catch(char const*s){
        cout<<s<<endl;
    }
    
	return 0;
}