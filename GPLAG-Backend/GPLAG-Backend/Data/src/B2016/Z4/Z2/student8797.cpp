#include <iostream>
#include <stdexcept>

class GradjaninBiH{
    std::string i_i_p;
    int niz[13];
    GradjaninBiH *prije=nullptr;
    static GradjaninBiH *kraj;
    static int Validacija(int dan, int mjesec, int godina){
        int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if(godina % 4 == 0 && (godina % 100 != 0 || godina % 400 == 0))
            broj_dana[1]++;
        if(mjesec < 1 || mjesec > 12 || dan < 1 || dan > broj_dana[mjesec-1]) return 0; 
        return 1;
    }    
    static bool ima12(long long int l){
        int br(0);
        while (l!=0) {
            l/=10;
            br++;
        }
        if(br==12) return true; return false;
    }
public:
 enum Pol {Musko, Zensko};
 GradjaninBiH(std::string ime_i_prezime, long long int jmbg){
    int i=0;
    int niz2[13];
    int p[13];
    if(ima12(jmbg))
    {
        i=1;
        niz2[0]=0;
    }
    while(jmbg!=0)
    {
        niz2[i]=jmbg%10;
        jmbg/=10;
        i++;
    }
    
    for(; i>=0;i--) 
        p[12-i]=niz2[i];
    
    int mjesec=p[2]*10+p[3];
    int dan=p[0]*10+p[1];
    int godina=p[4]*100+p[5]*10+p[6];
    int a=11-(7*(p[0]+p[6])+6*(p[1]+p[7])+5*(p[2]+p[8])+4*(p[3]+p[9])+3*(p[4]+p[10])+2*(p[5]+p[11]))%11; 
    if(a==11) 
        a=0;
    if(Validacija(dan,mjesec,godina)==0 || jmbg<0 || a==10 || a!=p[12]) throw std::domain_error("JMBG nije validan");
    for(auto x(kraj); x!=nullptr;x=x->prije){
        bool isti(true);
        for(int i=0; i<13; i++){
            if(p[i]!=x->niz[i])
                isti=false;
        }
        if(isti) throw std::logic_error("Vec postoji gradjanin sa istim JMBG");
    }
    for(int i=0; i<13;i++)
        niz[i]=p[i];
    i_i_p=ime_i_prezime;
    if(kraj==nullptr)
        kraj=this;
    else{
        prije=kraj;
        kraj=this;
    }     
    
 }  
 GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja,  int godina_rodjenja, int sifra_regije, Pol pol);
 std::string DajImeIPrezime() const{
     return i_i_p;
 };  
 long long int DajJMBG() const{
    long long int suma=0;
    int k=10;
    for(int i=0; i<13; i++){
        suma=suma*k+niz[i];
    }
    return suma;
 } 
 int DajDanRodjenja() const{
    return niz[0]*10+niz[1];
 }  
 int DajMjesecRodjenja() const{
     return niz[2]*10+niz[3];
 }  
 int DajGodinuRodjenja() const{
     if(niz[4]==0) return 2000+niz[4]*100+niz[5]*10+niz[6];
     return 1000+niz[4]*100+niz[5]*10+niz[6];
 }  
 int DajSifruRegije() const{
     return niz[7]*10+niz[8];
 }  
 Pol DajPol() const{
     int rez(niz[9]*100+niz[10]*10+niz[11]);
     if(rez>=500) return Pol::Zensko;
     return Pol::Musko;
 }
 void PromijeniImeIPrezime(std::string novo_ime){
     i_i_p=novo_ime;
 }
 ~GradjaninBiH(){
     if(this==kraj)
        kraj=kraj->prije;
     else {
         auto x(kraj);
         for(auto y(kraj->prije);y!=this;y=y->prije) x=x->prije;
         if(this->prije==nullptr) 
            x->prije=nullptr;
         else    
            x->prije=this->prije;
     }      
 }
};
GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, int dan, int mjesec,  int godina, int sifra_regije, Pol pol){
    if(Validacija(dan,mjesec,godina)==0 || sifra_regije<0 || sifra_regije>99) throw std::logic_error("Neispravni podaci");
    int p[]{0,0,0};
    if(pol==Pol::Zensko) p[0]=5;
    niz[0]=dan/10;
    niz[1]=dan%10;
    niz[2]=mjesec/10;
    niz[3]=mjesec%10;
    niz[4]=(godina%1000)/100;
    niz[5]=(godina%100)/10;
    niz[6]=godina%10;
    niz[7]=sifra_regije/10;
    niz[8]=sifra_regije%10;
    while (true) {
        bool ima=false;
        for(auto x(kraj); x!=nullptr;x=x->prije){
            if((pol==Pol::Musko && x->niz[9]<5) || (pol==Pol::Zensko && x->niz[9]>=5)){
                if(x->niz[9]==p[0] && x->niz[10]==p[1] && x->niz[11]==p[2] && x->niz[11]==p[2] && x->DajSifruRegije()==sifra_regije && x->DajDanRodjenja()==dan&&x->DajMjesecRodjenja()==mjesec&&x->DajGodinuRodjenja()==godina){
                    ima=true;
                }
            }
        }
        if(ima || 11-(7*(niz[0]+niz[6])+6*(niz[1]+niz[7])+5*(niz[2]+niz[8])+4*(niz[3]+p[0])+3*(niz[4]+p[1])+2*(niz[5]+p[2]))%11==10){
            p[2]++;
            if(p[2]==10){
                p[2]=0;
                p[1]++;
                if(p[1]==10){
                   p[1]=0;
                   p[0]++;
               }
            }
        }
        
        else 
            break;
    }    
    niz[9]=p[0];
    niz[10]=p[1];
    niz[11]=p[2];
    niz[12]=11-(7*(niz[0]+niz[6])+6*(niz[1]+niz[7])+5*(niz[2]+niz[8])+4*(niz[3]+niz[9])+3*(niz[4]+niz[10])+2*(niz[5]+niz[11]))%11;
    if(niz[12]==11) niz[12]=0;
    i_i_p=ime_i_prezime;
    if(kraj==nullptr)
        kraj=this;
    else{
        prije=kraj;
        kraj=this;
    }   
}
GradjaninBiH *GradjaninBiH::kraj=nullptr;

int main ()
{
    GradjaninBiH* niz[100]{};
    std::cout << "Koliko gradjana zelite unijeti po JMBG? " << std::endl;
    int n; std::cin >> n;
    for(int i=0; i<n; i++){
        std::cout << "Unesite ime i prezime (u istom redu): " << std::endl;
        std::string ime;
        std::cin.ignore(10000,'\n');
        std::getline(std::cin, ime);
        std::cout << "Unesite JMBG: " << std::endl;
        long long int jmbg;
        std::cin >> jmbg;
        try {
            niz[i]=new GradjaninBiH(ime,jmbg);
            std::cout << "Unijeli ste gradjanina "<<niz[i]->DajImeIPrezime()<<" rodjenog "<<niz[i]->DajDanRodjenja()<<"."<<niz[i]->DajMjesecRodjenja()<<"."<<niz[i]->DajGodinuRodjenja()<<" u regiji "<<niz[i]->DajSifruRegije()<<", ";
            if(niz[i]->DajPol()==GradjaninBiH::Pol::Musko) std::cout << "musko";
            else std::cout << "zensko";
            std::cout <<"." << std::endl;
        }
        catch (std::domain_error error) {
            std::cout << error.what() << std::endl;
            i--;
        }
    }
    std::cout << "Koliko gradjana zelite unijeti po datumu rodjenja, regiji i polu? " << std::endl;
    int m; std::cin >> m;
    for(int i =0; i<m; i++){
        std::cout << "Unesite ime i prezime (u istom redu): " << std::endl;
        std::string ime;
        std::cin.ignore(10000,'\n');
        std::getline(std::cin, ime);
        std::cout << "Unesite datum rodjenja (format dd/mm/gggg): " << std::endl;
        char znak;
        int dan, mjesec,godina;
        std::cin >> dan>>znak>>mjesec>>znak>>godina;
        std::cout << "Unesite sifru regije: " << std::endl;
        int sifra_regije; std::cin >> sifra_regije;
        std::cout << "Unesite M za musko, Z za zensko: " << std::endl;
        char znakk; std::cin >> znakk; GradjaninBiH::Pol pol;
        if(znakk=='M') pol=GradjaninBiH::Pol::Musko; else pol=GradjaninBiH::Pol::Zensko;
        try {
            niz[i+n]=new GradjaninBiH(ime, dan, mjesec,godina,sifra_regije,pol);
            std::cout << "Unijeli ste gradjanina "<< niz[i+n]->DajImeIPrezime()<<" JMBG: "<<niz[i+n]->DajJMBG()<<"." << std::endl;
        }
        catch (std::logic_error error) {
            std::cout << error.what() << std::endl;
            i--;
        }
        
    }
    for(int i=0; i<100;i++) delete niz[i];
    
 
	return 0;
}