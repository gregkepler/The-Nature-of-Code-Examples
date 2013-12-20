#include "MSAObjCPointer.h"

namespace msa {
	
    //--------------------------------------------------------------
	ObjCPointer::ObjCPointer() {
		__useCount = 1;
		setInstanceName("");
		setClassName("ObjCPointer");
		verbose = false;
	}
	
    //--------------------------------------------------------------
	ObjCPointer::~ObjCPointer() {
		if(verbose) printf("%s : %s - *** DELETED ***\n", __myClassName.c_str(), __myInstanceName.c_str());
	}
	
	
    //--------------------------------------------------------------
	void ObjCPointer::retain() {
		__useCount++;
		if(verbose) printf("%s : %s - retain (%i)\n", __myClassName.c_str(), __myInstanceName.c_str(), __useCount);
	}
	
    //--------------------------------------------------------------
	void ObjCPointer::release() {
		__useCount--;
		if(verbose) printf("%s : %s - release (%i)\n", __myClassName.c_str(), __myInstanceName.c_str(), __useCount);
		if(__useCount == 0) delete this;
	}
	
	
    //--------------------------------------------------------------
	void ObjCPointer::setInstanceName(std::string n) {
		__myInstanceName = n;
	}
	
	
    //--------------------------------------------------------------
	void ObjCPointer::setInstanceName(const char* sz) {
		setInstanceName(std::string(sz));
	}
	
	
	
    //--------------------------------------------------------------
	void ObjCPointer::setClassName(std::string n) {
		__myClassName = n;
	}
	
	
    //--------------------------------------------------------------
	void ObjCPointer::setClassName(const char* sz) {
		setClassName(std::string(sz));
	}
	
    //--------------------------------------------------------------
	std::string ObjCPointer::getClassName() {
		return __myClassName;
	}
	
    //--------------------------------------------------------------
	std::string ObjCPointer::getInstanceName() {
		return __myInstanceName;
	}

}

