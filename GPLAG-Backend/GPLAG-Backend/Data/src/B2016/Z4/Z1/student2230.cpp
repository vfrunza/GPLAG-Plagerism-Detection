#include <iostream>
#include <stdexcept>
#include <cmath>
#include <vector>
#include <memory>
#include <algorithm>


#define epsilon 0.0000000001
typedef std::pair<double,double> Tacka;

class Trougao{
    Tacka a,b,c;
public:
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3){if(Orijentacija(t1,t2,t3)==0) throw std::domain_error("Nekorektne pozicije tjemena"); a=t1; b=t2;c=t3;}
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3){if(Orijentacija(t1,t2,t3)==0) throw std::domain_error("Nekorektne pozicije tjemena");a=t1; b=t2; c=t3;}
    void Postavi(int indeks, const Tacka &t){if(Orijentacija(a,b,t)==0) throw std::domain_error("Nekorektne pozicije tjemena"); if(Orijentacija(a,c,t)==0) throw std::domain_error("Nekorektne pozicije tjemena"); if(Orijentacija(b,c,t)==0) throw std::domain_error("Nekorektne pozicije tjemena"); if(indeks==1) a=t; else if(indeks==2) b=t; else if(indeks==3) c=t; else throw std::range_error("Nekorektan indeks");}
    static int Orijentacija(const Tacka &t1, const Tacka &t2,const Tacka &t3);
    Tacka DajTjeme(int indeks) const {if(indeks==1) return a; else if(indeks==2) return b; else if(indeks==3) return c; else throw std::range_error("Nekorektan indeks");}
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

int Trougao::Orijentacija(const Tacka &t1, const Tacka &t2,const Tacka &t3){
    int finalno;
    finalno=t1.first*(t2.second-t3.second)+t2.first*(t3.second-t1.second)+t3.first*(t1.second-t2.second);
    if(finalno>0) return 1;
    else if(finalno<0) return -1;
    else return 0;
}

double Trougao::DajStranicu(int indeks)const{
    if(indeks==1) return sqrt(pow(b.first-c.first,2)+ pow(b.second-c.second,2));
    else if(indeks==2) return sqrt(pow(a.first-c.first,2)+pow(a.second-c.second,2));
    else if(indeks==3) return sqrt(pow(a.first-b.first,2) + pow(a.second-b.second,2));
    else throw std::range_error("Nekorektan indeks");
}

double Trougao::DajUgao(int indeks)const{
    double stra=DajStranicu(1);
    double strb=DajStranicu(2);
    double strc=DajStranicu(3);
    if(indeks==1) return acos((strb*strb+strc*strc-stra*stra)/(2*strb*strc));
    else if(indeks==2) return acos((stra*stra+strc*strc-strb*strb)/(2*stra*strc));
    else if(indeks==3) return acos((stra*stra+strb*strb-strc*strc)/(2*stra*strb));
    else throw std::range_error("Nekorektan indeks");
}

Tacka Trougao::DajCentar() const{
    Tacka teziste;
    teziste.first=(a.first+b.first+c.first)/3.;
    teziste.second=(a.second+b.second+c.second)/3.;
    return teziste;
}

double Trougao::DajObim() const{
    double obim;
    double stra=DajStranicu(1);
    double strb=DajStranicu(2);
    double strc=DajStranicu(3);
    obim=stra+strb+strc;
    return obim;
}

double Trougao::DajPovrsinu() const{
    double povrsina;
    povrsina=(1/2.)*abs(a.first*(b.second-c.second)+b.first*(c.second-a.second)+c.first*(a.second-b.second));
    return povrsina;
}

bool Trougao::DaLiJePozitivnoOrijentiran() const{
    static int k=Orijentacija(a,b,c);
    if(k>0) return true;
    else return false;
}

bool Trougao::DaLiJeUnutra(const Tacka &t) const{
    Trougao tro(a,b,c);
    Trougao tro1(a,b,t);
    Trougao tro2(b,c,t);
    Trougao tro3(a,c,t);
    double povrsina=tro.DajPovrsinu();
    double povrsina1=tro1.DajPovrsinu();
    double povrsina2=tro2.DajPovrsinu();
    double povrsina3=tro3.DajPovrsinu();
    if(std::fabs(povrsina-(povrsina1+povrsina2+povrsina3))<=epsilon) return true;
    else return false;
}

void Trougao::Ispisi() const{
    std::cout<<"(("<<a.first<<","<<a.second<<"),("<<b.first<<","<<b.second<<"),("<<c.first<<","<<c.second<<"))";
}

void Trougao::Transliraj(double delta_x,double delta_y){
    a.first+=delta_x;
    b.first+=delta_x;
    c.first+=delta_x;
    a.second+=delta_y;
    b.second+=delta_y;
    c.second+=delta_y;
}

void Trougao::Centriraj(const Tacka &t){
    Tacka teziste=DajCentar();
    double udaljenostpox=std::fabs(t.first)-std::fabs(teziste.first);
    double udaljenostpoy=std::fabs(t.second)-std::fabs(teziste.second);
    if(std::fabs(t.first-teziste.first)<=epsilon) udaljenostpox=0;
    if(std::fabs(t.second-teziste.second)<=epsilon) udaljenostpoy=0;
    a.first+=udaljenostpox; a.second+=udaljenostpoy;
    b.first+=udaljenostpox; b.second+=udaljenostpoy;
    c.first+=udaljenostpox; c.second+=udaljenostpoy;
}

void Trougao::Rotiraj(const Tacka &t, double ugao){
    Tacka i,j,k;
    i.first=t.first+(a.first-t.first)*cos(ugao)-(a.second-t.second)*sin(ugao);
    i.second=t.second+(a.first-t.first)*sin(ugao)+(a.second-t.second)*cos(ugao);
    j.first=t.first+(b.first-t.first)*cos(ugao)-(b.second-t.second)*sin(ugao);
    j.second=t.second+(b.first-t.first)*sin(ugao)+(b.second-t.second)*cos(ugao);
    k.first=t.first+(c.first-t.first)*cos(ugao)-(c.second-t.second)*sin(ugao);
    k.second=t.second+(c.first-t.first)*sin(ugao)+(c.second-t.second)*cos(ugao);
    a=i;
    b=j;
    c=k;
}

void Trougao::Skaliraj(const Tacka &t, double faktor){
    if(std::fabs(faktor-0)<=epsilon) throw std::domain_error("Nekorektan faktor skaliranja");
    Tacka i,j,k;
    i.first=t.first+faktor*(a.first-t.first);
    i.second=t.second+faktor*(a.second-t.second);
    j.first=t.first+faktor*(b.first-t.first);
    j.second=t.second+faktor*(b.second-t.second);
    k.first=t.first+faktor*(c.first-t.first);
    k.second=t.second+faktor*(c.second-t.second);
    
    a=i;
    b=j;
    c=k;
}

void Trougao::Rotiraj(double ugao){
    Tacka i,j,k;
    Tacka t=DajCentar();
    i.first=t.first+(a.first-t.first)*cos(ugao)-(a.second-t.second)*sin(ugao);
    i.second=t.second+(a.first-t.first)*sin(ugao)+(a.second-t.second)*cos(ugao);
    j.first=t.first+(b.first-t.first)*cos(ugao)-(b.second-t.second)*sin(ugao);
    j.second=t.second+(b.first-t.first)*sin(ugao)+(b.second-t.second)*cos(ugao);
    k.first=t.first+(c.first-t.first)*cos(ugao)-(c.second-t.second)*sin(ugao);
    k.second=t.second+(c.first-t.first)*sin(ugao)+(c.second-t.second)*cos(ugao);
    a=i;
    b=j;
    c=k;
}

void Trougao::Skaliraj(double faktor){
    if(std::fabs(faktor-0)<=epsilon) throw std::domain_error("Nekorektan faktor skaliranja");
    Tacka i,j,k;
    Tacka t=DajCentar();
    i.first=t.first+faktor*(a.first-t.first);
    i.second=t.second+faktor*(a.second-t.second);
    j.first=t.first+faktor*(b.first-t.first);
    j.second=t.second+faktor*(b.second-t.second);
    k.first=t.first+faktor*(c.first-t.first);
    k.second=t.second+faktor*(c.second-t.second);
    a=i;
    b=j;
    c=k;
}

bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2){
    Tacka a=t1.DajTjeme(1);
    Tacka b=t1.DajTjeme(2);
    Tacka c=t1.DajTjeme(3);
    Tacka d=t2.DajTjeme(1);
    Tacka e=t2.DajTjeme(2);
    Tacka f=t2.DajTjeme(3); 
    if((a==d && ((b==e && c==f) || (b==f && c==e))) || (a==e && ((b==f && c==d) || (b==d && c==f))) || (a==f && ((b==d && c==e) || (b==e && c==d) )) ) return true;
    else return false;
}

bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2){
    double str1a=t1.DajStranicu(1);
    double str1b=t1.DajStranicu(2);
    double str1c=t1.DajStranicu(3);
    double str2a=t2.DajStranicu(1);
    double str2b=t2.DajStranicu(2);
    double str2c=t2.DajStranicu(3);
    double alfa1=t1.DajUgao(1);
    double alfa2=t2.DajUgao(2);
    double beta1=t1.DajUgao(1);
    double beta2=t2.DajUgao(2);
    double gama1=t1.DajUgao(3);
    double gama2=t2.DajUgao(3);
    
    if(std::fabs(str1a-str2a)<=epsilon && std::fabs(str1b-str2b)<=epsilon && std::fabs(str1c-str2c)<=epsilon && t1.Orijentacija(t1.DajTjeme(1),t1.DajTjeme(2),t1.DajTjeme(3))==t2.Orijentacija(t2.DajTjeme(1),t2.DajTjeme(2),t2.DajTjeme(3))) return true;
    else if(std::fabs(str1a-str2a)<=epsilon && std::fabs(str1b-str2c)<=epsilon && std::fabs(str1c-str2b)<=epsilon && t1.Orijentacija(t1.DajTjeme(1),t1.DajTjeme(2),t1.DajTjeme(3))==t2.Orijentacija(t2.DajTjeme(1),t2.DajTjeme(3),t2.DajTjeme(2))) return true;
    else if(std::fabs(str1a-str2b)<=epsilon && std::fabs(str1b-str2a)<=epsilon && std::fabs(str1c-str2c)<=epsilon && t1.Orijentacija(t1.DajTjeme(1),t1.DajTjeme(2),t1.DajTjeme(3))==t2.Orijentacija(t2.DajTjeme(2),t2.DajTjeme(1),t2.DajTjeme(3))) return true;
    else if(std::fabs(str1a-str2b)<=epsilon && std::fabs(str1b-str2c)<=epsilon && std::fabs(str1c-str2a)<=epsilon && t1.Orijentacija(t1.DajTjeme(1),t1.DajTjeme(2),t1.DajTjeme(3))==t2.Orijentacija(t2.DajTjeme(2),t2.DajTjeme(3),t2.DajTjeme(1))) return true;
    else if(std::fabs(str1a-str2c)<=epsilon && std::fabs(str1b-str2b)<=epsilon && std::fabs(str1c-str2a)<=epsilon && t1.Orijentacija(t1.DajTjeme(1),t1.DajTjeme(2),t1.DajTjeme(3))==t2.Orijentacija(t2.DajTjeme(3),t2.DajTjeme(2),t2.DajTjeme(1))) return true;
    else if(std::fabs(str1a-str2c)<=epsilon && std::fabs(str1b-str2a)<=epsilon && std::fabs(str1c-str2b)<=epsilon && t1.Orijentacija(t1.DajTjeme(1),t1.DajTjeme(2),t1.DajTjeme(3))==t2.Orijentacija(t2.DajTjeme(3),t2.DajTjeme(1),t2.DajTjeme(2))) return true;
    else if(std::fabs(str1b-str2b)<=epsilon && std::fabs(str1c-str2c)<=epsilon && std::fabs(beta1-beta2)<=epsilon) return false;
    else if(std::fabs(str1a-str2a)<=epsilon && std::fabs(str1c-str2c)<=epsilon && std::fabs(alfa1-alfa2)<=epsilon) return false;
    else if(std::fabs(str1a-str2a)<=epsilon && std::fabs(str1b-str2b)<=epsilon && std::fabs(alfa1-alfa2)<=epsilon) return false;
    else if(std::fabs(str1b-str2b)<=epsilon && std::fabs(str1c-str2c)<=epsilon && std::fabs(alfa1-alfa2)<=epsilon) return false;
    else if(std::fabs(str1a-str2a)<=epsilon && std::fabs(str1c-str2c)<=epsilon && std::fabs(beta1-beta2)<=epsilon) return false;
    else if(std::fabs(str1a-str2a)<=epsilon && std::fabs(str1b-str2b)<=epsilon && std::fabs(gama1-gama2)<=epsilon) return false;
    else if(std::fabs(alfa1-alfa2)<=epsilon && std::fabs(beta1-beta2)<=epsilon && std::fabs(str1c-str2c)<=epsilon) return false;
    else if(std::fabs(beta1-beta2)<=epsilon && std::fabs(gama1-gama2)<=epsilon && std::fabs(str1a-str2a)<=epsilon) return false;
    else if(std::fabs(alfa1-alfa2)<=epsilon && std::fabs(gama1-gama2)<=epsilon && std::fabs(str1b-str2b)<=epsilon) return false;
    else return false;
}

bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2){
    double a1=t1.DajStranicu(1);
    double b1=t1.DajStranicu(2);
    double c1=t1.DajStranicu(3);
    double a2=t2.DajStranicu(1);
    double b2=t2.DajStranicu(2);
    double c2=t2.DajStranicu(3);
    double alfa1=t1.DajUgao(1);
    double alfa2=t2.DajUgao(1);
    double beta1=t1.DajUgao(2);
    double beta2=t2.DajUgao(2);
    double gama1=t1.DajUgao(3);
    double gama2=t2.DajUgao(3);
    
    if(std::fabs((a1/a2)-(b1/b2))<=epsilon && std::fabs((a1/a2)-(c1/c2))<=epsilon && t1.Orijentacija(t1.DajTjeme(1),t1.DajTjeme(2),t1.DajTjeme(3))==t2.Orijentacija(t2.DajTjeme(1),t2.DajTjeme(2),t2.DajTjeme(3))) return true;
    else if(std::fabs((a1/a2)-(b1/c2))<=epsilon && std::fabs((a1/a2)-(c1/b2))<=epsilon && t1.Orijentacija(t1.DajTjeme(1),t1.DajTjeme(2),t1.DajTjeme(3))==t2.Orijentacija(t2.DajTjeme(1),t2.DajTjeme(3),t2.DajTjeme(2))) return true;
    else if(std::fabs((a1/b2)-(b1/a2))<=epsilon && std::fabs((a1/b2)-(c1/c2))<=epsilon && t1.Orijentacija(t1.DajTjeme(1),t1.DajTjeme(2),t1.DajTjeme(3))==t2.Orijentacija(t2.DajTjeme(2),t2.DajTjeme(1),t2.DajTjeme(3))) return true;
    else if(std::fabs((a1/b2)-(b1/c2))<=epsilon && std::fabs((a1/b2)-(c1/a2))<=epsilon && t1.Orijentacija(t1.DajTjeme(1),t1.DajTjeme(2),t1.DajTjeme(3))==t2.Orijentacija(t2.DajTjeme(2),t2.DajTjeme(3),t2.DajTjeme(1))) return true;
    else if(std::fabs((a1/c2)-(b1/b2))<=epsilon && std::fabs((a1/c2)-(c1/a2))<=epsilon && t1.Orijentacija(t1.DajTjeme(1),t1.DajTjeme(2),t1.DajTjeme(3))==t2.Orijentacija(t2.DajTjeme(3),t2.DajTjeme(2),t2.DajTjeme(1))) return true;
    else if(std::fabs((a1/c2)-(b1/a2))<=epsilon && std::fabs((a1/c2)-(c1/b2))<=epsilon && t1.Orijentacija(t1.DajTjeme(1),t1.DajTjeme(2),t1.DajTjeme(3))==t2.Orijentacija(t2.DajTjeme(3),t2.DajTjeme(1),t2.DajTjeme(2))) return true;
    
    else if((std::fabs(alfa1-alfa2)<=epsilon && std::fabs(beta1-beta2)<=epsilon) || (std::fabs(alfa1-alfa2)<=epsilon && std::fabs(gama1-gama2)<=epsilon) || (std::fabs(beta1-beta2)<=epsilon && std::fabs(gama1-gama2)<=epsilon)) return false;
    else if((std::fabs(a1/a2-b1/b2)<=epsilon && std::fabs(gama1-gama2)<=epsilon)) return false;
    else if((std::fabs(a1/a2-c1/c2)<=epsilon) && std::fabs(beta1-beta2)<=epsilon) return false;
    else if((std::fabs(b1/b2-c1/c2)<=epsilon) && std::fabs(alfa1-alfa2)<=epsilon) return false;
    else if((std::fabs(a1/a2-b1/b2)<=epsilon) && (std::fabs(a1/a2-c1/c2)<=epsilon) && (std::fabs(b1/b2-c1/c2)<=epsilon)) return false;
    else return false;
}

int main ()
{
    
    int n;
   // double deltax,deltay;
    std::cout<<"Koliko zelite kreirati trouglova: ";
    jodja:
    std::cin>>n;
    if(n==0) {std::cout<<"Ponovite unos: "; std::cin.clear();std::cin.ignore(1000,'\n'); goto jodja;}
    std::vector<std::shared_ptr<Trougao>> vektor;
    vektor.resize(n);
    for(int i(0);i<vektor.size();i++){
        double t1x,t1y,t2x,t2y,t3x,t3y;
        std::cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
        std::cin>>t1x;
        std::cin>>t1y;
        std::cin>>t2x;
        std::cin>>t2y;
        std::cin>>t3x;
        std::cin>>t3y;
        Tacka a,b,c;
        a.first=t1x; a.second=t1y;
        b.first=t2x; b.second=t2y;
        c.first=t3x; c.second=t3y;
        try{
        Trougao tro(a,b,c);
        vektor[i]=std::make_shared<Trougao>(tro);
        }
        catch(std::domain_error e){
            std::cout<<e.what();
            std::cout<<", ponovite unos!"<<std::endl;
            i--;
        }
        catch(std::bad_alloc e){
            std::cout<<"Problem sa memorijom"<<std::endl;
        }
    }
    
    auto it=vektor.begin();
    double deltax,deltay;
    std::cout<<"Unesite vektor translacije (dx dy): ";
    std::cin>>deltax>>deltay;
    double ugao;
    std::cout<<"Unesite ugao rotacije: ";
    std::cin>>ugao;
    double faktor_skaliranja;
    std::cout<<"Unesite faktor skaliranja: ";
    std::cin>>faktor_skaliranja;
    std::cout<<"Trouglovi nakon obavljenih transformacija:"<<std::endl;
   
    std::transform(vektor.begin(),vektor.end(),it,[deltax,deltay](std::shared_ptr<Trougao> tro){
        tro->Transliraj(deltax,deltay);
        return tro;
    });
    std::transform(vektor.begin(),vektor.end(),it,[ugao](std::shared_ptr<Trougao>tro){
        tro->Rotiraj(tro->DajCentar(),ugao);
        return tro;
    });
    
    std::transform(vektor.begin(),vektor.end(),it,[faktor_skaliranja](std::shared_ptr<Trougao> tro){
        tro->Skaliraj(tro->DajTjeme(1),faktor_skaliranja);
        return tro;
    });
    std::sort(vektor.begin(),vektor.end(),[](std::shared_ptr<Trougao>tro1 , std::shared_ptr<Trougao> tro2){
        if(tro1->DajPovrsinu()<tro2->DajPovrsinu()) return true;
        else return false;
    });
    std::for_each(vektor.begin(),vektor.end(),[](std::shared_ptr<Trougao> tro){
        tro->Ispisi();
        std::cout<<std::endl;
    });
    auto pok=std::min_element(vektor.begin(),vektor.end(),[](std::shared_ptr<Trougao>tro1, std::shared_ptr<Trougao>tro2){
        if(tro1->DajObim()<tro2->DajObim()) return true;
        else return false;
    });
    std::cout<<"Trougao sa najmanjim obimom: ";
    (*pok)->Ispisi();
    std::cout<<std::endl;
    std::vector<std::pair<std::shared_ptr<Trougao>,std::shared_ptr<Trougao>>> par;
    for(int i(0);i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(DaLiSuIdenticni(*vektor[i],*vektor[j])){
                par.push_back(std::make_pair(vektor[i],vektor[j]));
            }
        }
    }
    if(par.size()!=0){
        std::cout<<"Parovi identicnih trouglova:"<<std::endl;
        for(int i(0);i<par.size();i++){
            par[i].first->Ispisi();
            std::cout<<" i ";
            par[i].second->Ispisi();
            std::cout<<std::endl;
        }
    }
    else{
        std::cout<<"Nema identicnih trouglova!";
        std::cout<<std::endl;
    }
    std::vector<std::pair<std::shared_ptr<Trougao>, std::shared_ptr<Trougao>>> podudarni;
    for(int i(0);i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(DaLiSuPodudarni(*vektor[i],*vektor[j])){
                podudarni.push_back(make_pair(vektor[i],vektor[j]));
            }
        }
    }
    if(podudarni.size()!=0){
        std::cout<<"Parovi podudarnih trouglova:"<<std::endl;
        for(int i(0);i<podudarni.size();i++){
            podudarni[i].first->Ispisi();
            std::cout<<" i ";
            podudarni[i].second->Ispisi();
            std::cout<<std::endl;
        }
    }
    else {
        std::cout<<"Nema podudarnih trouglova!"<<std::endl;
    }
    std::vector<std::pair<std::shared_ptr<Trougao>, std::shared_ptr<Trougao>>> slicni;
    for(int i(0);i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(DaLiSuSlicni(*vektor[i],*vektor[j])){
                slicni.push_back(make_pair(vektor[i],vektor[j]));
            }
        }
    }
    if(slicni.size()!=0){
        std::cout<<"Parovi slicnih trouglova:"<<std::endl;
        for(int i(0);i<slicni.size();i++){
            slicni[i].first->Ispisi();
            std::cout<<" i ";
            slicni[i].second->Ispisi();
            std::cout<<std::endl;
        }
    }
    else{
        std::cout<<"Nema slicnih trouglova!"<<std::endl;
    }
    
 	return 0;
}