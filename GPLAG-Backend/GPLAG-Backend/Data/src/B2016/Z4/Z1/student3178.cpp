#include <new>
#include <memory>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <utility>
#include <stdexcept>
#include <algorithm>
#include <cmath>
#include <iomanip>

typedef std::pair<double, double> Tacka;
const double Eps = 1e-10;

class Trougao{
    std::vector<Tacka> tjemena;  //tjemena(3,std:make_pair(0,0));
    
    static bool JesuLiJednaki(double x, double y,double Eps = 1e-10){
        return (std::fabs(x-y) <= Eps*(std::fabs(x) + std::fabs(y)));
    }
    
    static double DajDuzinuDuzi(Tacka t1, Tacka t2) {
        double d;
        d = sqrt((t2.first - t1.first)*(t2.first - t1.first) + (t2.second - t1.second)*(t2.second - t1.second));
        return d;
    }
   
   static double DajIzraz(Tacka t1, Tacka t2, Tacka t3) {
       return (t1.first*(t2.second - t3.second) +  t2.first*(t1.second - t3.second) +  t3.first*(t1.second - t2.second));
   }
   static Trougao PreurediTjemena(Trougao t){
       if(t.DajUgao(1)>t.DajUgao(2)) std::swap(t.tjemena[0],t.tjemena[1]);
       if(t.DajUgao(2)>t.DajUgao(3)) std::swap(t.tjemena[1],t.tjemena[2]);
       if(t.DajUgao(1)>t.DajUgao(3)) std::swap(t.tjemena[0],t.tjemena[2]);
       return t;
   }


 static bool JesuLiJednakeStranice(Trougao t1, Trougao t2) {
       double a1=t1.DajDuzinuDuzi(t1.tjemena[0],t1.tjemena[1]);
       double b1=t1.DajDuzinuDuzi(t1.tjemena[1],t1.tjemena[2]);
       double c1=t1.DajDuzinuDuzi(t1.tjemena[0],t1.tjemena[2]);
       double a2=t2.DajDuzinuDuzi(t2.tjemena[0],t2.tjemena[1]);
       double b2=t2.DajDuzinuDuzi(t2.tjemena[1],t2.tjemena[2]);
       double c2=t2.DajDuzinuDuzi(t2.tjemena[0],t2.tjemena[2]);
       if((Trougao::JesuLiJednaki(a1,a2) && Trougao::JesuLiJednaki(b1,b2) && Trougao::JesuLiJednaki(c1,c2)) || (Trougao::JesuLiJednaki(a1,a2) && Trougao::JesuLiJednaki(b1,c2) && Trougao::JesuLiJednaki(c1,b2)) || (Trougao::JesuLiJednaki(a1,b2) && Trougao::JesuLiJednaki(b1,a2) && Trougao::JesuLiJednaki(c1,c2)) || (Trougao::JesuLiJednaki(a1,b2) && Trougao::JesuLiJednaki(c1,a2) && Trougao::JesuLiJednaki(b1,c2)) || (Trougao::JesuLiJednaki(a1,c2) && Trougao::JesuLiJednaki(b1,a2) && Trougao::JesuLiJednaki(c1,b2)) || (Trougao::JesuLiJednaki(a1,c2) && Trougao::JesuLiJednaki(b1,b2) && Trougao::JesuLiJednaki(c1,a2)) ||  (Trougao::JesuLiJednaki(a1,a2) && Trougao::JesuLiJednaki(b1,b2) && Trougao::JesuLiJednaki(c1,a2))  ){
        return true;}
       else return false;
   }
   
 //   static bool JesuLiProporcionalneStranice(Trougao t1, Trougao t2) {    
 
 //   }
    
    public:

Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    if(Trougao::Orijentacija(t1,t2,t3) == 0) throw std::domain_error("Nekorektne pozicije tjemena");
    Postavi(t1,t2,t3);
}

void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3);
void Postavi(int indeks, const Tacka &t);
static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3);

Tacka DajTjeme(int indeks) const{ 
     if(indeks != 1 || indeks !=2 || indeks !=3) throw std::range_error("Nekorektan indeks");
     return tjemena[indeks-1]; }

double DajStranicu(int indeks) const;
double DajUgao(int indeks) const;

Tacka DajCentar() const;

double DajObim() const{
     return (Trougao::DajDuzinuDuzi(tjemena[0],tjemena[1]) + Trougao::DajDuzinuDuzi(tjemena[0],tjemena[2]) + Trougao::DajDuzinuDuzi(tjemena[1],tjemena[2]));//legitivmno?
}

double DajPovrsinu() const{
    double povrsina;
    povrsina = (1/2)* std::fabs(DajIzraz(tjemena[0],tjemena[1],tjemena[2]));//da li je ovo legitiman poziv privtnih atributa)??
    return povrsina;
}

bool DajLiJePozitivnoOrijentiran() const{
    int n;
    n=Trougao::Orijentacija(tjemena[0],tjemena[1],tjemena[2]);
    if(Trougao::JesuLiJednaki(n,1)) //OVDE MOZDA NIJE MORALO SA JESI LIO JEFNALKI
    return true;
    else return false;
}

bool DajLiJeUnutra(const Tacka &t ) const;
void Ispisi() const;
void Transliraj(double delta_x, double delta_y);
void Centriraj(const Tacka &t);
void Rotiraj(const Tacka &t, double ugao);
void Skaliraj(const Tacka &t, double faktor);
void Rotiraj( double ugao);
void Skaliraj(double faktor);
friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);
};



void Trougao::Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    if(Trougao::Orijentacija(t1,t2,t3)==0) throw std::domain_error("Nekorektne pozicije tjemena");
    
    tjemena[0].first=t1.first; 
    tjemena[0].second=t1.second;
    tjemena[1].first=t2.first; 
    tjemena[1].second=t2.second;
    tjemena[2].first=t3.first; 
    tjemena[2].second=t3.second;
}

void Trougao::Postavi(int indeks, const Tacka &t){
    if(indeks != 1 || indeks !=2 || indeks !=3) throw std::range_error("Nekorektan indeks");
  //  if(Trougao::Orijentacija(t1,t2,t3)==0) throw std::domain_error("Nekorektne pozicije tjemena");
    
    if(indeks ==1) {
    tjemena[0].first=t.first; 
    tjemena[0].second=t.second;}
    else if(indeks ==2) {
    tjemena[1].first=t.first; 
    tjemena[1].second=t.second;}
    else if(indeks ==3) {
    tjemena[2].first=t.first; 
    tjemena[2].second=t.second;}
}

int Trougao::Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    double indikator;
    indikator = DajIzraz(t1,t2,t3);
    if ((indikator>0) && !JesuLiJednaki(indikator,0)) return 1;
    if (JesuLiJednaki(indikator,0)) return 0;
    if ((indikator<0) && !JesuLiJednaki(indikator,0)) return -1; 
}

double Trougao::DajStranicu(int indeks) const{
    if(indeks != 1 || indeks !=2 || indeks !=3) throw std::range_error("Nekorektan indeks");
    double duzina{0};
    if(indeks==1){ duzina=DajDuzinuDuzi(tjemena[1], tjemena[2]);}
    else if(indeks==2){ duzina=DajDuzinuDuzi(tjemena[0], tjemena[2]);}
    else if(indeks==3){ duzina=DajDuzinuDuzi(tjemena[0], tjemena[1]);}
    return duzina;
}

double Trougao::DajUgao(int indeks) const{
     if(indeks != 1 || indeks !=2 || indeks !=3) throw std::range_error("Nekorektan indeks");
     double alfa, beta, gama;
     double a,b,c;
     a=DajDuzinuDuzi(tjemena[1],tjemena[2]);
     b=DajDuzinuDuzi(tjemena[0],tjemena[2]);
     c=DajDuzinuDuzi(tjemena[0],tjemena[1]);
     if(indeks==1){
         alfa= acos((b*b + c*c - a*a)/2*b*c);
         return alfa;}
     else if(indeks==2){
         beta= acos((a*a + c*c - b*b)/2*a*c);
         return beta;}
     else if(indeks==3){
         gama= acos((a*a + b*b - c*c)/2*a*b);
         return gama;}
}


Tacka Trougao::DajCentar() const{
    double x,y;
    x=(tjemena[0].first + tjemena[1].first + tjemena[2].first)/3 ;
    y=(tjemena[0].second + tjemena[1].second + tjemena[2].second)/3;
    return std::make_pair(x,y);
}

bool Trougao::DajLiJeUnutra(const Tacka &t ) const{
    if(Trougao::Orijentacija(tjemena[0],tjemena[1],tjemena[2]) != 0 && Trougao::Orijentacija(tjemena[0],tjemena[1],tjemena[2]) == Trougao::Orijentacija(tjemena[0],tjemena[1],t) && Trougao::Orijentacija(tjemena[0],tjemena[1],t) == Trougao::Orijentacija(tjemena[1],tjemena[2],t) && Trougao::Orijentacija(tjemena[1],tjemena[2],t) == Trougao::Orijentacija(tjemena[2],tjemena[0],t))
    return true;
    else return false;
}

void Trougao::Ispisi() const{
    std::cout<< "((" << tjemena[0].first << "," << tjemena[0].second <<"),(" << tjemena[1].first << "," << tjemena[1].second  <<"),(" << tjemena[2].first << "," << tjemena[2].second  <<"))";
}


    
void Trougao::Rotiraj(const Tacka &t, double ugao){
    tjemena[0].first = t.first + (tjemena[0].first - t.first)*cos(ugao) - (tjemena[0].second - t.second)*sin(ugao);
    tjemena[0].second = t.second + (tjemena[0].first - t.first)*sin(ugao) + (tjemena[0].second - t.second)*cos(ugao);
    tjemena[1].first = t.first + (tjemena[1].first - t.first)*cos(ugao) - (tjemena[1].second - t.second)*sin(ugao);
    tjemena[1].second = t.second + (tjemena[1].first - t.first)*sin(ugao) + (tjemena[1].second - t.second)*cos(ugao);
    tjemena[2].first = t.first + (tjemena[2].first - t.first)*cos(ugao) - (tjemena[2].second - t.second)*sin(ugao);
    tjemena[2].second = t.second + (tjemena[2].first - t.first)*sin(ugao) + (tjemena[2].second - t.second)*cos(ugao);
}

void Trougao::Skaliraj(const Tacka &t, double faktor){
    if(Trougao::JesuLiJednaki(faktor,0)) std::domain_error ("Nekorektan faktor skaliranja");
    tjemena[0].first = t.first + faktor*(tjemena[0].first - t.first);
    tjemena[0].second = t.second + faktor*(tjemena[0].second - t.second);
    tjemena[1].first = t.first + faktor*(tjemena[1].first - t.first);
    tjemena[1].second = t.second + faktor*(tjemena[1].second - t.second);
    tjemena[2].first = t.first + faktor*(tjemena[2].first - t.first);
    tjemena[2].second = t.second + faktor*(tjemena[2].second - t.second);
    
}

void Trougao::Rotiraj( double ugao){
    Tacka t= Trougao::DajCentar();
    tjemena[0].first = t.first + (tjemena[0].first - t.first)*cos(ugao) - (tjemena[0].second - t.second)*sin(ugao);
    tjemena[0].second = t.second + (tjemena[0].first - t.first)*sin(ugao) + (tjemena[0].second - t.second)*cos(ugao);
    tjemena[1].first = t.first + (tjemena[1].first - t.first)*cos(ugao) - (tjemena[1].second - t.second)*sin(ugao);
    tjemena[1].second = t.second + (tjemena[1].first - t.first)*sin(ugao) + (tjemena[1].second - t.second)*cos(ugao);
    tjemena[2].first = t.first + (tjemena[2].first - t.first)*cos(ugao) - (tjemena[2].second - t.second)*sin(ugao);
    tjemena[2].second = t.second + (tjemena[2].first - t.first)*sin(ugao) + (tjemena[2].second - t.second)*cos(ugao);
}

void Trougao::Skaliraj(double faktor){
    if(Trougao::JesuLiJednaki(faktor,0)) std::domain_error ("Nekorektan faktor skaliranja");
    Tacka t = Trougao::DajCentar();
    tjemena[0].first = t.first + faktor*(tjemena[2].first - t.first);
    tjemena[0].second = t.second + faktor*(tjemena[0].second - t.second);
    tjemena[1].first = t.first + faktor*(tjemena[1].first - t.first);
    tjemena[1].second = t.second + faktor*(tjemena[1].second - t.second);
    tjemena[2].first = t.first + faktor*(tjemena[2].first - t.first);
    tjemena[2].second = t.second + faktor*(tjemena[2].second - t.second);
}


void Trougao::Transliraj(double delta_x, double delta_y){
     tjemena[0].first += delta_x;
     tjemena[0].second += delta_y;
     tjemena[1].first += delta_x;
     tjemena[1].second += delta_y;
     tjemena[2].first += delta_x;
     tjemena[2].second += delta_y;
}

void Trougao::Centriraj(const Tacka &t){
    Tacka c;
    c = DajCentar();
    double x_raz, y_raz;
    x_raz=t.first - c.first;
    y_raz=t.second - c.second;
    
    tjemena[0].first += x_raz;
    tjemena[0].second += y_raz;
    tjemena[1].first += x_raz;
    tjemena[1].second += y_raz;
    tjemena[2].first += x_raz;
    tjemena[2].second += y_raz;
}
bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2){
    int brojac{0};
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(t1.JesuLiJednaki(t1.tjemena[i].first, t2.tjemena[j].first) && t1.JesuLiJednaki(t1.tjemena[i].second, t2.tjemena[j].second)){
        brojac++;
        break;}
    }
}
if(brojac==3) return true;
else return false;
}

bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2){
   Trougao pomocni1 = Trougao::PreurediTjemena(t1);
   Trougao pomocni2 = Trougao::PreurediTjemena(t2);
   if(Trougao::Orijentacija(pomocni1.tjemena[0], pomocni1.tjemena[1], pomocni1.tjemena[2]) == Trougao::Orijentacija(pomocni2.tjemena[0], pomocni2.tjemena[1], pomocni2.tjemena[2])  && Trougao::JesuLiJednakeStranice(t1,t2))
          return true;
   return false;
    
}
/*
bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2){
    Trougao pomocni1 = Trougao::PreurediTjemena(t1);
   Trougao pomocni2 = Trougao::PreurediTjemena(t2);
   if(Trougao::Orijentacija(pomocni1.tjemena[0], pomocni1.tjemena[1], pomocni1.tjemena[2]) == Trougao::Orijentacija(pomocni2.tjemena[0], pomocni2.tjemena[1], pomocni2.tjemena[2])  && Trougao::JesuLiProporcionalneStranice(t1,t2))
          return true;
   return false;
}
*/
int main ()
{
    int n;
    std::cout << "Koliko zelite kreirati trouglova: "; //da li ovdje bacati izuzetak;
    std::cin>> n;
    
    try{
        std::vector<std::shared_ptr<Trougao>> p(n); 
        for(int i=0; i<n; i++) p[i] = nullptr;
        
        try{
            for(int i=0; i<n; i++){
                Tacka a,b,c;
                double x1,y1,x2,y2,x3,y3;
                std::cout<< "Unesite podatke za "<< i+1 << " trougao (x1 y1 x2 y2 x3 y3): ";
                std::cin>>  x1 >> y1 >> x2 >> y2 >> x3 >> y3;
                a=std::make_pair(x1,y1);
                b=std::make_pair(x2,y2);
                c=std::make_pair(x3,y3);
                if(Trougao::Orijentacija(a,b,c) == 0) {std::cout<<"Od zadanih tjemena se ne moze formirati trougao, unesite ponovo"; i--; break;}
                p[i]= std::make_shared<Trougao>(a,b,c);//ili push bac?? // poziv kontruktora!!! 
            }
        }
        catch(std::bad_alloc){
            throw;}
            double tx, ty;
            double ugao, faktor;
            std::cout << "Unesite podatke za transliranje (dx, dy): ";
            std::cin >> tx >> ty;
            std::cout << "Unesite ugao rotacije: ";
            std::cin >> ugao;
            std::cout << "Unesite faktor skaliranja: ";
            std::cin >> faktor;
            std::transform(p.begin(), p.begin()+n, p.begin(), [tx, ty, ugao, faktor](std::shared_ptr<Trougao> pok){
                pok->Transliraj(tx,ty);
                pok->Rotiraj(pok->DajCentar(),ugao);
                pok->Skaliraj(pok->DajTjeme(1),faktor);
                return pok;});
                
          //
          
         std::sort(p.begin(), p.end(), [](std::shared_ptr<Trougao> pok1, std::shared_ptr<Trougao> pok2 ){return pok1->DajPovrsinu() > pok2->DajPovrsinu();});
            
            std::cout << "Trouglovi, nakon transformacija: " << std::endl;
            std::for_each(p.begin(), p.begin()+n, [](std::shared_ptr<Trougao> pok){//ili for_each
                pok->Ispisi();
                std::cout << std::endl;});
            std::cout << "Trougao sa najmanjim obimom: ";
            auto najmanji=std::min_element(p.begin(), p.begin()+n, [](std::shared_ptr<Trougao> pok1, std::shared_ptr<Trougao> pok2){
                return pok1->DajObim() > pok2->DajObim() || std::fabs(pok1->DajObim()-pok2->DajObim())<=Eps;});
            (**najmanji).Ispisi();}
            
          /*  for(int i=0; i<p.size(); i++){
            while(i<p.size() ){
                
               if(Trougao::JesuLiPodudarni(p[i], p[i+1)
                std::cout << "Parovi identicnih trouglova: " <<std::endl;
            }
            }
    std::cout << "Parovi podudarnih trouglova: " <<std::endl;
    
    std::cout << "Parovi slicnih trouglova: " <<std::endl;*/
    
    catch(std::logic_error e){
       std::cout << e.what() << std::endl;
    }
    catch(std::range_error e){
       std::cout << e.what() << std::endl;
    }
         //   for(int i=0; i<n; i++) delete p[i];
         //   delete[] p;
         //   p=nullptr;
  
	return 0;
}