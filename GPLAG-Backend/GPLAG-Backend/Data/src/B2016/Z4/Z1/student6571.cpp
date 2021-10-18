/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <utility>
#include <stdexcept>
#include <cmath>
#include <memory>
#include <vector>
#include <algorithm>
const double PI=atan(1)*4;
typedef std::pair<double, double> Tacka;

class Trougao{
    Tacka a;
    Tacka b;
    Tacka c;

    public:
     Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        if(t1==t2 && t2==t3 && t3==t1) throw std::domain_error("Nekorektne pozicije tjemena");
        a=t1; b=t2; c=t3;
        
    }
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        a=t1;b=t2;c=t3;
    }
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

void Trougao::Postavi(int indeks, const Tacka &t){
    if(indeks<1 || indeks>2) throw std::range_error("Nekorektan indeks");
    
    if(indeks==1) a=t;
    if(indeks==2) b=t;
    if(indeks==3) c=t;
}
int Trougao::Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    double x1,y1,x2,y2,x3,y3;
        x1=t1.first;
        y1=t1.second;
        x2=t2.first;
        y2=t2.second;
        x3=t3.first;
        y3=t3.second;
    if((x1 == x2 && x2==x3 && x3==x1)||(y1==y2&&y2==y3&&y3==y1)) return 0;
   if(x1*(y2-y3)-x2*(y1-y3)+x3*(y1-y2) <0) return -1;
      if(x1*(y2-y3)-x2*(y1-y3)+x3*(y1-y2) >0) return 1;

}

Tacka Trougao::DajTjeme(int indeks )const {
    if(indeks==1) return a;
    if(indeks ==2) return b;
    if(indeks==3) return c;
}

double Trougao::DajStranicu(int indeks) const{
    double prva_x=a.first;
    double prva_y=a.second;
    double druga_x=b.first;
    double druga_y=b.second;
    double treca_x=c.first;
    double treca_y=c.second;
    double rezultat;
    if(indeks==1){
        rezultat=sqrt((druga_x-treca_x)*(druga_x-treca_x) + (druga_y-treca_y)*(druga_y-treca_y));
        return rezultat;
    }
    if(indeks==2){
        rezultat=sqrt((treca_x-prva_x)*(treca_x-prva_x)+(treca_y-prva_y)*(treca_y-prva_y));
        return rezultat;
    }
    if(indeks==3){
        rezultat=sqrt((prva_x-druga_x)*(prva_x-druga_x)+(prva_y-druga_y)*(prva_y-druga_y));
        return rezultat;
    }
}
double Trougao::DajUgao(int indeks) const{
double prva_x=a.first; double prva_y=a.second; double druga_x=b.first; double druga_y=b.second; double treca_x=c.first; double treca_y=c.second;
double stranica_a=sqrt((druga_x-treca_x)*(druga_x-treca_x)+(druga_y-treca_y)*(druga_y-treca_y));
double stranica_b=sqrt((treca_x-prva_x)*(treca_x-prva_x)+(treca_y-prva_y)*(treca_y-prva_y));
double stranica_c=sqrt((prva_x-druga_x)*(prva_x-druga_x)+(prva_y-druga_y)*(prva_y-druga_y));
double ugao;
if(indeks==1) {
    ugao=acos((stranica_b*stranica_b+stranica_c*stranica_c-stranica_a*stranica_a)/(2*stranica_b*stranica_c));
    ugao=ugao*(180/PI);
    return ugao;
}
if(indeks==2){
    ugao=acos((stranica_b*stranica_b+stranica_c*stranica_c-stranica_a*stranica_a)/(2*stranica_b*stranica_c));
    ugao=ugao*(180/PI);
    return ugao;
}
if(indeks==3){
    ugao=acos((stranica_a*stranica_a+stranica_b*stranica_b-stranica_c*stranica_c)/(2*stranica_a*stranica_b));
    ugao=ugao*(180/PI);
    return ugao;
}
}
Tacka Trougao::DajCentar() const{
    Tacka centar;
   // double prva_x=a.first, prva_y=a.second, druga_x=b.first, druga_y=b.second, treca_x=c.first, treca_y=c.second,centar_x=centar.first,centar_y=centar.second;
    
    centar.first=(a.first+b.first+c.first)/3.;
    centar.second=(a.second+b.second+c.second)/3.;
    return centar;
}
double Trougao::DajObim() const{
    double prva_x=a.first, prva_y=a.second, druga_x=b.first, druga_y=b.second, treca_x=c.first, treca_y=c.second;
    double stranica_a=sqrt((druga_x-treca_x)*(druga_x-treca_x)+(druga_y-treca_y)*(druga_y-treca_y));
    double stranica_b=sqrt((prva_x-treca_x)*(prva_x-treca_x)+(prva_y-treca_y)*(prva_y*treca_y));
    double stranica_c=sqrt((prva_x-druga_x)*(prva_x-druga_x)+(prva_y-druga_y)*(prva_y-druga_y));
    double Obim=stranica_a+stranica_b+stranica_c;
    return Obim;
 }
double Trougao::DajPovrsinu() const{
      double prva_x=a.first, prva_y=a.second, druga_x=b.first, druga_y=b.second, treca_x=c.first, treca_y=c.second;
    double Povrsina=prva_x*(druga_y-treca_y)-druga_x*(prva_y-treca_y)+treca_x*(prva_y-druga_y);
    Povrsina = Povrsina/2;
    return Povrsina;
 }
bool Trougao::DaLiJePozitivnoOrijentiran()const{
      double x1=a.first, y1=a.second, x2=b.first, y2=b.second, x3=c.first, y3=c.second;
   if(x1*(y2-y3)-x2*(y1-y3)+x3*(y1-y2) <0) return false;
      if(x1*(y2-y3)-x2*(y1-y3)+x3*(y1-y2) >0) return true;
 }
bool Trougao::DaLiJeUnutra(const Tacka &t) const{
    double testna_x=t.first, testna_y=t.second;
     double prva_x=a.first, prva_y=a.second, druga_x=b.first, druga_y=b.second, treca_x=c.first, treca_y=c.second;
    if((testna_x<=prva_x && testna_x<=druga_x && testna_x<=treca_x)||(testna_y<=prva_y&&testna_y<=druga_y&&testna_y<=treca_y)||(testna_x>=prva_x && testna_x>=druga_x && testna_x>=treca_x)||(testna_y>=prva_y&&testna_y>=druga_y&&testna_y>=treca_y)) return false;
    
    return true;
    
 }
void Trougao::Ispisi() const{
  //  a.first=int(a.first);     b.first=int(b.first);     c.first=int(c.first);     a.second=int(a.second); b.second=int(b.second); c.second=int(c.second);



    std::cout<<"(("<<(int)a.first<<","<<(int)a.second<<") , ("<<(int)b.first<<","<<(int)b.second<<") , ("<<(int)c.first<<","<<(int)c.second<<"))"<<std::endl;
 }
void Trougao::Transliraj(double delta_x, double delta_y){
a.first += delta_x; b.first += delta_x; c.first += delta_x; a.second += delta_y; b.second += delta_y; c.second += delta_y;
 }

void Trougao::Centriraj(const Tacka &t){
        double prva_x=a.first, prva_y=a.second, druga_x=b.first, druga_y=b.second, treca_x=c.first, treca_y=c.second;
        double staro_x=(prva_x+druga_x+treca_x)/3;
        double staro_y=(prva_y+druga_y+treca_y)/3;
        double razlika_x, razlika_y;
        double nova_x=t.first, nova_y=t.second;
        razlika_x=nova_x-staro_x;
        razlika_y=nova_y-staro_y;
        double nova_x1, nova_x2, nova_x3, nova_y1, nova_y2, nova_y3;
        nova_x1=razlika_x+prva_x;
        nova_x2=razlika_x+druga_x;
        nova_x3=razlika_x+treca_x;
        nova_y1=razlika_y+prva_y;
        nova_y2=razlika_y+druga_y;
        nova_y3=razlika_y+treca_y;
 }
void Trougao::Rotiraj(const Tacka &t, double ugao){
    a.first=t.first+(a.first-t.first)*cos(ugao)-(a.second-t.second)*sin(ugao);
    a.second=t.second+(a.first-t.first)*sin(ugao)+(a.second-t.second)*cos(ugao);
    b.first=t.first+(b.first-t.first)*cos(ugao)-(b.second-t.second)*sin(ugao);
    b.second=t.second+(b.first-t.first)*sin(ugao)+(b.second-t.second)*cos(ugao);
    c.first=t.first+(c.first-t.first)*cos(ugao)-(c.second-t.second)*sin(ugao);
    c.second=t.second+(c.first-t.first)*sin(ugao)+(c.second-t.second)*cos(ugao);
 }
void Trougao::Skaliraj(const Tacka &t, double faktor){
        //if(faktor>0){
        a.first=t.first+faktor*(a.first-t.first);
        a.second=t.second+faktor*(a.second-t.second);
        b.first=t.first+faktor*(b.first-t.first);
        b.second=t.second+faktor*(b.second-t.second);
        c.first=t.first+faktor*(c.first-t.first);
        c.second=t.second+faktor*(c.second-t.second);
        /*}
        if(faktor<0){
            double dodatno_x1, dodatno_y1, dodatno_x2, dodatno_y2, dodatno_x3, dodatno_y3;
        skalirano_x1=centar_x+faktor*(prva_x-centar_x);
        skalirano_y1=centar_y+faktor*(prva_y-centar_y);
        skalirano_x2=centar_x+faktor*(druga_x-centar_x);
        skalirano_y2=centar_y+faktor*(druga_y-centar_y);
        skalirano_x3=centar_x+faktor*(treca_x-centar_x);
        skalirano_x3=centar_y+faktor*(treca_y-centar_y);
        dodatno_x1=centar_x+(skalirano_x1-centar_x)*cos(180)-(skalirano_y1-centar_y)*sin(180);
        dodatno_y1=centar_y+(skalirano_x1-centar_x)*sin(180)+(skalirano_y1-centar_y)*cos(180);
        dodatno_x2=centar_x+(skalirano_x2-centar_x)*cos(180)-(skalirano_y2-centar_y)*sin(180);
        dodatno_y2=centar_y+(skalirano_x2-centar_x)*sin(180)+(skalirano_y2-centar_y)*cos(180);
        dodatno_x3=centar_x+(skalirano_x3-centar_x)*cos(180)-(skalirano_y3-centar_y)*sin(180);
        dodatno_y3=centar_y+(skalirano_x3-centar_x)*sin(180)+(skalirano_y3-centar_y)*cos(180);
        }*/
        if(faktor==0) throw std::domain_error("Nekorektan faktor skaliranja");
 }
void Trougao::Rotiraj(double ugao){
      Tacka d=DajCentar();
      double teziste_x=d.first;
      double teziste_y=d.second;
        //double teziste_x=(a.first+b.first+c.first)/3.;
      //  double teziste_y=(a.second + b.second + c.second)/3.;
      a.first=teziste_x+(a.first-teziste_x)*cos(ugao)-(a.second-teziste_y)*sin(ugao);
        a.second=teziste_y+(a.first-teziste_x)*sin(ugao)+(a.second-teziste_y)*sin(ugao);
       b.first=teziste_x+(b.first-teziste_x)*cos(ugao)-(b.second-teziste_y)*sin(ugao);
        b.second=teziste_y+(b.first-teziste_x)*sin(ugao)+(b.second-teziste_y)*cos(ugao);
        c.first=teziste_x+(c.first-teziste_x)*cos(ugao)-(c.first-teziste_x)*sin(ugao);
        c.second=teziste_y+(c.first-teziste_x)*sin(ugao)+(c.second-teziste_y)*cos(ugao);

 }
 void Trougao::Skaliraj(double faktor){
        double prva_x=a.first, prva_y=a.second, druga_x=b.first, druga_y=b.second, treca_x=c.first, treca_y=c.second;
        double skalirano_x1=0,skalirano_y1=0,skalirano_x2=0,skalirano_y2=0,skalirano_x3=0,skalirano_y3=0;
        double centar_x=(prva_x+druga_x+treca_x)/3;
        double centar_y=(prva_y+druga_y+treca_y)/3;
         if(faktor>0){
        skalirano_x1=centar_x+faktor*(prva_x-centar_x);
        skalirano_y1=centar_y+faktor*(prva_y-centar_y);
        skalirano_x2=centar_x+faktor*(druga_x-centar_x);
        skalirano_y2=centar_y+faktor*(druga_y-centar_y);
        skalirano_x3=centar_x+faktor*(treca_x-centar_x);
        skalirano_x3=centar_y+faktor*(treca_y-centar_y);
        }
        if(faktor<0){
            double dodatno_x1, dodatno_y1, dodatno_x2, dodatno_y2, dodatno_x3, dodatno_y3;
        skalirano_x1=centar_x+faktor*(prva_x-centar_x);
        skalirano_y1=centar_y+faktor*(prva_y-centar_y);
        skalirano_x2=centar_x+faktor*(druga_x-centar_x);
        skalirano_y2=centar_y+faktor*(druga_y-centar_y);
        skalirano_x3=centar_x+faktor*(treca_x-centar_x);
        skalirano_x3=centar_y+faktor*(treca_y-centar_y);
        dodatno_x1=centar_x+(skalirano_x1-centar_x)*cos(180)-(skalirano_y1-centar_y)*sin(180);
        dodatno_y1=centar_y+(skalirano_x1-centar_x)*sin(180)+(skalirano_y1-centar_y)*cos(180);
        dodatno_x2=centar_x+(skalirano_x2-centar_x)*cos(180)-(skalirano_y2-centar_y)*sin(180);
        dodatno_y2=centar_y+(skalirano_x2-centar_x)*sin(180)+(skalirano_y2-centar_y)*cos(180);
        dodatno_x3=centar_x+(skalirano_x3-centar_x)*cos(180)-(skalirano_y3-centar_y)*sin(180);
        dodatno_y3=centar_y+(skalirano_x3-centar_x)*sin(180)+(skalirano_y3-centar_y)*cos(180);
        }
        if(faktor==0) throw std::domain_error("Nekorektan faktor skaliranja");


 }
 bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2){
        if((t1.a==t2.a || t1.a==t2.b || t1.a==t2.c )&&(t1.b==t2.a || t1.b==t2.b || t1.b==t2.c)&&(t1.c==t2.a||t1.c==t2.b||t1.c==t2.c)) return true;
        
        return false;
 }
 bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2){
     Trougao t=t1;
     double delta_x,delta_y;
     delta_x=t1.DajTjeme(1).first-t2.DajTjeme(1).first;
     delta_y=t1.DajTjeme(1).second-t2.DajTjeme(1).second;
   t.Transliraj(delta_x,delta_y);
   if(DaLiSuIdenticni(t,t2)) return true;
   else {
       double ugao1, ugao2, ugao;
       ugao1=t.DajUgao(1); ugao2=t2.DajUgao(1);
       ugao=ugao2-ugao1;
       t.Rotiraj(ugao);
       if(DaLiSuIdenticni(t,t2)){
           return true;
       } else return false;
   }
    
 }
 bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2){
     Trougao t=t1;
     double delta_x,delta_y;
     delta_x=t1.DajTjeme(1).first-t2.DajTjeme(1).first;
     delta_y=t1.DajTjeme(1).second-t2.DajTjeme(1).second;
     t.Transliraj(delta_x,delta_y);
     if(DaLiSuIdenticni(t,t2)){
         return true;
     }
     double ugao1,ugao2,ugao;
     ugao1=t.DajUgao(1); ugao2=t2.DajUgao(1);
     ugao=ugao2-ugao1;
     t.Rotiraj(ugao);
     if(DaLiSuIdenticni(t,t2)){
         return true;
     }
     Tacka prva=t1.a;
     double faktor=1;
     t.Skaliraj(prva,faktor);
     if(DaLiSuIdenticni(t,t2)){
         return true;
     } else return false;
     
 }
int main ()
{
  
    Tacka a1,b1,c1;
   // Trougao k;
    std::vector<std::shared_ptr<Trougao>> vektor;
   
 int n;
 std::cout<<"Koliko zelite kreirati trouglova: "<<std::endl;
 std::cin>>n;
  //std::shared_ptr<Trougao> vektor[100];
  
 for(int i=0; i<n; i++){
     std::cout<<"Unesite podatke za "<<i+1<<".trougao (x1 y1 x2 y2 x3 y3): ";
     std::cin>>a1.first; std::cin>>a1.second; std::cin>>b1.first; std::cin>>b1.second; std::cin>>c1.first; std::cin>>c1.second;
         vektor.push_back(std::make_shared<Trougao>(a1,b1,c1));
    
     
 }
 double dx,dy;
 std::cout<<"Unesite vektor translacije (dx dy): ";
 std::cin>>dx>>dy;
 double ugao;
 std::cout<<"Unesite ugao rotacije: ";
 std::cin>>ugao;
 double faktor;
 std::cout<<"Unesite faktor skaliranja: ";
 std::cin>>faktor;
 std::transform(vektor.begin(), vektor.end(), vektor.begin(), [dx,dy](std::shared_ptr<Trougao> t){t->Transliraj(dx,dy);return t;});
 
  std::transform(vektor.begin(), vektor.end(), vektor.begin(), [ugao](std::shared_ptr<Trougao> t){t->Rotiraj(ugao); return t;});
std::transform(vektor.begin(), vektor.end(), vektor.begin(), [faktor](std::shared_ptr<Trougao> t){t->Skaliraj(faktor); return t;});
 std::cout<<"Trouglovi nakon obavljenih transformacija: "<<std::endl;
 for(int i=0; i<n; i++){
     vektor[i].DajPovrsinu();
     vektor[i]->Ispisi();
 }
/* for(int i=0; i<n; i++){
     vektor[i]->DajPovrsinu();
     vektor[i]->Ispisi();
    
 }*/
	return 0;
}