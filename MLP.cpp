#include "stdafx.h"
#include "MLP.h"
#include "Layer.h"
#include <fstream>
#include <iostream>
MLP::MLP(int neurons_in_a_layer[2])
{
    Layer layer1(neurons_in_a_layer[0], 0, 1);
    layers.push_back(layer1);
    Layer layer2(neurons_in_a_layer[1], neurons_in_a_layer[0], 2);
    layers.push_back(layer2);
    Layer layer3(neurons_in_a_layer[2], neurons_in_a_layer[1], 3);
    layers.push_back(layer3);
}

void MLP::Start(std::vector<float> image){
    layers[0].Start(image, *this);
    layers[1].Start(layers[0].GetNeuronsValue(), *this);
    layers[2].Start(layers[1].GetNeuronsValue(), *this);
}

void MLP::BackPropagation(){ 
    for (int i = 2; i > 0; i--){  
        layers[i].Error(i + 1, *this); // mlp -> *this
        layers[i].CountingDw();
        layers[i].ChangeWeights();
    }
}

Layer &MLP::GetLayer(int layernumber){
    return this->layers[layernumber-1];
}

void MLP::CountingGeneralError(){
    general_error = 0;
    for (int i = 1; i < 3; i++)
        general_error = general_error + this->layers[i].GetErrors();
}

bool MLP::LearningIsOK(){
    if (general_error < epsilon) number_of_good_tests++;
    else number_of_good_tests = 0;
    if (number_of_good_tests == 10) return true;
    return false;
}

void MLP::EndOfEra(int number){
    if (number%number_of_learning_sets == 0) {
        number_of_eras++;

    }
}

int MLP::GetEndOfEraTimes(){
    return this->number_of_eras;
}

void MLP::ClearLayers(){
    layers[0].ClearLayer();
    layers[1].ClearLayer();
    layers[2].ClearLayer();
}
MLP::~MLP()
{
}
