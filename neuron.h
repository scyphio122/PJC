#ifndef NEURON_H
#define NEURON_H

#include <QList>
#include "connection.h"
#include <stdint-gcc.h>

#define     BIPOLAR_SIGMOID_FUNCTION

#ifdef  BIPOLAR_SIGMOID_FUNCTION
        #undef  UNIPOLAR_SIGMOID_FUNCTION
        #define TRANSFER_FUNCTION_DIFFERENTIAL(beta, x)  (2*beta*exp(beta*x))/((exp(beta*x)+1)*(exp(beta*x)+1))
#endif

#ifdef UNIPOLAR_SIGMOID_FUNCTION
    #undef  BIPOLAR_SIGMOID_FUNCTION
    #define TRANSFER_FUNCTION_DIFFERENTIAL(beta, x)  (beta*exp(beta*x))/((exp(beta*x)+1)*(exp(beta*x)+1))
#endif

const double beta = 0.6;

class Connection;
class CommonNeuron;
class Neuron
{
protected:
    double output;
    double neuronError;
    QList<Connection> targetNeuronConnection;



public:
    Neuron();
    virtual ~Neuron();
    void        CalculateOutput();
    double      GetOutput();
    Connection* GetConnectionAt(uint16_t index);
    void        ClearConnection();
    void        ClearOutput();
    void        CreateTargetNeuronConnection(Connection connection);
    void        ClearTargetNeuronConnection();
    void        ConnectNeuron(CommonNeuron *neuronToConnect, bool connectionWeightRandom_Or_FromFile);
    void        AllocateMemoryForTargetConnectionsList(uint16_t connectionsNumber);
    double      GetNeuronError();
    void        SetNeuronError(double value);
    uint16_t    ConnectionsSize();
    void        LoadSignalInNextNeurons(double signal);


};

#endif // NEURON_H
