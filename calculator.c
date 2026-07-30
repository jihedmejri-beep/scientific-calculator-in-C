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

// main function
	
int main (int argc, char * argv[]){

const char * title = "Calculator";

gtk_init(&argc , &argv);

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

gtk_window_set_title(GTK_WINDOW(window),title);

gtk_window_set_default_size(GTK_WINDOW(window), 400, 550);

gtk_window_set_icon_from_file(GTK_WINDOW(window),"icon.png",NULL);

//Display

GtkWidget *display = gtk_entry_new();

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

GtkWidget *sin_button = createButton(grid, "sin", 1, 1, 1, 1);
GtkWidget *cos_button = createButton(grid, "cos", 2, 1, 1, 1);
GtkWidget *tan_button = createButton(grid, "tan", 3, 1, 1, 1);
GtkWidget *ln_button = createButton(grid, "ln", 4, 1, 1, 1);
GtkWidget *e_button = createButton(grid, "e", 5, 1, 1, 1);


GtkWidget *log_button = createButton(grid, "log", 1, 2, 1, 1);
GtkWidget *pow_button = createButton(grid, "^", 2, 2, 1, 1);
GtkWidget *prim_button = createButton(grid, "primitive", 3, 2, 1, 1);
GtkWidget *mode_button = createButton(grid, "mode", 4, 2, 1, 1);
GtkWidget *graph_button = createButton(grid, "graph", 5, 2, 1, 1);


GtkWidget *btn_7 = createButton(grid, "7", 1, 3, 1, 1);
GtkWidget *btn_8 = createButton(grid, "8", 2, 3, 1, 1);
GtkWidget *btn_9 = createButton(grid, "9", 3, 3, 1, 1);
GtkWidget *btn_mul = createButton(grid, "x", 4, 3, 1, 1);
GtkWidget *btn_div = createButton(grid, "÷", 5, 3, 1, 1);


GtkWidget *btn_4 = createButton(grid, "4", 1, 4, 1, 1);
GtkWidget *btn_5 = createButton(grid, "5", 2, 4, 1, 1);
GtkWidget *btn_6 = createButton(grid, "6", 3, 4, 1, 1);
GtkWidget *btn_add = createButton(grid, "+", 4, 4, 1, 1);
GtkWidget *btn_sub = createButton(grid, "-", 5, 4, 1, 1);


GtkWidget *btn_1 = createButton(grid, "1", 1, 5, 1, 1);
GtkWidget *btn_2 = createButton(grid, "2", 2, 5, 1, 1);
GtkWidget *btn_3 = createButton(grid, "3", 3, 5, 1, 1);


GtkWidget *btn_0 = createButton(grid, "0", 1, 6, 1, 1); 
GtkWidget *btn_pi = createButton(grid, "π", 2, 6, 1, 1);
GtkWidget *btn_eq = createButton(grid, "=", 3, 6, 2, 1);

g_signal_connect(window,"destroy",G_CALLBACK(gtk_main_quit),NULL);
gtk_widget_show_all(window);
gtk_main();
return 0;



}
