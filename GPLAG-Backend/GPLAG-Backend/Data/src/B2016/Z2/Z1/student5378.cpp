/*B 16/17, Zadaća 2, Zadatak 1
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
	
*/


#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;
enum class Komande {
    PomjeriJednoMjesto, PomjeriDalje, Blokiraj,Deblokiraj,PrikaziOkolinu,
    ZavrsiIgru,KreirajIgru};
    enum class Status{NijeKraj,KrajPoraz,KrajPobjeda};
    enum class Smjerovi{GoreLijevo,Gore,GoreDesno,Desno,DoljeDesno,Dolje,DoljeLijevo,Lijevo};
    enum class KodoviGresaka{PogresnaKomanda,NedostajeParametar,SuvisanParametar,NeispravanParametar};
    enum class Polje{Prazno,Posjeceno,Mina,BlokiranoPrazno,BlokiranoPosjeceno,BlokiranoMina};
    typedef vector<vector<Polje>>Tabla;
    Tabla KreirajTablu (int n){
        return Tabla(n,vector<Polje>(n));
    }
    Tabla KreirajIgru(int n,const vector<vector<int>>&mine){
        for(unsigned int i=0;i<mine.size();i++){
            if(mine[i].size()!=2) throw domain_error("Ilegalan format zadavanja mina");
            else if(mine[i][0]>n-1 ||mine[i][0]<0||mine[i][1]>n-1||mine[i][1]<0) throw domain_error("Ilegalne pozicije mina");
        }
        auto t(KreirajTablu(n));
        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        t[i][j]=Polje(0);
        for(unsigned int i=0;i<mine.size();i++)
        for(int j=0;j<2;j++){
            t[mine[i][0]][mine[i][1]]=Polje(2);
        }
        return t;
    }
    vector<vector<int>>PrikaziOkolinu(const Tabla &polja,int x,int y){
        if(x==0||y==0||(unsigned int)x==polja.size()-1||(unsigned int)y==polja.size()-1)throw domain_error("Polje (x,y) ne postoji");
        vector<vector<int>>okolina;
        int brojac(0);
        int n{int(polja.size())};
        for(int i=-1;i<2;i++){
            vector<int>m;
            for(int j=-1;j<2;j++){
                brojac=0;
                if(x+i>=0 && y+j>=0 && x+i<n && y+j<n){
                    for(int iPojedinacno=-1;iPojedinacno<2;iPojedinacno++){
                        for(int jPojedinacno=-1;jPojedinacno<2;jPojedinacno++){
                            if(iPojedinacno==0 && jPojedinacno==0) continue;
                             if( x+i+iPojedinacno>=0 && y+j+jPojedinacno>=0 && x+i+iPojedinacno<n && y+j+jPojedinacno<n  &&
                           polja[x+i+iPojedinacno][y+j+jPojedinacno]==Polje(2))
                           {
                               brojac++;
                           }
                        }
                    }
                }
                m.push_back(brojac);
            }
            okolina.push_back(m);
            m.clear();
            }
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++)
                cout<<okolina[i][j]<<" ";
                cout<<endl;
            }
            return okolina;
        }
        void BlokirajPolje(Tabla &polja,int x,int y){
            if(x<0 || y<0|| (unsigned int)x>polja.size()-1||(unsigned int)y>polja.size()-1)throw domain_error("Polje (x,y) ne postoji");
            for(int i=0;i<3;i++)
            if(polja[x][y]==Polje(i)) polja[x][y]=Polje(i+3);
    }
    void DeblokirajPolje(Tabla &polja,int x ,int y){
        if(x<0 || y<0 || (unsigned int)x>polja.size()-1||(unsigned int)y>polja.size()-1)throw domain_error ("Polje (x,y) ne postoji");
        for(int i=0;i<3;i++){
            if(polja[x][y]==Polje(i+3)) polja[x][y]=Polje(i);
        }
    }

    Status Idi(Tabla &polja, int &x,int &y, Smjerovi smjer){
        int dimTable{int(polja.size())};
        polja[x][y]=Polje(1);
        Status statusIgre{Status(0)};
        bool mrtviSmo{false},pobjediliSmo{true};
        if(smjer==Smjerovi(0)){
            if((x-y)<0||(y-1)<0 || (x-1)>=dimTable||(y-1)>=dimTable) throw out_of_range("Izlazak van igrace table");
            if(polja[x-1][y-1]>Polje(2))throw logic_error("Blokirano polje");
            x-=1;
            y-=1;
            if(polja[x][y]==Polje(2)) mrtviSmo=true;
        }
        if(smjer==Smjerovi(1)){
            if((x-1)<0||(x-1)>=dimTable) throw out_of_range("Izlazak van igrace table");
            if(polja[x-1][y]>Polje(2)) throw logic_error("Blokirano polje");
            x-=1;
            if(polja[x][y]==Polje(2)) mrtviSmo=true;
        }
        if(smjer==Smjerovi(2)){
            if((x-1)<0 || (y+1)<0 ||(x-1)>=dimTable||(y+1)>=dimTable)throw out_of_range("Izlazak van igrace table");
            if(polja[x-1][y+1]>Polje(2))throw logic_error("Bloirano polje");
            x-=1;
            y+=1;
            if(polja[x][y]==Polje(2)) mrtviSmo=true;
        }
        if(smjer==Smjerovi(3)){
            if((y+1)<0||(y+1)>=dimTable) throw out_of_range("Izlazak van igrace table");
            if(polja[x][y+1]>Polje(2)) throw logic_error("Blokirano polje");
            y+=1;
            if(polja[x][y]==Polje(2))mrtviSmo=true;
        }
        if(smjer==Smjerovi(4)){
            if((x+1)<0||(y+1)<0||(x+1)>=dimTable||(y+1)>=dimTable)throw out_of_range("Izlazak van igrace table");
            if(polja[x+1][y+1]>Polje(2)) throw logic_error("Blokiraj polje");
            x+=1;
            y+=1;
            if(polja[x][y]==Polje(2)) mrtviSmo=true;
        }
        if(smjer==Smjerovi(5)){
            if((x+1)<0||(x+1)>=dimTable) throw out_of_range ("Izlazak van igrace table");
         if( polja[x+1][y]>Polje(2) )  throw logic_error("Blokirano polje");
        x+=1;
        if( polja[x][y]==Polje(2) )    mrtviSmo = true;

        }
        if(smjer==Smjerovi(6)){
            if((x+1)<0 || (y-1)<0 || (x+1)>=dimTable||(y-1)>=dimTable) throw out_of_range ("Izlazak van igrace table");
            if(polja[x+1][y-1]>Polje(2)) throw logic_error("Blokirano polje");
            x+=1;
            y-=1;
            if(polja[x][y]==Polje(2)) mrtviSmo=true;
        }
        if(smjer==Smjerovi(7)){
            if((y-1)<0||(y-1)>=dimTable) throw out_of_range("Izlazak van igrace table");
            if(polja[x][y-1]>Polje(2)) throw logic_error("Blokirano polje");
            y-=1;
            if(polja[x][y]==Polje(2)) mrtviSmo=true;
        }
        if(mrtviSmo){
            for(int i=0;i<dimTable;i++)
            for(int j=0;j<dimTable;j++)
            polja[i][j]=Polje(0);
            statusIgre=Status(1);
            return statusIgre;
        }
        for(int i=0;i<dimTable;i++){
            for(int j=0;j<dimTable;j++){
                if(polja[i][j]!=Polje(1)){
                    pobjediliSmo=false;
                    return statusIgre;
                }
            }
        }
        if(pobjediliSmo){
            statusIgre=Status(2);
            return statusIgre;
        }
        return Status(0);
    }
    Status Idi(Tabla &polja,int&x,int&y,int novi_x,int novi_y)
    {
        
    }
    bool UnosKomande(Komande &komanda,Smjerovi &smjer,int &x,int &y,KodoviGresaka &greska){
        
    }
    void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y,
 Smjerovi p_smjer = Smjerovi::Gore, int p_x = 0, int p_y = 0);

    int main(){
        cout<<"Unesite komandu: ";
        int n;
        cout<<"Unsite broj polja: ";
        cin>>n;
        vector<vector<int>>mine;
        int x,y;
        char znak(')');
        cout<<"Unsite pozicije mina: ";
        while(znak==')'){
            cin>>znak;
            if(znak!='('){
                if(znak=='.') break;
                cin.clear();
                cin.ignore(10000,'\n');
                cout<<"Greska, unesite ponovo!"<<endl;
                znak=')';
                continue;
            }
            cin>>x;
            cin>>znak;
            if(znak!=','||x>=n){
                if(znak=='.')break;
                cin.clear();
                cin.ignore(10000,'\n');
                cout<<"Greska, unesite ponovo!"<<endl;
                znak=')';
                continue;
            }
            cin>>y;
            cin>>znak;
            if(znak==')'&&y<n){
                vector<int>m;
                m.push_back(x);
                m.push_back(y);
                mine.push_back(m);
                continue;
            }
            else 
            {
                if(znak=='.') break;
                cin.clear();
                cin.ignore(10000,'\n');
                cout<<"Greska, unesite ponovo!";
                znak=')';
                continue;
            }
        }
        Tabla tab;
        try{
            tab=KreirajIgru(n,mine);
        }
        catch(domain_error izuzetak){
            cout<<izuzetak.what()<<endl;
        }
        vector<vector<int>>okolina;
        cout<<"Unesite koordinate tacke za trazenje okoline: ";
        cin>>x>>y;
        try{
            okolina=PrikaziOkolinu(tab,x,y);
            BlokirajPolje(tab,x,y);
        }
        catch(domain_error e){
            cout<<e.what()<<endl;
        }
        return 0;
    }
