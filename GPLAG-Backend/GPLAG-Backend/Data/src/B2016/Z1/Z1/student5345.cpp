#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstdlib>

typedef long long ll;

struct node { /* racuna se u predznanje iz OR-a */
	ll val;
	node *left, *right;
};

bool insert(node** n, ll val) {
	if ((*n) == NULL) {
		*n = (node*) std::malloc(sizeof(node));
		(*n)->left = (*n)->right = NULL;
		(*n)->val = val;
		return true;
	}
	
	if (val < (*n)->val) {
		return insert(&(*n)->left, val);
	}
	
	if (val > (*n)->val) {
		return insert(&(*n)->right, val);
	}
	
	return false;
}

void free_tree(node** n) {
	if ((*n) == NULL) return;
	free_tree(&(*n)->left);
	free_tree(&(*n)->right);
	std::free(*n);
}


bool JelOpak(ll n) {
	if (n == 0) return false;
	
	int tmp[3] = {0};
	n = std::abs(n);
	
	while (n > 0) {
		tmp[n % 3]++;
		n /= 3;
	}
	
	for (int i = 0; i < 3; i++) {
		if (tmp[i] & 1) return false;
	}
	
	return true;
}

bool JelOdvratan(ll n) {
	if (n == 0) return true;
	
	int tmp[3] = {0};
	n = std::abs(n);
	
	while (n > 0) {
		tmp[n % 3]++;
		n /= 3;
	}
	
	for (int i = 0; i < 3; i++) {
		if (!(tmp[i] & 1) && tmp[i] > 0) return false;
	}
	
	return true;
}

bool unutra(std::vector<int>* v, int n) {
	for (int i = 0; i < v->size(); i++) {
		if (v->at(i) == n) return true;
	}
	
	return false;
}

std::vector<int> IzdvojiGadne(std::vector<int> v, bool koe) {
	//node *tree = NULL;
	std::vector<int> ret;
	
	for(int i = 0; i < v.size(); i++) {
		if (koe) {
			if (JelOpak(v[i])) {
				//if (insert(&tree, v[i])) ret.push_back(v[i]);
				if (!unutra(&ret, v[i])) ret.push_back(v[i]);
			}
		}
		else {
			if (JelOdvratan(v[i])) {
				//if (insert(&tree, v[i])) ret.push_back(v[i]);
				if (!unutra(&ret, v[i])) ret.push_back(v[i]);
			}
		}
	}
	
	//free_tree(&tree);
	
	return ret;
}

int main() {
	int n;
	std::vector<int> ulaz;
	
	std::printf("Unesite brojeve (0 za prekid unosa): ");
	while (std::scanf("%d", &n) == 1 && n != 0) {
		ulaz.push_back(n);
	}
	
	std::vector<int> opaki = IzdvojiGadne(ulaz, true);
	std::vector<int> odvratni = IzdvojiGadne(ulaz, false);
	
	std::printf("Opaki: ");
	for (int i = 0; i < opaki.size(); i++) {
		std::printf("%d ", opaki[i]);
	}
	
	std::printf("\nOdvratni: ");
	for (int i = 0; i < odvratni.size(); i++) {
		std::printf("%d ", odvratni[i]);
	}
	
	std::printf("\n");

	return 0;
}