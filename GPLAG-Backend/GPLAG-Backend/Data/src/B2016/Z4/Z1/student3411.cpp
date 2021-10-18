/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <utility>
#include <stdexcept>
#include <cmath>
#include <algorithm>
#include <memory>
#include <vector>
#include <set>
typedef std::pair<double, double> Tacka;
const double eps = 1E-10;

class Trougao{
    Tacka x;
    Tacka y;
    Tacka z;
    public:
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        if(abs(t1.first*(t2.second-t3.second)+t2.first*(t3.second-t1.second)+t3.first*(t1.second-t2.second))<=eps) throw std::domain_error("Nekorektne pozicije tjemena");
        x=t1; y=t2; z=t3;
    }
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        if(abs(t1.first*(t2.second-t3.second)+t2.first*(t3.second-t1.second)+t3.first*(t1.second-t2.second))<=eps) throw std::domain_error("Nekorektne pozicije tjemena");
        x=t1; y=t2; z=t3;
    }
    void Postavi(int indeks, const Tacka &t){
        if(indeks<1 || indeks>3) throw std::range_error("Nekorektan indeks");
        if(indeks==1) this->Postavi(t,y,z);
        if(indeks==2) this->Postavi(x,t,z);
        if(indeks==3) this->Postavi(x,y,t);
    }
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        if((t1.first*(t2.second-t3.second)+t2.first*(t3.second-t1.second)+t3.first*(t1.second-t2.second))>0) return 1;
        else if((t1.first*(t2.second-t3.second)+t2.first*(t3.second-t1.second)+t3.first*(t1.second-t2.second))<0) return -1;
        else return 0;
    }
    Tacka DajTjeme(int indeks) const{
        if(indeks<1 || indeks>3) throw std::range_error("Nekorektan indeks");
        if(indeks==1) return x;
        if(indeks==2) return y;
        if(indeks==3) return z;
        
    }
    double DajStranicu(int indeks) const{
        if(indeks<1 || indeks>3) throw std::range_error("Nekorektan indeks");
        if(indeks==3) return sqrt((y.first-x.first)*(y.first-x.first)+(y.second-x.second)*(y.second-x.second));
        if(indeks==2) return sqrt((z.first-x.first)*(z.first-x.first)+(z.second-x.second)*(z.second-x.second));
        if(indeks==1) return sqrt((z.first-y.first)*(z.first-y.first)+(z.second-y.second)*(z.second-y.second));
    }
    double DajUgao(int indeks) const{
        if(indeks<1 || indeks>3) throw std::range_error("Nekorektan indeks");
        if(indeks==1) return (this->DajStranicu(2)*this->DajStranicu(2)+this->DajStranicu(3)*this->DajStranicu(3)-this->DajStranicu(1)*this->DajStranicu(1))/(2.*this->DajStranicu(2)*this->DajStranicu(3));
        if(indeks==2) return (this->DajStranicu(1)*this->DajStranicu(1)+this->DajStranicu(3)*this->DajStranicu(3)-this->DajStranicu(2)*this->DajStranicu(2))/(2.*this->DajStranicu(1)*this->DajStranicu(3));
        if(indeks==3) return (this->DajStranicu(1)*this->DajStranicu(1)+this->DajStranicu(2)*this->DajStranicu(2)-this->DajStranicu(3)*this->DajStranicu(3))/(2.*this->DajStranicu(1)*this->DajStranicu(2));
    }
    Tacka DajCentar() const{
        Tacka t((x.first+y.first+z.first)/3,(x.second+y.second+z.second)/3);
        return t;
    }
    double DajObim() const{
        return (this->DajStranicu(1)+this->DajStranicu(2)+this->DajStranicu(3));
    }
    double DajPovrsinu() const{
        double p(x.first*(y.second-z.second)+y.first*(z.second-x.second)+z.first*(x.second-y.second));
        if(p>=0) return p;
        else return -p;
    }
    bool DaLiJePozitivnoOrijentiran() const{
        int a(Orijentacija(x,y,z));
        if(a==1) return true;
        if (a==-1) return false;
    }
    bool DaLiJeUnutra(const Tacka &t) const{ //treba napisat
            Trougao a(t,y,z);
            Trougao b(x,t,z);
            Trougao c(x,y,t);
            if(abs(this->DajPovrsinu()-(a.DajPovrsinu()+b.DajPovrsinu()+c.DajPovrsinu()))<=eps) return true;
            return false;
        } 
    void Ispisi() const{
        std::cout<<"(("<<x.first<<","<<x.second<<"),("<<y.first<<","<<y.second<<"),("<<z.first<<","<<z.second<<"))";
    }
    void Transliraj(double delta_x, double delta_y){
        x.first+=delta_x; x.second+=delta_y;
        y.first+=delta_x; y.second+=delta_y;
        z.first+=delta_x; z.second+=delta_y;
    }
    void Centriraj(const Tacka &t){
        Tacka t2(this->DajCentar());
        this->Transliraj(t.first-t2.first,t.second-t2.second);
    }
    void Rotiraj(const Tacka &t, double ugao){
        x=std::make_pair(t.first+(x.first-t.first)*cos(ugao)-(x.second-t.second)*sin(ugao),t.second+(x.first-t.first)*sin(ugao)+(x.second-t.second)*cos(ugao));
        y=std::make_pair(t.first+(y.first-t.first)*cos(ugao)-(y.second-t.second)*sin(ugao),t.second+(y.first-t.first)*sin(ugao)+(y.second-t.second)*cos(ugao));
        z=std::make_pair(t.first+(z.first-t.first)*cos(ugao)-(z.second-t.second)*sin(ugao),t.second+(z.first-t.first)*sin(ugao)+(z.second-t.second)*cos(ugao));
    }
    void Skaliraj(const Tacka &t, double faktor){
        if(abs(faktor)<=eps) throw std::domain_error("Nekorektan faktor skaliranja");
        x=std::make_pair(t.first+faktor*(x.first-t.first),t.second+faktor*(x.second-t.second));
        y=std::make_pair(t.first+faktor*(y.first-t.first),t.second+faktor*(y.second-t.second));
        z=std::make_pair(t.first+faktor*(z.first-t.first),t.second+faktor*(z.second-t.second));
    }
    void Rotiraj(double ugao){
        Tacka t(this->DajCentar());
        this->Rotiraj(t,ugao);
    }
    void Skaliraj(double faktor){
        Tacka t(this->DajCentar());
        this->Skaliraj(t,faktor);
    }
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);
};
bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2){
    Tacka c1(t1.DajCentar()), c2(t2.DajCentar());
    if(abs(c1.second-c2.second)>=eps) return false;
    Tacka niz1[3]={t1.DajTjeme(1),t1.DajTjeme(2),t1.DajTjeme(3)};
    Tacka niz2[3]={t2.DajTjeme(1),t2.DajTjeme(2),t2.DajTjeme(3)};
    std::sort(niz1,niz1+3);
    std::sort(niz2,niz2+3);
    int br(0);
    for(int i=0; i<3; i++)
        if(abs(niz1[i].first-niz2[i].first)<=eps && abs(niz1[i].second-niz2[i].second)<=eps) br++;
    if(br==3) return true;
    return false;
    
}
bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2){
    double niz1[3]={t1.DajStranicu(1),t1.DajStranicu(2),t1.DajStranicu(3)};
    double niz2[3]={t2.DajStranicu(1),t2.DajStranicu(2),t2.DajStranicu(3)};
    Tacka niz3[3]={t1.DajTjeme(1),t1.DajTjeme(2),t1.DajTjeme(3)};
    Tacka niz4[3]={t2.DajTjeme(1),t2.DajTjeme(2),t2.DajTjeme(3)};
    for(int i=0; i<3; i++){
        int min(i); int min1(i);
        for(int j=i+1; j<3; j++){
            if(niz1[j]<niz1[min]){
                min=j;
            }
            if(niz2[j]<niz2[min1]){
                min1=j;
            }
        }
        auto temp1(niz1[i]); auto temp2(niz3[i]);
        niz1[i]=niz1[min]; niz3[i]=niz3[min];
        niz1[min]=temp1; niz3[min]=temp2;
        auto temp3(niz2[i]); auto temp4(niz4[i]);
        niz2[i]=niz2[min1]; niz4[i]=niz4[min1];
        niz2[min1]=temp3; niz4[min1]=temp4;
    }
    Trougao t3(niz3[0],niz3[1],niz3[2]), t4(niz4[0],niz4[1],niz4[2]);
    double niz5[3]={t3.DajStranicu(1),t3.DajStranicu(2),t3.DajStranicu(3)};
    double niz6[3]={t4.DajStranicu(1),t4.DajStranicu(2),t4.DajStranicu(3)};
    std::sort(niz5,niz5+3);
    std::sort(niz6,niz6+3);
    int br(0);
    for(int i=0; i<3; i++)
        if(abs(niz5[i]-niz6[i])<=eps) br++;
    if(br==3 && Trougao::Orijentacija(t3.x,t3.y,t3.z)==Trougao::Orijentacija(t4.x,t4.y,t4.z)) return true;
    return false; 
}
bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2){
    double niz1[3]={t1.DajStranicu(1),t1.DajStranicu(2),t1.DajStranicu(3)};
    double niz2[3]={t2.DajStranicu(1),t2.DajStranicu(2),t2.DajStranicu(3)};
    double niz5[3]={t1.DajStranicu(1),t1.DajStranicu(2),t1.DajStranicu(3)};
    double niz6[3]={t2.DajStranicu(1),t2.DajStranicu(2),t2.DajStranicu(3)};
    std::sort(niz5,niz5+3);
    std::sort(niz6,niz6+3);
    Tacka niz3[3]={t1.DajTjeme(1),t1.DajTjeme(2),t1.DajTjeme(3)};
    Tacka niz4[3]={t2.DajTjeme(1),t2.DajTjeme(2),t2.DajTjeme(3)};
    int br(0);
    double k(niz5[0]/niz6[0]);
    for(int i=1; i<3; i++){
        double tmp(niz5[i]-k*niz6[i]);
        if(tmp<=eps && tmp>=-eps) br++;
    }
    if(br!=2) return false; //return true;
    else{
        for(int i=0; i<3; i++){
            int min(i), min1(i);
            for(int j=i+1; j<3; j++){
                if(niz1[j]<niz1[min]) min=j;
                if(niz2[j]<niz2[min1]) min1=j;
            }
            auto temp1(niz1[i]); auto temp2(niz3[i]);
            niz1[i]=niz1[min]; niz3[i]=niz3[min];
            niz1[min]=temp1; niz3[min]=temp2;
            auto temp3(niz2[i]); auto temp4(niz4[i]);
            niz2[i]=niz2[min1]; niz4[i]=niz4[min1];
            niz2[min1]=temp3; niz4[min1]=temp4;
        }
        Trougao t3(niz3[0],niz3[1],niz3[2]), t4(niz4[0],niz4[1],niz4[2]);
        if(Trougao::Orijentacija(t3.x,t3.y,t3.z)==Trougao::Orijentacija(t4.x,t4.y,t4.z)) return true;
    }
    return false;
}
int main ()
{   int n;
    std::cout<<"Koliko zelite kreirati trouglova: ";
    std::cin>>n;
    std::vector<std::shared_ptr<Trougao>> v(n);
    for(int i=0; i<n; i++){
        double a,b,c,d,e,f;
        std::cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
        std::cin>>a>>b>>c>>d>>e>>f;
        Tacka t1(a,b),t2(c,d),t3(e,f);
        try{
            v[i]=std::make_shared<Trougao>(t1,t2,t3);
        }
        catch(std::domain_error e){
            std::cout<<e.what()<<", ponovite unos!"<<std::endl;
            i--;
        }
        catch(std::bad_alloc){
            std::cout<<"Nedovoljno memorije!"<<std::endl;
            for(int i=0; i<n; i++) v[i]=nullptr;
        }
    }
    std::cout<<"Unesite vektor translacije (dx dy): ";
    double dx,dy;
    std::cin>>dx>>dy;
    std::cout<<"Unesite ugao rotacije: ";
    double ugao;
    std::cin>>ugao;
    std::cout<<"Unesite faktor skaliranja: ";
    double faktor;
    std::cin>>faktor;
    std::transform(v.begin(), v.end(), v.begin(), [dx,dy](std::shared_ptr<Trougao> t){
        t->Transliraj(dx,dy);
        return t;
    });
    std::transform(v.begin(), v.end(), v.begin(),[ugao](std::shared_ptr<Trougao> t){
        t->Rotiraj(ugao);
        return t;
    });
    try{
        std::transform(v.begin(), v.end(), v.begin(), [faktor](std::shared_ptr<Trougao> t){
            t->Skaliraj(t->DajTjeme(1),faktor);
            return t;
        });
    }
    catch(std::domain_error e){
        std::cout<<e.what();
    }
    std::sort(v.begin(), v.end(), [] (std::shared_ptr<Trougao> t1, std::shared_ptr<Trougao> t2){
        return (t1->DajPovrsinu()<t2->DajPovrsinu());
    });
    std::cout<<"Trouglovi nakon obavljenih transformacija:"<<std::endl;
    std::for_each(v.begin(), v.end(), [](std::shared_ptr<Trougao> t){t->Ispisi(); std::cout<<std::endl;});
    auto p(std::min_element(v.begin(), v.end(), [](std::shared_ptr<Trougao> t1, std::shared_ptr<Trougao> t2){
        return(t2->DajObim()>=t1->DajObim());
    }));
    std::cout<<"Trougao sa najmanjim obimom: "; (*p)->Ispisi(); std::cout<<std::endl;
    std::vector<std::pair<std::shared_ptr<Trougao>,std::shared_ptr<Trougao>>> v3;
    bool nalazi(false);
    for(int i=0; i<n; i++){
        for(int j=i+1;j<n; j++){
            if(DaLiSuIdenticni(*(v[i]),*(v[j]))) {v3.push_back(std::make_pair(v[i],v[j])); nalazi=true; }//v[i]->Ispisi();std::cout<<" i ";v[j]->Ispisi(); std::cout<<std::endl;}
        }
    }
    if(nalazi){
        std::cout<<"Parovi identicnih trouglova:"<<std::endl;
        for(int i=0; i<v3.size(); i++) {v3[i].first->Ispisi();std::cout<<" i ";v3[i].second->Ispisi(); std::cout<<std::endl;}
    }
    else std::cout<<"Nema identicnih trouglova!"<<std::endl;
    std::vector<std::pair<std::shared_ptr<Trougao>,std::shared_ptr<Trougao>>> v1;
    nalazi=(false);
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(DaLiSuPodudarni(*(v[i]),*(v[j]))) {v1.push_back(std::make_pair(v[i],v[j])); nalazi=true; }//v[i]->Ispisi();std::cout<<" i ";v[j]->Ispisi(); std::cout<<std::endl;}
        }
    }
    if(nalazi){
        std::cout<<"Parovi podudarnih trouglova:"<<std::endl;
        for(int i=0; i<v1.size(); i++) {v1[i].first->Ispisi();std::cout<<" i ";v1[i].second->Ispisi(); std::cout<<std::endl;}
    }
    else std::cout<<"Nema podudarnih trouglova!"<<std::endl;
    nalazi=false;
    std::vector<std::pair<std::shared_ptr<Trougao>,std::shared_ptr<Trougao>>> v2;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(DaLiSuSlicni(*v[i],*v[j])) {v2.push_back(std::make_pair(v[i],v[j])); nalazi=true;}//v[i]->Ispisi(); std::cout<<" i "; v[j]->Ispisi(); std::cout<<std::endl;}
        }
    }
    if(nalazi){
        std::cout<<"Parovi slicnih trouglova:"<<std::endl;
        for(int i=0; i<v2.size(); i++) {v2[i].first->Ispisi();std::cout<<" i ";v2[i].second->Ispisi(); std::cout<<std::endl;}
    }
    else std::cout<<"Nema slicnih trouglova!"<<std::endl;
	return 0; 
}