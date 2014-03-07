//
//  Perceptron.h
//

class Perceptron {
	std::vector<float> mWeights;		// Vector of weights for inputs
	float mLearningConstant;			// learning constant
	
public:
	Perceptron( int n, float c );
	
	void				train( std::vector<ci::Vec2f> forces, ci::Vec2f error );
	ci::Vec2f			feedforward( std::vector<ci::Vec2f> forces );
	
};