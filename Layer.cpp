#include "stdafx.h"
#include <vector>
#include "Layer.h"
#include "MLP.h"

Layer::Layer(int number, int previous_number, int layernumber)
{
    number_of_layer = layernumber;
    number_of_neurons = number;
    number_of_neurons_previous = previous_number;
    errors.resize(number_of_neurons);
    neurons.resize(number_of_neurons);
    weights.resize(number_of_neurons);
    dweights.resize(number_of_neurons);
    for (int i = 0; i < number; i++)
        weights[i].resize(previous_number);
    for (int i = 0; i < number; i++)
        for (int j = 0; j < previous_number; j++)
        weights[i][j] = rand();
}

void Layer::Start(std::vector<float>image){//ÊÀÊ ÏÅĞÅÄÀÒÜ ÈÇ ÑËÎß Â ÑËÎÉ, ÊÀÊ ÑÂßÇÀÒÜ, ×ÒÎ ÂÛÄÀÂÀÒÜ, ×ÒÎ ÄÀËÜØÅ-ÒÎ, ÎÌÃ
    MakeInputValue(image);
    CountingNET();
    CountingActivation();
}

void Layer::MakeInputValue(std::vector<float>value){
    for (int i = 0; i < input_value.size(); i++)
        input_value[i] = value[i];
} 

std::vector<float> Layer::GetInputValue(){
    return this->input_value;
}

void Layer::CountingNET(){
    for (int i = 0; i < number_of_neurons; i++)
        for (int j = 0; j < number_of_neurons_previous; j++)
            NET[i] = NET[i] + weights[i][j] * input_value[j];
}

void Layer::CountingActivation(){
    for (int i = 0; i < number_of_neurons; i++)
        neurons[i] = 1 / (1 + exp(alpha*NET[i]));
}

std::vector<float> Layer::GetNeuronsValue(){
    return this->neurons;
}

float Layer::GetErrors(){
    float sum = 0;
    for (int i = 0; i < number_of_layer; i++)
        for (int j = 0; j < number_of_neurons_previous; j++)
            sum = sum + errors[i] * weights[i][j];
    return sum;
}

void Layer::Error(int number_of_layer, MLP &mlp){
    if (number_of_layer == 3) {
        for (int i = 0; i < number_of_neurons; i++)
            errors[i] = (expected_value[i] - neurons[i])* neurons[i] * (1 - neurons[i]);
    }
    else { 
        for (int i = 0; i < number_of_neurons; i++)
            errors[i] = neurons[i] * (1 - neurons[i]) * mlp.GetLayer(3).GetErrors();//÷òî èçìåíèòü?
    }
}

void Layer::MakeExpectedValue(std::vector<float>value){
    expected_value = value;
}

void Layer::CountingDw(){
    for (int i = 0; i < number_of_neurons; i++)
        dweights[i] = learning_rate * input_value[i] * errors[i];
}

void Layer::ChangeWeights(){
    for (int i = 0; i < number_of_neurons; i++)
        for (int j = 0; j < number_of_neurons_previous; j++)
            weights[i][j] = weights[i][j] + alpha*dweights[i];
}

std::vector<float> Layer::GetNET(){
    return this->NET;
}

Layer::~Layer(){}