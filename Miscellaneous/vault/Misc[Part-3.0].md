Ok. Reset.
No assumptions

## 0. What a subsequence problem really is (no shortcuts)

Array:
`a[0], a[1], ..., a[n-1]`

At **each index** you have exactly **two legal actions**:

* take `a[i]`
* skip `a[i]`

That is not a choice tree “idea”.
That is a **binary state machine**.

Brute force recursion:

```
f(i):
  if i == n: stop
  take a[i]  → f(i+1)
  skip a[i]  → f(i+1)
```

Number of leaves = `2^n`.

So the **core problem** is:

> How do we stop this binary tree from exploding?

Everything else is secondary.

---

## 1. First-principles question (this is where people skip)

Ask this **before** any technique:

> When two different paths reach the same index `i`,
> are they actually different in the future?

If **no**, you can merge them.

This single question creates **all DP**.

---

## 2. Case 1: subsequence existence (YES / NO)

### Example

Subset sum:
“Is there a subsequence with sum = K?”

### Brute force state

Path history:

```
picked elements so far
current sum
current index
```

But ask the key question:

> If two paths reach index `i` with the same remaining sum,
> will their future possibilities differ?

Answer: **no**

So the **only future-relevant state** is:

```
(index i, remaining_sum)
```

### Collapse

Instead of exploring both paths separately:

* merge them into one state

This converts:

* exponential tree
  → DAG

This is DP **not as a trick**, but as **state merging**.

---

## 3. Why this works (no handwaving)

At index `i`:

* elements `[i..n-1]` are fixed
* past choices don’t matter except for what they caused

If two histories produce the **same constraints**, they are equivalent.

That is the entire justification.

---

## 4. Case 2: subsequence optimization (MAX / MIN)

### Example

Maximum sum subsequence
LIS (longest increasing subsequence)

### What breaks naive DP

You might think state is:

```
(index, chosen_elements)
```

That’s exponential. Useless.

So ask again:

> What part of the past actually affects future choices?

For LIS:

* Only the **last chosen value** matters
* Not the whole subsequence

So valid state:

```
(index i, last_value)
```

Now DP becomes possible.

---

## 5. Why LIS can be optimized further (important)

Even `(i, last_value)` is too big.

Observation:
If you have two states at same length:

```
length = L
tail = x   and   tail = y
```

and `x < y`:

Then state `(L, y)` is **strictly worse**.
It allows fewer future extensions.

So you can **delete it forever**.

This is not greedy magic.
This is **dominance elimination**.

That’s why LIS becomes `O(n log n)`.

---

## 6. Case 3: counting subsequences (not listing)

### Example

Count subsequences with sum = K
Count distinct subsequences

Brute force:

* enumerate all
* count valid ones

Same merging idea, but instead of `bool`, store **count**.

State:

```
dp[i][state] = number of ways
```

Transitions:

* skip → add counts
* take → add counts

This works because:

> Counting paths that reach the same state is additive.

You didn’t reduce branches.
You **merged their results**.

---

## 7. Case 4: order-constrained subsequences

### Example

* increasing
* alternating
* bounded difference

Again ask:

> What single fact from the past constrains the future?

Examples:

* last value
* last parity
* last sign

That becomes part of the state.

Everything else is discarded.

---

## 8. Case 5: small n → bitmask

This one is mechanical.

If:

* `n ≤ 20`
* interactions depend on *which elements* are chosen

Then:

```
mask ∈ [0, 2^n)
```

Mask **is** the subsequence identity.

DP over masks:

* order removed
* permutations killed

No philosophy here. Just encoding.

---

## 9. One mental invariant (this is critical)

For subsequences:

> You never reduce time by iterating faster
> You reduce time by **merging futures**

If two paths have the same future, they must be merged.
If one state is strictly worse, it must be deleted.

---

## 10. Why people get stuck at “intermediate”

Because they:

* think in elements
* not in **state equivalence**

They ask:

> “Which elements do I pick?”

Instead of:

> “Which histories are equivalent from here?”

---

## 11. Subarray vs Subsequence (deep contrast)

* Subarray:
  kill states by **movement invariants**
* Subsequence:
  kill states by **equivalence + dominance**

Same idea. Different geometry.

---

## Final compression (no fluff)

Subsequence problems reduce to:

1. Binary choice causes explosion
2. Explosion is killed by merging equivalent futures
3. DP state = minimal future-relevant info
4. Dominated states are deleted
5. Counting aggregates paths, not elements



---

### Execution cue

Take **subset sum**.
Write the recursion tree.
Mark all nodes with same `(i, remaining)`.
Physically merge them on paper.
That act **is** understanding subsequence DP.
