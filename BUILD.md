# Build Instructions for VICE SYNDICATE

## Prerequisites

### Windows
- Visual Studio 2022 (with C++ support) or MinGW
- CMake 3.20+
- OpenGL 4.5+

### macOS
```bash
brew install cmake opengl glfw3 glew glm
```

### Linux (Ubuntu/Debian)
```bash
sudo apt-get install build-essential cmake libglfw3-dev libglew-dev libglm-dev libassimp-dev
```

### Linux (Fedora/RHEL)
```bash
sudo dnf install gcc-c++ cmake glfw-devel glew-devel glm-devel assimp-devel
```

## Build Steps

### 1. Clone the Repository
```bash
git clone https://github.com/OFFICIALSCOTT/VICE-SYNDICATE.git
cd VICE-SYNDICATE
git checkout dev/core-architecture
```

### 2. Create Build Directory
```bash
mkdir build
cd build
```

### 3. Configure with CMake
```bash
# Standard release build
cmake .. -DCMAKE_BUILD_TYPE=Release

# Or for debug build (with debugging symbols)
cmake .. -DCMAKE_BUILD_TYPE=Debug

# On Windows with Visual Studio
cmake .. -G "Visual Studio 17 2022"
```

### 4. Build
```bash
# Unix/Linux/macOS
cmake --build . --config Release -j$(nproc)

# Windows
cmake --build . --config Release --parallel 8

# Or use make on Unix systems
make -j$(nproc)
```

### 5. Run the Game
```bash
# Unix/Linux/macOS
./bin/ViceSyndicate

# Windows
.\bin\ViceSyndicate.exe
```

## Advanced Build Options

### Build with Debugging
```bash
cmake .. -DCMAKE_BUILD_TYPE=Debug
cmake --build . --config Debug
```

### Build with Optimizations
```bash
cmake .. -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_FLAGS_RELEASE="-O3 -march=native"
cmake --build . --config Release
```

### Generate IDE Project Files
```bash
# Visual Studio
cmake .. -G "Visual Studio 17 2022"

# Xcode
cmake .. -G "Xcode"

# Code::Blocks
cmake .. -G "CodeBlocks - Unix Makefiles"
```

## Troubleshooting

### CMake not found
- Install CMake from: https://cmake.org/download/
- Or use package manager (apt, brew, choco, etc.)

### OpenGL not found
- Windows: Ensure graphics drivers are updated
- Linux: `sudo apt-get install libgl1-mesa-dev`
- macOS: Should be included with Xcode

### GLFW/GLEW not found
- Install through package manager or vcpkg
- Or build from source: 
  - GLFW: https://github.com/glfw/glfw
  - GLEW: https://github.com/nigels-com/glew

### Compiler errors
- Ensure C++20 support in your compiler
- Update your compiler to the latest version
- Check the CMakeLists.txt for specific compiler requirements

## CI/CD Integration

### GitHub Actions Example
See `.github/workflows/build.yml` for automatic build and test workflows

## Performance Tips

1. **Enable LTO (Link Time Optimization)**
   ```bash
   cmake .. -DCMAKE_INTERPROCEDURAL_OPTIMIZATION=ON
   ```

2. **Optimize for your CPU**
   ```bash
   cmake .. -DCMAKE_CXX_FLAGS="-march=native -O3"
   ```

3. **Use ninja for faster builds**
   ```bash
   cmake .. -G Ninja
   cmake --build . --config Release
   ```

## Development Workflow

### Recommended for active development:
```bash
# Create build directory for development
mkdir build-dev
cd build-dev
cmake .. -DCMAKE_BUILD_TYPE=Debug
cmake --build .

# Run with debugger
gdb ./bin/ViceSyndicate
# or
lldb ./bin/ViceSyndicate
# or
Code with IDE debugger
```

---

**Last Updated**: 2026-05-04
**Tested On**: Linux, macOS, Windows
