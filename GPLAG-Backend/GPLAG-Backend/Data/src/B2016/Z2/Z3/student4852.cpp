#include<iostream>
#include<vector>
#include<iomanip>
#include<algorithm>
#include<type_traits>
#include<deque>
int f(int x){
    int suma=0;
    int c;
    while(x!=0){
        c=abs(x%10);
        x=x/10;
        suma=suma+c;
    }
    return suma;
}
template<typename tip1,typename tip2>
auto UvrnutiPresjek(tip1 p1,tip1 k1,tip2 p2,tip2 k2)->std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>>{
    int n(0);
    std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>>Matrica(n,std::vector<typename std::remove_reference<decltype(*p1)>::type>(3));
 	auto pomocni1(p1);
 	auto pomocni2(p2);
 	typename std::remove_reference<decltype(*p1)>::type output1; 
 	typename std::remove_reference<decltype(*p2)>::type output2;
 	while(pomocni1!=k1){
 	    output1=*pomocni1;
 	    while(pomocni2!=k2){
 	        output2=*pomocni2;
 	        if(output1==output2){
 	            n++;
 	            Matrica.resize(n);
 	            Matrica[n-1].push_back(*pomocni1);
 	            Matrica[n-1].push_back(0);
 	            Matrica[n-1].push_back(0);
 	        }
 	        pomocni2++;
 	    }
 	    pomocni1++;pomocni2=p2;
 	}
 		sort(Matrica.begin(),Matrica.end(),[](std::vector<typename std::remove_reference<decltype(*p1)>::type>a,std::vector<typename std::remove_reference<decltype(*p1)>::type>m){
 	    if(a[2]<m[2])
 	    return true;
 	    else return false;
 	});
 	return Matrica;
 }
 template<typename tip1,typename tip2>
auto UvrnutaRazlika(tip1 p1,tip1 k1,tip2 p2,tip2 k2)->std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>>{
    int n(0);
    std::vector<std::vector<typename std::remove_reference<decltype((*p1))>::type>>Matrica(n,std::vector<typename std::remove_reference<decltype(*p1)>::type>(2));
 	auto pomocni1(p1);
 	int t=1;
 	auto pomocni2(p2);
 	typename std::remove_reference<decltype(*p1)>::type output1; 
 	typename std::remove_reference<decltype(*p2)>::type output2;
 	while(pomocni1!=k1){
 	    t=1;
 	    output1=*pomocni1;
 	    while(pomocni2!=k2){
 	        output2=*pomocni2;
 	        if(output1==output2){
 	            t=0;break;
 	        }
 	        pomocni2++;
 	    }
 	    if(t){
 	       n++;
 	            Matrica.resize(n);
 	            Matrica[n-1].push_back(*pomocni1);
 	            Matrica[n-1].push_back(0); 
 	    }
 	    pomocni1++;pomocni2=p2;
 	}
 	pomocni1=p1;pomocni2=p2;
 	while(pomocni2!=k2){
 	    t=1;
 	    output2=*pomocni2;
 	    while(pomocni1!=k1){
 	        output1=*pomocni1;
 	        if(output2==output1){
 	            t=0;break;
 	        }
 	        pomocni1++;
 	    }
 	    if(t){
 	       n++;
 	            Matrica.resize(n);
 	            Matrica[n-1].push_back(*pomocni2);
 	            Matrica[n-1].push_back(0); 
 	    }
 	    pomocni2++;pomocni1=p1;
 	}
  	sort(Matrica.begin(),Matrica.end(),[](std::vector<decltype(f(*p1))>a,std::vector<decltype(f(*p1))>m){
 	    if(a[0]>m[0]||(a[0]==m[0]&&a[1]>m[1]))
 	    return true;
 	    else return false;
 	});
 	return Matrica;
 }
 template<typename tip1,typename tip2,typename funkcija>
auto UvrnutiPresjek(tip1 p1,tip1 k1,tip2 p2,tip2 k2,funkcija f)->std::vector<std::vector<decltype(f(*p1))>>{
    int n(0);
    std::vector<std::vector<decltype(f(*p1))>>Matrica(n,std::vector<decltype(f(*p1))>(3));
 	auto pomocni1(p1);
 	auto pomocni2(p2);
 	decltype(f(*p1)) output1; 
 	decltype(f(*p2)) output2;
 	while(pomocni1!=k1){
 	    output1=f(*pomocni1);
 	    while(pomocni2!=k2){
 	        output2=f(*pomocni2);
 	        if(output1==output2){
 	            n++;
 	            Matrica.resize(n);
 	            Matrica[n-1].push_back(*pomocni1);
 	            Matrica[n-1].push_back(*pomocni2);
 	            Matrica[n-1].push_back(output1);
 	        }
 	        pomocni2++;
 	    }
 	    pomocni1++;pomocni2=p2;
 	}
 	sort(Matrica.begin(),Matrica.end(),[](std::vector<decltype(f(*p1))>a,std::vector<decltype(f(*p1))>m){
 	    if(a[2]<m[2])
 	    return true;
 	    else return false;
 	});
 	return Matrica;
 }
 template<typename tip1,typename tip2,typename funkcija>
auto UvrnutaRazlika(tip1 p1,tip1 k1,tip2 p2,tip2 k2,funkcija f)->std::vector<std::vector<decltype(f(*p1))>>{
    int n(0);
    int t=1;
    std::vector<std::vector<decltype(f(*p1))>>Matrica(n,std::vector<decltype(f(*p1))>(2));
 	auto pomocni1(p1);
 	auto pomocni2(p2);
 	decltype(f(*p1)) output1; 
 	decltype(f(*p2)) output2;
 	while(pomocni1!=k1){
 	    t=1;
 	    output1=f(*pomocni1);
 	    while(pomocni2!=k2){
 	        output2=f(*pomocni2);
 	        if(output1==output2){
 	            t=0;break;
 	        }
 	        pomocni2++;
 	    }
 	    if(t){
 	         n++;
 	            Matrica.resize(n);
 	            Matrica[n-1].push_back(*pomocni1);
 	            Matrica[n-1].push_back(output1);
 	    }
 	    pomocni1++;pomocni2=p2;
 	}
 		while(pomocni2!=k2){
 	    t=1;
 	    output2=f(*pomocni2);
 	    while(pomocni1!=k1){
 	        output1=f(*pomocni1);
 	        if(output2==output1){
 	            t=0;break;
 	        }
 	        pomocni1++;
 	    }
 	    if(t){
 	         n++;
 	            Matrica.resize(n);
 	            Matrica[n-1].push_back(*pomocni2);
 	            Matrica[n-1].push_back(output1);
 	    }
 	    pomocni2++;pomocni1=p1;
 	}
 	sort(Matrica.begin(),Matrica.end(),[](std::vector<decltype(f(*p1))>a,std::vector<decltype(f(*p1))>m){
 	    if(a[0]>m[0]||(a[0]==m[0]&&a[1]>m[1]))
 	    return true;
 	    else return false;
 	});
 	return Matrica;
 }
int main ()
{
	return 0;
}