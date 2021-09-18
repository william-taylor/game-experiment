
# Game Experiment

```
# Install dependencies
conan install . -s build_type=Debug

# Create temp directory
mkdir build && cd build

# Generate
cmake ../

# Build
cmake --build . --target ALL_BUILD --config Debug

# Install
cmake --build . --target install --config Debug
```