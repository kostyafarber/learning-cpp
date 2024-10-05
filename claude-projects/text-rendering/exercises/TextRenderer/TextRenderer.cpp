#include "TextRenderer.h"
#include <iostream>

using namespace std;

WindowRendererException::WindowRendererException(const string &message)
    : runtime_error(message) {};

TextRenderer::TextRenderer(string face_path) {
  if (auto error = FT_Init_FreeType(&ft_lib)) {
    throw WindowRendererException("failed to initialise FreeType library");
  }

  auto error = FT_New_Face(ft_lib, face_path.c_str(), 0, &face);

  if (error) {
    throw WindowRendererException(
        format("failed to load font at {}", face_path));
  }
}

void TextRenderer::set_font_size(int size) {
  if (auto error = FT_Set_Pixel_Sizes(face, size, size)) {
    throw WindowRendererException(format("error setting size: {}", size));
  }
}

void TextRenderer::load_char(double c) {
  if (auto error = FT_Load_Char(face, c, 0)) {
    throw WindowRendererException("failed to load glyph");
  }
}

void TextRenderer::print_width(string text) {
  for (auto const &c : text) {
    load_char(c);
    cout << format("width of {} is {}\n", c, face->glyph->metrics.width / 64);
  }
}
