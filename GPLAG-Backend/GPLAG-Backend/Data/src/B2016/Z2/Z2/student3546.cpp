#include <iostream>
#include <vector>
#include <deque>
#include <stdexcept>
#include <iomanip>

using std::cin;
using std::cout;

enum class SmjerKretanja{
    NaprijedNazad,NazadNaprijed,GoreDolje,DoljeGore,LijevoDesno,DesnoLijevo
};

template <typename kont>
auto IzdvojiDijagonale3D(kont K,SmjerKretanja smjer)-> typename std::remove_reference<decltype(K.at(0))>::type {
    for(int i=0;i<K.size();i++){
        for(int j=0;j<K.at(i).size();j++){
            for(int k=j+1;k<K.at(i).size();k++){
                if(K.at(i).at(j).size()!=K.at(i).at(k).size())
                throw std::domain_error("Redovi nemaju isti broj elemenata");
            }
        }
    }
    for(int i=0;i<K.size();i++){
        for(int j=i+1;j<K.size();j++){
            if(K.at(i).size()!=K.at(j).size())
            throw std::domain_error("Plohe nemaju isti broj redova");
        }
    }
    typename std::remove_reference<decltype(K.at(0))>::type mat;
    int x=K.size();
    int y=K.at(0).size();
    int z=K.at(0).at(0).size();
    if(smjer==SmjerKretanja::NaprijedNazad){
        for(int i=0;i<x;i++){
            for(int j=0;j<y;j++){
                for(int k=0;k<z;k++){
                    if(j==k){
                        mat.resize(i+1);
                        mat.at(i).resize(j+1);
                        mat.at(i).at(j)=K.at(i).at(j).at(k);
                    }
                }
            }
        }
    }
    else if(smjer==SmjerKretanja::NazadNaprijed){
        for(int i=0;i<x;i++){
            for(int j=0;j<y;j++){
                for(int k=0;k<z;k++){
                    if(j+k==y){
                        mat.resize(x);
                        mat.at(x-i-1).resize(j+1);
                        mat.at(x-i-1).at(j)=K.at(i).at(j).at(k);
                    }
                }
            }
        }
    }
    else if(smjer==SmjerKretanja::GoreDolje){
        for(int i=0;i<x;i++){
            for(int j=0;j<y;j++){
                for(int k=0;k<z;k++){
                    if(i+k==x-1){
                        mat.resize(y);
                        mat.at(j).resize(x);
                        mat.at(j).at(x-i-1)=K.at(i).at(j).at(k);
                    }
                }
            }
        }
    }
    else if(smjer==SmjerKretanja::DoljeGore){
        for(int i=0;i<x;i++){
            for(int j=0;j<y;j++){
                for(int k=0;k<z;k++){
                    if(i-k==x-z){
                     mat.resize(y);
                     mat.at(y-j-1).resize(x);
                     mat.at(y-j-1).at(x-i-1)=K.at(i).at(j).at(k);
                    }
                }
            }
        }
    }
    else if(smjer==SmjerKretanja::LijevoDesno){
        for(int i=0;i<x;i++){
            for(int j=0;j<y;j++){
                for(int k=0;k<z;k++){
                    if(j+i==x-1){
                        mat.resize(z);
                        mat.at(k).resize(x);
                        mat.at(k).at(x-i-1)=K.at(i).at(j).at(k);
                    }
                }
            }
        }
    }
    else if(smjer==SmjerKretanja::DesnoLijevo){
        for(int i=0;i<x;i++){
            for(int j=0;j<y;j++){
                for(int k=0;k<z;k++){
                    if(i==j){
                        mat.resize(z);
                        mat.at(z-k-1).resize(x);
                        mat.at(z-k-1).at(i)=K.at(i).at(j).at(k);
                    }
                }
            }
        }
    }
    return mat;
}
int main ()
{
    int x,y,z;
    cout<<"Unesite dimenzije (x y z): ";
    cin>>x>>y>>z;
    if(x<0 || y<0 || z<0){
        cout<<"Neispravne dimenzije kontejnera!";
        return 0;
    }
    std::vector<std::deque<std::deque<int>>> V;
    cout<<"Unesite elemente kontejnera: "<<std::endl;
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            for(int k=0;k<z;k++){
                int broj;
                cin>>broj;
                V.resize(i+1);
                V.at(i).resize(j+1);
                V.at(i).at(j).push_back(broj);
            }
        }
    }
    cout<<"Unesite smjer kretanja [0 - 5]: ";
    int smjer;
    cin>>smjer;
    if(smjer<0 || smjer>5)
    cout<<"Smjer kretanja nije ispravan!"<<std::endl;
    std::deque<std::deque<int>> mat;
    switch(smjer){
        case 0:mat=IzdvojiDijagonale3D(V,SmjerKretanja::NaprijedNazad);
        cout<<"NaprijedNazad: "<<std::endl;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat.at(0).size();j++){
                cout<<std::setw(4)<<mat.at(i).at(j);
            }
            cout<<"\n";
        }
        break;
        case 1:mat=IzdvojiDijagonale3D(V,SmjerKretanja::NazadNaprijed);
        cout<<"NazadNaprijed: "<<std::endl;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat.at(0).size();j++){
                cout<<std::setw(4)<<mat.at(i).at(j);
            }
            cout<<"\n";
        }
        break;
        case 2:mat=IzdvojiDijagonale3D(V,SmjerKretanja::GoreDolje);
        cout<<"GoreDolje: "<<std::endl;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat.at(0).size();j++){
                cout<<std::setw(4)<<mat.at(i).at(j);
            }
            cout<<"\n";
        }
        break;
        case 3:mat=IzdvojiDijagonale3D(V,SmjerKretanja::DoljeGore);
        cout<<"DoljeGore: "<<std::endl;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat.at(0).size();j++){
                cout<<std::setw(4)<<mat.at(i).at(j);
            }
            cout<<"\n";
        }
        break;
        case 4:mat=IzdvojiDijagonale3D(V,SmjerKretanja::LijevoDesno);
        cout<<"LijevoDesno: "<<std::endl;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat.at(0).size();j++){
                cout<<std::setw(4)<<mat.at(i).at(j);
            }
            cout<<"\n";
        }
        break;
        case 5:mat=IzdvojiDijagonale3D(V,SmjerKretanja::DesnoLijevo);
        cout<<"DesnoLijevo: "<<std::endl;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat.at(0).size();j++){
                cout<<std::setw(4)<<mat.at(i).at(j);
            }
            cout<<"\n";
        }
        break;
    }
	return 0;
}