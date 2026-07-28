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
//bottons creation 

GtkWidget * button_1 = createButton(grid,"1",1,3,1,1);
GtkWidget * button_2 = createButton(grid,"2",2,3,1,1);

GtkWidget * button_3 = createButton(grid,"3",3,3,1,1);
GtkWidget * button_4 = createButton(grid,"4",1,2,1,1);

GtkWidget * button_5 = createButton(grid,"5",2,2,1,1);
GtkWidget * button_6 = createButton(grid,"6",3,2,1,1);

GtkWidget * button_7 = createButton(grid,"7",1,1,1,1);
GtkWidget * button_8 = createButton(grid,"8",2,1,1,1);

GtkWidget * button_9 = createButton(grid,"9",3,1,1,1);
GtkWidget * button_0 = createButton(grid,"0",1,4,3,3);

GtkWidget * button_plus = createButton(grid,"+",4,2,1,1);
GtkWidget * button_minus = createButton(grid,"-",5,2,1,1);

GtkWidget * button_multiplication = createButton(grid,"x",4,1,1,1);
GtkWidget * button_division = createButton(grid,"÷",5,1,1,1);

GtkWidget * button_equal  = createButton(grid,"=",4,4,3,3);

g_signal_connect(window,"destroy",G_CALLBACK(gtk_main_quit),NULL);
gtk_widget_show_all(window);
gtk_main();
return 0;



}
