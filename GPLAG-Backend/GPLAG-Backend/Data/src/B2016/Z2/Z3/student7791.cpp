#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <cmath>
#include <iomanip>

using std::cout;
using std::cin;
using std::vector;
using std::deque;
bool DaLiJeSavrsen(long long int n)
{
	long long int suma(0);
	for(long long int i=1;i<n;i++)
	{
		if(n%i==0)
		suma+=i;
	}
	if(suma==n)
	return true;
	return false;
}
bool DaLiJeProst(long long int n)
{
	if(n<=1) return false;
	if(n<100000)
	{
		for(long long int i=2;i<n;i++)
		{
			if(n%i==0)
			{
				return false;
				break;
			}
		}
	}
	else
	for(long long int i=2;i<sqrt(n);i++)
	{
	     if(n%i==0)	
	     {
	     	return false;
	     	break;
	     }
	}
return true;
}
int SumaDjelilaca(long long int n)
{
	int suma(0);
	if(n<0)
	n*=-1;
	for(long long int i=1;i<=n;i++)
	{
		if(n%i==0)
		suma+=i;
	}
	return suma;
}
int BrojProstihFaktora(long long int n)
{
	int broj(0);
	if(n<0)
	n*=-1;
	if(n==0 || n==1)
	return broj;
	while(n>1)
	{
		for(int i=2;i<=n;i++)
		{
			if(n%i==0)
			{
				bool l(DaLiJeProst(i));
				if(l)
				{
				n/=i;
				broj++;
				break;
				}
			}
		}
	}
	return broj;
}
int SumaCifara(long long int n)
{
	if(n<0)
	n*=-1;
	if(n==0)
	return 0;
	int suma(0);
	while(n>0)
	{
	int pom;
	pom=n%10;
	suma+=pom;
	n/=10;
	}
	return suma;
}
int BrojSavrsenihDjelilaca(long long int n)
{
	int broj(0);
	for(int i=1;i<=n;i++)
	{
		if(n%i==0)
		{
		bool k(DaLiJeSavrsen(i));
		if(k)
		broj++;
		}
	}
	return broj;
}
template <typename IterTip1, typename IterTip2, typename proiz1, typename proiz2>
auto UvrnutiPresjek(IterTip1 p1,IterTip1 p2,IterTip2 p3,IterTip2 p4, proiz1 f(proiz2))->vector<vector<decltype(*p1+*p1)>>
{
	vector<vector<decltype(*p1+*p1)>> mat;
	IterTip2 p3prim;
	p3prim=p3;
	while(p1!=p2)
	{
		p3=p3prim;
		while(p3!=p4)
		{
			auto pom1=*p1;
			auto pom2=*p3;
			if(f(pom1)==f(pom2))
		    {
		  	vector<decltype(*p1+*p1)> vek(2);
		  	vek[0]=*p1;
		  	vek[1]=*p3;
		  	int brojac(0);
		  	for(int i=0;i<mat.size();i++)
		  	{
		  		if(vek!=mat.at(i))
		  		brojac++;
		  	}
		  	if(brojac==mat.size())
		  	mat.push_back(vek);
		    }
		   p3++;
		}
	p1++;
	}
	vector<vector<decltype(*p1+*p1)>> mat1(mat.size(),std::vector<decltype(*p1+*p1)>(3));
	for(int i=0;i<mat1.size();i++)
	{
		for(int j=0;j<mat1[i].size();j++)
		{
			if(j<2)
			mat1[i][j]=mat[i][j];
			if(j==2)
			mat1[i][j]=f(mat[i][j-1]);
		}
	}
	std::sort(std::begin(mat1),std::end(mat1),[](vector<decltype(*p1+*p1)> pomvek1,vector<decltype(*p1+*p1)> pomvek2)->bool { if(pomvek1[2]<pomvek2[2]) return true; if(pomvek1[2]>pomvek2[2]) return false; if(pomvek1[0]<pomvek2[0]) return true; if(pomvek1[0]>pomvek2[0]) return false; if(pomvek1[1]<pomvek2[1]) return true; return false;});
	return mat1;
}
template <typename TIP>
TIP fja(TIP x)
{
	return x;
}
template <typename IterTip1,typename IterTip2>
auto UvrnutiPresjek(IterTip1 p1,IterTip1 p2,IterTip2 p3,IterTip2 p4)->vector<vector<decltype(*p1+*p1)>>
{
	vector<vector<decltype(*p1+*p1)>> mat;
	mat=UvrnutiPresjek(p1,p2,p3,p4,fja<decltype(*p1+*p1)>);
	for(int i=0;i<mat.size();i++)
	{
		mat[i][1]=0;
		mat[i][2]=0;
	}
	return mat;
}
template <typename IterTip1, typename IterTip2, typename proiz1, typename proiz2>
auto UvrnutaRazlika(IterTip1 p1,IterTip1 p2,IterTip2 p3,IterTip2 p4, proiz1 f(proiz2))->vector<vector<decltype(*p1+*p1)>>
{
   vector<vector<decltype(*p1+*p1)>> mat;
   for(IterTip1 i=p1;i!=p2;i++)
   {
   	vector<decltype(*p1+*p1)> vek1;
   	for(IterTip2 j=p3;j!=p4;j++)
   	{
   		auto pom1=*i;
   		auto pom2=*j;
   		if(f(pom1)==f(pom2))
   		{
   			j=p4;
   			break;
   		}
   		if(f(pom1)!=f(pom2) && j==p4-1)
   		{
   		vek1.push_back(pom1);
   		}
   	}
   	if(vek1.size()!=0)
   	{
   	int brojac(0);
	for(int i=0;i<mat.size();i++)
	{
	if(vek1!=mat.at(i))
	brojac++;
	}
	if(brojac==mat.size())
   	mat.push_back(vek1);
   	}
   }
   for(IterTip2 i=p3;i!=p4;i++)
   {
   	vector<decltype(*p1+*p1)> vek2;
   	for(IterTip1 j=p1;j!=p2;j++)
   	{
   		auto pom1=*i;
   		auto pom2=*j;
   		if(f(pom1)==f(pom2))
   		{
   			j=p2;
   			break;
   		}
   		if(f(pom1)!=f(pom2) && j==p2-1)
   		{
   			vek2.push_back(pom1);
   		}
   	}
   	if(vek2.size()!=0)
   	{
   			int brojac(0);
		  	for(int i=0;i<mat.size();i++)
		  	{
		  		if(vek2!=mat.at(i))
		  		brojac++;
		  	}
		  	if(brojac==mat.size())
   	     	mat.push_back(vek2);
   	}
  }
  vector<vector<decltype(*p1+*p1)>> mat1(mat.size(),std::vector<decltype(*p1+*p1)>(2));
  for(int i=0;i<mat1.size();i++)
  {
  	for(int j=0;j<mat1[i].size();j++)
  	{
  		if(j==0)
  		mat1[i][j]=mat[i][j];
  		if(j==1)
  		mat1[i][j]=f(mat[i][j-1]);
  	}
  }
 std::sort(std::begin(mat1),std::end(mat1),[](vector<decltype(*p1+*p1)> pomvek1,vector<decltype(*p1+*p1)> pomvek2)->bool { if(pomvek1[0]<pomvek2[0]) return false; if(pomvek1[0]>pomvek2[0]) return true; if(pomvek1[1]>pomvek2[1]) return true;  return false;});
return mat1;
}
template <typename IterTip1,typename IterTip2>
auto UvrnutaRazlika(IterTip1 p1,IterTip1 p2,IterTip2 p3,IterTip2 p4)->vector<vector<decltype(*p1+*p1)>>
{
	vector<vector<decltype(*p1+*p1)>> mat;
	mat=UvrnutaRazlika(p1,p2,p3,p4,fja<decltype(*p1+*p1)>);
	for(int i=0;i<mat.size();i++)
	mat[i][1]=0;
	return mat;
}
int main ()
{
	cout<<"Unesite broj elemenata prvog kontejnera: ";
	int br1;
	cin>>br1;
	cout<<"Unesite elemente prvog kontejnera: ";
	deque<int> dek1;
	for(int i=0;i<br1;i++)
	{
	int broj;
	bool ponavlja(false);
	cin>>broj;
	if(i==0)
	dek1.push_back(broj);
	else
	for(int j=0;j<dek1.size();j++)
	{
		if(dek1[j]==broj)
		ponavlja=true;
	}
	if(!ponavlja)
	dek1.push_back(broj);
	else
	br1++;
	}
	cout<<"Unesite broj elemenata drugog kontejnera: ";
	int br2;
	cin>>br2;
	cout<<"Unesite elemente drugog kontejnera: ";
	deque<int> dek2;
	for(int k=0;k<br2;k++)
	{
	int broj2;
	bool ponavlja2(false);
	cin>>broj2;
	if(k==0)
	dek2.push_back(broj2);
	else
	for(int j=0;j<dek2.size();j++)
	{
		if(dek2[j]==broj2)
		ponavlja2=true;
	}
	if(!ponavlja2)
	dek2.push_back(broj2);
	else
	br2++;
	}
	auto mat=UvrnutiPresjek(dek1.begin(),dek1.end(),dek2.begin(),dek2.end(),SumaCifara);
	cout<<"Uvrnuti presjek kontejnera: "<<std::endl;
	if(mat.size()!=0)
	for(int i=0;i<mat.size();i++)
	{
		for(int j=0;j<mat[i].size();j++)
		{
			cout<<std::setw(6)<<mat[i][j]<<" ";
			
		}
		cout<<std::endl;
	}
	auto mat2=UvrnutaRazlika(dek1.begin(),dek1.end(),dek2.begin(),dek2.end(),BrojProstihFaktora);
	cout<<"Uvrnuta razlika kontejnera: "<<std::endl;
	if(mat2.size()!=0)
	for(int i=0;i<mat2.size();i++)
	{
		for(int j=0;j<mat2[i].size();j++)
		{
			cout<<std::setw(6)<<mat2[i][j]<<" ";
		}
		cout<<std::endl;
	}
	cout<<"Dovidjenja!";
	return 0;
}