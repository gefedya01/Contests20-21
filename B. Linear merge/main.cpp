#include <iostream>
#include <vector>
#include <random>

using std::vector;
using std::cin;
using std::cout;
using std::swap;
using std::endl;
using std::rand;

auto Partition(vector<int>::iterator beg, vector<int>::iterator end) {
    int pivot = *(beg + rand() % (end - beg));
    auto left = beg;
    auto right = end;

    while(true) {
        do {
            --right;
        } while (*right > pivot);

        while (*left < pivot) {
            ++left;
        }
        if (left >= right) {
            return left;
        }
        swap(*right, *left);
        ++left;
    }
}

vector<int> LinearMerge(const vector<int>& first, const vector<int>& second) {
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
    int n, m = 0;
    int number;
    vector<int> first, second;
    std::cin >> n;

    first.reserve(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> number;
        first.emplace_back(number);
    }

    std::cin >> m;
    second.reserve(m);
    for (int i = 0; i < m; ++i)
    {
        cin >> number;
        second.emplace_back(number);
    }

    auto res = LinearMerge(first, second);
    Print(res);
    return 0;
}

