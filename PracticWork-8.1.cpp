#include <iostream>
#include <cmath>
#include <iomanip> // для setprecision

using namespace std;

int main()
{
    //S = V(0) * t + (a * t'2) / 2
    //V = V(0) + a * t
    //a = F / m
    //дано: F m t
    //найти: S 
    //

    float speed; // V
    float speed0; // V
    float distance; // S
    int time; // t
    float weight; // m
    float acceleration; // a
    int power; // F

    cout << "Все данные в международной системе единиц СИ!!!\n";
    cout << "Дробные значения вводятся через точку!\n";
    cout << "-----------*****------------\n";
    cout << "Введите скорость пепелаца в метрах в секунду\n";
    cin >> speed0;
    cin.ignore(100, '\n');
    //cout << "Скорость: " << speed << " м/с\n";    
    cout << "Введите силу тяги в Ньютонах\n";
    cin >> power;
    cin.ignore(100, '\n');
    do {
        cout << "Введите массу пепелаца в килограммах\n";
        cin >> weight;
        cin.ignore(100, '\n');
        if (weight <= 0) cout << "Масса всегда положительное значение!\n";
    } while (weight <= 0);
    cout << "Введите расчётное время в секундах\n";
    cin >> time;
    cin.ignore(100, '\n');
    cout << "-----------ИТОГО------------\n";
    cout << fixed << setprecision(1); //точность после запятой, что бы числа красиво выводились.
    if (speed0 > 1000) {
        cout << "Скорость: " << speed0 / 1000 << " км/с\n";
    }
    else cout << "Скорость: " << speed0 << " м/с\n";
    if (power > 1000) {
        cout << "Сила: " << power / 1000 << " кН\n";
    }
    else cout << "Сила: " << power << " Н\n";
    if (weight > 10000) {
        cout << "Масса: " << weight / 1000 << " кг\n";
    }
    else cout << "Масса: " << weight << " кг\n";
    if (time > 3600) {
        cout << "Время: " << time / 3600 << " ч" << time % 60 << " мин\n";
    }
    else if (time > 60) {
        cout << "Время: " << time / 60 << " мин " << time % 60 << " с\n";
    }
    else cout << "Время: " << time << " с\n";
    cout.unsetf(ios::fixed); //отменяю все изменения, потому что дальше точность важнее красоты. я хотел бы всегда сделать красоту, но не знаю как.
    cout << "------Произвожу расчёт------\n";
    cout << setprecision(4); //решил всё таки ограничить, потому что я не знаю какие примерные значения на входе и на выходе. 
    //у меня все значения получаются в формате 1.234 х 10^3 мне это не нравится, по этому ввёл ограничение на точность. 
    // в принципе кроме дистанции другие данные выводить не надо, просто для практики
    //a = F / m
    acceleration = (float)power / weight;
    cout << "Ускорение пепелаца: " << acceleration << " м/с*с\n";
    //V = V(0) + a * t
    speed = speed0 + acceleration * (float)time;
    if (speed > 1000) {
        cout << "Скорость пепелаца: " << speed / 1000 << " км/с\n";
    }
    else cout << "Скорость пепелаца: " << speed << " м/с\n";
    //S = V(0) * t + (a * t'2) / 2
    distance = speed0 * (float)time + (acceleration * pow(time, 2) / 2);
    distance = fabs(distance);
    if (distance > 1000) {
        cout << "Пройденное расстояние: " << distance / 1000 << " км\n";
    }
    else cout << "Пройденное расстояние: " << distance << " м\n";


    return 0;
}