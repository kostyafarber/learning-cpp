#include "TextRenderer.h"

TextRendererException::TextRendererException(const string &message)
    : runtime_error(message) {};

TextRenderer::TextRenderer(const string &font_path) {
  if (!font.loadFromFile(font_path)) {
    throw TextRendererException("error loading font");
  }
}

TextRenderer::~TextRenderer() {};
