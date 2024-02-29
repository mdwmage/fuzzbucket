# Set Shell
# set shell := ["zsh", "-cu"]

# Compiler Variables
compiler := "clang++"
std := "c++17"
sources := "src/"
libraries := "src/library/"
flags := "-Wall -g"
dir := "build"
target := "fuzz"


# Build program
build:
    @mkdir -p ./build/target/
    @echo "Building library files"
    @echo "---------------------------------------------"
    @for file in ` ls {{libraries}}`; do \
        echo "> building library file: $file"; \
        {{compiler}} -std={{std}} {{flags}} -c {{libraries}}$file -o {{dir}}/"$file".o; \
    done
    @echo -e "\n"
    @echo "Building source files"
    @echo "---------------------------------------------"
    @for file in `ls -I library -I "*.hpp" {{sources}}`; do \
        echo "> building source file: $file"; \
        {{compiler}} -std={{std}} {{flags}} -c {{sources}}$file -o {{dir}}/"$file".o; \
    done
    @echo -e "\nLinking Binaries..."
    @{{compiler}} -std={{std}} {{flags}} {{dir}}/*.o -o {{dir}}/target/{{target}}
    @echo "Binaries Linked!"
    @echo -e "\n---------------------------------------------"
    @echo "Project: {{target}} successfully built to ./{{dir}}/target/{{target}}"

# Clean output
clean:
    @rm -rf {{dir}}/*
