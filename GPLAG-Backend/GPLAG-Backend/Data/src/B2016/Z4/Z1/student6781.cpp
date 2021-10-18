#include <iostream>
#include <stdexcept>
#include <cmath>
#include <memory>
#include <vector>
using std::cout;
using std::cin;
typedef std::pair<double,double> Tacka;
const double eps = 1E-10;
bool UporediDvaBroja(double A,double B)
{
    return ((fabs(A-B)<eps));
}
class Trougao
{
    Tacka tacka[3];
public:

    static double Medzik(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        return (t1.first*(t2.second*t3.second)-t2.first*(t1.second-t3.second)-t3.first*(t1.second-t2.second));
    }

    static void ProvjeriIndex(const int indeks) {
        if(indeks!=1&&indeks!=2&&indeks!=3) { //posto samo mogu biti 1, 2, 3
            throw std::range_error("Nekorektan indeks");
        }

    }

    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        tacka[0]=t1;
        tacka[1]=t2;
        tacka[2]=t3;

    }

    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        tacka[0]=t1;
        tacka[1]=t2;
        tacka[2]=t3;

    }

    void Postavi(int indeks, const Tacka &t) {
        ProvjeriIndex(indeks);

        switch(indeks) {
        case 1:
            tacka[0]=t;
            break;
        case 2:
            tacka[1]=t;
            break;
        case 3:
            tacka[2]=t;
            break;
        }
    }

    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3) {

        if ( UporediDvaBroja(Medzik(t1,t2,t3),0)) {
            return 0;
        }
        if ( Medzik(t1,t2,t3)>0 ) {
            return 1;
        }
        if ( Medzik(t1,t2,t3)<0 ) {
            return -1;
        }
        return 0;
    }

    Tacka DajTjeme(int indeks) const {
        ProvjeriIndex(indeks);
        return tacka[indeks];
    }

    double DajStranicu(int indeks) const {
        ProvjeriIndex(indeks);
        switch(indeks) {
        case 1:
            return sqrt((tacka[2].first-tacka[1].first)+(tacka[2].second-tacka[1].second));

        case 2:
            return sqrt((tacka[0].first-tacka[2].first)+(tacka[0].second-tacka[2].second));

        case 3:
            return sqrt((tacka[0].first-tacka[1].first)+(tacka[0].second-tacka[1].second));
        }
        return 0; //pokusaj usutkavanja kompajlera
    }

    double DajUgao(int indeks) const {
        ProvjeriIndex(indeks);

        switch(indeks) {
        case 1:
            return acos(pow(DajStranicu(2),2)+pow(DajStranicu(3),2)-pow(DajStranicu(1),2))/(2*DajStranicu(2)*DajStranicu(3));
            break;
        case 2:
            return acos(pow(DajStranicu(1),2)+pow(DajStranicu(3),2)-pow(DajStranicu(2),2))/(2*DajStranicu(3)*DajStranicu(1));
            break;
        case 3:
            return acos(pow(DajStranicu(1),2)+pow(DajStranicu(2),2)-pow(DajStranicu(3),2))/(2*DajStranicu(1)*DajStranicu(2));
            break;
        }
        return 0;
    }

    Tacka DajCentar() const {
        Tacka centar;
        centar.first=(tacka[0].first+tacka[1].first+tacka[2].first)/3;
        centar.second=(tacka[0].second+tacka[1].second+tacka[2].second)/3;
        return centar;
    }

    double DajObim() const {
        double obim=0;
        for(int i=0; i<3; i++) {
            obim+=DajStranicu(i);
        }
        return obim;
    }

    double DajPovrsinu() const {
        return fabs(Medzik(tacka[0],tacka[1],tacka[2])/2);
    }

    bool DaLiJePozitivnoOrijentiran() const {
        return Orijentacija(tacka[0],tacka[1],tacka[2]);
    }

    bool DaLiJeUnutra(const Tacka &t) const {
        double povrsina1,povrsina2,povrsina3;
        povrsina1=fabs(Medzik(t,tacka[1],tacka[2])/2);
        povrsina2=fabs(Medzik(tacka[0],t,tacka[2])/2);
        povrsina3=fabs(Medzik(tacka[0],tacka[1],t)/2);
        return UporediDvaBroja(povrsina1+povrsina2+povrsina3,DajPovrsinu());
    }

    void Ispisi() const {
        cout<<"(("<<tacka[0].first<<","<<tacka[0].second<<"),("<<tacka[1].first<<","<<tacka[1].second<<"),("<<tacka[2].first<<","<<tacka[2].second<<"))";
    }
    void Transliraj(double delta_x, double delta_y) {
        tacka[0].first+=delta_x;
        tacka[1].first+=delta_x;
        tacka[2].first+=delta_x;

        tacka[0].second+=delta_y;
        tacka[1].second+=delta_y;
        tacka[2].second+=delta_y;
    }
    void Centriraj(const Tacka &t) {
        double delta_x=t.first-DajCentar().first,delta_y=t.second-DajCentar().second;
        Transliraj(delta_x,delta_y);

    }
    void Skaliraj(const Tacka &t, double faktor) {
        if(UporediDvaBroja(faktor,0)) {
            throw std::domain_error("Nekorektan faktor skaliranja");
        }
                double iks1,iks2,iks3,ips1,ips2,ips3;
        iks1=tacka[0].first;
        iks2=tacka[1].first;
        iks3=tacka[2].first;
        ips1=tacka[0].second;
        ips2=tacka[1].second;
        ips3=tacka[2].second;
        tacka[0].first=(t.first+faktor*(iks1-t.first));
        tacka[1].first=(t.first+faktor*( iks2-t.first));
        tacka[2].first=(t.first+faktor*(iks3-t.first));

        tacka[0].second=(t.second+faktor*(ips1-t.second));
        tacka[1].second=(t.second+faktor*(ips2-t.second));
        tacka[2].second=(t.second+faktor*(ips3-t.second));
    }
    void Rotiraj(const Tacka &t, double ugao) {
        double iks1,iks2,iks3,ips1,ips2,ips3;
        iks1=tacka[0].first;
        iks2=tacka[1].first;
        iks3=tacka[2].first;
        ips1=tacka[0].second;
        ips2=tacka[1].second;
        ips3=tacka[2].second;
        tacka[0].first=(t.first+(iks1-t.first)*cos(ugao)-(ips1-t.second)*sin(ugao));
        tacka[1].first=(t.first+(iks2-t.first)*cos(ugao)-(ips2-t.second)*sin(ugao));
        tacka[2].first=(t.first+(iks3-t.first)*cos(ugao)-(ips3-t.second)*sin(ugao));

        tacka[0].second=(t.second+(iks1-t.first)*sin(ugao)+(ips1-t.second)*cos(ugao));
        tacka[1].second=(t.second+(iks2-t.first)*sin(ugao)+(ips2-t.second)*cos(ugao));
        tacka[2].second=(t.second+(iks3-t.first)*sin(ugao)+(ips3-t.second)*cos(ugao));
    }
    void Rotiraj(double ugao) {
        Rotiraj(DajCentar(),ugao);
    }
    void Skaliraj(double faktor) {
        Skaliraj(DajCentar(),faktor);
    }
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);
};
bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2)
{
    //KRKANSKI USLOV ALERT
    if( ( UporediDvaBroja(t1.Trougao::DajTjeme(0).first,t2.Trougao::DajTjeme(0).first) && UporediDvaBroja(t1.Trougao::DajTjeme(0).second,t2.Trougao::DajTjeme(0).second))&&(UporediDvaBroja(t1.Trougao::DajTjeme(1).first,t2.Trougao::DajTjeme(1).first)&&UporediDvaBroja(t1.Trougao::DajTjeme(1).second,t2.Trougao::DajTjeme(1).second))&&(UporediDvaBroja(t1.Trougao::DajTjeme(2).first,t2.Trougao::DajTjeme(2).first)&&UporediDvaBroja(t1.Trougao::DajTjeme(2).second,t2.Trougao::DajTjeme(2).second)) ) {

        return true;
    } else if ( ( UporediDvaBroja(t1.Trougao::DajTjeme(1).first,t2.Trougao::DajTjeme(1).first) && UporediDvaBroja(t1.Trougao::DajTjeme(1).second,t2.Trougao::DajTjeme(1).second))&&(UporediDvaBroja(t1.Trougao::DajTjeme(2).first,t2.Trougao::DajTjeme(2).first)&&UporediDvaBroja(t1.Trougao::DajTjeme(2).second,t2.Trougao::DajTjeme(2).second))&&(UporediDvaBroja(t1.Trougao::DajTjeme(0).first,t2.Trougao::DajTjeme(0).first)&&UporediDvaBroja(t1.Trougao::DajTjeme(0).second,t2.Trougao::DajTjeme(0).second)) ) {

        return true;
    } else if ( ( UporediDvaBroja(t1.Trougao::DajTjeme(2).first,t2.Trougao::DajTjeme(2).first) && UporediDvaBroja(t1.Trougao::DajTjeme(2).second,t2.Trougao::DajTjeme(2).second))&&(UporediDvaBroja(t1.Trougao::DajTjeme(0).first,t2.Trougao::DajTjeme(0).first)&&UporediDvaBroja(t1.Trougao::DajTjeme(0).second,t2.Trougao::DajTjeme(0).second))&&(UporediDvaBroja(t1.Trougao::DajTjeme(1).first,t2.Trougao::DajTjeme(1).first)&&UporediDvaBroja(t1.Trougao::DajTjeme(1).second,t2.Trougao::DajTjeme(1).second)) ) {
        return true;
    }
    return false;
}

bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2)
{
    if( ( UporediDvaBroja(t1.Trougao::DajStranicu(0),t2.Trougao::DajStranicu(0)) && UporediDvaBroja(t1.Trougao::DajStranicu(0),t2.Trougao::DajStranicu(0)))&&(UporediDvaBroja(t1.Trougao::DajStranicu(1),t2.Trougao::DajStranicu(1))&&UporediDvaBroja(t1.Trougao::DajStranicu(1),t2.Trougao::DajStranicu(1)))&&(UporediDvaBroja(t1.Trougao::DajStranicu(2),t2.Trougao::DajStranicu(2))&&UporediDvaBroja(t1.Trougao::DajStranicu(2),t2.Trougao::DajStranicu(2))) ) {

        return true;
    } else if ( ( UporediDvaBroja(t1.Trougao::DajStranicu(1),t2.Trougao::DajStranicu(1)) && UporediDvaBroja(t1.Trougao::DajStranicu(1),t2.Trougao::DajStranicu(1)))&&(UporediDvaBroja(t1.Trougao::DajStranicu(2),t2.Trougao::DajStranicu(2))&&UporediDvaBroja(t1.Trougao::DajStranicu(2),t2.Trougao::DajStranicu(2)))&&(UporediDvaBroja(t1.Trougao::DajStranicu(0),t2.Trougao::DajStranicu(0))&&UporediDvaBroja(t1.Trougao::DajStranicu(0),t2.Trougao::DajStranicu(0))) ) {

        return true;
    } else if ( ( UporediDvaBroja(t1.Trougao::DajStranicu(2),t2.Trougao::DajStranicu(2)) && UporediDvaBroja(t1.Trougao::DajStranicu(2),t2.Trougao::DajStranicu(2)))&&(UporediDvaBroja(t1.Trougao::DajStranicu(0),t2.Trougao::DajStranicu(0))&&UporediDvaBroja(t1.Trougao::DajStranicu(0),t2.Trougao::DajStranicu(0)))&&(UporediDvaBroja(t1.Trougao::DajStranicu(1),t2.Trougao::DajStranicu(1))&&UporediDvaBroja(t1.Trougao::DajStranicu(1),t2.Trougao::DajStranicu(1))) ) {
        return true;
    }
    return false;

}
bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2)
{
    if( ( UporediDvaBroja(t1.Trougao::DajUgao(0),t2.Trougao::DajUgao(0)) && UporediDvaBroja(t1.Trougao::DajUgao(0),t2.Trougao::DajUgao(0)))&&(UporediDvaBroja(t1.Trougao::DajUgao(1),t2.Trougao::DajUgao(1))&&UporediDvaBroja(t1.Trougao::DajUgao(1),t2.Trougao::DajUgao(1)))&&(UporediDvaBroja(t1.Trougao::DajUgao(2),t2.Trougao::DajUgao(2))&&UporediDvaBroja(t1.Trougao::DajUgao(2),t2.Trougao::DajUgao(2))) ) {

        return true;
    } else if ( ( UporediDvaBroja(t1.Trougao::DajUgao(1),t2.Trougao::DajUgao(1)) && UporediDvaBroja(t1.Trougao::DajUgao(1),t2.Trougao::DajUgao(1)))&&(UporediDvaBroja(t1.Trougao::DajUgao(2),t2.Trougao::DajUgao(2))&&UporediDvaBroja(t1.Trougao::DajUgao(2),t2.Trougao::DajUgao(2)))&&(UporediDvaBroja(t1.Trougao::DajUgao(0),t2.Trougao::DajUgao(0))&&UporediDvaBroja(t1.Trougao::DajUgao(0),t2.Trougao::DajUgao(0))) ) {

        return true;
    } else if ( ( UporediDvaBroja(t1.Trougao::DajUgao(2),t2.Trougao::DajUgao(2)) && UporediDvaBroja(t1.Trougao::DajUgao(2),t2.Trougao::DajUgao(2)))&&(UporediDvaBroja(t1.Trougao::DajUgao(0),t2.Trougao::DajUgao(0))&&UporediDvaBroja(t1.Trougao::DajUgao(0),t2.Trougao::DajUgao(0)))&&(UporediDvaBroja(t1.Trougao::DajUgao(1),t2.Trougao::DajUgao(1))&&UporediDvaBroja(t1.Trougao::DajUgao(1),t2.Trougao::DajUgao(1))) ) {
        return true;
    }
    return false;
}
int main ()
{
    std::vector<std::shared_ptr<Trougao>> vektor;
    Tacka unos[3];
    int n;
    cout<<"Koliko zelite kreirati trouglova: ";
    cin>>n;
    for(int i=0; i<n; i++) {
        cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
        cin>>unos[0].first>>unos[0].second>>unos[1].first>>unos[1].second>>unos[2].first>>unos[2].second;

        auto p=std::make_shared<Trougao>(unos[0],unos[1],unos[2]);
        vektor.push_back(p);
    }
    cout<<"Unesite vektor translacije (dx dy): ";
    double dx,dy;
    cin>>dx>>dy;
    double ugaorotacije;
    cout<<"Unesite ugao rotacije: ";
    cin>>ugaorotacije;
    double faktorskaliranja;
    cout<<"Unesite faktor skaliranja: ";
    cin>>faktorskaliranja;
    cout<<"Trouglovi nakon obavljenih transformacija: \n";

    for(int i=0; i<n; i++) {
        vektor[i]->Transliraj(dx,dy); //a ok
        vektor[i]->Rotiraj(ugaorotacije); //prolly ok,myb not
        vektor[i]->Skaliraj(vektor[i]->DajCentar(),faktorskaliranja);
        vektor[i]->Ispisi();
        cout<<"\n";
    }



    return 0;
}