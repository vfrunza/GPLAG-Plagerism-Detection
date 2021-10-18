/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/
#include<deque>
#include<iostream>
#include<vector>
#include<type_traits>
#include<algorithm>
#include<cmath>
#include<iomanip>
using std::cout;
using std::cin;
using std::vector;
using std::deque;
int SumaCifara(long long int n)
{
	int suma(0);
	if(n==0)
	return 0;
	while(n!=0)
	{
	suma+=n%10;
	n/=10;
	}
	return abs(suma);
}
int SumaDjelilaca(long long int n)
{
	if(n==0)
	return 0;
	int suma(0);
	if(n>0)
	{
		for(int i=1;i<=n;i++)
		{
			if(n%i==0)
			suma+=i;
		}
	}
	else
	{
		for(int i=-1;i>=n;i--)
		{
			if(n%i==0)
			suma+=(-i);
		}
	}
	return suma;
}
int BrojProstihFaktora(long long int n)
{
	int br(0);
	if(n==0)
	return 0;
	while(!(n==1 || n==-1))
	{
		for(int i=2;i>=0;i++)
		{
			if(n==1 || n==-1)
			break;
			if(n%i==0)
			{
				br++;
				n/=i;
				i=1;
			}
		}
	}
	return br;
}
int BrojSavrsenihDjelilaca(long long int n)
{
	if(n==0)
	return 0;
	int br(0);
	if(n>0)
	{
		for(int i=1;i<=n;i++)
		{
			if(n%i==0 && SumaDjelilaca(i)==2*i)
			br++;
		}
	}
	else
	{
		for(int i=-1;i>=n;i--)
		{
			if(n%i==0 && SumaDjelilaca(i)==-2*i)
			br++;
		}
	}
	return br;
}
template<typename NekiTip1, typename NekiTip2, typename NekiTip3, typename NekiTip4>
auto UvrnutiPresjek(NekiTip1 p1,NekiTip1 p2,NekiTip2 q1,NekiTip2 q2,NekiTip3 fun(NekiTip4))->vector<vector<typename std::remove_reference<decltype(*p1)>::type>>
{
	vector<vector<typename std::remove_reference<decltype(*p1)>::type>> a;
	NekiTip1 p=p1;
	NekiTip1 q=q1;
	while(p!=p2)
	{
		q=q1;
		while(q!=q2)
		{
			if(fun(*p)==fun(*q))
			{
				a.push_back({*p,*q,fun(*p)});
			}
			q++;
		}
		p++;
	}
	sort(a.begin(),a.end(),[] (vector<typename std::remove_reference<decltype(*p1)>::type> b,vector<typename std::remove_reference<decltype(*p1)>::type> c)
	{
		if(b[2]!=c[2])
		return b[2]<c[2];
		else if(b[0]!=c[0])
		return b[0]<c[0];
		return b[1]<c[1];
	});
	return a;
}
template<typename NekiTip1, typename NekiTip2>
auto UvrnutiPresjek(NekiTip1 p1,NekiTip1 p2,NekiTip2 q1,NekiTip2 q2)->vector<vector<typename std::remove_reference<decltype(*p1)>::type>>
{
	vector<vector<typename std::remove_reference<decltype(*p1)>::type>> a;
	NekiTip1 p=p1;
	NekiTip1 q=q1;
	while(p!=p2)
	{
		q=q1;
		while(q!=q2)
		{
			if(*p==*q)
			{
				a.push_back({*p,0,0});
			}
			q++;
		}
		p++;
	}
	sort(a.begin(),a.end(),[] (vector<typename std::remove_reference<decltype(*p1)>::type> b,vector<typename std::remove_reference<decltype(*p1)>::type> c)
	{
		return b[0]<c[0];
	});
	return a;
}
template<typename NekiTip1, typename NekiTip2, typename NekiTip3, typename NekiTip4>
auto UvrnutaRazlika(NekiTip1 p1,NekiTip1 p2,NekiTip2 q1,NekiTip2 q2,NekiTip3 fun(NekiTip4))->vector<vector<typename std::remove_reference<decltype(*p1)>::type>>
{
	int br(0);
	vector<vector<typename std::remove_reference<decltype(*p1)>::type>> a;
	NekiTip1 p=p1;
	NekiTip2 q=q1;
	while(p!=p2)
	{
		br=0;
		q=q1;
		while(q!=q2)
		{
			if(fun(*p)!=fun(*q))
			br++;
			q++;
		}
		if(br==(q2-q1))
		a.push_back({*p,fun(*p)});
		p++;
	}
	p=p1;
	q=q1;
	while(q!=q2)
	{
		br=0;
		p=p1;
		while(p!=p2)
		{
			if(fun(*q)!=fun(*p))
			br++;
			p++;
		}
		if(br==(p2-p1))
		a.push_back({*q,fun(*q)});
		q++;
	}
	sort(a.begin(),a.end(),[] (vector<typename std::remove_reference<decltype(*p1)>::type> b,vector<typename std::remove_reference<decltype(*p1)>::type> c)
	{
		if(b[0]!=c[0])
		return b[0]>c[0];
		return b[1]>c[1];
	});
	return a;
}
template<typename NekiTip1,typename NekiTip2>
auto UvrnutaRazlika(NekiTip1 p1,NekiTip1 p2,NekiTip2 q1,NekiTip2 q2)->vector<vector<typename std::remove_reference<decltype(*p1)>::type>>
{
	int br(0);
	vector<vector<typename std::remove_reference<decltype(*p1)>::type>> a;
	NekiTip1 p=p1;
	NekiTip2 q=q1;
	while(p!=p2)
	{
		br=0;
		q=q1;
		while(q!=q2)
		{
			if(*p!=*q)
			br++;
			q++;
		}
		if(br==(q2-q1))
		a.push_back({*p,0});
		p++;
	}
	p=p1;
	q=q1;
	while(q!=q2)
	{
		br=0;
		p=p1;
		while(p!=p2)
		{
			if(*q!=*p)
			br++;
			p++;
		}
		if(br==(p2-p1))
		a.push_back({*q,0});
		q++;
	}
	sort(a.begin(),a.end(),[] (vector<typename std::remove_reference<decltype(*p1)>::type> b,vector<typename std::remove_reference<decltype(*p1)>::type> c)
	{
		return b[0]>c[0];
	});
	return a;
}
int main ()
{
	int n;
	int m;
	cout<<"Unesite broj elemenata prvog kontejnera: ";
	cin>>n;
	deque<int> a(n);
	cout<<"Unesite elemente prvog kontejnera: ";
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		int br(0);
		for(int j=0;j<i;j++)
		{
			if(a[j]==a[i])
			br++;
		}
		if(br!=0)
		i--;
	}	
	cout<<"Unesite broj elemenata drugog kontejnera: ";
	cin>>m;
	deque<int> b(m);
	cout<<"Unesite elemente drugog kontejnera: ";
	for(int i=0;i<m;i++)
	{
		cin>>b[i];
		int br(0);
		for(int j=0;j<i;j++)
		{
			if(b[j]==b[i])
			br++;
		}
		if(br!=0)
		i--;
	}
	cout<<"Uvrnuti presjek kontejnera:\n";
	for(int i=0;i<UvrnutiPresjek(a.begin(),a.end(),b.begin(),b.end(),SumaCifara).size();i++)
	{
		for(int j=0;j<3;j++)
		{
			cout<<std::setw(6)<<UvrnutiPresjek(a.begin(),a.end(),b.begin(),b.end(),SumaCifara)[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<"Uvrnuta razlika kontejnera:\n";
	for(int i=0;i<UvrnutaRazlika(a.begin(),a.end(),b.begin(),b.end(),BrojProstihFaktora).size();i++)
	{
		for(int j=0;j<2;j++)
		{
			cout<<std::setw(6)<<UvrnutaRazlika(a.begin(),a.end(),b.begin(),b.end(),BrojProstihFaktora)[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<"Dovidjenja!";
	return 0;
}
