````markdown
# INTRODUCTION

This manual gives complete descriptions of all the publicly available features of UNIX. It provides neither a general overview (see “The UNIX Time-sharing System” for that) nor details the implementation of the system (which remain to be disclosed).

Within the area it surveys, this manual attempts to be as complete and timely as possible. A conscious decision was made to describe each program in exactly the state it was in at the time its manual section was prepared. In particular, the desire to describe something as it should be, not as it is, was resisted.

Inevitably, this means that many sections will soon be out of date. (The rate of change of the system is so great that a dismayingly large number of early sections had to be modified while the rest were being written. The unbounded effort required to stay up-to-date is best indicated by the fact that several of the programs described were written specifically to aid in preparation of this manual!)

This manual is divided into seven sections:

1. Commands  
2. System calls  
3. Subroutines  
4. Special files  
5. File formats  
6. User-maintained programs  
7. Miscellaneous  

Commands are programs intended to be invoked directly by the user, in contradistinction to subroutines, which are intended to be called by the user’s programs. Commands generally reside in directory `/bin` (for binary programs). This directory is searched automatically by the command line interpreter. Some programs classified as commands are located elsewhere; this fact is indicated in the appropriate sections.

System calls are entries into the UNIX supervisor. In assembly language, they are coded with the use of the opcode `sys`, a synonym for the trap instruction.

The special files section discusses the characteristics of each system file which actually refers to an I/O device.

The file formats section documents the structure of particular kinds of files; for example, the form of the output of the loader and assembler is given. Excluded are files used by only one command, for example the assembler’s intermediate files.

User-maintained programs are not considered part of the UNIX system, and the principal reason for listing them is to indicate their existence without necessarily giving a complete description. The author should be consulted for information.

The miscellaneous section gathers odds and ends.

Each section consists of a number of independent entries of a page or so each. The name of the entry is in the upper right corner of its pages, its preparation date in the upper left. Entries within each section are alphabetized. It was thought better to avoid page numbers, since it is hoped that the manual will be updated frequently.

All entries have a common format.

- **The name section** repeats the entry name and gives a very short description of its purpose.
- **The synopsis** summarizes the use of the program being described. A few conventions are used, particularly in the Commands section:
  - Underlined words are considered literals, and are typed just as they appear.
  - Square brackets (`[]`) around an argument indicate that the argument is optional. When an argument is given as `name` it always refers to a file name.
  - Ellipses `...` are used to show that the previous argument-prototype may be repeated.
  - A final convention is used by the commands themselves. An argument beginning with a minus sign `-` is often taken to mean some sort of flag argument even if it appears in a position where a file name could appear. Therefore, it is unwise to have files whose names begin with `-`.
- **The description section** discusses in detail the subject at hand.
- **The files section** gives the names of files which are built into the program.
- **A see also section** gives pointers to related information.
- **A diagnostics section** discusses the diagnostics that may be produced. This section tends to be as terse as the diagnostics themselves.
- **The bugs section** gives known bugs and sometimes deficiencies. Occasionally also the suggested fix is described.
- **The owner section** gives the name of the person or persons to be consulted in case of difficulty. The rule has been that the last one to modify something owns it, so the owner is not necessarily the author. The owner’s initials stand for:

  - `ken` — K. Thompson  
  - `amr` — D. M. Ritchie  
  - `jfo` — J. F. Ossanna  
  - `rhm` — R. Morris  

These three-character names also happen to be UNIX user ID’s, so messages may be transmitted by the `mail` command or, if the addressee is logged in, by `write`.

At the beginning of this document is a table of contents, organized by section and alphabetically within each section. There is also a permuted index derived from the table of contents. Within each index entry, the title of the writeup to which it refers is followed by the appropriate section number in parentheses. This fact is important because there is considerable name duplication among the sections, arising principally from commands which exist only to exercise a particular system call.

This manual was prepared using the UNIX text editor `ed` and the formatting program `roff`.

---

# TABLE OF CONTENTS

## I. COMMANDS

```text
ar      archive (combine) files
as      assembler
b       compile B program
bas     BASIC dialect
bcd     convert ASCII to BCD
boot    reboot system
cat     concatenate (or print) files
chdir   change working directory
check   check consistency of file system
chmod   change access mode of files
chown   change owner of files
cmp     compare file contents
cp      copy file
date    get date and time of day
db      symbolic debugger
dbppt   write binary paper tape
dc      desk calculator
df      find free disk space
dsw     delete files interactively
dtf     format DECtape
du      find disk usage
ed      text editor
find    find file with given name
for     compile Fortran program
form    generate form letter
hup     hang up typewriter
lbppt   read binary paper tape
ld      link editor (loader)
ln      link to file
ls      list contents of directory
mail    send mail to another user
mesg    permit or deny messages
mkdir   create directory
mkfs    initialize file system
mount   mount detachable file system
mv      move or rename file
nm      print namelist
od      octal dump of file
pr      print file with headings
rew     rewind DECtape
rkd     dump disk to tape
rkf     format RK disk
rkl     load disk from tape
rm      remove (delete) file
rmdir   remove (delete) directory
roff    run off (format) text
sdate   adjust date and time
sh      command interpreter
stat    get file status
strip   remove symbols, relocation bits
su      become super-user
sum     sum file
tap     manipulate DECtape
tm      get time information
tty     find name of terminal
type    print file on IBM 2741
umount  dismount removable file system
un      find undefined symbols
wc      get (English) word count
who     who is on the system
write   write to another user
````

## II. SYSTEM CALLS

```text
break   set program break
cemt    catch EMT traps
chdir   change working directory
chmod   change mode of file
chown   change owner of file
close   close open file
creat   create file
exec    execute program file
exit    terminate execution
fork    create new process
fstat   status of open file
getuid  get user ID
gtty    get typewriter mode
ilgins  catch illegal instruction trap
intr    catch or inhibit interrupts
link    link to file
mkdir   create directory
mount   mount file system
open    open file
quit    catch or inhibit quits
read    read file
rele    release processor
seek    move read or write pointer
setuid  set user ID
smdate  set date modified of file
stat    get file status
stime   set system time
stty    set mode of typewriter
tell    find read or write pointer
time    get time of year
umount  dismount file system
unlink  remove (delete) file
wait    wait for process
write   write file
```

## III. SUBROUTINES

```text
atof    convert ASCII to floating
atoi    convert ASCII to integer
ctime   convert time to ASCII
exp     exponential function
fptrap  floating-point simulator
ftoa    convert floating to ASCII
get     get character
itoa    convert integer to ASCII
log     logarithm base e
mesg    print string on typewriter
ptime   print time
putc    write character or word
sin     sine, cosine
switch  transfer depending on value
```

## IV. SPECIAL FILES

```text
mem                 core memory as file
ppt                 punched paper tape
rf0                 RF disk file
rk0                 RK disk file
tapo,...,tap7        DECtape file
tty                 console typewriter
ttyo,...,tty5        remote typewriter
```

## V. FILE FORMATS

```text
a.out       assembler and loader output
archive     archive file
bppt        binary paper tape format
core        core image file
directory   directory format
file system file system format
passwd      password file
uids        map names to user ID's
utmp        logged-in user information
```

## VI. USER MAINTAINED PROGRAMS

```text
basic   DEC supplied BASIC
bj      the game of black jack
cal     print calendar
chess   the game of chess
das     disassembler
dli     load DEC binary paper tapes
dpt     read DEC ASCII paper tapes
moo     the game of MOO
sort    sort a file
ttt     the game of tic-tac-toe
```

## VII. MISCELLANEOUS

```text
as2             assembler's pass 2
ascii           map of ASCII
ba              B assembler
bc              B compiler
bilib           B interpreter library
bproc           boot procedure
brt1, brt2       B start and finish
f1,f2,f3,f4      Fortran compiler passes
glob            argument expander
init            initializer process
kbd             map of TTY 37 keyboard
liba            standard assembly-language library
libb            standard B library
libf            standard Fortran library
login, logout   logging on and logging off the system
msh             mini Shell
suftab          roff's suffix table
tabs            set tab stops on typewriter
```

---

# INDEX

> NOTE: The index in the source you provided is extremely long and irregularly wrapped; it is preserved below as a preformatted block to keep it faithful.

```text
chmod(I): change access mode of files
sdate(I): adjust date and time
mail(I): send mail to another user
write(I): write to another user
a.out(V): assembler and loader output
ar(I): archive (combine) files
archive(V): archive file
glob(VII): argument expander
bcd(I): convert ASCII to BCD
atof(III): convert ASCII to floating
atoi(III): convert ASCII to integer
ascii(VII): map of ASCII
ctime(III): convert time to ASCII
ftoa(III): convert floating to ASCII
itoa(III): convert integer to ASCII
as(I): assembler
ba(VII): B assembler
as2(VII): assembler's pass 2
liba(VII): standard assembly-language library
bc(VII): B compiler
bilib(VII): B interpreter library
libb(VII): standard B library
brt1, brt2(VII): B start and finish
bas(I): BASIC dialect
basic(VI): DEC supplied BASIC
bppt(V): binary paper tape format
dbppt(I): write binary paper tape
lbppt(I): read binary paper tape
bj(VI): the game of black jack
bproc(VII): boot procedure
break(II): set program break
dc(I): desk calculator
cal(VI): print calendar
cemt(II): catch EMT traps
ilgins(II): catch illegal instruction trap
intr(II): catch or inhibit interrupts
quit(II): catch or inhibit quits
cat(I): concatenate (or print) files
chmod(II): change mode of file
chown(I): change owner of files
chown(II): change owner of file
chdir(I): change working directory
chdir(II): change working directory
putc(III): write character or word
get(III): get character
check(I): check consistency of file system
chess(VI): the game of chess
close(II): close open file
cmp(I): compare file contents
for(I): compile Fortran program
cp(I): copy file
core(V): core image file
mem(IV): core memory as file
wc(I): get (English) word count
mkdir(I): create directory
mkdir(II): create directory
creat(II): create file
fork(II): create new process
date(I): get date and time of day
smdate(II): set date modified of file
db(I): symbolic debugger
das(VI): disassembler
dpt(VI): read DEC ASCII paper tapes
dli(VI): load DEC binary paper tapes
dsw(I): delete files interactively
dtf(I): format DECtape
du(I): find disk usage
rkd(I): dump disk to tape
od(I): octal dump of file
ld(I): link editor (loader)
ed(I): text editor
exec(II): execute program file
exit(II): terminate execution
exp(III): exponential function
mkfs(I): initialize file system
mount(I): mount detachable file system
mount(II): mount file system
umount(I): dismount removable file system
umount(II): dismount file system
find(I): find file with given name
pr(I): print file with headings
ln(I): link to file
ls(I): list contents of directory
mail(I): send mail to another user
tap(I): manipulate DECtape
uids(V): map names to user ID's
kbd(VII): map of TTY 37 keyboard
mesg(I): permit or deny messages
mesg(III): print string on typewriter
msh(VII): mini Shell
mkfs(I): initialize file system
stty(II): set mode of typewriter
gtty(II): get typewriter mode
moo(VI): the game of MOO
mv(I): move or rename file
seek(II): move read or write pointer
nm(I): print namelist
open(II): open file
passwd(V): password file
rele(II): release processor
strip(I): remove symbols, relocation bits
rew(I): rewind DECtape
rf0(IV): RF disk file
rk0(IV): RK disk file
rkf(I): format RK disk
rkl(I): load disk from tape
rm(I): remove (delete) file
rmdir(I): remove (delete) directory
roff(I): run off (format) text
suftab(VII): roff's suffix table
stime(II): set system time
tabs(VII): set tab stops on typewriter
setuid(II): set user ID
stat(I): get file status
stat(II): get file status
fstat(II): status of open file
sin(III): sine, cosine
sort(VI): sort a file
sum(I): sum file
su(I): become super-user
time(II): get time of year
tm(I): get time information
tty(I): find name of terminal
type(I): print file on IBM 2741
un(I): find undefined symbols
unlink(II): remove (delete) file
utmp(V): logged-in user information
wait(II): wait for process
who(I): who is on the system
write(I): write to another user
```

---

# SECTION I — COMMANDS

---

## 11/3/71 — AR (I)

### NAME

`ar` — archive

### SYNOPSIS

`ar key afile name,`

### DESCRIPTION

`ar` maintains groups of files combined into a single archive file. Its main use is to create and update library files as used by the loader. It can be used, though, for any similar purpose.

`key` is one character from the set `drtux`, optionally concatenated with `v`. `afile` is the archive file. The names are constituent files in the archive file. The meanings of the key characters are:

* `d` means delete the named files from the archive file.
* `r` means replace the named files in the archive file. If the archive file does not exist, `r` will create it. If the named files are not in the archive file, they are appended.
* `t` prints a table of contents of the archive file. If no names are given, all files in the archive are tabled. If names are given, only those files are tabled.
* `u` is similar to `r` except that only those files that have been modified are replaced. If no names are given, all files in the archive that have been modified will be replaced by the modified version.
* `x` will extract the named files. If no names are given, all files in the archive are extracted. In neither case does `x` alter the archive file.
* `v` means verbose. Under the verbose option, `ar` gives a file-by-file description of the making of a new archive file from the old archive and the constituent files. The following abbreviations are used:

  * `c` copy
  * `a` append
  * `d` delete
  * `r` replace
  * `x` extract

### FILES

`/tmp/vtma, vtmb ...` temporary

### SEE ALSO

`ld`

### DIAGNOSTICS

Bad usage, `afile -- not in archive format`
`cannot open temp file`, `name -- cannot open`

### BUGS

`name -- phase error`, `name -- cannot create`
`no archive file cannot create archive file`, `name -- not found`
Option `l` (table with more information) should be implemented.
There should be a way to specify the placement a new file in an archive. Currently, it is placed at the end.

### OWNER

`ken, dmr`

---

## 11/3/71 — AS (I)

### NAME

`as` — assembler

### SYNOPSIS

`as name`

### DESCRIPTION

`as` assembles the concatenation of `name, ...`. `as` is based on the DEC-provided assembler PAL-11R [references], although it was coded locally. Therefore, only the differences will be recorded.

Character changes are: (as given in source)

In `as`, the character `%;` is a logical new line; several operations may appear on one line if separated by `;`.

Several new expression operators have been provided:

* right shift (logical)
* `*` multiplication
* left shift
* `%` division
* remainder (no longer means “register”)
* one’s complement
* parentheses for grouping
* result has value of left, type of right

For example location `0` (relocatable) can be written `0 .`; another way to denote register 2 is `2 r0`.

All of the preceding operators are binary; if a left operand is missing, it is taken to be `0`. The `!` operator adds its left operand to the one’s complement of its right operand.

There is a conditional assembly operation code different from that of PAL-11R (whose conditionals are not provided):

```text
.if expression
.endif
```

If the expression evaluates to non-zero, the section of code between the `.if` and the `.endif` is assembled; otherwise it is ignored. `.if`s may be nested.

Temporary labels like those introduced by Knuth [reference] may be employed. A temporary label is defined as:

```text
n:
```

where `n` is a digit `0 ... 9`. Symbols of the form `nf` refer to the first label `n:` following the use of the symbol; those of the form `nb` refer to the last `n:`. The same `n` may be used many times.

The PAL-11R opcodes `.eot` and `.end` are redundant and are omitted.

The symbols `r0...r5`, `sp`, `pc`, `ac`, `ma`, `div`, `mul`, `lsh`, `ash`, `nor`, `CSW` are predefined with appropriate values. The symbol `csw` refers to the console switches.

`is` is the relocation constant and is added to each relocatable symbol; normally it is `40000(8)`; it may be changed to assemble a section of code at a location different from that in which it will be executed.

It is illegal to assign a value to `is` less than its current value.

The new opcode `sys` is used to specify system calls. Names for system calls are predefined. See the section on system calls for their names.

Strings of characters may be assembled in a way more convenient than PAL-11’s `ascii` operation (which is, therefore, omitted). Strings are included between the string quotes `<` and `>`:

```text
<here is a string>
```

Escape sequences exist to enter non-graphic and other difficult characters. These sequences are also effective in single and double character constants introduced by single (`'`) and double (`"`) quotes respectively.

The binary output of the assembler is placed on the file `a.out` in the current directory. `a.out` also contains the symbol table from the assembly and relocation bits. The output of the assembler is executable immediately if the assembly was error-free and if there were no unresolved external references. The link editor `ld` may be used to combine several assembly outputs and resolve global symbols.

The multiple location counter feature of PAL11R is not supported.

The assembler does not produce a listing of the source program. This is not a serious drawback; the debugger `db` discussed below is sufficiently powerful to render a printed octal translation of the source unnecessary.

### FILES

* `/etc/as2` — pass 2 of the assembler
* `a.tmp1` — temporary
* `a.tmp2` — temporary
* `a.tmp3` — temporary
* `a.out` — object

### SEE ALSO

`ld, nm, sh, un, db, a.out` (format of output)

### DIAGNOSTICS

When an input file cannot be read, its name followed by a question mark is typed and assembly ceases.

When syntactic or semantic errors occur, a single-character diagnostic is typed out together with the line number and the file name in which it occurred. Errors in pass 1 cause cancellation of pass 2. The possible errors are:

```text
A parentheses error
B Branch instruction has too remote an address
E error in Expression
F error in local
G (F type symbol or "b")
M Multiply defined symbol as label
O Odd-- word quantity assembled at odd address
P Phase error-- different in pass 2 from pass 1 value
R Relocation error
U Undefined symbol
X syntax error
```

### BUGS

Symbol table overflow is not checked.

### OWNER

`dmr`

---

## 11/3/71 — B (I)

### NAME

`B` — language

### SYNOPSIS

`sh rc /usr/b/rc name`

### DESCRIPTION

B is a language suitable for system programming. It is described in a separate publication, B reference manual.

The canned shell sequence in `/usr/b/rc` will compile the program `name.b` into the executable file `a.out`. It involves running the B compiler, the B assembler, the assembler and the link editor.

The process leaves the files `name.i` and `name.s` in the current directory.

### FILES

`name.b, name.i, name.s`

### SEE ALSO

`/etc/bc, /etc/ba, /etc/brt1, /etc/brt2, /etc/bilib, /etc/libb.a,` B reference manual.

### DIAGNOSTICS

See B reference manual.

### BUGS

There should be a `B` command.

### OWNER

`ken, dmr`

---

## 11/3/71 — BAS (I)

### NAME

`bas` — basic

### SYNOPSIS

`bas [file]`

### DESCRIPTION

`bas` is a dialect of basic. If a file argument is provided, the file is used for input before the console is read.

`bas` accepts lines of the form:

* `statement`
* `integer statement`

Integer numbered statements (known as internal statements) are stored for later execution. They are stored in sorted ascending order. Nonnumbered statements are immediately executed.

The result of an immediate expression statement (that does not have `=` as its highest operator) is printed.

Statements have the following syntax: (`expr` is short for expression)

* `expr`
  The expression is executed for its side effects (assignment or function call) or for printing as described above.
* `done`
  Return to system level.
* `draw expr expr expr`
  Draw on a 611-type storage scope through a TSP-1 plotter interface. Coordinates are `0..1` in both x and y directions. Evaluate expressions as X, Y, Z. Draw line from previous X,Y to new X,Y; if Z non-zero, line visible, else invisible.
* `for name = expr expr statement`
  or
  `for name = expr expr` … `next`
  Repetitively executes a statement (first form) or group (second form) under control of a named variable. Variable starts at first expr and increments by one each loop, not exceeding the second expr.
* `goto expr`
  Expression evaluated, truncated to integer, execution goes to corresponding numbered statement. If executed from immediate mode, internal statements compiled first.
* `if expr statement`
  Statement executed if expression evaluates to non-zero.
* `list [expr [expr]]`
  Print stored internal statements. No args: all. One arg: that statement. Two args: inclusive range.
* `print expr`
  Evaluate and print expression.
* `return expr`
  Evaluate expr; result passed back as function call value.
* `run`
  Internal statements compiled. Symbol table re-initialized. RNG reset. Control passed to lowest numbered internal statement.

Expressions syntax:

* `name` — variable name: letter `a`-`z` followed by letters/digits; first four chars significant.
* `number` — digits, at most one `.`, optional scale factor `e digits` or `e -digits`.
* `( expr )` — parentheses alter order.
* `expr op expr` — binary operators.
* `expr (expr, expr, ...)` — function call: expression evaluates to line number entry of function in stored statements; if negative, builtin function called.
* `name [ expr expr ... ]` — arrays not yet implemented.

Operators:

* `=` assignment; left operand must be name or array element; binds right-to-left. All others bind left-to-right.
* `&` logical and
* `|` logical or
* relational: `< <= > >= == <>` return 1 if relation holds else 0. Same-level relations extend: `a>b>c` same as `a>b & b>c`.
* `+ -` add/subtract
* `* /` multiply/divide
* `^` exponentiation

Builtin functions:

* `arg(i)` — ith actual parameter at current call level.
* `exp(x)` — exponential.
* `log(x)` — natural log.
* `sin(x)` — sine (radians).
* `cos(x)` — cosine.
* `atn(x)` — arctangent (not implemented).
* `rnd()` — random between 0 and 1.
* `expr()` — program input; reads line, evaluates as expression, returns value.
* `int(x)` — truncate to integer.

### FILES

`/tmp/btma, btmb` temporary

### DIAGNOSTICS

Syntax errors cause incorrect line to be typed with an underscore where the parse failed. All other diagnostics are self explanatory.

### BUGS

Arrays are not yet implemented. In general, program sizes, recursion, etc. are not checked and cause trouble.

### OWNER

`ken`

---

## 11/3/71 — BCD (I)

### NAME

`bcd` — binary coded decimal conversion

### SYNOPSIS

`bcd [string]`

### DESCRIPTION

`bcd` will convert a string into GECOS card code. If no argument string is provided, `bcd` will read a line and convert it.

### SEE ALSO

—

### DIAGNOSTICS

—

### BUGS

—

### OWNER

`dmr`

---

## 11/3/71 — BOOT (I)

### NAME

`boot` — reboot system

### SYNOPSIS

`/etc/boot`

### DESCRIPTION

`boot` logically a command, and is kept in `/etc` only to lessen the probability of its being invoked by accident or from curiosity. It reboots the system by jumping to the read-only memory, which contains a disk boot program.

### FILES

—

### SEE ALSO

boot procedure

### DIAGNOSTICS

—

### BUGS

Should obviously not be executable by the general user. Also, it should reboot in a more direct manner. The mechanism invoked by jumping to the ROM loader is sensitive to the contents of the console switches, which makes the whole procedure even more dangerous.

Rather than jumping to the ROM, `boot` should simulate the ROM action with `173700` in the switches. In this manner, it may be used when the switches are not set, and even in installation without a ROM.

### OWNER

`ken`

---

## 11/3/71 — CAT (I)

### NAME

`cat` — concatenate and print

### SYNOPSIS

`cat file,...`

### DESCRIPTION

`cat` reads each file in sequence and writes it on the standard output stream. Thus:

```text
cat file
```

is about the easiest way to print a file. Also:

```text
cat file1 file2 >file3
```

is about the easiest way to concatenate files.

If no input file is given, `cat` reads from the standard input file.

### FILES

—

### SEE ALSO

`pr, cp`

### DIAGNOSTICS

none; if a file cannot be found it is ignored.

### BUGS

—

### OWNER

`ken, dmr`

---

## 11/3/71 — CHDIR (I)

### NAME

`chdir` — change working directory

### SYNOPSIS

`chdir directory`

### DESCRIPTION

`directory` becomes the new working directory. Because a new process is created to execute each command, `chdir` would be ineffective if it were written as a normal command. It is therefore recognized and executed by the Shell.

### FILES

—

### SEE ALSO

`sh`

### DIAGNOSTICS

`?`

### BUGS

—

### OWNER

`ken, dmr`

---

## 11/3/71 — CHECK (I)

### NAME

`check` — file system consistency check

### SYNOPSIS

`check [ filesystem [ blockno, ... ]]`

### DESCRIPTION

`check` will examine a file system, build a bit map of used blocks, and compare this bit map against the bit map maintained on the file system. If the file system is not specified, a check of both `/dev/rf0` and `/dev/rk0` is performed. Output includes the number of files on the file system, the number of these that are ‘large’, the number of used blocks, and the number of free blocks.

### FILES

`/dev/rf0, /dev/rk0`

### SEE ALSO

`find`

### DIAGNOSTICS

Diagnostics are produced for blocks missing, duplicated, and bad block addresses. Diagnostics are also produced for block numbers passed as parameters. In each case, the block number, i-number, and block class (`1 = inode, x = indirect, f = free`) is printed.

### BUGS

The checking process is two-pass in nature. If checking is done on an active file system, extraneous diagnostics may occur. The swap space on the RF file system is not accounted for and will therefore show up as ‘missing’.

### OWNER

`ken, dmr`

---

## 11/3/71 — CHMOD (I)

### NAME

`chmod` — change mode

### SYNOPSIS

`chmod octal file, ...`

### DESCRIPTION

The octal mode replaces the mode of each of the files. The mode is constructed from the OR of the following modes:

* `01` write for non-owner
* `02` read for non-owner
* `04` write for owner
* `10` read for owner
* `20` executable
* `40` set-UID

Only the owner of a file may change its mode.

### FILES

—

### SEE ALSO

`stat, ls`

### DIAGNOSTICS

`?`

### BUGS

—

### OWNER

`ken, amr`

---

## 11/3/71 — CHOWN (I)

### NAME

`chown` — change owner

### SYNOPSIS

`chown owner file, ...`

### DESCRIPTION

`owner` becomes the new owner of the files. The owner may be either a decimal UID or a name found in `/etc/uids`.

Only the owner of a file is allowed to change the owner. It is illegal to change the owner of a file with the set-user-ID mode.

### FILES

`/etc/uids`

### SEE ALSO

`stat`

### DIAGNOSTICS

`?`

### BUGS

—

### OWNER

`ken, dmr`

---

## 11/3/71 — CMP (I)

### NAME

`cmp` — compare two files

### SYNOPSIS

`cmp file1 file2`

### DESCRIPTION

The two files are compared for identical contents. Discrepancies are noted by giving the offset and the differing words.

### FILES

—

### SEE ALSO

—

### DIAGNOSTICS

Messages are given for inability to open either argument, premature EOF on either argument, and incorrect usage.

### BUGS

If the two files differ in length by one byte, the extra byte does not enter into the comparison.

### OWNER

`dmr`

---

## 11/3/71 — CP (I)

### NAME

`cp` — copy

### SYNOPSIS

`cp file1 file2 [file3 file4 ...]`

### DESCRIPTION

Files are taken in pairs; the first is opened for reading, the second created mode 17. Then the first is copied into the second.

### FILES

—

### SEE ALSO

`cat, pr`

### DIAGNOSTICS

Error returns are checked at every system call, and appropriate diagnostics are produced.

### BUGS

The second file should be created in the mode of the first. A directory convention as used in `mv` should be adopted to `cp`.

### OWNER

`ken, dmr`

---

## 11/3/71 — DATE (I)

### NAME

`date` — print the date

### SYNOPSIS

`date`

### DESCRIPTION

The current date is printed to the second.

### FILES

—

### SEE ALSO

`sdate`

### DIAGNOSTICS

—

### BUGS

—

### OWNER

`amr`

---

## 11/3/71 — DB (I)

### NAME

`db` — debug

### SYNOPSIS

`db [core [namelist]]`

### DESCRIPTION

Unlike many debugging packages (including DEC’s ODT, on which `db` is loosely based) `db` is not loaded as part of the core image which it is used to examine; instead it examines files. Typically, the file will be either a core image produced after a fault or the binary output of the assembler.

`core` is the file being debugged; if omitted, `core` is assumed. `namelist` is a file containing a symbol table. If it is omitted, `a.out` is the default. If no appropriate name list file can be found, `db` can still be used but some of its symbolic facilities become unavailable.

The format for most `db` requests is an address followed by a one character command.

Addresses are expressions built up as follows:

1. A name has the value assigned to it when the input file was assembled. It may be relocatable or not depending on the use of the name during the assembly.
2. An octal number is an absolute quantity with the appropriate value.
3. An octal number immediately followed by `r` is a relocatable quantity with the appropriate value.
4. The symbol `.` indicates the current pointer of `db`. The current pointer is set by many `db` requests.
5. Expressions separated by `+` or (blank) are expressions with value equal to the sum of the components. At most one of the components may be relocatable.
6. Expressions separated by `-` form an expression with value equal to the difference of the components. If the right component is relocatable, the left component must be relocatable.
7. Expressions are evaluated left to right.

Names for registers are built in:

* `r0 ... r5`
* `sp`
* `pc`
* `ac`
* `mb`

These may be examined. Their values are deduced from the contents of the stack in a core image file. They are meaningless in a file that is not a core image.

If no address is given for a command, the current address (also specified by `.`) is assumed. In general, `.` points to the last word or byte printed by `db`.

There are `db` commands for examining locations interpreted as octal numbers, machine instructions, ASCII characters, and addresses. For numbers and characters, either bytes or words may be examined. The following commands are used to examine the specified file:

* `/` The addressed word is printed in octal.
* `\` The addressed byte is printed in octal.
* `?` The addressed word is printed as two ASCII characters.
* (single-quote style in source) The addressed byte is printed as an ASCII character.
* (B-address mode) The addressed word is multiplied by 2, then printed in octal (used with B programs, whose addresses are word addresses).
* (instruction mode) The addressed word is interpreted as a machine instruction and a symbolic form of the instruction, including symbolic addresses, is printed.
* `&` The addressed word is interpreted as a symbolic address and is printed as the name of the symbol whose value is closest to the addressed word, possibly followed by a signed offset.
* `<nl>` A blank line advances the current location counter and prints the resulting location in the mode last specified.
* (decrement) This character decrements and prints the resulting location in the mode last selected; it is a converse to `<nl>`.

It is illegal for the word-oriented commands to have odd addresses. The incrementing and decrementing of `.` done by the `<nl>` and decrement requests is by one or two depending on whether the last command was word or byte oriented.

The address portion of any of the above commands may be followed by a comma and then by an expression. In this case that number of sequential words or bytes specified by the expression is printed. `.` is advanced so that it points at the last thing printed.

There are two commands to interpret the value of expressions:

* `=`
  When preceded by an expression, the value of the expression is typed in octal. When not preceded by an expression, the value of `.` is indicated. This command does not change the value of `.`.
* `:`
  Attempt to print the given expression as a symbolic address. If relocatable, nearest symbol printed with signed offset. If absolute, exact-match symbol printed if found else octal value printed.

Patch command:

* `Π`
  Must be preceded by an expression. The value of the expression is stored at the location addressed by current `.`. The opcodes do not appear in the symbol table, so the user must assemble them by hand.

After a fault producing a core image:

* `$`
  Prints the contents of the general registers and several other registers both in octal and symbolic format. Values are as at time of fault.

Exit from `db` is by generating an end-of-file on the typewriter (EOT character).

### FILES

—

### SEE ALSO

`as`; `core` for format of core image.

### DIAGNOSTICS

“File not found” if the first argument cannot be read; otherwise “?”.

### BUGS

Really, `db` should know about relocation bits, floating point operations, and PDP11/45 instructions.

### OWNER

`dmr`

---

## 11/3/71 — DBPPT (I)

### NAME

`dbppt` — dump binary paper tape

### SYNOPSIS

`dbppt name [output]`

### DESCRIPTION

`dbppt` produces binary paper tape in UNIX standard format, which includes checksums and a zero-suppression feature. File `name` is dumped; if the output argument is not given, output goes to `/dev/ppt`.

### FILES

`/dev/ppt`

### SEE ALSO

`lbppt` to reload the tapes; `bppt` for binary paper tape format.

### DIAGNOSTICS

`?`

### BUGS

—

### OWNER

`ken`

---

## 11/3/71 — DC (I)

### NAME

`dc` — desk calculator

### SYNOPSIS

`dc`

### DESCRIPTION

`dc` is an arbitrary precision integer arithmetic package. The overall structure of `dc` is a stacking (reverse Polish) calculator. The following constructions are recognized:

* `number`
  Value pushed on stack. If starts with `0`, number is octal, otherwise decimal.
* `+ - * / %`
  Top two stack values are added, subtracted, multiplied, divided, or remaindered. Two entries popped; result pushed.
* `Sx`
  Pop top, store into register named `x` (any character).
* `Lx`
  Push value in register `x` (register not altered).
* `d`
  Duplicate top of stack.
* `p`
  Print top in decimal (top unchanged).
* `f`
  Pop and print all stack values in decimal.
* `r`
  Pop all stack values.
* `g`
  exit.
* `n`
  print brief synopsis of commands to `dc`.
* `new-line`, `space`
  ignored.

Example to calculate monthly, weekly and hourly rates for a $10,000/year salary:

```text
10000
100*    (now in cents)
dsa     (non-destructive store)
12/     (pennies per month)
1a52/   (pennies per week)
d10*    (deci-pennies per week)
375/    (pennies per hour)
f       (print all results)

(3) 512
(2) 19230
(1) 83333
```

### FILES

—

### SEE ALSO

—

### DIAGNOSTICS

`? (x)` for unrecognized character `x`.

### BUGS

`%` doesn’t work correctly.

### OWNER

`ken`

---

## 11/3/71 — DF (I)

### NAME

`df` — disk free

### SYNOPSIS

`df [filesystem]`

### DESCRIPTION

`df` prints out the number of free blocks available on a file system. If the file system is unspecified, the free space on `/dev/rf0` and `/dev/rk0` is printed.

### FILES

`/dev/rf0, /dev/rk0`

### SEE ALSO

`check`

### DIAGNOSTICS

—

### BUGS

—

### OWNER

`ken, dmr`

---

## 11/3/71 — DSW (I)

### NAME

`dsw` — delete interactively

### SYNOPSIS

`dsw [directory]`

### DESCRIPTION

For each file in the given directory (`.` if not specified) `dsw` types its name. If `y` is typed, the file is deleted; if `x`, `dsw` exits; if anything else, the file is not removed.

### FILES

—

### SEE ALSO

`rm`

### DIAGNOSTICS

—

### BUGS

The name “dsw” is a carryover from the ancient past. Its etymology is amusing but the name is nonetheless ill-advised.

### OWNER

`dmr, ken`

---

## 11/3/71 — DTF (I)

### NAME

`dtf` — DECtape format

### SYNOPSIS

`/etc/dtf`

### DESCRIPTION

`dtf` will write timing tracks, mark tracks and block numbers on a virgin DECtape. The format is DEC standard of 578 blocks of 256 words each. The end zones are a little longer than standard DEC.

Before use, the tape to be formatted should be mounted on drive 0. The `wall` and `wtm` switches should be enabled. After the tape is formatted, the switches should be disabled to prevent damage to subsequent tapes due to a controller logic error.

### FILES

—

### SEE ALSO

`sdate`

### DIAGNOSTICS

`?` is typed for any error detected.

### BUGS

This program does physical I/O on drive 0. The processor priority is set very high due to very stringent real time requirements. This means that all time sharing activities are suspended during the formatting (about 1.5 minutes). The real time clock will also be slow.

### OWNER

`ken`

---

## 11/3/71 — DU (I)

### NAME

`du` — summarize disk usage

### SYNOPSIS

`du [-s] [-a] [name ...]`

### DESCRIPTION

`du` gives the number of blocks contained in all files and (recursively) directories within each specified directory or file name. If `name` is missing, `.` is used.

* `-s` causes only the grand total to be given.
* `-a` causes an entry to be generated for each file.
* Absence of either causes an entry to be generated for each directory only.

A file which has two links to it is only counted once.

### DIAGNOSTICS

—

### BUGS

Files at the top level (not under `-a` option) are not listed. Removable file systems do not work correctly since i-numbers may be repeated while the corresponding files are distinct. `du` should maintain an i-number list per root directory encountered.

### OWNER

`amr`

---

## 11/3/71 — ED (I)

### NAME

`ed` — editor

### SYNOPSIS

`ed [name]`

### DESCRIPTION

`ed` is the standard text editor. `ed` is based on QED [reference] but is fully if succinctly described here. Differences between `ed` and QED are also noted to simplify the transition to the less powerful editor.

If the optional argument is given, `ed` simulates an `e` command on the named file; i.e., the file is read into `ed`’s buffer so that it can be edited.

`ed` operates on a copy of any file it is editing; changes made in the copy have no effect on the file until an explicit write (`w`) command is given. The copy resides in a temporary file called the buffer. There is only one buffer.

Commands: zero or more addresses followed by a single character command, possibly followed by parameters. Addresses specify lines in the buffer. Commands requiring addresses have defaults, so addresses can often be omitted.

Only one command per line. Certain commands accept input text; while accepting, `ed` is in input mode; no commands recognized; input collected. Leave input mode by typing a period (`.`) alone at the beginning of a line.

Regular expressions (limited):

1. ordinary character matches itself
2. `^` at beginning matches start of line
3. `$` at end matches end of line
4. `.` matches any character but newline
5. `re*` matches any number of adjacent occurrences of `re`
6. `[chars]` matches any character in set; if first is `^`, matches any character but newline and those in set
7. concatenation matches concatenation
8. null regular expression alone equals last regular expression encountered

Use `\` to escape metacharacters or delimiter.

Addresses:

1. `.` current line
2. `$` last line
3. `n` nth line
4. `/re/` search forward (wraps)
5. `?re?` search backward (wraps)
6. `addr+N` / `addr-N` relative

Addresses separated by `,` or `;` (semicolon sets current line to previous address before interpreting next, used to control search start for `/` and `?`).

Commands (defaults shown in parentheses; parentheses not part of address). Any command may be suffixed by `p` to print current line after completion.

* `(.)a`
  Append text after addressed line. Address 0 legal (insert at beginning). Current line becomes last input line (or addressed line if none).
* `(.,.)c`
  Change: delete addressed lines, then accept replacement text. Current becomes last input line (or first line not changed if none).
* `(.,.)d`
  Delete addressed lines. Current becomes first line not deleted.
* `e filename`
  Edit: delete buffer, read file; current becomes last line; number of chars read typed.
* `(1,$)g/re/command`
  Global: mark matching lines, then execute command on each with current set. Repeated command cannot be `a, g, i, c`.
* `(.)i`
  Insert text before addressed line (like `a` but before).
* `(.,.)l`
  List unambiguously; non-printing overstruck; long lines folded with `\newline`.
  (Overstrike mapping shown in source.)
* `(.,.)p`
  Print addressed lines; current becomes last printed.
* `q`
  Quit without automatic write.
* `($)r filename`
  Read file after addressed line; default is last-mentioned file; address 0 legal; number chars read typed; current becomes last line of inserted file.
* `(.,.)s/re/repl/`
  Substitute first occurrence per line; error if substitution fails on all addressed lines. Delimiter can be any non-space non-newline. `&` in replacement expands to matched text; escape `&` to suppress.
* `(1,$)w filename`
  Write addressed lines to file; default last named in `e, r, w`; current unchanged; number chars written typed.
* `($)=`
  Print line number of addressed line; current unchanged.
* `!UNIX command`
  Remainder sent to UNIX to interpret as command; current unchanged.
* `<newline>`
  Blank line equals `.+1p` (step through text).

Limits: at most 1500 lines, max line 256 characters.

Differences from QED (as listed in source):

1. No `\f`; leave input mode by `.` alone on a line.
2. Only one buffer (no `\b` stream directive).
3. Commands limited to: `acdeg i l pqrs W =` where `e` is new, `Π` exists.
4. Only special regex characters: `.^$[]*` with usual meanings; `^` and `$` effective only at beginning/end respectively; otherwise escape with `\` (which is not otherwise special).
5. In `s`, only leftmost occurrence is substituted.
6. `a` has different default address.

### FILES

`/tmp/etma, etmb, ...` temporary
`/etc/msh` used to implement `!` command.

### SEE ALSO

—

### DIAGNOSTICS

`?` for any error

### BUGS

`ed` is used as the shell for the editing system. It has the editing system UID built in and if invoked under this UID will give slightly different responses. This is a little kludgy.

### OWNER

`ken`

---

## 11/3/71 — FIND (I)

### NAME

`find` — find file with given name

### SYNOPSIS

`find name or number ...`

### DESCRIPTION

`find` searches the entire file system hierarchy and gives the path names of all files with the specified names or (decimal) i-numbers.

### FILES

—

### SEE ALSO

—

### DIAGNOSTICS

—

### BUGS

—

### OWNER

`dmr`

---

## 11/3/71 — FOR (I)

### NAME

`for` — fortran

### SYNOPSIS

`for file`

### DESCRIPTION

`for` is a nearly complete fortran compiler. `file` is the name of a fortran source program to be compiled. Differences from ANSI standard fortran include:

1. arbitrary combinations of types allowed in expressions; not all combos expected in runtime. Normal conversions among integer, real and double precision allowed.

### FILES

`f.tmp1, 2 3` — temporary
`/etc/f1, 2 3 4` — passes
`/etc/xx` — runtime

### DIAGNOSTICS

Diagnostics given by number. If source available, printed with underline at current character pointer. Listing of error numbers is available.

### BUGS

Features not yet implemented:

* functions
* arithmetic statement functions
* data statements
* complex constants
* hollerith constants
* continuation cards

### OWNER

`dmr, ken`

---

## 11/3/71 — FORM (I)

### NAME

`form` — form letter generator

### SYNOPSIS

`.form proto arg, ...`

### DESCRIPTION

`form` generates a form letter from a prototype letter, an associative memory, arguments and in a special case, the current date.

If invoked with argument `x`, the following files come into play:

* `x.f` — prototype input
* `x.r` — form letter output
* `x.am` — associative memory
* `form.am` — associative memory if `x.am` not found

Process copies `x.f` to `x.r`. If `\n` (n=1..9) encountered, nth argument inserted and rescanned. If `\0`, current date inserted. If needed argument not given, message `\n:` typed and response used.

If `[name]` encountered, name looked up in associative memory; if found, replaced (rescanned). If not found, message `name:` typed and response used; if memory writable, response entered under name.

Responses typed as arbitrary text terminated by two new lines (only first newline included). Process terminates instantly on EOF anywhere except in associative memory.

### FILES

`x.f` input file
`x.r` output file
`x.am` associative memory
`form.am` associative memory

### SEE ALSO

`type`

### DIAGNOSTICS

`settup error` when appropriate files cannot be located or created.

### BUGS

“settup” is misspelled.

### OWNER

`rhm, ken`

---

## 11/3/71 — HUP (I)

### NAME

`hup` — hang up typewriter

### SYNOPSIS

`hup`

### DESCRIPTION

`hup` hangs up the phone on the typewriter which uses it.

### FILES

—

### SEE ALSO

—

### DIAGNOSTICS

—

### BUGS

Should not be used; sometimes causes the typewriter channel to be lost.

### OWNER

`dmr, ken`

---

## 11/3/71 — LBPPT (I)

### NAME

`lbppt` — load binary paper tapes

### SYNOPSIS

`lbppt output [input]`

### DESCRIPTION

`lbppt` loads a paper tape in standard UNIX binary paper tape format. It is used to bring files to a UNIX installation. Currently there is a GECOS program to prepare a GECOS file in binary paper tape format.

If input specified, the character stream from that input is expected to be in UNIX binary paper tape format. If not present, `/dev/ppt` is assumed. Input stream is interpreted, checksummed, and copied to output file.

### FILES

`/dev/ppt`

### SEE ALSO

`dbppt`, `bppt` format

### DIAGNOSTICS

`check sum`; `usage:`; `read error`

### BUGS

—

### OWNER

`ken`

---

## 11/3/71 — LD (I)

### NAME

`ld` — link editor

### SYNOPSIS

`ld [-usaol] name, ...`

### DESCRIPTION

`ld` combines several object programs into one; resolves external references; and searches libraries. In simplest case, names of several object programs are given; `ld` combines them, producing an object module which can be executed or become input for another `ld`.

Argument routines concatenated in order specified. Entry point is beginning of first routine.

Libraries are searched: only routines defining unresolved externals are loaded. If a loaded routine refers to an undefined symbol still undefined at end of library, library searched again. Order affects efficiency more than results.

Flags (preceded by `-`):

* `-s` squash output: remove symbol table and relocation bits (can also be done by `strip`).
* `-u sym` take following argument as symbol, enter it as undefined in symbol table (useful for loading wholly from a library).
* `-o octal` set origin of load to given octal number; affects definition of relocatable externals; see DMR before using.
* `-l` abbreviation for library name:

  * `-l` alone = `/etc/liba.a` (standard assembly library)
  * `-lx` = `/etc/libx.a` where x any character; libraries exist for Fortran (`x=f`) and B (`x=b`).
* `-a` means absolute (load at origin absolute 0) but it doesn’t work.

Output left on `a.out`. Executable only if no errors occurred.

### FILES

`/etc/libx.a` for various x
`/etc/ltma, ltmb, ...` temporary
`a.out` output file

### SEE ALSO

`as, strip, ar` (maintains libraries)

### DIAGNOSTICS

* `can't create temp file` — unwritable directory or someone else using `ld` in same directory
* `can't open temp file` — temp deleted
* `file not found` — bad argument
* `bad format` — bad argument
* `relocation error` — bad argument (relocation bits corrupted)
* `bad relocation` — user error: relocatable reference to external symbol that turns out absolute
* `multiply defined` — same symbol defined twice
* `un` — undefined symbol
* `symbol not found` — loader bug

### BUGS

Option `-a` doesn’t work at all; option `-o` doesn’t work right.

### OWNER

`amr`

---

## 11/3/71 — LN (I)

### NAME

`ln` — make a link

### SYNOPSIS

`ln name1 [name2]`

### DESCRIPTION

Creates a link to existing file `name1`. If `name2` given, link has that name; otherwise placed in current directory with last path component of `name1`.

Forbidden to link to a directory or across file systems.

### FILES

—

### SEE ALSO

`rm` (to unlink)

### DIAGNOSTICS

—

### BUGS

Links don’t work right with respect to the backup system: one copy backed up for each link, and on reload both copies restored and link relationship lost.

### OWNER

`ken, dmr`

---

## 11/3/71 — LS (I)

### NAME

`ls` — list contents of directory

### SYNOPSIS

`ls [-ltasd] name,...`

### DESCRIPTION

`ls` lists contents of one or more directories:

* `-l` long format: i-number, mode, owner, size bytes, time last modification (see `stat` for mode format)
* `-t` sort by time modified (latest first) instead of by name
* `-a` list all entries; usually those beginning with `.` suppressed
* `-s` give size in blocks for each entry
* `-d` if argument is directory, list only its name, not contents (mostly used with `-l`)

If no argument, `.` listed. If argument is not directory, its name is given.

### FILES

`/etc/uids` to get user ID’s for `ls -l`

### SEE ALSO

`stat`

### DIAGNOSTICS

`name nonexistent`; `name unreadable`; `name unstatable`

### BUGS

In `ls -l`, when a user cannot be found in `/etc/uids`, the user number printed instead of a name is incorrect. It is correct in `stat`.

### OWNER

`dmr, ken`

---

## 11/3/71 — MAIL (I)

### NAME

`mail` — send mail to another user

### SYNOPSIS

`mail [letter person ...]`

### DESCRIPTION

`mail` without an argument searches for file `mailbox`, prints it if present, and asks if it should be saved. If answer is `y`, mail is renamed `mail`, otherwise deleted. The answer may be supplied in `letter` argument.

When followed by names of a letter and one or more people, the letter is appended to each person’s `mailbox`. Each letter is preceded by sender’s name and a postmark.

A person is either a directory name in `/usr` (mail sent to `/usr/person/mailbox`) or the path name of a directory (mailbox in that directory used).

When a user logs in he is informed of the presence of mail.

### FILES

`/etc/uids` to map sender numerical user ID to name; `mail` and `mailbox` in various directories.

### SEE ALSO

`init`

### DIAGNOSTICS

`who are you?` if user cannot be identified (bug). `Cannot send to user` if mailbox cannot be opened.

### BUGS

—

### OWNER

`ken`

---

## 11/3/71 — MESG (I)

### NAME

`mesg` — permit or deny messages

### SYNOPSIS

`mesg [n] [y]`

### DESCRIPTION

`mesg n` forbids messages via `write` by revoking non-user write permission on the user’s typewriter. `mesg y` reinstates permission. `mesg` with no argument reverses current permission. In all cases previous state is reported.

### FILES

`/dev/ttyn`

### SEE ALSO

`write`

### DIAGNOSTICS

`?` if standard input is not a typewriter

### BUGS

—

### OWNER

`dmr, ken`

---

## 11/3/71 — MKDIR (I)

### NAME

`mkdir` — make a directory

### SYNOPSIS

`mkdir dirname`

### DESCRIPTION

`mkdir` creates directory `dirname`. The standard entries `.` and `..` are made automatically.

### FILES

—

### SEE ALSO

`rmdir` to remove directories

### DIAGNOSTICS

`?`

### BUGS

No permissions are checked. The system’s user ID, not that of the creator, becomes the owner of the directory.

### OWNER

`ken, dmr`

---

## 11/3/71 — MKFS (I)

### NAME

`mkfs` — make file system

### SYNOPSIS

`/etc/mkfs t`
`/etc/mkfs r`

### DESCRIPTION

Initializes either a DECtape (argument `t`) or an RK03 disk pack (argument `r`) so it contains an empty file system. Must be used before a tape/pack can be mounted as file system.

Super-block, i-list, free list initialized; root directory entries `.` and `..` created. Blocks: RK03’s 4872, tapes 578.

Kept in `/etc` to avoid inadvertent use and destruction.

### FILES

`/dev/tap0, /dev/rk0`

### SEE ALSO

—

### DIAGNOSTICS

`Arg count`, `Unknown argument`, `Open error`.

### BUGS

—

### OWNER

`ken, amr`

---

## 11/3/71 — MOUNT (I)

### NAME

`mount` — mount file system

### SYNOPSIS

`mount special dir`

### DESCRIPTION

Announces removable file system mounted on device corresponding to special file `special`. Directory `dir` (must exist) becomes root name of newly mounted file system.

### FILES

—

### SEE ALSO

`umount`

### DIAGNOSTICS

`?` if special already in use, cannot be read, or if `dir` does not exist.

### BUGS

Should be usable only by the super-user.

### OWNER

`ken, dmr`

---

## 11/3/71 — MV (I)

### NAME

`mv` — move or rename a file

### SYNOPSIS

`mv name1 name2 [name3 name4 ...]`

### DESCRIPTION

Changes name of `name1` by linking to it under `name2` and then unlinking `name1`. Several pairs allowed. If new name is a directory, file moved into that directory under its old name. Directories may only be moved within same parent directory (just renamed).

### FILES

—

### SEE ALSO

—

### DIAGNOSTICS

`?a` incorrect argument count
`?d` attempt to move a directory
`?s` moving file to itself
`?l` link error; old file doesn't exist or can’t write new directory
`?u` can’t unlink old name

### BUGS

If `mv` removes target file but then unable to link back to old file, result is `?l` and removal of target file. Common with demountable file systems; should be circumvented; `mv` should copy if it can.

### OWNER

`ken, dmr`

---

## 11/3/71 — NM (I)

### NAME

`nm` — get name list

### SYNOPSIS

`nm [name]`

### DESCRIPTION

Prints symbol table from assembler/loader output. Only relocatable, global, undefined symbols (not absolute). Defined symbol preceded by value; undefined by blanks. Global symbols have first character underlined. Output sorted alphabetically. Default file: `a.out`.

### FILES

`a.out`

### SEE ALSO

`as, ld`

### DIAGNOSTICS

—

### BUGS

—

### OWNER

`dmr, ken`

---

## 11/3/71 — OD (I)

### NAME

`od` — octal dump

### SYNOPSIS

`od name [origin]`

### DESCRIPTION

Dumps file in octal, eight words per line with origin on left. If octal origin given, truncated to 0 mod 16 and dumping starts there; otherwise from 0. Continues until interrupted.

### FILES

—

### SEE ALSO

`db`

### DIAGNOSTICS

`?`

### BUGS

Dumping does not cease at EOF; file appears padded with garbage to length of 511 mod 512 bytes.

### OWNER

`ken, dmr`

---

## 11/3/71 — PR (I)

### NAME

`pr` — print file

### SYNOPSIS

`pr [-lcm] name, ...`

### DESCRIPTION

Produces printed listing of files. Output separated into pages headed by file name, date, page number.

* `-l` 78 lines/page instead of 66 (legal size)
* `-c` current date heads subsequent files
* `-m` modified date heads subsequent files (`-m` default)

### FILES

`/dev/ttyn` to suspend messages.

### SEE ALSO

`cat, cp, mesg`

### DIAGNOSTICS

none (files not found ignored)

### BUGS

none

### OWNER

`ken, dmr`

---

## 11/3/71 — REW (I)

### NAME

`rew` — rewind tape

### SYNOPSIS

`rew [digit]`

### DESCRIPTION

Rewinds DECtape drives. Digit is logical tape number `0..7`; missing digit indicates drive 0.

### FILES

`/dev/tap0, ..., /dev/tap7`

### SEE ALSO

—

### DIAGNOSTICS

`?` if no tape mounted or file can’t be opened.

### BUGS

—

### OWNER

`ken, dmr`

---

## 11/3/71 — RKD (I)

### NAME

`rkd` — dump RK disk to tape

### SYNOPSIS

`/etc/rkd`

### DESCRIPTION

Copies RK03/RK05 disk pack onto nine DECtapes. Physical I/O, interrupts disabled; time-sharing suspended. Tape drive sequence: 0, 1, 0, 1, ... Exits if 0 appears in console switches.

### FILES

—

### SEE ALSO

`rkl`

### DIAGNOSTICS

none; errors retried forever

### BUGS

—

### OWNER

`ken`

---

## 11/3/71 — RKF (I)

### NAME

`rkf` — format RK03 disk pack

### SYNOPSIS

`rkf`

### DESCRIPTION

Formats a virgin disk pack. Because it destroys all information and is not interlocked against file system activity, it is not maintained in executable form; source must be located and assembled.

### FILES

none (uses physical I/O on drive 0)

### SEE ALSO

—

### DIAGNOSTICS

`error` printed and core image produced if write error occurs. Copy of RK status register in register 5.

### BUGS

Not interlocked against system I/O; if I/O already occurring it will be badly disrupted. All information destroyed.

### OWNER

`ken, dmr`

---

## 11/3/71 — RKL (I)

### NAME

`rkl` — reload RK disk from tape

### SYNOPSIS

`/etc/rkl`

### DESCRIPTION

Loads an RK05/RK05 disk pack from nine DECtapes. Uses physical I/O with interrupts disabled; time-sharing suspended. Only super-user may invoke. Drive sequence: 0, 1, 0, 1, ... Ceases if 0 appears in console switches.

### FILES

—

### SEE ALSO

`rkd`

### DIAGNOSTICS

none; errors retried forever

### BUGS

—

### OWNER

`ken`

---

## 11/3/71 — RM (I)

### NAME

`rm` — remove (unlink) files

### SYNOPSIS

`rm name ...`

### DESCRIPTION

Removes directory entries for files. If entry was last link, file destroyed. Requires write permission in directory, but neither read nor write permission on file itself. Directories cannot be removed by `rm`; see `rmdir`.

### FILES

none

### SEE ALSO

`rmdir`

### DIAGNOSTICS

If file cannot be removed or doesn’t exist, file name followed by `?` typed.

### BUGS

Should probably ask whether a read-only file is really to be removed.

### OWNER

`ken, dmr`

---

## 11/3/71 — RMDIR (I)

### NAME

`rmdir` — remove directory

### SYNOPSIS

`rmdir dir, ...`

### DESCRIPTION

Removes directories. Directory must be empty except `.` and `..` (which `rmdir` removes). Write permission required in directory containing it.

### FILES

none

### SEE ALSO

—

### DIAGNOSTICS

`dir?` if not found, not directory, or not removable.
`dir -- directory not empty` if has entries other than `.` or `..`.

### BUGS

—

### OWNER

`ken, dmr`

---

## 11/3/71 — ROFF (I)

### NAME

`roff` — format text

### SYNOPSIS

`roff [+number] [-number] name`

### DESCRIPTION

Formats text according to control lines embedded in text. `+number` begins at first page with that number; `-number` ceases at first page higher than that number. Fully described elsewhere [reference].

### FILES

`/etc/suftab` hyphenation suffix list
`/tmp/rtma, rtmb, ...` temporary
`/dev/ttyn` to suspend messages

### SEE ALSO

[reference], `mesg`

### DIAGNOSTICS

none (files not found ignored)

### BUGS

Does not check for various buffer overflow. If fault occurs, check input near error.

### OWNER

`jfo, dmr, ken`

---

## 11/3/71 — SDATE (I)

### NAME

`sdate` — set date and time

### SYNOPSIS

`sdate mmddhhmm`

### DESCRIPTION

Adjusts system date/time. `mm` month, `dd` day, `hh` hour (24-hour), `mm` minute. Example:

```text
sdate 10080045
```

sets date to Oct. 8, 12:45 AM.

### FILES

none

### SEE ALSO

`date`

### DIAGNOSTICS

`?` if syntactically incorrect.

### BUGS

none

### OWNER

`ken, dmr`

---

## 11/3/71 — SH (I)

### NAME

`sh` — shell (command interpreter)

### SYNOPSIS

`sh [name [arg ...]]`

### DESCRIPTION

Standard command interpreter. Reads and arranges execution of command lines. Can be invoked to interpret files of command lines.

Command lines: sequences of commands separated by delimiters. Each command: sequence of non-blank arguments separated by blanks. First arg is command name. Other args passed to invoked command except special forms.

If command name is path to executable, invoked; otherwise `/bin/` prefixed and searched. If search fails, diagnostic printed.

Delimiters:

* newline
* `;` sequential execution
* `&` simultaneous execution (background)

Redirection:

* `<arg` set standard input from file `arg`
* `>arg` set standard output to file `arg`

Globbing:
If an argument contains `?` or `*`, directory is searched for matching files. `*` matches any string; `?` matches any single character. If argument contains `/`, directory derived up to last `/` before wildcard; remainder matched in that directory. Matching list sorted and substituted into argument list. Each wildcard-argument expanded separately.

`\` escapes next character to remove special meaning; also allows line continuation: newline preceded by `\` translated into blank.

Sequences in single `'` or double `"` quotes taken literally.

When invoked as command with `sh [name [arg...]]`, in the file, `$n` (n=0..9) replaced by nth argument; `$0` replaced by `name`.

EOF in shell input causes exit; thus logout is EOF.

### FILES

`/etc/glob`

### SEE ALSO

[reference] (theory of shell)

### DIAGNOSTICS

`?` in case of difficulty; most common inability to find command. Also: input file (`<`) cannot be found; no more processes can be created (self-alleviates). No diagnostic for inability to create output file (`>`), because stdout already closed.

If `*` or `?` used, `glob` routine invoked; it types “No command” if cannot find command, and “No match” if no files matched.

### BUGS

Better diagnostics needed. If `*` or `?` used, command must be in `/bin` (not in user directory). This is a glob bug.

### OWNER

`dmr, ken`

---

## 11/3/71 — STAT (I)

### NAME

`stat` — get file status

### SYNOPSIS

`stat name, ...`

### DESCRIPTION

Gives info:

* i-number
* access mode
* number of links
* owner
* size in bytes
* date/time of last modification
* name (useful when several files named)

Mode is six-character string:

1. `s` small (<4096 bytes), `l` large
2. `d` directory, `-` otherwise
3. `x` executable, `u` set user ID on execution, `-` none
4. `r` owner can read, `-` cannot
5. `w` owner can write, `-` cannot
6. `r` non-owner can read, `-` cannot
7. `w` non-owner can write, `-` cannot

Owner usually symbolic; if not found in `/etc/uids`, a number given.

If number of arguments not exactly 1, header generated identifying fields.

### FILES

`/etc/uids`

### SEE ALSO

`ls -l` (same information)

### DIAGNOSTICS

`name?` for any error.

### BUGS

none

### OWNER

`amr`

---

## 11/3/71 — STRIP (I)

### NAME

`strip` — remove symbols and relocation bits

### SYNOPSIS

`strip name, ...`

### DESCRIPTION

Removes symbol table and relocation bits from assembler/loader output to save space after debugging. Same effect as `ld -s`.

### FILES

`/tmp/stma, stmb ...` temporary

### SEE ALSO

`ld, as`

### DIAGNOSTICS

Diagnostics for: non-existent argument; inability to create temp file; improper format; inability to re-read temp file.

### BUGS

—

### OWNER

`amr`

---

## 11/3/71 — SU (I)

### NAME

`su` — become privileged user

### SYNOPSIS

`su password`

### DESCRIPTION

Become super-user by supplying password. If correct, executes shell with UID set to super-user. To restore normal UID privileges, type EOF to super-user shell.

### FILES

—

### SEE ALSO

`shell`

### DIAGNOSTICS

“Sorry” if password wrong.

### BUGS

—

### OWNER

`dmr, ken`

---

## 11/3/71 — SUM (I)

### NAME

`sum` — sum file

### SYNOPSIS

`sum name`

### DESCRIPTION

Sums contents of a file. Often used to verify DECtape readability without error.

### FILES

none

### SEE ALSO

—

### DIAGNOSTICS

`?` if file cannot be read at all or error during read.

### BUGS

none

### OWNER

`ken`

---

## 11/3/71 — TAP (I)

### NAME

`tap` — manipulate DECtape

### SYNOPSIS

`tap [key] [name ...]`

### DESCRIPTION

Saves/restores selected portions of file system hierarchy on DECtape. Actions controlled by `key`. Other args are file/dir names specifying what to dump/restore/table.

Function portion of key (one of):

* `r` dump indicated files/dirs and subdirs onto tape; replace existing same-name entries; if no file arg, `/` default.
* `u` update tape: like `r` but replace only if modification date later than tape’s; default if none given.
* `d` delete named files/dirs from tape (requires at least one file arg).
* `x` extract named files from tape to file system; restore owner/mode/date-modified; if no file arg, extract entire tape.
* `t` list names of all files stored on tape that are same as or below file args; if no file arg, table entire tape.
* `l` like `t` but expanded listing with all available information.

Modifiers:

* `0..7` select tape drive; default 0.
* `v` verbose: type name of each file preceded by letter:

  * `r` replaced
  * `a` added
  * `x` extracted
  * `d` deleted
    Usable with `r,u,a,x` only.
* `c` fresh dump: zero tape directory before beginning (usable only with `x` and `u` as written in source).
* `f` “fake” entries: only directory entries updated, not data; cannot be extracted; usable only with `r,u`.
* `w` wait/pause before each file; prompt; responses:

  * `y` yes treat file
  * empty: no skip file
  * `x` exit immediately
    In `x` function, previously asked files already extracted; with `r,u,a` no change made to tape.
* `m` create directories during `x` if necessary.
* `i` ignore tape errors (suggest caution; for damaged tapes).

### FILES

`/dev/tap0 ... /dev/tap7`

### SEE ALSO

—

### DIAGNOSTICS

```text
RK open error
RK read error
RK write error
Directory check sum
Directory overflow
RK overflow
Phase error (file changed after selected but before dumped)
```

### BUGS

All references to “RK” should read “tape.” `m` option does not work correctly in all cases. `i` option not yet implemented.

### OWNER

`ken`

---

## TAP (I)
tap -- manipulate DECtape

**SYNOPSIS**  
tap [ key ] [ name ... ]

**DESCRIPTION**  
tap saves and restores selected portions of the file system hierarchy on DECtape. Its actions are controlled by the key argument. The key is a string of characters containing at most one function letter and possibly one or more function modifiers. Other arguments to the command are file or directory names specifying which files are to be dumped, restored, or tabled.

The function portion of the key is specified by one of the following letters:

**r**  
The indicated files and directories, together with all subdirectories, are dumped onto the tape. If files with the same names already exist, they are replaced (hence the "r"). "Same" is determined by string comparison, so /abc can never be the same as "/usr/dmr/abc" even if "/usr/dmr" is the current directory. If no file argument is given, / is the default.

**u**  
updates the tape. u is the same as r, but a file is replaced only if its modification date is later than the date stored on the tape; that is to say, if it has changed since it was dumped. u is the default command if none is given.

**a**  
deletes the named files and directories from the tape. At least one file argument must be given.

**x**  
extracts the named files from the tape to the file system. The owner, mode, and date-modified are restored to what they were when the file was dumped. If no file argument is given, the entire contents of the tape are extracted.

**t**  
lists the names of all files stored on the tape which are the same as or are hierarchically below the file arguments. If no file argument is given, the entire contents of the tape are tabled.

**l**  
is the same as t except that an expanded listing is produced giving all the available information about the listed files.

The following characters may be used in addition to the letter which selects the function desired.

**0, ..., 7**  
This modifier selects the drive which the tape is mounted. 0 is the default.

**v**  
Normally tap does its work silently. The v (verbose) option causes it to type the name of each file it treats preceded by a letter to indicate what is happening.  
r file is being replaced  
a file is being added (not there before)  
x file is being extracted  
d file is being deleted  
The v option can be used with r, u, a, and x only.

**c**  
means a fresh dump is being created; the tape directory will be zeroed before beginning. Usable only with r and u.

**f**  
causes new entries copied on tape to be "fake" in that only the entries, not the data associated with the entries are updated. Such fake entries cannot be extracted. Usable only with r and u.

**w**  
causes tap to pause before treating each file, type the indicative letter and the file name (as with v) await the user's response. Response y means yes, so the file is treated. Null response means no, and the file does not take part in whatever is being done. Response x means exit; the tap command terminates immediately. In the x function, files previously asked about have been extracted already. With r, u, and a no change has been made to the tape.

**m**  
make (create) directories during an x if necessary.

**i**  
ignore tape errors. It is suggested that this option be used with caution to read damaged tapes.

**FILES**  
/dev/tap0 ... /dev/tap7

**DIAGNOSTICS**  
rk  
RK open error  
RK read error  
RK write error  
Directory check sum  
Directory overflow

**BUGS**  
RK overflow  
Phase error (a file has changed after it was selected for dumping but before it was dumped)  
All references to "RK" should read "tape." The m option does not work correctly in all cases. The i option is not yet implemented.

**OWNER**  
ken


## TM (I)
tm -- provide time information

**SYNOPSIS**  
tm [ command arg, .... ]

**DESCRIPTION**  
tm is used to provide timing information. When used without an argument, output like the following is given:

tim 77:43:20 29.2  
ovh 13:59:42 1.2  
dsk 12:06:30 4.1  
idl 352:31:37 23.7  
usr 3:32:15 0.1  
der 5.171 0.0

The first column of numbers gives totals in the named categories since the last time the system was cold-booted; the second column gives the changes since the last time tm was invoked. The tim row is total real time (hours: minutes: seconds); unlike the other times, its origin is the creation date of tm's temporary file. ovh is time spent executing in the system; dsk is time spent waiting for both kinds of disk I/O; idl is idle time; usr is user execution time; der is RF disk error count (left number) and RK disk error count (right number).

tm can be invoked with arguments which are assumed to constitute a command to be timed. In this case the output is as follows:

tim 2.2  
ovh 0.3  
dsk 1.8  
idl 0.0  
usr 0.0

The given times represent the number of seconds spent in each category during execution of the command.

**FILES**  
/tmp/ttmp, /dev/rf0 (for absolute times) contains the information used to calculate the differential times.

**SEE ALSO**  
format of file system (which tells where the times come from)

**DIAGNOSTICS**  
"?" if the command cannot be executed; can't creat temp file if trouble with ttmp; cant read super-block if times cannot be read from system.

**BUGS**  
(1) when invoked with a command argument, everything going on at the moment is counted, not just the command itself.  
(2) Two users doing tm simultaneously interfere with each other's use of the temporary file.

**OWNER**  
ken, dmr


## TTY (I)
tty -- get tty name

**SYNOPSIS**  
tty

**DESCRIPTION**  
tty gives the name of the user's typewriter in the form "ttyn for n a digit. The actual path name is then "/dev/ttyn.  
"not a tty" if the standard input file is not a typewriter.

**BUGS**  
--

**OWNER**  
dmr, ken


## TYPE (I)
type -- type on 2741

**SYNOPSIS**  
type name,...

**DESCRIPTION**  
type produces output on an IBM 2741 terminal with a Correspondence type ball.  
type uses typewriter tty5, which, because of the lack of access ports, is also used as a standard communication channel. Therefore, who should be used to verify the absence of a user on tty5.

The method is as follows: type the type command. It will wait until tty5 is dialled up. When the phone answers, depress the interrupt button after paper has been loaded, and the first file will be typed. type spaces out to the end of a sheet of paper and waits until the interrupt button is depressed before beginning each new file.

**FILES**  
/dev/tty5

**SEE ALSO**  
who

**DIAGNOSTICS**  
--

**BUGS**  
Obviously some scheme is needed to prevent interference between normal users and type. The best thing would be to support 2741's as a standard terminal.

**OWNER**  
amr


## UMOUNT (I)
umount -- dismount file system

**SYNOPSIS**  
umount special

**DESCRIPTION**  
umount announces to the system that the removable file system previously mounted on special file special is to be removed.  
Only the super-user may issue this command.

**SEE ALSO**  
mount

**DIAGNOSTICS**  
?

**BUGS**  
This command should be restricted to the super-user.

**OWNER**  
ken, dmr


## UN (I)
un -- undefined symbols

**SYNOPSIS**  
un [name ]

**DESCRIPTION**  
un prints a list of undefined symbols from an assembly or loader run. If the file argument is not specified, a.out is the default. Names are listed alphabetically except that non-global symbols come first. Undefined global symbols (unresolved external references) have their first character underlined.

**FILES**  
a.out

**SEE ALSO**  
as, ld

**DIAGNOSTICS**  
"?" if the file cannot be found.

**BUGS**  
--

**OWNER**  
dmr, ken


## WC (I)
wc -- get (English) word count

**SYNOPSIS**  
wc name,...

**DESCRIPTION**  
wc provides a count of the words, text lines, and roff control lines for each argument file.  
A text line is a sequence of characters not beginning with . and ended by a new-line.  
A roff control line is a line beginning with .  
A word is a sequence of characters bounded by the beginning of a line, by the end of a line, or by a blank or a tab.

**SEE ALSO**  
roff

**DIAGNOSTICS**  
none; arguments not found are ignored.

**FILES**  
--

**BUGS**  
--

**OWNER**  
jfo


## WHO (I)
who -- who is on the system

**SYNOPSIS**  
who

**DESCRIPTION**  
who lists the name, typewriter channel, and login time for each current UNIX user.  
/tmp/utmp contains the necessary information; it is maintained by init.

**FILES**  
/tmp/utmp

**SEE ALSO**  
/etc/init

**DIAGNOSTICS**  
--

**BUGS**  
--

**OWNER**  
dmr, ken


## WRITE (I)
write -- write to another user

**SYNOPSIS**  
write user

**DESCRIPTION**  
write copies lines from your typewriter to that of another user. When first called, write sends the message  
message from yourname...  
The recipient of the message should write back at this point. Communication continues until an end of file is read from the typewriter or an interrupt is sent. At that point write writes "EOT" on the other terminal.

Permission to write may be denied or granted by use of the mesg command. At the outset writing is allowed. Certain commands, in particular roff and pr, disallow messages in order to prevent messy output.

If the character "!" is found at the beginning of a line, write calls the mini-shell msh to execute the rest of the line as a command.

The following protocol is suggested for using write: When you first write to another user, wait for him to write back before starting to send. Each party should end each message with a distinctive signal ("(o)" for "over" is conventional) that the other may reply. "(oo)" (for "over and out") is suggested when conversation is about to be terminated.

**FILES**  
/tmp/utmp is used to discover the target user's typewriter channel and the sending user's name.  
msh is used to execute commands.

**SEE ALSO**  
mesg

**DIAGNOSTICS**  
"user not logged in"; "permission denied".

**BUGS**  
--

**OWNER**  
dmr, ken


---

# System Calls (II)

## SYS BREAK (II)
break -- set program break  
sys break; addr. / break = 17.

**DESCRIPTION**  
break sets the system's idea of the highest location used by the program to addr. Locations greater than addr and below the stack pointer are not swapped and are thus liable to unexpected modification.  
If the argument is 0 or higher than the stack pointer the entire 4K word user core area is swapped.

When a program begins execution via exec the break is set at the highest location defined by the program and data storage areas. Ordinarily, therefore, only programs with growing data areas need to use break.

**SEE ALSO**  
exec

**DIAGNOSTICS**  
none; strange addresses cause the break to be set to include all of core.

**BUGS**  
--

**OWNER**  
ken, dmr


## SYS CEMT (II)
cemt -- catch emt traps  
sys cemt; arg / cemt = 29.; not in assembler

**DESCRIPTION**  
This call allows one to catch traps resulting from the emt instruction. Arg is a location within the program; emt traps are sent to that location. The normal effect of emt traps may be restored by giving an arg equal to 0.

Prior to the use of this call, the result of an emt instruction is a simulated rts instruction. The operand field is interpreted as a register, and an rts instruction is simulated for that register (after verifying that various registers have appropriate values). This feature is useful for debugging, since the most dangerous program bugs usually involve an rts with bad data on the stack or in a register.

**BUGS**  
--

**OWNER**  
ken, dmr


## SYS CHDIR (II)
chdir -- change working directory  
sys chdir; dirname / chdir = 12.

**DESCRIPTION**  
dirname is address of the pathname of a directory, terminated by a 0 byte. chdir causes this directory to become the current working directory.  
The error bit (c-bit) is set if the given name is not that of a directory.

**OWNER**  
ken, dmr


## SYS CHMOD (II)
chmod -- change mode of file  
sys chmod; name; mode / chmod = 15.

**DESCRIPTION**  
The file whose name is given as the null-terminated string pointed to by name has its mode changed to mode. Modes are constructed by oring together some combination of the following:  
01 write, non-owner  
02 read, non-owner  
04 write, owner  
10 read, owner  
20 executable  
40 set user ID on execution

Only the owner of a file (or the super-user) may change the mode.  
Error bit (c-bit) set if name cannot be found or if current user is neither the owner of the file nor the super-user.

**OWNER**  
ken, dmr


## SYS CHOWN (II)
chown -- change owner of file  
sys chown; name; owner / chown = 16.

**DESCRIPTION**  
The file whose name is given by the null-terminated string pointed to by name has its owner changed to owner. Only the present owner of a file (or the super-user) may donate the file to another user. Also, one may not change the owner of a file with the set-user-ID bit on, otherwise one could create Trojan Horses able to misuse other's files.

**FILES**  
/etc/uids has the mapping between user names and user numbers.

The error bit (c-bit) is set on illegal owner changes.

**OWNER**  
ken, dmr


## SYS CLOSE (II)
close -- close a file  
(file descriptor in r0)  
sys close / close = 6.

**DESCRIPTION**  
Given a file descriptor such as returned from an open or creat call, close closes the associated file. A close of all files is automatic on exit, but since processes are limited to 10 simultaneously open files, close is necessary to programs which deal with many files.

**SEE ALSO**  
creat, open

**DIAGNOSTICS**  
The error bit (c-bit) is set for an unknown file descriptor.

**BUGS**  
--

**OWNER**  
ken, dmr


## SYS CREAT (II)
creat -- create a new file  
sys creat; name; mode / creat = 8.  
(file descriptor in r0)

**DESCRIPTION**  
creat creates a new file or prepares to rewrite an existing file called name; name is the address of a null-terminated string. If the file did not exist, it is given mode mode; if it did exist, its mode and owner remain unchanged but it is truncated to 0 length.

The file is also opened for writing, and its file descriptor is returned in r0.

The mode given is arbitrary; it need not allow writing. This feature is used by programs which deal with temporary files of fixed names. The creation is done with a mode that forbids writing. Then if a second instance of the program attempts a creat, an error is returned and the program knows that the name is unusable for the moment.

If the last link to an open file is removed, the file is not destroyed until the file is closed.

**SEE ALSO**  
write, close

**DIAGNOSTICS**  
The error bit (c-bit) may be set if: a needed directory is not readable; the file does not exist and the directory in which it is to be created is not writable; the file does exist and is unwritable; the file is a directory.

**OWNER**  
ken, dmr


## SYS EXEC (II)
exec -- execute a file  
sys exec; name; args / exec = 11.

name: <...\0>  
args: arg1; arg2; ...; 0  
arg1: <...\0>

**DESCRIPTION**  
exec overlays the calling process with the named file, then transfers to the beginning of the core image of the file. The first argument to exec is a pointer to the name of the file to be executed. The second is the address of a list of pointers to arguments to be passed to the file. Conventionally, the first argument is the name of the file. Each pointer addresses a string terminated by a null byte.

There can be no return from the file; the calling core image is lost.

The program break is set from the executed file; see the format of a.out.

Once the called file starts execution, the arguments are passed as follows. The stack pointer points to the number of arguments. Just above this number is a list of pointers to the argument strings.

sp-> nargs  
arg1  
argn  
arg1: <arg1\0>  
argn: <argn\0>

The arguments are placed as high as possible in core: just below 60000(8).

Files remain open across exec calls. However, the illegal instruction, emt, quit, and interrupt trap specifications are reset to the standard values. (See ilgins, cemt, quit, intr.)

Each user has a real user ID and an effective user ID. (The real ID identifies the person using the system; the effective ID determines his access privileges.) exec changes the effective user ID to the owner of the executed file if the file has the set-user-ID mode. The real user ID is not affected.

**SEE ALSO**  
fork

**DIAGNOSTICS**  
If the file cannot be read or if it is not executable, a return from exec constitutes the diagnostic. The error bit (c-bit) is set.

**OWNER**  
ken, dmr


## SYS EXIT (II)
exit -- terminate process  
sys exit / exit = 1

**DESCRIPTION**  
exit is the normal means of terminating a process. All files are closed and the parent process is notified if it is executing a wait. This call can never return.

**SEE ALSO**  
sys wait

**OWNER**  
ken, dmr


## SYS FORK (II)
fork -- spawn new process  
fork / fork = 2.

(new process return)  
(old process return)

**DESCRIPTION**  
fork is the only way new processes are created. The new process's core image is a copy of that of the caller of fork; the only distinction is the return location and the fact that r0 in the old process contains the process ID of the new process. This process ID is used by wait.

**SEE ALSO**  
sys wait, sys exec

**DIAGNOSTICS**  
The error bit (c-bit) is set in the old process if a new process could not be created because of lack of swap space.

**BUGS**  
See wait for a subtle bug in process destruction.

**OWNER**  
ken, dmr


## SYS FSTAT (II)
fstat -- get status of open file  
/ fstat = 28.  
(file descriptor in r0)  
sys fstat; buf

**DESCRIPTION**  
This call is identical to stat, except that it operates on open files instead of files given by name. It is most often used to get the status of the standard input and output files, whose names are unknown.

**SEE ALSO**  
sys stat

**DIAGNOSTICS**  
The error bit (c-bit) is set if the file descriptor is unknown.

**OWNER**  
ken, dmr


## SYS GETUID (II)
getuid -- get user identification  
sys getuid / getuid = 24. (user ID in r0)

**DESCRIPTION**  
getuid returns the real user ID of the current process. The real user ID identifies the person who is logged in, in contradistinction to the effective user ID, which determines his access permission at each moment. It is thus useful to programs which operate using the set user ID mode, to find out who invoked them.

**FILES**  
/etc/uids can be used to map the user ID number into a name.

**SEE ALSO**  
setuid

**OWNER**  
ken, dmr


## SYS GTTY (II)
gtty -- get typewriter status  
(file descriptor in r0)  
sys gtty; arg / gtty = 32.; not in assembler  
arg: .=.+6

**DESCRIPTION**  
gtty stores in the three words addressed by arg the status of the typewriter whose file descriptor is given in r0. The format is the same as that passed by stty.

**SEE ALSO**  
stty

**DIAGNOSTICS**  
Error bit (c-bit) is set if the file descriptor does not refer to a typewriter.

**OWNER**  
ken, dmr


## SYS ILGINS (II)
ilgins -- catch illegal instruction trap  
sys ilgins; arg / ilgins = 33.; not in assembler

**DESCRIPTION**  
ilgins allows a program to catch illegal instruction traps. If arg is zero, the normal instruction trap handling is done: the process is terminated and a core image is produced. If arg is a location within the program, control is passed to arg when the trap occurs.

This call is used to implement the floating point simulator, which catches and interprets 11/45 floating point instructions.

**SEE ALSO**  
fptrap, the floating point package

**OWNER**  
ken, dmr


## SYS INTR (II)
intr -- set interrupt handling  
sys intr; arg / intr = 27.

**DESCRIPTION**  
When arg is 0, interrupts (ASCII DELETE) are ignored. When arg is 1, interrupts cause their normal result, that is, force an exit. When arg is a location within the program, control is transferred to that location when an interrupt occurs.

After an interrupt is caught, it is possible to resume execution by means of an rti instruction; however, great care must be exercised, since all I/O is terminated abruptly upon an interrupt. In particular, reads of the typewriter tend to return with 0 characters read, thus simulating an end of file.

**SEE ALSO**  
quit

**BUGS**  
It should be easier to resume after an interrupt, but I don't know how to make it work.

**OWNER**  
ken, dmr


## SYS LINK (II)
link -- link to a file  
sys link; name1; name2 / link = 9.

**DESCRIPTION**  
A link to name1 is created; the link has name name2. Either name may be an arbitrary path name.

**SEE ALSO**  
unlink

**DIAGNOSTICS**  
The error bit (c-bit) is set when name1 cannot be found; when name2 already exists; when the directory of name2 cannot be written; when an attempt is made to link to a directory by a user other than the super-user.

**OWNER**  
ken, dmr


## SYS MKDIR (II)
mkdir -- make a directory  
sys mkdir; name; mode / mkdir = 14.

**DESCRIPTION**  
mkdir creates an empty directory whose name is the null-terminated string pointed to by name. The mode of the directory is mode. The special entries . and .. are not present.  
mkdir can only be invoked by the super-user.

**SEE ALSO**  
mkdir command

**DIAGNOSTICS**  
Error bit (c-bit) is set if the directory already exists or if the user is not the super-user.

**OWNER**  
ken, dmr


## SYS MOUNT (II)
mount -- mount file system  
sys mount; special; name / mount = 21.; not in assembler

**DESCRIPTION**  
mount announces to the system that a removable file system has been mounted on special file special; from now on, references to file name will refer to the root file on the newly mounted file system. Special and name are pointers to null-terminated strings containing the appropriate path names.

Name must exist already. If it had useful contents, they are inaccessible while the file system is mounted. Almost always, name should be a directory so that an entire file system, not just one file, may exist on the removable device.

**SEE ALSO**  
umount

**DIAGNOSTICS**  
Error bit (c-bit) set if special is inaccessible or dir does not exist.

**BUGS**  
At most one removable device can be mounted at a time. The use of this call should be restricted to the super-user.

**OWNER**  
ken, dmr


## SYS OPEN (II)
open -- open for reading or writing  
sys open; name; mode / open = 5.  
(descriptor in r0)

**DESCRIPTION**  
open opens the file name for reading (if mode is 0) or writing (if mode is non-zero). name is the address of a string of ASCII characters representing a path name, terminated by a null character.

The file descriptor should be saved for subsequent calls to read (or write) and close. In both the read and write case the file pointer is set to the beginning of the file.

If the last link to an open file is removed, the file is not destroyed until it is closed.

**SEE ALSO**  
creat, read, write, close

**DIAGNOSTICS**  
The error bit (c-bit) is set if the file does not exist, if one of the necessary directories does not exist or is unreadable, or if the file is not readable.

**OWNER**  
ken, dmr


## SYS QUIT (II)
quit -- turn off quit signal  
sys quit; flag / quit = 26.

**DESCRIPTION**  
When flag is 0, this call disables quit signals from the typewriter (ASCII FS). When flag is 1, quits are re-enabled, and cause execution to cease and a core image to be produced. When flag is an address in the program, a quit causes control to be sent to that address.

Quits should be turned off only with due consideration.

**SEE ALSO**  
sys intr turns off interrupts

**BUGS**  
--

**OWNER**  
ken, dmr


## SYS READ (II)
read -- read from file  
(file descriptor in r0)  
sys read; buffer; nchars / read = 3.  
(nread in r0)

**DESCRIPTION**  
A file descriptor is a word returned from a successful open call. Buffer is the location of nchars contiguous bytes into which the input will be placed. It is not guaranteed that all nchars bytes will be read, however; for example if the file refers to a typewriter at most one line will be returned. In any event the number of characters read is returned in r0. If r0 returns with value 0, then end-of-file has been reached.

**SEE ALSO**  
open

**DIAGNOSTICS**  
As mentioned, r0 is 0 on return when the end of the file has been reached. If the read was otherwise unsuccessful the error bit (c-bit) is set. Many conditions, all rare, can generate an error: physical I/O errors, bad buffer address, preposterous nchars, file descriptor not that of an input file.

**OWNER**  
ken, dmr


## SYS RELE (II)
rele -- release processor  
sys rele / rele = 0; not in assembler

**DESCRIPTION**  
This call causes the process to be swapped out immediately if another process wants to run. Its main reason for being is internal to the system, namely to implement timer-runout swaps. However, it can be used beneficially by programs which wish to loop for some reason without consuming more processor time than necessary.

**OWNER**  
ken, dmr


## SYS SEEK (II)
seek -- move read/write pointer  
(file descriptor in r0)  
sys seek; offset; ptrname / seek = 19.

**DESCRIPTION**  
The file descriptor refers to a file open for reading or writing. The read (or write) pointer for the file is set as follows:  
if ptrname is 0, the pointer is set to offset.  
if ptrname is 1, the pointer is set to its current location plus offset.  
if ptrname is 2, the pointer is set to the size of the file plus offset.

**SEE ALSO**  
tell

**DIAGNOSTICS**  
The error bit (c-bit) is set for an undefined file descriptor.

**BUGS**  
A file can conceptually be as large as 2**20 bytes. Clearly only 2**16 bytes can be addressed by seek. The problem is most acute on the tape files and RK and RF. Something is going to be done about this.

**OWNER**  
ken, dmr


## SYS SETUID (II)
setuid -- set process ID  
sys setuid / setuid = 23.  
(process ID in r0)

**DESCRIPTION**  
The user ID of the current process is set to the argument in r0. Both the effective and the real user ID are set. This call is only permitted to the super-user.

**SEE ALSO**  
getuid

**DIAGNOSTICS**  
Error bit (c-bit) is set if the current user ID is not that of the super-user.

**OWNER**  
ken, dmr


## SYS SMDATE (II)
smdate -- set modified date on file  
(time to AC-MQ)  
sys smdate; file / smdate = 30.; not in assembler

**DESCRIPTION**  
File is the address of a null-terminated string giving the name of a file. The modified time of the file is set to the time given in the AC-MQ registers. This call is allowed only to the super-user.

**DIAGNOSTICS**  
Error bit is set if the user is not the super-user or if the file cannot be found.

**OWNER**  
ken, dmr


## SYS STAT (II)
stat -- get file status  
sys stat; name; buf / stat = 18.

**DESCRIPTION**  
name points to a null-terminated string naming a file; buf is the address of a 34(10) byte buffer into which information is placed concerning the file. It is unnecessary to have any permissions at all with respect to the file, but all directories leading to the file must be readable.

After stat, buf has the following format:
i-number                  buf,+0  
flags (see below)         +1  
number of links           +2  
user ID of owner          +3  
size in bytes             +4,+5  
first indirect block...   +6,+7  
...  
eighth indirect...        +22,+23  
creation time             +24,+25,+26,+27  
modification time         +28,+29,+30,+31  
unused                    +32,+33

The flags are as follows:  
100000 used (always on)  
040000 directory  
020000 file has been modified (always on)  
010000 large file  
000040 set user ID  
000020 executable  
000010 read, owner  
000004 write, owner  
000002 read, non-owner  
000001 write, non-owner

**SEE ALSO**  
fstat

**DIAGNOSTICS**  
Error bit (c-bit) is set if the file cannot be found.

**BUGS**  
The format is going to change someday.

**OWNER**  
ken, dmr


## SYS STIME (II)
stime -- set time  
(time in AC-MQ)  
sys stime / stime = 25.; not in assembler

**DESCRIPTION**  
stime sets the system's idea of the time and date. Only the super-user may use this call.

**SEE ALSO**  
sys time

**DIAGNOSTICS**  
Error bit (c-bit) set if user is not the super-user.

**OWNER**  
ken, dmr


## SYS STTY (II)
stty -- set mode of typewriter  
(file descriptor in r0)  
sys stty; arg / stty = 31.; not in assembler  
arg: dcrsr; dcpsr; mode

**DESCRIPTION**  
stty sets mode bits for a typewriter whose file descriptor is passed in r0. First, the system delays until the typewriter is quiescent. Then, the argument dcrsr is placed into the typewriter's reader control and status register, and dcpsr is placed in the printer control and status register. The DC-11 manual must be consulted for the format of these words. For the purpose of this call, the most important role of these arguments is to adjust to the speed of the typewriter.

The mode arguments contains several bits which determine the system's treatment of the typewriter:
200 even (M37 tty) parity allowed  
100 odd (non-M37 tty) allowed  
040 raw mode: wake up on all characters  
020 map CR into LF; echo LF or CR as CR-LF  
010 don't echo (half duplex)  
004 map upper case to lower case on input (M33 TTY)

Characters with the wrong parity, as determined by bits 200 and 100, are ignored.

In raw mode, every character is passed back immediately to the program. No erase or kill processing is done; the end-of-file character (EOT), the interrupt character (DELETE) and the quit character (FS) are not treated specially.

Mode 020 causes input carriage returns to be turned into new-lines; input of either CR or LF causes CR-LF both to be echoed (used for GE TermiNet 300's).

**SEE ALSO**  
gtty

**DIAGNOSTICS**  
The error bit (c-bit) is set if the file descriptor does not refer to a typewriter.

**BUGS**  
This call should be used with care. It is all too easy to turn off your typewriter.

**OWNER**  
ken, dmr


## SYS TELL (II)
tell -- get file pointer  
(file descriptor in r0)  
sys tell; offset; ptrname / tell = 20.  
(value returned in r0)

**DESCRIPTION**  
The file descriptor refers to an open file. The value returned in r0 is one of:  
if ptrname is 0, the value returned is offset;  
if ptrname is 1, the value is the current pointer plus offset;  
if ptrname is 2, the value returned is the number of bytes in the file plus offset.

**SEE ALSO**  
seek

**DIAGNOSTICS**  
The error bit (c-bit) is set if the file descriptor is unknown.

**BUGS**  
Tell doesn't work. Complain if you need it.

**OWNER**  
ken, dmr


## SYS TIME (II)
time -- get time of year  
time / time = 13.  
sys (time AC-MQ)

**DESCRIPTION**  
time returns the time since 00:00:00, Jan. 1, 1971, measured in sixtieths of a second. The high order word is in the AC register and the low order is in the MQ.

The chronological-minded user will note that 2**32 sixtieths of a second is only about 2.5 years.

**OWNER**  
ken, dmr


## SYS UMOUNT (II)
umount -- dismount file system  
sys umount; special / umount = 22.; not in assembler

**DESCRIPTION**  
umount announces to the system that special file special is no longer to contain a removable file system. The file associated with the special file reverts to its ordinary interpretation (see mount). The user must take care that all activity on the file system has ceased.

**SEE ALSO**  
mount

**DIAGNOSTICS**  
Error bit (c-bit) set if no file system was mounted on the special file.

**BUGS**  
Use of this call should be restricted to the super-user.

**OWNER**  
ken, dmr


## SYS UNLINK (II)
unlink -- remove directory entry  
sys unlink; name / unlink = 10.

**DESCRIPTION**  
Name points to a null-terminated string. Unlink removes the entry for the file pointed to by name from its directory. If this entry was the last link to the file, the contents of the file are freed and the file is destroyed. If, however, the file was open in any process, the actual destruction is delayed until it is closed, even though the directory entry has disappeared.

**SEE ALSO**  
link

**DIAGNOSTICS**  
The error bit (c-bit) is set to indicate that the file does not exist or that its directory cannot be written. Write permission is not required on the file itself. It is also illegal to unlink a directory (except for the super-user).

**BUGS**  
Probably write permission should be required to remove the last link to a file, but this gets in other problems (namely, one can donate an undeletable file to someone else). If the system crashes while a file is waiting to be deleted because it is open, the space is lost.

**OWNER**  
ken, dmr


## SYS WAIT (II)
wait -- wait for process to die  
sys wait / wait = 7.  
(process ID in r0)

**DESCRIPTION**  
wait causes its caller to delay until one of its child processes terminates. If any child has already died, return is immediate; if there are no children, return is immediate with the error bit set. In the case of several children several waits are needed to learn of all the deaths.

**SEE ALSO**  
fork

**DIAGNOSTICS**  
error bit (c-bit) on if no children not previously waited for.

**BUGS**  
A child which dies but is never waited for is not really gone in that it still consumes disk swap and system table space. This can make it impossible to create new processes. The bug can be noticed when several & separators are given to the shell not followed by an command without an ampersand. Ordinarily things clean themselves up when an ordinary command is typed, but it is possible to get into a situation in which no commands are accepted, so no waits are done; the system is then hung. The fix, probably, is to have a new kind of fork which creates a process for which no wait is necessary (or possible); also to limit the number of active or inactive descendants allowed to a process.

**OWNER**  
ken, dmr


## SYS WRITE (II)
write -- write on file  
(file descriptor in r0)  
sys write; buffer; nchars / write = 4.  
(number written in r0)

**DESCRIPTION**  
A file descriptor is a word returned from a successful open or creat call. buffer is the address of nchars contiguous bytes which are written on the output file. The number of characters actually written is returned in r0. It should be regarded as an error if this is not the same as requested.

For disk and tape files, writes which are multiples of 512 characters long and begin on a 512-byte boundary are more efficient than any others.

**SEE ALSO**  
sys creat, sys open

**DIAGNOSTICS**  
The error bit (c-bit) is set on an error: bad descriptor, buffer address, or count. physical I/O errors;

**OWNER**  
ken, dmr


---

# Library Routines (III) and Formats (V–VII)
