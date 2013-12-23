//
//  Cluster.h
//
//  Created by Greg Kepler
//
//

#include "cinder/app/AppNative.h"
#include "MSAPhysics2D.h"
#include "Node.h"

class Cluster {
public:
	Cluster( msa::physics::World2D* const world, int nodeAmt, float diameter, ci::Vec2f center );
	void	display();
	void	showConnections();
	
	msa::physics::World2D		*mWorld;
	vector<Node*>				mNodes;
	float						mDiameter;
};