#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>
#include <string>
#include <deque>
#include <algorithm>
#include <cmath>
#include <cfloat>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::deque;
int f(long long int a)
{
	int n(a),suma=0;
	while(n!=0) {
		suma+=n%10;
		n=n/10;
	}
	return suma;
}
int SumaDjelilaca(long long int a)
{
	int suma{};
	if(a<0)
		a=fabs(a);
	for(int i=1; i<=a; i++)
		if(a%i==0)
			suma+=i;
	return suma;
}
int BrojProstihFaktora(long long int a)
{
	
	int br{},b;
	int k=a%2;
	if(a==0)
		return 0;
	while(k==0) {
		b=a/2;
		a=b;
		k=a%2;
		br++;
	}
	for(int j=3; j<=a; j+=2) {
		if(j<=0)
			break;
		int k=a%j;
		while(k==0) {
			b=a/j;
			a=b;
			br++;
			k=a%j;
		}
		if(j==a)
			break;
	}
	return br;
}

int BrojSavrsenihDjelilaca(long long int a)
{
	int suma {},br {};
	for(int i=2; i<=a; i++){
		if(a%i==0) {
			for(int j=1; j<i; j++) {
				if(i%j==0) {
					suma+=j;
				}
			}
			if(suma==i)
				br++;
			suma=0;
		}
		if(i==a)
			break;
	}
	return br;
}
template <typename tip1, typename tip2, typename tip3, typename tip4>
auto UvrnutiPresjek(tip1 p1, tip1 k1, tip2 p2, tip2 k2, tip3 f(tip4))-> vector<vector<decltype(*p1+0)>> {
	vector<vector<decltype(*p1+0)>> M;
	if(p1-k1==0) return M;
	else if(p2-k2==0) return M;
	auto poc1(p1);
	auto kraj1(k1);
	auto poc2(p2);
	auto kraj2(k2);
	int i{};
	while(p1!=k1) {
		while(p2!=k2) {
			if(fabs(f(*p1)-f(*p2))<DBL_MIN) {
				M.resize(i+1);
				M[i].push_back(*p1);
				M[i].push_back(*p2);
				M[i].push_back(f(*p1));
				i++;
			}
			p2++;
		}
		p1++;
		p2=poc2;
	}
	p1=poc1;
	std::sort(M.begin(), M.end(),[](const std::vector<decltype(*p1+0)>& a, const std::vector<decltype(*p1+0)>& b) {
		if(fabs(a[2]-b[2])<DBL_MIN) {
			if(fabs(a[0]-b[0])<DBL_MIN) {
				if(fabs(a[1]-b[1])<DBL_MIN)
					return false;
				else return a[1]<b[1];
			} else return a[0]<b[0];
		}
		return a[2]<b[2];
	});
	for(int i=0; i<int(M.size())-1; i++) {
		for(int j=i+1; j<M.size(); j++)
			if(M[i]==M[j]) {
				M.erase(M.begin()+j);
				j--;
			}
	}
	return M;
}
template <typename tip1, typename tip2>
auto UvrnutiPresjek(tip1 p1, tip1 k1, tip2 p2, tip2 k2)-> vector<vector<decltype(*p1+0)>> {
	vector<vector<decltype(*p1+0)>> M;
	if(p1-k1==0) return M;
	else if(p2-k2==0) return M;
	auto poc1(p1);
	auto kraj1(k1);
	auto poc2(p2);
	auto kraj2(k2);
	int i{};
	while(p1!=k1) {
		while(p2!=k2) {
			if(*p1==*p2) {
				M.resize(i+1);
				M[i].push_back(*p1);
				M[i].push_back(0);
				M[i].push_back(0);
				i++;
			}
			p2++;
		}
		p1++;
		p2=poc2;
	}
	p1=poc1;
	std::sort(M.begin(), M.end(),[](const std::vector<decltype(*p1+0)>& a, const std::vector<decltype(*p1+0)>& b) {
		if(fabs(a[2]-b[2])<DBL_MIN) {
			if(fabs(a[0]-b[0])<DBL_MIN) {
				if(fabs(a[1]-b[1])<DBL_MIN)
					return false;
				else return a[1]<b[1];
			} else return a[0]<b[0];
		}
		return a[2]<b[2];
	});
	for(int i=0; i<int(M.size())-1; i++) {
		for(int j=i+1; j<M.size(); j++)
			if(M[i]==M[j]) {
				M.erase(M.begin()+j);
				j--;
			}
	}

	return M;
}
template <typename tip1, typename tip2,typename tip3, typename tip4>
auto UvrnutaRazlika(tip1 p1, tip1 k1, tip2 p2, tip2 k2, tip3 f(tip4))-> vector<vector<decltype(*p1+0)>> {
vector<vector<decltype(*p1+0)>>	M;	
	auto poc1(p1);
	auto kraj1(k1);
	auto poc2(p2);
	auto kraj2(k2);
	int i{};
	bool NemaPara=false;
	while(p1!=k1) {
		while(p2!=k2) {
			if(fabs(f(*p1)-f(*p2))<DBL_MIN) {

				NemaPara=true;
			}
			p2++;
		}
		if(!NemaPara) {
			M.resize(i+1);
			M[i].push_back(*p1);
			M[i].push_back(f(*p1));
			i++;
		}
		NemaPara=false;
		p1++;
		p2=poc2;
	}
	p1=poc1;
	p2=poc2;
	while(p2!=k2) {

		while(p1!=k1) {
			if(fabs(f(*p1)-f(*p2))<DBL_MIN) {

				NemaPara=true;
			}
			p1++;
		}
		if(!NemaPara) {

			M.resize(i+1);
			M[i].push_back(*p2);
			M[i].push_back(f(*p2));
			i++;

		}
		NemaPara=false;
		p2++;
		p1=poc1;
	}
	std::sort(M.begin(), M.end(),[](const vector<decltype(*p1+0)>& a, const vector<decltype(*p1+0)> & b) {
		if(fabs(a[0]-b[0])<DBL_MIN)
			return (a[1]>b[1]);
		else return a[0]>b[0];
	});
	
	for(int i=0; i<int(M.size())-1; i++) {
		for(int j=i+1; j<M.size(); j++)
			if(M[i]==M[j]) {
				M.erase(M.begin()+j);
				j--;
			}
	}
	return M;
}
template <typename tip1, typename tip2>
auto UvrnutaRazlika(tip1 p1, tip1 k1, tip2 p2, tip2 k2)-> vector<vector<decltype(*p1+0)>> {
vector<vector<decltype(*p1+0)>>	M;	
	auto poc1(p1);
	auto kraj1(k1);
	auto poc2(p2);
	auto kraj2(k2);
	int i{};
	bool NemaPara=false;
	while(p1!=k1) {
		while(p2!=k2) {
			if(fabs(*p1-*p2)<DBL_MIN) {

				NemaPara=true;
			}
			p2++;
		}
		if(!NemaPara) {
			M.resize(i+1);
			M[i].push_back(*p1);
			M[i].push_back(0);
			i++;
		}
		NemaPara=false;
		p1++;
		p2=poc2;
	}
	p1=poc1;
	p2=poc2;
	while(p2!=k2) {

		while(p1!=k1) {
			if(fabs(*p1-*p2)<DBL_MIN) {

				NemaPara=true;
			}
			p1++;
		}
		if(!NemaPara) {

			M.resize(i+1);
			M[i].push_back(*p2);
			M[i].push_back(0);
			i++;

		}
		NemaPara=false;
		p2++;
		p1=poc1;
	}
	std::sort(M.begin(), M.end(),[](const vector<decltype(*p1+0)>& a, const vector<decltype(*p1+0)> & b) {
		if(fabs(a[0]-b[0])<DBL_MIN)
			return (a[1]>b[1]);
		else return a[0]>b[0];
	});
	
	for(int i=0; i<int(M.size())-1; i++) {
		for(int j=i+1; j<M.size(); j++)
			if(M[i]==M[j]) {
				M.erase(M.begin()+j);
				j--;
			}
	}
	return M;
}
int main ()
{
	int n1,n2;
	int i {},br {};
	cout<<"Unesite broj elemenata prvog kontejnera: ";
	cin>>n1;
	cout<<"Unesite elemente prvog kontejnera: ";
	bool ima=false;
	deque<int> D1;
	while(i!=n1) {
		cin>>br;
		for(int j=0; j<D1.size(); j++)
			if(fabs(br-D1[j])<DBL_MIN)
				ima=true;
		if(!ima) {
			D1.push_back(br);
			i++;
		}
		ima=false;
	}
	cout<<"Unesite broj elemenata drugog kontejnera: ";
	cin>>n2;
	cout<<"Unesite elemente drugog kontejnera: ";
	deque<int> D2;
	i=0;
	while(i!=n2) {
		cin>>br;
		for(int j=0; j<D2.size(); j++)
			if(fabs(br-D2[j])<DBL_MIN)
				ima=true;
		if(!ima) {
			D2.push_back(br);
			i++;
		}
		ima=false;
	}
	vector<vector<int>> P;
	P=UvrnutiPresjek(D1.begin(), D1.end(),D2.begin(), D2.end(),f);
	cout<<"Uvrnuti presjek kontejnera:"<<endl;
	for(int i=0; i<P.size(); i++) {
		for(int j=0; j<3; j++)
			cout<<std::setw(6)<<P[i][j]<<" ";
		cout<<endl;
	}
	vector<vector<int>> R;
	R=UvrnutaRazlika(D1.begin(), D1.end(),D2.begin(), D2.end(), BrojProstihFaktora);
	cout<<"Uvrnuta razlika kontejnera:"<<endl;
	for(int i=0; i<R.size(); i++) {
		for(int j=0; j<2; j++)
			cout<<std::setw(6)<<R[i][j]<<" ";
		cout<<endl;
	}
	cout<<"Dovidjenja!"<<endl;
	return 0;
}