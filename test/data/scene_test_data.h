static const char* valid_background_scene =
"................................................................\n"
"|                                                              |\n"
"|                 TTTTT  EEEE    SSS  TTTTT                    |\n"
"|                   T    E      S       T                      |\n"
"|                   T    EEEE    SS     T                      |\n"
"|                   T    E         S    T                      |\n"
"|                   T    EEEE   SSS     T                      |\n"
"................................................................\n";

static const char* invalid_background_with_newlines_on_different_columns= 
"\"These newlines\n"
"are\n"
"misalligned,\n"
"see?\"";
static const char* invalid_background_with_no_newlines= 
"\t   be no "
"newlines 'ere :(\"\r\"Uh, there";

static int expected_scene_width = 64;
static int expected_scene_height = 8;

static const char* scene_object = "@";
