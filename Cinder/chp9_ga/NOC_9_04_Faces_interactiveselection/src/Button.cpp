//
//  Button.cpp
//
//  Created by Greg Kepler
//
//

#include "cinder/app/AppNative.h"
#include "cinder/Text.h"
#include "cinder/gl/Texture.h"
#include "Button.h"

using namespace ci;
using namespace ci::app;
using namespace std;

Button::Button( int x, int y, int w, int h, std::string s )
{
	mRect = Rectf( x, y, x + w, y + h );
    mTxt = s;
	mClickedOn = false;
}

void Button::display()
{
	// Draw rectangle and text based on whether rollover or clicked
	ColorA fillColor = ColorA( 0.0, 0.0, 0.0, 0.0 );
    if( mRolloverOn ) fillColor = Color( 0.5, 0.5, 0.5 );
    if( mClickedOn ) fillColor = Color::black();
	
	gl::color( fillColor );
	gl::drawSolidRect( mRect );
	gl::color( Color::black() );
	gl::drawStrokedRect( mRect );
	
    float b = 0.0;
    if( mClickedOn ) b = 1.0;
    else if( mRolloverOn ) b = 0.2;
    else b = 0.0;
	gl::color( Color::white() );
	
	TextBox tbox = TextBox().alignment( TextBox::LEFT ).size( Vec2i( getWindowWidth(), TextBox::GROW ) ).text( mTxt );
	tbox.setColor( Color( b, b, b ) );
	tbox.setBackgroundColor( ColorA( 0.0, 0.0, 0.0, 0.0 ) );
	gl::draw( tbox.render(), Vec2f( mRect.getX1() + 10.0, mRect.getY1() + 5.0 ) );
}

// Methods to check rollover, clicked, or released (must be called from appropriate
// Places in draw, mousePressed, mouseReleased
bool Button::rollover( ci::Vec2f mousePos )
{
	if( mRect.contains( mousePos ) ) mRolloverOn = true;
    else mRolloverOn = false;
    return mRolloverOn;
}

bool Button::clicked( ci::Vec2f mousePos )
{
	if( mRect.contains( mousePos ) ) mClickedOn = true;
    return mClickedOn;
}

bool Button::released()
{
	mClickedOn = false;
}
