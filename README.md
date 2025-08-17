# tofu

A practical, safe flexible use language focused on one-way simplicity, great DX, and built-in concurrency.

## Status
- Stage 0: LLVM-based seed compiler in C++ (this repo), minimal runtime shim.
- Next: type system + `Result/try`, iterators, `match/switch`, ARC/arenas; self-hosting.

## Build (seed)
```sh
cmake -S compiler -B build && cmake --build build --parallel
cmake -S runtime -B build-rt && cmake --build build-rt --parallel
```

## Try

```
# once example driver lands:
./build/tofu build examples/hello.tofu -o hello
./hello
```

## Governance & contribution
- **TEPs** (Tofu Enhancement Proposals): `docs/design/teps/TEP-xxxx.md`
- **Contributing:** `CONTRIBUTING.md` (style, DCO/CLA if desired, code review policy)
- **License:** pick **Apache-2.0** or **MIT** (common for languages)
- **CODEOWNERS:** seed with you + core maintainers; expand later
- **Issue labels:** `area:compiler`, `area:runtime`, `area:stdlib`, `kind:bug`, `kind:feature`, `good-first-issue`

## Dev ergonomics
- `./tools/dev.sh` (POSIX) / `tools/dev.ps1` (Win) for common tasks:
  - bootstrap LLVM (optional), configure, build, test, format
- `clang-format` for C/C++; later `tofu fmt` for Tofu code
- Pre-commit hooks (format, basic lint)
