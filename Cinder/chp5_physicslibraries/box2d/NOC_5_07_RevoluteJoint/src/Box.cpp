//
//  Box.cpp
//  NOC_5_07_RevoluteJoint
//
//  Created by Greg Kepler
//
//

#include "cinder/app/AppNative.h"
#include "cinder/Rand.h"
#include "Box.h"

using namespace ci;
using namespace ci::app;
using namespace std;

Box::Box( b2World* const world, ci::Vec2f pos, float w, float h, bool lock )
{
	mWorld = world;
	mWidth = w;
	mHeight = h;
	
	// Define and create the body
    b2BodyDef bd;
    bd.position.Set( pos.x, pos.y );
	
	if( lock ) bd.type = b2_staticBody;
    else bd.type = b2_dynamicBody;
	    
    mBody = mWorld->CreateBody( &bd );
	
	
	// Define the shape -- a  (this is what we use for a rectangle)
    b2PolygonShape sd;
    float box2dW = w / 2;
    float box2dH = h / 2;
    sd.SetAsBox( box2dW, box2dH );
	
    // Define a fixture
    b2FixtureDef fd;
    fd.shape = &sd;
    // Parameters that affect physics
    fd.density = 1;
    fd.friction = 0.3;
    fd.restitution = 0.5;
	
    mBody->CreateFixture( &fd );
	
    // Give it some initial random velocity
    mBody->SetLinearVelocity( b2Vec2( randFloat( -5.0, 5.0 ), randFloat( 2.0, 5.0 ) ) );
    mBody->SetAngularVelocity( randFloat( -5.0, 5.0 ) );
}

 // This function removes the particle from the box2d world
void Box::killBody()
{
    mWorld->DestroyBody( mBody );
}

// Drawing the box
void Box::display() {
    // We look at each body and get its screen position
    b2Vec2 pos = mBody->GetPosition();
    // Get its angle of rotation
    float a = toDegrees( mBody->GetAngle() );
	
    glPushMatrix();
	gl::translate(pos.x,pos.y);
	gl::rotate( a );
	Rectf rect = Rectf( ( -mWidth / 2 ), ( -mHeight / 2 ), ( -mWidth / 2 ) + mWidth, ( -mHeight / 2 ) + mHeight );
	gl::color( Color8u::gray( 127 ) );
	gl::drawSolidRect( rect );
		
	gl::color( Color::black() );
	gl::lineWidth( 2.0 );
	gl::drawStrokedRect( rect );
	
    glPopMatrix();
}