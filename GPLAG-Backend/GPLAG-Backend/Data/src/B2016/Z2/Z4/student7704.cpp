/*B 16/17, Zadaća 2, Zadatak 4
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/
#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <cstring>
#include <stdexcept>

using namespace std;

int PotencijalniKrivci(char **& spremnik, vector<string> v){
	int rez=0;
	char ** mat=nullptr;
	try{
		mat=new char*[v.size()];
	}catch(...){
		delete mat;
		mat=nullptr;
		throw bad_alloc();
	}
	for(int i(0); i<(int)v.size(); i++) mat[i] = nullptr;
	for(int i(0); i<(int)v.size(); i++){
		try{
			mat[i]=new char[v[i].size() + 1];
		}catch(bad_alloc()){
			for(int j(0); j<=i; j++){
				delete[] mat[j];
				mat[j]=nullptr;
			}
			delete[] mat;
			mat=nullptr;
		}
		int j=0;
		for(; j<(int)v[i].size(); j++)
			mat[i][j] = v[i][j];
		mat[i][j]='\0';
		rez++;
	}
	spremnik=mat;
	return rez;
}

int OdbaciOptuzbu(char **& mat, int vel, string s){
	bool postoji=false;
	for(int i(0); i<vel; i++){
		if(mat[i]!=nullptr && string(mat[i])==s){
			postoji=true;
			delete[] mat[i];
			mat[i]=nullptr;
			break;
		}	
	}
	if(!postoji)
		throw domain_error("Osoba sa imenom " + s + " nije bila optuzena");
	int obrisanih=0;
	for(int i(0); i<vel; i++) if(mat[i]==nullptr) obrisanih++;
	if(obrisanih>=10){
		char ** nova=nullptr;
		try{
			nova=new char*[vel - obrisanih];
		}catch(...){
			delete nova;
			nova=nullptr;
			return vel;
		}
		int j=0;
		for(int i(0); i<vel; i++){
			if(mat[i]!=nullptr){
				nova[j]=mat[i];
				mat[i]=nullptr;
				j++;
			}
		}
		vel-=obrisanih;
		mat=nova;
	}
	return vel;
}

int DodajOptuzbu(char **& mat, int vel, string s){
	bool imaMjesta(false);
	char * ime=nullptr;
	try{
		ime=new char[s.size() + 1];
	}catch(...){
		delete ime;
		throw bad_alloc();
	}
	strcpy(ime, s.c_str());
	for(int i(0); i<vel; i++){
		if(mat[i]==nullptr){
			mat[i]=ime;
			imaMjesta=true;
			break;
		}
	}
	
	if(!imaMjesta){
		char ** nova=nullptr;
		try{
			nova=new char*[vel + 1];
		}catch(...){
			delete nova;
			throw bad_alloc();
		}
		for(int i(0); i<vel; i++){
			nova[i]=mat[i];
			mat[i]=nullptr;
		}
		nova[vel]=ime;
		vel++;
		for(int i(0); i<vel-1; i++) delete[] mat[i];
		delete[] mat;
		mat=nova;
	}
	return vel;
}

void IzlistajOptuzbu(char ** mat, int vel){
	for(int i(0); i<vel; i++)
		if(mat[i]!=nullptr) cout << mat[i] << endl;
}

int main ()
{
	int n;
	char ** mat=nullptr;
	try{
		
		cout<< "Koliko potencijalnih krivaca zelite unijeti? " << endl;
        cin>> n;
        cout<< "Unesite potencijalne krivce: " << endl;
        vector<string> v;
        for(int i(0); i<n; i++){
            string s;
            cin>> s;
            v.push_back(s);
        }
        n=PotencijalniKrivci(mat, v);
        bool kraj(false);
        while(!kraj){
            cout<< "Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: " << endl;
			int izbor;
			string s;
			cin >> izbor;
			switch(izbor){
				case 0:
					kraj=true;
					break;
				case 1:
					cout<< "Unesite ime novog optuzenog: " << endl;
					cin>> s;
					n=DodajOptuzbu(mat, n, s);
					break;
				case 2:
					cout<< "Unesite ime koje zelite izbaciti: " << endl;
					cin>> s;
					n=OdbaciOptuzbu(mat, n, s);
					break;
				case 3:
					IzlistajOptuzbu(mat, n);
					break;
			}
        }
        for(int i(0); i<n; i++)
        	delete[] mat[i];
        delete[] mat;
	}catch(exception &e){
		cout << e.what() << endl;
		for(int i(0); i<n; i++)
        	delete[] mat[i];
        delete[] mat;
	}
	return 0;
}