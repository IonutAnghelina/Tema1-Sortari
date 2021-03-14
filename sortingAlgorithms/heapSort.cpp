/**
 * heapSort Algorithm
 * Time complexity: O(nlog(n))
 * Additional Memory: O(1)
 */

#include<cstdio>
#include<vector>
#include<algorithm>
#include<ctime>
#include<iostream>

using namespace std;

int n, maxVal, x;


inline void lift(vector<int> &v, int pos) {
    while (pos > 0) {
        if (v[pos] < v[(pos - 1) / 2]) {
            swap(v[pos], v[(pos - 1) / 2]);
            pos = (pos - 1) / 2;
        } else break;
    }
}

inline void drown(vector<int> &v, int length) {
    int currentPos = 0;

    while (currentPos < (length - 1)) {
        int leftSon = 2 * currentPos + 1;
        int rightSon = 2 * currentPos + 2;
        if (leftSon >= length) break;

        if (v[leftSon] >= v[currentPos] && (rightSon >= length || (v[rightSon] >= v[currentPos])))
            break;

        if (rightSon >= length || (v[leftSon] < v[rightSon])) {
            swap(v[currentPos], v[leftSon]);
            currentPos = leftSon;
        } else {
            swap(v[currentPos], v[rightSon]);
            currentPos = rightSon;
        }

    }
}

inline void heapSort(vector<int> &v) {

    int length = (int) v.size();


    for (int i = 0; i < length; i++)
        lift(v, i);


    int currentLength = length;
    for (int i = 0; i < currentLength; i++) {
        swap(v[0], v[length - 1]);
        length--;
        drown(v, length);
    }

    reverse(v.begin(), v.end());


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

        heapSort(v);

        clock_t end = clock();


        realTime += (long double) (end - begin) / CLOCKS_PER_SEC;


    }

    cerr << "Algoritmul heapSort a sortat sirurile din acest test in: " << (realTime / 10) * 1000 << "ms in medie"
         << '\n';

    return 0;
}