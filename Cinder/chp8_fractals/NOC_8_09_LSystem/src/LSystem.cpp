//
//  LSystem.cpp
//
//  Created by Greg Kepler
//
//	An LSystem has a starting sentence
//	An a ruleset
//	Each generation recursively replaces characteres in the sentence
//	Based on the rulset
//

#include "cinder/app/AppNative.h"
#include "LSystem.h"

using namespace ci;
using namespace ci::app;
using namespace std;

// Construct an LSystem with a startin sentence and a ruleset
LSystem::LSystem( std::string axiom, std::vector<Rule*> const *r )
{
	mSentence = axiom;
	mRuleset = *r;
	mGeneration = 0;
}

// Generate the next generation
void LSystem::generate()
{
    // An empty StringBuffer that we will fill
    string nextgen = "";
    // For every character in the sentence
    for( int i = 0; i < mSentence.length(); i++ )
	{
		// What is the character
		char currChar = mSentence.at( i );
		// convert the char into a string
		string curr(1, currChar );
		// We will replace it with itself unless it matches one of our rules
		string replace = "" + curr;
		// Check every rule
		for( int j = 0; j < mRuleset.size(); j++)
		{
			char a = mRuleset[j]->getA();
			// if we match the Rule, get the replacement String out of the Rule
			if (a == currChar) {
				replace = mRuleset[j]->getB();
				break;
			}
		}
		// Append replacement String
		nextgen.append(replace);
    }
    // Replace sentence
    mSentence = nextgen;

    // Increment generation
	mGeneration++;
}
