/*B 2016/2017, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

std::string ObrniFraze(std::string s, std::vector<std::string> fraza){
	//for-petlja kojom pristupamo frazama redom od prve do posljednje
	for(int i=0; i<fraza.size(); i++){
		int duzina(fraza[i].size());
		//for-petlja koja prolazi kroz svaki znak stringa
		for(int j=0; j<s.size(); j++){
			//1. uslov da se fraza i dio stringa podudaraju(da je prvi znak fraze jednak trenutnom znaku stringa)
			if(s[j]==fraza[i][0]){
				int br1(j);
				int br2(0);
				//while-petlja koja broji koliko se znakova poklapa
				//1. i 2. uslov sluze da brojaci ne izadju izvan opsega stringova
				while(br1<s.size() && br2<duzina && fraza[i][br2]==s[br1]){
					br1++;
					br2++;
				}
				//ako je broj podudarnih znakova jednak duzini fraze to znaci da je fraza pronadjena u stringu 
				if(br2==duzina){
					int brojac(br2/2);
					//while-petlja koja vrsi obrtanje rijeci u strinug
					while(brojac!=0){
						char pomocna(s[j+(duzina-br2)]);
						s[j+(duzina-br2)]=s[j+br2-1];
						s[j+br2-1]=pomocna;
						brojac--;
						br2--;
					}
				}
			}
		}
	}
	return s;
}
std::string IzmijeniUPigLatin(std::string s, std::vector<std::string> lista){
	if(lista.size()==0){
		int duzina(s.length());
		for(int i=0; i<duzina; i++){
			int kraj(i);
			bool rijec_nadjena(false);
			//uslov kojim se provjerava da li je nesto pocetak rijeci(tj. znak je eng. alfabet)
			if( (s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') ){
				rijec_nadjena=true;
				int pocetak(i);
				kraj=i;
				//while-petlja kojom se pozicinoramo na kraj trenutne rijeci
				while( kraj<duzina && ( (s[kraj]>='A' && s[kraj]<='Z') || (s[kraj]>='a' && s[kraj]<='z') ) )
					kraj++;
				//blok naredbi kojim prebacujemo prvo slovo na kraj rijeci, a ostala slova pomjeramo za jedno mjesto ulijevo
				char pomocna(s[pocetak]);
				for(int j=pocetak; j<kraj-1; j++)
					s[j]=s[j+1];
				s[kraj-1]=pomocna;
				//povecavamo string za 2, jer je potrebno dodati 2 nova znaka tj. "ay"
				duzina+=2;
				s.resize(duzina);
				//pomjeramo sve znakove stringa za 2 mjesta udesno(pocev od kraja pronadjene rijeci) da bi mogli upisati "ay"
				for(int j=duzina-1; j>=kraj+2; j--)
					s[j]=s[j-2];
				//buduci da smo napravili dodatni prostor, sada na kraj rijeci dodajemo "ay"
				s[kraj]='a';
				s[kraj+1]='y';
			}
			if(rijec_nadjena) i=kraj+1;
		}
	}
	else{
		//2 ugnijezdene for-petlje koje prolaze kroz svaki znak poslanih rijeci i provjeravaju da li se nalazi ista
		//osim slova engleskog alfabeta
		for(int i=0; i<lista.size(); i++){
			int duzina(lista[i].size());
			for(int j=0; j<duzina; j++)
				if( !( (lista[i][j]>='A' && lista[i][j]<='Z') || (lista[i][j]>='a' && lista[i][j]<='z') ) ){
					throw std::domain_error("Nekorektan izbor rijeci");
					break;
				}
		}
		for(int i=0; i<lista.size(); i++){
			int duzina(lista[i].size());
			bool neslovo=true;
			for(int j=0; j<s.size(); j++){
				int kraj(j);
				bool rijec_nadjena(false);
				// if i else if sluze za provjeru da li se radi o rijeci(a ne podstringu)
				if( !( (s[j]>='A' && s[j]<='Z') || (s[j]>='a' && s[j]<='z') ) )
					neslovo=true;
				//ako je trenutni znak u stringu s zaista pocetak nove rijeci(prije njega se nalazi nesto sto nije dio eng. alfabeta)
				//blok naredbi ispituje da li se ta rijec i rijec iz liste poklapaju
				else if(neslovo==true){
				neslovo=false;
				//uslov poklapanja dvije rijeci je da su im pocetna slova ista
				if(s[j]==lista[i][0]){
					int pocetak(j);
					kraj=j;
					int br2(0);
					//while-petlja koja sluzi za brojanje istih znakova
					while(kraj<s.size() && br2<duzina && lista[i][br2]==s[kraj]){
						kraj++;
						br2++;
					}
					//if-uslov koji provjerava da li je pronadjeno preklapanje izmedju trenutne rijeci iz liste i dijela stringa s
					//osim toga vrsi provjeru da li je podstring stringa s zaista rijec(tj. na mjestu iza poslednjeg podudarnog znaka
					//se nalazi kraj stringa s ili nesto sto nije slovo eng. alfabeta. U suprotnom to nije rijec, pa se ne treba vrsiti transformacija
					if(br2==duzina && (kraj==s.size() || !( (s[kraj]>='A' && s[kraj]<='Z') || (s[kraj]>='a' && s[kraj]<='z') ) ) ){
							rijec_nadjena=true;
							//princip rada izmjene rijeci u skladu sa PigLatin pravilima je potpuno identican prethodno opisanom
							// 60 do 76 linija koda, stoga ga nema potrebe dalje objasavati
							char pomocna(s[pocetak]);
							for(int k=pocetak; k<kraj-1; k++)
								s[k]=s[k+1];
							s[kraj-1]=pomocna;
							int duzina1(s.size());
							duzina1+=2;
							s.resize(duzina1);
							for(int k=duzina1-1; k>=kraj+2; k--)
								s[k]=s[k-2];
							s[kraj]='a';
							s[kraj+1]='y';
						}
					}
					}
					if(rijec_nadjena) j=kraj+1;
				}
			}
		}
		return s;
	}

int main ()
{		std::string s;
		std::cout<<"Unesite recenicu: ";
		std::getline(std::cin, s);
		std::vector<std::string> fraze;
		std::cout<<"Unesite fraze: ";
		int br(0),vel(1);
		while(std::cin.peek()!='\n'){
			fraze.resize(vel);
			std::getline(std::cin, fraze[br]);
			vel++;
			br++;
		}
		std::string s0(s);
	try{
		std::string s2(IzmijeniUPigLatin(s,fraze));
		std::cout<<"Recenica nakon PigLatin transformacije: "<<s2<<std::endl;
	}
	catch(std::domain_error izuzetak){
		std::cout <<"Izuzetak: "<<izuzetak.what() << std::endl;
	}
	std::string s1(ObrniFraze(s0,fraze));
	std::cout<<"Recenica nakon obrtanja fraza: "<<s1;
	return 0;
}