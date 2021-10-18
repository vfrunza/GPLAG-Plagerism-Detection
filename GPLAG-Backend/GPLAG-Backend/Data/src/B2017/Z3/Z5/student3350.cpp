/B2017/2018: Zadaća 3, Zadatak 5
#include <iostream>
#include <map>
#include <utility>
#include <queue>
using std::string;
std::map<int,string>mapa_karata{{2,"2"},{3,"3"},{4,"4"},{5,"5"},{6,"6"},{7,"7"},{8,"8"},{9,"9"},{10,"10"},{11,"J"},{12,"Q"},{13,"K"},{14,"A"}} ;
std::map<std::string,int>mapa_karata1{{"2",2},{"3",3},{"4",4},{"5",5},{"6",6},{"7",7},{"8",8},{"9",9},{"10",10},{"J",11},{"Q",12},{"K",13},{"A",14}} ;
string s1("Herc"),s2("Karo"),s3("Pik"),s4("Tref"); 
enum class Boje {Herc,Pik,Karo,Tref}; 
struct Karta {
    Boje boja;
    string vrijednost;
}; 

struct Cvor {
    Karta karta;
    Cvor *sljedeci_elemenat;
};
Cvor *KrieirajSpil()
{
    Cvor *poc,*pret;
    for(int i(0);i<4;i++)
    {
           for(int j(2);j<15;j++)
           {
               Karta k;
               k.boja=Boje(i);
               auto it(mapa_karata.find(j));
               k.vrijednost=(it->second);
               Cvor *novi_cvor(new Cvor);
               novi_cvor->karta=k;
               //novi_cvor->sljedeci_elemenat=nullptr;
               if(i==3&&j==14)
               {
                   pret->sljedeci_elemenat=novi_cvor;
                   novi_cvor->sljedeci_elemenat=poc;
               }
               if(i==0&&j==2) 
               {
                   poc=novi_cvor;
                   pret=novi_cvor;
               }
               if(i!=0&&i!=3&&j!=14&&j!=2)
               {
                   pret->sljedeci_elemenat=novi_cvor;
                   pret=novi_cvor;
               }
           }
    }
    return poc;
}
std::queue<std::pair<string,string>> IzbaciKarteRazbrajanjem(Cvor *&pocetni,short int &r,int n)
{
    std::pair<int,int>p;
    p=std::make_pair(r,n);
    int nh(0);
    if(p.first<1||p.first>52||p.second<1) throw std::logic_error("Neispravni elementi za izbacivanje!");
    std::queue<std::pair<string,string>>pomocni ;
    Cvor *p_veza=pocetni,*p_veza1=pocetni;
    while (p_veza->sljedeci_elemenat!=p_veza1)  
        p_veza=p_veza->sljedeci_elemenat;
    for(int i(0);i<p.second;i++)
    {
        for(int j(0);j<p.first;j++)
        {
            p_veza1=p_veza1->sljedeci_elemenat;
             p_veza=p_veza->sljedeci_elemenat;
             nh++;
             std::cout << nh<< std::endl;
        }
        Karta spil=p_veza1->karta;
        string st;
        if(spil.boja==Boje::Herc) st=s1;
        if(spil.boja==Boje::Karo) st=s2;
        if(spil.boja==Boje::Pik) st=s3;
        if(spil.boja==Boje::Tref) st=s4;
        std::pair<string,string>par;
        par=std::make_pair(st,spil.vrijednost);
        pomocni.push(par);
        Cvor *s=p_veza1;
        if(s==pocetni);
        {
            Cvor *neki=pocetni;
            while (neki->sljedeci_elemenat!=pocetni) 
               neki=neki->sljedeci_elemenat;
            
            pocetni=pocetni->sljedeci_elemenat;
            neki->sljedeci_elemenat=pocetni;
            s->sljedeci_elemenat=s;
            delete s;
        }
        if(s!=pocetni)
        {
            p_veza1=p_veza1->sljedeci_elemenat;
            p_veza->sljedeci_elemenat=s->sljedeci_elemenat;
            s->sljedeci_elemenat=s;
            delete s;
        }
    } 
    return pomocni;
}
void VratiPrvihNKarata(Cvor *c,std::queue<std::pair<string,string>>&red,int n)
{
    if(n>red.size()) throw std::range_error("Nedovoljno karata u steku!");
    Cvor *pocetak=c;
    Cvor *pomocni=c;
    while (pomocni->sljedeci_elemenat!=pocetak) {
        pomocni=pomocni->sljedeci_elemenat;
    }
    for(int i(0);i<n;i++)
    {
        std::pair<string,string>parovi;
        parovi=red.front();
        Boje b,provjeri;
        int broj,br;
        string provjeri_vrijednost;
        string s(parovi.first);
        if(s==s1) br=0,b=Boje::Herc;
        if(s==s2) br=1,b=Boje::Karo;
        if(s==s3) br=2,b=Boje::Pik;
        if(s==s4) br=3,b=Boje::Tref;
        s=parovi.second;
        auto it(mapa_karata1.find(s));
        broj=it->second;
        int broj_boja,broj_vrijednosti;
        provjeri=(c->karta).boja;
        if(provjeri==Boje(0)) broj_boja=0;
        if(provjeri==Boje(1)) broj_boja=1;
        if(provjeri==Boje(2)) broj_boja=2;
        if(provjeri==Boje(3)) broj_boja=3;
        provjeri_vrijednost=(c->karta).vrijednost;
        auto it1(mapa_karata1.find(provjeri_vrijednost));
        broj_vrijednosti=it1->second;
        while (broj_boja!=br) {
           c=c->sljedeci_elemenat;
           pomocni=pomocni->sljedeci_elemenat;
           Boje bo((c->karta).boja);
           if(bo==Boje(0)) broj_boja=0;
           if(bo==Boje(1)) broj_boja=1;
           if(bo==Boje(2)) broj_boja=2;
           if(bo==Boje(3)) broj_boja=3;
        }
        while (broj_vrijednosti<broj) {
            c=c->sljedeci_elemenat;
            pomocni=pomocni->sljedeci_elemenat;
            string str((c->karta).vrijednost);
            auto it(mapa_karata1.find(str));
            broj_vrijednosti=it->second;
        }
        Cvor *novi_cvor(new Cvor);
        (novi_cvor->karta).boja=b;
        (novi_cvor->karta).vrijednost=parovi.second;
        novi_cvor->sljedeci_elemenat=nullptr;
        pomocni->sljedeci_elemenat=novi_cvor;
        novi_cvor->sljedeci_elemenat=c;
        red.pop();
        pomocni=pomocni->sljedeci_elemenat;
        while (pomocni->sljedeci_elemenat!=pocetak) {
            pomocni=pomocni->sljedeci_elemenat;
        }
        c=pocetak;
    }
}
int main ()
{
    //try
   // {
    Cvor *p=KrieirajSpil();
     std::cout << "Unesite korak razbrajanja: ";
    short int korak;
    std::cin >> korak;
    int br_karata;
    std::cout << "Unesite broj karata koje zelite izbaciti: ";
    std::cin >> br_karata; 
    std::multimap<Boje,std::string>m;
    std::queue<std::pair<std::string,std::string>>red;
    red = IzbaciKarteRazbrajanjem(p,korak,br_karata);
    std::cout << red.size() << std::endl;
    /*std::cout << "U spilu trenutno ima "<<s.size()<<" karata, i to:";
    int t(1);
    std::string ref{};
    for(auto x : s)
    {
        b=x.first;
        if(b==Boje::Pik) { str=s1 ; if(ref!=str) t=1; }  
        if(b==Boje::Tref) { str=s2; if(ref!=str) t=1; }
        if(b==Boje::Herc) {str=s3; if(ref!=str) t=1;}
        if(b==Boje::Karo) {str=s4; if(ref!=str) t=1;}
        ref=str;
        if(str==ref&&t==1)
        {
            std::cout <<"\n" <<str<<": ";
            t++;
        }    
            std::cout <<x.second<<" ";
    }  
    }
    catch(std::logic_error &i)
    {
        std::cout << i.what() << std::endl;
        return 0;
    }
    std::cout << "\nUnesite broj karata koje zelite vratiti u spil: ";
    int vrati;
    std::cin >> vrati;

    int t=1;
    std::string ref1{};
    try
    {
    VratiPrvihNKarata(s,red,vrati);
    std::cout << "U spilu trenutno ima "<<s.size()<<" karata, i to:";
    for(auto x : s)
    {
        b=x.first;
        if(b==Boje::Pik) { str=s1; if(ref1!=str) t=1;}
        if(b==Boje::Tref) {str=s2; if(ref1!=str) t=1; }
        if(b==Boje::Herc) { str=s3; if(ref1!=str) t=1; }
        if(b==Boje::Karo) {str=s4; if(ref1!=str) t=1; }
        ref1=str;
        if(str==ref1&&t==1)
        {
            std::cout << "\n"<<str <<": ";
            t++;
        }
        std::cout << x.second<<" ";
    }
    }
    catch(std::range_error &i)
    {
        std::cout << i.what() << std::endl;
    }
    catch(std::domain_error &i)
    {
        std::cout << i.what() << std::endl;
    }
    catch(std::logic_error &i)
    {
        std::cout << i.what() << std::endl;
    }
	return 0; */
}
