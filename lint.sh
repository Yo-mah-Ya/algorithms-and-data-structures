find . -type f \
    -name *.c -o \
    -name *.cc -o \
    -name *.cpp -o \
    -name *.h -o \
    -name *.hh -o \
    -name *.hpp \
    | xargs clang-format -i

find . -type f \
    -name *.c -o \
    -name *.cc -o \
    -name *.cpp -o \
    -name *.h -o \
    -name *.hh -o \
    -name *.hpp \
    | xargs clang-tidy
