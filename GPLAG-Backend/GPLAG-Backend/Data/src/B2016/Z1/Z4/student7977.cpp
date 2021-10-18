/*B 2016/2017, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<iostream>
#include<vector>
#include<string>
#include<stdexcept>

std::string ObrniFraze(std::string s, std::vector<std::string> v){
	std::string povratni(s);

	for(int j=0; j<v.size(); j++){
		for(int i=0; i<povratni.length(); i++){
			if(povratni[i] == v[j][0]){
				int k;
				int h(i);
				h++;
				for(k=1; k<v[j].length(); k++){
					if(h == povratni.length())break;
					if(povratni[h] == v[j][k]){
						h++;
						continue;
					}else{
						break;
					}
				}
				if(k == v[j].length()){
					int duzina = ((h-i) / 2) + i;
					int kraj(h);
					char temp(povratni[i]);
					std::string rijec1(povratni.substr(i, kraj-i));
					
					for(int f=i; f<duzina; f++){
						h--;
						temp = povratni[f];
						povratni[f] = povratni[h];
						povratni[h] = temp;
					}
					std::string rijec2(povratni.substr(i, kraj-i));
					
					if(rijec1 != rijec2){
						i--;
					}else{
						continue;
					}
				}else{
					continue;
				}
			}else{
				continue;
			}
		}
	}
	return povratni;
}

std::string IzmijeniUPigLatin(std::string s, std::vector<std::string> v){
	for(int i=0; i<v.size(); i++){
		for(int j=0; j<v[i].size(); j++){
			if(!((v[i][j]>='a' && v[i][j]<='z')||(v[i][j]>='A' && v[i][j]<='Z'))){
				throw std::domain_error("Nekorektan izbor rijeci");
			}
		}
	}
	
	if(v.size() != 0){
		bool a(true);
		for(int i=0; i<s.length(); i++){
			if(!((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))){
				a = true;
			}else if(a == true){
				a = false; 
				for(int j=0; j<v.size(); j++){
					if(s[i] == v[j][0]){
						int k;
						int h(i);
						h++;
						for(k=1; k<v[j].length(); k++){
							if(h == s.length()) break;
							if(s[h] == v[j][k]){
								h++;
								continue;
							}else{
								break;
						}
						}
						if(k == v[j].length() && !((s[h] >= 'a' && s[h] <= 'z') || (s[h] >= 'A' && s[h] <= 'Z')) ){
							s.resize(s.length()+2);
							int kraj(s.length()-1);
							while(kraj != h-1){
								s[kraj] = s[kraj-2];
								kraj--;
							}
							s[h] = 'a';
							s[h+1] = 'y';
							char pomocna(s[i]);
							for(int x=i; x<h-1; x++){
								s[x] = s[x+1];
							}
							s[h-1] = pomocna;
							i = h+1;
						}else{
							continue;
						}
					}else{
						continue;
					}
				}
			}
		}
	}else{
		bool a(true);
		for(int i=0; i<s.length(); i++){
			if(!((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))){
				a = true;
			}else if(a == true){
				a = false;
				int j(i+1);
				while(((s[j] >= 'a' && s[j] <= 'z') || (s[j] >= 'A' && s[j] <= 'z')) && j < s.length()){
					j++;
				}
				s.resize(s.length()+2);
				int kraj(s.length()-1);
				while(kraj != j-1){
					s[kraj] = s[kraj-2];
					kraj--;
				}
				s[j] = 'y';
				s[j+1] = 'a';
				char pomocna(s[i]);
				for(int x=i; x<j-1; x++){
					s[x] = s[x+1];
				}
				s[j-1] = pomocna;
				i = j+1;
			}
		}
	}
	return s;
}

int main ()
{
	std::string s, povratni1, povratni2, rijec;
	std::vector<std::string> v;
	std::cout << "Unesite recenicu: ";
	std::getline(std::cin, s);
	std::cout << "Unesite fraze: ";
	int br_fraza=0;
	do{
		br_fraza++;
		std::getline(std::cin, rijec);
		if(rijec.length() != 0){
			v.resize(br_fraza);
			v[br_fraza-1] = rijec;
		}
	}while(rijec.length() != 0);

	try{
		povratni1 = IzmijeniUPigLatin(s, v);
		std::cout << "Recenica nakon PigLatin transformacije: " << povratni1 << std::endl;
	}catch(std::domain_error izuzetak){
		std::cout << "Izuzetak: " << izuzetak.what() << std::endl;
	}
	
	povratni2 = ObrniFraze(s, v);
	std::cout << "Recenica nakon obrtanja fraza: " << povratni2;

	return 0;
}