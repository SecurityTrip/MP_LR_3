#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 

using namespace std;




int checkInt()
{
    int a;
    cout << "Enter the number of elements: ";
    cin >> a;
    while (a <= 0)
    {
        cin.clear(); // используется для очистки буфера ввода от оставшегося мусора
        cin.ignore(4000000, '\n'); // озволяет удалить заданное количество символов из буфера или пока не удалится указанный символ
        cout << "Incorrect input. Please, try again. Enter the number of elements: ";
        cin >> a;
    }
    while ((cin.fail()) || (cin.peek() != '\n'))// cin.fail проверяет, произошло ли считывание. Если возникла ошибка и значение потока теперь fail, cin.fail возвращает true
    {
        if ((cin.fail()) || (cin.peek() != '\n'))// cin.peek читает символ из потока, но не убирает его оттуда
        {
            cin.clear(); // используется для очистки буфера ввода от оставшегося мусора
            cin.ignore(4000000, '\n'); // озволяет удалить заданное количество символов из буфера или пока не удалится указанный символ
            cout << "Incorrect input. Please, try again. Enter the number of elements: ";
            cin >> a;
        }
    }
    return a;
}

double random() {
    double Sum = 0;
    for (int i = 0; i <= 5; i++)
    {
        int sign = rand() % 2;
        if (sign == 0)
            Sum = Sum + rand();
        if (sign == 1)
            Sum = Sum - rand();
    }
    for (int i = 0; i <= 2; i++)
    {
        int sign = rand() % 2;
        if (sign == 0)
            Sum = Sum / rand();
        if (sign == 1)
            Sum = Sum * rand();
    }
    return Sum;
}

int main()
{
    string repeat = "Y";
    while ((repeat == "Y") || (repeat == "y"))
    {
        int n = checkInt();
        string type = txtChek();
        srand(time(NULL));
        cout.precision(14);
        double k;
        vector<double> array;
        vector<double> arrayBib;

        if (type == "1")
        {
            cout << "Enter the vector numbers: ";
            for (int i = 0; i < n; i++)
            {
                cin >> k;
                array.push_back(k);
            }
            cout << "Initial vetor: ";
            for (int i = 0; i < n; i++)
                cout << array[i] << " ";
            cout << endl;
        }

        if (type == "2")
        {
            cout << "Enter the vector numbers: " << endl;
            for (int i = 0; i < n; i++)
                array.push_back(random());
            cout << "Initial vetor: ";
            if (n < 15)
                for (int i = 0; i < n; i++)
                    cout << array[i] << " ";
            else
                for (int i = 0; i < 15; i++)
                    cout << array[i] << " ";
            cout << endl;
        }

        if (type == "3")
        {
            int l = n;
            for (int i = 0; i < l; i++) {
                double rand2 = random();
                int z = l / 3 + 1;
                for (int k = (rand() + 1) % z; k > 0; k--) {
                    array.push_back(rand2);
                    l--;
                }
                array.push_back(rand2);
            }
            cout << "Initial vetor: ";
            if (n < 15)
                for (int i = 0; i < n; i++)
                    cout << array[i] << " ";
            else
                for (int i = 0; i < 15; i++)
                    cout << array[i] << " ";
            cout << endl;
        }

        arrayBib = array;

        double start = clock();
        for (int i = 1; i < n; i++)
            for (int j = i; j > 0 && array[j - 1] > array[j]; j--)
                swap(array[j - 1], array[j]);
        double end = clock();
        double mySort = (end - start) / CLOCKS_PER_SEC;
        cout << "The vector obtained using my sort: ";
        if (n < 15)
            for (int i = 0; i < n; i++)
                cout << array[i] << " ";
        else
            for (int i = 0; i < 15; i++)
                cout << array[i] << " ";
        cout << endl;
        cout << "My sorting time: " << mySort << endl;

        double startBib = clock();
        sort(arrayBib.begin(), arrayBib.end());
        double  endBib = clock();
        double bibSort = (endBib - startBib) / CLOCKS_PER_SEC;
        cout << "Vector obtained using biblical sorting: ";
        if (n < 15)
            for (int i = 0; i < n; i++)
                cout << arrayBib[i] << " ";
        else
            for (int i = 0; i < 15; i++)
                cout << arrayBib[i] << " ";
        cout << endl;
        cout << "Library sort time: " << bibSort << endl;

        if (bibSort - (int)bibSort == 0)
            cout << "Acceleration insignificant" << endl;
        else
            cout << "speed up library sorting: " << mySort / bibSort << endl;

        repeat = repChek();
    }
}
