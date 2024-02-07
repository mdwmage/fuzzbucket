# Set Shell
set shell := ["zsh", "-cu"]

# Compiler Variables
compiler := "clang++"
sources := "src/*.cpp"
flags := "-Wall -g"
dir := "build"
target := "fuzz"


# Build program
build:
    @mkdir -p {{dir}}/target
    {{compiler}} {{flags}} {{sources}} -o {{dir}}/target/{{target}}

# Run Program
run: build
    @./{{dir}}/target/{{target}}


# Clean output
clean:
    @rm -rf {{dir}}/target/*
