# BSP - Binary Space Partition Triangle Point Localization

A geometric algorithm implementation in C++ that determines whether a point lies strictly inside a triangle using the barycentric coordinate method based on area calculations.

> **⭐ 100% C++98 Compliant**
> 
> High-precision fixed-point arithmetic with complete operator overloading

## 📋 Description

**BSP** is a geometric computation engine that solves the point-in-triangle problem using area-based barycentric coordinates. The project implements:

### Core Features ✅
- **Point-in-triangle algorithm** - BSP using area calculations
- **Fixed-point arithmetic** - 8 fractional bits for precise calculations
- **2D Point class** - Immutable coordinates with const correctness
- **Operator overloading** - All arithmetic, comparison, and assignment operators
- **Shoelace formula** - Geometric area calculation for triangles
- **C++98 standard** - No modern C++ features, strict compilation flags

## 🚀 Compilation

```bash
make          # Compile the project
make clean    # Remove object files
make fclean   # Remove everything including binary
make re       # Recompile from scratch
```

### Requirements

**Linux (Ubuntu/Debian):**
```bash
g++ compiler with C++98 support
Standard C++ library (STL)
```

**macOS:**
```bash
clang++ compiler with C++98 support
Standard C++ library
```

## 💻 Usage

```bash
./bsp
```

The program runs predefined test cases checking if points are:
- **Strictly inside** the triangle
- **Outside** the triangle
- **On edge** of the triangle
- **On vertex** of the triangle

## 🧠 Algorithm: Binary Space Partition (BSP)

### Mathematical Approach

The BSP algorithm determines if a point P lies **strictly inside** triangle ABC using area comparisons:

1. **Calculate the main triangle area**: `area(A, B, C)` = d0
2. **Calculate sub-triangle areas**:
   - `area(P, A, B)` = d1
   - `area(P, B, C)` = d2
   - `area(P, C, A)` = d3
3. **Validation logic**:
   - If any area = 0 → point is on edge/vertex → **return false**
   - If d0 ≠ d1 + d2 + d3 → point is outside → **return false**
   - Otherwise → point is strictly inside → **return true**

### Shoelace Formula

For triangle with vertices A(x₁, y₁), B(x₂, y₂), C(x₃, y₃):

```
Area = |x₁(y₂ - y₃) + x₂(y₃ - y₁) + x₃(y₁ - y₂)| / 2
```

This formula efficiently computes signed area, allowing detection of collinear points.

## 📚 Core Classes

### `Fixed` Class
Represents fixed-point numbers with **8 fractional bits** for precise decimal calculations without floating-point errors.

**Features:**
- Constructors for int/float/copy conversion
- Comparison operators: `>`, `<`, `>=`, `<=`, `==`, `!=`
- Arithmetic operators: `+`, `-`, `*`, `/`
- Increment/Decrement: `++`, `--` (prefix & postfix)
- Methods: `getRawBits()`, `setRawBits()`, `toFloat()`, `toInt()`
- Static methods: `min()`, `max()` for both const and non-const references
- Stream operator: `operator<<` for output

### `Point` Class
Represents an immutable 2D point with **const** Fixed-point coordinates.

**Features:**
- Constructors: default, parametrized (float x, float y), copy
- Methods: `getX()`, `getY()` return Fixed values
- Operators: assignment `=`, inequality `!=`
- **Key**: Coordinates are const → prevents modification after creation

### `bsp()` Function

```cpp
bool bsp(Point const a, Point const b, Point const c, Point const point);
```

**Purpose:** Determines if `point` is strictly inside triangle `abc`

**Parameters:**
- `a`, `b`, `c` - Triangle vertices
- `point` - Test point

**Returns:**
- `true` - Point is strictly inside the triangle
- `false` - Point is on edge, vertex, or outside

**Example:**
```cpp
Point const a(0.0f, 0.0f);
Point const b(10.0f, 0.0f);
Point const c(5.0f, 10.0f);
Point const p(5.0f, 5.0f);

if (bsp(a, b, c, p))
    std::cout << "Point is inside!" << std::endl;
```

## 📁 Project Structure

```
BSP/
├── Makefile                 # Build configuration
├── README.md                # This file
│
├── includes/
│   ├── Fixed.hpp           # Fixed-point class header
│   └── Point.hpp           # 2D Point class header
│
└── srcs/
    ├── main.cpp            # Test program & demo
    ├── Fixed.cpp           # Fixed-point implementation
    ├── Point.cpp           # Point class implementation
    └── bsp.cpp             # BSP algorithm implementation
```

## 🧪 Test Cases

The main program includes comprehensive test coverage:

```cpp
// Define triangle ABC
Point const a(0.0f, 0.0f);     // Bottom-left vertex
Point const b(10.0f, 0.0f);    // Bottom-right vertex
Point const c(5.0f, 10.0f);    // Top vertex

// Test cases
Point const inside(5.0f, 5.0f);      // Inside: true
Point const outside(15.0f, 5.0f);    // Outside: false
Point const onEdge(5.0f, 0.0f);      // On edge: false
Point const onVertex(0.0f, 0.0f);    // On vertex: false
```

## 🔧 Implementation Details

### Fixed-Point Arithmetic

**8 Fractional Bits:**
- Stores numbers as integers with implicit decimal point
- Range: approximately -8,388,608.00390625 to 8,388,607.99609375
- Precision: 1/256 = 0.00390625

**Conversion:**
```cpp
// Int to Fixed: multiply by 2^8 = 256
Fixed f(42);  // Stored as 42 * 256 = 10752

// Float to Fixed: multiply by 2^8, then convert to int
Fixed f(3.14f);  // Stored as (int)(3.14f * 256) = 803

// Back to float: divide by 2^8
float val = fixed.toFloat();  // 803 / 256.0f = 3.1367...
```

### Const Correctness

**Immutable Points:**
```cpp
Point p(1.0f, 2.0f);
// p.p_x and p.p_y are const
// Cannot be modified after construction
// Ensures geometric integrity
```

**Benefits:**
- Prevents accidental point mutations
- Enables compiler optimizations
- Makes code intent clear
- Thread-safe operations

### Area Calculation Precision

The Shoelace formula is numerically stable even with:
- Very small triangles (high precision needed)
- Degenerate triangles (area ≈ 0)
- Collinear points (detectable via zero area)

Using Fixed-point avoids floating-point rounding errors.

## 📊 Technical Specifications

### Compilation Flags

```makefile
-Wall           # Enable all standard warnings
-Wextra         # Enable extra warnings
-Werror         # Treat warnings as errors
-std=c++98      # C++98 standard (no C++11 or later)
```

### Complexity Analysis

- **Time Complexity**: O(1) per query (constant 4 area calculations)
- **Space Complexity**: O(1) (stores only triangle + point)

### Numerical Stability

- **Fixed-point arithmetic** eliminates floating-point rounding errors
- **Area-based method** avoids division operations in comparison
- **Shoelace formula** is mathematically proven for polygon area

## 🎓 Educational Value

This project demonstrates:

✅ **Object-Oriented Design** - Class hierarchy and encapsulation
✅ **Operator Overloading** - All C++ operator categories
✅ **Fixed-Point Arithmetic** - Alternative to floating-point
✅ **Geometric Algorithms** - Mathematical computational geometry
✅ **Const Correctness** - Proper use of const in C++
✅ **Template Concepts** - Min/max static methods
✅ **Memory Management** - Stack allocation, RAII principles
✅ **Input Validation** - Robust edge case handling
✅ **Code Quality** - Clean, well-documented C++ code
✅ **Build System** - Professional Makefile configuration

## 🚀 Performance

- **Initialization**: O(n) for n Fixed-point constructions
- **BSP Query**: O(1) - constant time geometric test
- **Memory**: ~100 bytes per test (negligible for geometric algorithms)

## 📝 Example Usage

```cpp
#include "Point.hpp"

int main(void)
{
    // Create triangle
    Point const vertex_a(0.0f, 0.0f);
    Point const vertex_b(100.0f, 0.0f);
    Point const vertex_c(50.0f, 100.0f);
    
    // Test various points
    Point const test_point(50.0f, 50.0f);
    
    // Query BSP
    if (bsp(vertex_a, vertex_b, vertex_c, test_point))
        std::cout << "Inside triangle" << std::endl;
    else
        std::cout << "Outside or on boundary" << std::endl;
    
    return 0;
}
```

## 🔍 Edge Cases Handled

| Case | Input | Output | Reason |
|------|-------|--------|--------|
| Inside triangle | Point in interior | `true` | All area conditions met |
| Outside triangle | Point beyond boundary | `false` | Sum of sub-areas ≠ main area |
| On triangle edge | Point on side AB | `false` | One sub-area = 0 |
| On vertex | Point at corner A | `false` | Two sub-areas = 0 |
| Degenerate triangle | Collinear vertices | Undefined | Area = 0 (handled gracefully) |

## 👤 Author

[@itaharbo91](https://github.com/itaharbo91)

---

**GitHub Description**: Geometric algorithm in C++98 implementing Binary Space Partition (point-in-triangle test) using fixed-point arithmetic. Features immutable const-correct 2D points with complete operator overloading and barycentric coordinate validation.