Below is the **exact, end-to-end Low Level Design (LLD) roadmap**, ordered from first principles to interview-ready.
Everything is included **only if it shows up in real interviews**.
Language context: **C++**.
No theory for theory’s sake.

---

## 0. Why LLD Exists (First Principles) — **MANDATORY**

**Problem without LLD**

* Code works for the first version.
* Any change (new feature, rule, scale) causes cascading edits.
* Interviewers see “working code” that collapses under small requirement changes.

**Why naive approaches fail**

* Single `main()` / god classes.
* Logic tied directly to data structures.
* Conditionals (`if/else`, `switch`) grow linearly with requirements.

**What LLD fixes**

* Separates *what varies* from *what stays stable*.
* Allows extension without rewriting existing code.
* Makes reasoning about behavior possible before coding.

**Interview signal**

* Interviewer is testing *change tolerance*, not syntax.
* They intentionally add requirements mid-interview.

**Dependency**

* None. This is the mental baseline.

---

## 1. Object-Oriented Thinking (Not OOP Syntax) — **MANDATORY**

### 1.1 Objects vs Functions

**Problem without this**

* You write procedural logic with structs/classes as passive containers.

**Naive failure**

* Functions take many parameters.
* Data invariants are not enforced.

**Concept**

* Objects own both **state + behavior**.
* Invariants live inside objects.

**Interview**

* Interviewer asks: “Who should own this responsibility?”

---

### 1.2 Responsibility Assignment (Core Skill)

**Problem**

* Unsure where logic should go.

**Naive failure**

* “Utility” or “Manager” classes do everything.

**Concept**

* Each class has **one reason to change**.
* Behavior lives closest to the data it uses.

**Interview**

* “Why is this method in this class?”

---

### 1.3 Encapsulation (Real Meaning)

**Problem**

* Any part of code can mutate any data.

**Naive failure**

* Public fields, setters everywhere.

**Concept**

* Hide representation, expose behavior.
* Protect invariants.

**Interview**

* Changing internal data structure should not break users.

---

### 1.4 Abstraction vs Interface (C++ specific)

**Problem**

* Overuse of abstract classes without need.

**Naive failure**

* Abstract base classes with no polymorphic usage.

**Concept**

* Abstraction exists to **decouple**.
* Use when multiple implementations or testing substitution is needed.

**Interview**

* “Why is this an interface?”

---

## 2. Relationships Between Objects — **MANDATORY**

### 2.1 Association / Aggregation / Composition

**Problem**

* Memory ownership confusion.

**Naive failure**

* Raw pointers everywhere.
* Leaks or unclear lifetimes.

**Concept**

* Composition = ownership.
* Aggregation = reference without ownership.

**Interview**

* “Who creates and destroys this object?”

---

### 2.2 Dependency Direction

**Problem**

* High-level logic depends on low-level details.

**Naive failure**

* Business logic directly uses concrete classes.

**Concept**

* Depend on abstractions, not implementations.

**Interview**

* Mocking or swapping implementations.

---

## 3. SOLID (Practical, Not Textbook) — **MANDATORY**

### 3.1 Single Responsibility Principle (SRP)

**Problem**

* One class changes for many reasons.

**Naive failure**

* `UserManager`, `OrderProcessor` doing everything.

**Fix**

* Separate by *reason to change*, not by method count.

**Interview**

* “What breaks if requirement X changes?”

---

### 3.2 Open/Closed Principle (OCP)

**Problem**

* New feature requires editing existing code.

**Naive failure**

* `switch(type)` everywhere.

**Fix**

* Polymorphism.
* Strategy pattern (later).

**Interview**

* “How would you add a new payment method?”

---

### 3.3 Liskov Substitution Principle (LSP)

**Problem**

* Subclasses break base assumptions.

**Naive failure**

* Overriding methods that weaken contracts.

**Fix**

* Subtypes must be usable as base type.

**Interview**

* Edge cases when replacing implementations.

---

### 3.4 Interface Segregation Principle (ISP)

**Problem**

* Fat interfaces.

**Naive failure**

* Classes forced to implement unused methods.

**Fix**

* Small, focused interfaces.

**Interview**

* Cleaner mocking and testing discussion.

---

### 3.5 Dependency Inversion Principle (DIP)

**Problem**

* Hard dependencies.

**Naive failure**

* `new ConcreteClass()` inside business logic.

**Fix**

* Inject dependencies via constructor.

**Interview**

* “How would you test this class?”

---

## 4. UML Diagrams (Interview-Driven) — **MANDATORY**

### 4.1 Class Diagram

**Purpose**

* Structure, not behavior.

**Interview**

* Primary diagram used.
* Shows classes, relationships, multiplicity.

---

### 4.2 Sequence Diagram

**Purpose**

* Interaction flow.

**Interview**

* Used when explaining scenarios (booking, payment).

---

### 4.3 When NOT to draw UML

* Don’t waste time drawing all diagrams.
* Only draw when interviewer asks or confusion exists.

---

## 5. Design Patterns (Only the Ones That Matter) — **MANDATORY CORE**

### 5.1 Strategy

**Problem**

* Conditional logic explosion.

**Fix**

* Encapsulate algorithms.

**Used in**

* Payment methods, pricing rules, cache eviction.

---

### 5.2 Factory / Abstract Factory

**Problem**

* Object creation logic scattered.

**Fix**

* Centralize creation.

**Used in**

* Vehicle creation (Parking Lot), Payment gateways.

---

### 5.3 Observer

**Problem**

* Tight coupling for notifications.

**Fix**

* Publish/subscribe.

**Used in**

* Seat availability, stock alerts.

---

### 5.4 Singleton (Controlled Use)

**Problem**

* Shared resource.

**Caution**

* Overuse is a red flag.

**Used in**

* Config, logger.

---

### Optional (Know conceptually)

* Decorator
* Command
* State

---

## 6. Concurrency & Thread Safety (Selective) — **OPTIONAL but HIGH SIGNAL**

**Problem**

* Race conditions.

**Naive failure**

* Ignoring concurrency completely.

**Concepts**

* Mutex
* Atomic
* Thread-safe design boundaries

**Interview**

* Cache, booking systems.

---

## 7. Canonical LLD Interview Problems — **MANDATORY**

### 7.1 Parking Lot

**Focus**

* Vehicle types
* Spot allocation
* Entry/Exit flow

**Patterns**

* Strategy, Factory

**Mistakes**

* Over-modeling
* Ignoring extensibility

---

### 7.2 LRU Cache

**Focus**

* O(1) operations
* Separation of policy vs storage

**Patterns**

* Strategy

---

### 7.3 Elevator System

**Focus**

* Request handling
* Scheduling abstraction

**Mistakes**

* Jumping into algorithms before design

---

### 7.4 BookMyShow / Ticket Booking

**Focus**

* Seat locking
* State transitions

**Mistakes**

* Ignoring concurrency
* No clear ownership

---

### 7.5 Vending Machine

**Focus**

* State pattern
* Payment handling

---

## 8. How Interviewers Evaluate You — **MANDATORY**

### What they look for

* Clear responsibility boundaries
* Ability to handle change
* Tradeoff discussion

### Common rejection reasons (from Reddit/LC)

* Coding too early
* Overusing patterns
* Ignoring interviewer hints
* Overengineering

---

## 9. LLD Interview Thinking Framework — **MANDATORY**

**Step 1**: Clarify requirements
**Step 2**: Identify core entities
**Step 3**: Assign responsibilities
**Step 4**: Define relationships
**Step 5**: Add extensibility points
**Step 6**: Code only if asked

---

## 10. What Is NOT Required

* Clean Architecture
* Hexagonal Architecture
* Microservices
* Event sourcing

These are **system design**, not LLD.

---

### Final dependency order (compressed)

```
Why LLD
→ Object responsibilities
→ OOP fundamentals
→ Relationships & ownership
→ SOLID
→ UML
→ Core design patterns
→ Interview problems
→ Interview communication
```

This roadmap is complete.
Nothing essential is missing.
Nothing extra is included.

**Execution cue:** pick **Parking Lot**, do only steps 1–4 today, no code.
