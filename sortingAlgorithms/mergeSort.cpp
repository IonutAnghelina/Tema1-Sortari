/**
 * MergeSort Algorithm
 * Time complexity: O(n*log(n))
 * Additional Memory: O(n)
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

void mergeSort(vector<int> &v, int left, int right) {
    if (left == right)
        return;

    int mid = (left + right) >> 1;

    mergeSort(v, left, mid);
    mergeSort(v, mid + 1, right);

    aux.clear();
    aux.shrink_to_fit();
    aux.resize(right - left + 1);

    //merge(v.begin() + left, v.begin() + mid + 1, v.begin() + mid + 1, v.begin() + right + 1, aux.begin());

    int i = left;
    int j = mid + 1;
    int cnt = 0;

    while (i <= mid && j <= right) {
        if (v[i] < v[j]) {
            aux[cnt++] = v[i];
            i++;
        } else {
            aux[cnt++] = v[j];
            j++;
        }
    }

    while (i <= mid) {
        aux[cnt++] = v[i];
        i++;
    }
    while (j <= right) {
        aux[cnt++] = v[j];
        j++;
    }

    for (int i = left; i <= right; i++)
        v[i] = aux[i - left];

    //copy(aux.begin(), aux.end(), v.begin() + left);

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

        mergeSort(v, 0, n - 1);


        clock_t end = clock();


        realTime += (long double) (end - begin) / CLOCKS_PER_SEC;

        cerr << testSort(v, n) << '\n';

    }

    cerr << "Algoritmul mergeSort a sortat sirurile din acest test in: " << (realTime / 10) * 1000 << "ms in medie"
         << '\n';

    return 0;
}