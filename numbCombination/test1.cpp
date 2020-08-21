//https://ideone.com/L8Nlzd

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
 
template <typename T>
void Combination(const std::vector<T>& v, std::size_t count)
{
    assert(count <= v.size());
    std::vector<bool> bitset(v.size() - count, 0);
    bitset.resize(v.size(), 1);
 
    do {
        for (std::size_t i = 0; i != v.size(); ++i) {
            if (bitset[i]) {
                std::cout << v[i] << " ";
            }
        }
        std::cout << std::endl;
    } while (std::next_permutation(bitset.begin(), bitset.end()));
}
 
int main() {
	 std::vector<int> v; //= {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    v.push_back(0);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);
    v.push_back(8);
    v.push_back(9);
 
	Combination(v, 5);
}