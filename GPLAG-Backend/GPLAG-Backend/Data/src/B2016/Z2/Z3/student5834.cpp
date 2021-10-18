/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<deque>
#include<cmath>
int SumaDjelilaca(long long int x){
	int s=0;
	x=abs(x);
	for(int i=1;i<=x;i++){
		if(x%i==0)
			s+=i;
	}
	return s;
}
int BrojProstihFaktora(long long int x){
	int br=0;
	long long int c=abs(x);
	for(int i=2;i<=abs(x);i++){
		if(c%i==0)
			while(c%i==0){
				br++;
				c/=i;
			}
	}
	return br;
}
int BrojSavrsenihDjelilaca(long long int x){
	long long int c=abs(x);
	int br=0;
	for(int i=1;i<=abs(x);i++){
		if(c%i==0){
			int s=0;
		//	c/=i;
			for(int j=1;j<i;j++){
				if(i%j==0)
					s+=j;
			}
			if(s==i) br++;
		}
	}
	return br;
	
}

//SA 4 ARGUMENTA
template <typename t1,typename t2>
auto UvrnutiPresjek(t1 p1,t1 p2,t2 q1,t2 q2)->std::vector<std::vector<decltype(*p1+*p1)> >{
	int br=q2-q1,n=0,i=0;
	std::vector<std::vector<decltype(*p1+*p1)> > mat;
	while(p1!=p2){
		while(q1!=q2){
			if(*p1==*q1){
				n++;
				mat.resize(n);
				mat[i].resize(3);
				mat[i][0]=*p1;
				mat[i][1]=0;
				mat[i][2]=0;
				i++;
			}
			q1++;
		}
		p1++;
		q1-=br;
	}
	std::sort(mat.begin(),mat.end(),[](std::vector<decltype(mat[0][0]+mat[0][0])> a,std::vector<decltype(mat[0][0]+mat[0][0])> b){
	if(a[0]<b[0]) return true;
		return false;
	}
	);
	return mat;
}


//SA 5 ARGUMENATA
template <typename t1,typename t2,typename tipf>
auto UvrnutiPresjek(t1 p1,t1 p2,t2 q1,t2 q2,tipf fun)->std::vector<std::vector<decltype(*p1+*p1)> >
{
	int br=q2-q1,n=0,i=0;
	std::vector<std::vector<decltype(*p1+*p1)> > mat;
	while(p1!=p2){
		while(q1!=q2){
			if(fun(*p1)==fun(*q1)){
				n++;
				mat.resize(n);
				mat[i].resize(3);
				mat[i][0]=*p1;
				mat[i][1]=*q1;
				mat[i][2]=fun(*q1);
				i++;
			}
			q1++;
		}
		p1++;
		q1-=br;
	}
	std::sort(mat.begin(),mat.end(),[](std::vector<decltype(mat[0][0]+mat[0][0])> a,std::vector<decltype(mat[0][0]+mat[0][0])> b){
		if(a[2]<b[2]) return true;
		else if(a[2]==b[2]){
			if(a[0]<b[0]) return true;
			else if(a[0]==b[0]){
				if(a[1]<b[1]) return true;
			}
		}
		return false;
	}
	);
	return mat;
}
//5 ARGUMENATA RAZLIKA
template <typename t1,typename t2,typename tipf>
auto UvrnutaRazlika(t1 p1,t1 p2,t2 q1,t2 q2,tipf fun)->std::vector<std::vector<decltype(*p1+*p1)> >{
	int br=q2-q1,n=0,i=0;
	int br1=p2-p1;
	t1 pom1=p1,pom2=p2;
	t2 qom1=q1,qom2=q2;
	std::vector<std::vector<decltype(*p1+*p1)> > mat;
	while(p1!=p2){
		bool tr=true;
		while(q1!=q2){
			if(fun(*p1)==fun(*q1)){
			tr=false;
			}
			q1++;
		}
		if(tr){
			n++;
			mat.resize(n);
			mat[i].resize(2);
			mat[i][0]=*p1;
			mat[i][1]=fun(*p1);
			i++;
		}
		p1++;
		q1-=br;
	}
	
	while(qom1!=qom2){
		bool tr=true;
		while(pom1!=pom2){
			if(fun(*pom1)==fun(*qom1)){
			tr=false;
			}
			pom1++;
		}
		if(tr){
			n++;
			mat.resize(n);
			mat[i].resize(2);
			mat[i][0]=*qom1;
			mat[i][1]=fun(*qom1);
			i++;
		}
		qom1++;
		pom1-=br1;
	}
	std::sort(mat.begin(),mat.end(),[](std::vector<decltype(mat[0][0]+mat[0][0])> a,std::vector<decltype(mat[0][0]+mat[0][0])> b){
		if(a[0]>b[0]) return true;
		else if(a[0]==b[0])
			if(a[1]>b[1]) 
				return true;
		return false;
	}
	);
	return mat;
}
//4 ARGUMENTA RAZLIKA
template <typename t1,typename t2>
auto UvrnutaRazlika(t1 p1,t1 p2,t2 q1,t2 q2)->std::vector<std::vector<decltype(*p1+*p1)> >{
	int br=q2-q1,n=0,i=0;
	int br1=p2-p1;
	t1 pom1=p1,pom2=p2;
	t2 qom1=q1,qom2=q2;
	std::vector<std::vector<decltype(*p1+*p1)> > mat;
	while(p1!=p2){
		bool tr=true;
		while(q1!=q2){
			if(*p1==*q1){
			tr=false;
			}
			q1++;
		}
		if(tr){
			n++;
			mat.resize(n);
			mat[i].resize(2);
			mat[i][0]=*p1;
			mat[i][1]=0;
			i++;
		}
		p1++;
		q1-=br;
	}
	
	while(qom1!=qom2){
		bool tr=true;
		while(pom1!=pom2){
			if(*pom1==*qom1){
			tr=false;
			}
			pom1++;
		}
		if(tr){
			n++;
			mat.resize(n);
			mat[i].resize(2);
			mat[i][0]=*qom1;
			mat[i][1]=0;
			i++;
		}
		qom1++;
		pom1-=br1;
	}
	std::sort(mat.begin(),mat.end(),[](std::vector<decltype(mat[0][0]+mat[0][0])> a,std::vector<decltype(mat[0][0]+mat[0][0])> b){
			if(a[0]>b[0]) 
				return true;
		return false;
	}
	);
	return mat;
}
int main ()
{
	std::cout<<"Unesite broj elemenata prvog kontejnera: ";
	int n1;
	std::cin>>n1;
	std::cout << "Unesite elemente prvog kontejnera: ";
	std::vector<int> v1;
	for(int i=0;i<n1;i++)
	{
		int x;
		std::cin>>x;
		for(int j=0;j<v1.size();j++)
			if(v1[j]==x)  {i--; goto g;} 
		v1.push_back(x);
	g:	continue;
	}
	std::cout<<"Unesite broj elemenata drugog kontejnera: ";
	int n2;
	std::cin>>n2;
	std::cout<<"Unesite elemente drugog kontejnera: ";
	std::vector<int> v2;
	for(int i=0;i<n2;i++)
	{
		int x;
		std::cin>>x;
		for(int j=0;j<v2.size();j++)
			if(v2[j]==x)  {i--; goto h;} 
		v2.push_back(x);
	h:	continue;
	}
	std::cout<<"Uvrnuti presjek kontejnera:"<<std::endl;
	auto rez=UvrnutiPresjek(v1.begin(),v1.end(),v2.begin(),v2.end(),[]( int x){
		int s=0;
		x=abs(x);
		while(x!=0){
			int c=x%10; 
			s+=c; 
			x/=10;
			
		} 
		return s;
		
	}
		);
	for(int i=0;i<rez.size();i++){
		for(int j=0;j<rez[i].size();j++){
			std::cout<<std::setw(6) <<rez[i][j] <<" ";
		}
		std::cout << std::endl;
	}
	auto rez1=UvrnutaRazlika(v1.begin(),v1.end(),v2.begin(),v2.end(),[]( int x){
		int br=0;
	 int c=abs(x);
	for(int i=2;i<=abs(x);i++){
		if(c%i==0){
			while(c%i==0){
				br++;
				c/=i;
			}
		}
	}
	return br;
	});
	
	std::cout << "Uvrnuta razlika kontejnera:" << std::endl;
		for(int i=0;i<rez1.size();i++){
			for(int j=0;j<rez1[i].size();j++){
				std::cout <<std::setw(6)<<rez1[i][j] <<" ";
		}
		std::cout << std::endl;
	}

	std::cout << "Dovidjenja!";
	return 0;
}