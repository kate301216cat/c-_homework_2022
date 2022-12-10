#include <iostream>
#include <vector>
using namespace std;
int Binary_search(vector<int>x, int target) {
    int max = (x.size()) - 1;
    int min = 0;
    int average;
    while (max > min) {
        average = (max + min) / 2;
        if (x[average] == target) {
            return true;
        }
        else if (x[average] > target) {
            max = (average - 1);
        }
        else {
            min = (average + 1);
        }
    }
    return false;
}
int main() {
    setlocale(LC_ALL, "Russian");
    unsigned int i;
    int n;
    vector<int>x;
    cout << "Введите размер массива: ";
    cin >> i;
    cout << "Введите массив через энтер: " << endl;
    while (x.size() < i && cin >> n) {
        x.push_back(n);
    }
    int target;
    cout << "Введите число, которое хотите найти: \n";
    cin >> target;
    if (Binary_search(x, target)) {
        cout << "Ваше число найдено!";
    }
    else {
        cout << "Ваше число не найдено!";
    }
    return 0;
}