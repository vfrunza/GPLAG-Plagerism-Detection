#include <iostream>
#include <vector>
#include <deque>
#include <iomanip>
#include <stdexcept>
typedef std::vector<std::deque<std::deque<int>>>mat;
typedef std::deque<std::deque<int>> mat1;
enum class SmjerKretanja{
    NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
};
template <typename NekiTip1, typename NekiTip2>
NekiTip1 IzdvojiDijagonale3D(NekiTip2 kont, SmjerKretanja smjer){
    NekiTip1 a;
    int red{0}, kolona{0}, ploha{0}, x{0}, y{0};
    ploha=kont.size();
    red=kont[0].size();
    kolona=kont[0][0].size();
    for(int i=0; i<ploha; i++){
        if(kont[i].size()!=kont[0].size()) throw std::domain_error("Plohe nemaju isti broj redova");
    }
    for(int i=0; i<ploha; i++){
        for(int j=0; j<red; j++){
          if(kont[i][j].size()!=kont[0][0].size()) throw std::domain_error("Redovi nemaju isti broj elemenata");
        }
    }
 if(smjer==SmjerKretanja::NaprijedNazad){
        a.resize(ploha);
        for(int i=0; i<ploha; i++) a[i].resize(red);
        for(int i=0; i<ploha; i++){
            for(int j=0; j<red; j++){
                for(int k=0;  k<kolona; k++){
                    if(j==k){ a[x][y]=kont[i][j][k]; y++;}
                }
            }
            x++;
            y=0;
        }
    }
    if(smjer==SmjerKretanja::NazadNaprijed){
        a.resize(ploha);
        for(int i=0; i<ploha; i++) a[i].resize(red);
        for(int i=ploha-1; i>=0; i--){
            for(int j=0; j<red; j++){
                for(int k=kolona-1; k>=0; k--){
                    if(k==kolona-j-1){ a[x][y]=kont[i][j][k]; y++;}
                }
            }
            x++;
            y=0;
        }
    }
      if(smjer==SmjerKretanja::GoreDolje){
        int poz{0};
        a.resize(red);
        for(int i=0; i<red; i++) a[i].resize(ploha);
                for(int k=0; k<kolona; k++){
                   if(k<ploha) {a[x][y]=kont[1][0][k]; y++;}
                   else if(poz==0) {x++; y=0; a[x][y]=kont[1][0][k]; y++; poz=1;}
                    else a[x][y]=kont[1][0][k];
                }
                x++;
                y=0;
                for(int k=0; k<ploha; k++){
                  a[x][y]=kont[0][0][k]; 
                  y++;
                }
    }
      if(smjer==SmjerKretanja::DoljeGore){ 
        a.resize(red);
        for(int i=0; i<red; i++) a[i].resize(ploha);
        for(int i=red-1; i>=0; i--){
          a[x][y]=kont[1][i][kolona-1];
          y++;
          a[x][y]=kont[0][i][kolona-2];
          x++;
          y=0;
        }
    }
      if(smjer==SmjerKretanja::LijevoDesno){
        a.resize(kolona);
        for(int i=0; i<kolona; i++) a[i].resize(ploha);
        for(int i=0; i<kolona; i++){
            a[x][y]=kont[1][0][i];
            y++;
            a[x][y]=kont[0][1][i];
            x++;
            y=0;
        }
    }
   if(smjer==SmjerKretanja::DesnoLijevo){
        a.resize(kolona);
        for(int i=0; i<kolona; i++) a[i].resize(ploha);
        for(int i=kolona-1; i>=0; i--){
            a[x][y]=kont[0][0][i];
            y++;
            a[x][y]=kont[1][1][i];
            x++;
            y=0;
        }
    }
   return a;
}
int main (){
   try{
    int x{0}, y{0}, z{0}, smjer;
    mat a;
    std::cout <<"Unesite dimenzije (x y z): ";
    std::cin >>x>>y>>z;
    if(x<=0 ||  y<=0  || z<=0){std::cout <<"Neispravne dimenzije kontejnera!"<<std::endl; return 0;}
    a.resize(x);
    for(int i=0; i<x; i++){
        for(int j=0; j<y; j++){
            a[i].resize(y);
        }
    }
    for(int i=0; i<x; i++){
        for(int j=0; j<y; j++){
            for(int k=0; k<z; k++){
                a[i][j].resize(z);
            }
        }
    }
    std::cout <<"Unesite elemente kontejnera: "<<std::endl;
    for(int i=0; i<x; i++){
        for(int j=0; j<y; j++){
            for(int k=0; k<z; k++){
               std::cin >>a[i][j][k]; 
            }
        }
    }
    std::cout <<"Unesite smjer kretanja [0 - 5]: ";
    std::cin >>smjer;
    if(smjer>5 || smjer<0){std::cout <<"Smjer kretanja nije ispravan!"<<std::endl; return 0;}
    mat1 b;
    if(smjer==0 || smjer==1){
     b.resize(x);
     for(int i=0; i<x; i++) b[i].resize(y);
    }
    if(smjer==2 || smjer==3){
        b.resize(y);
        for(int i=0; i<y; i++) b[i].resize(x);
    }
    if(smjer==4 || smjer==5){
        b.resize(z);
        for(int i=0; i<z; i++) b[i].resize(x);
    }
    b=IzdvojiDijagonale3D<mat1>(a, (SmjerKretanja)smjer);
    if(smjer==(int)SmjerKretanja::NaprijedNazad){
        std::cout <<"NaprijedNazad: "<<std::endl;
        for(int i=0; i<x; i++){
            for(int j=0; j<y; j++){
                std::cout <<std::setw(4)<<std::right<<b[i][j];
            }
            std::cout <<std::endl;
        }
    }
    if(smjer==(int)SmjerKretanja::NazadNaprijed){
        std::cout <<"NazadNaprijed: "<<std::endl;
        for(int i=0; i<x; i++){
            for(int j=0; j<y; j++){
                std::cout <<std::setw(4)<<std::right<<b[i][j];
            }
            std::cout <<std::endl;
        }
    }
    if(smjer==(int)SmjerKretanja::GoreDolje){
        std::cout <<"GoreDolje: "<<std::endl;
        for(int i=0; i<y; i++){
            for(int j=0; j<x; j++){
                std::cout <<std::setw(4)<<std::right<<b[i][j];
            }
            std::cout <<std::endl;
        }
    }
    if(smjer==(int)SmjerKretanja::DoljeGore){
        std::cout <<"DoljeGore: "<<std::endl;
        for(int i=0; i<y; i++){
            for(int j=0; j<x; j++){
                std::cout <<std::setw(4)<<std::right<<b[i][j];
            }
            std::cout <<std::endl;
        }
    }
    if(smjer==(int)SmjerKretanja::LijevoDesno){
        std::cout <<"LijevoDesno: "<<std::endl;
        for(int i=0; i<z; i++){
            for(int j=0; j<x; j++){
                std::cout<<std::setw(4)<<std::right<<b[i][j];
            }
            std::cout <<std::endl;
        }
    }
    if(smjer==(int)SmjerKretanja::DesnoLijevo){
        std::cout <<"DesnoLijevo: "<<std::endl;
        for(int i=0; i<z; i++){
            for(int j=0; j<x; j++){
                std::cout <<std::setw(4)<<std::right<<b[i][j];
            }
            std::cout <<std::endl;
        }
    }
   }
   catch(std::domain_error izuzetak){
       std::cout <<izuzetak.what();
   }
	return 0;
}