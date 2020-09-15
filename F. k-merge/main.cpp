#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::swap;
using std::endl;


template <class Cont>
void Print(const Cont& arr) {
    for(const auto& i : arr)
        std::cout << i << ' ';
}

int main()
{
    int n_i, k, number, S;
    std::cin >> k;

    vector<vector<int>> matrix(k);
    S = 0;
    for (int i = 0; i < k; ++i)
    {
        cin >> n_i;
        S += n_i;
        auto& vec = matrix[i];
        for (int j = 0; j < n_i; ++j)
        {
            cin >> number;
            vec.emplace_back(number);
        }
    }

    std::vector<int> output_vec;
    output_vec.reserve(S);

    auto cmp = [](const auto& lhs,const auto& rhs){return lhs.second > rhs.second;};
    std::priority_queue<std::pair<std::pair<typename vector<int>::iterator, typename vector<int>::iterator>, int>,
            std::vector<std::pair<std::pair<typename vector<int>::iterator, typename vector<int>::iterator>, int>>, decltype(cmp)> min_heap(cmp);
    for (int j = 0; j < k; ++j)
    {
        auto& temp = matrix[j];
        min_heap.push({{temp.begin(), temp.end()}, temp[0]});
    }

    for (int l = 0; l < S; ++l)
    {
        auto current = min_heap.top();
        min_heap.pop();
        output_vec.emplace_back(current.second);
        if (++current.first.first != current.first.second) {
            current.second = *current.first.first;
            min_heap.push(current);
        }
    }
    Print(output_vec);
    return 0;
}

