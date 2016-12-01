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
    int neurons_number[3] = { 1, 10, 1 };
    MLP mlp(neurons_number);
    int j = 0;//counting number of iterations
    int i = 0;
  
    while (mlp.LearningIsOK())
    {
        i++;
        vector<float>image;
        float value;

        while (image.size() < 1){
            fin >> value;
            fout << value;
            image.push_back(value);

        }
   
        j++;
        mlp.Start(image);
        image.clear();
        fout<<mlp.GetLayer(3).GetNeuronsValue()[0];
        vector<float> Evalue;
        Evalue.push_back(sin(value));
        mlp.expected_value = Evalue;
        mlp.BackPropagation();
        mlp.CountingGeneralError();
        mlp.EndOfEra(j);
        Evalue.clear();
       // cout << mlp.GetLayer(3).GetNET()[0];
        mlp.ClearLayers();
    }
    fin.close();
    fout.close();
    return 0;
}

