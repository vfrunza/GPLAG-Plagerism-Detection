#include <iostream>
#include <cstring>
#include <new>

using namespace std;

int main()
{
	char **pok=nullptr;
	cout<<"Koliko zelite recenica: ";
	int broj_rec;
	cin>>broj_rec;
	cin.ignore(10000, '\n');
	
	try{
		
		cout<<"Unesite recenice: "<<endl;
		pok=new char*[broj_rec];
		try{
			for(int i=0; i<broj_rec; i++)
			{
				char recenica[1000];
				cin.getline(recenica, sizeof recenica);
			
					pok[i]=new char[(sizeof recenica)+1];
					strcpy(pok[i], recenica);
			}
			
			cout<<"Sortirane recenice: "<<endl;
		
			for(int i=0; i<broj_rec-1; i++)
			{
				for(int j=i+1; j<broj_rec; j++)
				{
			
					if(strcmp(pok[i],pok[j])>0)
					{
						char *temp;
						temp=pok[i];
						pok[i]=pok[j];
						pok[j]=temp;
					}
				}
			}
			for(int i=0; i<broj_rec; i++)
			{
				cout<<pok[i]<<endl;
			}
			
			for(int i=0; i<broj_rec; i++)
			{
				delete [] pok[i];
			}
			delete [] pok;
			
			
		}
		catch(...)
		{
			
			for(int i=0; i<broj_rec; i++)
			{
				delete [] pok[i];
			}
			throw;
		}
	}
	
	catch(...)
	{
		cout<<endl;
		cout<<"Problemi s memorijom!";
		delete [] pok;
	}

	return 0;
}