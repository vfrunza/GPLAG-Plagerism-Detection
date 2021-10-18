/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/
#include <iostream>
#include <vector>
#include <iomanip>
#include <deque>
#include <algorithm>

using namespace std;

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

int SumaDjelilaca(long long int n)
{	int suma=0;
	for(int i=1;i<=n/2;i++)
	{
		if(n%i==0) suma+=i;
	}
	return suma+=n;
}

bool JelProst(int n)
{
	for(int i=2;i<n;i++)
		if(n%i==0) return false;

	return true;
}

int BrojProstihFaktora(long long int n)
{
	int br=0;
	int a=1,b=1;
	    
	    if(JelProst(n)) return 1;
	    
		for(int i=1;i<n;i++)
		{
			for(int j=1;j<n;j++)
			{
				if(i*j==n)
				{
					a=i;
					b=j;
					break;
				}
			}
			if(a*b==n) break;
		}
		
		for(int i=2;i<=a;i++)
		{
			if(JelProst(i) && a%i==0)
			{
				a/=i;
				br++;
				i=1;
			}
		}
		
		for(int i=2;i<=b;i++)
		{
			if(JelProst(i) && b%i==0)
			{
				b/=i;
				br++;
				i=1;
			}
		}
		
	
	return br;
}

bool JelSavrsen(int n)
{   
	int suma=0;
	
	//if(n==2) return true;
	
	for(int i=1;i<n;i++)
		if(n%i==0) suma+=i;
	
	//cout<<n<<" "<<suma<<endl;
	if(n==suma) return true;
	return false;
}

int BrojSavrsenihDjelilaca(long long int n)
{   
	int br=0;
	for(int i=2;i<=n;i++)
	{
		if(n%i==0 && JelSavrsen(i)) br++;
	}
	return br;
}

template<typename t>
void Ispis(vector<vector<t>> mat)
{
	for(int i=0;i<mat.size();i++)
	{
		for(int j=0;j<mat[i].size();j++)
		{
			cout<<setw(6)<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
}

template <typename t1,typename t2,typename t3,typename t>
auto UvrnutiPresjek(t1 p1,t1 p2,t2 p3,t2 p4,t3 f(t))->vector<vector<decltype(*p1+0)>>
{
	

	vector<vector<decltype(p1[0]+0)>> mat;
	
	for(t1 i=p1;i!=p2;i++)
	{	
		vector<decltype(p1[0]+0)>v(3);
		for(t2 j=p3;j!=p4;j++)
		{
			if(f(*i)==f(*j))
			{
			   bool postoji=false;
			   for(int k=0;k<mat.size();k++)
			      if(*i==mat[k][0] && *j==mat[k][1])
			      postoji=true;
			      if(!postoji){
		 				v[0]=*i;
						v[1]=*j;
						v[2]=f(*i);
						mat.push_back(v);
			      }
			}
		}
	}
	
	sort(mat.begin(),mat.end(),[]( vector<decltype(p1[0]+0)> a, vector<decltype(*p1+0)> b)
							{
								return (a[2]<b[2] || (a[2]==b[2] && a[0]<b[0] ) || (a[2]==b[2] && a[0]==b[0] && a[1]<b[1]));
							}
		);
		
	

	
	return mat;
}

template <typename t1,typename t2,typename t3,typename t>
auto UvrnutaRazlika(t1 p1,t1 p2,t2 p3,t2 p4,t3 f(t))->vector<vector<decltype(p1[0]+0)>>
{
	

	vector<vector<decltype(p1[0]+0)>> mat;

	decltype(p1[0]+0) a;

	for(auto i=p1;i!=p2;i++)
	{	vector<decltype(p1[0]+0)> v(2); bool ima=false;
	
		for(auto j=p3;j!=p4;j++)
		{
			a=f(*i);
			decltype(p1[0]+0) b=f(*j);
			if(a==b) ima=true;
		}
		if(ima==false)
		{
			v[0]=*i;
			v[1]=a;
			mat.push_back(v);
		}
		
	}
	
		for(auto i=p3;i!=p4;i++)
		{	
			vector<decltype(p1[0]+0)> v(2); bool ima=false;
			for(auto j=p1;j!=p2;j++)
			{
					a=f(*i);
					decltype(p1[0]+0)  b=f(*j);
			        if(a==b) ima=true;
			}
			if(ima==false)
			{
				v[0]=*i;
				v[1]=a;
				mat.push_back(v);
			}
		}
		
		
		sort(mat.begin(),mat.end(),[]( vector<decltype(p1[0]+0)> a, vector<decltype(*p1+0)> b)
							{
								return (a[0]>b[0] || (a[0]==b[0] && a[1]>b[1]));
							}
			);
	

	return mat;
}

template <typename t1,typename t2>
auto UvrnutiPresjek(t1 p1,t1 p2,t2 p3,t2 p4)->vector<vector<decltype(*p1+0)>>
{
	
	vector<vector<decltype(p1[0]+0)>> mat;
	
	for(t1 i=p1;i!=p2;i++)
	{
		vector<decltype(p1[0]+0)>v(3);
		for(t2 j=p3;j!=p4;j++)
		{
			if(*i==*j)
			{
			   bool postoji=false;
			   for(int k=0;k<mat.size();k++)
			      if(*i==mat[k][0])
			      	postoji=true;
			      if(!postoji){
		 				v[0]=*i;
						v[1]=0;
						v[2]=0;
						mat.push_back(v);
			      }
			}
		}
	}
	
	sort(mat.begin(),mat.end(),[]( vector<decltype(p1[0]+0)> a, vector<decltype(*p1+0)> b)
							{
								return (a[0]<b[0]);
							}
		);
	return mat;
}

template <typename t1,typename t2>
auto UvrnutaRazlika(t1 p1,t1 p2,t2 p3,t2 p4)->vector<vector<decltype(p1[0]+0)>>
{

		vector<vector<decltype(p1[0]+0)>> mat;

	decltype(p1[0]+0) a;

	for(auto i=p1;i!=p2;i++)
	{	vector<decltype(p1[0]+0)> v(2); bool ima=false;
	
		for(auto j=p3;j!=p4;j++)
		{
			a=*i;
			decltype(p1[0]+0) b=*j;
			if(a==b) ima=true;
		}
		if(ima==false)
		{
			v[0]=*i;
			v[1]=0;
			mat.push_back(v);
		}
		
	}
	
		for(auto i=p3;i!=p4;i++)
		{	
			vector<decltype(p1[0]+0)> v(2); bool ima=false;
			for(auto j=p1;j!=p2;j++)
			{
					a=*i;
					decltype(p1[0]+0)  b=*j;
			        if(a==b) ima=true;
			}
			if(ima==false)
			{
				v[0]=*i;
				v[1]=0;
				mat.push_back(v);
			}
		}
		

		sort(mat.begin(),mat.end(),[]( vector<decltype(p1[0]+0)> a, vector<decltype(*p1+0)> b)
							{
								return (a[0]>b[0]);
							}
			);
	

	return mat;
}

int main ()
{
	cout<<"Unesite broj elemenata prvog kontejnera: ";
	int n;
	cin>>n;
	cout<<"Unesite elemente prvog kontejnera: ";

	deque<int> d1;

	for(int i=0;i<n;i++)
	{   
		int a; cin>>a; bool postoji=false;
		for(int j=0;j<i;j++) 
			if(a==d1[j])postoji=true;
			
		if(postoji==false) d1.push_back(a);
		else i--;
		
	}

	cout<<"Unesite broj elemenata drugog kontejnera: ";
	cin>>n;
	cout<<"Unesite elemente drugog kontejnera: ";

	deque<int> d2;

	for(int i=0;i<n;i++)
	{   
		int a; cin>>a; bool postoji=false;
		for(int j=0;j<i;j++) 
			if(a==d2[j]) postoji=true;
			
		if(postoji==false) d2.push_back(a);
		else i--;
	}
	
	vector<vector<int>> mat=UvrnutiPresjek(d1.begin(),d1.end(),d2.begin(),d2.end(),SumaCifara);
  	cout<<"Uvrnuti presjek kontejnera:"<<endl;
  	Ispis(mat);
  	
  	cout<<"Uvrnuta razlika kontejnera:"<<endl;
    vector<vector<int>> mat2=UvrnutaRazlika(d1.begin(),d1.end(),d2.begin(),d2.end(),BrojProstihFaktora);
  	Ispis(mat2);
	
	cout<<"Dovidjenja!";
	
	
	return 0;
}