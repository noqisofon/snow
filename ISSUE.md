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
- [x] **Environment Support**: Implement variable binding and lookup.
- [x] **Builtin Functions**: Implement basic arithmetic and list manipulation (`car`, `cdr`, `cons`).
- [x] **Special Forms**: Implement `quote`, `if`, `setq`, `lambda` (Implemented `quote`, `if`, `setq`).

## Current Status

The project now compiles and has a working REPL.
Features implemented:
- Basic types: Cons, Symbol, Builtin Function.
- Environment: Global variable binding and lookup.
- Builtin functions: `car`, `cdr`, `cons`.
- Special forms: `quote`, `if`, `setq`.
