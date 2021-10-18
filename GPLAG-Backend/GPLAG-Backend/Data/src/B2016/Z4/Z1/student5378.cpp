/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <memory>
#include <vector>
#include <algorithm>
using namespace std;
typedef std::pair<double,double> Tacka;
class Trougao{
    Tacka a,b,c;
    static bool Provjera(double d1,double d2){
        const double eps=1E-10;
        if(fabs(d1-d2)<=eps*(fabs(d1)+fabs(d2))) return true;
        return false;
    }
    static bool Provjera(Tacka t1,Tacka t2){
        if(Provjera(t1.first,t2.first)==true && Provjera(t1.second,t2.second)==true) return true;
        return false;
    }
    public:
    Trougao(const Tacka &t1,const Tacka &t2,const Tacka &t3){
        Postavi (t1,t2,t3);
    }
    void Postavi(const Tacka &t1,const Tacka &t2,const Tacka &t3){
        if(Provjera(t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second),0))throw domain_error("Nekorektne pozicije tjemena");
        a=t1;
        b=t2;
        c=t3;
    }
    void Postavi(int indeks , const Tacka &t){
        if(indeks==1)a=t;
        else if(indeks==2)b=t;
        else if(indeks==3)c=t;
        else throw range_error("Nekorektan indeks");
    }
    static int Orijentacija(const Tacka &t1,const Tacka &t2,const Tacka &t3){
        static int o=t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second);
        if(o>0) return 1;
        else if(o<0)return -1;
        return 0;
    }
    Tacka DajTjeme(int indeks)const{
        if(indeks==1)return a;
        else if(indeks == 2)return b;
        else if(indeks==3)return c;
        else throw range_error("Nekorektan indeks");
    }
    double DajStranicu(int indeks )const{
        double stranica;
        if(indeks ==1) stranica=sqrt((b.first-c.first)*(b.first-c.first)+(b.second-c.second)*(b.second-c.second));
        else if(indeks ==2)stranica=sqrt((a.first-c.first)*(a.first-c.first)+(a.second-c.second)*(a.second-c.second));
        else if(indeks==3)stranica=sqrt((a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second));
        else throw range_error("Nekorektan indeks");
        return stranica;
    }
    double DajUgao(int indeks)const{
        double A,B,C;
        A=DajStranicu(1);B=DajStranicu(2);C=DajStranicu(3);
        double ugao;
        if(indeks ==1)ugao = acos((B*B+C*C-A*A)/(2*B*C));
        else if(indeks==2)ugao =acos((A*A+C*C-B*B)/(2*A*C));
        else if(indeks==3)ugao =acos((A*A+B*B-C*C)/(2*A*B));
        else throw range_error ("Nekorektan indeks");
        return ugao;
    }
    Tacka DajCentar()const{
        return make_pair((a.first+b.first+c.first)/3,(a.second+b.second+c.second)/3);
    }
    double DajObim()const{
        double A,B,C;
        A=DajStranicu(1);B=DajStranicu(2);C=DajStranicu(3);
        return A+B+C;
    }
    double DajPovrsinu()const{
        double pov;
        pov=(1/2.)*fabs(a.first*(b.second-c.second)-b.first*(a.second-c.second)+c.first*(a.second-b.second));
        return pov;
    }
    bool DaLiJePozitivnoOrijentiran()const{
        return Orijentacija(a,b,c);
    }
    bool DaLiJeUnutra(const Tacka &t)const;
    void Ispisi()const{
        cout<<"(("<<a.first<<","<<a.second<<"),("<<b.first<<","<<b.second<<"),("<<c.first<<","<<c.second<<"))";
    }
    void Transliraj(double delta_x,double delta_y){
        a=make_pair(a.first+delta_x,a.second+delta_y);
        b=make_pair(b.first+delta_x,b.second+delta_y);
        c=make_pair(c.first+delta_x,c.second+delta_y);
        Postavi(a,b,c);
    }
    void Centriraj(const Tacka &t){
        Transliraj(t.first/2,t.second/2);
    }
    void Rotiraj(const Tacka &t,double ugao){
        a=make_pair(t.first+(a.first-t.first)*cos(ugao)-(a.second-t.second)*sin(ugao),t.second+(a.first-t.first)*sin(ugao)+(a.second-t.second)*cos(ugao));
        b=make_pair(t.first+(b.first-t.first)*cos(ugao)-(b.second-t.second)*sin(ugao),t.second+(b.first-t.first)*sin(ugao)+(b.second-t.second)*cos(ugao));
        c=make_pair(t.first+(c.first-t.first)*cos(ugao)-(c.second-t.second)*sin(ugao),t.second+(c.first-t.first)*sin(ugao)+(c.second-t.second)*cos(ugao));
        Postavi(a,b,c);
    }
    void Skaliraj(const Tacka &t,double faktor){
        a=make_pair(t.first+faktor*(a.first-t.first),t.second+faktor*(a.second-t.second));
        b=make_pair(t.first+faktor*(b.first-t.first),t.second+faktor*(b.second-t.second));
        c=make_pair(t.first+faktor*(c.first-t.first),t.second+faktor*(c.second-t.second));
    }
    void Rotiraj(double ugao){
        Rotiraj(DajCentar(),ugao);
    }
    void Skaliraj(double faktor){
        Skaliraj(DajCentar(),faktor);
    }
    friend bool DaLiSuIdenticni(const Trougao &t1,const Trougao &t2){
        return Provjera(t1.DajCentar(),t2.DajCentar());
    }
    friend bool DaLiSuPodudarni(const Trougao &t1,const Trougao &t2){
        if(Provjera (t1.DajPovrsinu(),t2.DajPovrsinu()))return true;
        return false;
    }
    friend bool DaLiSuSlicni(const Trougao &t1,const Trougao &t2){
        double A,B,C;
        A=t1.DajStranicu(1);B=t1.DajStranicu(2);C=t1.DajStranicu(3);
        double A1,B1,C1;
        A1=t2.DajStranicu(1);B1=t2.DajStranicu(2);C1=t2.DajStranicu(3);
        double k=A/A1;
        double k1=A/B1;
        double k2=A/C1;
        if(Provjera (k,B/B1)&&Provjera(k,C/C1)) return true;
        if(Provjera (k1,B/C1)&&Provjera(k,C/A1))return true;
        if(Provjera(k2,B/A1)&&Provjera(k2,C/B1))return true;
        return false;
    }
};
int main ()
{
    int n;
    cout<<"Koliko zelite kreirati trouglova: ";
    cin>>n;
    vector<shared_ptr<Trougao>> v;
    for(int i=0;i<n;i++){
        cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
        Tacka a,b,c;
        cin>>a.first>>a.second>>b.first>>b.second>>c.first>>c.second;
        try{
            v.push_back(make_shared<Trougao>(a,b,c));
        }
        catch(domain_error e){
            i--;
            cout<<e.what()<<", ponovite unos!"<<endl;
        }
    }
    Tacka t;
    cout << "Unesite vektor translacije (dx dy): ";
    cin>>t.first>>t.second;
    cout<<"Unesite ugao rotacije: ";
    double u;
    cin>>u;
    cout<<"Unesite faktor skaliranja: ";
    double f;
    cin>>f;
    
    cout <<"Trouglovi nakon obavljenih transformacija:"<<endl;
    for(int i=0;i<v.size();i++){
        v[i]->Transliraj(t.first,t.second);
        v[i]->Rotiraj(u);
        v[i]->Skaliraj(v[i]->DajTjeme(1),f);
    }
    sort(v.begin(),v.end(),[](shared_ptr<Trougao>t1,shared_ptr<Trougao>t2){return t1->DajPovrsinu()<t2->DajPovrsinu();});
    for(int i=0;i<v.size();i++){
        v[i]->Ispisi();cout<<endl;
    }
    cout<<"Trougao sa najmanjim obimom: ";
    auto obim=min_element(v.begin(),v.end(),[](shared_ptr<Trougao>t1,shared_ptr<Trougao>t2){return t1->DajObim()<t2->DajObim();});
    (*obim)->Ispisi();cout<<endl;
    int br=0;
    for(int i=0;i<v.size()-1;i++){
        for(int j=i+1;j<v.size();j++){
            if(DaLiSuIdenticni(*v[i],*v[j])){
                br++;
                if(br==1)cout<<"Parovi identicnih trouglova: "<<endl;
                v[i]->Ispisi();
                cout<<" i ";
                v[j]->Ispisi();
                cout<<endl;
                br++;
            }
        }
    }
    if(br==0)cout<<"Nema identicnih trouglova!"<<endl;
    br=0;
    for(int i=0;i<v.size()-1;i++){
    for(int j=i+1;j<v.size();j++){
        if(DaLiSuPodudarni(*v[i],*v[j])){
            br++;
            if(br==1)cout<<"Parovi podudarnih trouglova: "<<endl;
            v[i]->Ispisi();
            cout<<" i ";
            v[i]->Ispisi();
            cout<<endl;
            break;
        }
    }
}
if(br==0)cout<<"Nema podudarnih trouglova!"<<endl;
br=0;
for(int i=0;i<v.size()-1;i++){
    for(int j=i+1;j<v.size();j++){
        if(DaLiSuSlicni(*v[i],*v[j])){
            br++;
            if(br==1)cout<<"Parovi slicnih trouglova: "<<endl;
            v[i]->Ispisi();
            cout<<" i ";
            v[i]->Ispisi();
            cout<<endl;
        }
    }
}
if(br==0) cout<<"Nema slicnih trouglova!"<<endl;
	return 0;
}