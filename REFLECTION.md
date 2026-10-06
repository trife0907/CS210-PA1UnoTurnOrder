### 1. Why does concat only need to work between two lists of the same representation? What would you have to do differently, or what would go wrong, if you tried to make it work between a LinkedList and an ArrayList?
Concat only needs to work between two lists of the same representation because our code is only allowing us to run our 
Uno game as a LinkedList or an ArrayList. Plus, `concat()` can only work with the same representation by accessing the
other list's array or head pointer. If we wanted to concat an ArrayList and a LinkedList, we would have to change our
implementation and design entirely.

### 2. Walk through reverse() on your linked list: name the three pointers you need alive at once, and explain why losing track of any one of them mid-loop corrupts the list.
The three pointers are prev, current, and next. In my implementation of `reverse()`, the current's next pointer points to
the previous node, then I shift all the pointers down the list. Losing track of any one of them means that I lose access
to an essential part of my list, whether it be for reversing pointers or traversing, and I corrupt my list.

### 3. addAnywhere and deleteAnywhere both need a bounds check. What’s the valid range for position in each, and what does your implementation do if a caller passes a position outside it?
For `addAnywhere()`, the valid range for `position` is [0, size_]. For `deleteAnywhere()`, the valid range is [0, size_ - 1].
If a caller passes a position outside these bounds, I print an error message and simple return without executing the function.

### 4. In LinkedList::concat, why did you need to walk to the end of the list first, when addFront and deleteFront never needed to? What would change about concat’s performance if LinkedList still tracked a tail pointer, and what would you have to keep updated elsewhere if you added one back?
In `LinkedList::concat`, we only have a head pointer, so we have to walk to the end of the list first so you can attach the last node to the other
list's head node. That's the goal of `concat()`. If LinkedList tracked a tail_ pointer, then the concatenation would
take O(1) time because it simply updates the tail pointer. However, we would now keep track of this new tail pointer
for all operations, not just `concat()`.

### 5. Pick either addAnywhere or deleteAnywhere in ArrayList and explain, in your own words, what has to shift and in which direction, and why shifting in the wrong direction would overwrite data you still need.
In `addAnywhere()` in `ArrayList`, the data in the elements from `position` to the end of the list have to shift up, or
to the right, by one. This is because we need to make room for an insertion at the index of `position`. Shifting to the
left would cause shifted data to be overwritten by the next shift, causing us to lose important data.

### 6. Point to the exact line in your main.cpp where a Reverse card actually changes the direction of play, and explain what would visibly break in the game if that call were missing.
Line 90 in `main.cpp` is where `table1->reverse()` runs, and the turn order is reversed. If this call were missing, then
turn order would never be reversed and the played Reverse card would have no effect.