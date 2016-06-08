# GTK+ - Example
---------------------------

### Code:

```c
#include <gtk/gtk.h>

int main (int argc, char *argv[])
{
    GtkWidget *window;
    GtkWidget *label;

    gtk_init(&argc, &argv);

    /* Create the main, top level window */
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    /* Give it the title */
    gtk_window_set_title(GTK_WINDOW(window), "Hello, world!");

    /* Center the window */
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

    /* Set the window's default size */
    gtk_window_set_default_size(GTK_WINDOW(window), 200, 100);

    /*
    ** Map the destroy signal of the window to gtk_main_quit;
    ** When the window is about to be destroyed, we get a notification and
    ** stop the main GTK+ loop by returning 0
    */
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    /*
    ** Assign the variable "label" to a new GTK label,
    ** with the text "Hello, world!"
    */
    label = gtk_label_new("Hello, world!");

    /* Plot the label onto the main window */
    gtk_container_add(GTK_CONTAINER(window), label);

    /* Make sure that everything, window and label, are visible */
    gtk_widget_show_all(window);

    /*
    ** Start the main loop, and do nothing (block) until
    ** the application is closed
    */
    gtk_main();

    return 0;
}
```

### How to install gtk and compile and run example:

```bash
sudo apt-get install libgtk-3-dev

# Using pkg-config in a Unix shell, this code can be compiled with the following command (assume above source has file name "helloworld.c"):
cc -Wall helloworld.c -o helloworld $(pkg-config --cflags --libs gtk+-3.0)

#Invoke the program
$ ./helloworld
```
