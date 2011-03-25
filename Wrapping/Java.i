// Java
#if SWIGJAVA

%pragma(java) jniclasscode=%{
  static {
    System.loadLibrary ( "SimpleITKJava" );
  }
%}

%include "arrays_java.i"
%apply byte[]  { uint8_t *}
%apply int[]  { int32_t *}
%apply short[]  { int16_t *}
%apply long[]  { int64_t *}
%apply float[]  { float *}
%apply double[]  { double *}

// Make Java method names follow the naming conventions
// See the swig.swg file, and ruby.swg for details on how this works
// Documented in: http://www.swig.org/Doc2.0/SWIG.html#SWIG_advanced_renaming
%rename("%(firstlowercase)s", %$isfunction ) "";

#endif // End of Java specific sections
