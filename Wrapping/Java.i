// Java
#if SWIGJAVA

%pragma(java) jniclasscode=%{
  static {
    System.loadLibrary ( "SimpleITKJava" );
  }
%}

%include "arrays_java.i"
%apply int[]  { int *}

// Make Java method names follow the naming conventions
// See the swig.swg file, and ruby.swg for details on how this works
// Documented in: http://www.swig.org/Doc2.0/SWIG.html#SWIG_advanced_renaming
%rename("%(firstlowercase)s", %$isfunction ) "";

#endif // End of Java specific sections
