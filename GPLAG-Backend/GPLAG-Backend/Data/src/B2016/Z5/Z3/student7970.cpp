/B16/17 (Zadaća 5, Zadatak 3)
//Autotestovi by Enil Pajic (mail: epajic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <algorithm>
#include <initializer_list>
#include <set>
#include <limits>
#include <sstream>

using std::cin;
using std::cout;
using std::endl;
using std::set;
using std::logic_error;
using std::overflow_error;
using std::initializer_list;


class Razlomak
{
  long long int b, n;
  
  static long long int NZD (long long int p, long long int q)
  {
      if (p==0)
      {
        return q;
      }
      
      return NZD(q%p,p);
  };
  
  public:
  
  Razlomak ()
  {
      b=0;
      n=1;
  };
  
  Razlomak(long long int x, long long int y)
  {
      long long int d;
      
      if (y==0) throw logic_error("Nekorektan razlomak");
      
      d=NZD(x,y);
      d=abs(d);
      b=x/d;
      n=y/d;
      
      if (n<0)
      {
          n=abs(n);
          b=b*(-1);
      }
      
      if (b<0 && n<0)
      {
          b=abs(b);
          n=abs(n);
      }
  };
  
  
  Razlomak (long long int x)
  {
      b=x;
      n=1;
  };
  
  Razlomak (long int x)
  {
      b=x;
      n=1;
  };
  
  Razlomak (int x)
  {
      b=x;
      n=1;
  };
  
  Razlomak (initializer_list <long long int> lista)
  {
      int broj(0);
      long long int x, y, d;
      
      for (auto it(lista.begin()); it!=lista.end(); it++)
      {
          broj++;
      }
      
      if (broj==0)
      {
          b=0;
          n=1;
      }
      
      if (broj==1)
      {
          b=*lista.begin();
          n=1;
      }
      
      if (broj==2)
      {
          for (auto it(lista.begin()); it!=lista.end(); it++)
          {
              if (*it==*lista.begin())
              {
                  x=*it;
              }
              
              else
              {
                  y=*it;
                  if (y==0) throw logic_error("Nekorektan razlomak");
              }
          }
          
          d=NZD(x,y);
          d=abs(d);
          b=x/d;
          n=y/d;
          
          if (n<0)
          {
            n=abs(n);
            b=b*(-1);
          }
      
          if (b<0 && n<0)
          {
            b=abs(b);
            n=abs(n);
          }
      }
  };
  
  operator long double() const;
  
  
  long long int DajBrojnik() {return b;};
  long long int DajNazivnik() {return n;};
  
  friend std::ostream &operator <<(std::ostream &tok, const Razlomak &s);
  friend std::istream &operator >>(std::istream &tok, Razlomak &s);
  friend Razlomak operator +(const Razlomak &r1, const Razlomak &r2);
  friend Razlomak operator +=(Razlomak &r1, const Razlomak &r2);
  friend Razlomak operator -(const Razlomak &r1, const Razlomak &r2);
  friend Razlomak operator -=(Razlomak &r1, const Razlomak &r2);
  friend Razlomak operator *(const Razlomak &r1, const Razlomak &r2);
  friend Razlomak operator *=(Razlomak &r1, const Razlomak &r2);
  friend Razlomak operator /(const Razlomak &r1, const Razlomak &r2);
  friend Razlomak operator /=(Razlomak &r1, const Razlomak &r2);
  friend Razlomak operator +(const Razlomak &r);
  friend Razlomak operator -(Razlomak &r);
  friend Razlomak &operator ++ (Razlomak &r);
  friend Razlomak operator ++ (Razlomak &r, int);
  friend Razlomak &operator -- (Razlomak &r);
  friend Razlomak operator -- (Razlomak &r, int);
  friend bool operator == (const Razlomak& r1, const Razlomak& r2);
  friend bool operator != (const Razlomak& r1, const Razlomak& r2);
  friend bool operator > (const Razlomak& r1, const Razlomak& r2);
  friend bool operator < (const Razlomak& r1, const Razlomak& r2);
  friend bool operator >= (const Razlomak& r1, const Razlomak& r2);
  friend bool operator <= (const Razlomak& r1, const Razlomak& r2);
};

Razlomak::operator long double() const 
{
  long double rez, temp1(b), temp2(n);

  rez=temp1/temp2;
  
  return rez;
}

std::istream &operator >>(std::istream &tok, Razlomak &s)
{
  char znak;
  long long int d, x, y;

  tok>>std::ws;
  if (tok.peek()>='a' && tok.peek()<='z') tok.setstate(std::ios::failbit);
 
  tok>>x;
  if (tok.peek()!='/') 
  {
    s.b=x;
    s.n=1;
  }
  
  else
  {
    tok>>znak>>y;
    d=s.NZD(x,y);
    s.b=x/d;
    s.n=y/d;
    if (tok.peek()>='a' && tok.peek()<='z') tok.setstate(std::ios::failbit);
  }
  
	return tok;
}

std::ostream &operator <<(std::ostream &tok, const Razlomak &s)
{
  
  if ((s.b>0 && s.n==1) || (s.b<0 && s.n==1))
  {
    tok<<s.b;
  }
  
  else if (s.b==0)
  {
    tok<<0;
  }
  
  else
  {
    tok<<s.b;
	  tok<<"/";
	  tok<<s.n;
  }
  
	return tok;
}

Razlomak operator +(const Razlomak &r1, const Razlomak &r2)
{
	Razlomak rez;
	long long int t, x, y, d, min, max;
	t=rez.NZD(r1.n,r2.n);
	
	
	min=std::numeric_limits<long long int>::min();
  max=std::numeric_limits<long long int>::max();
	
	if ((r2.b*(r1.n/t))<0)
	{
	  if ((r1.b*(r2.n/t))<(min-(r2.b*(r1.n/t)))) throw overflow_error("Nemoguce dobiti tacan rezultat");
	}
	
	else
	{
	  if ((r1.b*(r2.n/t))>(max-(r2.b*(r1.n/t)))) throw overflow_error("Nemoguce dobiti tacan rezultat");
	}
	
	x=(r1.b*(r2.n/t))+(r2.b*(r1.n/t));
	y=r1.n*(r2.n/t);
	
	
	d=rez.NZD(x,y);
      
  rez.b=x/d;
  rez.n=y/d;
  
  if (rez.n<0)
  {
    rez.n=abs(rez.n);
    rez.b=rez.b*(-1);
  }
      
  if (rez.b<0 && rez.n<0)
  {
    rez.n=abs(rez.n);
    rez.b=abs(rez.b);
  }
  
	return rez;
}

Razlomak operator +=(Razlomak &r1, const Razlomak &r2)
{
	Razlomak rez;
	long long int t, x, y, d, min, max;
	t=rez.NZD(r1.n,r2.n);
	
	
	min=std::numeric_limits<long long int>::min();
  max=std::numeric_limits<long long int>::max();
	
	if ((r2.b*(r1.n/t))<0)
	{
	  if ((r1.b*(r2.n/t))<(min-(r2.b*(r1.n/t)))) throw overflow_error("Nemoguce dobiti tacan rezultat");
	}
	
	else
	{
	  if ((r1.b*(r2.n/t))>(max-(r2.b*(r1.n/t)))) throw overflow_error("Nemoguce dobiti tacan rezultat");
	}
	
	x=(r1.b*(r2.n/t))+(r2.b*(r1.n/t));
	y=r1.n*(r2.n/t);
	
	
	d=rez.NZD(x,y);
      
  rez.b=x/d;
  rez.n=y/d;
  
  if (rez.n<0)
  {
    rez.n=abs(rez.n);
    rez.b=rez.b*(-1);
  }
      
  if (rez.b<0 && rez.n<0)
  {
    rez.n=abs(rez.n);
    rez.b=abs(rez.b);
  }
  
  r1.b=rez.b;
  r1.n=rez.n;
  
	return r1;
}

Razlomak operator -(const Razlomak &r1, const Razlomak &r2)
{
	Razlomak rez;
	long long int t, x, y, d, min, max;
	t=rez.NZD(r1.n,r2.n);
	
	
	min=std::numeric_limits<long long int>::min();
  max=std::numeric_limits<long long int>::max();
	
	if ((r2.b*(r1.n/t))<0)
	{
	  if ((r1.b*(r2.n/t))>(max+(r2.b*(r1.n/t)))) throw overflow_error("Nemoguce dobiti tacan rezultat");
	}
	
	else
	{
	  if ((r1.b*(r2.n/t))<(min+(r2.b*(r1.n/t)))) throw overflow_error("Nemoguce dobiti tacan rezultat");
	}
	
	x=(r1.b*(r2.n/t))-(r2.b*(r1.n/t));
	y=r1.n*(r2.n/t);
	
	
	d=rez.NZD(x,y);
      
  rez.b=x/d;
  rez.n=y/d;
  
  if (rez.n<0)
  {
    rez.n=abs(rez.n);
    rez.b=rez.b*(-1);
  }
      
  if (rez.b<0 && rez.n<0)
  {
    rez.n=abs(rez.n);
    rez.b=abs(rez.b);
  }
  
	return rez;
}


Razlomak operator -=(Razlomak &r1, const Razlomak &r2)
{
	Razlomak rez;
	long long int t, x, y, d, min, max;
	t=rez.NZD(r1.n,r2.n);
	
	
	min=std::numeric_limits<long long int>::min();
  max=std::numeric_limits<long long int>::max();
	
	if ((r2.b*(r1.n/t))<0)
	{
	  if ((r1.b*(r2.n/t))>(max+(r2.b*(r1.n/t)))) throw overflow_error("Nemoguce dobiti tacan rezultat");
	}
	
	else
	{
	  if ((r1.b*(r2.n/t))<(min+(r2.b*(r1.n/t)))) throw overflow_error("Nemoguce dobiti tacan rezultat");
	}
	
	x=(r1.b*(r2.n/t))-(r2.b*(r1.n/t));
	y=r1.n*(r2.n/t);
	
	
	d=rez.NZD(x,y);
      
  rez.b=x/d;
  rez.n=y/d;
  
  if (rez.n<0)
  {
    rez.n=abs(rez.n);
    rez.b=rez.b*(-1);
  }
      
  if (rez.b<0 && rez.n<0)
  {
    rez.n=abs(rez.n);
    rez.b=abs(rez.b);
  }
  
  r1.b=rez.b;
  r1.n=rez.n;
  
	return r1;
}

Razlomak operator *(const Razlomak &r1, const Razlomak &r2)
{
	Razlomak rez;
	long long int s, t, x, y, d, min, max;
	s=rez.NZD(r1.b,r2.n);
	t=rez.NZD(r2.b,r1.n);
	
	
	min=std::numeric_limits<long long int>::min();
  max=std::numeric_limits<long long int>::max();
	
	if ((r2.b/t)<0)
	{
	  if ((r1.b/s)==min) throw overflow_error("Nemoguce dobiti tacan rezultat");
	  if (((r1.b/s)*(-1))>(max/((r2.b/t)*(-1)))) throw overflow_error("Nemoguce dobiti tacan rezultat");
	  if (((r1.b/s)*(-1))<(min/((r2.b/t)*(-1)))) throw overflow_error("Nemoguce dobiti tacan rezultat");
	}
	
	else
	{
	  if ((r1.b/s)<(min/(r2.b/t))) throw overflow_error("Nemoguce dobiti tacan rezultat");
	  if ((r1.b/s)>(max/(r2.b/t))) throw overflow_error("Nemoguce dobiti tacan rezultat");
	}
	
	if ((r2.n/s)<0)
	{
	  if ((r1.n/t)==min) throw overflow_error("Nemoguce dobiti tacan rezultat");
	  if (((r1.n/t)*(-1))>(max/((r2.n/s)*(-1)))) throw overflow_error("Nemoguce dobiti tacan rezultat");
	  if (((r1.n/t)*(-1))<(min/((r2.n/s)*(-1)))) throw overflow_error("Nemoguce dobiti tacan rezultat");
	}
	
	else
	{
	  if ((r1.n/t)<(min/(r2.n/s))) throw overflow_error("Nemoguce dobiti tacan rezultat");
	  if ((r1.n/t)>(max/(r2.n/s))) throw overflow_error("Nemoguce dobiti tacan rezultat");
	}
	
	x=(r1.b/s)*(r2.b/t);
	y=(r1.n/t)*(r2.n/s);
	
	
	d=rez.NZD(x,y);
      
  rez.b=x/d;
  rez.n=y/d;
  
  if (rez.n<0)
  {
    rez.n=abs(rez.n);
    rez.b=rez.b*(-1);
  }
      
  if (rez.b<0 && rez.n<0)
  {
    rez.n=abs(rez.n);
    rez.b=abs(rez.b);
  }
  
	return rez;
}

Razlomak operator *=(Razlomak &r1, const Razlomak &r2)
{
	Razlomak rez;
	long long int s, t, x, y, d, min, max;
	s=rez.NZD(r1.b,r2.n);
	t=rez.NZD(r2.b,r1.n);
	
	
	min=std::numeric_limits<long long int>::min();
  max=std::numeric_limits<long long int>::max();
	
	if ((r2.b/t)<0)
	{
	  if ((r1.b/s)==min) throw overflow_error("Nemoguce dobiti tacan rezultat");
	  if (((r1.b/s)*(-1))>(max/((r2.b/t)*(-1)))) throw overflow_error("Nemoguce dobiti tacan rezultat");
	  if (((r1.b/s)*(-1))<(min/((r2.b/t)*(-1)))) throw overflow_error("Nemoguce dobiti tacan rezultat");
	}
	
	else
	{
	  if ((r1.b/s)<(min/(r2.b/t))) throw overflow_error("Nemoguce dobiti tacan rezultat");
	  if ((r1.b/s)>(max/(r2.b/t))) throw overflow_error("Nemoguce dobiti tacan rezultat");
	}
	
	if ((r2.n/s)<0)
	{
	  if ((r1.n/t)==min) throw overflow_error("Nemoguce dobiti tacan rezultat");
	  if (((r1.n/t)*(-1))>(max/((r2.n/s)*(-1)))) throw overflow_error("Nemoguce dobiti tacan rezultat");
	  if (((r1.n/t)*(-1))<(min/((r2.n/s)*(-1)))) throw overflow_error("Nemoguce dobiti tacan rezultat");
	}
	
	else
	{
	  if ((r1.n/t)<(min/(r2.n/s))) throw overflow_error("Nemoguce dobiti tacan rezultat");
	  if ((r1.n/t)>(max/(r2.n/s))) throw overflow_error("Nemoguce dobiti tacan rezultat");
	}
	
	x=(r1.b/s)*(r2.b/t);
	y=(r1.n/t)*(r2.n/s);
	
	
	d=rez.NZD(x,y);
      
  rez.b=x/d;
  rez.n=y/d;
  
  if (rez.n<0)
  {
    rez.n=abs(rez.n);
    rez.b=rez.b*(-1);
  }
      
  if (rez.b<0 && rez.n<0)
  {
    rez.n=abs(rez.n);
    rez.b=abs(rez.b);
  }
  
  r1.b=rez.b;
  r1.n=rez.n;
  
	return r1;
}

Razlomak operator /(const Razlomak &r1, const Razlomak &r2)
{
	Razlomak rez;
	long long int u, t, x, y, d, min, max;
	u=rez.NZD(r1.b,r2.b);
	t=rez.NZD(r1.n,r2.n);
	
	min=std::numeric_limits<long long int>::min();
  max=std::numeric_limits<long long int>::max();
	
	if ((r2.n/t)<0)
	{
	  if ((r1.b/u)==min) throw overflow_error("Nemoguce dobiti tacan rezultat");
	  if (((r1.b/u)*(-1))>(max/((r2.n/t)*(-1)))) throw overflow_error("Nemoguce dobiti tacan rezultat");
	  if (((r1.b/u)*(-1))<(min/((r2.n/t)*(-1)))) throw overflow_error("Nemoguce dobiti tacan rezultat");
	}
	
	else
	{
	  if ((r1.b/u)<(min/(r2.n/t))) throw overflow_error("Nemoguce dobiti tacan rezultat");
	  if ((r1.b/u)>(max/(r2.n/t))) throw overflow_error("Nemoguce dobiti tacan rezultat");
	}
	
	if ((r2.b/u)<0)
	{
	  if ((r1.n/t)==min) throw overflow_error("Nemoguce dobiti tacan rezultat");
	  if (((r1.n/t)*(-1))>(max/((r2.b/u)*(-1)))) throw overflow_error("Nemoguce dobiti tacan rezultat");
	  if (((r1.n/t)*(-1))<(min/((r2.b/u)*(-1)))) throw overflow_error("Nemoguce dobiti tacan rezultat");
	}
	
	else
	{
	  if ((r1.n/t)<(min/(r2.b/u))) throw overflow_error("Nemoguce dobiti tacan rezultat");
	  if ((r1.n/t)>(max/(r2.b/u))) throw overflow_error("Nemoguce dobiti tacan rezultat");
	}
	
	x=(r1.b/u)*(r2.n/t);
	y=(r1.n/t)*(r2.b/u);
	
	
	d=rez.NZD(x,y);
      
  rez.b=x/d;
  rez.n=y/d;
  
  if (rez.n<0)
  {
    rez.n=abs(rez.n);
    rez.b=rez.b*(-1);
  }
      
  if (rez.b<0 && rez.n<0)
  {
    rez.n=abs(rez.n);
    rez.b=abs(rez.b);
  }
  
	return rez;
}


Razlomak operator /=(Razlomak &r1, const Razlomak &r2)
{
	Razlomak rez;
	long long int u, t, x, y, d, min, max;
	u=rez.NZD(r1.b,r2.b);
	t=rez.NZD(r1.n,r2.n);
	
	min=std::numeric_limits<long long int>::min();
  max=std::numeric_limits<long long int>::max();
	
	if ((r2.n/t)<0)
	{
	  if ((r1.b/u)==min) throw overflow_error("Nemoguce dobiti tacan rezultat");
	  if (((r1.b/u)*(-1))>(max/((r2.n/t)*(-1)))) throw overflow_error("Nemoguce dobiti tacan rezultat");
	  if (((r1.b/u)*(-1))<(min/((r2.n/t)*(-1)))) throw overflow_error("Nemoguce dobiti tacan rezultat");
	}
	
	else
	{
	  if ((r1.b/u)<(min/(r2.n/t))) throw overflow_error("Nemoguce dobiti tacan rezultat");
	  if ((r1.b/u)>(max/(r2.n/t))) throw overflow_error("Nemoguce dobiti tacan rezultat");
	}
	
	if ((r2.b/u)<0)
	{
	  if ((r1.n/t)==min) throw overflow_error("Nemoguce dobiti tacan rezultat");
	  if (((r1.n/t)*(-1))>(max/((r2.b/u)*(-1)))) throw overflow_error("Nemoguce dobiti tacan rezultat");
	  if (((r1.n/t)*(-1))<(min/((r2.b/u)*(-1)))) throw overflow_error("Nemoguce dobiti tacan rezultat");
	}
	
	else
	{
	  if ((r1.n/t)<(min/(r2.b/u))) throw overflow_error("Nemoguce dobiti tacan rezultat");
	  if ((r1.n/t)>(max/(r2.b/u))) throw overflow_error("Nemoguce dobiti tacan rezultat");
	}
	
	x=(r1.b/u)*(r2.n/t);
	y=(r1.n/t)*(r2.b/u);
	
	
	d=rez.NZD(x,y);
      
  rez.b=x/d;
  rez.n=y/d;
  
  if (rez.n<0)
  {
    rez.n=abs(rez.n);
    rez.b=rez.b*(-1);
  }
      
  if (rez.b<0 && rez.n<0)
  {
    rez.n=abs(rez.n);
    rez.b=abs(rez.b);
  }
  
  r1.b=rez.b;
  r1.n=rez.n;
  
	return r1;
}

Razlomak operator +(const Razlomak &r)
{
	return r;
}

Razlomak operator -(Razlomak &r)
{
  long long int min;
  min=std::numeric_limits<long long int>::min();
  
  if (r.b==min) throw overflow_error("Nemoguce dobiti tacan rezultat");
  
  else
  {
    if (r.n<0)
    {
      r.n=abs(r.n);
      r.b=r.b*(-1);
    }
      
    if (r.b<0 && r.n<0)
    {
      r.n=abs(r.n);
      r.b=abs(r.b);
    }
    
    r.b=r.b*(-1);
  }

	return r;
}

Razlomak &operator ++ (Razlomak &r)
{
  long long int max, d;
  max=std::numeric_limits<long long int>::max();
  if (r.b==max) throw overflow_error("Nemoguce dobiti tacan rezultat");
  if (r.b>max-r.n) throw overflow_error("Nemoguce dobiti tacan rezultat");
  
  r.b=r.b+r.n;
  
  d=r.NZD(r.b,r.n);
  d=abs(d);
  
  r.b=r.b/d;
  r.n=r.n/d;
  
  return r;
}

Razlomak operator ++ (Razlomak &r, int)
{
  long long int max, d;
  Razlomak kopija (r);
  max=std::numeric_limits<long long int>::max();
  if (r.b==max) throw overflow_error("Nemoguce dobiti tacan rezultat");
  if (r.b>max-r.n) throw overflow_error("Nemoguce dobiti tacan rezultat");
  
  r.b=r.b+r.n;
  
  d=r.NZD(r.b,r.n);
  d=abs(d);
  
  r.b=r.b/d;
  r.n=r.n/d;
  
  return kopija;
}

Razlomak &operator -- (Razlomak &r)
{
  long long int min, d;
  min=std::numeric_limits<long long int>::min();
  if (r.b==min) throw overflow_error("Nemoguce dobiti tacan rezultat");
  if (r.b<min+r.n) throw overflow_error("Nemoguce dobiti tacan rezultat");
  
  r.b=r.b-r.n;
  
  d=r.NZD(r.b,r.n);
  d=abs(d);
  
  r.b=r.b/d;
  r.n=r.n/d;
  
  return r;
}

Razlomak operator -- (Razlomak &r, int)
{
  long long int min, d;
  Razlomak kopija (r);
  min=std::numeric_limits<long long int>::min();
  if (r.b==min) throw overflow_error("Nemoguce dobiti tacan rezultat");
  if (r.b<min+r.n) throw overflow_error("Nemoguce dobiti tacan rezultat");
  
  r.b=r.b-r.n;
  
  d=r.NZD(r.b,r.n);
  d=abs(d);
  
  r.b=r.b/d;
  r.n=r.n/d;
  
  return kopija;
}

bool operator == (const Razlomak& r1, const Razlomak& r2)
{
  long double rez1, rez2, temp1, temp2;
  
  temp1=r1.b;
  temp2=r1.n;
  
  rez1=temp1/temp2;
  
  temp1=r2.b;
  temp2=r2.n;
  
  rez2=temp1/temp2;

  return rez1==rez2;
}

bool operator != (const Razlomak& r1, const Razlomak& r2)
{
  long double rez1, rez2, temp1, temp2;
  
  temp1=r1.b;
  temp2=r1.n;
  
  rez1=temp1/temp2;
  
  temp1=r2.b;
  temp2=r2.n;
  
  rez2=temp1/temp2;

  return rez1!=rez2;
}

bool operator > (const Razlomak& r1, const Razlomak& r2)
{
  long double rez1, rez2, temp1, temp2;
  
  temp1=r1.b;
  temp2=r1.n;
  
  rez1=temp1/temp2;
  
  temp1=r2.b;
  temp2=r2.n;
  
  rez2=temp1/temp2;

  return rez1>rez2;
}

bool operator < (const Razlomak& r1, const Razlomak& r2)
{
  long double rez1, rez2, temp1, temp2;
  
  temp1=r1.b;
  temp2=r1.n;
  
  rez1=temp1/temp2;
  
  temp1=r2.b;
  temp2=r2.n;
  
  rez2=temp1/temp2;

  return rez1<rez2;
}

bool operator >= (const Razlomak& r1, const Razlomak& r2)
{
  long double rez1, rez2, temp1, temp2;
  
  temp1=r1.b;
  temp2=r1.n;
  
  rez1=temp1/temp2;
  
  temp1=r2.b;
  temp2=r2.n;
  
  rez2=temp1/temp2;

  return rez1>=rez2;
}

bool operator <= (const Razlomak& r1, const Razlomak& r2)
{
  long double rez1, rez2, temp1, temp2;
  
  temp1=r1.b;
  temp2=r1.n;
  
  rez1=temp1/temp2;
  
  temp1=r2.b;
  temp2=r2.n;
  
  rez2=temp1/temp2;

  return rez1<=rez2;
}
 

int main ()
{
  try
  {
    Razlomak r, r3(5), r4{1/-7}, r5, r6{};
    long long int x, y;
    
    cout<<"Unesi brojnik i nazivnik: ";
    cin>>x>>y;
    Razlomak r1(x,y);
    cout<<"Unesi brojnik i nazivnik: ";
    cin>>x>>y;
    Razlomak r2{x,y};
    cout<<"Razlomak 1 glasi: "<<r1<<endl;
    cout<<"Razlomak 2 glasi: "<<r2<<endl;
    cout<<"Razlomak 3 glasi: "<<r3<<endl;
    cout<<"Razlomak 4 glasi: "<<r4<<endl;
    cout<<"Razlomak 5 glasi: "<<r5<<endl;
    cout<<"Razlomak 6 glasi: "<<r6<<endl;
    cout<<"Zbir ova dva razlomka je: "<<r1+r2<<endl;
    r=r1;
    r1+=r2;
    cout<<"Zbir (+=) ova dva razlomka je: "<<r1<<endl;
    r1=r;
    cout<<"Razlika ova dva razlomka je: "<<r1-r2<<endl;
    r=r1;
    r1-=r2;
    cout<<"Razlika (-=) ova dva razlomka je: "<<r1<<endl;
    r1=r;
    cout<<"Proizvod ova dva razlomka je: "<<r1*r2<<endl;
    r=r1;
    r1*=r2;
    cout<<"Proizvod (*=) ova dva razlomka je: "<<r1<<endl;
    r1=r;
    cout<<"Kolicnik ova dva razlomka je: "<<r1/r2<<endl;
    r=r1;
    r1/=r2;
    cout<<"Kolicnik (/=) ova dva razlomka je: "<<r1<<endl;
    r1=r;
    if (r1==r2)
    cout<<"Razlomci su jednaki."<<endl;
    if (r1!=r2)
    cout<<"Razlomci su razliciti."<<endl;
    if (r1>r2)
    cout<<"Prvi razlomak je veci od drugog."<<endl;
    if (r1<r2)
    cout<<"Prvi razlomak je manji od drugog."<<endl;
    if (r1>=r2)
    cout<<"Prvi razlomak je ili veci od ili jednak drugom."<<endl;
    if (r1<=r2)
    cout<<"Prvi razlomak je ili manji od ili jednak drugom."<<endl;
  }
    
  catch (overflow_error izuzetak)
  {
    cout<<izuzetak.what();
  }
  
	return 0;
}