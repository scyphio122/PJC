#include "bias.h"

Bias::Bias()
{
    this->input = 1;
    this->ClearOutput();
    this->ClearConnection();
}

Bias::~Bias()
{
    this->ClearTargetNeuronConnection();
}

