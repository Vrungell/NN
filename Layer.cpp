#include "stdafx.h"
#include <vector>
#include "Layer.h"
#include "MLP.h"
#include <cmath>
#include <algorithm>

Layer::Layer(int number, int previous_number, int layernumber)
{
    number_of_layer = layernumber;
    number_of_neurons = number;
    number_of_neurons_previous = previous_number;
    weights.resize(number_of_neurons);
    NET.resize(number_of_neurons);
    for (int i = 0; i < number; i++)
        weights[i].resize(previous_number);
    for (int i = 0; i < number; i++)
        for (int j = 0; j < previous_number; j++)
        weights[i][j] = rand();
}

void Layer::Start(std::vector<float>&image, MLP mlp){
    MakeInputValue(image);
    CountingNET(mlp);
    CountingActivation();
}

void Layer::MakeInputValue(std::vector<float>&value){
    for (int i = 0; i < value.size(); i++)
        input_value.push_back(value[i]);
} 

std::vector<float>& Layer::GetInputValue(){
    return this->input_value;
}

void Layer::CountingNET(MLP mlp){//как поменять для первого слоя? (nnp = 0)
    if (this->number_of_layer != 1){
        for (int i = 0; i < number_of_neurons; i++)
            for (int j = 0; j < number_of_neurons_previous; j++)
                NET[i] = NET[i] + weights[i][j] * mlp.GetLayer(number_of_layer -1).neurons[j];
    }
    else
        for (int i = 0; i < number_of_neurons; i++)
            NET[i] = input_value[i];
}

void Layer::CountingActivation(){
    if (this->number_of_layer !=1){//Надо сделать так, чтобы без 3(а вдруг +скрытый слой)
        for (int i = 0; i < number_of_neurons; i++)
            neurons.push_back(1 / (1 + exp(alpha*NET[i])));
    }
    else
        for (int i = 0; i < number_of_neurons; i++)
            neurons.push_back(NET[i]);
}

std::vector<float> &Layer::GetNeuronsValue(){
    return this->neurons;
}

float &Layer::GetErrors(){
    float sum = 0;
    if (this->number_of_layer != 1){
        for (int i = 0; i < number_of_neurons; i++)
            for (int j = 0; j < number_of_neurons_previous; j++)
                sum = sum + errors[i] * weights[i][j];
    }
    return sum;
}

void Layer::Error(int number_of_layer, MLP &mlp){//Вот это вообще не очень функция ПОЧЕМУ У ВТОРОГО СЛОЯ НЕ СЧИТАЮТСЯ ОШИБКИ КАРЛ
    if (number_of_layer == 3) {//без 3
        for (int i = 0; i < number_of_neurons; i++)
            errors.push_back((expected_value[i] - neurons[i])* neurons[i] * (1 - neurons[i]));//почему не работает push_back?
    }
    else { 
        for (int i = 0; i < number_of_neurons; i++)
            errors.push_back(neurons[i] * (1 - neurons[i]) * mlp.GetLayer(number_of_layer+1).GetErrors());//что изменить? ответ:ты добавила что-то в errors после того
                                                                                                          // в старой сети есть элементы в errors и в expected_value , а в копии - только в exppected_valye
    }
}

void Layer::MakeExpectedValue(std::vector<float> & value){
    expected_value = value;
}

void Layer::CountingDw(){
    for (int i = 0; i < number_of_neurons; i++)
        dweights.push_back(learning_rate * neurons[i] * errors[i]);//что должно стоять вместо input_value?
}

void Layer::ChangeWeights(){
    for (int i = 0; i < number_of_neurons; i++)
        for (int j = 0; j < number_of_neurons_previous; j++)
            weights[i][j] =  weights[i][j] + alpha*dweights[i];
}

std::vector<float> &Layer::GetNET(){
    return this->NET;
}

Layer::~Layer(){}