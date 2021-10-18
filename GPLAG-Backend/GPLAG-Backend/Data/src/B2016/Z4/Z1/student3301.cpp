/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <utility>
#include <vector>
#include <memory>
#include <algorithm>
typedef std::pair<double, double> Tacka;

double pi = 4 * atan(1);

class Trougao{
    std::vector<Tacka> tjemena;
    static bool IstiSu(double x, double y, double greska=1e-10){
        if((x<0 && y>0) || (x>0 && y<0))
          return false;
        return std::fabs(x-y)<(greska);
    }
    static bool TriIsta (double x, double y, double z, double greska=1e-10){
        return (IstiSu(x,y,greska) && IstiSu(y, z, greska));
    }
    static void TestIndeksa(int indeks){
        if(indeks<1 || indeks>3)
          throw std::range_error("Nekorektan indeks");
    }
    
    static double DuzinaStranice(const Tacka &t1, const Tacka &t2){
        return std::sqrt((t1.first - t2.first)*(t1.first - t2.first) + ((t1.second - t2.second)*(t1.second - t2.second)));
    }
   static  double Izraz (const Tacka &t1, const Tacka &t2, const Tacka &t3){
        return (t1.first*(t2.second - t3.second) - t2.first*(t1.second - t3.second) + t3.first*(t1.second - t2.second));
    }
   static void StraniceTrougla (const Trougao &t, double &a, double &b, double &c){
        a = DuzinaStranice(t.tjemena[1], t.tjemena[2]);
        b = DuzinaStranice(t.tjemena[0], t.tjemena[2]);
        c = DuzinaStranice(t.tjemena[0], t.tjemena[1]);
    }
    static void RotirajTacku (Tacka &t1, const Tacka &t, double ugao);
    static void SkalirajTacku (Tacka &t1, const Tacka &t, double faktor);
    public:
     Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3) : tjemena(3){
        Postavi(t1, t2, t3);
     }
     void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3){
         if(IstiSu(Orijentacija(t1, t2, t3), 0))
           throw std::domain_error("Nekorektne pozicije tjemena");
          tjemena[0] = t1; tjemena[1] = t2; tjemena[2] = t3;
     }
     void Postavi(int indeks, const Tacka &t){
         TestIndeksa(indeks);
         if((indeks==1 && Orijentacija(t, tjemena[1], tjemena[2])==0) || (indeks==2 && Orijentacija(tjemena[0], t, tjemena[2])==0) || (indeks==3 && Orijentacija(tjemena[0], tjemena[1],t)==0))
            throw std::domain_error("Nekorektne pozicije tjemena");
         tjemena[indeks - 1] = t;
         
     }
     static int Orijentacija (const Tacka &t1, const Tacka &t2, const Tacka &t3){
         if(Trougao::IstiSu(Trougao::Izraz(t1, t2, t3),0))
           return 0;
         return (Izraz(t1, t2, t3) / std::abs(Izraz(t1, t2, t3)));
     }
     Tacka DajTjeme(int indeks) const{
         TestIndeksa(indeks);
         return tjemena[indeks - 1];
     }
     double DajStranicu(int indeks) const;
     double DajUgao(int indeks) const;
     Tacka DajCentar() const;
     double DajObim() const;
     double DajPovrsinu() const{
         return (0.5 * std::abs(Izraz(tjemena[0], tjemena[1], tjemena[2])));
     }
     bool DaLiJePozitivnoOrijentiran() const{
         return Orijentacija(tjemena[0], tjemena[1], tjemena[2]) > 0;
     }
     bool DaLiJeUnutra(const Tacka &t) const;
     void Ispisi() const{
         std::cout<<"(("<<tjemena[0].first<<","<<tjemena[0].second<<"),("<<tjemena[1].first<<","<<tjemena[1].second<<"),("<<tjemena[2].first<<","<<tjemena[2].second<<"))";
     }
     void Transliraj(double delta_x, double delta_y){
         
         Tacka a(std::make_pair(tjemena[0].first + delta_x, tjemena[0].second + delta_y));
         Tacka b(std::make_pair(tjemena[1].first + delta_x, tjemena[1].second + delta_y));
         Tacka c(std::make_pair(tjemena[2].first + delta_x, tjemena[2].second + delta_y));
         
         Postavi(a, b, c);
     }
     void Centriraj(const Tacka &t);
     void Rotiraj (const Tacka &t, double ugao);
     void Rotiraj(double ugao);
     void Skaliraj(const Tacka &t, double faktor);
     void Skaliraj(double faktor);
     friend bool DaLiSuIdenticni (const Trougao &t1, const Trougao &t2);
     friend bool DaLiSuPodudarni (const Trougao &t1, const Trougao &t2);
     friend bool DaLiSuSlicni (const Trougao &t1, const Trougao &t2);
};

double Trougao::DajStranicu(int indeks) const{
    TestIndeksa(indeks);
    if(indeks==1)
      return DuzinaStranice(tjemena[1], tjemena[2]);
    if(indeks==2)
      return DuzinaStranice(tjemena[0], tjemena[2]);
    return DuzinaStranice(tjemena[0], tjemena[1]);
}

double Trougao::DajUgao(int indeks) const{
    TestIndeksa(indeks);
    double a, b, c;
    StraniceTrougla(*this , a, b, c);
    if(indeks==1)
      return std::acos((b*b + c*c - a*a)/(2*b*c));
    if(indeks==2)
      return std::acos((a*a + c*c - b*b)/(2*a*c));
    return std::acos((b*b + a*a - c*c)/(2*b*a));
}

Tacka Trougao::DajCentar() const{
    double as1, as2;
    as1 = (1./3.)*(tjemena[0].first + tjemena[1].first + tjemena[2].first);
    as2 = (1./3.)*(tjemena[0].second + tjemena[1].second + tjemena[2].second);
    Tacka a(std::make_pair(as1, as2));
    return a;
}

double Trougao::DajObim() const{
    double a, b, c;
    StraniceTrougla(*this , a, b, c);
    return (a + b + c);
}

bool Trougao::DaLiJeUnutra(const Tacka &t) const{
    if(Orijentacija(tjemena[0], tjemena[1], tjemena[2])==0)
      return false;
    if(Orijentacija(tjemena[0], tjemena[1], tjemena[2]) == Orijentacija(tjemena[0], tjemena[1], t) && Orijentacija(tjemena[0], tjemena[1], t)==Orijentacija(tjemena[1], tjemena[2],t) && Orijentacija(tjemena[1], tjemena[2], t)==Orijentacija(tjemena[2], tjemena[0],t))
       return true;
    return false;
}

void Trougao::Centriraj(const Tacka &t){
    Tacka centar(DajCentar());
    double delta_x(t.first - centar.first), delta_y(t.second - centar.second);
    Transliraj(delta_x, delta_y);
}


 void Trougao::RotirajTacku(Tacka &t1, const Tacka &t, double ugao){
  
    double s = std::sin(ugao);
    t1.first-=t.first;
    t1.second-=t.second;
    double c = std::cos(ugao);
    double x_novo = t1.first*c - t1.second*s;
    double y_novo = t1.first*s + t1.second*c;
    t1.first = x_novo + t.first;
    t1.second = y_novo + t.second;
    
}

void Trougao::Rotiraj (const Tacka &t, double ugao){
    RotirajTacku(tjemena[0], t, ugao);
    RotirajTacku(tjemena[1], t, ugao);
    RotirajTacku(tjemena[2], t, ugao);
}

void Trougao::Rotiraj(double ugao){
  Rotiraj(DajCentar(), ugao);
}

void Trougao::SkalirajTacku(Tacka &t1, const Tacka &t, double faktor){
    t1.first-=t.first;
    t1.first*=faktor;
    t1.first+=t.first;
    t1.second-=t.second;
    t1.second*=faktor;
    t1.second+=t.second;
}

void Trougao::Skaliraj(const Tacka &t, double faktor){
    if(std::fabs(faktor - 0)<0.00001)
      throw std::domain_error("Nekorektan faktor skaliranja");
    SkalirajTacku(tjemena[0], t, faktor);
    SkalirajTacku(tjemena[1], t, faktor);
    SkalirajTacku(tjemena[2], t, faktor);
}

void Trougao::Skaliraj(double faktor){
   if(Trougao::IstiSu(faktor,0))
      throw std::domain_error("Nekorektan faktor skaliranja");
    SkalirajTacku(tjemena[0], DajCentar(), faktor);
    SkalirajTacku(tjemena[1], DajCentar(), faktor);
    SkalirajTacku(tjemena[2], DajCentar(), faktor);
}

bool DaLiSuIdenticni (const Trougao &t1, const Trougao &t2){
    return ((t1.tjemena[0]==t2.tjemena[0] || t1.tjemena[0]==t2.tjemena[1] || t1.tjemena[0]==t2.tjemena[2]) && (t1.tjemena[1]==t2.tjemena[1] || t1.tjemena[1]==t2.tjemena[0] || t1.tjemena[1]==t2.tjemena[2]) && (t1.tjemena[2]==t2.tjemena[2] || t1.tjemena[2]==t2.tjemena[0] || t1.tjemena[2]==t2.tjemena[1]));
}

bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2){
    double a1, b1, c1, a(0), b(0), c(0);
    Tacka A2, B2, C2;
    Trougao::StraniceTrougla(t1, a1, b1, c1);
    Trougao::StraniceTrougla (t2, a, b, c);
    if(Trougao::IstiSu(a1, a)){
        A2 = t2.tjemena[0];
    }
    else if(Trougao::IstiSu(a1, b)){
        A2 = t2.tjemena[1];
    }
    else if(Trougao::IstiSu(a1, c)){
        A2 = t2.tjemena[2];
    }
    else
      return false;
    if(Trougao::IstiSu(b1, a))
      B2 = t2.tjemena[0];
    else if(Trougao::IstiSu(b1, b))
      B2 = t2.tjemena[1];
    else if(Trougao::IstiSu(b1, c))
      B2 = t2.tjemena[2];
    else
      return false;
    if(Trougao::IstiSu(c1, a))
      C2 = t2.tjemena[0];
   else if(Trougao::IstiSu(c1, b))
      C2 = t2.tjemena[1];
    else if(Trougao::IstiSu(c1, c))
      C2 = t2.tjemena[2];
    else 
      return false;
    if(Trougao::Orijentacija(t1.tjemena[0], t1.tjemena[1], t1.tjemena[2])==Trougao::Orijentacija(A2, B2, C2))
      return true;
    return false;
}

bool DaLiSuSlicni (const Trougao &t1, const Trougao &t2){
    if(DaLiSuPodudarni(t1, t2))
      return true;
    double a1, b1, c1, a2, b2, c2;
    Tacka A2, B2, C2;
    Trougao::StraniceTrougla(t1, a1, b1, c1);
    Trougao::StraniceTrougla(t2, a2, b2, c2);
    
    if(Trougao::TriIsta((a1/a2), (b1/b2), (c1/c2))){
        A2 = t2.tjemena[0];
        B2 = t2.tjemena[1];
        C2 = t2.tjemena[2];
    }
    else if(Trougao::TriIsta((a1/b2), (b1/a2),(c1/c2))){
    
        A2 = t2.tjemena[1];
        B2 = t2.tjemena[0];
        C2 = t2.tjemena[2];
    }
    else if(Trougao::TriIsta((a1/c2), (b1/b2), (c1/a2))){
    
        A2 = t2.tjemena[2];
        B2 = t2.tjemena[1];
        C2 = t2.tjemena[0];
    }
    else if(Trougao::TriIsta((a1/a2), (b1/c2), (c1/b2))){
    
        A2 = t2.tjemena[0];
        B2 = t2.tjemena[2];
        C2 = t2.tjemena[1];
    }
    else if(Trougao::TriIsta((a1/c2), (b1/a2), (c1/b2))){
    
        A2 = t2.tjemena[2];
        B2 = t2.tjemena[0];
        C2 = t2.tjemena[1];
    }
    else if(Trougao::TriIsta((a1/b2), (b1/c2), (c1/a2))){
    
        A2 = t2.tjemena[1];
        B2 = t2.tjemena[2];
        C2 = t2.tjemena[0];
    }
    else
      return false;
    if(Trougao::Orijentacija(t1.tjemena[0], t1.tjemena[1], t1.tjemena[2])==Trougao::Orijentacija(A2, B2, C2))
      return true;
    return false;
    
}



int main ()
{
    
  int n;
    std::cout<<"Koliko zelite kreirati trouglova: ";
    std::cin>>n;
    std::vector<std::shared_ptr<Trougao>> v(n);
    std::vector<Tacka> niz(3);

    double a(0), b(0);
    for(int i=0; i<n; i++){
        std::cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
       
       for(int j=0; j<3; j++){
        
       std::cin>>a>>b;
        niz[j].first = a;
        niz[j].second = b;
        }
        try{
        Trougao t(niz[0], niz[1], niz[2]);
        
        
        v[i] = std::shared_ptr<Trougao>(new Trougao(t));
        }
        catch(std::domain_error e){
            std::cout<<e.what()<<", ponovite unos!"<<std::endl;
            i--;
        }
    }
    try{
    double delta_x, delta_y;
    std::cout<<"Unesite vektor translacije (dx dy): ";
   
    std::cin>>delta_x>>delta_y;
    
    
    
    std::transform(v.begin(), v.end(), v.begin(), [delta_x, delta_y] (std::shared_ptr<Trougao> t)->std::shared_ptr<Trougao> { (*t).Transliraj(delta_x, delta_y); return t;});
    
    double ugao_rotacije;
    std::cout<<"Unesite ugao rotacije: ";
    std::cin>>ugao_rotacije;
    std::transform(v.begin(), v.end(), v.begin(), [ugao_rotacije] (std::shared_ptr<Trougao> t) ->std::shared_ptr<Trougao> {auto p = t.get(); (*p).Rotiraj((*p).DajCentar(), ugao_rotacije); return t; });
    
    double faktor_skaliranja;
    std::cout<<"Unesite faktor skaliranja: ";
    std::cin>>faktor_skaliranja;
    std::transform(v.begin(), v.end(), v.begin(), [faktor_skaliranja] (std::shared_ptr<Trougao> t) ->std::shared_ptr<Trougao> {auto p=t.get(); (*p).Skaliraj((*p).DajTjeme(1), faktor_skaliranja); return t;});
    
	std::sort(v.begin(), v.end(), [] (std::shared_ptr<Trougao> t1, std::shared_ptr<Trougao> t2) ->bool {return (*t1).DajPovrsinu()<(*t2).DajPovrsinu();});
	std::cout<<"Trouglovi nakon obavljenih transformacija:"<<std::endl;
	std::for_each(v.begin(), v.end(), [] (std::shared_ptr<Trougao> t) {t->Ispisi(); std::cout<<std::endl;});
	
	std::cout<<"Trougao sa najmanjim obimom: ";
	auto q = std::min_element(v.begin(), v.end(), [] (std::shared_ptr<Trougao> t1, std::shared_ptr<Trougao> t2) {return (*t1).DajObim() < (*t2).DajObim();});
	auto s(*q);
	(*s).Ispisi();
	bool postoje(false);
	int brojac(0);
	for(int i=0; i<v.size(); i++)
	    for(int j=i + 1; j<v.size(); j++)
	        if(DaLiSuIdenticni(*v[i], *v[j])){
	            if(brojac==0)
	              std::cout<<"\nParovi identicnih trouglova:"<<std::endl;
	          
	            brojac++;
	            (*v[i]).Ispisi(); std::cout<<" i "; (*v[j]).Ispisi();
	            std::cout<<std::endl;
	            postoje = true;
	        }
	 if(!postoje)
	   std::cout<<"\nNema identicnih trouglova!"<<std::endl;
	postoje = false;
	brojac = 0;
	for(int i=0; i<v.size(); i++)
	  for(int j=i+1; j<v.size(); j++)
	    if(DaLiSuPodudarni(*v[i], *v[j])){
	        if(brojac==0)
	          std::cout<<"Parovi podudarnih trouglova:"<<std::endl;
	        brojac++;
	        (*v[i]).Ispisi(); std::cout<<" i "; (*v[j]).Ispisi();
	        std::cout<<std::endl;
	        postoje = true;
	    }
	if(!postoje)
	  std::cout<<"Nema podudarnih trouglova!"<<std::endl;
	postoje = false;
	brojac = 0;
	for(int i=0; i<v.size(); i++)
	  for(int j=i+1; j<v.size(); j++)
	    if(DaLiSuSlicni(*v[i], *v[j])){
	        if(brojac==0)
	          std::cout<<"Parovi slicnih trouglova:"<<std::endl;
	        brojac++;
	        (*v[i]).Ispisi(); std::cout<<" i "; (*v[j]).Ispisi();
	        std::cout<<std::endl;
	        postoje = true;
	    }
	if(!postoje)
	  std::cout<<"Nema slicnih trouglova!";
    }
    catch (std::domain_error e){
        std::cout<<e.what();
    }
    catch(std::range_error a){
        std::cout<<a.what();
    }
	return 0;
}


