#include <iostream>
#include<cmath>
#include<iomanip>
#include<deque> 
#include<limits>
#include<stdexcept>
#include<vector>
enum  Polje {
Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina
};
enum  Smjerovi {
GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo
};
enum  Status {
NijeKraj, KrajPoraz, KrajPobjeda
};
enum  KodoviGresaka {
PogresnaKomanda, NedostajeParmetar, SuvisanParametar, NeispravanParametar
};
enum  Komande {
PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, Prikaziokolinu,
ZavrsiIgru, Kreirajigru
};
int pretvori (char *a,char *b){
    int suma=0;
    b--;
    int i=0;
    while(b>=a){
        suma+=(*b-'0')*pow(10,i);
        i++;
        b--;
    }
return suma;

}
bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y,
KodoviGresaka &greska){
	std::string s;
	char *temp;
	std::getline(std::cin,s);
	int i=0;
	while(s[i]==' ')i++;
	if(s[i]=='Z'){i++;if(i==s.size()){komanda=ZavrsiIgru;return true;}while(i<s.size()){if(s[i]!=' '){greska=SuvisanParametar;return false;}i++;}return true;}
	if(s[i]=='B'){
	    i++;
	    while(s[i]==' ')i++;
	    if(s[i]<'0'||s[i]>'9'){greska=NeispravanParametar;return false;}
	    temp=&s[i];
	    while(s[i]>='0'&&s[i]<='9')i++;
	    x=pretvori(temp,&s[i]);
	    while(s[i]==' ')i++;
	    if(s[i]<'0'||s[i]>'9'){greska=NeispravanParametar;return false;}
	    temp=&s[i];
	    while(s[i]>='0'&&s[i]<='9')i++;
	    y=pretvori(temp,&s[i]);
		while(i<s.size()){if(s[i]!=' ')greska=SuvisanParametar;return false;i++;}
		komanda=Blokiraj;
		return true;
	}
	if(s[i]=='D'){
	 i++;
	 while(s[i]==' ')i++;
	 if(s[i]<'0'||s[i]>'9'){greska=NeispravanParametar;return false;}
	 temp=&s[i];
	 while(s[i]>='0'&&s[i]<='9')i++;
	 x=pretvori(temp,&s[i]);
	  while(s[i]==' ')i++;
	  if(s[i]<'0'||s[i]>'9'){greska=NeispravanParametar;return false;}
	  temp=&s[i];
	  while(s[i]>='0'&&s[i]<='9')i++;
	  y=pretvori(temp,&s[i]);
	  while(i<s.size()){if(s[i]!=' ')greska=SuvisanParametar;return false;i++;}
	  komanda=Deblokiraj;
		return true;
	}
	if(s[i]=='P'){
		
		i++;
	
	if(s[i]=='O'){
			i++;
	if(i==s.size()){komanda=Prikaziokolinu;return true;}
	while(i<s.size())if(s[i]!=' '){greska=SuvisanParametar;return false;}
	komanda=Prikaziokolinu;return true;
	}
		
		
		if(s[i]=='1'){
			komanda=PomjeriJednoMjesto;
			i++;
			while(s[i]==' ')i++;
			if(i==s.size()){greska=NedostajeParmetar;return false;}
		if(s[i]=='G'){
		if(s[i+1]=='L'){i++;i++;if(i==s.size()){smjer=GoreLijevo;return true;}while(i<s.size()){if(s[i]!=' '){greska=SuvisanParametar;return false;};i++;}smjer=GoreLijevo;return true;}
		if(s[i+1]=='D'){i++;i++;if(i==s.size()){smjer=GoreDesno;return true;}while(i<s.size()){if(s[i]!=' '){greska=SuvisanParametar;return false;};i++;}smjer=GoreDesno;return true;}
		i++;if(i==s.size()){smjer=Gore;return true;}
		while(i<s.size()){if(s[i]!=' '){greska=SuvisanParametar;return false;};i++;}
		smjer=Gore;
		return true;
	}
	if(s[i]=='D'){
		if(s[i+1]=='o'&&s[i+2]=='D'){i++;i++;i++;if(i==s.size()){smjer=DoljeDesno;return true;}while(i<s.size()){if(s[i]!=' '){greska=SuvisanParametar;return false;}i++;}smjer=DoljeDesno;return true;}
		if(s[i+1]=='o'&&s[i+2]=='L'){i++;i++;i++;if(i==s.size()){smjer=DoljeLijevo;return true;}while(i<s.size()){if(s[i]!=' '){greska=SuvisanParametar;return false;}i++;}smjer=DoljeLijevo;return true;}
		if(s[i+1]=='o'){i++;i++;if(i==s.size()){smjer=Dolje;return true;}while(i<s.size()){if(s[i]!=' '){greska=SuvisanParametar;return false;}i++;}smjer=Dolje;return true;}
		{i++;if(i==s.size()){smjer=Desno;return true;}while(i<s.size()){if(s[i]!=' '){greska=SuvisanParametar;return false;}i++;}smjer=Desno;return true;}
	}
	if(s[i]=='L'){i++;if(i==s.size()){smjer=Lijevo;return true;}while(i<s.size()){if(s[i]!=' '){greska=SuvisanParametar;return false;}i++;}smjer=Lijevo;return true;}
	while(i<s.size())if(s[i]!=' '){greska=NeispravanParametar;return false;}
		greska=NedostajeParmetar;return false;
		}
	if(s[i]=='>'){
		i++;
		while (s[i]==' ')i++;
		if(i==s.size()){greska=NedostajeParmetar;return false;}
		if(s[i]<'0'||s[i]>'9'){greska=NeispravanParametar;return false;}
		temp=&s[i];
		while(s[i]>='0'&&s[i]<='9')i++;
		x=pretvori(temp,&s[i]);
		while (s[i]==' ')i++;
		if(i==s.size()){greska=NedostajeParmetar;return false;}
		if(s[i]<'0'||s[i]>'9'){greska=NeispravanParametar;return false;}
		temp=&s[i];
		while(s[i]>='0'&&s[i]<='9')i++;
		y=pretvori(temp,&s[i]);
		if(i==s.size()){komanda=PomjeriDalje;return true;}
		while(i<s.size())if(s[i]!=' '){greska=SuvisanParametar;return false;}
		komanda=PomjeriDalje;
		return true;
	}
	greska=PogresnaKomanda;return false;
	}
	
	greska=PogresnaKomanda;
	return false;
	
}

typedef std::vector<std::vector<Polje>> Tabla;

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine){
	for(int i=0;i<mine.size();i++){
		if((mine[i].size()!=2)||mine[i][0]>n-1||mine[i][0]<0||mine[i][1]>n-1||mine[i][1]<0)throw std::domain_error {"Ilegalan format zadavanja mina"};
	}

	Tabla igra;
	igra.resize(n);
	for(int i=0;i<igra.size();i++){
		igra[i].resize(n);
	}
	int counter(0);
	bool a(false);
	for(int i=0;i<igra.size();i++){
		for(int j=0;j<igra.size();j++){
			if(a==false){
			if ((i==mine[counter][0])&&(j==mine[counter][1])) {
				igra[i][j]=Mina;
				counter++;
				if (counter>=mine.size())a=true;
			}}
			else igra[i][j]=Prazno;
			
		}
	}
	return igra;
}

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y){
	if(x<0||y<0||x>=polja.size()||y>=polja.size())throw std::out_of_range {"Izlazak van igrace table"};
	std::vector<std::vector<int>> v(3);
	for(int i=0;i<3;i++){
		v[i].resize(3);
	}
	int xcounter=0;
	int ycounter=0;
	int suma=0;
	for(int i=1;i>-2;i--){
		for(int j=1;j>-2;j--){
			if(x-i<0||x-i>=polja.size()||y-j<0||y-j>=polja.size()){v[xcounter][ycounter]=0;ycounter++;if(ycounter==3){xcounter++;ycounter=0;}continue;}
			suma=0;
			for(int k=1;k>-2;k--){
				for(int l=1;l>-2;l--){
					if(x-i-k<0||x-i-k>=polja.size()||y-j-l<0||y-j-l>=polja.size())continue;
					if(k==0&&l==0)continue;
					if(polja[x-i-k][y-j-l]==Mina)suma++;
			}
		}v[xcounter][ycounter]=suma;ycounter++;if(ycounter==3){xcounter++;ycounter=0;}
	}}
	return v;
	
}

void BlokirajPolje(Tabla &polja, int x, int y){
	if(x<0||y<0||x>=polja.size()||y>=polja.size())throw std::out_of_range {"Izlazak van igrace table"};
	if(polja[x][y]==Prazno)polja[x][y]=BlokiranoPrazno;
	if(polja[x][y]==Mina)polja[x][y]=BlokiranoMina;
	if(polja[x][y]==Posjeceno)polja[x][y]=BlokiranoPosjeceno;
}

void DeblokirajPolje(Tabla &polja, int x, int y){
	if(x<0||y<0||x>=polja.size()||y>=polja.size())throw std::out_of_range {"Izlazak van igrace table"};
	if(polja[x][y]==BlokiranoPrazno)polja[x][y]=Prazno;
	if(polja[x][y]==BlokiranoMina)polja[x][y]=Mina;
	if(polja[x][y]==BlokiranoPosjeceno)polja[x][y]=Posjeceno;
}

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer){
	Status rtn=NijeKraj;
	int temp1=x;
	int temp2=y;
	if(smjer==Lijevo)if(--y<0){x=temp1;y=temp2;throw std::out_of_range {"Izlazak van igrace table"};}
	if(smjer==Gore)if(--x<0){x=temp1;y=temp2;throw std::out_of_range {"Izlazak van igrace table"};}
	if(smjer==Dolje)if(++x>=polja.size()){x=temp1;y=temp2;throw std::out_of_range {"Izlazak van igrace table"};}
	if(smjer==Desno)if(++y>=polja.size()){x=temp1;y=temp2;throw std::out_of_range {"Izlazak van igrace table"};}
	if(smjer==GoreDesno)if(--x<0||++y>=polja.size()){x=temp1;y=temp2;throw std::out_of_range {"Izlazak van igrace table"};}
	if(smjer==GoreLijevo)if(--x<0||--y<0){x=temp1;y=temp2;throw std::out_of_range {"Izlazak van igrace table"};}
	if(smjer==DoljeDesno)if(++x>=polja.size()||++y>=polja.size()){x=temp1;y=temp2;throw std::out_of_range {"Izlazak van igrace table"};}
	if(smjer==DoljeLijevo)if(++x>=polja.size()||--y<0){x=temp1;y=temp2;throw std::out_of_range {"Izlazak van igrace table"};}
	if(polja[x][y]==BlokiranoMina||polja[x][y]==BlokiranoPosjeceno||polja[x][y]==BlokiranoPrazno){x=temp1;y=temp2;throw std::logic_error{"Blokirano polje"};}
	if(polja[x][y]==Mina)return KrajPoraz;
	bool rekt(true);
	polja[x][y]=Posjeceno;
	for(int i=0;i<polja.size();i++){
		for(int j=0;j<polja.size();j++){
			if(polja[i][j]==Prazno){rekt=false;goto out_of_loop;}
		}
	}
	out_of_loop:
	if(rekt==true)rtn=KrajPobjeda;
	if(rekt==false)rtn=NijeKraj;
	return rtn;
}

Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y){
	Status rtn=NijeKraj;
	if(novi_y<0||novi_y<0||novi_x>=polja.size()||novi_x>=polja.size()){throw std::out_of_range {"Izlazak van igrace table"};}
	if(polja[novi_x][novi_y]==BlokiranoMina||polja[novi_x][novi_y]==BlokiranoPosjeceno||polja[novi_x][novi_y]==BlokiranoPrazno){throw std::logic_error{"Blokirano polje"};}
	if(polja[novi_x][novi_y]==Mina)return KrajPoraz;
	bool rekt(true);
	x=novi_x;
	y=novi_y;
	
	polja[x][y]=Posjeceno;
	for(int i=0;i<polja.size();i++){
		for(int j=0;j<polja.size();j++){
			if(polja[i][j]==Prazno){rekt=false;goto out_of_loop;}
		}
	}
	out_of_loop:
	if(rekt==true)return KrajPobjeda;
	if(rekt==false){return NijeKraj;}
	
	return rtn;
}
bool Jeltocka(std::string s){
	if(s[0]=='.')return true;
	return false;
}

bool MojaFunkcija(std::string s, int &a, int &b){
	int i=0;
	char *temp;
	if(i==s.size())return true;
	while(s[i]==' ')i++;
	if(i==s.size())return true;
	if(s[i]!='(')return true;
	i++;
	if(i==s.size())return true;
	while(s[i]==' ')i++;
	if(i==s.size())return true;
	if(s[i]<'0'||s[i]>'9')return true;
	if(i==s.size())return true;
	temp=&s[i];
	while(s[i]>='0'&&s[i]<='9')i++;
	a=pretvori(temp,&s[i]);
	while(s[i]==' ')i++;
	if(i==s.size())return true;
	if(s[i]!=',')return true;
	i++;
	if(i==s.size())return true;
	while(s[i]==' ')i++;
	if(i==s.size())return true;
	if(s[i]<'0'||s[i]>'9')return true;
	temp=&s[i];
	while(s[i]>='0'&&s[i]<='9')i++;
	b=pretvori(temp,&s[i]);
	if(i==s.size())return true;
	while(s[i]==' ')i++;
	if(i==s.size())return true;
	if(s[i]!=')')return true;
	i++;
	if(i==s.size())return false;
	while(1){
		if(i==s.size())return false;
		if(s[i]!=' ')return true;
		i++;
	}
	return false;
}
void PrijaviGresku(){
	std::cout << "Greska, unesite ponovo!" << std::endl;
}
void IzvrsiKomandu(Komande komanda,Tabla &igra,int &x,int &y,Smjerovi smjer=Gore,int x1=0,int y1=0){

	if(komanda==PomjeriJednoMjesto){auto c= Idi(igra,x,y,smjer);if(c==KrajPobjeda){std::cout << "Bravo, obisli ste sva sigurna polja" << std::endl;throw 1;}if(c==KrajPoraz){std::cout << "Nagazili ste na minu" << std::endl;throw 1;}}
	if(komanda==PomjeriDalje) {auto c =Idi(igra,x,y,x1,y1);if(c==KrajPobjeda){std::cout << "Bravo, obisli ste sva sigurna polja" << std::endl;throw 1;}if(c==KrajPoraz){std::cout << "Nagazili ste na minu" << std::endl;throw 1;}}
	if(komanda==Blokiraj)BlokirajPolje(igra,x1,y1);
	if(komanda==Deblokiraj)DeblokirajPolje(igra,x1,y1);
	if(komanda==Prikaziokolinu){
		auto mat=PrikaziOkolinu(igra,x,y);
		for(int i=0;i<mat.size();i++){
			for(int j=0;j<mat.size();j++){
				std::cout<<mat[i][j]<<" ";
			}
			std::cout  << std::endl;
		}
	}
	if(komanda==ZavrsiIgru)throw 1;
	
}
int main (){
	char c;
	int n;
	Tabla igra;
	std::vector<std::vector<int>> v;
	while(1){
	std::cout << "Unesite komandu: ";
	std::cin>>c;
	if(c!='K'){std::cout << "Greska, unesite ponovo!" << std::endl;continue;}
	if (c=='K'){
		std::cout << "Unesite broj polja: ";
		std::cin >> n;
		break;
		}}
	int a,b;
	std::string s;
	std::cin.ignore(1000,'\n');
	std::cout << "Unesite pozicije mina: ";
	while (1){
		std::getline(std::cin,s);
		if(Jeltocka(s))break;
		if(MojaFunkcija(s,a,b)){std::cout << "Greska, unesite ponovo!" << std::endl;continue;}
		std::vector<int> ss;
		if(a>=n||b>=n||a<0||b<0){std::cout << "Greska, unesite ponovo!" << std::endl;continue;}
		if(a==0&&b==0){std::cout << "Greska, unesite ponovo!" << std::endl;continue;}
		ss.push_back(a);
		ss.push_back(b);
		v.push_back(ss);
	}
	try{
	igra =KreirajIgru(n,v);
	}catch(std::domain_error error){
		std::cout<<error.what();
	}
	igra[0][0]=Posjeceno;
	int x=0;int y=0;
	int x1,y1;
	int provjera1=x,provjera2=y;
	
	while(1){
		Komande kom;Smjerovi smj;KodoviGresaka gresk;
	std::cout << "Unesite komandu: " ;
	if(UnosKomande(kom,smj,x1,y1,gresk)==false){std::cout << "Greska, unesite ponovo!" << std::endl;continue;}
	try{
	IzvrsiKomandu(kom,igra,x,y,smj,x1,y1);
	if(provjera1!=x||provjera2!=y){
	std::cout <<  "Tekuca pozicija igraca je ("<<x<<","<<y<<")"<< std::endl;
	provjera1=x;provjera2=y;
	}
	}catch(std::out_of_range range){
		std::cout << range.what() << std::endl;
		continue;
	}catch(std::logic_error Lo){
		std::cout << Lo.what() << std::endl;
	}
	catch(...){
		std::cout<<"Dovidjenja!";
		break;
	}

	}
	return 0;
}