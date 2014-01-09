//
//  CA.h
//  NOC_7_01_WolframCA_figures
//
//  Created by Greg Kepler on 1/9/14.
//
//

class CA {
	std::vector<int> mCells;
	int mGeneration;
	int *mRuleset;
	
	void	setRules();
	int		rules( int a, int b, int c );
	
public:
	CA( int r[] );
	void	randomize();
	void	restart();
	void	render();
	void	generate();
	bool	finished();
};