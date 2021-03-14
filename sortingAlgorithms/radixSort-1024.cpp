/**
 * RadixSort Algorithm with base: 1024
 * Time complexity: O(n*(maxVal/1024))-WorstCase
 * Additional Memory: O(n)-Can be improved to O(1)
 */

#include<cstdio>
#include<vector>
#include<ctime>
#include<iostream>

using namespace std;
int n, maxVal, x;

const int base = 10; /**The real base will be 1<<base**/

vector<int> lst[(1 << base) + 5];

void radixSort(vector<int> &v, int maxVal) {
    int pw = 0;


    while ((1LL << pw) <= maxVal) {
        for (int i = 0; i < (1 << base); i++) {
            lst[i].clear();
            lst[i].shrink_to_fit();
        }

        for (auto it:v) {
            long long key = (it >> pw) & ((1 << base) - 1);
            lst[key].push_back(it);

        }

        int cnt = 0;

        for (int i = 0; i < (1 << base); i++)
            for (auto it:lst[i])
                v[cnt++] = it;
        pw += base;

    }

}

inline int testSort(vector<int> &v, int n) {
    for (int i = 0; i < (n - 1); i++)
        if (v[i] > v[i + 1])
            return 0;
    return 1;
}


int main() {


    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);

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


        clock_t begin = clock();

        radixSort(v, maxVal);

        clock_t end = clock();


        realTime += (long double) (end - begin) / CLOCKS_PER_SEC;

        //cerr<<testSort(v,n)<<'\n';

    }

    cerr << "Algoritmul radixSort a sortat sirurile din acest test in: " << (realTime / 10) * 1000 << "ms in medie"
         << '\n';

    return 0;
}