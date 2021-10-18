/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <utility>
#include <cmath>
#include <stdexcept>
#include <vector>
#include <memory>
#include <algorithm>

typedef std::pair<double,double> Tacka;

int ProvjeriOrijentaciju(const Tacka &t1,const Tacka &t2,const Tacka &t3){
    double formula;
    formula=t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second);
    return formula;
}
bool DaLiSuJednaki(double x, double y) {
    double Eps = 0.0000000001;
 return (std::fabs(x - y) <= Eps * (std::fabs(x) + std::fabs(y)));
}
class Trougao{
    Tacka t1,t2,t3;
    friend int ProvjeriOrijentaciju(const Tacka &t1,const Tacka &t2,const Tacka &t3) ;
    friend double Kosinusna(double a,double b,double c);
    friend bool DaLiSuJednaki(double x, double y);
    public:
    Trougao(const Tacka &t1,const Tacka &t2,const Tacka &t3);
    void Postavi(const Tacka &t1,const Tacka &t2,const Tacka &t3);
    void Postavi(int indeks,const Tacka &t);
    static int Orijentacija(const Tacka &t1,const Tacka &t2,const Tacka &t3);
    Tacka DajTjeme(int indeks) const{
         if(indeks<1 || indeks>3) throw std::range_error("Nekorektan indeks");
         if(indeks==1) return t1;
         if(indeks==2) return t2;
         return t3;
    }
    double DajStranicu(int indeks) const;
    double DajUgao(int indeks) const;
    Tacka DajCentar() const;
    double DajObim() const;
    double DajPovrsinu() const;
    bool DaLiJePozitivnoOrijentiran() const{
        if(ProvjeriOrijentaciju(t1,t2,t3)>0) return true;
        return false;
    }
    bool DaLiJeUnutra(const Tacka &t) const;
    void Ispisi() const{
        std::cout<<"(("<<t1.first<<","<<t1.second<<"),("<<t2.first<<","<<t2.second<<"),("<<t3.first<<","<<t3.second<<"))";
    }
    void Transliraj(double delta_x,double delta_y);
    void Centriraj(const Tacka &t);
    void Rotiraj(const Tacka &t,double ugao);
    void Skaliraj(const Tacka &t,double faktor);
    void Rotiraj(double ugao);
    void Skaliraj(double faktor);
    friend bool DaLiSuIdenticni(const Trougao &t1,const Trougao &t2);
    friend bool DaLiSuPodudarni(const Trougao &t1,const Trougao &t2);
    friend bool DaLiSuSlicni(const Trougao &t1,const Trougao &t2);
};

double Kosinusna(double a,double b,double c){
    double ugao;
    ugao=acos((a*a+b*b-c*c)/(2*a*b));
    return ugao;
}
bool Trougao::DaLiJeUnutra(const Tacka &t) const {
    double povrsina_ukupna(fabs(ProvjeriOrijentaciju(t1,t2,t3))/2);
    double povrsina1(fabs(ProvjeriOrijentaciju(t1,t2,t))/2);
    double povrsina2(fabs(ProvjeriOrijentaciju(t2,t3,t))/2);
    double povrsina3(fabs(ProvjeriOrijentaciju(t3,t1,t))/2);
    if(DaLiSuJednaki(povrsina1,0) || DaLiSuJednaki(povrsina2,0) || DaLiSuJednaki(povrsina3,0)) return false;
    else if(DaLiSuJednaki(povrsina_ukupna,(povrsina1+povrsina2+povrsina3))) return true;
    return false;
}
double Trougao::DajStranicu(int indeks) const{
     if(indeks<1 || indeks>3) throw std::range_error("Nekorektan indeks");
     double duzina_stranice;
     if(indeks==1) duzina_stranice=sqrt((t2.first-t3.first)*(t2.first-t3.first)+(t2.second-t3.second)*(t2.second-t3.second));
     if(indeks==2) duzina_stranice=sqrt((t1.first-t3.first)*(t1.first-t3.first)+(t1.second-t3.second)*(t1.second-t3.second));
     if(indeks==3)duzina_stranice=sqrt((t2.first-t1.first)*(t2.first-t1.first)+(t2.second-t1.second)*(t2.second-t1.second));
    return duzina_stranice;   
}
double Trougao::DajUgao(int indeks) const{
    if(indeks<1 || indeks>3) throw std::range_error("Nekorektan indeks");
    double ugao;
    double prva(DajStranicu(1)),druga(DajStranicu(2)),treca(DajStranicu(3));
    if(indeks==1){
        ugao=Kosinusna(druga,treca,prva);
    }
    if(indeks==2) ugao=Kosinusna(prva,treca,druga);
    else ugao=Kosinusna(prva,druga,treca);
    return ugao;
}
Tacka Trougao::DajCentar() const{
    Tacka teziste;
       double x,y;
       x=(t1.first+t2.first+t3.first)/3;
       y=(t1.second+t2.second+t3.second)/3;
       teziste=std::make_pair(x,y);
       return teziste;
}

double Trougao::DajObim() const{
    double obim(DajStranicu(1)+DajStranicu(2)+DajStranicu(3));
    return obim;
}

double Trougao::DajPovrsinu() const{
    double povrsina(fabs(ProvjeriOrijentaciju(t1,t2,t3))/2);
    return povrsina;
}


Trougao::Trougao(const Tacka &t1,const Tacka &t2,const Tacka &t3){
    //if(ProvjeriOrijentaciju(t1,t2,t3)==0) throw std::domain_error("Nekorektne pozicije tjemena");
        Trougao::t1=t1;
        Trougao::t2=t2;
        Trougao::t3=t3;
}
void Trougao::Postavi(const Tacka &t1,const Tacka &t2,const Tacka  &t3){
     if(ProvjeriOrijentaciju(t1,t2,t3)==0) throw std::domain_error("Nekorektne pozicije tjemena");
        Trougao::t1=t1;
        Trougao::t2=t2;
        Trougao::t3=t3;
}
void Trougao::Postavi(int indeks,const Tacka &t){
    if(indeks<1 || indeks>3) throw std::range_error("Nekorektan indeks");
    if(indeks==1) Trougao::t1=t;
    else if(indeks==2) Trougao::t2=t;
    else Trougao::t3=t;
}

int Trougao::Orijentacija(const Tacka &t1,const Tacka &t2,const Tacka &t3){
    if(ProvjeriOrijentaciju(t1,t2,t3)>0) return 1;
    else if(ProvjeriOrijentaciju(t1,t2,t3)<0) return -1;
    return 0;
}

void Trougao::Transliraj(double delta_x,double delta_y){
    t1.first+=delta_x;
    t2.first=t2.first+delta_x;
    t3.first=t3.first+delta_x;
    t1.second=t1.second+delta_y;t2.second=t2.second+delta_y;t3.second=t3.second+delta_y;
}
void Trougao::Centriraj(const Tacka &t){
    Tacka teziste(DajCentar());
    
    //teziste=std::make_pair(DajCentar());
    if(t.first>teziste.first && t.second>teziste.second){
        t1.first=t1.first+(t.first-teziste.first);t2.first=t2.first+(t.first-teziste.first);t3.first=t3.first+(t.first-teziste.first);
        t1.second=t1.second+(t.second-teziste.second);t2.second=t2.second+(t.second-teziste.second);t3.second=t3.second+(t.second-teziste.second);
    }
    if(t.first<teziste.first && t.second>teziste.second){
         t1.first=t1.first-(t.first-teziste.first);t2.first=t2.first-(t.first-teziste.first);t3.first=t3.first-(t.first-teziste.first);
        t1.second=t1.second+(t.second-teziste.second);t2.second=t2.second+(t.second-teziste.second);t3.second=t3.second+(t.second-teziste.second);
    }
    if(t.first<teziste.first && t.second<teziste.second){
         t1.first=t1.first-(t.first-teziste.first);t2.first=t2.first-(t.first-teziste.first);t3.first=t3.first-(t.first-teziste.first);
        t1.second=t1.second-(t.second-teziste.second);t2.second=t2.second-(t.second-teziste.second);t3.second=t3.second-(t.second-teziste.second);
    }
    if(t.first>teziste.first && t.second<teziste.second){
         t1.first=t1.first+(t.first-teziste.first);t2.first=t2.first+(t.first-teziste.first);t3.first=t3.first+(t.first-teziste.first);
        t1.second=t1.second-(t.second-teziste.second);t2.second=t2.second-(t.second-teziste.second);t3.second=t3.second-(t.second-teziste.second);
    }
}
  void Trougao::Rotiraj(const Tacka &t,double ugao){
      //ugao=ugao*3.14159265/180;
      t1.first=t.first+(t1.first-t.first)*cos(static_cast<long double>(ugao))-(t1.second-t.second)*sin(ugao);t1.second=t.second+(t1.first-t.first)*sin(ugao)+(t1.second-t.second)*cos(ugao);
      t2.first=t.first+(t2.first-t.first)*cos(ugao)-(t2.second-t.second)*sin(ugao);t2.second=t.second+(t2.first-t.first)*sin(ugao)+(t2.second-t.second)*cos(ugao);
      t3.first=t.first+(t3.first-t.first)*cos(ugao)-(t3.second-t.second)*sin(ugao);t3.second=t.second+(t3.first-t.first)*sin(ugao)+(t3.second-t.second)*cos(ugao);
  }
  void Trougao::Skaliraj(const Tacka &t,double faktor){
      if(DaLiSuJednaki(faktor,0)) throw std::domain_error("Nekorektan faktor skaliranja");
      t1.first=t.first+faktor*(t1.first-t.first);t1.second=t.second+faktor*(t1.second-t.second);//Provjeri jos jednom formulu Aida
      t2.first=t.first+faktor*(t2.first-t.first);t2.second=t.second+faktor*(t2.second-t.second);
       t3.first=t.first+faktor*(t3.first-t.first);t3.second=t.second+faktor*(t3.second-t.second);
  }
void Trougao::Rotiraj(double ugao){
   //ugao=ugao*3.14159265/180;
        Tacka t(this->DajCentar());
      t1.first=t.first+(t1.first-t.first)*cos(ugao)-(t1.second-t.second)*sin(ugao);t1.second=t.second+(t1.first-t.first)*sin(ugao)+(t1.second-t.second)*cos(ugao);
      t2.first=t.first+(t2.first-t.first)*cos(ugao)-(t2.second-t.second)*sin(ugao);t2.second=t.second+(t2.first-t.first)*sin(ugao)+(t2.second-t.second)*cos(ugao);
      t3.first=t.first+(t3.first-t.first)*cos(ugao)-(t3.second-t.second)*sin(ugao);t3.second=t.second+(t3.first-t.first)*sin(ugao)+(t3.second-t.second)*cos(ugao);
  }
  void Trougao::Skaliraj(double faktor){
      if(DaLiSuJednaki(faktor,0)) throw std::domain_error("Nekorektan faktor skaliranja");
      Tacka t(DajCentar());
      t1.first=t.first+faktor*(t1.first-t.first);t1.second=t.second+faktor*(t1.second-t.second);//Provjeri jos jednom formulu Aida
      t2.first=t.first+faktor*(t2.first-t.first);t2.second=t.second+faktor*(t2.second-t.second);
       t3.first=t.first+faktor*(t3.first-t.first);t3.second=t.second+faktor*(t3.second-t.second);
  }
 bool DaLiSuIdenticni(const Trougao &t1,const Trougao &t2){
    if(DaLiSuJednaki(t1.t1.first,t2.t1.first) && DaLiSuJednaki(t1.t1.second,t2.t1.second) && DaLiSuJednaki(t1.t2.first,t2.t2.first) && DaLiSuJednaki(t1.t2.second,t2.t2.second) && DaLiSuJednaki(t1.t3.first,t2.t3.first) && DaLiSuJednaki(t1.t3.second,t2.t3.second))
    return true;
    if(DaLiSuJednaki(t1.t1.first,t2.t2.first) && DaLiSuJednaki(t1.t1.second,t2.t2.second) && DaLiSuJednaki(t1.t2.first,t2.t1.first) && DaLiSuJednaki(t1.t2.second,t2.t1.second) && DaLiSuJednaki(t1.t3.first,t2.t3.first) && DaLiSuJednaki(t1.t3.second,t2.t3.second))
    return true;
    if(DaLiSuJednaki(t1.t1.first,t2.t1.first) && DaLiSuJednaki(t1.t1.second,t2.t1.second) && DaLiSuJednaki(t1.t2.first,t2.t3.first) && DaLiSuJednaki(t1.t2.second,t2.t3.second) && DaLiSuJednaki(t1.t3.first,t2.t2.first) && DaLiSuJednaki(t1.t3.second,t2.t2.second))
    return true;
    if(DaLiSuJednaki(t1.t1.first,t2.t3.first) && DaLiSuJednaki(t1.t1.second,t2.t3.second) && DaLiSuJednaki(t1.t2.first,t2.t2.first) && DaLiSuJednaki(t1.t2.second,t2.t2.second) && DaLiSuJednaki(t1.t3.first,t2.t1.first) && DaLiSuJednaki(t1.t3.second,t2.t1.second))
    return true;
    return false;
  } 
  
  bool DaLiSuPodudarni(const Trougao &t1,const Trougao &t2){
      double stra1(t1.DajStranicu(1)),stra2(t1.DajStranicu(2)),stra3(t1.DajStranicu(3));
       double strb1(t2.DajStranicu(1)),strb2(t2.DajStranicu(2)),strb3(t2.DajStranicu(3));
      std::vector<double> v1{stra3,stra2,stra1};
      std::vector<double> v2{strb1,strb2,strb3};
      std::sort(v1.begin(),v1.end(),[](double a,double b){
          return a<b;
      });
      
     
      std::sort(v2.begin(),v2.end(),[](double a,double b){
          return a<b;
      });
      bool m(true),n(true);
      for(int i=0;i<3;i++){
          if(DaLiSuJednaki(v1[i],v2[i])==false) {
              m=false;
          }
      }
     // if(Trougao::Orijentacija(t1.t1,t1.t2,t1.t3)==Trougao::Orijentacija(t2.t1,t2.t2,t2.t3) || Trougao::Orijentacija(t1.t1,t1.t2,t1.t3)==Trougao::Orijentacija(t2.t1,t2.t2,t2.t3)*(-1)) n=false;
      if(n==true && m==true) return true;
      return false;
  }
bool DaLiSuSlicni(const Trougao &t1,const Trougao &t2){
   double stra1(t1.DajStranicu(1)),stra2(t1.DajStranicu(2)),stra3(t1.DajStranicu(3));
       double strb1(t2.DajStranicu(1)),strb2(t2.DajStranicu(2)),strb3(t2.DajStranicu(3));
      std::vector<double> v1{stra3,stra2,stra1};
      std::vector<double> v2{strb1,strb2,strb3};
      std::sort(v1.begin(),v1.end(),[](double a,double b){
          return a<b;
      });
      std::sort(v2.begin(),v2.end(),[](double a,double b){
          return a<b;
      });
     // bool m(true);
      
          if(!(DaLiSuJednaki(v1[0]/v2[0],v1[1]/v2[1]) && DaLiSuJednaki( v1[1]/v2[1],v1[2]/v2[2]) && DaLiSuJednaki( v1[0]/v2[0],v1[2]/v2[2]))) {
              return false;
          }
      
     if(Trougao::Orijentacija(t1.t1,t1.t2,t1.t3)!=Trougao::Orijentacija(t2.t1,t2.t2,t2.t3)) return false;
   
    return true;
}
  
int main ()
{
    std::cout<<"Koliko zelite kreirati trouglova: ";
    int n;
    std::cin>>n;
   
    try{
         std::vector<std::shared_ptr<Trougao>> veca(n);
        for(int i=0;i<n;i++){
            std::cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
                Tacka a;
                double x,y;
                std::cin>>x>>y;
                a=std::make_pair(x,y);
                Tacka b;
                std::cin>>x>>y;
                b=std::make_pair(x,y);
                Tacka c;
                std::cin>>x>>y;
                c=std::make_pair(x,y);
                Trougao t1(a,b,c);
                double str1(t1.DajStranicu(1)),str2(t1.DajStranicu(2)),str3(t1.DajStranicu(3));
                //std::cout<<str1<<" "<<str2<<" "<<str2<<std::endl;
                if(!(str1<str2+str3 && str2<str1+str3 && str3<str1+str2)){
                while(!(str1<str2+str3 && str2<str1+str3 && str3<str1+str2)){
                    std::cout<<"Nekorektne pozicije tjemena, ponovite unos!"<<std::endl;
                     std::cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
                Tacka a;
                double x,y;
                std::cin>>x>>y;
                a=std::make_pair(x,y);
                Tacka b;
                std::cin>>x>>y;
                b=std::make_pair(x,y);
                Tacka c;
                std::cin>>x>>y;
                c=std::make_pair(x,y);
                Trougao t1(a,b,c);
                double str1(t1.DajStranicu(1)),str2(t1.DajStranicu(2)),str3(t1.DajStranicu(3));
                 if((str1<str2+str3 && str2<str1+str3 && str3<str1+str2)) break;
                }
                }
                std::shared_ptr<Trougao> pok(std::make_shared<Trougao>(a,b,c));

                veca[i]=(pok);
        }
        
        
        
        
        std::cout<<"Unesite vektor translacije (dx dy): ";
        double delta_x,delta_y;
        std::cin>>delta_x>>delta_y;
        std::cout<<"Unesite ugao rotacije: ";
        double ugao;
        std::cin>>ugao;
        std::cout<<"Unesite faktor skaliranja: ";
        double faktor;
        std::cin>>faktor;
          std::transform(veca.begin(),veca.end(),veca.begin(),[&delta_x,&delta_y,&ugao,&faktor](std::shared_ptr<Trougao> &pok){
                pok->Transliraj(delta_x,delta_y);
                //Tacka centar(pok->DajCentar());
                Tacka skaliranje(pok->DajTjeme(1));
                pok->Rotiraj(ugao);
                pok->Skaliraj(skaliranje,faktor);
                return pok;
            });
            std::sort(veca.begin(),veca.end(),[](std::shared_ptr<Trougao> pok1 , std::shared_ptr<Trougao> pok2){
                return pok1->DajPovrsinu() < pok2->DajPovrsinu();
            });
        std::cout<<"Trouglovi nakon obavljenih transformacija: ";
        std::for_each(veca.begin(),veca.end(),[](std::shared_ptr<Trougao> pok){
            std::cout<<std::endl;
            pok->Ispisi();
        })  ;
        std::cout<<std::endl;
        std::cout<<"Trougao sa najmanjim obimom: ";
        auto it(std::min_element(veca.begin(),veca.end(),[](std::shared_ptr<Trougao> pok1,std::shared_ptr<Trougao> pok2){return pok1->DajObim() < pok2->DajObim();}));
        (*it)->Ispisi();
        std::cout<<std::endl;
         std::vector<std::shared_ptr<Trougao>> v1;
        
        int brojac(0);
       for(int i=0;i<n;i++){
           Trougao t1(*(veca[i]));
           for(int j=i+1;j<n;j++){
               Trougao t2(*(veca[j]));
               if(DaLiSuIdenticni(t1,t2)){
                   /*t1.Ispisi();
                   std::cout<<" i ";
                   t2.Ispisi();
                   std::cout<<std::endl*/
                   brojac++;
               }
           }
       }
       if(brojac==0) std::cout<<"Nema identicnih trouglova!"<<std::endl;
       else{
       std::cout<<"Parovi identicnih trouglova:"<<std::endl;
       for(int i=0;i<n;i++){
           Trougao t1(*(veca[i]));
           for(int j=i+1;j<n;j++){
               Trougao t2(*(veca[j]));
               if(DaLiSuIdenticni(t1,t2)){
                   t1.Ispisi();
                   std::cout<<" i ";
                   t2.Ispisi();
                   std::cout<<std::endl;
                   brojac++;
               }
           }
       }
       }
       brojac=0;
 
   for(int i=0;i<n;i++){
           Trougao t1(*(veca[i]));
           for(int j=i+1;j<n;j++){
               Trougao t2(*(veca[j]));
               if(DaLiSuPodudarni(t1,t2)){
            
                   brojac++;
               }
           }
       }
       if(brojac==0) std::cout<<"Nema podudarnih trouglova!"<<std::endl;
         else{
         std::cout<<"Parovi podudarnih trouglova:"<<std::endl;
          for(int i=0;i<n;i++){
           Trougao t1(*(veca[i]));
           for(int j=i+1;j<n;j++){
               Trougao t2(*(veca[j]));
               if(DaLiSuPodudarni(t1,t2)){
                   t1.Ispisi();
                   std::cout<<" i ";
                   t2.Ispisi();
                   std::cout<<std::endl;
                   brojac++;
               }
           }
       }
         }
       brojac=0;
    //std::cout<<std::endl;
     for(int i=0;i<n;i++){
           Trougao t1(*(veca[i]));
           for(int j=i+1;j<n;j++){
               Trougao t2(*(veca[j]));
               if(DaLiSuSlicni(t1,t2)){
                   brojac++;
               }
           }
       }
       if(brojac==0) std::cout<<"Nema slicnih trouglova!"<<std::endl;
        else{
        std::cout<<"Parovi slicnih trouglova:"<<std::endl;
         for(int i=0;i<n;i++){
           Trougao t1(*(veca[i]));
           for(int j=i+1;j<n;j++){
               Trougao t2(*(veca[j]));
               if(DaLiSuSlicni(t1,t2)){
                   t1.Ispisi();
                   std::cout<<" i ";
                   t2.Ispisi();
                   std::cout<<std::endl;
                   brojac++;
               }
           }
       }
        }
    }
    catch(std::domain_error izuzetak){
        std::cout<<izuzetak.what();
    }
   // std::shared_ptr<Trougao>
	return 0;
}