# C Coding Standard

## Names

Names have to be sensical, and fitting for the purpose. For example, if we have a function that is used to sort an integer array:

- Bad naming: sort(args);
- Good naming: sort_int_array(args).

Function and variable names have to be all lowercase, and, if made of multiple words - they have to be seperated by the '\_' seperator. Also, if a pointer is declared - place the pointer closer to the name of the variable, and not the type.<br>

Bad examples:

- int\* Foo;
- int variableTwo
- void UsefulFunctioN(args);

Good examples:

- int \*foo;
- int variable_two;
- int useful_function(args);

If using #define, the format is as follows:<br>
#define DEF_NAME value

If using global variables, add prefix g\_. Example:<br>
int g_user_count;

If using structs, for the data type of the struct, follow formatting as mentioned above; when creating the struct itself, start with lowercase, and, if there are multiple words - capitalize the first letter of each word. For example:<br>

typedef struct {<br>int foo;
<br>} foo_t;

foo_t fooDataList;
<br> foo_t - foo is the name, _t means type

## Syntax

When initalizing / declaring functions, use the following format:

type function_name(void arg1, void arg2[]) {<br>
    foo;<br>
    return;
<br>}

When using if/else if/else statements, always use brackets, even if it's a one liner for easier reading. The following syntax is to be used:

if(statement) {<br>

}
else if(statement) {

}
else {

}

The same formatting as above is to be used for loops of all kinds.
