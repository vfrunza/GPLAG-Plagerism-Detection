/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <utility>
#include <cmath>
using namespace std;
typedef std::pair<double, double> Tacka;
class Trougao{
    Tacka t[3];
    public:
    Trougao(const Tacka &t1,const Tacka &t2,const Tacka &t2){
        Trougao::t[0]=t1;
        Trougao::t[1]=t2;
        Trougao::t[2]=t3;
    }
    void Postavi(const Tacka &t1,const Tacka &t2,const Tacka &t2){
         Trougao::t[0]=t1;
        Trougao::t[1]=t2;
        Trougao::t[2]=t3;
    }
    void Postavi(int indeks,const Tacka &t){
        Trougao::t[indeks]=t;
    }
    static int Orijentacija(const Tacka &t1,const Tacka &t2,const Tacka &t2){
    if(t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)-t3.first*(t1.second-t2.second)>0) return 1;
    else
    if(t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)-t3.first*(t1.second-t2.second)<0) return -1;
    else
    return 0;
     }
    Tacka DajTjeme(int indeks) const {return t[indeks];}
    double DajStranicu(int indeks)const{ 
        if(indeks==0) return Duzina(t[1],t[2]);
        else
        if(indeks==1) return Duzina(t[0],t[2]);
        else
        return Duzina(t[0],t[1]);
    }
    double DajUgao(int indeks)const{
    double a=Duzina(t[1],t[2]);
    double b=Duzina(t[0],t[2]);
    double c=Duzina(t[0],t[1]);
    if(indeks==0) return acos((b*b+c*c-a*a)/(2*b*c))*4*atan(1)/180;
    else if(indeks==1) return acos((a*a+c*c-b*b)/(2*a*c))*4*atan(1)/180;
    else return acos((a*a+b*b-c*c)/(2*a*b))*4*atan(1)/180;
    }
    Tacka DajCentar(){
        Tacka t=make_pair((t[0].first+t[1].first+t[2].first)/3,(t[0].second+t[1].second+t[2].second)/3);
        return t;
    }
    double DajObim()const{return Duzina(t[1],t[2])+Duzina(t[0],t[2])+Duzina(t[0],t[1]);}
    double DajPovrsinu()const{return 0.5*abs(Povrsina);}
    bool DaLiJePozitivnoOrijentirana()const{if(Orijentacija(t[0],t[1],t[2])>0)return true;
        else if(Orijentacija(t[0],t[1],t[2])<0) return false;
    }
    bool DaLiJeUnutra(Tacka &t)const{
        if(Orijentacija(t[0],t[1],t[2])==Orijentacija(t,t[1],t[2]) && Orijentacija(t[0],t[1],t[2])==Orijentacija(t[0],t,t[2]) && Orijentacija(t[0],t[1],t[2])==Orijentacija(t[0],t[1],t)) return true;
        else return false;
    }
    void Ispisi()const{cout<<"(("<<t[0].first<<","<<t[0].second<<")"<<",("<<t[1].first<<","<<t[1].second<<")"<<",("<<t[2].first<<","<<t[2].second<<"))";}
    void Transliraj(double delta_x,double delta_y){
    Transliraj(t[0],delta_x,delta_y);
     Transliraj(t[1],delta_x,delta_y);
      Transliraj(t[2],delta_x,delta_y);
    }
    void Centriraj(const Tacka &t){
    Tacka c=DajCentar();
    Centriraj(t[0],t,c);
    Centriraj(t[1],t,c);
    Centriraj(t[2],t,c);
    }
    void Rotiraj(const Tacka &t, double ugao){
          Rotiraj(t[0],t,ugao);
       Rotiraj(t[1],t,ugao);
       Rotiraj(t[2],t,ugao);
    }
    void Skaliraj(const Tacka &t,double faktor){
      Skaliraj(t[0],t,faktor);
   Skaliraj(t[1],t,faktor);
   Skaliraj(t[2],t,faktor);
    }
    void Rotiraj(double ugao){
      Tacka t=DajCentar();
       Rotiraj(t[0],t,ugao);
       Rotiraj(t[1],t,ugao);
       Rotiraj(t[2],t,ugao);
    }
    void Skaliraj(double faktor){
        Tacka t=DajCentar();
   Skaliraj(t[0],t,faktor);
   Skaliraj(t[1],t,faktor);
   Skaliraj(t[2],t,faktor);
    }
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);
friend void Skaliraj(Tacka &t,const Tacka &p,double faktor);
friend void Rotiraj(Tacka &t,const Tacka &p,double ugao);
friend void Centriraj(Tacka &t, const Tacka &p);
friend void Transliraj(Tacka &t,double dx,double dy);
friend double Duzina(const Tacka &t,const Tacka &p);
};
bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2){
if((t1[0]==t2[0] || t1[0]==t2[1] || t1[0]==t2[2])&&(t1[1]==t2[0] || t1[1]==t2[1] || t1[1]==t2[2])&&(t1[2]==t2[0] || t1[2]==t2[1] || t1[2]==t2[2])) return true;
else return false;
}
bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2){
    
}
bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2){

}
void Skaliraj(Tacka &t,const Tacka &p,double faktor){
     t.first=p.first+faktor*(p.first-t.first);
    t.second=p.second+faktor*(p.second-t.second);
}
void Rotiraj(Tacka &t,const Tacka &p,double ugao){
      t.first=p.first+(t.first-p.first)*cos(ugao)-(t.second-p.second)*sin(ugao);
    t.second=p.second+(t.first-p.first)*sin(ugao)-(t.second-p.second)*cos(ugao);
}
void Centriraj(Tacka &t, const Tacka &p,const Tacka &q){
     t.first+=p.first-q.first;
     t.first+=q.first-p.first;
}
void Transliraj(Tacka &t,double dx,double dy){
       t.first+=dx;
       t.second+=dy;
}
double Duzina(const Tacka &t,const Tacka &p){
    return sqrt((t.first-p.first)*(t.first-p.first)+(t.second-p.second)*(t.second-p.second));
}
int main ()
{
     
     
	return 0;
}