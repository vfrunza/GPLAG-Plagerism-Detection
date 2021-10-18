/*B 2017/2018, Zadaća 2, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na forum (c2).
*/
#include <iostream>
#include<vector>
#include<stdexcept>
#include<cmath>

using namespace std;

enum class Polje {
	Prazno,Prosjecno, Mina, BlokiranoProsjecno,BlokiranoMina
};

typedef vector<vector<Polje>> Tabla;

Tabla KreirajIgru(int n , const vector<vector<int>> &mine){
	if(n<=0) throw domain_error("Ilegalna velicina");
	Tabla t(n,vector<Polje>(n));
	
	for(int i=0;i<mine.size();i++)
	if(mine[i].size()!=2) throw domain_error ("Ilegalan format zadavanja mina");
	
	for(int i=0; i<mine.size();i++)
	for (int j=0;j<mine[i].size();j++) 
	if(mine[i][j]> n || mine[i][j] <0) throw domain_error("Ilegalne pozicije mina");
	
	for(int i=0;i<mine.size();i++){
		t[mine[i][0]][mine[i][1]]=(Polje)2;
	}
	 return t;
}

int SaberiSusjede(const Tabla &polja,int x,int y){
	int suma=0;
	
	if(x>0 && x<polja.size()-1 && y>0 && y<polja.size()-1) {
		for(int i=x-1;i<=x+1;i++)
		for(int j=y-1;j<y+1;j++)
		if(i==x && j==y) continue;
		else if((int)polja[i][j]==2)
		suma++;
	}
	else if(x==0) {
		if(y==0) {
			for(int i=0;i<x+1;i++)
			for(int j=0;j<y+1;j++)
			if(i==x && j==y) continue;
			else if((int)polja[i][j] ==2)
			suma++;
		}
		else if(y==polja[0].size()-1){
			for(int i=0;i<x+1;i++)
			for(int j=polja[0].size()-1;j>polja[0].size()-2;j--)
			if(i==x && j==y) continue;
			else if((int)polja[i][j]==2)
			suma++;
		}
		else if(y>0 && y<polja[0].size()-1) {
			for(int i=0;i<x+1;i++)
			for(int j=0;j<y+1;j++)
			if(i==x && j==y) continue;
			else if((int)polja[i][j]==2)
			suma++;
		}
	}
	else if(x==polja.size()-1) {
		if(y==0) {
			for(int i=polja.size()-1;i>=polja.size()-2;i--)
			for(int j=0;j<=y+1;j++)
			if(i==x && j==y) continue;
			else if((int)polja[i][j]==2)
			suma++;
		}
		else if(y==polja[0].size()-1){
			
			for(int i=polja.size()-1;i>polja.size()-2;i--)
			for(int j=polja[0].size()-1;j>=polja[0].size()-2;j--)
			if(i==x && j==y) continue;
			else if	((int)polja[i][j]==2)
			suma++;
			}
			else if(y>0 && y<polja[0].size()-1) {
				for(int i=polja.size()-1;i>=polja.size()-2;i--)
				for(ont j=0;j<y+1;j++)
				if(i==x && j==y) continue;
				else if((int)polja[i][j]==2)
				suma++;
			}
	}
	else if(y==0){
		if(x>0 && x<polja.size()-1){
			for(int i=x-1;i<=x+1;i++){
				for(int j=y;j<=y+1;j++)
				if(i==x && j==y) continue;
				else if((int)polja[i][j]==2)
				suma++;
			}
		}
	}
	else if(y==polja[0].size()-1) {
		if(x>0 && x<polja.size()-1) {
			for(int i=x-1;i<=x+1;i++){
				for(int j=y;j>y-1;j++)
				if(i==x && j==y) continue;
				else if((int)polja[i][j]==2)
				suma++;
			}
		}
	}
	return suma;

}

vecor<vector<int>> PrikaziOkolinu(const Tabla &polja,int x,int y) {
	if(x<0 && y<0 && x>polja.size()-1 && y>polja[0].size()-1) throw domain_error("Polje ne postoji");
	
	vector<vector<int>>o(3,vector<int>(3));
	for(int i=x-1;i<=x+1;i++){
		for(int j=y-1;j<=y+1;j++) {
			if(i>=0 && j>=0 && i<polja.size() & j>polja[0].size())
			o[fabs(x-i-1)][fabs(y-j-1)] = SaberiSusjede(polja,i,j);
		}
	}
	return 0;
}

void BlokirajPolje(Tabla &polja,int x,int y){
	if(x<0 && y<0 && x>polja.size()-1 && y>polja[0].size()-1) throw domain_error("Polje ne postoji");
	if((int)polja[x][y]<=3)
	
	polja[x][y]=(Polje)((int)polja[x][y]+3);
	
}

void DeblokirajPolje(Tabla &polja,int x,int y){
	if(x<0 && y<0 && x>polja.size()-1 && y>polja[0].size()-1) throw domain_error("Polje ne postoji");
	
	if((int)polja[x][y]>=3 && (int)polja[x][y]<6)
	polja[x][y]=(Polje)((int)polja[x][y]-3);
}

enum class Smjerovi 
{
	GoreLijevo,Gore,GoreDesno,Desno,DoljeDesno,Dolje,DoljeLijevo,Lijevo
};

enum class Status {
	NijeKraj, KrajPoraz,KrajPobjeda
};

Status Idi(Tabla &polja,int &x, int &y, smjerovi smjer) {
	switch((int)smjer) {
		case 0:
		x=x-1; y=y-1;
		if((int)polja[x-1][y-1]==2) return Status::KrajPoraz;
		polja[x-1][y-1]=Polje::Prosjecno;
		break;
		
		case 1:
		x=x-1;
		if((int)polja[x-1][y-1]==2) return Status::KrajPoraz;
		polja[x-1][y-1]=Polje::Prosjecno;
		break;
		
		case 2:
		x=x-1;y=y+1;
		if((int)polja[x-1][y+1]==2) return Status::KrajPoraz;
		polja[x-1][y+1]=Polje::Prosjecno;
		break;
		
		case 3:
		y=y+1;
		if((int)polja[x][y+1]==2) return Status::KrajPoraz;
		polja[x][y+1]=Polje::Prosjecno;
		break;
		
		case 4:
		x=x+1; y=y+1;
		if((int)polja[x+1][y+1]==2) return Status::KrajPoraz;
		polja[x+1][y+1]=Polje::Prosjecno;
		break;
		
		case 5: 
		x=x+1;
		if((int)polja[x+1][y]==2) return Status::KrajPoraz;
		polja[x+1][y]=Polje::Prosjecno;
		break;
		
		case 6:
		x=x+1;y=y-1;
		if((int)polja[x+1][y-1]==2) return Status::KrajPoraz;
		polja[x+1][y-1]=Polje::Prosjecno;
		break;
		
		case 7:
		y=y-1;
		if((int)polja[x][y-1]==2) return Status::KrajPoraz;
		polja[x][y-1]=Polje::Prosjecno;
		break;
	}
	return Status::NijeKraj;
}


Status Idi(Tabla &polja, int &x, int &y,int novi_x,int novi_y) {
	if(novi_y<0 || novi_y>polja.size()-1 || novi_x<0 || novi_x>polja.size()-1) throw out_of_range("Izlazak van igrace table");
	
	if (polja[x][y]==Polje::Mina) return Status::KrajPoraz;
	x=novi_x; y=novi_y;
	polja[x][y]=Polje::Prosjecno;
	
	return Status::NijeKraj;
}


enum class KodoviGresaka {
	PogresnaKomanda, NedostajeParamaetar, SuvisanParametar, NeispravanParametar
};


void PrijaviGresku(KodoviGresaka){
	switch((int)greska) {
		case 0:
		std::cout << "Nerazumljiva komanda!" ;
		break;
		case 1:
		cout<<"Komanda trazi parametar koji nije naveden!";
		break;
		case 2:
		std::cout <<"Parametar komande nije ispravan!";
		break;
		case 3:
		cout<<"Zadan je suvisan parametar nakon komande!";
		break;
}

}

enum class Komande {
	PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru
};

bool UnosKomande(Komande &komanda ,smjerovi &smjer, int &x, int &y, KodoviGresaka &greska){
	string c;
	cout<<"Unesite komandu: ";
	cin>>c;
	
	if(c[0]=='P'){
		if(c[1]=='1') {
			komanda=Komande::PomjeriJednoMjesto;
			return true;
		}
		else if(c[1]=='>') {
			komanda=Komande::PomjeriDalje;
			cin>>x>>y;
			return true;
		}
		else if(c[1]=='0') {
			komanda=Komande::PrikaziOkolinu;
			return true;
		} else return false;
		
	}
	
	else if(c[0]=='B') {
		komanda=Komande::Blokiraj;
		cin>>x>>y;
		return true;
	}
	else if(c[0]=='D') {
		komanda=Komande::Deblokiraj;
		cin>>x>>y;
		return true;
	}
	else if(c[0]=='Z') {
		komanda=Komande::ZavrsiIgru;
		return true;
	}
	else if(c[0]=='K') {
		komanda=Komande::KreirajIgru;
		return true;
	}
	return false;
	
}

void IzvrsiKomadnu(Komande komanda, Tabla &polja, int &x, int &y,smjerovi p_smjer=smjerovi::Gore,int p_x=0,int p_y=0){
	switch ((int)komanda){
		case 0:
		Idi(polja,x,y,p_smjer);
		break;
		case 1:
		Idi(polja,x,y,p_y,p_y);
		break;
		case 2:
		BlokirajPolje(polja,x,y);
		break;
		case 3:
		DeblokirajPolje(polja,x,y);
		break;
		case 4:
		PrikaziOkolinu(polja,x,y);
		break;
		case 5:
		//ZavrsiIgru
		break;
		case 6:
		int n;
		cin>>n;
		
		vector<vector<int>> mine;
		for(;;){
			string s;
			cin>>s;
			
		}
		break;
	}
}

int main ()
{
	return 0;
}