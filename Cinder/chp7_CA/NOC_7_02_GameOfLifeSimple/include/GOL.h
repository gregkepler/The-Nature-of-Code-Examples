//
//  GOL.h
//
//  Created by Greg Kepler
//
//

class GOL {
	std::vector<std::vector<int>>	mBoard;
	int								mColumns, mRows;
	int								mWidth;
	
	
public:
	GOL();
	void	init();
	void	display();
	void	generate();
};