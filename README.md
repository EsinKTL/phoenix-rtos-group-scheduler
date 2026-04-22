# Group-Based Scheduler Implementation for Phoenix-RTOS

This repository contains a custom implementation of a **Group-Based Scheduling** algorithm within the [Phoenix-RTOS](https://phoenix-rtos.com/) microkernel. This project was developed as part of an operating systems research assignment to manage CPU resources across distinct task groups with specific time quanta.

## Overview

The standard Phoenix-RTOS scheduler was extended to support a hierarchical group scheduling logic. Tasks are assigned to one of three groups (A, B, or C), and each group is allocated a specific number of CPU quanta. This ensures predictable execution ratios and prevents low-priority groups from consuming excessive resources.

### Key Modifications
- **Kernel Space:** Modified `_threads_schedule` to implement group-switching logic.
- **System Calls:** Integrated `setGroup` and `setQuanta` to allow user-space applications to configure scheduler behavior.
- **Library (libphoenix):** Added API wrappers to bridge user applications with the new kernel functionality.

---

## Technical Implementation

### Scheduler Logic
The scheduler operates on a Round-Robin basis between groups. The execution flow follows this cycle:
1. **Selection:** The kernel selects the next thread from the current active group.
2. **Quanta Consumption:** Each tick reduces the `currentQuantaLeft` for that group.
3. **Context Switch:** Once a group exhausts its quanta, the scheduler switches to the next group in the `A -> B -> C -> A` sequence.

### System Call Interface
```c
int setGroup(int group);              // Assigns the calling process to a group (0, 1, or 2)
int setQuanta(int group, int quanta); // Sets the CPU time slice for a specific group
