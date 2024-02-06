# Set Shell
set shell := ["zsh", "-cu"]

# Compiler Variables
compiler := "clang++"
sources := "src/*.cpp"
flags := "-Wall -g"
dir := "build"
target := "main"


# Build program
build:
    {{compiler}} {{flags}} {{sources}} -o {{dir}}/{{target}}

# Run Program
run: build && clean
    @./{{dir}}/{{target}}


# Clean output
clean:
    @rm -rf {{target}}
