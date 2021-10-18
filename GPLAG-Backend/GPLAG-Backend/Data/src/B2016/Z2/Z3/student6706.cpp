#include<iostream>
#include<deque>
#include<vector>
#include<cmath>
#include<iomanip>
using namespace std;
int f(long long int x){
	int sum=0;
	while(x!=0){
		sum=x%10+sum;
		x/=10;
	}
	return sum;
}
int SumaDjelilaca(long long int x){
	int sum=0;
    x=fabs(x);
	for(int i=1; i<=x; i++){
	if(x%i==0) sum+=i;
	}
	return sum;
}
bool prost(long long int n){
	for (long long int i=2; i<n; i++) {if(n%i==0) return false;}
	return true;
}

int BrojProstihFaktora( long long int n){
	int brojac(0);
	if(prost(n)==1) return 1;
	if(prost(n)==0){
       while(n!=1){
      for(int i=2;i<=n;i++){
           if(n%i==0){
            n=n/i;
            brojac++;
            break;
            }
        }
    }
	}
    return brojac;
}
int BrojSavrsenihDjelilaca(long long int x){
	int brojac=0;
	for(int i=1; i<=x; i++){
     int sum=0;
	if(x%i==0) {
    for(int j=1;j<i;j++){
        if(i%j==0) sum+=j;
    }
    if(sum==i) brojac++;
	}
}

return brojac;
}
template<typename tip1, typename tip2, typename tip3, typename tip4>
auto UvrnutiPresjek(tip1 pocetak1, tip1 kraj1, tip2 pocetak2, tip2 kraj2, tip3 f(tip4 x) )->vector<vector<typename std::remove_reference<decltype(*pocetak1)>::type>>{
	int brojredova=0;
	vector<vector<typename std::remove_reference<decltype(*pocetak1)>::type>> m;
	while(pocetak1<kraj1){
	tip2 pomocna=pocetak2;
	while(pocetak2<kraj2){
		vector<long long int> a;
		if(f(*pocetak1)==f(*pocetak2)){ 
			a.push_back(*pocetak1); 
			a.push_back(*pocetak2); 
			a.push_back(f(*pocetak1)); 
		}
		if(a.size()==3) {
		brojredova++;
			m.resize(brojredova);
			for(int b=brojredova-1; b<m.size(); b++) m[b].resize(a.size());
			for(int b=brojredova-1; b<m.size(); b++){
				for(int d=0; d<m[b].size(); d++){
					m[b][d]=a[d];
				}
			}
		}
		pocetak2++;
    }
    pocetak2=pomocna;
    pocetak1++;
  }
  for(int i=0;i<m.size();i++){
    for(int j=i+1;j<m.size();j++){
        if(m[i][2]>m[j][2]){
            for(int k=0;k<3;k++){
                int pomocna=m[i][k];
                m[i][k]=m[j][k];
                m[j][k]=pomocna;
                }
            }
        else if(m[i][2]==m[j][2]){
            if(m[i][0]>m[j][0]){
                for(int k=0;k<3;k++){
                int pomocna=m[i][k];
                m[i][k]=m[j][k];
                m[j][k]=pomocna;
                }
            }
            else if(m[i][0]==m[j][0]){
                if(m[i][1]>m[j][1]){
                    for(int k=0;k<3;k++){
                int pomocna=m[i][k];
                m[i][k]=m[j][k];
                m[j][k]=pomocna;
                }
            }
            }
            }
            }
            }
  return m;
}
template<typename tip1, typename tip2, typename tip3, typename tip4>
auto UvrnutaRazlika(tip1 pocetak1, tip1 kraj1, tip2 pocetak2, tip2 kraj2, tip3 f(tip4 x) )->vector<vector<typename std::remove_reference<decltype(*pocetak1)>::type>>{
	int brojredova=0;
	vector<vector<typename std::remove_reference<decltype(*pocetak1)>::type>> m;
	tip2 pomocna2=pocetak2;
	tip1 pomocna1=pocetak1;
    int jeste=1;
	while(pocetak1<kraj1){
		vector<long long int> a;
		jeste=1;
		if(f(*pocetak1)!=f(*pocetak2)){
			jeste=0;
			pomocna2=pocetak2;
			while(pocetak2<kraj2){
		     if(f(*pocetak1)==f(*pocetak2)) { jeste=1; break;}
		     pocetak2++;
		}
		}
		pocetak2=pomocna2;
		if(jeste==0) {a.push_back(*pocetak1); a.push_back(f(*pocetak1));}
		if(a.size()==2) {
		brojredova++;
			m.resize(brojredova);
			for(int b=brojredova-1; b<m.size(); b++) m[b].resize(a.size());
			for(int b=brojredova-1; b<m.size(); b++){
				for(int d=0; d<m[b].size(); d++){
					m[b][d]=a[d];
				}
			}
		}
      pocetak1++;
    }
    pocetak1=pomocna1;
    pocetak2=pomocna2;
    while(pocetak2<kraj2){
		vector<long long int> a;
		jeste=1;
		if(f(*pocetak2)!=f(*pocetak1)){
			jeste=0;
			pomocna1=pocetak1;
			while(pocetak1<kraj1){
		     if(f(*pocetak2)==f(*pocetak1)) { jeste=1; break;}
		     pocetak1++;
		}
		}
		pocetak1=pomocna1;
		if(jeste==0) {a.push_back(*pocetak2); a.push_back(f(*pocetak2));}
		if(a.size()==2) {
		brojredova++;
			m.resize(brojredova);
			for(int b=brojredova-1; b<m.size(); b++) m[b].resize(a.size());
			for(int b=brojredova-1; b<m.size(); b++){
				for(int d=0; d<m[b].size(); d++){
					m[b][d]=a[d];
				}
			}
		}
      pocetak2++;
    }
    for(int i=0;i<m.size();i++){
    for(int j=i+1;j<m.size();j++){
        if(m[i][0]<m[j][0]){
            for(int k=0;k<2;k++){
                int pomocna=m[i][k];
                m[i][k]=m[j][k];
                m[j][k]=pomocna;
                }
            }
        else if(m[i][1]==m[j][1]){
            if(m[i][1]<m[j][1]){
                for(int k=0;k<2;k++){
                int pomocna=m[i][k];
                m[i][k]=m[j][k];
                m[j][k]=pomocna;
                }
            }
         
            }
            }
            }
  return m;
}



template<typename tip1, typename tip2>
auto UvrnutiPresjek(tip1 pocetak1, tip1 kraj1, tip2 pocetak2, tip2 kraj2)->vector<vector<typename std::remove_reference<decltype(*pocetak1)>::type>>{
	int brojredova=0;
	vector<vector<typename std::remove_reference<decltype(*pocetak1)>::type>> m;
	while(pocetak1<kraj1){
	tip2 pomocna=pocetak2;
	while(pocetak2<kraj2){
		vector<long long int> a;
		if(*pocetak1==*pocetak2){ 
			a.push_back(*pocetak1); 
			a.push_back(0); 
			a.push_back(0); 
		}
		if(a.size()==3) {
		brojredova++;
			m.resize(brojredova);
			for(int b=brojredova-1; b<m.size(); b++) m[b].resize(a.size());
			for(int b=brojredova-1; b<m.size(); b++){
				for(int d=0; d<m[b].size(); d++){
					m[b][d]=a[d];
				}
			}
		}
		pocetak2++;
    }
    pocetak2=pomocna;
    pocetak1++;
  }
  for(int i=0;i<m.size();i++){
    for(int j=i+1;j<m.size();j++){
        if(m[i][2]>m[j][2]){
            for(int k=0;k<3;k++){
                int pomocna=m[i][k];
                m[i][k]=m[j][k];
                m[j][k]=pomocna;
                }
            }
        else if(m[i][2]==m[j][2]){
            if(m[i][0]>m[j][0]){
                for(int k=0;k<3;k++){
                int pomocna=m[i][k];
                m[i][k]=m[j][k];
                m[j][k]=pomocna;
                }
            }
            else if(m[i][0]==m[j][0]){
                if(m[i][1]>m[j][1]){
                    for(int k=0;k<3;k++){
                int pomocna=m[i][k];
                m[i][k]=m[j][k];
                m[j][k]=pomocna;
                }
            }
            }
            }
            }
            }
  return m;
}
template<typename tip1, typename tip2>
auto UvrnutaRazlika(tip1 pocetak1, tip1 kraj1, tip2 pocetak2, tip2 kraj2)->vector<vector<typename std::remove_reference<decltype(*pocetak1)>::type>>{
	int brojredova=0;
	vector<vector<typename std::remove_reference<decltype(*pocetak1)>::type>> m;
	tip2 pomocna2=pocetak2;
	tip1 pomocna1=pocetak1;
    int jeste=1;
	while(pocetak1<kraj1){
		vector<long long int> a;
		jeste=1;
		if(*pocetak1!=*pocetak2){
			jeste=0;
			pomocna2=pocetak2;
			while(pocetak2<kraj2){
		     if(*pocetak1==*pocetak2) { jeste=1; break;}
		     pocetak2++;
		}
		}
		pocetak2=pomocna2;
		if(jeste==0) {a.push_back(*pocetak1); a.push_back(0);}
		if(a.size()==2) {
		brojredova++;
			m.resize(brojredova);
			for(int b=brojredova-1; b<m.size(); b++) m[b].resize(a.size());
			for(int b=brojredova-1; b<m.size(); b++){
				for(int d=0; d<m[b].size(); d++){
					m[b][d]=a[d];
				}
			}
		}
      pocetak1++;
    }
    pocetak1=pomocna1;
    pocetak2=pomocna2;
    while(pocetak2<kraj2){
		vector<long long int> a;
		jeste=1;
		if(*pocetak2!=*pocetak1){
			jeste=0;
			pomocna1=pocetak1;
			while(pocetak1<kraj1){
		     if(*pocetak2==*pocetak1) { jeste=1; break;}
		     pocetak1++;
		}
		}
		pocetak1=pomocna1;
		if(jeste==0) {a.push_back(*pocetak2); a.push_back(0);}
		if(a.size()==2) {
		brojredova++;
			m.resize(brojredova);
			for(int b=brojredova-1; b<m.size(); b++) m[b].resize(a.size());
			for(int b=brojredova-1; b<m.size(); b++){
				for(int d=0; d<m[b].size(); d++){
					m[b][d]=a[d];
				}
			}
		}
      pocetak2++;
    }
    for(int i=0;i<m.size();i++){
    for(int j=i+1;j<m.size();j++){
        if(m[i][1]<m[j][1]){
            for(int k=0;k<2;k++){
                int pomocna=m[i][k];
                m[i][k]=m[j][k];
                m[j][k]=pomocna;
                }
            }
        else if(m[i][1]==m[j][1]){
            if(m[i][0]<m[j][0]){
                for(int k=0;k<2;k++){
                int pomocna=m[i][k];
                m[i][k]=m[j][k];
                m[j][k]=pomocna;
                }
            }
         
            }
            }
            }
  return m;
}
int main (){
	int n;
	cout<<"Unesite broj elemenata prvog kontejnera: ";
	cin>>n;
	cout<<"Unesite elemente prvog kontejnera: ";
	deque<long long int>c;
	c.resize(n);
	int i=0,k=0;
		while(i<n){
		cin>>c[i];
		int jeste=0;
		int pomocna=i;
		while(i!=0){
		if(c[k]==c[i-1]) jeste=1;
		i--;
		}
		i=pomocna;
		if(jeste) {i--; k--;}
		i++;
		k++;
	}
	cin.ignore(10000,'\n');
	int n1=0;
	cout<<"Unesite broj elemenata drugog kontejnera: ";
	cin>>n1;
	cout<<"Unesite elemente drugog kontejnera: ";
	deque<long long int>d(n1);
	i=0;
	k=0;
		while(i<n1){
		cin>>d[i];
		int jeste=0;
		int pomocna=i;
		while(i!=0){
		if(d[k]==d[i-1]) jeste=1;
		i--;
		}
		i=pomocna;
		if(jeste) {i--; k--;}
		i++;
		k++;
	}
	vector<vector<typename std::remove_reference<decltype(c[0])>::type>> m(UvrnutiPresjek(c.begin(),c.end(),d.begin(),d.end(),f));
	cout<<"Uvrnuti presjek kontejnera:"<<endl;
	for(int i=0; i<m.size();i++){
		cout<<" ";
		for(int j=0; j<m[i].size();j++){
			cout<<setw(5)<<m[i][j];
		}
		cout<<endl;
	}
	cout<<"Uvrnuta razlika kontejnera:"<<endl;
	vector<vector<typename std::remove_reference<decltype(c[0])>::type>> w(UvrnutaRazlika(c.begin(),c.end(),d.begin(),d.end(),f));
	for(int i=0; i<w.size();i++){
		cout<<" ";
		for(int j=0; j<w[i].size();j++){
			cout<<setw(5)<<w[i][j];
			
		}
		cout<<endl;
	}
	cout<<"Dovidjenja!";
	return 0;
}