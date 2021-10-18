/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <utility>
#include <stdexcept>
#include <algorithm>
#include<vector>
#include <memory>
#include <cmath>
typedef std::pair<double, double> Tacka;
const double FABS=0.0000000001;
bool jednakii(double prvi, double drugi){
       if(prvi-drugi<0 || prvi-drugi>0)return false;
        //if(prvi-drugi>0)return false;
        return true;
    }
class Trougao{
    Tacka tacka1,tacka2,tacka3;
     static bool jednaki(double prvi, double drugi){
       if(prvi-drugi<FABS || prvi-drugi>FABS)return false;
       // else if(prvi-drugi>0)return false;
        return true;
    }
    static double pomocna_povrsina(Tacka t1,Tacka t2,Tacka t3){
        double broj=t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second);
        return broj;
    }
    static double dajduzinu(Tacka tacka1, Tacka tacka2){
        double broj=std::sqrt((tacka1.second-tacka2.second)*(tacka1.second-tacka2.second)+(tacka1.first-tacka2.first)*(tacka1.first-tacka2.first));
        return std::abs(broj);
    }
    static bool jednakatjemena(Tacka t1, Tacka t2){
        if(jednaki(t1.first,t2.first)==true && jednaki(t1.second,t2.second)==true)return true;
        return false;
    }
    public:
   
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        if( Orijentacija(t1,t2,t3)==0) throw std::domain_error ("Nekorektne pozicije tjemena");
        tacka1.first=t1.first; tacka1.second=t1.second;
        tacka2.first=t2.first; tacka2.second=t2.second;
        tacka3.first=t3.first; tacka3.second=t3.second;
    }
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3){
         if(Orijentacija(t1,t2,t3)==0) throw std::domain_error ("Nekorektne pozicije tjemena");
         tacka1.first=t1.first; tacka1.second=t1.second;
         tacka2.first=t2.first; tacka2.second=t2.second;
         tacka3.first=t3.first; tacka3.second=t3.second;
    }
    void Postavi(int indeks, const Tacka &t){
        if(indeks<=0 || indeks>=4)throw std::range_error("Nekorektan indeks");
        if(indeks==1){
            if(Orijentacija(t,tacka2,tacka3)==0)throw std::domain_error("Nekorektne pozicije tjemena");
            tacka1.first=t.first; tacka1.second=t.second;
        }
        else if(indeks==2){
            if(Orijentacija(tacka1,t,tacka3)==0)throw std::domain_error("Nekorektne pozicije tjemena");
            tacka2.first=t.first;tacka2.second=t.second;
        }
        else { 
            if(Orijentacija(tacka1,tacka2,t)==0)throw std::domain_error("Nekorektne pozicije tjemena");
            tacka3.first=t.first; tacka3.second=t.second;
        }
    }
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3){
                double broj=t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second);
                if(broj<FABS && jednaki(broj,0)==true)return 0;
                if(broj<FABS &&jednaki(broj,FABS)==true)return -1;
                return 1;
               
    }
    Tacka DajTjeme(int indeks) const{
        if(indeks<=0 || indeks>=4 )throw std::range_error("Nekorektan indeks");
        if(indeks==1)return tacka1;
        else if(indeks==2)return tacka2;
        else return tacka3;
    }
    double DajStranicu(int indeks) const{
        if(indeks<=0 || indeks>=4)throw std::range_error("Nekorektan indeks");
        if(indeks==1){
            double broj=std::sqrt((tacka2.second-tacka3.second)*(tacka2.second-tacka3.second)+(tacka2.first-tacka3.first)*(tacka2.first-tacka3.first));
            return std::abs(broj);
        }
        else if(indeks==2){
            double broj=std::sqrt((tacka1.second-tacka3.second)*(tacka1.second-tacka3.second)+(tacka1.first-tacka3.first)*(tacka1.first-tacka3.first));
            return std::abs(broj);
        }
        else{
            double broj=std::sqrt((tacka1.second-tacka2.second)*(tacka1.second-tacka2.second)+(tacka1.first-tacka2.first)*(tacka1.first-tacka2.first));
            return std::abs(broj);
        }
    }
    double DajUgao(int indeks) const{
        if(indeks<=0 || indeks>=4)throw std::range_error("Nekorektan indeks");
        if(indeks==1){
            double ugao=DajStranicu(1)*DajStranicu(1)-DajStranicu(2)*DajStranicu(2)-DajStranicu(3)*DajStranicu(3);
            ugao/=(DajStranicu(2)*DajStranicu(3)*2);
            return std::acos(ugao);
        }
        if(indeks==2){
            double ugao=DajStranicu(2)*DajStranicu(2)-DajStranicu(1)*DajStranicu(1)-DajStranicu(3)*DajStranicu(3);
            ugao/=(DajStranicu(1)*DajStranicu(3)*2);
            return std::acos(ugao);
        }
        if(indeks==3){
            double ugao=DajStranicu(3)/DajStranicu(3)-DajStranicu(1)*DajStranicu(1)-DajStranicu(2)*DajStranicu(2);
            ugao/=(DajStranicu(1)*DajStranicu(2)*2);
            return std::acos(ugao);
        }
    }
    Tacka DajCentar() const{
        Tacka centar;
        double koordinata1=tacka1.first+tacka2.first+tacka3.first;
        koordinata1/=3;
        double koordinata2=tacka1.second+ tacka2.second+tacka3.second;
        koordinata2/=3;
        centar.first=koordinata1;
        centar.second=koordinata2;
        return centar;
    }
    double DajObim() const{
        double broj=DajStranicu(1)+DajStranicu(2)+DajStranicu(3);
        return broj;
    }
    double DajPovrsinu() const{
        double povrsina=std::abs(pomocna_povrsina(tacka1,tacka2,tacka3));
        povrsina/=2;
        return povrsina;
    }
    bool DaLiJePozitivnoOrijentiran() const{
        if(Orijentacija(tacka1, tacka2, tacka3)==1)return true;
        return false;
    }
    bool DaLiJeUnutra(const Tacka &t) const{
        if(Orijentacija(tacka1,tacka2,tacka3)==1 && Orijentacija(tacka1,tacka2,t)==1 && Orijentacija(tacka2, tacka3,t)==1 && Orijentacija(tacka3, tacka1, t)==1 )return true;
        return false;
    }
    void Ispisi() const{
        std::cout<<"(("<<tacka1.first<<","<<tacka1.second<<"), ("<<tacka2.first<<","<<tacka2.second<<"), ("<<tacka3.first<<","<<tacka3.second<<"))";
    }
    void Transliraj(double delta_x, double delta_y){
        tacka1.first+=delta_x; tacka1.second+=delta_y;
        tacka2.first+=delta_x; tacka2.second+=delta_y;
        tacka3.first+=delta_x; tacka3.second+=delta_y;
        Postavi(tacka1,tacka2,tacka3);
    }
    void Centriraj(const Tacka &t){
        Tacka centar(DajCentar());
        double delta_x=centar.first-t.first;
        double delta_y=centar.second-t.second;
        tacka1.first+=delta_x; tacka1.second+=delta_y;
        tacka2.first+=delta_x; tacka2.second+=delta_y;
        tacka3.first+=delta_x; tacka3.second+=delta_y;
        Postavi(tacka1,tacka2,tacka3);
    }
    void Rotiraj(const Tacka &t, double ugao){
        tacka1.first=t.first+(tacka1.first-t.first)*std::acos(ugao)-(tacka1.second-t.second)*std::asin(ugao);
        tacka1.second=t.second+(tacka1.first-t.first)*std::asin(ugao)+(tacka1.second-t.second)*std::acos(ugao);
        tacka2.first=t.first+(tacka2.first-t.first)*std::acos(ugao)-(tacka2.second-t.second)*std::asin(ugao);
        tacka2.second=t.second+(tacka2.first-t.first)*std::asin(ugao)+(tacka2.second-t.second)*std::acos(ugao);
        tacka3.first=t.first+(tacka3.first-t.first)*std::acos(ugao)-(tacka3.second-t.second)*std::asin(ugao);
        tacka3.second=t.second+(tacka3.first-t.first)*std::asin(ugao)+(tacka3.second-t.second)*std::acos(ugao);
        Postavi(tacka1,tacka2,tacka3);
    }
    void Skaliraj(const Tacka &t, double faktor){
        if(faktor<FABS || jednaki(faktor,0)==true)throw std::domain_error("Nekorektan faktor skaliranja");
        tacka1.first=t.first+faktor*(tacka1.first-t.first); tacka1.second=t.second+faktor*(tacka1.second-t.second);
        tacka2.first=t.first+faktor*(tacka2.first-t.first); tacka2.second=t.second+faktor*(tacka2.second-t.second);
        tacka3.first=t.first+faktor*(tacka3.first-t.first); tacka3.second=t.second+faktor*(tacka3.second-t.second);
        Postavi(tacka1, tacka2,tacka3);
    }
    void Skaliraj(double faktor){
        if(faktor<FABS || jednaki(faktor,0)==true)throw std::domain_error("Nekorektan faktor skaliranja");
        const Tacka t(DajCentar());
        tacka1.first=t.first+faktor*(tacka1.first-t.first); tacka1.second=t.second+faktor*(tacka1.second-t.second);
        tacka2.first=t.first+faktor*(tacka2.first-t.first); tacka2.second=t.second+faktor*(tacka2.second-t.second);
        tacka3.first=t.first+faktor*(tacka3.first-t.first); tacka3.second=t.second+faktor*(tacka3.second-t.second);
        Postavi(tacka1,tacka2,tacka3);
    }
    void Rotiraj(double ugao){
        Tacka t(DajCentar());
        tacka1.first=t.first+(tacka1.first-t.first)*std::acos(ugao)-(tacka1.second-t.second)*std::asin(ugao);
        tacka1.second=t.second+(tacka1.first-t.first)*std::asin(ugao)+(tacka1.second-t.second)*std::acos(ugao);
        tacka2.first=t.first+(tacka2.first-t.first)*std::acos(ugao)-(tacka2.second-t.second)*std::asin(ugao);
        tacka2.second=t.second+(tacka2.first-t.first)*std::asin(ugao)+(tacka2.second-t.second)*std::acos(ugao);
        tacka3.first=t.first+(tacka3.first-t.first)*std::acos(ugao)-(tacka3.second-t.second)*std::asin(ugao);
        tacka3.second=t.second+(tacka3.first-t.first)*std::asin(ugao)+(tacka3.second-t.second)*std::acos(ugao);
        Postavi(tacka1,tacka2,tacka3);
        
    }
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2){
        //bool jedan(true), dva(true), tri(true);
        if(Orijentacija(t1.tacka1,t1.tacka2,t1.tacka3)==0 || Orijentacija(t2.tacka1,t2.tacka2, t2.tacka3)==0)throw std::domain_error("Nekorektne pozicije tjemena");
        if(jednakatjemena(t1.tacka1,t2.tacka1)==true&& jednakatjemena(t1.tacka2,t2.tacka2)==true && jednakatjemena(t1.tacka3,t2.tacka3)==true)return true;
        if(jednakatjemena(t1.tacka1,t2.tacka2)==true&& jednakatjemena(t1.tacka2,t2.tacka1)==true && jednakatjemena(t1.tacka3,t2.tacka3)==true)return true;
        if(jednakatjemena(t1.tacka1,t2.tacka3)==true&& jednakatjemena(t1.tacka2,t2.tacka2)==true && jednakatjemena(t1.tacka3,t2.tacka1)==true)return true;
        if(jednakatjemena(t1.tacka1,t2.tacka1)==true&& jednakatjemena(t1.tacka2,t2.tacka3)==true && jednakatjemena(t1.tacka3,t2.tacka2)==true)return true;
    }
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2){
       bool potrebanuslov(false);
        double povrsina=t1.DajPovrsinu();
        if(jednakii(povrsina,t2.DajPovrsinu())==false)return false;
        if(jednakii(povrsina,t2.DajPovrsinu())==true)potrebanuslov=true;
        double delta=dajduzinu(t1.tacka1,t2.tacka1);
        if(potrebanuslov==true && jednaki(delta, dajduzinu(t1.tacka2,t2.tacka2))==true && jednaki(delta, dajduzinu(t1.tacka3,t2.tacka3))==true )return true;
        if(potrebanuslov==true && jednaki(delta, dajduzinu(t1.tacka2,t2.tacka3))==true && jednaki(delta, dajduzinu(t1.tacka3, t2.tacka2))==true)return true;
        delta=dajduzinu(t1.tacka1,t2.tacka2);
        if(potrebanuslov==true && jednaki(delta, dajduzinu(t1.tacka2,t2.tacka3))==true && jednaki(delta, dajduzinu(t1.tacka3,t2.tacka1))==true) return true;
        if(potrebanuslov==true && jednaki(delta, dajduzinu(t1.tacka2,t2.tacka1))==true && jednaki(delta, dajduzinu(t1.tacka3,t2.tacka3))==true) return true;
        delta=dajduzinu(t1.tacka1,t2.tacka3);
        if(potrebanuslov==true && jednaki(delta, dajduzinu(t1.tacka2,t2.tacka1))==true && jednaki(delta, dajduzinu(t1.tacka3,t2.tacka2))==true) return true;
        if(potrebanuslov==true && jednaki(delta, dajduzinu(t1.tacka3,t2.tacka1))==true && jednaki(delta, dajduzinu(t1.tacka2,t2.tacka2))==true) return true;
        delta=dajduzinu(t2.tacka2,t2.tacka3);
        if(potrebanuslov==true && jednaki(delta, dajduzinu(t1.tacka1,t2.tacka2))==true && jednaki(delta, dajduzinu(t1.tacka3,t2.tacka1))==true) return true;
        if(potrebanuslov==true && jednaki(delta, dajduzinu(t1.tacka2,t2.tacka3))==true && jednaki(delta, dajduzinu(t1.tacka3,t2.tacka1))==true) return true;
        return false;
    }
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2){
                //SSS
               if(DaLiSuIdenticni(t1,t2)==true )return true;
               //SUS
               double povrsinat1=t1.DajPovrsinu();
                double povrsinat2=t2.DajPovrsinu();
                if(povrsinat1>povrsinat2){
                    double broj=povrsinat1/povrsinat2;
                    if((broj -(int)broj)!=0)return false;
                    return true;
                }
                else if(povrsinat1<povrsinat2){
                    double broj=povrsinat2/povrsinat1;
                    if((broj -(int)broj)!=0)return false;
                    return true;
                }
                return false;
    }

    

};
int main ()
{
   int n;
   std::cout<<"Koliko zelite kreirati trouglova: ";
   std::cin>>n;
   std::vector<std::shared_ptr<Trougao>>v(n);
   for(int i=0;i<v.size();i++){
       std::cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
       Tacka t1,t2,t3;
       double x,y;
       std::cin>>x>>y;
       t1.first=x;t1.second=y;
       std::cin>>x>>y;
       t2.first=x;t2.second=y;
       std::cin>>x>>y;
       t3.first=x;t3.second=y;
       //Trougao(t1,t2,t3);
       std::shared_ptr<Trougao> p;
       p = std::make_shared<Trougao>(t1,t2,t3);
       v[i]=p;
   }
    std::cout<<"Unesite vektor translacije (dx dy): ";
    double jedan,dva;
    std::cin>>jedan>>dva;
    //std::vector<std::shared_ptr<Trougao>>novi(n);
    /*std::transform(v.begin(), v.end(), v.begin(),[jedan,dva](std::shared_ptr<Trougao> izmjena){
        (*izmjena).Transliraj(jedan, dva);
    });*/
    
    std::cout<<"Unesite ugao rotacije: ";
    double ugao;
    std::cin>>ugao;
    /*std::transform(v.begin(), v.end(), v.begin(),[ugao](std::shared_ptr<Trougao> izmjena){
        izmjena->Rotiraj(ugao);
    });*/
    std::cout<<"Unesite faktor skaliranja: ";
    double faktor;
    std::cin>>faktor;
   /* std::transform(v.begin(), v.end(), v.begin(),[faktor](std::shared_ptr<Trougao> izmjena){
        izmjena->Skaliraj(faktor);
    });*/
    std::cout<<"Trouglovi nakon obavljenih transformacija: ";
	return 0;
}