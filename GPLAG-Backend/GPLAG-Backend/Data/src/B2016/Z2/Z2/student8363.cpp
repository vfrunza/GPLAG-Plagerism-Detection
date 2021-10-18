// B 16/17, Zadaća 2, Zadatak 2
//	Autotestovi by Enil Pajic (epajic1@etf.unsa.ba | @eon : etf.ba)
//	NAPOMENA: i javeni ATo-vi su dio postavke!	
#include <iostream>
#include <stdexcept>
#include <type_traits>
#include <vector>
#include <deque>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
enum class SmjerKretanja{    
    NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo //tjesno mii Saarajevoo
};

template <typename T3D >
auto IzdvojiDijagonale3D(T3D kocka,SmjerKretanja smjer)->typename std::remove_reference<decltype(kocka.at(0))>::type{
    int y ;
    int x;
    int z  = kocka.size();
    if(z==0 )throw std::domain_error("Plohe nemaju isti broj redova");
    else{
    y = kocka.at(0).size();
    if(y==0)throw std::domain_error("Plohe nemaju isti broj redova");
    
     x  = kocka.at(0).at(0).size();
    for (int i = 0; i < z; i++) {
        if(kocka.at(i).size()!=y)throw std::domain_error("Plohe nemaju isti broj redova");
        for (auto e : kocka.at(i)) {
        if(e.size()!=x)throw std::domain_error("Plohe nemaju isti broj kolona");
    }
    }
    
    
    }
    typedef typename std::remove_reference<decltype(kocka.at(0))>::type DvaD;
    typedef typename std::remove_reference<decltype(kocka.at(0).at(0))>::type JedanD;
    
    DvaD izlaz;
    int a = static_cast<int>(smjer);
    if(!a){
        for (int i = 0; i < z; i++) {
            JedanD tmp;
            for (int j = 0; j < y && j<x; j++) {
                tmp.push_back(kocka.at(i).at(j).at(j));
            }
            izlaz.push_back(tmp);
        }
    }
    else if(a==1){
        for (int i = z-1; i >=0; i--) {
            JedanD tmp;
            for(int j=0;j<y && j<x;j++){
                tmp.push_back(kocka.at(i).at(j).at(x-j-1));
            }
            izlaz.push_back(tmp);
        }
    }
    else if(a==2){
        for(int j=0;j<y;j++){
            
            JedanD tmp;
        for(int i=z-1;i>=0 ;i--){
                for(int k=0;k<x;k++){
                    if(k==z-i-1){
                      tmp.push_back(kocka.at(i).at(j).at(k));
                      break;
                    }
                }
            }
                izlaz.push_back(tmp);
        }
    }
    else if(a==3){
        for(int j=y-1;j>=0;j--){
            JedanD tmp;
            for(int k=z-1;k>=0;k--){
            for(int i=x-1;i>=0;i--)
            if(x-i-1==z-k-1)
            tmp.push_back(kocka.at(k).at(j).at(i));
            }
            izlaz.push_back(tmp);
        }
    }
    else if(a==4){
        for (int i = 0; i < x; i++) {
            JedanD tmp;
            for(int k=z-1;k>=0 && z-k-1<y;k--)
                for(int j=0;j<y && j<z;j++){
                    if(z-k-1==j){tmp.push_back(kocka.at(k).at(j).at(i));break;}
                }
            izlaz.push_back(tmp);
        }
    }
    else if(a==5){
        for (int i = x-1; i >=0; i--) {
            JedanD tmp;
            for(int k=0;k<z && k<y;k++){
                for(int j=0;j<y && j<z;j++)
                if(k==j){
                    tmp.push_back(kocka.at(k).at(j).at(i));
                    break;
                }
            }
            izlaz.push_back(tmp);
        }
    }
    
    
    return izlaz;
}
int main ()
{

    typedef std::vector<int> OneD;
    typedef std::vector<OneD> TwoD;
    typedef std::vector<TwoD> ThreeD;
    cout<<"Unesite dimenzije (x y z): ";
    int x,y,z;
    int a=0;
    ThreeD test;
    cin>>z>>y>>x;
    if(z<=0 || y<=0 || x<=0){
        cout<<"Neispravne dimenzije kontejnera!"<<endl;
        return 0;
    }
    cout<<"Unesite elemente kontejnera: \n";
    for (int i = 0; i < z; i++) {
        TwoD twoD;
        for (int j = 0; j < y; j++) {
            OneD oneD;
            for (int k = 0; k < x; k++) {
                int b;
                cin>>b;
                oneD.push_back(b);
            }
            twoD.push_back(oneD);
        }
        test.push_back(twoD);
    } 
    
    cout<<"Unesite smjer kretanja [0 - 5]: ";
    cin>>a;
    if(!(a>=0 && a<6)){
        cout<<"Smjer kretanja nije ispravan!\n";
        return 0;
    }
    
    std::string asd[7]{
        "NaprijedNazad","NazadNaprijed","GoreDolje","DoljeGore","LijevoDesno","DesnoLijevo"
    };
    try{
    TwoD rez= IzdvojiDijagonale3D(test,static_cast<SmjerKretanja>(a));
    std::cout << asd[a]<<": " << std::endl;
    for (auto e : rez){
        for (auto i : e) {
            cout<<std::setw(4)<<i;
        }
        cout<<endl;
    }}
catch(std::domain_error e){
    cout<<e.what()<<endl;
}
	return 0;
}