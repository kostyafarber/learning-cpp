#include "clipboard_bridge.h"
#include "event_emitter.h"
#include <format>
#include <iostream>

int main() {
  EventEmitter emitter;

  // This handle will automatically unregister when it goes out of scope
  auto handle = emitter.on("user_login", [](const Event &e) {
    std::cout << "User logged in with data: " << e.get_data() << "\n";
  });

  // Emit an event
  emitter.emit("user_login", "user123");

  auto content = getClipboardContent();
  std::cout << std::format("clipboard content is: {}\n", content);

  return 0;
}