# Automotive Functional Safety

* part failure = Critical failures must not occur.

## What is Functional Safety

There are different separated types of safeties:

* **Safety:** Protect the system from hazards.
* **Functional Safety:** Protect the system from hazards caused by electric system that might cause malfunction in electronic components like memory corruption.
* **Active Safety:** to protect the vehicle passengers from possible collisions and other dangers like **ADAS**.
* **Security:** To protect the system from hacking activities.

**Electrical / Electronic System**:

* Is a combination of electric and electronic components integrated in one system.

**Functional Safety**:

* The absence of unreasonable risk due to hazards caused by malfunctioning behavior of E/E system or software error hazards.

**Safety**:

* The absence of unreasonable risk.

**Active Safety**:

* A system helps to prevent or mitigate road crashes.

**Fu.S.A.**:

* The previous three Safties protect **Humans** from **Vehicles**.

**Security**:

* To protect **Vehicles** from **humans**.

---

## ISO 26262

### Vocabulary

* An **Item**: is a system or array of system that has an effect on the overall performance of the vehicla.
* A **System**: is a set of elements represents a black box to implement certain function that can be part of an item pipeline or array.
* An **Element**: is one of the components that makes a system (H/W, S/W, etc.)

### ISO 26262 Concept Phase

1. Item definition
   * Function description
   * Scope, boundaries, interfaces
   * Operational modes

2. Hazard analysis and risk assessment of every function
   * **System failure** (Severity of failure class parameter `S[1..3]`)
   * **Driving situation** (Probability of exposure class parameter `E[1..4]`)
   * **Controllability by Driver** (Controllability class parameter `C[1..3]`)

   * The Automotive Safety Integrity Level **(ASIL)** is the sum of the three parameters based on **HARA** analysis.

3. Functional safety concept (For every safety goal)
   * Define requirements for error detection in sensing, logic, and actuauion phase.
   * Define safe states and recovery strategy.
   * Define driver warning requirements.

#### Concept Phase Output

1. Specify Function definition and get functions.
2. Get **ASIL** from **HARA** analysis for every function.
3. Put requirements which inherits functions goals **ASIL**s. Each requirement inherits **the Biggest ASIL**.

