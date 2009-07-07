#include <stdio.h>
#include <X11/X.h>
#include <X11/XKBlib.h>
#include <locale.h>
#include <gtk/gtk.h>
#include <gdk/gdkx.h>


static XkbDescRec xkb;

int main (int argc, char **argv)
{
    gtk_init (&argc, &argv);
    setlocale (LC_ALL, "");
    fprintf (stderr, "%d\n", XSupportsLocale ());


}
