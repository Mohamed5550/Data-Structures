# Heap Data Structure

## Contents

- What is Heap?
- How heap works
- Heap sort
- Priority queue

---

## What is Heap?

- Heap is a data structure which stores the data in a `binary tree` with one additional conditions which is for *`max-heaps`*, every element should larger than or equal all elements below it, and vise versa for *`min-heaps`*.

- Every Level in the heap should be completely filled before putting starting a new level, so the heap size is at max equals **`2n`**

## How heap works

- To understand how heap works we should first understand the `max-heapify` action.

### Max-Heapify

    It is the method of puttin the current node in its correct place regarding all nodes below it, and this runs in 3 steps:
        - compare the node with its left child
        - compare the greatest of them with the right child
        - if the current node is not the greater, do the first step again with its new position
        - Remember to stop when the left and right are out of bounds

Now that's all about how `heapify`

But wait! how do we go to left and right?

- it's simple, when we start with the index `1` and it is a complete binary tree (yes, it is heap) left always equals `2i`, and right is `2i+1`

### Building a heap

- To build a heap we just run the heapify method to all node starting with n/2 down to 1

- Why n/2 and not n?
  - Because all other nodes after n/2 are leafes, which has no left or right, so there will be no effect to run heapify on them

- Why top to down and now down to top?
  - Because heapify is only affected with what below it, so we maintain all the nodes below the current node before we heapify it. Consider this heap `2 1 1 3`:
    - If we go from down to top, we first exchange the right `1` with `3` then we exchange `3` with `2` to make the heap like this: `3 2 1 1`
    - If we go fro top to down, we don't exchange `2` with any of the `ones`, then when we go to `1` we exchange it with `3` then we terminate, that makes the heap like this: `2 3 1 1`, which is not a correct heap

---

## Heap sort

- We now have a heap, how to use it to sort in nlog(n)?
- After we have a valid heap we will use it to sort by doing only two steps from n to 1:
  - We swap the first elment in the heap with the last one
    - Why? becasue we know it is the largest element in the heap, so it should be the last element.
  - We run heapify on the first element but to (i-1) to ignore the last element we have put, so we have now a heap of `size = i-1`.
  - We repeat these two operations until the heap size equals only one element which will be the smalles element in the heap. After that the heap will be sorted

- Why is its complexity nlogn?
  - Because we run on whole array and run heapify each time and we know heapify takes logn.
