/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/

#include <iostream>
#include <vector>
#include <deque>
#include <stdexcept>
#include <algorithm>
#include <iomanip>
#include <type_traits>
using namespace std;

template<typename t1, typename t2>
auto UvrnutiPresjek(t1 p1, t1 k1, t2 p2, t2 k2) -> vector<vector<decltype(*p1+0)>>
{
	vector<vector<decltype(*p1+0)>> mat;
	t2 pom=p2;
		while(p1!=k1)
		{
			p2=pom;
			while(p2!=k2)
			{
				if(*p1==*p2)
				{
					vector<decltype(*p1+0)> v;
					v.push_back(*p1);
					v.push_back(0);
					v.push_back(0);
					mat.push_back(v);
				}
				p2++;
			}
			p1++;
		}
		for(int i=0; i<mat.size()-1; i++)
			for(int j=i+1; j<mat.size(); j++)
				if(mat[i][0]==mat[j][0])
				{
					for(int k=j; k<mat.size()-1; k++) 
						for(int l=0; l<3; l++) mat[k][l]=mat[k+1][l];
					mat.resize(mat.size()-1);
					j--;
				}
	    sort(mat.begin(), mat.end(), [](vector<decltype(*p1+0)> v1, vector<decltype(*p1+0)> v2) {return (v1[2]<v2[2] || v1[2]==v2[2]&&v1[0]<v2[0] || v1[2]==v2[2]&&v1[0]==v2[0]&&v1[1]<v2[1]);   });
		return mat;
}

template<typename t3, typename t2, typename t1, typename t4>
vector<vector<t3>> UvrnutiPresjek(t1 p1, t1 k1, t2 p2, t2 k2, t3 f(t4))
{
	vector<vector<t3>> mat;
	t2 pom=p2;
	while(p1!=k1)
	{
		p2=pom;
		while(p2!=k2)
		{
			if(f(*p1)==f(*p2))
			{
				vector<t3> v;
				v.push_back(*p1);
				v.push_back(*p2);
				v.push_back(f(*p1));
				mat.push_back(v);
			}
			p2++;
		}
		p1++;
	}
	for(int i=0; i<mat.size()-1; i++)
	{
		for(int j=i+1; j<mat.size(); j++)
		{
			if(mat[i][0]==mat[j][0])
				if(mat[i][1]==mat[j][1])
					if(mat[i][2]==mat[j][2])
						{
							for(int k=j; k<mat.size()-1; k++) 
								for(int l=0; l<3; l++) mat[k][l]=mat[k+1][l];
							mat.resize(mat.size()-1);
							j--;
						}
		}
	}
	sort(mat.begin(), mat.end(), [](vector<t3> v1, vector<t3> v2) {return (v1[2]<v2[2] || v1[2]==v2[2]&&v1[0]<v2[0] || v1[2]==v2[2]&&v1[0]==v2[0]&&v1[1]<v2[1]);   });
	return mat;
}

template<typename t1, typename t2>
auto UvrnutaRazlika(t1 p1, t1 k1, t2 p2, t2 k2) -> vector<vector<decltype(*p1+0)>>
{
	vector<vector<decltype(*p1+0)>> mat;
	t2 pd=p2;
    t1 pp=p1;
    while(p1!=k1)
    {
    	bool ima=false;
    	p2=pd;
    	while(p2!=k2)
    	{
    		if(*p1==*p2) ima=true;
    		p2++;
    	}
    	if(!ima)
    	{
    		vector<decltype(*p1+0)> v;
    		v.push_back(*p1);
    		v.push_back(0);
    		mat.push_back(v);
    	}
    	p1++;
    }
    p2=pd;
    p1=pp;
    while(p2!=k2)
    {
    	bool ima=false;
    	p1=pp;
    	while(p1!=k1)
    	{
    		if(*p2==*p1) ima=true;
    		p1++;
    	}
    	if(!ima)
    	{
    		vector<decltype(*p1+0)> v;
    		v.push_back(*p2);
    		v.push_back(0);
    		mat.push_back(v);
    	}
    	p2++;
    }
    sort(mat.begin(), mat.end(), [](vector<decltype(*p1+0)> v1, vector<decltype(*p1+0)> v2) {return (v1[0]>v2[0] || v1[0]==v2[0]&&v1[1]>v2[1]);});
	return mat;
}

template<typename t3, typename t2, typename t1, typename t4>
vector<vector<t3>> UvrnutaRazlika(t1 p1, t1 k1, t2 p2, t2 k2, t3 f(t4))
{
	vector<vector<t3>> mat;
	t2 pd=p2;
    t1 pp=p1;
    while(p1!=k1)
    {
    	bool ima=false;
    	p2=pd;
    	while(p2!=k2)
    	{
    		if(f(*p1)==f(*p2)) ima=true;
    		p2++;
    	}
    	if(!ima)
    	{
    		vector<t3> v;
    		v.push_back(*p1);
    		v.push_back(f(*p1));
    		mat.push_back(v);
    	}
    	p1++;
    }
    p2=pd;
    p1=pp;
    while(p2!=k2)
    {
    	bool ima=false;
    	p1=pp;
    	while(p1!=k1)
    	{
    		if(f(*p2)==f(*p1)) ima=true;
    		p1++;
    	}
    	if(!ima)
    	{
    		vector<t3> v;
    		v.push_back(*p2);
    		v.push_back(f(*p2));
    		mat.push_back(v);
    	}
    	p2++;
    }
    sort(mat.begin(), mat.end(), [](vector<t3> v1, vector<t3> v2) {return (v1[0]>v2[0] || v1[0]==v2[0]&&v1[1]>v2[1]);});
	
	return mat;
}

bool prost(long long int n)
{
	for(int i=2; i<n; i++) if(n%i==0) return false;
	return true;
}

int BrojProstihFaktora(long long int n)
{
	int br=0;
	for(int i=2; i<=n; i++)
	{
		if(n==1)break;
		if(n%i==0)
		{
			while(n%i==0)
			{
				br++;
				n/=i;
			}
		}
	}
	return br;
}

int SumaDjelilaca(long long int n)
{
	int suma=0;
	for(int i=1; i<=n; i++)
		if(n%i==0) suma+=i;
	return suma;
}

int SumaCifara(long long int n)
{
	int suma=0;
	while(n!=0)
	{
		suma+=n%10;
		n/=10;
	}
	return suma;
}

bool savrsen(long long int n)
{
	long long int suma=0;
	for(int i=1;i<n; i++) if(n%i==0) suma+=i;
	return n==suma;
}

int BrojSavrsenihDjelilaca(long long int n)
{
	int br=0;
	for(int i=1; i<=n; i++) if(n%i==0 && savrsen(i)) br++;
	return br;
}

int main ()
{
	deque<int> d1, d2;
	int n;
	cout<<"Unesite broj elemenata prvog kontejnera: ";
	cin>>n;
	cout<<"Unesite elemente prvog kontejnera: ";
	while(1)
	{
		int a;
		cin>>a;
		bool ima=false;
		for(int i=0; i<d1.size(); i++) if(d1[i]==a) {ima=true;}
		if(ima) continue;
		d1.push_back(a);
		if(d1.size()==n) break;
	}
	cout<<"Unesite broj elemenata drugog kontejnera: ";
	cin>>n;
	cout<<"Unesite elemente drugog kontejnera: ";
	while(1)
	{
		int a;
		cin>>a;
		bool ima=false;
		for(int i=0; i<d2.size(); i++) if(d2[i]==a) {ima=true;}
		if(ima) continue;
		d2.push_back(a);
		if(d2.size()==n) break;
	}
	cout<<"Uvrnuti presjek kontejnera:"<<endl;
	vector<vector<int>> v1=UvrnutiPresjek(d1.begin(), d1.end(), d2.begin(), d2.end(),  SumaCifara);
	for(int i=0; i<v1.size(); i++) 
	{
		for(int j=0; j<v1[i].size(); j++)
		{
			cout<<setw(6)<<right<<v1[i][j]<<" ";
		}
		cout<<endl;
	} 
	cout<<"Uvrnuta razlika kontejnera:"<<endl;
	vector<vector<int>> v=UvrnutaRazlika(d1.begin(), d1.end(), d2.begin(), d2.end(), BrojProstihFaktora);
	for(int i=0; i<v.size(); i++) 
	{
		for(int j=0; j<v[i].size(); j++)
		{
			cout<<setw(6)<<right<<v[i][j]<<" ";
		}
		cout<<endl;
	} 
	cout<<"Dovidjenja!"; 
	return 0;
}