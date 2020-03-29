#include <iostream>
#include <stdio.h>
#include <fstream>
using namespace std;

int main(int argc, char **argv)
{
    if (argc > 2)
    {
        cout << "Expected 1 argument found 2";
        return 1;
    }
    unsigned char cells[30000];
    char ch;
    for (int i = 0; i < 30000; i++)
        cells[i] = 0;
    int index = 0;
    ifstream file;
    file.open(argv[1]);
    while (!file.eof())
    {
        file >> ch;
        if (file.eof())
            break;
        // cout << ch;
        switch (ch)
        {
        case '+':
            cells[index]++;
            // cout << cells[index];
            break;
        case '-':
            cells[index]--;
            // cout << int(cells[index]);
            break;
        case '.':
            // cout << cells[index];
            putchar(cells[index]);
            // cout << endl;
            break;
        case ',':
            cells[index] = getchar();
            break;
        case '>':
            index++;
            if (index == 30000)
                index = 0;
            break;
        case '<':
            index--;
            if (index == -1)
                index = 30000 - 1;
            break;
        default:
            continue;
        }
    }
    return 0;
}