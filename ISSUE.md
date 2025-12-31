# Roadmap to Basic Common Lisp Implementation

The goal is to create a minimal working Common Lisp environment (REPL).

## Tasks

- [x] **Fix Build System**: Ensure the project compiles on Linux (GCC).
- [x] **Core Data Structures**: Implement Cons cells, Symbols, and basic object system.
- [x] **Memory Management**: Implement basic `malloc` wrappers (Garbage Collection is future work).
- [x] **Reader**: Implement `snow_read` to parse S-expressions (Symbols, Lists).
- [x] **Printer**: Implement `snow_print` to display S-expressions.
- [x] **Evaluator**: Implement `snow_eval` (currently Identity, needs expansion).
- [x] **REPL**: Create a main loop connecting Read, Eval, and Print.
- [ ] **Environment Support**: Implement variable binding and lookup.
- [ ] **Builtin Functions**: Implement basic arithmetic and list manipulation (`car`, `cdr`, `cons`).
- [ ] **Special Forms**: Implement `quote`, `if`, `setq`, `lambda`.

## Current Status

The project now compiles and has a basic REPL that can read and print lists and symbols. Evaluation is currently an identity function.
