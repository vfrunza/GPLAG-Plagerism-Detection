// B 16/17, Zadaća 2, Zadatak 2
//	Autotestovi by Enil Pajic (epajic1@etf.unsa.ba | @eon : etf.bagg)
//	NAPOMENA: i javni ATo-vi su dio postavke!	
#include <iostream>
#include <type_traits>
#include <vector>
#include <iomanip>
#include <deque> 
#include <stdexcept>

enum class SmjerKretanja {
    NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
};

int min(int a, int b){if(a<b)return a;return b;}

template<typename tip>
    auto IzdvojiDijagonale3D(tip kont, SmjerKretanja smjer)->typename std::remove_reference<decltype(kont.at(0))>::type{
        int n=kont.size(), m=0, p=0;
        if(n!=0)m=kont.at(0).size();
        if(m!=0)p=kont.at(0).at(0).size();
        for(int i=0;i<n;i++){
            for(int j=0;j<kont.at(i).size();j++){
                if(kont.at(i).at(j).size()!=p)throw std::domain_error("Redovi nemaju isti broj elemenata");
            }
        }
        for(int i=0;i<n;i++){
            if(kont.at(i).size()!=m)throw std::domain_error("Plohe nemaju isti broj redova");
        }
        typename std::remove_reference<decltype(kont.at(0))>::type rjes;
        if(m==0 || p==0)return rjes;
        bool negn, negm, negp, gn=false, gm=false, gp=false;
        int g, mini;
        if(smjer==SmjerKretanja::NaprijedNazad){
            g=n;mini=min(m, p);negn=false;negm=false;negp=false;gn=true;
        }
        if(smjer==SmjerKretanja::NazadNaprijed){
            g=n;mini=min(m, p);negn=true;negm=false;negp=true;gn=true;
        }
        if(smjer==SmjerKretanja::DesnoLijevo){
            g=p;mini=min(m, n);negn=false;negm=false;negp=true;gp=true;
        }
        if(smjer==SmjerKretanja::LijevoDesno){
            g=p;mini=min(m, n);negn=true;negm=false;negp=false;gp=true;
        }
        if(smjer==SmjerKretanja::GoreDolje){
            g=m;mini=min(n, p);negn=true;negm=false;negp=false;gm=true;
        }
        if(smjer==SmjerKretanja::DoljeGore){
            g=m;mini=min(n, p);negn=true;negm=true;negp=true;gm=true;
        }
        for(int i=0;i<g;i++){
            int x, y, z;
            rjes.push_back(typename std::remove_reference<decltype(kont.at(0).at(0))>::type {});
            for(int j=0;j<mini;j++){
                if(gn){
                    if(negn)x=n-i-1; else x=i;
                    if(negm)y=m-j-1; else y=j;
                    if(negp)z=p-j-1; else z=j;
                }
                if(gm){
                    if(negn)x=n-j-1; else x=j;
                    if(negm)y=m-i-1; else y=i;
                    if(negp)z=p-j-1; else z=j;
                }
                if(gp){
                    if(negn)x=n-j-1; else x=j;
                    if(negm)y=m-j-1; else y=j;
                    if(negp)z=p-i-1; else z=i;
                }
                rjes.at(i).push_back(kont.at(x).at(y).at(z));
            }
        }
        return rjes;
    }

int main ()
{
    std::vector<SmjerKretanja> niz={SmjerKretanja::NaprijedNazad, SmjerKretanja::NazadNaprijed, SmjerKretanja::GoreDolje, SmjerKretanja::DoljeGore, SmjerKretanja::LijevoDesno, SmjerKretanja::DesnoLijevo};
    std::vector<std::string> ss={"NaprijedNazad", "NazadNaprijed", "GoreDolje", "DoljeGore", "LijevoDesno", "DesnoLijevo"};
    
        std::cout<<"Unesite dimenzije (x y z): ";
        int n, m, p;
        std::cin>>n>>m>>p;
        if(n<=0 || m<=0 || p<=0){
            std::cout<<"Neispravne dimenzije kontejnera!";
            return 0;
        }
        std::vector<std::vector<std::vector<int> > > v(n, std::vector<std::vector<int> > (m, std::vector<int> (p)));
        std::cout<<"Unesite elemente kontejnera: \n";
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                for(int k=0;k<p;k++)
                    std::cin>>v.at(i).at(j).at(k);
                    
        std::cout<<"Unesite smjer kretanja [0 - 5]: ";
        int r;
        std::cin>>r;
        if(r<0 || r>5){
            std::cout<<"Smjer kretanja nije ispravan!\n";
        return 1;
        }
        std::vector<std::vector<int> > rjes=IzdvojiDijagonale3D(v, niz.at(r));
        std::cout<<ss.at(r)<<": \n";
        for(auto i:rjes){
            for(auto j:i){
                std::cout<<std::setw(4)<<j;
            }
            std::cout<<"\n";
        }
	return 0;
}