#pragma once
#include<vector>
#include "MLP.h"
#include <cmath>
class MLP;

class Layer
{
private:
    int number_of_neurons = 0;
    int number_of_neurons_previous = 0;
    int number_of_layer = 0;
    float alpha = 0.1;//for activation
    float delta, gamma;//for shake
    float learning_rate = 0.1;
    std::vector<float>dweights;
    std::vector<std::vector<float>>weights;
    std::vector<float>NET;
    std::vector<float>neurons;//value of activation
    std::vector<float>errors;
   
public:
    Layer(int number, int previous_number, int layernumber);
    std::vector<float>input_value;
    void MakeInputValue(std::vector<float>&value);
    void MakeExpectedValue(std::vector<float>&value);
    void Start(std::vector<float>&image, MLP mlp);
    void CountingNET(MLP mlp);
    void CountingActivation();
    std::vector<float>& GetNeuronsValue();
    void Error(int number_of_layer, MLP &mlp);
    std::vector<float>& GetInputValue();
    std::vector<float>& GetNET();
    float &GetErrors();
    void CountingDw();
    void ChangeWeights();
    void ClearLayer();
    ~Layer();
};


