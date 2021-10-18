#include <iostream>
#include <vector>
#include <algorithm>
#include <new>
#include <string>
#include <cstring>
#include <stdexcept>

using namespace::std;

int PotencijalniKrivci(char ** &a,vector<string> v)
{
	a = nullptr;
	try
	{
		a = new char*[v.size()];
		for(int i = 0 ; i < v.size();i++)
		{
			a[i] = nullptr;
			a[i] = new char[v[i].length() + 1];
			strcpy(a[i],v[i].c_str());
		}
	}
	catch(bad_alloc)
	{
		for(int i(0); i < v.size();i++)
			delete[] a[i];
		delete [] a;
		throw;
	}
	return v.size();
}
int OdbaciOptuzbu(char **& a,int vel,string s)
{
	int broj_nlptr(0);
	for(int i(0);i< vel;i++)
	{
		if(a[i] == nullptr)
			broj_nlptr++;
	}
	char ime[50];
	strcpy(ime,s.c_str());
	
	int brojac(0);
	for(int i(0);i < vel;i++)
	{
		if(strcmp(a[i],ime) == 0)
		{
			delete[] a[i];
			a[i] = nullptr;
			brojac++;
		}
	}

	if(brojac == 0)
		throw domain_error("Osoba sa imenom " + s + " nije bila optuzena");

	char **novi = nullptr;
	if(broj_nlptr > 10)
	{
			novi = new char*[vel - broj_nlptr];
			for (int i(0); i < vel - broj_nlptr; i++)
                novi[i] = nullptr;
			for(int i(0);i<vel;i++)
			{
				int j(0);
				if(a[i] != nullptr)
				{
					char *temp = new char[strlen(a[i])];
					strcpy(temp,a[i]);
					novi[j] = temp;
					j++;
					
				}
			}
			a = novi;
	}
	return vel - broj_nlptr;
}
int DodajOptuzbu(char **& a,int vel,string s)
{
	char *ime = new char[s.length()+1];
	strcpy(ime,s.c_str());
	for(int i(0); i < vel;i++)
	{
		if(a[i] == nullptr)
		{
			a[i] = ime;
			return vel;
		}
	}
	char **novi;
	try
	{
		novi = new char*[vel+1];
		
		for(int i(0);i < vel;i++)
		{
			novi[i] = nullptr;
			novi[i] = new char[strlen(a[i])+1];
			strcpy(novi[i],a[i]);
			delete[] a[i];
		}
		novi[vel] = new char[strlen(ime)+1];
		strcpy(novi[vel],ime);
		delete[] ime;
		delete[] a;
		a = novi;
		
	}
	catch(...)
	{

	}
	return vel+1;
}
void IzlistajOptuzbu(char **a, int vel)
{
	for(int i(0); i < vel;i++)
	{
			int j(0);
			if(a[i] == nullptr)
				continue;
			while(j < strlen(a[i]))
			{
				cout << a[i][j++];
			}
		cout << endl;
	}
}
int main()
{
	int n,m;
	vector<string> a;
	char **krivci;
	cout << "Koliko potencijalnih krivaca zelite unijeti? " << endl;
	cin >> n;
	cout << "Unesite potencijalne krivce: " << endl;
	for(int i = 0;i < n;i++)
	{
		string temp;
		cin >> temp;
		a.push_back(temp);
	}
	try
	{
		m = PotencijalniKrivci(krivci,a);
		while(m != 0)
		{
			int opc;
			string temp;
			cout << "Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: " << endl;
			cin >> opc;
			if(opc == 0)
				break;
			if(opc == 1)
			{
				cout << "Unesite ime novog optuzenog: " << endl;
				cin >> temp;
				m = DodajOptuzbu(krivci,m,temp);
			}
			if(opc == 2)
			{
				cout << "Unesite ime koje zelite izbaciti: " << endl;
				cin >> temp;
				m = OdbaciOptuzbu(krivci,m,temp);
			}
			if(opc == 3)
			IzlistajOptuzbu(krivci,m);
		}
	}
	catch(...)
	{
		
	}
	for(int i(0); i < m;i++)
	{
		delete[] krivci[i];
		krivci[i] = nullptr;
	}
	delete[] krivci;
	krivci = nullptr;
	
	return 0;
}