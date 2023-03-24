# Test-retdec


## Build
```
cmake -Bbuild
```

## IROPT
```
clang -S -emit-llvm -c -O3 capstone2llvmir_test_1.ll -o capstone2llvmir_test_1.o3.ll -m64
```

## IR2S
```
clang -S -O0 -masm=intel -c capstone2llvmir_test_1.ll -o capstone2llvmir_test_1.s -m64
```

## IR2OBJ
```
clang -O0 -masm=intel -c capstone2llvmir_test_1.ll -o capstone2llvmir_test_1.o -m64
```
