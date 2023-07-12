# BinaryTreeEvaluator

This is a simple binary tree evaluator written in C++ within our algorithms lecture.

## Usage
First you need to compile the programm. You can do this by using the makefile. Just type `make` in your terminal. This will create a binary file called `BinaryTreeEvaluator`.

```bash
$ cmake --build <your destination folder, eg. /cmake-build-debug with CLion> --target BinaryTreeEvaluator -j 8
```


In order to use this programm you need to pass arguments to the programm. The first argument is the mode: Infix( | ), Postfix ( > ) or Prefix ( < ). The first argument is the expression you want to evaluate.

### Example
```bash
./BinaryTreeEvaluator {"<","/+10*4 5-/84 12 1"}  # Prefix
./BinaryTreeEvaluator {"|","((10 +(4*5))/((84/12)-1))"}   # Infix
./BinaryTreeEvaluator {">", "10 4 5*+84 12 / 1 -/"}  # Postfix
```

Example output:
```bash
$ ./BinaryTreeEvaluator {"|","((10 +(4*5))/((84/12)-1))"}

Mode:|
Expression:((10 +(4*5))/((84/12)-1))
Prefix:  /+10 *4 5 -/84 12 1 = 5
Infix:   ((10 +(4 *5) )  /((84 /12)  -1) )  = 5
Postfix: 10 4 5*+ 84 12/ 1-/ = 5
Nodes: 11
Depth: 4
        .——— 1
    .——— -
   │   │    .——— 12
   │    `——— /
   │        `——— 84
——— /
   │        .——— 5
   │    .——— *
   │   │    `——— 4
    `——— +
        `——— 10
```

## Contributers
- [Dinar Karchevskii](https://github.com/karchevskii)
- [Philipp Konstantin Gehrig](https://github.com/philippgehrig)

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

## License
[MIT](https://choosealicense.com/licenses/mit/)

