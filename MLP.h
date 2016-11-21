#pragma once
#include <vector>
#include "Layer.h"
class MLP
{
private:
    int number_of_layers;
    std::vector<Layer>layers;
    float general_error;
    float epsilon;
    int number_of_learning_sets;
public:
    std::vector<float> expected_value;
    Layer GetLayer(int layernumber);
    void CountingGeneralError();
    bool LearningIsOK();
    MLP();
    ~MLP();
};

