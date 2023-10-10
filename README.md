# Valgrind Exercise
ENPM808X - Abhishekh Reddy Munnangi, 119399002

## Running the exercise

> **Note:** The steps assume that the user already has the environment for ENPM808x course.

### Clone this repository to your favorite directory

```bash
git clone https://github.com/armgits/armgits-valgrind-exercise.git armgits-valgrind-exercise
```

> **Note:** Run the following commands from the project root directory

### Generate the build system

```bash
cmake -S ./ -B build/
```

>**Note:** Re-run this command everytime when any `CMakeLists.txt` file is changed.

### Build the project

Normal
```bash
cmake --build build/
```

Build clean
```bash
cmake --build build/ --clean-first
```

Using `bear`
```bash
bear -- cmake --build build/ --clean-first
```

### Run the program using Valgrind

```bash
valgrind --leak-check=yes ./build/app/shell-app
```

### Clean-up the project

Clean the build artifacts while retaining the build system
```bash
cmake --build build/ --target clean
```

Remove the build system including artifacts
```bash
rm -rf build/
```

Additional files and folders (if they exist)
```bash
rm -r .cache/ compile_commands.json
```

## Extra credit responses

#### 1. What happens when the executable is linked statically? Does Valgrind still detect those same bugs?

By rebuilding the project and re-running Valgrind after enabling static linking in the `app/CMakeLists.txt` file, there are additional errors. If the previous two bugs were not fixed, Valgrind will detect the same bugs in the program in addition to the bugs from libraries after enabling static linking.

#### 2. Why or why not.

Linking the executable statically bakes in the links to the libraries the program relies on. This technically makes the library code to be the part of binary executable on which Valgrind runs its tests on.

If the library code the program relies on contains bugs the library authors are responsible for, they still show up in the actual program since Valgrind cannot differentiate library code from the code written by the programmer due to static linking.

By dynamically linking the libraries, Valgrind could clearly differentiate the library code from the program code and supress the errors from library code. This greatly improves debugging since the errors are now focused on the actual program written by the programmer.
