#include<bits/stdc++.h>

using namespace std;

typedef struct state {
    double singles[4];
} state;

void print_digits(int n, int d[4]) {
    for(int i = 0; i < n; i++)
        cout << d[i] << " ";
    cout << endl;
}

void print_state(state e) {
    for(int i = 0; i < 4; i++)
        cout << e.singles[i] << " ";
    cout << endl;
}

int get_state(int idx, int d[4]) {
    int copy_d[4] = {d[0], d[1], d[2], d[3]};
    int n = 0, m = 1;

    copy_d[idx]--;
    for(int i = idx + 1; i < 4; i++)
        copy_d[i]++;

    for(int i = 3; i >= 0; i--) {
        n += copy_d[i] * m;
        m *= 10;
    }
    
    return n;
}

void add_states(vector<state>& E, int a, int b, double s) {
    for(int i = 0; i < 4; i++) 
        E[a].singles[i] += s * E[b].singles[i];
}

void update_single(vector<state>& E, int n, int d[4]) {
    for(int i = 3; i > 0; i--) {
        E[n].singles[i] = E[n].singles[i - 1];
    }
    E[n].singles[0] = 0;
}

vector<int> update_children(int n, vector<state>& E) {
    int d[4], copy_n = n;
    vector<int> ret;

    for(int i = 3; i >= 0; i--) {
        d[i] = copy_n % 10;
        copy_n /= 10;
    }

    int sum = d[0] + d[1] + d[2] + d[3];
    if(sum == 1)
        update_single(E, n, d);

    for(int i = 0; i < 4; i++) {
        if(d[i] == 0)
            continue;

        int k = get_state(i, d);
        add_states(E, k, n, (double) d[i] / (double) sum);
        ret.push_back(k);
    }

    return ret;
}

int main() {
    vector<state> E (2000);
    set<int> curr {1111};

    E[1111].singles[0] = 1.;

    for(int k = 1; k < 15; k++) {
        cout << k << endl;
        set<int> next;

        for(int i : curr) {
            cout << i << " - ";
            vector<int> children = update_children(i, E);
            for(int child : children)
                next.insert(child);
            print_state(E[i]);
        }

        curr = next;
    }

    print_state(E[1]);

    double singles = 0.;
    
    for(int i = 1; i < 4; i++) {
        singles += i * E[1].singles[i];
    }

    cout << "\n" << singles << endl;

    return 0;
}

