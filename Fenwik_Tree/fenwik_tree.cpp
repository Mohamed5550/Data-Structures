#include <bits/stdc++.h>
using namespace std;

vector <long long> fenwik_tree;
vector <int> v;
int n;

int lsb(int i) {
    // Getting least significant bit by anding with (~i+1) or (-i)
    return i & -i;
}

void build() {
    // We can iterate and "update()" on each step but this will build in O(nlogn)
    // Instead we go from down to top and change only the directly affected parent of the current index in O(n)

    for(int i = 1; i <= n; i ++) {
        fenwik_tree[i] += v[i];
        if(i+lsb(i) <= n)
            fenwik_tree[i+lsb(i)] += fenwik_tree[i];
    }
    cout << "\n";
}

void update(int i, int x) {
    // We update the current index
    // Then we update all the affected parents of it
    // Each parent is the next level which can be reached by adding the LSB

    v[i] = x;
    while(i <= n) {
        fenwik_tree[i] += x;
        i += lsb(i);
    }
}

long long prefix_sum(int i) {
    // We get the prefix sum from i to 1 by going from each step to the next step of it
    // Each step can be reached by removing the LSB

    long long res = 0;
    while(i > 0) {
        res += fenwik_tree[i];
        i -= lsb(i);
    }

    return res;
}

long long range(int i, int j) {
    return prefix_sum(i) - prefix_sum(j-1);
}

int main() {
    cin >> n;

    v.assign(n+1, 0);
    for(int i = 1; i <= n; i ++) cin >> v[i];

    fenwik_tree.assign(n+1, 0);
    build();

    cout << range(5, 2) << "\n";

    // set second element to 3
    update(2, 3-v[2]);

    cout << range(5, 2) << "\n";
}