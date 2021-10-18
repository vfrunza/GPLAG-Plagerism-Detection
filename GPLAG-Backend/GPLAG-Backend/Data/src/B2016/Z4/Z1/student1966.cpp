#include <iostream>
#include <utility>
#include <stdexcept>
#include <cmath>
#include <memory>
#include <algorithm>
#include <vector>

typedef std::pair<double, double> Tacka;
class Trougao{
    Tacka A, B, C;
    public:    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        if(Orijentacija(t1, t2, t3)==0) throw std::domain_error("Nekorektne pozicije tjemena, ponovite unos!");
        A=t1; B=t2; C=t3;
    }
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        if(Orijentacija(t1, t2, t3)==0) throw std::domain_error("Nekorektne pozicije tjemena, ponovite unos!\n");
        A=t1; B=t2; C=t3;
    }
    void Postavi(int indeks, const Tacka &t) {
        if(indeks<1 || indeks>3) throw std::range_error("Nekorektan indeks");
        if(indeks==1) A=t;
        else if(indeks==2) B=t;
        else if(indeks==3) C=t;
    }
    static int Orijentacija(const Tacka &A, const Tacka &B, const Tacka &C) {
        int rezultat;
        rezultat=A.first*(B.second-C.second)-B.first*(A.second-C.second)+C.first*(A.second-B.second);
        return rezultat;
    }
    Tacka DajTjeme(int indeks) const {
        if(indeks<1 || indeks>3) throw std::range_error("Nekorektan indeks");
        if(indeks==1) return A;
        if(indeks==2) return B;
         return C;}
    double DajStranicu(int indeks) const {
        if(indeks<1 || indeks>3) throw std::range_error("Nekorektan indeks");
        if(indeks==1) return fabs(sqrt((B.first-C.first)*(B.first-C.first) + (B.second-C.second)*(B.second-C.second)));
        if(indeks==2) return fabs(sqrt((A.first-C.first)*(A.first-C.first) + (A.second-C.second)*(A.second-C.second)));
        return fabs(sqrt((A.first-B.first)*(A.first-B.first) + (A.second-B.second)*(A.second-B.second)));
    }
    double DajUgao(int indeks) const {
        if(indeks<1 || indeks>3) throw std::range_error("Nekorektan indeks");
        if(indeks==1) return acos((DajStranicu(2)*DajStranicu(2)+DajStranicu(3)*DajStranicu(3)-DajStranicu(1)*DajStranicu(1))/(2*DajStranicu(2)*DajStranicu(3)));
        if(indeks==2) return acos((DajStranicu(1)*DajStranicu(1)+DajStranicu(3)*DajStranicu(3)-DajStranicu(2)*DajStranicu(2))/(2*DajStranicu(1)*DajStranicu(3)));
        return acos((DajStranicu(1)*DajStranicu(1)+DajStranicu(2)*DajStranicu(2)-DajStranicu(3)*DajStranicu(3))/(2*DajStranicu(1)*DajStranicu(2)));
    }
    Tacka DajCentar() const {
        return std::make_pair(((A.first+B.first+C.first)/3), ((A.second+B.second+C.second)/3));
    }
    double DajObim() const {
        return DajStranicu(1)+DajStranicu(2)+DajStranicu(3);
    }
    double DajPovrsinu() const {
        return 0.5*fabs(Orijentacija(A,B,C));
    }
    bool DaLiJePozitivnoOrijentiran() const {
        if(Orijentacija(A,B,C)>0) return true;
        return false;
    }
    bool DaLiJeUnutra(const Tacka &t) {
        if(Orijentacija(A,B,C)>0) {
            if(Orijentacija(A,B,t)>0 && Orijentacija(B,t,C)<0 && Orijentacija(A,t,C)>0) return true;}
        else if(Orijentacija(A,B,C)<0) {
            if(Orijentacija(A,t,C)<0 && Orijentacija(C,t,B)<0 && Orijentacija(A,t,B)>0) return true;
        }
        return false;
    }
    void Ispisi() const {
        std::cout<<"(("<<A.first<<","<<A.second<<"),("<<B.first<<","<<B.second<<"),("<<C.first<<","<<C.second<<"))";
    }
    void Transliraj(double delta_x, double delta_y) {
        Tacka Anovo, Bnovo, Cnovo;
        Anovo.first=A.first+delta_x; Bnovo.first=B.first+delta_x; Cnovo.first=C.first+delta_x;
        Anovo.second=A.second+delta_y; Bnovo.second=B.second+delta_y; Cnovo.second=C.second+delta_y;
        this->Postavi(Anovo, Bnovo, Cnovo);
    }
    void Centriraj(const Tacka &t) {
        double dx, dy;
        dx=this->DajCentar().first-t.first;
        dy=this->DajCentar().second-t.second;
        A.first-=dx; B.first-=dx; C.first-=dx;
        A.second-=dy; B.second-=dy; C.second-=dy;
    }
    void Rotiraj(const Tacka &t, double ugao) {
        Tacka Anovo=A, Bnovo=B, Cnovo=C;
        Anovo.first=t.first+(A.first-t.first)*cos(ugao)-(A.second-t.second)*sin(ugao);
        Bnovo.first=t.first+(B.first-t.first)*cos(ugao)-(B.second-t.second)*sin(ugao);
        Cnovo.first=t.first+(C.first-t.first)*cos(ugao)-(C.second-t.second)*sin(ugao);
        Anovo.second=t.second+(A.first-t.first)*sin(ugao)+(A.second-t.second)*cos(ugao);
        Bnovo.second=t.second+(B.first-t.first)*sin(ugao)+(B.second-t.second)*cos(ugao);
        Cnovo.second=t.second+(C.first-t.first)*sin(ugao)+(C.second-t.second)*cos(ugao);
        this->Postavi(Anovo, Bnovo, Cnovo);
    }
    void Skaliraj( Tacka t, double faktor) {
        if(fabs(faktor)<0.00001) throw std::domain_error("Nekorektan faktor skaliranja");
        Tacka Anovo, Bnovo, Cnovo;
         Anovo.first=t.first+faktor*(A.first-t.first);
          Bnovo.first=t.first+faktor*(B.first-t.first);
       Cnovo.first=t.first+faktor*(C.first-t.first);
  Anovo.second=t.second+faktor*(A.second-t.second);
     Bnovo.second=t.second+faktor*(B.second-t.second);
          Cnovo.second=t.second+faktor*(C.second-t.second);
          this->Postavi(Anovo, Bnovo, Cnovo);
    }
    void Rotiraj(double ugao) {
       Tacka Astaro=A, Bstaro=B, Cstaro=C;
       Tacka centar=this->DajCentar();
        A.first=centar.first+(A.first-centar.first)*cos(ugao)-(A.second-centar.second)*sin(ugao);
        B.first=centar.first+(B.first-centar.first)*cos(ugao)-(B.second-centar.second)*sin(ugao);
        C.first=centar.first+(C.first-centar.first)*cos(ugao)-(C.second-centar.second)*sin(ugao);
        A.second=centar.second+(Astaro.first-centar.first)*sin(ugao)+(A.second-centar.second)*cos(ugao);
        B.second=centar.second+(Bstaro.first-centar.first)*sin(ugao)+(B.second-centar.second)*cos(ugao);
        C.second=centar.second+(Cstaro.first-centar.first)*sin(ugao)+(C.second-centar.second)*cos(ugao);
    }
    void Skaliraj(double faktor) {
        if(fabs(faktor-faktor)<0.00001) throw std::domain_error("Nekorektan faktor skaliranja");
        A.first=this->DajCentar().first+faktor*(A.first-this->DajCentar().first);
        B.first=this->DajCentar().first+faktor*(B.first-this->DajCentar().first);
        C.first=this->DajCentar().first+faktor*(C.first-this->DajCentar().first);
        A.second=this->DajCentar().second+faktor*(A.second-this->DajCentar().second);
        B.second=this->DajCentar().second+faktor*(B.second-this->DajCentar().second);
        C.second=this->DajCentar().second+faktor*(C.second-this->DajCentar().second);
    }
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);
};
bool IsteTacke(Tacka t1, Tacka t2) {
    if(fabs(t1.first-t2.first)<1e-5 && fabs(t1.second-t2.second)<1e-5) return true;
    return false;
}
bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2) {
    if(t1.Orijentacija(t1.A, t1.B, t1.C)!=0 && t2.Orijentacija(t2.A, t2.B, t2.C)!=0) {
      if(IsteTacke(t1.A, t2.A) && IsteTacke(t1.B, t2.B) && IsteTacke(t1.C, t2.C)) return true;
      else if(IsteTacke(t1.A, t2.A) && IsteTacke(t1.B, t2.C) && IsteTacke(t1.C, t2.B)) return true;
      else if(IsteTacke(t1.A, t2.B) && IsteTacke(t1.B, t2.C) && IsteTacke(t1.C, t2.A)) return true;
      else if(IsteTacke(t1.A, t2.B) && IsteTacke(t1.B, t2.A) && IsteTacke(t1.C, t2.C)) return true;
      else if(IsteTacke(t1.A, t2.C) && IsteTacke(t1.B, t2.B) && IsteTacke(t1.C, t2.A)) return true;
      else if(IsteTacke(t1.A, t2.C) && IsteTacke(t1.B, t2.A) && IsteTacke(t1.C, t2.B)) return true;}
      return false;
}
bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2) {
    if(DaLiSuIdenticni(t1, t2)) return true;
    auto zamjena=t1;
    int i=1, cuvar(0);
    while(i<=3) {
        if(t2.DajStranicu(1)-zamjena.DajStranicu(i)<0.0001) {cuvar=i;
        break;} 
        i++;}
     double ugaoDrugog, ugaoPrvog, ugao;
     if(fabs(t2.C.first-t2.B.first)<0.001) ugaoDrugog=2*atan(1);
    else  ugaoDrugog=atan((t2.C.second-t2.B.second)/(t2.C.first-t2.B.first));
     
     if(cuvar==1) { if(fabs(zamjena.C.first-zamjena.A.first)<0.001) ugaoPrvog=2*atan(1);
        else  ugaoPrvog=atan((zamjena.C.second-zamjena.A.second)/(zamjena.C.first-zamjena.A.first));
    }
       if(cuvar==2) {ugaoPrvog=atan((zamjena.A.second-zamjena.C.second)/(zamjena.A.first-zamjena.C.first));
     if(fabs(zamjena.A.first-zamjena.C.first)<0.001) ugaoPrvog=2*atan(1);}
       if(cuvar==3) {ugaoPrvog=atan((zamjena.A.second-zamjena.B.second)/(zamjena.A.first-zamjena.B.first));
     if(fabs(zamjena.A.first-zamjena.B.first)<0.001) ugaoPrvog=2*atan(1);}
     ugao=ugaoPrvog-ugaoDrugog;
     zamjena.Centriraj(t2.DajCentar());
     if(cuvar==1|| cuvar==2 ||cuvar==3) {
        auto temp=zamjena, temp2=zamjena;
         zamjena.Rotiraj(zamjena.DajTjeme(3), ugao);
         zamjena.Centriraj(t2.DajCentar());
         if(DaLiSuIdenticni(zamjena, t2)) return true;
         zamjena.Rotiraj(zamjena.DajTjeme(3), 4*atan(1));
         zamjena.Centriraj(t2.DajCentar());
         if(DaLiSuIdenticni(zamjena, t2)) return true;
         zamjena.Rotiraj(zamjena.DajTjeme(3), 4*atan(1)-2*ugao);
         zamjena.Centriraj(t2.DajCentar());
         if(DaLiSuIdenticni(zamjena, t2)) return true;
          zamjena.Rotiraj(zamjena.DajTjeme(3), 4*atan(1));
         zamjena.Centriraj(t2.DajCentar());
         if(DaLiSuIdenticni(zamjena, t2)) return true;
         
          temp.Rotiraj(temp.DajTjeme(2), ugao);
         temp.Centriraj(t2.DajCentar());
         if(DaLiSuIdenticni(temp, t2)) return true;
         temp.Rotiraj(temp.DajTjeme(2), 4*atan(1));
         temp.Centriraj(t2.DajCentar());
         if(DaLiSuIdenticni(temp, t2)) return true;
         temp.Rotiraj(temp.DajTjeme(2), 4*atan(1)-2*ugao);
         temp.Centriraj(t2.DajCentar());
         if(DaLiSuIdenticni(temp, t2)) return true;
          temp.Rotiraj(temp.DajTjeme(2), 4*atan(1));
         temp.Centriraj(t2.DajCentar());
         if(DaLiSuIdenticni(temp, t2)) return true;
         
          temp2.Rotiraj(temp.DajTjeme(1), ugao);
         temp2.Centriraj(t2.DajCentar());
         if(DaLiSuIdenticni(temp2, t2)) return true;
         temp2.Rotiraj(temp2.DajTjeme(1), 4*atan(1));
         temp2.Centriraj(t2.DajCentar());
         if(DaLiSuIdenticni(temp2, t2)) return true;
         temp2.Rotiraj(temp2.DajTjeme(1), 4*atan(1)-2*ugao);
         temp2.Centriraj(t2.DajCentar());
         if(DaLiSuIdenticni(temp2, t2)) return true;
          temp2.Rotiraj(temp2.DajTjeme(1), 4*atan(1));
         temp2.Centriraj(t2.DajCentar());
         if(DaLiSuIdenticni(temp2, t2)) return true;
     }    
    
    return false;
        
    }
    
bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2) {
    auto zamjena=t1;
    zamjena.Centriraj(t2.DajCentar());
    double skalar=t2.DajStranicu(1)/t1.DajStranicu(1);
    if(fabs(skalar-skalar)>0){
    zamjena.Skaliraj(skalar);}
    if(DaLiSuPodudarni(zamjena,t2)) return true;
     return false;
}

int main ()
{
    Tacka prva(1,2), druga(6, 7), treca(10,13);

   int n;
   std::cout<<"Koliko zelite kreirati trouglova: ";
   std::cin>>n;
   std::vector<std::shared_ptr<Trougao>> v;
   for(int i=0; i<n; i++) {
       Tacka a(1,2),b(6,7),c(10,13);
       Trougao trokut(prva, druga, treca);
       bool dobar_unos=false;
       while (!dobar_unos) {
             std::cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
             double x1,y1,x2,y2,x3,y3;
            std::cin>>x1>>y1>>x2>>y2>>x3>>y3;
        a=std::make_pair(x1,y1), b=std::make_pair(x2,y2), c=std::make_pair(x3,y3);
       bool proslo=true;
       try{
           
           trokut.Postavi(a,b,c);
       } catch(std::domain_error e){
           std::cout<<e.what();
           dobar_unos=false;
           proslo=false;
       } if(proslo) dobar_unos=true;
       }
if(dobar_unos) {
       trokut.Postavi(a,b,c);
        v.push_back(std::make_shared<Trougao> (trokut));}
       }
    Trougao trokut(prva, druga, treca);
    std::cout<<"Unesite vektor translacije (dx dy): ";
    double delta_x, delta_y;
    std::cin>>delta_x>>delta_y;
    std::cout<<"Unesite ugao rotacije: ";
    double ugao;
    std::cin>>ugao;
    std::cout<<"Unesite faktor skaliranja: ";
    double skalar;
    std::cin>>skalar;
    std::transform(v.begin(), v.end(), v.begin(),  [delta_y, delta_x,  ugao, skalar] (std::shared_ptr<Trougao> t)->std::shared_ptr<Trougao> {
        t->Transliraj(delta_x, delta_y);
        t->Rotiraj(ugao);
        t->Skaliraj(t->DajTjeme(1), skalar);
        return t;
    } );  
   std::sort(v.begin(), v.end(), [](std::shared_ptr<Trougao> x, std::shared_ptr<Trougao> y){
       if(x->DajPovrsinu()<y->DajPovrsinu()) return true;
       return false;
   });
   std::cout<<"Trouglovi nakon obavljenih transformacija:";
std::for_each(v.begin(), v.end(), [](std::shared_ptr<Trougao> t){
    std::cout<<std::endl;
    t->Ispisi();
});
    
   auto naj=std::min_element(v.begin(), v.end(), [] (std::shared_ptr<Trougao> x, std::shared_ptr<Trougao> y)->bool{
       return (x->DajObim()<y->DajObim());
   });
   std::cout<<"\nTrougao sa najmanjim obimom: ";
   (*naj)->Ispisi();
      std::vector<std::pair<Trougao, Trougao> > identicni, podudarni, slicni;
      for(auto i=v.begin(); i<v.end(); i++) {
          for(auto j=i+1; j<v.end(); j++) {if(DaLiSuIdenticni(**i, **j)) identicni.push_back(std::make_pair(**i, **j));
          if(DaLiSuPodudarni(**i, **j) || DaLiSuPodudarni(**j, **i)) podudarni.push_back(std::make_pair(**i, **j));
              if(DaLiSuSlicni(**i,**j) || DaLiSuSlicni(**j, **i)) slicni.push_back(std::make_pair(**i,**j));
          }
      }
      if(identicni.size()==0) std::cout<<"\nNema identicnih trouglova!";
      else{
  std::cout<<"\nParovi identicnih trouglova: ";
  for(int i=0; i<identicni.size(); i++) {
      std::cout<<std::endl;
      identicni[i].first.Ispisi();
      std::cout<<" i ";
      identicni[i].second.Ispisi();
  } }
  if(podudarni.size()==0) std::cout<<"\nNema podudarnih trouglova!";
  else{
  std::cout<<"\nParovi podudarnih trouglova: ";
  for(int i=0; i<podudarni.size(); i++) {
      std::cout<<std::endl;
      podudarni[i].first.Ispisi();
      std::cout<<" i ";
      podudarni[i].second.Ispisi();
  }}
  if(slicni.size()==0) std::cout<<"\nNema slicnih trouglova!";
  else{
  std::cout<<"\nParovi slicnih trouglova: ";
  for(int i=0; i<slicni.size(); i++) {
      std::cout<<std::endl;
      slicni[i].first.Ispisi();
      std::cout<<" i ";
      slicni[i].second.Ispisi();
  }} 
  
	return 0;
}