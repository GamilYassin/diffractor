# Building Diffractor

## Overview
Diffractor is a high-performance photo and video organizer for Windows, built with C++ and Direct3D 11. It provides fast media indexing, duplicate detection, and advanced search capabilities.

## System Requirements

### Development Environment
- Windows 10/11 64-bit
- Visual Studio 2022
- Git
- CMake (for some third-party dependencies)

### Required Dependencies
The project uses several third-party libraries that are managed through submodules and the build system:

#### Core Libraries
- FFmpeg (video processing)
- XMP Toolkit SDK (metadata handling)
- LibRaw (RAW image support)
- SQLite (database)
- Various image format libraries (WebP, HEIF, JPEG, PNG)

## Build Instructions

### 1. Clone the Repository
```bash
# Clone the main repository with submodules
git clone --recursive https://github.com/diffractor/diffractor.git
cd diffractor

# If you forgot --recursive, you can initialize submodules later with:
git submodule update --init --recursive
```

### 2. Build Dependencies
The project includes several third-party libraries that need to be built first. Most dependencies are handled automatically through the build system.

### 3. Open and Build Solution
1. Open `df.sln` in Visual Studio 2022
2. Select your desired build configuration (Debug/Release)
3. Build the solution (F7 or Build → Build Solution)

### 4. Running Tests
Diffractor includes a built-in test suite:
1. Start the application from Visual Studio
2. Look for the checkmark button in the top-left toolbar
3. Click it to access the test run menu
4. Press ESC to return to normal application mode

### 5. Adding Languages
Diffractor supports multiple languages through PO files:
1. Locate the language files in `exe/languages/`
2. Use [Poedit](https://poedit.net/) to create or edit translations
3. Base new translations on the German language file
4. Place new language files in: `C:\Users\[USER]\AppData\Local\Diffractor\languages`

## Project Structure

### Key Directories
- `/src` - Main source code
- `/third-party` - Third-party dependencies
- `/tools` - Build and development tools
- `/exe` - Output directory and resources
- `/installer` - Installation package resources

### Core Components
- Image Processing (`files_*.cpp`)
- Metadata Handling (`metadata_*.cpp`)
- UI Components (`ui_*.cpp`, `ui_*.h`)
- Database/Model Layer (`model_*.cpp`, `model_*.h`)
- Platform-specific Code (`platform_win_*.cpp`)

## Troubleshooting

### Common Build Issues
1. **Submodule Issues**
   - Ensure all submodules are properly initialized
   - Run `git submodule update --init --recursive`

2. **Missing Dependencies**
   - Check that Visual Studio has all required workloads installed
   - Verify that third-party libraries are properly built

3. **Compilation Errors**
   - Ensure you're using a compatible Visual Studio version
   - Check that all required Windows SDKs are installed

## Contributing
1. Fork the repository
2. Create a feature branch
3. Make your changes
4. Run the test suite
5. Submit a pull request

For more details on contributing, please see the main [README.md](README.md).
