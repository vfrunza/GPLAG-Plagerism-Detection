/*B 16/17, Zadaća 2, Zadatak 4
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>


void BrisiNullPrt(char** &mat, int &n){
	try{
		char** mat1 = new char*[n];
		int num_nums(n);
		for(int i=0; i<n; i++){
			if(mat1[i]==nullptr){ continue; num_nums--;}
			try{
				int ime_size(0);
				char *p=mat[i];
				while(*p){
					ime_size++;
					p++;
				}ime_size++;
				mat1[i] = new char[ime_size];
				for(int j=0; j<ime_size; j++){
					mat1[i][j]=mat[i][j];
				}
			}catch(...){
				for(int j=0; j<i; j++){
					delete[] mat1[j];
				}delete[] mat1;
				throw;
			}
		}
		for(int j=0; j<n; j++){
			delete[] mat[j];
		}delete[] mat;
		mat=mat1; n=num_nums;
	}catch(...){
		return;
	}
}

int PotencijalniKrivci(char** &mat, std::vector<std::string> pot_prodavaci){
	int num_alloc(0);
	try{
		mat = new char*[pot_prodavaci.size()];
		for(int i=0; i<pot_prodavaci.size(); i++){
			try{
				mat[i] = new char[pot_prodavaci.at(i).length()+1];
				num_alloc++;
				int j(0);
				for(;j<pot_prodavaci.at(i).length(); j++){mat[i][j]=pot_prodavaci[i][j];}
				mat[i][j]=0;
			}catch(std::bad_alloc){
				for(int j=0; j<i; j++){
					delete[] mat[j];
				}
				delete[] mat;
				throw;
			}
		}
	}catch(std::bad_alloc){throw;}
	return num_alloc;
}

int OdbaciOptuzbu(char** &mat, int n, std::string ime){
	int num_nulptr(0);
	int i=0; for(; i<n; i++){
		if(mat[i] == nullptr) {num_nulptr++; continue;}
		bool isti(1);
		for(int j=0; j<ime.length(); j++){
			if(j==ime.length()-1 && mat[i][j+1]!=0) { isti=0; break;}
			if(ime.at(j)!=mat[i][j]){ isti=0; break;}
		}
		if(isti){
			delete[] mat[i];
			mat[i] = nullptr;
			break;
		}
	}
	if(num_nulptr > 10) BrisiNullPrt(mat, n);
	if(i==n){throw std::domain_error("Osoba sa imenom " + ime + " nije bila optuzena");}
	return n;
}

int DodajOptuzbu(char** &mat, int n, std::string ime){
	char *optuzeni = new char[ime.length()+1];
	for(int i=0; i<ime.length(); i++){
		if(i==ime.length()-1){optuzeni[i]=ime[i]; i++; optuzeni[i]=0;}
		else optuzeni[i]=ime[i];
	}
	for(int i=0; i<n; i++){
		if(mat[i]==nullptr) {mat[i]=optuzeni; break;}
		//Ako nema nijedan nullptr
		if(i==n-1){
			try{
			char** mat1 = new char*[n+1];
				for(int i=0; i<n+1; i++){
					try{
						if(i==n){
							mat1[i] = new char[ime.length()+1];
							for(int j=0; j<ime.length()+1; j++){
								mat1[i][j]=optuzeni[j];
							}
							delete[] optuzeni;
							break;
						}
						int ime_size(0);
						char *p=mat[i];
						while(*p){
							ime_size++;
							p++;
						}ime_size++;
						mat1[i] = new char[ime_size];
						for(int j=0; j<ime_size; j++){
						mat1[i][j]=mat[i][j];
						}
					}catch(...){
						for(int j=0; j<i; j++){
							delete[] mat1[j];
						}delete[] mat1;
						throw;
					}
				}
				for(int j=0; j<n; j++){
					delete[] mat[j];
				}delete[] mat;
				mat=mat1;
				return n+1;
			}catch(...){
				throw;
			}
		}
	}
	return n+1;
}

void IzlistajOptuzbu(char** mat, int n){
	for(int i=0; i<n; i++){
		if(mat[i]==nullptr) continue;
		char *p=mat[i]; int ime_size(0);
		while(*p){
			ime_size++;
			p++;
		}ime_size++;
		for(int j=0; j<ime_size-1; j++){
			std::cout << mat[i][j];
		}
		std::cout << std::endl;
	}
}

int main ()
{
	std::cout << "Koliko potencijalnih krivaca zelite unijeti? " << std::endl;
	int br_krivaca(0);
	std::cin >> br_krivaca;
	std::cout << "Unesite potencijalne krivce: " << std::endl;
	std::cin.ignore(1000, '\n');
	try{
		char **pot_krivci = new char *[br_krivaca];
			for(int i=0; i<br_krivaca; i++){
				try{
					std::string ime;
					std::getline(std::cin, ime);
					pot_krivci[i] = new char [ime.length()+1];
					for(int k=0; k<ime.length(); k++){
						pot_krivci[i][k]=ime[k];
						if(k==ime.length()-1) pot_krivci[i][k+1]=0;
					}
				}catch(std::bad_alloc){
					for(int j=0; j<i; j++){
						delete[] pot_krivci[i];
					}delete[] pot_krivci;
					throw;
				}
			}
		int choice(0);
		int imena_num(br_krivaca);
		do{
			std::cout << "Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: " << std::endl;
			std::cin >> choice;
			if(choice==1){
				std::cout << "Unesite ime novog optuzenog: " << std::endl;
				std::string ime;
				std::cin.ignore(1000, '\n');
				std::getline(std::cin, ime);
				imena_num = DodajOptuzbu(pot_krivci, br_krivaca, ime);
			}
			if(choice==2){
				std::cout << "Unesite ime koje zelite izbaciti: " << std::endl;
				std::string ime;
				std::cin.ignore(1000, '\n');
				std::getline(std::cin, ime);
				imena_num = OdbaciOptuzbu(pot_krivci, imena_num, ime);
			}
			if(choice==3) IzlistajOptuzbu(pot_krivci, imena_num);
		}while(choice);
		for(int i=0; i<imena_num; i++){
			delete[] pot_krivci[i];
		}delete[] pot_krivci;
	}catch(std::bad_alloc){
		std::cout << "Izuzetak" << std::endl;
	}
	return 0;
}