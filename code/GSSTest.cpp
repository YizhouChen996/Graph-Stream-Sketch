// GSS.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <fstream>
#include <string>
#include "GSS.h"

using namespace std;

int main()
{
    // initialize GSS
    GSS gss(1000, 4, 16, 2, 16, true, 63399);

    // path of dataset
    ifstream fin("\\out.txt");
    string line;

    int count = 0;

    while (fin.eof() == false)
    {
        getline(fin, line);

        // skip non-data line
        if (line[0] > '9' || line[0] < '0')
            continue;

        // number of two nodes
        int pos1 = line.find("\t");
        int pos2 = line.find("\t", pos1 + 1);
        string num1 = line.substr(0, pos1);
        string num2 = line.substr(pos1+1, pos2 - pos1);
        //cout << num1 << " " << num2 << endl;

        // insert an edge
        gss.insert(num1, num2, 1);
        count++;

        // Give a hint every 10000 updates        
        if (count % 10000 == 0)
            cout << count << endl;
    }

    fin.close();

    // path of ground truth
    ifstream fin2("\\ground_truth.txt");

    while (fin2.eof() == false) {
        getline(fin2, line);

        int pos1 = line.find(" ");
        int pos2 = line.find(" ", pos1 + 1);
        string num1 = line.substr(0, pos1);
        string num2 = line.substr(pos1 + 1, pos2 - pos1);
        int result = gss.edgeQuery(num1, num2);

        cout << num1 << " " << num2 << " " << result << endl;
    }

    fin2.close();

    return 0;
}
