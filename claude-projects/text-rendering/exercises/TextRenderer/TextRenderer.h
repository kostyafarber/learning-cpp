#include <stdexcept>
#include <string>

using namespace std;

class TextRendererException : public runtime_error {
public:
  TextRendererException(const string &message);
};

class TextRenderer {
public:
  TextRenderer(string face_path);

  void set_font_size(int size);

  void load_char(double c);

  void render_char(double c);

  void print_width(string text);

  ~TextRenderer();

private:
};