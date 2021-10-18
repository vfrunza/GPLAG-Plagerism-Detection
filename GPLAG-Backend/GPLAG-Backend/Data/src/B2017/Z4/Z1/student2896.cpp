#include <iostream>
#include <stdexcept>
#include <tuple>
#include <cmath>
#include <vector>
#include <memory>
#include <algorithm>
using namespace std;
const double PI=4*atan(1);
class Kugla
{
     double x,y,z,r;
     static void TestPoluprecnika(double poluprecnik) {
          if(poluprecnik<0) throw domain_error("Ilegalan poluprecnik");
     }
public:
     explicit Kugla (double r=0) {
          TestPoluprecnika(r);
          x=0,y=0,z=0,Kugla::r=r;
     }
     Kugla (double x, double y, double z, double r=0) {
          TestPoluprecnika(r);
          Kugla::x=x,Kugla::y=y,Kugla::z=z,Kugla::r=r;
     }
     explicit Kugla (const tuple<double, double, double> &centar, double r=0) {
          TestPoluprecnika(r);
          x=get<0>(centar),y=get<1>(centar),z=get<2>(centar),Kugla::r=r;
     }
     double DajX() const {
          return x;
     }
     double DajY() const {
          return y;
     }
     double DajZ() const {
          return z;
     }
     tuple<double, double, double> DajCentar() const {
          return make_tuple(x,y,z);
     }
     double DajPoluprecnik() const {
          return r;
     }
     double DajPovrsinu() const {
          return 4*r*r*PI;
     }
     double DajZapreminu() const {
          return (4./3)*PI*r*r*r;
     }
     Kugla &PostaviX (double x) {
          Kugla::x=x;
          return *this;
     }
     Kugla &PostaviY (double y) {
          Kugla::y=y;
          return *this;
     }
     Kugla &PostaviZ (double z) {
          Kugla::z=z;
          return *this;
     }
     Kugla &PostaviCentar (double x, double y, double z) {
          Kugla::x=x,Kugla::y=y,Kugla::z=z;
          return *this;
     }
     Kugla &PostaviCentar (const tuple<double, double, double> &centar) {
          x=get<0>(centar),y=get<1>(centar),z=get<2>(centar);
          return *this;
     }
     Kugla &PostaviPoluprecnik (double r) {
          TestPoluprecnika(r);
          Kugla::r=r;
          return *this;
     }
     void Ispisi () const {
          cout<<"{("<<DajX()<<","<<DajY()<<","<<DajZ()<<"),"<<DajPoluprecnik()<<"}"<<endl;
     }
     void Transliraj (double delta_x, double delta_y, double delta_z) {
          x+=delta_x;
          y+=delta_y;
          z+=delta_z;
     }
     friend bool DaLiSuIdenticne (const Kugla &k1, const Kugla &k2) {
          return abs(k1.x-k2.x)<10e-10*(abs(k1.x)+abs(k2.x)) && abs(k1.y-k2.y)<10e-10*(abs(k1.y)+abs(k2.y)) &&
                 abs(k1.z-k2.z)<10e-10*(abs(k1.z)+abs(k2.z)) && abs(k1.r-k2.r)<10e-10*(abs(k1.r)+abs(k2.r));
     }
     friend bool DaLiSuPodudarne (const Kugla &k1, const Kugla &k2) {
          return abs(k1.r-k2.r)<10e-10*(abs(k1.r)+abs(k2.r));
     }
     friend bool DaLiSuKoncentricne (const Kugla &k1, const Kugla &k2) {
          return abs(k1.x-k2.x)<10e-10*(abs(k1.x)+abs(k2.x)) && abs(k1.y-k2.y)<10e-10*(abs(k1.y)+abs(k2.y)) &&
                 abs(k1.z-k2.z)<10e-10*(abs(k1.z)+abs(k2.z));
     }
     friend bool DaLiSeDodirujuIzvana (const Kugla &k1, const Kugla &k2) {
          return abs(sqrt((k1.x-k2.x)*(k1.x-k2.x)+(k1.y-k2.y)*(k1.y-k2.y)+(k1.z-k2.z)*(k1.z-k2.z))-abs(k1.r+k2.r))<
                 10e-10*(abs(sqrt((k1.x-k2.x)*(k1.x-k2.x)+(k1.y-k2.y)*(k1.y-k2.y)+(k1.z-k2.z)*(k1.z-k2.z)))+abs(k1.r+k2.r));
     }
     friend bool DaLiSeDodirujuIznutra (const Kugla &k1, const Kugla &k2) {
          return abs(sqrt((k1.x-k2.x)*(k1.x-k2.x)+(k1.y-k2.y)*(k1.y-k2.y)+(k1.z-k2.z)*(k1.z-k2.z))-abs(k1.r-k2.r))<
                 10e-10*(abs(sqrt((k1.x-k2.x)*(k1.x-k2.x)+(k1.y-k2.y)*(k1.y-k2.y)+(k1.z-k2.z)*(k1.z-k2.z)))+abs(k1.r-k2.r));
     }
     friend bool DaLiSePreklapaju (const Kugla &k1, const Kugla &k2) {
          return DaLiSeSijeku(k1,k2);
     }
     friend bool DaLiSeSijeku (const Kugla &k1, const Kugla &k2) {
          return sqrt((k1.x-k2.x)*(k1.x-k2.x)+(k1.y-k2.y)*(k1.y-k2.y)+(k1.z-k2.z)*(k1.z-k2.z))<k1.r+k2.r
                 && sqrt((k1.x-k2.x)*(k1.x-k2.x)+(k1.y-k2.y)*(k1.y-k2.y)+(k1.z-k2.z)*(k1.z-k2.z))>abs(k1.r-k2.r);
     }
     bool DaLiSadrzi (const Kugla &k) const {
          return sqrt((x-k.x)*(x-k.x)+(y-k.y)*(y-k.y)+(z-k.z)*(z-k.z))<r+k.r;
     }
     friend double RastojanjeCentara (const Kugla &k1, const Kugla &k2) {
          return sqrt((k1.x-k2.x)*(k1.x-k2.x)+(k1.y-k2.y)*(k1.y-k2.y)+(k1.z-k2.z)*(k1.z-k2.z));
     }
};
int main ()
{
     cout<<"Unesite broj kugla: ";
     int n=10;
     while(!(cin>>n) || n<=0) {
          cout<<"Neispravan broj kugli, unesite ponovo!\n";
          cin.clear();
          cin.ignore(10000,'\n');
     }
     vector<shared_ptr<Kugla>> kugle;
     for(int i=1; i<=n; i++) {
          cout<<"Unesite centar "<<i<<". kugle: ";
          tuple<double, double, double> centar;
          while(!(cin>>get<0>(centar)) || !(cin>>get<1>(centar)) || !(cin>>get<2>(centar))) {
               cout<<"Neispravan centar\n";
               cin.clear();
               cin.ignore(10000,'\n');
               cout<<"Unesite centar "<<i<<". kugle: ";
          }
          cout<<"Unesite poluprecnik "<<i<<". kugle: ";
          double poluprecnik=0;
          while(!(cin>>poluprecnik) || poluprecnik<0) {
               cout<<"Ilegalan poluprecnik\n";
               cin.clear();
               cin.ignore(10000,'\n');
               cout<<"Unesite centar "<<i<<". kugle: ";
               while(!(cin>>get<0>(centar)) || !(cin>>get<1>(centar)) || !(cin>>get<2>(centar))) {
                    cout<<"Neispravan centar\n";
                    cin.clear();
                    cin.ignore(10000,'\n');
                    cout<<"Unesite centar "<<i<<". kugle: ";
               }
               cout<<"Unesite poluprecnik "<<i<<". kugle: ";
          }
          Kugla kugla(centar,poluprecnik);
          try {
               shared_ptr<Kugla> tmp(new Kugla(kugla));
               kugle.push_back(tmp);
          } catch(...) {
               for(int i=0; i<kugle.size(); i++)
                    kugle[i]=nullptr;
               cout<<"Curenje";
          }
     }
     cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): ";
     tuple<double, double, double> translacija;
     while(!(cin>>get<0>(translacija)>>get<1>(translacija)>>get<2>(translacija))) {
          cout<<"Neispravni parametri translacije, unesite ponovo!\n";
          cin.clear();
          cin.ignore(10000,'\n');
     }
     cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: "<<endl;
     transform(kugle.begin(),kugle.end(),kugle.begin(),[translacija](shared_ptr<Kugla> a) {
          a->Transliraj(get<0>(translacija),get<1>(translacija),get<2>(translacija));
          return a;
     });
     sort(kugle.begin(),kugle.end(),[](const shared_ptr<Kugla> &a, const shared_ptr<Kugla> &b) {
          return a->DajZapreminu()<b->DajZapreminu();
     });
     for_each(kugle.begin(),kugle.end(),[](const shared_ptr<Kugla> &a) {
          a->Ispisi();
     });
     auto p(max_element(kugle.begin(),kugle.end(),[](const shared_ptr<Kugla> &a, const shared_ptr<Kugla> &b) {
          return a->DajPovrsinu()<b->DajPovrsinu();
     }));
     cout<<"Kugla sa najvecom povrsinom je: ";
     (*p)->Ispisi();
     bool presjek=false;
     int i=0;
     for_each(kugle.begin(),kugle.end(),[kugle,&presjek,&i](const shared_ptr<Kugla> &a) {
          i++;
          for_each(kugle.begin()+i,kugle.end(),[&](const shared_ptr<Kugla> &b) {
               if(DaLiSeSijeku(*b,*a)) {
                    presjek=true;
                    cout<<"Presjecaju se kugle: ";
                    a->Ispisi();
                    b->Ispisi();
               }

          });
     });
     if(presjek==false) cout<<"Ne postoje kugle koje se presjecaju!";
     return 0;
}
