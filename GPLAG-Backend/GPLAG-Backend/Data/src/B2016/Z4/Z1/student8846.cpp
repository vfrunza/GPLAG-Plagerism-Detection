/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <utility>
#include <stdexcept>
#include <cmath>
#include <memory>
#include <vector>
#include <algorithm>
#define epsilon 0.00000000001
typedef std::pair<double,double> Tacka;
Tacka skaliranje(const Tacka t,double faktor,Tacka tacka_skaliranja){//provjerit da li sam fino sve 
/*tacka_skaliranja.first=(tacka_skaliranja.first+faktor*(t.first-tacka_skaliranja.first));
tacka_skaliranja.second=(tacka_skaliranja.second+faktor*(t.second-tacka_skaliranja.second));*/
    tacka_skaliranja.first=(t.first+faktor*(tacka_skaliranja.first-t.first));
    tacka_skaliranja.second=(t.second+faktor*(tacka_skaliranja.second-t.second));
    return tacka_skaliranja;
}


double povrsina(Tacka t1,Tacka t2,Tacka t3){
    return (std::abs(t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second)))/2;
}
double udaljenost(Tacka t1,Tacka t2)
{
    return std::sqrt((t1.first-t2.first)*(t1.first-t2.first)+ (t2.second-t1.second)*(t2.second-t1.second));
}
Tacka centar(Tacka t1,Tacka t2,Tacka t3){
    Tacka t;
    t.first=(t1.first+t2.first+t3.first)/3;
    t.second=(t1.second+t2.second+t3.second)/3;
    return t;
}
class Trougao{
    Tacka t1,t2,t3;
   /* Tacka Trougao::tjeme(Trougao t, int br){
    return DajTjeme(br);
}*/
  public:
  Trougao(const Tacka &t1,const Tacka &t2, const Tacka &t3){
     if(Orijentacija(t1,t2,t3)==0) throw std::domain_error("Nekorektne pozicije tjemena");
      Trougao::t1.first=t1.first; Trougao::t1.second=t1.second;
      Trougao::t2.first=t2.first; Trougao::t2.second=t2.second;
      Trougao::t3.first=t3.first; Trougao::t3.second=t3.second;
  }
  void Postavi(const Tacka &t1, const Tacka &t2,const Tacka &t3){
      if(Orijentacija(t1,t2,t3)==0) throw std::domain_error("Nekorektne pozicije tjemena");
      Trougao::t1.first=t1.first; Trougao::t1.second=t1.second;
      Trougao::t2.first=t2.first; Trougao::t2.second=t2.second;
      Trougao::t3.first=t3.first; Trougao::t3.second=t3.second;
  }
  void Postavi(int indeks,const Tacka &t){
      if(indeks<1 || indeks>3) throw std::range_error("Nekorektan indeks");
      if(indeks==1){
          Trougao::t1.first=t.first;
          Trougao::t1.second=t.second;
      }
      else if(indeks==2){
          Trougao::t2.first=t.first;
          Trougao::t2.second=t.second;
      }
      else if(indeks==3){
          Trougao::t3.first=t.first;
          Trougao::t3.second=t.second;
      }
  }
  static int Orijentacija(const Tacka &t1,const Tacka &t2,const Tacka &t3);
  Tacka DajTjeme(int indeks)const{
      if(indeks<1 || indeks>3) throw std::range_error("Nekorektan indeks");
      if(indeks==1) return t1;
      else if(indeks==2) return t2;
      else if(indeks==3) return t3;
  }
  double DajStranicu(int indeks)const{
      if(indeks<1 || indeks>3) throw std::range_error("Nekorektan indeks");
      if(indeks==1) return udaljenost(t2,t3);
      else if(indeks==2) return udaljenost(t1,t3);
      else if(indeks==3) return udaljenost(t1,t2);
  }
  double DajUgao(int indeks)const{
      if(indeks<1 || indeks>3) throw std::range_error("Nekorektan indeks");
      if(indeks==1) return acos((DajStranicu(2)*DajStranicu(2)+DajStranicu(3)*DajStranicu(3)-DajStranicu(1)*DajStranicu(1))/(2*DajStranicu(2)*DajStranicu(3)));
      if(indeks==2) return acos((DajStranicu(1)*DajStranicu(1)+DajStranicu(3)*DajStranicu(3)-DajStranicu(2)*DajStranicu(2))/(2*DajStranicu(1)*DajStranicu(3)));
      if(indeks==3) return acos((DajStranicu(1)*DajStranicu(1)+DajStranicu(2)*DajStranicu(2)-DajStranicu(3)*DajStranicu(3))/(2*DajStranicu(1)*DajStranicu(3)));
  }
  Tacka DajCentar()const{
      return centar(t1,t2,t3);
  }
  double DajObim()const
  {
      return DajStranicu(1)+DajStranicu(2)+DajStranicu(3);
  }
  double DajPovrsinu() const{
      return povrsina(t1,t2,t3);
  }
  bool DaLiJePozitivnoOrijentiran()const{
      if(Orijentacija(t1,t2,t3)==1) return true;
      else return false;
  }
  bool DaLiJeUnutra(const Tacka &t)const;
  void Ispisi()const{
      std::cout<<"(("<<t1.first<<","<<t1.second<<"),("<<t2.first<<","<<t2.second<<"),("<<t3.first<<","<<t3.second<<"))";
  }
  void Transliraj(double delta_x,double delta_y){
      t1.first=t1.first+delta_x;
      t2.first=t2.first+delta_x;
      t3.first=t3.first+delta_x;
      t1.second=t1.second+delta_y;
      t2.second=t2.second+delta_y;
      t3.second=t3.second+delta_y;
  }
  void Centriraj(const Tacka &t){
      double delta_x(std::abs(DajCentar().first-t.first));
      double delta_y(std::abs(DajCentar().second-t.second));
      Transliraj(delta_x,delta_y);
  }
  void Rotiraj(const Tacka &t,double ugao){
      t1.first=(t.first+(t1.first-t.first)*std::cos(ugao)-(t1.second-t.second)*std::sin(ugao));
      t2.first=(t.first+(t2.first-t.first)*std::cos(ugao)-(t2.second-t.second)*std::sin(ugao));
      t3.first=(t.first+(t3.first-t.first)*std::cos(ugao)-(t3.second-t.second)*std::sin(ugao));
      t1.second=(t.second+(t1.first-t.first)*std::sin(ugao)+(t1.second-t.second)*std::cos(ugao));
      t2.second=(t.second+(t2.first-t.first)*std::sin(ugao)+(t2.second-t.second)*std::cos(ugao));
      t3.second=(t.second+(t3.first-t.first)*std::sin(ugao)+(t3.second-t.second)*std::cos(ugao));
  }
  void Skaliraj(const Tacka &t,double faktor){
      if(faktor<epsilon) throw std::domain_error("Nekorektan faktor skaliranja");
     t1=skaliranje(t,faktor,t1);
     t2=skaliranje(t,faktor,t2);
     t3=skaliranje(t,faktor,t3);
  }
  void Rotiraj(double ugao){
      Rotiraj(centar(t1,t2,t3),ugao);
  }
  void Skaliraj(double faktor){
      Skaliraj(centar(t1,t2,t3),faktor);
  }
  friend bool DaLiSuIdenticni(const Trougao &t1,const Trougao &t2);
  
  friend bool DaLiSuPodudarni(const Trougao &t1,const Trougao &t2);
  friend bool DaLiSuSlicni(const Trougao &t1,const Trougao &t2);

};

int Trougao::Orijentacija(const Tacka &t1,const Tacka &t2,const Tacka &t3){

    if(std::fabs(t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second))>epsilon)
    {
        if((t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second))<-epsilon) return -1;
         else if((t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second))>epsilon) return 1;
 
    }
    else return 0;
}
bool Jednakost(Tacka t1,Tacka t2)
{
if(std::fabs(t1.first-t2.first)<epsilon && std::fabs(t1.second-t2.second)<epsilon) return true;
else return false;
}
bool DaLiSuIdenticni(const Trougao &t1,const Trougao &t2){
   if(
   (Jednakost(t1.DajTjeme(1),t2.DajTjeme(1)) || Jednakost(t1.DajTjeme(1),t2.DajTjeme(2)) || Jednakost(t1.DajTjeme(1),t2.DajTjeme(3))) && 
   (Jednakost(t1.DajTjeme(2),t2.DajTjeme(1)) || Jednakost(t1.DajTjeme(2),t2.DajTjeme(2)) || Jednakost(t1.DajTjeme(2),t2.DajTjeme(3))) &&
   (Jednakost(t1.DajTjeme(3),t2.DajTjeme(1)) || Jednakost(t1.DajTjeme(3),t2.DajTjeme(2)) || Jednakost(t1.DajTjeme(3),t2.DajTjeme(3))) 
   ) return true;
   else return false;
}

bool JednakostDouble(double x,double y)
{
    return std::fabs(x-y)<epsilon;
}

bool DaLiSuPodudarni(const Trougao &t1,const Trougao &t2)
{

    if(t1.DaLiJePozitivnoOrijentiran()!=t2.DaLiJePozitivnoOrijentiran())
    {
           return false;
    }
    
    std::vector<double> stranicea;
    std::vector<double> straniceb;
    for(int i=0;i<3;i++)
    {
        stranicea.push_back(t1.DajStranicu(i+1));
        straniceb.push_back(t2.DajStranicu(i+1));
    }
    std::sort(stranicea.begin(),stranicea.end());
    std::sort(straniceb.begin(),straniceb.end());
    std::vector<double> sve_stranice;
    for(int i=0;i<3;i++)
    {
        sve_stranice.push_back(stranicea[i]);
    }
    
    for(int i=0;i<3;i++)
    {
        sve_stranice.push_back(straniceb[i]);
    }
    for(int i=1;i<3;i++)
    {
        if(std::fabs(sve_stranice[i]-sve_stranice[i+3])>epsilon) return false;
    }
    return true;
}

bool DaLiSuSlicni(const Trougao &t1,const Trougao &t2)
{
    if(t1.DaLiJePozitivnoOrijentiran()!=t2.DaLiJePozitivnoOrijentiran()) return false;
    std::vector<double> stranicea;
    std::vector<double> straniceb;
    for(int i=0;i<3;i++)
    {
        stranicea.push_back(t1.DajStranicu(i+1));
        straniceb.push_back(t2.DajStranicu(i+1));
    }
    std::sort(stranicea.begin(),stranicea.end());
    std::sort(straniceb.begin(),straniceb.end());
    std::vector<double> sve_stranice;
    for(int i=0;i<3;i++)
    {
        sve_stranice.push_back(stranicea[i]);
    }
    
    for(int i=0;i<3;i++)
    {
        sve_stranice.push_back(straniceb[i]);
    }
    for(int i=1;i<3;i++)
    {
        if(std::fabs(sve_stranice[i]/sve_stranice[i+3]-sve_stranice[i-1]/sve_stranice[i+2])>epsilon) return false;
    }
    return true;
    /*double faktor=stranicea[0]/straniceb[0];
    Tacka t=t2.DajTjeme(1);
    Trougao tr=t2;
    tr.Skaliraj(t,faktor);
    if(DaLiSuPodudarni(tr,t1)) return true;
    else return false;*/
}

bool DaLiSeNalaziUVektoru(std::vector<std::pair<Trougao,Trougao>> trouglovi, std::pair<Trougao,Trougao> par)
{
    for(int i=0;i<(int)trouglovi.size();i++)
    {
        if((DaLiSuIdenticni(trouglovi[i].first,par.first) && DaLiSuIdenticni(trouglovi[i].second,par.second)) || (DaLiSuIdenticni(trouglovi[i].first,par.second) && DaLiSuIdenticni(trouglovi[i].second,par.first)) ) return true;
    }
    return false;
}


int main ()
{
   Tacka t1,t2,t3;
   double x1,y1,x2,y2,x3,y3;
    int n;
    std::vector<std::shared_ptr<Trougao>> vektor;
    std::cout<<"Koliko zelite kreirati trouglova: ";
    std::cin>>n;
    for(int i=0;i<n;i++){
        std::cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
       std::cin>>x1>>y1>>x2>>y2>>x3>>y3;
       t1=std::make_pair(x1,y1);
       t2=std::make_pair(x2,y2);
       t3=std::make_pair(x3,y3);
       try{
           vektor.emplace_back(std::make_shared<Trougao>(Trougao(t1,t2,t3)));
       }
       catch(std::domain_error){
           std::cout<<"Nekorektne pozicije tjemena, ponovite unos";
           --i;
       }
    }
    double dx,dy,ugao,fakt;
    std::cout<<"Unesite vektor translacije (dx dy): ";
    std::cin>>dx>>dy;
    std::cout<<"Unesite ugao rotacije: ";
    std::cin>>ugao;
    std::cout<<"Unesite faktor skaliranja: ";
    std::cin>>fakt;
    
    std::cout<<"Trouglovi nakon obavljenih transformacija: ";
    std::vector<std::shared_ptr<Trougao>> vektor2(n),vektor3(n),vektor4(n);
    std::transform(vektor.begin(),vektor.end(),vektor2.begin(),[dx,dy](std::shared_ptr<Trougao> vektor)/*->(std::shared_ptr<Trougao> )*/{ (*vektor).Transliraj(dx,dy); return vektor;});
    std::transform(vektor2.begin(),vektor2.end(),vektor3.begin(),[ugao](std::shared_ptr<Trougao> vektor2){(*vektor2).Rotiraj((*vektor2).DajCentar(),ugao);return vektor2;});
    std::transform(vektor3.begin(),vektor3.end(),vektor4.begin(),[fakt](std::shared_ptr<Trougao> vektor3){(*vektor3).Skaliraj((*vektor3).DajTjeme(1),fakt); return vektor3;});
    std::sort(vektor4.begin(),vektor4.end(),[](std::shared_ptr<Trougao> t1,std::shared_ptr<Trougao> t2){return t1->DajPovrsinu()<t2->DajPovrsinu();});
    std::cout<<std::endl;
    std::for_each(vektor4.begin(),vektor4.end(),[](std::shared_ptr<Trougao>t){t->Ispisi(); std::cout<<"\n";});
    
    
    std::cout<<"Trougao sa najmanjim obimom: ";
    (*std::min_element(vektor4.begin(),vektor4.end(),[](std::shared_ptr<Trougao> t1,std::shared_ptr<Trougao> t2){
        return t1->DajObim()<t2->DajObim();}))->Ispisi();
        std::vector<std::pair<Trougao,Trougao>> identicni,podudarni,slicni;
        std::cout<<std::endl;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i!=j)
                {
                    if(DaLiSuIdenticni(*vektor4[i],*vektor4[j]))
                    {
                        if(!DaLiSeNalaziUVektoru(identicni,std::make_pair(*vektor4[i],*vektor4[j])))
                            {
                                identicni.push_back(std::make_pair(*vektor4[j],*vektor4[i]));
                            }
                    }
                    if(DaLiSuPodudarni(*vektor4[i],*vektor4[j]))
                    {
                        if(!DaLiSeNalaziUVektoru(podudarni,std::make_pair(*vektor4[i],*vektor4[j])))
                            {
                                podudarni.push_back(std::make_pair(*vektor4[j],*vektor4[i]));
                            }
                    }
                     if(DaLiSuSlicni(*vektor4[i],*vektor4[j]))
                    {
                        if(!DaLiSeNalaziUVektoru(slicni,std::make_pair(*vektor4[i],*vektor4[j])))
                            {
                                slicni.push_back(std::make_pair(*vektor4[j],*vektor4[i]));
                            }
                    }
                }
            }
        }
        if((int)identicni.size()==0)
        {
            std::cout<<"Nema identicnih trouglova!\n";
        }
        else
        {
            std::cout<<"Parovi identicnih trouglova: \n";
            std::for_each(identicni.begin(),identicni.end(),[](std::pair<Trougao,Trougao> p)
            {
               p.second.Ispisi();
               std::cout<<" i ";
               p.first.Ispisi();
               std::cout<<"\n";
                
            });
        }
        if((int)podudarni.size()==0)
        {
            std::cout<<"Nema podudarnih trouglova!\n";
        }
        else
        {
            std::cout<<"Parovi podudarnih trouglova: \n";
            std::for_each(podudarni.begin(),podudarni.end(),[](std::pair<Trougao,Trougao> p)
            {
               p.second.Ispisi();
               std::cout<<" i ";
               p.first.Ispisi();
               std::cout<<"\n";
                
            });
        }
        if((int)slicni.size()==0)
        {
            std::cout<<"Nema slicnih trouglova!\n";
        }
        else
        {
            std::cout<<"Parovi slicnih trouglova: \n";
            std::for_each(slicni.begin(),slicni.end(),[](std::pair<Trougao,Trougao> p)
            {
               p.second.Ispisi();
               std::cout<<" i ";
               p.first.Ispisi();
               std::cout<<"\n";
                
            });
        }
    
        /*
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                if(DaLiSuIdenticni(*vektor4[i],*vektor4[j]))
                    identicni.push_back(std::make_pair(i+1,j+1));
                    if(identicni.size()==0) std::cout<<"Nema identicnih trouglova";
                    else {
                        std::cout<<"Parovi identicnih trouglova: ";
                        for(auto &par:identicni){
                           // std::cout<<par.Ispisi();
                        }
                        for(int i=0;i<identicni.size();i++){
                            std::cout<<"("<<identicni[i].first<<","<<identicni[i].second<<")";
                             std::cout<<" i ";
                        }
                   
          //  }*/
        
	return 0;
}