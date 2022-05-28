# Fenwik Tree

## What is Fenwit Tree or Bainry Indexed Tree

    - It is a data structure for calculating range queries
    - Its complexity is O(nlog(n)))

## How it works

    - Each index is responsible for the 2^(x-1) indicies below it, which x is the place of its least signigicant bit.

### For Example:

- **12** is 1100 in binary, the leas signigicant bit is 3 so it is reponsible of *2^2=4* bits below it. and so on.

### Calculating ranges

    - By this way we can get the value of 1 to i, which i is any index in the array. Thus we can ge the value of any range between i and j. 
