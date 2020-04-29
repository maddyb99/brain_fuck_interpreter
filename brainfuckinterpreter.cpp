#include <bits/stdc++.h>
#include <stdio.h>
#include <fstream>
using namespace std;

void performAction(char c){
    
}

int main(int argc, char **argv)
{
    if (argc > 2)
    {
        cout << "Expected 1 argument found 2";
        return 1;
    }
    unsigned char cells[30000];
    char ch;
    bool isLooping=false,beginLoop=false;
    vector<char> loopData;
    for (int i = 0; i < 30000; i++)
        cells[i] = 0;
    int index = 0;
    ifstream file;
    file.open(argv[1]);
    while (!file.eof())
    {
        if(isLooping){
            ch=loopData[0];
            loopData.erase(loopData.begin()); 
        }
        else
            file >> ch;
        if(beginLoop)
            loopData.push_back(ch);
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
        case '[':
            if(cells[index]==0)
                break;
            beginLoop=true;
            break;
        case ']':
            if(cells[index]==0){
                isLooping=false;
                beginLoop=false;
                loopData.clear();
                break;
            }
            isLooping=true;
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