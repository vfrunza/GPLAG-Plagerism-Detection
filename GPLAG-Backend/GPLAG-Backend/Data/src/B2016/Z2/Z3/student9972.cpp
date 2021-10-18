#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <iterator>
#include <iomanip>
using namespace std;
template <typename t, typename t1>
auto UvrnutiPresjek(t poc1, t kraj1, t1 poc2, t1 kraj2)->vector<vector<decltype(*poc1+0)> > 
{

	vector<vector<decltype(*poc1+0)> > mat;
	int br=0,red=0;
	bool isti=false;
	for(auto i=poc1;i<kraj1;i++){
		isti=false;
	for(auto j=poc2;j<kraj2;j++)
		if(*i==*j){isti=true; if(isti){br++;}
		isti=false;
			}
		}
		mat.resize(br);
		for(int i=0;i<mat.size();i++)
		mat[i].resize(3);
	for(auto i=poc1;i<kraj1;i++){
	for(auto j=poc2;j<kraj2;j++){
		if(*i==*j){ mat[red][0]=*i; mat[red][1]=0; mat[red][2]=0;
			
		if(red<br-1)red++;
			}
		}
	}
	sort(mat.begin(),mat.end(),[](vector<decltype(*poc1+0)> a ,vector<decltype(*poc1+0)> b){
		return a[0]<b[0];});
		return mat;
}
template <typename t, typename t1,typename t2,typename t3>

vector<vector<t2>> UvrnutiPresjek(t poc1, t kraj1, t1 poc2, t1 kraj2,t2 f(t3))
{

	vector<vector<t2>> mat;
	int br=0,red=0;
	bool isti=false;
	for(auto i=poc1;i<kraj1;i++){
		isti=false;
	for(auto j=poc2;j<kraj2;j++)
		if(f(abs(*i))==f(abs(*j))){isti=true; if(isti){br++;}
		isti=false;
			}
		}
		mat.resize(br);
		for(int i=0;i<mat.size();i++)
		mat[i].resize(3);
	for(auto i=poc1;i<kraj1;i++){
	for(auto j=poc2;j<kraj2;j++){
		if(f(*i)==f(*j)){ mat[red][0]=*i; mat[red][1]=*j; mat[red][2]=f(*i);
			
		if(red<br-1)red++;
			}
		}
	}
	sort(mat.begin(),mat.end(),[](vector<t2> a ,vector<t2> b){
		if(a[2]!=b[2]) return a[2]<b[2];
		else if(a[0]!=b[0]) return a[0]<b[0];
		else return a[1]<b[1];});
		return mat;
}

template <typename t, typename t1>
auto UvrnutaRazlika(t poc1, t kraj1, t1 poc2, t1 kraj2)->vector<vector<decltype(*poc1+0)> >
{

	vector<vector<decltype(*poc1+0)> >mat;
	int br=0,red=0;
	bool isti=false,dobar=true;

	 	
	for(auto i=poc1;i<kraj1;i++){
		isti=false;
	for(auto j=poc2;j<kraj2;j++)
		if(*i==*j){isti=true;}
		if(!isti){br++;}
			}
	for(auto i=poc2;i<kraj2;i++){
		isti=false;
	for(auto j=poc1;j<kraj1;j++)
		if(*i==*j){isti=true;}
		if(!isti){br++;}
			}
		
		mat.resize(br);
		for(int i=0;i<mat.size();i++)
		mat[i].resize(2);
	for(auto i=poc1;i<kraj1;i++){
		dobar=true;
	for(auto j=poc2;j<kraj2;j++){
		if(*i==*j){dobar=false;}
	}
		if(dobar){mat[red][0]=*i; mat[red][1]=0;
		if(red<br-1)red++;
	}
	}
	for(auto i=poc2;i<kraj2;i++){
		dobar=true;
	for(auto j=poc1;j<kraj1;j++){
		if(*i==*j)dobar=false;
	}
		if(dobar){mat[red][0]=*i;mat[red][1]=0;
		if(red<br-1)red++;
	}
	}
	sort(mat.begin(),mat.end(),[](vector<decltype(*poc1+0)> a ,vector<decltype(*poc1+0)> b){
		return a[0]>b[0];});
		return mat;
}
template <typename t, typename t1,typename t2,typename t3>
vector<vector<t2>> UvrnutaRazlika(t poc1, t kraj1, t1 poc2, t1 kraj2,t2 f(t3))
{

	vector<vector<t2>> mat;
	int br=0,red=0;
	bool isti=false,dobar=true;

	 	
	for(auto i=poc1;i<kraj1;i++){
		isti=false;
	for(auto j=poc2;j<kraj2;j++)
		if(f(*i)==f(*j)){isti=true;}
		if(!isti){br++;}
			}
	for(auto i=poc2;i<kraj2;i++){
		isti=false;
	for(auto j=poc1;j<kraj1;j++)
		if(f(*i)==f(*j)){isti=true;}
		if(!isti){br++;}
			}
		
		mat.resize(br);
		for(int i=0;i<mat.size();i++)
		mat[i].resize(2);
	for(auto i=poc1;i<kraj1;i++){
		dobar=true;
	for(auto j=poc2;j<kraj2;j++){
		if(f(*i)==f(*j)){dobar=false;}
	}
		if(dobar){mat[red][0]=*i; mat[red][1]=f(*i);
		if(red<br-1)red++;
	}
	}
	for(auto i=poc2;i<kraj2;i++){
		dobar=true;
	for(auto j=poc1;j<kraj1;j++){
		if(f(*i)==f(*j))dobar=false;
	}
		if(dobar){mat[red][0]=*i;mat[red][1]=f(*i);
		if(red<br-1)red++;
	}
	}
	sort(mat.begin(),mat.end(),[](vector<t2> a ,vector<t2> b){
		if(a[0]!=b[0]) return a[0]>b[0];
		else return a[1]>b[1];});
		return mat;
}

int SumaDjelilaca(long long int a)
{
	int suma=0;
	if(a==0)return a;
	else if(a<0)a*=-1;
		for(int i=1;i<=a;i++)
		{
			if(a%i==0)suma+=i;
		}
	return suma;
}
int SumaCifara(long long int a)
{
	int suma=0;
	if(a==0)return a;
	else if(a<0)a*=-1;
	while(a!=0)
	{
		suma+=a%10;
		a/=10;
	}
	return suma;
}
bool Jeliprost(int n)
{
	for(int i=2;i<=n/2;i++)
	if(n%i==0)return false;
	return true;
}
int BrojProstihFaktora(long long int a)
{
	int suma=0;
	if(a<0)a*=-1;
	for(int j=2;j<=a;j++)
	if(a%j==0 && Jeliprost(j)==true){suma++;a/=j;j--;}
	
	return suma;
}
int pomocna(int n)
{
	int suma=0;
	for(int i=1;i<n;i++)
	if(n%i==0)suma+=i;
	return suma;
}
int BrojSavrsenihDjelilaca(long long int a)
{
	int br=0;
	if(a==0)return 0;
	if(a<0)a*=-1;
	for(int i=1;i<=a;i++)
		if(a%i==0 && pomocna(i)==i)br++;
		return br;
}
int main ()
{
	int n1,n2,a,b;
	deque<int> d1, d2;
	vector<vector<int>>mat;
	cout<<"Unesite broj elemenata prvog kontejnera: ";
	cin>>n1;
	cout<<"Unesite elemente prvog kontejnera: ";
	for(int i=0;i<n1;i++){
	cin>>a;
	bool ima=false;
	for(int j=0;j<d1.size();j++)
	if(a==d1[j]){ima=true;n1++;break;}
	if(!ima)d1.push_back(a);
		
	}
	cout<<"Unesite broj elemenata drugog kontejnera: ";
	cin>>n2;
	cout<<"Unesite elemente drugog kontejnera: ";
	for(int i=0;i<n2;i++){
	cin>>b;
	bool ima=false;
	for(int j=0;j<d2.size();j++)
	if(b==d2[j]){ima=true;n2++;break;}
	if(!ima)d2.push_back(b);
	}
	cout<<"Uvrnuti presjek kontejnera:"<<endl;
	mat=UvrnutiPresjek(d1.begin(),d1.end(),d2.begin(),d2.end(),SumaCifara);
		for(int i=0;i<mat.size();i++){
        for(int j=0;j<mat[i].size();j++)
        cout<<setw(6)<<mat[i][j]<<" ";
        cout<<endl;}
        
      cout<<"Uvrnuta razlika kontejnera:"<<endl;
	mat=UvrnutaRazlika(d1.begin(),d1.end(),d2.begin(),d2.end(),BrojProstihFaktora);
	for(int i=0;i<mat.size();i++){
        for(int j=0;j<mat[i].size();j++)
        cout<<setw(6)<<mat[i][j]<<" ";
        cout<<endl;}
        
       cout<<"Dovidjenja!";
    
	return 0;
}