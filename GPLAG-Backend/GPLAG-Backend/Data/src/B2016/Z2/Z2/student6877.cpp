// B 16/17, Zadaća 2, Zadatak 2
//	Autotestovi by Enil Pajic (epajic1@etf.unsa.ba | @eon : etf.ba)
//	NAPOMENA: i javni ATo-vi su dio postavke!	

#include <iostream>
#include <deque>
#include <vector>
#include <string>
#include <iomanip>

typedef std::deque<std::deque<std::vector<short int>>> kontejner;
typedef std::deque<std::deque<short int>> matrica;
typedef std::deque<short int> Dek;

enum class SmjerKretanja {NaprijedNazad = 0, NazadNaprijed = 1, GoreDolje = 2, DoljeGore = 3, LijevoDesno = 4, DesnoLijevo = 5};

matrica NaprijedNaz (kontejner kont){
    int a(kont.size());
    int b(kont[0].size());
    int c(kont[0][0].size());
    int sirina;
    if(b<c) sirina=b;
    else sirina=c;
    matrica NapNaz(a, Dek (sirina));
    for(int i=0;i<a;i++){
        for(int j=0;j<sirina;j++){
            NapNaz[i][j]=kont[i][j][j];
        }
    }
    return NapNaz;
}

matrica NazadNap (kontejner kont){
    int a(kont.size());
    int b(kont[0].size());
    int c(kont[0][0].size());
    int sirina;
    if(b<c) sirina=b;
    else sirina=c;
    matrica NazNap(a, Dek (sirina));
    int pom(0);
    int k(sirina);
    for(int i=a-1;i>=0;i--){
        for(int j=0;j<sirina;j++){
            NazNap[pom][j]=kont[i][j][k-j];
           
        }
        pom++;
    }
    return NazNap;
}

matrica GoreD(kontejner kont){
    int a(kont.size());
    int b(kont[0].size());
    int c(kont[0][0].size());
    int sirina;
    if(a<c) sirina=a;
    else sirina=c;
    matrica GD(b, Dek (sirina));
    int i(a-1);
    for(int j=0;j<b;j++){
        for(int k=0;k<sirina;k++){
            GD[j][k]=kont[i-k][j][k];
        }
    }
    return GD;
}


matrica DoljeG(kontejner kont){
    int a(kont.size());
    int b(kont[0].size());
    int c(kont[0][0].size());
    int sirina;
    if(a<c) sirina=a;
    else sirina=c;
    matrica DG(b, Dek (sirina));
   
    for(int j=0;j<b;j++){
        for(int k=0;k<sirina;k++){
            DG[j][k]=kont[sirina-1-k][b-j-1][c-k-1];
        }
    }
    return DG;
}

matrica LijevoD (kontejner kont){
    int a(kont.size());
    int b(kont[0].size());
    int c(kont[0][0].size());
    int sirina;
    if(a<b) sirina=a;
    else sirina=b;
    int i(sirina-1);
    matrica LD (c, Dek (sirina));
    for(int k=0;k<c;k++){
        for(int j=0;j<sirina;j++){
            LD[k][j]=kont[i-j][j][k];
        }
    }
       
    return LD;
}

matrica DesnoL(kontejner kont){
    int a(kont.size());
    int b(kont[0].size());
    int c(kont[0][0].size());
    int sirina;
    if(a<b) sirina=a;
    else sirina=b;
    int pom(0);
    matrica DL(c, Dek(sirina));
    for(int k=c-1;k>=0;k--){
        for(int j=0;j<sirina;j++){
            DL[pom][j]=kont[j][j][k];
            }
        pom++;
    }
    return DL;
}




/*template <typename NekiTip> */
matrica IzdvojiDijagonale3D (kontejner kont, SmjerKretanja smjer){
    matrica D2kont;

    if (smjer==SmjerKretanja::NaprijedNazad) D2kont=NaprijedNaz(kont);
    else if (smjer==SmjerKretanja::NazadNaprijed) D2kont=NazadNap(kont);
    else if (smjer==SmjerKretanja::GoreDolje) D2kont=GoreD(kont);
    else if (smjer==SmjerKretanja::DoljeGore) D2kont=DoljeG(kont);
    else if (smjer==SmjerKretanja::LijevoDesno) D2kont=LijevoD(kont);  
    else if (smjer==SmjerKretanja::DesnoLijevo) D2kont=DesnoL(kont);
    
    
    return D2kont;

}


int main ()
{
    std::cout << "Unesite dimenzije (x y z): ";
    int x,y,z;
    std::cin >> x >> y >> z;
    if(x<0 || y<0 || z<0) {std::cout<<"Neispravne dimenzije kontejnera!"<<std::endl; return 0;}
    std::cout <<"Unesite elemente kontejnera: "<<std::endl;
    kontejner kont; 
    kont.resize(x);
    for(int i=0;i<x;i++){
        kont[i].resize(y);
            for(int j=0;j<y;j++){
            kont[i][j].resize(z);
        }
    }
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            for(int k=0;k<z;k++){
                std::cin >> kont[i][j][k];
            }
        }
    }
    
    std::cout <<"Unesite smjer kretanja [0 - 5]: ";
    int smjer;
    std::cin >> smjer;
    matrica nova;
    if (smjer==0) { std::cout<<"NaprijedNazad: "<<std::endl;       nova=IzdvojiDijagonale3D(kont, SmjerKretanja::NaprijedNazad) ; }
    else if (smjer==1) { std::cout<<"NazadNaprijed: "<<std::endl;  nova=IzdvojiDijagonale3D(kont, SmjerKretanja::NazadNaprijed); }
    else if (smjer==2) { std::cout<<"GoreDolje: "<<std::endl;      nova=IzdvojiDijagonale3D(kont, SmjerKretanja::GoreDolje); }
    else if (smjer==3) { std::cout<<"DoljeGore: "<<std::endl;      nova=IzdvojiDijagonale3D(kont, SmjerKretanja::DoljeGore); }
    else if (smjer==4) { std::cout<<"LijevoDesno: "<<std::endl;    nova=IzdvojiDijagonale3D(kont, SmjerKretanja::LijevoDesno); }
    else if (smjer==5) { std::cout<<"DesnoLijevo: "<<std::endl;    nova=IzdvojiDijagonale3D(kont, SmjerKretanja::DesnoLijevo); }
    else {std::cout<<"Smjer kretanja nije ispravan!"<<std::endl; return 0; }
    for(int i=0;i<nova.size();i++){
        for(int j=0;j<nova[1].size();j++){
            std::cout<<std::setw(4)<<nova[i][j];
        }
        std::cout<<std::endl;
    }
    
	return 0;
}