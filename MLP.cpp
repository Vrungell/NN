#include "stdafx.h"
#include "MLP.h"
#include "Layer.h"
MLP::MLP()
{
    Layer layer(900, 0, 1);
    layers.push_back(layer);
    Layer layer(30, 900, 2);
    layers.push_back(layer);
    Layer layer(10, 30, 3);
    layers.push_back(layer);
}

Layer MLP::GetLayer(int layernumber){
    return this->layers[layernumber-1];
}

void MLP::CountingGeneralError(){
    general_error = 0;
    for (int i = 0; i < 3; i++)
        general_error = general_error + this->layers[i].GetErrors();
}

bool MLP::LearningIsOK(){
    if (general_error < epsilon) return true;
    else return false;
}

bool 
MLP::~MLP()
{
}
