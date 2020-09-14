#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using std::vector;
using std::unordered_map;
using std::cin;
using std::cout;
using std::swap;
using std::endl;

template< class InputIt1, class InputIt2, class OutputIt >
OutputIt merge( InputIt1 first1, InputIt1 last1,
                InputIt2 first2, InputIt2 last2,
                OutputIt d_first ) {
    auto it_first = first1;
    auto it_second = first2;

    while (it_first != last1 && it_second != last2) {
        while (it_first != last1 && *it_first <= *it_second) {
            vec.emplace_back(*it_first);
            d_first = 
            ++it_first;
        }
        if (it_first == first.end()) {
            while (it_second != second.end()) {
                vec.emplace_back(*it_second);
                ++it_second;
            }
            break;
        }

        while (it_second != second.end() && *it_second <= *it_first) {
            vec.emplace_back(*it_second);
            ++it_second;
        }

        if (it_second == second.end()) {
            while (it_first != first.end()) {
                vec.emplace_back(*it_first);
                ++it_first;
            }
            break;
        }
    }
}

auto ComponentMergeSort(const unordered_map<std::string, int>& first, const unordered_map<std::string, int>&) {
    vector<int> vec;
    vec.reserve(first.size() + second.size());

    auto it_first = first.begin();
    auto it_second = second.begin();

    while (it_first != first.end() && it_second != second.end()) {
        while (it_first != first.end() && *it_first <= *it_second) {
            vec.emplace_back(*it_first);
            ++it_first;
        }
        if (it_first == first.end()) {
            while (it_second != second.end()) {
                vec.emplace_back(*it_second);
                ++it_second;
            }
            break;
        }

        while (it_second != second.end() && *it_second <= *it_first) {
            vec.emplace_back(*it_second);
            ++it_second;
        }

        if (it_second == second.end()) {
            while (it_first != first.end()) {
                vec.emplace_back(*it_first);
                ++it_first;
            }
            break;
        }
    }
    return vec;
}

void Print(const vector<int>& arr) {
    for(int i : arr)
        std::cout << i << ' ';
}



int main()
{
    int n = 0;
    std::string name;
    std::string surname;
    std::unordered_map<std::string, int> person_score;
    std::cin >> n;

    person_score.reserve(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> name;
        cin >> surname;
        int inf, math, rus = 0;
        cin >> inf >> math >> rus;
        person_score[name + ' ' + surname] = inf + math + rus;
    }

    auto res = LinearMerge(first, second);
    Print(res);
    return 0;
}


