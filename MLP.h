#pragma once
#include <vector>
#include "Layer.h"
class Layer;

class MLP
{
private:
    int number_of_layers;
    std::vector<Layer>layers;
    float general_error;
    float epsilon;
    int number_of_learning_sets = 10;
    int number_of_eras;
public:
    std::vector<float> expected_value;
    Layer GetLayer(int layernumber);
    void Start(std::vector<float> image);
    void CountingGeneralError();
    bool LearningIsOK();
    void EndOfEra(int number);
    void BackPropagation(MLP mlp);
    MLP(int neurons_in_a_layer[2]);
    int GetEndOfEraTimes();
    ~MLP();
};

