Fine.
We start from **subarray** and strip this down to mechanics. 

---

## 0. What “subarray” actually means

Subarray = **contiguous range** `[L, R]`.

Brute force:

```
for L in [0..n-1]
  for R in [L..n-1]
    process a[L..R]
```

This generates **O(n²)** states.

Every subarray problem is about **not touching most of these (L, R) pairs**.

---

## 1. Aspect 1: “Value of subarray” → PREFIX SUM

### Problem type

* sum of subarray
* average
* xor
* count of something additive

### Brute force redundancy

When you move `R` by 1:

* You recompute everything from scratch.

### Key realization

Subarray value = **difference of prefixes**.

```
sum(L, R) = pref[R] - pref[L-1]
```

### What changed?

You removed the **inner loop work**, not the loops.

* States still `(L, R)`
* Computation collapsed to O(1)

This is **value compression**, not state reduction.

---

## 2. Aspect 2: “Equality / Balance” → PREFIX STATE + HASH

### Problem type

* subarray sum = K
* equal 0s and 1s
* same number of odds and evens

### Brute force redundancy

Different `(L, R)` pairs produce the **same prefix state**.

Example (0 → -1, 1 → +1):

```
prefix[i] = balance till i
```

If:

```
prefix[i] == prefix[j]
```

Then:

```
subarray (i+1, j) has balance 0
```

### Key realization

You don’t care about `(L, R)` anymore.
You care about **prefix state collisions**.

### What changed?

* State reduced from `(L, R)` → `prefix_value`
* Hash map remembers first occurrence

This is **state deduplication**.

---

## 3. Aspect 3: “Maximum / Minimum” → MONOTONIC STACK

### Problem type

* largest rectangle in histogram
* sum of subarray minimums
* next greater / smaller

### Brute force redundancy

For each index:

* Scan left
* Scan right

You keep re-checking the same comparisons.

### Key realization

Once an element is blocked by a smaller one:

* It will **never matter again**

### Mechanism

Stack keeps **only candidates that are not yet invalidated**.

Each index:

* pushed once
* popped once

### What changed?

* Killed repeated scans
* Enforced **monotonic invariant**

This is **future pruning**.

---

## 4. Aspect 4: “Fixed constraint” → SLIDING WINDOW

### Problem type

* sum ≤ K
* at most K distinct
* longest valid subarray

### Brute force redundancy

For each `L`, you expand `R` again from scratch.

### Key realization

If increasing `R` breaks validity:

* Increasing `L` can only help

This requires **monotonic validity**.

### Mechanism

Two pointers:

* `R` only moves forward
* `L` only moves forward

No backtracking.

### What changed?

* `(L, R)` space reduced from n² to O(n)
* Branching replaced by movement

This is **search space linearization**.

---

## 5. Aspect 5: “Choice / Partition” → DP ON SUBARRAYS

### Problem type

* matrix chain multiplication
* palindrome partitioning
* interval DP

### Brute force redundancy

Same subarray solved multiple times via different splits.

### Key realization

Answer for `[L, R]` depends only on smaller intervals.

### Mechanism

```
dp[L][R] = min over k in [L..R-1] of:
           dp[L][k] + dp[k+1][R] + cost
```

### What changed?

* Memoized overlapping subarrays
* Turned exponential recursion into polynomial

This is **temporal freezing**.

---

## 6. Aspect 6: “All subarrays contribution” → COUNT, NOT ENUMERATE

### Problem type

* sum of subarray minimums
* sum of ranges
* total contribution problems

### Brute force redundancy

You add same element many times.

### Key realization

Count **how many subarrays** an element participates in.

Example:

```
count = (# choices of L) * (# choices of R)
```

Boundaries found via monotonic stack.

### What changed?

* Enumeration → combinatorics
* O(n²) → O(n)

This is **global aggregation**.

---

## One unifying table

| Aspect         | Core idea           | What is eliminated |
| -------------- | ------------------- | ------------------ |
| Prefix sum     | Precompute history  | Repeated summation |
| Hash + prefix  | State collision     | Redundant ranges   |
| Sliding window | Monotonic validity  | Backtracking       |
| Stack          | Monotonic structure | Re-scanning        |
| DP             | Overlap             | Re-solving         |
| Contribution   | Counting            | Enumeration        |

---

## Final reality check

There is no “DSA secret”.

There is:

* Identify redundancy
* Decide memory form
* Enforce invariant
* Kill branches

Every intermediate problem is **one of these**, sometimes layered.

---

### Execution cue

Take **one subarray problem** you know.
Write brute force.
Label what repeats.
Ask which **aspect** above kills it.
Repeat until this mapping becomes automatic.

That’s the skill.
