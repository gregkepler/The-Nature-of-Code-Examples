//
//  GOL.h
//
//  Created by Greg Kepler
//
//

#include "Cell.h"

class GOL {
	std::vector<std::vector<Cell>>	mBoard;
	int								mColumns, mRows;
	int								mWidth;
	
	
public:
	GOL();
	void	init();
	void	display();
	void	generate();
};