#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cassert>

using std::cin;
using std::cout;
using std::swap;
using std::endl;

template<class RandomIt>
void InplaceMerge(RandomIt first1, RandomIt last1,
           RandomIt first2, RandomIt last2) {
    if (*std::prev(last1) <= *first2 || first1 == last1 || first2 == last2) {
        return;
    }

    if (last1 - first1 >= last2 - first2) {
        RandomIt mid1 = first1 + std::distance(first1, last1) / 2;
        RandomIt lb = std::lower_bound(first2, last2, *mid1);
        auto it = std::rotate(mid1, first2, lb);

        InplaceMerge(first1, mid1, mid1, it);
        InplaceMerge(it, lb, lb, last2);
    } else {
        RandomIt mid2 = first2 + std::distance(first2, last2) / 2;
        RandomIt lb = std::lower_bound(first1, last1, *mid2);
        auto it = std::rotate(lb, first2, mid2);

        InplaceMerge(first1, lb, lb, it);
        InplaceMerge(it, mid2, mid2, last2);
    }
}

template <class Cont>
void Print(const Cont& arr) {
    for(const auto& i : arr)
        std::cout << i << ' ';
}

int main()
{
    int n, num = 0;
    std::cin >> n;
    std::vector<int> arr;

    arr.reserve(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> num;
        arr.emplace_back(num);
    }

    int m = 0;
    std::cin >> m;
    arr.reserve(n + m);
    for (int i = 0; i < m; ++i)
    {
        cin >> num;
        arr.emplace_back(num);
    }

    InplaceMerge(arr.begin(), arr.begin() + n, arr.begin() + n, arr.end());
    Print(arr);
    return 0;
}
