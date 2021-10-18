/*B 16/17, Zadaća 2, Zadatak 1
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
	
*/
#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>



enum class Polje {
	Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina
};
enum class Smjerovi {
 GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo
};
enum class Status {
 NijeKraj, KrajPoraz, KrajPobjeda
};
enum class KodoviGresaka {
 PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar
};

enum class Komande {
 PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu,
 ZavrsiIgru, KreirajIgru
};


typedef std::vector<std::vector<Polje>> Tabla;

void PrijaviGresku(KodoviGresaka k){
	if(k==KodoviGresaka::PogresnaKomanda) std::cout<<"Nerazumljiva komanda!"<<std::endl;
	if(k==KodoviGresaka::NedostajeParametar) std::cout<<"Komanda trazi parametar koji nije naveden!"<<std::endl;
	if(k==KodoviGresaka::SuvisanParametar) std::cout<<"Zadan je suvisan parametar nakon komande!"<<std::endl;
	if(k==KodoviGresaka::NeispravanParametar) std::cout<<"Parametar komande nije ispravan!";
}

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine){
	for(int i=0; i<mine.size(); i++){
		for(int j=0; j<mine.size(); j++){
			if(mine[i].size()!=mine[j].size() && mine[i].size()!=2) throw std::domain_error("Ilegalan format zadavanja mina");
		}
	}
	for(int i=0; i<mine.size(); i++){
		for(int j=0; j<mine[0].size(); j++){
			if(mine[i][j]>n-1) throw std::domain_error("Ilegalne pozicije mina");
		}
	}
	Tabla t(n, std::vector<Polje>(n));
    for(int i=0; i<n; i++){
    	for(int j=0; j<n; j++){
    		for(int k=0; k<mine.size(); k++){
    			for(int l=0; l<mine[0].size(); l++){
			    if(i==mine[k][0] && j==mine[k][1]) t[i][j]=(Polje::Mina);
    			}}
    	}
    }
	return t;
}

std::vector<std::vector<int>> PrikaziOkolinu(Tabla t, int x, int y){
	std::vector<std::vector<int>>mat(3, std::vector<int>(3));
    if(x>=t.size() || y>=t[0].size()|| x<0 || y<0) { std::string greska="Polje ("+std::to_string(x)+","+std::to_string(y)+") ne postoji";
	throw std::domain_error(greska);}
	int br(0);
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			for(int k=0; k<3; k++){
				for(int l=0; l<3; l++){
			if(t[k+1][l]==Polje::Mina) br++;
			if(t[k][l+1]==Polje::Mina) br++;
			if(t[k+1][l+1]==Polje::Mina) br++;
			if(k!=0 ){
				if(t[k-1][l]==Polje::Mina) br++;
				if(t[k-1][l+1]==Polje::Mina) br++;

			}
			if(l!=0){
				if(t[k][l-1]==Polje::Mina) br++;
				if(t[k+1][l-1]==Polje::Mina) br++;
			}
			if(l!=0 && k!=0){
			if(t[k-1][l-1]==Polje::Mina) br++;

			}
			mat[k][l]=br;
			br=0;
}}
break;
		}
		break;
	}
	return mat;
}

void BlokirajPolje(Tabla &t, int x, int y){
	if(x>=t.size() || y>=t[0].size()|| x<0 || y<0) { std::string greska="Polje ("+std::to_string(x)+","+std::to_string(y)+") ne postoji";
	throw std::domain_error(greska);}
	for(int i=0; i<t.size(); i++){
		for(int j=0; j<t[0].size(); j++){
			if(i==x && j==y && t[i][j]==Polje::Prazno) t[i][j]=Polje::BlokiranoPrazno;
			if(i==x && j==y && t[i][j]==Polje::Posjeceno) t[i][j]=Polje::BlokiranoPosjeceno;
			if(i==x && j==y && t[i][j]==Polje::Mina) t[i][j]=Polje::BlokiranoMina;
		}
	}
}
void DeblokirajPolje(Tabla &t, int x, int y){
    if(x>=t.size() || y>=t[0].size()|| x<0 || y<0) { std::string greska="Polje ("+std::to_string(x)+","+std::to_string(y)+") ne postoji";
	throw std::domain_error(greska);}
	for(int i=0; i<t.size(); i++){
		for(int j=0; j<t[0].size(); j++){
			if(i==x && j==y && t[i][j]==Polje::BlokiranoPrazno) t[i][j]=Polje::Prazno;
			if(i==x && j==y && t[i][j]==Polje::BlokiranoPosjeceno) t[i][j]=Polje::Posjeceno;
			if(i==x && j==y && t[i][j]==Polje::BlokiranoMina) t[i][j]=Polje::Mina;
		}
	}
}

void Idi(Tabla &t, int &x, int &y, Smjerovi s){
	if(x<0 || y<0 || x>=t.size()|| y>=t[0].size()) throw std::out_of_range("Izlazak van igrace table");
	else if(x==0 && y==0 &&(s==Smjerovi::Lijevo || s==Smjerovi::Gore || s==Smjerovi::GoreDesno || s==Smjerovi::GoreLijevo || s==Smjerovi::DoljeLijevo)) throw std::out_of_range("Izlazak van igrace table");
	else if(x==0 && y==t[0].size() &&(s==Smjerovi::Desno || s==Smjerovi::Gore || s==Smjerovi::GoreDesno || s==Smjerovi::GoreLijevo || s==Smjerovi::DoljeDesno)) throw std::out_of_range("Izlazak van igrace table");
   	else if(x==t.size() && y==0 &&(s==Smjerovi::Lijevo || s==Smjerovi::Dolje || s==Smjerovi::DoljeDesno || s==Smjerovi::DoljeLijevo)) throw std::out_of_range("Izlazak van igrace table");
    else if(x==t.size() && y==t[0].size() &&(s==Smjerovi::Desno || s==Smjerovi::Dolje || s==Smjerovi::DoljeDesno || s==Smjerovi::DoljeLijevo)) throw std::out_of_range("Izlazak van igrace table");

	for(int i=0; i<t.size(); i++){
		for(int j=0; j<t[0].size(); j++){
			if(s==Smjerovi::Desno && (t[x][y+1]==Polje::BlokiranoPosjeceno || t[x][y+1]==Polje::BlokiranoPrazno || t[x][y+1]==Polje::BlokiranoMina)) throw std::logic_error("Blokirano polje");
			if(s==Smjerovi::Lijevo && y!=0 &&  (t[x][y-1]==Polje::BlokiranoPosjeceno || t[x][y-1]==Polje::BlokiranoPrazno || t[x][y-1]==Polje::BlokiranoMina)) throw std::logic_error("Blokirano polje");
            if(s==Smjerovi::Gore && x!=0 && (t[x-1][y]==Polje::BlokiranoPosjeceno || t[x-1][y]==Polje::BlokiranoPrazno || t[x-1][y]==Polje::BlokiranoMina)) throw std::logic_error("Blokirano polje");
            if(s==Smjerovi::Dolje &&(t[x+1][y]==Polje::BlokiranoPosjeceno || t[x+1][y]==Polje::BlokiranoPrazno || t[x+1][y]==Polje::BlokiranoMina)) throw std::logic_error("Blokirano polje");
			if(s==Smjerovi::GoreDesno && x!=0 && (t[x-1][y+1]==Polje::BlokiranoPosjeceno || t[x-1][y+1]==Polje::BlokiranoPrazno || t[x-1][y+1]==Polje::BlokiranoMina)) throw std::logic_error("Blokirano polje");
			if(s==Smjerovi::GoreLijevo && x!=0 && y!=0 &&(t[x-1][y-1]==Polje::BlokiranoPosjeceno || t[x-1][y-1]==Polje::BlokiranoPrazno || t[x-1][y-1]==Polje::BlokiranoMina)) throw std::logic_error("Blokirano polje");
			if(s==Smjerovi::DoljeDesno && (t[x+1][y+1]==Polje::BlokiranoPosjeceno || t[x+1][y+1]==Polje::BlokiranoPrazno || t[x+1][y+1]==Polje::BlokiranoMina)) throw std::logic_error("Blokirano polje");
			if(s==Smjerovi::DoljeLijevo && y!=0 &&  (t[x+1][y-1]==Polje::BlokiranoPosjeceno || t[x+1][y-1]==Polje::BlokiranoPrazno || t[x+1][y-1]==Polje::BlokiranoMina)) throw std::logic_error("Blokirano polje");

		}
	}

	int b(x), c(y);
	if(s==Smjerovi::GoreLijevo){ b=x-1; c=y-1;}
	if(s==Smjerovi::Gore) b=x-1; 
	if(s==Smjerovi::GoreDesno){b=x+1; c=y-1;}
	if(s==Smjerovi::Desno){c=y+1;}
	if(s==Smjerovi::DoljeDesno){b=x+1; c=y+1;}
	if(s==Smjerovi::Dolje) b=x+1;
	if(s==Smjerovi::DoljeLijevo){b=x+1; c=y-1;}
	if(s==Smjerovi::Lijevo)c=y-1;
	for(int i=0; i<t.size(); i++){
		for(int j=0; j<t[0].size(); j++){
			t[x][y]=Polje::Posjeceno;
		}
	}
	x=b;
	y=c;
}
Status Idi(Tabla &t, int &x, int &y, int z, int k){
	if(z<0 || k<0 || z>=t.size()|| k>=t[0].size()) throw std::out_of_range("Izlazak van igrace table");
	for(int i=0; i<t.size(); i++){
		for(int j=0; j<t[0].size(); j++){
			if(t[z][k]==Polje::BlokiranoPosjeceno || t[z][k]==Polje::BlokiranoPrazno || t[z][k]==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
		}
	}
x=z;
y=k;
for(int i=0; i<t.size(); i++){
	for(int j=0; j<t[0].size(); j++){
		if(t[x][y]==Polje::Mina){
			for(int i=0; i<t.size(); i++){
				for(int j=0; j<t[0].size(); j++){
					t[i][j]=Polje::Prazno;
				}
			}
			return Status::KrajPoraz;
		}
		else if(t[x][y]!=Polje::Mina){
			int nemapraznih(0);
			for(int i=0; i<t.size(); i++){
				for(int j=0; j<t[0].size(); j++){
					if(i!=x && j!=y && t[i][j]!=Polje::Prazno) nemapraznih=1;
					else {nemapraznih=0; break;}
				}
			}
			if(nemapraznih)return Status::KrajPobjeda;
		}
		else return Status::NijeKraj;
	}
}

}
bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska){
    std::string s;
    std::getline(std::cin, s);
    int a(0);
    int c(x), d(y);
	if(s=="P1 GL" || s=="P1 GL " || s==" P1 GL" || s==" P1 GL "){smjer=Smjerovi::GoreLijevo;
	komanda=Komande::PomjeriJednoMjesto;
	}
	if(s=="P1 G" || s=="P1 G " || s==" P1 G" || s==" P1 G "){ smjer=Smjerovi::Gore;
			komanda=Komande::PomjeriJednoMjesto;
	}

	if(s=="P1 GD" || s=="P1 GD " || s==" P1 GD" || s==" P1 GD ") {smjer=Smjerovi::GoreDesno;
			komanda=Komande::PomjeriJednoMjesto;
}
	if(s=="P1 D" || s=="P1 D " || s==" P1 D" || s==" P1 D ") { smjer=Smjerovi::Desno;
				komanda=Komande::PomjeriJednoMjesto;
}

	if(s=="P1 Do" || s=="P1 Do " || s==" P1 Do" || s==" P1 Do "){ smjer=Smjerovi::Dolje;
			komanda=Komande::PomjeriJednoMjesto;
}
	if(s=="P1 DoD" || s=="P1 DoD " || s==" P1 DoD" || s==" P1 DoD ") {smjer=Smjerovi::DoljeDesno;
			komanda=Komande::PomjeriJednoMjesto;
}
	if(s=="P1 DoL" || s=="P1 DoL " || s==" P1 DoL" || s==" P1 DoL "){smjer=Smjerovi::DoljeLijevo;
				komanda=Komande::PomjeriJednoMjesto;
}

	if(s=="P1 L" || s=="P1 L " || s==" P1 L" || s==" P1 L "){ smjer=Smjerovi::Lijevo;
				komanda=Komande::PomjeriJednoMjesto;
}

std::string p, q;

		for(int i=0; i<s.length(); i++){
			if(s[i]=='P' && s[i+1]=='>' ) {komanda=Komande::PomjeriDalje; a=1;}

            if(s[i]>='0' && s[i]<='9'){ 
            	x=s[i]-'0'; 
            	for(int j=i+1; j<s.length(); j++){
            		if(s[j]>='0' && s[j]<='9') {y=s[j]-'0'; break;}
            		
            	} 
            	break;
            }
		}
if(a!=1) greska=KodoviGresaka::PogresnaKomanda;


	for(int i=0; i<s.length(); i++){
			if(s[i]=='B'){ komanda=Komande::Blokiraj; a=1;}
            if(s[i]>='0' && s[i]<='9'){ 
            	x=s[i]-'0'; 
            	for(int j=i+1; j<s.length(); j++){
            		if(s[j]>='0' && s[j]<='9') {y=s[j]-'0'; break;}
            		
            	} 
            	break;
            }
		}
		if(a!=1) greska=KodoviGresaka::PogresnaKomanda; 


	for(int i=0; i<s.length(); i++){
			if(s[i]=='D') {komanda=Komande::Deblokiraj; a=1;}
            if(s[i]>='0' && s[i]<='9'){ 
            	x=s[i]-'0';
            	for(int j=i+1; j<s.length(); j++){
            		if(s[j]>='0' && s[j]<='9') {
            			y=s[j]-'0'; 
            			break;}}
            			break;}


		}
		if(a!=1) greska=KodoviGresaka::PogresnaKomanda; 

		
	for(int i=0; i<s.length(); i++){
			if(s[i]=='Z') {komanda=Komande::ZavrsiIgru; a=1;}
            else if(!( s[i]==' ')){ greska=KodoviGresaka::NeispravanParametar; }
		}		
	if(a!=1) greska=KodoviGresaka::PogresnaKomanda; 


    for(int i=0; i<s.length(); i++){
			if(s[i]=='K') {komanda=Komande::KreirajIgru; a=1;}
            else if(!( s[i]==' ')){ greska=KodoviGresaka::SuvisanParametar; }
		}		
		if(a!=1) greska=KodoviGresaka::PogresnaKomanda; 

	
    for(int i=0; i<s.length(); i++){
			if(s[i]=='P' && s[i+1]=='O') {komanda=Komande::PrikaziOkolinu; a=1;}
            if(!( s[i]==' ')){greska=KodoviGresaka::SuvisanParametar;}

		}	
		if(a!=1) greska=KodoviGresaka::PogresnaKomanda; 
      
		if(s==" P1" || s=="P1" || s=="P1 " || s==" P1 " || s=="P>" || s==" P>" || s==" P> " || s=="P> " || s=="B" || s==" B" || s==" B "|| s=="B " || s=="D" || s==" D" || s==" D "|| s=="D ") greska=KodoviGresaka::NedostajeParametar;
//if((s=="P1"+p + q) && p!="Do" && p!="G" && p!="GD" && p!="GL" && p!="DoD" && p!="DoL" && p!="D" && p!="L" && q!=" "){ a=1; greska=KodoviGresaka::NeispravanParametar;}
      if(s=="P1 G" || s=="P1 G " || s==" P1 G" || s==" P1 G "||s=="P1 GL" || s=="P1 GL " || s==" P1 GL" || s==" P1 GL "||s=="P1 GD" || s=="P1 GD " || s==" P1 GD" || s==" P1 GD "||s=="P1 D" || s=="P1 D " || s==" P1 D" || s==" P1 D "){
      	x=c;
      	y=d;
      }
      if(s=="P1 Do" || s=="P1 Do " || s==" P1 Do" || s==" P1 Do "||s=="P1 DoD" || s=="P1 DoD " || s==" P1 DoD" || s==" P1 DoD "||s=="P1 DoL" || s=="P1 DoL " || s==" P1 DoL" || s==" P1 DoL "||s=="P1 L" || s=="P1 L " || s==" P1 L" || s==" P1 L "){
      	x=c;
      	y=d;
      }
		if(greska!=KodoviGresaka::SuvisanParametar && greska!=KodoviGresaka::NedostajeParametar && greska!=KodoviGresaka::NeispravanParametar) return 1;
		return 0;
}

/*void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer = Smjerovi::Gore, int p_x = 0, int p_y = 0){
	if(komanda==Komande::PomjeriJednoMjesto)
	if(komanda==Komande::PomjeriDalje)
	if(komanda==Komande::Blokiraj) BlokirajPolje(polja, x, y);
	if(komanda==Komande::Deblokiraj) DeblokirajPolje(polja, x, y);
	if(komanda==Komande::PrikaziOkolinu)
	if(komanda==Komande::KreirajIgru) KreirajIgru()
	if(komanda==Komande::ZavrsiIgru)
}*/


int main ()
{
 
 return 0;
}