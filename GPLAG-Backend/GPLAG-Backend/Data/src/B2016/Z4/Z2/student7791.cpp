/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <string>
using std::string;
using std::cout;
using std::cin;
class GradjaninBiH
{
    private:
    string cime_i_prezime;
    long long int cjmbg;
    GradjaninBiH *pok_na_pred;
    static GradjaninBiH *pok_na_zad;
    int DajKontrolnu() const;
  //  int cdan_rodjenja,cmjesec_rodjenja,cgodina_rodjenja,csifra_regije;
  //  Pol cpol;
   bool JeLiValidan(long long int jmbg,int &dan,int &mjesec,int &godina,int &sifra) const;
    public:
    enum Pol {Musko, Zensko};
    ~GradjaninBiH()=default;
    GradjaninBiH(const GradjaninBiH &g)=delete;
    GradjaninBiH &operator=(const GradjaninBiH &g)=delete;
GradjaninBiH(std::string ime_i_prezime, long long int jmbg);
GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja,int godina_rodjenja, int sifra_regije, Pol pol);
std::string DajImeIPrezime() const;
long long int DajJMBG() const;
int DajDanRodjenja() const;
int DajMjesecRodjenja() const;
int DajGodinuRodjenja() const;
int DajSifruRegije() const;
Pol DajPol() const;
void PromijeniImeIPrezime(std::string novo_ime);
};
GradjaninBiH* GradjaninBiH::pok_na_zad=nullptr;
int GradjaninBiH::DajKontrolnu() const
{
    long long int pom(cjmbg);
    pom/=10;
    int a=pom%10;
    pom/=10;
    int b=pom%10;
    pom/=10;
    int c=pom%10;
    int d=a+(b*10)+(c*100);
    return d;
}
bool GradjaninBiH::JeLiValidan(long long int ljmbg,int &dan,int &mjesec,int &godina,int &sifra) const
{
    long long int jmbg(ljmbg);
    if(jmbg<0)
    return false;
    int niz[13]={0};
    niz[0]=-1;
    int i(12);
    while(jmbg>0)
    {
        if(i<0) 
        break;
        int pom(jmbg%10);
        niz[i]=pom;
        jmbg/=10;
        i--;
    }
    if(i!=0 && i!=-1)
    return false;
    if(jmbg!=0)
    return false;
    if(niz[0]==-1)
    niz[0]=0;
    int pom(11-(7*(niz[0]+niz[6])+6*(niz[1]+niz[7])+5*(niz[2]+niz[8])+4*(niz[3]+niz[9])+3*(niz[4]+niz[10])+2*(niz[5]+niz[11]))%11);
    if(pom==10)
    return false;
    if(pom==11)
    pom=0;
    if(pom!=niz[12])
    return false;
    int d,m,g;
    d=niz[0]*10+niz[1];
    m=niz[2]*10+niz[3];
    g=1000+niz[4]*100+niz[5]*10+niz[6];
    int broj_dana[12]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((g%4==0 && g%100!=0) || g%400==0) 
    broj_dana[1]++;
    if(g<1 || d<1 || m<1 || m>12 || d>broj_dana[m-1])
    return false;
    dan=d;
    mjesec=m;
    godina=g;
    int s(niz[7]*10+niz[8]);
    sifra=s;
   // int p(niz[9]*100+niz[10]*10+niz[11]);
  //  if(p<=499)
  //  pol=Musko;
  //  else
 //   pol=Zensko;
    return true;
}
GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, long long int jmbg) : pok_na_pred(nullptr)
{
    int cdan_rodjenja,cmjesec_rodjenja,cgodina_rodjenja,csifra_regije;
    if(!GradjaninBiH::JeLiValidan(jmbg,cdan_rodjenja,cmjesec_rodjenja,cgodina_rodjenja,csifra_regije))
    throw std::logic_error("JMBG nije validan");
    if(pok_na_zad!=nullptr)
    {
        GradjaninBiH *pom(pok_na_zad);
       while(true)
       {
          if((*pom).GradjaninBiH::DajJMBG()==jmbg)
          throw std::logic_error("Vec postoji gradjanin sa istim JMBG");
          else
          {
              pom=(*pom).GradjaninBiH::pok_na_pred;
              if(pom==nullptr) break;
          }
       }
    }
    cjmbg=jmbg;
    cime_i_prezime=ime_i_prezime;
     if(pok_na_zad!=nullptr)
    pok_na_pred=pok_na_zad;
    pok_na_zad=this;
    
}
GradjaninBiH::GradjaninBiH(std::string ime_i_prezime,int d,int m,int g, int s, Pol pol) :pok_na_pred(nullptr)
{
   int broj_dana[12]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
   if((g%4==0 && g%100!=0) || g%400==0) 
   broj_dana[1]++;
   if(g<1 || d<1 || m<1 || m>12 || d>broj_dana[m-1] || s<0 || s>99)  
   throw std::logic_error("Neispravni podaci");
   int cdan_rodjenja,cmjesec_rodjenja,cgodina_rodjenja,csifra_regije;
   Pol cpol;
   cdan_rodjenja=d;
   cgodina_rodjenja=g;
   cmjesec_rodjenja=m;
   csifra_regije=s;
   cpol=pol;
   g-=1000;
   if(g>=1000)
   g-=1000;
   cime_i_prezime=ime_i_prezime;
   cjmbg=d*(1e+11)+m*(1e+9)+g*(1e+6)+s*(1e+4);
   int kontrolna(0);
   if(pol==GradjaninBiH::Zensko)
   kontrolna=500;
   if(g<100)
   g+=1000;
   if(pok_na_zad!=nullptr)
   {
        GradjaninBiH *pom(pok_na_zad);
       while(true)
       {
           if(pom==nullptr) break;
          if((*pom).GradjaninBiH::DajDanRodjenja()==d && (*pom).GradjaninBiH::DajMjesecRodjenja()==m && (*pom).GradjaninBiH::DajGodinuRodjenja()==(g+1000) && (*pom).GradjaninBiH::DajSifruRegije()==s && (*pom).GradjaninBiH::DajPol()==pol && (*pom).GradjaninBiH::DajKontrolnu()==kontrolna)
     //    if((*pom).GradjaninBiH::DajKontrolnu()==kontrolna)
          {
                kontrolna++;
                pom=pok_na_zad;
          } 
          else
          {
              pom=(*pom).GradjaninBiH::pok_na_pred;
              if(pom==nullptr) break;
          }
       }
   }
   cjmbg+=(kontrolna*(1e1));
   long long int jmbg(cjmbg);
   int niz[13];
    niz[0]=-1;
    int i(12);
    while(jmbg>0)
    {
        if(i<0) 
        break;
        int pom(jmbg%10);
        niz[i]=pom;
        jmbg/=10;
        i--;
    }
     int pom(11-(7*(niz[0]+niz[6])+6*(niz[1]+niz[7])+5*(niz[2]+niz[8])+4*(niz[3]+niz[9])+3*(niz[4]+niz[10])+2*(niz[5]+niz[11]))%11);
   // if(pom==10)
   // throw std::logic_error("Neprikladan JMBG");
    if(pom==11)
    pom=0;
    cjmbg+=pom;
     if(pok_na_zad!=nullptr)
   pok_na_pred=pok_na_zad;
    pok_na_zad=this;
}
std::string GradjaninBiH::DajImeIPrezime() const
{
    return cime_i_prezime;
}
int GradjaninBiH::DajDanRodjenja() const
{
     int cdan_rodjenja,cmjesec_rodjenja,cgodina_rodjenja,csifra_regije;
     long long int jmbg(cjmbg);
    if(GradjaninBiH::JeLiValidan(jmbg,cdan_rodjenja,cmjesec_rodjenja,cgodina_rodjenja,csifra_regije))
   return cdan_rodjenja;
   else
   return cdan_rodjenja;
}
int GradjaninBiH::DajMjesecRodjenja() const
{
    int cdan_rodjenja,cmjesec_rodjenja,cgodina_rodjenja,csifra_regije;
    long long int jmbg(cjmbg);
    if(GradjaninBiH::JeLiValidan(jmbg,cdan_rodjenja,cmjesec_rodjenja,cgodina_rodjenja,csifra_regije))
    return cmjesec_rodjenja;
    else
    return cmjesec_rodjenja;
}
int GradjaninBiH::DajGodinuRodjenja() const
{
int cdan_rodjenja,cmjesec_rodjenja,cgodina_rodjenja,csifra_regije;
long long int jmbg(cjmbg);
bool pom=GradjaninBiH::JeLiValidan(jmbg,cdan_rodjenja,cmjesec_rodjenja,cgodina_rodjenja,csifra_regije);
if(cgodina_rodjenja<1100)
cgodina_rodjenja+=1000;

return cgodina_rodjenja;
}
int GradjaninBiH::DajSifruRegije() const
{
    int cdan_rodjenja,cmjesec_rodjenja,cgodina_rodjenja,csifra_regije;
    long long int jmbg(cjmbg);
    if(GradjaninBiH::JeLiValidan(jmbg,cdan_rodjenja,cmjesec_rodjenja,cgodina_rodjenja,csifra_regije))
    return csifra_regije;
    else
    return csifra_regije;
}
GradjaninBiH::Pol GradjaninBiH::DajPol() const
{
    int cdan_rodjenja,cmjesec_rodjenja,cgodina_rodjenja,csifra_regije;
    Pol cpol;
    long long int jmbg(cjmbg);
    if(GradjaninBiH::JeLiValidan(jmbg,cdan_rodjenja,cmjesec_rodjenja,cgodina_rodjenja,csifra_regije))
    {
       int pom=(*this).GradjaninBiH::DajKontrolnu();
       if(pom<=499)
       cpol=GradjaninBiH::Musko;
       else
       cpol=GradjaninBiH::Zensko;
       return cpol;
    }
    else
    throw;
}
void GradjaninBiH::PromijeniImeIPrezime(std::string novo_ime)
{
    cime_i_prezime=novo_ime;
    
}
long long int GradjaninBiH::DajJMBG() const
{
    return cjmbg;
}
int main ()
{
    cout<<"Koliko gradjana zelite unijeti po JMBG? "<<std::endl;
    int broj;
    cin>>broj;
    GradjaninBiH *p[100];
   for(int i=0;i<broj;i++)
    {
        cout<<"Unesite ime i prezime (u istom redu): "<<std::endl;
        string ime;
        cin.ignore(10000,'\n');
        std::getline(cin,ime);
        cout<<"Unesite JMBG: "<<std::endl;
        long long int maticni;
        cin>>maticni;
        try
        {
            
            p[i]=(new GradjaninBiH(ime,maticni));
            if(p[i]->GradjaninBiH::DajPol()==GradjaninBiH::Musko)
            cout<<"Unijeli ste gradjanina "<<p[i]->GradjaninBiH::DajImeIPrezime()<<" rodjenog "<<p[i]->GradjaninBiH::DajDanRodjenja()<<"."<<p[i]->GradjaninBiH::DajMjesecRodjenja()<<"."<<p[i]->GradjaninBiH::DajGodinuRodjenja()<<" u regiji "<<p[i]->GradjaninBiH::DajSifruRegije()<<", musko."<<std::endl;
       else
       cout<<"Unijeli ste gradjanina "<<p[i]->GradjaninBiH::DajImeIPrezime()<<" rodjenog "<<p[i]->GradjaninBiH::DajDanRodjenja()<<"."<<p[i]->GradjaninBiH::DajMjesecRodjenja()<<"."<<p[i]->GradjaninBiH::DajGodinuRodjenja()<<" u regiji "<<p[i]->GradjaninBiH::DajSifruRegije()<<", zensko."<<std::endl;
       if(i==broj-1)
       break;
        }
        catch(std::logic_error izuzetak)
        {
            cout<<izuzetak.what()<<std::endl;
i--;

            
        }
        
    }
    cout<<"Koliko gradjana zelite unijeti po datumu rodjenja, regiji i polu? "<<std::endl;
    int broj2;
    cin>>broj2;
    for(int i=broj;i<broj2+broj;i++)
    {
    cout<<"Unesite ime i prezime (u istom redu): "<<std::endl;
    string ime2;
    cin.ignore(10000,'\n');
    std::getline(cin,ime2);
    cout<<"Unesite datum rodjenja (format dd/mm/gggg): "<<std::endl;
    char znak1,znak2;
    int d,m,g;
    cin>>d>>znak1>>m>>znak2>>g;
    cout<<"Unesite sifru regije: "<<std::endl;
    int s;
    cin>>s;
   // cout<<d<<znak1<<m<<znak2<<g;
   // cout<<d;
   try
   {
    cout<<"Unesite M za musko, Z za zensko: "<<std::endl;
    char znak3;
    cin>>znak3;
    if(znak3=='M')
    p[i]=(new GradjaninBiH(ime2,d,m,g,s,GradjaninBiH::Pol::Musko));
    if(znak3=='Z')
    p[i]=(new GradjaninBiH(ime2,d,m,g,s,GradjaninBiH::Pol::Zensko));
        cout<<"Unijeli ste gradjanina "<<p[i]->GradjaninBiH::DajImeIPrezime()<<" JMBG: "<<p[i]->GradjaninBiH::DajJMBG()<<"."<<std::endl;
        if(i==broj2+broj-1)
        return 0;
        
    }
    catch(std::logic_error izuzetak)
    {
        cout<<izuzetak.what()<<std::endl;
       i--;
    }
    }
	return 0;
}