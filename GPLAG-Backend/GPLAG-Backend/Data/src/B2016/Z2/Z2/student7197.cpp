// B 16/17, Zadaća 2, Zadatak 2
//	Autotestovi by Enil Pajic (epajic1@etf.unsa.ba | @eon : etf.ba)
//	NAPOMENA: i javni ATo-vi su dio postavke!	
#include <iostream>
#include <vector>
#include <deque>
#include <stdexcept>
#include <iomanip>

enum class SmjerKretanja {NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo};
//IZDVAJA IZ 3D KONTEJNERA ODREDJENE DIJAGONALE, I SMJESTAU 2D MATRICU, U ZAVISNOSTI OD ZADANOG SMJERA
template <typename Tip>
auto IzdvojiDijagonale3D (Tip kont, SmjerKretanja smjer)->typename std::remove_reference<decltype(kont.at(0))>::type {
    typename std::remove_reference <decltype(kont.at(0))>::type mat;
    if (kont.size()==0) return mat;
    for (int i=0; i<kont.size()-1; i++){
        if (kont.at(i).size() != kont.at(i+1).size()) throw std::domain_error ("Plohe nemaju isti broj redova");
        for (int j=0; j<kont.at(i).size()-1; j++)
        if (kont.at(i).at(j).size() != kont.at(i).at(j+1).size()) throw std::domain_error ("Redovi nemaju isti broj elemenata");
    }
    for (int i=0; i<kont.size(); i++)
        for (int j=0; j<kont.at(i).size(); j++) {
            if (smjer==SmjerKretanja::NaprijedNazad || smjer==SmjerKretanja::NazadNaprijed)
                mat.resize(kont.size());
            else if (smjer==SmjerKretanja::DesnoLijevo || smjer==SmjerKretanja::LijevoDesno)
                mat.resize(kont.at(i).at(j).size());
            else mat.resize(kont.at(i).size());
        }
        
    for (int i=0; i<kont.size(); i++)
        for (int j=0; j<kont.at(i).size(); j++)
            for (int k=0; k<kont.at(i).at(j).size(); k++){
                if (smjer==SmjerKretanja::NaprijedNazad && j==k)
                    mat.at(i).push_back(kont.at(i).at(j).at(k));
                else if (smjer==SmjerKretanja::NazadNaprijed && j+k==kont.at(i).at(j).size()-1)
                    mat.at(i).push_back(kont.at(i).at(j).at(k));
                else if (smjer==SmjerKretanja::DesnoLijevo && i==j)
                    mat.at(k).push_back(kont.at(i).at(j).at(k));
                else if (smjer==SmjerKretanja::LijevoDesno && i+j==kont.size()-1)
                    mat.at(k).push_back(kont.at(i).at(j).at(k));
                else if (smjer==SmjerKretanja::GoreDolje && i+k==kont.size()-1)
                    mat.at(j).push_back(kont.at(i).at(j).at(k));
                else if (smjer==SmjerKretanja::DoljeGore && i+kont.at(i).at(j).size()==k+kont.size())
                    mat.at(j).push_back(kont.at(i).at(j).at(k));
            }


    if (smjer==SmjerKretanja::NazadNaprijed || smjer==SmjerKretanja::DesnoLijevo || smjer==SmjerKretanja::DoljeGore)
        for (int i=0; i<mat.size()/2; i++){
            auto temp=mat.at(i);
            mat.at(i)=mat.at(mat.size()-1-i);
            mat.at(mat.size()-1-i)=temp;
        }
    if (smjer==SmjerKretanja::LijevoDesno || smjer==SmjerKretanja::GoreDolje || smjer==SmjerKretanja::DoljeGore)
        for (int i=0; i<mat.size(); i++)
            for (int j=0; j<mat.at(i).size()/2; j++){
                auto temp=mat.at(i).at(j);
                mat.at(i).at(j)=mat.at(i).at(mat.at(i).size()-1-j);
                mat.at(i).at(mat.at(i).size()-1-j)=temp;
            }
    return mat;
}

//STRING, KOJI SMIJER KRETANJA SE TRAZI
std::string Koji_je_smjer (int s,SmjerKretanja &gdje) {
    std::string smjer="";
    if (s==0) {smjer="NaprijedNazad: \n"; gdje=SmjerKretanja::NaprijedNazad;}
    else if (s==1) {smjer="NazadNaprijed: \n"; gdje=SmjerKretanja::NazadNaprijed;}
    else if (s==2) {smjer="GoreDolje: \n"; gdje=SmjerKretanja::GoreDolje;}
    else if (s==3) {smjer="DoljeGore: \n"; gdje=SmjerKretanja::DoljeGore;}
    else if (s==4) {smjer="LijevoDesno: \n"; gdje=SmjerKretanja::LijevoDesno;}
    else if (s==5) {smjer="DesnoLijevo: \n"; gdje=SmjerKretanja::DesnoLijevo;}
    return smjer;
}
//UNOS ELEMENATA KONTEJNERA
std::vector<std::deque<std::deque<int>>> Unos_kontejnera (int x, int y, int z) {
    std::vector<std::deque<std::deque<int>>> kont;
    int broj;
    kont.resize(x);
    for (int i=0; i<x; i++)
        for (int j=0; j<y; j++) {
            kont.at(i).resize(y);
            for (int k=0; k<z; k++){
                std::cin>>broj;
                kont.at(i).at(j).push_back(broj);
            }
        }
    return kont;
}
int main ()
{
    try {
        int x,y,z;
        std::cout<<"Unesite dimenzije (x y z): ";
        std::cin>>x>>y>>z;
        if (x<0 || y<0 || z<0) {
            std::cout<<"Neispravne dimenzije kontejnera!\n";
            return 1;
        }
        std::cout<<"Unesite elemente kontejnera: \n";
        auto kont=Unos_kontejnera(x,y,z);
        int smjer_br;
        std::cout<<"Unesite smjer kretanja [0 - 5]: ";
        std::cin>>smjer_br;
        if (smjer_br!=5 && smjer_br!=4 && smjer_br!=3 && smjer_br!=2 && smjer_br!=1 && smjer_br!=0) {
            std::cout<<"Smjer kretanja nije ispravan!\n";
            return 1;
        }
        SmjerKretanja smjer;
        auto s=Koji_je_smjer(smjer_br,smjer);
        std::cout<<s;
        auto mat=IzdvojiDijagonale3D(kont,smjer);
        for (int i=0; i<mat.size(); i++){
            for (int j=0; j<mat.at(i).size(); j++)
                std::cout<<std::setw(4)<<mat.at(i).at(j);
            std::cout<<std::endl;
        }
    }
    catch (std::domain_error a){
        std::cout<<a.what()<<std::endl;
    }
	return 0;
}