#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
using std::cout; using std::list; using std::vector; using std::swap; using std::iterator;

list<int> mergelistver(list<int> A, list<int> B)
{
    list<int> C(A.size() + B.size());
    auto i = A.begin(), j = B.begin(), k = C.begin();
    while (i != A.end() && j != B.end()) {
        if (*i < *j) {
            *k++ = *i++;
        }
        else {
            *k++ = *j++;
        }
    }
    for (; i != A.end(); ++i) {
        *k++ = *i;
    }
    for (; j != B.end(); ++j) {
        *k++ = *j;
    }

    return C;
}

void Merge(vector<int>& v, int l, int m, int h)
{
    static vector<int> v2;
    int i = l, j = m + 1;
    while (i <= m && j <= h) {
        v[i] <= v[j] ? v2.push_back(v[i++]) : v2.push_back(v[j++]);
    }
    while (i <= m) {
        v2.push_back(v[i++]);
    }
    while (j <= h) {
        v2.push_back(v[j++]);
    }
    for (int i = l; i <= h; ++i) {
        v[i] = v2[i - l];
    }
    v2.clear();
}

void MergeSort(vector<int>& v, int l, int h)
{
    if (l < h) {
        const int m = (l + h) / 2;
        MergeSort(v, l, m);
        MergeSort(v, m + 1, h);
        Merge(v, l, m, h);
    }
}

int Partition(vector<int> &v, int l, int h)
{
    const int pivot = v[l];
    int i = l, j = h;
    while (i < j) {
        do {
            ++i;
        } while (v[i] <= pivot);
        do {
            --j;
        } while (v[j] > pivot);
        if (i < j) {
            swap(v[i], v[j]);
        }
    }
    swap(v[l], v[j]);

    return j;
}

void QuickSort(vector<int> &v, int l, int h)
{
    if (l < h) {
        const int j = Partition(v, l, h);
        QuickSort(v, l, j);
        QuickSort(v, j + 1, h);
    }
}

int main()
{
    vector<int> sorted {5, 8, 2, 3, 7, 1, 0, 9, 10, 4, 11, 6};
    QuickSort(sorted, 0, sorted.size());
    for (int val : sorted) {
        cout << val << " ";
    }
    cout << "\n";
    vector<int> sortedmerge {5, 8, 2, 3, 7, 1, 0, 9, 10, 4, 11, 6};
    MergeSort(sortedmerge, 0, sortedmerge.size() - 1);
    for (int val : sortedmerge) {
        cout << val << " ";
    }
}