/*B 2017/2018, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.	
*/
#include <iostream>
#include <vector>
#include <deque>

using namespace std;

enum Smjer{Rastuci,Opadajuci};

bool JelStepenDvojke(int n)
{   
	//if(n<0) return false;
	int a=1;
	while(a<n)
	{
		a*=2;
	}
	return a==n;
}


deque<vector<int>> MaksimalniPodnizoviStepenaDvojke(vector<int> v,Smjer s)
{
	deque<vector<int>> d;
	vector<int> temp;
		
		for(int i=0;i<v.size();i++)
		{   
			
		     if(s==Rastuci)
		     {
		     	if(i<v.size()-1)
		     	{
			     	if(v.at(i)<v.at(i+1) && JelStepenDvojke(v.at(i)))
			     		temp.push_back(v.at(i));
			     	else if(v.at(i)>v.at(i+1) && JelStepenDvojke(v.at(i)) && temp.size()!=0) {temp.push_back(v.at(i)); d.push_back(temp);temp.resize(0);}
			     	else if(!JelStepenDvojke(v.at(i)) && temp.size()!=0){d.push_back(temp);temp.resize(0);}
		     	}
			   else 
			   {
			   		if(JelStepenDvojke(v.at(i)) && v.at(i)>v.at(i-1) && temp.size()!=0)
			   		{
							temp.push_back(v.at(i));
							d.push_back(temp);
							temp.resize(0);
			   		}
			   		else if(!JelStepenDvojke(v.at(i)) && temp.size()>1){d.push_back(temp);temp.resize(0);}
			   }
		     }
		     else if(s==Opadajuci)
		     {
		     	if(i<v.size()-1)
		     	{
			     	if(v.at(i)>v.at(i+1) && JelStepenDvojke(v.at(i)))
			     		temp.push_back(v.at(i));
			     	else if(v.at(i)<v.at(i+1) && JelStepenDvojke(v.at(i)) && temp.size()!=0) {temp.push_back(v.at(i)); d.push_back(temp);temp.resize(0);}
			     	else if(!JelStepenDvojke(v.at(i)) && temp.size()!=0){d.push_back(temp);temp.resize(0);}
		     	}
			   else 
			   {
			   		if(JelStepenDvojke(v.at(i)) && v.at(i)<v.at(i-1) && temp.size()!=0)
			   		{
							temp.push_back(v.at(i));
							d.push_back(temp);
							temp.resize(0);
			   		}
			   		else if(!JelStepenDvojke(v.at(i)) && temp.size()>1){d.push_back(temp);temp.resize(0);}
			   }
		     }
		     
		     
		}
	return d;			
}


int main ()
{
	

	int a;
	int M;
	vector<int>v;

	cout<<"Unesite broj elemenata vektora: ";
	cin>>a;
	
	v.resize(a);
	
	cout<<"Unesite elemente vektora: ";
	for(int i=0; i<v.size(); i++) {
		cin>>v.at(i);
	}
	
		cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
				while(1) {
					cin>>M;
					if(M!=1 && M!=2) {cout<<"Neispravan unos!";
					cout<<" Unesite ponovo: "; }
					else break;
				}
				
	if(M==1) {	
		
deque<vector<int>> 	v1=MaksimalniPodnizoviStepenaDvojke(v,Rastuci);

	cout<<"Maksimalni rastuci podnizovi: "<<endl;
	
	
	for(int i=0; i<v1.size(); i++) {
		for(int j=0;j<v1.at(i).size();j++)
			 cout<<v1.at(i).at(j)<<" ";
			cout<<endl;
		}

	}
	else if(M==2) {
			
			
	deque<vector<int>> 	v1=MaksimalniPodnizoviStepenaDvojke(v,Opadajuci);
	
	cout<<"Maksimalni opadajuci podnizovi: "<<endl;
	
	for(int i=0; i<v1.size(); i++) {
		for(int j=0;j<v1.at(i).size();j++)
			 cout<<v1.at(i).at(j)<<" ";
			cout<<endl;
		}
	} 
	
return 0;
}
	/*
	vector<int> v{1,2,4,2,1};
	//(int i=0;i<v.size();i++)
	//	cout<<v[i]<<"->"<<JelStepenDvojke(v[i])<<endl;
	
	deque<vector<int>> d=MaksimalniPodnizoviStepenaDvojke(v,Opadajuci);
	
	for(int i=0;i<d.size();i++)
	{
		for(int j=0;j<d[i].size();j++)
		{
			cout<<d[i][j]<<" ";
		}
		cout<<endl;
	}
	
	return 0;
	}


*/