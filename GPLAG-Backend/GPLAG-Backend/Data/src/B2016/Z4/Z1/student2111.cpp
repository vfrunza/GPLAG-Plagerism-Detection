/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <utility>
#include <cmath>
#include <vector>
#include <memory>
#include <algorithm>

typedef std::pair<double,double> Tacka;

class Trougao {
    private:
        Tacka tacke[3];
        static double OnajIzraz(const Tacka &t1, const Tacka &t2, const Tacka &t3){
            return t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second);
        }
        static void BaciIzuzetakZaIndeks(int indeks){ 
            if(indeks<1 || indeks>3) throw std::range_error("Nekorektan indeks");
        }
        static double Duzina (const Tacka &t1, const Tacka &t2){
            return std::sqrt((t1.first-t2.first)*(t1.first-t2.first)+(t1.second-t2.second)*(t1.second-t2.second));
        }
        static double IzracunajUgao(double s1, double s2, double s3){
            return std::acos((s2*s2+s3*s3-s1*s1)/(2*s2*s3));
        }
        static bool Jednakokraki(const Trougao &t){
            return (Jednake(t.DajStranicu(1),t.DajStranicu(2)) || Jednake(t.DajStranicu(1),t.DajStranicu(3)) || Jednake(t.DajStranicu(2),t.DajStranicu(3)));};
        static bool Jednake(double x, double y, double eps = 1e-10);
        static bool JednakeTacke(const Tacka &t1, const Tacka &t2){
            return(Jednake(t1.first,t2.first)&&Jednake(t1.second,t2.second));
        }
    public: 
        Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3){
            Postavi(t1,t2,t3);
        }
        void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3){
            if(Orijentacija(t1,t2,t3)==0) throw std::domain_error("Nekorektne pozicije tjemena");
            tacke[0]=t1; tacke[1]=t2; tacke[2]=t3;
        }
        void Postavi(int indeks, const Tacka &t){
            BaciIzuzetakZaIndeks(indeks); if(indeks==1) Postavi(t,DajTjeme(2),DajTjeme(3));
            else if(indeks==2) Postavi(DajTjeme(1),t,DajTjeme(3));
            else Postavi(DajTjeme(1),DajTjeme(2),t);
        }
        static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3){
            double x=OnajIzraz(t1,t2,t3);
            if(x<0) return -1; 
            else if(x>0) return 1; 
            else return 0;
        }
        Tacka DajTjeme(int indeks) const{
            BaciIzuzetakZaIndeks(indeks); 
            return tacke[indeks-1];
        }
        double DajStranicu (int indeks) const{
            BaciIzuzetakZaIndeks(indeks); 
            if(indeks==1) return Duzina(tacke[1],tacke[2]); 
            else if(indeks==2) return Duzina(tacke[0],tacke[2]); 
            else return Duzina(tacke[0],tacke[1]);
        }
        double DajUgao (int indeks) const{
            BaciIzuzetakZaIndeks(indeks);
            if(indeks==1) return IzracunajUgao(DajStranicu(1),DajStranicu(2),DajStranicu(3));
            else if(indeks==2) return IzracunajUgao(DajStranicu(2), DajStranicu(1),DajStranicu(3));
            else return IzracunajUgao(DajStranicu(3), DajStranicu(1), DajStranicu(2));}
        Tacka DajCentar () const{
            return {(tacke[0].first+tacke[1].first+tacke[2].first)/3,(tacke[0].second+tacke[1].second+tacke[2].second)/3};}
        double DajObim () const{
            return DajStranicu(1)+DajStranicu(2)+DajStranicu(3);
        }
        double DajPovrsinu () const {
            return 0.5*std::fabs(OnajIzraz(tacke[0],tacke[1],tacke[2]));
        }
        bool DaLiJePozitivnoOrijentiran () const{
            if(Orijentacija(tacke[0],tacke[1],tacke[2])==1) return true; 
            return false;
        }
        bool DaLiJeUnutra (const Tacka &t) const;
        void Ispisi () const{
            std::cout<<"(("<<tacke[0].first<<","<<tacke[0].second<<"),("<<tacke[1].first<<","<<tacke[1].second<<"),("<<tacke[2].first<<","<<tacke[2].second<<"))";
        }
        void Transliraj (double delta_x, double delta_y){
            for(int i=0;i<3;i++) tacke[i].first+=delta_x, tacke[i].second+=delta_y;
        }
        void Centriraj (const Tacka &t){
            Transliraj(t.first-DajCentar().first, t.second-DajCentar().second);
        }
        void Rotiraj (const Tacka &t, double ugao);
        void Skaliraj (const Tacka &t, double faktor);
        void Rotiraj (double ugao){
            Rotiraj(DajCentar(),ugao);
        }
        void Skaliraj (double faktor){
            Skaliraj(DajCentar(),faktor);
        }
        friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
        friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
        friend bool DaLiSuSlicni (const Trougao &t1, const Trougao &t2);
};
void Trougao::Rotiraj(const Tacka &t, double ugao){
    for(int i=0;i<3;i++){
        double a=t.first+(tacke[i].first-t.first)*std::cos(ugao)-(tacke[i].second-t.second)*std::sin(ugao);
        double b=t.second+(tacke[i].first-t.first)*std::sin(ugao)+(tacke[i].second-t.second)*std::cos(ugao);
        tacke[i].first=a;
        tacke[i].second=b;
    }
}
bool Trougao::Jednake(double x, double y, double eps){
    return std::fabs(x-y) <= eps * (std::fabs(x)+std::fabs(y));
}
void Trougao::Skaliraj(const Tacka &t, double faktor){
    if(Jednake(faktor,0)) throw std::domain_error("Nekorektan faktor skaliranja");
    for(int i=0;i<3;i++)
        tacke[i].first=t.first+faktor*(tacke[i].first-t.first), tacke[i].second=t.second+faktor*(tacke[i].second-t.second);
}
bool Trougao::DaLiJeUnutra(const Tacka &t) const {
    
    int a=Orijentacija(tacke[0],tacke[1], tacke[2]), b=Orijentacija(tacke[0],tacke[1],t);
    int c=Orijentacija(tacke[1],tacke[2],t), d=Orijentacija(tacke[2],tacke[0],t);
    if(a>0&&b>0&&c>0&&d>0) return true;
    if(a<0&&b<0&&c<0&&d<0) return true;
    return false;
}
bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2){
    
    std::vector<double> s1,s2;
    for(int i=1;i<4;i++){
        s1.push_back(t1.DajStranicu(i));
        s2.push_back(t2.DajStranicu(i));
    }
    std::sort(s1.begin(),s1.end());
    std::sort(s2.begin(),s2.end());
    if(s1!=s2) return false; 
    if(s1==s2 && Trougao::Jednakokraki(t1))
        return true;
    std::vector<int> i1{1,2,3},i2{1,2,3};
    std::vector<Tacka> v1{t1.tacke[0],t1.tacke[1],t1.tacke[2]},v2{t2.tacke[0],t2.tacke[1],t2.tacke[2]};
    for(int i=0;i<3;i++){
        for(int j=i+1;j<3;j++){
            if(t1.DajStranicu(i1[i])>t1.DajStranicu(i1[j])){
                std::swap(i1[i],i1[j]);
                std::swap(v1[i],v1[j]);
            }
            if(t2.DajStranicu(i2[i])>t2.DajStranicu(i2[j])){
                std::swap(i2[i],i2[j]);
                std::swap(v2[i],v2[j]);
            }
        }
    }
    if(s1==s2 && Trougao::Orijentacija(v1[0],v1[1],v1[2])==Trougao::Orijentacija(v2[0],v2[1],v2[2]))
        return true;
    return false;
}
bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2){
    
    if(!(Trougao::JednakeTacke(t1.tacke[0],t2.tacke[0]) || Trougao::JednakeTacke(t1.tacke[0],t2.tacke[1]) || Trougao::JednakeTacke(t1.tacke[0],t2.tacke[2])))
        return false;
    if(!(Trougao::JednakeTacke(t1.tacke[1],t2.tacke[0]) || Trougao::JednakeTacke(t1.tacke[1],t2.tacke[1]) || Trougao::JednakeTacke(t1.tacke[1],t2.tacke[2])))
        return false;
    if(!(Trougao::JednakeTacke(t1.tacke[2],t1.tacke[0]) || Trougao::JednakeTacke(t1.tacke[2],t2.tacke[1]) || Trougao::JednakeTacke(t1.tacke[2],t2.tacke[2])))
        return false;
    
    return true;
} 
bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2){
    
    std::vector<double> s1,s2;
    for(int i=1;i<4;i++){
        s1.push_back(t1.DajStranicu(i));
        s2.push_back(t2.DajStranicu(i));
    }
    std::sort(s1.begin(),s1.end());
    std::sort(s2.begin(),s2.end());
    bool prop=false;
    if(Trougao::Jednake(s1[0]/s2[0], s1[1]/s2[1]) && Trougao::Jednake(s1[0]/s1[0], s1[2]/s2[2]) && Trougao::Jednake(s1[1]/s2[1],s1[2]/s2[2]))
        prop=true;
    if(!prop)
        return false;
    if(prop && Trougao::Jednakokraki(t1))
        return true;
    std::vector<int> i1{1,2,3},i2{1,2,3};
    std::vector<Tacka> v1{t1.tacke[0],t1.tacke[1],t1.tacke[2]},v2{t2.tacke[0],t2.tacke[1],t2.tacke[2]};
    for(int i=0;i<3;i++){
        for(int j=0; j<3; j++){
            if(t1.DajStranicu(i1[i])>t1.DajStranicu(i1[j])){
                std::swap(i1[i],i1[j]);
                std::swap(v1[i],v1[j]);
            }
            if(t2.DajStranicu(i2[i])>t2.DajStranicu(i2[j])){
                std::swap(i2[i],i2[j]);
                std::swap(v2[i],v2[j]);
            }
        }
    }
    
    if(Trougao::Orijentacija(v1[0],v1[1],v1[2])==Trougao::Orijentacija(v2[0],v2[1],v2[2]))
        return true;
        
    return false;
}

int main (){
    std::vector<std::shared_ptr<Trougao>> tr;
    try{
        int n;
    std::cout<<"Koliko zelite kreirati trouglova: ";
    std::cin>>n;

    double x1,x2,x3,y1,y2,y3;
    for(int i=1 ; i<=n ; i++){
        bool neispravan;
        do{
           neispravan=false;
           std::cout<<"Unesite podatke za "<<i<<". trougao (x1 y1 x2 y2 x3 y3): ";
           std::cin>>x1>>y1>>x2>>y2>>x3>>y3;
           try{
           std::shared_ptr<Trougao> pok(new Trougao({x1,y1},{x2,y2},{x3,y3}));
               tr.push_back(pok);
           }
           catch(std::domain_error e){
               std::cout<<e.what()<<", ponovite unos!"<<std::endl;
               neispravan=true;
           }
            
        }
        while(neispravan);
    }
    
    double dx,dy,ugao,faktor;
    std::cout<<"Unesite vektor translacije (dx dy): ";
    std::cin>>dx>>dy;
    std::cout<<"Unesite ugao rotacije: ";
    std::cin>>ugao;
    std::cout<<"Unesite faktor skaliranja: ";
    std::cin>>faktor;
    std::transform(tr.begin(),tr.end(),tr.begin(),[dx,dy] (std::shared_ptr<Trougao> t){
        t->Transliraj(dx,dy);
        return t;
    });
    std::transform(tr.begin(),tr.end(),tr.begin(),[ugao](std::shared_ptr<Trougao> t){
        t->Rotiraj(ugao);
        return t;
    });
    std::transform(tr.begin(),tr.end(),tr.begin(),[faktor](std::shared_ptr<Trougao> t){
        t->Skaliraj(t->DajTjeme(1),faktor);
        return t;
    });
    
    std::sort(tr.begin(),tr.end(),[](std::shared_ptr<Trougao> p1, std::shared_ptr<Trougao> p2){
        return p1->DajPovrsinu()<p2->DajPovrsinu();});
        
        std::cout<<"Trouglovi nakon obavljenih transformacija:"<<std::endl;
        
        std::for_each(tr.begin(),tr.end(),[](std::shared_ptr<Trougao> t){
            t->Ispisi(); std::cout<<std::endl;
        });
        
        auto pok=std::min_element(tr.begin(),tr.end(),[](std::shared_ptr<Trougao> p1, std::shared_ptr<Trougao> p2){
            if(p1->DajObim()<p2->DajObim())
                return true;
            return false;
        });
        
        if(pok!=tr.end()) std::cout<<"Trougao sa najmanjim obimom: ", (*pok)->Ispisi();
        std::cout<<std::endl;
        std::vector<std::pair<Trougao,Trougao>> paroviI;
        std::vector<std::pair<Trougao,Trougao>> paroviS;
        std::vector<std::pair<Trougao,Trougao>> paroviP;
        for(int i=0;i<tr.size();i++){
            for(int j=i+1; j<tr.size();j++){
                if(DaLiSuIdenticni(*tr[i],*tr[j]))
                    paroviI.push_back({*tr[i],*tr[j]});
                if(DaLiSuPodudarni(*tr[i],*tr[j]))
                    paroviP.push_back({*tr[i],*tr[j]});
                if(DaLiSuSlicni(*tr[i],*tr[j]))
                    paroviS.push_back({*tr[i],*tr[j]});
            }
        }
            if(paroviI.size()==0)
                std::cout<<"Nema identicnih trouglova!"<<std::endl;
            else {
                std::cout<<"Parovi identicnih trouglova: "<<std::endl;
                for(auto x : paroviI){
                    x.first.Ispisi(); std::cout<<" i "; x.second.Ispisi();
                    std::cout<<std::endl;
                }
            }
            if(paroviP.size()==0)
                std::cout<<"Nema podudarnih trouglova!"<<std::endl;
            else{
                std::cout<<"Parovi podudarnih trouglova: "<<std::endl;
                for(auto x : paroviP){
                    x.first.Ispisi(); std::cout<<" i "; x.second.Ispisi();
                    std::cout<<std::endl;
                }
            }
            if(paroviS.size()==0)
                std::cout<<"Nema slicnih trouglova!"<<std::endl;
            else{
                std::cout<<"Parovi slicnih trouglova: "<<std::endl;
                for(auto x : paroviS){
                    x.first.Ispisi(); std::cout<<" i "; x.second.Ispisi();
                    std::cout<<std::endl;
                }
            }
    }
    catch(std::bad_alloc){
        for(int i=0;i<tr.size();i++)
            tr[i]=nullptr;
        std::cout<<"Nedovoljno memorije";
        
    }
            
        
	return 0;
}