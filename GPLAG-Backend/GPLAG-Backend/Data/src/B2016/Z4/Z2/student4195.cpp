#include <iostream>
#include <string>
#include <stdexcept>

using std::cout;
using std::cin;
using std::endl;
using std::string;

class GradjaninBiH{
   public:
    enum Pol{Musko, Zensko};
    GradjaninBiH(std::string ime_i_prezime, long long int jmbg);
    GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja,
    int godina_rodjenja, int sifra_regije, Pol pol);
    ~GradjaninBiH();
    GradjaninBiH(const GradjaninBiH &gradjanin)=delete;
    std::string DajImeIPrezime() const {return iip;}
    long long int DajJMBG() const { return UJMBG(jmbg);}
    int DajDanRodjenja() const {return dan;}
    int DajMjesecRodjenja() const {return mjesec;}
    int DajGodinuRodjenja() const { return godina;}
    int DajSifruRegije() const {return sifra_regije; }
    Pol DajPol() const {return pol; }
    void PromijeniImeIPrezime(std::string novo_ime){
        iip=std::move(novo_ime);
    }
   private:
    static GradjaninBiH* zadnji;
    GradjaninBiH* prethodni=nullptr;
    int jmbg[13];
    string iip;
    int dan,mjesec,godina,sifra_regije;
    Pol pol;
    long long int UJMBG(const int *p) const;
};
GradjaninBiH* GradjaninBiH::zadnji=nullptr;

GradjaninBiH::~GradjaninBiH(){
    if(this==zadnji) zadnji=prethodni; //zadnji samo preusmjeri na prethodni, ako je on i prvi, odna ce bit nullptrs vakako
    else if (prethodni!=nullptr) { //Ako nije ni prvi ni zadnji, onda preusmjeri pok slejdeceg da pokazuje na prethodni od trenutnog
        for(auto pok=zadnji; pok!=nullptr; pok=pok->prethodni){
            if(pok->prethodni==this){
                pok->prethodni=this->prethodni;
                break;
            }
        }
    }
}


int BrojCifara(long long int jmbg){
    int br(0);
    while(jmbg>0){
        jmbg/=10;
        br++;
    }
    return br;
}

int UBroj(int *p,int br_mjesta){
    int broj(0),stepen(1);
    for(int i=0; i<br_mjesta-1; i++) stepen*=10;
    for(int j=0; j<br_mjesta; j++){
        broj+=p[j]*stepen;
        stepen/=10;
    }
    return broj;
}

long long int GradjaninBiH::UJMBG(const int p[]) const{
    long long int broj(0), stepen(1);
    for(int i=0; i<12; i++) stepen*=10;
    for(int j=0; j<13; j++){
        broj+=p[j]*stepen;
        stepen/=10;
    }
    return broj;
}

bool PrestupnaGodina(int godina){
    if(godina%400==0 or (godina%100!=0 and godina%4==0)) return true;
    return false;
}

int BrojDana(int mjesec,int godina){
    int dani[12]{31,28,31,30,31,30,31,31,30,31,30,31};
    if(PrestupnaGodina(godina))
        dani[1]++;
    return dani[mjesec-1];
}

void ProvjeriDatum(int dan, int mjesec, int godina,string poruka){ //Baci izuzetak ako ne valja, u supr nista ne radi
    if(mjesec<1 or mjesec>12 or dan<1 or godina<0 or dan>BrojDana(mjesec,godina)) 
        throw std::logic_error(poruka);
}

int ProvjeriZadnju(int kod, int* jmbg,bool provjeri=true){ //Baca izuzetak ako ne valja, u supr nista ne radi
    int suma(0),t=7,k=6;
    for(int i=0; i<6; i++,t--,k++) suma+=t*(jmbg[i]+jmbg[k]);
    suma=11-suma%11;
    if(suma==11) suma=0;
    if(suma==10 and !provjeri) return -1;
    if(provjeri and suma!=kod) throw std::logic_error("Nevazeci jmbg");
    return suma;
    
}

bool UporediJMBG(int* niz1, int* niz2){
    for(int i=0; i<13; i++){
        if(niz1[i]!=niz2[i]) return false;
    }
    return true;
}

GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, long long int jmbg_br):iip(ime_i_prezime){
    if(BrojCifara(jmbg_br)!=12 and BrojCifara(jmbg_br)!=13) throw std::logic_error("Nevazeci jmbg");
    int br(12);
    while(br>=0){
        jmbg[br]=jmbg_br%10;
        jmbg_br/=10;
        br--;
    }
    dan=UBroj(jmbg,2); mjesec = UBroj(jmbg+2,2),godina = UBroj(jmbg+4,3); sifra_regije= UBroj(jmbg+7,2);
    int br_spola(UBroj(jmbg+9,3)), kod(UBroj(jmbg+12,1));
    if(godina>=0 and godina<=17) godina+=2000;
    else godina+=1000;
    ProvjeriDatum(dan,mjesec,godina,"Nevazeci jmbg");
    ProvjeriZadnju(kod,jmbg);
    if(br_spola>=500) pol=Pol::Zensko;
    else pol=Pol::Musko;
    for(auto pok=this->prethodni; pok!=nullptr; pok=pok->prethodni){
        if(UporediJMBG(this->jmbg,pok->jmbg)) throw std::logic_error("Vec postoji gradjanin sa istim JMBG");
    }
    prethodni=zadnji;
    zadnji=this;
    
}

GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja,
int godina_rodjenja, int sifra_regije, Pol pol): iip(ime_i_prezime),dan(dan_rodjenja),mjesec(mjesec_rodjenja),godina(godina_rodjenja),pol(pol){
    ProvjeriDatum(dan,mjesec,godina,"Neispravni podaci");
    if(sifra_regije<0 or sifra_regije>99) throw std::logic_error("Neispravni podaci");
    jmbg[1]=dan_rodjenja%10; dan_rodjenja/=10; jmbg[0]=dan_rodjenja%10; //dan
    jmbg[3]=mjesec_rodjenja%10; mjesec_rodjenja/=10; jmbg[2]=mjesec_rodjenja%10; //mjesec
    int i=6;
    while(i>3){                                                                   //godina
        jmbg[i]=godina_rodjenja%10;
        godina_rodjenja/=10;
        i--;
    }
    jmbg[8]=sifra_regije%10; sifra_regije/=10; jmbg[7]=sifra_regije%10; //sifra regije
    bool idi_dalje(false);
    int najmanji_kod;
    if(DajPol()==Pol::Musko) najmanji_kod=0;
    else najmanji_kod=500;
    while(true){
        for(auto pok=this->prethodni; pok!=nullptr; pok=pok->prethodni){
            if(pok->DajPol()==pol and pok->DajSifruRegije()==sifra_regije and DajDanRodjenja()==pok->DajDanRodjenja() and
            DajGodinuRodjenja()==pok->DajGodinuRodjenja() and DajMjesecRodjenja()==pok->DajMjesecRodjenja()){
                int br(12);
                long long int jmbg_br(pok->DajJMBG());
                int jmbgk[13];
                while(br>=0){
                    jmbgk[br]=jmbg_br%10;
                    jmbg_br/=10;
                    br--;
                }
                int sifra(UBroj(jmbgk+9,3));
                if(sifra==najmanji_kod) {
                    idi_dalje=true;
                    break;
                }
            }
        }
        if(idi_dalje){
            najmanji_kod++; //Probaj sljedeci
            idi_dalje=false;
            continue;
        }
        i=11;
        while(i>8){                                                                   //godina
            jmbg[i]=najmanji_kod%10;
            najmanji_kod/=10;
            i--;
        }
        int suma(ProvjeriZadnju(najmanji_kod,jmbg,false));
        if(suma==-1) {
            najmanji_kod++;
            continue;
        }
        jmbg[12]=suma;
        break;
    }
}

int main ()
{
    GradjaninBiH* gradjani[100];//svi na nullptr radi inicijalizacije
    int velicina;
    cout<<"Koliko gradjana zelite unijeti po JMBG? "<<endl;
    cin>>velicina;
    cin.ignore(10000,'\n');
    for(int i=0; i<velicina; i++) gradjani[i]=nullptr;
    try{
        for(int i=0; i<velicina; i++){
           cout<<"Unesite ime i prezime (u istom redu): "<<endl;
           string iip;
           getline(cin,iip);
           cout<<"Unesite JMBG: "<<endl;
           long long int jmbg;
           cin>>jmbg;
           cin.ignore(10000,'\n');
           try{
               gradjani[i]=new GradjaninBiH(iip,jmbg);
               cout<<"Unijeli ste gradjanina "<<iip<<" rodjenog "<<gradjani[i]->DajDanRodjenja()<<"."<<gradjani[i]->DajMjesecRodjenja()<<
               "."<<gradjani[i]->DajGodinuRodjenja()<<" u regiji "<<gradjani[i]->DajSifruRegije()<<", ";
              if(gradjani[i]->DajPol()==GradjaninBiH::Pol::Musko) cout<<"musko.";
              else cout<<"zensko.";
              cout<<endl;
           }
           catch(std::logic_error){
               cout<<"JMBG nije validan"<<endl;
               i--;
           }
        }
        for(int i=0; i<velicina; i++) delete gradjani[i];
        
        cout<<"Koliko gradjana zelite unijeti po datumu rodjenja, regiji i polu? "<<endl;
        cin>>velicina;
        cin.ignore(10000,'\n');
        for(int i=0; i<velicina; i++){
           cout<<"Unesite ime i prezime (u istom redu): "<<endl;
           string iip;
           getline(cin,iip);
           cout<<"Unesite datum rodjenja (format dd/mm/gggg): "<<endl;
           int dan,mjesec,godina;
           cin>>dan; cin.get();
           cin>>mjesec; cin.get();
           cin>>godina;
           cout<<"Unesite sifru regije: "<<endl;
           int sifra;
           cin>>sifra;
           cin.ignore(10000,'\n');
           cout<<"Unesite M za musko, Z za zensko: "<<endl;
           string spol;
           GradjaninBiH::Pol pol;
           getline(cin,spol);
           if(spol=="M") pol=GradjaninBiH::Pol::Musko;
           else pol=GradjaninBiH::Pol::Zensko;
           try{
             gradjani[i]=new GradjaninBiH(iip,dan,mjesec,godina,sifra,pol);
             cout<<"Unijeli ste gradjanina "<<gradjani[i]->DajImeIPrezime()<<" JMBG: "<<gradjani[i]->DajJMBG()<<"."<<endl;
           }
           catch(std::logic_error e){
               cout<<e.what()<<endl;
               i--;
           }
           
        }
        for(int i=0; i<velicina; i++) delete gradjani[i];
    }
    catch(std::bad_alloc){
        for(int i=0; i<velicina; i++) delete gradjani[i];
    }
    return 0;
}
