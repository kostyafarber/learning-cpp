#include <SDL2/SDL.h>
#include <ft2build.h>
#include FT_FREETYPE_H
#include "TextRenderer.h"

using namespace std;

/*
Create a simple function that takes a string and font size, and prints out the
width of each character in pixels.
*/
int main() {
  TextRenderer tr(
      "/Users/kostyafarber/Library/Fonts/BerkeleyMonoVariable-Regular.ttf");
  string text_to_render = "TANSTAAFL";

  tr.set_font_size(16);
  tr.print_width(text_to_render);
}