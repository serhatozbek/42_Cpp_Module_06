# C++ Module 06 — 42 Piscine

Type conversion, pointer reinterpretation, and RTTI. Three progressive exercises exploring type system manipulation.

| Ex | Class | Concept |
|---|---|---|
| ex00 | `ScalarConverter` | Implicit/explicit conversions, pseudo-destructors |
| ex01 | `Serializer` | `reinterpret_cast`, pointer serialization |
| ex02 | `A`, `B`, `C` | Inheritance, `dynamic_cast`, RTTI |

**Outcomes:**
- `reinterpret_cast` for raw pointer/bit manipulation
- `dynamic_cast` for safe downcast at runtime
- Type identification without virtual functions
- Template pseudo-destructor calls
- String-to-type conversion edge cases

## Build

```bash
cd cpp06/ex00 && make && ./convert "42"
```

---

⚠️ **Disclaimer**
This repository contains personal solutions to 42 C++ Piscine exercises for educational and portfolio purposes only. Per 42's honour code, students in the Common Core must write their own solutions without copying. These codes are shared to demonstrate completed work and serve as a reference for future projects.
