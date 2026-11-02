// Optional supplied boundary test. First try writing this test yourself.
// Add this file to the event_stats_tests target to build and discover it.
#include "event_stats.h"

#include <gtest/gtest.h>

#include <vector>

TEST(FindBusiestEvent, ALogWithOneRecordReturnsThatRecord) {
    const std::vector<Event> events {{10, 5}};
    EXPECT_EQ(findBusiestEvent(events), &events[0]);
}
