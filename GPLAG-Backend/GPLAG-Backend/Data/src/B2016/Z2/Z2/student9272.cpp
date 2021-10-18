#include <iostream>
#include <deque>
#include <vector>
#include <type_traits>
#include <iomanip>
#include <stdexcept>
using std::cout;
using std::cin;
using std::deque;
using std::vector;
using std::endl;
enum class SmjerKretanja { NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo};
typedef deque<deque<int>> Matrica;
void IspisiMatricu (Matrica m){
   for (deque<int> red : m){
cout << " ";
      for(int x : red) cout  << std::setw(3) <<  x << " ";
      cout << std::endl;
   }
}

template <typename Kockica>
auto IzdvojiDijagonale3D(Kockica rubick, SmjerKretanja smjer) -> typename std::remove_reference<decltype(rubick.at(0))>::type {

    typename std::remove_reference<decltype(rubick.at(0))>::type Matrica, NazNaprijed, GorDolje, DoljGore, LijevDesno, DesnLijevo, NapNazad;
NazNaprijed.resize(rubick.size());
GorDolje.resize(rubick.at(0).size());
DesnLijevo.resize(rubick.at(0).at(0).size());
NapNazad.resize(rubick.size());
DoljGore.resize(rubick.at(0).size());
LijevDesno.resize(rubick.at(0).at(0).size());
int w,r,t;
w=rubick.size();
r=rubick.at(0).size();
t=rubick.at(0).at(0).size();
if (w==0) return Matrica;
for (int i(0); i<w-1; i++){
    if (rubick.at(i).size()!=rubick.at(i+1).size()) throw std::domain_error("Plohe nemaju isti broj redova");
}
for (int i(0); i<w-1; i++){
    for (int j(0); j<rubick.at(i).size()-1; j++){
        if (rubick.at(i).at(j).size()!=rubick.at(i).at(j+1).size() 
        || rubick.at(i).at(j).size()!=rubick.at(i+1).at(j).size() 
        || rubick.at(i).at(i).size()!=rubick.at(i+1).at(i+1).size()) throw std::range_error("Redovi nemaju isti broj elemenata");
    }
}


int brojac1(0);
    int brojac2(0);
    int harry(0);

    for (int i(0); i<rubick.size(); i++){

        for (int j(0); j<rubick.at(i).size(); j++){
            
            for (int k(0); k<rubick.at(i).at(j).size(); k++){
                if (j==k) {

                brojac1++;
             //   NapNazad.at(harry).resize(brojac2+1);
               
              auto  x(rubick.at(i).at(j).at(k));
                brojac2++;
                    NapNazad.at(harry).push_back(x); }

            }
        } harry++; brojac2=0;
    }
    int brojac15(0);
    int brojac16(0);
    int brojac17(0);
    int zayn(0);
    for (int i=rubick.size()-1; i>=0; i--){
        for (int j(0); j<rubick.at(i).size(); j++){
            if (j!=0) brojac15++;
            for (int k(0); k<rubick.at(i).at(j).size(); k++){
                if (k==rubick.at(i).at(j).size()-1-brojac15) {

                brojac16++;
            //    NazNaprijed.at(zayn).resize(brojac17+1);
                auto  x(rubick.at(i).at(j).at(k));
                
                brojac17++;
                    NazNaprijed.at(zayn).push_back(x); }

            }
        } zayn++; brojac15=0;
    }
    int brojac3(0);
    int brojac4(0);
    int brojac5(0);

    for (int i(rubick.size()-1); i>=0; i--){
        int mgk(0);
        int geazy(0);
        for (int j(0); j<rubick.at(i).size(); j++){
            for (int k(0); k<rubick.at(i).at(j).size(); k++){
                if(i==rubick.size()-1 && k==0){ 
                auto  x(rubick.at(i).at(j).at(k));

                brojac4++;
         //       GorDolje.at(mgk).resize(brojac3+1);
                brojac3++;
                GorDolje.at(mgk).push_back(x);
                mgk++;
                }
            else if(i==rubick.size()-1-brojac5 && k==brojac5){
                    auto  x(rubick.at(i).at(j).at(k));

                brojac4++;
             //   GorDolje.at(geazy).resize(brojac3+1);
                brojac3++;
                GorDolje.at(geazy).push_back(x);
                geazy++;
                 }


            }
        }
        brojac5++;
    }
    int brojac6(0);
    int brojac7(0);
    int brojac8(0);

   for (int i(w-1); i>=0; i--){
        int geazy(0);
        int mgk(0);
        for (int j(r-1); j>=0; j--){
            for (int k(0); k<t; k++){
                if (i==w-1 && k==t-1){
                 auto  x(rubick.at(i).at(j).at(k));
                brojac6++;
            //    DoljGore.at(mgk).resize(brojac7+1);
                brojac7++;
                DoljGore.at(mgk).push_back(x);
                mgk++;
                }
                else if(i==w-1-brojac8 && k==t-brojac8-1){
                     auto  x(rubick.at(i).at(j).at(k));
                brojac6++;
             //   DoljGore.at(geazy).resize(brojac7+1);
                brojac7++;
                DoljGore.at(geazy).push_back(x);
                geazy++;
                 }
            }
        }
        brojac8++;
    }
    int brojac9(0);
    int brojac10(0);
    int brojac11(0);
    for (int i(0); i<rubick.size(); i++){
        int mgk(0);
        for (int j(0); j<rubick.at(i).size(); j++){
            for (int k=rubick.at(i).at(j).size()-1; k>=0; k--){
                if (i==0 && j==0){
                 auto  x(rubick.at(i).at(j).at(k));
                brojac9++;
             //   DesnLijevo.at(mgk).resize(brojac10+1);
                brojac10++;
                DesnLijevo.at(mgk).push_back(x);
                mgk++;
                }
               else if (i==brojac11 && j==brojac11) {
                     auto  x(rubick.at(i).at(j).at(k));
                brojac9++;
            //    DesnLijevo.at(mgk).resize(brojac10+1);
                brojac10++;
                DesnLijevo.at(mgk).push_back(x);
                mgk++;
                }
            }
        }  brojac11++;
    }
    int brojac12(0);
    int brojac13(0);
    int brojac14(0);
    for (int i=rubick.size()-1; i>=0; i--){
        int mgk(0);
        for (int j(0); j<rubick.at(i).size(); j++){
        //    for (int k=rubick.at(i).at(j).size()-1; k>=0; k--){
        for (int k(0); k<t; k++){
                if (i==rubick.size()-1 && j==0){
                 auto  x(rubick.at(i).at(j).at(k));
                brojac12++;
            //    LijevDesno.at(mgk).resize(brojac13+1);
                brojac13++;
                LijevDesno.at(mgk).push_back(x);
                mgk++;
                }
               else if (i==rubick.size()-1-brojac14 && j==brojac14) {
                     auto  x(rubick.at(i).at(j).at(k));
                brojac12++;
        //        LijevDesno.at(mgk).resize(brojac13+1);
                brojac13++;
                LijevDesno.at(mgk).push_back(x);
                mgk++;
                }
            }
        }  brojac14++;
    }
    if (smjer==SmjerKretanja(0)){  return NapNazad; }
    if (smjer==SmjerKretanja(1)){  return NazNaprijed;}
    if (smjer==SmjerKretanja(5)){  return DesnLijevo;}
    if (smjer==SmjerKretanja(4)){  return LijevDesno;}
    if (smjer==SmjerKretanja(2)){  return GorDolje;}
    if (smjer==SmjerKretanja(3)){  return DoljGore;}

    return NapNazad;
}


int main ()
{
     SmjerKretanja smjernica;
    cout << "Unesite dimenzije (x y z): ";
    int x,y,z;
    cin >> x >> y >> z;
    if(x<0 || y<0 || z<0){ cout <<"Neispravne dimenzije kontejnera!"; return 0; }
    cout << "Unesite elemente kontejnera:" << std::endl;
    vector<deque<deque<int>>> kont;
    kont.resize(x);
  for (int k(0); k<x; k++){
     for (int i(0); i<y; i++){
         kont[k].resize(y);
         for (int j(0); j<z; j++){
              kont[k][i].resize(z);
        }
    }
}
 for (int k(0); k<x; k++){
     for (int i(0); i<y; i++){
         for (int j(0); j<z; j++){
              int o;
              cin >> o;
              kont[k][i][j]=o;
        }
    }
}  Matrica Brankova_Kockica;
try{
 cout << "Unesite smjer kretanja [0 - 5]: ";    int  smjer;    cin >> smjer;   
 if (smjer<0||smjer>5) {cout << "Smjer kretanja nije ispravan!"<<endl; return 0; }
 if (smjer==0){ cout<<"NaprijedNazad: "<<endl; smjernica=SmjerKretanja(0);}
  else if (smjer==1){ cout<<"NazadNaprijed: "<<endl; smjernica=SmjerKretanja(1);  }
 else  if (smjer==2){ cout<<"GoreDolje: "<<endl; smjernica=SmjerKretanja(2); }
 else if (smjer==3) {cout<<"DoljeGore: "<<endl; smjernica=SmjerKretanja(3);}
 else if (smjer==4){cout<<"LijevoDesno: "<<endl; smjernica=SmjerKretanja(4);}
 else if (smjer==5){cout<<"DesnoLijevo: "<<endl; smjernica=SmjerKretanja(5);}
  Brankova_Kockica=IzdvojiDijagonale3D(kont,smjernica);
  IspisiMatricu(Brankova_Kockica);
}catch(std::domain_error izuzetak){
    cout << izuzetak.what()<<endl;
}catch(std::range_error jbg){
    cout <<  jbg.what() << endl;
}
	return 0;
}
