This is a fork of PNG++, the C++ wrapper for libPNG.

## Text metadata for PNG images

This fork adds functionality to add PNG metadata to images in the form of text comments.

It adds the following new functions:

```cpp
std::vector<text>& image::get_text();
void image::set_text(std::vector<text> const& txt);
```

The `text` struct is a wrapper for libpng's `png_text` struct, with the following constructor:

```cpp
text(png_const_charp key,
     png_const_charp txt,
     int compression = PNG_TEXT_COMPRESSION_zTXt,
     size_t text_length = 0,
     size_t itxt_length = 0,
     png_charp lang = nullptr,
     png_charp lang_key = nullptr)
```

An example of generating a PNG image and adding metadata is as follows:

```cpp
  png::image<png::rgba_pixel> output_png(image_size.x, image_size.y);
  
  // construct your PNG as normal here, this is just a basic example:
  for(png::uint_32 y = 0; y != 255; ++y) {
    for(png::uint_32 x = 0; x != 255; ++x) {
      output_png[y][x] = png::rgba_pixel(x, 0, y, 96);
    }
  }
  
  auto png_comments{output_png.get_text()};                
  std::initializer_list<std::pair<std::string, std::string>> comments {
    {"Title", "My beautiful PNG"},
    {"Author", "Armchair Software"},
    {"Copyright", "Copyright Armchair Ltd"},
  };
  for(auto const &[key, text] : comments) {
    png_comments.emplace_back(key.c_str(), text.c_str());
  }
  output_png.set_text(png_comments);
  
  output_png.write("my_filename.png")
```

Take care about string lifetimes if using c_str() as above!  The `png_text` struct keeps char pointers and does not copy the text, so the underlying strings must remain available until the PNG is written.

For more information about the specific fields of the `png_text` struct, see the libpng [documentation](http://www.libpng.org/pub/png/libpng-manual.txt) and [examples](https://github.com/mitsuba-renderer/libpng/blob/master/example.c#L854).

## Other improvements

This fork adds a few other minor improvements which don't affect the core functionality:

- Improved MinGW32 compatibility
- Improved Emscripten compatibility

## PNG++ functionality

For all other PNG++ functionality, see the original documentation at https://www.nongnu.org/pngpp/.
  
---

The original README continues below.
-----------------------


This is png++ the C++ wrapper for libpng.  Version 0.2

General
=======

PNG++ aims to provide simple yet powerful C++ interface to libpng, the
PNG reference implementation library.

PNG++ is free software distributed under a modified variant of BSD
license.  For more details please refer to file COPYING in this
directory.

Using raw libpng in C++ may impose serious challenge since lots of
precautions must be taken to handle initialization/deinitialization of
control structures as well as handling errors correctly.  With png++
you can read or write PNG images just in a single line of C++ code:

png::image< png::rgb_pixel > image("input.png");
image.write("output.png");

The code reads an image from the file named "input.png", then writes
the image to a file named "output.png".  In this example png++ does
all the transformations needed to create adequate in-memory RGB
representation of the image (well, in most cases it simply instructs
libpng to do so).

The image in "input.png" can be RGB image, or it might be grayscale or
even indexed image with a palette--png++ will just convert any input
to RGB format.  However, for technical reasons such automatic
transformation is supported for RGB and Grayscale color types only.
Optionally there may be an alpha channel in the target color space
(RGBA and Gray+Alpha respectively).


Download
========

The project is hosted at Savannah:

	http://savannah.nongnu.org/projects/pngpp/

Released source packages can be found here:

	http://download.savannah.nongnu.org/releases/pngpp/

Also, you can check out sources directly from SVN repository:

	svn://svn.sv.nongnu.org/pngpp/trunk/

or, for people w/o outgoing svn:

	http://svn.sv.nongnu.org/pngpp/trunk/

Online documentation can be found here:

	http://www.nongnu.org/pngpp/doc/html/index.html


Help
====

There is a mailing list for developers:

	http://lists.nongnu.org/mailman/listinfo/pngpp-devel

You can also contact me by dropping a mail to <alex.shulgin@gmail.com>.


Happy hacking!
--
Alex Shulgin  <alex.shulgin@gmail.com>
