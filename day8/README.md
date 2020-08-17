# Day 8

## Create/Instantiate objects

- Allocate on the stack

  The basic way to allocate data in the memory.

  The allocated data will be destroyed after end curly bracket, such as local variables.

  ```cpp
  Entity entity("Minho"); // Stack
  ```

- Allocate on the heap

  Data allocated in the heap must be freed manually.
