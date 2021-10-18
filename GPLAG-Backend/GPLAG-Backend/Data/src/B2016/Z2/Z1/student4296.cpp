#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
enum class Polje
{
    Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina
};
enum class Smjerovi
{
    GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo
};
enum class Status
{
    NijeKraj, KrajPoraz, KrajPobjeda
};
enum class KodoviGresaka
{
    PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar
};
enum class Komande
{
    PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu,
    ZavrsiIgru, KreirajIgru
};

typedef std::vector<std::vector<Polje>> Tabla;
Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine)
{
    Tabla K(n,vector<Polje> (n, Polje::Prazno) );
    for(int i=0; i<mine.size(); i++) {
        if(mine[i].size()!=2) throw std::domain_error ("Ilegalan format zadavanja mina");
    }
    for(int i=0; i<mine.size(); i++) {
        if(mine[i][0]>=n || mine[i][1]>=n) {
            throw std::domain_error ("Ilegalne pozicije mina");
        }
        K[mine[i][0]][mine[i][1]]=Polje::Mina;
    }
    return K;
}

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y)
{
    std::vector<std::vector<int>> O(3, std::vector<int> (3));
    int br {};
    int red {}, kol {};
    int vel(polja.size());
    int H=0;
    if(x<0 || y<0 || x>=vel || y>=vel) {
        string s("Polje () ne postoji");
        string a("0");
        a=std::to_string(x)+","+std::to_string(y);
        s.insert(7,a);
        throw std::domain_error (s);
    }
    for(int i=x-1; i<x+2; i++) {
        kol=0;
        for(int j=y-1; j<y+2; j++) {
            if(i>vel || j>vel)
                break;
            for(int k=i-1; k<i+2; k++) {
                for(int l=j-1; l<j+2; l++) {
                    if(k<0 || l<0)
                        continue;
                    else if(k>vel || l>vel)
                        break;
                    else if(k==i && l==j)
                        continue;
                    else if(polja[k][l]==Polje::Mina) br++;
                }
            }

            O[red][kol]=br;
            kol++;
            br=0;
        }
        H++;
        red++;
    }
    return O;
}
void BlokirajPolje(Tabla &polja, int x, int y)
{
    int vel(polja.size());
    if(x<0 || y<0 || x>=vel || y>=vel) {
         string s("Polje () ne postoji");
        string a("0");
        a=std::to_string(x)+","+std::to_string(y);
        s.insert(7,a);
        throw std::domain_error (s);
    }
    if(polja[x][y]==Polje::Prazno)
        polja[x][y]=Polje::BlokiranoPrazno;
    else if(polja[x][y]==Polje::Posjeceno)
        polja[x][y]=Polje::BlokiranoPosjeceno;
    else if(polja[x][y]==Polje::Mina)
        polja[x][y]=Polje::BlokiranoMina;

}
void DeblokirajPolje(Tabla &polja, int x, int y)
{
    int vel(polja.size());
    if(x<0 || y<0 || x>=vel || y>=vel) {
        string s("Polje () ne postoji");
        string a("0");
        a=std::to_string(x)+","+std::to_string(y);
        s.insert(7,a);
        throw std::domain_error (s);
    }
    if(polja[x][y]==Polje::BlokiranoPrazno)
        polja[x][y]=Polje::Prazno;
    else if(polja[x][y]==Polje::BlokiranoPosjeceno)
        polja[x][y]=Polje::Posjeceno;
    else if(polja[x][y]==Polje::BlokiranoMina)
        polja[x][y]=Polje::Mina;

}
Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer)
{
    int vel(polja.size());
    if(smjer==Smjerovi::GoreLijevo) {
        if(x-1<0 || y-1<0 || x-1>=vel || y-1>=vel) throw std::out_of_range ("Izlazak van igrace table");
        if(polja[x-1][y-1]==Polje::BlokiranoPosjeceno || polja[x-1][y-1]==Polje::BlokiranoPrazno || polja[x-1][y-1]==Polje::BlokiranoMina)
            throw std::logic_error ("Blokirano polje");
        polja[x][y]=Polje::Posjeceno;
        x=x-1;
        y=y-1;
    } else if(smjer==Smjerovi::Gore) {
        if(x-1<0 || y<0  || x-1>=vel) throw std::out_of_range ("Izlazak van igrace table");
        if(polja[x-1][y]==Polje::BlokiranoPosjeceno || polja[x-1][y]==Polje::BlokiranoPrazno || polja[x-1][y]==Polje::BlokiranoMina)
            throw std::logic_error ("Blokirano polje");
        polja[x][y]=Polje::Posjeceno;
        x=x-1;
    } else if(smjer==Smjerovi::GoreDesno) {
        if(x-1<0 || y+1<0 || x-1>=vel || y+1>=vel) throw std::out_of_range ("Izlazak van igrace table");
        if(polja[x-1][y+1]==Polje::BlokiranoPosjeceno || polja[x-1][y+1]==Polje::BlokiranoPrazno || polja[x-1][y+1]==Polje::BlokiranoMina)
            throw std::logic_error ("Blokirano polje");
        polja[x][y]=Polje::Posjeceno;
        x=x-1;
        y=y+1;
    } else if(smjer==Smjerovi::Desno) {
        if(x<0 || y+1<0 || y+1>=vel) throw std::out_of_range ("Izlazak van igrace table");
        if(polja[x][y+1]==Polje::BlokiranoPosjeceno || polja[x][y+1]==Polje::BlokiranoPrazno || polja[x][y+1]==Polje::BlokiranoMina)
            throw std::logic_error ("Blokirano polje");
        polja[x][y]=Polje::Posjeceno;
        y=y+1;

    } else if(smjer==Smjerovi::Lijevo) {
        if(x<0 || y-1<0 || y-1>=vel) throw std::out_of_range ("Izlazak van igrace table");
        if(polja[x][y-1]==Polje::BlokiranoPosjeceno || polja[x][y-1]==Polje::BlokiranoPrazno || polja[x][y-1]==Polje::BlokiranoMina)
            throw std::logic_error ("Blokirano polje");
        polja[x][y]=Polje::Posjeceno;
        y=y-1;
    } else if(smjer==Smjerovi::DoljeLijevo) {
        if(x+1<0 || y-1<0 || x+1>=vel || y-1>=vel) throw std::out_of_range ("Izlazak van igrace table");
        if(polja[x+1][y-1]==Polje::BlokiranoPosjeceno || polja[x+1][y-1]==Polje::BlokiranoPrazno || polja[x+1][y-1]==Polje::BlokiranoMina)
            throw std::logic_error ("Blokirano polje");
        polja[x][y]=Polje::Posjeceno;
        x=x+1;
        y=y-1;
    } else if(smjer==Smjerovi::Dolje) {
        if(x+1<0 || y<0 || x+1>=vel) throw std::out_of_range ("Izlazak van igrace table");
        if(polja[x+1][y]==Polje::BlokiranoPosjeceno || polja[x+1][y]==Polje::BlokiranoPrazno || polja[x+1][y]==Polje::BlokiranoMina)
            throw std::logic_error ("Blokirano polje");
        polja[x][y]=Polje::Posjeceno;
        x=x+1;
    } else if(smjer==Smjerovi::DoljeDesno) {
        if(x+1<0 || y+1<0 || x+1>=vel || y+1>=vel) throw std::out_of_range ("Izlazak van igrace table");
        if(polja[x+1][y+1]==Polje::BlokiranoPosjeceno || polja[x+1][y+1]==Polje::BlokiranoPrazno || polja[x+1][y+1]==Polje::BlokiranoMina)
            throw std::logic_error ("Blokirano polje");
        polja[x][y]=Polje::Posjeceno;
        x+=1;
        y+=1;

    }
    if(polja[x][y]==Polje::Mina) {

        for(int i=0; i<vel; i++)
            for(int j=0; j<vel; j++)
                polja[i][j]=Polje::Prazno;
        return Status::KrajPoraz;
    }
    bool posjet=true;
    for(int i=0; i<vel; i++)
        for(int j=0; j<vel; j++)
            if(polja[i][j]!= Polje::Posjeceno && polja[i][j]!=Polje::Mina)
                posjet=false;
    if(posjet)
        return Status::KrajPobjeda;
    return Status::NijeKraj;
}
Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y)
{
    int vel(polja.size());

    if(novi_x<0 || novi_y<0 || novi_x>=vel || novi_y>=vel) throw std::out_of_range ("Izlazak van igrace table");
    if(polja[novi_x][novi_y]==Polje::BlokiranoPosjeceno || polja[novi_x][novi_y]==Polje::BlokiranoPrazno || polja[novi_x][novi_y]==Polje::BlokiranoMina)
        throw std::logic_error ("Blokirano polje");
    polja[x][y]=Polje::Posjeceno;
    x=novi_x;
    y=novi_y;
    if(polja[x][y]==Polje::Mina) {
        for(int i=0; i<vel; i++)
            for(int j=0; j<vel; j++)
                polja[i][j]=Polje::Prazno;
        return Status::KrajPoraz;
    }
    bool posjet=true;
    for(int i=0; i<vel; i++)
        for(int j=0; j<vel; j++)
            if(polja[i][j]!= Polje::Posjeceno && polja[i][j]!=Polje::Mina)
                posjet=false;
    if(posjet)
        return Status::KrajPobjeda;
    return Status::NijeKraj;
}

bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y,KodoviGresaka &greska)
{
    vector<string> KomKretanja {"P1"};
    vector<string> KomPozicije {"P>","B","D"};
    vector<string> KomBezParametra {"PO","Z","K"};
    vector<string> Pravac {"GL","G","GD","D","DoD","Do","DoL","L"};
    vector<string> PraviPravac {"GoreLijevo","Gore","GoreDesno","Desno","DoljeDesno","Dolje","DoljeLijevo","Lijevo"};
    string s,k,p;
    cin.clear();

    std::getline(std::cin, s);
    int i {};
    bool kretanja=false, pozicije=false, bez=false, pravac=false;
    while(s[i]==' ' && i<s.size())
        i++;
    while(i<s.size()) {
        k.push_back(s[i]);
        if(k==KomKretanja[0])
            kretanja=true;
        for(int j=0; j<KomPozicije.size(); j++)
            if(k==KomPozicije[j])
                pozicije=true;

        for(int j=0; j<KomBezParametra.size(); j++)
            if(k==KomBezParametra[j])
                bez=true;

        if(kretanja) {
            komanda=Komande::PomjeriJednoMjesto;
            i++;
            while(s[i]==' ' && i<s.size())
                i++;
            if(i==s.size()){
                greska=KodoviGresaka::NedostajeParametar;
                return false;
            }
            if(s[i]<'A' || s[i]>'Z'){
                greska=KodoviGresaka::NeispravanParametar;
                return false;
            }
            while(i<s.size()) {
                p.push_back(s[i]);
                for(int j=0; j<Pravac.size(); j++)
                    if(Pravac[j]==p) {
                        pravac=true;
                        break;
                    } 

                i++;
            }
            if(p.size()==0) {
                greska=KodoviGresaka::NedostajeParametar;
                return false;
            } else if(!pravac) {
                greska=KodoviGresaka::NeispravanParametar;
                return false;
            } else {
                int j;
                for(j=0; j<Pravac.size(); j++)
                    if(Pravac[j]==p) {
                        pravac=true;
                        break;
                    }
            while(s[i]==' ' && i<s.size())
                i++;
            if(i<s.size()){
                greska=KodoviGresaka::NeispravanParametar;
                return false;
            }
                smjer=static_cast<Smjerovi>(j);
            }
        }

        if(pozicije) {
            if(k=="B")
                komanda=static_cast<Komande>(2);
            else if(k=="D")
                komanda=static_cast<Komande>(3);
            else     komanda=static_cast<Komande>(1);

            i++;
        
            while(s[i]==' ' && i<s.size())
                i++;
            if(i==s.size()){
                greska=KodoviGresaka::NedostajeParametar;
                return false;
            }
            char *k;
            k=&s[i];
            if(!(s[i]>='0' && s[i]<='9')) {
                greska=KodoviGresaka::NeispravanParametar;
                return false;
            }
            x=atoi(k);
            while((s[i]>='0' && s[i]<='9') && i<s.size())
                i++;
            while(s[i]==' ' && i<s.size())
                i++;
                
             if(i==s.size()){
                    greska=KodoviGresaka::NeispravanParametar;
                    return false;
                }
            if(!(s[i]>='0' && s[i]<='9')) {
                greska=KodoviGresaka::NeispravanParametar;
                return false;
            }

            k=&s[i];
            y=atoi(k);
            while((s[i]>='0' && s[i]<='9') && i<s.size())
                i++;
            while(s[i]==' ' && i<s.size())
                i++;
            if(i!=s.size()) {
                greska=KodoviGresaka::NeispravanParametar;
                return false;
            }


        }
        if(bez) {
            i++;
            while(s[i]==' ' && i<s.size())
                i++;
            if(i<s.size()) {
                greska=KodoviGresaka::SuvisanParametar;
                return false;
            }
        }
        i++;
    }

    if(bez) {
        if(k=="K")
            komanda=Komande::KreirajIgru;
        else if(k=="Z")
            komanda=Komande::ZavrsiIgru;
        else komanda=Komande::PrikaziOkolinu;
    }
    if(bez==false && pozicije==false && kretanja==false) {

        greska=KodoviGresaka::PogresnaKomanda;
        return false;
    }

    return true;
}
void PrijaviGresku(KodoviGresaka Greska)
{
    if(Greska==KodoviGresaka::PogresnaKomanda)
        cout<<"Nerazumljiva komanda!"<<endl;
    else if(Greska==KodoviGresaka::NedostajeParametar)
        cout<<"Komanda trazi parametar koji nije naveden!"<<endl;
    else if(Greska==KodoviGresaka::NeispravanParametar)
        cout<<"Parametar komande nije ispravan!"<<endl;
    else if(Greska==KodoviGresaka::SuvisanParametar)
        cout<<"Zadan je suvisan parametar nakon komande!"<<endl;

}
bool ispravnost(string s)
{
    int vel=s.size();
    int i=1;
    if(s[0]!='(')
        return false;
    if(!(s[i]>='0' && s[i]<='9'))
        return false;
    while(i<vel && s[i]>='0' && s[i]<='9')
        i++;
    if(s[i]!=',')
        return false;
    i++;
    if(!(s[i]>='0' && s[i]<='9'))
        return false;
    while(i<vel && s[i]>='0' && s[i]<='9')
        i++;
    if(s[i]!=')')
        return false;
    if(i!=vel-1)
        return false;
    return true;
}
void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y,Smjerovi p_smjer = Smjerovi::Gore, int p_x = 0, int p_y = 0)
{

    if(komanda==Komande::KreirajIgru) {
        cout<<"Unesite broj polja: ";
        int n;
        cin>>n;
        vector<vector<int>> V;
        cout<<"Unesite pozicije mina: ";
        string s;
        int i=0;
        cin.ignore(1000,'\n');
        while(s!="." ) {
            i=0;
            cin.clear();

            std::getline(std::cin, s);

            if(s==".")
                break;
            bool format=true;
            format=ispravnost(s);
            if(format) {
                i++;
                int broj=0, suma1=0, suma2=0;
                while(i<s.size() && s[i]>='0' && s[i]<='9') {
                    suma1*=10;
                    broj=s[i]-'0';
                    suma1+=broj;
                    i++;
                }
                i++;
                while(i<s.size() && s[i]>='0' && s[i]<='9') {
                    suma2*=10;
                    broj=s[i]-'0';
                    suma2+=broj;
                    i++;
                }
                if((suma1!=0 || suma2!=0) && suma1>=0 && suma2>=0 && suma1<n && suma2<n) {
                    std::vector<int> M {suma1,suma2};
                    V.push_back(M);
                } else cout<<"Greska, unesite ponovo!"<<endl;
                if(s==".")
                    break;
            }else cout<<"Greska, unesite ponovo!"<<endl;
            
        }
            polja=KreirajIgru(n,V);
        }
    

    if(komanda==Komande::ZavrsiIgru) {
        for(int i=0; i<polja.size(); i++)
            for(int j=0; j<polja.size(); j++)
                polja[i][j]=Polje::Prazno;
        throw std::runtime_error ("Igra zavrsena");
    }
    if(komanda==Komande::PrikaziOkolinu) {
        vector<vector<int>> O(PrikaziOkolinu(polja,x,y));
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++)
                cout<<std::left<<std::setw(2)<<O[i][j];
            cout<<endl;
        }
    } else if(komanda==Komande::PomjeriJednoMjesto) {
        Status s= Idi(polja, x, y,p_smjer);
        if(s==Status::KrajPoraz ) {
            for(int i=0; i<polja.size(); i++) {
                for(int j=0; j<polja.size(); j++)
                    polja[i][j]=Polje::Prazno;
            }
            cout<<"Nagazili ste na minu"<<endl;
            throw std::runtime_error ("Igra zavrsena");
        } else if(s==Status::KrajPobjeda ) {
            cout<<"Bravo, obisli ste sva sigurna polja"<<endl;
            for(int i=0; i<polja.size(); i++)
                for(int j=0; j<polja.size(); j++)
                    polja[i][j]=Polje::Prazno;
            throw std::runtime_error ("Igra zavrsena");
        } else cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")"<<endl;
    } else if(komanda==Komande::PomjeriDalje) {
        Status s= Idi(polja, x, y,p_x,p_y);
        if(s==Status::KrajPoraz ) {
            for(int i=0; i<polja.size(); i++) {
                for(int j=0; j<polja.size(); j++)
                    polja[i][j]=Polje::Prazno;
            }
            cout<<"Nagazili ste na minu"<<endl;
            throw std::runtime_error ("Igra zavrsena");
        } else if(s==Status::KrajPobjeda ) {
            for(int i=0; i<polja.size(); i++)
                for(int j=0; j<polja.size(); j++)
                    polja[i][j]=Polje::Prazno;
            cout<<"Bravo, obisli ste sva sigurna polja"<<endl;
            throw std::runtime_error ("Igra zavrsena");
        } else  cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")"<<endl;
    } else if(komanda==Komande::Blokiraj) {
        BlokirajPolje(polja,p_x,p_y);
    } else if(komanda==Komande::Deblokiraj)
        DeblokirajPolje(polja,p_x,p_y);

}
int main ()
{
    Komande k=Komande::KreirajIgru;
    Smjerovi s=Smjerovi::Gore;
    int x=0,y=0, n_x=0, n_y=0;
    Tabla M;
    bool P;
    KodoviGresaka g=KodoviGresaka::NedostajeParametar;
    
    vector<string> G= {"Nerazumljiva komanda!", "Komanda trazi parametar koji nije naveden!", "Zadan je suvisan parametar nakon komande!", "Parametar komande nije ispravan!"};
    while(k!=Komande::ZavrsiIgru) {
        cout<<"Unesite komandu: ";

        P=UnosKomande(k,s,n_x,n_y,g);

        if(P) {
            if(k==Komande::ZavrsiIgru)
                break;
            try {
                IzvrsiKomandu(k,M,x,y,s,n_x,n_y);
            } catch(std::domain_error e) {
                cout<<e.what()<<endl;
            } catch(std::logic_error e) {
                cout<<e.what()<<endl;
            } catch(std::runtime_error e) {
                cout<<e.what()<<endl;
            }
        } else {
            int s=int(g);
            cout<<G[s]<<endl;
        }


    }
    std::cout <<"Dovidjenja!"<<std::endl;

    return 0;
}