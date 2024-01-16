#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(std::time(0)); 

    int n = 10; 
    std::vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        v[i] = std::rand() % 100; 
    }

    int ak = std::rand() % 100; 
    int bk = ak + std::rand() % 100; 

    std::cout << "Згенеровані числа ak та bk: " << ak << ", " << bk << std::endl;
    std::cout << "Згенерований масив: ";
    for (int i = 0; i < n; ++i) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;

    int firstPositiveIndex = -1;
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] > 0) {
            firstPositiveIndex = i;
            break;
        }
    }

    if (firstPositiveIndex == -1) {
        std::cout << "Немає позитивних елементів у векторі" << std::endl;
        return 0;
    }

    int maxElementIndex = -1;
    for (int i = firstPositiveIndex + 1; i < v.size(); ++i) {
        if (v[i] >= ak && v[i] <= bk) {
            if (maxElementIndex == -1 || v[i] > v[maxElementIndex]) {
                maxElementIndex = i;
            }
        }
    }

    if (maxElementIndex == -1) {
        std::cout << "Немає елементів у заданому діапазоні після першого позитивного елемента" << std::endl;
    } else {
        std::cout << "Індекс першого максимального елемента у заданому діапазоні після першого позитивного елемента: " << maxElementIndex << std::endl;
    }

    return 0;
}