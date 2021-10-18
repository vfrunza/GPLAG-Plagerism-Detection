#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

using std::cout;
using std::cin;
using std::endl;

int PotencijalniKrivci( char**&x, std::vector<std::string> krivci)
{
	char**pok;
	try{
		pok=new char*[krivci.size()];
		for(int i=0; i<krivci.size(); i++)
		{
			pok[i]=nullptr;
		}
		for(int i=0; i<krivci.size(); i++)
		{
			pok[i]=new char[krivci[i].size()+1];
			
		}
		for(int i(0); i<krivci.size(); i++)
		{
			int k(0);
			for(int j(0); j<krivci[i].size(); j++)
			{
				pok[i][j]=krivci[i][j];
				k=j;
			} 
			k++;
			pok[i][k]='\0';
		}
		x=pok;
		return krivci.size();
	}
	catch(...)
	{
		for(int i=0; i<krivci.size(); i++)
		{
			delete[] pok[i];
		}
		delete[] pok;
		throw std::bad_alloc();
	}
}


int OdbaciOptuzbu( char**&x, int n, std::string s)
{
	int br(0);
	for(int i=0; i<n; i++)
	{
		if(x[i]==nullptr) br++;
		
	}
	
	std::string pomocni;
	pomocni=s;
	std::vector<int>indexi;
	for(int i=0; i<n; i++)
	{
		std::string s2;
		for(int j=0; j<pomocni.size(); j++)
		{
			s2=s2+x[i][j];
		}
		if(s2==pomocni)
		{
			indexi.push_back(i);
			br++;
			
		}
		
	}
	if(indexi.size()==0) 
	{
		throw std::domain_error("Osoba sa imenom "+s+" nije bila optuzena");
	}
	for(int i=0; i<indexi.size(); i++ )
	{
		delete[] x[indexi[i]];
		x[indexi[i]] = nullptr;
		
	}
	int vel=n-br;
	int index(0);
	if(br>=10)
	{
		char**pok=new char*[vel];
		for(int i(0); i<vel; i++)
		{
			pok[i]=nullptr;
		}
		for(int i(0); i<n; i++)
		{
			if(x[i]!=nullptr)
			{
				pok[index]= x[i];
				index++;
			}
			delete[] x[i];
		}
		delete[] x;
		x=pok;
		return vel;
		
	}
	else return n;
}

void IzlistajOptuzbu( char**x, int n )
{
	for(int i(0); i<n; i++)
	{
		if(x[i]!=0)
		{
			cout<<x[i];
		}
		cout<<endl;
	}
}

int main ()
{
	int n;
	cout<<"Koliko potencijalnih krivaca zelite unijeti? "<<endl;
	cin>>n;
	std::cin.ignore(10000, '\n');
	 std::vector<std::string> vs;
	 std::string s;
	 
	 cout<<"Unesite potencijalne krivce: "<<endl;
	 for(int i(0); i<n; i++)
	 {
	 	std::getline(cin, s);
	 	vs.push_back(s);
	 }
	 char **krivci;
	 n=PotencijalniKrivci(krivci, vs);
	 int x;
	 do{
	 	cout<<"Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: "<<endl;
	 	cin>>x;
	 	if(x==0) {
	 		for(int i(0); i<n; i++)
	 		{
	 			delete[] krivci[i];
	 		}
	 		delete[] krivci;
	 	
	 	}
	 	else if(x==2)
	 	{
	 		cout<<"Unesite ime koje zelite izbaciti: "<<endl;
	 		try{
	 			std::string ime;
	 			std::getline(cin,ime);
	 			n=OdbaciOptuzbu(krivci,n,ime );
	 			
	 		}
	 		catch(std::domain_error e)
	 		{
	 			cout<<e.what()<<endl;
	 		}
	 		
	 		
	 	}
	 	else if(x==3)
	 	{
	 		IzlistajOptuzbu(krivci, n);
	 	}
	 	
	 	
	 	
	 }while(x!=0);
	 
	 
	
	
	
	return 0;
}