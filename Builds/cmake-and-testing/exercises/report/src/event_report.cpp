#include "event_report.h"
#include "event_stats.h"

#include <ostream>

void printEventSummary(std::ostream& output, const std::vector<Event>& events) {
    output << "Records: " << events.size() << '\n';
    output << "Total event count: " << totalEventCount(events) << '\n';

    const Event* busiest {findBusiestEvent(events)};
    if (busiest != nullptr) {
        output << "Busiest record: " << busiest->eventCount
               << " events at " << busiest->elapsedSeconds << " seconds\n";
    } else {
        output << "No events.\n";
    }
}
