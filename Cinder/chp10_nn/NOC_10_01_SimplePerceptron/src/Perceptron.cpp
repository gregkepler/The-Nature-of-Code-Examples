//
//  Perceptron.cpp
//  NOC_10_01_SimplePerceptron
//
//  Created by Greg Kepler on 2/25/14.
//
//

#include "cinder/app/AppNative.h"
#include "cinder/Rand.h"
#include "Perceptron.h"

using namespace ci;
using namespace ci::app;
using namespace std;

Perceptron::Perceptron( int n, float c )
{
	mWeights.resize( n );
	
    // Start with random weights
    for (int i = 0; i < mWeights.size(); i++ ) {
		mWeights[i] = randFloat( -1.0, 1.0 );
    }
    mLearningConstant = c;
}

// Function to train the Perceptron
// Weights are adjusted based on "desired" answer
void Perceptron::train( std::vector<float> inputs, int desired )
{
	// Guess the result
    int guess = feedforward( inputs );
    // Compute the factor for changing the weight based on the error
    // Error = desired output - guessed output
    // Note this can only be 0, -2, or 2
    // Multiply by learning constant
    float error = desired - guess;
    // Adjust weights based on weightChange * input
    for( int i = 0; i < mWeights.size(); i++ )
	{
		mWeights[i] += mLearningConstant * error * inputs[i];
    }
}

// Guess -1 or 1 based on input values
int Perceptron::feedforward( vector<float> inputs )
{
    // Sum all values
    float sum = 0;
    for( int i = 0; i < mWeights.size(); i++ )
	{
		sum += inputs[i] * mWeights[i];
    }
    // Result is sign of the sum, -1 or 1
    return activate( sum );
}

int Perceptron::activate( float sum )
{
    if( sum > 0 ) return 1;
    else return -1;
}

// Return weights
std::vector<float> Perceptron::getWeights()
{
	return mWeights;
}