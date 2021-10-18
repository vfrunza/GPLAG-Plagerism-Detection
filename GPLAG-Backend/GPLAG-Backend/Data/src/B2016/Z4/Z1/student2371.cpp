/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <utility>
#include<stdexcept>
#include<cmath>
#include<vector>
#include<algorithm>
#include<memory>
using std::cout;
using std::cin;
using std::endl;
using std::domain_error;
using std::range_error;
using std::vector;
using std::shared_ptr;
typedef std::pair<double, double> Tacka;
class Trougao{
    Tacka a,b,c;
    static double Povrsina(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        return  abs((t1.first*(t2.second - t3.second) + t2.first*(t3.second - t1.second) + t3.first*(t1.second-t2.second))/2);
    }
    public:
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        if (Orijentacija (t1, t2, t3)==0) throw std::domain_error ("Nekorektne pozicije tjemena");
        else {c=t3; b=t2; a=t1;}
    };
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        if (Orijentacija( t1, t2, t3)==0) throw std::domain_error ("Nekorektne pozicije tjemena");
        else {c=t3; b=t2; a=t1;}
    };
    void Postavi(int indeks, const Tacka &t){
        if (indeks!=1 && indeks!=2 &&indeks!=3) throw std::range_error ("Nekorektan indeks postavi");
        if (indeks==1) a=t;
        if (indeks==2) b=t;
        if (indeks==3) c=t;
    };
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        double temp= t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)-t3.first*(t1.second-t2.second);
        if (temp>0) return 1;
        if (temp<0) return -1 ;
        if (fabs(temp)<=(1e-10)*fabs(temp)) return 0;
    }
    Tacka DajTjeme(int indeks) const{
        if (indeks!=1 && indeks!=2 && indeks!=3) throw std::range_error ("Nekorektan indeks tjeme");
        if (indeks==1) return a;
        if (indeks==2) return b;
        if (indeks==3) return c;
    }
   double DajStranicu(int indeks) const{
        if (indeks!=1 && indeks!=2 && indeks!=3) throw std::range_error ("Nekorektan indeks stranica");
        if (indeks==1) return (sqrt(((b.first-c.first)*(b.first-c.first))+((b.second-c.second)*(b.second-c.second))));
        if (indeks==2) return (sqrt(((a.first-c.first)*(a.first-c.first))+((a.second-c.second)*(a.second-c.second))));
        if (indeks==3) return (sqrt(((b.first-a.first)*(b.first-a.first))+((b.second-a.second)*(b.second-a.second))));
    }
    double DajUgao(int indeks) const{
        //if (indeks!=1 && indeks!=2 && indeks!=3) throw std::range_error ("Nekorektan indeks ugla");
        double A=DajStranicu(1);
        double B=DajStranicu(2);
        double C=DajStranicu(3);
        if (indeks==1) return acos(((A*A-C*C-B*B)/(2*B*C)));
        if (indeks==2) return acos(((B+B-C*C-A*A)/(2*A*C)));
        if (indeks==3) return acos(((C*C-A*A-B*B)/(2*A*B)));
    }
    Tacka DajCentar() const{
        Tacka centar;
        centar.first=((a.first+b.first+c.first)/3);
        centar.second=((a.second+b.second+c.second)/3);
        return centar;
    };
    double DajObim() const{
        double obim=DajStranicu(1)+DajStranicu(2)+DajStranicu(3);
        return obim;
    };
    double DajPovrsinu() const{
        double povrsina= abs((a.first*(b.second - c.second) + b.first*(c.second - a.second) + c.first*(a.second-b.second))/2);
        return povrsina;
    };
    bool DaLiJePozitivnoOrijentiran() const{
        if(Orijentacija(a,b,c)==1) return true;
        else return false;
    };
    bool DaLiJeUnutra(const Tacka &t) const{
        if (Povrsina(t,a,b)+Povrsina(t,b,c)+Povrsina(t,a,c)-DajPovrsinu()<0.00000001 )return true;
        else return false;
    };
    void Ispisi() const{
        cout<<"(("<<a.first<<","<<a.second<<"),("<<b.first<<","<<b.second<<"),("<<c.first<<","<<c.second<<"))";
    };
    void Transliraj(double delta_x, double delta_y){
        if (a.first<0) a.first-=delta_x; 
        else a.first+=delta_x;
        if (b.first<0) b.first-=delta_x;
        else b.first+=delta_x;
        if (c.first<0) c.first-=delta_x;
        else c.first+=delta_x;
        if (a.second<0) a.second-=delta_y;
        else a.second+=delta_y;
        if (b.second<0) b.second-=delta_y;
        else b.second+=delta_y;
        if (c.second<0) c.second-=delta_y;
        else c.second+=delta_y;
    };
    void Centriraj(const Tacka &t){
        double delta_x=t.first-DajCentar().first;
        double delta_y=t.second-DajCentar().second;
        Transliraj(delta_x, delta_y);
        
    }
    void Rotiraj(const Tacka &t, double ugao){
        bool a1=false, a2=false;
        double a3, b3, c3;
        a3=t.first+(a.first-t.first)*cos(ugao)-(a.second-t.second)*sin(ugao);
        a.second=t.second+(a.first-t.first)*sin(ugao)+(a.second-t.second)*cos(ugao);
        b3=t.first+(b.first-t.first)*cos(ugao)-(b.second-t.second)*sin(ugao);
        b.second=t.second+(b.first-t.first)*sin(ugao)+(b.second-t.second)*cos(ugao);
        c3=t.first+(c.first-t.first)*cos(ugao)-(c.second-t.second)*sin(ugao);
        c.second=t.second+(c.first-t.first)*sin(ugao)+(c.second-t.second)*cos(ugao);
        c.first=c3;
        a.first=a3;
        b.first=b3;
    }
    void Skaliraj(const Tacka &t, double faktor){
        if (fabs(faktor)==(1e-10)*fabs(faktor)) throw std::domain_error("Nekorektan faktor skaliranja");
        a.first=t.first+faktor*(a.first-t.first);
        b.first=t.first+faktor*(b.first-t.first);
        c.first=t.first+faktor*(c.first-t.first);
        a.second=t.second+faktor*(a.second-t.second);
        b.second=t.second+faktor*(b.second-t.second);
        c.second=t.second+faktor*(c.second-t.second);
        if (faktor<0) Rotiraj(180);
    };
    void Rotiraj(double ugao){
        Rotiraj(DajCentar(), ugao);
    }
    void Skaliraj(double faktor){
        Skaliraj(DajCentar(), faktor);
    };
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);  
};
bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2){
    int broj1=0;
    for (int i=0; i<3; i++){
        for (int j=0; j<3;j++){
            if (t1.DajTjeme(i+1) == t2.DajTjeme(j+1))  { broj1++;break;}
        }
    }
    if (broj1==3) return true;
    else return false;
}

bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2){
    int broj1=0, broj2=0, broj3, broj4, broj5, broj6;
    double a1=t1.DajStranicu(1);
    double b1=t1.DajStranicu(2);
    double c1=t1.DajStranicu(3);
    double a2=t2.DajStranicu(1);
    double b2=t2.DajStranicu(2);
    double c2=t2.DajStranicu(3);
    double temp1, temp2, temp3, temp4, temp5, temp6;
    if (a1>b1 && a1>c1 && b1>c1) {temp1=a1; temp2=b1; temp3=c1;}
    if (a1>b1 && a1>c1 && c1>b1) {temp1=a1; temp2=c1; temp3=b1;}
    if (b1>a1 && b1>c1 && a1>c1) {temp1=b1; temp2=a1; temp3=c1;}
    if (b1>a1 && c1>a1 && b1>c1) {temp1=b1; temp2=c1; temp3=a1;}
    if (c1>b1 && c1>a1 && b1>a1) {temp1=c1; temp2=b1; temp3=a1;}
    if (c1>b1 && c1>a1 && a1>b1) {temp1=c1; temp2=a1; temp3=b1;}
    
    if (a2>b2 && a2>c2 && b2>c2) {temp4=a2; temp5=b2; temp6=c2;}
    if (a2>b2 && a2>c2 && c2>b2) {temp4=a2; temp5=c2; temp6=b2;}
    if (b2>a2 && b2>c2 && a2>c2) {temp4=b2; temp5=a2; temp6=c2;}
    if (b2>a2 && c2>a2 && b2>c2) {temp4=b2; temp5=c2; temp6=a2;}
    if (c2>b2 && c2>a2 && b2>a2) {temp4=c2; temp5=b2; temp6=a2;}
    if (c2>b2 && c2>a2 && a2>b2) {temp4=c2; temp5=a2; temp6=b2;}
    Tacka x1;
    if (temp1==a1) x1=t1.DajTjeme(1);
    else if (temp1==b1)  x1=t1.DajTjeme(2);
    else x1=t1.DajTjeme(3);
    Tacka x2;
    if (temp4==a2) x2=t2.DajTjeme(1);
    else if (temp4==b2) x2=t2.DajTjeme(2);
    else x2=t2.DajTjeme(3);
    Tacka y1;
    if (temp2==a1) y1=t1.DajTjeme(1);
    else if (temp2==b1) y1=t1.DajTjeme(1);
    else y1=t1.DajTjeme(3);
    Tacka y2;
    if (temp5==a2) y2=t2.DajTjeme(1);
    else if (temp5==b2) y2=t2.DajTjeme(2);
    else y2=t2.DajTjeme(3);
    Tacka z1;
    if (temp3==a1)  z1=t1.DajTjeme(1);
    else if (temp3=b1)  z1=t1.DajTjeme(2);
    else z1=t1.DajTjeme(3);
    Tacka z2;
    if (temp6==a2)  z2=t2.DajTjeme(1);
    else if (temp6==b2) z2=t2.DajTjeme(2);
    else z2=t2.DajTjeme(3);
    
    if (temp1==temp4 && temp2==temp5 && temp3==temp6 && Trougao::Orijentacija(x1, y1, z1)==Trougao::Orijentacija(x2, y2, z2)){
        return true;
    }
    else return false;
}
bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2){
    int broj1=0, broj2=0, broj3, broj4, broj5, broj6;
    double a1=t1.DajStranicu(1);
    double b1=t1.DajStranicu(2);
    double c1=t1.DajStranicu(3);
    double a2=t2.DajStranicu(1);
    double b2=t2.DajStranicu(2);
    double c2=t2.DajStranicu(3);
    double temp1, temp2, temp3, temp4, temp5, temp6;
    if (a1>b1 && a1>c1 && b1>c1) {temp1=a1; temp2=b1; temp3=c1;}
    if (a1>b1 && a1>c1 && c1>b1) {temp1=a1; temp2=c1; temp3=b1;}
    if (b1>a1 && b1>c1 && a1>c1) {temp1=b1; temp2=a1; temp3=c1;}
    if (b1>a1 && c1>a1 && b1>c1) {temp1=b1; temp2=c1; temp3=a1;}
    if (c1>b1 && c1>a1 && b1>a1) {temp1=c1; temp2=b1; temp3=a1;}
    if (c1>b1 && c1>a1 && a1>b1) {temp1=c1; temp2=a1; temp3=b1;}
    
    if (a2>b2 && a2>c2 && b2>c2) {temp4=a2; temp5=b2; temp6=c2;}
    if (a2>b2 && a2>c2 && c2>b2) {temp4=a2; temp5=c2; temp6=b2;}
    if (b2>a2 && b2>c2 && a2>c2) {temp4=b2; temp5=a2; temp6=c2;}
    if (b2>a2 && c2>a2 && b2>c2) {temp4=b2; temp5=c2; temp6=a2;}
    if (c2>b2 && c2>a2 && b2>a2) {temp4=c2; temp5=b2; temp6=a2;}
    if (c2>b2 && c2>a2 && a2>b2) {temp4=c2; temp5=a2; temp6=b2;}
    Tacka x1;
    if (temp1==a1) x1=t1.DajTjeme(1);
    else if (temp1==b1)  x1=t1.DajTjeme(2);
    else x1=t1.DajTjeme(3);
    Tacka x2;
    if (temp4==a2) x2=t2.DajTjeme(1);
    else if (temp4==b2) x2=t2.DajTjeme(2);
    else x2=t2.DajTjeme(3);
    Tacka y1;
    if (temp2==a1) y1=t1.DajTjeme(1);
    else if (temp2==b1) y1=t1.DajTjeme(1);
    else y1=t1.DajTjeme(3);
    Tacka y2;
    if (temp5==a2) y2=t2.DajTjeme(1);
    else if (temp5==b2) y2=t2.DajTjeme(2);
    else y2=t2.DajTjeme(3);
    Tacka z1;
    if (temp3==a1)  z1=t1.DajTjeme(1);
    else if (temp3=b1)  z1=t1.DajTjeme(2);
    else z1=t1.DajTjeme(3);
    Tacka z2;
    if (temp6==a2)  z2=t2.DajTjeme(1);
    else if (temp6==b2) z2=t2.DajTjeme(2);
    else z2=t2.DajTjeme(3);
    double razlika=fabs(temp1-temp4);
    if ( fabs(temp2-temp5)==razlika && (temp3-temp6)==razlika && Trougao::Orijentacija(x1, y1, z1)==Trougao::Orijentacija(x2, y2, z2)){
        return true;
    }
    else return false;

}
int main ()
{
    try{
        cout<<"Koliko zelite kreirati trouglova: ";
        int n;
        int brojilo=0;
        cin>>n;
        vector<shared_ptr<Trougao>> vek_pok;
        while (brojilo<n){
            Tacka a,b,c;
            cout<<"Unesite podatke za "<<brojilo+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
            cin>>a.first>>a.second>>b.first>>b.second>>c.first>>c.second;
            Trougao t1(a,b,c);
            double temp=t1.DajStranicu(1);
            double temp1=t1.DajStranicu(2);
            double temp2=t1.DajStranicu(3);
            if(temp+temp1<=temp2 || temp1+temp2<=temp || temp2+temp<=temp1){
              cout<<"Nekorektne pozicije tjemena, ponovite unos!"<<endl;
              continue;
            } 
            else{
            auto pok(std::make_shared<Trougao>(t1));
            vek_pok.push_back(pok);
            brojilo++;
            }
        }
        cout<<"Unesite vektor translacije (dx dy): ";
        double dx, dy;
        cin>>dx>>dy;
        cout<<"Unesite ugao rotacije: ";
        double ugao;
        cin>>ugao;
        cout<<"Unesite faktor skaliranja: ";
        double faktor;
        cin>>faktor;
        vector<shared_ptr<Trougao>> vek_pok1;
        vek_pok1.resize(n);
        transform(vek_pok.begin(), vek_pok.end(), vek_pok1.begin(), [faktor, ugao, dx, dy] (std::shared_ptr<Trougao> tro){ 
            tro->Transliraj(dx, dy); 
            tro->Rotiraj(tro->DajCentar(), ugao);
            tro->Skaliraj(tro->DajTjeme(1), faktor);
            return tro;
        });
        std::sort(vek_pok1.begin(), vek_pok1.end(), [](std::shared_ptr<Trougao> tro1, std::shared_ptr<Trougao> tro2 ){
            return (tro1->DajPovrsinu() < tro2->DajPovrsinu()); 
        });
        cout<<"Trouglovi nakon obavljenih transformacija:"<<endl;
        for_each(vek_pok1.begin(), vek_pok1.end(), [](std::shared_ptr<Trougao> tro1 ){
            tro1->Ispisi(); cout<<endl;
        });
        cout<<"Trougao sa najmanjim obimom: ";
       (*min_element(vek_pok1.begin(), vek_pok1.end(),[](std::shared_ptr<Trougao> tro1, std::shared_ptr<Trougao> tro2){
            return (tro1->DajObim()<tro2->DajObim());
        }))->Ispisi();
        
        int br=0;
        for (int i=0; i<vek_pok1.size(); i++){
            for (int j=i+1; j<vek_pok1.size(); j++){
                if (DaLiSuIdenticni(*vek_pok1[i], *vek_pok1[j])==true){ br++; break; }
            
            }
        }
        if (br!=0){
        cout<<"\nParovi identicnih trouglova:"<<endl;
        for (int i=0; i<vek_pok1.size(); i++){
            for (int j=i+1; j<vek_pok1.size(); j++){
                if (DaLiSuIdenticni(*vek_pok1[i], *vek_pok1[j])==true) {
                    vek_pok1[i]->Ispisi();
                    cout<<" i ";
                    vek_pok1[j]->Ispisi();
                    cout<<endl;
                 }
            
            }
        }
        }
        if (br==0) cout<<"\nNema identicnih trouglova!"<<endl;
        br=0;
         for (int i=0; i<vek_pok1.size(); i++){
            for (int j=i+1; j<vek_pok1.size(); j++){
                if (DaLiSuPodudarni(*vek_pok1[i], *vek_pok1[j])==true){ br++; break; }
            
            }
        }
        if (br!=0){
        cout<<"Parovi podudarnih trouglova:"<<endl;
        for (int i=0; i<vek_pok1.size(); i++){
            for (int j=i+1; j<vek_pok1.size(); j++){
                if (DaLiSuPodudarni(*vek_pok1[i], *vek_pok1[j])==true) {
                    vek_pok1[i]->Ispisi();
                    cout<<" i ";
                    vek_pok1[j]->Ispisi();
                    cout<<endl;
                }
            }
        
        }
        }
        if (br==0) cout<<"Nema podudarnih trouglova!"<<endl;
        br=0;
         for (int i=0; i<vek_pok1.size(); i++){
            for (int j=i+1; j<vek_pok1.size(); j++){
                if (DaLiSuPodudarni(*vek_pok1[i], *vek_pok1[j])==true){ br++; break; }
            
            }
        }
        if (br!=0){
        cout<<"Parovi slicnih trouglova:"<<endl;
        for (int i=0; i<vek_pok1.size(); i++){
            for (int j=i+1; j<vek_pok1.size(); j++){
                if (DaLiSuPodudarni(*vek_pok1[i], *vek_pok1[j])==true) {
                    vek_pok1[i]->Ispisi();
                    cout<<" i ";
                    vek_pok1[j]->Ispisi();
                    cout<<endl;
                }
            }
        }
        }
        if (br==0) cout<<"Nema slicnih trouglova!"<<endl;
    }
    catch(domain_error izuzetak){
        cout<<izuzetak.what()<<", ponovite unos!"<<endl;
    }
    catch(range_error izuzetak){
        cout<<izuzetak.what()<<", ponovite unos!"<<endl;
    }
    return 0;
}
