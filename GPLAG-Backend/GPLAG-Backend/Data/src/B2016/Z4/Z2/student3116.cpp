/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>


using namespace std;

class GradjaninBiH
{
    
    string ImePrezime;
    int Jmbg[13];
    static GradjaninBiH *prethodni;
    static GradjaninBiH *trenutni;
    
    void IspisiJmbg() const
    {
        for(int i=0;i<13;i++)
            cout<<Jmbg[i];
    }
    
    long long int PretvoriUBroj() const
    { 
        long long int suma=0;int k=10;
        for(int i=0;i<13;i++)
        {  
            suma=suma*k+Jmbg[i];
        }
        
        return suma;
    }
    
    public:
    enum Pol {Musko, Zensko};
    GradjaninBiH(std::string ime_i_prezime, long long int jmbg):ImePrezime(ime_i_prezime)
    { 
        int br=12;
        while(jmbg!=0)
        {
            Jmbg[br]=jmbg%10;
            jmbg/=10;
            br--;
            if(br==0 && jmbg==0) Jmbg[br]=0;
        }
        
    }
    GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja,int godina_rodjenja, int sifra_regije, Pol pol)
    {
        ImePrezime=ime_i_prezime;
        
        Jmbg[0]=dan_rodjenja/10;
        Jmbg[1]=dan_rodjenja%10;
       
        Jmbg[2]=mjesec_rodjenja/10;
        Jmbg[3]=mjesec_rodjenja%10;
       
        int god=godina_rodjenja/100;
        Jmbg[4]=god%10;
        god=godina_rodjenja/10;
        Jmbg[5]=god%10;
        Jmbg[6]=godina_rodjenja%10;
        
        Jmbg[7]=sifra_regije/10;
        Jmbg[8]=sifra_regije%10;
        
        Jmbg[9]=0;
        Jmbg[10]=0;
        Jmbg[11]=0;
        
        Jmbg[12]=11-(7*(Jmbg[0]+Jmbg[6])+6*(Jmbg[1]+Jmbg[7])+5*(Jmbg[2]+Jmbg[8])+4*(Jmbg[3]+Jmbg[9])+3*(Jmbg[4]+Jmbg[10])+2*(Jmbg[5]+Jmbg[11]))%11;
        if(Jmbg[12]==11)
            Jmbg[12]=0;
        
    }
    std::string DajImeIPrezime() const {return ImePrezime;}
    long long int DajJMBG() const{return PretvoriUBroj();}
    int DajDanRodjenja() const {return Jmbg[0]*10+Jmbg[1];}
    int DajMjesecRodjenja() const{return Jmbg[2]*10+Jmbg[3];};
   
    int DajGodinuRodjenja() const
    {
        int god=1; 
        for(int i=4;i<7;i++)
            god=god*10+Jmbg[i];
            
        if(god<1018) god+=1000;
        return god;
    }
    int DajSifruRegije() const{return Jmbg[7]*10+Jmbg[8];}
    Pol DajPol() const
    {
        int sex=0;
        for(int i=9;i<12;i++)
        {
            sex=sex*10+Jmbg[i];
        }
        if (sex<499) return Musko;
        return Zensko;
    }
    void PromijeniImeIPrezime(std::string novo_ime)
    {
        ImePrezime=novo_ime;
    }
    
   

    
};
string ToString(GradjaninBiH::Pol p)
{
        if (GradjaninBiH::Pol::Musko==p) return "musko";
        return "zensko";
}
    
GradjaninBiH::Pol ToPol(char c)
{
    if(c=='M') return GradjaninBiH::Pol::Musko;
    return GradjaninBiH::Pol::Zensko;
}
int main ()
{
    cout<<"Koliko gradjana zelite unijeti po JMBG?"<<endl;
    int n;cin>>n;
    cin.clear();cin.ignore(10000,'\n');
        
    for(int i=0;i<n;i++)
    {
        string s;long long int jmbg;
        cout<<"Unesite ime i prezime (u istom redu): ";
        getline(cin,s);
        
        cout<<"Unesite JMBG: "<<endl;
        cin>>jmbg;
        
        cin.clear();cin.ignore(10000,'\n');
   
             
        GradjaninBiH g(s,jmbg);
        
        cout<<"Unijeli ste gradjanina "<<g.DajImeIPrezime()<<" rodjenog "<<g.DajDanRodjenja()<<"."<<g.DajMjesecRodjenja()<<"."<<g.DajGodinuRodjenja()<<" u regiji "<<g.DajSifruRegije()<<", "<<ToString(g.DajPol())<<"."<<endl;
    }
   
    cout<<"Koliko gradjana zelite unijeti po datumu rodjenja, regiji i polu? ";
    int n1;
    cin>>n1;
    cin.clear();cin.ignore(10000,'\n');
   
    for(int i=0;i<n1;i++)
    {
        string s;
        cout<<"Unesite ime i prezime (u istom redu): ";
        getline(cin,s);
        
        cout<<"Unesite datum rodjenja (format dd/mm/gggg): ";
        int d,m,g;char h;g
        cin>>d>>h>>m>>h>>g;
        
        cout<<"Unesite sifru regije: ";
        int sifra;
        cin>>sifra;
        
        cout<<"Unesite M za musko,Z za zensko: ";
        char c;
        cin>>c;
        
        cin.clear();cin.ignore(10000,'\n');
   
        GradjaninBiH grad(s,d,m,g,sifra,ToPol(c));
        
        cout<<"Unijeli ste gradjanina "<<grad.DajImeIPrezime()<<" JMBG: "<<grad.DajJMBG()<<endl;
    }
    
	return 0;
}