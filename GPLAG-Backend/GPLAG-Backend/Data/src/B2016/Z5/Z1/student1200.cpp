#include <iostream>
#include <stdexcept>
#include <iomanip>

using std::cout;

class Sat{
	int sati,minute,sekunde;
  public: //Interfejs
    Sat() { 
      sati=0;
      minute=0;
      sekunde=0;
    }
    Sat(int sati, int minute, int sekunde){PostaviNormalizirano(sati,minute,sekunde);}
    static bool DaLiJeIspravno(int sati,int minute,int sekunde){
    	if(sati<0 or sati>23 or minute <0 or minute>59 or sekunde < 0 or sekunde >59) return false;
    	return true;
    }
    
    void Postavi(int sati, int minute, int sekunde){
      if(!DaLiJeIspravno(sati,minute,sekunde)) throw std::domain_error("Neispravno vrijeme");
      Sat::sati=sati; Sat::minute=minute; Sat::sekunde=sekunde;
    }
    Sat& operator ++();
    Sat& operator --();
    Sat operator ++(int);
    Sat operator --(int);
    Sat& operator +=(int sekunde);
    Sat& operator -=(int sekunde);
    
    
    
    void PostaviNormalizirano(int sati, int minute, int sekunde){
      Sat::sati=sati; Sat::minute=minute; Sat::sekunde=sekunde;
      this->operator --(); //Ove dvije funkcije ce se "ponistiti" a pri tome ce srediti sve negativne brojeve i izvrsit ce "prelivanje"
      this->operator ++();
    }
    
    
    friend std::ostream& operator <<(std::ostream &tok,const Sat& sat) {
      tok<<std::setfill('0')<<std::setw(2)<<sat.DajSate()<<":"<<std::setw(2)<<sat.DajMinute()<<":"<<std::setw(2)<<sat.DajSekunde(); 
      return tok;
      
    }
    
    
    
    int DajSate() const { return sati; }
    int DajMinute() const { return minute; }
    int DajSekunde() const { return sekunde; }
    friend int operator -(const Sat& sat1, const Sat& sat2);
    friend Sat operator -(const Sat& sat1, int n);
    friend Sat operator +(const Sat& sat1, int n);
};

Sat& Sat::operator ++(){ //Sljedeci
      sekunde ++;
      if(sekunde>59){
        minute+=sekunde/60;
        sekunde%=60;
      }
      if(minute>59){
        sati+=minute/60;
        minute%=60;
      }
      if(sati>23)
        sati%=24;
        
      return *this;
}

Sat Sat::operator++(int){
    Sat sat(*this);
    this->operator ++();
    return sat;
}

Sat& Sat::operator --(){ //Prethodni
      sekunde--;
      if(sekunde<0){
        minute--; //zbog minusa vec treba jednom smanjit
        minute+=sekunde/60;
        sekunde=60+sekunde%60;
      }
      if(minute<0){
        sati--; //zbog minusa vec treba jednom smanjit
        sati+=minute/60;
        minute=60+minute%60;
      }
      if(sati<0)
        sati=24+sati%24;
          
      return *this;
}
    
Sat Sat::operator--(int){
    Sat sat(*this);
    this->operator --();
    return sat;
}
    
Sat& Sat::operator +=(int sekunde){ //PomjeriZa

  if(sekunde<0){
    for(int i=0; i<abs(sekunde); i++)
      this->operator --();
  }
  
  else{
    for(int i=0; i<sekunde; i++)
      this->operator ++();
  }
  return *this;
  
}

Sat& Sat::operator -=(int sekunde){
    this->operator+=(-sekunde);
    return *this;
}

int operator -(const Sat& sat1, const Sat& sat2){
  int prve_sekunde ( sat1.DajSekunde()+ sat1.DajMinute()*60 + sat1.DajSate()*3600 );
  int druge_sekunde ( sat2.DajSekunde() + sat2.DajMinute()*60 + sat2.DajSate() * 3600);
  return prve_sekunde-druge_sekunde;
}

Sat operator -(const Sat& sat1, int n){
    Sat rez(sat1);
    rez-=n;
    return rez;
}
Sat operator +(const Sat& sat2, int n){
    Sat rez(sat2);
    rez+=n;
    return rez;
}

int main ()
{
  Sat sat_sa_pijace;
  Sat neki_sat(10,20,30);
  try{
    sat_sa_pijace.Postavi(10,12,42);
    cout<<sat_sa_pijace;
    std::cout<<std::endl;
    sat_sa_pijace.PostaviNormalizirano(213,-212,530);
    cout<<sat_sa_pijace;
    std::cout<<std::endl;
    std::cout<<"Sati: "<<sat_sa_pijace.DajSate()<<std::endl<<"Minute: "<<sat_sa_pijace.DajMinute()<<std::endl<<"Sekunde: "<<sat_sa_pijace.DajSekunde()<<std::endl;
    ++sat_sa_pijace;;
    cout<<sat_sa_pijace;
    std::cout<<std::endl;
    ++sat_sa_pijace;
    cout<<sat_sa_pijace;
    std::cout<<std::endl;
    sat_sa_pijace+=215;
    cout<<sat_sa_pijace;
    std::cout<<std::endl;
    Sat kofa_original;
    kofa_original.Postavi(10,5,0);
    std::cout<<sat_sa_pijace-kofa_original<<std::endl;
    std::cout<<sat_sa_pijace-kofa_original<<std::endl<<kofa_original-sat_sa_pijace<<std::endl;
    kofa_original.Postavi(-10,2,3);
  }
  catch(std::domain_error e){
    std::cout<<e.what()<<std::endl;
  }
	return 0;
}