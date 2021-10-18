#include <iostream>
#include <iomanip>
#include <vector>
#include <deque>
#include <type_traits>
#include <string>
#include <iterator>
typedef std::deque<std::deque<int>> Matrica;
enum class SmjeroviKretanja { NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo };
  template <typename Kontejner1>
auto IzdvojiDijagonale3D(Kontejner1 &kont,SmjeroviKretanja smjer)-> Matrica {
 Matrica  Rezultat(3,std::deque<int>(0,0));
    for(int g=0;g<6;g++) {
        if(SmjeroviKretanja(g)==smjer && g==0) {
    for(int i=0;i<2;i++) {
        for(int j=0;j<kont[i].size();j++) {
            Rezultat[i].push_back(kont[i][j][j]);
        }
    }
}
else {
      if(SmjeroviKretanja(g)==smjer && g==1) {
    for(int p=1;p>=0;p--) {
        for(int r=kont[p][std::abs(p-1)].size()-1;r>=0;r--) {
            Rezultat[std::abs(p-1)].push_back(kont[p][r][r]);
        }
    }
}
else {
    if(SmjeroviKretanja(g)==smjer && g==2) {
         for(int k=2;k<4;k++) {
        for(int l=0;l<kont[k][k].size();l++) {
                Rezultat[k-2].push_back(kont[k][l][l]);
        }
    }
    }
    else {
        if(SmjeroviKretanja(g)==smjer && g==3) {
         for(int k=3;k>=2;k--) {
        for(int l=kont[k][k].size()-1;l>=0;l--) {
                Rezultat[k-3].push_back(kont[k][l][l]);
        }
    }
    }
    else {
        if(SmjeroviKretanja(g)==smjer && g==4) {
             for(int h=4;h<6;h++) {
        for(int m=0;m<kont[h][h].size();m++) {
                Rezultat[h-4].push_back(kont[h][m][m]);
        }
    }
        }
        else {
             if(SmjeroviKretanja(g)==smjer && g==5) {
             for(int h=5;h>=4;h--) {
        for(int m=kont[h][h].size()-1;m>=0;m--) {
                Rezultat[h-5].push_back(kont[h][m][m]);
        }
    }
        }
        }
    }
    }
}
}
}
return Rezultat;
}
int main ()
{
    std::cout<<"Unesite dimenzije (x y z): ";
    int x,y,z;
    std::cin>>x>>y>>z;
    if(x<0 || y<0 || z<0)  {
        std::cout<<"Neispravne dimenzije kontejnera!";
        return 0;
    }
    std::vector<std::deque<std::deque<int>>> v(x,std::deque<std::deque<int>>(y));
    int n;
    std::cout<<"Unesite elemente kontejnera: ";
    for(int i=0;i<x;i++) {
        for(int j=0;j<y;j++) {
            for(int k=0;k<z;k++) {
                std::cin>>n;
                v[i][j].push_back(n);
        }
    }
    }
    std::cout<<std::endl<<"Unesite smjer kretanja [0 - 5]: ";
    SmjeroviKretanja kretanje;
    int d(0);
    std::cin>>d;
    if(d<0 || d>5) { 
    std::cout<<"Smjer kretanja nije ispravan!"<<std::endl;
    }
    else {
    kretanje=SmjeroviKretanja(d);
      switch(d) {
          case 0:
          std::cout<<"NaprijedNazad: "<<std::endl;
          break;
          case 1:
          std::cout<<"NazadNaprijed: "<<std::endl;
          break;
          case 2:
          std::cout<<"GoreDolje: "<<std::endl;
          break;
          case 3:
          std::cout<<"DoljeGore: "<<std::endl;
          break;
           case 4:
          std::cout<<"LijevoDesno: "<<std::endl;
          break;
           case 5:
          std::cout<<"DesnoLijevo: "<<std::endl;
          break;
      }
auto Dijagonale(IzdvojiDijagonale3D(v,kretanje));
 std::deque<int>::iterator it;
for(int g=0;g<Dijagonale.size();g++) {
    it=Dijagonale[g].begin();
    for(int h=0;h<Dijagonale[g].size();h++) {
        if(*it!=0) {
        std::cout<<std::setw(4)<<*it++;
    }
    }
    std::cout<<std::endl;
    }
    std::cout<<std::endl;
    }
	return 0;
}