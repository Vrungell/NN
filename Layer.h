#pragma once
#include<vector>
#include "MLP.h"
class Layer
{
private:
    int number_of_neurons;
    int number_of_neurons_previous;
    int number_of_layer;
    static float alpha;//for activation
    static float delta, gamma;//for shake
    static float learning_rate;
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
    float Layer::GetErrors();
    void Layer::CountingDw();
    void Layer::ChangeWeights();
    ~Layer();
};


