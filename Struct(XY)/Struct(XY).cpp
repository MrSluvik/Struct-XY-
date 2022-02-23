// 1. Створіть структуру, що описує точку у двовимірній системі координат (x, y). За допомогою цієї структури задайте дві точки.
//Напишіть функцію, яка обчислює відстань між цими двома точками.
//Єдиною умовою є зчитування даних з файлу і запис даних в файл
#include <iostream>
#include<fstream>
#include<Windows.h>
#include<math.h>
using namespace std;

double length(int x1, int y1, int x2, int y2);//ф-н обчислення відстані між точками

struct XY
{    
    int x = 0;
    int y = 0;
 
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int a1, b1, c1, g1;
    ofstream fileI;
    fileI.open("D:/Users8/Я/Desktop/text.txt");
    cout << "Введіть x1, y1, x2, y2 "<<endl;
    cin >> a1 >> b1 >> c1 >> g1;
    fileI << a1 <<" " << b1 << " " << c1 << " " << g1;//запис в файл координати точок
    fileI.close();
    int a, b, c, g;
    double dov = 0;//змінна для довжини
    ifstream fileOut;
    fileOut.open("D:/Users8/Я/Desktop/text.txt");
    fileOut >> a >> b >> c >> g;//зчитування координати з файлу
    XY firstpoint;
    firstpoint.x=a;
    firstpoint.y = b;

    XY secondpoint;
    secondpoint.x=c;
    secondpoint.y =g;

    dov=length(firstpoint.x, firstpoint.y, secondpoint.x, secondpoint.y);//присвоюємо значення функції змінній
    cout << "Довжина між точками = " << dov;//виводимо довжину в консоль
    fileOut.close();

    ofstream fileIn;
    fileIn.open("D:/Users8/Я/Desktop/text.txt");
    fileIn <<"\nДовжина між точками = "<< dov;//запис в файл довжини між точками
    fileIn.close();

    return 0;
}
double length(int x1, int y1, int x2, int y2) {
    double d = 0;
    d = sqrt(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1)));
    return d;

}
