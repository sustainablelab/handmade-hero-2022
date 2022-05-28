#include <windows.h>

// How I can do structs?

// Can do this
struct foo
{
    int x;
};
struct foo Foo; // <-- Now I have a Foo that is a foo struct.

// Can do this too. It a shorted form of the above.
struct goo
{
    int x;
} Goo; // <-- Now I have a Goo that is a goo struct.

// Can also do this.
struct poo
{
    int x;
}; // <-- I have nothing yet, just a struct data type.
//   The thing      The new type name
//      ┌────┴───┐ ┌┴┐
typedef struct poo poo; // <-- now `poo` is really `struct poo`
poo Poo; // <-- Now I have a Poo that is a poo struct.
// People usually do this because now I can make more `poo` later.
// But they do it using the final form below.

// Yet another way to do this. This is not the final form.
typedef struct zoo
{
    int x;
} zoo; // Now `zoo` is the data type `struct zoo`.
zoo Zoo;

// ----------> People usually do this. <-----------------
// This is it. You ready?
typedef struct
{
    int x;
} bob; // Now `bob` is the struct data type I just defined.
bob Bob;

typedef struct
{
    int a;
    int b;
    int c;
} z00;

int CALLBACK WinMain(
        HINSTANCE hInst,        // Handle to this instance of the app
        HINSTANCE hInstPrev,    // Existing instance of the program: NULL
        LPSTR cmdline,          // Cmd line for the app
        int cmdshow             // Controls how the window is shown
        )
{
    Foo.x = 0;
    Goo.x = Foo.x + 1;
    Poo.x = Goo.x + 1;
    poo Poo2;
    Poo2.x = Poo.x + 1;
    zoo Zoo;
    Zoo.x = Poo2.x + 1;
    bob Bob;
    Bob.x = Zoo.x + 1;

    /* z00 Z00 = {};  This does not work in C, only in C++*/
    z00 Z01 = {0};
    z00 Z02 = {0, 1, 2};

    return 0;
}

