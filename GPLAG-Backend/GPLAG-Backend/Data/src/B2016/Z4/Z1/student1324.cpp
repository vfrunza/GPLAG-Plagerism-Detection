/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <utility>
#include <memory>
#include <algorithm>
#include <vector>
#include <stdexcept>
#include <cmath>

typedef std::pair<double,double> Tacka;

class Trougao{
        std::vector<Tacka>v{3};
        void TestIndeksa(int indeks) const {
            if(indeks<1 || indeks>3)throw std::range_error("Nekorektan indeks");
        }
        static double Izraz(const Tacka &t1,const Tacka &t2, const Tacka &t3) {
            return t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second);
            
        }
        double Duzina(const Tacka &t1, const Tacka &t2) const {
            return std::sqrt(pow(t2.first-t1.first,2)+pow(t2.second-t1.second,2));
        }
        double Ugao(double a,double b, double c) const {
            return std::acos((b*b+c*c-a*a) / (2*b*c));
        }
        double Povrsina(const Tacka &t1,const Tacka &t2, const Tacka &t3) const {
            return (1./2)*std::fabs(Izraz(t1,t2,t3));
        }
    public:
        Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3){
            if(!Orijentacija(t1,t2,t3))throw std::domain_error("Nekorektne pozicije tjemena");
            v[0]=t1; v[1]=t2; v[2]=t3;
        }
        void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3){
            if(!Orijentacija(t1,t2,t3))throw std::domain_error("Nekorektne pozicije tjemena");
            v[0]=t1; v[1]=t2; v[2]=t3;
        }
        void Postavi(int indeks, const Tacka &t){
            try{
                TestIndeksa(indeks);
                if(indeks-1==0 && !Orijentacija(t,v[1],v[2]))throw std::domain_error("Nekorektne pozicije tjemena");
                if(indeks-1==1 && !Orijentacija(v[0],t,v[2]))throw std::domain_error("Nekorektne pozicije tjemena");
                if(indeks-1==2 && !Orijentacija(v[0],v[1],t))throw std::domain_error("Nekorektne pozicije tjemena");
                v[indeks-1]=t;
            }
            catch(...){
                throw;
            }
        }
        static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3){
            if(Izraz(t1,t2,t3)>0)return 1;
            if(Izraz(t1,t2,t3)==0)return 0;
            else return -1;
        }
        Tacka DajTjeme(int indeks) const { 
            try{
                TestIndeksa(indeks);
                return v[indeks-1]; 
            }
            catch(...){
                throw;
            }   
        }
        double DajStranicu(int indeks) const {
            try{
                TestIndeksa(indeks);
                if(indeks-1==0) return Duzina(v[1],v[2]);
                if(indeks-1==1) return Duzina(v[0],v[2]);
                else return Duzina(v[0],v[1]);
            }
            catch(...){
                throw;
            }
        }
        double DajUgao(int indeks) const{
            try{
                TestIndeksa(indeks);
                if(indeks-1==0) return Ugao(Duzina(v[1],v[2]), Duzina(v[0],v[1]), Duzina(v[0],v[2]));
                if(indeks-1==1) return Ugao(Duzina(v[0],v[2]), Duzina(v[0],v[1]), Duzina(v[1],v[2]));
                if(indeks-1==2) return Ugao(Duzina(v[0],v[1]),Duzina(v[1],v[2]), Duzina(v[0],v[2]) );
            }
            catch(...){
                throw;
            }
        }
        Tacka DajCentar() const {
            return std::make_pair( (v[0].first+v[1].first+v[2].first)/3 , (v[0].second+v[1].second+v[2].second)/3 );
        }
        double DajObim() const {
            return Duzina(v[0],v[1])+Duzina(v[1],v[2])+Duzina(v[0],v[2]);
        }
        double DajPovrsinu() const{
            return Povrsina(v[0],v[1],v[2]);
        }
        bool DaLiJePozitivnoOrijentiran() const{
            if(Orijentacija(v[0],v[1],v[2])==1)return true;
            else return false;
            
        }
        bool DaLiJeUnutra(const Tacka &t) const {
            if(DajPovrsinu()==Povrsina(t,v[1],v[2])+Povrsina(v[0],t,v[2])+Povrsina(v[0],v[1],t))return true;
            else return false;
        }
        void Ispisi() const{
            std::cout << "((" << v[0].first << "," << v[0].second << "),(" << v[1].first << "," << v[1].second << "),(" << v[2].first << "," << v[2].second << "))";
        }
        void Transliraj(double delta_x, double delta_y){
            for(int i=0;i<3;i++){
                v[i].first+=delta_x;
                v[i].second+=delta_y;
            }    
        }
        void Centriraj(const Tacka &t){
            Tacka t1(DajCentar());
            Transliraj(t1.first-t.first,t1.second-t.second);
        }
        void Rotiraj(const Tacka &t, double ugao){
            for(int i=0;i<3;i++) {
                v[i]=std::make_pair(t.first+(v[i].first-t.first)*std::cos(ugao)-(v[i].second-t.second)*std::sin(ugao), t.second+(v[i].first-t.first)*std::sin(ugao)+(v[i].second-t.second)*std::cos(ugao));
            }
        }
        void Skaliraj(const Tacka &t, double faktor){
            if(faktor==0)throw std::domain_error("Nekorektan faktor skaliranja");
            for(int i=0;i<3;i++)
                v[i]=std::make_pair(t.first+faktor*(v[i].first-t.first),t.second+faktor*(v[i].second-t.second));
        }
        void Rotiraj(double ugao){
            Rotiraj(DajCentar(),ugao);
        }
        void Skaliraj(double faktor){
            Skaliraj(DajCentar(),faktor);
        }
        friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
        friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
        friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);
};

bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2){
    bool flag(false);
    for(int i=1;i<4;i++){
        int br(0);
        for(int j=1;j<4;j++)if(t1.DajTjeme(i)==t2.DajTjeme(j))br++;
        if(br)flag=true;
        else return false;
    }
    return flag;
}

bool DaLiSuPodudarni(const Trougao &t1,const Trougao &t2){
    bool flag(false);
    int ind[6];
    int br1(0);
        for(int i=1;i<4;i++){
            int br(0);
            for(int j=1;j<4;j++) if(t1.DajStranicu(i)==t2.DajStranicu(j)){
                ind[br1]=i; ind[++br1]=j;
                br++; br1++;
            }    
            if(br)flag=true;
            else return false;
        }
    if(Trougao::Orijentacija(t1.DajTjeme(ind[0]),t1.DajTjeme(ind[2]),t1.DajTjeme(ind[4]))==Trougao::Orijentacija(t2.DajTjeme(ind[1]),t2.DajTjeme(ind[3]),t2.DajTjeme(ind[5])))flag=true;
    else flag=false;
    
    return flag;
    
}

bool DaLiSuSlicni(const Trougao &t1,const Trougao &t2){
    bool flag(false);
    int ind[6];
    int br1(0);
        for(int i=1;i<4;i++){
            int br(0);
            for(int j=1;j<4;j++) if(t1.DajUgao(i)==t2.DajUgao(j)){
                ind[br1]=i; ind[++br1]=j;
                br++; br1++;
            }    
            if(br)flag=true;
            else return false;
        }
    if(Trougao::Orijentacija(t1.DajTjeme(ind[0]),t1.DajTjeme(ind[2]),t1.DajTjeme(ind[4]))==Trougao::Orijentacija(t2.DajTjeme(ind[1]),t2.DajTjeme(ind[3]),t2.DajTjeme(ind[5])))flag=true;
    else flag=false;
    
    return flag;
}

int main ()
{
    int n(0);
    std::cout << "Koliko zelite kreirati trouglova: " ;
    std::cin >> n;
    
        std::vector<std::shared_ptr<Trougao>> v1;
        
        for(int i=0;i<n;i++){
            int x1,y1,x2,y2,x3,y3;
            std::cout << "Unesite podatke za " << i+1 << ". trougao (x1 y1 x2 y2 x3 y3): ";
            std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
                Tacka T1=std::make_pair(x1,y1);
                Tacka T2=std::make_pair(x2,y2);
                Tacka T3=std::make_pair(x3,y3);
                    try{
                        v1.push_back(std::make_shared<Trougao>(Trougao(T1,T2,T3)));
                    }
                    catch(std::domain_error e){
                        std::cout << e.what() << ", ponovite unos!" << std::endl;
                        i--;
                    }
        }
            
            int dx,dy;
            std::cout << "Unesite vektor translacije (dx dy): ";
            std::cin >> dx >> dy;
                std::transform(v1.begin(),v1.end(),v1.begin(),[dx,dy](std::shared_ptr<Trougao> t){t->Transliraj(dx,dy);return t;});
                
                double ugao;
                std::cout << "Unesite ugao rotacije: " ;   
                std::cin >> ugao;
                
                int faktor;
                std::cout << "Unesite faktor skaliranja: ";
                std::cin >> faktor;
                try{
                    std::transform(v1.begin(),v1.end(),v1.begin(),[ugao,faktor](std::shared_ptr<Trougao> t){ t->Rotiraj(ugao); t->Skaliraj(t->DajTjeme(1),faktor); return t;});
                }
                catch(std::domain_error e){
                    std::cout << e.what() << std::endl;
                }
                std::sort(v1.begin(),v1.end(),[](const std::shared_ptr<Trougao> &t1,const std::shared_ptr<Trougao> &t2){return t1->DajPovrsinu()<t2->DajPovrsinu();});
                
                std::cout << "Trouglovi nakon obavljenih transformacija:" << std::endl;
                std::for_each(v1.begin(),v1.end(),[](std::shared_ptr<Trougao> t){t->Ispisi();std::cout << std::endl;});
                
                    std::cout << "Trougao sa najmanjim obimom: ";
                    auto i=std::min_element(v1.begin(),v1.end(),[](const std::shared_ptr<Trougao> &t1,const std::shared_ptr<Trougao> &t2){ return t1->DajObim()<t2->DajObim();});
                    (*i)->Ispisi(); std::cout << std::endl;
                    
                    int flag(0);
                    for(int i=0;i<v1.size();i++)
                        for(int j=i+1;j<v1.size();j++)
                            if(DaLiSuIdenticni(*v1[i],*v1[j])) flag=1;
                    if(flag){ 
                        std::cout << "Parovi identicnih trouglova:" << std::endl;
                        for(int i=0;i<v1.size();i++){
                            for(int j=i+1;j<v1.size();j++){
                                if(DaLiSuIdenticni(*v1[i],*v1[j])){
                                    v1[i]->Ispisi();
                                    std::cout << " i ";
                                    v1[j]->Ispisi();
                                    std::cout << std::endl;
                                }
                            }
                        }
                    }
                    else std::cout << "Nema identicnih trouglova!"<< std::endl;
                    
                    flag=0;
                    for(int i=0;i<v1.size();i++)
                        for(int j=i+1;j<v1.size();j++)
                            if(DaLiSuPodudarni(*v1[i],*v1[j])) flag=1;
                    if(flag){ 
                           std::cout << "Parovi podudarnih trouglova:" << std::endl;
                            for(int i=0;i<v1.size();i++){
                                for(int j=i+1;j<v1.size();j++){
                                    if(DaLiSuPodudarni(*v1[i],*v1[j])){
                                        v1[i]->Ispisi();
                                        std::cout << " i ";
                                        v1[j]->Ispisi();
                                        std::cout << std::endl;
                                    }
                                }
                            }
                    }
                    else std::cout << "Nema podudarnih trouglova!" << std::endl;
                    
            flag=0;
            for(int i=0;i<v1.size();i++)
                for(int j=i+1;j<v1.size();j++)
                    if(DaLiSuSlicni(*v1[i],*v1[j])) flag=1;
                if(flag){ 
                    std::cout << "Parovi slicnih trouglova:" << std::endl;  
                    for(int i=0;i<v1.size();i++){
                        for(int j=i+1;j<v1.size();j++){
                            if(DaLiSuSlicni(*v1[i],*v1[j])){
                                v1[i]->Ispisi();
                                std::cout << " i ";
                                v1[j]->Ispisi();
                                std::cout << std::endl;
                            }
                        }
                    }
                }
     
                else std::cout << "Nema slicnih trouglova!" << std::endl;
    return 0;                    
}
