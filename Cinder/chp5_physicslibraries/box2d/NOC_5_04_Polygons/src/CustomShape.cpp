//
//  CustomShape.cpp
//  NOC_5_04_Polygons
//
//  Created by Greg Kepler
//
//

#include "cinder/app/AppNative.h"
#include "cinder/Rand.h"
#include "CustomShape.h"

using namespace ci;
using namespace ci::app;
using namespace std;

CustomShape::CustomShape( b2World* const world, ci::Vec2f pos )
{
	mWorld = world;
	makeBody( pos );
}


void CustomShape::killBody()
{
    mWorld->DestroyBody( mBody );
}

// Is the particle ready for deletion?
bool CustomShape::done()
{
    // Let's find the screen position of the particle
    b2Vec2 pos = mBody->GetPosition();
    // Is it off the bottom of the screen?
    if( pos.y > getWindowHeight() ) {
        killBody();
        return true;
    }
    return false;
}

// Drawing the box
void CustomShape::display()
{
	// draw solid
    gl::color( Color8u::gray( 127 ) );
	drawShape();
	
	// draw outline
	gl::color( Color8u::black() );
	gl::lineWidth( 2.0 );
	glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
	drawShape();
	
	glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
}

void CustomShape::drawShape()
{
	// We look at each body and get its screen position
    Vec2f pos = Vec2f( mBody->GetPosition().x, mBody->GetPosition().y );
	// Get its angle of rotation
    float a = toDegrees( mBody->GetAngle() );
	
	b2Fixture *f = mBody->GetFixtureList();
	b2PolygonShape *ps = (b2PolygonShape *)f->GetShape();
    
    glPushMatrix();
    gl::translate( pos );
    gl::rotate( a );
	glBegin( GL_POLYGON );
	
    // For every vertex, convert to pixel vector
    for (int i = 0; i < ps->GetVertexCount(); i++) {
		
		b2Vec2 v = ps->GetVertex(i);
		glVertex2f( v.x, v.y );
    }
    glEnd();
    glPopMatrix();

}

// Here's our function that adds the particle to the Box2D world
void CustomShape::makeBody( Vec2f pos )
{
	b2Vec2 vertices[4];
	// reversed vertices so that it's counter-clockwise
    vertices[0] = b2Vec2( -10, -10 );
    vertices[1] = b2Vec2( 20, -15 );
    vertices[2] = b2Vec2( 15, 0 );
    vertices[3] = b2Vec2( -15, 25 );
	
	// Define a polygon (this is what we use for a rectangle)
    b2PolygonShape ps;
    ps.Set( vertices, 4 );
	
	// Define the body and make it from the shape
    b2BodyDef bd;
    // Set its position
    bd.type = b2_dynamicBody;
    bd.position.Set( pos.x, pos.y );
    mBody = mWorld->CreateBody( &bd );
    
    mBody->CreateFixture( &ps, 1.0 );
    
    // Give it some initial random velocity
    mBody->SetLinearVelocity( b2Vec2( randFloat( -5.0, 5.0 ), randFloat( 2.0, 5.0 ) ) );
    mBody->SetAngularVelocity( randFloat( -5.0, 5.0 ) );
}