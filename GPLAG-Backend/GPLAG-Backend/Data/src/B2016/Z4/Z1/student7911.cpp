/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <utility>
#include <cmath>
#include <stdexcept>
#include <vector>
#include <memory>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::pair;
using std::range_error;
using std::domain_error;
using std::sqrt;
using std::acos;
using std::abs;
using std::cos;
using std::sin;
using std::fabs;
using std::vector;
using std::make_pair;
using std::shared_ptr;
using std::make_shared;
using std::transform;
using std::sort;
using std::for_each;
using std::min_element;

typedef std::pair<double, double> Tacka;

double TestOrijentacije  (const Tacka &t1, const Tacka &t2, const Tacka &t3){
        return (t1.first*(t2.second - t3.second) - t2.first*(t1.second - t3.second) + t3.first*(t1.second - t2.second));
        
    }
    
    void TestIndeksa(int indeks)  {
        if(indeks < 1 || indeks > 3)
        throw range_error("Nekorektan indeks!");
    }
    
    double DuzinaStranice (const Tacka &t1, const Tacka &t2){
        return sqrt((t1.first-t2.first)*(t1.first-t2.first)+(t1.second-t2.second)*(t1.second-t2.second));
    }
    
    Tacka Teziste (const Tacka &t1, const Tacka &t2, const Tacka &t3){
        
        Tacka centar;
        centar.first = (t1.first + t2.first + t3.first)/3;
        centar.second = (t1.second + t2.second + t3.second)/3;
        
        return centar;
        
    }
    
bool UporediRealne(double x, double y){
    const double eps(1e-10);
    if(fabs(x-y) <= eps*(fabs(x)+fabs(y)))return 1;
    return 0;
}

class Trougao{
    Tacka m[3];
    
    
    
   
    public:
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        
        int tmp;
        tmp = TestOrijentacije(t1,t2,t3);
        if(UporediRealne(tmp,0))throw domain_error("Nekorektne pozicije tjemena");
        
        m[0] = t1; 
        m[1] = t2;
        m[2] = t3;
        
    }
    
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        int tmp;
        tmp = TestOrijentacije(t1,t2,t3);
        if(UporediRealne(tmp,0))throw domain_error("Nekorektne pozicije tjemena");
        
        m[0] = t1; 
        m[1] = t2;
        m[2] = t3;
        
    }
    
    void Postavi(int indeks, const Tacka &t){
        TestIndeksa(indeks);
        const double eps(1e-10);

        if(fabs(indeks)<=eps*fabs(indeks)){
            double x = TestOrijentacije(m[1],m[2],t);
            if(fabs(x) <= eps*fabs(x))throw domain_error("Nekorektne pozicije tjemena");
        }
        //fabs(x-y) <= eps*(fabs(x)+fabs(y))
         if(fabs(indeks-1) <= eps*(fabs(indeks)+fabs(1))){
             double x = TestOrijentacije(m[0],m[2],t);
            if(fabs(x) <= eps*fabs(x))throw domain_error("Nekorektne pozicije tjemena");
        }
        
         if(fabs(indeks-2) <= eps*(fabs(indeks)+fabs(2))){
             double x = TestOrijentacije(m[1],m[0],t);
            if(fabs(x) <= eps*fabs(x))throw domain_error("Nekorektne pozicije tjemena");
        }
        
        
        m[indeks-1] = t;
        
    }
    
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3){
         double tmp;
         tmp = TestOrijentacije(t1,t2,t3);
        if(tmp>0)return 1;
        else if(tmp<0)return -1;
        else if(UporediRealne(tmp,0))return 0;
    }
    
    Tacka DajTjeme(int indeks) const{ return m[indeks-1];}
    
    double DajStranicu(int indeks) const{
        TestIndeksa(indeks);
        if(indeks-1 == 0)return DuzinaStranice(m[1],m[2]);
        else if(indeks-1 == 1) return DuzinaStranice(m[0],m[2]);
        else if(indeks-1==2)return DuzinaStranice(m[0],m[1]);
    }
    
    double DajUgao(int indeks) const{
        TestIndeksa(indeks);
        double a = DuzinaStranice(m[1],m[2]);
        double b = DuzinaStranice(m[0],m[2]);
        double c = DuzinaStranice(m[0],m[1]);
        
        if(indeks-1 == 0) return acos((b*b+c*c-a*a)/(2*c*b));
        else if(indeks-1 == 1) return acos((a*a+c*c-b*b)/(2*a*c));
        else if(indeks-1 == 2) return acos((a*a+b*b-c*c)/(2*a*b));
    }
    
    Tacka DajCentar() const{
        return Teziste(m[0],m[1],m[2]);
    }
    
    double DajObim() const{
        double a = DuzinaStranice(m[1],m[2]);
        double b = DuzinaStranice(m[0],m[2]);
        double c = DuzinaStranice(m[0],m[1]);
        
        return a+b+c;
    }
    
    double DajPovrsinu() const{
        double tmp = TestOrijentacije(m[0],m[1],m[2]);
        return (1./2)*abs(tmp);
    }
    
    bool DaLiJePozitivnoOrijentiran() const{
        double tmp = TestOrijentacije(m[0],m[1],m[2]);
        if(tmp>0)return 1;
        return 0;
    }
    
    bool DaLiJeUnutra(const Tacka &t) const{
        double uslov1 = TestOrijentacije(m[0], m[1], m[2]);
        double uslov2 = TestOrijentacije(m[0], m[1], t);
        double uslov3 = TestOrijentacije(m[1], m[2], t);
        double uslov4 = TestOrijentacije(m[2], m[0], t);
        
        if((uslov1>0 && uslov2>0 && uslov3>0 && uslov4>0)||(uslov1<0 && uslov2<0 && uslov3<0 && uslov4<0))return true;
        return false;
    }


    void Ispisi() const{
        cout<<"(("<<m[0].first<<","<<m[0].second<<"),("<<m[1].first<<","<<m[1].second<<"),("<<m[2].first<<","<<m[2].second<<"))";
    }
    
    void Transliraj(double delta_x, double delta_y){
        m[0].first = m[0].first+delta_x;
        m[1].first = m[1].first+delta_x;
        m[2].first = m[2].first+delta_x;
        
        m[0].second = m[0].second+delta_y;
        m[1].second = m[1].second+delta_y;
        m[2].second = m[2].second+delta_y;
        
    }
    
    void Centriraj(const Tacka &t){
        Tacka centar;
        centar = Teziste(m[0],m[1],m[2]);
        double delta_x = t.first - centar.first;
        double delta_y = t.second - centar.second;
        
        m[0].first = m[0].first+delta_x;
        m[1].first = m[1].first+delta_x;
        m[2].first = m[2].first+delta_x;
        
        m[0].second = m[0].second+delta_y;
        m[1].second = m[1].second+delta_y;
        m[2].second = m[2].second+delta_y;
        
    }
    
    void Rotiraj(const Tacka &t, double ugao){
        
        m[0].first =  t.first + (m[0].first - t.first)*cos(ugao) - (m[0].second - t.second)*sin(ugao);
        m[0].second = t.second + (m[0].first - t.first)*sin(ugao) + (m[0].second - t.second)*cos(ugao);
        
        m[1].first =  t.first + (m[1].first - t.first)*cos(ugao) - (m[1].second - t.second)*sin(ugao);
        m[1].second = t.second + (m[1].first - t.first)*sin(ugao) + (m[1].second - t.second)*cos(ugao);
        
        m[2].first =  t.first + (m[2].first - t.first)*cos(ugao) - (m[2].second - t.second)*sin(ugao);
        m[2].second = t.second + (m[2].first - t.first)*sin(ugao) + (m[2].second - t.second)*cos(ugao);
    
    }
    
    void Skaliraj(const Tacka &t, double faktor){
        

        if(UporediRealne(faktor,0))throw domain_error("Nekorektan faktor skaliranja");
        
        m[0].first = t.first + faktor*(m[0].first - t.first);
        m[0].second = t.second + faktor*(m[0].second - t.second);
        
        m[1].first = t.first + faktor*(m[1].first - t.first);
        m[1].second = t.second + faktor*(m[1].second - t.second);
        
        m[2].first = t.first + faktor*(m[2].first - t.first);
        m[2].second = t.second + faktor*(m[2].second - t.second);
        
    }
    
    void Rotiraj(double ugao){
        
        Tacka t = DajCentar();
        Tacka d1,d2,d3;
        d1.first = m[0].first;
        d1.second = m[0].second;
        m[0].first =  t.first + (d1.first - t.first)*cos(ugao) - (d1.second - t.second)*sin(ugao);
        m[0].second = t.second + (d1.first - t.first)*sin(ugao) + (d1.second - t.second)*cos(ugao);
        
        d2.first = m[1].first;
        d2.second = m[1].second;
        m[1].first =  t.first + (d2.first - t.first)*cos(ugao) - (d2.second - t.second)*sin(ugao);
        m[1].second = t.second + (d2.first - t.first)*sin(ugao) + (d2.second - t.second)*cos(ugao);
        
         d3.first = m[2].first;
        d3.second = m[2].second;
        m[2].first =  t.first + (d3.first - t.first)*cos(ugao) - (d3.second - t.second)*sin(ugao);
        m[2].second = t.second + (d3.first - t.first)*sin(ugao) + (d3.second - t.second)*cos(ugao);
    
    }
    
    void Skaliraj(double faktor){
        
        Tacka t = DajCentar();
        
        m[0].first = t.first + faktor*(m[0].first - t.first);
        m[0].second = t.second + faktor*(m[0].second - t.second);
        
        m[1].first = t.first + faktor*(m[1].first - t.first);
        m[1].second = t.second + faktor*(m[1].second - t.second);
        
        m[2].first = t.first + faktor*(m[2].first - t.first);
        m[2].second = t.second + faktor*(m[2].second - t.second);
        
    }
    
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2){
        int brojac = 0;
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
               
                if((UporediRealne(t1.m[i].first, t2.m[j].first))&&(UporediRealne(t1.m[i].second, t2.m[j].second)))brojac++;
        }
        
        
    }
    
    if(brojac == 3)return true;
        return false;
    }
    
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2){
        vector<pair<double,double>> ugstr1(3),ugstr2(3);//par ugao stranica, podudarni isti im ugl i str
        
        if(DaLiSuIdenticni(t1,t2))return 1;
        
        for(int i=0; i<3; i++){
            ugstr1[i] = make_pair(t1.DajStranicu(i+1),t1.DajUgao(i+1));
            ugstr2[i] = make_pair(t2.DajStranicu(i+1),t2.DajUgao(i+1));
        }
        //Provjera da li je trougao jkk ili jdstr
        bool jkk = 0;
        for(int i=0; i<3; i++){
            int brojac = 0;
            for(int j=0; j<3; j++){
                if((UporediRealne(ugstr1[i].first,ugstr2[j].first))&&(UporediRealne(ugstr1[i].second,ugstr2[j].second)))brojac++;
            }
            if(brojac>=2){jkk = 1;break;}
            else continue;
        }
        
        if(jkk){
            
            int brojac = 0;
        for(int i=0; i<3; i++){
            for(int j=0; j<ugstr2.size(); j++){
                
                if((UporediRealne(ugstr1[i].first,ugstr2[j].first))&&(UporediRealne(ugstr1[i].second,ugstr2[j].second))){
                    brojac++;
                    
                    ugstr2.erase(ugstr2.begin()+j);
                    j--;
                }
            }
        }
        
        if(brojac == 3)return true;
        else return false;
            
        }
        else if(!jkk){
        
        //Pamcenje indeksa
        vector<int> zapamti;
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if((UporediRealne(ugstr1[i].first,ugstr2[j].first))&&(UporediRealne(ugstr1[i].second,ugstr2[j].second))){
                    zapamti.push_back(j);
                }
            }
        }
        
        int brojac = 0;
        for(int i=0; i<3; i++){
            for(int j=0; j<ugstr2.size(); j++){
                
                if((UporediRealne(ugstr1[i].first,ugstr2[j].first))&&(UporediRealne(ugstr1[i].second,ugstr2[j].second))){
                    brojac++;
                    
                    ugstr2.erase(ugstr2.begin()+j);
                    j--;
                }
            }
        }
        
        if(brojac == 3){
            int x = Orijentacija(t1.m[0],t1.m[1],t1.m[2]);
            int y = Orijentacija(t2.m[zapamti[0]], t2.m[zapamti[1]], t2.m[zapamti[2]]);
            if(x==y)return true;
            else return false;
        }
        else return false;
        
        }
    }
    
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2){
        //slicni isti im ugl
        
            if(DaLiSuIdenticni(t1,t2))return 1;
            vector<double> uglovi1(3),uglovi2(3);
            
            for(int i=0; i<3; i++){
                uglovi1[i] = t1.DajUgao(i+1);
                uglovi2[i] = t2.DajUgao(i+1);
            }
            
            bool jkk = 0;
        for(int i=0; i<3; i++){
            int brojac = 0;
            for(int j=0; j<3; j++){
                if((UporediRealne(uglovi1[i],uglovi2[j])))brojac++;
            }
            if(brojac>=2){jkk = 1;break;}
            else continue;
        }
        
        if(jkk){
            
            int brojac = 0;
            for(int i=0; i<3; i++){
                for(int j=0; j<uglovi2.size(); j++){
                    
                    if(UporediRealne(uglovi1[i],uglovi2[j])){
                        brojac++;
                        
                        uglovi2.erase(uglovi2.begin()+j);
                        
                        j--;
                    }
                }
            }
            
            
        
        if(brojac == 3)return true;
        else return false;
            
            
        }
        else{
            
            vector<int> zapamti;
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if((UporediRealne(uglovi1[i],uglovi2[j]))){
                    zapamti.push_back(j);
                }
            }
        }
            
            int brojac =0;
            for(int i=0; i<3; i++){
                for(int j=0; j<uglovi2.size(); j++){
                    
                    if(UporediRealne(uglovi1[i],uglovi2[j])){
                        brojac++;
                        
                        uglovi2.erase(uglovi2.begin()+j);
                        
                        j--;
                    }
                }
            }
            
            if(brojac == 3){
                int x = Orijentacija(t1.m[0],t1.m[1],t1.m[2]);
            int y = Orijentacija(t2.m[zapamti[0]], t2.m[zapamti[1]], t2.m[zapamti[2]]);
            if(x==y)return true;
            else return false;
            }
            else return false;
        
        }
        
    }

    

    
};
int main ()
{
     try{   
        cout<<"Koliko zelite kreirati trouglova: ";
        int n;
        cin>>n;
        
        vector<shared_ptr<Trougao>> v;
        
        for(int i=0; i<n; i++){
            cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
            double x1, y1, x2, y2, x3, y3;
            cin>>x1>>y1>>x2>>y2>>x3>>y3;
            Tacka t1 = make_pair(x1,y1);
            Tacka t2 = make_pair(x2,y2);
            Tacka t3 = make_pair(x3,y3);
            shared_ptr<Trougao> p;
            try{
                p = make_shared<Trougao>(t1,t2,t3);
                
            }
            catch(domain_error e){
                cout<<e.what()<< ", ponovite unos!" <<endl;
                i--;
                continue;
            }
            v.push_back(p);
            
        }
        
        cout<<"Unesite vektor translacije (dx dy): ";
        double dx, dy; cin>>dx>>dy;
        
        transform(v.begin(), v.begin()+n, v.begin(), [dx,dy](shared_ptr<Trougao> a){ (*a).Transliraj(dx,dy); return a;});
        
        cout<<"Unesite ugao rotacije: ";
        double ugao; cin>>ugao; 
        
        transform(v.begin(), v.begin()+n,v.begin(), [ugao](shared_ptr<Trougao> a){ (*a).Rotiraj(ugao);return a;});
       
        
        cout<<"Unesite faktor skaliranja: ";
        double faktor; cin>>faktor;
         transform(v.begin(), v.begin()+n,v.begin(), [faktor](shared_ptr<Trougao> a){(*a).Skaliraj((*a).DajTjeme(1),faktor);return a;});
         
         sort(v.begin(), v.begin()+n, [](shared_ptr<Trougao> a, shared_ptr<Trougao> b){
             if((*a).DajPovrsinu()<(*b).DajPovrsinu())return 1; else return 0;});
             
             cout<<"Trouglovi nakon obavljenih transformacija: "<<endl;
        for_each(v.begin(), v.begin()+n, [](shared_ptr<Trougao> a){(*a).Ispisi(); cout<<endl;});
        
        
        cout<<"Trougao sa najmanjim obimom: ";
       auto p =  min_element(v.begin(), v.begin()+n, [](shared_ptr<Trougao> a,shared_ptr<Trougao> b){return (*a).DajObim()<(*b).DajObim();});
        
        (*p)->Ispisi();
        
        cout<<endl;
        int brojac =0;
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                if(DaLiSuIdenticni(*v[i],*v[j])){ brojac++;}
            }
        }
        
        
        if(brojac==0)cout<<"Nema identicnih trouglova!"<<endl;
        else{
            cout<<"Parovi identicnih trouglova: "<<endl;
        
        brojac=0;
         for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                if(DaLiSuIdenticni(*v[i],*v[j])){(*v[i]).Ispisi(); cout<<" i "; (*v[j]).Ispisi();cout<<endl; brojac++;}
            }
        }
            
        }
        
        brojac=0;
         for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                if(DaLiSuPodudarni(*v[i],*v[j])){brojac++;}
            }
        }
        
        if(brojac==0)cout<<"Nema podudarnih trouglova!"<<endl;
        else{
            cout<<"Parovi podudarnih trouglova: "<<endl;
         brojac=0;
         for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                if(DaLiSuPodudarni(*v[i],*v[j])){(*v[i]).Ispisi(); cout<<" i "; (*v[j]).Ispisi();cout<<endl; brojac++;}
            }
        }
            
        }
        
        
        brojac=0;
         for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                if(DaLiSuSlicni(*v[i],*v[j])){brojac++;}
            }
        }
        
        if(brojac==0)cout<<"Nema slicnih trouglova!"<<endl;
        else{
            cout<<"Parovi slicnih trouglova: "<<endl;
         brojac=0;
         for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                if(DaLiSuSlicni(*v[i],*v[j])){(*v[i]).Ispisi(); cout<<" i "; (*v[j]).Ispisi();cout<<endl; brojac++;}
            }
        }
            
        }
     }
     catch(domain_error e){
         cout<<e.what();
         
     }
     catch(range_error t){
         cout<<t.what();
     } 
    
    
    
	return 0;
}