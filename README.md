Follow along with Handmade Hero on Windows, but using Cygwin,
Vim, and `make` instead of Emacs and the `.bat` script.

The only reason to use Cygwin instead of MinGW is that Cygwin has
a working version of `cscope` and MinGW does not.

I love that MinGW lets me write native Windows executables
without having to look at the Win32 API. But in this instance, I
don't need MinGW to hide the Win32 API from me. Casey shows how
to use the Win32 API.

So there is no advantage to using MinGW because I don't need to
run `gcc` from MinGW to get my native Windows executable.
Instead, I'll be using the `MSVC` toolchain when I build on
Windows.

## ToC

- [Day 1](doc/day001.md) - setup to build with MSVC toolchain and
  to use VisualStudio as my debugger
