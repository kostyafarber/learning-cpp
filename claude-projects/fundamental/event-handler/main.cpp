#include <algorithm>
#include <cstddef>
#include <functional>
#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>

class EventEmitter;

using namespace std;
class Event {
private:
  string m_name;
  string m_data;

public:
  Event(string name, string data) : m_name(name), m_data(data) {};

  string get_name() const { return m_name; }
  string get_data() const { return m_data; }

  Event(Event &) = delete;
  Event &operator=(Event &) = delete;

  Event(Event &&other)
      : m_name(move(other.m_name)), m_data(move(other.m_data)) {}

  Event &operator=(Event &&other) {
    m_name = move(other.m_name);
    m_data = move(other.m_data);

    return *this;
  }
};

class EventHandle {
private:
  EventEmitter *m_emitter;
  string m_event_name;
  size_t m_handler_id;

public:
  EventHandle(EventEmitter *emitter, string event_name, size_t handler_id)
      : m_emitter(emitter), m_event_name(event_name),
        m_handler_id(handler_id) {};

  ~EventHandle() { m_emitter = nullptr; }

  EventHandle(EventHandle &) = delete;
  EventHandle &operator=(EventHandle &) = delete;

  EventHandle(EventHandle &&other)
      : m_emitter(move(other.m_emitter)),
        m_event_name(move(other.m_event_name)),
        m_handler_id(move(other.m_handler_id)) {
    other.m_emitter = nullptr;
  }

  EventHandle &operator=(EventHandle &&other) {
    m_emitter = move(other.m_emitter);
    m_event_name = move(other.m_event_name);
    m_handler_id = move(other.m_handler_id);

    other.m_emitter = nullptr;

    return *this;
  }
};

class EventEmitter {
  // need to understand this syntax is it like a type alias? like in Go type
  // Handler func()...
  using Handler = std::function<void(const Event &)>;

  std::unordered_map<string, vector<std::pair<size_t, Handler>>> m_handlers;
  size_t m_next_handler_id = 0;

public:
  EventHandle on(string event_name, Handler h) {
    auto e = EventHandle(this, event_name, m_next_handler_id);
    m_handlers[event_name].push_back(make_pair(m_next_handler_id, h));

    m_next_handler_id++;
    return e;
  }

  void unregister(string event_name, size_t handler_id) {
    auto &handlers = m_handlers[event_name];
    handlers.erase(remove_if(handlers.begin(), handlers.end(),
                             [handler_id](auto const &pair) {
                               return pair.first == handler_id;
                             }),
                   handlers.end());
  }

  void emit(string event_name, string event_data) {
    Event e(event_name, event_data);

    auto handlers = m_handlers[event_name];

    // this is making copies
    for (auto const &h : handlers) {
      h.second(e);
    }
  }
};

// Example usage:
int main() {
  EventEmitter emitter;

  // This handle will automatically unregister when it goes out of scope
  auto handle = emitter.on("user_login", [](const Event &e) {
    std::cout << "User logged in with data: " << e.get_data() << "\n";
  });

  // Emit an event
  emitter.emit("user_login", "user123");

  return 0;
}