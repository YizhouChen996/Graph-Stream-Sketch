// GSS.cpp : ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
//

#include <iostream>
#include <fstream>
#include <string>
#include "GSS.h"

using namespace std;

int main()
{
    freopen("result4.txt", "w", stdout);
    // initialize GSS
    GSS gss(148, 4, 16, 2, 16, false, 63399);

    // path of dataset
    ifstream fin("./out.txt");
    string line;
    
    getline(fin, line);
    
    int count = 0;

    while (fin.eof() == false)
    {
        getline(fin, line);

        // skip non-data line
        
        /*
        if (line[0] > '9' || line[0] < '0')
            continue;
        */

        // number of two nodes
        int pos1 = line.find("\t");
        int pos2 = line.find("\t", pos1+1);
        string num1 = line.substr(0, pos1);
        string num2 = line.substr(pos1+1, pos2-pos1-1);
        //cout << num1 << " " << num2 << endl;

        // insert an edge
        gss.insert(num1, num2, 1);

        /*
        if(gss.buffer.size()!=0)
            cout<<gss.buffer.size()<<endl;
        */

        count++;

        // Give a hint every 10000 updates        
        if (count % 10000 == 0)
            cout << count << endl;
    }

    fin.close();

    // path of ground truth
    // ifstream fin2("\\ground_truth.txt");
    ifstream fin2("./out.txt");
    getline(fin2, line);


    while (fin2.eof() == false) {
        getline(fin2, line);

        int pos1 = line.find("\t");
        int pos2 = line.find("\t", pos1+1);
        string num1 = line.substr(0, pos1);
        string num2 = line.substr(pos1+1, pos2-pos1-1);
        int result = gss.edgeQuery(num1, num2);
        //cout<<gss.buffer.size()<<endl;
        cout << num1 << " " << num2 << " " << result <<endl;
        //printf("The result of (%s,%s) is %d", num1.c_str(), num2.c_str(), result);
    }

    fin2.close();

    return 0;
}
