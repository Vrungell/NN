// NN.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "MLP.h"
#include "Layer.h"
#include <vector>
#include <fstream>
#include <cstdio>

using namespace std; 

int _tmain(int argc, _TCHAR* argv[])
{
    ifstream fin("C:\\Users\\user\\Documents\\Visual Studio 2013\\Projects\\NN\\NN\\input.txt", ios::in);
    ofstream finforgraphic("C:\\Users\\user\\Documents\\Visual Studio 2013\\Projects\\NN\\NN\\inputforgraphic.txt", ios::out);
    ofstream fout("C:\\Users\\user\\Documents\\Visual Studio 2013\\Projects\\NN\\NN\\output.txt", ios::out);
    float value;
    std::vector<float> values;
    while (fin >> value) {
        values.push_back(value);
    }
    int neurons_number[3] = { 1, 10, 1 };
    MLP mlp(neurons_number);
    int j = 0;//counting number of iterations
    int i = 0;
  
    while (mlp.GetEndOfEraTimes()<10)
    {
        vector<float>image;
        if (i == 50) i = 0;
        image.push_back(values[i]);
        i++;//номер элемента из файла
        j++;//номер итерации
        mlp.Start(image);
        image.clear();
        vector<float> Evalue;
        Evalue.push_back(sin(values[i]));
        mlp.expected_value = Evalue;
        mlp.BackPropagation();
        mlp.CountingGeneralError();
        mlp.EndOfEra(j);
        Evalue.clear();
        cout << mlp.GetLayer(3).GetNeuronsValue()[0];
       // cout << mlp.GetLayer(3).GetNET()[0];
        mlp.ClearLayers();
    }
    i = 0;
    while (i < 51)
    {
        vector<float>image;
        image.push_back(values[i]);
        mlp.Start(image);
        fout << mlp.GetLayer(3).GetNeuronsValue()[0];
        image.clear();
        i++;
        mlp.ClearLayers();
    }
    fin.close();
    fout.close();
    return 0;
}

