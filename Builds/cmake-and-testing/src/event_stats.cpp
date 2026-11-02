#include "event_stats.h"

#include <cstddef>

std::uint64_t totalEventCount(const std::vector<Event>& events) {
    std::uint64_t total {};
    for (const Event& event : events) {
        total += event.eventCount;
    }
    return total;
}

const Event* findBusiestEvent(const std::vector<Event>& events) {
    const Event* busiest {nullptr};

    // We will inspect this loop with a test and a debugger during the lesson.
    for (std::size_t index {1}; index < events.size(); ++index) {
        const Event& candidate {events[index]};
        if (busiest == nullptr || candidate.eventCount > busiest->eventCount) {
            busiest = &candidate;
        }
    }

    return busiest;
}
