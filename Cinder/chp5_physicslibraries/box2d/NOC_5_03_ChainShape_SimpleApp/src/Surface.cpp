//
//  Surface.cpp
//  NOC_5_03_ChainShape_SimpleApp
//
//  Created by Greg Kepler on 11/23/13.
//
//

#include "cinder/app/AppNative.h"
#include "Surface.h"

using namespace ci;
using namespace ci::app;
using namespace std;


SurfaceBoundary::SurfaceBoundary( b2World* const world )
{
	mWorld = world;
	
	// Here we keep track of the screen coordinates of the chain
	surface.push_back( b2Vec2( 0.0, getWindowHeight() / 2 ) );
	
    /*surface.add(new Vec2(0, height/2));
    surface.add(new Vec2(width/2, height/2+50));
    surface.add(new Vec2(width, height/2));
	
    // This is what box2d uses to put the surface in its world
    ChainShape chain = new ChainShape();
	
    // We can add 3 vertices by making an array of 3 Vec2 objects
    Vec2[] vertices = new Vec2[surface.size()];
    for (int i = 0; i < vertices.length; i++) {
		vertices[i] = box2d.coordPixelsToWorld(surface.get(i));
    }
	
    chain.createChain(vertices, vertices.length);
	
    // The edge chain is now a body!
    BodyDef bd = new BodyDef();
    Body body = box2d.world.createBody(bd);
    // Shortcut, we could define a fixture if we
    // want to specify frictions, restitution, etc.
    body.createFixture(chain, 1);*/
}