# LeetCode 1352: Product of the Last K Numbers

## Problem

Design an algorithm that accepts a stream of integers and retrieves the product of the last `k` numbers in the stream.

Implement the `ProductOfNumbers` class with:

- `ProductOfNumbers()` – Initializes the object.
- `add(int num)` – Adds an integer `num` to the stream.
- `getProduct(int k)` – Returns the product of the last `k` numbers.

## Approach

### Vector-Based Storage and Iteration

We use a vector to store all the numbers added to the stream.

**1. Constructor**

Initialize the `ProductOfNumbers` object. The vector starts empty.

**2. add(int num)**

Use `push_back()` to insert the new number at the end of the vector.

**3. getProduct(int k)**

- Initialize a variable `multiply = 1`.
- Calculate the starting index using `productOfNumbers.size() - k`.
- Iterate from this index to the last index of the vector.
- Multiply each element with `multiply`.
- Return the final product.

This allows us to calculate the product of the last `k` numbers whenever requested.

## C++ Solution

```cpp
class ProductOfNumbers {
private:
    vector<int> productOfNumbers;

public:
    ProductOfNumbers() {
    }

    void add(int num) {
        productOfNumbers.push_back(num);
    }

    int getProduct(int k) {
        int multiply = 1;

        for(int i = productOfNumbers.size() - k;
            i <= productOfNumbers.size() - 1; i++) {
            multiply = multiply * productOfNumbers[i];
        }

        return multiply;
    }
};
```

## Example

**Operations:**

```text
add(3)
add(0)
add(2)
add(5)
add(4)
getProduct(2)
getProduct(3)
getProduct(4)
add(8)
getProduct(2)
```

**Output:**

```text
[null, null, null, null, null, 20, 40, 0, null, 32]
```

**Explanation:**

- `getProduct(2)` → 5 × 4 = 20
- `getProduct(3)` → 2 × 5 × 4 = 40
- `getProduct(4)` → 0 × 2 × 5 × 4 = 0
- `getProduct(2)` → 4 × 8 = 32

## Complexity Analysis

Let:
- `n` = number of elements stored in the vector.
- `k` = number of elements requested.

**add(int num):**
- Time Complexity: `O(1)` amortized – Inserting an element at the end of a vector takes constant amortized time.

**getProduct(int k):**
- Time Complexity: `O(k)` – We iterate through the last `k` elements.
- Auxiliary Space Complexity: `O(1)` – We only use a multiplication variable.

**Overall Space Complexity:** `O(n)` – The vector stores all added numbers.

## Key Concepts Learned

- Designing a class using private data members and public methods.
- Using vectors for dynamic storage.
- Using `push_back()` to insert elements.
- Accessing the last `k` elements using vector indices.
- Iterating over a specific range of a vector.
- Calculating products using a loop.