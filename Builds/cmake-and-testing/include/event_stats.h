#ifndef EVENT_STATS_H
#define EVENT_STATS_H

#include "event.h"

#include <cstdint>
#include <vector>

// Add the eventCount fields. An empty vector has a total of zero.
// The result uses 64 bits so adding a few large 32-bit counts is safe.
std::uint64_t totalEventCount(const std::vector<Event>& events);

// Return a pointer to the record with the largest eventCount, or nullptr
// for an empty vector. For a tie, return the first such record.
// The pointer refers to an element of events; it does not own that element.
// The caller must keep the vector alive and avoid invalidating its elements.
const Event* findBusiestEvent(const std::vector<Event>& events);

#endif // EVENT_STATS_H
