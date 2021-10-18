// B 16/17, Zadaća 2, Zadatak 2
//	Autotestovi by Enil Pajic (epajic1@etf.unsa.ba | @eon : etf.ba)
//	NAPOMENA: i javni ATo-vi su dio postavke!	
#include <iostream>
#include <deque>
#include <vector>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

enum class SmjerKretanja {
 NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
};

template<typename NekiTip>
auto Glavna(NekiTip kont, int x)->typename std::remove_reference<decltype(kont.at(0))>::type{
    typedef typename std::remove_reference<decltype(kont.at(0))>::type RR;
    RR mat2D;
    if(x==1){
        typename std::remove_reference<decltype(kont.at(0).at(0))>::type  x;
        
        for(int i(0);i<kont.size();i++){
            x.resize(0);
            for(int j(0);j<kont.at(i).size();j++){
                for(int k(0);k<kont.at(i).at(j).size();k++)
                if(j==k)
                x.push_back(kont.at(i).at(j).at(k));
            }
            mat2D.push_back(x);
        }
        return mat2D;
    }
    if(x==-1){
        typename std::remove_reference<decltype(kont.at(0).at(0))>::type  x;
        for(int i((kont.size())-1);i>=0;i--){
            x.resize(0);
            for(int j(0);j<kont.at(i).size();j++){
                for(int k((kont.at(i).at(j).size())-1);k>=0;k--)
                if(k==(kont.at(i).at(j).size())-1-j)
                x.push_back(kont.at(i).at(j).at(k));
            }
            mat2D.push_back(x);
        }
        return mat2D;
    }
    
    return mat2D;
}

template<typename NekiTip>
auto Druga(NekiTip kont, int x)->typename std::remove_reference<decltype(kont.at(0))>::type{
    typedef typename std::remove_reference<decltype(kont.at(0))>::type RR;
    RR mat2D;
    if(x==1){
        typename std::remove_reference<decltype(kont.at(0).at(0))>::type  x;
            x.resize(0);
            for(int j(0);j<kont.at(0).size();j++){
                int k(0);
                x.resize(0);
                for(int i((kont.size())-1);i>=0;i--){
                    x.push_back(kont.at(i).at(j).at(k));
                    k++;
                }
                mat2D.push_back(x);
            }
        return mat2D;
    }
    if(x==-1){
        
        typename std::remove_reference<decltype(kont.at(0).at(0))>::type  x;
            for(int j((kont.at(0).size())-1);j>=0;j--){
                int k((kont.at(0).at(0).size())-1);
                x.resize(0);
                for(int i((kont.size())-1);i>=0;i--){
                    x.push_back(kont.at(i).at(j).at(k));
                    k--;
                }
                mat2D.push_back(x);
            }
        return mat2D;
    }
    return mat2D;
}
template<typename NekiTip>
auto Sporedna(NekiTip kont, int x)->typename std::remove_reference<decltype(kont.at(0))>::type{
    typedef typename std::remove_reference<decltype(kont.at(0))>::type RR;
    RR mat2D;
    
    if(x==1){
       typename std::remove_reference<decltype(kont.at(0).at(0))>::type  x;
            x.resize(0);
            for(int k(0);k<kont.at(0).at(0).size();k++){
                int j(0);
                x.resize(0);
                for(int i((kont.size())-1);i>=0;i--){
                    x.push_back(kont.at(i).at(j).at(k));
                    j++;
                }
            
                mat2D.push_back(x);
            }
        return mat2D;
    }
    if(x==-1){
       typename std::remove_reference<decltype(kont.at(0).at(0))>::type  x;
           for(int k((kont.at(0).at(0).size())-1);k>=0;k--){
                int j(0);
                x.resize(0);
                for(int i(0);i<kont.size();i++){
                    x.push_back(kont.at(i).at(j).at(k));
                    j++;
                }
                mat2D.push_back(x);
            }
        return mat2D;
    }
    return mat2D;
}






template <typename NekiTip>
auto IzdvojiDijagonale3D(NekiTip kont, SmjerKretanja smjer)->typename std::remove_reference<decltype(kont.at(0))>::type{
    typedef typename std::remove_reference<decltype(kont.at(0))>::type RR;
    RR mat2D;
    
    if(smjer==SmjerKretanja::NaprijedNazad){
        mat2D=Glavna(kont,1);
        return mat2D;
    }
    if(smjer==SmjerKretanja::NazadNaprijed){
        mat2D=Glavna(kont,-1);
    }
    if(smjer==SmjerKretanja::GoreDolje){
        mat2D=Druga(kont,1);
        return mat2D;
    }
    if(smjer==SmjerKretanja::DoljeGore){
        mat2D=Druga(kont,-1);
    }
    if(smjer==SmjerKretanja::LijevoDesno){
        mat2D=Sporedna(kont,1);
        return mat2D;
    }
    if(smjer==SmjerKretanja::DesnoLijevo){
        mat2D=Sporedna(kont,-1);
    }
    return mat2D;
}



int main ()
{   
    int x,y,z;
    cout<<"Unesite dimenzije (x y z): ";
    cin>>x>>y>>z;
    if(x<=0|| y<=0 || z<=0){
        cout<<"Neispravne dimenzije kontejnera!";
        return 0;
    }
    cout<<"Unesite elemente kontejnera: ";
    std::deque<std::deque<std::deque<int>>> mat;
    for(int i(0);i<x;i++){
        
        std::deque<std::deque<int>> ma;
        for(int j(0);j<y;j++){
            std::deque<int> red;
            for(int k(0);k<z;k++){
                int l;
                cin>>l;
                red.push_back(l);
            }
            ma.push_back(red);
        }
        mat.push_back(ma);
    }    
    
    cout<<"\nUnesite smjer kretanja [0 - 5]: ";
    int sm;
    cin>>sm;
    if(sm<0 || sm>5) cout<<"Smjer kretanja nije ispravan!"<<endl;
    else{
    auto kont(IzdvojiDijagonale3D (mat,SmjerKretanja(sm)));
    
    std::vector<std::string> koji{{"NaprijedNazad: "},{"NazadNaprijed: "},{"GoreDolje: "},{"DoljeGore: "},{"LijevoDesno: "},{"DesnoLijevo: "}};
    cout<<koji.at(sm)<<endl;
    for (const auto &red : kont){
        for (const auto &x : red)
        std::cout.width (4), std::cout << x;
        std::cout << std::endl;
        }
    
    }

	return 0;
}