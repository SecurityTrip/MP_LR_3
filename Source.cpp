#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 

using namespace std;

vector<double> sort(vector<double> mass) {
    
    int i, j, step;
    int n = mass.size();
    int tmp;
    for (step = n / 2; step > 0; step /= 2)
        for (i = step; i < n; i++)
        {
            tmp = mass[i];
            for (j = i; j >= step; j -= step)
            {
                if (tmp < mass[j - step])
                    mass[j] = mass[j - step];
                else
                    break;
            }
            mass[j] = tmp;
        }
    return mass;
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
    double in_value;
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
    bool repeat = true;
    

    while (repeat) 
    {
        vector<double> array;
        cout << "Enter the vector numbers: ";
        int n = check_int();
        vector<double> arrayLib;
        double k;
        
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

        vector<double> sorted = sort(array);

        double end = clock();

        double mySort = (end - start) / CLOCKS_PER_SEC;

        for (int i = 0; i < 20; i++)
            cout << array[i] << " ";
        cout << endl;
        cout << "Sorting time: " << mySort << endl;

        double startLib = clock();
        sort(arrayLib.begin(), arrayLib.end());
        double  endLib = clock();
        double LibSort = (endLib - startLib) / CLOCKS_PER_SEC;

        for (int i = 0; i < 20 - 1; i++)
            cout << arrayLib[i] << " ";
        cout << endl;
        cout << "Sorting time: " << LibSort << endl;

        if (LibSort - (int)LibSort == 0)
            cout << "Acceleration insignificant" << endl;
        else
            cout << "Speed up library sorting: " << mySort / LibSort << endl;

        repeat = frepeat();
    }

}
