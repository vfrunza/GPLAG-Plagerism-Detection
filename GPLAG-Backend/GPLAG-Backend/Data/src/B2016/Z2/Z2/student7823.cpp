// B 16/17, Zadaća 2, Zadatak 2
//	Autotestovi by Enil Pajic (epajic1@etf.unsa.ba | @eon : etf.ba)
//	NAPOMENA: i javni ATo-vi su dio postavke!	

#include <vector>
#include <iostream>
#include <iomanip>
#include <deque>
#include <type_traits>
#include <stdexcept>

typedef std::vector<int> Vektor;
typedef std::vector<std::vector<int>> Matrica;
typedef std::vector<std::vector<std::vector<int>>> Mat3D;

enum class SmjerKretanja{
    NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
};

Matrica KreirajMatricu(int br_red, int br_kol){
    if(br_red==0 || br_kol==0) return(Matrica(br_red, Vektor(br_kol)));
    return Matrica(br_red, Vektor(br_kol));
}
Mat3D Kreiraj3DMatricu(int br_ploha, int br_red, int br_kol){
    return Mat3D(br_ploha, Matrica(br_red, Vektor(br_kol)));
}
Mat3D UnesiMatricu(int br_ploha, int br_red, int br_kol){
    Mat3D mat=Kreiraj3DMatricu(br_ploha,br_red,br_kol);
    for(int k=0;k<br_ploha;k++){
        for(int j=0;j<br_red;j++){
            for(int i=0;i<br_kol;i++){
                std::cin>>mat[k][j][i];
            }
        }
    }    
    return mat;
}

//Glavna funkcija
template<typename NekiTip>
auto IzdvojiDijagonale3D(NekiTip mat, SmjerKretanja smjer)-> typename std::remove_reference<decltype(mat.at(0))>::type {
    typename std::remove_reference<decltype(mat.at(0))>::type DvoDim;
    int br_ploha=mat.size();
    int br_red=mat[0].size();
    int br_kol=mat[0][0].size();
    if(br_ploha==0 || br_red==0 || br_kol==0){
        return DvoDim;
    }
    for(int k=0;k<br_ploha;k++){
        for(int i=0;i<br_red;i++){
            for(int j=0;j<br_kol;j++){
                if(mat.at(k).at(i).size()!=br_kol){
                    throw std::domain_error("Redovi nemaju isti broj elemenata");
                }
            }
        }
    }
    for(int k=0;k<br_ploha;k++){
        if(mat.at(k).size()!=br_red){
                throw std::domain_error("Plohe nemaju isti broj redova");
        }
    }

    if((int)smjer==0){       
        for(int k=0;k<br_ploha;k++){
            typename std::remove_reference<decltype(mat.at(0).at(0))>::type pom;
            for(int i=0;i<br_red;i++){
                for(int j=0;j<br_kol;j++){
                    if(i==j){ 
                        
                        pom.push_back(mat.at(k).at(i).at(j));}
                }
            }
            DvoDim.push_back(pom);
        }
        return DvoDim;
    }
    if((int)smjer==1){       
        for(int k=0;k<br_ploha;k++){
            typename std::remove_reference<decltype(mat.at(0).at(0))>::type pom;
            for(int i=0;i<br_red;i++){
                for(int j=0;j<br_kol;j++){
                    if(i+j==br_kol-1){ 
                        pom.push_back(mat.at(br_ploha-k-1).at(i).at(j));}
                }
            }
            DvoDim.push_back(pom);
        }
        return DvoDim;
    }
    if((int)smjer==2){
        for(int i=0;i<br_red;i++){
            typename std::remove_reference<decltype(mat.at(0).at(0))>::type pom;
            for(int j=0;j<br_kol;j++){
                for(int k=0;k<br_ploha;k++){
                    if(j==k){
                        pom.push_back(mat.at(br_ploha-k-1).at(i).at(j));}
                }
            }
            DvoDim.push_back(pom);
        }
        return DvoDim;
    }
    if((int)smjer==3){
        for(int i=0;i<br_red;i++){
           typename std::remove_reference<decltype(mat.at(0).at(0))>::type pom;
            for(int j=0;j<br_kol;j++){
                for(int k=0;k<br_ploha;k++){
                    if(j==k){
                        pom.push_back(mat.at(br_ploha-k-1).at(br_red-i-1).at(br_kol-j-1));}
                }
            }
            DvoDim.push_back(pom);
        }
        return DvoDim;
    }    
    if((int)smjer==4){       
        for(int j=0;j<br_kol;j++){
            typename std::remove_reference<decltype(mat.at(0).at(0))>::type pom;
            for(int i=0;i<br_red;i++){
                for(int k=0;k<br_ploha;k++){
                    if(i==k){
                        
                        pom.push_back(mat.at(br_ploha-k-1).at(i).at(j));}
                }
            }
            DvoDim.push_back(pom);
        }
        return DvoDim;
    }
    if((int)smjer==5){       
        for(int j=0;j<br_kol;j++){
            typename std::remove_reference<decltype(mat.at(0).at(0))>::type pom;
            for(int i=0;i<br_red;i++){
                for(int k=0;k<br_ploha;k++){
                    if(i==k){
                        pom.push_back(mat.at(k).at(i).at(br_kol-j-1));}
                }
            }
            DvoDim.push_back(pom);
        }
        return DvoDim;
    }
    return DvoDim;
}

void IspisiMatricu(Matrica m){
    for(int i=0;i<m.size();i++){
        for(int j=0;j<m[0].size();j++){
            std::cout<<std::setw(4)<<std::right<<m[i][j];
        }
        std::cout<<std::endl;
    }
}
int main (){
    std::cout<<"Unesite dimenzije (x y z): ";
    int br_ploha, br_red, br_kol;
    std::cin>>br_ploha>>br_red>>br_kol;
    if(br_ploha<0 || br_red<0 || br_kol<0){std::cout<<"Neispravne dimenzije kontejnera!"; return 0;}
    
    Mat3D mat=Kreiraj3DMatricu(br_ploha,br_red,br_kol);
    
    std::cout<<"Unesite elemente kontejnera: ";
    mat=UnesiMatricu(br_ploha,br_red,br_kol);
    Matrica rezultat=KreirajMatricu(0,0);
    std::cout<<"\nUnesite smjer kretanja [0 - 5]: ";
        int n;
    std::cin>>n;
    if(n<0 || n>5) {
        std::cout<<"Smjer kretanja nije ispravan!"<<std::endl;
        return 0;
    }
    const char *smjerovi[6]={"NaprijedNazad", "NazadNaprijed", "GoreDolje", "DoljeGore", "LijevoDesno", "DesnoLijevo"};
    std::cout<<smjerovi[n]<<": "<<std::endl;
try{
    std::cout<<std::endl;
    rezultat=(IzdvojiDijagonale3D(mat,SmjerKretanja(n)));
    IspisiMatricu(rezultat);
}catch(std::domain_error izuzetak){
    std::cout<<izuzetak.what();
}
	return 0;
}