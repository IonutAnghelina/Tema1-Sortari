/**
 * QuickSort Algorithm with Random
 * Time complexity: O(n^2)-WorstCase
 * Additional Memory: O(n)-Can be improved to O(1)
 */

#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>
#include<ctime>

using namespace std;
long long n, maxVal, x;
vector<long long> v, aux;


void quickSort(vector<long long> &v, int left, int right) {
    if (left >= right)
        return;

    int length = right - left + 1;

    long long pivot = v[left + (rand() % length)];

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

int main() {
    scanf("%lld", &n);
    scanf("%lld", &maxVal);

    for (int i = 1; i <= n; i++) {
        scanf("%lld", &x);
        v.push_back(x);
    }

    srand(time(0));
    aux.resize(n);

    quickSort(v, 0, n - 1);

    for (auto it:v)
        printf("%lld ", it);

    return 0;
}