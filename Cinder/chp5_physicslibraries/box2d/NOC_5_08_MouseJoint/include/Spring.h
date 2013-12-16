//
//  Spring.h
//  NOC_5_08_MouseJoint
//
//  Created by Greg Kepler
//
//

#include "cinder/app/AppBasic.h"
#include <Box2D/Box2D.h>
#include "Box.h"

class Spring {
public:
    Spring();
    Spring( b2World* const world );
    ~Spring();

	void    update( float x, float y );
	void    display();
	void    bind( float x, float y, Box* const box );
    void    destroy();
    
    float			mWidth, mHeight;
    b2Body			*mBody;
    b2World			*mWorld;
	b2MouseJoint	*mMouseJoint;
	Box				*mBox;
};