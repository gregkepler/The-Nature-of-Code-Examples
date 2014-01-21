//
//  Turtle.h
//
//  Created by Greg Kepler
//
//

class Turtle {
	std::string		mTodo;
	float			mLen;
	float			mTheta;
	
	
public:
	Turtle( std::string s, float l, float t );
	void render();
	void setLen( float l );
	void changeLen( float percent );
	void setToDo( std::string s );
	
};