// NN.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "MLP.h"
#include "Layer.h"
#include <vector>

using namespace std; 

int _tmain(int argc, _TCHAR* argv[])
{
    int neurons_number[3] = { 1, 10, 1 };
    MLP mlp(neurons_number);
    int j = 0;//counting number of iterations
    while (mlp.LearningIsOK() && mlp.GetEndOfEraTimes()<10) 
    {
        vector<float>image;
        float value;

        while (image.size() < 1){
            cin >> value;
            image.push_back(value);
        }
   
        j++;
        mlp.Start(image);
        vector<float> Evalue;
        Evalue.push_back(sin(value));
        mlp.GetLayer(3).MakeExpectedValue(Evalue);
        mlp.BackPropagation();
        mlp.CountingGeneralError();
        mlp.EndOfEra(j);
        cout << mlp.GetLayer(3).GetNeuronsValue()[0] << endl;
    }
    return 0;
}

