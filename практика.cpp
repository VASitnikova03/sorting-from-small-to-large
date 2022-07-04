#include <iostream>
#include <string>
using namespace std;


void print_menu()
{
    system("cls"); // очищаем экран
    cout << "Что вы хотите сделать?" << endl;
    cout << "1. Упорядочить по возрастанию" << endl;
    cout << "2. Упорядочить по убыванию" << endl;
    cout << "3. Выйти" << endl;
    cout << ">";
}


int get_variant(int count)
{
    int variant;
    string s; // строка для считывания введённых данных
    getline (cin, s); // считываем строку
    // пока ввод некорректен, сообщаем об этом и просим повторить его
    while (sscanf(s.c_str(), "%d", &variant) != 1 || variant < 1 || variant > count)
    {
        cout << "Некоректный ввод. Попробуйте снова: "; // выводим сообщение об ошибке
        getline(cin, s); // считываем строку повторно
    }
    return variant;
}


int findSmallestPosition(int list[], int startPosition, int listLength)//находим наименьшее число в массиве
{
    int smallestPosition = startPosition;//начальное число = наименьшее

    for (int i = startPosition; i < listLength; i++)// сравниваем со следующим числом 
    {
        if (list[i] < list[smallestPosition])//если меньше, то оно минимальное
            smallestPosition = i;
    }
    return smallestPosition;//возрващаем наименьшее число
}

int findBigestPosition(int list[], int startPosition, int listLength)//находим наибольшее число в массиве
{
    int bigestPosition = startPosition;//начальное число = наибольшее

    for (int i = startPosition; i < listLength; i++)// сравниваем со следующим числом 
    {
        if (list[i] > list[bigestPosition])//если больше, то оно максимальное
            bigestPosition = i;
    }
    return bigestPosition;//возрващаем наибольшее число
}

void selectionDecreasing(int list[], int listLength)//сортировка выбора по возрастанию
{
    for (int i = 0; i < listLength; i++)
    {
        int smallestPosition = findSmallestPosition(list, i, listLength);// записываем наименьшее значение 
        swap(list[i], list[smallestPosition]);//меняем местами наш элемент с наименьшим 
    }
    return;
}


void selectionDecreasing1(int list[], int listLength)//сортировка выбора по убыванию
{
    for (int i = 0; i < listLength; i++)
    {
        int bigestPosition = findBigestPosition(list, i, listLength);// записываем наибольшее значение 
        swap(list[i], list[bigestPosition]);//меняем местами наш элемент с наибольшим 
    }
    return;
}


int main()
{
    setlocale(LC_ALL, "Russian");
    int variant; // выбранный пункт меню
    int n;
    do
    {
        print_menu();

        variant = get_variant(4); // получаем номер выбранного пункта меню

        switch (variant)
        {
        case 1: {
            cout << "Введите размер массива" << endl;
            cin >> n;
            if (n <= 0) //если размер массива <=0 сообщаем об ошибке
            {
                cout << "Некоректный ввод. Попробуйте снова: " << endl;
                break;
            }
            cout << "Введите " << n << " целых чисел через пробел: ";
            int* list = new int[n];    // создаем динамический массив
            for (int i = 0; i < n; i++) {
                cin >> list[i]; // считываем числа в ячейки массива
            }
            selectionDecreasing(list, n);//сортировка по возрастанию 
            cout << "Полученный массив:" << endl;
            for (int i = 0; i < n; i++) //проходим от первого до последнего элемента полученного массива
                cout << list[i] << '\t';//выводим его
            cout << endl;
            break; }
        case 2: {
            cout << "Ведите размер массива" << endl;
            cin >> n;
            if (n <= 0) //если размер массива <=0 сообщаем об ошибке
            {
                cout << "Некоректный ввод. Попробуйте снова: " << endl;
                break;
            }
           // getchar();
            cout << "Введите " << n << " целых чисел через пробел: ";
            int* list = new int[n];    // создаем динамический массив
            for (int i = 0; i < n; i++) {
                cin >> list[i];  // считываем числа в ячейки массива
            }
            selectionDecreasing1(list, n);//сортировка по убыванию
            cout << "Полученный массив:" << endl;
            for (int i = 0; i < n; i++) //проходим от первого до последнего элемента полученного массива
                cout << list[i] << '\t';//выводим его
            cout << endl;
            break; }

        }

        if (variant != 3) 
            system("pause");
    } while (variant != 3);
    return 0;
}