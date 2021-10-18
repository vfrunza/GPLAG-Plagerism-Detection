/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>

using namespace std;

class GradjaninBiH
{
    string ime;
    long long int jmbg;
    
    GradjaninBiH *pret;
    static GradjaninBiH *tren;
    static int br;    
    
    bool ProvjeriDatum(int d,int m,int g)
    {
        int niz[12]={31,28,31,30,31,30,30,31,30,31,30,31};
        if((d<=0 || d>niz[m-1]) || (m<0 || m>12) || (g<1917))
         return false;
        return true;
    }
    
    public:
    enum Pol {Musko, Zensko};
    GradjaninBiH(std::string ime_i_prezime, long long int jmbg)
    {   
        
        ime=ime_i_prezime;
        
        int d,m,g;
        d=jmbg/100000000000;
        m=jmbg/1000000000%100;
        g=jmbg/1000000%1000;
        
        if(g>17)
            g+=1000;
        else g+=2000;
        
        if(!ProvjeriDatum(d,m,g)) throw logic_error("JMBG nije validan");
         if(br==0)
         {
             pret=nullptr;
             GradjaninBiH::jmbg=jmbg;
             tren=this;
         }
        else
        {   
            pret=tren;
            GradjaninBiH *pom=tren;
            while(pom!=nullptr) 
            {   
               
                if(pom->DajJMBG()==jmbg) throw logic_error("Vec postoji gradjanin sa istim JMBG");
                pom=pom->pret;
                
            }
            GradjaninBiH::jmbg=jmbg;
            tren=this;
        }
        
        
          br++;
                
        
    }
    GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja,int godina_rodjenja, int sifra_regije, Pol pol)
    {   
        
        if(!ProvjeriDatum(dan_rodjenja,mjesec_rodjenja,godina_rodjenja) || (sifra_regije<0 || sifra_regije>99)) throw logic_error("Neispravni podaci");
        
        ime=ime_i_prezime;
        long long int n=0;
        int godina=godina_rodjenja%1000;
        
       n=dan_rodjenja/10+n*10;
       n=dan_rodjenja%10+n*10;
       
       if(mjesec_rodjenja<10)
       {
           n*=10;
           n=mjesec_rodjenja%10+n*10;    
           
       }
       else{
       n=mjesec_rodjenja/10+n*10;
       n=mjesec_rodjenja%10+n*10;    
       }
       
       
       n=godina/100+n*10;
       n=godina/10%10+n*10;
       n=godina%10+n*10;
       
       if(sifra_regije<10)
       {
           n*=10;
           n=sifra_regije%10+n*10;    
       }
       else 
       {
           n=sifra_regije/10+n*10;
           n=sifra_regije%10+n*10;    
       }
       
       int id;
       if(Pol::Musko==pol) id=0;
       else if(Pol::Zensko==pol) id=500;
      
        if(br==0)
         {
             pret=nullptr;
             tren=this;
         }
        else
        {   
            pret=tren;
            GradjaninBiH *pom=tren;
            while(pom!=nullptr) 
            {  
                if(pom->DajJMBG()%1000/10==id && pom->DajJMBG()/10000==n && pom->DajPol()==pol) 
                        id++;
                pom=pom->pret;
       
            }
            tren=this;
        }
        
        if(id==0)
        {
           n*=1000;
        }
        else if(id>0 && id<10)
        {
            n*=10;n*=10;
            n=id%10+n*10;
        }
        else if(id>9 && id<100)
        {
            n*=10;
            n=id/10+n*10;
            n=id%10+n*10;
        }
        else 
        {
            n=id/100+n*10;
            n=id/10%10+n*10;
            n=id%10+n*10;
        }
        
         
        int c=11-(7*(dan_rodjenja/10+godina%10)+6*(dan_rodjenja%10+sifra_regije/10)+5*(mjesec_rodjenja/10+sifra_regije%10)+4*(mjesec_rodjenja%10+id/100)+3*(godina/100+id/10%10)+2*(godina/10%10+id%10))%11;
        if(c==11) c=0;
       else if(c==10) throw logic_error("JMBG nije validan");
        
        n=n*10+c;
       
         br++;
        jmbg=n;
    }
    std::string DajImeIPrezime() const
    {
        return ime;
    }
    long long int DajJMBG() const
    {
        return jmbg;
        
    }
    int DajDanRodjenja() const
    {
        return jmbg/100000000000;
    }
    int DajMjesecRodjenja() const
    {
        return (jmbg/1000000000)%100;
    }
    int DajGodinuRodjenja() const
    {
        int g=(jmbg/1000000)%1000;
        if(g>917)g+=1000;
        else g+=2000;
        return g;
    }
    int DajSifruRegije() const
    {
        return(jmbg/10000)%100;
    }
    Pol DajPol() const
    {
        int n=(jmbg/10)%1000;
        if(n<=499) return Pol::Musko;
        return Pol::Zensko;
    }
    void PromijeniImeIPrezime(std::string novo_ime)
    {
        ime=novo_ime;
    }
    
    void Ispis()const
    {
        cout<<ime<<"/"<<jmbg<<endl;
    }
    
};

string Pretvori(GradjaninBiH::Pol pol)
{
    if(pol==GradjaninBiH::Musko) return "musko";
    return "zensko";
}

GradjaninBiH::Pol Pretvori(char c)
{
    if(c=='M') return GradjaninBiH::Musko;
    return GradjaninBiH::Zensko;
}
GradjaninBiH *GradjaninBiH::tren;
int GradjaninBiH::br=0;
int main ()
{   
    GradjaninBiH *niz[1000];
    cout<<"Koliko gradjana zelite unijeti po JMBG? "<<endl;
    int n;cin>>n;
    cin.clear();
    cin.ignore(10000,'\n');
   
    for(int i=0;i<n;i++)
    {
        string s;long long int jmbg;
        cout<<"Unesite ime i prezime (u istom redu): "<<endl;
        getline(cin,s);
        cout<<"Unesite JMBG: "<<endl;
        cin>>jmbg;
        cin.clear();cin.ignore(10000,'\n');
        try{
                niz[i]=new GradjaninBiH(s,jmbg);
                 cout<<"Unijeli ste gradjanina "<<niz[i]->DajImeIPrezime()<<" rodjenog "<<niz[i]->DajDanRodjenja()<<"."<<niz[i]->DajMjesecRodjenja()
        <<"."<<niz[i]->DajGodinuRodjenja()<<" u regiji "<<niz[i]->DajSifruRegije()<<", "<<Pretvori(niz[i]->DajPol())<<"."<<endl;
    
        }catch(logic_error e)
        {   
            i--;
            cout<<e.what()<<endl;
        }
        
    }
    
    int n1;
    cout<<"Koliko gradjana zelite unijeti po datumu rodjenja, regiji i polu? "<<endl;
    cin>>n1;
    
    cin.clear();
    cin.ignore(10000,'\n');
   
   
    for(int i=n;i<n+n1;i++)
    {
        string s;
        cout<<"Unesite ime i prezime (u istom redu): "<<endl;
        getline(cin,s);
        cout<<"Unesite datum rodjenja (format dd/mm/gggg): "<<endl;
        int m,d,g;char c;
        cin>>d>>c>>m>>c>>g;
        int sifra;
        cout<<"Unesite sifru regije: "<<endl;
        cin>>sifra;
        cout<<"Unesite M za musko, Z za zensko: "<<endl;
        char p;
        cin>>p;
        
        cin.clear();
        cin.ignore(10000,'\n');
   
        
        try
        {
            niz[i]=new GradjaninBiH(s,d,m,g,sifra,Pretvori(p));
            cout<<"Unijeli ste gradjanina "<<niz[i]->DajImeIPrezime()<<" JMBG: "<<niz[i]->DajJMBG()<<"."<<endl;
        }
        catch(logic_error e )
        {   
            i--;
            cout<<e.what()<<endl;
        }
        
        
    }
    
    for(int i=0;i<n+n1;i++)
        delete niz[i];
    
    
	return 0;
}