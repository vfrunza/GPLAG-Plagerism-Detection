/*B 2016/2017, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Danas je lijep dan   --  Danas je ijeplay dan  --- |Danas je |+|ijep|+|l|ay|+| dan|	
*/
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

std::string spoji(std::string s1,std::string s2){
	for(int i=0; i<(int)s2.size();i++)
		s1.push_back(s2[i]);
	return s1;
}

std::string Saltaj2(int kraj, std::string recenica, std::string rijec){
	int pocetak=kraj-int(rijec.size())+1;
	std::string s1,s2,s3,s4,s5;
	for(int i=0; i<pocetak; i++)
		s1.push_back(recenica[i]);
	for(int i=pocetak+1; i<pocetak+(int)rijec.size(); i++)
		s2.push_back(recenica[i]);
	s3.push_back(recenica[pocetak]);
	s4="ay";
	for(int i=kraj+1; i<(int)recenica.size(); i++)
		s5.push_back(recenica[i]);
	recenica=spoji(spoji(spoji(spoji(s1,s2),s3),s4),s5);
	return recenica;
}

std::vector<std::string> Poizdvajaj(std::string s){
	std::vector<std::string> p;
	std::string t;
	for(int i=0;i<(int)s.size();i++){
		while((s[i]>='A' && s[i]<='Z')||(s[i]>='a' && s[i]<='z')){
			t.push_back(s[i]);
			i++;
		}
		if((int)t.size()!=0){
			p.push_back(t);
			i--;
			p.resize(0);
		}
	}
	return p;
}

bool Provjeri (std::vector<std::string> v){
	for(int i=0; i<(int)v.size(); i++)
		for(int j=0; j<(int)v[i].size();j++)
			if(!((v[i][j]>='A' && v[i][j]<='Z')||(v[i][j]>='a' && v[i][j]<='z')))
				return true;
	return false;
}

std::string Igraj (std::string s, std::string g){ //TREBA JE MODIFIKOVATI; JER ĆE PROMIJENITI TIPA MUAZ (UA) MAUTYZ - Nesto na taj fazon
		int velicina{0};
		for(int i=0; i<(int)s.size(); i++){
		if((s[i]>='a' && s[i]<='z')||(s[i]>='A' && s[i]<='Z'))
			velicina++;
		else
			velicina=0;
		if(s[i]==g[0]){
			int j=0;
			for(; j<(int)g.size(); j++){
				if((s[i]>='a' && s[i]<='z')||(s[i]>='A' && s[i]<='Z'))
					velicina++;
				else
					velicina=0;
				if(s[i]!=g[j])
					break;
				if(i+1==(int)s.size() && j+1!=g.size())
					break;
				i++;
			}
			velicina--;
//			std::cout<<"\n"<<g.size()<<" "<<velicina;
			if(j==(int)g.size() && velicina==(int)g.size())//to bi se moglo ovdje dodati vjerovatno
				s=Saltaj2(i-1,s,g);
			i--;
		}
	}
	return s;
}


std::string IzmijeniUPigLatin(std::string s,std::vector<std::string> v){
	if((int)v.size()==0)
		v=Poizdvajaj(s);
	else if(Provjeri(v)) //TREBA RAZMISLITI DA LI TREBA I IZ REČENICE KAD FRAZE BUDEM VADIO; KAKO IH VADITI
		throw std::domain_error("Izuzetak: Nekorektan izbor rijeci"); //VJEROVATNO NIJE Č
	for(int i=0; i<(int)v.size(); i++)
		s=Igraj(s,v[i]);
	return s;	
}


std::string Saltaj(int kraj,std::string recenica, std::string rijec){
	int pocetak=kraj-int(rijec.size())+1;
	for(int i=0; i<(int)rijec.size()/2; i++){
		char a;
		a=recenica[kraj-i];
		recenica[kraj-i]=recenica[pocetak+i];
		recenica[pocetak+i]=a;
	}
	return recenica;
}

std::string Obrni (std::string s, std::string g){
	for(int i=0; i<(int)s.size(); i++){
		if(s[i]==g[0]){
			int j=0;
			for(; j<(int)g.size(); j++){
				if(s[i]!=g[j])
					break;
				if(i+1==(int)s.size() && j+1!=g.size()){

					break;}
				i++;
			}
			if(j==(int)g.size())
				s=Saltaj(i-1,s,g);
			i--;
		}
	}
	return s;
}


std::string ObrniFraze(std::string s,std::vector<std::string> v){
	for(int i=0; i<(int)v.size(); i++)
		s=Obrni(s,v[i]);
	return s;
}

int main ()
{
	std::string s;
	std::cout<<"Unesite recenicu: ";
	std::getline(std::cin,s);
	std::cout<<"Unesite fraze: ";
	std::vector<std::string> b;
	while(1){
		std::string p;
		std::getline(std::cin,p);
		if(p=="")
			break;
		b.push_back(p);
	}
	try{ //MOGUĆE DA IDE I JEDNO I DRUGO U SLUČAJU BACANJA IZUZETKA ILI SAMO IZUZETAK!!
		std::cout<<"Recenica nakon PigLatin transformacije: "<<IzmijeniUPigLatin(s,b);
	}
	catch(std::domain_error izuzetak){
        std::cout << izuzetak.what();
    }
	std::cout<<"\nRecenica nakon obrtanja fraza: "<<ObrniFraze(s,b);
	return 0;
}
