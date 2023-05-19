#include <chrono>
class Timer {
public:
    Timer() : start_time_(std::chrono::high_resolution_clock::now()) {}

    ~Timer() {
        auto end_time = std::chrono::high_resolution_clock::now();
        std::cout << "Time: "
            << std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time_).count()
            << " microseconds" << std::endl;
    }

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start_time_;
};

#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <array>
#include <algorithm>
#include <random>

int main() {
    const int size = 1000000; // размер контейнеров
    std::vector<int> v(size);
    std::deque<int> d(size);
    std::list<int> l(size);
    std::array<int, size> a;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, size);

    // заполняем контейнеры случайными числами
    for (int i = 0; i < size; i++) {
        int val = dis(gen);
        v[i] = val;
        d[i] = val;
        l.push_back(val);
        a[i] = val;
    }
    {Timer t;
        std::sort(v.begin(), v.end());
    }
    {Timer t;
        std::sort(d.begin(), d.end());
    }
    {Timer t;
        l.sort();
    }
    {Timer t;
        std::sort(a.begin(), a.end());
    }
    return 0;
}