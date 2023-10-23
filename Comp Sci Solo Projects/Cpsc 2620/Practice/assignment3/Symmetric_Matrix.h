#ifndef SYMMETRIC_MATRIX
#define SYMMETRIC_MATRIX
#include "Structured_Matrix.h"
#include <string>
#include <vector>
using namespace std;

class SymmetricMatrix : public StructuredMatrix{
public:
    //constructors
    /*conditions
    //acts as default constructor if no argument is supplied
    //precondition: none
    //postCondition: a SymmetricMatrix Object is created with the paramiters of size and elements
    */
    SymmetricMatrix(int size = 0, double element = 0.0);
    //destructor
    ~SymmetricMatrix();

    //indexs
    /*conditions
    //precondition: none
    //postCondition: returns constant elements in matrix object from the given
    //row and coloums
    */
    virtual const double& operator()(int rows, int coloums) const = 0;
    /*conditions
    //precondition: none
    //postCondition: returns non constant elements in matrix object from the given
    //row and coloums
    */
    virtual double& operator()(int rows, int coloums) = 0;

    //caculations
    virtual double sum() = 0; //finds the sum of a matrixs contents

    //output
    virtual void print() = 0;

  protected:
    virtual void FormMatrix(double element) = 0; //forms matrixs
};
#endif
