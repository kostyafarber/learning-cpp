#include "event_emitter.h"
#include <functional>

class Impl;
class ClipboardWatcher {
  ClipboardWatcher();
  ~ClipboardWatcher();

  void start();
  void stop();

  using WatchHandler = std::function<void(const Event &)>;

private:
  EventEmitter *m_emitter;
  bool m_running{false};
};