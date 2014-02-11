#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"
#include "cinder/Text.h"
#include "Population.h"
#include "Button.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class NOC_9_04_Faces_interactiveselectionApp : public AppNative {
  public:
	void prepareSettings( Settings *settings );
	void setup();
	void mouseDown( MouseEvent event );
	void mouseUp( MouseEvent event );
	void mouseMove( MouseEvent event );
	void update();
	void draw();
	void drawText( string str, Vec2i pos );
	
	Population			*mPopulation;
	Button				*mButton;
	Vec2f				mousePos;
};

void NOC_9_04_Faces_interactiveselectionApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 800, 200 );
}

void NOC_9_04_Faces_interactiveselectionApp::setup()
{
	int popmax = 10;
	float mutationRate = 0.05;  // A pretty high mutation rate here, our population is rather small we need to enforce variety
	// Create a population with a target phrase, mutation rate, and population max
	mPopulation = new Population( mutationRate, popmax );
	// A simple button class
	mButton = new Button( 15, 150, 160, 20, "evolve new generation" );
}

void NOC_9_04_Faces_interactiveselectionApp::mouseDown( MouseEvent event )
{
	if( mButton->clicked( event.getPos() ) ) {
		mPopulation->selection();
		mPopulation->reproduction();
	}
}

void NOC_9_04_Faces_interactiveselectionApp::mouseUp( MouseEvent event )
{
	mButton->released();
}

void NOC_9_04_Faces_interactiveselectionApp::mouseMove( MouseEvent event )
{
	mousePos = event.getPos();
}

void NOC_9_04_Faces_interactiveselectionApp::update()
{
}

void NOC_9_04_Faces_interactiveselectionApp::draw()
{
	// clear out the window with black
	gl::clear( Color::white() );
	
	// Display the faces
	mPopulation->display();
	mPopulation->rollover( mousePos );
	
	// Display some text
	drawText( "Generation #:" + to_string( mPopulation->getGenerations() ), Vec2i( 15, 190 ) );
	
	// Display the button
	mButton->display();
	mButton->rollover( mousePos );
}

void NOC_9_04_Faces_interactiveselectionApp::drawText( string str, Vec2i pos )
{
	TextBox tbox = TextBox().alignment( TextBox::LEFT ).size( Vec2i( getWindowWidth(), TextBox::GROW ) ).text( str );
	tbox.setColor( Color::black() );
	tbox.setBackgroundColor( ColorA( 0, 0, 0, 0 ) );
	gl::draw( tbox.render(), pos );
}

CINDER_APP_NATIVE( NOC_9_04_Faces_interactiveselectionApp, RendererGl )
