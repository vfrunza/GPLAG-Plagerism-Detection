#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;
typedef vector<vector<int>> Matrix;

enum class Polje
{
    Prazno,Posjeceno,Mina,BlokiranoPrazno,BlokiranoPosjeceno,BlokiranoMina
};
enum class Smjerovi
{
    GoreLijevo,Gore,GoreDesno,Desno,DoljeDesno,Dolje,DoljeLijevo,Lijevo
};
enum class Status
{
    NijeKraj,KrajPoraz,KrajPobjeda
};
enum class KodoviGresaka
{
    PogresnaKomanda,NedostajeParametar,SuvisanParametar,NeispravanParametar
};
enum class Komande
{
    PomjeriJednoMjesto,PomjeriDalje,Blokiraj,Deblokiraj,PrikaziOkolinu,ZavrsiIgru,KreirajIgru
};

typedef std::vector<std::vector<Polje>> Tabla;

Tabla KreirajIgru(int n,const std::vector<std::vector<int>> &mine)
{
    if(n<=0)throw domain_error("Ilegalna velicina");
    int velicinaMat(mine[0].size());
    for(int i(0); i<mine.size(); i++)
        if(mine[i].size()!=velicinaMat)throw domain_error("Ilegalan format zadavanja mina");
    for(int x(0); x<mine.size(); x++) {
        for(int y(0); y<2; y++)
            if(mine[x][y]>mine.size() || mine[x][y]<0)throw domain_error("Ilegalne pozicije mina");

    }
    Tabla Ploca(n,vector<Polje> (n));
    Polje M,P;
    M=Polje(2);
    P=Polje(0);
    for(int i(0); i<n; i++)
        for(int j(0); j<n; j++)
            for(int k(0); k<mine.size(); k++)
                Ploca[i][j]=P;
    for(int i(0); i<n; i++)
        for(int j(0); j<n; j++)
            for(int k(0); k<mine.size(); k++)
                if(i==mine[k][0] && j==mine[k][1])Ploca[i][j]=M;
    return Ploca;
}

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja,int x,int y)
{
    if((x>=polja.size() || x<0) && (y>=polja.size() || y<0))throw domain_error("Polje (x,y) ne postoji");
    Matrix mat(3,vector<int> (3));
    for(int i(0); i<polja.size(); i++)
        for(int j(0); j<polja.size(); j++)

            if(x==i && y==j) {
                int var1(0),var2(0),m(i-1),n(j-1);
                int limit1(m+3),limit2(n+3);
                for(int m(i-1); m<limit1; m++) {
                    for(int n(j-1); n<limit2; n++) {

                        int counter(0),limit3(m-1+3),limit4(n-1+3);

                        for(int okolina1(m-1); okolina1<limit3; okolina1++)
                            for(int okolina2(n-1); okolina2<limit4; okolina2++)
                                if(okolina1<0 || okolina2<0 || okolina1>polja.size() || okolina2>polja.size() || (okolina1==m && okolina2==n))continue;
                                else if(polja[okolina1][okolina2]==Polje(2))counter++;

                        mat[var1][var2]=counter;
                        var2++;
                    }
                    var1++;
                    var2=0;
                }
            }
    return mat;
}

void BlokirajPolje(Tabla &polja,int x,int y)
{
    if(x<0 || y<0 || x>=polja.size() || y>=polja.size())throw domain_error("Polje (x,y) ne postoji");
    for(int i(0); i<polja.size(); i++)
        for(int j(0); j<polja.size(); j++)
            if(i==x && j==y) {
                if(polja[i][j]==Polje(0))polja[i][j]=Polje(3);
                else if(polja[i][j]==Polje(1))polja[i][j]=Polje(4);
                else if(polja[i][j]==Polje(2))polja[i][j]=Polje(5);
            }
}

void DeblokirajPolje(Tabla &polja,int x,int y)
{
    if(x<0 || y<0 || x>=polja.size() || y>=polja.size())throw domain_error("Polje (x,y) ne postoji");
    for(int i(0); i<polja.size(); i++)
        for(int j(0); j<polja.size(); j++)
            if(i==x && j==y) {
                if(polja[i][j]==Polje(3))polja[i][j]=Polje(0);
                else if(polja[i][j]==Polje(4))polja[i][j]=Polje(1);
                else if(polja[i][j]==Polje(5))polja[i][j]=Polje(2);
            }
}

Status Idi(Tabla &polja,int &x,int &y,Smjerovi smjer)
{   //treba li se pobrinuti ovdje za koordinate
    polja[x][y]=Polje(1);
    for(int i(0); i<polja.size(); i++)
        for(int j(0); j<polja.size(); j++)
            if(i==x && y==j) {
                if(smjer==Smjerovi(0)) {
                    x-=1;
                    y-=1;
                    if(polja[x][y]==Polje::Prazno)return Status::NijeKraj;
                    else if(polja[x][y]==Polje::Mina)return Status::KrajPoraz;
                } else if(smjer==Smjerovi(1)) {
                    x-=1;
                    if(polja[x][y]==Polje::Prazno)return Status::NijeKraj;
                    else if(polja[x][y]==Polje::Mina)return Status::KrajPoraz;
                } else if(smjer==Smjerovi(2)) {
                    x-=1;
                    y+=1;
                    if(polja[x][y]==Polje::Prazno)return Status::NijeKraj;
                    else if(polja[x][y]==Polje::Mina)return Status::KrajPoraz;
                } else if(smjer==Smjerovi(3)) {
                    y+=1;
                    if(polja[x][y]==Polje::Prazno)return Status::NijeKraj;
                    else if(polja[x][y]==Polje::Mina)return Status::KrajPoraz;
                } else if(smjer==Smjerovi(4)) {
                    x+=1;
                    y+=1;
                    if(polja[x][y]==Polje::Prazno)return Status::NijeKraj;
                    else if(polja[x][y]==Polje::Mina)return Status::KrajPoraz;
                } else if(smjer==Smjerovi(5)) {
                    x+=1;
                    if(polja[x][y]==Polje::Prazno)return Status::NijeKraj;
                    else if(polja[x][y]==Polje::Mina)return Status::KrajPoraz;
                } else if(smjer==Smjerovi(6)) {
                    x+=1;
                    y-=1;
                    if(polja[x][y]==Polje::Prazno)return Status::NijeKraj;
                    else if(polja[x][y]==Polje::Mina)return Status::KrajPoraz;
                } else if(smjer==Smjerovi(7)) {
                    y-=1;
                }
            }
}
Status Idi(Tabla &polja,int &x,int &y,int novi_x,int novi_y)
{
   /*  for(int i(0); i<polja.size(); i++)
        for(int j(0); j<polja.size(); j++)
            if(i==novi_x && j==novi_y) {
                if(smjer==Smjerovi(0)) {
                    x-=1;
                    y-=1;
                    if(polja[x][y]==Polje::Prazno)return Status::NijeKraj;
                    else if(polja[x][y]==Polje::Mina)return Status::KrajPoraz;
                } else if(smjer==Smjerovi(1)) {
                    x-=1;
                    if(polja[x][y]==Polje::Prazno)return Status::NijeKraj;
                    else if(polja[x][y]==Polje::Mina)return Status::KrajPoraz;
                } else if(smjer==Smjerovi(2)) {
                    x-=1;
                    y+=1;
                    if(polja[x][y]==Polje::Prazno)return Status::NijeKraj;
                    else if(polja[x][y]==Polje::Mina)return Status::KrajPoraz;
                } else if(smjer==Smjerovi(3)) {
                    y+=1;
                    if(polja[x][y]==Polje::Prazno)return Status::NijeKraj;
                    else if(polja[x][y]==Polje::Mina)return Status::KrajPoraz;
                } else if(smjer==Smjerovi(4)) {
                    x+=1;
                    y+=1;
                    if(polja[x][y]==Polje::Prazno)return Status::NijeKraj;
                    else if(polja[x][y]==Polje::Mina)return Status::KrajPoraz;
                } else if(smjer==Smjerovi(5)) {
                    x+=1;
                    if(polja[x][y]==Polje::Prazno)return Status::NijeKraj;
                    else if(polja[x][y]==Polje::Mina)return Status::KrajPoraz;
                } else if(smjer==Smjerovi(6)) {
                    x+=1;
                    y-=1;
                    if(polja[x][y]==Polje::Prazno)return Status::NijeKraj;
                    else if(polja[x][y]==Polje::Mina)return Status::KrajPoraz;
                } else if(smjer==Smjerovi(7)) {
                    y-=1;
                }
            }*/
}

/*PrijaviGresku(KodoviGresaka kod){
    if(kod==PogresnaKomanda(0))cout<<"Nerazumljiva komanda!";
    if(kod==PogresnaKomanda(1))cout<<"Komanda trazi parametar koji nije naveden!";
    if(kod==PogresnaKomanda(2))cout<<"Zadan je suvisan parametar nakon komande!";
    if(kod==PogresnaKomanda(3))cout<<"Parametar komande nije ispravan!";

}*/

bool UnosKomande(Komande &komanda,Smjerovi &smjer,int &x,int &y,KodoviGresaka &greska)
{

}

int main ()
{

    return 0;
}