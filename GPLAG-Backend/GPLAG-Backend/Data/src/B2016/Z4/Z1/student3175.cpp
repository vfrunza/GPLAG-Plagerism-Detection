/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <vector>
using namespace std;

typedef std::pair<double, double> Tacka;

class Trougao
{
    Tacka T1,T2,T3;
    public:
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3)
    {
        T1=t1; T2=t2; T3=t3;
    }
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3)
    {
        T1=t1; T2=t2; T3=t3;
    }
    void Postavi(int indeks, const Tacka &t)
    {
        if(indeks!=1 && indeks!=2 && indeks!=3) throw range_error("Nekorektan indeks");
        if(indeks==1) T1=t;
        else if(indeks==2) T2=t;
        else T3=t;
    }
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3)
    {
        double n= t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second);
        if(n>0) return 1;
        else if(n<0) return -1;
        else return 0;
    }
    Tacka DajTjeme(int indeks) const
    {
        if(indeks!=1 && indeks!=2 && indeks!=3) throw range_error("Nekorektan indeks");
        if(indeks==1) return T1;
        else if(indeks==2) return T2;
        else return T3;
    }
    double DajStranicu(int indeks) const
    {
        if(indeks!=1 && indeks!=2 && indeks!=3) throw range_error("Nekorektan indeks");
        if(indeks==1) return sqrt(pow((T2.first-T3.first),2)+pow((T2.second-T3.second),2));
        else if(indeks==2) return sqrt(pow((T1.first-T3.first),2)+pow((T1.second-T3.second),2));
        else return sqrt(pow((T2.first-T1.first),2)+pow((T2.second-T1.second),2));
    }
    double DajUgao(int indeks) const
    {
        if(indeks!=1 && indeks!=2 && indeks!=3) throw range_error("Nekorektan indeks");
        double a=DajStranicu(1), b=DajStranicu(2), c=DajStranicu(3);
        if(indeks==1) return acos((b*b+c*c-a*a)/(2*b*c))*(180/(atan(1)*4));
        else if(indeks==2) return acos((a*a+c*c-b*b)/(2*a*c))*(180/(atan(1)*4));
        else return acos((b*b+a*a-c*c)/(2*b*a))*(180/(atan(1)*4));
    }
    Tacka DajCentar() const
    {
        Tacka t=make_pair((T1.first+T2.first+T3.first)/3,(T1.second+T2.second+T3.second)/3);
        return t;
    }
    double DajObim() const
    {
        return DajStranicu(1)+DajStranicu(2)+DajStranicu(3);
    }
    double DajPovrsinu() const
    {
        return abs(T1.first*(T2.second-T3.second)-T2.first*(T1.second-T3.second)+T3.first*(T1.second-T2.second))/2;
    }
    bool DaLiJePozitivnoOrijentiran() const
    {
        return (T1.first*(T2.second-T3.second)-T2.first*(T1.second-T3.second)+T3.first*(T1.second-T2.second) > 0);
    }
    bool DaLiJeUnutra(const Tacka &t) const
    {
        if(Orijentacija(T1,T2,T3)==1)
        {
            if(Orijentacija(T1,T2,t)==1 && Orijentacija(T2,T3,t)==1 && Orijentacija(T3,T1,t)==1) return true;
            else return false;
        }
        if(Orijentacija(T1,T2,T3)==-1)
        {
            if(Orijentacija(T1,T2,t)==-1 && Orijentacija(T2,T3,t)==-1 && Orijentacija(T3,T1,t)==-1) return true;
            else return false;
        }
    }
    void Ispisi() const
    {
        cout<<"(("<<T1.first<<","<<T1.second<<"),("<<T2.first<<","<<T2.second<<"),("<<T3.first<<","<<T3.second<<"))";
    }
    void Transliraj(double delta_x, double delta_y)
    {
        T1=make_pair(T1.first+delta_x, T1.second+delta_y);
        T2=make_pair(T2.first+delta_x, T2.second+delta_y);
        T3=make_pair(T3.first+delta_x, T3.second+delta_y);
    }
    void Centriraj(const Tacka &t)
    {
        Tacka p=DajCentar();
        double dx=t.first-p.first, dy=t.second-p.second;
        Transliraj(dx,dy);
    }
    void Rotiraj(const Tacka &t, double ugao)
    {
        T1=make_pair(t.first+(t.first-T1.first)*cos(ugao)-(t.second-T1.second)*sin(ugao), t.second+(t.first-T1.first)*sin(ugao)-(t.second-T1.second)*cos(ugao));
        T2=make_pair(t.first+(t.first-T2.first)*cos(ugao)-(t.second-T2.second)*sin(ugao), t.second+(t.first-T2.first)*sin(ugao)-(t.second-T2.second)*cos(ugao));
        T1=make_pair(t.first+(t.first-T3.first)*cos(ugao)-(t.second-T3.second)*sin(ugao), t.second+(t.first-T3.first)*sin(ugao)-(t.second-T3.second)*cos(ugao));
    }
    void Skaliraj(const Tacka &t, double faktor)
    {
        if(faktor==0) throw domain_error("Nekorektan faktor skaliranja");
        T1=make_pair(t.first+faktor*(T1.first-t.first), t.second+faktor*(T1.second-t.second));
        T2=make_pair(t.first+faktor*(T2.first-t.first), t.second+faktor*(T2.second-t.second));
        T3=make_pair(t.first+faktor*(T3.first-t.first), t.second+faktor*(T3.second-t.second));
    }
    void Rotiraj(double ugao)
    {
        Rotiraj(DajCentar(),ugao);
    }
    void Skaliraj(double faktor)
    {
        Skaliraj(DajCentar(),faktor);
    }
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2)
    {
        int br1=0, br2=0, br3=0;
        if(t1.T1.first==t2.T1.first && t1.T1.second==t2.T1.second) br1++;
        if(t1.T1.first==t2.T2.first && t1.T1.second==t2.T2.second) br1++;
        if(t1.T1.first==t2.T3.first && t1.T1.second==t2.T3.second) br1++;
        if(t1.T2.first==t2.T1.first && t1.T2.second==t2.T1.second) br2++;
        if(t1.T2.first==t2.T2.first && t1.T2.second==t2.T2.second) br2++;
        if(t1.T2.first==t2.T3.first && t1.T2.second==t2.T3.second) br2++;
        if(t1.T3.first==t2.T1.first && t1.T3.second==t2.T1.second) br3++;
        if(t1.T3.first==t2.T2.first && t1.T3.second==t2.T2.second) br3++;
        if(t1.T3.first==t2.T3.first && t1.T3.second==t2.T3.second) br3++;
        return (br1==1 && br2==1 && br3==1);
    }
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2)
    {
        
    }
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2); 
};

int main ()
{
	 int n;
    cout<<"Koliko zelite kreirati trouglova: ";
    cin>>n;
    vector<Trougao> v;
    
    for(int i=0;i<n;i++)
    {   
        
        try
        {
        cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
        Tacka t1,t2,t3;
        cin>>t1.first>>t1.second;
        cin>>t2.first>>t2.second;
        cin>>t3.first>>t3.second;
        
          Trougao t(t1,t2,t3);
          v.push_back(t);
         
        }
        catch(domain_error e)
        {
            cin.clear();
            cin.ignore(10000,'\n');
            i--;
            cout<<e.what()<<", ponovite unos!" << endl;
        
        }
        
    }
    
    cout<<"Unesite vektor translacije (dx dy) : ";
    double a,b;
    cin>>a>>b;
    cout<<"Unesite ugao rotacije: ";
    double r;
    cin>>r;
    cout<<"Unesite faktor skaliranja: ";
    double s;
    cin>>s;
    
    cout<<"Trouglovi nakon obavljenih transformacija: "<<endl;
    for(int i=0;i<v.size();i++)
    {
        v[i].Transliraj(a,b);
        v[i].Rotiraj(r);
        v[i].Skaliraj(v[i].DajTjeme(1),s);
        v[i].Ispisi();
    }
    
    
	return 0;
}