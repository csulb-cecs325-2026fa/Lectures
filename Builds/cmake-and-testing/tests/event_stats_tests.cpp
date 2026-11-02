#include "event_stats.h"

#include <gtest/gtest.h>

#include <cstdint>
#include <limits>
#include <vector>

TEST(TotalEventCount, EmptyLogHasZeroTotal) {
    const std::vector<Event> events;
    EXPECT_EQ(totalEventCount(events), 0);
}

TEST(TotalEventCount, AddsCountsRatherThanElapsedSeconds) {
    const std::vector<Event> events {{10, 5}, {20, 100}, {30, 5}};
    EXPECT_EQ(totalEventCount(events), 110);
}

TEST(TotalEventCount, TotalCanExceedOne32BitCount) {
    const auto largest {std::numeric_limits<std::uint32_t>::max()};
    const std::vector<Event> events {{10, largest}, {20, 1}};
    EXPECT_EQ(totalEventCount(events), std::uint64_t {largest} + 1);
}

TEST(FindBusiestEvent, EmptyLogHasNoBusiestRecord) {
    const std::vector<Event> events;
    EXPECT_EQ(findBusiestEvent(events), nullptr);
}

TEST(FindBusiestEvent, FindsTheLargestCount) {
    const std::vector<Event> events {{10, 5}, {20, 100}, {30, 5}};
    const Event* busiest{findBusiestEvent(events)};
    EXPECT_EQ(busiest, &events[1]);
}

// Do these tests demonstrate every promise in event_stats.h?
// Think about a single record, a maximum at the beginning, and tied counts.
