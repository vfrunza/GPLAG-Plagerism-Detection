
#include <iostream>
#include <cmath>
#include <algorithm>
#include <deque>
#include <vector>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;


//template <typename tip>
int SumaDjelilaca( long long int n)
{
	int suma{0};
	for(int i=1; i<=n; i++)
	{
		if(n%i==0) suma+=i;
	}
	return suma;
}
//template <typename tip>
int BrojProstihFaktora( long long int  n)
{
	int br(0);
	n=int(n);
	for( int i=2; i<=n; i++ )
	{
		if(n%i==0)
		{
			int a(0);
			for(int j=1; j<=i; j++)
			{
				if(i%j==0) a++;
			}
			if(a==2) 
			{
				br++;
				n=n/i;
				i--;
			
			}
		}
	}
	return br;
}
int SumaCifara( long long int n)
{
	int suma(0);
	while(n!=0)
	{
		suma+=n%10;
		n=n/10;
	}
	
	return suma;
}
int suma(int n)
{
	int suma(0);
	for(int i=1; i<n; i++)
	{
		if(n%i==0) suma+=i;
	}
	
	return suma;
	
}

//template<typename tip>
int BrojSavrsenihDjelilaca( long long int n )
{
	int br(0);
	n=int(n);
	for( int i=2; i<=n; i++)
	{
		if(n%i==0)
		{
			if(suma(i)==i) 
				{
					br++;
					n=n/i;
					i--;
				}
			
		}
	}
	return br;
}


template<typename tip1, typename tip2>
auto UvrnutiPresjek(tip1 pocetak1, tip1 kraj1, tip2  pocetak2, tip2 kraj2,   int f(long long int)=nullptr) -> std::vector<std::vector<typename std::remove_reference<decltype( *pocetak1 )>::type>>
{
	std::vector<std::vector<typename std::remove_reference<decltype(*pocetak2)>::type>> mat;
	tip2 cuva2(pocetak2);
	tip1 cuva1(pocetak1);
	if(f==nullptr)
	{
		while(pocetak1<kraj1)
		{
			
			pocetak2=cuva2;
			
			while(pocetak2<kraj2)
			{
				if(*pocetak1==(*pocetak2))
				{
					std::vector<typename std::remove_reference<decltype(*pocetak2)>::type> v;
					v.push_back(*pocetak1);
					v.push_back(0);
					v.push_back(0);
					mat.push_back(v);
				}
				pocetak2++;
				
			}
			pocetak1++;
			
		}
		
		
	}
	else{
		while( pocetak1<kraj1)
		{
		
			pocetak2=cuva2;
		
			while (pocetak2<kraj2) 
			{
				if(f(*pocetak1)==f(*pocetak2))
				{
					std::vector<typename std::remove_reference<decltype(*pocetak2)>::type> v;
					v.push_back(*pocetak1);
					v.push_back(*pocetak2);
					v.push_back(f(*pocetak1));
					mat.push_back(v);
				}
				pocetak2++;
			}
	
			pocetak1++;
		}
	}
	//JOS sortirati
	
	std::sort(mat.begin(), mat.end(), [](std::vector<typename std::remove_reference <decltype(*pocetak1)>::type>v1 , std::vector<typename std::remove_reference <decltype(*pocetak1)>::type>v2){
		if(v1[2]<v2[2]) return v1[2]<v2[2]; else if(v1[2]> v2[2]) return false;
		else if(v1[0]<v2[0]) return v1[0]<v2[0]; else if(v1[0]>v2[0]) return false;
		else if(v1[1]<v2[1]) return v1[1]<v2[1];
		else return false;
	});
	
	
	return mat;
}

template<typename tip1, typename tip2>
auto UvrnutaRazlika(tip1 pocetak1, tip1 kraj1, tip2 pocetak2, tip2 kraj2,  int f(long long int)=nullptr) -> std::vector<std::vector<typename std::remove_reference<decltype(*pocetak1)>::type>>
{
	std::vector<std::vector<typename std::remove_reference<decltype(*pocetak2 )>::type>> mat ;
	bool nema_par(false);
	tip1 cuva1(pocetak1);
	tip2 cuva2(pocetak2);
	
	if(f==nullptr)
	{
		while(pocetak1<kraj1)
		{
			nema_par=false;
			pocetak2=cuva2;
			while(pocetak2<kraj2)
			{
				if(*pocetak2==*pocetak1)
				{
					nema_par=true;
				}
				pocetak2++;
			}
			if(nema_par==false)
			{
				std::vector<typename std::remove_reference<decltype(*pocetak1)>::type> v;
				v.push_back(*pocetak1);
				v.push_back(0);
				mat.push_back(v);
				
			}
			pocetak1++;
		}
		pocetak2=cuva2;
		while(pocetak2<kraj2)
		{
			nema_par=false;
			pocetak1=cuva1;
			
			while(pocetak1<kraj1)
			{
				if(*pocetak1==*pocetak2)
				{
					nema_par=true;
				}
				pocetak1++;
			}
			if(nema_par==false)
			{
				std::vector<typename std::remove_reference<decltype(*pocetak1)>::type> v;
				v.push_back(*pocetak2);
				v.push_back(0);
				mat.push_back(v);
			}
			pocetak2++;
			
		}
	}
	
	else{
	while(pocetak1<kraj1)
	{
		nema_par=false;
		pocetak2=cuva2;
	
		while(pocetak2<kraj2)
		{
			if(f(*pocetak1)== f(*pocetak2)) 
			{
				nema_par=true;
				
			}
			pocetak2++;
			
		}
		if(nema_par==false)
		{
			std::vector<typename std::remove_reference<decltype(*pocetak1)>::type> v;
			v.push_back(*pocetak1);
			v.push_back(f(*pocetak1));
			mat.push_back(v);
		}
		pocetak1++;
	}

	pocetak2=cuva2;
	
	while(pocetak2 < kraj2)
	{
		nema_par=false;
		pocetak1=cuva1;
		
		while(pocetak1< kraj1)
		{
			if(f(*pocetak2)==f(*pocetak1))
			{
				nema_par=true;
				
			}
			pocetak1++;
		}
		if(nema_par==false)
		 {
		 	std::vector<typename std::remove_reference<decltype(*pocetak1)>::type> v;
		 	v.push_back(*pocetak2);
		 	v.push_back(f(*pocetak2));
		 	mat.push_back(v);
		 }
	
		pocetak2++;
	}
	}

	//SORTIRANJE
	
	std::sort(mat.begin(), mat.end(), []( std::vector<typename std::remove_reference<decltype(*pocetak1)>::type> v1, std::vector<typename std::remove_reference<decltype(*pocetak1)>::type> v2  ){
		if(v1[0]>v2[0]) return v1[0]>v2[0];
		else if(v1[0]<v2[0]) return false;
		else if(v1[1]>v2[1]) return v1[1]<v2[1];
		else return false;
		
	});
	
	return mat;
	
	
}

int main ()
{
	int n;
	cout<<"Unesite broj elemenata prvog kontejnera: ";
	cin>>n;
	cout<<"Unesite elemente prvog kontejnera: ";
	std::deque<int> d1 ;
	bool tacno=false;
	int i(0);

	do {
		int broj;
		cin>>broj;
		tacno=false;
		for(int j=0; j<d1.size(); j++)
		{
			if(broj==d1[j]){
				tacno=true;
			
			}
		}
		if(tacno==false)
		{
			d1.push_back(broj);
			i++;
		}
		
	}while(i!=n);
	cout<<"Unesite broj elemenata drugog kontejnera: ";
	int m ;
	cin>>m;
	cout<<"Unesite elemente drugog kontejnera: ";
	std::deque<int> d2 ;
	i=0;
	do{
		int broj;
		cin>>broj;
		tacno=false;
		for(int j=0; j<d2.size(); j++)
		{
			if(broj==d2[j]){
				tacno=true;
				
			}
		}
		if(tacno==false)
		{
			d2.push_back(broj);
			i++;
		}
		
	}while(i!=m);
	cout<<"Uvrnuti presjek kontejnera: "<<endl;
	auto mat1=UvrnutiPresjek( d1.begin(), d1.end(), d2.begin(), d2.end(),SumaCifara);
	auto mat2 = UvrnutaRazlika(d1.begin(), d1.end(), d2.begin(), d2.end(), BrojProstihFaktora );

	for( int i=0; i<mat1.size(); i++)
	{
		for( int j=0; j<mat1[i].size(); j++)
			{
				cout<<std::setw(6)<<mat1[i][j]<<" ";
			}
			cout<<endl;
	
	}
	
	cout<<"Uvrnuta razlika kontejnera: "<<endl;
	for( int i=0; i<mat2.size(); i++)
	{
		for( int j=0; j<mat2[i].size(); j++)
			{
				cout<<std::setw(6)<<mat2[i][j]<<" ";
			}
			cout<<endl;
	
	}
	cout<<"Dovidjenja!";
	
	
	return 0;
}