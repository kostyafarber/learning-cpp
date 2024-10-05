#include <SDL2/SDL.h>
#include <ft2build.h>
#include FT_FREETYPE_H
#include <stdexcept>
#include <string>

using namespace std;

class WindowRendererException : public runtime_error {
public:
  WindowRendererException(const string &message);
};

class TextRenderer {
public:
  FT_Face face;

  TextRenderer(string face_path);

  void set_font_size(int size);

  void load_char(double c);

  void print_width(string text);

private:
  FT_Library ft_lib;
};