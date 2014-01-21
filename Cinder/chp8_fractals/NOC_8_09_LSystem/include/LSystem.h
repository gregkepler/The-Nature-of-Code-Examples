//
//  LSystem.h
//
//  Created by Greg Kepler
//
//

#include "Rule.h"

class LSystem {
	std::string			mSentence;		// The sentence (a String)
	std::vector<Rule*>	mRuleset;		// The ruleset (an array of Rule objects)
	int					mGeneration;	// Keeping track of the generation #
	
public:
	LSystem( std::string axiom, std::vector<Rule*> const *r );
	void generate();
	std::string getSentence(){		return mSentence; };
	int			getGeneration(){	return mGeneration; };
	
};