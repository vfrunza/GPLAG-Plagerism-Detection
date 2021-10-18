#include <iostream>
#include <stdexcept>
#include <cmath>
#include <vector>
#include <memory>
#include <algorithm>
typedef std::pair<double, double> Tacka;
#define EPS 1E-10

class Trougao{
    std::vector<Tacka> t;
    std::vector<std::pair<int,int>> ostali{{1,2},{0,2},{0,1}};
    static double Izraz(const Tacka &t1, const Tacka &t2, const Tacka &t3){return t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second);}
    void Index(int tem)const {
        if(tem!=1 && tem !=2 && tem !=3)
            throw std::range_error("Nekorektan indeks");
    }
 
    public:
    explicit Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3){Postavi(t1,t2,t3);}
    
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        if(Orijentacija(t1,t2,t3)==0)throw std::domain_error("Nekorektne pozicije tjemena"); 
        t.push_back(t1);t.push_back(t2);t.push_back(t3);
    }
    
    void Postavi(int indeks, const Tacka &t){
        Index(indeks);
        std::vector<Tacka> temp=Trougao::t;
        temp[indeks-1]=t;
        if(Orijentacija(temp[0],temp[1],temp[2])==0)throw std::domain_error("Nekorektne pozicije tjemena"); 
        this->t[indeks-1]=t;
    }
    
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3){ if(Izraz(t1,t2,t3)<0){return -1;}else{if(Izraz(t1,t2,t3)>0)return 1; else return 0;}}
    
    Tacka DajTjeme(int indeks) const{Index(indeks);return t[indeks-1];}
    
    double DajStranicu(int indeks) const{Index(indeks);return std::sqrt(std::pow((t[ostali[indeks-1].first].first-t[ostali[indeks-1].second].first),2)+std::pow((t[ostali[indeks-1].first].second-t[ostali[indeks-1].second].second),2));}
    
    double DajUgao(int indeks) const{
        Index(indeks);
        double a(t[ostali[indeks-1].first].first-t[indeks-1].first), b(t[ostali[indeks-1].second].first-t[indeks-1].first), c(t[ostali[indeks-1].first].second-t[indeks-1].second), d(t[ostali[indeks-1].second].second-t[indeks-1].second);
        return std::acos((a*b+c*d)/(std::sqrt(std::pow(a,2)+std::pow(c,2))*std::sqrt(std::pow(b,2)+std::pow(d,2))));
    }
    
    Tacka DajCentar() const{return Tacka((t[0].first+t[1].first+t[2].first)/3,(t[0].second+t[1].second+t[2].second)/3);}
    
    double DajObim() const{return DajStranicu(1)+DajStranicu(2)+DajStranicu(3);}
    
    double DajPovrsinu() const{return std::abs(((double)1/2)*Izraz(t[0],t[1],t[2]));}
    
    bool DaLiJePozitivnoOrijentiran() const{return Orijentacija(t[0],t[1],t[2])>0;}
    
    bool DaLiJeUnutra(const Tacka &t) const {return Orijentacija(this->t[0],this->t[1],this->t[2])==Orijentacija(this->t[0],this->t[1],t)==Orijentacija(this->t[1],this->t[2],t)==Orijentacija(this->t[2],this->t[0],t);}
    
    void Ispisi() const {std::cout<<"(("<<t[0].first<<","<<t[0].second<<"),("<<t[1].first<<","<<t[1].second<<"),("<<t[2].first<<","<<t[2].second<<"))";}
    
    void Transliraj(double delta_x, double delta_y){
        for(int i=0;i<3;i++){
            t[i].first+=delta_x;
            t[i].second+=delta_y;
        }
    }
    
    void Centriraj (const Tacka &t){Transliraj(t.first-DajCentar().first, t.second-DajCentar().second);}
    
    void Rotiraj (const Tacka &t, double ugao) {for(int i=0;i<3;i++) this->t[i]= Tacka((t.first+(this->t[i].first-t.first)*std::cos(ugao)-(this->t[i].second-t.second)*std::sin(ugao)),(t.second+(this->t[i].first-t.first)*std::sin(ugao)+(this->t[i].second-t.second)*std::cos(ugao)));}
    
    void Skaliraj(const Tacka &t, double faktor) { 
        if((faktor<0 || faktor>0)==false)throw std::domain_error("Nekorektan faktor skaliranja");
        for(int i=0;i<3;i++) this->t[i]= Tacka((t.first+faktor*(this->t[i].first-t.first)),(t.second+faktor*(this->t[i].second-t.second)));
        if(faktor<0)Rotiraj(180);
    }
    
    void Rotiraj(double ugao) {Rotiraj(DajCentar(),ugao);}
    
    void Skaliraj(double faktor) {Skaliraj(DajCentar(), faktor);}
    
    friend bool DaLiSuIdenticni (const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuPodudarni (const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuSlicni (const Trougao &t1, const Trougao &t2);
};
bool Zajednicka(const Trougao &t1, const Trougao &t2, bool Koja){
    std::vector<Tacka> tjemena;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(std::abs(t1.DajUgao(i+1)-t2.DajUgao(j+1))<EPS && ((Koja==0 && std::abs(t1.DajStranicu(i+1)-t2.DajStranicu(j+1))<EPS) || Koja==1)){
                tjemena.push_back(t2.DajTjeme(j+1));
                break;
            }
    if(tjemena.size()==3 && Trougao::Orijentacija(t1.DajTjeme(1), t1.DajTjeme(2), t1.DajTjeme(3))==Trougao::Orijentacija(tjemena[0], tjemena[1], tjemena[2]) &&Trougao::Orijentacija(t1.DajTjeme(1), t1.DajTjeme(2), t1.DajTjeme(3))!=0)
        return true;
    else return false;
}
bool DaLiSuIdenticni (const Trougao &t1, const Trougao &t2){
    for(int i=0;i<3;i++){
        bool nadjen{};
        for(int j=0;j<3;j++){
            if(t1.t[i]==t2.t[j])
                nadjen=true;
        }
        if(nadjen==false)
            return false;
    }
    return true;
}
bool DaLiSuPodudarni (const Trougao &t1, const Trougao &t2){return Zajednicka(t1,t2,0);}
bool DaLiSuSlicni (const Trougao &t1, const Trougao &t2){return Zajednicka(t1,t2,1);}
void Parovi(bool(*f)(const Trougao &, const Trougao &), std::vector<std::shared_ptr<Trougao>> &pok, int br_el, std::vector<std::pair<Trougao, Trougao>> &parovi){
    for(int i=0;i<br_el;i++)
            for(int j=i+1;j<br_el;j++)
                if(f(*pok[i], *pok[j]))
                    parovi.push_back(std::pair<Trougao, Trougao>(*pok[i], *pok[j]));
}

int main (){
    int br_el;
    std::cout<<"Koliko zelite kreirati trouglova: ";
    std::cin>>br_el;
    try{
        std::vector<std::shared_ptr<Trougao>> pok(br_el, nullptr);
        Tacka t1,t2,t3;
        for(int i=0;i<br_el;i++){
            std::cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
            std::cin>>t1.first>>t1.second>>t2.first>>t2.second>>t3.first>>t3.second;
            try{
                pok[i]=std::shared_ptr<Trougao>(new Trougao(t1,t2,t3));
            }catch(std::domain_error Izuzetak){std::cout<<Izuzetak.what()<<", ponovite unos!"<<std::endl; i--;}
        }
        std::cout<<"Unesite vektor translacije (dx dy): ";
        double d_x, d_y,ugao, skaliranje;
        std::cin>>d_x>>d_y;
        std::cout<<"Unesite ugao rotacije: ";
        std::cin>>ugao;
        std::cout<<"Unesite faktor skaliranja: ";
        std::cin>>skaliranje;

        std::transform(pok.begin(), pok.end(), pok.begin(), [d_x,d_y,ugao,skaliranje](const std::shared_ptr<Trougao> &trougao)->std::shared_ptr<Trougao>{trougao->Transliraj(d_x,d_y); trougao->Rotiraj(ugao); trougao->Skaliraj(trougao->DajTjeme(1), skaliranje); return trougao;});
        std::sort(pok.begin(), pok.end(), [](const std::shared_ptr<Trougao> &trougao1, const std::shared_ptr<Trougao> &trougao2)->bool{return trougao1->DajPovrsinu()<trougao2->DajPovrsinu();});
        auto min=*std::min_element(pok.begin(), pok.end(), [](const std::shared_ptr<Trougao> &trougao1, const std::shared_ptr<Trougao> &trougao2)->bool{return trougao1->DajObim()<trougao2->DajObim();});
        
        std::cout<<"Trouglovi nakon obavljenih transformacija: \n";
        for(int i=0;i<br_el;i++){
            pok[i]->Ispisi();
            std::cout<<std::endl;
        }
        std::cout<<"Trougao sa najmanjim obimom: ";
        min->Ispisi();
        std::cout<<std::endl;
        
        std::vector<std::pair<Trougao,Trougao>> identicni, slicni, podudarni;
        Parovi(DaLiSuIdenticni, pok, br_el, identicni);
        Parovi(DaLiSuPodudarni, pok, br_el, podudarni);
        Parovi(DaLiSuSlicni, pok, br_el, slicni);
        
        if(identicni.size()!=0){
            std::cout<<"Parovi identicnih trouglova:"<<std::endl;
            std::for_each(identicni.begin(), identicni.end(),[](std::pair<Trougao, Trougao> &parovi){(parovi.first).Ispisi(); std::cout<<" i "; (parovi.second).Ispisi(); std::cout<<std::endl;});
        }else {std::cout<<"Nema identicnih trouglova!"<<std::endl;}
        
        if(podudarni.size()!=0){
            std::cout<<"Parovi podudarnih trouglova:"<<std::endl;
            std::for_each(podudarni.begin(), podudarni.end(),[](std::pair<Trougao, Trougao> &parovi){(parovi.first).Ispisi(); std::cout<<" i "; (parovi.second).Ispisi(); std::cout<<std::endl;});
        }else {std::cout<<"Nema podudarnih trouglova!"<<std::endl;}
        
        if(slicni.size()!=0){
            std::cout<<"Parovi slicnih trouglova:"<<std::endl;
            std::for_each(slicni.begin(), slicni.end(),[](std::pair<Trougao, Trougao> &parovi){(parovi.first).Ispisi(); std::cout<<" i "; (parovi.second).Ispisi(); std::cout<<std::endl;});
        }else {std::cout<<"Nema slicnih trouglova!"<<std::endl;}
        
        for(int i=0;i<br_el;i++)
            pok[i]=nullptr;
    }catch(...){}
    
    return 0;
}