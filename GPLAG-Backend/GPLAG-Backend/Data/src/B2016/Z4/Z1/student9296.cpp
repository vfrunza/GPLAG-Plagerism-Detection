/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <utility>
#include <vector>
#include <algorithm>
#include <memory>
#include <cmath>
const double epsilon(1e-10);
typedef std::pair<double, double> Tacka;
double Izraz(const Tacka t1, const Tacka t2, const Tacka t3){
    return t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second);
}
class Trougao{
    Tacka t1, t2, t3;
    bool ValidnostIndexa(int index)const{
        if(index!=1 && index!=2 && index!=3) return false;
        return true;
    }
    static bool UporediDoubleove(double x, double y){
        if(fabs(x-y)<=epsilon) return true;  //isti su
        return false;
    }
    static bool UporediPoOstatku(double x, double y){
        x+=0.5; y+=0.5;
        if(fabs((int)x % (int)y)<=epsilon) return true;  //moooozda ne bude radilo kako treba
        return false;
    }
    static void Skalirano(const Tacka centar, Tacka t, int faktor){
        t.first=centar.first+faktor*(t.first-centar.first);
        t.second=centar.second+faktor*(t.second-centar.second);
    }
    static Tacka DajRotiranuTacku(const Tacka &t, const Tacka &pom, double ugao){
        Tacka nova(t.first+(pom.first-t.first)*cos(ugao)-(pom.second-t.second)*sin(ugao), t.second+(pom.first-t.first)*sin(ugao)+(pom.second-t.second)*cos(ugao));
        return nova;
    }
public:
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3){Postavi(t1,t2,t3);}
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        if(!(Orijentacija(t1, t2, t3)))
            throw std::domain_error("Nekorektne pozicije tjemena");
        Trougao::t1=t1; Trougao::t2=t2; Trougao::t3=t3;
    }
    void Postavi(int index, const Tacka &t){
        if(!ValidnostIndexa(index)) throw std::range_error("Nekorektan indeks");
        if(!Orijentacija(t1,t2,t) || !Orijentacija(t,t2,t3) || !Orijentacija(t1,t,t3)) throw std::domain_error("Nekorektne pozicije tjemena");
        if(index==1) t1=t;
        else if(index==2) t2=t;
        else t3=t;
    }
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        if(Izraz(t1,t2,t3)<0) return -1;
        else if(Izraz(t1,t2,t3)>0) return 1;
        return 0;
    }
    Tacka DajTjeme(int index)const{
        if(!ValidnostIndexa(index)) throw std::range_error("Nekorektan indeks");
        if(index==1) return t1;
        else if(index==2) return t2;
        return t3;
    }
    double DajStranicu(int index)const{
        if(index==1) return std::sqrt(pow(t2.first - t3.first, 2) - pow(t2.second - t3.second, 2));
        else if(index==2) return std::sqrt(pow(t3.first - t1.first, 2) - pow(t3.second - t1.second, 2));
        return std::sqrt(pow(t1.first - t2.first, 2) - pow(t1.second - t2.second, 2));  //ovo moze u pomocnu
    }
    double DajUgao(int index)const{
        double a(DajStranicu(1)), b(DajStranicu(2)), c(DajStranicu(3));
        if(index==1) return acos((c*c + b*b - a*a)/2*c*b);
        else if(index==2) return acos((a*a + c*c - b*b)/2*a*c);
        return acos((a*a + b*b - c*c)/2*a*b);
    }
    Tacka DajCentar()const{Tacka centar((t1.first + t2.first + t3.first)/2, (t1.second + t2.second + t3.second)/2); return centar;}
    double DajObim()const{return DajStranicu(1)+DajStranicu(2)+DajStranicu(3);}
    double DajPovrsinu()const{return 1./2 * fabs(Izraz(t1,t2,t3));}
    bool DaLiJePozitivnoOrijentiran()const{
        if(Orijentacija(t1, t2, t3)<=0) return false;
        return true;
    }
    bool DaLiJeUnutra(const Tacka &t)const{
        int help(Orijentacija(t1,t2,t3));
        double povrs(DajPovrsinu());
        if(help!=Orijentacija(t1,t2,t) || help!=Orijentacija(t2,t3,t) || help!=Orijentacija(t3,t1,t)) return false;
        if(UporediDoubleove(povrs, 1./2 * fabs(Izraz(t1,t2,t))) || UporediDoubleove(povrs, 1./2*fabs(Izraz(t2,t3,t))) || UporediDoubleove(povrs, 1./2*fabs(Izraz(t3,t1,t)))) return false;
        return true;
    }
    void Ispisi()const{std::cout<<"(("<<t1.first<<","<<t1.second<<"),("<<t2.first<<","<<t2.second<<"),("<<t3.first<<","<<t3.second<<"))";}
    void Transliraj(double delta_x, double delta_y){
        t1.first+=delta_x; t1.second+=delta_y; t2.first+=delta_x; t2.second+=delta_y; t3.first+=delta_x; t3.second+=delta_y;
    }
    void Centriraj(const Tacka &t){     //nisam sigurna je li ovo 100% dobro; msm da bi trebalo dodati provjeru
        auto centar(DajCentar());
        Transliraj(centar.first-t.first, centar.second-t.second);
    }
    void Rotiraj(const Tacka &t, double ugao){
        t1=DajRotiranuTacku(t,t1,ugao); t2=DajRotiranuTacku(t,t2,ugao); t3=DajRotiranuTacku(t,t3,ugao);
    }
    void Skaliraj(const Tacka &t, double faktor){
        if(!faktor) throw std::domain_error("Nekorektan faktor skaliranja");
        Skalirano(t,t1,faktor); Skalirano(t,t2,faktor); Skalirano(t,t3,faktor);
    }
    void Rotiraj(double ugao){Rotiraj(DajCentar(), ugao);}
    void Skaliraj(double faktor){Skaliraj(DajCentar(),faktor);}
    friend bool DaLiSuIdenticni(const Trougao &T1, const Trougao &T2);
    friend bool DaLiSuPodudarni(const Trougao &T1, const Trougao &T2);
    friend bool DaLiSuSlicni(const Trougao &T1, const Trougao &T2);
};
void DaLiNesto(std::vector<std::shared_ptr<Trougao>> v, bool f(const Trougao &t1, const Trougao &t2)){
    for(int i=0; i<v.size(); i++){
        for(int j=0; j<v.size(); j++){
            if(i==j) continue;
            if(f(*v[i],*v[j])){
                v[i]->Ispisi();
                std::cout<<" i ";
                v[j]->Ispisi();
            }
        }
        std::cout<<std::endl;
    }
}
bool DaLiSuIdenticni(const Trougao &T1, const Trougao &T2){
    Tacka c1(T1.DajCentar()), c2(T2.DajCentar());
    if(!Trougao::UporediDoubleove(c1.first, c2.first) || !Trougao::UporediDoubleove(c1.second, c2.second)) return false;
    return true;
}
bool DaLiSuPodudarni(const Trougao &T1,const Trougao &T2){
    if(T1.Orijentacija(T1.t1, T1.t2, T1.t3)!=T2.Orijentacija(T2.t1,T2.t2,T2.t3)) return false;
    if(!Trougao::UporediDoubleove(T1.DajStranicu(1), T2.DajStranicu(1))
    || !Trougao::UporediDoubleove(T1.DajStranicu(2), T2.DajStranicu(2))
    || !Trougao::UporediDoubleove(T1.DajStranicu(3), T2.DajStranicu(3))) return false;
    return true;
}
bool DaLiSuSlicni(const Trougao &T1,const Trougao &T2){
    if(T1.Orijentacija(T1.t1,T1.t2,T1.t3)!=T2.Orijentacija(T2.t1,T2.t2,T2.t3)) return false;
    if(!Trougao::UporediPoOstatku(T1.DajStranicu(1), T2.DajStranicu(1)) 
    || !Trougao::UporediPoOstatku(T1.DajStranicu(2), T2.DajStranicu(2))
    || !Trougao::UporediPoOstatku(T1.DajStranicu(3), T2.DajStranicu(3))) return false;
    return true;
}
int main ()
{
    int n;
    std::cout<<"Koliko zelite kreirati trouglova: ";
    std::cin>>n;
    std::vector<std::shared_ptr<Trougao>>trouglovi;
    for(int i=0; i<n; i++){
        Tacka t1,t2,t3;
        std::cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
        std::cin>>t1.first>>t1.second>>t2.first>>t2.second>>t3.first>>t3.second;
        try{
            Trougao t(t1,t2,t3);
            trouglovi.push_back(std::make_shared<Trougao>(t));
        }
        catch(std::domain_error w){
            std::cout<<w.what()<<std::endl;
            i--;
        }
    }
    std::cout<<"Unesite vektor translacije (dx dy): ";
    double delx, dely;
    std::cin>>delx>>dely;
    std::cout<<"Unesite ugao rotacije: ";
    double ugao;
    std::cin>>ugao;
    std::cout<<"Unesite faktor skaliranja: ";
    double faktor;
    std::cin>>faktor;
    std::transform(trouglovi.begin(), trouglovi.end(), trouglovi.begin(), [delx,dely,ugao,faktor](std::shared_ptr<Trougao> &t){
        t->Transliraj(delx,dely); t->Rotiraj(ugao); t->Skaliraj(t->DajTjeme(1), faktor); return t;});
    std::sort(trouglovi.begin(), trouglovi.end(), [](std::shared_ptr<Trougao> t1, std::shared_ptr<Trougao> t2){
        return t1->DajPovrsinu()<t2->DajPovrsinu();});
    std::cout<<"Trouglovi nakon obavljenih transformacija: "<<std::endl;
    std::for_each(trouglovi.begin(), trouglovi.end(), [](std::shared_ptr<Trougao> t){t->Ispisi(); std::cout<<std::endl;});
    std::cout<<"Trougao sa najmanjim obimom: ";
    (*std::min_element(trouglovi.begin(), trouglovi.end(), [](std::shared_ptr<Trougao> t1, std::shared_ptr<Trougao> t2){return t1->DajObim()<t2->DajObim();}))->Ispisi();
    std::cout<<std::endl<<"Parovi identicnih trouglova:"<<std::endl;
    DaLiNesto(trouglovi,DaLiSuIdenticni);
    std::cout<<"Parovi podudarnih trouglova:"<<std::endl;
    DaLiNesto(trouglovi,DaLiSuPodudarni);
    std::cout<<"Parovi slicnih trouglova:"<<std::endl;
    DaLiNesto(trouglovi,DaLiSuSlicni);
	return 0;
	
	
	
	
	
	
	
	
	
}