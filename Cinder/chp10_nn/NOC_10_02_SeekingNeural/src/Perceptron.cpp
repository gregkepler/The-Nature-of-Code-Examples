//
//  Perceptron.cpp
//

#include "cinder/app/AppNative.h"
#include "cinder/Rand.h"
#include "Perceptron.h"

using namespace ci;
using namespace ci::app;
using namespace std;

// Perceptron is created with n weights and learning constant
Perceptron::Perceptron( int n, float c )
{
	mWeights.resize( n );
	
    // Start with random weights
    for( int i = 0; i < mWeights.size(); i++ ){
		mWeights[i] = randFloat( 0.0, 1.0 );
    }
    mLearningConstant = c;
}

// Function to train the Perceptron
// Weights are adjusted based on "desired" answer
void Perceptron::train( std::vector<Vec2f> forces, Vec2f error )
{
	for( int i = 0; i < mWeights.size(); i++ )
	{
		mWeights[i] += mLearningConstant * error.x * forces[i].x;
		mWeights[i] += mLearningConstant * error.y * forces[i].y;
		mWeights[i] = constrain( mWeights[i], 0.0f, 1.0f );
    }
}

// Guess -1 or 1 based on input values
Vec2f Perceptron::feedforward( vector<Vec2f> forces )
{
    // Sum all values
    Vec2f sum = Vec2f::zero();
    for( int i = 0; i < mWeights.size(); i++ )
	{
		forces[i] *= mWeights[i];
		sum += forces[i];
    }
    return sum;
}