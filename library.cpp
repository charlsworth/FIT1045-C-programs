#include "splashkit.h"
#include "utilities.h"

// createing a menu option type
enum menu_option
{
    ENTER_DETAILS,
    PRINT_BOOK,
    QUIT
};

// number of menu otions
const int NUM_MENU_OPTIONS = (int)QUIT + 1;

// creating a structure for a book
struct book
{
    string title;
    string location;
    int pages;
    static const int MEMBER_COUNT = 3;
};

string enum_to_string(menu_option option)
// function that turns the menu option into a string
{
    switch (option)
    {
    case ENTER_DETAILS:
        return "Enter book details";
    case PRINT_BOOK:
        return "Print book";
    case QUIT:
        return "Quit";
    default:
        return "Invalid value";
    }
}

menu_option select_menu(string prompt)
// function for chosing a menu option
{
    write_line("");
    write_line(prompt);
    for (int i = 0; i < NUM_MENU_OPTIONS; i++)
    {
        menu_option current_option = (menu_option)i;
        write_line(to_string(i + 1) + ": " + enum_to_string(current_option));
    };

    int menu_choice;

    do
    {
        menu_choice = read_integer("Option: ");
    } while ((0 >= menu_choice) or (menu_choice > NUM_MENU_OPTIONS));
    return (menu_option)(menu_choice - 1);
}

book enter_data(book &data)
// function for entering book data
{
    write_line("");
    data.title = read_string("Enter title: ");
    data.location = read_string("Enter location: ");
    data.pages = read_integer("Enter number of pages: ");

    return data;
}

void print_data(const book &data)
// function that prints book data
{
    write_line("");
    write_line("book details:");
    write_line("Title: " + data.title);
    write_line("Location: " + data.location);
    write_line("Pages: " + to_string(data.pages));
}

int main()
// main function
{
    book defult_book;
    book data = enter_data(defult_book);
    menu_option option;

    while (true)
    {
        option = select_menu("Menu:");
        write_line("option choosen is: " + enum_to_string(option));

        switch (option)
        {
        case ENTER_DETAILS:
            data = enter_data(data);
            break;
        case PRINT_BOOK:
            print_data(data);
            break;
        case QUIT:
            write_line("");
            write_line("exiting the program...");
            return 0;
        default:
            write_line("Error 2");
            break;
        }
    }
    return 0;
}