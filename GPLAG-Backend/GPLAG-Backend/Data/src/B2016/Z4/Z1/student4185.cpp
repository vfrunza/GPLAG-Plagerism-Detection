/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <memory>
#include <utility>
#include <math.h>
#include <vector>
typedef std::pair<double, double> Tacka;

double Rastojanje(Tacka t1, Tacka t2) { return sqrt(pow(t1.first-t2.first,2) + pow(t1.second - t2.second, 2));}
static int Poredi( double x, double y)  { const double Eps = 1e-10; return (fabs(x-y) <= Eps * (fabs(x) - fabs(y))); }

// K L A S A 
class Trougao{
    Tacka prva,druga,treca;
// POMOCNE      
    bool IspavanIndeks(int indeks) const { if(indeks <= 0 || indeks > 3 ) return false; return true; }
    double Rastojanje (Tacka t1, Tacka t2) const { return sqrt(pow(t1.first - t2.first,2) + pow(t1.second - t2.second,2)); }
    
    double Formula(const Tacka &t1, const Tacka &t2, const Tacka &t3) const {
        double r = t1.first * (t2.second - t3.second) - t2.first * (t1.second - t3.second) + t3.first * (t1.second - t2.second);
        return r;
    }
    
    public:
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        if (Orijentacija(t1, t2, t3) == 0) throw std::domain_error("Nekorektne pozicije tjemena");
        prva = t1; druga = t2; treca = t3; 
    };
    
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        double r = t1.first * (t2.second - t3.second) - t2.first * (t1.second - t3.second) + t3.first * (t1.second - t2.second);
        if (r<0) return -1;
        if (r>0) return  1;
        return 0;
}
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuPodudarni (const Trougao &t1, const Trougao &t2);

void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    if (Orijentacija(t1,t2,t3) == 0) throw std::domain_error("Nekorektne pozicije tjemena");
    prva = t1; druga = t2; treca = t3;
}
void Postavi(int indeks, const Tacka &t){
    if(!(IspavanIndeks(indeks))) throw std::range_error("Nekorektan indeks");
    if(indeks == 1) prva = t;
    if(indeks == 2) druga = t;
    if(indeks == 3) treca = t;
}
Tacka DajTjeme(int indeks) const{
    if (!IspavanIndeks(indeks)) throw std::range_error ("Neispravan indeks");
    if (indeks == 1) return Trougao::prva;
    if (indeks == 2) return Trougao::druga;
    if (indeks == 3) return Trougao::treca;
    }
double DajStranicu(int indeks) const{
    if (!IspavanIndeks(indeks)) throw std::range_error ("Neispravan indeks");
    if (indeks == 1) return Rastojanje(druga,treca);
    if (indeks == 2) return Rastojanje(prva,treca);
    if (indeks == 3) return Rastojanje(druga,prva);
}

double DajUgao(int indeks) const{
    if (!IspavanIndeks(indeks)) throw std::range_error ("Neispravan indeks");
    double a(DajStranicu(1)), b(DajStranicu(2)), c(DajStranicu(3));
    if (indeks == 1) return acos((b*b + c*c - a*a)/(2*b*c));
    if (indeks == 2) return acos((a*a + c*c - b*b)/(2*a*c));
    if (indeks == 3) return acos((b*b + a*a - c*c)/(2*b*a));
}

Tacka DajCentar() const{
    double x = (prva.first + druga.first + treca.first) / 3;
    double y = (prva.second + druga.second + treca.second) / 3;
    Tacka nova;
    nova.first = x; 
    nova.second = y;
    return nova;
}
double DajObim() const{
    return DajStranicu(1) + DajStranicu(2) + DajStranicu(3);
}
double DajPovrsinu() const{
    return (1./2) * fabs(Formula(prva, druga, treca));
}
bool DaLiJePozitivnoOrijentiran() const{
    if(Orijentacija(prva, druga, treca) == -1) return false;
    if(Orijentacija(prva, druga, treca) ==  1) return true;
}
bool DaLiJeUnutra(const Tacka &t) const{
    if (Orijentacija(prva,druga,treca) && Orijentacija(prva,druga,t) && Orijentacija(druga,treca,t) && Orijentacija(treca,prva,t))
    return true;
    return false; 
}
void Ispisi() const{
    std::cout << "(("<<prva.first<<","<<prva.second<<"),("<<druga.first<<","<<druga.second<<"),("<<treca.first<<","<<treca.second<<"))";
}
void Transliraj(double delta_x, double delta_y){
    
    prva.first  += delta_x;  prva.second += delta_y;
    druga.first += delta_x; druga.second += delta_y;
    treca.first += delta_x; treca.second += delta_y;
}
void Centriraj(const Tacka &t){
    Tacka centar = DajCentar();
    double deltax = t.first - centar.first;
    double deltay = t.second - centar.second;
    Trougao::Transliraj(deltax, deltay);
}
void Skaliraj(const Tacka &t, double faktor) {
    if (Poredi(faktor, 0)) throw std::domain_error ("Nekorektne faktor skaliranja");
    Tacka jedan(prva), dva(druga), tri(treca);
    prva.first   = t.first + faktor * (jedan.first - t.first);
    prva.second  = t.second + faktor * (jedan.second - t.second);
    druga.first  = t.first + faktor * (dva.first - t.first);
    druga.second = t.second + faktor * (dva.second - t.second);
    treca.first  = t.first + faktor * (tri.first - t.first);
    treca.second = t.second + faktor * (tri.second - t.second);
    
}
void Skaliraj(double faktor){
     Skaliraj(DajCentar(), faktor);
}
void Rotiraj(const Tacka &t, double ugao){
    Tacka jedan(prva), dva(druga), tri(treca);
    prva.first  = t.first + cos(ugao) * (jedan.first - t.first) - sin(ugao) * (jedan.second - t.second);
    druga.first = t.first + cos(ugao) * (dva.first - t.first) - sin(ugao) * (dva.second - t.second);
    treca.first = t.first + cos(ugao) * (tri.first - t.first) - sin(ugao) * (tri.second - t.second);
    
    prva.second  = t.second + sin(ugao) * (jedan.first - t.first) + (jedan.second - t.second) * cos(ugao);
    druga.second = t.second + sin(ugao) * (dva.first - t.first) + (dva.second - t.second) * cos(ugao);
    treca.second = t.second + sin(ugao) * (tri.first - t.first) + (tri.second - t.second) * cos(ugao);
}
void Rotiraj(double ugao) {
    Trougao::Rotiraj(DajCentar(), ugao);
}
};
// P R I J A T E LJ S K E
bool DaLiSuIdenticni(const Trougao &u1,const Trougao &u2){
    std::vector<Tacka> u11{u1.DajTjeme(1), u1.DajTjeme(2), u1.DajTjeme(3)}, u22{u2.DajTjeme(1), u2.DajTjeme(2), u2.DajTjeme(3)} ;
    
    for(int i = 0; i < 3; i++){
        for(int j = i+1; j < 3; j++){
            if(u11[i].first > u11[j].first){
                Tacka temp = u11[i];
                u11[i] = u11[j];
                u11[j] = temp;
            }
            if(u22[i].first > u22[j].first){
                Tacka temp1 = u22[i];
                u22[i] = u22[j];
                u22[j] = temp1;
            }
        }
    }
            int brojac = 0;
            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    if (Poredi(u11[i].first, u22[j].first) && Poredi(u11[i].second, u22[j].second)) brojac++;
                }
            }
            if(brojac == 3) return true;
            return false;
}

 bool DaLiSuPodudarni(const Trougao &u1,const  Trougao &u2){
    std::vector<std::pair<Tacka, double> > u11(3), u22(3);
    
    u11[0] = std::make_pair(u1.DajTjeme(1), Rastojanje(u1.DajTjeme(2), u1.DajTjeme(3)));
    u11[1] = std::make_pair(u1.DajTjeme(2), Rastojanje(u1.DajTjeme(1), u1.DajTjeme(3)));
    u11[2] = std::make_pair(u1.DajTjeme(3), Rastojanje(u1.DajTjeme(1), u1.DajTjeme(2)));
    
    u22[0] = std::make_pair(u2.DajTjeme(1), Rastojanje(u2.DajTjeme(2), u2.DajTjeme(3)));
    u22[1] = std::make_pair(u2.DajTjeme(2), Rastojanje(u2.DajTjeme(1), u2.DajTjeme(3)));
    u22[2] = std::make_pair(u2.DajTjeme(3), Rastojanje(u2.DajTjeme(1), u2.DajTjeme(2)));
    for(int i = 0; i < 3; i++){
        for(int j = i + 1; j < 3; j++){
            if (u11[i].second > u11[j].second) {
                std::pair<Tacka, double> temp = u11[i];
                u11[i] = u11[j];
                u11[j] = temp;
            }
            if(u22[i].second > u22[j].second) {
                std::pair<Tacka, double> temp1 = u22[i];
                u22[i] = u22[j];
                u22[j] = temp1;
            }
        }
    }
    int brojac = 0;
    if(u22[0].second == u11[0].second && u11[1].second == u22[1].second && u11[2].second == u22[2].second) brojac =3;
    if (brojac == 3){
    if(u1.Orijentacija(u11[0].first, u11[1].first, u11[2].first) == u2.Orijentacija(u22[0].first, u22[1].first, u22[2].first))
    return true;
    }
    return false;
}

bool DaLiSuSlicni(const Trougao &u1,const Trougao &u2){
    std::vector<std::pair<Tacka, double> > u11(3), u22(3);
    
    u11[0] = std::make_pair(u1.DajTjeme(1), Rastojanje(u1.DajTjeme(2), u1.DajTjeme(3)));
    u11[1] = std::make_pair(u1.DajTjeme(2), Rastojanje(u1.DajTjeme(1), u1.DajTjeme(3)));
    u11[2] = std::make_pair(u1.DajTjeme(3), Rastojanje(u1.DajTjeme(1), u1.DajTjeme(2)));
    
    u22[0] = std::make_pair(u2.DajTjeme(1), Rastojanje(u2.DajTjeme(2), u2.DajTjeme(3)));
    u22[1] = std::make_pair(u2.DajTjeme(2), Rastojanje(u2.DajTjeme(1), u2.DajTjeme(3)));
    u22[2] = std::make_pair(u2.DajTjeme(3), Rastojanje(u2.DajTjeme(1), u2.DajTjeme(2)));
    for(int i = 0; i < 3; i++){
        for(int j = i + 1; j < 3; j++){
            if(u11[i].second > u11[j].second){
                std::pair<Tacka, double> temp = u11[i];
                u11[i] = u11[j];
                u11[j] = temp;
            }
            if(u22[i].second > u22[j].second){
                std::pair<Tacka, double> temp1 = u22[i];
                u22[i] = u22[j];
                u22[j] = temp1;
            }
        }
    }
    int brojac = 0;
   if(Poredi(u11[0].second/u22[0].second,u11[1].second/u22[1].second) && Poredi(u11[1].second/u22[1].second, u11[2].second/u22[2].second)) brojac = 3;
    if(brojac == 3){
      if(u1.Orijentacija(u11[0].first, u11[1].first, u11[2].first) == u2.Orijentacija(u22[0].first, u22[1].first, u22[2].first))
        return true;
    }
    return false;
}
int main ()
{ std::cout << "Koliko zelite kreirati trouglova: ";
    int n;
    std::cin >> n;
    std::vector<std::shared_ptr<Trougao>> vec;
    for(int i = 0; i < n; i++){
        std::cout << "Unesite podatke za "<<i+1 <<". trougao (x1 y1 x2 y2 x3 y3): ";
        double x1, y1, x2, y2, x3, y3;
        std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >>y3;
        Tacka t1 = std::make_pair(x1,y1);
        Tacka t2 = std::make_pair(x2,y2);
        Tacka t3 = std::make_pair(x3,y3);
        std::shared_ptr<Trougao> pok;
        try{
            pok = std::make_shared<Trougao> (t1, t2, t3);
        }
        catch (...){
            std::cout << "Nekorektne pozicije tjemena, ponovite unos!"<<std::endl;
            i--;
            continue;
        }
        vec.push_back(pok);
    }
    
    
 std::cout << "Unesite vektor translacije (dx dy): ";    
 double deltax, deltay;
 std::cin >> deltax >> deltay;
 std::cout << "Unesite ugao rotacije: ";
 double ugao; 
 std::cin >> ugao;
 std::cout << "Unesite faktor skaliranja: ";
 double faktor;
 std::cin >> faktor;
 std::transform(vec.begin(), vec.end(),vec.begin(), [deltax, deltay, ugao, faktor](std::shared_ptr<Trougao> t){
     (*t).Transliraj(deltax,deltay); 
     (*t).Rotiraj(ugao);
     (*t).Skaliraj((*t).DajTjeme(1),faktor);
     return t;
 });
 std::sort(vec.begin(), vec.end(), [](std::shared_ptr<Trougao> u1, std::shared_ptr<Trougao> u2){
     return (*u1).DajPovrsinu() < (*u2).DajPovrsinu();
 });
 std::cout << "Trouglovi nakon obavljenih transformacija:" << std::endl;
 std::for_each(vec.begin(), vec.end(), [](std::shared_ptr<Trougao> t){
     (*t).Ispisi(); std::cout << std::endl;
 });
    auto max = std::min_element(vec.begin(),vec.end(),[](std::shared_ptr<Trougao> u1, std::shared_ptr<Trougao> u2){
        return (*u1).DajObim() < (*u2).DajObim();
    });
   std::cout << "Trougao sa najmanjim obimom: " ;
   (*max)->Ispisi(); std::cout << std::endl;
   
   
   
    int s(0), id(0), p(0);
    std::vector<std::shared_ptr<Trougao>> slicni, podudarni, identicni ;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(DaLiSuIdenticni(*vec[i], *vec[j])) {id++; identicni.push_back(vec[i]); identicni.push_back(vec[j]);}
            if(DaLiSuPodudarni(*vec[i], *vec[j])){ p++; }
            if(DaLiSuSlicni(*vec[i],*vec[j])) {s++; slicni.push_back(vec[i]); slicni.push_back(vec[j]);}
            } 
        }
// I D E N T I C N I 
    if(id!=0){
        std::cout << "Parovi identicnih trouglova:" << std::endl;
    for(int i = 0; i < identicni.size(); i+=2){
        (*identicni[i]).Ispisi(); std::cout  << " i ";  (*identicni[i+1]).Ispisi();
        std::cout  << std::endl;
    }
    }
    else {std::cout << "Nema identicnih trouglova!" << std::endl;}
// P O D U D A R N I 
   if(p!=0){
       std::cout << "Parovi podudarnih trouglova:" << std::endl;
       for(int i = 0; i < n; i++){
           for(int j = i+1; j < n; j++){
               if(DaLiSuPodudarni(*vec[i], *vec[j])){
                   (*vec[i]).Ispisi(); std::cout << " i "; (*vec[j]).Ispisi();
                   std::cout  << std::endl;
               }
           }
       }
   }
   else std::cout << "Nema podudarnih trouglova!" << std::endl;
// S L I C N I 
   if(s!=0){
       std::cout << "Parovi slicnih trouglova:" << std::endl;
   for(int i = 0; i<n; i++){
        for(int j = i+1 ; j < n ; j++){
            if((vec[i]!=vec[j]) && DaLiSuSlicni(*vec[i], *vec[j])){ (*vec[i]).Ispisi(); std::cout << " i "; (*vec[j]).Ispisi(); 
                std::cout << std::endl;
            }
        }
    } 
   }
   else std::cout << "Nema slicnih trouglova!" << std::endl;
  
	return 0;
}