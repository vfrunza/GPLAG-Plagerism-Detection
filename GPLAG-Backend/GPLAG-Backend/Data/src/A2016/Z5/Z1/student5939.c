#include <stdio.h>
#include <string.h>


struct Student {
	char ime[20], prezime [20];
	int ocjene[50];
	int br_ocjena;
};


static struct Student* m1 = NULL;
static struct Student* m2 = NULL;
static struct Student* m3 = NULL;
static struct Student* s;
    
double prosjek_ocjena(struct Student student) {
	int i;
	double suma = 0;
	
	for (i = 0; i < student.br_ocjena; i++) {
		
		if (student.ocjene[i] == 5)
		    return 5.0;
		    
	    suma = suma + student.ocjene[i];
	
	}
	
	if (student.br_ocjena == 0)  
	    return 5.0;
	
	return suma / student.br_ocjena;
	
}


int genijalci(struct Student* student, int vel, double prosjek) {
	
    int i = 0;
    int j = 0;
    int status = 1;
    
 
    
    for(i=0; i < vel; i++) {
    	if (prosjek_ocjena(student[i]) < prosjek) {
    	    for (j=i; j < vel - 1; j++ )
    	        student[j] = student[j + 1];
    	
    	
        vel = vel - 1;
        i = i - 1;
       }
    }
    
    s = student;
    
    while (s < student + vel) {
    	
    	if (status) {
    		m1 = s;
    		status = 0;
    	}
    	
    	else if (prosjek_ocjena(*s) > prosjek_ocjena(*m1)) m1 = s;
    	
    	else if (prosjek_ocjena(*s) == prosjek_ocjena(*m1)) {
    	        if (strcmp(s->prezime, m1->prezime) == 0) {
    	            if(strcmp(s->ime, m1->ime) < 0)
    	                m1 = s;
    	        }
    	else if (strcmp(s->prezime, m1->prezime) < 0) m1=s; 
    	}
    	    
       s++;
    }
    
    status = 1;
    s = student;
    
    
    while (s < student + vel) {
        
        if (s == m1) {
    		s++;
    		continue;
    	}
    	
    	if (status) {
    		m2 = s;
    		status = 0;
    	}
    	
    	else if (prosjek_ocjena(*s) > prosjek_ocjena(*m2)) m2 = s;
    	    
    	
    	else if (prosjek_ocjena(*s) == prosjek_ocjena(*m2)) {
    	    if (strcmp(s->prezime, m2->prezime) == 0) {
    	        if (strcmp(s->ime, m2-> ime) < 0)
    	            m2 = s;
    	    }
    	    
    	   else if (strcmp(s->prezime, m2->prezime) < 0)  m2 = s;
    	}
    	s++;
    	    
    }
    
    
    status = 1;
    s = student;
    
    while (s < student + vel) {
    	
    	if (s == m1 || s==m2) {
    		s++;
    		continue;
    	}
    	
    	
    	if (status) {
    		m3 = s;
    		status = 0;
    	}
    	
    	
    	else if (prosjek_ocjena(*s) > prosjek_ocjena(*m3))
    	    m3 = s;
    	   
           
       else if (prosjek_ocjena(*s) == prosjek_ocjena(*m3)) {
           if (strcmp(s->prezime, m3->prezime) == 0) {
               if (strcmp(s->ime, m3->ime) < 0)
                   m3 = s;
           }
           
        else if (strcmp(s->prezime, m3->prezime) < 0)
           m3 = s;
       }
       
       s++;
       
    }
    
    
    if (m1 != NULL) 
        printf("%s %s\n", m1->prezime, m1->ime);
    if (m2 != NULL) 
        printf("%s %s\n", m2->prezime, m2->ime);
    if (m3 != NULL) 
        printf("%s %s\n", m3->prezime, m3->ime);
    return vel;    
}

int main() {
    
    return 0;	
}