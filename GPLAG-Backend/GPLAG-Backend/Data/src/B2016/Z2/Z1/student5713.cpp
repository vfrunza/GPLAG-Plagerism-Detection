/*B 16/17, Zadaća 2, Zadatak 1
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
	
*/

#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;




typedef vector<vector<Polje>> Tabla;

enum class Polje {
	Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno,
	BlokiranoMina
};


vector<vector<int>> KreirajIgru(int n, const vector<vector<int>> &mine){
	int red, kolona;
	Tabla matrica (n, vector<int> n (Prazno)); 
	for(int i=0; i<mine.size(); i++){
		for(int j=0; j<mine[i].size(); j++){
		if(mine[i].size()>2) throw std::domain_error ("Ilegalan format zadavanja mina");
		if(mine[i][j]>n) throw std::domain_error ("Ilegalne pozicije mina");
			red=mine[i][0];
			kolona=mine[i][1];
		matrica[red][kolona]=Mina;
		}	
	}
	return matrica;
}



vector<vector<int>> PrikaziOkolinu (const Tabla &polja, int x, int y){
	if(x>polja.size() || x<0 || y>polja.size() || y<0) 
	throw std::domain_error("Polje ("<<x<<","<<y<<") ne postoji");
	
	vector<vector<int>> Matrica (3, vector<int> (3)(0));
	
	int red(-1), kolona(0);
/*	for(int i=0; i<polja.size(); i++){
		for(int j=0; j<polja.size(); j++){
			if(i==x && j==y){*/
				//int c=y-1;
				int brojac(0);
				for(int k=x-1; k<x-1+3; k++){
					red++;
					for(int l=y-1; l<y-1+3; l++){
					/*	if(x-1<0 ) {k++;break;}
						if(y-1<0) {c++;break;}
						if(x+1>=polja.size()) break;
						if(y+1>=polja.size()) break;*/
						
							for(int m=k-1; m<k+2; m++){
								for(int n=l-1; n<l+2; n++){
									if(m<0 || m>polja.size() || n<0 || n>polja.size()) continue;
									if(m==k && n==l) continue;
									if(polja[m][n]==Mina) brojac++;
								}
							}
						
							/*
							if(	polja[k-1][l]==Mina) brojac++;
						    if(	polja[k-1][l-1]==Mina) brojac++;
							if(	polja[k-1][l+1]==Mina) brojac++;
							if(	polja[k][l+1]==Mina) brojac++;
							if(	polja[k][l-1]==Mina) brojac++;
							if(	polja[k+1][l]==Mina) brojac++;
							if(	polja[k+1][l+1]==Mina) brojac++;
							if(	polja[k+1][l-1]==Mina) brojac++;
						*/
				
				}
				Matrica[red][kolona]=brojac;
				brojac=0;
				kolona++;
				if(kolona==3) kolona=0;
				
				
			}
		
	
	return Matrica;
}




void BlokirajPolje(Tabla &polja, int x, int y){
		if(x>polja.size() || x<0 || y>polja.size() || y<0) 
	throw std::domain_error("Polje ("<<x<<","<<y<<") ne postoji");
	if(polja[x][y]==Prazno) polja[x][y]=BlokiranoPrazno;
	else if(polja[x][y]==Posjeceno) polja[x][y]=BlokiranoPosjeceno;
	else if(polja[x][y]==Mina) polja[x][y]=BlokiranoMina;
	
}
/*time to pray :D*/

void DeblokirajPolje(Tabla &polja, int x, int y){
			if(x>polja.size() || x<0 || y>polja.size() || y<0) 
	throw std::domain_error("Polje ("<<x<<","<<y<<") ne postoji");
	
	if(polja[x][y]==BlokiranoPrazno) polja[x][y]=Prazno;
	else if(polja[x][y]==BlokiranoPosjeceno) polja[x][y]=Posjeceno;
	else if(polja[x][y]==BlokiranoMina) polja[x][y]=Mina;
	
}

enum class Smjerovi {
 GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo
};

enum class Status {
 NijeKraj, KrajPoraz, KrajPobjeda
};


Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer){
		if(x>polja.size() || x<0 || y>polja.size() || y<0) 
	throw std::domain_error("Polje ("<<x<<","<<y<<") ne postoji");
	
	Status st_igre=NijeKraj;
	if(smjer==GoreLijevo){
		if(x>0 && y>0) {
			polja[x][y]=Posjeceno;
			x--; y--;
	}
}
   else if(smjer==Gore){
		if(x>0) {
			polja[x][y]=Posjeceno;
			x--;
	}
}

	else if(smjer==GoreDesno){
		if(x>0 && y<polja.size()) {
			polja[x][y]=Posjeceno;
			x--; y++;
	}
}

	else if(smjer==Desno){
		if( y<polja.size()) {
			polja[x][y]=Posjeceno;
			 y++;
	}
}

	else if(smjer==Lijevo){
		if(y>0) {
			polja[x][y]=Posjeceno;
			y--;
	}
}

	else if(smjer==DoljeLijevo){
		if(x<polja.size() && y>0) {
			polja[x][y]=Posjeceno;
			x++; y--;
		
	}
}
	else if(smjer==Dolje){
		if(x<polja.size()) {
			polja[x][y]=Posjeceno;
			x++;
	}
}

	else if(smjer==DoljeDesno){
		if(x<polja.size() && y<polja.size()) {
			polja[x][y]=Posjeceno;
			x++; y++;
	}
}


	if(polja[x][y]==Mina) { 
		st_igre=KrajPoraz;
		for(int i=0; i<polja.size(); i++)
			for(int j=0; j<polja.size(); j++){
				polja[i][j]=Prazno;
			}
	}
			
	else {
		int posjetio_sva_polja(1);
		for(int i=0; i<polja.size(); i++){
			for(int j=0; j<polja.size(); j++){
				if(polja[i][j]==Posjeceno) continue;
				posjetio_sva_polja=0;
				i=polja.size()-1; 
				break;
			}
		}
		if(posjetio_sva_polja==1) st_igre=KrajPobjeda;
		else st_igre=NijeKraj;
	}
		
	
	return st_igre;
}





Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y){
	int Status st_igre=NijeKraj;
		if(x>polja.size() || x<0 || y>polja.size() || y<0) 
	throw std::domain_error("Polje ("<<x<<","<<y<<") ne postoji");
	
		if(novi_x>polja.size() || novi_x<0 || novi_y>polja.size() || novi_y<0) 
	throw std::out_of_range("Izlazak van igrace table");
	
	if(polja[novi_x][novi_y]==BlokiranoPosjeceno ||
	polja[novi_x][novi_y]==BlokiranoPrazno || 
	polja[novi_x][novi_y]==BlokiranoMina)
	throw std::logic_error ("Blokirano polje");
	
	x=novi_x; y=novi_y;
	if(polja[x][y]==Mina) { 
		st_igre=KrajPoraz;
		for(int i=0; i<polja.size(); i++)
			for(int j=0; j<polja.size(); j++){
				polja[i][j]=Prazno;
			}
	}
			
	else {
		int posjetio_sva_polja(1);
		for(int i=0; i<polja.size(); i++){
			for(int j=0; j<polja.size(); j++){
				if(polja[i][j]==Posjeceno) continue;
				posjetio_sva_polja=0;
				i=polja.size()-1; 
				break;
			}
		}
		if(posjetio_sva_polja==1) st_igre=KrajPobjeda;
		else st_igre=NijeKraj;
	}
		
	
	return st_igre;
	
}

enum class KodoviGresaka {
 PogresnaKomanda, NedostajeParmetar, SuvisanParametar, NeispravanParametar
};

enum class Komande {
 PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu,
 ZavrsiIgru, KreirajIgru
};

void PrijaviGresku (KodoviGresaka neki){
	if     (neki==PogresnaKomanda) cout<<"Nerazumljiva komanda!";
	else if(neki==NedostajeParametar) cout<<"Komanda trazi parametar koji nije naveden!";
	else if(neki==NeispravanParametar) cout<<"Parametar komande nije ispravan!";
	else if(neki==SuvisanParametar)cout<<"Zadan je suvisan parametar nakon komande!";
}

bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska){
	cout<<"Unesi komandu:";
	string s;
	komanda=std::getline(std::cin, s);
	for(int i=0; i<s.size(); i++)
	if(s[i]==' ') s.erase(s.begin()+i);
	
	char poc_slovo='&';
	char drugo_slovo='&';
	char a='&', b='&', c='&', d='&';
	for(int i=0; i<s.size(); i++)
	poc_slovo=s[0];
//	if(s[0]=='P') drugo_slovo=s[1];
	if(s.size()>1) drugo_slovo=s[1];
	if(s.size()>2) a=s[2];
	if(s.size()>3)b=s[3];
	if(s.size()>4) c=s[4];
	if(s.size()>5) {d=s[5]; break;}


if(poc_slovo=='P'){
	//if(drugo_slovo!='1' && drugo_slovo!='>') greska=PogresnaKomanda;
	if(drugo_slovo=='1'){
	if((a=='G'){
		if(b=='L' && c=='&') {komanda=PomjeriJednoMjesto; smjer=GoreLijevo;}
		else if(b=='&' && c=='&') {komanda=PomjeriJednoMjesto; smjer=Gore;}
		else if(b=='D' && c=='&') {komanda=PomjeriJednoMjesto; smjer=GoreDesno;}
		else if(c!='&') {greska=SuvisanParametar; return false;}
		else if(b!='L' && b!='D') {greska=NedostajeParmetar; return false;}
	
	}
	else if(a=='D'){
		if(b=='&') {komanda=PomjeriJednoMjesto; smjer=Dolje;}
		else if(b=='o' && c=='D' && d=='&') {komanda=PomjeriJednoMjesto; smjer=DoljeDesno;}
		else if(b=='o' && c=='L' && d=='&') {komanda=PomjeriJednoMjesto; smjer=DoljeLijevo;}
		else if(c!='&') {greska=SuvisanParametar; return false;}
		else if(b!='o' ) {greska=NedostajeParmetar; return false;}
		
	}
	else if(a=='L' && b=='&'){komanda=PomjeriJednoMjesto; smjer=Lijevo;}
	else if(a=='L' && b!='&') {greska=SuvisanParametar; return false;}
	
	else if(a=='D' && b=='&'){komanda=PomjeriJednoMjesto; smjer=Desno;}
	else if((a=='D' || a=='L') && b!='&') {greska=SuvisanParametar; return false;}
	
		
	}
	else if(drugo_slovo='>'){
		if(a>='0' && a<='9' && b>='0' && b<='9' && c=='&') {
			komanda=PomjeriDalje; x=a; y=b;}
			if(c!='&') {greska=SuvisanParametar; return false;}
			else {greska=NedostajeParmetar; return false;}
	}
	
//	else greska=NedostajeParametar;
//	}
}
	else if(poc_slovo=='P' && drugo_slovo=='O' && a=='&'){
		komanda=PrikaziOkolinu; 
	
}
//	else if(poc_slovo=='P' && drugo_slovo=='O' && a!='&') greska=SuvisanParametar;


else if(poc_slovo=='Z' && drugo_slovo=='&') komanda=ZavrsiIgru;
else if(poc_slovo=='K' && drugo_slovo=='&') komanda=KreirajIgru;

else if(poc_slovo=='B'){
	if(drugo_slovo>='0' && drugo_slovo<='9' && a>='0' && a<='9')
	{komanda=Blokiraj; x=drugo_slovo; y=a;}
	
}

else if(poc_slovo=='D'){
	if(drugo_slovo>='0' && drugo_slovo<='9' && a>='0' && a<='9')
	{ komanda=Deblokiraj; x=drugo_slovo; y=a; }
	
}
else {greska=PogresnaKomanda; return false;}
return true;
}



//void IzvrsiKomandu(Komande komanda, Tabla &polja, int x, int &y,
 Smjerovi p_smjer = Smjerovi::Gore, int p_x = 0, int p_y = 0);






int main ()
{
	cout<<"Unesite broj polja:";
	int n;
	cin>>n;
	cout<<"Unesite pozicije mina:";
	vector<vector<int>>mine;
 //odoh spavati ranim aBd :( 
//	KreirajIgru(n, );
	return 0;
}