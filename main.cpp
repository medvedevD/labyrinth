#include <iostream>
#include <math.h>
#include <cmath>
#include <string>
#include <ctime>
#include <windows.h>
#include <stdio.h>
using namespace std;
int main(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 11));
    setlocale(0, "rus");
    srand(time(0));
    string b[1000],t="p";
    int a = 1, c[1000], c1 = 2, n, k = 0,height=0,width=0;
    while (height % 2 == 0 || width % 2 == 0 || height < 5 || width < 5 || (height + 2)*(width + 2) >= 1000 || width>70){
        cout << "Enter height and width" << endl;
        cin >> height >> width;
    }
    height += 2;
    width += 2;
    for (int x = 0; x < height*width; x++){
        b[x] = " ";
        if (x < width)b[x] = "X";
        if (x>height*width-width-1)b[x] = "X";
        if (x % width == 0)b[x] = "X";
        if (x % width == width-1)b[x] = "X";
    }
    while (a%2==1)
       a = rand() % (width-4)+width*height-width+2;
    b[a] = ".";
    b[a-width] = ".";
    a = 1;
    while (a%2==1)
       a = rand() % (width-4)+2;
    b[a] = ".";
    b[a+width] = ".";
    a += width*2;
    cout << 1;
    while (c1>1){
        int a1 = a;
        if (k < 15){
            c[c1] = a;
            c1++;
        }
        b[a] = ".";
        k = 0;
        while (a1 == a && k<15){
            n = rand() % 4 + 1;
            if (n == 1 && b[a + 2] ==" ")a++;
            if (n == 2 && b[a + width*2] ==" ")a += width;
            if (n == 3 && b[a - width*2] ==" " )a -= width;
            if (n == 4 && b[a - 2] ==" ")a--;
            k++;
        }
        if (k == 15){
            c[c1 - 1] = 0;
            c1 -= 2;
            a = c[c1];
            c1++;
        }
        if (a>0)
            b[a] = ".";
        if (a < 0)
            c1 = 0;
        if (k < 15){
            if (n == 1)a++;
            if (n == 2)a += width;
            if (n == 3)a -= width;
            if (n == 4)a--;
            b[a] = ".";
        }
    }
    b[width*2] = "X";
    for (int x = 0; x < width*height; x++){
        if (b[x] == "X")b[x] = "";
        if (b[x] == " ")b[x] = "X";
        if (x>width * 2||x<width)
             if (b[x] == ".")b[x] = " ";
    }
    system("CLS");
    for (int x = 0; x < width*height; x++){
        cout << b[x];
        if (x % width == width-1)
            cout << endl;
    }
    //Прохождение
    int a1,a2,m[1000],j,h=0;
    c1 = 0;
    cout << "want to follow the progress? y/n ";
    while (h==0){
        cin >> t;
        if (t == "y"){
            h = 1;
            j = 0;
        }
        if (t == "n"){
            h = 1;
            j = 1;
        }
    }
    k = j;
    for (int x = 0; x < width; x++){
        for (int y = 0; y < width*height; y++)
            b[y] = b[y + 1];
    }
    for (int x = 0; x < width;x++)
        if (b[x] == ".")
            a = x;
    for (int x = width*(height-3)-1; x < width*(height-2); x++)
        if (b[x] == " ")
            a1 = x;
    for (int x = 0; x < 1000; x++)
        c[x] = 0;
       b[a] = ".";
    while (a != a1){
        if (k == 0){
            system("CLS");
            for (int x = 0; x < width*height; x++){
                cout << b[x];
                if (x % width == width - 1)
                    cout << endl;
            }
            Sleep(150);
        }
        n = 0;
        a2 = a;
        while (a2 == a){
            n++;
            k = j;
            if (n == 1 && b[a - width] ==" "&&a - width>0&&m[a-width]!=666)a -= width;
            if (n == 2 && b[a - 1] == " "&&m[a -1] != 666)a--;
            if (n == 3 && b[a + 1] == " "&&m[a +1] != 666)a++;
            if (n == 4 && b[a + width] == " "&&m[a + width] != 666)a += width;
            if (n == 5){
                k = 1;
                n = 0;
                c1--;
                b[a] = " ";
                m[a] = 666;
                c1--;
                a = c[c1];
                c1++;
            }
        }
        b[a] = ".";
        c[c1] = a;
        c1++;

    }
    system("CLS");
    for (int x = 0; x < width*height; x++){
        if (b[x] == ".")
            SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 14));
        cout << b[x];
        if (x % width == width - 1)
            cout << endl;
        SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 11));
    }
    return 0;
}
