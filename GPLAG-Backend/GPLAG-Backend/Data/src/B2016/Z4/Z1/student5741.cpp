/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <utility>
#include <stdexcept>
#include <cmath>
#include <memory>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::pair;
using std::range_error;
using std::domain_error;
using std::make_pair;
using std::shared_ptr;
using std::make_shared;
using std::vector;
using std::sort;
using std::swap;
using std::min_element;
using std::transform;
using std::for_each;


typedef pair<double,double> Tacka;

class Trougao{
    Tacka t1;
    Tacka t2;
    Tacka t3;
    static bool JesuLiJednaki(double x,double y,double Eps=1e-10){
        return std::fabs(x-y)<=Eps*(std::fabs(x)+fabs(y));
    }
public:
    Trougao(const Tacka &t1,const Tacka &t2,const Tacka &t3){
        if(Orijentacija(t1,t2,t3)==0){
            throw domain_error("Nekorektne pozicije tjemena");
        }
        Trougao::t1=t1;
        Trougao::t2=t2;
        Trougao::t3=t3;
    }
    
    
    
    
    void Postavi(const Tacka &t1,const Tacka &t2,const Tacka &t3){
        if(Orijentacija(t1,t2,t3)==0){
            throw domain_error("Nekorektne pozicije tjemena");
        }
        Trougao::t1=t1;
        Trougao::t2=t2;
        Trougao::t3=t3;
    }
    
    
    
    
    void Postavi(int indeks,const Tacka &t1){
        if(!(indeks==1 || indeks==2 || indeks==3)){
            throw range_error("Nekorektan indeks");
        }
        if(indeks==1){
            if(Orijentacija(t1,Trougao::t2,Trougao::t3)==0){
                throw domain_error("Nekorektne pozicije tjemena");
            }
            Trougao::t1=t1;
        }
        else if(indeks==2){
            if(Orijentacija(Trougao::t1,t1,Trougao::t3)==0){
                throw domain_error("Nekorektne pozicije tjemena");
            }
            Trougao::t2=t1;
        }
        else{
            if(Orijentacija(Trougao::t1,Trougao::t2,t1)==0){
                throw domain_error("Nekorektne pozicije tjemena");
            }
            Trougao::t3=t1;
        }
    }
    
    
    
    
    
    static int Orijentacija(const Tacka &t1,const Tacka &t2,const Tacka &t3){
        double izraz(t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second));
        if(izraz>0){
            return 1;
        }
        else if(izraz<0){
            return -1;
        }
        else return 0;
    }
    
    
    
    
    
    Tacka DajTjeme(int indeks) const{
        if(!(indeks==1 || indeks==2 || indeks==3)){
            throw range_error("Nekorektan indeks");
        }
        if(indeks==1){
            return t1;
        }
        else if(indeks==2){
            return t2;
        }
        else{
            return t3;
        }
    }
    
    
    
    
    
    double DajStranicu(int indeks) const{
        if(!(indeks==1 || indeks==2 || indeks==3)){
            throw range_error("Nekorektan indeks");
        }
        if(indeks==1){
            return sqrt((t2.first-t3.first)*(t2.first-t3.first)+(t2.second-t3.second)*(t2.second-t3.second));
        }
        else if(indeks==2){
            return sqrt((t1.first-t3.first)*(t1.first-t3.first)+(t1.second-t3.second)*(t1.second-t3.second));
        }
        else{
            return sqrt((t1.first-t2.first)*(t1.first-t2.first)+(t1.second-t2.second)*(t1.second-t2.second));
        }
    }
    
    
    
    
    
    double DajUgao(int indeks) const{
        if(!(indeks==1 || indeks==2 || indeks==3)){
            throw range_error("Nekorektan indeks");
        }
        if(indeks==1){
            return acos((DajStranicu(2)+DajStranicu(3)-DajStranicu(1))/(2*DajStranicu(2)*DajStranicu(3)));
        }
        else if(indeks==2){
            return acos((DajStranicu(1)+DajStranicu(3)-DajStranicu(2))/(2*DajStranicu(1)*DajStranicu(3)));
        }
        else{
            return acos((DajStranicu(1)+DajStranicu(2)-DajStranicu(3))/(2*DajStranicu(1)*DajStranicu(2)));
        }
    }
    
    
    
    
    
    Tacka DajCentar() const{
        return make_pair((t1.first+t2.first+t3.first)/3,(t1.second+t2.second+t3.second)/3);
    }
    
    
    
    
    
    double DajObim() const{
        return DajStranicu(1)+DajStranicu(2)+DajStranicu(3);
    }
    
    
    
    
    
    double DajPovrsinu() const{
        double izraz(t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second));
        return (1./2)*fabs(izraz);
    }
    
    
    
    
    
    bool DaLiJePozitivnoOrijentiran() const{
        if(Orijentacija(t1,t2,t3)==1){
            return true;
        }
        else return false;
    }
    
    
    
    
    
    bool DaLiJeUnutra(const Tacka &t) const{
        int o(Orijentacija(t1,t2,t3));
        int o1(Orijentacija(t1,t2,t));
        int o2(Orijentacija(t2,t3,t));
        int o3(Orijentacija(t3,t1,t));
        if(o==0 || o1==0 || o2==0 || o3==0){
            return false;
        }
        if(o==1){
            if(o1!=1 || o2!=1 || o3!=1){
                return false;
            }
            else return true;
        }
        else if(o==-1){
            if(o1!=-1 || o2!=-1 || o3!=-1){
                return false;
            }
            else return true;
        }
        else return false;
    }
    
    
    
    
    
    void Ispisi() const{
        cout<<"(("<<t1.first<<","<<t1.second<<"),"<<"("<<t2.first<<","<<t2.second<<"),"<<"("<<t3.first<<","<<t3.second<<"))";
    }
    
    
    
    
    
    void Transliraj(double delta_x,double delta_y){
        t1.first=t1.first+delta_x;
        t2.first=t2.first+delta_x;
        t3.first=t3.first+delta_x;
        t1.second=t1.second+delta_y;
        t2.second=t2.second+delta_y;
        t3.second=t3.second+delta_y;
    }
    
    
    
    
    
    void Centriraj(const Tacka &t){
        double razlika_po_x(t.first-DajCentar().first);
        double razlika_po_y(t.second-DajCentar().second);
        Transliraj(razlika_po_x,razlika_po_y);
    }
    
    
    
    
    
    void Rotiraj(const Tacka &t,double ugao){
        t1=make_pair(t.first+(t1.first-t.first)*cos(ugao)-(t1.second-t.second)*sin(ugao),t.second+(t1.first-t.first)*sin(ugao)+(t1.second-t.second)*cos(ugao));
        t2=make_pair(t.first+(t2.first-t.first)*cos(ugao)-(t2.second-t.second)*sin(ugao),t.second+(t2.first-t.first)*sin(ugao)+(t2.second-t.second)*cos(ugao));
        t3=make_pair(t.first+(t3.first-t.first)*cos(ugao)-(t3.second-t.second)*sin(ugao),t.second+(t3.first-t.first)*sin(ugao)+(t3.second-t.second)*cos(ugao));
    }
    
    
    
    
    
    void Skaliraj(const Tacka &t,double faktor){
        if(JesuLiJednaki(faktor,0)){
            throw domain_error("Nekorektan faktor skaliranja");
        }
        t1=make_pair(t.first+faktor*(t1.first-t.first),t.second+faktor*(t1.second-t.second));
        t2=make_pair(t.first+faktor*(t2.first-t.first),t.second+faktor*(t2.second-t.second));
        t3=make_pair(t.first+faktor*(t3.first-t.first),t.second+faktor*(t3.second-t.second));
    }
    
    
    
    
    
    void Rotiraj(double ugao){
        Rotiraj(DajCentar(),ugao);
    }
    
    
    
    
    
    void Skaliraj(double faktor){
        if(JesuLiJednaki(faktor,0)){
            throw domain_error("Nekorektan faktor skaliranja");
        }
        Skaliraj(DajCentar(),faktor);
    }
    
    
    
    
    
    friend bool DaLiSuIdenticni(const Trougao &t1,const Trougao &t2);
    friend bool DaLiSuPodudarni(const Trougao &t1,const Trougao &t2);
    friend bool DaLiSuSlicni(const Trougao &t1,const Trougao &t2);
};



bool DaLiSuIdenticni(const Trougao &t1,const Trougao &t2){
    vector<Tacka> trougao1;
    trougao1.push_back(t1.t1);
    trougao1.push_back(t1.t2);
    trougao1.push_back(t1.t3);
    vector<Tacka> trougao2;
    trougao2.push_back(t2.t1);
    trougao2.push_back(t2.t2);
    trougao2.push_back(t2.t3);
    vector<double> duzina_stranica1;
    duzina_stranica1.push_back(t1.DajStranicu(1));
    duzina_stranica1.push_back(t1.DajStranicu(2));
    duzina_stranica1.push_back(t1.DajStranicu(3));
    vector<double> duzina_stranica2;
    duzina_stranica2.push_back(t2.DajStranicu(1));
    duzina_stranica2.push_back(t2.DajStranicu(2));
    duzina_stranica2.push_back(t2.DajStranicu(3));
    for(int i=0;i<3;i++){
        for(int j=i+1;j<3;j++){
            if(duzina_stranica1[i]>duzina_stranica1[j]){
                swap(duzina_stranica1[i],duzina_stranica1[j]);
                swap(trougao1[i],trougao1[j]);
                j--;
            }
        }
    }
    for(int i=0;i<3;i++){
        for(int j=i+1;j<3;j++){
            if(duzina_stranica2[i]>duzina_stranica2[j]){
                swap(duzina_stranica2[i],duzina_stranica2[j]);
                swap(trougao2[i],trougao2[j]);
                j--;
            }
        }
    }
    for(int i=0;i<3;i++){
        if(!(Trougao::JesuLiJednaki(trougao1[i].first,trougao2[i].first)) || !(Trougao::JesuLiJednaki(trougao1[i].second,trougao2[i].second))){
            return false;
        }
    }
    return true;
}





bool DaLiSuPodudarni(const Trougao &t1,const Trougao &t2){
    vector<Tacka> trougao1;
    trougao1.push_back(t1.t1);
    trougao1.push_back(t1.t2);
    trougao1.push_back(t1.t3);
    vector<Tacka> trougao2;
    trougao2.push_back(t2.t1);
    trougao2.push_back(t2.t2);
    trougao2.push_back(t2.t3);
    vector<double> duzina_stranica1;
    duzina_stranica1.push_back(t1.DajStranicu(1));
    duzina_stranica1.push_back(t1.DajStranicu(2));
    duzina_stranica1.push_back(t1.DajStranicu(3));
    vector<double> duzina_stranica2;
    duzina_stranica2.push_back(t2.DajStranicu(1));
    duzina_stranica2.push_back(t2.DajStranicu(2));
    duzina_stranica2.push_back(t2.DajStranicu(3));
    vector<double> uglovi1;
    uglovi1.push_back(t1.DajUgao(1));
    uglovi1.push_back(t1.DajUgao(2));
    uglovi1.push_back(t1.DajUgao(3));
    vector<double> uglovi2;
    uglovi2.push_back(t2.DajUgao(1));
    uglovi2.push_back(t2.DajUgao(2));
    uglovi2.push_back(t2.DajUgao(3));
    for(int i=0;i<3;i++){
        for(int j=i+1;j<3;j++){
            if(duzina_stranica1[i]>duzina_stranica1[j]){
                swap(duzina_stranica1[i],duzina_stranica1[j]);
                swap(trougao1[i],trougao1[j]);
                swap(uglovi1[i],uglovi1[j]);
                j--;
            }
        }
    }
    for(int i=0;i<3;i++){
        for(int j=i+1;j<3;j++){
            if(duzina_stranica2[i]>duzina_stranica2[j]){
                swap(duzina_stranica2[i],duzina_stranica2[j]);
                swap(trougao2[i],trougao2[j]);
                swap(uglovi1[i],uglovi1[j]);
                j--;
            }
        }
    }
    if(Trougao::Orijentacija(trougao1[0],trougao1[1],trougao1[2])!=Trougao::Orijentacija(trougao2[0],trougao2[1],trougao2[2])){
        return false;
    }
    for(int i=0;i<3;i++){
        if(!(Trougao::JesuLiJednaki(duzina_stranica1[i],duzina_stranica2[i])) || !(Trougao::JesuLiJednaki(uglovi1[i],uglovi2[i]))){
            return false;
        }
    }
    return true;
}


bool DaLiSuSlicni(const Trougao &t1,const Trougao &t2){
    vector<Tacka> trougao1;
    trougao1.push_back(t1.t1);
    trougao1.push_back(t1.t2);
    trougao1.push_back(t1.t3);
    vector<Tacka> trougao2;
    trougao2.push_back(t2.t1);
    trougao2.push_back(t2.t2);
    trougao2.push_back(t2.t3);
    vector<double> duzina_stranica1;
    duzina_stranica1.push_back(t1.DajStranicu(1));
    duzina_stranica1.push_back(t1.DajStranicu(2));
    duzina_stranica1.push_back(t1.DajStranicu(3));
    vector<double> duzina_stranica2;
    duzina_stranica2.push_back(t2.DajStranicu(1));
    duzina_stranica2.push_back(t2.DajStranicu(2));
    duzina_stranica2.push_back(t2.DajStranicu(3));
    vector<double> uglovi1;
    uglovi1.push_back(t1.DajUgao(1));
    uglovi1.push_back(t1.DajUgao(2));
    uglovi1.push_back(t1.DajUgao(3));
    vector<double> uglovi2;
    uglovi2.push_back(t2.DajUgao(1));
    uglovi2.push_back(t2.DajUgao(2));
    uglovi2.push_back(t2.DajUgao(3));
    for(int i=0;i<3;i++){
        for(int j=i+1;j<3;j++){
            if(duzina_stranica1[i]>duzina_stranica1[j]){
                swap(duzina_stranica1[i],duzina_stranica1[j]);
                swap(trougao1[i],trougao1[j]);
                swap(uglovi1[i],uglovi1[j]);
                j--;
            }
        }
    }
    for(int i=0;i<3;i++){
        for(int j=i+1;j<3;j++){
            if(duzina_stranica2[i]>duzina_stranica2[j]){
                swap(duzina_stranica2[i],duzina_stranica2[j]);
                swap(trougao2[i],trougao2[j]);
                swap(uglovi1[i],uglovi1[j]);
                j--;
            }
        }
    }
    if(Trougao::Orijentacija(trougao1[0],trougao1[1],trougao1[2])!=Trougao::Orijentacija(trougao2[0],trougao2[1],trougao2[2])){
        return false;
    }
    double faktor_proporcionalnosti(duzina_stranica1[0]/duzina_stranica2[0]);
    for(int i=1;i<3;i++){
        if(!(Trougao::JesuLiJednaki(duzina_stranica1[i]/duzina_stranica2[i],faktor_proporcionalnosti))){
            return false;
        }
    }
    return true;
}


int main ()
{
    int n;
    cout<<"Koliko zelite kreirati trouglova: ";
    cin>>n;
    vector<shared_ptr<Trougao>> v;
    for(int i=0;i<n;i++){
        cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
        double x1,x2,x3,y1,y2,y3;
        cin>>x1>>y1>>x2>>y2>>x3>>y3;
        try{
            Trougao t(make_pair(x1,y1),make_pair(x2,y2),make_pair(x3,y3));
            v.push_back(make_shared<Trougao> (make_pair(x1,y1),make_pair(x2,y2),make_pair(x3,y3)));
        }
        catch(domain_error izuzetak){
            cout<<izuzetak.what()<<", ponovite unos!"<<endl;
            i--;
        }
    }
    cout<<"Unesite vektor translacije (dx dy): ";
    double dx;
    double dy;
    cin>>dx;
    cin>>dy;
    double ugao;
    cout<<"Unesite ugao rotacije: ";
    cin>>ugao;
    double faktor_skaliranja;
    cout<<"Unesite faktor skaliranja: ";
    cin>>faktor_skaliranja;
    transform(v.begin(),v.end(),v.begin(),[dx,dy](shared_ptr<Trougao> p1){
        p1->Transliraj(dx,dy);
        return p1;
    });
    transform(v.begin(),v.end(),v.begin(),[ugao](shared_ptr<Trougao> p1){
        p1->Rotiraj(ugao);
        return p1;
    });
    transform(v.begin(),v.end(),v.begin(),[faktor_skaliranja](shared_ptr<Trougao> p1){
        p1->Skaliraj(p1->DajTjeme(1),faktor_skaliranja);
        return p1;
    });
    sort(v.begin(),v.end(),[](shared_ptr<Trougao> p1,shared_ptr<Trougao> p2){
        return p1->DajPovrsinu()<p2->DajPovrsinu();
    });
    cout<<"Trouglovi nakon obavljenih transformacija:"<<endl;
    for_each(v.begin(),v.end(),[](shared_ptr<Trougao> p1){
        p1->Ispisi();
        cout<<endl;
    });
    cout<<"Trougao sa najmanjim obimom: ";
    (*(min_element(v.begin(),v.end(),[](shared_ptr<Trougao> p1,shared_ptr<Trougao> p2){
        return p1->DajObim()<p2->DajObim();
    })))->Ispisi();
    int br(0);
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(DaLiSuIdenticni(*v[i],*v[j])){
                if(br==0){
                    cout<<endl<<"Parovi identicnih trouglova:"<<endl;
                }
                v[i]->Ispisi();
                cout<<" i ";
                v[j]->Ispisi();
                cout<<endl;
                br++;
            }
        }
    }
    if(br==0){
        cout<<endl<<"Nema identicnih trouglova!";
    }
    br=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(DaLiSuPodudarni(*v[i],*v[j])){
                if(br==0){
                    cout<<"Parovi podudarnih trouglova:"<<endl;
                }
                v[i]->Ispisi();
                cout<<" i ";
                v[j]->Ispisi();
                cout<<endl;
                br++;
            }
        }
    }
    if(br==0){
        cout<<endl<<"Nema podudarnih trouglova!";
    }
    br=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(DaLiSuSlicni(*v[i],*v[j])){
                if(br==0){
                    cout<<"Parovi slicnih trouglova:"<<endl;
                }
                v[i]->Ispisi();
                cout<<" i ";
                v[j]->Ispisi();
                cout<<endl;
                br++;
            }
        }
    }
    if(br==0){
        cout<<endl<<"Nema slicnih trouglova!";
    }
	return 0;
}