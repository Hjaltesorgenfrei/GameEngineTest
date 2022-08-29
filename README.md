# Games programming template

Dependencies to install:

- sdl2
- sdl2-image
- sdl2-mixer
- glew
- lua5.3

## Linux

`yay -S lua53 glew sdl2 sdl2_image sdl2_mixer`

## Windows

`vcpkg integrate install`

`vcpkg install sdl2 sdl2-image sdl2-mixer glew opengl`
VCPKG_DEFAULT_TRIPLET=x64-windows
And compile with: 
`-DCMAKE_TOOLCHAIN_FILE=/path/to/vcpkg/scripts/buildsystems/vcpkg.cmake`
