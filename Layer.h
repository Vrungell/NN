#pragma once
#include<vector>
#include "MLP.h"
#include <cmath>
class MLP;

class Layer
{
private:
    int number_of_neurons;
    int number_of_neurons_previous;
    int number_of_layer;
    float alpha = 0.1;//for activation
    float delta, gamma;//for shake
    float learning_rate = 0.1;
    std::vector<float>dweights;
    std::vector<std::vector<float>>weights;
    std::vector<float>NET;
    std::vector<float>neurons;//value of activation
    std::vector<float>errors;
    std::vector<float>expected_value;

public:
    Layer(int number, int previous_number, int layernumber);
    std::vector<float>input_value;
    void MakeInputValue(std::vector<float>value);
    void MakeExpectedValue(std::vector<float>value);
    void Start(std::vector<float>image);
    void CountingNET();
    void CountingActivation();
    std::vector<float> GetNeuronsValue();
    void Error(int number_of_layer, MLP &mlp);
    std::vector<float> GetInputValue();
    std::vector<float> GetNET();
    float GetErrors();
    void CountingDw();
    void ChangeWeights();
    ~Layer();
};


