#ifndef CONNECTION_H
#define CONNECTION_H
//#include "neuron.h"
#include "filehandler.h"

#define MIN_WEIGHT (double)(-1)
#define MAX_WEIGHT (double)(1)
#define CONNECTION_WEIGHT_RANDOM    true
#define CONNECTION_WEIGHT_FROM_FILE false


class Neuron;
class CommonNeuron;
class Connection: public FileHandler
{
private:
    double weight;
    double previousWeight;
    Neuron* targetNeuron;
    double pureSignal;
public:
    Connection();
    ~Connection();
    void RandomizeWeight();
    void SetWeight(double weightToSet);
    void SetNeuronAddress(Neuron *targetNeuron);
    double GetWeight();
    double GetPreviousWeight();
    Neuron* GetConnectedNeuron();



};

#endif // CONNECTION_H
