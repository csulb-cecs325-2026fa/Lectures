#ifndef EVENT_H
#define EVENT_H

#include <cstdint>

// The same small data model as the event-log homework. Here we supply the
// records directly, so we can study builds and debugging without file I/O.
struct Event {
    std::uint32_t elapsedSeconds {};
    std::uint32_t eventCount {};
};

#endif // EVENT_H
