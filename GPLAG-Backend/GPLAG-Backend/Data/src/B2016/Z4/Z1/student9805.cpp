/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <cmath>

#include <stdexcept>
const double PI=4*atan(1);
const double eps=0.000000000000001;
typedef std::pair<double,double> Tacka;


class Trougao{
    Tacka tacka1,tacka2,tacka3;
   
    public:
    Trougao(const Tacka &tacka1, const Tacka &tacka2, const Tacka &tacka3);
    void Postavi(const Tacka &tacka1, const Tacka &tacka2, const Tacka &tacka3);
    void Postavi(int indeks, const Tacka &t);
    static int Orijentacija(const Tacka &tacka1, const Tacka &tacka2, const Tacka &tacka3){
    double A=(tacka1.first*(tacka2.second-tacka3.second)-tacka2.first*(tacka1.second-tacka3.second)+tacka3.first*(tacka1.second-tacka2.second));
    if(A>=0 && A<eps) return 0;
    if (A>0) return 1;
    else return -1;
    }
    Tacka DajTjeme(int indeks) const{
        if(indeks==1)return tacka1;
        if(indeks==2)return tacka2;
        if(indeks==3)return tacka3;
        else{
            throw std::range_error("Nekorektan indeks");
        }
    }
    double DajStranicu(int indeks) const{
        double A=sqrt((tacka2.first-tacka3.first)*(tacka2.first-tacka3.first)+(tacka2.second-tacka3.second)*(tacka2.second-tacka3.second)),B=sqrt((tacka1.first-tacka3.first)*(tacka1.first-tacka3.first)+(tacka1.second-tacka3.second)*(tacka1.second-tacka3.second));
        double C=sqrt((tacka2.first-tacka1.first)*(tacka2.first-tacka1.first)+(tacka2.second-tacka1.second)*(tacka2.second-tacka1.second));
        if(indeks==1) return A;
        if(indeks==2) return B;
        if(indeks==3) return C;
        else{
            throw std::range_error("Nekorektan indeks");
        }
    }
    double DajUgao(int indeks) const{
        if(indeks==1) return acos((DajStranicu(3)*DajStranicu(3)+DajStranicu(2)*DajStranicu(2)-DajStranicu(1)*DajStranicu(1))/(2*DajStranicu(2)*DajStranicu(3)));
        if(indeks==2) return acos((DajStranicu(3)*DajStranicu(3)+DajStranicu(1)*DajStranicu(1)-DajStranicu(2)*DajStranicu(2))/(2*DajStranicu(1)*DajStranicu(3)));
        if(indeks==3) return acos((DajStranicu(1)*DajStranicu(1)+DajStranicu(2)*DajStranicu(2)-DajStranicu(3)*DajStranicu(3))/(2*DajStranicu(2)*DajStranicu(1)));
        else{
            throw std::range_error("Nekorektan indeks");
        }
    }
    Tacka DajCentar() const;
    double DajObim() const{
        return DajStranicu(1)+DajStranicu(2)+DajStranicu(3);
    }
    double DajPovrsinu() const{
        double S=DajObim()/2;
        return sqrt(S*(S-DajStranicu(1))*(S-DajStranicu(2))*(S-DajStranicu(3)));
    }
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
Tacka Trougao::DajCentar()const{
    Tacka Centar;
    Centar.first=(tacka1.first+tacka2.first+tacka3.first)/3;
    Centar.second=(tacka1.second+tacka2.second+tacka3.second)/3;
    return Centar;
}

bool DaLiJeLegalan(Tacka t1,Tacka t2,Tacka t3){
    if((abs(t1.first-t2.first)<eps && abs(t1.second-t2.second)<eps)||(abs (t3.first-t2.first)<eps && abs(t3.second-t2.second<eps)) || (abs(t1.first-t3.first)<eps && abs(t1.second-t3.second)<eps)) return false;
    else return true;
}

Trougao::Trougao(const Tacka &tacka1, const Tacka &tacka2, const Tacka &tacka3){
    if(DaLiJeLegalan(tacka1,tacka2,tacka3)&&(Orijentacija(tacka1,tacka2,tacka3))!=0){
      Trougao::tacka1=tacka1;Trougao::tacka2=tacka2;Trougao::tacka3=tacka3;  
    }
    else {
        throw std::domain_error("Nekorektne pozicije tjemena");
    }

}

void Trougao::Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    if(DaLiJeLegalan(t1,t2,t3)&&Orijentacija(t1,t2,t3)!=0){
        Trougao::tacka1=t1;Trougao::tacka2=t2;Trougao::tacka3=t3;
    }
    else{
        throw std::domain_error("Nekorektne pozicije tjemena");
    }
}

void Trougao::Postavi(int indeks, const Tacka &t){
    if(indeks==1) Trougao::tacka1=t;
    if(indeks==2) Trougao::tacka2=t;
    if(indeks==3) Trougao::tacka3=t;
    else{
        throw std::range_error("Nekorektan indeks");
    }
    if(DaLiJeLegalan(Trougao::tacka1,Trougao::tacka2,Trougao::tacka3)&&Orijentacija(Trougao::tacka1,Trougao::tacka2,Trougao::tacka3))
    {}
    else{
        throw std::domain_error("Nekorektne pozicije tjemena");
    }
}

bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2){
    if(DaLiJeLegalan(t1.tacka1,t1.tacka2,t1.tacka3)&&Trougao::Orijentacija(t1.tacka1,t1.tacka2,t1.tacka3)&&DaLiJeLegalan(t2.tacka1,t2.tacka2,t2.tacka3)&&Trougao::Orijentacija(t2.tacka1,t2.tacka2,t2.tacka3)){
        if((t1.tacka1==t2.tacka1||t1.tacka1==t2.tacka2||t1.tacka1==t2.tacka3)&&(t1.tacka2==t2.tacka1||t1.tacka2==t2.tacka2||t1.tacka2==t2.tacka3)&&(t1.tacka3==t2.tacka1||t1.tacka3==t2.tacka2||t1.tacka3==t2.tacka3)){
            return true;
        }
        else return false;
    }
    else{
        throw std::domain_error("Nekorektne pozicije tjemena");
    }
}

bool Trougao::DaLiJePozitivnoOrijentiran()const{
    if(Orijentacija(tacka1,tacka2,tacka3)==1){
        return true;
    }
    else return false;
}

bool Trougao::DaLiJeUnutra(const Tacka &t) const{
    if(Orijentacija(tacka1,tacka2,tacka3)==1 && Orijentacija(tacka1,tacka2,t)==1 && Orijentacija(tacka2,tacka3,t)==1 && Orijentacija(tacka3,tacka1,t)==1){
        return true;
    }
    else return false;
}

void Trougao::Ispisi()const{
    std::cout<<"(";
    std::cout<<"("<<tacka1.first<<","<<tacka1.second<<")";
    std::cout<<",";
    std::cout<<"("<<tacka2.first<<","<<tacka2.second<<")";
    std::cout<<",";
    std::cout<<"("<<tacka3.first<<","<<tacka3.second<<")";
    std::cout<<")";
}

void Trougao::Transliraj(double delta_x,double delta_y){
    Trougao::tacka1.first+=delta_x;
    Trougao::tacka1.second+=delta_y;
    Trougao::tacka2.first+=delta_x;
    Trougao::tacka2.second+=delta_y;
    Trougao::tacka3.first+=delta_x;
    Trougao::tacka3.second+=delta_y;
    
}

void Trougao::Centriraj(const Tacka &t){
    Tacka pomocna=Trougao::DajCentar();
    double delta_x=t.first-pomocna.first;
    double delta_y=t.second-pomocna.second;
    Trougao::tacka1.first+=delta_x;
    Trougao::tacka1.second+=delta_y;
    Trougao::tacka2.first+=delta_x;
    Trougao::tacka2.second+=delta_y;
    Trougao::tacka3.first+=delta_x;
    Trougao::tacka3.second+=delta_y;
}

void Trougao::Rotiraj(const Tacka &t,double ugao){
    Trougao::tacka1.first=t.first+((tacka1.first-t.first)*cos(ugao))-((tacka1.second-t.second)*sin(ugao));
    Trougao::tacka1.second=t.second+((tacka1.first-t.first)*sin(ugao))+((tacka1.second-t.second)*cos(ugao));
    Trougao::tacka2.first=t.first+((tacka2.first-t.first)*cos(ugao))-((tacka2.second-t.second)*sin(ugao));
    Trougao::tacka2.second=t.second+((tacka2.first-t.first)*sin(ugao))+((tacka2.second-t.second)*cos(ugao));
    Trougao::tacka3.first=t.first+((tacka3.first-t.first)*cos(ugao))-((tacka3.second-t.second)*sin(ugao));
    Trougao::tacka3.second=t.second+((tacka3.first-t.first)*sin(ugao))+((tacka3.second-t.second)*cos(ugao));
}

void Trougao::Skaliraj(const Tacka &t,double faktor){
    if(faktor>=0 && faktor <eps){
        throw std::domain_error("Nekorektan faktor skaliranja");
    }
    else{
    Trougao::tacka1.first=t.first+((tacka1.first-t.first)*faktor);
    Trougao::tacka1.second=t.second+((tacka1.second-t.second)*faktor);
    Trougao::tacka2.first=t.first+((tacka2.first-t.first)*faktor);
    Trougao::tacka2.second=t.second+((tacka2.second-t.second)*faktor);
    Trougao::tacka3.first=t.first+((tacka3.first-t.first)*faktor);
    Trougao::tacka3.second=t.second+((tacka3.second-t.second)*faktor);
    }
}

void Trougao::Rotiraj(double ugao){
    Tacka centar=DajCentar();
    Trougao::tacka1.first=centar.first+((tacka1.first-centar.first)*cos(ugao))-((tacka1.second-centar.second)*sin(ugao));
    Trougao::tacka1.second=centar.second+((tacka1.first-centar.first)*sin(ugao))+((tacka1.second-centar.second)*cos(ugao));
    Trougao::tacka2.first=centar.first+((tacka2.first-centar.first)*cos(ugao))-((tacka2.second-centar.second)*sin(ugao));
    Trougao::tacka2.second=centar.second+((tacka2.first-centar.first)*sin(ugao))+((tacka2.second-centar.second)*cos(ugao));
    Trougao::tacka3.first=centar.first+((tacka3.first-centar.first)*cos(ugao))-((tacka3.second-centar.second)*sin(ugao));
    Trougao::tacka3.second=centar.second+((tacka3.first-centar.first)*sin(ugao))+((tacka3.second-centar.second)*cos(ugao));
}

void Trougao::Skaliraj(double faktor){
    Tacka centar=DajCentar();
    if(faktor>=0 && faktor <eps){
        throw std::domain_error("Nekorektan faktor skaliranja");
    }
    else{
        Trougao::tacka1.first=centar.first+((tacka1.first-centar.first)*faktor);
        Trougao::tacka1.second=centar.second+((tacka1.second-centar.second)*faktor);
        Trougao::tacka2.first=centar.first+((tacka2.first-centar.first)*faktor);
        Trougao::tacka2.second=centar.second+((tacka2.second-centar.second)*faktor);
        Trougao::tacka3.first=centar.first+((tacka3.first-centar.first)*faktor);
        Trougao::tacka3.second=centar.second+((tacka3.second-centar.second)*faktor);
    }
}
int main ()
{
    try{
        Tacka t1(0,0),t2(5,2),t3(1,4);
        
        Trougao t(t1,t2,t3);
        
        std::cout<<t2.first<<"\n";
        Tacka pom=t.DajTjeme(2);
        std::cout<<pom.first<<" "<<pom.second<<"\n"<<t.DajStranicu(2)<<" Strana\n"<<t.DajUgao(1)+t.DajUgao(2)+t.DajUgao(3)<<" Ugao\n"<<t.DajObim()<<"\n"<<t.DajPovrsinu()<<"\n";
        Tacka t4(2,5);
        t.Postavi(t4,t2,t3);
        Tacka pomoc=t.DajTjeme(1);
        std::cout<<pomoc.first<<" ";
        
        Trougao trou2(t4,t2,t3);
        
        std::cout<<DaLiSuIdenticni(t,trou2)<<"\n";
        trou2.Ispisi();
        std::cout<<"\n";
        trou2.Transliraj(2,2);
        trou2.Ispisi();
        Tacka trou2cent=trou2.DajCentar();
        std::cout<<"\n"<<trou2cent.first<<" "<<trou2cent.second<<"\n";
        Tacka p(5,5);
        trou2.Centriraj(p);
        trou2.Ispisi();
        std::cout<<"\n";
        Tacka t10(1,1),t11(2,2),t12(3,1);
        Trougao t101112(t10,t11,t12);
        Tacka nula(1,1);
        t101112.Rotiraj(nula,PI);
        t101112.Ispisi();
        std::cout<<"\n";
        t101112.Rotiraj(nula,PI);
        t101112.Ispisi();
        std::cout<<"\n";
        t101112.Skaliraj(t101112.DajCentar(),2);
        t101112.Ispisi();
        t101112.Skaliraj(1);
        std::cout<<"\n";
        t101112.Ispisi();
        
    }
    catch(std::domain_error izuzetak){
        std::cout<<izuzetak.what();
    }
    catch(std::range_error izuzetak){
        std::cout<<izuzetak.what();
    }
	return 0;
}