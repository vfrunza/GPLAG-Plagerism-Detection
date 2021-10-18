/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <list>
#include <algorithm>
#include <vector>



typedef std::pair<double, double> Tacka;


class Trougao{
    Tacka t1, t2, t3;
    
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



Trougao::Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    Postavi(t1, t2, t3);
}


void Trougao::Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    if(Orijentacija(t1, t2, t3)==0){
        throw std::domain_error("Nekorektne pozicije tjemena");
    }
    this->t1=t1;
    this->t2=t2;
    this->t3=t3;
}




void Trougao::Postavi(int indeks, const Tacka &t){
    if(indeks==1){
        if(Orijentacija(t, t2, t3)==0){
        throw std::domain_error("Nekorektne pozicije tjemena");
        }
        this->t1=t;
    }
    else if(indeks==2){
        if(Orijentacija(t1, t, t3)==0){
        throw std::domain_error("Nekorektne pozicije tjemena");
    }
        this->t2=t;
    }
    else if(indeks==3){
        if(Orijentacija(t1, t2, t)==0){
        throw std::domain_error("Nekorektne pozicije tjemena");
    }
        this->t3=t;
    }
    else{
        throw std::range_error("Nekorektan indeks");
    }
}





 int Trougao::Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    int orijentacija=t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second);
    if(orijentacija>0){
        return 1;
    }
    else if(orijentacija<0){
        return -1;
    }
        return 0;
}





Tacka Trougao::DajTjeme(int indeks) const{
    if(indeks==1){
        return t1;
    }
    else if(indeks==2){
        return t2;
    }
    else if(indeks==3){
        return t3;
    }
    else{
        throw std::range_error("Nekorektan indeks");
    }
}





double Trougao::DajStranicu(int indeks) const{
    if(indeks==1){
        return std::sqrt(((t3.first-t2.first)*(t3.first-t2.first))-((t3.second-t2.second)*(t3.second-t2.second)));
    }
    else if(indeks==2){
        return std::sqrt(((t3.first-t1.first)*(t3.first-t1.first))-((t3.second-t1.second)*(t3.second-t1.second)));
    }
    else if(indeks==3){
        return std::sqrt(((t2.first-t1.first)*(t2.first-t1.first))-((t2.second-t1.second)*(t2.second-t1.second)));
    }
    else{
        throw std::range_error("Nekorektan indeks");
    }
}






double Trougao::DajUgao(int indeks) const{
    if(indeks==1){
        return acos((DajStranicu(2)*DajStranicu(2)+DajStranicu(3)*DajStranicu(3)-DajStranicu(1)*DajStranicu(1))/(2*DajStranicu(2)*DajStranicu(3)));
    }
    else if(indeks==2){
        return acos((DajStranicu(1)*DajStranicu(1)+DajStranicu(3)*DajStranicu(3)-DajStranicu(2)*DajStranicu(2))/(2*DajStranicu(1)*DajStranicu(3)));
    }
    else if(indeks==3){
        return acos((DajStranicu(1)*DajStranicu(1)+DajStranicu(2)*DajStranicu(2)-DajStranicu(3)*DajStranicu(3))/(2*DajStranicu(1)*DajStranicu(2)));
    }
    else{
        throw std::range_error("Nekorektan indeks");
    }
}





Tacka Trougao::DajCentar() const{
    Tacka centar;
    centar.first=(t1.first+t2.first+t3.first)/3.;
    centar.second=(t1.second+t2.second+t3.second)/3.;
    return centar;
}






double Trougao::DajObim() const{
    return DajStranicu(1)+DajStranicu(2)+DajStranicu(3);
}



double Trougao::DajPovrsinu() const{
    return fabs(t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second))/2.;
}






bool Trougao::DaLiJePozitivnoOrijentiran() const{
    if(Orijentacija(t1,t2,t3)==1){
        return true;
    }
    else if(Orijentacija(t1,t2,t3)==-1){
        return false;
    }
}






bool Trougao::DaLiJeUnutra(const Tacka &t) const{
    if((Orijentacija(t1,t2,t3)==1) && (Orijentacija(t1,t2,t)==1) && (Orijentacija(t2,t3,t)==1) && (Orijentacija(t3,t1,t)==1)){
        return true;
    }
    else if((Orijentacija(t1,t2,t3)==-1) && (Orijentacija(t1,t2,t)==-1) && (Orijentacija(t2,t3,t)==-1) && (Orijentacija(t3,t1,t)==-1)){
        return true;
    }
    else{
        return false;
    }
}






void Trougao::Ispisi() const{
    std::cout<<"(("<<t1.first<<","<<t1.second<<") , ("<<t2.first<<","<<t2.second<<") , ("<<t3.first<<","<<t3.second<<"))";
}


void Trougao::Transliraj(double delta_x, double delta_y){
    t1.first+=delta_x;
    t1.second+=delta_y;
    t2.first+=delta_x;
    t2.second+=delta_y;
    t3.first+=delta_x;
    t3.second+=delta_y;
}







void Trougao::Centriraj(const Tacka &t){
    Tacka centar=DajCentar();
    double delta_x=t.first-centar.first;
    double delta_y=t.second-centar.second;
    Transliraj(delta_x, delta_y);
}







void Trougao::Rotiraj(const Tacka &t, double ugao){
    double x1=(t.first+(t1.first-t.first)*cos(ugao))-((t1.second-t.second)*sin(ugao));
    double y1=(t.second+(t1.first-t.first)*sin(ugao))-((t1.second-t.second)*cos(ugao));
    double x2=(t.first+(t2.first-t.first)*cos(ugao))-((t2.second-t.second)*sin(ugao));
    double y2=(t.second+(t2.first-t.first)*sin(ugao))-((t2.second-t.second)*cos(ugao));
    double x3=(t.first+(t3.first-t.first)*cos(ugao))-((t3.second-t.second)*sin(ugao));
    double y3=(t.second+(t3.first-t.first)*sin(ugao))-((t3.second-t.second)*cos(ugao));
    t1.first=x1;
    t1.second=y1;
    t2.first=x2;
    t2.second=y2;
    t1.first=x3;
    t3.second=y3;
}







void Trougao::Skaliraj(const Tacka &t, double faktor){
    if(faktor==0){
        throw std::domain_error("Nekorektan faktor skaliranja");
    }
    double x1=t.first+faktor*(t1.first-t.first);
    double y1=t.second+faktor*(t1.second-t.second);
    double x2=t.first+faktor*(t2.first-t.first);
    double y2=t.second+faktor*(t2.second-t.second);
    double x3=t.first+faktor*(t3.first-t.first);
    double y3=t.second+faktor*(t3.second-t.second);
    t1.first=x1;
    t1.second=y1;
    t2.first=x2;
    t2.second=y2;
    t1.first=x3;
    t3.second=y3;
}







void Trougao::Rotiraj(double ugao){
    double x1=(DajCentar().first+(t1.first-DajCentar().first)*cos(ugao))-((t1.second-DajCentar().second)*sin(ugao));
    double y1=(DajCentar().second+(t1.first-DajCentar().first)*sin(ugao))-((t1.second-DajCentar().second)*cos(ugao));
    double x2=(DajCentar().first+(t2.first-DajCentar().first)*cos(ugao))-((t2.second-DajCentar().second)*sin(ugao));
    double y2=(DajCentar().second+(t2.first-DajCentar().first)*sin(ugao))-((t2.second-DajCentar().second)*cos(ugao));
    double x3=(DajCentar().first+(t3.first-DajCentar().first)*cos(ugao))-((t3.second-DajCentar().second)*sin(ugao));
    double y3=(DajCentar().second+(t3.first-DajCentar().first)*sin(ugao))-((t3.second-DajCentar().second)*cos(ugao));
    t1.first=x1;
    t1.second=y1;
    t2.first=x2;
    t2.second=y2;
    t1.first=x3;
    t3.second=y3;
}







void Trougao::Skaliraj(double faktor){
    if(faktor==0){
        throw std::domain_error("Nekorektan faktor skaliranja");
    }
    double x1=DajCentar().first+faktor*(t1.first-DajCentar().first);
    double y1=DajCentar().second+faktor*(t1.second-DajCentar().second);
    double x2=DajCentar().first+faktor*(t2.first-DajCentar().first);
    double y2=DajCentar().second+faktor*(t2.second-DajCentar().second);
    double x3=DajCentar().first+faktor*(t3.first-DajCentar().first);
    double y3=DajCentar().second+faktor*(t3.second-DajCentar().second);
    t1.first=x1;
    t1.second=y1;
    t2.first=x2;
    t2.second=y2;
    t1.first=x3;
    t3.second=y3;
}





bool Uporedi(double x, double y){
    if(fabs(x-y)<0.001){
        return true;
    }
    return false;
}






bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2){
    std::list<Tacka> lista_1 {t1.DajTjeme(1), t1.DajTjeme(2), t1.DajTjeme(3)};
    std::list<Tacka> lista_2 {t2.DajTjeme(1), t2.DajTjeme(2), t2.DajTjeme(3)};
    bool nadjeno(true);
    for(auto it(lista_1.begin()); it!=lista_1.end(); it++){
        auto it2 = std::find_if(lista_2.begin(), lista_2.end(), [it](Tacka t){
            return Uporedi(it->first, t.first) && Uporedi(it->second, t.second);
        });
        if(it2 != lista_2.end()) lista_2.erase(it2);
        else nadjeno = false;
    }
    return nadjeno;
}





bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2){
    int brojac_1_m{0};
    int brojac_1_v{0};
    int brojac_2_m{0};
    int brojac_2_v{0};
    
    if(t1.DajStranicu(1)>t1.DajStranicu(2)){
        brojac_1_v++;
    }
    else{
        brojac_1_m++;
    }
    if(t1.DajStranicu(2)>t1.DajStranicu(3)){
        brojac_1_v++;
    }
    else{
        brojac_1_m++;
    }
    if(t1.DajStranicu(3)>t1.DajStranicu(1)){
        brojac_1_v++;
    }
    else{
        brojac_1_m++;
    }
    
    
     if(t2.DajStranicu(1)>t1.DajStranicu(2)){
        brojac_2_v++;
    }
    else{
        brojac_2_m++;
    }
    if(t2.DajStranicu(2)>t1.DajStranicu(3)){
        brojac_2_v++;
    }
    else{
        brojac_2_m++;
    }
    if(t2.DajStranicu(3)>t1.DajStranicu(1)){
        brojac_2_v++;
    }
    else{
        brojac_2_m++;
    }
    
    if(brojac_1_m!=brojac_2_m){
        return false;
    }
    
    
    std::list<double> lista_1 {t1.DajStranicu(1), t1.DajStranicu(2), t1.DajStranicu(3)};
    std::list<double> lista_2 {t2.DajStranicu(1), t2.DajStranicu(2), t2.DajStranicu(3)};
    bool nadjeno(true);
    for(auto it(lista_1.begin()); it!=lista_1.end(); it++){
        auto it2 = std::find_if(lista_2.begin(), lista_2.end(), [it](double t){
            return Uporedi(*it, t);
        });
        if(it2 != lista_2.end()) lista_2.erase(it2);
        else nadjeno = false;
    }
    return nadjeno;
}




bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2){
    int brojac_1_m{0};
    int brojac_1_v{0};
    int brojac_2_m{0};
    int brojac_2_v{0};
    
    if(t1.DajStranicu(1)>t1.DajStranicu(2)){
        brojac_1_v++;
    }
    else{
        brojac_1_m++;
    }
    if(t1.DajStranicu(2)>t1.DajStranicu(3)){
        brojac_1_v++;
    }
    else{
        brojac_1_m++;
    }
    if(t1.DajStranicu(3)>t1.DajStranicu(1)){
        brojac_1_v++;
    }
    else{
        brojac_1_m++;
    }
    
    
     if(t2.DajStranicu(1)>t1.DajStranicu(2)){
        brojac_2_v++;
    }
    else{
        brojac_2_m++;
    }
    if(t2.DajStranicu(2)>t1.DajStranicu(3)){
        brojac_2_v++;
    }
    else{
        brojac_2_m++;
    }
    if(t2.DajStranicu(3)>t1.DajStranicu(1)){
        brojac_2_v++;
    }
    else{
        brojac_2_m++;
    }
    
    if(brojac_1_m!=brojac_2_m){
        return false;
    }
    
    
    
}


int main(){
    
    std::cout<<"Unesite prirodan broj n: ";
    int n;
    std::cin>>n;
    std::cin.ignore(10000, '\n');
    
    
    
    
    
    
    return 0;
}