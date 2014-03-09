Cinder Examples
===========================

These examples were converted from the original processing source for the creative codeing c++ library [Cinder](http://www.libCinder.org). The examples were created using Cinder release 0.8.4 on OSX 10.8, though all or most of the examples should run on previous versions. Visual C++ projects for each example are also included, but haven't been tested or opened at all really, at least not yet, so don't hate me.

The code samples for Cinder vary in some very specific ways from processing due to differences in how some functions work, how some functions are named and the absence of some features. 

This is a list of some of the processing/Cinder differences that you may encounter

* The ``PVector`` equivalent is ``Vec2f``
* Processing's ``map`` equivalent is ``lmap`` in Cinder
* The equivalent ``noise`` function in Cinder is ``Perlin::fBm()``
* Instead of arrays, C++ vectors and/or lists are used
* Cinder includes helper functions to draw out shapes using OpenGl such as ``drawSolidRect()``, ``drawSolidEllipse()``, etc. instead if ``rect()``, ``ellipse()``, etc.
* Instead of the setup function, some of the app specific settings are done in the ``prepareSettings()`` function, while variables are initialized in the ``setup`` function.
* Cinder has an ``update()`` function in addition to the draw function. Generally, ``update`` is used for updating values and doing calculations, while draw is for rendering out the visuals. That convention wasn't strictly adhered to, but has been implemented in select places.
* The basic mathematical vector operations(``add()``, ``sub()``, ``mult()``, and ``div()``) don't exist in Cinder nad instead use the actual operators (``+``, ``-``, ``*`` and ``/``) to perform those functions.
* The ``point()`` function doesn't exist in Cinder as of version 0.8.4, so you may see replacement drawing methods, such as 1 pixel ellipse, rectangle, or line drawing in its place.

You'll also notice that the variables are slightly different to conform with best practices within the Cinder/C++ coding environment. For instance, member variables often start with the letter 'm'. So instead of calling your variables 'x' and 'y', we often call them 'mX' and 'mY'. This is consistent to how the Cinder framework has been developed. 

Spacing conventions have been followed as much as possible as well. So instead of something like ``function(param1, param2);``, you'll see ``function( param1, param2 );``.

If you're new to C++, you may be thrown off my some member variables with * in front of it, such as *walker in many of the introduction examples. This refers to the variable being a pointer. You can read more about pointers [here](http://www.cplusplus.com/doc/tutorial/pointers/).

### Chapter 3

* Many of the processing examples include a version with trails on. The Cinder equivalent includes code that you can uncomment to turn trails on.

### Chapter 5
#### Box2d

* Rotations from Box2d bodies have to be translated to degrees

#### Toxiclibs

* Since Toxiclibs doesn't exist for Cinder, [MSA Physics](https://github.com/memo/ofxMSAPhysics) is used.

#### MSA Physics
* The source is included (in the src folder for the chapter) but may be out of date. The latest can be [found here](https://github.com/memo/ofxMSAPhysics)
* The attraction class (MSAPhysicsAttraction.h) was rewritten to match toxi's attraction function. It's not perfect, but you get the point.

### Chapter 10

* Examples  10-3 and 10-4 utilize header guards and forward declaration since there is cyclacle inclusion. You can read more about include guards and forwards declaration [here](http://www.cplusplus.com/forum/articles/10627/) and [here](http://en.wikipedia.org/wiki/Include_guard) and [here](http://en.wikipedia.org/wiki/Forward_declaration).