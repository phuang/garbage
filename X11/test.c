#include <stdio.h>
#include <X11/X.h>
#include <locale.h>

int main()
{
    setlocale (LC_ALL, "");
    fprintf (stderr, "%d\n", XSupportsLocale ());
}
