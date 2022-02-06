# https://docs.microsoft.com/en-us/cpp/build/reference/compiler-options-listed-by-category?view=msvc-160
# /Zi -- generate debug symbols and put them in a .pdb file
# /FC -- display full path of source code files in compiler messages
# /Fe -- name and directory for .exe output by compiler
# /Fa -- generate assembly
# /c  -- compile without linking
# /Od -- disable optimization
CFLAGS = /Zi
# IMPORTLIBS = user32.lib gdi32.lib
IMPORTLIBS =

.PHONY: ..\build\win32_handmade.exe
..\build\win32_handmade.exe: win32_handmade.cpp
	cl.exe $(CFLAGS) $(IMPORTLIBS) $< /Fe"$@"


.PHONY: lib-tags
lib-tags: win32_handmade.cpp
	cl.exe /c /sourceDependencies lib-tags.json $<
	rm win32_handmade.obj
	python.exe parse-lib-tags-json.py
	rm lib-tags.json
	ctags -f lib-tags --c-kinds=+p -L lib-tags.txt
	rm lib-tags.txt

.PHONY: clean
clean:
	rm -f ../build/*.exe ../build/*.obj ../build/*.pdb ../build/*.ilk
