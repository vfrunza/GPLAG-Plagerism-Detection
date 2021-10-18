#include <stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<stack>
using namespace std;
public struct trans {
	int vertex_od;
	int vertex_do;
	char trans_simbol;
};
public class NFA {
public:
	vector<int> vertex;
	vector<trans> transitions;
	int finalnostanje;

	NFA() {

	}

	int broj_vertex() {
		return vertex.size();
	}

	void set_vertex(int no_vertex) {
		for(int i = 0; i < no_vertex; i++) {
			vertex.push_back(i);
		}
	}

	void set_transition(int vertex_od, int vertex_do, char trans_simbol) {
		trans novitrans;
		novitrans.vertex_od = vertex_od;
		novitrans.vertex_do = vertex_do;
		novitrans.trans_simbol = trans_simbol;
		transitions.push_back(novitrans);
	}

	void set_finalnostanje(int fs) {
		finalnostanje = fs;
	}

	int get_finalnostanje() {
		return finalnostanje;
	}

	void display() {
		trans novitrans;
		cout<<"\n";
		for(int i = 0; i < transitions.size(); i++) {
			novitrans = transitions.at(i);
			cout<<"q"<<novitrans.vertex_od<<" --> q"<<novitrans.vertex_do<<" : Simbol - "<<novitrans.trans_simbol<<endl;
		}
		cout<<"\nFinalno stanje je q"<<get_finalnostanje()<<endl;
	}
};



NFA concat(NFA a, NFA b) {
	NFA rezultat;
	rezultat.set_vertex(a.broj_vertex() + b.broj_vertex());
	int i;
	trans novitrans;

	for(i = 0; i < a.transitions.size(); i++) {
		novitrans = a.transitions.at(i);
		result.set_transition(novitrans.vertex_od, novitrans.vertex_do, novitrans.trans_simbol);
	}

	rezultat.set_transition(a.get_finalnostanje(), a.broj_vertex(), '^');

	for(i = 0; i < b.transitions.size(); i++) {
		novitrans = b.transitions.at(i);
		rezultat.set_transition(novitrans.vertex_od + a.broj_vertex(), novitrans.vertex_do + a.broj_vertex(), novitrans.trans_simbol);
	}

	rezultat.set_finalnostanje(a.broj_vertex() + b.broj_vertex() - 1);

	return rezultat;
}


NFA kleene(NFA a) {
	NFA rezultat;
	int i;
	trans novitrans;
	
	rezultat.set_vertex(a.broj_vertex() + 2);

	rezultat.set_transition(0, 1, '^');

	for(i = 0; i < a.transitions.size(); i++) {
		novitrans = a.transitions.at(i);
		rezultat.set_transition(novitrans.vertex_from + 1, novitrans.vertex_to + 1, novitrans.trans_simbol);
	}

	rezultat.set_transition(a.broj_vertex(), a.broj_vertex() + 1, '^');
	rezultat.set_transition(a.broj_vertex(), 1, '^');
	rezultat.set_transition(0, a.broj_vertex() + 1, '^');

	result.set_finalnostanje(a.broj_vertex() + 1);

	return rezultat;
}


NFA or_selection(vector<NFA> selections, int no_of_selections) {
	NFA result;
	int vertex_count = 2;
	int i, j;
	NFA med;
	trans new_trans;

	for(i = 0; i < no_of_selections; i++) {
		vertex_count += selections.at(i).broj_vertex();
	}

	result.set_vertex(vertex_count);
	
	int adder_track = 1;

	for(i = 0; i < no_of_selections; i++) {
		result.set_transition(0, adder_track, '^');
		med = selections.at(i);
		for(j = 0; j < med.transitions.size(); j++) {
			new_trans = med.transitions.at(j);
			result.set_transition(new_trans.vertex_od + adder_track, new_trans.vertex_do + adder_track, new_trans.trans_simbol);
		}
		adder_track += med.broj_vertex();

		result.set_transition(adder_track - 1, vertex_count - 1, '^');
	}

	result.set_finalnostanje(vertex_count - 1);

	return result;
}


NFA re_to_nfa(string re) {
	stack<char> operators;
	stack<NFA> operands;
	char op_sym;
	int op_count;
	char cur_sym;
	NFA *new_sym;
	
	for(string::iterator it = re.begin(); it != re.end(); ++it) {
		cur_sym = *it;
		if(cur_sym != '(' && cur_sym != ')' && cur_sym != '*' && cur_sym != '|' && cur_sym != '.') {
			new_sym = new NFA();
			new_sym->set_vertex(2);
			new_sym->set_transition(0, 1, cur_sym);
			new_sym->set_finalnostanje(1);
			operands.push(*new_sym);
			delete new_sym;
		} else {
			if(cur_sym == '*') {
				NFA star_sym = operands.top();
				operands.pop();
				operands.push(kleene(star_sym));
			} else if(cur_sym == '.') {
				operators.push(cur_sym);
			} else if(cur_sym == '|') {
				operators.push(cur_sym);
			} else if(cur_sym == '(') {
				operators.push(cur_sym);
			} else {
				op_count = 0;
				char c;
				op_sym = operators.top();
				if(op_sym == '(') continue;
				do {
					operators.pop();
					op_count++;
				} while(operators.top() != '(');
				operators.pop();
				NFA op1;
				NFA op2;
				vector<NFA> selections;
				if(op_sym == '.') {
					for(int i = 0; i < op_count; i++) {
						op2 = operands.top();
						operands.pop();
						op1 = operands.top();
						operands.pop();
						operands.push(concat(op1, op2));
					}
				} else if(op_sym == '|'){
					selections.assign(op_count + 1, NFA());
					int tracker = op_count;
					for(int i = 0; i < op_count + 1; i++) {
						selections.at(tracker) = operands.top();
						tracker--;
						operands.pop();
					}
					operands.push(or_selection(selections, op_count+1));
				} else {
					
				}
			}
		}
	}

	return operands.top();
}


int main() {
	NFA a, b;

	cout<<"\nZa regularni izraz : (a)";
	a.set_vertex(2);
	a.set_transition(0, 1, 'a');
	a.set_finalnostanje(1);
	a.display();
//	getch();

	cout<<"\nZa regularni izraz : (b)";
	b.set_vertex(2);
	b.set_transition(0, 1, 'b');
	b.set_finalnostanje(1);
	b.display();
//	getch();

	cout<<"\Za regularni izraz : (a.b)";
	NFA ab = concat(a, b);
	ab.display();
//	getch();

	cout<<"\nZa regularni izraz [Kleene Closure] : (a*)";
	NFA a_star = kleene(a);
	a_star.display();
//	getch();

	cout<<"\nZa regularni izraz [Or] : (a|b)";
	int no_of_selections;
	no_of_selections = 2;
	vector<NFA> selections(no_of_selections, NFA());
	selections.at(0) = a;
	selections.at(1) = b;
	NFA a_or_b = or_selection(selections, no_of_selections);
	a_or_b.display();	
//	getch();

	return 0;
}

