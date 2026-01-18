# C++ Inheritance Demo

A comprehensive demonstration of C++ inheritance concepts including base classes, derived classes, virtual functions, polymorphism, and proper object lifecycle management.

## 📋 Features

- **Base Class (Animal)**: Abstract base class with virtual and pure virtual functions
- **Derived Classes**: Dog, Cat, and Bird classes demonstrating inheritance
- **Polymorphism**: Runtime polymorphism using virtual functions
- **Smart Pointers**: Modern C++ memory management with `std::unique_ptr`
- **Cross-Platform**: Works on Windows 11 and Ubuntu 24 (and other Linux distributions)
- **Professional Structure**: One class per file following "do one thing well" principle

## 💡 Why One Class Per File?

While it's technically possible to put all classes in a single file, this project follows modern C++ best practices by separating each class into its own header and implementation files. This approach:

- **Enables side-by-side editing**: Work on multiple classes simultaneously in split view
- **Follows "do one thing well"**: Each file has a single, clear responsibility
- **Improves compilation speed**: Only modified files need recompilation
- **Facilitates code review**: Changes to one class don't clutter diffs with unrelated code
- **Enhances reusability**: Import individual classes into other projects without dependencies
- **Supports team collaboration**: Multiple developers can work on different classes without merge conflicts

## 🛠️ Environment Setup

### Linux (Ubuntu 24.04)

#### Prerequisites

You need a C++ compiler, CMake build system, and GDB debugger.

#### Installation Steps

1. **Update package list:**
   ```bash
   sudo apt update
   ```

2. **Install build tools:**
   ```bash
   sudo apt install -y build-essential cmake gdb
   ```
   
   This installs:
   - `build-essential`: GCC compiler, G++, and make
   - `cmake`: Cross-platform build system
   - `gdb`: GNU debugger for debugging

3. **Verify installation:**
   ```bash
   g++ --version      # Should show GCC 13.x or later
   cmake --version    # Should show 3.20 or later
   gdb --version      # Should show GDB 15.x or later
   ```

#### VSCode Configuration

- The project includes a `launch.json` with **(gdb) Launch - Linux** configuration
- This uses GDB for debugging
- Build tasks are pre-configured in `tasks.json`

---

### Windows 11

#### Prerequisites

You need a C++ compiler, CMake, and a debugger. Windows has multiple options.

#### Option 1: Visual Studio (Recommended)

**Best for:** Most users, especially those new to C++ on Windows

1. **Download Visual Studio:**
   - Go to [Visual Studio 2022 Downloads](https://visualstudio.microsoft.com/downloads/)
   - Download Community Edition (free)

2. **During installation, select:**
   - ✅ **Desktop development with C++**
   - ✅ **CMake tools for Windows**
   - ✅ **Windows SDK** (usually selected by default)

3. **Verify installation:**
   Open "Developer Command Prompt for VS 2022" and run:
   ```cmd
   cl           REM Microsoft C++ compiler
   cmake --version
   ```

#### VSCode Configuration
- Use the **(Windows) MSVC Launch** configuration in `launch.json`
- This uses the Visual Studio debugger (`cppvsdbg`)

---

#### Option 2: MinGW-w64 + GDB

**Best for:** Those who prefer GCC/GDB or need compatibility with Linux tooling

1. **Install MSYS2:**
   - Download from [msys2.org](https://www.msys2.org/)
   - Run installer with default settings

2. **Install toolchain:**
   Open "MSYS2 MINGW64" terminal and run:
   ```bash
   pacman -S mingw-w64-x86_64-gcc mingw-w64-x86_64-cmake mingw-w64-x86_64-gdb mingw-w64-x86_64-make
   ```

3. **Add to Windows PATH:**
   - Open "Environment Variables" in Windows Settings
   - Add to System PATH: `C:\msys64\mingw64\bin`
   - Restart VSCode/terminals

4. **Verify installation:**
   Open Command Prompt or PowerShell:
   ```bash
   g++ --version
   cmake --version
   gdb --version
   ```

#### VSCode Configuration
- Use the **(Windows) GDB Launch** configuration in `launch.json`
- This uses GDB for debugging

---

#### Option 3: Chocolatey Package Manager

**Best for:** Those comfortable with command-line package management

1. **Install Chocolatey:**
   - Open PowerShell as Administrator
   - Follow instructions at [chocolatey.org/install](https://chocolatey.org/install)

2. **Install tools:**
   ```powershell
   choco install cmake --installargs 'ADD_CMAKE_TO_PATH=System'
   choco install mingw
   ```

3. **Verify installation:**
   ```powershell
   g++ --version
   cmake --version
   gdb --version
   ```

#### VSCode Configuration
- Use the **(Windows) GDB Launch** configuration in `launch.json`

## 🔧 VSCode Extensions

Install these extensions for the best experience:

1. **C/C++** (ms-vscode.cpptools) - IntelliSense, debugging
2. **CMake Tools** (ms-vscode.cmake-tools) - CMake integration
3. **CMake** (twxs.cmake) - CMakeLists.txt language support

Install via command:
```bash
code --install-extension ms-vscode.cpptools
code --install-extension ms-vscode.cmake-tools
code --install-extension twxs.cmake
```

## 🚀 Building the Project

### Using VSCode (Recommended)

1. Open the project folder in VSCode
2. CMake should auto-configure (if not, press `Ctrl+Shift+P` → "CMake: Configure")
3. Build using:
   - Press `Ctrl+Shift+B` (default build task), or
   - Press `Ctrl+Shift+P` → "CMake: Build", or
   - Click "Build" in the CMake status bar

### Using Command Line

**Linux/macOS:**
```bash
# Configure
cmake -B build -S . -DCMAKE_BUILD_TYPE=Debug

# Build
cmake --build build --config Debug

# Run
./build/inheritance_demo
```

**Windows (Command Prompt):**
```cmd
REM Configure
cmake -B build -S . -DCMAKE_BUILD_TYPE=Debug

REM Build
cmake --build build --config Debug

REM Run
build\Debug\inheritance_demo.exe
```

**Windows (PowerShell):**
```powershell
# Configure
cmake -B build -S . -DCMAKE_BUILD_TYPE=Debug

# Build
cmake --build build --config Debug

# Run
.\build\Debug\inheritance_demo.exe
```

## 🐛 Debugging in VSCode

### Linux (Ubuntu 24)

1. Open [main.cpp](main.cpp)
2. Set breakpoints by clicking left of line numbers
3. Press `F5` or select "Run → Start Debugging"
4. Choose "**(gdb) Launch - Linux**" configuration
5. Program will build automatically and start debugging

### Windows 11

1. Open [main.cpp](main.cpp)
2. Set breakpoints
3. Press `F5` or select "Run → Start Debugging"
4. Choose configuration:
   - **Visual Studio**: Select "**(Windows) MSVC Launch**"
   - **MinGW/GDB**: Select "**(Windows) GDB Launch**"
5. Program will build and start debugging

### Debug Features Available

- **Step Over** (`F10`): Execute current line
- **Step Into** (`F11`): Enter function calls
- **Step Out** (`Shift+F11`): Exit current function
- **Continue** (`F5`): Run until next breakpoint
- **Variables Panel**: Inspect variable values
- **Call Stack**: View function call hierarchy
- **Watch**: Monitor specific expressions

## 📁 Project Structure

```
cpp_inheritance_demo/
├── main.cpp              # Main source with inheritance demo
├── CMakeLists.txt        # Cross-platform build configuration
├── .vscode/
│   ├── launch.json       # Debug configurations
│   ├── tasks.json        # Build tasks
│   └── settings.json     # VSCode settings
└── README.md             # This file
```

## 🎓 Code Concepts Demonstrated

### 1. **Base Class & Virtual Functions**
```cpp
class Animal {
    virtual void makeSound() const;      // Virtual function
    virtual std::string getType() const = 0;  // Pure virtual (abstract)
};
```

### 2. **Inheritance**
```cpp
class Dog : public Animal {
    // Inherits from Animal
};
```

### 3. **Function Overriding**
```cpp
void makeSound() const override {
    std::cout << "Woof! Woof!" << std::endl;
}
```

### 4. **Polymorphism**
```cpp
std::unique_ptr<Animal> animal = std::make_unique<Dog>("Buddy", 3, "Golden");
animal->makeSound();  // Calls Dog's version due to polymorphism
```

### 5. **Smart Pointers**
```cpp
std::vector<std::unique_ptr<Animal>> animals;
animals.push_back(std::make_unique<Dog>(...));
// Automatic memory management, no manual delete needed
```

## 🔍 Expected Output

```
=== C++ Inheritance Demo ===

1. Creating objects...

Animal constructor: Buddy
Dog constructor: Buddy
Animal constructor: Whiskers
Cat constructor: Whiskers
Animal constructor: Tweety
Bird constructor: Tweety

2. Calling member functions...

I am Buddy, a 3 year old Dog (Golden Retriever)
Buddy says: Woof! Woof!
Buddy is fetching the ball!

I am Whiskers, a 2 year old Indoor Cat
Whiskers says: Meow! Meow!
Whiskers is climbing the tree!

I am Tweety, a 1 year old Bird (wingspan: 0.300000m)
Tweety says: Chirp! Chirp!
Tweety is flying with a wingspan of 0.3 meters!

3. Demonstrating polymorphism...
[... polymorphism examples ...]

5. Objects going out of scope...
[... destructor calls in reverse order ...]
```

## 🛟 Troubleshooting

### CMake not found
- **Linux**: `sudo apt install cmake`
- **Windows**: Ensure CMake is in your PATH

### Compiler not found
- **Linux**: `sudo apt install build-essential`
- **Windows**: Install Visual Studio or MinGW-w64

### GDB not found (Linux)
```bash
sudo apt install gdb
```

### Cannot debug (Windows with MinGW)
- Ensure `gdb.exe` is in your PATH
- Check the `miDebuggerPath` in [.vscode/launch.json](.vscode/launch.json)

### Build fails on Windows
- Try using "Developer Command Prompt for VS 2022"
- Or ensure MinGW's `bin` directory is in PATH

## 📚 Learning Resources

- [C++ Inheritance](https://en.cppreference.com/w/cpp/language/derived_class)
- [Virtual Functions](https://en.cppreference.com/w/cpp/language/virtual)
- [Smart Pointers](https://en.cppreference.com/w/cpp/memory)
- [CMake Documentation](https://cmake.org/documentation/)

## 📝 License

This is a demonstration project for educational purposes. Feel free to use and modify as needed.

## 🤝 Contributing

This is a demo project, but suggestions for improvements are welcome!

---

**Happy Coding! 🚀**
