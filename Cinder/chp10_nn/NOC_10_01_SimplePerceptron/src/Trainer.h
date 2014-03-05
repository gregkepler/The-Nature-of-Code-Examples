//
//  Trainer.h
//
//	A class to describe a training point
//	Has an x and y, a "bias" (1) and known output
//	Could also add a variable for "guess" but not required here
//

class Trainer {
	
	
public:
	Trainer( float x, float y, int a );
	std::vector<float>		mInputs;
	int						mAnswer;
};