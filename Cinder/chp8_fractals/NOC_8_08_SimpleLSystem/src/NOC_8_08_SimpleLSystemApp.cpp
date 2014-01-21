//
//  Example 8-8: Simple L-System
//  The Nature of Code
//
//  Converted from Daniel Shiffman's Processing Examples
//  Created by Greg Kepler
//
//	L-System
//	Just demonstrating working with L-System strings
//  No drawing
//
//

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/Text.h"
#include "cinder/gl/Texture.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class NOC_8_08_SimpleLSystemApp : public AppNative {
  public:
	void prepareSettings( Settings *settings );
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
	
	// Start with "A"
	string current = "A";
	// Number of  generations
	int count = 0;
};

void NOC_8_08_SimpleLSystemApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 800, 200 );
}

void NOC_8_08_SimpleLSystemApp::setup()
{
	console() << "Generation " << count << ": " + current << endl;;
}

void NOC_8_08_SimpleLSystemApp::mouseDown( MouseEvent event )
{
	// A new StringBuffer for the next generation
	string next = "";
	
	// Look through the current String to replace according to L-System rules
	for (int i = 0; i < current.length(); i++) {
		char c = current.at( i );
		if( c == 'A' ) {
			// If we find A replace with AB
			next.append("AB");
		}  else if (c == 'B') {
			// If we find B replace with A
			next.append("A");
		}
	}
	// The current String is now the next one
	current = next;
	count++;
	// Print to message console
	console() << "Generation " << count << ": " << current << endl;
	//println(count + " " + current.length());*/
}

void NOC_8_08_SimpleLSystemApp::update()
{
}

void NOC_8_08_SimpleLSystemApp::draw()
{
	// clear out the window with black
	gl::clear( Color::white() );
	
	gl::color( Color::black() );
	TextBox tbox = TextBox().size( Vec2i( getWindowWidth(), TextBox::GROW ) ).text( "Click mouse to generate" );
	tbox.setBackgroundColor( ColorA( 0, 0, 0, 0 ) );
	gl::enableAlphaBlending();
	gl::pushMatrices();
	gl::translate( Vec2f( 10.0, getWindowHeight() - 20.0 ) );
	gl::draw(  gl::Texture( tbox.render() ) );
	gl::popMatrices();

	

}

CINDER_APP_NATIVE( NOC_8_08_SimpleLSystemApp, RendererGl )