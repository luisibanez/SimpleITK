/**
 * Simple test of SimpleITK's java wrapping
 */

import org.itk.simple.*;

class ImageConnection {

  public static void main(String argv[]) {

    // do some simple operations
    System.out.println("SimpleITK says 'Hello World' from Java");

    if ( argv.length < 2 ) {
      System.out.println("Usage: java ImageConnection <input> <output>");
      return;
    }

    ImageFileReader reader = new ImageFileReader();

    reader.setFileName(argv[0]);

    Image img = reader.execute();

    PixelContainer pixelsContainer = img.getPixelContainer();


  }

}
