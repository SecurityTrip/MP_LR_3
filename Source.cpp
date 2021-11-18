#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 

using namespace std;

void Shell(vector<double>& arr, int n)
{
    int d = n / 2;
    double time1 = clock() / 1000.0;

    while (d > 0)
    {
        for (int i = 0; i < n - d; i++)
        {
            int j = i;
            while (j >= 0 && arr[j] > arr[j + d])
            {
                int temp = arr[j];
                arr[j] = arr[j + d];
                arr[j + d] = temp;

                j--;
            }
        }
        d = d / 2;
    }
}

string txtChek()
{
    string type;
    cout << "Enter the type of vector (from the keyboard: 1/ completely random: 2/ random with a small number of unique values: 3): ";
    cin >> type;
    while ((((type == "1") || (type == "2") || (type == "3")) != 1) || (cin.peek() != '\n'))
    {
        cin.clear(); // используется для очистки буфера ввода от оставшегося мусора
        cin.ignore(4000000, '\n'); // озволяет удалить заданное количество символов из буфера или пока не удалится указанный символ
        cout << "Unidentified operator, try again. Enter the type of vector (from the keyboard: 1/ completely random: 2/ random with a small number of unique values: 3): " << endl;
        cin >> type;
    }
    return type;
}

double check_input()		//проверка ввода чисел													
{
    double in_value;
    cin >> in_value;
    while ((cin.fail()) || (cin.peek() != '\n'))
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Wrong type of input data, try again: "; cin >> in_value;
        cout << endl;
    }
    return in_value;
}

int check_int()		//проверка ввода чисел													
{
    int in_value;
    cin >> in_value;
    while ((cin.fail()) || (cin.peek() != '\n' || in_value <=0))
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Wrong type of input data, try again: "; cin >> in_value;
        cout << endl;
    }
    return in_value;
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

bool frepeat() {

    string repeatt;
    cout << "\nRepeat? (Y/N) " << endl;
    cin >> repeatt;
    while (((repeatt == "Y") || (repeatt == "y") || (repeatt == "N") || (repeatt == "n")) != 1 || (cin.peek() != '\n'))
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Unidentified operator, try again" << endl;
        cout << "Repeat? (Y/N) " << endl;
        cin >> repeatt;
        cout << endl;
    }
    if (repeatt == "Y" || repeatt == "y")
    {
        return true;
    }
    else
    {
        return false;
    }
}


int main() 
{
    cout.precision(10);
    bool repeat = true;

    while (repeat) 
    {
        vector<double> array;
        vector<double> arrayLib;
        double k;
        cout << "Enter the vector numbers: ";
        int n = check_int();
        string vec_type = txtChek();

        if (vec_type == "1")
        {
            
            for (int i = 0; i < n; i++)
            {
                k = check_input();
                array.push_back(k);
            }
            cout << "Initial vetor: ";
            for (int i = 0; i < n; i++)
                cout << array[i] << " ";
            cout << endl;
        }

        if (vec_type == "2")
        {
            
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

        if (vec_type == "3")
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
        arrayLib = array;

        double start = clock();

        vector<double> sorted = Shell(array,array.size());

        start = clock() - start;
        cout << endl;

       

        cout << "Sorted with function: ";
        if (sorted.size() < 15)
            for (int i = 0; i < sorted.size(); i++)
                cout << sorted[i] << " ";
        else
            for (int i = 0; i < 15; i++)
                cout << sorted[i] << " ";
        cout << endl;
        cout << "Sorting function time: " << start / CLOCKS_PER_SEC << endl;

        double startLib = clock();
        sort(arrayLib.begin(), arrayLib.end());
        startLib = clock() - startLib;
        

        cout << "Sorted with library: ";
        if (arrayLib.size() < 15)
            for (int i = 0; i < arrayLib.size(); i++)
                cout << arrayLib[i] << " ";
        else
            for (int i = 0; i < 15; i++)
                cout << arrayLib[i] << " ";
        cout << endl;
        cout << "Sorting library time: " << startLib / CLOCKS_PER_SEC << endl;

        if ((startLib / CLOCKS_PER_SEC) - (int)(startLib / CLOCKS_PER_SEC) == 0)
            cout << "Acceleration insignificant" << endl;
        else
            cout << "Speed up library sorting: " << (start / CLOCKS_PER_SEC) / (startLib / CLOCKS_PER_SEC) << endl;

        repeat = frepeat();
    }
}
