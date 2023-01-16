# Arm Cortex-M4 Base Project

Example Workspace für die Vorlesung Systemnahe Programmierung 2 an der
DHWB Ravensburg.

## Arm Documentation
 - [Cortex M4 Startseite](https://developer.arm.com/Processors/Cortex-M4)
   - [ARMv7-M Architecture Reference Manual](https://developer.arm.com/documentation/ddi0403/latest/)
   - [Cortex-M4 Devices Generic User Guide](https://developer.arm.com/documentation/dui0553/b/?lang=en)
   - [Arm Cortex-M4 Processor Technical Reference Manual Revision r0p1](https://developer.arm.com/documentation/100166/0001/?lang=en)
 - [Arm Application Binary Interface](https://github.com/ARM-software/abi-aa)
 - [GNU Assembler Documentation](https://sourceware.org/binutils/docs-2.40/as/index.html)
 - [GNU Linker Documentation](https://sourceware.org/binutils/docs-2.40/ld/index.html)

## Prerequisites
 - CMake
 - Arm GCC Cross-Compiler
 - Wind River Simics

### Windows
Installation von CMake über Download des Installers (https://cmake.org/download/)
oder Paketmanager `winget install CMake.CMake`.

Installation der ARM GCC Toolchain [Website](https://gnutoolchains.com/arm-eabi/)
Nach z.B. C:\Toolchains\
**WICHTIG:** zu PATH hinzufügen (lassen)

### Linux
Über Paketmanager Installieren:

**Ubuntu/ Debian**: ```sudo apt install gcc-arm-none-eabi cmake```

**Arch**:
```
yay -S gcc-arm-none-eabi-bin 
sudo pacman -S cmake
```

**macOS**: ```brew install gcc-arm-embedded```

## Building
Auschecken des Quellcodes:
`git clone https://github.com/infohoschie/Arm-Cortex-M4-Base.git`

Erstellen des Build:
 - Mittels CMake Presets:
   ```cmake --preset arm-cortex-m4```
 - Klassisch:
   ```cmake -B build -S . -DCMAKE_BUILD_TYPE=Debug -DCMAKE_TOOLCHAIN_FILE=toolchain.cmake```

Bauen:
 - Mittels CMake Presets:
  ```cmake --build --preset arm-cortex-m4```
 - Klassisch:
   ```cmake --build build```
 
## Running in Wind River Simics
Install Wind River Simics (Currently only for Windows and Linux available)

**Note**
For Linux installation assure, that I386 Support is available, e.g. for 
Ubuntu/ Debian: ```sudo dpkg --add-architecture i386```

Propagate the License Server via environment variable:
```SIMICS_LICENSE_FILE=27000@wrs-lizenz.inf.dhbw-ravensburg.de```

Start Simics, e.g. via command-line:
```<SIMICS_INSTALL>/bin/simics6_22_12/simics-6/simics-6.0.154/bin/simics-eclipse```
Create Simics Workspace

Create Simics Project: File -> New -> Simics Project

Via Tab *Simics Control* create new *Simics Session*.
Select *Target System*: *arm-cortex-m4-ref - cortex-m4-ref-helloworld*
Modify *Parameters*: *Runtime* -> *demo_image* set to built binary
Select *Start as debug session*

## IDEs
### Jetbrains CLion
Das Projekt kann direkt in der IDE geöffnet (ausgechecked) werden.
Die CMake Presets werden direkt als build-target angeboten

### Visual Studio Code
TODO:
 - [ ] Plugins
 - [ ] Configuration
