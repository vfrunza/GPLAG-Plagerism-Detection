/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include<utility>
#include<stdexcept>
#include<cmath>
#include<algorithm>
#include<memory>
#include<vector>
typedef std::pair<double, double> Tacka;
bool jednaki(double x,double y, double eps=1e-10){
    return std::fabs(x-y)<=eps*(std::fabs(x)+std::fabs(y));
}
class Trougao{
    Tacka tacka1,tacka2,tacka3;
    public:
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        if(Orijentacija(t1,t2,t3)==0) throw std::domain_error("Nekorektne pozicije tjemena, ponovite unos!");
        tacka1=t1; tacka2=t2; tacka3=t3;
    }
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        if(Orijentacija(t1,t2,t3)==0) throw std::domain_error("Nekorektne pozicije tjemena, ponovite unos!");
        tacka1=t1; tacka2=t2; tacka3=t3;
    }
    void Postavi(int indeks, const Tacka &t){
        if(indeks==1) tacka1=t;
        else if(indeks==2) tacka2=t;
        else if(indeks==3) tacka3=t;
        else  throw std::range_error("Nekorektan indeks");
    }
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        double rez=t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second);
        if(rez>0) return 1;
        if(rez<0) return -1;
        return 0;
    }
    Tacka DajTjeme(int indeks) const{
        if(indeks==1) return tacka1;
        if(indeks==2) return tacka2;
        if(indeks==3) return tacka3;
        else throw std::range_error("Nekorektan indeks");
    }
    double DajStranicu(int indeks) const{
        if(indeks==1) return sqrt((tacka2.first-tacka3.first)*(tacka2.first-tacka3.first)+(tacka2.second-tacka3.second)*(tacka2.second-tacka3.second));
        if(indeks==2) return sqrt((tacka1.first-tacka3.first)*(tacka1.first-tacka3.first)+(tacka1.second-tacka3.second)*(tacka1.second-tacka3.second));
        if(indeks==3) return sqrt((tacka2.first-tacka1.first)*(tacka2.first-tacka1.first)+(tacka2.second-tacka1.second)*(tacka2.second-tacka1.second));
        else throw std::range_error("Nekorektan indeks");
    }
    double DajUgao(int indeks) const{
        if(indeks==1) return acos((DajStranicu(2)*DajStranicu(2)+DajStranicu(3)*DajStranicu(3)-DajStranicu(1)*DajStranicu(1))/(2*DajStranicu(2)*DajStranicu(3)))*4*atan(1)/180;
        if(indeks==2) return acos((DajStranicu(1)*DajStranicu(1)+DajStranicu(3)*DajStranicu(3)-DajStranicu(2)*DajStranicu(2))/(2*DajStranicu(1)*DajStranicu(3)))*4*atan(1)/180;
        if(indeks==3) return acos((DajStranicu(1)*DajStranicu(1)+DajStranicu(2)*DajStranicu(2)-DajStranicu(3)*DajStranicu(3))/(2*DajStranicu(1)*DajStranicu(2)))*4*atan(1)/180;
        else throw std::range_error("Nekorektan indeks");
    }
    Tacka DajCentar() const{
        double xt=(tacka1.first+tacka2.first+tacka3.first)/3., yt=(tacka1.second+tacka2.second+tacka3.second)/3.;
        return {xt,yt};
    }
    double DajObim() const{
        return DajStranicu(1)+DajStranicu(2)+DajStranicu(3);
    }
    double DajPovrsinu() const{
        return fabs(tacka1.first*(tacka2.second-tacka3.second)-tacka2.first*(tacka1.second-tacka3.second)+tacka3.first*(tacka1.second-tacka2.second))/2;
    }
    bool DaLiJePozitivnoOrijentiran() const{
        if(Orijentacija(tacka1,tacka2,tacka3)==1) return true;
        return false;
    }
    bool DaLiJeUnutra(const Tacka &t) const{
        double ukupna=DajPovrsinu();
        double pov1=fabs(tacka1.first*(tacka2.second-t.second)-tacka2.first*(tacka1.second-t.second)+t.first*(tacka1.second-tacka2.second))/2;
        double pov2=fabs(t.first*(tacka2.second-tacka3.second)-tacka2.first*(t.second-tacka3.second)+tacka3.first*(t.second-tacka2.second))/2;
        double pov3=fabs(tacka1.first*(t.second-tacka3.second)-t.first*(tacka1.second-tacka3.second)+tacka3.first*(tacka1.second-t.second))/2;
        if(jednaki(ukupna,pov1+pov2+pov3)) return true;
        return false;
    }
    void Ispisi() const{
        std::cout << "(("<<tacka1.first<<","<<tacka1.second<<"),("<<tacka2.first<<","<<tacka2.second<<"),("<<tacka3.first<<","<<tacka3.second<<"))";
    }
    void Transliraj(double delta_x, double delta_y){
        tacka1.first+=delta_x;
        tacka2.first+=delta_x;
        tacka3.first+=delta_x;
        
        tacka1.second+=delta_y;
        tacka2.second+=delta_y;
        tacka3.second+=delta_y;
    }
    void Centriraj(const Tacka &t){
        Tacka centar=DajCentar();
        double delta_x=(t.first-centar.first),delta_y=(t.second-centar.second);
        tacka1.first+=delta_x;
        tacka2.first+=delta_x;
        tacka3.first+=delta_x;
        tacka1.second+=delta_y;
        tacka2.second+=delta_y;
        tacka3.second+=delta_y;
    }
    void Rotiraj(const Tacka &t, double ugao){
        double a=tacka1.first,b=tacka2.first,c=tacka3.first;
        tacka1.first=t.first+(a-t.first)*cos(ugao)-(tacka1.second-t.second)*sin(ugao);
        tacka2.first=t.first+(b-t.first)*cos(ugao)-(tacka2.second-t.second)*sin(ugao);
        tacka3.first=t.first+(c-t.first)*cos(ugao)-(tacka3.second-t.second)*sin(ugao);
        tacka1.second=t.second+(a-t.first)*sin(ugao)+(tacka1.second-t.second)*cos(ugao);
        tacka2.second=t.second+(b-t.first)*sin(ugao)+(tacka2.second-t.second)*cos(ugao);
        tacka3.second=t.second+(c-t.first)*sin(ugao)+(tacka3.second-t.second)*cos(ugao);
    }
    void Skaliraj(const Tacka &t, double faktor){
        if(faktor==0.) throw std::domain_error("Nekorektan faktor skaliranja");
        tacka1.first=t.first+faktor*(tacka1.first-t.first);
        tacka2.first=t.first+faktor*(tacka2.first-t.first);
        tacka3.first=t.first+faktor*(tacka3.first-t.first);
        tacka1.second=t.second+faktor*(tacka1.second-t.second);
        tacka2.second=t.second+faktor*(tacka2.second-t.second);
        tacka3.second=t.second+faktor*(tacka3.second-t.second);
    }
    void Rotiraj(double ugao){
        Tacka t=DajCentar();
        double a=tacka1.first,b=tacka2.first,c=tacka3.first;
        tacka1.first=t.first+(a-t.first)*cos(ugao)-(tacka1.second-t.second)*sin(ugao);
        tacka2.first=t.first+(b-t.first)*cos(ugao)-(tacka2.second-t.second)*sin(ugao);
        tacka3.first=t.first+(c-t.first)*cos(ugao)-(tacka3.second-t.second)*sin(ugao);
        tacka1.second=t.second+(a-t.first)*sin(ugao)+(tacka1.second-t.second)*cos(ugao);
        tacka2.second=t.second+(b-t.first)*sin(ugao)+(tacka2.second-t.second)*cos(ugao);
        tacka3.second=t.second+(c-t.first)*sin(ugao)+(tacka3.second-t.second)*cos(ugao);
    }
    void Skaliraj(double faktor){
        if(faktor==0.) throw std::domain_error("Nekorektan faktor skaliranja");
        Tacka t=DajCentar();
        tacka1.first=t.first+faktor*(tacka1.first-t.first);
        tacka2.first=t.first+faktor*(tacka2.first-t.first);
        tacka3.first=t.first+faktor*(tacka3.first-t.first);
        tacka1.second=t.second+faktor*(tacka1.second-t.second);
        tacka2.second=t.second+faktor*(tacka2.second-t.second);
        tacka3.second=t.second+faktor*(tacka3.second-t.second);
    }
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);
};

bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2){
    bool prva=false,druga=false,treca=false;
    if(t1.tacka1==t2.tacka1) prva=true;
    if(t1.tacka1==t2.tacka2) prva=true;
    if(t1.tacka1==t2.tacka3) prva=true;
    
    if(t1.tacka2==t2.tacka1) druga=true;
    if(t1.tacka2==t2.tacka2) druga=true;
    if(t1.tacka2==t2.tacka3) druga=true;
    
    if(t1.tacka3==t2.tacka1) treca=true;
    if(t1.tacka3==t2.tacka2) treca=true;
    if(t1.tacka3==t2.tacka3) treca=true;
    
    if(prva && druga && treca ) return true;
    return false;
}
bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2){
    double a=t1.DajStranicu(1),b=t1.DajStranicu(2),c=t1.DajStranicu(3),a1=t2.DajStranicu(1),b1=t2.DajStranicu(2),c1=t2.DajStranicu(3);
    double maxa,maxb,maxc,maxa1,maxb1,maxc1;
    if(a>b && a>c) {
        maxa=a;
        if(b>c){
            maxb=b;
            maxc=c;
        }
        else{
            maxb=c;
            maxc=b;
        }
    }
    else if(b>a && b>c){
        maxa=b;
        if(a>c){
            maxb=a;
            maxc=c;
        }
        else{
            maxb=c;
            maxc=a;
        }
    }
    else if(c>a && c>b){
        maxa=c;
        if(a>b){
            maxb=a;
            maxc=b;
        }
        else{
            maxb=b;
            maxc=a;
        }
    }
    else if(jednaki(b,a) && c>a){
        maxa=c; maxb=b; maxc=a;
    }
    else if(jednaki(c,a) && b>a ){
        maxa=b; maxb=c; maxc=a;
    }
    else if(jednaki(c,b) && a>c){
        maxa=a; maxb=b; maxc=c;
    }
    else if(jednaki(b,a) && c<a){
        maxa=b; maxb=b; maxc=c;
    }
    else if(jednaki(c,a) && b<a ){
        maxa=a; maxb=c; maxc=b;
    }
    else if(jednaki(c,b) && a<c){
        maxa=c; maxb=b; maxc=a;
    }
    else {
        maxa=c; maxb=b; maxc=a;
    }
    
    if(a1>b1 && a1>c1) {
        maxa1=a1;
        if(b1>c1){
            maxb1=b1;
            maxc1=c1;
        }
        else{
            maxb1=c1;
            maxc1=b1;
        }
    }
    else if(b1>a1 && b1>c1){
        maxa1=b1;
        if(a1>c){
            maxb1=a1;
            maxc1=c1;
        }
        else{
            maxb1=c1;
            maxc1=a1;
        }
    }
    else if(c1>a1 && c>b1){
        maxa1=c1;
        if(a1>b1){
            maxb1=a1;
            maxc1=b1;
        }
        else{
            maxb1=b1;
            maxc1=a1;
        }
    }
    else if(jednaki(b1,a1) && c1>a1){
        maxa1=c1; maxb1=b1; maxc1=a1;
    }
    else if(jednaki(c1,a1) && b1>a1 ){
        maxa1=b1; maxb1=c1; maxc1=a1;
    }
    else if(jednaki(c1,b1) && a1>c1){
        maxa1=a1; maxb1=b1; maxc1=c1;
    }
    else if(jednaki(b1,a1) && c1<a1){
        maxa1=b1; maxb1=b1; maxc1=c1;
    }
    else if(jednaki(c1,a1) && b1<a1 ){
        maxa1=a1; maxb1=c1; maxc1=b1;
    }
    else if(jednaki(c1,b1) && a1<c1){
        maxa1=c1; maxb1=b1; maxc1=a1;
    }
    else {
        maxa1=a1; maxb1=b1; maxc1=c1;
    }
    
    Tacka x,y,z,x1,y1,z1;
    if(jednaki(t1.DajStranicu(1),maxa)){
        x=t1.DajTjeme(1);
    }
    if(jednaki(t1.DajStranicu(2),maxa)){
        x=t1.DajTjeme(2);
    }
    if(jednaki(t1.DajStranicu(3),maxa)){
        x=t1.DajTjeme(3);
    }
    if(jednaki(t1.DajStranicu(1),maxb)){
        y=t1.DajTjeme(1);
    }
    if(jednaki(t1.DajStranicu(2),maxb)){
        y=t1.DajTjeme(2);
    }
    if(jednaki(t1.DajStranicu(3),maxb)){
        y=t1.DajTjeme(3);
    }
    if(jednaki(t1.DajStranicu(1),maxc)){
        z=t1.DajTjeme(1);
    }
    if(jednaki(t1.DajStranicu(2),maxc)){
        z=t1.DajTjeme(2);
    }
    if(jednaki(t1.DajStranicu(3),maxc)){
        z=t1.DajTjeme(3);
    }
    
    
    if(jednaki(t2.DajStranicu(1),maxa1)){
        x1=t2.DajTjeme(1);
    }
    if(jednaki(t2.DajStranicu(2),maxa1)){
        x1=t2.DajTjeme(2);
    }
    if(jednaki(t2.DajStranicu(3),maxa1)){
        x1=t2.DajTjeme(3);
    }
    if(jednaki(t2.DajStranicu(1),maxb1)){
        y1=t2.DajTjeme(1);
    }
    if(jednaki(t2.DajStranicu(2),maxb1)){
        y1=t2.DajTjeme(2);
    }
    if(jednaki(t2.DajStranicu(3),maxb1)){
        y1=t2.DajTjeme(3);
    }
    if(jednaki(t2.DajStranicu(1),maxc1)){
        z1=t2.DajTjeme(1);
    }
    if(jednaki(t2.DajStranicu(2),maxc1)){
        z1=t2.DajTjeme(2);
    }
    if(jednaki(t2.DajStranicu(3),maxc1)){
        z1=t2.DajTjeme(3);
    }
    
    if(jednaki(maxa,maxa1) && jednaki(maxb,maxb1) && jednaki(maxc,maxc1)){
        if(t1.Orijentacija(x,y,z)==t2.Orijentacija(x1,y1,z1))
            return true;
    }
    return false;
}
bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2){
    double a=t1.DajStranicu(1),b=t1.DajStranicu(2),c=t1.DajStranicu(3),a1=t2.DajStranicu(1),b1=t2.DajStranicu(2),c1=t2.DajStranicu(3);
    double maxa,maxb,maxc,maxa1,maxb1,maxc1;
    if(a>b && a>c) {
        maxa=a;
        if(b>c){
            maxb=b;
            maxc=c;
        }
        else{
            maxb=c;
            maxc=b;
        }
    }
    else if(b>a && b>c){
        maxa=b;
        if(a>c){
            maxb=a;
            maxc=c;
        }
        else{
            maxb=c;
            maxc=a;
        }
    }
    else if(c>a && c>b){
        maxa=c;
        if(a>b){
            maxb=a;
            maxc=b;
        }
        else{
            maxb=b;
            maxc=a;
        }
    }
    else if(jednaki(b,a) && c>a){
        maxa=c; maxb=b; maxc=a;
    }
    else if(jednaki(c,a) && b>a ){
        maxa=b; maxb=c; maxc=a;
    }
    else if(jednaki(c,b) && a>c){
        maxa=a; maxb=b; maxc=c;
    }
    else if(jednaki(b,a) && c<a){
        maxa=b; maxb=b; maxc=c;
    }
    else if(jednaki(c,a) && b<a ){
        maxa=a; maxb=c; maxc=b;
    }
    else if(jednaki(c,b) && a<c){
        maxa=c; maxb=b; maxc=a;
    }
    else {
        maxa=c; maxb=b; maxc=a;
    }
    
    if(a1>b1 && a1>c1) {
        maxa1=a1;
        if(b1>c1){
            maxb1=b1;
            maxc1=c1;
        }
        else{
            maxb1=c1;
            maxc1=b1;
        }
    }
    else if(b1>a1 && b1>c1){
        maxa1=b1;
        if(a1>c){
            maxb1=a1;
            maxc1=c1;
        }
        else{
            maxb1=c1;
            maxc1=a1;
        }
    }
    else if(c1>a1 && c>b1){
        maxa1=c1;
        if(a1>b1){
            maxb1=a1;
            maxc1=b1;
        }
        else{
            maxb1=b1;
            maxc1=a1;
        }
    }
    else if(jednaki(b1,a1) && c1>a1){
        maxa1=c1; maxb1=b1; maxc1=a1;
    }
    else if(jednaki(c1,a1) && b1>a1 ){
        maxa1=b1; maxb1=c1; maxc1=a1;
    }
    else if(jednaki(c1,b1) && a1>c1){
        maxa1=a1; maxb1=b1; maxc1=c1;
    }
    else if(jednaki(b1,a1) && c1<a1){
        maxa1=b1; maxb1=b1; maxc1=c1;
    }
    else if(jednaki(c1,a1) && b1<a1 ){
        maxa1=a1; maxb1=c1; maxc1=b1;
    }
    else if(jednaki(c1,b1) && a1<c1){
        maxa1=c1; maxb1=b1; maxc1=a1;
    }
    else {
        maxa1=a1; maxb1=b1; maxc1=c1;
    }
    
    Tacka x,y,z,x1,y1,z1;
    if(jednaki(t1.DajStranicu(1),maxa)){
        x=t1.DajTjeme(1);
    }
    if(jednaki(t1.DajStranicu(2),maxa)){
        x=t1.DajTjeme(2);
    }
    if(jednaki(t1.DajStranicu(3),maxa)){
        x=t1.DajTjeme(3);
    }
    if(jednaki(t1.DajStranicu(1),maxb)){
        y=t1.DajTjeme(1);
    }
    if(jednaki(t1.DajStranicu(2),maxb)){
        y=t1.DajTjeme(2);
    }
    if(jednaki(t1.DajStranicu(3),maxb)){
        y=t1.DajTjeme(3);
    }
    if(jednaki(t1.DajStranicu(1),maxc)){
        z=t1.DajTjeme(1);
    }
    if(jednaki(t1.DajStranicu(2),maxc)){
        z=t1.DajTjeme(2);
    }
    if(jednaki(t1.DajStranicu(3),maxc)){
        z=t1.DajTjeme(3);
    }
    
    
    if(jednaki(t2.DajStranicu(1),maxa1)){
        x1=t2.DajTjeme(1);
    }
    if(jednaki(t2.DajStranicu(2),maxa1)){
        x1=t2.DajTjeme(2);
    }
    if(jednaki(t2.DajStranicu(3),maxa1)){
        x1=t2.DajTjeme(3);
    }
    if(jednaki(t2.DajStranicu(1),maxb1)){
        y1=t2.DajTjeme(1);
    }
    if(jednaki(t2.DajStranicu(2),maxb1)){
        y1=t2.DajTjeme(2);
    }
    if(jednaki(t2.DajStranicu(3),maxb1)){
        y1=t2.DajTjeme(3);
    }
    if(jednaki(t2.DajStranicu(1),maxc1)){
        z1=t2.DajTjeme(1);
    }
    if(jednaki(t2.DajStranicu(2),maxc1)){
        z1=t2.DajTjeme(2);
    }
    if(jednaki(t2.DajStranicu(3),maxc1)){
        z1=t2.DajTjeme(3);
    }
    
    
    double razlika=fabs(maxa-maxa1);
        if( fabs(maxb-maxb1)==razlika && fabs(maxc-maxc1)==razlika)
            if(t1.Orijentacija(x,y,z)==t2.Orijentacija(x1,y1,z1))
            return true;
    
   
    return false;
}
int main (){
    int n;
    std::cout << "Koliko zelite kreirati trouglova: " ;
    std::cin>>n;
    std::vector<std::shared_ptr<Trougao>> v(n);
    try {
        for(int i=0; i<n; i++) {
            std::cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
            Tacka par1;
            std::cin>>par1.first;
            std::cin>>par1.second;
            Tacka par2;
            std::cin>>par2.first;
            std::cin>>par2.second;
            Tacka par3;
            std::cin>>par3.first;
            std::cin>>par3.second;
            Trougao pom({1,2},{7,9},{3,77});
            try{
             pom.Postavi(par1,par2,par3);
            }
            catch(std::domain_error x){
                std::cout<<x.what()<<std::endl;
                i--;
                continue;
            }
            v[i]= std::make_shared<Trougao> (pom);
       //     std::cout<<"a="<<v[i]->DajStranicu(1)<<"     b="<<v[i]->DajStranicu(2)<<"     c="<<v[i]->DajStranicu(3)<<"  orjentacija: "<<v[i]->DaLiJePozitivnoOrijentiran()<<std::endl;
       //     std::cout<<"alfa="<<v[i]->DajUgao(1)<<"     beta="<<v[i]->DajUgao(2)<<"     gama="<<v[i]->DajUgao(3)<<std::endl;
        }
        
        //std::cout<<std::endl<<"a1="<<v[0]->DajStranicu(1)<<std::endl;
        std::cout <<"Unesite vektor translacije (dx dy): ";
        double delta_x,delta_y;
        std::cin>>delta_x>>delta_y;
        std::transform(v.begin(),v.end(),v.begin(),[delta_x,delta_y](std::shared_ptr<Trougao> t){
            t->Transliraj(delta_x,delta_y);
            return t;
        }
        );
        
        std::cout<< "Unesite ugao rotacije: ";
        double ugao;
        std::cin>>ugao;
        std::transform(v.begin(),v.end(),v.begin(),[ugao](std::shared_ptr<Trougao> tr){
            tr->Rotiraj(ugao);
            return tr;
        }
        );
        std::cout<<"Unesite faktor skaliranja: ";
        double faktor;
        std::cin>>faktor;
        std::transform(v.begin(),v.end(),v.begin(),[faktor](std::shared_ptr<Trougao> tr){
            tr->Skaliraj(tr->DajTjeme(1),faktor);
            return tr;
        });
        std::cout << "Trouglovi nakon obavljenih transformacija:" << std::endl;
        std::sort(v.begin(),v.end(),[](std::shared_ptr<Trougao> t1,std::shared_ptr<Trougao> t2){
            if(t1->DajPovrsinu()<t2->DajPovrsinu()) return true;
            return false;
        }
        );
        std::for_each(v.begin(),v.end(),[](std::shared_ptr<Trougao> t){
            t->Ispisi();
            std::cout<<std::endl;
        });
        auto minobim=*(std::min_element(v.begin(),v.end(),[](std::shared_ptr<Trougao> t1,std::shared_ptr<Trougao> t2){
            if(t1->DajObim()<t2->DajObim()) return true;
            return false;
        }));
        std::cout << "Trougao sa najmanjim obimom: ";
        minobim->Ispisi();
        std::cout << std::endl;
        //********IDENTICNI***********************************
        std::vector<int> videnttr ;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                Trougao prvi(v[i]->DajTjeme(1),v[i]->DajTjeme(2),v[i]->DajTjeme(3)),druga(v[j]->DajTjeme(1),v[j]->DajTjeme(2),v[j]->DajTjeme(3));
                if(DaLiSuIdenticni(prvi,druga) ){
                    videnttr.push_back(i);
                    videnttr.push_back(j);
                }
            }
        }
        if(videnttr.size()!=0){
        std::cout << "Parovi identicnih trouglova:" << std::endl;
        for(int i=0;i<videnttr.size();i+=2){
            v[videnttr[i]]->Ispisi();
            std::cout <<" i " ;
            v[videnttr[i+1]]->Ispisi();
            if(i+2!=videnttr.size()-1)
            std::cout  << std::endl;
        }
        }
        else 
            std::cout<<"Nema identicnih trouglova!"<<std::endl;
        //********PODUDARNI***********************************
        std::vector<int> videnttr1 ;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                Trougao prvi(v[i]->DajTjeme(1),v[i]->DajTjeme(2),v[i]->DajTjeme(3)),druga(v[j]->DajTjeme(1),v[j]->DajTjeme(2),v[j]->DajTjeme(3));
                if(DaLiSuPodudarni(prvi,druga) ){
                    videnttr1.push_back(i);
                    videnttr1.push_back(j);
                   // std::cout<<"orjentacija 1: "<<prvi.Orijentacija(prvi.DajTjeme(1),prvi.DajTjeme(2),prvi.DajTjeme(3))<<"    orj2: "<<druga.Orijentacija(druga.DajTjeme(1),druga.DajTjeme(2),druga.DajTjeme(3))<<std::endl;
                   // std::cout<<i<<" isti ko i  "<<j<<std::endl;
                }
            }
        }
        if(videnttr1.size()!=0){
        std::cout << "Parovi podudarnih trouglova:" << std::endl;
        for(int i=0;i<videnttr1.size();i+=2){
            v[videnttr1[i]]->Ispisi();
            std::cout <<" i " ;
            v[videnttr1[i+1]]->Ispisi();
            
            if(i+2!=videnttr1.size()-1)
            std::cout  << std::endl;
        }
        }
        else
            std::cout<<"Nema podudarnih trouglova!"<<std::endl;
        //********SLICNI**************************************
        std::vector<int> videnttr2 ;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                Trougao prvi(v[i]->DajTjeme(1),v[i]->DajTjeme(2),v[i]->DajTjeme(3)),druga(v[j]->DajTjeme(1),v[j]->DajTjeme(2),v[j]->DajTjeme(3));
                if(DaLiSuSlicni(prvi,druga)){
                    videnttr2.push_back(i);
                    videnttr2.push_back(j);
                }
            }
        }
        if(videnttr2.size()!=0){
            std::cout << "Parovi slicnih trouglova:" << std::endl;
        for(int i=0;i<videnttr2.size();i+=2){
            v[videnttr2[i]]->Ispisi();
            std::cout <<" i " ;
            v[videnttr2[i+1]]->Ispisi();
            if(i+2!=videnttr2.size()-1)
            std::cout  << std::endl;
        }
        }
        else    
            std::cout<<"Nema slicnih trouglova!"<<std::endl;
    }
    catch (std::domain_error x) {
        std::cout<<x.what();
    } catch(std::range_error x) {
        std::cout<<x.what();
    }
    //   10 7 9 3 0 0 2 1 6 1 6 4 5 8 7 3 1 5 
    return 0;
}