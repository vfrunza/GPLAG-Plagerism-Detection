/*B 2016/2017, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<iostream>
#include<string>
#include<vector>
#include<stdexcept>

bool alfabet(std::vector<std::string> v){
	for(int i=0; i<v.size();i++)
	for(int j=0; j<v[i].size();j++)
	if(!((v[i][j]>='a' && v[i][j]<='z')||(v[i][j]>='A' && v[i][j]<='Z'))) return false;
	return true;

}

std::string ObrniFraze(std::string s, std::vector<std::string> v){
	std::string fraza, rijec;
	for(int i=0; i<v.size();i++){
		fraza=v[i];
		int karakter(0);
		while(karakter<s.size()){
			if(fraza[0]==s[karakter]){
				rijec=s.substr(karakter, fraza.size());
				if(rijec==fraza){
					int velicina=1;
					for(int j=0;j<fraza.size();j++){
						
						s[karakter+j]=fraza[fraza.size()-velicina];
						velicina++;
					}
				}
			}
//			else karakter=karakter+fraza.size();
		karakter++;
		}
	}
	
	return s;
}

	std::string IzmijeniUPigLatin(std::string s, std::vector<std::string> v){
		std::string fraza, rijec;
		std::string aye("ay");
		if(!alfabet(v)) throw std::domain_error("Nekorektan izbor rijeci");
			for(int i=0; i<v.size();i++){
				fraza=v[i];
				int karakter(0);
				while(karakter<s.size()){
					if(fraza[0]==s[karakter]){
						rijec=s.substr(karakter, fraza.size());
							if(karakter!=0 && s[karakter-1]!=' '){
								karakter+=fraza.size()-1;
								continue;}
/*					if(karakter+fraza.size()+1<s.size() && s[karakter+fraza.size()+1]!=' '){
								karakter+=1;
								continue;}*/
							if(rijec==fraza){
								std::string slovo;
								
								slovo=s[karakter];
//								s.erase(s.begin()+karakter);
//								s.insert(s.begin()+(karakter+fraza.size())), slovo);
								int velicina=1;
								char ubaci(s[karakter]);
								int j;
									for(j=0;j<fraza.size()-1;j++){
										s[karakter+j]=fraza[j+1];
										velicina++;
									}
								//	slovo=slovo+ay;
									s.insert(s.begin()+karakter+j, ubaci);
									s.insert(s.begin()+karakter+j+1, 'a');
									s.insert(s.begin()+karakter+j+2, 'y');
									s.erase(s.begin()+karakter+j+3);
				}
			}
//			else karakter=karakter+fraza.size();
		karakter++;
		}
	}
	return s;
}

int main ()
{
	std::cout<<"Unesite recenicu: ";
	std::string recenica, fraza, obrnuta, piglatin;
	std::getline(std::cin, recenica);
	std::vector<std::string> fraze;
//	fraze ={"danas", "lijep", "suncan"};
	std::cout<<"Unesite fraze: ";
	for(int i=0;;i++){
		std::getline(std::cin, fraza);
		fraze.push_back(fraza);
		if(std::cin.peek()=='\n') break;
	}
	try{
	piglatin=IzmijeniUPigLatin(recenica, fraze);
	std::cout<<"Recenica nakon PigLatin transformacije: ";
	std::cout<<piglatin<<std::endl;
	}
	catch(std::domain_error izuzetak){
	 std::cout<<"Izuzetak: "<<izuzetak.what();
	}
	std::cout<<"\nRecenica nakon obrtanja fraza: ";
	obrnuta=ObrniFraze(recenica, fraze);
	std::cout<<obrnuta;
	return 0;
}