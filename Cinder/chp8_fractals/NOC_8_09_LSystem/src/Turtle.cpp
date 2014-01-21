//
//  Turtle.cpp
//
//  Created by Greg Kepler
//
//

#include "cinder/app/AppNative.h"
#include "Turtle.h"

using namespace ci;
using namespace ci::app;
using namespace std;

Turtle::Turtle( string s, float l, float t)
{
    mTodo = s;
    mLen = l;
    mTheta = t;
}

void Turtle::render()
{
	gl::color( ColorA8u( 0, 0, 0, 175 ) );
    for( int i = 0; i < mTodo.length(); i++ )
	{
		char c = mTodo.at( i );
		if (c == 'F' || c == 'G') {
			gl::drawLine( Vec2f( 0.0, 0.0 ), Vec2f( mLen, 0.0 ) ) ;
			gl::translate( mLen, 0 );
		}
		else if (c == '+') {
			gl::rotate( mTheta );
		}
		else if (c == '-') {
			gl::rotate( -mTheta );
		}
		else if (c == '[') {
			gl::pushMatrices();
		}
		else if (c == ']') {
			gl::popMatrices();
		}
    }
}

void Turtle::setLen( float l )
{
    mLen = l;
}

void Turtle::changeLen( float percent )
{
    mLen *= percent;
}

void Turtle::setToDo( string s )
{
    mTodo = s;
}