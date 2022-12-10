#include <iostream>
#include <vector>

using namespace std;


void insertionSort(vector<int> data, int n)
{
    int i, j, t;

    for (i = 1; i < n; i++)
    {
        j = i;
        t = data[i];
        while (j > 0 && t < data[j - 1])
        {
            data[j] = data[j - 1];
            j-= 1;
        }
        data[j] = t;
    }

}

int main()
{
    setlocale(LC_ALL, "Russian");
    vector<int> numbers;
    cout << "Введите размер массива: ";
    int n;
    cin >> n;
    cout << "Введите числа через Enter: ";
    int temp;
    for (int i = 0; i < n; ++i)
    {
        cin >> temp;
        numbers.push_back(temp);

    }
    insertionSort(numbers, n);
    for (auto e : numbers)
    {
        std::cout << e << " ";
    }
}

