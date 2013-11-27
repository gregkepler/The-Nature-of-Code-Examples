//
//  Surface.cpp
//  NOC_5_03_ChainShape_SimpleApp
//
//  Created by Greg Kepler
//
//

#include "cinder/app/AppNative.h"
#include <Box2D/Box2D.h>
#include "Surface.h"

using namespace ci;
using namespace ci::app;
using namespace std;


SurfaceBoundary::SurfaceBoundary( b2World* const world )
{
	mWorld = world;
	
	// Here we keep track of the screen coordinates of the chain
	surface.push_back( b2Vec2( 0.0, getWindowHeight() / 2 ) );
	surface.push_back( b2Vec2( getWindowWidth() / 2, getWindowHeight() / 2 + 50 ) );
    surface.push_back( b2Vec2( getWindowWidth(), getWindowHeight() / 2 ) );
	
	// This is what box2d uses to put the surface in its world
	b2ChainShape chain;
	// We can add 3 vertices by making an array of 3 Vec2 objects
    b2Vec2 vertices[ 3 ];
    for( int i = 0; i < 3; i++ ) {
		vertices[i] = surface[i];
    }
	
	chain.CreateChain( vertices, 3 );
	
	// The edge chain is now a body!
    b2BodyDef bd;
    mBody = mWorld->CreateBody( &bd );
    // Shortcut, we could define a fixture if we
    // want to specify frictions, restitution, etc.
    mBody->CreateFixture( &chain, 1.0f );
}

// A simple function to just draw the edge chain as a series of vertex points
void SurfaceBoundary::display()
{
	glColor3f(0.0f, 0.0f, 0.0f); // sets color to black.
	gl::color( Color::black() );
	glBegin( GL_POLYGON );
    glVertex2f( 0.0f, getWindowHeight() );
	for( b2Vec2 v: surface ){
		glVertex2f( v.x, v.y );
	}
	glVertex2f( getWindowWidth(), getWindowHeight() );
    glVertex2f( 0.0f, getWindowHeight() );
	glEnd();
}