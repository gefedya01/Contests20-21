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

void QuickSort(vector<int>::iterator beg, vector<int>::iterator end) {
    if (beg < end)
    {
        auto it = Partition(beg, end);
        if (it > beg + 1) {
            QuickSort(beg, it);
        }
        if (it + 1 < end) {
            QuickSort(it, end);
        }
    }
}

void Print(const vector<int>& arr) {
    for(int i = 0; i < arr.size(); ++i)
        std::cout << arr.at(i) << ' ';
}

int main()
{
    int n, number = 0;
    vector<int> arr;
    std::cin >> n;

    arr.reserve(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> number;
        arr.emplace_back(number);
    }
    QuickSort(arr.begin(), arr.end());
    Print(arr);

    return 0;
}
