# Nephilim


### Getting Started
    Follow the necessary steps depending on platform.

## Windows

1. Install CMake for Windows. I used the MSI on their [website](https://cmake.org/download/).

2. Download the Visual Studio Installer. We will only be installing the Visual Studio Build Tools. [Here](https://visualstudio.microsoft.com/downloads/). Select the Community Edition.

3. After a lengthy update process of the Visual Studio Installer, Install the Build tools. Select the "C++ build tools" and "Universal Windows Platform build tools" box. Ensure the Windows SDK and C++ MSVC tools are installed.

4. You may need to restart your machine.

5. If you haven't already installed VSCode, install it now. There are a few main extensions that I use. Be careful not to have more than one C/C++ intellisense extension installed and running on your workspace. below is the extensions list I'm using.
    - [C/C++ by Microsoft](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools)
    - (Optional)[Better Comments](https://marketplace.visualstudio.com/items?itemName=aaron-bond.better-comments)
    - [CMake Tools](https://marketplace.visualstudio.com/items?itemName=vector-of-bool.cmake-tools)
    - [CMake Integration](https://marketplace.visualstudio.com/items?itemName=go2sh.cmake-integration-vscode)
    - (Optional) [CMake file autocomplete](https://marketplace.visualstudio.com/items?itemName=twxs.cmake)

6. Once you clone this project and open it in VSCode. The CMake extensions should ask you to auto configure. I would highly recommend this.

7. Create a file in the .vscode folder `c_cpp_properties.json`. And include the contents below. I think if you have a different version of the tools it will install the version in the c_cpp_properties.json file below on your local machine. If not you may need to edit the version below that you actually have.

```
{
    "configurations": [
        {
            "name": "Win32",
            "includePath": [
                "${workspaceFolder}/**",
                "C:\\Program Files (x86)\\Microsoft Visual Studio\\2019\\BuildTools\\VC\\Tools\\MSVC\\14.22.27905\\include"
            ],
            "defines": [
                "_DEBUG",
                "UNICODE",
                "_UNICODE"
            ],
            "windowsSdkVersion": "10.0.17763.0",
            "compilerPath": "C:\\Program Files (x86)\\Microsoft Visual Studio\\2019\\BuildTools\\VC\\Tools\\MSVC\\14.222.27905\\bin\\Hostx64\\x64\\cl.exe",
            "cStandard": "c11",
            "cppStandard": "c++17",
            "intelliSenseMode": "msvc-x64",
            "compileCommands": "${workspaceFolder}/build/compile_commands.json",
            "configurationProvider": "go2sh.cmake-integration"
        }
    ],
    "version": 4
}
```

7. Assuming no issues, you should be able to open your command pallette [Ctrl + Shift + P] and use `CMake: Build` or `CMake: Debug Target` with no problems! Be sure to set the main target on the CMake extension if you plan on using that. I can set up a build and launch.json later, but for now the best way to actually run this would be to navigate to the build directory and run neph.exe.

(note: small issue is if you debug target in cmake its running in the root directory which does not have the image to load, so it will have an error)

## Feel Free to add the steps for other systems.
- may require cmakelists changes.
