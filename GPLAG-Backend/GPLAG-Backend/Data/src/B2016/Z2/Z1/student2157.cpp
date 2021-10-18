/B 16/17, Zadaća 2, Zadatak 1

	NAPOMENA: i javni ATo-vi su dio postavke

	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba

*/
#include <iostream>
#include <vector>
#include <new>
#include <string>
#include <complex>
#include <stdexcept>
#include <algorithm>
#include <deque>

enum class Komande {
PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu,
ZavrsiIgru, KreirajIgru
};
enum class KodoviGresaka {
PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar
};
enum class Status {
 NijeKraj, KrajPoraz, KrajPobjeda
};
enum class Smjerovi {
 GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo
};
enum class Polje {
 Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina
};
typedef std::vector<std::vector<Polje>> Tabla;

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine){//KREIRANJE TABLE SA MINAMA
    Tabla p(n,std::vector<Polje>(n,Polje(0)));
    if(mine.size()==0)return p;
    for(int i=0;i<mine.size();i++){
        if(mine[i].size()!=2){
            throw std::domain_error("Ilegalan format zadavanja mina");
        }
    }
    for(int i=0;i<mine.size();i++){
            if(mine[i][0]>n-1 || mine[i][1]>n-1)throw std::domain_error("Ilegalne pozicije mina");
    }

	int brojac(0);
	for(;;){
	    int i=mine[brojac][0];
        for(int j=0;j<n;j++){
            if(j==mine[brojac][1]){p[i][j]=Polje(2);brojac++;break;}
        }
    if(brojac==mine.size())break;
	}
	p[0][0]=Polje::Prazno;
return p;
}
int BrojMinaUOkolini(std::vector<std::vector<int>> m,int x,int y){//SUMA U OKOLINI POMOCNA
    int suma=0;
   for(int i=x-1;i<=x+1;i++){
    for(int j=y-1;j<=y+1;j++){
        if(i==x && j==y)continue;
        if(m[i][j]==2)suma++;
        }
   }
    return suma;
}
std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y){  //OKOLINA FUNKCIJA
    std::string izuzetak("Polje (");
    izuzetak.push_back('0'+x);
    izuzetak.push_back(',');
    izuzetak.push_back('0'+y);
    izuzetak=izuzetak+(") ne postoji");
    if(x>polja.size()-1 || y>polja.size()-1){
        throw std::domain_error(izuzetak);
    }
    int vel=polja.size()+4;
    std::vector<std::vector<int>> vek;
    vek=std::vector<std::vector<int>>(vel,std::vector<int>(vel,0));
    for(int i=2;i<vek.size();i++){
       if(i==vel-2)break;
    for(int j=2;j<vek.size();j++){
            if(j==vel-2)break;
        if(int(polja[i-2][j-2]))vek[i][j]=int(polja[i-2][j-2]);
    }
   }
   y=y+2;
   x=x+2;
   int brx(0);
   int bry(0);
    std::vector<std::vector<int>> Okolona(3,std::vector<int>(3,0));
    for(int i=x-1;i<=(x+1);i++){
            bry=0;
        for(int j=y-1;j<=(y+1);j++){
            Okolona[brx][bry]=BrojMinaUOkolini(vek,i,j);
            bry++;
        }brx++;
    }
    return Okolona;
}
void BlokirajPolje(Tabla &polja, int x, int y){
    std::string izuzetak("Polje (");
    izuzetak.push_back('0'+x);
    izuzetak.push_back(',');
    izuzetak.push_back('0'+y);
    izuzetak=izuzetak+(") ne postoji");
    if(x>polja.size()-1 || y>polja.size()-1){
        throw std::domain_error(izuzetak);
    }
    if(int(polja[x][y])<=2 && int(polja[x][y])>=0) polja[x][y]=Polje(int(polja[x][y])+3);
}
void DeblokirajPolje(Tabla &polja, int x, int y){
    std::string izuzetak("Polje (");
    izuzetak.push_back('0'+x);
    izuzetak.push_back(',');
    izuzetak.push_back('0'+y);
    izuzetak=izuzetak+(") ne postoji");
    if(x>polja.size()-1 || y>polja.size()-1){
        throw std::domain_error(izuzetak);
    }
    if(int(polja[x][y])<=5 && int(polja[x][y])>=3) polja[x][y]=Polje(int(polja[x][y])-3);
}
Status Idi(Tabla &polja,int &x,int &y,Smjerovi smjer){
    if(smjer==Smjerovi::GoreLijevo){//GORELIJEVO
        if(x==0||y==0)throw std::out_of_range("Izlazak van igrace table");
        if(int(polja[x-1][y-1]) >=3)throw std::logic_error("Blokirano polje");
        polja[x][y]=Polje(1);
        x--;y--;
    }
    else if(smjer==Smjerovi::Gore){//GORE
        if(x==0)throw std::out_of_range("Izlazak van igrace table");
        if(int(polja[x-1][y]) >=3)throw std::logic_error("Blokirano polje");
        polja[x][y]=Polje(1);
        x--;
    }
    else if(smjer==Smjerovi::GoreDesno){//GOREDESNO
        if(x==0 || y==(polja.size()-1))throw std::out_of_range("Izlazak van igrace table");
        if(int(polja[x-1][y+1]) >=3)throw std::logic_error("Blokirano polje");
        polja[x][y]=Polje(1);
        x--;y++;
    }
    else if(smjer==Smjerovi::Desno){//DESNO
        if(y==(polja.size()-1))throw std::out_of_range("Izlazak van igrace table");
        if(int(polja[x][y+1]) >=3)throw std::logic_error("Blokirano polje");
        polja[x][y]=Polje(1);
        y++;
    }
    else if(smjer==Smjerovi::DoljeDesno){//DOLEDESNO
        if(x==(polja.size()-1) || y==(polja.size()-1))throw std::out_of_range("Izlazak van igrace table");
        if(int(polja[x+1][y+1]) >=3)throw std::logic_error("Blokirano polje");
        polja[x][y]=Polje(1);
        x++;y++;
    }
    else if(smjer==Smjerovi::Dolje){//DOLE
        if(x==(polja.size()-1))throw std::out_of_range("Izlazak van igrace table");
        if(int(polja[x+1][y]) >=3)throw std::logic_error("Blokirano polje");
        polja[x][y]=Polje(1);
        x++;
    }
    else if(smjer==Smjerovi::DoljeLijevo){//DOLELIJEVO
        if(x==(polja.size()-1) || (y==0))throw std::out_of_range("Izlazak van igrace table");
        if(int(polja[x+1][y-1]) >=3)throw std::logic_error("Blokirano polje");
        polja[x][y]=Polje(1);
        x++;y--;
    }
    else if(smjer==Smjerovi::Lijevo){//LIJEVO
        if(y==0)throw std::out_of_range("Izlazak van igrace table");
        if(int(polja[x][y-1]) >=3)throw std::logic_error("Blokirano polje");
        polja[x][y]=Polje(1);
        y--;
    }
    if(polja[x][y]==Polje::Mina)return Status::KrajPoraz;
    for(int i=0;i<polja.size();i++){
        for(int j=0;j<polja.size();j++){
            if(i==x && y==j)continue;
            if(polja[i][j]==Polje::BlokiranoPrazno || polja[i][j]==Polje::Prazno)return Status(0);
        }
    }
return Status(2);
}
Status Idi(Tabla &polja,int &x,int &y,int x0,int y0){
    if(x0>polja.size()-1 || y0>polja.size()-1 || x0<0 || y0<0){
        throw std::out_of_range("Izlazak van igrace table");
    }
    if(int(polja[x0][y0]) >=3)throw std::logic_error("Blokirano polje");
    if(int(polja[x0][y0]) ==2)return Status(1);
    polja[x][y] = Polje(1);
    x=x0;
    y=y0;
    if(polja[x][y]==Polje::Mina)return Status::KrajPoraz;
    for(int i=0;i<polja.size();i++){
        for(int j=0;j<polja.size();j++){
            if(i==x && y==j)continue;
            if(polja[i][j]==Polje::BlokiranoPrazno || polja[i][j]==Polje::Prazno)return Status(0);
        }
    }
return Status(2);
}
void PrijaviGresku(KodoviGresaka greska){
    if(greska==KodoviGresaka(0))std::cout<<"Nerazumljiva komanda!"<<std::endl;
    if(greska==KodoviGresaka(1))std::cout<<"Komanda trazi parametar koji nije naveden!"<<std::endl;
    if(greska==KodoviGresaka(2))std::cout<<"Zadan je suvisan parametar nakon komande!"<<std::endl;
    if(greska==KodoviGresaka(3))std::cout<<"Parametar komande nije ispravan!"<<std::endl;
}
void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y,Smjerovi p_smjer = Smjerovi::Gore, int p_x = 0, int p_y = 0){
    auto statut(Status::NijeKraj);
    int parametar;
    if(komanda==Komande::KreirajIgru){
        std::vector<std::vector<int>> mine;
        std::cout<<"Unesite broj polja: ";
        for(;;){
            std::cin>>parametar;
            if(parametar!=0)break;
            else {
                std::cout<<"Greska, unesite ponovo!"<<std::endl;std::cin.clear();std::cin.ignore(1000,'\n');}
          }
          mine=std::vector<std::vector<int>>(parametar*parametar,std::vector<int>(2,0));
          std::cout<<"Unesite pozicije mina: ";
          std::string unos_mine;
          int brojac(0);
          std::cin.ignore(10000,'\n');
          for(;;){
            std::getline(std::cin,unos_mine,'\n');
            auto p=remove(unos_mine.begin(),unos_mine.end(),' ');
            unos_mine.resize(p-unos_mine.begin());
            auto c=remove(unos_mine.begin(),unos_mine.end(),'\t');
            unos_mine.resize(c-unos_mine.begin());
            if(unos_mine[0]=='.'&& unos_mine.size()==1){
                    break;
            }
            if(unos_mine[0]=='('&&(unos_mine[1]>='0' && unos_mine[1]<='9')&& unos_mine[2]==','&&(unos_mine[3]>='0' && unos_mine[3]<='9') && unos_mine[4]==')'){
                if(unos_mine.size()==5){
                        int a=int(unos_mine[1])-48;
                        int b=int(unos_mine[3])-48;
                    if(a<(parametar) && b<(parametar)){
                        mine[brojac][0]=a;
                        mine[brojac][1]=b;
                        brojac++;
                        continue;

                        }
                    else if(a>=parametar || b>=parametar){
                        std::cout<<"Greska, unesite ponovo!"<<std::endl;
                        continue;
                        }
                }
                else{
                    std::cout<<"Greska, unesite ponovo!"<<std::endl;
                    continue;
                }
            }
            else{
                std::cout<<"Greska, unesite ponovo!"<<std::endl;
                continue;
            }
            break;
          }
        mine.resize(brojac+1);
        polja=KreirajIgru(parametar,mine);
      }

    if(komanda==Komande::PomjeriJednoMjesto || komanda==Komande::PomjeriDalje){
        try{
            if(komanda==Komande::PomjeriJednoMjesto)statut=Idi(polja,x,y,p_smjer);
            if(komanda==Komande::PomjeriDalje)statut=Idi(polja,x,y,p_x,p_y);
        std::cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")"<<std::endl;
        }
        catch(std::out_of_range iz){
            std::cout<<iz.what()<<std::endl;
        }
        catch(std::logic_error iz){
            std::cout<<iz.what()<<std::endl;
        }

    }
    if(komanda==Komande::Blokiraj || komanda==Komande::Deblokiraj){
        try{
            if(komanda==Komande::Blokiraj)BlokirajPolje(polja,p_x,p_y);
            if(komanda==Komande::Deblokiraj)DeblokirajPolje(polja,p_x,p_y);
        }
        catch(std::domain_error x){
            std::cout<<x.what()<<std::endl;
        }
    }
    if(komanda==Komande::PrikaziOkolinu){
        try{
        auto ispis=PrikaziOkolinu(polja,x,y);
        for(auto i:ispis){
            for(auto j:i){
                std::cout<<j<<" ";
            }std::cout<<std::endl;
        }
        }
    catch(std::domain_error x){
    std::cout<<x.what()<<std::endl;
    }
    }
    if(komanda==Komande::ZavrsiIgru){
       for(int i=0;i<polja.size();i++){
            for(int j=0;j<polja[i].size();j++){
                polja[i][j]=Polje::Prazno;
            }
        }
        std::cout<<"Dovidjenja!";
    }

    if(statut==Status::KrajPoraz || statut==Status::KrajPobjeda || komanda==Komande::ZavrsiIgru){
        for(int i=0;i<polja.size();i++){
            for(int j=0;j<polja.size();j++){
                polja[i][j]=Polje::Prazno;
            }
        }
        if(statut==Status::KrajPoraz)std::cout<<"Nagazili ste na minu"<<std::endl;
        if(statut==Status::KrajPobjeda)std::cout<<"Bravo, obisli ste sva sigurna polja"<<std::endl;
        throw std::runtime_error("Igra zavrsena");
    }

}
bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y,KodoviGresaka &greska){
    bool c(true);
    std::string unos_komande;
    std::getline(std::cin,unos_komande,'\n');
    auto p=remove(unos_komande.begin(),unos_komande.end(),' ');
    unos_komande.resize(p-unos_komande.begin());
    auto d=remove(unos_komande.begin(),unos_komande.end(),'\t');
    unos_komande.resize(d-unos_komande.begin());
    if(unos_komande[0]=='K'){
        if(unos_komande.size()==1 && x==0 && y==0){
        komanda=Komande::KreirajIgru;
        return c;
        }
        else greska=KodoviGresaka(2);

    }
    else if(unos_komande[0]=='P' && unos_komande[1]=='1'){
            c=true;
            komanda=Komande::PomjeriJednoMjesto;
        if(unos_komande[2]=='G' && unos_komande[3]=='L' && unos_komande.size()==4){
            smjer=Smjerovi::GoreLijevo;
            return c;
        }
        else if(unos_komande[2]=='G' && unos_komande.size()==3){
            smjer=Smjerovi::Gore;
            return c;
        }
        else if(unos_komande[2]=='G' && unos_komande[3]=='D' &&  unos_komande.size()==4){
            smjer=Smjerovi::GoreDesno;
            return c;
        }
        else if(unos_komande[2]=='D' && unos_komande.size()==3){
            smjer=Smjerovi::Desno;
            return c;
        }
        else if(unos_komande[2]=='D' && unos_komande[3]=='o' && unos_komande[4]=='D' && unos_komande.size()==5){
            smjer=Smjerovi::DoljeDesno;
            return c;
        }
        else if(unos_komande[2]=='D' && unos_komande[3]=='o' && unos_komande.size()==4){
            smjer=Smjerovi::Dolje;
            return c;
        }
        else if(unos_komande[2]=='D' && unos_komande[3]=='o' && unos_komande[4]=='L' &&  unos_komande.size()==5){
            smjer=Smjerovi::DoljeLijevo;
            return c;
        }
        else if(unos_komande[2]=='L' && unos_komande.size()==3){
            smjer=Smjerovi::Lijevo;
            return c;
        }
        else if(unos_komande.size()==2){
                greska=KodoviGresaka(1);
                c=false;
        }
        else{greska=KodoviGresaka(3);c=false;}
    }
    else if(unos_komande[0]=='P' && unos_komande[1]=='>'){
        if((unos_komande[2]>='0'&& unos_komande[2]<='9') && (unos_komande[3]>='0'&& unos_komande[3]<='9')&& unos_komande.size()==4){
            x=int(unos_komande[2])-48;
            y=int(unos_komande[3])-48;
            komanda=Komande::PomjeriDalje;
            return c;
        }
        else if(unos_komande.size()==2){greska=KodoviGresaka::NedostajeParametar;c=false;}
        else{greska=KodoviGresaka::NeispravanParametar;c=false;}
    }
    else if(unos_komande[0]=='B'){
        if((unos_komande[1]>='0'&& unos_komande[1]<='9') && (unos_komande[2]>='0'&& unos_komande[2]<='9')  && unos_komande.size()==3){
            x=int(unos_komande[1])-48;
            y=int(unos_komande[2])-48;
            komanda=Komande::Blokiraj;
            return c;
        }
        else if(unos_komande.size()==1){greska=KodoviGresaka::NedostajeParametar;c=false;}
        else{greska=KodoviGresaka::NeispravanParametar;c=false;}
    }
    else if(unos_komande[0]=='D'){
        if((unos_komande[1]>='0'&& unos_komande[1]<='9') && (unos_komande[2]>='0'&& unos_komande[2]<='9')  && unos_komande.size()==3){
            x=int(unos_komande[1])-48;
            y=int(unos_komande[2])-48;
            komanda=Komande::Deblokiraj;
            return c;
        }
        else if(unos_komande.size()==1){greska=KodoviGresaka::NedostajeParametar;c=false;}
        else{greska=KodoviGresaka::NeispravanParametar;c=false;}
    }
    else if(unos_komande[0]=='P' && unos_komande[1]=='O'){
        if(unos_komande.size()==2){
                komanda=Komande::PrikaziOkolinu;
                return c;
        }
        else{greska=KodoviGresaka::SuvisanParametar;c=false;}
    }
    else if(unos_komande[0]=='Z'){
        if(unos_komande.size()==1){
                komanda=Komande::ZavrsiIgru;return c;
        }
        else{greska=KodoviGresaka::SuvisanParametar;c=false;}
    }
    else{greska=KodoviGresaka::PogresnaKomanda;c=false;}


    return c;
}
int main ()
{
	int x(0);int y(0);
	int trenutnix(0);int trenutniy(0);
	Smjerovi smjer=Smjerovi::Gore;
	Komande komanda;
	Tabla Ploca;
	KodoviGresaka greska;
	std::cout<<"Unesite komandu: ";
	try{
	for(;;){
        trenutnix=x;
        trenutniy=y;
        if(UnosKomande(komanda,smjer,x,y,greska)){
            if(komanda==Komande::PomjeriDalje || komanda==Komande::Blokiraj || komanda==Komande::Deblokiraj){
                int privx,privy;
                privx=x;
                privy=y;
                x=trenutnix;
                y=trenutniy;
                trenutnix=privx;
                trenutniy=privy;
                IzvrsiKomandu(komanda,Ploca,x,y,smjer,trenutnix,trenutniy);
            }
            else IzvrsiKomandu(komanda,Ploca,x,y,smjer);
        std::cout<<"Unesite komandu: ";
        }
        else{
            PrijaviGresku(greska);
        }
    }
    }
    catch(std::runtime_error x){
    return 0;
    }
 return 0;
 }
