// ConsoleApplication20.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;


int main()
{
    setlocale(LC_ALL, "Russian");

    int   points, starting_point, end_point;

    cout << "Введите: количество дорог, начальную точку и конечную точку " << endl;
    cin >> points >> starting_point >> end_point;

    starting_point--;
    end_point--;

    cout << "\n";

    vector <vector <int> > roads(points, vector <int>(points));

    ifstream input("road_map.txt");

    for (int i = 0; i < points; i++) {
        roads.push_back(vector<int>());

        for (int j = 0; j < points; j++) {


            input >> roads[i][j];
            cout << roads[i][j] << "\t";

        }

        cout << "\n" << "\n";
    }

    vector <int> point_distance(points, numeric_limits<int>::max());

    point_distance[starting_point] = 0;

    priority_queue <pair <int, int > > length_and_top;

    length_and_top.push(make_pair(0, starting_point));

    while (!length_and_top.empty()) {

        int que_len = -length_and_top.top().first;

        int ver = length_and_top.top().second;

        length_and_top.pop();

        if (que_len > point_distance[ver]) continue;

        for (int i = 0; i < points; i++) {

            int to = i;

            int length = roads[ver][i];

            if (point_distance[to] > point_distance[ver] + length && length >= 0) {
                point_distance[to] = point_distance[ver] + length;
                length_and_top.push(make_pair(-point_distance[to], to));
            }
        }
    }

    if (point_distance[end_point] == numeric_limits<int>::max()) {

        cout << "Не попадаем";
    }

     else cout << point_distance[end_point];
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
