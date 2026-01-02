

# 1. What problem we are solving

We are studying **impartial combinatorial games** under **normal play**.

Meaning:

* Two players
* Perfect information
* No randomness
* Same moves available to both players
* Players alternate turns
* **Whoever cannot move loses**

Example used throughout:

* One pile of stones
* On a move, remove **1, 2, or 3** stones

---

# 2. Fundamental goal

For every position (pile size `k`), determine:

* **Winning (W)**: current player can force a win
* **Losing (L)**: current player will lose if opponent plays optimally

This is the **only thing** we care about.

---

# 3. Definitions (non-negotiable)

### Losing position (L)

A position where:

* **No legal move** leads to a losing position for the opponent

Equivalently:

* Every move gives the opponent a winning position

### Winning position (W)

A position where:

* **At least one legal move** leads to a losing position for the opponent

You do **not** need all moves to be good.
One is enough.

---

# 4. Base case (initial anchor)

```
pile = 0
```

* No moves possible
* Player to move loses

So:

```
0 → L
```

This is not a choice. It is forced by the rules.

---

# 5. Single-pile analysis (step by step)

Allowed moves: −1, −2, −3

We classify positions using only the W/L definitions.

### pile = 1

Moves:

* 1 → 0 (L)

Exists move to L ⇒ **W**

---

### pile = 2

Moves:

* 2 → 1 (W)
* 2 → 0 (L)

Exists move to L ⇒ **W**

---

### pile = 3

Moves:

* 3 → 2 (W)
* 3 → 1 (W)
* 3 → 0 (L)

Exists move to L ⇒ **W**

---

### pile = 4

Moves:

* 4 → 3 (W)
* 4 → 2 (W)
* 4 → 1 (W)

All moves go to W ⇒ **L**

winning position means the player to move can force a win.

---

### pile = 5

Moves:

* 5 → 4 (L)
* 5 → 3 (W)
* 5 → 2 (W)

Exists move to L ⇒ **W**

---

### Resulting pattern

```
Pile:   0  1  2  3  4  5  6  7  8 ...
Result: L  W  W  W  L  W  W  W  L ...
```

Every multiple of 4 is losing.

---

# 6. Why “remove 3 at pile=3” wins

At pile = 3:

* You can remove **3**
* You make pile = 0
* Opponent’s turn
* Opponent has no move
* Opponent loses immediately

That alone makes pile = 3 a winning position.

Your earlier mistake was **mixing turns**.

---

# 7. Why numbers (labels) are introduced

W/L logic is correct but repetitive.

We compress it using **labels** (Grundy numbers):

* Losing position → label **0**
* Winning position → label **> 0**

These labels:

* Are **not** scores
* Are **not** advantages
* Are **not** number of moves
* Are **type identifiers** for positions

Two positions with the same label behave identically.

---

# 8. What mex is and why it appears

### mex = *minimum excluded non-negative integer*

Example:

```
mex{0,1,3} = 2
mex{1,2,3} = 0
```

### Why mex appears (intuition)

For a position `P`:

* Look at all positions reachable in one move
* Collect their labels
* Assign `P` the **smallest non-negative label not used by its children**

Why?

* The label must differ from all immediate options
* Smallest such label gives a canonical encoding

This **exactly** encodes:

* Losing positions get 0
* Winning positions get non-zero

No mystery. No assumption.

---

# 9. Computing labels for this game

Let `g(k)` = label of pile size `k`.

Base:

```
g(0) = 0
```

Recurrence:

```
g(k) = mex{ g(k−1), g(k−2), g(k−3) }
```

Evaluating:

```
g(1) = mex{0}       = 1
g(2) = mex{1,0}     = 2
g(3) = mex{2,1,0}   = 3
g(4) = mex{3,2,1}   = 0
g(5) = mex{0,3,2}   = 1
...
```

Pattern:

```
g(k) = k mod 4
```

Derived, not memorized.

---

# 10. Why large n (e.g. 2.4 billion) is NOT a problem

You do **not** compute all previous values.

Once periodicity is discovered:

```
g(n) = n % 4
```

So:

* Time: O(1)
* Space: O(1)

This is standard in impartial games.

---

# 11. Where XOR DOES and DOES NOT belong

### Single pile

* XOR is irrelevant
* Outcome depends only on `g(k) == 0 or not`

### Multiple independent piles

* Each pile has its own Grundy number
* The combined position is equivalent to:

```
g_total = g(pile1) XOR g(pile2) XOR ...
```

Rule:

```
g_total == 0 → losing
g_total != 0 → winning
```

This is **Sprague–Grundy theorem**.

Talking about XOR when there is only one pile is **unnecessary**.

Your objection was correct.

---

# 12. Final invariant (burn this in)

* Losing: **all moves → W**
* Winning: **exists move → L**
* Label 0 ⇔ losing
* Label ≠ 0 ⇔ winning
* mex encodes this rule
* XOR only matters when combining games

Nothing else is foundational.

---

## Conditioning cue

Rebuild the W/L table from scratch without numbers once more.
If you hesitate, you’re still skipping turn ownership.
