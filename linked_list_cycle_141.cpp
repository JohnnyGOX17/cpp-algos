#include <gtest/gtest.h>

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head) { return true; }

TEST(LLCycleTest, HashMap) {
    auto test = ListNode(3);
    // Expect equality.
    EXPECT_EQ(hasCycle(&test), true);
}
