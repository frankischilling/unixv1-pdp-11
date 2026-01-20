# Unix V1 C Compiler Notes - Thompson B PDP-11 1972 Dialect

## What the Unix V1 C Compiler Has Taught Us

Here's what your `cc` (the one you're using on that PDP-11 / early Unix) has taught us so far, just from the way it parses, diagnoses, and rejects your file.

### 1) It's a very early C (pre-ANSI / "K&R style")

No prototypes. Functions are defined as:

```
foo(a, b)
int a;
char b[];
{ ... }
```

not `foo(int a, char *b)`.

Implicit int is assumed all over the place: if you don't declare a return type, it tends to default to int.

It's happy with the old "everything is int unless told otherwise" vibe, and it won't enforce types the way modern compilers do.

### 2) Its comment handling is simple and brutal

`/* ... */` works, but it is not nestable and it has no special "ignore this" intelligence.

If you put `*/` anywhere inside an existing block comment (even as an example), it ends the comment right there.

That is exactly what happened to you with:

```
* - Comments: /* ... */
```

The inner `*/` terminated the big header comment early, so the rest of your English text became "code".

### 3) It really doesn't like non-ASCII / fancy punctuation

Once your comment accidentally ended, the compiler started "reading" your prose. That's why you saw:

"Unknown character" on lines that contained punctuation it doesn't recognize (commonly: Unicode dashes, smart quotes, bullets, etc.).

So: when working with this `cc`, treat the source file as 7-bit ASCII unless you have strong proof otherwise.

### 4) Its diagnostics reveal old symbol/name rules

Your errors look like:

```
14: _Za undefined
19: _PROGRAM undefined
26: _STATEMEN undefined
```

That tells us:

It tokenizes stray words as identifiers once it thinks it's in code.

It prints "undefined" identifiers with a leading underscore in its messages (common of old toolchains / internal symbol conventions).

It also appears to truncate identifiers in diagnostics (you get partial words like _Identifi, _Characte, _STATEMEN), which is a classic symptom of small fixed-size name storage.

### 5) Multi-character character constants are "special" (and can trigger "Long character constant")

You got:

```
15: Long character constant
```

That happens when the compiler sees something like `'...'` that it decides is too long / not representable the way it expects.
Early C often allows multi-character constants in limited ways, but this compiler is picky, and it's easy to trip.

### 6) The error categories are coarse: it's a parser from the stone age

Instead of rich messages, you mostly get buckets like:

- External definition syntax (top-level parse failed)
- Statement syntax (couldn't parse a statement)
- Expression syntax (couldn't parse an expression)
- Unknown character (lexer hit a byte it can't classify)

That means when it fails early, you often get an avalanche of nonsense errors, because it's out of sync.

### 7) Practical rules for writing code this compiler won't choke on

- Never include literal `*/` inside a `/* ... */` comment. Spell it out as star-slash or `/ * * /`.
- Stick to plain ASCII characters.
- Use K&R function headers and old-style declarations.
- Avoid modern C features entirely:
  - no `//` comments
  - no `#include` dependence (unless you know your environment's preprocessor story)
  - no `void`, `signed`/`unsigned`, `long long`, `enum`, `struct` (depending on which exact `cc` you've got)
  - no modern escapes assumptions
- Expect `int` to be 16-bit in practice (PDP-11 worldview), and write with octal masks/values like you already are (`017777`, etc.).

## Target Dialect: THOMPSON_B_PDP11_1972

The `bcc.c` compiler targets **Thompson B (1972)** as documented in kbman/btut - the exact language used in early PDP-11 Unix development with libb.a runtime expectations.

## Building for Unix V1

Compile with:

```
cc bcc.c
```

This produces `a.out` which can be run directly.

## C Language Restrictions

The Unix V1 C compiler is a very early implementation with significant limitations compared to the 1974 C Reference Manual (CMAN74).

### What Works

1. **Function definitions** (K&R / pre-ANSI style):

   ```c
   funcname(a, b)
   {
       ...
   }
   ```

2. **Local variables (MUST be declared first)**
   All local declarations must appear at the **top of the function body** before any executable statements:

   ```c
   main()
   {
       int x;
       int y;

       x = 5;
   }
   ```

3. **Static locals inside functions** (persistent state across calls):

   ```c
   counter()
   {
       static n;
       n = n + 1;
       return(n);
   }
   ```

4. **Function parameters**
   Parameters default to `int` if not declared with a type list:

   ```c
   add(a, b)
   {
       return(a + b);
   }
   ```

5. **Pointer parameters / array parameters**
   Use the old "type-after-args" style:

   ```c
   putstr(s)
   char s[];
   {
       while(s[0]) {
           putch(s[0]);
           s = s + 1;
       }
   }
   ```

### What Does NOT Work (or is unreliable)

1. **External variable definitions at file scope**
   These commonly fail with "External definition syntax":

   ```c
   int x;
   extern x;
   static x;
   char buf[512];
   ```

2. **Preprocessor**
   No `#define`, `#include`, etc.

3. **Array initializers**
   Cannot initialize arrays with `{ ... }` at declaration.

4. **Declarations after statements (C99-style) — NOT allowed**
   This triggers errors like "Unknown keyword" / "Statement syntax":

   ```c
   f()
   {
       do_something();
       int x;      /* WRONG on V1 C */
       x = 1;
   }
   ```

   **Fix:** move all declarations to the top of the function.

5. **`!=` operator may not exist** (depends on the exact V1/V2 compiler build)
   Code using `!=` can produce "Statement syntax" / bogus codegen. Prefer forms that avoid it:

   * Instead of `a != 0`, use `(a == 0) == 0`

6. **Local `char` buffers can be problematic**
   Some builds are picky about `char` locals and treating them as byte-addressable buffers. When you need to write a single byte (like newline), prefer an `int` buffer and write 1 byte:

   ```c
   int nl[1];
   nl[0] = 012;
   write(2, nl, 1);
   ```

   (On PDP-11, `write()` will take the low byte for the 1-byte count.)

7. **Avoid bit-packed "byte-in-word" tricks**
   Don't use bit operations (`<<`, `>>`, `&`, `|`) to pack multiple bytes into single words (like `w = i >> 1` with manual shift loops) inside helper routines like `tokname()`. The V1/V2 cc+as toolchain can fail in the assembler stage with `e ####` errors, and the object file won't be produced.

   **Safe approach:** Store characters as one-per-word (`int name[]`), and print/compare using `putnm()` and `nmeq()` instead of relying on C `char*` strings.

   **Don't:** Pass word arrays directly to `read`/`write` for bulk byte I/O. Use 1-byte syscalls or a truly byte-addressable buffer model.

8. **Never treat `int b[N]` as a byte buffer for `read`/`write`**
   Don't pass word arrays directly to `read`/`write` syscalls expecting byte-level access. On PDP-11, words are 2 bytes, so `read(fd, buf, 512)` into an `int buf[512]` will fill 1024 bytes, but indexing as `buf[i]` only accesses every other byte.

   **Safe approach:** Use single-byte syscalls for reliable I/O:
   ```c
   read(0, &c, 1)   /* into an int c */
   write(1, &c, 1)  /* from an int c */
   ```
   This avoids fragile byte-packing code that can trigger assembler failures (`e ####`) or produce silent half-output.

### Operators

* Use `|` for both bitwise OR and logical OR (no `||`)
* Use `&` for both bitwise AND and logical AND (no `&&`)
* Assignment operators: `=+`, `=-`, `=*`, `=/`, `=%` (B-style, not `+=`)

### Character Constants / Escapes

* Prefer **octal** for control characters:

  * newline = `012`, tab = `011`, space = `040`
* **Do not rely on C escape handling** in string literals (some toolchains behave oddly).
  Prefer explicit `putch(012)` rather than `"\n"` if you see literal `n` output.

Example:

```c
putnl()
{
    putch(012);
}
```

### Workaround for Global State

Since external variables don't work, store state as static locals behind "accessor" functions:

```c
getbuf()
{
    static buf[512];
    return(buf);
}

getbufp(op, v)
{
    static p;
    if(op) p = v;
    return(p);
}
```

Or consolidate state into a single function that returns pointers.

### Symbol Table Implementation

The compiler includes a complete symbol table system for tracking identifiers:

**Symbol Classes:**
- `1` = function
- `2` = global variable
- `3` = auto (local) variable
- `4` = parameter
- `5` = label
- `6` = external reference

**Symbol Properties:**
- **Name**: Stored as `int[]` array (one char per word)
- **Class**: Type of symbol (function, variable, label, etc.)
- **Offset**: Stack offset (for locals) or global label number
- **Dimension**: Array/vector size (0 for scalars)
- **External**: Flag for external references needed
- **Scope Level**: Nesting level (0=global, 1=function, etc.)

**Core Functions:**
```c
lookup(name)     /* Find symbol by name, returns index or 0 */
install(name, class)  /* Add new symbol, returns index */
enter_scope()    /* Increase scope level for function entry */
leave_scope()    /* Decrease scope level, remove local symbols */
```

**Usage:**
```c
/* In parser when encountering identifier */
sym = lookup(tokname(2, 0, 0));
if(sym == 0) {
    /* New symbol */
    sym = install(tokname(2, 0, 0), 3);  /* auto variable */
}

/* Function entry */
enter_scope();

/* Function exit */
leave_scope();
```

### V1-Safe Compiler Runtime Contract

These constraints are baked into the B compiler codebase and must never regress:

**1. Single-byte I/O only**
For anything interactive or byte-oriented, use:
```c
read(0, &c, 1)   /* read one byte into int c */
write(1, &c, 1)  /* write one byte from int c */
```
Never pass `int name[]` directly to `read`/`write` for bulk I/O.

**2. Identifier storage as int name[] (one char per word)**
Store identifiers and strings as `int name[]`, NOT as `char*` strings.
This ensures comparisons and printing work reliably in V1 C.

**3. Canonical string operations: putnm() + nmeq()**
Use these as the only string operations inside the compiler:
```c
putnm(s)    /* print int[] name to stdout */
nmeq(a, b)  /* compare int[] a to char[] b literal */
```
Do NOT use C string operations like `strcmp()`, `strcpy()`, etc.

**Reference implementations:**
```c
putnm(s)
int s[];
{
    while(s[0]) {
        putch(s[0]);
        s = s + 1;
    }
}

nmeq(a, b)
int a[];
char b[];
{
    while(((b[0] == 0) == 0) & (a[0] == (b[0] & 0377))) {
        a = a + 1;
        b = b + 1;
    }
    return(a[0] == (b[0] & 0377));
}
```

### Syscalls Available

* `read(fd, buf, n)`
* `write(fd, buf, n)`
* `exit(status)`

### File Size Limitations

**Critical Unix V1 Constraint:** Individual source files cannot exceed ~500 lines of code.

#### Why This Matters
- Unix V1's `cc` compiler and assembler have severe memory limitations
- Large files trigger "move failed: filename.o" errors during compilation
- The assembler cannot handle object files larger than available temporary space

#### Practical Limits Observed
- **Safe maximum**: ~400-450 lines per file
- **Danger zone**: 500+ lines will likely fail
- **Splitting required**: Files over 500 lines must be split into multiple smaller files

#### Splitting Strategy
When a file becomes too large:
1. Split logically related functions into separate files (e.g., `bcc4.c` → `bcc4a.c` + `bcc4b.c`)
2. Compile all split files together: `cc file1.c file2.c file3.c ...`
3. Maintain function dependencies across split files

#### Impact on Development
- **Modular design**: Forces clean separation of concerns
- **Frequent compilation testing**: Check file sizes regularly
- **Function grouping**: Keep related functions together when possible

**Note:** This constraint shaped early Unix development practices and influenced the modular design of the original Unix tools.

### Style Guidelines

1. Opening brace on its own line
2. One variable declaration per line
3. All locals declared at top of function body
4. Avoid modern operators / constructs (`!=`, `&&`, `||`, etc.)
5. Keep functions small (stack is tight, compiler is fragile)
