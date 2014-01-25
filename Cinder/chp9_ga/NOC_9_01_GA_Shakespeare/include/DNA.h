//
//  DNA.h
//
//  Created by Greg Kepler
//
//

class DNA {
	
	std::vector<char>	mGenes;		// The genetic sequence

	
public:
	DNA();
	DNA( int num );
	
	float				mFitness;
	void				fitness( std::string target );
	DNA					crossover( DNA partner);
	void				mutate( float mutationRate);
	std::string			getPhrase();
};