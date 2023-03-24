# Test-retdec


## Build
```
cmake -Bbuild
```

## IR2S
```
clang -S -O0 -masm=intel -c capstone2llvmir_test_1.ll -o capstone2llvmir_test_1.s -m64
```

## IR2OBJ
```
clang -O0 -masm=intel -c capstone2llvmir_test_1.ll -o capstone2llvmir_test_1.o -m64
```
