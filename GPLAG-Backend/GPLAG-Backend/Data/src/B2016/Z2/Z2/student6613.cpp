// B 16/17, Zadaća 2, Zadatak 2
//	Autotestovi by Enil Pajic (epajic1@etf.unsa.ba | @eon : etf.ba)
//	NAPOMENA: i javni ATo-vi su dio postavke!	
#include<iostream>
#include<deque>
#include<vector>
#include<type_traits>
using std::cin;
using std::cout;
using std::endl;
template<typename tip>
auto IzdvojiDijagonale3D(tip kontejner, int n)->typename std::remove_reference<decltype(kontejner.at(0))>::type{
    typename std::remove_reference<decltype((kontejner).at(0))>::type m, mat;
    typename std::remove_reference<decltype(m.at(0))>::type v, vek; 
    if(n==0){
        for(int i=0; i<kontejner.size(); i++){
            m=kontejner.at(i);
            for(int j=0; j<m.size(); j++){
                v=m.at(j); 
                for(int k=0; k<m.size(); k++)
                    if(j==k) vek.push_back(v.at(j));
            }
                mat.push_back(vek);
                vek.resize(0);
        }
    }
    else if(n==1){
        for(int i=kontejner.size()-1; i>=0; i--){
            m=kontejner.at(i);
            for(int j=0; j<m.size(); j++){
                v=m.at(j);
                int vel=v.size()-j-1;
                for(int k=0; k<v.size(); k++)
                    if(k==vel) vek.push_back(v.at(k));
            }
            mat.push_back(vek);
            vek.resize(0);
        }
    }
    return mat;
}

int main ()
{
    int x, y, z, broj;
    cout<<"Unesite dimenzije (x y z): ";
    cin>>x>>y>>z;
    std::vector<std::deque<std::deque<int>>>kontejner;
    std::deque<std::deque<int>>matrica;
    std::deque<int>vektor;
    cout<<"Unesite elemente kontejnera: ";
    for(int i=0; i<x; i++){
        for(int j=0; j<y; j++){
            for(int k=0; k<z; k++){
                cin>>broj;
                vektor.push_back(broj);
            }
            matrica.push_back(vektor);
            vektor.resize(0);
        }
        kontejner.push_back(matrica);
        matrica.resize(0);
    }
    cout<<"Elementi su: "<<endl;
    std::deque<std::deque<int>> mat=IzdvojiDijagonale3D(kontejner, 1);
    for(int i=0; i<mat.size(); i++){
        for(int j=0; j<mat[i].size(); j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
	return 0;
}