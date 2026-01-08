Short answer: **monotonic stacks remove *comparative redundancy***.

Now the precise breakdown.

---

### The problem *without* a monotonic stack

In array problems, you repeatedly ask questions like:

* “What is the **next smaller** element to the right?”
* “What is the **previous greater** element to the left?”
* “For how many subarrays is `a[i]` the minimum/maximum?”

A naïve approach does this:

For each index `i`
→ scan left
→ scan right

That means:

* The **same elements are compared again and again**
* An element that was already proven useless is still rechecked

Example (next smaller element):

```
[5, 4, 3, 2, 1]
```

For `5`: compare with 4,3,2,1
For `4`: compare with 3,2,1
For `3`: compare with 2,1

Same comparisons repeated.
That is the redundancy.

---

### What redundancy exactly gets removed?

A monotonic stack removes **redundant dominance checks**.

Once an element:

* is **dominated** (smaller for min-stack / larger for max-stack)
* by a newer element

it can **never** be the answer for any future index.

So keeping it is pointless.

---

### Core invariant

In a **monotonic increasing stack**:

```
stack bottom -> top
a[i1] < a[i2] < a[i3] < ...
```

If a new element `x` arrives:

* While `stack.top() >= x` → pop

Why?

Because:

* `x` is closer
* `x` is smaller or equal
* `x` kills all larger elements behind it forever

Those popped elements are **redundant states**.

---

### Type of redundancy eliminated

#### 1. **Redundant comparisons**

Each element is:

* pushed once
* popped once

So total comparisons = O(n)

Instead of re-comparing the same pairs across many scans.

---

#### 2. **Redundant candidates**

Elements that:

* can never be next/previous smaller/greater
* for any future index

are discarded immediately.

---

#### 3. **Redundant subarray boundaries**

In problems like:

* Sum of Subarray Minimums
* Largest Rectangle in Histogram

You need:

```
how far left?
how far right?
```

Naively:

* recompute boundaries repeatedly

Monotonic stack:

* computes each boundary **once**
* stores exact dominance span

---

### Why stack order matters

The stack enforces a **total order of usefulness**.

Elements in the stack are:

* strictly ordered
* still *alive* as potential answers

Anything breaking that order is useless.

---

### One-line mental model

> A monotonic stack removes elements that are **provably never optimal again**.

No magic.
No tricks.
Just aggressive pruning of dead comparisons.

---

### Concrete C++ sketch (next smaller to right)

```cpp
vector<int> nsr(n, n);
stack<int> st;

for (int i = 0; i < n; i++) {
    while (!st.empty() && a[st.top()] > a[i]) {
        nsr[st.top()] = i;
        st.pop();
    }
    st.push(i);
}
```

Each index:

* enters once
* exits once
  No repeated scans.

