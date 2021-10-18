/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <cmath>
#include <memory>
#include <vector>
#define PI 4*atan(1)

using std::cin;
using std::cout;
using std::endl;
using std::pair;
using std::vector;
using std::shared_ptr;
using std::transform;
using std::sort;
using std::for_each;
using std::min_element;
using std::make_shared;
using std::sqrt;
using std::pow;
using std::sin;
using std::cos;
using std::abs;
using std::acos;
using std::domain_error;
using std::range_error;

typedef pair<double,double> Tacka;
const double eps (0.00000000001);

class Trougao
{
    Tacka ta1,ta2,ta3;
    
    public:
    Trougao (const Tacka &t1, const Tacka &t2, const Tacka &t3)
     {
        ta1=t1;
        ta2=t2;
        ta3=t3;
        
        if (Orijentacija(ta1,ta2,ta3)==0) throw domain_error ("Nekorektne pozicije tjemena");
    };
    
    void Postavi (const Tacka &t1, const Tacka &t2, const Tacka &t3)
    {
        ta1=t1;
        ta2=t2;
        ta3=t3;
        
        if (Orijentacija(ta1,ta2,ta3)==0) throw domain_error ("Nekorektne pozicije tjemena");
    };
    
    void Postavi(int indeks, const Tacka &t)
    {
        if (indeks==1)
        {
            ta1=t;
            if (Orijentacija(ta1,ta2,ta3)==0) throw domain_error ("Nekorektne pozicije tjemena");
        }
        
        else if (indeks==2)
        {
            ta2=t;
            if (Orijentacija(ta1,ta2,ta3)==0) throw domain_error ("Nekorektne pozicije tjemena");
        }
        
        else if (indeks==3)
        {
            ta3=t;
            if (Orijentacija(ta1,ta2,ta3)==0) throw domain_error ("Nekorektne pozicije tjemena");
        }
        
        else 
        {
            throw range_error ("Nekorektan indeks");
        }
    };
    
    static int Orijentacija (const Tacka &t1, const Tacka &t2, const Tacka &t3)
    {
        double racun;
        int rez;
        
        racun=t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second);
        
        if (racun>0)
        {
            rez=1;
        }
        
        if (racun<0)
        {
            rez=-1;
        }
        
        if (racun==0)
        {
            rez=0;
        }
        
        return rez;
    };
    
    Tacka DajTjeme (int indeks) const 
    {
        if (indeks==1)
        {
            return ta1;
        }
        
        else if (indeks==2)
        {
            return ta2;
        }
        
        else if (indeks==3)
        {
            return ta3;
        }
        
        else 
        {
            throw range_error ("Nekorektan indeks");
        }
    };
    
    double DajStranicu (int indeks) const
    {
        double rez;
        
        if (indeks==1)
        {
            rez=sqrt(pow((ta3.first-ta2.first),2)+pow((ta3.second-ta2.second),2));
            return rez;
        }
        
        else if (indeks==2)
        {
            rez=sqrt(pow((ta3.first-ta1.first),2)+pow((ta3.second-ta1.second),2));
            return rez;
        }
        
        else if (indeks==3)
        {
            rez=sqrt(pow((ta2.first-ta1.first),2)+pow((ta2.second-ta1.second),2));
            return rez;
        }
        
        else 
        {
            throw range_error ("Nekorektan indeks");
        }
    };
    
    double DajUgao (int indeks) const
    {
        double rez, a, b, c;
        a=DajStranicu(1);
        b=DajStranicu(2);
        c=DajStranicu(3);
        
        if (indeks==1)
        {
            rez=acos(((c*c)+(b*b)-(a*a))/(2*b*c));
            return rez;
        }
        
        else if (indeks==2)
        {
            rez=acos(((c*c)+(a*a)-(b*b))/(2*a*c));
            return rez;
        }
        
        else if (indeks==3)
        {
            rez=acos(((a*a)+(b*b)-(c*c))/(2*a*b));
            return rez;
        }
        
        else 
        {
            throw range_error ("Nekorektan indeks");
        }
    };
    
    Tacka DajCentar() const
    {
        Tacka rez;
        
        rez.first=(ta1.first+ta2.first+ta3.first)/3;
        rez.second=(ta1.second+ta2.second+ta3.second)/3;
        
        return rez;
    };
    
    double DajObim() const
    {
        double rez, a, b, c;
        a=DajStranicu(1);
        b=DajStranicu(2);
        c=DajStranicu(3);
        
        rez=a+b+c;
        
        return rez;
    };
    
    double DajPovrsinu() const
    {
        double rez;
        
        rez=0.5*(abs(ta1.first*(ta2.second-ta3.second)-ta2.first*(ta1.second-ta3.second)+ta3.first*(ta1.second-ta2.second)));
        
        return rez;
    };
    
    bool DaLiJePozitivnoOrijentiran() const
    {
        bool tacnost(false);
        
        if (Orijentacija(ta1,ta2,ta3)==1)
        {
            tacnost=true;
        }
        
        return tacnost;
    };
    
    bool DaLiJeUnutra (const Tacka &t) const
    {
        bool tacnost(false);

      double d, up1, up2, str1, str2, str3;
      
      d=(ta2.second-ta3.second)*(ta1.first-ta3.first)+(ta3.first-ta2.first)*(ta1.second-ta3.second);
      up1=(ta2.second-ta3.second)*(t.first-ta3.first)+(ta3.first-ta2.first)*(t.second-ta3.second);
      up2=(ta3.second-ta1.second)*(t.first-ta3.first)+(ta1.first-ta3.first)*(t.second-ta3.second);
      str1=up1/d;
      str2=up2/d;
      str3=1-str1-str2;
      
      if ((str1>0&&str1<1)&&(str2>0&&str2<1)&&(str3>0&&str3<1))
      {
          tacnost=true;
      }
      
      return tacnost;
    };
    
    void Ispisi() const {cout<<"(("<<ta1.first<<","<<ta1.second<<"),("<<ta2.first<<","<<ta2.second<<"),("<<ta3.first<<","<<ta3.second<<"))";};
    
    void Transliraj (double delta_x, double delta_y)
    {
        ta1.first=ta1.first+delta_x;
        ta1.second=ta1.second+delta_y;
        ta2.first=ta2.first+delta_x;
        ta2.second=ta2.second+delta_y;
        ta3.first=ta3.first+delta_x;
        ta3.second=ta3.second+delta_y;
    };
    
    void Centriraj (const Tacka &t)
    {
        Tacka centar;
        double delta_x, delta_y;
        
        centar=DajCentar();
        
        delta_x=t.first-centar.first;
        delta_y=t.second-centar.second;
        
        ta1.first=ta1.first+delta_x;
        ta1.second=ta1.second+delta_y;
        ta2.first=ta2.first+delta_x;
        ta2.second=ta2.second+delta_y;
        ta3.first=ta3.first+delta_x;
        ta3.second=ta3.second+delta_y;
    };
    
    void Rotiraj (const Tacka &t, double ugao)
    {
        Tacka backup;
        
        backup.first=ta1.first;
        ta1.first=t.first+(ta1.first-t.first)*cos(ugao)-(ta1.second-t.second)*sin(ugao);
        ta1.second=t.second+(backup.first-t.first)*sin(ugao)+(ta1.second-t.second)*cos(ugao);
        
        backup.first=ta2.first;
        ta2.first=t.first+(ta2.first-t.first)*cos(ugao)-(ta2.second-t.second)*sin(ugao);
        ta2.second=t.second+(backup.first-t.first)*sin(ugao)+(ta2.second-t.second)*cos(ugao);
        
        backup.first=ta3.first;
        ta3.first=t.first+(ta3.first-t.first)*cos(ugao)-(ta3.second-t.second)*sin(ugao);
        ta3.second=t.second+(backup.first-t.first)*sin(ugao)+(ta3.second-t.second)*cos(ugao);
    };
    
    void Skaliraj (const Tacka &t, double faktor)
    {
        if (faktor==0) throw domain_error ("Nekorektan faktor skaliranja");
        
        else if (faktor<0)
        {
            faktor=abs(faktor);
            ta1.first=t.first+faktor*(ta1.first-t.first);
            ta1.second=t.second+faktor*(ta1.second-t.second);
            ta2.first=t.first+faktor*(ta2.first-t.first);
            ta2.second=t.second+faktor*(ta2.second-t.second);
            ta3.first=t.first+faktor*(ta3.first-t.first);
            ta3.second=t.second+faktor*(ta3.second-t.second);
            
            Rotiraj(PI);
        }
        
        else
        {
            ta1.first=t.first+faktor*(ta1.first-t.first);
            ta1.second=t.second+faktor*(ta1.second-t.second);
            ta2.first=t.first+faktor*(ta2.first-t.first);
            ta2.second=t.second+faktor*(ta2.second-t.second);
            ta3.first=t.first+faktor*(ta3.first-t.first);
            ta3.second=t.second+faktor*(ta3.second-t.second);
        }
    };
    
    void Rotiraj (double ugao)
    {
        Tacka t, backup;
        t=DajCentar();
        
        backup.first=ta1.first;
        ta1.first=t.first+(ta1.first-t.first)*cos(ugao)-(ta1.second-t.second)*sin(ugao);
        ta1.second=t.second+(backup.first-t.first)*sin(ugao)+(ta1.second-t.second)*cos(ugao);
        
        backup.first=ta2.first;
        ta2.first=t.first+(ta2.first-t.first)*cos(ugao)-(ta2.second-t.second)*sin(ugao);
        ta2.second=t.second+(backup.first-t.first)*sin(ugao)+(ta2.second-t.second)*cos(ugao);
        
        backup.first=ta3.first;
        ta3.first=t.first+(ta3.first-t.first)*cos(ugao)-(ta3.second-t.second)*sin(ugao);
        ta3.second=t.second+(backup.first-t.first)*sin(ugao)+(ta3.second-t.second)*cos(ugao);
    };
    
    void Skaliraj (double faktor)
    {
        Tacka t;
        t=DajCentar();
        
        if (faktor==0) throw domain_error ("Nekorektan faktor skaliranja");
        
        else if (faktor<0)
        {
            faktor=abs(faktor);
            ta1.first=t.first+faktor*(ta1.first-t.first);
            ta1.second=t.second+faktor*(ta1.second-t.second);
            ta2.first=t.first+faktor*(ta2.first-t.first);
            ta2.second=t.second+faktor*(ta2.second-t.second);
            ta3.first=t.first+faktor*(ta3.first-t.first);
            ta3.second=t.second+faktor*(ta3.second-t.second);
            
            Rotiraj(PI);
        }
        
        else
        {
            ta1.first=t.first+faktor*(ta1.first-t.first);
            ta1.second=t.second+faktor*(ta1.second-t.second);
            ta2.first=t.first+faktor*(ta2.first-t.first);
            ta2.second=t.second+faktor*(ta2.second-t.second);
            ta3.first=t.first+faktor*(ta3.first-t.first);
            ta3.second=t.second+faktor*(ta3.second-t.second);
        }
    };
    
    friend bool DaLiSuIdenticni (const Trougao &t1, const Trougao &t2)
    {
        bool tacnost (false);
        int broj(0);
        Tacka tas1, tas2, tas3, tas4, tas5, tas6;
        
        tas1=t1.DajTjeme(1);
        tas2=t1.DajTjeme(2);
        tas3=t1.DajTjeme(3);
        tas4=t2.DajTjeme(1);
        tas5=t2.DajTjeme(2);
        tas6=t2.DajTjeme(3);
        
        if ((tas1.first==tas4.first && tas1.second==tas4.second)||(tas1.first==tas5.first && tas1.second==tas5.second)||(tas1.first==tas6.first && tas1.second==tas6.second))
        {
            broj++;
        }
        
        if ((tas2.first==tas4.first && tas2.second==tas4.second)||(tas2.first==tas5.first && tas2.second==tas5.second)||(tas2.first==tas6.first && tas2.second==tas6.second))
        {
            broj++;
        }
        
        if ((tas3.first==tas4.first && tas3.second==tas4.second)||(tas3.first==tas5.first && tas3.second==tas5.second)||(tas3.first==tas6.first && tas3.second==tas6.second))
        {
            broj++;
        }
        
        if (broj==3)
        {
            tacnost=true;
        }
        
        return tacnost;
    };
    
    friend bool DaLiSuPodudarni (const Trougao &t1, const Trougao &t2)
    {
        bool tacnost(false);
        double a1, b1, c1, a2, b2, c2;
        Tacka tas1, tas2, tas3, tas4, tas5, tas6, salji1, salji2, salji3, salji4, salji5, salji6;
        pair <double,Tacka> pas1, pas2, pas3, pas4, pas5, pas6;
        vector<pair<double,Tacka>> grupa1, grupa2;
        
        int broj(0);
        
        a1=t1.DajStranicu(1);
        b1=t1.DajStranicu(2);
        c1=t1.DajStranicu(3);
        
        a2=t2.DajStranicu(1);
        b2=t2.DajStranicu(2);
        c2=t2.DajStranicu(3);
        
        tas1=t1.DajTjeme(1);
        tas2=t1.DajTjeme(2);
        tas3=t1.DajTjeme(3);
        tas4=t2.DajTjeme(1);
        tas5=t2.DajTjeme(2);
        tas6=t2.DajTjeme(3);
        
        pas1.first=a1;
        pas1.second=tas1;
        pas2.first=b1;
        pas2.second=tas2;
        pas3.first=c1;
        pas3.second=tas3;
        
        pas4.first=a2;
        pas4.second=tas4;
        pas5.first=b2;
        pas5.second=tas5;
        pas6.first=c2;
        pas6.second=tas6;
        
        grupa1.push_back(pas1);
        grupa1.push_back(pas2);
        grupa1.push_back(pas3);
        
        grupa2.push_back(pas4);
        grupa2.push_back(pas5);
        grupa2.push_back(pas6);
        
        sort (grupa1.begin(), grupa1.end(), [](pair<double,Tacka> x, pair<double,Tacka> y){return x.first<y.first;});
        sort (grupa2.begin(), grupa2.end(), [](pair<double,Tacka> x, pair<double,Tacka> y){return x.first<y.first;});
        
        salji1=grupa1[0].second;
        salji2=grupa1[1].second;
        salji3=grupa1[2].second;
        
        salji4=grupa2[0].second;
        salji5=grupa2[1].second;
        salji6=grupa2[2].second;
        
        if (Orijentacija(salji1,salji2,salji3)==Orijentacija(salji4,salji5,salji6))
        {
            broj++;
        }
        
        if (a1==a2||a1==b2||a1==c2)
        {
            if (b1==a2||b1==b2||b1==c2)
            {
                if (c1==a2||c1==b2||c1==c2)
                {
                    broj++;
                }
            }
        }
        
        if (broj==2)
        {
            tacnost=true;
        }
        
        return tacnost;
    };
    
    friend bool DaLiSuSlicni (const Trougao &t1, const Trougao &t2)
    {
        bool tacnost(false);
        double a1, b1, c1, a2, b2, c2;
        Tacka tas1, tas2, tas3, tas4, tas5, tas6, salji1, salji2, salji3, salji4, salji5, salji6;
        pair <double,Tacka> pas1, pas2, pas3, pas4, pas5, pas6;
        vector<pair<double,Tacka>> grupa1, grupa2;
        
        int broj(0);
        
        a1=t1.DajStranicu(1);
        b1=t1.DajStranicu(2);
        c1=t1.DajStranicu(3);
        
        a2=t2.DajStranicu(1);
        b2=t2.DajStranicu(2);
        c2=t2.DajStranicu(3);
        
        tas1=t1.DajTjeme(1);
        tas2=t1.DajTjeme(2);
        tas3=t1.DajTjeme(3);
        tas4=t2.DajTjeme(1);
        tas5=t2.DajTjeme(2);
        tas6=t2.DajTjeme(3);
        
        pas1.first=a1;
        pas1.second=tas1;
        pas2.first=b1;
        pas2.second=tas2;
        pas3.first=c1;
        pas3.second=tas3;
        
        pas4.first=a2;
        pas4.second=tas4;
        pas5.first=b2;
        pas5.second=tas5;
        pas6.first=c2;
        pas6.second=tas6;
        
        grupa1.push_back(pas1);
        grupa1.push_back(pas2);
        grupa1.push_back(pas3);
        
        grupa2.push_back(pas4);
        grupa2.push_back(pas5);
        grupa2.push_back(pas6);
        
        sort (grupa1.begin(), grupa1.end(), [](pair<double,Tacka> x, pair<double,Tacka> y){return x.first<y.first;});
        sort (grupa2.begin(), grupa2.end(), [](pair<double,Tacka> x, pair<double,Tacka> y){return x.first<y.first;});
        
        salji1=grupa1[0].second;
        salji2=grupa1[1].second;
        salji3=grupa1[2].second;
        
        salji4=grupa2[0].second;
        salji5=grupa2[1].second;
        salji6=grupa2[2].second;
        if (abs((grupa1[0].first/grupa2[0].first)-(grupa1[1].first/grupa2[1].first))<eps && abs((grupa1[1].first/grupa2[1].first)-(grupa1[2].first/grupa2[2].first))<eps)
        {
            if (Orijentacija(salji1,salji2,salji3)==Orijentacija(salji4,salji5,salji6))
            {
                broj++;
            }   
        }
        
        if (broj==1)
        {
            tacnost=true;
        }
        return tacnost;
    };
};

int main ()
{
    bool tacnost;
    double temp1, temp2, tempo, dx, dy, ugao, faktor;
    Tacka t1, t2, t3, t4, t5, t6, test;
    int brojac, n;
    vector <shared_ptr<Trougao>> trouglovi, kopija;
    
    try
    {
        cout<<"Koliko zelite kreirati trouglova: ";
        cin>>n;
        trouglovi.resize(n);
        kopija.resize(n);
        for (int i=0; i<n; i++)
        {   
            try
            {
                cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
                cin>>t1.first>>t1.second>>t2.first>>t2.second>>t3.first>>t3.second;
                trouglovi[i]=make_shared<Trougao>(Trougao(t1,t2,t3));  
            }
            
            catch (domain_error izuzetak)
            {   
                i--;
                cout<<izuzetak.what()<<", ponovite unos!"<<endl;
            }
        }
        
        cout<<"Unesite vektor translacije (dx dy): ";
        cin>>dx>>dy;
        
        cout<<"Unesite ugao rotacije: ";
        cin>>ugao;
        
        cout<<"Unesite faktor skaliranja: ";
        cin>>faktor;
        
        transform (trouglovi.begin(), trouglovi.end(), kopija.begin(), [&](shared_ptr <Trougao> salji)
        {
            salji->Transliraj(dx,dy);
            salji->Rotiraj(ugao);
            salji->Skaliraj(salji->DajTjeme(1),faktor);
            return nullptr;
        });
        
        sort (trouglovi.begin(), trouglovi.end(),[](shared_ptr <Trougao> salji1, shared_ptr <Trougao> salji2)
        {
            return salji1->DajPovrsinu()<salji2->DajPovrsinu();
        });
        
        
        cout<<"Trouglovi nakon obavljenih transformacija: "<<endl;
        
        for_each (trouglovi.begin(), trouglovi.end(), [](shared_ptr <Trougao> salji)
        {
            salji->Ispisi();
            cout<<endl;
        });
        
        cout<<"Trougao sa najmanjim obimom: ";
        
        (*min_element (trouglovi.begin(), trouglovi.end(),[] (shared_ptr<Trougao> salji1, shared_ptr <Trougao> salji2)
        {
            return salji1->DajObim()<salji2->DajObim();
        }))->Ispisi();
        
        cout<<endl;
        kopija.resize(0);
        
        tacnost=false;
        
        for (int k=0; k<n; k++)
        {
            for (int g=k+1; g<n; g++)
            {
                if (DaLiSuIdenticni(*(trouglovi[k]),*(trouglovi[g])))
                {
                    if (tacnost==false)
                    {
                        cout<<"Parovi identicnih trouglova:"<<endl;
                        tacnost=true;
                    }
                    trouglovi[k]->Ispisi();
                    cout<<" i ";
                    trouglovi[g]->Ispisi();
                    cout<<endl;
                    kopija.resize(1);
                }
            }
        }
        
        if (kopija.size()==0)
        {
            cout<<"Nema identicnih trouglova!"<<endl;
        }
        
        
        kopija.resize(0);
        
        tacnost=false;
        
        for (int k=0; k<n; k++)
        {
            for (int g=k+1; g<n; g++)
            {
                if (DaLiSuPodudarni(*(trouglovi[k]),*(trouglovi[g])))
                {
                    if (tacnost==false)
                    {
                        cout<<"Parovi podudarnih trouglova:"<<endl;
                        tacnost=true;
                    }
                    trouglovi[k]->Ispisi();
                    cout<<" i ";
                    trouglovi[g]->Ispisi();
                    cout<<endl;
                    kopija.resize(1);
                }
            }
        }
        
        if (kopija.size()==0)
        {
            cout<<"Nema podudarnih trouglova!"<<endl;
        }
        
        kopija.resize(0);
        
        tacnost=false;
        
        for (int k=0; k<n; k++)
        {
            for (int g=k+1; g<n; g++)
            {
                if (DaLiSuSlicni(*(trouglovi[k]),*(trouglovi[g])))
                {
                    if (tacnost==false)
                    {
                        cout<<"Parovi slicnih trouglova:"<<endl;
                        tacnost=true;
                    }
                    trouglovi[k]->Ispisi();
                    cout<<" i ";
                    trouglovi[g]->Ispisi();
                    cout<<endl;
                    kopija.resize(1);
                }
            }
        }
        
        if (kopija.size()==0)
        {
            cout<<"Nema slicnih trouglova!"<<endl;
        }
    }
    
    catch (domain_error izuzetak)
    {
        cout<<izuzetak.what();
    }
    
    catch (range_error izuzetak)
    {
        cout<<izuzetak.what();
    }
    
    

	return 0;
}