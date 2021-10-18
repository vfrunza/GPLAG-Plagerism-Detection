/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <utility>
#include <cmath>
#include <vector>
#include <memory>
#include <algorithm>
#include <map>

using namespace std;

typedef pair<double,double> Tacka;
const double pi=4.*atan(1);

class Trougao {
    Tacka x1,x2,x3;
    static bool Jednaki(double x,double y);
    static bool Jednaki(Tacka p, Tacka q);
    public:
    Trougao (const Tacka &t1,const Tacka &t2,const Tacka &t3){
        if(Orijentacija(t1,t2,t3)==0)throw domain_error ("Nekorektne pozicije tjemena");
        x1=t1;x2=t2;x3=t3;
    }
    void Postavi(const Tacka &t1,const Tacka &t2,const Tacka &t3){
        if(Orijentacija(t1,t2,t3)==0) throw domain_error("Nekorektne pozicije tjemena");
        x1=t1;x2=t2;x3=t3;
    }
    void Postavi(int indeks,const Tacka &t);
    static int Orijentacija(const Tacka &t1,const Tacka &t2,const Tacka &t3);
    Tacka DajTjeme(int indeks) const;
    double DajStranicu(int indeks) const;
    double DajUgao(int indeks) const;
    Tacka DajCentar() const {Tacka t; t=make_pair((x1.first+x2.first+x3.first)/3,(x1.second+x2.second+x3.second)/3);return t;}
    double DajObim() const {double obim;obim=DajStranicu(1)+DajStranicu(2)+DajStranicu(3);return obim;}
    double DajPovrsinu()const;
    bool DaLiJePozitivnoOrijentiran() const;
    bool DaLiJeUnutra(const Tacka &t) const;
    void Ispisi() const;
    void Transliraj(double delta_x,double delta_y);
    void Centriraj (const Tacka &t);
    void Rotiraj(const Tacka &t,double ugao);
    void Skaliraj(const Tacka &t,double faktor);
    void Rotiraj(double ugao);
    void Skaliraj(double faktor);
    friend bool DaLiSuIdenticni(const Trougao &t1,const Trougao &t2);
    friend bool DaLiSuPodudarni(const Trougao &t1,const Trougao &t2);
    friend bool DaLiSuSlicni(const Trougao &t1,const Trougao &t2);
    
};
bool Trougao::Jednaki(Tacka p,Tacka q){
    if(Jednaki(p.first,q.first) && Jednaki(p.second,q.second))return true;
    return false;
}
bool Trougao::Jednaki(double x,double y){
    const double eps(1e-10);
    if(fabs(x-y)<=eps*(fabs(x)+fabs(y)))return true;
    return false;
}
inline void Trougao::Postavi(int indeks,const Tacka &t){
    if(indeks!=1 && indeks!=2 && indeks!=3)throw range_error("Nekorektan indeks");
    if(indeks==1)x1=t;
    if(indeks==2)x2=t;
    if(indeks==3)x3=t;
}
int Trougao::Orijentacija(const Tacka &t1,const Tacka &t2,const Tacka &t3){
    double rezultat=t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second);
    if(rezultat<=-1)return -1;
    if(rezultat>=1)return 1;
    return 0;
}
inline Tacka Trougao::DajTjeme(int indeks) const {
    if(indeks!=1 && indeks!=2 && indeks!=3)throw range_error("Nekorektan indeks");
    if(indeks==1)return x1;
    if(indeks==2)return x2;
    return x3;
}
double Trougao::DajStranicu(int indeks) const {
    if(indeks!=1 && indeks!=2 && indeks!=3)throw range_error("Nekorektan indeks");
    if(indeks==1)return sqrt((x3.first-x2.first)*(x3.first-x2.first)+(x3.second-x2.second)*(x3.second-x2.second));
    if(indeks==2)return sqrt((x3.first-x1.first)*(x3.first-x1.first)+(x3.second-x1.second)*(x3.second-x1.second));
    return sqrt((x1.first-x2.first)*(x1.first-x2.first)+(x1.second-x2.second)*(x1.second-x2.second));
}
double Trougao::DajUgao(int indeks) const {
    if(indeks!=1 && indeks!=2 && indeks!=3)throw range_error("Nekorektan indeks");
    double ugao;
    if(indeks==1){ugao=acos((DajStranicu(2)*DajStranicu(2)+DajStranicu(3)*DajStranicu(3)-DajStranicu(1)*DajStranicu(1))/(2*DajStranicu(2)*DajStranicu(3)));return ugao;}
    if(indeks==2){ugao=acos((DajStranicu(1)*DajStranicu(1)+DajStranicu(3)*DajStranicu(3)-DajStranicu(2)*DajStranicu(2))/(2*DajStranicu(1)*DajStranicu(3)));return ugao;}
    ugao=acos((DajStranicu(1)*DajStranicu(1)+DajStranicu(2)*DajStranicu(2)-DajStranicu(3)*DajStranicu(3))/(2*DajStranicu(1)*DajStranicu(2)));return ugao;
}

inline double Trougao::DajPovrsinu() const{
    return fabs(x1.first*(x2.second-x3.second)-x2.first*(x1.second-x3.second)+x3.first*(x1.second-x2.second))/2;
}
bool Trougao::DaLiJePozitivnoOrijentiran() const {
    if(Orijentacija(x1,x2,x3)==-1 || Orijentacija(x1,x2,x3)==0)return false;
    return true;
}
bool Trougao::DaLiJeUnutra(const Tacka &t) const {
if(Orijentacija(x1,x2,x3)==Orijentacija(x1,x2,t) && Orijentacija(x1,x2,x3)==Orijentacija(x2,x3,t) && Orijentacija(x1,x2,x3)==Orijentacija(x3,x1,t))return true;
return false;
}
inline void Trougao:: Ispisi() const {
    cout<<"(("<<x1.first<<","<<x1.second<<"),("<<x2.first<<","<<x2.second<<"),("<<x3.first<<","<<x3.second<<"))";
}
void Trougao::Transliraj(double delta_x,double delta_y){
    x1.first+=delta_x;x1.second+=delta_y;
    x2.first+=delta_x;x2.second+=delta_y;
    x3.first+=delta_x;x3.second+=delta_y;
}
void Trougao::Centriraj(const Tacka &t){
    Tacka teziste;
    teziste.first=(x1.first+x2.first+x3.first)/3;
    teziste.second=(x1.second+x2.second+x3.second)/3;
    double delta_x,delta_y;
    delta_x=teziste.first-t.first;
    delta_y=teziste.second-t.second;
    Transliraj(delta_x,delta_y);
}
void Trougao::Rotiraj(const Tacka &t,double ugao){
    //double ugao=ugao*pi/180;
    Tacka x1_st(x1),x2_st(x2),x3_st(x3);
    x1.first=t.first+(x1_st.first-t.first)*cos(ugao)-(x1_st.second-t.second)*sin(ugao);
    x1.second=t.second+(x1_st.first-t.first)*sin(ugao)+(x1_st.second-t.second)*cos(ugao);
    x2.first=t.first+(x2_st.first-t.first)*cos(ugao)-(x2_st.second-t.second)*sin(ugao);
    x2.second=t.second+(x2_st.first-t.first)*sin(ugao)+(x2_st.second-t.second)*cos(ugao);
    x3.first=t.first+(x3_st.first-t.first)*cos(ugao)-(x3_st.second-t.second)*sin(ugao);
    x3.second=t.second+(x3_st.first-t.first)*sin(ugao)+(x3_st.second-t.second)*cos(ugao);
}

void Trougao::Skaliraj(const Tacka &t,double faktor){
    if(faktor==0.)throw domain_error("Nekorektan faktor skaliranja");
    x1.first=t.first+faktor*(x1.first-t.first);x1.second=t.second+faktor*(x1.second-t.second);
    x2.first=t.first+faktor*(x2.first-t.first);x2.second=t.second+faktor*(x2.second-t.second);
    x3.first=t.first+faktor*(x3.first-t.first);x3.second=t.second+faktor*(x3.second-t.second);
}
void Trougao::Rotiraj(double ugao){
    Rotiraj(DajCentar(),ugao);
}
void Trougao::Skaliraj(double faktor){
    Tacka teziste;
    teziste.first=(x1.first+x2.first+x3.first)/3;teziste.second=(x1.second+x2.second+x3.second)/3;
    Skaliraj(teziste,faktor);
}
bool DaLiSuIdenticni(const Trougao &t1,const Trougao &t2){
    if((Trougao::Jednaki(t1.DajTjeme(1),t2.DajTjeme(1)) || Trougao::Jednaki(t1.DajTjeme(1),t2.DajTjeme(2)) || Trougao::Jednaki(t1.DajTjeme(1),t2.DajTjeme(3))) && (Trougao::Jednaki(t1.DajTjeme(2),t2.DajTjeme(1)) || Trougao::Jednaki(t1.DajTjeme(2),t2.DajTjeme(2)) || Trougao::Jednaki(t1.DajTjeme(2),t2.DajTjeme(3))) && (Trougao::Jednaki(t1.DajTjeme(3),t2.DajTjeme(1)) || Trougao::Jednaki(t1.DajTjeme(3),t2.DajTjeme(2)) || Trougao::Jednaki(t1.DajTjeme(3),t2.DajTjeme(3))))return true;
    return false;
}
bool DaLiSuPodudarni(const Trougao &t1,const Trougao &t2){
    if((Trougao::Jednaki(t1.DajStranicu(1),t2.DajStranicu(1)) || Trougao::Jednaki(t1.DajStranicu(1),t2.DajStranicu(2)) || Trougao::Jednaki(t1.DajStranicu(1),t2.DajStranicu(3))) && (Trougao::Jednaki(t1.DajStranicu(2),t2.DajStranicu(1)) || Trougao::Jednaki(t1.DajStranicu(2),t2.DajStranicu(2)) || Trougao::Jednaki(t1.DajStranicu(2),t2.DajStranicu(3))) && (Trougao::Jednaki(t1.DajStranicu(3),t2.DajStranicu(1)) || Trougao::Jednaki(t1.DajStranicu(3),t2.DajStranicu(2)) || Trougao::Jednaki(t1.DajStranicu(3),t2.DajStranicu(3)))){
        double max_str1=t1.DajStranicu(1),max_str2=t2.DajStranicu(1);
        int zapamti_ind1=1,zapamti_ind2=1;
        for(int i=1;i<=3;i++){
            if(t1.DajStranicu(i)>max_str1){max_str1=t1.DajStranicu(i);zapamti_ind1=i;}
            if(t2.DajStranicu(i)>max_str2){max_str2=t2.DajStranicu(i);zapamti_ind2=i;}
        }
        if(t1.DaLiJePozitivnoOrijentiran()){
        if(zapamti_ind1==3)zapamti_ind1=1;
        else zapamti_ind1++;
        }
        else {
            if(zapamti_ind1==1)zapamti_ind1=3;
            else zapamti_ind1--;
        }
        if(t2.DaLiJePozitivnoOrijentiran()){
        if(zapamti_ind2==3)zapamti_ind2=1;
        else zapamti_ind2++;
        }
        else {
            if(zapamti_ind2==1)zapamti_ind2=3;
            else zapamti_ind2--;
        }
        if(Trougao::Jednaki(t1.DajStranicu(zapamti_ind1),t2.DajStranicu(zapamti_ind2)))return true;
    }
    return false;
}
bool DaLiSuSlicni(const Trougao &t1,const Trougao &t2){
if((Trougao::Jednaki(t1.DajUgao(1),t2.DajUgao(1)) || Trougao::Jednaki(t1.DajUgao(1),t2.DajUgao(2)) || Trougao::Jednaki(t1.DajUgao(1),t2.DajUgao(3))) && (Trougao::Jednaki(t1.DajUgao(2),t2.DajUgao(1)) || Trougao::Jednaki(t1.DajUgao(2),t2.DajUgao(2)) || Trougao::Jednaki(t1.DajUgao(2),t2.DajUgao(3))) && (Trougao::Jednaki(t1.DajUgao(3),t2.DajUgao(1)) || Trougao::Jednaki(t1.DajUgao(3),t2.DajUgao(2)) || Trougao::Jednaki(t1.DajUgao(3),t2.DajUgao(3)))){
    double max_str1=t1.DajStranicu(1),max_str2=t2.DajStranicu(1);
    int zapamti_ind1=1,zapamti_ind2=1;
    for(int i=1;i<=3;i++){
        if(t1.DajStranicu(i)>max_str1){max_str1=t1.DajStranicu(i);zapamti_ind1=i;}
        if(t2.DajStranicu(i)>max_str2){max_str2=t2.DajStranicu(i);zapamti_ind2=i;}
    }
    if(t1.DaLiJePozitivnoOrijentiran()){
        if(zapamti_ind1==3)zapamti_ind1=1;
        else zapamti_ind1++;
    }
    else {
        if(zapamti_ind1==1)zapamti_ind1=3;
        else zapamti_ind1--;
    }
    if(t2.DaLiJePozitivnoOrijentiran()){
        if(zapamti_ind2==3)zapamti_ind2=1;
        else zapamti_ind2++;
    }
    else {
        if(zapamti_ind2==1)zapamti_ind2=3;
        else zapamti_ind2--;
    }
    if(Trougao::Jednaki(t1.DajStranicu(zapamti_ind1)/t2.DajStranicu(zapamti_ind2),max_str1/max_str2))return true;
}  
return false;
}

int main ()
{
    cout<<"Koliko zelite kreirati trouglova: ";
    int n;cin>>n;
    vector<shared_ptr<Trougao>>vp;
    for(int i=0;i<n;i++){
        vector<Tacka>tjemena(3);
        cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
        for(int j=0;j<3;j++){
            int x,y;
            cin>>x>>y;
            tjemena[j]=make_pair(x,y);
           }
           try {
            auto p (make_shared<Trougao>(tjemena[0],tjemena[1],tjemena[2]));
            vp.push_back(p); 
           }
           catch(domain_error e){
               cout<<e.what()<<", ponovite unos!"<<endl;i--;
           }
           catch(range_error r){
               cout<<r.what()<<", ponovite unos!"<<endl;i--;
           }
        }
        cout<<"Unesite vektor translacije (dx dy): ";
        double delta_x,delta_y;
        cin>>delta_x>>delta_y;
        transform(vp.begin(),vp.end(),vp.begin(),[delta_x,delta_y](shared_ptr<Trougao>vp){ vp->Transliraj(delta_x,delta_y);return vp;});
        cout<<"Unesite ugao rotacije: ";
        double ugao;cin>>ugao;//ugao=ugao*pi/180;
        transform(vp.begin(),vp.end(),vp.begin(),[ugao](shared_ptr<Trougao>vp){ vp->Rotiraj(vp->DajCentar(),ugao);return vp;});
        cout<<"Unesite faktor skaliranja: ";
        double faktor;
        cin>>faktor;
        transform(vp.begin(),vp.end(),vp.begin(),[faktor](shared_ptr<Trougao>vp){ vp->Skaliraj(vp->DajTjeme(1),faktor);return vp;});
        cout<<"Trouglovi nakon obavljenih transformacija: "<<endl;
        sort(vp.begin(),vp.end(),[](shared_ptr<Trougao>pok,shared_ptr<Trougao>pok2){
           return  (*pok).DajPovrsinu()<(*pok2).DajPovrsinu();
        });
        for_each(vp.begin(),vp.end(),[](shared_ptr<Trougao>pok){
            (*pok).Ispisi();
            cout<<endl;
        });
        cout<<"Trougao sa najmanjim obimom: ";
        if(vp.size()>1){
        auto p=min_element(vp.begin(),vp.end(),[](shared_ptr<Trougao>pok,shared_ptr<Trougao>pok2){
            return (*pok).DajObim()<(*pok2).DajObim();
        });
        (*p)->Ispisi();
            
        }
        else if(vp.size()==1) (*vp[0]).Ispisi();
        bool a=false;
       vector<pair<shared_ptr<Trougao>,shared_ptr<Trougao>>>parovi1;
        for(int i=0;i<vp.size();i++){
            for(int j=0;j<vp.size();j++){
                if(i==j)continue;
                if(DaLiSuIdenticni(*vp[i],*vp[j])){a=true;parovi1.push_back(make_pair(vp[i],vp[j]));}
            }
        }
        if(!a)cout<<endl<<"Nema identicnih trouglova!"<<endl;
        else {
            for(int i=0;i<parovi1.size();i++){
               for(int j=i+1;j<parovi1.size();j++){
                   if(i==parovi1.size()-1)break;
                   if((parovi1[i].first==parovi1[j].first || parovi1[i].first==parovi1[j].second) && (parovi1[i].second==parovi1[j].first || parovi1[i].second==parovi1[j].second)){parovi1[j].first=nullptr;parovi1[j].second=nullptr;}
               }
           }
            cout<<endl<<"Parovi identicnih trouglova:"<<endl;
            for(int i=0;i<parovi1.size();i++){
                if(parovi1[i].first!=nullptr && parovi1[i].second!=nullptr){
               (*parovi1[i].first).Ispisi();cout<<" i ";
               (*parovi1[i].second).Ispisi();cout<<endl;
               }
            }
        }
        a=false;
         vector<pair<shared_ptr<Trougao>,shared_ptr<Trougao>>>parovi2;
        for(int i=0;i<vp.size();i++){
            for(int j=0;j<vp.size();j++){
                if(i==j)continue;
                if(DaLiSuPodudarni((*vp[i]),(*vp[j]))){a=true;parovi2.push_back(make_pair(vp[i],vp[j]));}
            }
        }
        if(!a)cout<<"Nema podudarnih trouglova!"<<endl;
        else {
            for(int i=0;i<parovi2.size();i++){
               for(int j=i+1;j<parovi2.size();j++){
                   if(i==parovi2.size()-1)break;
                   if((parovi2[i].first==parovi2[j].first || parovi2[i].first==parovi2[j].second) && (parovi2[i].second==parovi2[j].first || parovi2[i].second==parovi2[j].second)){parovi2[j].first=nullptr;parovi2[j].second=nullptr;}
               }
           }
            cout<<"Parovi podudarnih trouglova:"<<endl;
            for(int i=0;i<parovi2.size();i++){
                if(parovi2[i].first!=nullptr && parovi2[i].second!=nullptr){
               (*parovi2[i].first).Ispisi();cout<<" i ";
               (*parovi2[i].second).Ispisi();cout<<endl;
               }
               
            }
        } 
       a=false;
     
       vector<pair<shared_ptr<Trougao>,shared_ptr<Trougao>>>parovi3;
       for(int i=0;i<vp.size();i++){
           for(int j=0;j<vp.size();j++){
               if(i==j)continue;
               if(DaLiSuSlicni(*vp[i],*vp[j])){a=true;parovi3.push_back(make_pair(vp[i],vp[j]));}
           }
       }
       if(!a)cout<<"Nema slicnih trouglova!";
       else {
           for(int i=0;i<parovi3.size();i++){
               for(int j=i+1;j<parovi3.size();j++){
                   if(i==parovi3.size()-1)break;
                   if((parovi3[i].first==parovi3[j].first || parovi3[i].first==parovi3[j].second) && (parovi3[i].second==parovi3[j].first || parovi3[i].second==parovi3[j].second)){parovi3[j].first=nullptr;parovi3[j].second=nullptr;}
               }
           }
           cout<<"Parovi slicnih trouglova:"<<endl;
           for(int i=0;i<parovi3.size();i++){
               if(parovi3[i].first!=nullptr && parovi3[i].second!=nullptr){
               (*parovi3[i].first).Ispisi();cout<<" i ";
               (*parovi3[i].second).Ispisi();cout<<endl;
               }
           }
       }
      
	return 0;
}