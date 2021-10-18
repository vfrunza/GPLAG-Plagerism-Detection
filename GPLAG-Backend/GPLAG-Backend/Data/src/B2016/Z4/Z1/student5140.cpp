/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <utility>
#include <stdexcept>
#include <cmath>
#include <vector>
#include <memory>
#include <algorithm>

typedef std::pair<double, double> Tacka;
const double epsilon(1e-10);


class Trougao{
    Tacka tjeme1,tjeme2,tjeme3;
public:
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3){ //KONSTRUKTOR
        if(Orijentacija(t1,t2,t3)==0)
            throw std::domain_error("Nekorektne pozicije tjemena");
        else
            tjeme1=t1; tjeme2=t2; tjeme3=t3;
    }
    void Postavi (const Tacka &t1, const Tacka &t2, const Tacka &t3){
        if(Orijentacija(t1,t2,t3)==0)//orijentacija?? fali
            throw std::domain_error("Nekorektne pozicije tjemena");
        else
            tjeme1=t1; tjeme2=t2; tjeme3=t3;
    }
    void Postavi (int indeks, const Tacka &t){
        if(indeks==1)
            tjeme1=t;
        else if(indeks==2)
            tjeme2=t;
        else if(indeks==3)
            tjeme3=t;
        else
            throw std::range_error("Nekorektan indeks");
    }
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        double test;
        test=t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second); //treba li plus
        if(test>0)
            return 1;
        if(test<0)
            return -1;
        if(test-0<epsilon)
            return 0;
    }
    Tacka DajTjeme(int indeks) const{
        if(indeks==1)
            return tjeme1;
        else if(indeks==2)
            return tjeme2;
        else if(indeks==3)
            return tjeme3;
        else
            throw std::range_error("Nekorektan indeks");
    }
    double DajStranicu(int indeks) const{
        if(indeks==1)
            return (std::sqrt(std::pow((tjeme2.first-tjeme3.first),2)+std::pow((tjeme2.second-tjeme3.second),2)));
        else if (indeks==2)
            return (std::sqrt(std::pow((tjeme1.first-tjeme3.first),2)+std::pow((tjeme1.second-tjeme3.second),2)));
        else if (indeks==3)
            return (std::sqrt(std::pow((tjeme2.first-tjeme1.first),2)+std::pow((tjeme2.second-tjeme1.second),2)));
        else
            throw std::range_error("Nekorektan indeks");
    }
    double DajUgao(int indeks) const{
        if(indeks==1)
            return std::acos((std::pow(DajStranicu(2),2)+std::pow(DajStranicu(3),2)-std::pow(DajStranicu(1),2))/(2*DajStranicu(2)*DajStranicu(3)));
        else if(indeks==2)
            return std::acos((std::pow(DajStranicu(1),2)+std::pow(DajStranicu(3),2)-std::pow(DajStranicu(2),2))/(2*DajStranicu(1)*DajStranicu(3)));
        else if(indeks==3)
            return std::acos((std::pow(DajStranicu(2),2)+std::pow(DajStranicu(1),2)-std::pow(DajStranicu(3),2))/(2*DajStranicu(2)*DajStranicu(1)));
        else
            throw std::range_error("Nekorektan indeks");
    }
    Tacka DajCentar() const{
        Tacka centar;
        centar.first=(tjeme1.first+tjeme2.first+tjeme3.first)/3;
        centar.second=(tjeme1.second+tjeme2.second+tjeme3.second)/3;
        return centar;
    }
    double DajObim() const{
        return DajStranicu(1)+DajStranicu(2)+DajStranicu(3);
    }
    double DajPovrsinu() const{
        return 0.5*std::fabs(tjeme1.first*(tjeme2.second-tjeme3.second)-tjeme2.first*(tjeme1.second-tjeme3.second)+tjeme3.first*(tjeme1.second-tjeme2.second));
    }
    bool DaLiJePozitivnoOrijentiran() const{
        if(Orijentacija(tjeme1,tjeme2,tjeme3)>0)
            return true;
        else
            return false;
    }
    bool DaLiJeUnutra(const Tacka &t) const{//vrati se
        double p1(0.5*std::fabs(t.first*(tjeme2.second-tjeme3.second)-tjeme2.first*(t.second-tjeme3.second)+tjeme3.first*(t.second-tjeme2.second)));
        double p2(0.5*std::fabs(tjeme1.first*(t.second-tjeme3.second)-t.first*(tjeme1.second-tjeme3.second)+tjeme3.first*(tjeme1.second-t.second)));
        double p3(0.5*std::fabs(tjeme1.first*(tjeme2.second-t.second)-tjeme2.first*(tjeme1.second-t.second)+t.first*(tjeme1.second-tjeme2.second)));
        if(DajPovrsinu()-(p1+p2+p3)<epsilon)
            return true;
        return false;
    }
    void Ispisi ()const{
        std::cout << "((" << tjeme1.first << "," << tjeme1.second << "),(" << tjeme2.first << "," << tjeme2.second << "),(" << tjeme3.first << "," << tjeme3.second << "))";
    }
    void Transliraj(double delta_x, double delta_y){
        tjeme1.first+=delta_x; tjeme2.first+=delta_x; tjeme3.first+=delta_x;
        tjeme1.second+=delta_y; tjeme2.second+=delta_y; tjeme3.second+=delta_y;
    }
    void Centiraj(const Tacka &t){ //vrati
        Tacka centar(DajCentar());
        double x(t.first-centar.first);
        double y(t.second-centar.second);
        tjeme1.first+=x; tjeme2.first+=x; tjeme3.first+=x;
        tjeme1.second+=y; tjeme2.second+=y; tjeme3.second+=y;
    }
    void Rotiraj(const Tacka &t, double ugao){
        tjeme1=std::make_pair(t.first+(tjeme1.first-t.first)*std::cos(ugao)-(tjeme1.second-t.second)*std::sin(ugao) , t.second+(tjeme1.first-t.first)*std::sin(ugao)+(tjeme1.second-t.second)*std::cos(ugao));
        tjeme2=std::make_pair(t.first+(tjeme2.first-t.first)*std::cos(ugao)-(tjeme2.second-t.second)*std::sin(ugao) , t.second+(tjeme2.first-t.first)*std::sin(ugao)+(tjeme2.second-t.second)*std::cos(ugao));
        tjeme3=std::make_pair(t.first+(tjeme3.first-t.first)*std::cos(ugao)-(tjeme3.second-t.second)*std::sin(ugao) , t.second+(tjeme3.first-t.first)*std::sin(ugao)+(tjeme3.second-t.second)*std::cos(ugao));
    }
    void Skaliraj(const Tacka &t, double faktor){    
        if(faktor-0<epsilon)
            throw std::domain_error("Nekorektan faktor skaliranja");
        tjeme1=std::make_pair(t.first+faktor*(tjeme1.first-t.first) , t.second+faktor*(tjeme1.second-t.second));
        tjeme2=std::make_pair(t.first+faktor*(tjeme2.first-t.first) , t.second+faktor*(tjeme2.second-t.second));
        tjeme3=std::make_pair(t.first+faktor*(tjeme3.first-t.first) , t.second+faktor*(tjeme3.second-t.second));
    }
    void Rotiraj(double ugao){
        Tacka t(DajCentar());
        tjeme1=std::make_pair(t.first+(tjeme1.first-t.first)*std::cos(ugao)-(tjeme1.second-t.second)*std::sin(ugao) , t.second+(tjeme1.first-t.first)*std::sin(ugao)+(tjeme1.second-t.second)*std::cos(ugao));
        tjeme2=std::make_pair(t.first+(tjeme2.first-t.first)*std::cos(ugao)-(tjeme2.second-t.second)*std::sin(ugao) , t.second+(tjeme2.first-t.first)*std::sin(ugao)+(tjeme2.second-t.second)*std::cos(ugao));
        tjeme3=std::make_pair(t.first+(tjeme3.first-t.first)*std::cos(ugao)-(tjeme3.second-t.second)*std::sin(ugao) , t.second+(tjeme3.first-t.first)*std::sin(ugao)+(tjeme3.second-t.second)*std::cos(ugao));
    }
    void Skaliraj(double faktor){
        if(faktor-0<epsilon)
            throw std::domain_error("Nekorektan faktor skaliranja");
        Tacka t(DajCentar());
        tjeme1=std::make_pair(t.first+faktor*(tjeme1.first-t.first) , t.second+faktor*(tjeme1.second-t.second));
        tjeme2=std::make_pair(t.first+faktor*(tjeme2.first-t.first) , t.second+faktor*(tjeme2.second-t.second));
        tjeme3=std::make_pair(t.first+faktor*(tjeme3.first-t.first) , t.second+faktor*(tjeme3.second-t.second));
    }
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);
};

bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2){
    if(t1.tjeme1==t2.tjeme1 && t1.tjeme2==t2.tjeme2 && t1.tjeme3==t2.tjeme3)
        return true;
    if(t1.tjeme1==t2.tjeme1 && t1.tjeme2==t2.tjeme3 && t1.tjeme3==t2.tjeme2)
        return true;
    if(t1.tjeme1==t2.tjeme2 && t1.tjeme2==t2.tjeme3 && t1.tjeme3==t2.tjeme1)
        return true;
    if(t1.tjeme1==t2.tjeme2 && t1.tjeme2==t2.tjeme1 && t1.tjeme3==t2.tjeme3)
        return true;
    if(t1.tjeme1==t2.tjeme3 && t1.tjeme2==t2.tjeme1 && t1.tjeme3==t2.tjeme2)
        return true;
    if(t1.tjeme1==t2.tjeme3 && t1.tjeme2==t2.tjeme2 && t1.tjeme3==t2.tjeme1)
        return true;
    return false;
}

bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2){
        if(t1.DajStranicu(1)-t2.DajStranicu(1)<epsilon && t1.DajStranicu(2)-t2.DajStranicu(2)<epsilon && t1.DajStranicu(3)-t2.DajStranicu(3)<epsilon && DaLiSuSlicni(t1,t2))
            return true;
        if(t1.DajStranicu(1)-t2.DajStranicu(1)<epsilon && t1.DajStranicu(2)-t2.DajStranicu(3)<epsilon && t1.DajStranicu(3)-t2.DajStranicu(2)<epsilon && DaLiSuSlicni(t1,t2))
            return true;
        if(t1.DajStranicu(1)-t2.DajStranicu(2)<epsilon && t1.DajStranicu(2)-t2.DajStranicu(3)<epsilon && t1.DajStranicu(3)-t2.DajStranicu(1)<epsilon && DaLiSuSlicni(t1,t2))
            return true;
        if(t1.DajStranicu(1)-t2.DajStranicu(2)<epsilon && t1.DajStranicu(2)-t2.DajStranicu(1)<epsilon && t1.DajStranicu(3)-t2.DajStranicu(3)<epsilon && DaLiSuSlicni(t1,t2))
            return true;
        if(t1.DajStranicu(1)-t2.DajStranicu(3)<epsilon && t1.DajStranicu(2)-t2.DajStranicu(1)<epsilon && t1.DajStranicu(3)-t2.DajStranicu(2)<epsilon && DaLiSuSlicni(t1,t2))
            return true;
       if(t1.DajStranicu(1)-t2.DajStranicu(3)<epsilon && t1.DajStranicu(2)-t2.DajStranicu(2)<epsilon && t1.DajStranicu(3)-t2.DajStranicu(1)<epsilon && DaLiSuSlicni(t1,t2))
            return true;
    return false;
}


bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2){
        if(t1.DajUgao(1)-t2.DajUgao(1)<epsilon && t1.DajUgao(2)-t2.DajUgao(2)<epsilon && t1.DajUgao(3)-t2.DajUgao(3)<epsilon && Trougao::Orijentacija(t1.tjeme1,t1.tjeme2,t1.tjeme3)==Trougao::Orijentacija(t2.tjeme1,t2.tjeme2,t2.tjeme3))
            return true;
        if(t1.DajUgao(1)-t2.DajUgao(1)<epsilon && t1.DajUgao(2)-t2.DajUgao(3)<epsilon && t1.DajUgao(3)-t2.DajUgao(2)<epsilon && Trougao::Orijentacija(t1.tjeme1,t1.tjeme2,t1.tjeme3)==Trougao::Orijentacija(t2.tjeme1,t2.tjeme3,t2.tjeme2))
            return true;
        if(t1.DajUgao(1)-t2.DajUgao(2)<epsilon && t1.DajUgao(2)-t2.DajUgao(3)<epsilon && t1.DajUgao(3)-t2.DajUgao(1)<epsilon && Trougao::Orijentacija(t1.tjeme1,t1.tjeme2,t1.tjeme3)==Trougao::Orijentacija(t2.tjeme2,t2.tjeme3,t2.tjeme1))
            return true;
        if(t1.DajUgao(1)-t2.DajUgao(2)<epsilon && t1.DajUgao(2)-t2.DajUgao(1)<epsilon && t1.DajUgao(3)-t2.DajUgao(3)<epsilon && Trougao::Orijentacija(t1.tjeme1,t1.tjeme2,t1.tjeme3)==Trougao::Orijentacija(t2.tjeme2,t2.tjeme1,t2.tjeme3))
            return true;
        if(t1.DajUgao(1)-t2.DajUgao(3)<epsilon && t1.DajUgao(2)-t2.DajUgao(1)<epsilon && t1.DajUgao(3)-t2.DajUgao(2)<epsilon && Trougao::Orijentacija(t1.tjeme1,t1.tjeme2,t1.tjeme3)==Trougao::Orijentacija(t2.tjeme3,t2.tjeme1,t2.tjeme2))
            return true;
        if(t1.DajUgao(1)-t2.DajUgao(3)<epsilon && t1.DajUgao(2)-t2.DajUgao(2)<epsilon && t1.DajUgao(3)-t2.DajUgao(1)<epsilon && Trougao::Orijentacija(t1.tjeme1,t1.tjeme2,t1.tjeme3)==Trougao::Orijentacija(t2.tjeme3,t2.tjeme2,t2.tjeme1))
            return true;
    return false;
}

bool Povrsina(std::shared_ptr<Trougao> t1, std::shared_ptr<Trougao> t2){
    return t1->DajPovrsinu()<t2->DajPovrsinu();
}


int main ()
{
    int n;
    std::cout << "Koliko zelite kreirati trouglova: ";
    std::cin >> n;
    std::vector<std::shared_ptr<Trougao>> vektor(n);
    for(int i=0; i<n; i++){
        Tacka x1,x2,x3;
        std::cout << "Unesite podatke za " << i+1 << ". trougao (x1 y1 x2 y2 x3 y3): ";
        std::cin >> x1.first >> x1.second >> x2.first >> x2.second >> x3.first >> x3.second;
        try{  
            Trougao p(x1,x2,x3);
            std::shared_ptr<Trougao> t(std::make_shared<Trougao>(p));
            vektor[i]=t;
        } catch(std::domain_error tekst){
            std::cout << tekst.what() << ", ponovite unos!" << std::endl;
            i--;
        }
    }
    double x,y;
    std::cout << "Unesite vektor translacije (dx dy): ";
    std::cin >> x >> y;
    std::transform(vektor.begin(),vektor.begin()+n,vektor.begin(),[x,y](std::shared_ptr<Trougao> v){v->Transliraj(x,y); return v;});
    
    double ugao;
    std::cout << "Unesite ugao rotacije: ";
    std::cin >> ugao;
    std::transform(vektor.begin(),vektor.begin()+n,vektor.begin(),[ugao](std::shared_ptr<Trougao> v){v->Rotiraj(ugao); return v;});
    
    double faktor;
    std::cout << "Unesite faktor skaliranja: ";
    std::cin >> faktor;
    std::transform(vektor.begin(),vektor.begin()+n,vektor.begin(),[faktor](std::shared_ptr<Trougao> v){v->Skaliraj(v->DajTjeme(1),faktor); return v;});
    
    //sortiraj
    std::sort(vektor.begin(),vektor.begin()+n,Povrsina);
    
    std::cout << "Trouglovi nakon obavljenih transformacija:" << std::endl;
    std::for_each(vektor.begin(),vektor.begin()+n,[](std::shared_ptr<Trougao> v){v->Ispisi(); std::cout << std::endl;});
    
    std::cout << "Trougao sa najmanjim obimom: ";
    auto minel=std::min_element(vektor.begin(),vektor.begin()+n,[](std::shared_ptr<Trougao> t1,std::shared_ptr<Trougao> t2){return t1->DajObim()<t2->DajObim();});
    (*minel)->Ispisi();
    std::cout << std::endl;
    
    bool identicni(false);
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(DaLiSuIdenticni(*vektor[i],*vektor[j])){
                    if(!identicni){
                        identicni=true;
                        std::cout << "Parovi identicnih trouglova: " << std::endl;
                    }
                    vektor[i]->Ispisi();
                    std::cout << " i ";
                    vektor[j]->Ispisi();
                    std::cout << std::endl;
            }
        }
    }
    if(!identicni) 
        std::cout << "Nema identicnih trouglova!" << std::endl;
        
    bool podudarni(false);
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(DaLiSuPodudarni(*vektor[i],*vektor[j])){
                    if(!podudarni){
                        podudarni=true;
                        std::cout << "Parovi podudarnih trouglova: " << std::endl;
                    }
                    vektor[i]->Ispisi();
                    std::cout << " i ";
                    vektor[j]->Ispisi();
                    std::cout << std::endl;
            }
        }
    }
    if(!podudarni) 
        std::cout << "Nema podudarnih trouglova!" << std::endl;
        
    bool slicni(false);
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(DaLiSuSlicni(*vektor[i],*vektor[j])){
                    if(!slicni){
                        slicni=true;
                        std::cout << "Parovi slicnih trouglova: " << std::endl;
                    }
                    vektor[i]->Ispisi();
                    std::cout << " i ";
                    vektor[j]->Ispisi();
                    std::cout << std::endl;
            }
        }
    }
    if(!slicni) 
        std::cout << "Nema slicnih trouglova!" << std::endl;
	return 0;
}