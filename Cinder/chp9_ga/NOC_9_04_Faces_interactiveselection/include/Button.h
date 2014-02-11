//
//  Button.h
//  NOC_9_04_Faces_interactiveselection
//
//  Created by Greg Kepler on 2/11/14.
//
//

#include "Cinder/app/AppNative.h"

class Button {
	
	public:
	Button( int x, int y, int w, int h, std::string s );
	
	void	display();
	bool	rollover( ci::Vec2f mousePos );
	bool	clicked( ci::Vec2f mousePos );
	bool	released();
};