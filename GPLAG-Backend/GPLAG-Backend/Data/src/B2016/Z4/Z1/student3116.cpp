/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <vector>
#include <algorithm>


using namespace std;

typedef pair<double, double> Tacka;

  bool JesuIsti(double d1,double d2)
        {
            const double eps=1E-10;
            if(fabs(d1-d2)<=eps*(fabs(d1)+fabs(d2)))return true;
            return false;
        }

class Trougao
{
    Tacka t1,t2,t3;

     
        
    public:
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3)
    {   
        if (JesuIsti(t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second),0)) throw domain_error("Nekorektne pozicije tjemena");
        Trougao::t1=t1;
        Trougao::t2=t2;
        Trougao::t3=t3;
    }
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3)
    {   
        if (JesuIsti(t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second),0)) throw domain_error("Nekorektne pozicije tjemena");
        Trougao::t1=t1;
        Trougao::t2=t2;
        Trougao::t3=t3;
    }
    void Postavi(int indeks, const Tacka &t)
    {
        switch(indeks)
        {
            case 1:Trougao::t1=t;break;
            case 2:Trougao::t2=t;break;
            case 3:Trougao::t3=t;break;
            default: throw range_error("Nekorektan indeks");
        }
       
    }
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3)
    {
        static int o=t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second);
        
        if(o>0) return 1;
        else if(o<0) return -1;
        return 0;
    }
    Tacka DajTjeme(int indeks) const
    {
        switch(indeks)
        {
            case 1:return t1;
            case 2:return t2;
            case 3:return t3;
        }
        throw range_error("Nekorektan indeks");
    }
    double DajStranicu(int indeks) const
    {
        switch(indeks)
        {
            case 1:return sqrt((t2.first-t3.first)*(t2.first-t3.first)+(t2.second-t3.second)*(t2.second-t3.second));
            case 2:return sqrt((t1.first-t3.first)*(t1.first-t3.first)+(t1.second-t3.second)*(t1.second-t3.second));
            case 3:return sqrt((t1.first-t2.first)*(t1.first-t2.first)+(t1.second-t2.second)*(t1.second-t2.second));
        }
        throw range_error("Nekorektan indeks");
    }
    double DajUgao(int indeks) const
    {
        switch(indeks)
        {
            case 1:return acos((DajStranicu(2)*DajStranicu(2)+DajStranicu(3)*DajStranicu(3)-DajStranicu(1)*DajStranicu(1))/(2*DajStranicu(3)*DajStranicu(2)));
            case 2:return acos((DajStranicu(1)*DajStranicu(1)+DajStranicu(3)*DajStranicu(3)-DajStranicu(2)*DajStranicu(2))/(2*DajStranicu(1)*DajStranicu(3)));
            case 3:return acos((DajStranicu(1)*DajStranicu(1)+DajStranicu(2)*DajStranicu(2)-DajStranicu(3)*DajStranicu(3))/(2*DajStranicu(1)*DajStranicu(2)));
        }
        throw range_error("Nekorektan indeks");
    }
    Tacka DajCentar() const
    {
        Tacka c;
        c.first=(t1.first+t2.first+t3.first)/3;
        c.second=(t1.second+t2.second+t3.second)/3;
        return c;
    }
    double DajObim() const
    {
        return DajStranicu(1)+DajStranicu(2)+DajStranicu(3);
    }
    double DajPovrsinu() const
    {
        return (1/2.)*(abs(t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second)));
    }
    
    bool DaLiJePozitivnoOrijentiran() const
    {
        return Orijentacija(this->t1,this->t2,this->t3);
    }
    
    bool DaLiJeUnutra(const Tacka &t) const
    {
        if(Orijentacija(this->t1,this->t2,this->t3)>0 && Orijentacija(this->t1,this->t2,t)>0 && Orijentacija(this->t1,t,this->t3)>0 && Orijentacija(t,this->t2,this->t3)>0)
           return true;
        
        if(Orijentacija(this->t1,this->t2,this->t3)<0 && Orijentacija(this->t1,this->t2,t)<0 && Orijentacija(this->t1,t,this->t3)<0 && Orijentacija(t,this->t2,this->t3)<0)
           return true;
        
        return false;        
    }
    void Ispisi() const
    {
        cout<<"("<<"("<<t1.first<<","<<t1.second<<"),"<<"("<<t2.first<<","<<t2.second<<"),"<<"("<<t3.first<<","<<t3.second<<")"<<")";
    }
    
    void Transliraj(double delta_x, double delta_y)
    {
        Trougao::t1.first+=delta_x;
        Trougao::t2.first+=delta_x;
        Trougao::t3.first+=delta_x;
        
        Trougao::t1.second+=delta_y;
        Trougao::t2.second+=delta_y;
        Trougao::t3.second+=delta_y;
    }
    void Centriraj(const Tacka &t)
    {
        Transliraj(t.first,t.second);
    }
    void Rotiraj(const Tacka &t, double ugao)
    {
        
        Trougao::t1.first=t.first+(Trougao::t1.first-t.first)*cos(ugao)-(Trougao::t1.second-t.second)*sin(ugao);
        Trougao::t2.first=t.first+(Trougao::t2.first-t.first)*cos(ugao)-(Trougao::t2.second-t.second)*sin(ugao);
        Trougao::t3.first=t.first+(Trougao::t3.first-t.first)*cos(ugao)-(Trougao::t3.second-t.second)*sin(ugao);
    
        Trougao::t1.second=t.second+(Trougao::t1.first-t.first)*sin(ugao)+(Trougao::t1.second-t.second)*cos(ugao);
        Trougao::t2.second=t.second+(Trougao::t2.first-t.first)*sin(ugao)+(Trougao::t2.second-t.second)*cos(ugao);
        Trougao::t3.second=t.second+(Trougao::t3.first-t.first)*sin(ugao)+(Trougao::t3.second-t.second)*cos(ugao);
        
            
    }
    void Skaliraj(const Tacka &t, double faktor)
    {
        if(JesuIsti(faktor,0)) throw domain_error("Nekorektan faktor skaliranja");
        
        Trougao::t1.first=t.first+faktor*(Trougao::t1.first-t.first);
        Trougao::t1.second=t.second+faktor*(Trougao::t1.second-t.second);
        Trougao::t2.first=t.first+faktor*(Trougao::t2.first-t.first);
        Trougao::t2.second=t.second+faktor*(Trougao::t2.second-t.second);
        Trougao::t3.first=t.first+faktor*(Trougao::t3.first-t.first);
        Trougao::t3.second=t.second+faktor*(Trougao::t3.second-t.second);
        
        if(faktor<0) Rotiraj(atan(1)*4);
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
            if (JesuIsti(t1.DajCentar().first,t2.DajCentar().first) && JesuIsti(t1.DajCentar().second,t2.DajCentar().second)) return true;
            return false;
    }
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2)
    {
       
        for(int i=1;i<4;i++)
        {
            bool jeste=false;
                for(int j=1;j<4;j++)
                {
                    if(JesuIsti(t1.DajStranicu(i),t2.DajStranicu(j)) && JesuIsti(t1.DajUgao(i),t2.DajUgao(j)))
                       { jeste=true;break;}
                }
            if(jeste==false) return false;
        }
        
         return true;
    }
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2)
    {
        if (JesuIsti(t1.DajStranicu(1)/t2.DajStranicu(1),t1.DajStranicu(2)/t2.DajStranicu(2)) && JesuIsti(t1.DajStranicu(1)/t2.DajStranicu(1),t1.DajStranicu(3)/t2.DajStranicu(3))&& JesuIsti(t1.DajStranicu(2)/t2.DajStranicu(2),t1.DajStranicu(3)/t2.DajStranicu(3)) ) return true;
        return false;
    }


 

int main ()
{
    int n;
    cout<<"Koliko zelite kreirati trouglova: ";
    cin>>n;
    vector<Trougao> v;
    
    for(int i=0;i<n;i++)
    {   
        cin.clear();
        cin.ignore(10000,'\n');
        cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
        Tacka t1,t2,t3;
        cin>>t1.first>>t1.second;
        cin>>t2.first>>t2.second;
        cin>>t3.first>>t3.second;

        try
        { 
          Trougao t(t1,t2,t3);
          v.push_back(t);
        }
        catch(domain_error e)
        {   
            i--;
            cout<<e.what()<<", ponovite unos!" << endl;
        }
        
    }
    
    cout<<"Unesite vektor translacije (dx dy) :";
    double a,b;
    cin>>a>>b;
    cout<<"Unesite ugao rotacije: ";
    double r;
    cin>>r;
    cout<<"Unesite faktor skaliranja: ";
    double s;
    cin>>s;
    
    cout<<"Trouglovi nakon obavljenih transformacija:"<<endl;
    for(int i=0;i<v.size();i++)
    {  
        v[i].Transliraj(a,b);
        v[i].Rotiraj(r);
        v[i].Skaliraj(v[i].DajTjeme(1),s);
    }
    sort(v.begin(),v.end(),[](Trougao t1,Trougao t2){return t1.DajPovrsinu()<t2.DajPovrsinu();});
    
    for(int i=0;i<v.size();i++){
        v[i].Ispisi();cout<<endl;}
        
    auto it=min_element(v.begin(),v.end(),[](Trougao t1,Trougao t2){return t1.DajObim()<t2.DajObim();});
    cout<<"Trougao sa najmanjim obimom: ";it->Ispisi();cout<<endl;
    
    vector<pair<Trougao,Trougao>> Identicni;
    for(int i=0;i<v.size()-1;i++)
    {
        for(int j=i+1;j<v.size();j++)
        {
            if(DaLiSuIdenticni(v[i],v[j]))
                Identicni.push_back(make_pair(v[i],v[j]));
        }
    }
    
    if(Identicni.size()==0) cout<<"Nema identicnih trouglova!"<<endl;
    else cout<<"Parovi identicnih trouglova:"<<endl;
    for(int i=0;i<Identicni.size();i++){
        Identicni[i].first.Ispisi();cout<<" i ";Identicni[i].second.Ispisi();cout<<endl;
    }
    
    
    vector<pair<Trougao,Trougao>> Podudarni;
    for(int i=0;i<v.size()-1;i++)
    {
        for(int j=i+1;j<v.size();j++)
        {
            if(DaLiSuPodudarni(v[i],v[j]))
                Podudarni.push_back(make_pair(v[i],v[j]));
        }
    }
    if(Podudarni.size()==0) cout<<"Nema podudarnih trouglova!"<<endl;
    else cout<<"Parovi podudarnih trouglova:"<<endl;
    for(int i=0;i<Podudarni.size();i++)
    {
        Podudarni[i].first.Ispisi();cout<<" i ";Podudarni[i].second.Ispisi();cout<<endl;
    }
    
    vector<pair<Trougao,Trougao>> Slicni;
    for(int i=0;i<v.size()-i;i++)
    {
        for(int j=i+1;j<v.size();j++)
        {
            if(DaLiSuSlicni(v[i],v[j]))
                Slicni.push_back(make_pair(v[i],v[j]));
        }
    }
    
    
    if(Slicni.size()==0) cout<<"Nema slicnih trouglova!"<<endl;
    else cout<<"Parovi slicnih trouglova:"<<endl;
    for(int i=0;i<Slicni.size();i++){
        Slicni[i].first.Ispisi();cout<<" i ";Slicni[i].second.Ispisi();cout<<endl;
    }
    

	return 0;
}