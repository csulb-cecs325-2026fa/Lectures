#ifndef EVENT_REPORT_H
#define EVENT_REPORT_H

#include "event.h"

#include <iosfwd>
#include <vector>

// Write the same summary as the original main(), using the supplied stream.
// This lets a caller choose std::cout, a file stream, or a string stream.
void printEventSummary(std::ostream& output, const std::vector<Event>& events);

#endif // EVENT_REPORT_H
