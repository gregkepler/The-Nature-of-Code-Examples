/***********************************************************************
 
 Super simple Objective C style Smart Pointer which keeps reference count 
 and frees memory when reference count is zero.
 
 Any object you want this functionality, should extend ofxObjCPointer
 
 
 If someone passes you a pointer and you only need the data temporarily
 (you do NOT need the data beyond the scope of the function)
 just use the pointer/data and do NOT call any of the special methods (retain or release).
 
 If you DO need to keep the data beyond the scope of the function,
 call myObjPointer->retain() on the pointer to indicate that you need the data, 
 and call myObjPointer->release() when you are done with it.
 
 If you allocated the pointer with 'new MyObject' or retained it with myObj->retain()
 then you must ALWAYS release it 'myObj->release()' when you are done.
 You do not need to worry about whether anyone else is using the data or not, 
 the reference count will take care of that.
 
 Never use 'delete myObj', only use 'myObj->release();
 
 ************************************************************************/

#pragma once

#include <string>
#include <stdio.h>

namespace msa {
	
	class ObjCPointer {
	public:
		bool verbose;
		
		ObjCPointer();
		virtual ~ObjCPointer();
		
		// use this to indicate you are using the object and want to keep it safe in memory
		void retain();
		
		// use this to indicate you are done with the object and as far as you are concerned, it can be deleted
		void release();	
		
		void setInstanceName(std::string n);
		void setInstanceName(const char* sz); 
		
		std::string getClassName();
		std::string getInstanceName();
		
	protected:	
		void setClassName(std::string n);
		void setClassName(const char* sz); 
		
	private:
		unsigned int	__useCount;
		std::string		__myClassName;
		std::string		__myInstanceName;
	};
	
}

