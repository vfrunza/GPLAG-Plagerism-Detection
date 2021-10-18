/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <utility>

typedef std::pair<double,double> Tacka;
class Trougao{
    Tacka t1,t2,t3;
    public:
    Trougao(const Tacka &t1,const Tacka &t2, const Tacka &t3){
        Postavi(t1,t2,t3);
    }
    void Postavi(const Tacka &t1,const Tacka &t2,const Tacka &t3){
        Trougao::t1=t1;Trougao::t2=t2;Trougao::t3=t3;
    }
    void Postavi(int indeks,const Tacka &t);
    static int Orijentacija(const Tacka &t1,const Tacka &t2,const Tacka &t3);
    Tacka DajTjeme(int indeks)const;
    double DajStranicu(int indeks)const;
    double DajUgao(int indeks)const;
    Tacka DajCentar()const;
    double DajObim()const;
    double DajPovrsinu()const;
};

Trougao::void Postavi(int indeks,const Tacka &t){
    if(indeks<1 || indeks>3)throw std::range_error("Nekorektan indeks");
    if(indeks==1){
        (*this).t1=t;
    }else if(indeks==2){
        (*this).t2=t;
    }else{
        (*this).t3=t;
    }
}
int Trougao::Orijentacija(const Tacka &t1,const Tacka &t2,const Tacka &t3){
    if((t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second))>0){
        return 1;
    }else if((t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second))<0){
        return -1;
    }else{
        return 0;
    }
}
Trougao::Tacka DajTjeme(int indeks)const{
    if(indeks<1 || indeks>3) throw std::range_error("Nekorektan indeks");
    if(indeks==1){
        return (*this).t1;
    }else if(indeks==2){
        return (*this).t2;
    }else{
        return (*this).t3;
    }
}
Trougao::double DajStranicu(int indeks)const{
    if(indeks<1 || indeks>3)throw std::range_error("Nekorektan indeks");
    if(indeks==1){
        return std::sqrt(std::pow((t3.first-t2.first),2)+std::pow((t3.second-t2.second),2));
    }else if(indeks==2){
        return std::sqrt(std::pow((t3.first-t1.first),2)+std::pow((t3.second-t1.second),2));
    }else{
        return std::sqrt(std::pow((t1.first-t2.first),2)+std::pow((t1.second-t2.second),2));
    }
}
Trougao::double DajUgao(int indeks)const{
    if(indeks<1 || indeks>3)throw std::range_error("Nekorektan indeks");
    if(indeks==1){
        return std::sqrt((-std::pow(DajStranicu(1),2)+std::pow(DajStranicu(2),2)+std::pow(DajStranicu(3),2))/(2*DajStranicu(2)*DajStranicu(3)));
    }else if(indeks==2){
        return std::sqrt((std::pow(DajStranicu(3),2)+std::pow(DajStranicu(1),2)-std::pow(DajStranicu(2),2))/(2*DajStranicu(3)*DajStranicu(1)));
    }else{
        return std::sqrt((std::pow(DajStranicu(2),2)+std::pow(DajStranicu(1),2)-std::pow(DajStranicu(1),2))/(2*DajStranicu(1)*DajStranicu(2)));
    }
}
Trougao::Tacka DajCentar()const{
    return Trougao((t1.first+t2.first+t3.first)/3,(t1.second+t2.second+t3.second)/3);
}
Trougao::double DajObim()const{
    return (DajStranicu(1)+DajStranicu(2)+DajStranicu(3));
}
Trougao::double DajPovrsinu()const{
    return std::fabs((t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second))/2;
}
int main ()
{
	return 0;
}