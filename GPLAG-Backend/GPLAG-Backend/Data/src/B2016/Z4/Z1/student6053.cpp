/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include<stdexcept>
#include<utility>
#include<cmath>
#include<vector>
#include<memory>

#define epsilon 0000000000.1
using namespace std;

typedef pair<double, double> Tacka;
class Trougao{
    Tacka tacka_1, tacka_2, tacka_3;
    static bool Uporedi(double x,double y){
        if(fabs(x-y)<=epsilon) return true;
        return false;
    }
    public:

Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3);
void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3);
void Postavi(int indeks, const Tacka &t);
static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    if((t1.first*(t2.second-t3.second))-(t2.first*(t1.second-t3.second))-(t3.first*(t1.second-t2.second))>0) return 1; 
     if((t1.first*(t2.second-t3.second))-(t2.first*(t1.second-t3.second))-(t3.first*(t1.second-t2.second))<0) return -1;
     // if((t1.first*(t2.second-t3.second))-(t2.first*(t1.second-t3.second))-(t3.first*(t1.second-t2.second))==0); 
}
Tacka DajTjeme(int indeks) const;
double DajStranicu(int indeks) const;
double DajUgao(int indeks) const;
Tacka DajCentar() const;
double DajObim() const{ return DajStranicu(1)+DajStranicu(2)+DajStranicu(3);}
double DajPovrsinu() const{ double s(DajObim()/2);return sqrt(s*(s-DajStranicu(1))*(s-DajStranicu(2))*(s-DajStranicu(3)));}
bool DaLiJePozitivnoOrijentiran() const{
if((tacka_1.first*(tacka_2.second-tacka_3.second))-(tacka_2.first*(tacka_1.second-tacka_3.second))-(tacka_3.first*(tacka_1.second-tacka_2.second))>0) return true; return false;}
bool DaLiJeUnutra(const Tacka &t) const;
void Ispisi() const;
void Transliraj(double delta_x, double delta_y);
void Centriraj(const Tacka &t);
void Rotiraj(const Tacka &t, double ugao);
void Skaliraj(const Tacka &t, double faktor);
void Rotiraj(double ugao);
void Skaliraj(double faktor);
friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2){
        if(Uporedi(t1.tacka_1.first,t2.tacka_1.first) && Uporedi(t1.tacka_1.second,t2.tacka_1.second)){
        if(Uporedi(t1.tacka_2.first,t2.tacka_2.first) && Uporedi(t1.tacka_2.second,t2.tacka_2.second) && Uporedi(t1.tacka_3.first,t2.tacka_3.first) && Uporedi(t1.tacka_3.second,t2.tacka_3.second))
        return true;
        if(Uporedi(t1.tacka_2.first,t2.tacka_3.first) && Uporedi(t1.tacka_2.second,t2.tacka_3.second) && Uporedi(t1.tacka_3.first,t2.tacka_2.first) && Uporedi(t1.tacka_3.second,t2.tacka_2.second))
        return true;
        }
        
    if(Uporedi(t1.tacka_1.first,t2.tacka_2.first) && Uporedi(t1.tacka_1.second,t2.tacka_2.second)){
        if(Uporedi(t1.tacka_2.first,t2.tacka_1.first) && Uporedi(t1.tacka_2.second,t2.tacka_1.second) && Uporedi(t1.tacka_3.first,t2.tacka_3.first) && Uporedi(t1.tacka_3.second,t2.tacka_3.second))
        return true;
        if(t1.tacka_2.first-t2.tacka_3.first<epsilon && t1.tacka_2.second-t2.tacka_3.second<epsilon && t1.tacka_3.first-t2.tacka_1.first<epsilon && t1.tacka_3.second-t2.tacka_1.second<epsilon)
        return true;
        }
    if(Uporedi(t1.tacka_1.first,t2.tacka_3.first) && Uporedi(t1.tacka_1.second,t2.tacka_3.second)){
        if(Uporedi(t1.tacka_2.first,t2.tacka_1.first) && Uporedi(t1.tacka_2.second,t2.tacka_1.second) && Uporedi(t1.tacka_3.first,t2.tacka_2.first) && Uporedi(t1.tacka_3.second,t2.tacka_2.second))
        return true;
        if(Uporedi(t1.tacka_2.first,t2.tacka_2.first) && Uporedi(t1.tacka_2.second,t2.tacka_2.second) && Uporedi(t1.tacka_3.first,t2.tacka_1.first) && Uporedi(t1.tacka_3.second,t2.tacka_1.second))
        return true;
        }
    return false;

}

friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2){
    if(Uporedi(t1.DajStranicu(1),t2.DajStranicu(1)) && Uporedi(t1.DajStranicu(2),t2.DajStranicu(2)) && Uporedi(t1.DajStranicu(3),t2.DajStranicu(3))) return true;
    return false;
}
friend bool TrougaoDaLiSuSlicni(const Trougao &t1, const Trougao &t2){
    
        if(Uporedi((t1.DajStranicu(1)/t2.DajStranicu(1)),(t1.DajStranicu(2)/t2.DajStranicu(2))) && Uporedi((t1.DajStranicu(3)/t2.DajStranicu(3)),(t1.DajStranicu(1)/t2.DajStranicu(1))) && Uporedi((t1.DajStranicu(3)/t2.DajStranicu(3)),(t1.DajStranicu(2)/t2.DajStranicu(2))))
        return true;
        return false;
}
};

Trougao::Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    if(Uporedi((t2.first-t1.first)/(t3.first-t1.first),(t2.second-t1.second)/(t3.second-t1.second))) throw domain_error("Nekorektne pozicije tjemena");
    Postavi(t1, t2, t3);
}
void Trougao::Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    if(Uporedi((t2.first-t1.first)/(t3.first-t1.first),(t2.second-t1.second)/(t3.second-t1.second))) throw domain_error("Nekorektne pozicije tjemena");
    tacka_1=t1; tacka_2=t2; tacka_3=t3;
}
void Trougao::Postavi(int indeks, const Tacka &t){
if(indeks<0 || indeks>3) throw range_error ("Nekorektan indeks");
if(indeks==1) tacka_1=t;
if(indeks==2) tacka_2=t;
if(indeks==3) tacka_3=t;
}
Tacka Trougao::DajTjeme(int indeks) const { 
if(indeks<0 || indeks>3) throw range_error ("Nekorektan indeks");
if(indeks==1) return tacka_1; if(indeks==2) return tacka_2;  if(indeks==3) return tacka_3;
}
double Trougao::DajStranicu(int indeks) const{
    if(indeks<0 || indeks>3) throw range_error ("Nekorektan indeks");
    if(indeks==1) return (sqrt(tacka_3.first-tacka_2.first)*(tacka_3.first-tacka_2.first)+(tacka_3.second-tacka_2.second)*(tacka_3.second-tacka_2.second));
    if(indeks==2) return (sqrt(tacka_3.first-tacka_1.first)*(tacka_3.first-tacka_1.first)+(tacka_3.second-tacka_1.second)*(tacka_3.second-tacka_1.second));
    if(indeks==3) return (sqrt(tacka_2.first-tacka_1.first)*(tacka_2.first-tacka_1.first)+(tacka_2.second-tacka_1.second)*(tacka_2.second-tacka_1.second));
}
double Trougao::DajUgao(int indeks) const{
     if(indeks<0 || indeks>3) throw range_error ("Nekorektan indeks");
     if(indeks==1) return acos((DajStranicu(2)*DajStranicu(2)+DajStranicu(3)*DajStranicu(3)-DajStranicu(1)*DajStranicu(1))/2*DajStranicu(2)*DajStranicu(3));
     if(indeks==2) return acos((DajStranicu(3)*DajStranicu(3)+DajStranicu(1)*DajStranicu(1)-DajStranicu(2)*DajStranicu(2))/2*DajStranicu(1)*DajStranicu(3));
     if(indeks==3) return acos((DajStranicu(1)*DajStranicu(1)+DajStranicu(2)*DajStranicu(2)-DajStranicu(3)*DajStranicu(3))/2*DajStranicu(1)*DajStranicu(2));
}
Tacka Trougao::DajCentar() const{ Tacka aritmeticka; aritmeticka.first=(tacka_1.first+tacka_2.first+tacka_3.first)/3; aritmeticka.second=(tacka_1.second+tacka_2.second+tacka_3.second)/3; return aritmeticka;}

bool Trougao::DaLiJeUnutra(const Tacka &t) const{
    if((Orijentacija(tacka_1,tacka_2,tacka_3))==1 && Orijentacija(tacka_1,tacka_2,t)==1 && Orijentacija(tacka_2,tacka_3,t)==1 && Orijentacija(tacka_3,tacka_1,t)==1) return true;
}
void Trougao::Ispisi() const {
    cout<<"(("<<tacka_1.first<<","<<tacka_1.second<<") , ("<<tacka_2.first<<","<<tacka_2.second<<") , ("<<tacka_3.second<<","<<tacka_3.first<<"))";
    
}
void Trougao::Transliraj(double delta_x, double delta_y){
    tacka_1.first+=delta_x;
    tacka_2.first+=delta_x;
    tacka_3.first+=delta_x;
    tacka_1.second+=delta_y;
    tacka_2.second+=delta_y;
    tacka_3.second+=delta_y;
}
void Trougao::Centriraj(const Tacka &t){
    double deltaX, deltaY;
    deltaX=(3*t.first)/(tacka_1.first+tacka_2.first+tacka_3.first);
    deltaY=(3*t.first)/(tacka_1.second+tacka_2.second+tacka_3.second);
    Transliraj(deltaX,deltaY);
}
void Trougao::Rotiraj(const Tacka &t, double ugao){
    tacka_1.first=t.first+(tacka_1.first-t.first)*cos(ugao)-(tacka_1.second-t.second)*sin(ugao);
    tacka_2.first=t.first+(tacka_2.first-t.first)*cos(ugao)-(tacka_2.second-t.second)*sin(ugao);
    tacka_3.first=t.first+(tacka_3.first-t.first)*cos(ugao)-(tacka_3.second-t.second)*sin(ugao);
    tacka_1.second=t.second+(tacka_1.first-t.first)*sin(ugao)+(tacka_1.second-t.second)*cos(ugao);
    tacka_2.second=t.second+(tacka_2.first-t.first)*sin(ugao)+(tacka_2.second-t.second)*cos(ugao);
    tacka_3.second=t.second+(tacka_3.first-t.first)*sin(ugao)+(tacka_3.second-t.second)*cos(ugao);
}
void Trougao::Skaliraj(const Tacka &t, double faktor){
    Tacka pomocna(t);
    if(fabs(faktor)<epsilon) throw domain_error ("Nekorektan faktor skaliranja");
    if(faktor>0){
    tacka_1.first=pomocna.first+faktor*(tacka_1.first-pomocna.first);
    tacka_2.first=pomocna.first+faktor*(tacka_2.first-pomocna.first);
    tacka_3.first=pomocna.first+faktor*(tacka_3.first-pomocna.first);
    tacka_1.second=pomocna.second+faktor*(tacka_1.second-pomocna.second);
    tacka_2.second=pomocna.second+faktor*(tacka_2.second-pomocna.second);
    tacka_3.second=pomocna.second+faktor*(tacka_3.second-pomocna.second);
    }
    else {
    tacka_1.first=pomocna.first+faktor*(tacka_1.first-pomocna.first);
    tacka_2.first=pomocna.first+faktor*(tacka_2.first-pomocna.first);
    tacka_3.first=pomocna.first+faktor*(tacka_3.first-pomocna.first);
    tacka_1.second=pomocna.second+faktor*(tacka_1.second-pomocna.second);
    tacka_2.second=pomocna.second+faktor*(tacka_2.second-pomocna.second);
    tacka_3.second=pomocna.second+faktor*(tacka_3.second-pomocna.second);
    Rotiraj(DajCentar(),4.*atan(1.));
    }
        
}
void Trougao::Rotiraj(double ugao){
  tacka_1.first=DajCentar().first+(tacka_1.first-DajCentar().first)*cos(ugao)-(tacka_1.second-DajCentar().second)*sin(ugao);
  tacka_2.first=DajCentar().first+(tacka_2.first-DajCentar().first)*cos(ugao)-(tacka_2.second-DajCentar().second)*sin(ugao);
  tacka_3.first=DajCentar().first+(tacka_3.first-DajCentar().first)*cos(ugao)-(tacka_3.second-DajCentar().second)*sin(ugao);
  tacka_1.second=DajCentar().second+(tacka_1.first-DajCentar().first)*sin(ugao)+(tacka_1.second-DajCentar().second)*cos(ugao);
  tacka_2.second=DajCentar().second+(tacka_2.first-DajCentar().first)*sin(ugao)+(tacka_2.second-DajCentar().second)*cos(ugao);
  tacka_3.second=DajCentar().second+(tacka_3.first-DajCentar().first)*sin(ugao)+(tacka_3.second-DajCentar().second)*cos(ugao);
}
void Trougao::Skaliraj(double faktor){
   
    if(fabs(faktor)<epsilon) throw domain_error ("Nekorektan faktor skaliranja");
    if(faktor>0){
    tacka_1.first=DajCentar().first+faktor*(tacka_1.first-DajCentar().first);
    tacka_2.first=DajCentar().first+faktor*(tacka_2.first-DajCentar().first);
    tacka_3.first=DajCentar().first+faktor*(tacka_3.first-DajCentar().first);
    tacka_1.second=DajCentar().second+faktor*(tacka_1.second-DajCentar().second);
    tacka_2.second=DajCentar().second+faktor*(tacka_2.second-DajCentar().second);
    tacka_3.second=DajCentar().second+faktor*(tacka_3.second-DajCentar().second);
    }
    else {
    tacka_1.first=DajCentar().first+faktor*(tacka_1.first-DajCentar().first);
    tacka_2.first=DajCentar().first+faktor*(tacka_2.first-DajCentar().first);
    tacka_3.first=DajCentar().first+faktor*(tacka_3.first-DajCentar().first);
    tacka_1.second=DajCentar().second+faktor*(tacka_1.second-DajCentar().second);
    tacka_2.second=DajCentar().second+faktor*(tacka_2.second-DajCentar().second);
    tacka_3.second=DajCentar().second+faktor*(tacka_3.second-DajCentar().second);
    Rotiraj(DajCentar(),4.*atan(1.));
    }
}
  
    

int main ()
{
    int n;
    vector<shared_ptr<Trougao>> v(n); 
	return 0;
}