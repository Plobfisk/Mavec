#include "../headers/mavec.h"

#include <iostream>

class Layer {
public:
    Layer(int nodesIn, int nodesOut) : m_nodesIn(nodesIn), m_nodesOut(nodesOut) {
        // [input 1 neuron 1] [input 1 neuron 2] [input 1 neuron 3] ...
        // [input 2 neuron 1] [input 2 neuron 2] [input 2 neuron 3] ...
        //           .                  .                  .         .
        //           .                  .                  .            .
        //           .                  .                  .               .
        
        m_weights.size(nodesIn, nodesOut);
        m_biases.size(nodesOut);
        m_outputs.size(nodesOut);

        m_weights.Random(0,1);
        m_biases.Random(0,1);
    }

    Vector<double> Forward(Vector<double> inputs) {
        for (int nodeOut = 0; nodeOut < m_nodesOut; nodeOut++) {
            double output = m_biases(nodeOut);
            for (int nodeIn = 0; nodeIn < m_nodesIn; nodeIn++) {
                output += inputs(nodeIn) * m_weights(nodeIn, nodeOut);
            }
            m_outputs(nodeOut) = output;
        }
        return m_outputs;
    }
private:
    Matrix<double> m_weights;
    Vector<double> m_biases;
    Vector<double> m_outputs;

    int m_nodesIn;
    int m_nodesOut;
};

class NN {
public:
    NN(Vector<int> layers) {
        m_layers.size(layers.size());
        for (int i = 0; i < layers.size(); i++) {
            
        }
    }

private:
    Vector<double> m_layers;

};
// Indexing error handling
int main() {
    /*size_t N = 3;
    Vector<double> A(N);
    Vector<double> B(N);
    A.Random(0,1);
    B.Random(0,1);

    Matrix<double> C(N,N);
    C.Random(0, 1);

    C.print();
    (B*A).print();
    (C* (B*A)).print();*/

    Vector<double> input(2);
    input = {3,7};

    Layer layer(2,3);
    Vector<double> output = layer.Forward(input);

    output.print();

    return 0;
}