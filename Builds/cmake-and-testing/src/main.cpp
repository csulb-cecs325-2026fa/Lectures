#include "event_stats.h"

#include <iostream>
#include <vector>

int main() {
    const std::vector<Event> events {
        {10, 5},
        {20, 100},
        {30, 5}
    };

    std::cout << "Records: " << events.size() << '\n';
    std::cout << "Total event count: " << totalEventCount(events) << '\n';

    const Event* busiest {findBusiestEvent(events)};
    if (busiest != nullptr) {
        std::cout << "Busiest record: " << busiest->eventCount
                  << " events at " << busiest->elapsedSeconds << " seconds\n";
    } else {
        std::cout << "No events.\n";
    }
}
