/B2017/2018: Zadaća 5, Zadatak 1
#include <iostream>
#include <stdexcept>
#include <iomanip>

class Sat {
  int sati,minute,sekunde;
  static bool DaLiJeIspravno(int s, int m, int se)
{
	if(s < 0 || s > 23 || m<0 || m>59 || se<0 || se>59) return false;
	return true;
}
  
  public:
  
  Sat(int h, int m, int s) {
    if(!DaLiJeIspravno(h,m,s)) throw std::domain_error("Neispravno vrijeme!");
    else {
        sati=h; minute=m; sekunde=s;
    }
  }
  void Postavi(int h, int m, int s) {
      if(!DaLiJeIspravno(h,m,s)) throw std::domain_error("Neispravno vrijeme!");
      else {
          sati=h;
          minute=m;
          sekunde=s;
      }
  }
  int DajSate() const {return sati;}
  int DajMinute() const {return minute;}
  int DajSekunde() const {return sekunde;}
  
  void Sljedeci();
  void Prethodni();
  void PomjeriZa(int pomak);
  
  friend int BrojSekundiIzmedju(const Sat &s1, const Sat &s2);
  void Ispisi() const {
      std::cout<<DajSate()<<":"<<DajMinute()<<":"<<DajSekunde();
  }
      
};

    void Sat::Sljedeci() {
        sekunde++;
		    while (sekunde>59) {
			    minute++;
			    sekunde-=60;
		    }
		    while (minute>59) {
			    sati++;
			    minute-=60;
		    }
		    while (sati>23) {
			    sati-=24;
		    }
		Postavi(sati,minute,sekunde);
	}
	
	void Sat::Prethodni() {
	    sekunde--;
	        while (sekunde<0) {
			    minute--;
			    sekunde+=60;
		    }
		    while (minute<0)  {
			    sati--;
			    minute+=60;
		    }
		    while (sati<0)  {
		    	sati+=24;
		    }

		    Postavi(sati,minute,sekunde);
	}
	
	void Sat::PomjeriZa(int pomak) {
	    sekunde+=pomak;
	    while (sekunde>59) {
			    minute++;
			    sekunde-=60;
		    }
		    while (minute>59) {
			    sati++;
			    minute-=60;
		    }
		    while (sati>23) {
			    sati-=24;
		    }
		   while (sekunde<0) {
			    minute--;
			    sekunde+=60;
		    }
		    while (minute<0)  {
			    sati--;
			    minute+=60;
		    }
		    while (sati<0)  {
		    	sati+=24;
		    }

		    Postavi(sati,minute,sekunde);
	}
	
        int BrojSekundiIzmedju(const Sat &s1, const Sat &s2) {
	    long int sec1(s1.sati*3600+s1.minute*60+s1.sekunde),sec2(s2.sati*3600+s2.minute*60+s2.sekunde);
	    return sec1-sec2;
	}
	
	


int main ()
{
	try{
	Sat s1(10,20,15);
    s1.Postavi(5,15,59);
    s1.Ispisi();
    std::cout<<std::endl;
    s1.Sljedeci();
    s1.Ispisi();
    std::cout<<std::endl;
    s1.Prethodni();
    s1.Ispisi();
    std::cout<<std::endl;
    s1.PomjeriZa(4);
    s1.Ispisi();
    std::cout<<std::endl;
    Sat s2(12,10,6),s3(10,2,1);
    int x;
    x=BrojSekundiIzmedju(s2,s3);
    std::cout<<"Izmedju vremena s2 i s3 je: "<<x<<" sekundi"<<std::endl;
	}catch(std::domain_error e){
		std::cout<<e.what()<<std::endl;
	}
    
	return 0;
}
