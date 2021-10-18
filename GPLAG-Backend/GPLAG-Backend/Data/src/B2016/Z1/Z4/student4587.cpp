#include<iostream>
#include<string>
#include<vector>
#include<stdexcept>
std:: string ObrniFraze ( std:: string recenica, std::vector<std::string>popis )
{
	int m(recenica.size());
	if(popis.size()>0) {
		for(std:: string fraza : popis) {
			int i(0);
			int n(fraza.size());
			while(i<m) {
				int j(0);
				if(recenica[i]==fraza[j]) {
					int pom=i;
					while( (recenica[i]==fraza[j]) && i<m && j<n ) {
						i++;
						j++;
					}
					i--;
					j--;
					int duzina(i-pom);
					if(j==n-1) {
						int pom2=i;
						while(pom2>pom) {
							const char tmp=recenica[pom2];
							recenica[pom2]=recenica[pom];
							recenica[pom]=tmp;
							pom++;
							pom2--;
						}
					}
				i=i-duzina;}
				i++;
			}
		}
	}
	return recenica;
}


std:: string IzmijeniUPigLatin ( std:: string recenica, std::vector<std::string>popis )
{

	if(popis[0].size()==0) {
		int i(0);
		while(i<recenica.size() ) {
			if(  (recenica[i]>='a' && recenica[i]<='z') || (recenica[i]>='A' && recenica[i]<='Z')  ) {
				int pom(i);
				while( ( (recenica[i]>='a' && recenica[i]<='z') || (recenica[i]>='A' && recenica[i]<='Z') )  && i<recenica.size() ) {
					i++;
				}
				i--;
				char tmp=recenica[pom];
				while(pom<i) {
					recenica[pom]=recenica[pom+1];
					pom++;
				}
				recenica[i]=tmp;
				if(i==recenica.size()-1) {
					recenica.push_back('a');
					recenica.push_back('y');
					return recenica;
				} else {

					i++;
					recenica.insert(recenica.begin()+i,'a');
					i++;
					recenica.insert(recenica.begin()+i,'y');
				}
			}
			i++;
		}
	}


	else {

		for(std::string x : popis) {
			for( const char y : x ) {
				if(!( (y>='a' && y<='z') || (y>='A' && y<='Z') ) ) {
					throw std::domain_error("Nekorektan izbor rijeci");
				}
			}
		}

		for(std::string fraza : popis) {
			int i(0);
			int n(fraza.size());
			bool razmak (true);
			while(i<recenica.size()) {
				int j(0);
				if( !( (recenica[i]>='a' && recenica[i]<='z') || (recenica[i]>='A' && recenica[i]<='Z') ) ) {
					razmak=true;
				} else if(razmak==true && recenica[i]==fraza[j]) {
					razmak=false;
					int pom=i;
					while( (recenica[i]==fraza[j]) && i<recenica.size() && j<n ) {
						i++;
						j++;
					}
					i--;
					j--;
					if( j==n-1 && ( i==recenica.size()-1 || ( !( (recenica[i+1]>='a' && recenica[i+1]<='z') || (recenica[i+1]>='A' && recenica[i+1]<='Z') ) ) ) ) {
						char tmp=recenica[pom];
						while(pom<i) {
							recenica[pom]=recenica[pom+1];
							pom++;
						}
						recenica[i]=tmp;
						i++;
						recenica.insert(recenica.begin()+i,'a');
						i++;
						recenica.insert(recenica.begin()+i,'y');

					}
				} else {
					razmak=false;
				}
				i++;
			}
		}
	}
	return recenica;
}

int main ()
{
	std:: string recenica;
	std:: string s;
	std::vector<std::string>popis_rijeci ;

	std::cout << "Unesite recenicu: ";
	std::getline(std::cin,recenica);

	std::cout << "Unesite fraze: ";
	for(;;) {
		std::getline(std::cin,s);
		popis_rijeci.push_back(s);

		if(std::cin.peek()=='\n') {
			break;
		}
	}

	try {
		IzmijeniUPigLatin(recenica,popis_rijeci);
	}

	catch( std:: domain_error izuzetak ) {
		std::cout <<"Izuzetak: "<< izuzetak.what();

		std::cout << std::endl;

		std::cout << "Recenica nakon obrtanja fraza: ";
		for(const char x : ObrniFraze(recenica,popis_rijeci) ) {
			std::cout << x;
		}
		return 0;
	}

	std::cout << "Recenica nakon PigLatin transformacije: ";

	for(const char x : IzmijeniUPigLatin(recenica,popis_rijeci) ) {
		std::cout << x;
	}



	std::cout << std::endl;

	std::cout << "Recenica nakon obrtanja fraza: ";
	for(const char x : ObrniFraze(recenica,popis_rijeci) ) {
		std::cout << x;
	}

	return 0;
}