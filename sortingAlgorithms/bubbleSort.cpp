/**
 * BubbleSort Algorithm
 * Time complexity: O(n^2)
 * Additional Memory: O(1)
 */

#include<cstdio>
#include<vector>
#include<ctime>
#include<iostream>
#include<algorithm>

using namespace std;
int n, maxVal, x;
vector<int> aux;

const int base = 4; /**The real base will be 1<<base**/

vector<int> lst[(1 << base) + 5];
const int limit = (1e8);
vector<int> freq;

inline void bubbleSort(vector<int> &v) {
    bool ok;
    int sz = (int) v.size() - 1;
    do {
        ok = 0;
        for (int i = 0; i < sz; i++)
            if (v[i] > v[i + 1]) {
                swap(v[i], v[i + 1]);
                ok = 1;
            }


    } while (ok);
}

inline int testSort(vector<int> &v, int n) {
    for (int i = 0; i < (n - 1); i++)
        if (v[i] > v[i + 1])
            return 0;
    return 1;
}


int main() {


    freopen("batch9.out", "r", stdin);


    int t;

    long double realTime = 0;


    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);
        scanf("%d", &maxVal);

        vector<int> v;

        for (int i = 1; i <= n; i++) {
            scanf("%d", &x);


            v.push_back(x);
        }

        //aux.resize(n);
        //srand(time(0));

        clock_t begin = clock();

        bubbleSort(v);


        clock_t end = clock();


        realTime += (long double) (end - begin) / CLOCKS_PER_SEC;

        cerr << testSort(v, n) << '\n';

    }

    cerr << "Algoritmul bubbleSort a sortat sirurile din acest test in: " << (realTime / 10) * 1000 << "ms in medie"
         << '\n';

    return 0;
}