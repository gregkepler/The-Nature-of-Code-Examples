//
//  Cluster.cpp
//
//  Created by Greg Kepler
//
//

#include "Cluster.h"
#include "cinder/Rand.h"

using namespace ci;
using namespace ci::app;
using namespace std;

Cluster::Cluster( msa::physics::World2D* const world, int nodeAmt, float diameter, ci::Vec2f center )
{
	mWorld = world;
	
	// Set the diameter
    mDiameter = diameter;
	
    // Create the nodes
    for( int i = 0; i < nodeAmt; i++ ) {
		// We can't put them right on top of each other
		mNodes.push_back( new Node( center + randVec2f() ) );
    }
	
    // Connect all the nodes with a Spring
    for( int i = 0; i < mNodes.size() - 1; i++ )
	{
		Node *ni = mNodes[i];
		for( int j = i + 1; j < mNodes.size(); j++ )
		{
			Node *nj = mNodes[j];
			// A Spring needs two particles, a resting length, and a strength
			mWorld->makeSpring( ni, nj, 0.01, diameter );
		}
    }
}

void Cluster::display()
{
	// Show all the nodes
	for( vector<Node*>::iterator n = mNodes.begin(); n != mNodes.end(); ++n )
	{
		(*n)->display();
	}
}

// Draw all the internal connections
void Cluster::showConnections() {
	gl::color( ColorA8u( 0, 0, 0, .58 ) );
	gl::lineWidth( 2.0 );
	
	for ( int i = 0; i < mNodes.size()-1; i++ ) {
		Node *pi = mNodes[i];
		for ( int j = i+1; j < mNodes.size(); j++ ) {
			Node *pj = mNodes[j];
			gl::drawLine( pi->getPosition(), pj->getPosition() );
		}
    }
	
	
}