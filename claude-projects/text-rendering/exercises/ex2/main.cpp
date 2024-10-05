#include "TextRenderer.h"
#include <SDL.h>
#include <SDL_error.h>
#include <SDL_events.h>
#include <SDL_render.h>
#include <SDL_timer.h>
#include <SDL_video.h>
#include <arm_neon.h>
#include <format>
#include <stdexcept>
#include <string>

using namespace std;

class WindowRendererException : public runtime_error {
public:
  WindowRendererException(const string &message) : runtime_error(message) {};
};

class WindowRenderer {
public:
  WindowRenderer(int width, int height) {
    int init_flags = SDL_INIT_VIDEO;
    if (auto error = SDL_Init(init_flags) != 0) {
      throw TextRendererException("failed to init SDL2 library");
    }

    int win_ren_flags = 0;
    if (auto error = SDL_CreateWindowAndRenderer(width, height, win_ren_flags,
                                                 &window, &renderer) != 0) {
      throw TextRendererException("failed to create window and renderer");
    }
  }

  void run() {
    bool run = true;
    while (run) {
      SDL_Event e;
      while (SDL_PollEvent(&e)) {
        switch (e.type) {
        case SDL_QUIT:
          run = false;
          break;
        }
      }
    }
  };

  void render_char(FT_Bitmap bitmap) {
    auto surface = SDL_CreateRGBSurfaceFrom(
        bitmap.buffer, bitmap.width, bitmap.rows, 8, bitmap.pitch,
        0x000000ff, // red mask (all bits set for grayscale)
        0x000000ff, // green mask (all bits set for grayscale)
        0x000000ff, // blue mask (all bits set for grayscale)
        0);

    if (!surface) {
      throw WindowRendererException(
          format("failed to get surface: {}", string(SDL_GetError())));
    }

    auto texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (!texture) {
      throw WindowRendererException(
          format("failed to get texture: {}", string(SDL_GetError())));
    }

    if (auto error = SDL_RenderCopy(renderer, texture, nullptr, nullptr) != 0) {
      throw WindowRendererException(
          format("failed to get render copy: {}", string(SDL_GetError())));
    }
  }

  ~WindowRenderer() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
  };

private:
  SDL_Window *window;
  SDL_Renderer *renderer;
};

/*
Implement a basic text wrapping function that breaks a long string
into lines based on a given width.
*/
int main() {
  TextRenderer tr(
      "/Users/kostyafarber/Library/Fonts/BerkeleyMonoVariable-Regular.ttf");

  tr.load_char('T');
  WindowRenderer wr(1000, 800);

  auto bitmap = tr.face->glyph->bitmap;
  wr.render_char(bitmap);

  wr.run();
}