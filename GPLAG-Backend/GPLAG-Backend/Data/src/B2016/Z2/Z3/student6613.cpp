/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/
#include<iostream>
#include<vector>
#include<deque>
#include<type_traits>
#include<algorithm>
#include<iomanip>
#include<cmath>
using std::cin;
using std::cout;
using std::endl;

bool Prost(int n){
	int br(0);
	for(int j=1; j<=sqrt(n); j++){
		if(n%j==0) br++;
		if(br>1) return 0;
	}
	if(br==1) return 1;
	return 0;
}
int SumaCifara(long long n){
	int br(0);
	do{
		br+=n%10;
		n/=10;
	} while(n!=0);
	return br;
}
int SumaDjelilaca(long long int n){
	int s(0);
	if(n<0) n*=(-1);
	for(int i=1; i<=n; i++)
		if(n%i==0) s+=i;
	
	return s;
}
bool Savrsen(int n){
	return((SumaDjelilaca(n)-n)==n);
}
int BrojSavrsenihDjelilaca(long long int n){
	int br(0);
	if(n<0) n*=(-1);
	for(int i=1; i<=n; i++){
		if(n%i==0 && Savrsen(i)) br++;
	}
	return br;
}
int BrojProstihFaktora(long long int n){
	int br(0);
		for(int i=2; i<=n; i++){
			if(Prost(i) && n%i==0){
				while(n%i==0){
				n/=i;
				br++;
				}
		}
	}
	return br;
}
template<typename tip1, typename tip2>
auto UvrnutiPresjek(tip1 p1, tip1 p2, tip2 s1, tip2 s2)->std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>>{
	std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>>mat;
	tip1 p=p1;
	typedef std::vector<typename std::remove_reference<decltype(*p1)>::type> tip;
	while(p!=p2){
		tip2 s=s1;
		while(s!=s2){
			if(*s==*p) {
				std::vector<typename std::remove_reference<decltype(*p1)>::type>v;
				v.push_back(*p);
				v.push_back(0);
				v.push_back(0);
		//		for(int i=0; i<3; i++) cout<<v[i]<<" ";
				mat.push_back(v);
				s=s2-1;
			}
			s++;
		}
		p++;
	}
	sort(mat.begin(), mat.end(),[](tip x, tip y){
		if(x[0]<y[0]) return 1;
		return 0;
	});

	return mat;
}
template<typename tip1, typename tip2, typename tip3, typename tip4>
auto UvrnutiPresjek(tip1 p1, tip1 p2, tip2 s1, tip2 s2, tip3 fun(tip4))->std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>>{
	std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>>mat;
	tip1 p=p1;
	typedef std::vector<typename std::remove_reference<decltype(*p1)>::type> tip;
	while(p!=p2){
		tip2 s=s1;
		while(s!=s2){
			if(fun(*s)==fun(*p)) {
				std::vector<typename std::remove_reference<decltype(*p1)>::type>v;
				v.push_back(*p);
				v.push_back(*s);
				v.push_back(fun(*p));
				mat.push_back(v);
			}
			s++;
		}
		p++;
	}
	sort(mat.begin(), mat.end(),[](tip x, tip y){
		if(x[2]<y[2]) return 1;
		if(x[2]==y[2]){
			if(x[0]<y[0]) return 1;
			if(x[0]==y[0]){
				if(x[1]<y[1]) return 1;
			}
		}
		return 0;
	});

	return mat;
}
template<typename tip1, typename tip2, typename tip3, typename tip4>
auto UvrnutaRazlika(tip1 p1, tip1 p2, tip2 s1, tip2 s2, tip3 fun(tip4))->std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>>{
	std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>>mat;
	tip1 p=p1;
	int br(0);
	typedef std::vector<typename std::remove_reference<decltype(*p1)>::type> tip;
	while(p!=p2){
		tip2 s=s1;
		br=0;
		while(s!=s2){
			if(fun(*s)==fun(*p)) 
				br++;
			s++;
		}
		if(br==0){
				std::vector<typename std::remove_reference<decltype(*p1)>::type>v;
				v.push_back(*p);
				v.push_back(fun(*p));
				mat.push_back(v);
		}
		p++;
	}
	tip2 s=s1;
		while(s!=s2){
		p=p1;
		br=0;
		while(p!=p2){
			if(fun(*s)==fun(*p)) 
				br++;
			p++;
		}
		if(br==0){
				std::vector<typename std::remove_reference<decltype(*p1)>::type>v;
				v.push_back(*s);
				v.push_back(fun(*s));
				mat.push_back(v);
		}
		s++;
	}
	sort(mat.begin(), mat.end(),[](tip x, tip y){
		if(x[0]>y[0]) return 1;
		if(x[0]==y[0])
			if(x[1]>y[1]) return 1;
		return 0;
	});

	return mat;
}
template<typename tip1, typename tip2>
auto UvrnutaRazlika(tip1 p1, tip1 p2, tip2 s1, tip2 s2)->std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>>{
	std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>>mat;
	tip1 p=p1;
	int br(0);
	typedef std::vector<typename std::remove_reference<decltype(*p1)>::type> tip;
	while(p!=p2){
		tip2 s=s1;
		br=0;
		while(s!=s2){
			if(*s==*p) 
				br++;
			s++;
		}
		if(br==0){
				std::vector<typename std::remove_reference<decltype(*p1)>::type>v;
				v.push_back(*p);
				v.push_back(0);
				mat.push_back(v);
		}
		p++;
	}
	tip2 s=s1;
		while(s!=s2){
		p=p1;
		br=0;
		while(p!=p2){
			if(*s==*p) 
				br++;
			p++;
		}
		if(br==0){
				std::vector<typename std::remove_reference<decltype(*p1)>::type>v;
				v.push_back(*s);
				v.push_back(0);
				mat.push_back(v);
		}
		s++;
	}
	sort(mat.begin(), mat.end(),[](tip x, tip y){
		if(x[0]>y[0]) return 1;
		
		return 0;
	});

	return mat;
}

int main()
{
	int n;
	cout<<"Unesite broj elemenata prvog kontejnera: ";
	cin>>n;
	std::deque<int>v1(n);
	int x, t;

cout<<"Unesite elemente prvog kontejnera: ";
for(int i=0; i<n; i++){
		cin>>x;
		t=0;
		for(int j=0; j<i-1; j++)
			if(x==v1[j])
				t=1;

		if(t==0) v1[i]=x;
		else i--;
	}
	int m;
	cout<<"Unesite broj elemenata drugog kontejnera: ";

	cin>>m;
	std::deque<int>v2(m);
	cout<<"Unesite elemente drugog kontejnera: ";
	for( int i=0; i<m; i++){
		cin>>x;
		t=0;
		for(int j=0; j<i-1; j++)
			if(x==v2[j])
				t=1;
		
		if(t==0) v2[i]=x;
		else i--;
	}

	std::vector<std::vector<int>> mat=(UvrnutiPresjek(v1.begin(), v1.end(), v2.begin(), v2.end(), SumaCifara));
	cout<<"Uvrnuti presjek kontejnera:"<<endl;
	for(int i=0; i<mat.size(); i++){
		for(int j=0; j<3; j++)
			cout<<std::right<<std::setw(6)<<mat[i][j]<<" ";
		cout<<endl;
	}
	std::vector<std::vector<int>> mat1=(UvrnutaRazlika(v1.begin(), v1.end(), v2.begin(), v2.end(), BrojProstihFaktora));
	cout<<"Uvrnuta razlika kontejnera:"<<endl;
	for(int i=0; i<mat1.size(); i++){
		for(int j=0; j<2; j++)
			cout<<std::right<<std::setw(6)<<mat1[i][j]<<" ";
		cout<<endl;
	}
	cout<<"Dovidjenja!";
	return 0;
}