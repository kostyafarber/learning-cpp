#pragma once
#include <cstddef>
#include <functional>
#include <string>

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
      : m_name(std::move(other.m_name)), m_data(std::move(other.m_data)) {}

  Event &operator=(Event &&other) {
    m_name = std::move(other.m_name);
    m_data = std::move(other.m_data);

    return *this;
  };
};

class EventHandle;

class EventEmitter {
  using Handler = std::function<void(const Event &)>;

  std::unordered_map<string, vector<std::pair<size_t, Handler>>> m_handlers;
  size_t m_next_handler_id = 0;

public:
  EventHandle on(string event_name, Handler h);

  void unregister(string event_name, size_t handler_id);
  void emit(string event_name, string event_data);
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
      : m_emitter(std::move(other.m_emitter)),
        m_event_name(std::move(other.m_event_name)),
        m_handler_id(std::move(other.m_handler_id)) {
    other.m_emitter = nullptr;
  }

  EventHandle &operator=(EventHandle &&other) {
    m_emitter = std::move(other.m_emitter);
    m_event_name = std::move(other.m_event_name);
    m_handler_id = std::move(other.m_handler_id);

    other.m_emitter = nullptr;

    return *this;
  }
};
