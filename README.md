
## Building Demos

```
# Install dependencies
conan install . -s build_type=Debug

# Create temp directory
mkdir build && cd build

# Generate
cmake ../

# Build 
cmake --build . --target (ALL_BUILD|all) --config Debug

# Install
cmake --build . --target install --config Debug
```

## Building Docs

```
# Goto docs
cd docs

# Install Ruby dependencies
bundle install

# Serve static files
bundle exec jekyll serve
```