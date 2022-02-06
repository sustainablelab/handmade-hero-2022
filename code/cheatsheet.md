- `PS> vcvars`
- `PS> w:` (go to SUBST w: drive)
- First time setup:
    - `PS> devenv .\bob.exe` (makes a .sln for you, save the .sln)
    - `F11` (will open `..\code\bob.cpp` and stop execution on first line of code)
    - Options - Debugging - General
        - check the box "Show disassembly if source is not available"
- Existing solution:
    - `PS> devenv` (will open most recent solution)
        - *Tools* -> *Options* -> *Startup* -> *Most Recent Solution*
        - `PS> devenv .\win32_handmade.sln` <--- most recent
        - `PS> devenv .\ex_ptr_alias.sln`
- VisualStudio:
    - **F5** (run)
    - **Shift+F5** (stop)
    - **F10** (step and if its a call step over)
    - **F11** (step and if its a call step in)
    - **Shift+F11** (step out of a call)
    - **F9** (set breakpoint)
    - if disassembly is open, step is by lines of assembly
- `;m<Space>` -- build
- `;mr<Space>` -- build and run (when run from Vim, if QUIT is not coded, use task manager to quit)
- `;Alt<Left-Arrow/Right-Arrow>` -- jump between errors
- `;t<Space>` -- close quickfix window
- `;K` -- DuckDuckGo for WinAPI stuff
- `;cu` -- create tags (needed for omni complete) and cscope database
    - `Win32<C-x><C-o>` -- see all `Win32` functions
    - `;wz` -- close preview window
- useful ctags tricks to inspect code
    - `-x` prints human-readable info to stdout instead of making a tags file
    - List all functions used in `file`:

    ```bash
    ctags  -x  --c-kinds=f  file
    ```

    - List all global variables used in file:

    ```bash
    ctags  -x  --c-kinds=v file
    ```

- `:make lib-tags`
    - updates tags file `lib-tags` based on source dependencies
      of `win32_handmade.cpp` as determined by `cl.exe`
    - example: `WND<C-x><C-o>` -- see all system header defined
      types starting with prefix `WND`
- `PS> cl.exe` -- Microsoft C/C++ Optimizing Compiler Version 19.28 for x64
    - https://docs.microsoft.com/en-us/cpp/build/reference/compiler-options-listed-by-category?view=msvc-160
- `PS> ml64.exe` -- Microsoft Macro Assembler (x64) Version 14.28
    - https://docs.microsoft.com/en-us/cpp/assembler/masm/masm-for-x64-ml64-exe?view=msvc-160
- `;intel` -- open intel assembly instruction reference in browser
    - this is a PDF
    - click the menu (hamburger on top-left) and scroll
    - or search (Ctrl+F) for the instruction and click link in
      PDF table of contents

