#include <iostream>
#include <stdexcept>
#include <tuple>
#include <cmath>
#include <vector>
#include <memory>
#include <algorithm>
using namespace std;
const double PI=4*atan(1);
class NepreklapajucaKugla
{
     double x,y,z,r;
     NepreklapajucaKugla *veza=nullptr;
     static NepreklapajucaKugla *prethodni;
     static void TestPoluprecnika(double poluprecnik) {
          if(poluprecnik<0) throw domain_error("Ilegalan poluprecnik");
     } static void TestPreklapanja(const NepreklapajucaKugla &n) {
          throw logic_error("Nedozvoljeno preklapanje");
     }

public:
     explicit NepreklapajucaKugla (double r=0) {
          TestPoluprecnika(r);
          x=0,y=0,z=0,NepreklapajucaKugla::r=r;
     }
     NepreklapajucaKugla (double x, double y, double z, double r=0) {
          TestPoluprecnika(r);
          NepreklapajucaKugla::x=x,NepreklapajucaKugla::y=y,NepreklapajucaKugla::z=z,NepreklapajucaKugla::r=r;
     }
     explicit NepreklapajucaKugla (const tuple<double, double, double> &centar, double r=0) {
          TestPoluprecnika(r);
          x=get<0>(centar),y=get<1>(centar),z=get<2>(centar),NepreklapajucaKugla::r=r;
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
     NepreklapajucaKugla &PostaviX (double x) {
          NepreklapajucaKugla::x=x;
          return *this;
     }
     NepreklapajucaKugla &PostaviY (double y) {
          NepreklapajucaKugla::y=y;
          return *this;
     }
     NepreklapajucaKugla &PostaviZ (double z) {
          NepreklapajucaKugla::z=z;
          return *this;
     }
     NepreklapajucaKugla &PostaviCentar (double x, double y, double z) {
          NepreklapajucaKugla::x=x,NepreklapajucaKugla::y=y,NepreklapajucaKugla::z=z;
          return *this;
     }
     NepreklapajucaKugla &PostaviCentar (const tuple<double, double, double> &centar) {
          x=get<0>(centar),y=get<1>(centar),z=get<2>(centar);
          return *this;
     }
     NepreklapajucaKugla &PostaviPoluprecnik (double r) {
          TestPoluprecnika(r);
          NepreklapajucaKugla::r=r;
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
     friend double RastojanjeCentara (const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2) {
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
     vector<shared_ptr<NepreklapajucaKugla>> kugle;
     for(int i=1; i<=n; i++) {
          cout<<"Unesite centar za "<<i<<". kuglu: ";
          tuple<double, double, double> centar;
          while(!(cin>>get<0>(centar)) || !(cin>>get<1>(centar)) || !(cin>>get<2>(centar))) {
               cout<<"Neispravan centar\n";
               cin.clear();
               cin.ignore(10000,'\n');
               cout<<"Unesite centar za "<<i<<". kuglu: ";
          }
          cout<<"Unesite poluprecnik: ";
          double poluprecnik=0;
          while(!(cin>>poluprecnik) || poluprecnik<0) {
               cout<<"Ilegalan poluprecnik\n";
               cin.clear();
               cin.ignore(10000,'\n');
               cout<<"Unesite centar za "<<i<<". kuglu: ";
               while(!(cin>>get<0>(centar)) || !(cin>>get<1>(centar)) || !(cin>>get<2>(centar))) {
                    cout<<"Neispravan centar\n";
                    cin.clear();
                    cin.ignore(10000,'\n');
                    cout<<"Unesite centar za "<<i<<". kuglu: ";
               }
               cout<<"Unesite poluprecnik ";
          }
          NepreklapajucaKugla kugla(centar,poluprecnik);
          try {
               shared_ptr<NepreklapajucaKugla> tmp(new NepreklapajucaKugla(kugla));
               kugle.push_back(tmp);
          } catch(...) {
               for(int i=0; i<kugle.size(); i++)
                    kugle[i]=nullptr;
               cout<<"Curenje";
          }
     }
     sort(kugle.begin(),kugle.end(),[](const shared_ptr<NepreklapajucaKugla> &a, const shared_ptr<NepreklapajucaKugla> &b) {
          return a->DajPovrsinu()<b->DajPovrsinu();
     });
     cout<<"\nKugle nakon obavljenog sortiranja: \n";
     for_each(kugle.begin(),kugle.end(),[](const shared_ptr<NepreklapajucaKugla> &a) {
          a->Ispisi();
     });
     return 0;
}
