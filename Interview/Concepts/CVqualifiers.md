# CV(const and volatile) type qualifiers

## volatile

Tell compiler should not optimize the access to an object.

- Only constraint compiler
- Do not guarateen full memory barrier in CPU level
- Do not guarateen multithreads synchronous
- No atomicity(done it or never do it)

### Scenarios

- Mutilple threads sharing segement and always be modified
- Interrupt service program and hardware access situation

