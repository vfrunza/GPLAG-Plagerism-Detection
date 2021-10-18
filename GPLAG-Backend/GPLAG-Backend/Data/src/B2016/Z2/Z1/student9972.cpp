#include<iostream>
#include<stdexcept>
#include<vector>
#include<string>
#include<complex>

using namespace std;
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

typedef vector<vector<Polje>> Tabla;
string Pretvori(int a)
{
	string s;
	int br=0,x=a,k=1;
	while(x!=0){br++;x/=10;}
	x=a;
	s.resize(s.size()+br);
	for(int i=0;i<s.size();i++)
	{
		s[i]=(x%10)*k+s[i]+'0';
		x/=10;
		k=10;
	}
	return s;
}
Tabla KreirajIgru(int n, const vector<vector<int>> &mine)
{
	Tabla mat;
	for(int i=0;i<mine.size();i++){
	if(mine[i].size()!=2){throw domain_error("Ilegalan format zadavanja mina");}
	}
	for(int i=0;i<mine.size();i++)
	for(int j=0;j<2;j++)
	if(mine[i][j]>=n)throw domain_error("Ilegalne pozicije mina");
	mat.resize(n);
	for(int i=0;i<n;i++)
	mat[i].resize(n);
	
	
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	mat[i][j]=Polje::Prazno;


	for(int i=0;i<mine.size();i++)
	mat[mine[i][0]][mine[i][1]]=Polje::Mina;
	 
	return mat;	
}
int Racunaj(const Tabla &polja, int a,int b)
{
	int br=0;
	int x=a,y=b;
	if(x==0)x++;
	if(y==0)y++;
	for(int i=x;i<=(a+2)&& (i<=polja.size());i++)
	for(int j=y;(j<=(b+2) &&(j<=polja[0].size()));j++){
	if((i-1==a && j-1==b) && polja[i-1][j-1]==Polje::Mina){continue;}
	if(polja[i-1][j-1]==Polje::Mina ){br++;}

}
	return br;
}
vector<vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y)
{
	vector<vector<int>>mat;
	int br=0;
	string s1=Pretvori(x),s2=Pretvori(y);
	if(x>=polja.size() || y>=polja[0].size()) throw domain_error("Polje (" + s1 +"," + s2 +") ne postoji");
	mat.resize(3);
	for(int i=0;i<mat.size();i++)
	mat[i].resize(3);
	int red=0;
	for(int i=x-1;i<=x+1 &&(i<polja.size());i++){
		int kolona=0;
	for(int j=y-1;j<=y+1&& (y<polja[0].size());j++){
		br=0;
		br=Racunaj(polja,i,j);
		mat[red][kolona]=br;
		kolona++;
		
	}
		
	red++;	
	}
return mat;	
}

void BlokirajPolje(Tabla &polja, int x, int y)
{
	
	string s1=Pretvori(x),s2=Pretvori(y);
	if(x>=polja.size() || y>=polja[0].size()) throw domain_error("Polje (" + s1 +"," + s2 +") ne postoji");
	if(polja[x][y]==Polje::Prazno) polja[x][y]=Polje::BlokiranoPrazno;
	else if(polja[x][y]==Polje::Posjeceno)polja[x][y]=Polje::BlokiranoPosjeceno;
	else if(polja[x][y]==Polje::Mina)polja[x][y]=Polje::BlokiranoMina;
	
}

void DeblokirajPolje(Tabla &polja, int x, int y)
{
	string s1=Pretvori(x),s2=Pretvori(y);
	if(x>=polja.size() || y>=polja[0].size()) throw domain_error("Polje (" + s1 +"," + s2 +") ne postoji");
	
	if(polja[x][y]==Polje::BlokiranoPrazno) polja[x][y]=Polje::Prazno;
	else if(polja[x][y]==Polje::BlokiranoPosjeceno)polja[x][y]=Polje::Posjeceno;
	else if(polja[x][y]==Polje::BlokiranoMina)polja[x][y]=Polje::Mina;
	
}
Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer)
{
	if(y==0 && (smjer==Smjerovi::Lijevo || smjer==Smjerovi::GoreLijevo || smjer==Smjerovi::DoljeLijevo))throw out_of_range("Izlazak van igrace table");
	if(x==0 && (smjer==Smjerovi::Gore || smjer==Smjerovi::GoreLijevo || smjer==Smjerovi::GoreDesno))throw out_of_range("Izlazak van igrace table");
	if(y==polja[0].size()-1 && (smjer==Smjerovi::Desno || smjer==Smjerovi::GoreDesno || smjer==Smjerovi::DoljeDesno))throw out_of_range("Izlazak van igrace table");
	if(x==polja.size()-1 && (smjer==Smjerovi::Dolje || smjer==Smjerovi::DoljeLijevo || smjer==Smjerovi::DoljeDesno))throw out_of_range("Izlazak van igrace table");
	
	if(smjer==Smjerovi::Gore && (polja[x-1][y]==Polje::BlokiranoPosjeceno || polja[x-1][y]==Polje::BlokiranoPrazno || polja[x-1][y]==Polje::BlokiranoMina))throw logic_error("Blokirano polje"); 
	if(smjer==Smjerovi::GoreDesno && (polja[x-1][y+1]==Polje::BlokiranoPosjeceno || polja[x-1][y+1]==Polje::BlokiranoPrazno || polja[x-1][y+1]==Polje::BlokiranoMina))throw logic_error("Blokirano polje"); 
	if(smjer==Smjerovi::GoreLijevo && (polja[x-1][y-1]==Polje::BlokiranoPosjeceno || polja[x-1][y-1]==Polje::BlokiranoPrazno || polja[x-1][y-1]==Polje::BlokiranoMina))throw logic_error("Blokirano polje"); 
	if(smjer==Smjerovi::Dolje && (polja[x+1][y]==Polje::BlokiranoPosjeceno || polja[x+1][y]==Polje::BlokiranoPrazno || polja[x+1][y]==Polje::BlokiranoMina))throw logic_error("Blokirano polje"); 
	if(smjer==Smjerovi::DoljeDesno && (polja[x+1][y+1]==Polje::BlokiranoPosjeceno || polja[x+1][y+1]==Polje::BlokiranoPrazno || polja[x+1][y+1]==Polje::BlokiranoMina))throw logic_error("Blokirano polje"); 
	if(smjer==Smjerovi::DoljeLijevo && (polja[x+1][y-1]==Polje::BlokiranoPosjeceno || polja[x+1][y-1]==Polje::BlokiranoPrazno || polja[x+1][y-1]==Polje::BlokiranoMina))throw logic_error("Blokirano polje"); 
	if(smjer==Smjerovi::Desno && (polja[x][y+1]==Polje::BlokiranoPosjeceno || polja[x][y+1]==Polje::BlokiranoPrazno || polja[x][y+1]==Polje::BlokiranoMina))throw logic_error("Blokirano polje"); 
	if(smjer==Smjerovi::Lijevo && (polja[x][y-1]==Polje::BlokiranoPosjeceno || polja[x+1][y-1]==Polje::BlokiranoPrazno || polja[x][y-1]==Polje::BlokiranoMina))throw logic_error("Blokirano polje"); 

	
	
	if(smjer==Smjerovi::GoreDesno){x--;y++; polja[x+1][y-1]=Polje::Posjeceno;}
	else if(smjer==Smjerovi::GoreLijevo){x--;y--; polja[x+1][y+1]=Polje::Posjeceno;}
	else if(smjer==Smjerovi::Gore){x--; polja[x+1][y]=Polje::Posjeceno;}
	else if(smjer==Smjerovi::Lijevo){y--; polja[x][y+1]=Polje::Posjeceno;}
	else if(smjer==Smjerovi::Desno){y++; polja[x][y-1]=Polje::Posjeceno;}
	else if(smjer==Smjerovi::DoljeLijevo){x++;y--; polja[x-1][y+1]=Polje::Posjeceno;}
	else if(smjer==Smjerovi::DoljeDesno){x++;y++; polja[x-1][y-1]=Polje::Posjeceno;}
	else if(smjer==Smjerovi::Dolje){x++; polja[x-1][y]=Polje::Posjeceno;}
	if(polja[x][y]==Polje::Mina){
	for(int i=0;i<polja.size();i++)
	for(int j=0;j<polja[0].size();j++)
	polja[i][j]=Polje::Prazno;
	return Status::KrajPoraz;
	}
	else{int ima=0;
	for(int i=0;i<polja.size();i++)
	for(int j=0;j<polja[0].size();j++)
	if(polja[i][j]==Polje::Posjeceno)ima=1;
	if(ima==0)return Status::KrajPobjeda;
	}
	return Status::NijeKraj;

}
Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y)
{
	if(novi_x>=polja.size() || novi_y>=polja[0].size()){ throw out_of_range("Izlazak van igrace table"); }
	if(polja[novi_x][novi_y] == Polje::BlokiranoPosjeceno || polja[novi_x][novi_y]==Polje::BlokiranoPrazno || polja[novi_x][novi_y]==Polje::BlokiranoMina) throw logic_error("Blokirano polje");
	x=novi_x; y=novi_y;
	if(polja[x][y]==Polje::Mina){
	for(int i=0;i<polja.size();i++)
	for(int j=0;j<polja[0].size();j++)
	polja[i][j]=Polje::Prazno;
	return Status::KrajPoraz;
	}
	else{int ima=0;
	for(int i=0;i<polja.size();i++)
	for(int j=0;j<polja[0].size();j++)
	if(polja[i][j]==Polje::Posjeceno)ima=1;
	if(ima==0)return Status::KrajPobjeda;
	}
	return Status::NijeKraj;
}
void PrijaviGresku(KodoviGresaka Parametar)
{
	if(Parametar==KodoviGresaka::PogresnaKomanda)cout<<"Nerazumljiva komanda!"<<endl;
	else if(Parametar==KodoviGresaka::NedostajeParametar)cout<<"Komanda trazi parametar koji nije naveden!"<<endl;
	else if(Parametar==KodoviGresaka::NeispravanParametar)cout<<"Parametar komande nije ispravan!"<<endl;
	else if(Parametar==KodoviGresaka::SuvisanParametar)cout<<"Zadan je suvisan parametar nakon komande!"<<endl;
}

int JeLiIsti(string s,vector<string>s1)
{
	int br=-1;
    bool isti;
    
    for(int i=0;i<s1.size();i++){
        isti=true;
        string s2=s1[i];
	for(int j=0;(j<s.size() || j<s2.size());j++)
      if(s[j]!=s2[j]) {isti=false;break;}
      if(isti){br=i;break;}
    }
    return br;
}
string funkcija(string &s)
{
	string s1;
	int pocetak=0,kraj=0;
	for(int i=0;i<s.size();i++){
	if(((toupper(s[i])>='A' && toupper(s[i])<='Z') &&(i==0 || s[i-1]==' ')) || (s[i+1]=='1' || s[i+1]=='>')){pocetak=i;
	while((toupper(s[i])>='A' && toupper(s[i])<='Z') || ((s[i]=='1' || s[i]=='>') && toupper(s[i-1])>='A' && toupper(s[i-1])<='Z'))i++;
	if(s[i]==' ' || i==s.size()){kraj=i;
	s1= s.substr(pocetak,kraj-pocetak);
	s=s.substr(kraj,s.size()-kraj);
            }
        break;}
	}
	return s1;
}
void novi(string &s)
{
    int pocetak=0,kraj=0;
    for(int i=0;i<s.size();i++){
    if((toupper(s[i])>='A' && toupper(s[i])<='Z')&&(i==0 || s[i-1]==' ')){pocetak=i;
            while(toupper(s[i])>='A' && toupper(s[i])<='Z' ){i++;}
    if(s[i]==' ' || i==s.size()){kraj=i;
    s=s.substr(pocetak,kraj-pocetak);
            }
        break;}
    }
}
int pretvorba(string s, int pocetak, int kraj)
{
	int broj=0;
	for(int i=pocetak;i<kraj;i++)
	{
		broj=broj*10 +s[i]-'0';
	}
	return broj;
	
}
void brojevi(string s, int &a, int &b)
{
	int pocetak=0,kraj=0,br=0;
    for(int i=0;i<s.size();i++){
    if((s[i]>='0' && s[i]<='9')&&(i==0 || s[i-1]==' ')){ pocetak=i;
            while(s[i]>='0' && s[i]<='9'){i++;}
    if(s[i]==' ' || i==s.size()){br++;kraj=i;
    	if(br==1)a=pretvorba(s,pocetak,kraj);
    	if(br==2)b=pretvorba(s,pocetak,kraj);
            }
       }
    }	
}

bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y,KodoviGresaka &greska)
{
	int a,b,jedan=0,dva=0;
	string s,s3;
	vector<string> s1{{"GL"},{"GD"},{"G"},{"DoL"},{"DoD"},{"D"},{"Do"},{"L"}};
	vector<string> s2{{"P1"},{"P>"},{"B"},{"D"},{"PO"},{"Z"},{"K"}};
	getline(cin , s);
	s3=funkcija(s);
	brojevi(s,jedan,dva);

	novi(s);
	
	b=JeLiIsti(s3,s2);
	if(s.size()==0 && b>=0 && b<=3){greska=KodoviGresaka::NedostajeParametar; return false;}
	if(b==0){komanda=Komande::PomjeriJednoMjesto;
		a=JeLiIsti(s,s1);
	if(a==0 && jedan==0 && dva==0){smjer=Smjerovi::GoreLijevo; return true;}
	else if(a==1 && jedan==0 && dva==0){smjer=Smjerovi::GoreDesno; return true;}
	else if(a==2 && jedan==0 && dva==0){smjer=Smjerovi::Gore; return true;}
	else if(a==3 && jedan==0 && dva==0){smjer=Smjerovi::DoljeLijevo; return true;}
	else if(a==4 && jedan==0 && dva==0){smjer=Smjerovi::DoljeDesno; return true;}
	else if(a==5 && jedan==0 && dva==0){smjer=Smjerovi::Desno; return true;}
	else if(a==6 && jedan==0 && dva==0){smjer=Smjerovi::Dolje; return true;}
	else if(a==7 && jedan==0 && dva==0){smjer=Smjerovi::Lijevo; return true;}
	else if(jedan>0 ){greska=KodoviGresaka::NeispravanParametar; return false;}
	else if(a==-1 && s.size()!=0) {greska=KodoviGresaka::SuvisanParametar; return false;}
	}
	else if((b>0 && b<=3) &&(jedan==0 || dva==0)){;greska=KodoviGresaka::NeispravanParametar; return false;}
else if(b==1 && s.size()!=0){komanda=Komande::PomjeriDalje;x=jedan;y=dva; return true;}
else if(b==2 && s.size()!=0){komanda=Komande::Blokiraj; x=jedan; y=dva; return true;}
else if(b==3 && s.size()!=0){komanda=Komande::Deblokiraj; x=jedan; y=dva; return true;}
else if(b==4){komanda=Komande::PrikaziOkolinu; x=jedan, y=dva; return true;}
else if(b==5) {komanda=Komande::ZavrsiIgru; return true;}
else if(b==6) {komanda=Komande::KreirajIgru; return true;}
else if(b==-1) 
{
		greska=KodoviGresaka::PogresnaKomanda; return false;
}
	 	
if((b>=0 && b<=3) && (s.size()==0)) {greska=KodoviGresaka::NedostajeParametar; return false;}
	

	return true;
}


void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer = Smjerovi::Gore, int p_x = 0, int p_y = 0)
{
	
	if(komanda==Komande::KreirajIgru)
	{
		int br_polja;
		string s;
		int a,b;
		cout<<"Unesite broj polja: ";
		cin>>br_polja;
		polja.resize(br_polja);
		for(int i=0;i<br_polja;i++)
		polja[i].resize(br_polja);
		cout<<"Unesite pozicije mina: ";
		while(1)
		{
			ovdje:
			cin>>s;
			if(s[0]=='.')break;
			if(s[0]!='(' || s[1]<'0' || s[1]>'9' || s[2]!=',' || s[3]<'0' || s[3]>'9' || s[4]!=')'){cout<<"Greska,unesite ponovo!"<<endl;goto ovdje;}

			a=s[1]-'0'; b=s[3]-'0';
			for(int i=0;i<br_polja;i++)
				for(int j=0;j<br_polja;j++){
				if(i==a && j==b)polja[i][j]=Polje::Mina; 
			}
		}
	}
	else if(komanda==Komande::PomjeriJednoMjesto)
	{ try
		{
		Status status=Idi(polja,x,y,p_smjer);
		string s1=Pretvori(x),s2=Pretvori(y);
		if((polja[x][y]==Polje::BlokiranoPrazno)|| (polja[x][y]==Polje::BlokiranoPosjeceno) || (polja[x][y]==Polje::BlokiranoMina)) status=Status::NijeKraj;
		cout<<"Tekuca pozicija igraca je (" + s1 +"," + s2 +")"<<endl;
		if(status==Status::KrajPobjeda)cout<<"Bravo, obisli ste sva sigurna polja"<<endl;
		else if(status==Status::KrajPoraz)cout<<"Nagazili ste na minu"<<endl;
		if(status!=Status::NijeKraj){
		for(int i=0;i<polja.size();i++)
		for(int j=0;j<polja[i].size();j++)
		polja[i][j]=Polje::Prazno;
		throw runtime_error("Igra zavrsena");
		}
		}
		catch(out_of_range e)
		{
			cout<<e.what()<<endl;
		}
		catch(logic_error e)
		{
			cout<<e.what()<<endl;
		}
		
	}
	else if(komanda==Komande::PomjeriDalje)
	{
		Status status1=Idi(polja,p_x,p_y,x,y);
		string s1=Pretvori(p_x),s2=Pretvori(p_y);
		cout<<"Tekuca pozicija igraca je (" + s1 +"," + s2 +")";
			if(status1==Status::KrajPobjeda)cout<<"Bravo, obisli ste sva sigurna polja";
		else if(status1==Status::KrajPoraz)cout<<"Nagazili ste na minu";
		if(status1!=Status::NijeKraj){
		for(int i=0;i<polja.size();i++)
		for(int j=0;j<polja[i].size();j++)
		polja[i][j]=Polje::Prazno;
		throw runtime_error("Igra zavrsena");
		}
		
	}
	else if(komanda==Komande::Blokiraj)
	{
		BlokirajPolje(polja,x,y);
	}
	else if(komanda==Komande::Deblokiraj)
	{
		DeblokirajPolje(polja,x,y);
	}
	else if(komanda==Komande::PrikaziOkolinu)
	{
		vector<vector<int>>mat=PrikaziOkolinu(polja,x,y);
		
		for(int i=0;i<mat.size();i++){
		for(int j=0;j<mat[i].size();j++)
		cout<<mat[i][j]<<" ";
		cout<<endl;
		}
	}
	else if(komanda==Komande::ZavrsiIgru)
	{
		for(int i=0;i<polja.size();i++)
		for(int j=0;j<polja[i].size();j++)
		polja[i][j]=Polje::Prazno;
		throw runtime_error("Igra zavrsena");
		
	}
	
}


int main ()
{
	bool radi;
	Tabla mat;
	int x=0,y=0;
	Komande komanda;
	Smjerovi smjer;
	KodoviGresaka greska;
	
	while(1){
	try
		{	
	cout<<"Unesite komandu: ";
	
	radi=UnosKomande(komanda, smjer,x,y,greska);
	if(radi)
	{
		IzvrsiKomandu(komanda,mat,x,y,smjer);
	}
	else PrijaviGresku(greska);
		}
	catch(out_of_range e){cout<<e.what();}
	catch(runtime_error e){cout<<"Dovidjenja"<<endl;break;}
	}
	
return 0;
}