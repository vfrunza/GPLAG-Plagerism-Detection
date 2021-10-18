#include <iostream>
#include <stdexcept>
#include <cmath>
#include <memory>
#include <vector>

using namespace std;
typedef std::pair<double, double> Tacka;

double Pomocna (const Tacka& t1, const Tacka& t2, const Tacka& t3)
{
    double ori(t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)-t3.first*(t1.second-t2.second));
    return ori;
}

double znak (const Tacka& t1, const Tacka& t2, const Tacka& t3)
{
    return (t1.first-t3.first)*(t2.second-t3.second)-(t2.first-t3.first)*(t1.second-t3.second);
}

void KorektanIndeks (int indeks)
{
    if(indeks<1 or indeks>3) throw range_error ("Nekorektan indeks");
}

double UdaljenostTacaka(const Tacka& t1, const Tacka& t2)
{
    return sqrt(((t2.first-t1.first)*(t2.first-t1.first))+((t2.second-t1.second)*(t2.second-t1.second)));
}

class Trougao
{
    Tacka vrhovi[3];
    public:
    Trougao (const Tacka& t1, const Tacka& t2, const Tacka& t3) {Postavi(t1,t2,t3);}
    void Postavi (const Tacka& t1, const Tacka& t2, const Tacka& t3) 
    {
        if(Orijentacija(t1,t2,t3)!=0)
        {
            vrhovi[0]=t1;
            vrhovi[1]=t2;
            vrhovi[2]=t3;
        }
        else throw domain_error ("Nekorektne pozicije tjemena");
    }
    void Postavi (int indeks, const Tacka& t)
    {
        KorektanIndeks(indeks);
        vrhovi[indeks-1]=t;
    }
    static int Orijentacija (const Tacka& t1, const Tacka& t2, const Tacka& t3)
    {
        double ori(Pomocna(t1,t2,t3));
        if(ori>0) return 1;
        else if (ori<0) return -1;
        else return 0;
    }
    Tacka DajTjeme (int indeks) const
    {
        KorektanIndeks(indeks);
        return vrhovi[indeks-1];
    }
    double DajStranicu (int indeks) const
    {
        KorektanIndeks(indeks);
        switch(indeks)
        {
            case 1: return UdaljenostTacaka(vrhovi[1], vrhovi[2]); 
            case 2: return UdaljenostTacaka(vrhovi[0], vrhovi[2]); 
            case 3: return UdaljenostTacaka(vrhovi[0], vrhovi[1]);
        }
        
        return 0;
    }
    Tacka DajCentar() const
    {
        Tacka centar;
        centar.first=(DajTjeme(1).first+DajTjeme(2).first+DajTjeme(3).first)/3;
        centar.second=(DajTjeme(1).second+DajTjeme(2).second+DajTjeme(3).second)/3;
        return centar;
    }
    double DajObim () const
    {
        return DajStranicu(1)+DajStranicu(2)+DajStranicu(3);
    }
    double DajPovrsinu () const
    {
        double s(DajObim()/2);
        return sqrt(s*(s-DajStranicu(1))*(s-DajStranicu(2))*(s-DajStranicu(3)));
    }
    double DajUgao (int indeks) const
    {
        KorektanIndeks(indeks);
        switch(indeks)
        {
            case 1: return acos ((DajStranicu(1)*DajStranicu(1)-DajStranicu(2)*DajStranicu(2)-DajStranicu(3)*DajStranicu(3))/2*DajStranicu(2)*DajStranicu(3));
            case 2: return acos ((DajStranicu(2)*DajStranicu(2)-DajStranicu(1)*DajStranicu(1)-DajStranicu(3)*DajStranicu(3))/2*DajStranicu(1)*DajStranicu(3));
            case 3: return acos ((DajStranicu(3)*DajStranicu(3)-DajStranicu(2)*DajStranicu(2)-DajStranicu(1)*DajStranicu(1))/2*DajStranicu(2)*DajStranicu(1));
        }
        
        return 0;
        
    }
   bool DaLiJeUnutra(const Tacka &t) const
   {
       bool b1(znak(t, DajTjeme(1), DajTjeme(2))<0.0f), b2(znak(t, DajTjeme(2), DajTjeme(3))<0.0f), b3(znak(t, DajTjeme(3), DajTjeme(1))<0.0f);
       return ((b1==b2) and (b2==b3));
       
   }
   bool DaLiJePozitivnoOrijentiran() const
   {
       return Orijentacija(DajTjeme(1), DajTjeme(2), DajTjeme(3))==1;
   }
   void IspisiJednoTjeme(int indeks) const
   {
       cout << "(" << DajTjeme(indeks).first << "," << DajTjeme(indeks).second << ")";
   }
   
   void Ispisi () const
   {
      cout << "(";
      for (int i=1; i<=3; i++)
      {
          IspisiJednoTjeme(i);
          if(i!=3) cout << ",";
      }
      cout << ")";
   }

};

int main ()
{
    try
    {
        cout << "Koliko zelite kreirati trouglova ";
        int n;
        cin >> n;
       
    }
    catch(domain_error e)
    {
        cout<< e.what();
    }
    catch(range_error e)
    {
        cout << e.what();
    }
	return 0;
}