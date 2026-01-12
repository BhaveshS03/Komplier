

# Kompiler

A minimalist project written in **C** that explores language processing concepts. It currently implements a stack-based descent parser using an LL(1) grammar.
This project is mainly developed for learning and experimentation purposes.


## Feature Roadmap

Current implementation status of the compiler components below:

* [x] **Lexical Analyzer**: Manual implementation of a DFA-based scanner in C.
* [x] **LL(1) Parser**: Recursive descent parsing for statements and expressions.
* [ ] **Symbol Table**: Hash-map based storage for variable tracking. (In Progress).
* [ ] **Type Checking**: Semantic analysis to prevent type-mismatch errors (Planned).
* [ ] **Basic Arithmetic**: Support for addition and operator precedence.
* [ ] **IR Generation**: Generating Three-Address Code, mostly for LLVM (Planned)


## The Pipeline (Expected)

The compiler follows the classic front-end architecture:

1. **Scanner (`lexer.c`):** Reads the source file character-by-character and generates tokens.
2. **Parser (`parser.c`):** Consumes tokens and validates them against the CFG.
3. **Symbol Table:** Manages memory addresses and variable scopes. 
4. **Interpreter/CodeGen:** Evaluates the Abstract Syntax Tree (AST) or generates output.


## Grammar Rules

The compiler logic is governed by the following Context-Free Grammar:

```bnf
S  -> id = E | print ( E )
E  -> T E'
E' -> + T E' | ε
T  -> id | num | ( E )
```


## Getting Started

### Prerequisites

* **Compiler:** `gcc` or `clang`

### Installation & Build

```bash
# Clone the repository
git clone https://github.com/BhaveshS03/Kompiler.git
cd Kompiler

# Compile the project
gcc -o kompiler src/main.c src/lexer.c src/parser.c -Iinclude

```

### Usage

Run the Parser:

```bash
./kompiler

```


## 📂 Project Structure

* `main.c` — Entry point of the compiler.
* `src/lexer.c` — Logic for tokenization.
* `src/parser.c` — Implementation of the CFG rules.
* `include/` — Header files (`.h`) for definitions and structures.
* `examples/` — Sample code snippets in the custom language.
