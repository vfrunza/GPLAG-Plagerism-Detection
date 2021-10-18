void najduzi_bp(char*s1, char* s2)
{ 
	char* temp1=s1;
	char*temp2=s1;
	char*cuva=s1;
	char*pocetaks2=s2;
	int brojac=0;

	int max=0;
	char*krajnja_pozicija=s1;
	while(*s1!='\0'){

	if((*s1>='a' && *s1<='z') || (*s1>='A' && *s1<='Z')){ 
		cuva=s1;
		temp2=s1;
		temp1=s1;
		temp2++;
		while(temp1<temp2){
			if(*temp2==*temp1)
			break;
			else 
			brojac++;
			temp1++;
		}
		while(temp1>cuva){
			temp1--;
		}
		

	}s1++;}
	max=brojac;
	brojac=0;
	while(*s1!='\0'){
		if(*s1>'a' && *s1<'z'){
			krajnja_pozicija=s1;
		cuva=s1;
		pocetaks2=s1;
		temp2=s1;
		temp1=s1;
		temp2++;
		while(temp1<temp2){
			if(*temp2==*temp1)
			break;
			else 
			brojac++;
			temp1++;
		}
		while(temp1>cuva){
			temp1--;
		}
			krajnja_pozicija++;
		}
		s1++;
	}

	if(brojac>max){
	max=brojac;
	brojac=0;
	while(cuva<krajnja_pozicija){
		*cuva=*s2;
		cuva++;
		s2++;
	}
	}
	while(s2>pocetaks2){
		s2--;
	}
}
	int main(void){
		return 0;
	}