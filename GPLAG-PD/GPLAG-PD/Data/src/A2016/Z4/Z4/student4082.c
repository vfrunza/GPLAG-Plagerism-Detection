#include <stdio.h>
#include <limits.h>
#include <math.h>

int remove_range(char *s, int left, int right){
	int i, len = _strlen(s);
	for(i = left; i <= len; i++){
		s[i] = s[i+(right-left) + 1];
	}
	
	return _strlen(s);
}

void unesi(char niz[], int velicina){
	char znak = getchar();
	int i = 0;
	if(znak == '\n') znake = getchar();
	while(i < velicina -1 && znak != '\n'){
		niz[i] = znak;
		i++;
		znak = getchar();
	}
	 niz[i] = '\0';
}

int _strlen(char *s){
	int len = 0;
	if(s[0] == '\0') return len;
	while(s[++len] != '\0');
	return len;
}

int _isdigit(char c){
	if('0' <= c && c <= '9') return 1;
	else return 0;
}


int to_digit(char c){
	return (int)(c-'0');
}

char equal(double x, double y){
	if(fabs(x) < 0.000001) x = 0;
	if(fabs(y) < 0.000001) y = 0;
	
	return fabs(x-y) <= 0.000001 * (fabs(x) + fabs(y));
}

char contains(double x, double y, double x1, double y1, double x2, double y2){
	return ((x1 < x || equal(x1, x2)) && (x < x2 || equal(x, x2))
			&& (y1 < y || equal(y1, y2)) && (y < y2 || equal(y, y2)));
}

double get_double(char *p, char *f, char delim){
	char *s = p;
	char modif = 1;
	if(p[0] == '\0'){
		*f = -1;
		return 0;
	}else if(p[0] == '-'){
		modif = -1;
		p++;
	}
	
	int a = 0;
	double aa = 0;
	while(_isdigit(*p)){
		a = 10 * a + to_digit(*p);
		p++;
	}
	
	if(*p == delim){
		*f = p - s;
		return a;
	}else if(*p != '.'){
		*f = -1;
		return 0;
	}
	
	p++;
	
	if(*p == delim){
		*f = p - s;
		return a * modif;
	}
	
	
	double mul = 0.1;
	
	while(_isdigit(*p)){
		aa += mul * to_digit(*p);
		mul /= 10.0;
		p++;
	}
	
	if(*p != delim){
		*f = -1;
		return 0;
	}
	
	*f = p - s;
	
	return modif * (a + aa);
	
}

char* obuhvat(char *text, double x1, double y1, double x2, double y2){
	int i, j, ind = 0, remove_count = 0, len = _strlen(text);
	char last = 0;
	
	if(!len) return NULL;
	
	char *carry = text;
	
	for(i = 0; i < len && !last; i++){
		double a, b;
		int off = 0;
		if(text[i++] != '(') return NULL;
		
		char f; 
		
		a = get_double(text + i, &f, ',');
		
		if(!f) return NULL;
		
		i+=f+1;
		off += f+1;
		
		if(last && text[i+1] != '\0') return NULL;
		if(text[i] == ')') last = 1;
		else if(text[i] != ',') return NULL;
		
		printf("off: %d\n", off);
		getchar();
		
		if(!contains(a,b,x1,y1,x2,y2)) remove_range(text, i -remove_count,i-remove_count+off);
	}
	
	printf("done\n");
}


int main(){
	
}