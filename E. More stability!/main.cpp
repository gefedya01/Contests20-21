#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <functional>

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::swap;
using std::endl;

template<class RandomIt, class Cmp>
void InplaceMerge(RandomIt first1, RandomIt last1,
                  RandomIt first2, RandomIt last2, Cmp cmp) {
    if (!cmp(*first2, *std::prev(last1)) || first1 == last1 || first2 == last2) {
        return;
    }

    if (last1 - first1 >= last2 - first2) {
        RandomIt mid1 = first1 + std::distance(first1, last1) / 2;
        RandomIt lb = std::lower_bound(first2, last2, *mid1, cmp);
        auto it = std::rotate(mid1, first2, lb);

        InplaceMerge(first1, mid1, mid1, it, cmp);
        InplaceMerge(it, lb, lb, last2, cmp);
    } else {
        RandomIt mid2 = first2 + std::distance(first2, last2) / 2;
        RandomIt lb = std::upper_bound(first1, last1, *mid2, cmp);
        auto it = std::rotate(lb, first2, mid2);

        InplaceMerge(first1, lb, lb, it, cmp);
        InplaceMerge(it, mid2, mid2, last2, cmp);
    }
}

template<class RandomIt, class Cmp>
void MergeSort(RandomIt first, RandomIt last, Cmp cmp) {
    if (last == std::next(first)) {
        return;
    }
    RandomIt mid = std::next(first, std::distance(first, last) / 2);
    MergeSort(first, mid, cmp);
    MergeSort(mid, last, cmp);
    InplaceMerge(first, mid, mid, last, cmp);
}

template <class Cont>
void Print(const Cont& arr) {
    for(const auto& i : arr)
        std::cout << i.first << std::endl;
}



int main()
{
    int n = 0;
    std::string name;
    std::string surname;
    std::vector<std::pair<std::string, int>> person_score;
    std::cin >> n;

    person_score.reserve(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> name;
        cin >> surname;
        int inf, math, rus = 0;
        cin >> inf >> math >> rus;
        person_score.emplace_back(name + ' ' + surname, inf + math + rus);
    }

    MergeSort(person_score.begin(), person_score.end(), [](const auto& lhs,
                                                           const auto& rhs){return lhs.second > rhs.second;});
    Print(person_score);
    return 0;
}
