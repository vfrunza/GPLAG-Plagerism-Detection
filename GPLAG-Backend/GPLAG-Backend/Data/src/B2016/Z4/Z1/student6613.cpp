/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include<stdexcept>
#include<utility>
#include<vector>
#include<cmath>
using std::cin;
using std::cout;
using std::endl;
typedef std::pair<double, double> Tacka;
class Trougao{
    Tacka t1, t2, t3;
    static double izraz(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        return  (t1.first*(t2.second-t3.second))+(t2.first*(t1.second-t3.second))+(t3.first*(t1.second-t2.second));
    }
    static void index(int indeks){
        if(indeks!=1 || indeks!=2 || indeks!=3) throw std::range_error("Nekorektan indeks");
    }
    double d(const Tacka &t1, const Tacka &t2)const{
        return std::sqrt((t2.first-t1.first)*(t2.first-t1.first)+(t2.second-t1.second)*(t2.second-t1.second));
    }
    static bool Iste(const Tacka &t1, const Tacka &t2){
        int br=0;
        double epsilon(1E-10);
        if(t1.first+epsilon==t2.first || t1.first==t2.first+epsilon || t1.first==t2.first) br++;
        if(t1.second+epsilon==t2.second || t1.second==t2.second+epsilon || t1.second==t2.second) br++;
        if(br==2) return 1;
        else return 0;
    }
    public:
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        if(!izraz(t1, t2, t3)) throw std::domain_error("Nekorektne pozicije tjemena");
        Trougao::t1=t1; Trougao::t2=t2; Trougao::t3=t3;
    }
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        if(!izraz(t1, t2, t3)) throw std::domain_error("Nekorektne pozicije tjemena");
        Trougao::t1=t1; Trougao::t2=t2; Trougao::t3=t3;
    }
    void Postavi(int indeks, const Tacka &t){
        index(indeks);
        if(indeks==1) t1=t;
        else if(indeks==2) t2=t;
        else t3=t;
    }
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        Trougao t(t1, t2, t3);
        if(izraz(t1, t2, t3)>0) return 1;
        else if(izraz(t1, t2, t3)<0) return -1;
        else return 0;
    }
    Tacka DajTjeme(int indeks) const{
        index(indeks);
        if(indeks==1) return t1;
        else if(indeks==2) return t2;
        else return t3;
    }
    double DajStranicu(int indeks) const{
        index(indeks);
        if(indeks==1) return d(t2, t3);
        else if(indeks==2) return d(t1,t3);
        else return d(t1, t2);
    }
    double DajUgao(int indeks) const{
        index(indeks);
        if(indeks==1) return (acos(((d(t1,t3)*d(t1,t3))+(d(t1,t2)*d(t1,t2))-(d(t2,t3)*d(t2,t3)))/(2*d(t1,t3)*d(t1,t2))))*((4*atan(1))/180);
        else if(indeks==2) return (acos(((d(t1,t2)*d(t1,t2))+(d(t3,t2)*d(t3,t2))-(d(t1,t3)*d(t1,t3)))/(2*d(t1,t2)*d(t3,t2))))*((4*atan(1))/180);
        else return (acos(((d(t1,t3)*d(t1,t3))+(d(t3,t2)*d(t3,t2))-(d(t2,t1)*d(t2,t1)))/(2*d(t1,t3)*d(t3,t2))))*((4*atan(1))/180);
    }
    Tacka DajCentar() const{
        return {((t1.first+t2.first+t3.first)/3),((t1.second+t2.second+t3.second)/3)};
    }
    double DajObim() const{
        return d(t1,t2)+d(t2,t3)+d(t1, t3);
    }
    double DajPovrsinu() const{
        if(izraz(t1, t2, t3)<0) return 0.5*izraz(t1, t2, t3)*(-1);
        else return 0.5*izraz(t1, t2, t3);
    }
    bool DaLiJePozitivnoOrijentiran() const{
        return (izraz(t1, t2, t3)>0);
    }
    bool DaLiJeUnutra(const Tacka &t) const;
    void Ispisi() const{
        cout<<"(("<<t1.first<<","<<t1.second<<"),("<<t2.first<<","<<t2.second<<"),("<<t3.first<<","<<t3.second<<"))";
    }
    void Transliraj(double delta_x, double delta_y){
        t1.first+=delta_x;
        t2.first+=delta_x;
        t3.first+=delta_x;
        t1.second+=delta_y;
        t2.second+=delta_y;
        t3.second+=delta_y;
    }
    void Centriraj(const Tacka &t){
        double dodaj_x(t.first-this->DajCentar().first), dodaj_y(t.second-this->DajCentar().second);
        t1.first+=dodaj_x; t1.second+=dodaj_y;
        t2.first+=dodaj_x; t2.second+=dodaj_y;
        t3.first+=dodaj_x; t3.second+=dodaj_y;
    }
    void Rotiraj(const Tacka &t, double ugao){
        t1.first=t.first+(t1.first-t.first)*cos(ugao)-(t1.second-t.second)*sin(ugao);
        t2.first=t.first+(t2.first-t.first)*cos(ugao)-(t2.second-t.second)*sin(ugao);
        t3.first=t.first+(t3.first-t.first)*cos(ugao)-(t3.second-t.second)*sin(ugao);
    }
    void Skaliraj(const Tacka &t, double faktor){
        if(!faktor) throw std::domain_error("Nekorektan faktor skaliranja");
        t1.first=t.first+faktor*(t1.first-t.first);  t1.second=t.second+faktor*(t1.second-t.second);
        t2.first=t.first+faktor*(t2.first-t.first);  t2.second=t.second+faktor*(t2.second-t.second);
        t3.first=t.first+faktor*(t3.first-t.first);  t3.second=t.second+faktor*(t3.second-t.second);
    }
    void Rotiraj(double ugao){
        this->Rotiraj(this->DajCentar(),ugao);
    }
    void Skaliraj(double faktor){
        this->Skaliraj(this->DajCentar(), faktor);
    }
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2){
        std::vector<Tacka>tacke1{t1.t1, t1.t2, t1.t3}, tacke2{t2.t1, t2.t2, t2.t3};
        int br(0);
        for(int i=0; i<3; i++){
            br=0;
            for(int j=0; j<3; j++){
                if(Iste(tacke1[i],tacke2[j])) br++;
            }
            if(!br) return 0;
        }
        return 1;
    }
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2){
        Trougao tr1(Trougao::t1.t1, Trougao::t1.t2, Trougao::t1.t3), tr2(Trougao::t2.t1, Trougao::t2.t2, Trougao::t2.t3);
        std::vector<double>v(3), duzine(3);
        v[0]=d(Trougao::tr1.t2, Trougao::tr1.t3); v[1]=d(Trougao::tr1.t1,Trougao::tr1.t3); v[2]=d(Trougao::tr1.t1, Trougao::tr1.tr2);
        duzine[0]=d(Trougao::tr2.t2, Trougao::tr2.t2); duzine[1]=d(Trougao::tr2.t1,Trougao::tr2.t3); duzine[2]=d(Trougao::tr2.t1, Trougao::tr2.t2);
        for(int i=0; i<2; i++){
            if(Iste(v[i],v[i+1]) && Iste(v[i], duzine[i]) && Iste(duzine[i], duzine[i+1])) br++;
            if(i==1) if(!Iste(v[i+1],duzine[i+1])) br--;
        }
        if(br==2) return 1;
        int maxi;
        double pom;
        for(int i=0; i<2; i++){
            max=v[i];
            for(int j=i+1; j<2; j++){
                if(maxi<v[j]) maxi=j;
            }
            pom=v[i];
            v[i]=v[maxi];
            v[maxi]=pom;
            
        }
    return 0;
    }
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);

};
int main ()
{
    int n;
    cin>>n;
    std::vector<std::shared_ptr<Trougao>>v(n);
    
	return 0;
}