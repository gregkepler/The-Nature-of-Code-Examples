//
//  Perceptron.h
//

class Perceptron {
	std::vector<float> mWeights;		// Vector of weights for inputs
	float mLearningConstant;			// learning constant
	
public:
	Perceptron( int n, float c );
	
	void				train( std::vector<float> inputs, int desired );
	int					feedforward( std::vector<float> inputs );
	int					activate( float sum );
	std::vector<float>	getWeights();
	
};