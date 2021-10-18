/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <string>
#include <stdexcept>

bool dat(int d,int  m, int g)
{
    if(m>12 || m<=0 || g<1917 || d<=0 || g>2017) return false;
    if((m==1 || m==3 || m==5 || m==7 || m==8|| m==10|| m==12)&&d>31) return false;
    if((m==4 || m==6 || m==9 || m==11)&&d>30) return false;
    if((g%400==0 || (g%4==0 && g%100!=0))&&d>29&&m==2) return false;
    if(d>28&&m==2&&!(g%400==0 || (g%4==0 && g%100!=0))) return false;
    return true;
}

bool IstiNiz(int *p,int *q,int l)
{
    for(int i=0;i<l;i++)
        if(p[i]!=q[i]) return false;
    return true;
}

class GradjaninBiH
{
    std::string ip;
    int c[13];
    GradjaninBiH* pok;
    static GradjaninBiH *prosli;
public:
    enum Pol {Musko, Zensko};
    GradjaninBiH(std::string ime_i_prezime, long long int jmbg)
    {
        ip=ime_i_prezime; 
        for(int i=12;i>=0;i--)
        {
            c[i]=jmbg%10;
            jmbg/=10;
        }
        if(jmbg) std::logic_error("JMBG nije validan");
        int b=1000;
        if(c[4]==0 && (c[5]==0 || (c[5]==1 && c[6]<=7))) b+=1000;
        int a=11-(7*(c[0]+c[6])+6*(c[1]+c[7])+5*(c[2]+c[8])+4*(c[3]+c[9])+3*(c[4]+c[10])+2*(c[5]+c[11]))%11;
        if(!dat(c[0]*10+c[1],c[2]*10+c[3],b+c[4]*100+c[5]*10+c[6])||(a!=c[12] && !(c[12]==0 && a==11))) throw std::logic_error("JMBG nije validan");
        for(auto pom=prosli;pom;pom=pom->pok) if(IstiNiz(c,pom->c,13)) throw std::logic_error("Vec postoji gradjanin sa istim JMBG");
        pok=prosli;
        prosli=this;
    }
    GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol)
    {
        if(!dat(dan_rodjenja,mjesec_rodjenja,godina_rodjenja)||sifra_regije<0||sifra_regije>99 ) throw std::logic_error("Neispravni podaci");
        ip=ime_i_prezime; 
        c[0]=dan_rodjenja/10;
        c[1]=dan_rodjenja%10;
        c[2]=mjesec_rodjenja/10;
        c[3]=mjesec_rodjenja%10;
        c[4]=(godina_rodjenja/100)%10;
        c[5]=(godina_rodjenja/10)%10;
        c[6]=godina_rodjenja%10;
        c[7]=sifra_regije/10;
        c[8]=sifra_regije%10;
        if(int(pol)) c[9]=5;
        else c[9]=0;
        c[10]=0,c[11]=0;
        for(auto pom=prosli;pom;pom=pom->pok)
        {
            if(IstiNiz(c,pom->c,9)) c[11]++;
            if(c[11]>=10) c[11]=0,c[10]++;
            if(c[10]>=10) c[10]=0,c[9]++;
        }
        if(11-(7*(c[0]+c[6])+6*(c[1]+c[7])+5*(c[2]+c[8])+4*(c[3]+c[9])+3*(c[4]+c[10])+2*(c[5]+c[11]))%11==10)
        {
            c[11]++;
            if(c[11]>=10) c[11]=0,c[10]++;
            if(c[10]>=10) c[10]=0,c[9]++;
        }
        c[12]=11-(7*(c[0]+c[6])+6*(c[1]+c[7])+5*(c[2]+c[8])+4*(c[3]+c[9])+3*(c[4]+c[10])+2*(c[5]+c[11]))%11;
        if(c[12]==11) c[12]=0;
        pok=prosli;
        prosli=this;
    }
    ~GradjaninBiH()
    {
        if(this==prosli) prosli=this->pok;
        else 
        {
            GradjaninBiH *pom=prosli;
            for(;pom->pok==this;pom=pom->pok);
            pom->pok=this->pok;
        }
    }
    std::string DajImeIPrezime() const {return ip;}
    long long int DajJMBG() const
    {
        long long int br=0;
        for(int i=0;i<13;i++)
        {
            br+=c[i];
            if(i!=12) br*=10;
        }
        return br;
    }
    int DajDanRodjenja() const  { return 10*c[0]+c[1];}
    int DajMjesecRodjenja() const{ return 10*c[2]+c[3];}
    int DajGodinuRodjenja() const
    {
        if(c[4]==0 && (c[5]==0 || (c[5]==1 && c[6]<=7)))
        return 2000+100*c[4]+10*c[5]+c[6];
        return 1000+100*c[4]+10*c[5]+c[6];
    }
    int DajSifruRegije() const{    return c[7]*10+c[8];}
    Pol DajPol() const { return Pol(c[9]>=5);}
    void PromijeniImeIPrezime(std::string novo_ime){ip=novo_ime;}
};
GradjaninBiH *GradjaninBiH::prosli=nullptr;
int main ()
{
    std::cout << "Koliko gradjana zelite unijeti po JMBG? \n";
    int n;
    std::cin >>n;
    for(int i=0;i<n;i++)
    {
        try
        {
            std::string ip;
            std::cout << "Unesite ime i prezime (u istom redu): \n";
            std::cin >> std::ws;
            std::getline(std::cin,ip);
            long long int br;
            std::cout <<"Unesite JMBG: \n";
            std::cin >> br;
            GradjaninBiH gr(ip,br);
            std::cout << "Unijeli ste gradjanina " << gr.DajImeIPrezime() << " rodjenog " << gr.DajDanRodjenja() << "." << gr.DajMjesecRodjenja() << "." << gr.DajGodinuRodjenja() << " u regiji " << gr.DajSifruRegije() << ", ";
            if(gr.DajPol()) std::cout << "zensko.\n";
            else std::cout << "musko.\n";
        }
        catch(std::logic_error x)
        {
            std::cout << x.what()<<"\n";
            i--;
        }
    }
    std::cout << "Koliko gradjana zelite unijeti po datumu rodjenja, regiji i polu? \n";
    std::cin >> n;
    for(int i=0;i<n;i++)
    {
        try
        {
            char p;
            std::string ip;
            std::cout << "Unesite ime i prezime (u istom redu): \n";
            if(p=std::cin.peek(),p==' '|| p=='\n') std::cin >> std::ws;
            std::getline(std::cin,ip);
            int d,m,g,sr;
            std::cout <<"Unesite datum rodjenja (format dd/mm/gggg): \n";
            std::cin >> d >> p >> m >>p>> g;
            std::cout << "Unesite sifru regije: \n";
            std::cin >> sr;
            int a;
            std::cout << "Unesite M za musko, Z za zensko: \n";
            p=getchar();
            p=getchar();
            if(p=='M' || p=='m') a=0;
            else a=1;
            GradjaninBiH gr(ip,d,m,g,sr,GradjaninBiH::Pol(a));
            std::cout << "Unijeli ste gradjanina " << gr.DajImeIPrezime() << " JMBG: " << gr.DajJMBG() <<".\n";
        }
        catch(std::logic_error x)
        {
            std::cout << x.what() <<"\n";
            i--;
        }
    }
	return 0;
}