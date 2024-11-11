#include "event_emitter.h"

EventHandle EventEmitter::on(string event_name, Handler h) {
  auto e = EventHandle(this, event_name, m_next_handler_id);
  m_handlers[event_name].push_back(make_pair(m_next_handler_id, h));

  m_next_handler_id++;
  return e;
}

void EventEmitter::unregister(string event_name, size_t handler_id) {
  auto &handlers = m_handlers[event_name];
  handlers.erase(remove_if(handlers.begin(), handlers.end(),
                           [handler_id](auto const &pair) {
                             return pair.first == handler_id;
                           }),
                 handlers.end());
}

void EventEmitter::emit(string event_name, string event_data) {
  Event e(event_name, event_data);

  auto handlers = m_handlers[event_name];

  // this is making copies
  for (auto const &h : handlers) {
    h.second(e);
  }
}
