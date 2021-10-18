#include <iostream>
#include <vector>
#include <deque>
#include <stdexcept>
#include <type_traits>
#include <iomanip>
enum class SmjerKretanja{
    NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
};
template <typename ah>
void resize(ah &kont, int n){
    typedef typename std::remove_reference<decltype(kont.at(0))>::type elem;
    elem tmp;
    for(int i = 0; i < n; i++) kont.push_back(tmp);
}
typedef std::vector<std::deque<std::deque<int> > > cudo;
template <typename eww>
auto IzdvojiDijagonale3D(eww kont, SmjerKretanja smjer) -> typename std::remove_reference<decltype(kont.at(0))>::type {
    std::vector<SmjerKretanja> v{SmjerKretanja::NaprijedNazad, SmjerKretanja::NazadNaprijed, SmjerKretanja::GoreDolje, SmjerKretanja::DoljeGore, SmjerKretanja::LijevoDesno, SmjerKretanja::DesnoLijevo};
    typedef typename std::remove_reference<decltype(kont.at(0))>::type xoxo;
    xoxo ret; bool start1(true); int illcry;
    for(int i = 0; i < kont.size(); i++)
        for(int j = 0; j < kont.at(i).size(); j++){
            if(start1){
                illcry = kont.at(i).at(j).size();
                start1 = false;
            }
            if(kont.at(i).at(j).size() != illcry)
                throw std::domain_error("Redovi nemaju isti broj elemenata");
        }   
    start1 = true;
        for(int i = 0; i < kont.size(); i++){
            if(start1){
                illcry = kont.at(i).size();
                start1 = false;
            }
            if( kont.at(i).size() != illcry)
                throw std::domain_error("Plohe nemaju isti broj redova");
        }
    if(kont.size() == 0 || kont.at(0).size() == 0 || kont.at(0).at(0).size() == 0) return ret;
    int x, y;
    if(smjer == v[0] || smjer == v[1]){x = kont.size(); y = kont.at(0).size();}
    else if(smjer == v[2] || smjer == v[3]){ x = kont.at(0).size(); y = kont.size();}
    else if(smjer == v[4] || smjer == v[5]){ x = kont.at(0).at(0).size(); y = kont.size();}
    int mode = int(smjer);
    resize(ret,x);
    //ret.resize(x);
    for(int i = 0; i < x; i++) resize(ret.at(i),y);// ret.at(i).resize(y);
    int xx(kont.size()), yy(kont.at(0).size()), zz(kont.at(0).at(0).size());
    for(int i = 0; i < xx; i++)
        for(int j = 0; j < yy; j++)
            for(int k = 0; k < zz; k++){
                if(mode == 0 && j == k)
                    ret.at(i).at(j) = kont.at(i).at(j).at(k);
                else if(mode == 1 && j + k == zz - 1)
                    ret.at(x-i-1).at(j) = kont.at(i).at(j).at(k);
                else if(mode == 5 && i == j)
                    ret.at(zz - k -1).at(i) = kont.at(i).at(j).at(k);//i + k
                else if(mode == 4 && i + j == xx - 1)
                    ret.at(k).at(xx-i-1) = kont.at(i).at(j).at(k);
                else if(mode == 2 && i + k == xx - 1)
                    ret.at(j).at(xx- i-1) = kont.at(i).at(j).at(k);
                else if(mode == 3 && i +zz-k-1== xx-1)
                    ret.at(yy-1-j).at(xx-1-i) = kont.at(i).at(j).at(k);
            }
    return ret;
}
int main ()
{
    std::vector<SmjerKretanja> v{SmjerKretanja::NaprijedNazad, SmjerKretanja::NazadNaprijed, SmjerKretanja::GoreDolje, SmjerKretanja::DoljeGore, SmjerKretanja::LijevoDesno, SmjerKretanja::DesnoLijevo};
    cudo x;
    int xx(2), y(3), z(4);
    std::cout << "Unesite dimenzije (x y z): ";
    std::cin >> xx >> y >> z;
    if(xx < 0 || y < 0 || z < 0){
        std::cout << "Neispravne dimenzije kontejnera!";
        return 0;
    }
    x.resize(xx);
    std::cout << "Unesite elemente kontejnera: \n";
    for(int i = 0; i < xx; i++){
        x.at(i).resize(y);
        for(int j = 0; j < y; j++){
            x.at(i).at(j).resize(z);
            for(int k = 0; k < z; k++)
                std::cin >> x.at(i).at(j).at(k);
        }
    }
    std::cout << "Unesite smjer kretanja [0 - 5]: ";
    int n;
    std::cin >> n;
    if(n < 0 || n > 5){
        std::cout <<"Smjer kretanja nije ispravan!" << std::endl;
        return 0;
    }
    std::vector<std::string> str{"NaprijedNazad", "NazadNaprijed", "GoreDolje", "DoljeGore", "LijevoDesno", "DesnoLijevo"};
    SmjerKretanja smjer = v[n];
    try{
        auto blah = IzdvojiDijagonale3D(x, smjer);
        std::cout << str[n] << ": " << std::endl;
        for(int i = 0; i < blah.size(); i++){
            for(int j = 0; j < blah.at(i).size(); j++)
                std::cout << std::setw(4) <<  blah.at(i).at(j);
            std::cout << std::endl;
        }
    }catch(std::exception &err){
        std::cout << "Izuzetak: " << err.what(); 
    }
	return 0;
}