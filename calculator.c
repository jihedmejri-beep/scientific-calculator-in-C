#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>

// helper function to create buttons and attached to the grid 

GtkWidget * createButton(GtkWidget * grid,char * text,int column , int row ,int spaceRowsTaken , int spaceColumnsTaken ){
	GtkWidget *button = gtk_button_new_with_label(text);
	gtk_widget_set_size_request(button, 10, 10);
	//gtk_widget_set_hexpand(button, TRUE);
	//gtk_widget_set_vexpand(button, TRUE);
	gtk_grid_attach(GTK_GRID(grid), button, column,row , spaceColumnsTaken, spaceRowsTaken);
	return button;}

    void load_css(void) {
    GtkCssProvider *provider = gtk_css_provider_new();
    GdkDisplay *display = gdk_display_get_default();
    GdkScreen *screen = gdk_display_get_default_screen(display);

    gtk_style_context_add_provider_for_screen(screen,
                                              GTK_STYLE_PROVIDER(provider),
                                              GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);

    // link of css file
    gtk_css_provider_load_from_path(provider, "calculator.css", NULL);
    
    g_object_unref(provider);
}

// main function
	
int main (int argc, char * argv[]){

const char * title = "Calculator";

gtk_init(&argc , &argv);

// load of css file
load_css();

printf ("hello world/n");

// Create css provider
    GtkCssProvider *provider = gtk_css_provider_new();

    // Load CSS styling rules: set larger font for display entry and buttons
    gtk_css_provider_load_from_data(provider,
        "entry { font-size: 32px; font-weight: bold; }\n"
        "button { font-size: 24px; }\n",
        -1, NULL);

    // Apply the CSS rules to the default screen
    gtk_style_context_add_provider_for_screen(
        gdk_screen_get_default(),
        GTK_STYLE_PROVIDER(provider),
        GTK_STYLE_PROVIDER_PRIORITY_APPLICATION
    );

//window creation 

GtkWidget*window =gtk_window_new(GTK_WINDOW_TOPLEVEL);

GtkStyleContext *context0 = gtk_widget_get_style_context(window);
gtk_style_context_add_class(context0, "window");

gtk_window_set_title(GTK_WINDOW(window),title);

gtk_window_set_default_size(GTK_WINDOW(window), 450,650);

gtk_window_set_icon_from_file(GTK_WINDOW(window),"icon.png",NULL);

//Display

GtkWidget *display = gtk_entry_new();
context0 = gtk_widget_get_style_context(display);
gtk_style_context_add_class(context0, "display");


gtk_editable_set_editable(GTK_EDITABLE(display), FALSE);

gtk_widget_set_size_request(display, -1, 80);//default in gtk -1  

gtk_widget_set_hexpand(display, TRUE);  // expand horizontally
gtk_widget_set_vexpand(display, TRUE);  // expand vertically

// add the margin of screan
gtk_widget_set_margin_bottom(display, 20);

// box creation 
GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL,10);

gtk_container_add(GTK_CONTAINER(window), box);

gtk_box_pack_start(GTK_BOX(box), display, FALSE, FALSE, 0);

gtk_widget_set_hexpand(box, TRUE);  // expand horizontally
gtk_widget_set_vexpand(box, TRUE);  // expand vertically



//grid creation

GtkWidget *grid = gtk_grid_new();

gtk_widget_set_hexpand(grid, true);

gtk_widget_set_vexpand(grid, true);

gtk_grid_set_row_spacing(GTK_GRID(grid),3);

gtk_grid_set_column_spacing(GTK_GRID(grid),3);

gtk_box_pack_start(GTK_BOX(box), grid, TRUE, TRUE, 0);

// space between buttons
gtk_grid_set_row_spacing(GTK_GRID(grid), 5);
gtk_grid_set_column_spacing(GTK_GRID(grid), 5);


//bottons creation 

GtkWidget *c_button = createButton(grid, "C", 4, 5, 2, 1);
GtkStyleContext *context = gtk_widget_get_style_context(c_button);
gtk_style_context_add_class(context, "c");

GtkWidget *sin_button = createButton(grid, "sin", 1, 1, 1, 1);
// give a class to an element 
context = gtk_widget_get_style_context(sin_button);
gtk_style_context_add_class(context, "sin");

GtkWidget *cos_button = createButton(grid, "cos", 2, 1, 1, 1);
context = gtk_widget_get_style_context(cos_button);
gtk_style_context_add_class(context, "sin");

GtkWidget *tan_button = createButton(grid, "tan", 3, 1, 1, 1);
context = gtk_widget_get_style_context(tan_button);
gtk_style_context_add_class(context, "sin");

GtkWidget *ln_button = createButton(grid, "ln", 4, 1, 1, 1);
context = gtk_widget_get_style_context(ln_button);
gtk_style_context_add_class(context, "sin");

GtkWidget *e_button = createButton(grid, "e", 5, 1, 1, 1);
context = gtk_widget_get_style_context(e_button);
gtk_style_context_add_class(context, "sin");

GtkWidget *log_button = createButton(grid, "log", 1, 2, 1, 1);
context = gtk_widget_get_style_context(log_button);
gtk_style_context_add_class(context, "sin");

GtkWidget *pow_button = createButton(grid, "^", 2, 2, 1, 1);
context = gtk_widget_get_style_context(pow_button);
gtk_style_context_add_class(context, "sin");

GtkWidget *prim_button = createButton(grid, "primitive", 3, 2, 1, 1);
GtkStyleContext * context2 = gtk_widget_get_style_context(prim_button);
gtk_style_context_add_class(context2, "prim");

GtkWidget *mode_button = createButton(grid, "mode", 4, 2, 1, 1);
context2 = gtk_widget_get_style_context(mode_button);
gtk_style_context_add_class(context2, "prim");

GtkWidget *graph_button = createButton(grid, "graph", 5, 2, 1, 1);
context2 = gtk_widget_get_style_context(graph_button);
gtk_style_context_add_class(context2, "prim");


GtkWidget *btn_7 = createButton(grid, "7", 1, 3, 1, 1);
GtkStyleContext * context3 = gtk_widget_get_style_context(btn_7);
gtk_style_context_add_class(context3, "num");

GtkWidget *btn_8 = createButton(grid, "8", 2, 3, 1, 1);
context3 = gtk_widget_get_style_context(btn_8);
gtk_style_context_add_class(context3, "num");

GtkWidget *btn_9 = createButton(grid, "9", 3, 3, 1, 1);
context3 = gtk_widget_get_style_context(btn_9);
gtk_style_context_add_class(context3, "num");

GtkWidget *btn_mul = createButton(grid, "x", 4, 3, 1, 1);
context3 = gtk_widget_get_style_context(btn_mul);
gtk_style_context_add_class(context3, "op");

GtkWidget *btn_div = createButton(grid, "÷", 5, 3, 1, 1);
context3 = gtk_widget_get_style_context(btn_div);
gtk_style_context_add_class(context3, "op");



GtkWidget *btn_4 = createButton(grid, "4", 1, 4, 1, 1);
context3 = gtk_widget_get_style_context(btn_4);
gtk_style_context_add_class(context3, "num");

GtkWidget *btn_5 = createButton(grid, "5", 2, 4, 1, 1);
context3 = gtk_widget_get_style_context(btn_5);
gtk_style_context_add_class(context3, "num");

GtkWidget *btn_6 = createButton(grid, "6", 3, 4, 1, 1);
context3 = gtk_widget_get_style_context(btn_6);
gtk_style_context_add_class(context3, "num");

GtkWidget *btn_add = createButton(grid, "+", 4, 4, 1, 1);
context3 = gtk_widget_get_style_context(btn_add);
gtk_style_context_add_class(context3, "op");

GtkWidget *btn_sub = createButton(grid, "-", 5, 4, 1, 1);
context3 = gtk_widget_get_style_context(btn_sub);
gtk_style_context_add_class(context3, "op");


GtkWidget *btn_1 = createButton(grid, "1", 1, 5, 1, 1);
context3 = gtk_widget_get_style_context(btn_1);
gtk_style_context_add_class(context3, "num");

GtkWidget *btn_2 = createButton(grid, "2", 2, 5, 1, 1);
context3 = gtk_widget_get_style_context(btn_2);
gtk_style_context_add_class(context3, "num");

GtkWidget *btn_3 = createButton(grid, "3", 3, 5, 1, 1);
context3 = gtk_widget_get_style_context(btn_3);
gtk_style_context_add_class(context3, "num");


GtkWidget *btn_0 = createButton(grid, "0", 1, 6, 1, 1); 
GtkStyleContext *context4 = gtk_widget_get_style_context(btn_0);
gtk_style_context_add_class(context4, "normale");
GtkWidget *btn_pi = createButton(grid, "π", 2, 6, 1, 1);
context4 = gtk_widget_get_style_context(btn_pi);
gtk_style_context_add_class(context4, "normale");
GtkWidget *btn_eq = createButton(grid, "=", 3, 6, 2, 1);
context4 = gtk_widget_get_style_context(btn_eq);
gtk_style_context_add_class(context4, "normale");


g_signal_connect(window,"destroy",G_CALLBACK(gtk_main_quit),NULL);
gtk_widget_show_all(window);
gtk_main();
return 0;



}
