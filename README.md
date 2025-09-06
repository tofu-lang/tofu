# tofu

A practical, safe flexible use language focused on one-way simplicity, great DX, and built-in concurrency.

## Roadmap

| Milestone | Focus | Acceptance Criteria | Key Risks |
|-----------|-------|---------------------|-----------|
| **M0** | Repo scaffold & version CLI | `tofu --version` prints version; CI builds | None |
| **M1** | Lexer & basic parser | Tokenize and parse variable/func decls and literals; unit tests | Tokenization rules may evolve, requiring refactors |
| **M2** | AST + semantic analysis | Resolve names/types for primitives, structs, enums; simple type errors reported | Complexity of structural interfaces |
| **M3** | LLVM codegen for expressions & functions | Compile & run "hello world"; minimal runtime for strings/slices | Integrating ARC with LLVM IR |
| **M4** | Control flow & composite types | if/for/match, tuples, arrays, optionals/results; tests covering zero values | Exhaustive pattern checking complexity |
| **M5** | Memory model & concurrency | ARC/arena prototype, channels, spawn/join; cross-task safety checks | Concurrency semantics and ARC elision correctness |
| **M6** | Modules, tooling & stdlib core | Absolute imports, formatter, basic LSP features, core:fmt/io/errors modules | Scope creep in tooling vs. language features |

