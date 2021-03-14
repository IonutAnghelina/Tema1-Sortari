/**
 * QuickSort Algorithm without Random
 * Time complexity: O(n^2)-WorstCase
 * Additional Memory: O(n)-Can be improved to O(1)
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

void quickSort(vector<int> &v, int left, int right) {
    if (left >= right)
        return;

    int length = right - left + 1;

    long long pivot = v[left];

    int leftIndex = left, rightIndex = right;


    for (int i = left; i <= right; i++)
        if (v[i] < pivot) aux[leftIndex++] = v[i];
        else if (v[i] > pivot) aux[rightIndex--] = v[i];

    for (int i = left; i <= right; i++)
        v[i] = aux[i];

    for (int i = leftIndex; i <= rightIndex; i++)
        v[i] = pivot;

    quickSort(v, left, leftIndex - 1);
    quickSort(v, rightIndex + 1, right);


}

inline int testSort(vector<int> &v, int n) {
    for (int i = 0; i < (n - 1); i++)
        if (v[i] > v[i + 1])
            return 0;
    return 1;
}


int main() {


    freopen("batch11.out", "r", stdin);
//    freopen("data.out", "w", stdout);

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

        aux.resize(n);
        clock_t begin = clock();

        quickSort(v,0,n-1);


        clock_t end = clock();


        realTime += (long double) (end - begin) / CLOCKS_PER_SEC;

        //cerr<<testSort(v,n)<<'\n';

    }

    cerr << "Algoritmul quickSort a sortat sirurile din acest test in: " << (realTime / 10) * 1000 << "ms in medie"
         << '\n';

    return 0;
}