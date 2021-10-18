/*B 2017/2018, Zadaća 2, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na forum (c2).
*/
#include <iostream>
#include <vector> 
#include <deque>
#include <type_traits>
#include <iomanip>
#include <stdexcept>

using namespace std;

enum class SmjerKretanja {
 NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
};

template<typename Kontejner>
void IspisiKontejner(Kontejner kont)
{    
	cout<<"Pjescani sat unesene matrice je: "<<endl;
	for(int i=0;i<kont.size();i++)
	{   
	
		for(int j=0;j<kont.at(i).size();j++)
		{   
			int sirina=j+1;
				if(j>kont.at(i).size()/2) sirina=kont.at(i).size()-sirina+1;
		
			for(int k=0;k<kont.at(i).at(j).size();k++)
			{   
				
					if(j>0 && j<kont.at(i).size()-1 && k>0 && k<kont.at(i).size()-1)	sirina=1;
				
						cout<<setw((sirina)*4)<<kont.at(i).at(j).at(k);
						
			}
			cout<<endl;
		}
		cout<<endl;
	}
}




template<typename Kontejner>
auto PjescaniSat(Kontejner kont,SmjerKretanja k)->typename remove_reference<decltype(kont)>::type
{
	for(int i=0; i<kont.size(); i++){
		for(int j=0; j<kont.at(i).size(); j++){
				if(kont.at(i).size()!=kont.at(i).at(j).size()) throw domain_error("3D matrica nema oblik kocke");
				if(kont.at(i).size()%2==0) throw length_error("3D kontejner ne zadovoljava uvjet neparnosti");
		}
	}
	

	
	typename remove_reference<decltype(kont)>::type povratni;
	
	
	if((int)k==0)
	{
		for(int i=0;i<kont.size();i++)
		{   
			
			typename remove_reference<decltype(kont.at(i))>::type pomocni;
			
			for(int j=0;j<kont.at(i).size();j++)
			{   
				typename remove_reference<decltype(kont.at(i).at(j))>::type temp;
				    int granica=j;
					if(j>kont.at(i).at(j).size()/2) 
						granica=kont.at(i).size()-1-j;
						
					for(int k=granica;k<kont.at(i).at(j).size()-granica;k++)
					{
						temp.push_back(kont.at(j).at(i).at(k));
					}
					pomocni.push_back(temp);
				
				
				
				
			}
			povratni.push_back(pomocni);
		}
	}
	else if((int)k==1)
	{
		for(int i=0;i<kont.size();i++)
		{   
			
			typename remove_reference<decltype(kont.at(i))>::type pomocni;
			
			for(int j=kont.at(i).size()-1;j>=0;j--)
			{   
				typename remove_reference<decltype(kont.at(i).at(j))>::type temp;
				    int granica=j;
					if(j>kont.at(i).at(j).size()/2) 
						granica=kont.at(i).size()-1-j;
						
					for(int k=granica;k<kont.at(i).at(j).size()-granica;k++)
					{
						temp.push_back(kont.at(j).at(i).at(k));
					}
					pomocni.push_back(temp);
				
				
				
				
			}
			povratni.push_back(pomocni);
		}
	}
	else if((int)k==2)
	{
		for(int i=0;i<kont.size();i++)
		{   
			
			typename remove_reference<decltype(kont.at(i))>::type pomocni;
			
			for(int j=0;j<kont.at(i).size();j++)
			{   
				typename remove_reference<decltype(kont.at(i).at(j))>::type temp;
				    int granica=j;
					if(j>kont.at(i).at(j).size()/2) 
						granica=kont.at(i).size()-1-j;
						
					for(int k=granica;k<kont.at(i).at(j).size()-granica;k++)
					{
						temp.push_back(kont.at(i).at(j).at(k));
					}
					pomocni.push_back(temp);
				
			}
			povratni.push_back(pomocni);
		}
	}
	else if((int)k==3)
	{
		for(int i=0;i<kont.size();i++)
		{   
			
			typename remove_reference<decltype(kont.at(i))>::type pomocni;
			
			for(int j=kont.at(i).size()-1;j>=0;j--)
			{   
					typename remove_reference<decltype(kont.at(i).at(j))>::type temp;
				    int granica=j;
					if(j>kont.at(i).at(j).size()/2) 
						granica=kont.at(i).size()-1-j;
						
					for(int k=granica;k<kont.at(i).at(j).size()-granica;k++)
					{
						temp.push_back(kont.at(i).at(j).at(k));
					}
					pomocni.push_back(temp);
				
			}
			povratni.push_back(pomocni);
		}
	}
	else if((int)k==4)
	{
		for(int i=0;i<kont.size();i++)
		{   
			
			typename remove_reference<decltype(kont.at(i))>::type pomocni;
			
			for(int j=0;j<kont.at(i).size();j++)
			{   
				typename remove_reference<decltype(kont.at(i).at(j))>::type temp;
				    int granica=j;
					if(j>kont.at(i).at(j).size()/2) 
						granica=kont.at(i).size()-1-j;
						
					for(int k=granica;k<kont.at(i).at(j).size()-granica;k++)
					{
						temp.push_back(kont.at(i).at(k).at(j));
					}
					pomocni.push_back(temp);
				
				
				
				
			}
			povratni.push_back(pomocni);
		}
	}
	else if((int)k==5)
	{
		for(int i=0;i<kont.size();i++)
		{   
			
			typename remove_reference<decltype(kont.at(i))>::type pomocni;
			
			for(int j=kont.at(i).size()-1;j>=0;j--)
			{   
				typename remove_reference<decltype(kont.at(i).at(j))>::type temp;
				    int granica=j;
					if(j>kont.at(i).at(j).size()/2) 
						granica=kont.at(i).size()-1-j;
						
					for(int k=granica;k<kont.at(i).at(j).size()-granica;k++)
					{
						temp.push_back(kont.at(i).at(k).at(j));
					}
					pomocni.push_back(temp);
				
				
				
				
			}
			povratni.push_back(pomocni);
		}
	}
	
	
	
	
	
	
	
	
	return povratni;	
}

int main ()
{   
	/*	
	deque<vector<deque<string>>> kont
	{
		{
		 {"Hel","Hel","Hel","Hel","Hel"},
		{"Hel","Hel","Hel","Hel","Hel"},
		 {"Hel","Hel","Hel","Hel","Hel"},
		 {"Hel","Hel","Hel","Hel","Hel"},
		{"Hel","Hel","Hel","Hel","Hel"},
		},

		{
		 {"Hel","Hel","Hel","Hel","Hel"},
		{"Hel","Hel","Hel","Hel","Hel"},
		 {"Hel","Hel","Hel","Hel","Hel"},
		 {"Hel","Hel","Hel","Hel","Hel"},
		{"Hel","Hel","Hel","Hel","Hel"},
		},

		{
		 {"Hel","Hel","Hel","Hel","Hel"},
		{"Hel","Hel","Hel","Hel","Hel"},
		 {"Hel","Hel","Hel","Hel","Hel"},
		 {"Hel","Hel","Hel","Hel","Hel"},
		{"Hel","Hel","Hel","Hel","Hel"},
		},
		
			{
		 {"Hel","Hel","Hel","Hel","Hel"},
		{"Hel","Hel","Hel","Hel","Hel"},
		 {"Hel","Hel","Hel","Hel","Hel"},
		 {"Hel","Hel","Hel","Hel","Hel"},
		{"Hel","Hel","Hel","Hel","Hel"},
		},
		
			{
		 {"Hel","Hel","Hel","Hel","Hel"},
		{"Hel","Hel","Hel","Hel","Hel"},
		 {"Hel","Hel","Hel","Hel","Hel"},
		 {"Hel","Hel","Hel","Hel","Hel"},
		{"Hel","Hel","Hel","Hel","Hel"},
		}
		
	};
	
	kont=PjescaniSat(kont,SmjerKretanja::GoreDolje);
	IspisiKontejner(kont);*/
	
	
	vector<deque<deque<int>>> kont;
	
	int n;
	cout<<"Unesite dimenziju (x/y/z): ";
	for(;;) {
		cin>>n;
		if(n<0) cout<<"Dimenzija nije ispravna, unesite opet: ";
		else break;
	}
	kont.resize(n);
	for(int i=0;i<n;i++)
	  kont[i].resize(n);
	for(int i=0;i<n;i++)
	{
	  for(int j=0;j<n;j++)
	  {
	    kont[i][j].resize(n);
	  }
	}
	
	cout<<"Unesite elemente kontejnera: ";
	for(int i=0;i<n;i++)
	{
	  for(int j=0;j<n;j++)
	  {
	    for(int k=0;k<n;k++)
	      cin>>kont[i][j][k];
	  }
	}
	
	
	cout<<"Unesite smjer kretanja [0 - 5]: ";
	for(;;){
		cin>>n;
		if(n<0 || n>5) cout<<"Smjer nije ispravan, unesite opet: ";
		else break;
	}
	cout<<endl;
	try{
		kont=PjescaniSat(kont,(SmjerKretanja)n);
		IspisiKontejner(kont);
	} 
	catch(domain_error izuz) 
		{ 
			cout<<"Izuzetak: "<<izuz.what();
		}
	catch(length_error izuz) 
		{ 
			cout<<"Izuzetak: "<<izuz.what();
		}
	return 0;
}