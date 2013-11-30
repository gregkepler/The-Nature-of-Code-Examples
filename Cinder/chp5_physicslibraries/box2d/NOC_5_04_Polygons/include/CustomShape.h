//
//  CustomShape.h
//  NOC_5_04_Polygons
//
//  Created by Greg Kepler on 11/28/13.
//
//

#include "cinder/app/AppNative.h"
#include <Box2d/Box2D.h>

class CustomShape
{
public:
	CustomShape( b2World* const world, ci::Vec2f pos );
	void    display();
	void	drawShape();
	bool    done();
	
private:
	b2World		*mWorld;
	b2Body      *mBody;
	
	void    makeBody( ci::Vec2f pos );
    void    killBody();
};
