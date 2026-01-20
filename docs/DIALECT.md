# Dialect: THOMPSON_B_PDP11_1972 (kbman/btut)

## Goal

Compile the language used in kbman/btut examples and what early libb.a-style programs expect.

## Core Model

- Typeless word language (PDP-11 word = 16 bits)
- Arrays are word vectors; pointers/indexing are word-based
- Strings are sequences of characters terminated by `*e` (EOT / ASCII 4)
- Escape introducer is `*` (not `\`)

## Lexical

- Comments: `/* ... */`
- Identifiers: `[A-Za-z_][A-Za-z0-9_]*`
- Numbers: decimal; leading 0 = octal
- Character constants: `'...'` with `*n *t *e *0` etc; packed into word(s) as needed
- String constants: `"..."` with `*` escapes, compiler ensures `*e` termination

## Declarations & Program Structure

- `auto` locals (and vectors `auto v[10];`)
- `extrn` for externals (usable inside functions as in btut examples)
- Function definitions: `name(a,b){ ... }`
- Top-level external initializers like:
  ```
  v[10] 'hi!', 1, 2, 3, 0777;
  s1 "hello";
  ```

## Statements

- Expression statements
- Blocks `{ ... }`
- `if (...) ... [else ...]`
- `while (...) ...`
- `goto label;` and `label: statement;`
- `switch (...) { case K: ... default: ... }`
- `break` (at least for switch; loop-break TBD)

## Expressions/Operators

### Unary
`- ! * & ++ --`

### Binary
`+ - * / % << >> & | < <= > >= == !=`

### Assignment
`= =+ =- =* =/ =% =& =| =<< =>>`

### Conditional
`?:`

### Logical Composition
Done with `&` and `|` (no `&&` / `||`, no short-circuit promise)

## Explicit Non-Goals (for now)

- No types, no structs, no floats
- No `for`, no `do/while`
- No `&&` / `||`
- Anything beyond btut/kbman goes into an "Extensions" doc behind a flag

## Token Table

| Token | ID | Description |
|-------|-----|-------------|
| EOF | 0 | End of file |
| NAME | 1 | Identifier |
| NUMBER | 2 | Numeric constant |
| CHAR | 3 | Character constant |
| STRING | 4 | String constant |
| SEMI | 5 | `;` |
| LBRACE | 6 | `{` |
| RBRACE | 7 | `}` |
| LPAREN | 8 | `(` |
| RPAREN | 9 | `)` |
| LBRACK | 10 | `[` |
| RBRACK | 11 | `]` |
| COMMA | 12 | `,` |
| ASSIGN | 13 | `=` |
| PLUS | 14 | `+` |
| MINUS | 15 | `-` |
| STAR | 16 | `*` |
| SLASH | 17 | `/` |
| MOD | 18 | `%` |
| AND | 19 | `&` |
| OR | 20 | `\|` |
| NOT | 21 | `!` |
| LT | 22 | `<` |
| GT | 23 | `>` |
| EQ | 24 | `==` |
| NE | 25 | `!=` |
| LE | 26 | `<=` |
| GE | 27 | `>=` |
| AUTO | 28 | `auto` |
| EXTRN | 29 | `extrn` |
| IF | 30 | `if` |
| ELSE | 31 | `else` |
| WHILE | 32 | `while` |
| RETURN | 33 | `return` |
| ASNOP | 34 | `=+` `=-` `=*` `=/` `=%` |
| GOTO | 35 | `goto` |
| SWITCH | 36 | `switch` |
| CASE | 37 | `case` |
| DEFAULT | 38 | `default` |
| BREAK | 39 | `break` |
| COLON | 40 | `:` |
| QUEST | 41 | `?` |
| INC | 42 | `++` |
| DEC | 43 | `--` |
