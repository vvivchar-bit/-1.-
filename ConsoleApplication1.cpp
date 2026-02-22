#include <iostream>
#include <list>
#include <iomanip>
#include <cmath>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::list<double> lst;
    bool hasLessThanMinus3 = false;

    for (int i = 0; i < n; ++i) {
        double x;
        std::cin >> x;
        lst.push_back(x);
        if (x < -3.0) hasLessThanMinus3 = true;
    }

    if (hasLessThanMinus3) {
        // якщо є хоча б один елемент < -3, то всі від'ємні замінити квадратами
        for (double& x : lst) {
            if (x < 0.0) x = x * x;
        }
    }
    else {
        // інакше всі елементи помножити на 0.1
        for (double& x : lst) {
            x *= 0.1;
        }
    }

    // Вивід у зворотньому порядку: an, an-1, ..., a1
    std::cout << std::fixed << std::setprecision(6);
    for (auto it = lst.rbegin(); it != lst.rend(); ++it) {
        std::cout << *it;
        if (std::next(it) != lst.rend()) std::cout << " ";
    }
    std::cout << "\n";

    return 0;
}
