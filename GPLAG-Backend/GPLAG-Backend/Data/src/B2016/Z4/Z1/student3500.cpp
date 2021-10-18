/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <cmath>
#include <utility>
#include <stdexcept>

typedef std::pair<double, double> Tacka;


class Trougao{
    Tacka t1,t2,t3;
    
public:
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3);
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3);
    void Postavi(int indeks, const Tacka &t);
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3);
    Tacka DajTjeme(int indeks) const;
    double DajStranicu(int indeks) const;
    double DajUgao(int indeks) const;
    Tacka DajCentar() const;
    double DajObim() const;
    double DajPovrsinu() const;
    
    bool DaLiJePozitivnoOrijentiran() const;
    bool DaLiJeUnutra(const Tacka &t) const;
    void Ispisi() const;
    void Transliraj(double delta_x, double delta_y);
    void Centriraj(const Tacka &t);
    void Rotiraj(const Tacka &t, double ugao);
    void Skaliraj(const Tacka &t, double faktor);
    void Rotiraj(double ugao);
    void Skaliraj(double faktor);
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);
};

double metrika(Tacka One, Tacka Two){                                                                                      //METRIKA
    double d;
    d=sqrt((One.first-Two.first)*(One.first-Two.first)+(One.second-Two.second)*(One.second-Two.second));
    return d;
}

int orj(const Tacka &t1, const Tacka &t2, const Tacka &t3){                                                           //miniOrijentacija                    
    int O=(t1.first*(t2.second-t3.second))-(t2.first*(t1.second-t3.second))+(t3.first*(t1.second-t2.second));
    if(O>0) return 1;
    else if(O<0) return -1;
    else return 0;
}



Trougao::Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3){ 
    if(orj(t1,t2,t3)==0) throw std::domain_error("Nekorektne pozicije tjemena");                                       //KONSTRUKTOR
    this->t1=t1; this->t2=t2; this->t3=t3;
}

void Trougao::Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3){                                                     //POSTAVA
    if(orj(t1,t2,t3)==0) throw std::domain_error("Nekorektne pozicije tjemena");
    this->t1=t1; this->t2=t2; this->t3=t3;
}

int Trougao::Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3){                                          //Orijentacija
    int O=t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second);
    if(O>0) return 1;
    else if(O<0) return -1;
    else return 0;
}

void Trougao::Ispisi(){
    std::cout<<"(("<<this->t1.first<<","<<this->t1.second<<"),("<<this->t2.first<<","<<this->t2.second<<"),("<<this->t3.first<<","<<this->t3.second<<"))";
}

Tacka Trougao::DajCentar() const{                                                                                               //centar
    double x,y;
    x=(t1.first+t2.first+t3.first)/3;
    y=(t1.second+t2.second+t3.second)/3;
    Tacka C(x,y);
    return C;
}


bool Trougao::DaLiJePozitivnoOrijentiran() const{                                                                               //POZ OR
    if((*this).Orijentacija(t1,t2,t3)==1) return true;
    else return false;
}

double Trougao::DajObim() const{                                                                                               //OBIM
    return (metrika(t1,t2)+metrika(t2,t3)+metrika(t3,t1));
}
 
double Trougao::DajPovrsinu() const{                                                                                            //POVRSH
    Tacka M((t1.first+t2.first)/2,(t1.second+t2.second)/2);
    double P=((metrika(t1,t2))*(metrika(M,t3))/2);
    return P;
}

double trPov(Tacka t1, Tacka t2, Tacka t3) {                                                                                            //POVRSH
    Tacka M((t1.first+t2.first)/2,(t1.second+t2.second)/2);
    double P=((metrika(t1,t2))*(metrika(M,t3))/2);
    return P;
}

Tacka Trougao::DajTjeme(int indeks) const{                                                                                       //tjeme
    if(indeks==1) return t1;
    else if(indeks==2) return t2;
    else if(indeks==3) return t3;
    else throw std::range_error("Nekorektan indeks");
}

double Trougao::DajStranicu(int indeks) const{                                                                                 //STRANICE
    if(indeks==1) return (metrika(t2,t3));
    else if(indeks==2) return (metrika(t3,t1));
    else if(indeks==3) return (metrika(t1,t2));
    else throw std::range_error("Nekorektan indeks");
}

bool Trougao::DaLiJeUnutra(const Tacka &t) const{                                                                                  //Unutra
    double P=(*this).DajPovrsinu();
    double p=trPov(t1, t2, t)+trPov(t2, t3, t)+trPov(t3,t1,t);
    if(P==p) return true;
    else return false;
}

void Trougao::Transliraj(double delta_x, double delta_y){
    t1.first+=delta_x;
    t2.first+=delta_x;
    t3.first+=delta_x;
    t1.second+=delta_y;
    t2.second+=delta_y;
    t3.second+=delta_y;
}

void Trougao::Centriraj(const Tacka &t){
    Tacka C=(*this).DajCentar();
    double delta_x, delta_y;
    delta_x=t.first-C.first;
    delta_y=t.second-C.second;
    t1.first+=delta_x;
    t2.first+=delta_x;
    t3.first+=delta_x;
    t1.second+=delta_y;
    t2.second+=delta_y;
    t3.second+=delta_y;
    
}

void Trougao::Rotiraj(const Tacka &t, double ugao){
    double xc, yc;
    xc=t.first; yc=t.second;
    t1=std::make_pair(xc+(t1.first-xc)*cos(ugao)-(t1.second-yc)*sin(ugao),yc+(t1.first-xc)*sin(ugao)+(t1.second-yc)*cos(ugao));
    t2=std::make_pair(xc+(t2.first-xc)*cos(ugao)-(t2.second-yc)*sin(ugao),yc+(t2.first-xc)*sin(ugao)+(t2.second-yc)*cos(ugao));
    t3=std::make_pair(xc+(t3.first-xc)*cos(ugao)-(t3.second-yc)*sin(ugao),yc+(t3.first-xc)*sin(ugao)+(t3.second-yc)*cos(ugao));
}

void Trougao::Skaliraj(const Tacka &t, double faktor){
    if(faktor==0) throw std::domain_error("Nekorektan faktor skaliranja");
    double xc, yc;
    xc=t.first; yc=t.second;
    t1=std::make_pair(xc+faktor*(t1.first-xc), yc+faktor*(t1.second-yc));
    t2=std::make_pair(xc+faktor*(t2.first-xc), yc+faktor*(t2.second-yc));
    t3=std::make_pair(xc+faktor*(t3.first-xc), yc+faktor*(t3.second-yc));
}

void Trougao::Rotiraj(double ugao){
    Tacka t=(*this).DajCentar();
    double xc, yc;
    xc=t.first; yc=t.second;
    t1=std::make_pair(xc+(t1.first-xc)*cos(ugao)-(t1.second-yc)*sin(ugao),yc+(t1.first-xc)*sin(ugao)+(t1.second-yc)*cos(ugao));
    t2=std::make_pair(xc+(t2.first-xc)*cos(ugao)-(t2.second-yc)*sin(ugao),yc+(t2.first-xc)*sin(ugao)+(t2.second-yc)*cos(ugao));
    t3=std::make_pair(xc+(t3.first-xc)*cos(ugao)-(t3.second-yc)*sin(ugao),yc+(t3.first-xc)*sin(ugao)+(t3.second-yc)*cos(ugao));
}

void Trougao::Skaliraj(double faktor){
    if(faktor==0) throw std::domain_error("Nekorektan faktor skaliranja");
    Tacka t=(*this).DajCentar();
    double xc, yc;
    xc=t.first; yc=t.second;
    t1=std::make_pair(xc+faktor*(t1.first-xc), yc+faktor*(t1.second-yc));
    t2=std::make_pair(xc+faktor*(t2.first-xc), yc+faktor*(t2.second-yc));
    t3=std::make_pair(xc+faktor*(t3.first-xc), yc+faktor*(t3.second-yc));
}

double DajUgao(int indeks){
    double ugao, a, b, c;
    int i, j;
    if(indeks==1) {i=2;j=3;}
    else if(indeks==2) {i=3;j=1;}
    else if(indeks==3) {i=1;j=2;}
    else throw std::range_error("Nekorektan indeks");

    a=(*this).DajStranicu(indeks); b=(*this).DajStranicu(i); c=(*this).DajStranicu(j);
    ugao=acos((b*b+c*c-a*a)/(b*c*2));
    return ugao;
}

bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2){
    if((t1.t1.first==t2.t1.first)&&(t1.t2.first==t2.t2.first)&&(t1.t3.first==t2.t3.first)&&(t1.t1.second==t2.t1.second)&&(t1.t2.second==t2.t2.second)&&(t1.t3.second==t2.t3.second)) return true;
    else return false;
}
bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2){
   
}
bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2){
     
}












int main ()
{
	return 0;
}