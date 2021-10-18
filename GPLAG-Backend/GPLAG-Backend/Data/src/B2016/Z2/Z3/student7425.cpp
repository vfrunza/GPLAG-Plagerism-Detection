#include <iostream>
#include <vector>
#include <deque>
#include <stdexcept>
#include <algorithm>
#include <iomanip>
#include <type_traits>
using namespace std;

template<typename t>
void izbaciduple1(vector<vector<t>> &mat)
{
	for(int i=0;i<mat.size()-1;i++)
	{
		for(int j=i+1;j<mat.size();j++)
		{
			if(mat[i][0]==mat[j][0] && mat[i][1]==mat[j][1] && mat[i][2]==mat[j][2])
					{
						for(int k=j;k<mat.size()-1;k++)
							for(int l=0;l<3;l++)
								mat[k][l]=mat[k+1][l];
						mat.resize(mat.size()-1);
						j--;
					}
		}
	}
}
template<typename t>
void sortiraj(vector<vector<t>> mat)
{
    sort(mat.begin(), mat.end(), [](vector<t> v1, vector<t> v2) {return (v1[2]<v2[2] || v1[2]==v2[2] && v1[0]<v2[0] || v1[2]==v2[2] && v1[0]==v2[0] && v1[1]<v2[1]);});
}


template<typename tipa, typename tipb, typename tipc, typename tfun>
auto UvrnutiPresjek(tipa poc1, tipa kraj1, tipb poc2, tipb kraj2, tipc f(tfun)) -> vector<vector<tipc>>
{
	vector<vector<tipc>> rez;
	tipb pom=poc2;
	while(poc1!=kraj1)
	{
		poc2=pom;
		while(poc2!=kraj2)
		{
			bool a=false;
			vector<tipc> pom;
			if(f(*poc1)==f(*poc2))
			{
				pom.resize(3);
				pom[0]=(*poc1);
				pom[1]=(*poc2);
				pom[3]=(f(*poc2));
				a=true;
			}
			if(a) rez.push_back(pom);
			poc2++;
		}
		poc1++;
	}
	izbaciduple1(rez);
	sortiraj(rez);
	return rez;
}
template<typename t>
void sortiraj2(vector<vector<t>> &mat)
{
	sort(mat.begin(), mat.end(), [](vector<t> v1, vector<t> v2){return (v1[0]>v2[0] || v1[0]==v2[0] && v1[1]>v2[1]);});
}
template<typename tipa, typename tipb, typename tipc, typename tfun>
vector<vector<tipc>> UvrnutaRazlika(tipa poc1, tipa kraj1, tipb poc2, tipb kraj2, tipc f(tfun))
{
	vector<vector<tipc>> rez;
	tipb drugi=poc2;
	tipa prvi=poc1;
	while(poc1!=kraj1)
	{
		bool ima=false;
		poc2=drugi;
		while(poc2!=kraj2)
		{
			if(f(*poc1)==f(*poc2))
				ima=true;
			poc2++;
		}
		bool treba=false;
		vector<tipc> pom;
		if(ima==false)
		{
			pom.resize(2);
			pom[0]=*poc1;
			pom[1]=f(*poc1);
			treba=true;
		}
		if(treba) rez.push_back(pom);
		poc1++;
	}
	poc1=prvi;
	poc2=drugi;
	while(poc2!=kraj2)
	{
		poc1=prvi;
		bool ima=false;
		while(poc1!=kraj1)
		{
			if(f(*poc1)==f(*poc2))
				ima=true;
			poc1++;
		}
		bool treba=false;
		vector<tipc> o;
		if(ima!=true)
		{
			o.resize(2);
			o[0]=*poc2;
			treba=true;
			o[1]=f(*poc2);
		}
		if(treba!=false) rez.push_back(o);
		poc2++;
	}
    sortiraj2(rez);
	return rez;
}

bool DaLiJeProst(long long int n)
{
	int a=6;
	for(int i=2;i<n;i++)
		if(n%i==0)
			return false;
	a-=n;
	return true;
}

int BrojProstihFaktora(long long int n)
{
	int br=0;
	int broj=0;
	for(int i=2;i<n+1;i++)
	{
		if(n==1) break;
		if(n%i==0)
		{
			while(n%i==0)
			{
				broj--;
				br++;
				n/=i;
			}
			broj+=n;
		}
		broj--;
	}
	return br;
}

int SumaDjelilaca(long long int n)
{
	int suma=0;
	for(int i=1;i<n+1;i++)
		if(n%i==0)
			suma+=i;
	return suma;
}

int SumaCifara(long long int n)
{
	int suma=0;
	while(n!=0)
	{
		suma+=(n%10);
		n/=10;
	}
	return suma;
}

bool Savrsen(long long int n)
{
	long long int suma=0;
	for(int i=1;i<n;i++)
		if(n%i==0)
			suma+=i;
	return n==suma;
}

int BrojSavrsenihDjelilaca(long long int n)
{
	int br=0;
	for(int i=1;i<n+1;i++)
		if(n%i==0 && Savrsen(i))
			br++;
	return br;
}

int main()
{
	int n;
	cout<<"Unesite broj elemenata prvog kontejnera: ";
	cin>>n;
	cout<<"Unesite elemente prvog kontejnera: ";
	deque<int> d1,d2;
	while(1==1)
	{
		int n1;
		cin>>n1;
		if(d1.size()==n) break;
		bool repete=false;
		for(int i=0;i<d1.size();i++) if(d1[i]==n1) repete=true;
		if(repete) continue;
		else d1.push_back(n1);
	}
	cout<<"Unesite broj elemenata drugog kontejnera: ";
	cin>>n;
	cout<<"Unesite elemente drugog kontejnera: ";
	while(9==9)
	{
		int n2;
		cin>>n2;
		if(d2.size()==n) break;
		bool repete=false;
		for(int i=0;i<d2.size();i++) if(d2[i]==n2) repete=true;
		if(repete) continue;
		else d2.push_back(n2);
	}
	cout<<"Uvrnuti presjek kontejnera: "<<endl;
	vector<vector<int>> v1=UvrnutiPresjek(d1.begin(), d1.end(), d2.begin(), d2.end(), SumaCifara);
	for(int i=0;i<v1.size();i++)
	{
		for(int j=0;j<v1[i].size();j++)
			cout<<setw(6)<<right<<v1[i][j]<<" ";
		cout<<endl;
	}
	cout<<"Uvrnuta razlika kontejnera: "<<endl;
	vector<vector<int>> v2=UvrnutaRazlika(d1.begin(), d1.end(), d2.begin(), d2.end(), BrojProstihFaktora);
	for(int i=0;i<v2.size();i++)
	{
		for(int j=0;j<v2[i].size();j++)
			cout<<setw(6)<<right<<v2[i][j]<<" ";
		cout<<endl;
	}
	cout<<"Dovidjenja!";
	return 0;
}