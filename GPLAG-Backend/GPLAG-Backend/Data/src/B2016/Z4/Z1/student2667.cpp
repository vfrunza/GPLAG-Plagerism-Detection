/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <memory>

#define epsilon 0.00001
typedef std::pair<double, double> Tacka;
class Trougao {
    Tacka t1, t2, t3;
    void ProvjeriDaLiJeTrougao( Tacka t11,  Tacka t22, Tacka t33){
       if(Izraz(t11,t22,t33) == 0) throw std::domain_error ("Nekorektne pozicije tjemena");
    }
    static int Izraz(Tacka t11, Tacka t22, Tacka t33) {
        return t11.first*(t22.second - t33.second) + t22.first*(t33.second - t11.second) + t33.first*(t11.second - t22.second);
    }
    public: 
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        Postavi(t1,t2,t3);
    }
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        try{
            this->t1 = t1; 
            this->t2 = t2;
            this->t3 = t3;  
            ProvjeriDaLiJeTrougao(t1,t2,t3);
        }
        catch(...){
            throw;
        }
        
    }
    void Postavi(int indeks, const Tacka &t){
       
        if(indeks == 1)
            this->t1 = t;
        else if(indeks == 2)
            this->t2 = t;
        else if(indeks == 3) 
            this->t3 = t;
        else 
            throw std::range_error("Nekorektan indeks");
        ProvjeriDaLiJeTrougao(t1,t2,t3);
    }
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        int i = Izraz(t1,t2,t3);
        if(i == 0) return 0;
        else if(i < 0) return -1;
        else return 1;
    }
    Tacka DajTjeme(int indeks) const{
        if(indeks == 1)
            return t1;
        else if(indeks == 2)
            return t2;
        else if(indeks == 3) 
            return t3;
        else 
            throw std::range_error("Nekorektan indeks");
    }
    double DajStranicu(int indeks) const{
        if(indeks == 1)
            return sqrt((t2.first - t3.first)*(t2.first - t3.first) + (t2.second - t3.second)*(t2.second - t3.second));
        else if(indeks == 2)
            return sqrt((t1.first - t3.first)*(t1.first - t3.first) + (t1.second - t3.second)*(t1.second - t3.second));
        else if(indeks == 3) 
            return sqrt((t2.first - t1.first)*(t2.first - t1.first) + (t2.second - t1.second)*(t2.second - t1.second));
        else 
            throw std::range_error("Nekorektan indeks");
    }
    double DajUgao(int indeks) const{
        double nasuprot_prve = DajStranicu(1);
        double nasuprot_druge = DajStranicu(2);
        double nasuprot_trece = DajStranicu(3);
        
        if(indeks == 1){
           
            auto x = acos((nasuprot_trece*nasuprot_trece + nasuprot_druge*nasuprot_druge - nasuprot_prve*nasuprot_prve)/(2*nasuprot_trece*nasuprot_druge));
            
            return x;
        }
        else if(indeks == 2)
            return acos((nasuprot_trece*nasuprot_trece + nasuprot_prve*nasuprot_prve - nasuprot_druge*nasuprot_druge)/(2*nasuprot_trece*nasuprot_prve));
        else if(indeks == 3)
             return acos((nasuprot_prve*nasuprot_prve + nasuprot_druge*nasuprot_druge - nasuprot_trece*nasuprot_trece)/(2*nasuprot_prve*nasuprot_druge)); 
        else 
            throw std::range_error("Nekorektan indeks");
    }
    Tacka DajCentar() const{
        Tacka t = std::make_pair((t1.first+t2.first+t3.first)/3, (t1.second+t2.second+t3.second)/3);
        return t;
    }
    double DajObim() const{
        double nasuprot_prve = DajStranicu(1);
        double nasuprot_druge = DajStranicu(2);
        double nasuprot_trece = DajStranicu(3);
        return nasuprot_trece+nasuprot_druge+nasuprot_prve;
    }
    double DajPovrsinu() const{
        int i = Izraz(t1,t2,t3);
        return std::abs(i)/2;
    }
    bool DaLiJePozitivnoOrijentiran() const{
        if(Orijentacija(t1,t2,t3) == 1) return true;
        else return false;
    }
    bool DaLiJeUnutra(const Tacka &t) const{
        int o = Orijentacija(t1,t2,t3);
        if(o == Orijentacija(t1,t2,t) && o == Orijentacija(t2,t3,t) && o == Orijentacija(t3,t1,t)) return true;
        return false;
    }
    void Ispisi() const{
        std::cout<< "((" << t1.first << "," << t1.second << "),(" << t2.first << "," << t2.second << "),(" << t3.first << "," << t3.second << "))" ;
    }
    void Transliraj(double delta_x, double delta_y){
        t1.first = t1.first + delta_x;
        t2.first = t2.first + delta_x;
        t3.first = t3.first + delta_x;
        t1.second = t1.second + delta_y;
        t2.second = t2.second + delta_y;
        t3.second = t3.second + delta_y;
        
        
    }
    void Centriraj(const Tacka &t){
        Tacka x = DajCentar();
        auto delta_x = t.first - x.first;
        auto delta_y = t.second - x.second;
        Transliraj(delta_x,delta_y);
    }
    void Rotiraj(const Tacka &t, double ugao){
        auto x = t.first;
        auto y = t.second;
        
        auto a = t1.first;
        auto b = t1.second;
        t1.first = x + (a - x)*cos(ugao) - (b - y)*sin(ugao);
        t1.second = y + (a - x)*sin(ugao) + (b - y)*cos(ugao);
        
        a = t2.first;
        b = t2.second;
        t2.first = x+ (a - x)*cos(ugao) - (b - y)*sin(ugao);
        t2.second = y + (a-x)*sin(ugao) + (b - y)*cos(ugao);
        
        a = t3.first;
        b = t3.second;
        t3.first = x+ (a - x)*cos(ugao) - (b - y)*sin(ugao);
        t3.second = y + (a-x)*sin(ugao) + (b - y)*cos(ugao);
        
    }
    void Skaliraj(const Tacka &t, double faktor){
        if(fabs(faktor) < epsilon) throw std::domain_error("Nekorektan faktor skaliranja");
        auto x = t.first;
        auto y = t.second;
        t1.first = x + faktor*(t1.first - x);
        t1.second = y + faktor*(t1.second - y);
        t2.first = x + faktor*(t2.first - x);
        t2.second = y + faktor*(t2.second - y);
        t3.first = x + faktor*(t3.first - x);
        t3.second = y + faktor*(t3.second - y);
        
    }
    void Rotiraj(double ugao){
        Tacka t = DajCentar();
        Rotiraj(t,ugao);
    }
    void Skaliraj(double faktor){
        Tacka t = DajCentar();
        Skaliraj(t,faktor);
    }
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2){
        Tacka a = t1.DajTjeme(1);
        Tacka b = t1.DajTjeme(2);
        Tacka c = t1.DajTjeme(3);
        
        Tacka d = t2.DajTjeme(1);
        Tacka e = t2.DajTjeme(2);
        Tacka f = t2.DajTjeme(3);
        if((a==d && ((b==e && c==f) || (b==f && c==e))) || (a==e && ((b==f && c==d) || (b==d && c==f))) || (a==f && ((b==d && c==e) || (b==e && c==d) )) ) return true;
        return false;
    }
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2){
        auto a1 = t1.DajStranicu(1);
        auto b1 = t1.DajStranicu(2);
        auto c1 = t1.DajStranicu(3);
        
        auto a2 = t2.DajStranicu(1);
        auto b2 = t2.DajStranicu(2);
        auto c2 = t2.DajStranicu(3);
        
        if(fabs(a1-a2)<epsilon && fabs(b1-b2)<epsilon && fabs(c1-c2)<epsilon && t1.Orijentacija(t1.DajTjeme(1),t1.DajTjeme(2),t1.DajTjeme(3)) == t2.Orijentacija(t2.DajTjeme(1),t2.DajTjeme(2),t2.DajTjeme(3))) return true;
        else if(fabs(a1-a2)<epsilon && fabs(b1-c2)<epsilon && fabs(c1-b2)<epsilon && t1.Orijentacija(t1.DajTjeme(1),t1.DajTjeme(2),t1.DajTjeme(3)) == t2.Orijentacija(t2.DajTjeme(1),t2.DajTjeme(3),t2.DajTjeme(2))) return true;
        else if(fabs(a1-b2)<epsilon && fabs(b1-a2)<epsilon && fabs(c1-c2)<epsilon && t1.Orijentacija(t1.DajTjeme(1),t1.DajTjeme(2),t1.DajTjeme(3)) == t2.Orijentacija(t2.DajTjeme(2),t2.DajTjeme(1),t2.DajTjeme(3))) return true;
        else if(fabs(a1-b2)<epsilon && fabs(b1-c2)<epsilon && fabs(c1-a2)<epsilon && t1.Orijentacija(t1.DajTjeme(1),t1.DajTjeme(2),t1.DajTjeme(3)) == t2.Orijentacija(t2.DajTjeme(2),t2.DajTjeme(3),t2.DajTjeme(1))) return true;
        else if(fabs(a1-c2)<epsilon && fabs(b1-b2)<epsilon && fabs(c1-a2)<epsilon && t1.Orijentacija(t1.DajTjeme(1),t1.DajTjeme(2),t1.DajTjeme(3)) == t2.Orijentacija(t2.DajTjeme(3),t2.DajTjeme(2),t2.DajTjeme(1))) return true;
        else if(fabs(a1-c2)<epsilon && fabs(b1-a2)<epsilon && fabs(c1-b2)<epsilon && t1.Orijentacija(t1.DajTjeme(1),t1.DajTjeme(2),t1.DajTjeme(3)) == t2.Orijentacija(t2.DajTjeme(3),t2.DajTjeme(1),t2.DajTjeme(2))) return true;
        
        
        return false;
    }
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2){
        
        auto a1 = t1.DajStranicu(1);
        auto b1 = t1.DajStranicu(2);
        auto c1 = t1.DajStranicu(3);
        
        auto a2 = t2.DajStranicu(1);
        auto b2 = t2.DajStranicu(2);
        auto c2 = t2.DajStranicu(3);
        if(fabs((a1/a2) - (b1/b2))<epsilon && fabs((a1/a2)-(c1/c2))<epsilon && t1.Orijentacija(t1.DajTjeme(1),t1.DajTjeme(2),t1.DajTjeme(3)) == t2.Orijentacija(t2.DajTjeme(1),t2.DajTjeme(2),t2.DajTjeme(3))) return true;
        else if(fabs((a1/a2) - (b1/c2))<epsilon && fabs((a1/a2)-(c1/b2))<epsilon && t1.Orijentacija(t1.DajTjeme(1),t1.DajTjeme(2),t1.DajTjeme(3)) == t2.Orijentacija(t2.DajTjeme(1),t2.DajTjeme(3),t2.DajTjeme(2))) return true;
        else if(fabs((a1/b2) - (b1/a2))<epsilon && fabs((a1/b2)-(c1/c2))<epsilon && t1.Orijentacija(t1.DajTjeme(1),t1.DajTjeme(2),t1.DajTjeme(3)) == t2.Orijentacija(t2.DajTjeme(2),t2.DajTjeme(1),t2.DajTjeme(3))) return true;
        else if(fabs((a1/b2) - (b1/c2))<epsilon && fabs((a1/b2)-(c1/a2))<epsilon && t1.Orijentacija(t1.DajTjeme(1),t1.DajTjeme(2),t1.DajTjeme(3)) == t2.Orijentacija(t2.DajTjeme(2),t2.DajTjeme(3),t2.DajTjeme(1))) return true;
        else if(fabs((a1/c2) - (b1/b2))<epsilon && fabs((a1/c2)-(c1/a2))<epsilon && t1.Orijentacija(t1.DajTjeme(1),t1.DajTjeme(2),t1.DajTjeme(3)) == t2.Orijentacija(t2.DajTjeme(3),t2.DajTjeme(2),t2.DajTjeme(1))) return true;
        else if(fabs((a1/c2) - (b1/a2))<epsilon && fabs((a1/c2)-(c1/b2))<epsilon && t1.Orijentacija(t1.DajTjeme(1),t1.DajTjeme(2),t1.DajTjeme(3)) == t2.Orijentacija(t2.DajTjeme(3),t2.DajTjeme(1),t2.DajTjeme(2))) return true;
        return false;
    }

};
int main ()
{
    int n;
    std::cout<<"Koliko zelite kreirati trouglova: ";
    std::cin>>n;
    std::vector<std::shared_ptr<Trougao>> v(n);
    
    for(int i = 0; i < n; i++){
        std::vector<double> podaci;
        std::cout<<"Unesite podatke za " << i+1 << ". trougao (x1 y1 x2 y2 x3 y3): ";
        for(int j=0; j < 6; j++){
            double x;
            std::cin>> x;
            podaci.push_back(x);
        }
        
        std::cin.clear();
        std::cin.ignore(1000,'\n');
        Tacka t1, t2, t3;
        t1.first = podaci[0];
        t1.second = podaci[1];
        t2.first = podaci[2];
        t2.second = podaci[3];
        t3.first = podaci[4];
        t3.second = podaci[5];
        try{
            //Trougao t = new Trougao(t1,t2,t3);
            v[i] = std::make_shared<Trougao> (t1,t2,t3);
           /*Tacka t = v[i]->DajCentar();
           std::cout<< t.first << " " << t.second;*/
            //v[i]->Ispisi();
        }
        catch(std::domain_error e){
            std::cout<<e.what() << ", ponovite unos!"<<std::endl;
            i--;
        }
    }
    double delta_x,delta_y;
    std::cout<<"Unesite vektor translacije (dx dy): ";
    std::cin>>delta_x;
    std::cin>> delta_y;
    
    double ugao;
    std::cout << "Unesite ugao rotacije: ";
    std::cin>>ugao;
    
    double faktor; 
    std::cout<<"Unesite faktor skaliranja: ";
    std::cin>>faktor;
    
    std::transform(v.begin(), v.end(), v.begin(), [delta_x,delta_y](std::shared_ptr<Trougao> trougao) { trougao->Transliraj(delta_x,delta_y); return trougao;});
    std::transform(v.begin(), v.end(), v.begin(), [ugao](std::shared_ptr<Trougao> trougao) { trougao->Rotiraj(ugao); return trougao; });
    try{
        std::transform(v.begin(), v.end(), v.begin(), [faktor](std::shared_ptr<Trougao> trougao){ trougao->Skaliraj(trougao->DajTjeme(1),faktor); return trougao; });
    }
    catch(std::domain_error e){
        std::cout<<e.what()<<std::endl;
    }
    
    std::sort(v.begin(), v.end(), [](std::shared_ptr<Trougao> trougao1, std::shared_ptr<Trougao> trougao2) {
        
        if(trougao1->DajPovrsinu() < trougao2->DajPovrsinu()) return true;
        return false;
    });
    std::cout<<"Trouglovi nakon obavljenih transformacija: "<<std::endl;
    
    std::for_each(v.begin(), v.end(),  [](std::shared_ptr<Trougao> trougao) { trougao->Ispisi(); std::cout<<std::endl;} );
    
    auto najmanji_obim = std::min_element(v.begin(), v.end(), [](std::shared_ptr<Trougao> trougao1, std::shared_ptr<Trougao> trougao2){
        if(trougao1->DajObim() < trougao2->DajObim()) return true;
        return false;
    });
    std::cout<< "Trougao sa najmanjim obimom: ";
    (*najmanji_obim)->Ispisi();
    std::cout << std::endl;
    std::vector<std::pair<std::shared_ptr<Trougao>, std::shared_ptr<Trougao>>> parovi;
    
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            if(DaLiSuIdenticni(*v[i],*v[j])){
                parovi.push_back(make_pair(v[i],v[j]));
            }
        }
    }
    if(parovi.size()!=0){
        std::cout<<"Parovi identicnih trouglova:" << std::endl;
        for(int i = 0; i < parovi.size(); i++){
            parovi[i].first->Ispisi();
            std::cout<<" i ";
            parovi[i].second->Ispisi();
            std::cout<<std::endl;
        }
    }
    else {
        std::cout<< "Nema identicnih trouglova!"<< std::endl;
    }
    
    //
    
    std::vector<std::pair<std::shared_ptr<Trougao>, std::shared_ptr<Trougao>>> parovi_podudarnih;
    
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            if(DaLiSuPodudarni(*v[i],*v[j])){
                parovi_podudarnih.push_back(make_pair(v[i],v[j]));
            }
        }
    }
    if(parovi_podudarnih.size()!=0){
        std::cout<<"Parovi podudarnih trouglova:" <<std::endl;
        for(int i = 0; i < parovi_podudarnih.size(); i++){
            parovi_podudarnih[i].first->Ispisi();
            std::cout<<" i ";
            parovi_podudarnih[i].second->Ispisi();
            std::cout<<std::endl;
        }
    }
    else {
        std::cout<< "Nema podudarnih trouglova!" <<std::endl;
    }
    
    //
    
     std::vector<std::pair<std::shared_ptr<Trougao>, std::shared_ptr<Trougao>>> parovi_slicnih;
    
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            if(DaLiSuSlicni(*v[i],*v[j])){
                parovi_slicnih.push_back(make_pair(v[i],v[j]));
            }
        }
    }
    if(parovi_slicnih.size()!=0){
        std::cout<<"Parovi slicnih trouglova:" <<std::endl;
        for(int i = 0; i < parovi_slicnih.size(); i++){
            parovi_slicnih[i].first->Ispisi();
            std::cout<<" i ";
            parovi_slicnih[i].second->Ispisi();
            std::cout<<std::endl;
        }
    }
    else {
        std::cout<< "Nema slicnih trouglova!" << std::endl;
    }
    
	return 0;
}