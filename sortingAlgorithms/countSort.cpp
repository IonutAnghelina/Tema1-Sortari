/**
 * CountingSort Algorithm
 * Time complexity: O(n+maxVal)
 * Additional Memory: O(maxVal)
 */

#include<cstdio>
#include<vector>
#include<ctime>
#include<iostream>

using namespace std;
int n, maxVal, x;
vector<int> aux;

const int base = 4; /**The real base will be 1<<base**/

vector<int> lst[(1 << base) + 5];
const int limit = (1e8);
vector<int> freq;

inline void countSort(vector<int> &v, int maxVal) {

    if (maxVal > limit) {
        printf("The array could not be sorted because the values are too large\n");
        return;
    }

    freq.resize(maxVal + 1);
    freq.shrink_to_fit();
    fill(freq.begin(), freq.end(), 0);

    for (auto it:v)
        freq[it]++;

    v.clear();
    v.shrink_to_fit();

    for (int i = 0; i <= maxVal; i++)
        for (int j = 1; j <= freq[i]; j++)
            v.push_back(i);

}

inline int testSort(vector<int> &v, int n) {
    for (int i = 0; i < (n - 1); i++)
        if (v[i] > v[i + 1])
            return 0;
    return 1;
}


int main() {


    freopen("batch11.out", "r", stdin);


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

        countSort(v, maxVal);


        clock_t end = clock();


        realTime += (long double) (end - begin) / CLOCKS_PER_SEC;

        cerr << testSort(v, n) << '\n';

    }

    cerr << "Algoritmul countSort a sortat sirurile din acest test in: " << (realTime / 10) * 1000 << "ms in medie"
         << '\n';

    return 0;
}