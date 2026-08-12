#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>

double first_num = 0; // store the first number
char operation = 0;   // store the opperation

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

//put numbers on display's screan
void on_digit_clicked(GtkButton *button, gpointer user_data) {
    GtkEntry *entry = GTK_ENTRY(user_data);
    
    
    const gchar *current_text = gtk_entry_get_text(entry);
    const gchar *button_text = gtk_button_get_label(button);

    // concate the two texts
    gchar *new_text = g_strconcat(current_text, button_text, NULL);
    
    // display text and free memory
    gtk_entry_set_text(entry, new_text);
    g_free(new_text);
}

// clear fonction 
void on_clear_clicked(GtkButton *button, gpointer user_data) {
    // put user_data to GtkEntry
    GtkEntry *entry = GTK_ENTRY(user_data);
    
    // put an empty text to screan
    gtk_entry_set_text(entry, "");
}

// opperation function
void on_operation_clicked(GtkButton *button, gpointer user_data) {
    GtkEntry *entry = GTK_ENTRY(user_data);
    
    // store the first number
    const gchar *text = gtk_entry_get_text(entry);
    first_num = atof(text);
    
    // store the oppertion
    const gchar *op_text = gtk_button_get_label(button);
    operation = op_text[0]; // نأخذ أول حرف من النص
    
    // clear
    gtk_entry_set_text(entry, "");
}

// equal fonction
void on_equal_clicked(GtkButton *button, gpointer user_data) {
    GtkEntry *entry = GTK_ENTRY(user_data);
    
    // read second number
    const gchar *text = gtk_entry_get_text(entry);
    double second_num = atof(text);
    double result = 0.0;

    // application of the opp
    switch (operation) {
        case '+':
            result = first_num + second_num;
            break;
        case '-':
            result = first_num - second_num;
            break;
        case '*':
            result = first_num * second_num;
            break;
        case '/':
            if (second_num != 0) {
                result = first_num / second_num;
            } else {
                gtk_entry_set_text(entry, "Error");
                return;
            }
            break;
        default:
            return;
    }

    // transform number to text and put it in screan
    char result_str[32];
    snprintf(result_str, sizeof(result_str), "%g", result); // %g لتنسيق الأرقام بشكل نظيف
    gtk_entry_set_text(entry, result_str);
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

GtkWidget *entry = gtk_entry_new();
context0 = gtk_widget_get_style_context(entry);
gtk_style_context_add_class(context0, "display");


gtk_editable_set_editable(GTK_EDITABLE(entry), FALSE);

gtk_widget_set_size_request(entry, -1, 80);//default in gtk -1  

gtk_widget_set_hexpand(entry, TRUE);  // expand horizontally
gtk_widget_set_vexpand(entry, TRUE);  // expand vertically

// add the margin of screan
gtk_widget_set_margin_bottom(entry, 20);

// box creation 
GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL,10);

gtk_container_add(GTK_CONTAINER(window), box);

gtk_box_pack_start(GTK_BOX(box), entry, FALSE, FALSE, 0);

gtk_widget_set_hexpand(box, TRUE);  // expand horizontally
gtk_widget_set_vexpand(box, TRUE);  // expand vertically



//grid creation

GtkWidget *grid = gtk_grid_new();

gtk_widget_set_hexpand(grid, TRUE);

gtk_widget_set_vexpand(grid, TRUE);

gtk_grid_set_row_spacing(GTK_GRID(grid),3);

gtk_grid_set_column_spacing(GTK_GRID(grid),3);

gtk_box_pack_start(GTK_BOX(box), grid, TRUE, TRUE, 0);

// space between buttons
gtk_grid_set_row_spacing(GTK_GRID(grid), 5);
gtk_grid_set_column_spacing(GTK_GRID(grid), 5);


//bottons creation 

GtkWidget *c_button = createButton(grid, "C", 4, 5, 1, 1);
GtkStyleContext *context = gtk_widget_get_style_context(c_button);
gtk_style_context_add_class(context, "c");

// call clear fonction
g_signal_connect(c_button, "clicked", G_CALLBACK(on_clear_clicked), entry);

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

GtkWidget *btn_mul = createButton(grid, "*", 4, 3, 1, 1);
context3 = gtk_widget_get_style_context(btn_mul);
gtk_style_context_add_class(context3, "op");

GtkWidget *btn_div = createButton(grid, "/", 5, 3, 1, 1);
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
GtkWidget *btn_eq = createButton(grid, "=", 3, 6, 1, 3);
context4 = gtk_widget_get_style_context(btn_eq);
gtk_style_context_add_class(context4, "normale");

// call the number fonction
g_signal_connect(btn_0, "clicked", G_CALLBACK(on_digit_clicked), entry);
g_signal_connect(btn_1, "clicked", G_CALLBACK(on_digit_clicked), entry);
g_signal_connect(btn_2, "clicked", G_CALLBACK(on_digit_clicked), entry);
g_signal_connect(btn_3, "clicked", G_CALLBACK(on_digit_clicked), entry);
g_signal_connect(btn_4, "clicked", G_CALLBACK(on_digit_clicked), entry);
g_signal_connect(btn_5, "clicked", G_CALLBACK(on_digit_clicked), entry);
g_signal_connect(btn_6, "clicked", G_CALLBACK(on_digit_clicked), entry);
g_signal_connect(btn_7, "clicked", G_CALLBACK(on_digit_clicked), entry);
g_signal_connect(btn_8, "clicked", G_CALLBACK(on_digit_clicked), entry);
g_signal_connect(btn_9, "clicked", G_CALLBACK(on_digit_clicked), entry);

// call the operation fonction
g_signal_connect(btn_add, "clicked", G_CALLBACK(on_operation_clicked), entry);
g_signal_connect(btn_sub, "clicked", G_CALLBACK(on_operation_clicked), entry);
g_signal_connect(btn_mul, "clicked", G_CALLBACK(on_operation_clicked), entry);
g_signal_connect(btn_div, "clicked", G_CALLBACK(on_operation_clicked), entry);

// call equal fonction
g_signal_connect(btn_eq, "clicked", G_CALLBACK(on_equal_clicked), entry);


g_signal_connect(window,"destroy",G_CALLBACK(gtk_main_quit),NULL);
gtk_widget_show_all(window);
gtk_main();
return 0;



}
