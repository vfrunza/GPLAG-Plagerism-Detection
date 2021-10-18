/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <utility>
#include <stdexcept>
#include <cmath>



typedef std::pair<double,double> Tacka;

class Trougao{
    Tacka t1;
    Tacka t2;
    Tacka t3;
    bool static TestIndeksa (int indeks){
        if(indeks<1 || indeks>3) return false;
        else return true;
    }
    double Povrsina(Tacka t1, Tacka t2, Tacka t3){
        double P;
        P=t1.first*(t2.second-t3.second)-t2.first*(t3.second-t1.second)+t3.first*(t1.second-t2.second);
        return P;
    }
    public:
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        double P=Povrsina(t1,t2,t3);
        if(P==0) throw std::domain_error ("Nekorektne pozicije tjemena");
        else{
        Trougao::t1=t1;
        Trougao::t2=t2;
        Trougao::t3=t3;
        }
    }
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        double P=Povrsina(t1,t2,t3);
        if(P==0) throw std::domain_error ("Nekorektne pozicije tjemena");
        else{
        Trougao::t1=t1;
        Trougao::t2=t2;
        Trougao::t3=t3;
        }
    } 
    void Postavi(int indeks, const Tacka &t){
        if(!(TestIndeksa(indeks))) throw std::range_error ("Nekorektan indeks");
        else{
            switch(indeks){
                case 1: { t1=t; break; }
                case 2: { t2=t; break; }
                case 3: { t3=t; break; }
            }
        }
    }
    int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        double P=Povrsina(t1,t2,t3);
        if(P>0) return 1;
        if(P<0) return -1;
        else return 0;
    }
    Tacka DajTjeme (int indeks) const {
        if(!(TestIndeksa(indeks)))   throw std::range_error ("Nekorektan indeks");
        else {
             switch(indeks){
                case 1: { return t1; break; }
                case 2: { return t2; break; }
                case 3: { return t3; break; }
            }
        }
    }
    double DajStranicu(int indeks) const{
        if(!(TestIndeksa(indeks))) throw std::range_error ("Nekorektan indeks");
        else {
            switch(indeks){
                case 1:{
                    double d=std::sqrt((t3.first-t2.first)*(t3.first-t2.first)+(t3.second-t2.second)*(t3.second-t2.second));
                    return d;
                    break;
                }
                case 2:{
                    double d=std::sqrt((t3.first-t1.first)*(t3.first-t1.first)+(t3.second-t1.second)*(t3.second-t1.second));
                    return d;
                    break;
                }
                case 3:{
                    double d=std::sqrt((t2.first-t1.first)*(t2.first-t1.first)+(t2.second-t1.second)*(t2.second-t1.second));
                    return d;
                    break;
                }
            }
        }
    }
    double DajUgao(int indeks) const {
        if(!(TestIndeksa(indeks))) throw std::range_error ("NEkorektan indeks");
        else {
            double a=DajStranicu(1);
            double b=DajStranicu(2);
            double c=DajStranicu(3);
            switch(indeks){
                case 1:{
                    double Alfa=acos((b*b+c*c-a*a)/(2*b*c));
                    return Alfa;
                    break;
                }
                case 2:{
                    double Beta=acos((a*a+c*c-b*b)/(2*a*c));
                    return Beta;
                    break;
                }
                case 3:{
                    double Gama=acos((a*a+b*b-c*c)/(2*a*b));
                    return Gama;
                    break;
                }
            }
        }
    }
    Tacka DajCentar() const {
        double Xt=(t1.first+t2.first+t3.first)/3.;
        double Yt=(t1.second+t2.second+t3.second)/3.;
        Tacka centar=std::make_pair(Xt,Yt);
        return centar;
    }
    double DajObim()const {
        double a=DajStranicu(1);
        double b=DajStranicu(2);
        double c=DajStranicu(3);
        double O=a+b+c;
        return O;
    }
    double DajPovrsinu()const{
     
    } 
    bool DaLiJePozitivnoOrijentiran() const {
        
    }
    bool DaLiJeUnutra(const Tacka &t) const{
        
    }
    void Ispisi()const {
        std::cout<<"(("<<t1.first<<","<<t1.second<<") , ("<<t2.first<<","<<t2.second<<") , ("<<t3.first<<","<<t3.second<<"))";
    }
};
int main ()
{
    Trougao Abc({{1,0},{4,-2},{4,4}});
    int a(Abc.Orijentacija({1,0},{4,-2},{4,4}));
    Abc.Postavi(3,{3,3});
    std::cout<<a;
    Tacka b;
    b=Abc.DajTjeme(1);
    std::cout<<"asdasd"<<b.first<<",,,"<<b.second;
    double str=Abc.DajStranicu(1);
    std::cout <<"str:"<<str;
    Abc.Ispisi();
	return 0;
}