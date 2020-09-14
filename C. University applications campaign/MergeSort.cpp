#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <functional>

using std::vector;
using std::unordered_map;
using std::string;
using std::cin;
using std::cout;
using std::swap;
using std::endl;

//The following is an implementation of stable mergesort algorithm

template<class InputIt1, class InputIt2, class OutputIt, class Cmp> // The different types of input iterators are added for representation purposes
void Merge(InputIt1 first1, InputIt1 last1,
                InputIt2 first2, InputIt2 last2,
                OutputIt d_first, Cmp cmp) {
    while (first1 != last1 && first2 != last2) {
        if (cmp(*first1, *first2)) {
            *d_first = *first1;
            ++first1;
        } else {
            *d_first = *first2;
            ++first2;
        }
        ++d_first;
    }
    while (first2 != last2) {
        *d_first = *first2;
        ++first2;
        ++d_first;
    }
    while (first1 != last1) {
        *d_first = *first1;
        ++first1;
        ++d_first;
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

    std::vector<typename RandomIt::value_type> temp_buf(std::distance(first, last));
    temp_buf.reserve(std::distance(first, last));
    //std::copy(first, last, temp_buf.begin());
    Merge(first, mid, mid, last, temp_buf.begin(), cmp);
    std::copy(temp_buf.begin(), temp_buf.end(), first);
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

    MergeSort(person_score.begin(), person_score.end(), [](const std::pair<std::string, int>& x, const std::pair<std::string, int>& y){return x.second >= y.second;});
    Print(person_score);
    return 0;
}
