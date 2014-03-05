//
//  Perceptron.h
//  NOC_10_01_SimplePerceptron
//
//  Created by Greg Kepler on 2/25/14.
//
//

class Perceptron {
	std::vector<float> mWeights;
	float mLearningConstant;          // learning constant
	
public:
	Perceptron( int n, float c );
	
	void				train( std::vector<float> inputs, int desired );
	int					feedforward( std::vector<float> inputs );
	int					activate( float sum );
	std::vector<float>	getWeights();
	
};