# PDP-11 / Unix V1 B Compiler Plan (for SimH UNIX v1 Restoration)

This project targets development, testing, and validation of a B-to-PDP-11 C compiler using the reconstructed 1st Edition UNIX system in the [jserv/unix-v1 Restoration Repository](https://github.com/jserv/unix-v1). All compilation and execution will be performed inside the SimH PDP-11 emulator, booting disk images produced by this repository, which provides a historically faithful environment. (See also: Warren Toomey's "The Restoration of Early UNIX Artifacts.")

## Current Status: Thompson B PDP-11 1972 Lexer (kbman/btut Dialect)

The `bcc.c` file contains a functional lexical analyzer for **Thompson B (1972)** - the exact language used in kbman/btut examples and what early libb.a-style programs expect.

### Dialect Lock: THOMPSON_B_PDP11_1972
- **Reference**: kbman/btut + libb runtime expectations
- **Core Model**: Typeless word language (PDP-11 16-bit words), strings terminated by *e
- **Keywords**: auto, extrn, if, else, while, goto, switch, case, default, break, return
- **Operators**: Full set including ++ -- ?: : for complete kbman/btut coverage

### Working Features
- **Complete token recognition**: All Thompson B operators, keywords, identifiers, numbers, strings, character constants
- **Unix V1 compatibility**: Written in early K&R C style compatible with the V1 compiler
- **Robust I/O**: Uses single-byte syscalls to avoid assembler issues with byte-packing
- **Error handling**: Proper error reporting with clean output formatting

### Usage
```bash
# Compile on Unix V1
cc bcc.c
./a.out

# Type B code (e.g., "auto x = 5;") and press Ctrl+D
# Output shows token types and values:
# tok=28 name=auto
# tok=1 name=x
# tok=13
# tok=2 num=5
# tok=5
```

### Technical Achievements
- **V1 C Compiler Compliance**: Avoids all known V1 cc/as limitations (no `!=`, no `char` arrays, no bit-packing)
- **PDP-11 Word Safety**: Uses `int` arrays for character storage with proper masking
- **Assembler Compatibility**: Generates code that V1 `as` can assemble without errors
- **Historical Accuracy**: Implements early C lexical analysis as it would have worked in 1970s Unix

## Primary Environment and Emulator

- **System**: 1st Edition UNIX, reconstructed, running on SimH's PDP-11 emulation
- **Emulator**: [SimH PDP-11 Emulator](https://github.com/simh/simh)
- **Boot/disks**: Built using `make` per unix-v1 repo; images (rf0.dsk, rk0.dsk) bootable with SimH
- **Login workflow**: 
    - Boot SimH per README (`make run` or `./simh.cfg`), log in as `root`
    - Basic commands: `ls -l`, `chdir`, `ed` (sole editor), etc.
    - Shutdown: Ctrl-E, followed by `q`
- **Toolchain**: 
    - `/bin/cc` (early C compiler—2nd Edition dialect)
    - `/bin/as` (Unix V1 assembler)
    - `/bin/ld` (linker)
    - `/usr/lib/libb.a` (B runtime)
    - No modern libc; minimize dependencies outside these tools

## Compilation Pipeline (inside SimH/UNIX v1):

1. Write `.b` (B source) file on the UNIX v1 system (use `ed`)
2. Compile: our C-based B-compiler (to be named, e.g. `bcc_v1.c`), running on the PDP-11, converts `.b` to PDP-11 assembly (in V1 Unix `as` syntax)
3. Assemble: `as program.s` → produces object file
4. Link: `ld -lb a.out` (plus any extra objects as needed)

## Constraints & Conventions

- **Target platform**: PDP-11/20, 16-bit words, word-addressed pointers, string literals terminate with octal 004 (`*e`)
- **Language/tool limitations**: 
    - K&R C style (no ANSI/prototypes)
    - No preprocessor (`#define`, `#include`, etc., not available)
    - No `struct` (oldest C can't parse them)
    - Pointer types declared as arrays: (`char s[]; int argv[];`) not `*`
- **Runtime**: Depend exclusively on system `libb.a` for builtins and runtime; only add minimal fallbacks if absolutely needed
- **Output**: Generate `.s` files in V1 assembly; do not attempt automation of assembly/link steps—use system's own `as`/`ld`
- **Testing platform**: Binaries and source must build and run inside SimH-simulated PDP-11 UNIX v1 disk images

## Implementation Steps

- Build a minimal Thompson-style B front-end (lexer and parser) in C, compatible with the early UNIX v1 cc
    - Support token forms: classic B operators (`=+`, `=-`, etc), multi-char constants, *e strings
- Emit assembly in V1 `as` syntax:
    - Function prologue/epilogue using r5 as frame, `jsr pc` for calls, preserve callee-save regs (r2–r5)
    - Place global/static data and emitted string literals in `.data`/`.text` as per V1 conventions
- Integration:
    - Optionally, add host `--pdp11-v1` output flag (if run on modern host)
    - Deliver a standalone C source (`pdp11/bcc_v1.c`) for compilation via V1 `/bin/cc` directly under SimH UNIX

## Immediate Next Tasks

- Review/define V1 assembly boilerplate templates (function headers, label conventions, string/data emission)
- Implement a simple lexer and parser skeleton, confirming it compiles with UNIX v1 `/bin/cc`
- Wire minimal codegen for expressions/statements (print/loop/test)
- Add tiny `.b` test programs under `pdp11/tests/` on the UNIX v1 filesystem, to verify codegen and system I/O using the V1 runtime and system tools

## Unix V1 Utilities

### mv.c - File Move/Copy Utility

The original Unix V1 `mv` command has issues with certain operations. We wrote a replacement in V1-compatible C.

#### Features
- Copies file contents from source to destination
- Removes source file after successful copy
- Debug output shows progress (argc, file descriptors, bytes read)

#### Usage
```
# cc mv.c
# a.out source destination
argc=3
open
in=2
creat
out=3
n=512
done
```

#### V1 C Compatibility Patterns Used

The code demonstrates key patterns for writing V1-compatible C:

1. **No global variables** - Use static variables inside accessor functions:
   ```c
   buf(op, i, v)
   {
       static b[512];
       if(op == 1) b[i] = v;
       if(op == 2) return(b);
       return(b[i]);
   }
   ```

2. **Array parameters** - Use `int argv[]` not `char *argv[]`:
   ```c
   main(argc, argv)
   int argv[];
   {
   ```

3. **Single-byte I/O for numbers** - Write digits one at a time:
   ```c
   write(1, &d[i], 1);
   ```

4. **K&R function style** - No prototypes, parameters declared after name

#### Installation on V1
```
# ed mv.c
a
[paste mv.c contents]
.
w
q
# cc mv.c
# a.out mv.o /bin/mv
```

## References

- [1st Edition UNIX Restoration repo/README](https://github.com/jserv/unix-v1)
- [SimH PDP-11 Emulator](https://github.com/simh/simh)
- 1st Edition UNIX Programmer's Manual: [cat-v.org mirror](https://man.cat-v.org/unix-1st/) & [PDF](https://www.tuhs.org/Archive/Distributions/Research/Dennis_v1/UNIX_ProgrammersManual_Nov71.pdf)
- V1 kernel implementation doc: [PreliminaryUnixImplementationDocument_Jun72.pdf](http://www.bitsavers.org/pdf/att/unix/Early_UNIX/PreliminaryUnixImplementationDocument_Jun72.pdf)
- PDP-11/20 handbook: [PDF](http://www.bitsavers.org/pdf/dec/pdp11/handbooks/PDP1120_Handbook_1972.pdf)
- Early C reference: ["C Reference Manual" (1974)](https://web.archive.org/web/20240425202413/https://www.bell-labs.com/usr/dmr/www/cman74.pdf)
- [7th Edition Unix at 40 (video)](https://www.youtube.com/watch?v=TcUdsO11P4I)

For repository layout, building, operation, and licensing, see unix-v1 repo README and LICENSE.
