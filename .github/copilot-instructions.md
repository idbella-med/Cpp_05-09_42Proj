# Project Guidelines

## Code Style
- Follow the existing 42 C++98 style used throughout the exercise folders.
- Compile with `c++ -Wall -Wextra -Werror -std=c++98`; avoid newer language features unless the surrounding code already uses them.
- Keep class names, file names, include guards, and method signatures aligned with the neighboring files in the same exercise.

## Build and Test
- Build each exercise from its own directory with `make`.
- Use `clean`, `fclean`, and `re` for cleanup and rebuilds.
- Treat the exercise-local `main.cpp` files as the primary validation entry points.

## Conventions
- Each exercise directory is self-contained; do not introduce shared build machinery unless the repository already does so.
- Match the existing source layout and error-handling patterns in the module you are editing.
