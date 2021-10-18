/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <utility>
#include <memory>
#include <new>
#include <algorithm>
#include <stdexcept>
#include <vector>
#include <cmath>

typedef std::pair<double,double> Tacka;

class Trougao {
    std::vector<Tacka> trougao;
    static bool Double_cmp (double x, double y, double eps=1e-10){
        return std::fabs(x-y)<=eps*(std::fabs(x)+std::fabs(y));
    }
    static constexpr double PI=3.14159;
    public:
    Trougao (const Tacka &t1, const Tacka &t2, const Tacka &t3) { 
        if(Orijentacija(t1,t2,t3)==0) throw std::domain_error("Nekorektne pozicije tjemena");
        trougao.push_back(t1); trougao.push_back(t2); trougao.push_back(t3);
    };
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3);
    void Postavi(int indeks, const Tacka &t);
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        if(t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second)>0) return 1;
        else if(t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second)<0) return -1;
        return 0;
    }
    Tacka DajTjeme(int indeks) const;
    double DajStranicu(int indeks) const;
    double DajUgao(int indeks) const;
    Tacka DajCentar() const;
    double DajObim() const;
    double DajPovrsinu() const;
    bool DaLiJePozitivnoOrijentiran() const {return Orijentacija(trougao[0],trougao[1],trougao[2]);};
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

void Trougao::Postavi (const Tacka &t1, const Tacka &t2, const Tacka &t3){
    if(Orijentacija(t1,t2,t3)==0) throw std::domain_error ("Nekorektne pozicije tjemena");
    trougao[0]=t1; trougao[1]=t2; trougao[2]=t3;
    //trougao.push_back(t1); trougao.push_back(t2); trougao.push_back(t3);
}

void Trougao::Postavi(int indeks, const Tacka &t){
    if(indeks<1 || indeks>3) throw std::range_error("Nekorektan indeks");
    try{
        if(indeks==1) this->Postavi(t,this->trougao[1], this->trougao[2]);
        else if(indeks == 2) this->Postavi( this->trougao[0], t, this->trougao[2]);
        else this->Postavi(this->trougao[0], this->trougao[1], t);
    }
    catch(...){
        throw;
    }
}

Tacka Trougao::DajTjeme ( int indeks ) const{
    if(indeks <1 || indeks >3) throw std::range_error ("Nekorektan indeks");
    return trougao[indeks-1];
}

double Trougao::DajStranicu(int indeks) const{
    if(indeks <1 || indeks >3) throw std::range_error ("Nekorektan indeks");
    if(indeks==1) return std::sqrt((trougao[1].first-trougao[2].first)*(trougao[1].first-trougao[2].first)+(trougao[1].second-trougao[2].second)*(trougao[1].second-trougao[2].second));
    else if(indeks==2) return std::sqrt((trougao[0].first-trougao[2].first)*(trougao[0].first-trougao[2].first)+(trougao[0].second-trougao[2].second)*(trougao[0].second-trougao[2].second));
    return std::sqrt((trougao[1].first-trougao[0].first)*(trougao[1].first-trougao[0].first)+(trougao[1].second-trougao[0].second)*(trougao[1].second-trougao[0].second));
}

double Trougao::DajUgao(int indeks) const{
    if(indeks <1 || indeks >3) throw std::range_error ("Nekorektan indeks");
    double a(DajStranicu(1)), b(DajStranicu(2)), c(DajStranicu(3));
    if(indeks==1){
        double suma(b*b+c*c-a*a);
        return std::acos(suma/(2*b*c));
    }
    else if (indeks==2){
        double suma(a*a+c*c-b*b);
        return std::acos(suma/(2*a*c));
    } 
    double suma(a*a+b*b-c*c);
    return std::acos(suma/(2*a*b));
}

Tacka Trougao::DajCentar() const{
    return Tacka ((trougao[0].first+trougao[1].first+trougao[2].first)/3, (trougao[0].second+trougao[1].second+trougao[2].second)/3);
}

double Trougao::DajObim() const{
    return DajStranicu(1)+DajStranicu(2)+DajStranicu(3);
}

double Trougao::DajPovrsinu() const{
    auto a(std::fabs(trougao[0].first*(trougao[1].second-trougao[2].second)-trougao[1].first*(trougao[0].second-trougao[2].second)+trougao[2].first*(trougao[0].second-trougao[1].second)));
    return a/2;
}

void Trougao::Ispisi() const{
    std::cout << "(("<<trougao[0].first<<","<<trougao[0].second<<"),("<<trougao[1].first<<","<<trougao[1].second<<"),("<<trougao[2].first<<","<<trougao[2].second<<"))";
}

void Trougao::Transliraj(double delta_x, double delta_y){
    for(int i=0; i<3; i++){
        trougao[i].first+=delta_x;
        trougao[i].second+=delta_y;
    }
}

void Trougao::Centriraj(const Tacka &t){
    double dx(t.first-DajCentar().first), dy(t.second-DajCentar().second);
    Transliraj(dx,dy);
}

void Trougao::Rotiraj(const Tacka &t, double ugao){
    if(Double_cmp(ugao,0)) return;
    for(int i=0; i<3; i++){
        Tacka p(trougao[i]);
        trougao[i].first=t.first + (p.first-t.first)*std::cos(ugao)-(p.second-t.second)*std::sin(ugao);
        trougao[i].second=t.second + (p.first-t.first)*std::sin(ugao)+(p.second-t.second)*std::cos(ugao);
    }
}


void Trougao::Skaliraj(const Tacka &t, double faktor){
    if(Trougao::Double_cmp(faktor, 0)) throw std::domain_error("Nekorektan faktor skaliranja");
    for(int i=0; i<3; i++){
        trougao[i].first=t.first+faktor*(trougao[i].first-t.first);
        trougao[i].second=t.second+faktor*(trougao[i].second-t.second);
    }
}

void Trougao::Rotiraj(double ugao){
    Rotiraj(DajCentar(), ugao);
}


void Trougao::Skaliraj(double faktor){
    Skaliraj(DajCentar(),faktor);
}

bool Trougao::DaLiJeUnutra(const Tacka &t) const{
    
    if(Orijentacija(trougao[0],trougao[1],trougao[2])==1){
        if(Orijentacija(trougao[0],trougao[1],t)==1){
            if(Orijentacija(trougao[1],trougao[2],t)==1){
                if(Orijentacija(trougao[2], trougao[0], t)==1) return true;
            }
        }
    }
    else if(Orijentacija(trougao[0],trougao[1],trougao[2])==-1){
        if(Orijentacija(trougao[0],trougao[1],t)==-1){
            if(Orijentacija(trougao[1],trougao[2],t)==-1){
                if(Orijentacija(trougao[2],trougao[0],t)==-1) return true;
            }
        }
    }
    return false;
}

bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2){
    int identicni(0);
    for(int i=0;i<3; i++){
        for(int j=0; j<3; j++){
            if(Trougao::Double_cmp(t1.trougao[i].first,t2.trougao[j].first) && Trougao::Double_cmp(t1.trougao[i].second,t2.trougao[j].second)) identicni++;
        }
    }
    return (identicni==3);
}


bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2){
    

    bool nadjen(false);
        for(int i=1; i<4; i++){
            for(int j=1; j<4;j++){
                if(Trougao::Double_cmp(t1.DajStranicu(i), t2.DajStranicu(j)) && Trougao::Double_cmp(t1.DajUgao(i), t2.DajUgao(j))){
                    for(int k=1; k<4; k++){
                        for(int l=1; l<4; l++){
                            if(k!=i && l!=j){
                                if(Trougao::Double_cmp(t1.DajStranicu(k), t2.DajStranicu(l)) && Trougao::Double_cmp(t1.DajUgao(k), t2.DajUgao(l))){
                                    nadjen=true; 
                                    k=l=i=j=100 ;
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
        //for(int i=0; i<3; i++) if(stranice[i]==-1 || uglovi[i]==-1) return false;
    return nadjen;
}

bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2){
    std::vector<bool> isti(3);
    for(int i=1; i<4; i++){
        for(int j=1; j<4; j++){
            if(Trougao::Double_cmp(t1.DajUgao(i),t2.DajUgao(j))) isti[i-1]=true;
        }
    }
    int b(0);
    for(int i=0; i<3; i++) if(isti[i]) b++;
    if(b>=2) return true;
    return false;
}


int main ()
{
    int n;
    std::cout << "Koliko zelite kreirati trouglova: ";
        std::cin>>n;
        std::vector<std::shared_ptr<Trougao>> v;
    try{
        
    
        v.resize(n);
        
        for(int i=0; i<n; i++){
            std::cout << "Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): " ;
            double x1,y1,x2,y2,x3,y3;
            std::cin >> x1>>y1>>x2>>y2>>x3>>y3;
            try{
                Trougao t(Tacka(x1,y1), Tacka(x2,y2), Tacka(x3,y3));
                v[i]=std::make_shared<Trougao> (Tacka(x1,y1), Tacka(x2,y2), Tacka(x3,y3));
            }
            catch (std::domain_error){
                std::cout << "Nekorektne pozicije tjemena, ponovite unos!" << std::endl;
                i--;
            }
        }
        std::cout << "Unesite vektor translacije (dx dy): ";
        double dx,dy;
        std::cin >> dx>>dy;
        std::transform(v.begin(), v.end(), v.begin(), [dx,dy] (std::shared_ptr<Trougao> pok) { pok->Transliraj(dx,dy); return pok; } );
        
        std::cout << "Unesite ugao rotacije: " ;
        double ug;
        std::cin >> ug;
        std::transform(v.begin(), v.end(), v.begin(), [ug] (std::shared_ptr<Trougao> pok) { pok->Rotiraj(ug); return pok;});

        std::cout << "Unesite faktor skaliranja: " ;
        double fkt;
        std::cin >> fkt;
        try{
            std::transform(v.begin(), v.end(), v.begin(), [fkt] (std::shared_ptr<Trougao> pok) { pok->Skaliraj( pok->DajTjeme(1) ,fkt); return pok;});
        }
        catch (std::domain_error i){
            std::cout << i.what() << std::endl;
        }
        std::sort(v.begin(), v.end(), [](std::shared_ptr<Trougao> p1, std::shared_ptr<Trougao> p2) {return p1->DajPovrsinu() < p2->DajPovrsinu() ;});
        std::cout<<"Trouglovi nakon obavljenih transformacija:"<<std::endl;
        std::for_each(v.begin(), v.end(), [](std::shared_ptr<Trougao> ptr) {ptr->Ispisi(); std::cout<<std::endl;});
        
        Trougao min_obim (**std::min_element(v.begin(), v.end(), [](std::shared_ptr<Trougao> pok1, std::shared_ptr<Trougao> pok2) {return pok1->DajObim()<pok2->DajObim();}));
        std::cout << "Trougao sa najmanjim obimom: "; min_obim.Ispisi(); std::cout<<std::endl;
        bool idn(false), slicni(false), podudarni(false);
        
        for(int i=0; i<v.size(); i++){
            for(int j=i+1; j<v.size(); j++){
                if (DaLiSuIdenticni(*v[i], *v[j])){
                    if(!idn) std::cout << "Parovi identicnih trouglova:" << std::endl;
                    idn=true;
                    v[i]->Ispisi();
                    std::cout << " i "; v[j]->Ispisi();
                    std::cout  << std::endl;
                }
            }
        }
        if(!idn) std::cout << "Nema identicnih trouglova!" << std::endl;
        
        for(int i=0; i<v.size(); i++){
            for(int j=i+1; j<v.size(); j++){
                if (DaLiSuPodudarni(*v[i], *v[j])){
                    if(!podudarni) std::cout << "Parovi podudarnih trouglova:" << std::endl;
                    podudarni=true;
                    v[i]->Ispisi();
                    std::cout << " i "; v[j]->Ispisi();
                    std::cout  << std::endl;
                }
            }
        }
        if(!podudarni) std::cout << "Nema podudarnih trouglova!" << std::endl;
        
        for(int i=0; i<v.size(); i++){
            for(int j=i+1; j<v.size(); j++){
                if (DaLiSuSlicni(*v[i], *v[j])){
                    if(!slicni) std::cout << "Parovi slicnih trouglova:" << std::endl;
                    slicni=true;
                    v[i]->Ispisi();
                    std::cout << " i "; v[j]->Ispisi();
                    std::cout  << std::endl;
                }
            }
        }
        if(!slicni) std::cout << "Nema slicnih trouglova!" << std::endl;

        for(int i=0; i<n; i++) v[i]=nullptr;
    }
    catch(std::bad_alloc){
        std::cout << "Nema memorije" << std::endl;
        for(int i=0; i<n; i++) v[i]=nullptr;
    }
    
	return 0;
}