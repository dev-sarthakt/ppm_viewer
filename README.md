# PPM Image Viewer (C++ / SDL)

This project is a lightweight PPM (Portable Pixmap) image viewer written in C++, using SDL for window creation and pixel display. It is designed as a learning-focused tool that demonstrates low-level image parsing, raw pixel manipulation, and software rendering concepts.

The viewer supports ASCII PPM (P3) images and reads pixel data directly from a file, making it compatible with Unix pipelines (e.g. less/cat image.ppm | ./iv). Each pixel’s RGB values are mapped manually to the framebuffer and rendered to the screen without relying on high-level graphics abstractions.

A command-line flag allows optional portrait (rotated) rendering, showcasing coordinate transformation and basic image rotation logic. The project intentionally avoids external image libraries to emphasize understanding of file formats, memory layout, and pixel-level rendering.


# Features

Parses P3 PPM image format

Reads input from file

Direct per-pixel RGB rendering

Optional portrait / rotated display mode

Minimal dependencies (SDL only)

Cross-platform


# Purpose

This project is meant to deepen understanding of:

C/C++ file I/O and parsing

Command-line argument handling (argc / argv)

Software rendering pipelines

Image coordinate systems and transformations

Interaction between CPU-side buffers and display APIs


# Build

### Fedora
```bash
sudo dnf install SDL3-devel -y
g++ -std=gnu++26 iv.cpp $(pkg-config --cflags --libs sdl3) -o iv.out
```


# Run

### Landscape
```bash
less file.ppm | ./iv.out
```

### Portrait
```
less file.ppm | ./iv.out -p
```
