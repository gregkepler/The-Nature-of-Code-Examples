//
//  Lollipop.cpp
//  NOC_5_05_MultiShapes
//
//  Created by Greg Kepler
//
//

#include "cinder/app/AppNative.h"
#include "cinder/Rand.h"
#include "Lollipop.h"

using namespace ci;
using namespace ci::app;
using namespace std;

Lollipop::Lollipop( b2World* const world, ci::Vec2f pos )
{
	mWidth = 8.0;
    mHeight = 24.0;
    mRadius = 8.0;
	mWorld = world;
	makeBody( pos );
}

void Lollipop::killBody()
{
    mWorld->DestroyBody( mBody );
}

// Is the particle ready for deletion?
bool Lollipop::done()
{
    // Let's find the screen position of the particle
    b2Vec2 pos = mBody->GetPosition();
    // Is it off the bottom of the screen?
    if( pos.y > getWindowHeight() + mWidth * mHeight ) {
        killBody();
        return true;
    }
    return false;
}

// Drawing the box
void Lollipop::display()
{
	// We look at each body and get its screen position
    Vec2f pos = Vec2f( mBody->GetPosition().x, mBody->GetPosition().y );
    // Get its angle of rotation
    float a = toDegrees( mBody->GetAngle() );
	
    glPushMatrix();
	gl::translate( pos );
	gl::rotate( a );
    
	Rectf rect = Rectf( -mWidth/2, -mHeight/2, -mWidth/2 + mWidth, -mHeight/2 + mHeight );
	gl::lineWidth( 2.0 );
	
	// draw stem
	gl::color( Color8u::gray( 127 ) );
	gl::drawSolidRect( rect );
	gl::color( Color8u::black() );
	gl::drawStrokedRect( rect );

	
	// draw circle
	gl::color( Color8u::gray( 127 ) );
	gl::drawSolidEllipse( Vec2f( 0.0, -mHeight / 2 ), mRadius, mRadius );
	gl::color( Color8u::black() );
	gl::drawStrokedEllipse( Vec2f( 0.0, -mHeight / 2 ), mRadius, mRadius );
	
    glPopMatrix();
}

// Here's our function that adds the particle to the Box2D world
void Lollipop::makeBody( Vec2f pos )
{
	// Define the body and make it from the shape
    b2BodyDef bd;
    bd.type = b2_dynamicBody;
    bd.position.Set( pos.x, pos.y );
    mBody = mWorld->CreateBody( &bd );
	
    b2CircleShape circle;
    circle.m_radius = mRadius;
    b2Vec2 offset = b2Vec2( 0, -mHeight / 2 );
    circle.m_p.Set( offset.x, offset.y );
	
	b2PolygonShape ps;
    float box2dW = mWidth / 2;
    float box2dH = mHeight / 2;
    ps.SetAsBox( box2dW, box2dH );
	
    mBody->CreateFixture( &ps, 1.0 );
    mBody->CreateFixture( &circle, 1.0 );
	
    // Give it some initial random velocity
    mBody->SetLinearVelocity( b2Vec2( randFloat( -5.0, 5.0 ), randFloat( 2.0, 5.0 ) ) );
    mBody->SetAngularVelocity( randFloat( -5.0, 5.0 ) );
}